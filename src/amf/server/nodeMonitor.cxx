#include <clFaultApi.hxx>
#include <clGroupApi.hxx>
#include <clCommon.hxx>
#include <amfRpc.hxx>
#include "nodeMonitor.hxx"
#include <SAFplusAmfModule.hxx>

using namespace SAFplus;
extern Group clusterGroup;
extern SAFplus::Fault fault;
extern SAFplusAmf::SAFplusAmfModule cfg;

struct HeartbeatData
{
  enum
    {
      REQ      = 0xc101,
      REQ_OPP  = 0x01c1,
      RESP     = 0xc102,
      RESP_OPP = 0x02c1,
    };
  uint64_t now;
  uint16_t id;
};

const unsigned int InitialHbInterval = 3000;  // give a just started node an extra few seconds to come up

void NodeMonitor::initialize()
{
  lastHbHandle = INVALID_HDL;
  active = false;
  standby = false;
  safplusMsgServer.registerHandler(SAFplusI::HEARTBEAT_MSG_TYPE,this,0);
  for (int i=0;i<SAFplus::MaxNodes;i++)
    {
      lastHeard[i] = 0;
    }

  //maxSilentInterval = SAFplusI::NodeSilentInterval;
  quit = false;
  thread = boost::thread(boost::ref(*this));
}


void NodeMonitor::finalize()
{
  if (!quit)
    {
    quit = true;
    thread.join();
    }
}

void NodeMonitor::msgHandler(MsgServer* svr, Message* msg, ClPtrT cookie)
{
  ScopedLock<> lock(exclusion);
  if (msg->getLength() != sizeof(HeartbeatData))
    {
      // TODO: log error, notify fault mgr
      msg->free();
      return;
    }
  HeartbeatData hbbuf;
  HeartbeatData* hb = (HeartbeatData*) msg->flatten(&hbbuf,0, sizeof(HeartbeatData),0);
  assert(hb);
  if ((hb->id == HeartbeatData::REQ) || (hb->id == HeartbeatData::REQ_OPP))
    {
      hb->id = HeartbeatData::RESP;
      hb->now = nowMs();
      lastHbHandle = msg->getAddress();
      lastHbRequest = timerMs();
      if (hb == &hbbuf) 
        {
          logCritical("HB","NOD","Heartbeat response misalignment");
          assert(0); // TODO: copy it back, only needed if we used the temp buffer, which we should never do because this message is so small
        }
      svr->SendMsg(msg,SAFplusI::HEARTBEAT_MSG_TYPE);
    }
  else if ((hb->id == HeartbeatData::RESP) || (hb->id == HeartbeatData::RESP_OPP))
    {
      Handle hdl = msg->getAddress();
      if (hb->id == HeartbeatData::RESP_OPP) hb->now = __builtin_bswap64(hb->now);
      int64_t now = nowMs();
      int64_t timeDiff = now - hb->now;
      //logDebug("HB","NOD","Heartbeat response from [%d] handle [%" PRIx64 ":%" PRIx64 "] latency/time difference is [%" PRId64 " ms]",hdl.getNode(), hdl.id[0],hdl.id[1],timeDiff);
      lastHeard[hdl.getNode()] = timerMs();
    }
}

void NodeMonitor::becomeActive(void)
{
  standby = false;
  active = true;
}

void NodeMonitor::becomeStandby(void)
{
  active = false;
  standby = true;
  if (lastHbRequest == 0) lastHbRequest = timerMs();  // if we become standby without ever receiving a hb from the active I don't want the checking to trigger right away. 
}

NodeMonitor::~NodeMonitor()
{
  if (!quit) finalize(); // If quit is false, we never initialized this object and started the thread
}

