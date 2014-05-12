#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <clGroup.hxx>

ClUint32T clAspLocalId = 0x1;
ClBoolT   gIsNodeRepresentative = CL_TRUE;
using namespace SAFplus;
using namespace std;
enum
{
NODENAME_LEN = 16*8,              // Make sure it is a multiple of 64 bits
SC_ELECTION_BIT = 1<<8,           // This bit is set in the credential if the node is a system controller, making SCs preferred
STARTUP_ELECTION_DELAY_MS = 2000  // Wait for 5 seconds during startup if nobody is active so that other nodes can arrive, making the initial election not dependent on small timing issues.
};
class ConditionWake:public Wakeable
{
  public:
    int wakeSignal;
    void wake(int amt,void* cookie=NULL)
    {
      wakeSignal = amt;
    }
    ConditionWake()
    {
      wakeSignal = -1;
    }
};
void wait(int seconds)
{
  cout << "Now, wait for " << seconds << " seconds \n";
  boost::this_thread::sleep(boost::posix_time::milliseconds(seconds * 1000));
}
int main(int argc, char* argv[])
{
  Group            clusterGroup;
  ConditionWake    wakeable;
  EntityIdentifier *me;
  unsigned int credential = 0;
  unsigned int capabilities = 0;
  ClRcT rc            = CL_OK;

  if(argc > 1)
  {
    clAspLocalId = atoi(argv[1]);
  }

  /* Initialize log service */
  logInitialize();
  logEchoToFd = 1;

  /* Initialize necessary libraries */
  if ((rc = clOsalInitialize(NULL)) != CL_OK || (rc = clHeapInit()) != CL_OK || (rc = clBufferInitialize(NULL)) != CL_OK || (rc = clTimerInitialize(NULL)) != CL_OK)
  {
    return rc;
  }
  /* IOC communication */
  clIocLibInitialize(NULL);

  if(getenv("SCNODE") || clAspLocalId == 1)
  {
    credential = clAspLocalId | SC_ELECTION_BIT;
    capabilities = Group::ACCEPT_STANDBY | Group::ACCEPT_ACTIVE;
  }
  else if(getenv("PLNODE") || clAspLocalId != 1)
  {
    credential =  clAspLocalId;
    capabilities = Group::ACCEPT_STANDBY;
  }
  me = new SAFplus::Handle(PersistentHandle,0,0,clAspLocalId,0);
  clusterGroup.init(CLUSTER_GROUP);
  clusterGroup.setNotification(wakeable);
  wait(5);
  clusterGroup.registerEntity(*me, credential, NULL, 0,capabilities);
  wait(5);
  if(getenv("SCNODE") || clAspLocalId == 1)
  {
    clusterGroup.elect();
      while(wakeable.wakeSignal != Group::ELECTION_FINISH_SIG)
      {
        ;
      }
      cout << "Active: " << clusterGroup.getActive().getNode() << "\n";
      cout << "Standby: " << clusterGroup.getStandby().getNode() << "\n";
  }
  wait(10);
  cout << "My node id is: " << clusterGroup.myInformation.id.getNode() << "\n";
  if(getenv("SCNODE") || clAspLocalId == 1)
  {
    cout << "I leave cluster now \n";
    clusterGroup.deregister(*me);
    while(wakeable.wakeSignal != Group::NODE_LEAVE_SIG)
    {
      ;
    }
    return 0;
  }
  wait(10);
  if(clAspLocalId == 3)
  {
    cout << "I leave cluster now \n";
    wakeable.wakeSignal = -1;
    clusterGroup.deregister(*me);
    while(wakeable.wakeSignal != Group::NODE_LEAVE_SIG)
    {
      ;
    }
    return 0;
  }
  while(1)
  {
    ;
  }
}