void NodeMonitor::monitorThread(void)
{
  int loopCnt=-1;
  //assert(maxSilentInterval);  // You didn't call init()

  Group::Iterator end = clusterGroup.end();

  while(!quit)
    {
      loopCnt++;
      int64_t now = timerMs();
      if (active)
        {
          bool ka[SAFplus::MaxNodes];
          if (1)
            {
              ScopedLock<> lock(exclusion);
              for (int i=0;i<SAFplus::MaxNodes;i++)
                {
                  if (lastHeard[i] != 0)
                    {
                      if ((cfg.safplusAmf.healthCheckMaxSilence!=0) && (now - lastHeard[i] > cfg.safplusAmf.healthCheckMaxSilence))
                        {
                          fault.notify(getNodeHandle(i),AlarmState::ALARM_STATE_ASSERT,AlarmCategory::ALARM_CATEGORY_COMMUNICATIONS,AlarmSeverity::ALARM_SEVERITY_MAJOR,AlarmProbableCause::ALARM_PROB_CAUSE_RECEIVER_FAILURE);
                          lastHeard[i] = 0;  // after fault mgr notification, reset node as if its new.  If the fault mgr does not choose to kill the node, this will cause us to give the node another maxSilentInterval.
                          // DEBUG only trigger once boost::this_thread::sleep(boost::posix_time::milliseconds(1000000 + SAFplusI::NodeHeartbeatInterval)); 
                        }
                    }
                }
            }

          for (int i=1;i<SAFplus::MaxNodes;i++)  // Start Keepaliving any nodes that the fault manager thinks are up.
            {
              FaultState fs = fault.getFaultState(getNodeHandle(i));
              if (i != SAFplus::ASP_NODEADDR)  // No point in keepaliving myself
                {
                  if (fs == FaultState::STATE_UP)
                    {
                      Handle hdl = getProcessHandle(SAFplusI::AMF_IOC_PORT,i);
                      ka[i] = true;
                      if (lastHeard[i]==0) lastHeard[i] = timerMs() + InitialHbInterval;
                      HeartbeatData hd;
                      hd.id = HeartbeatData::REQ;
                      hd.now = nowMs();
                      //logDebug("HB","CLM","Heartbeat to handle [%" PRIx64 ":%" PRIx64 "]",hdl.id[0],hdl.id[1]);
                      safplusMsgServer.SendMsg(hdl, (void*) &hd, sizeof(HeartbeatData), SAFplusI::HEARTBEAT_MSG_TYPE);                
                    }
                  else
                    {
                      ka[i] = false;
                    }
                }              
            }

          // Keepalive any nodes in the cluster group.  Every node in this group SHOULD have registered with the fault manager and be UP so this should be a big NO-OP
          for (Group::Iterator it = clusterGroup.begin();it != end; it++)
            {
              Handle hdl = it->first;  // same as gi->id
              const GroupIdentity* gi = &it->second;
              int thisNode = hdl.getNode();
              assert(thisNode < SAFplus::MaxNodes);
              if (thisNode != SAFplus::ASP_NODEADDR)  // No point in keepaliving myself
                {
                  if (ka[thisNode] == false)
                    {
                      logInfo("HB","CLM"," heartbeat to [%d] handle [%" PRIx64 ":%" PRIx64 "] -- in cluster group but not in fault manager",hdl.getNode(), hdl.id[0],hdl.id[1]);
                      if (lastHeard[thisNode]==0) lastHeard[thisNode] = timerMs() + InitialHbInterval;
                      assert(hdl == gi->id);  // key should = handle in the value, if not shared memory is corrupt 
                      HeartbeatData hd;
                      hd.id = HeartbeatData::REQ;
                      hd.now = nowMs();
                      safplusMsgServer.SendMsg(hdl, (void*) &hd, sizeof(HeartbeatData), SAFplusI::HEARTBEAT_MSG_TYPE);
                    }
                }
            }
        }
      if (standby)  // Let the standby ensure that the active is alive
        {
          int64_t now = timerMs();
          if (loopCnt&31==0) 
            {
            cfg.safplusAmf.healthCheckMaxSilence.read();  // Periodically reload from the database to get any changes.  TODO: checkpoint should notify us
            cfg.safplusAmf.healthCheckPeriod.read();
            }

          if ((cfg.safplusAmf.healthCheckMaxSilence.value>0)&&((now > lastHbRequest)&&(now - lastHbRequest > cfg.safplusAmf.healthCheckMaxSilence)))
            {
              // TODO: Split brain avoidance.  The standby should send HB reqs to all the other nodes and count how many it can talk to.  If it is half or greater, then become active.  Otherwise, print a split brain critical message and exit
              Handle hdl;
              if (lastHbHandle == INVALID_HDL)  // We never received a HB from the active so fail whatever the cluster manager thinks is active
                {
                  lastHbHandle = clusterGroup.getActive(ABORT);
                }
              hdl = getNodeHandle(lastHbHandle);
              // I need to special case the fault reporting of the ACTIVE, since that fault server is probably dead.
              // TODO: It is more semantically correct to send this notification to the standby fault server by looking at the fault group.  However, it will end up pointing to this node...
              fault.notifyLocal(hdl,AlarmState::ALARM_STATE_ASSERT,AlarmCategory::ALARM_CATEGORY_COMMUNICATIONS,AlarmSeverity::ALARM_SEVERITY_MAJOR,AlarmProbableCause::ALARM_PROB_CAUSE_RECEIVER_FAILURE);
            }
        }

      uint64_t tmp = cfg.safplusAmf.healthCheckPeriod;
      if (tmp == 0) tmp = 1000; // if "off" loop every second anyway so we can detect when we get turned on.
      boost::this_thread::sleep(boost::posix_time::milliseconds(tmp)); 
    }
}
