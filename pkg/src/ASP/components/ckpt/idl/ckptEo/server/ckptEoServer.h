/*********************************************************************
* File: 
*********************************************************************/
/*********************************************************************
* Description : This file contains the declartions for server stub
*               routines
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _CKPTEO_SERVER_H_
#define _CKPTEO_SERVER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <clXdrApi.h>
#include <clIdlApi.h>
#include <ipi/clRmdIpi.h>
#include "../clientIDDefinitions.h"
#include "xdrClCkptIOVectorElementT.h"
#include "xdrCkptMasterDBClientInfoT.h"
#include "xdrCkptDynamicSyncupT.h"
#include "xdrCkptXlationDBEntryT.h"
#include "xdrCkptSectionInfoT.h"
#include "xdrCkptPeerListInfoT.h"
#include "xdrCkptCreateInfoT.h"
#include "xdrCkptCPInfoT.h"
#include "xdrClCkptCheckpointCreationAttributesT.h"
#include "xdrClCkptSectionIdT.h"
#include "xdrCkptHdlDbT.h"
#include "xdrCkptDPInfoT.h"
#include "xdrClCkptSectionDescriptorT.h"
#include "xdrCkptInfoT.h"
#include "xdrCkptMasterDBEntryIDLT.h"
#include "xdrCkptMasterDBInfoIDLT.h"
#include "xdrCkptOpenInfoT.h"
#include "xdrClCkptSectionCreationAttributesT.h"
#include "xdrClCkptCheckpointDescriptorT.h"
#include "xdrCkptUpdateFlagT.h"
#include "xdrCkptDynamicInfoT.h"



ClRcT clCkptEoIdlSyncDefer(ClIdlHandleT *pIdlHdl);
        
ClRcT clCkptEoClientInstall(void);

ClRcT clCkptEoClientUninstall(void);

extern ClRcT clCkptMasterCkptOpenServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterCkptCloseServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterCkptUnlinkServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptCheckpointStatusGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptSectionCreateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptSectionDeleteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptCheckpointWriteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptSectionOverwriteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptCheckpointReadServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptSvrIterationInitializeServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptIterationNextGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterActiveReplicaSetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterActiveReplicaSetSwitchOverServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterCkptRetentionDurationSetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptCheckpointSynchronizeServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptSectionExpirationTimeSetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterActiveAddrGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptServerFinalizeServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyMasterInfoSyncupServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptLeaderAddrUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyCkptCreateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyCkptOpenServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyCkptInfoUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptCreateInfoDeputyUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptActiveCkptOpenServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptReplicaNotifyServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyReplicaListUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptActiveCkptDeleteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptActiveAddrSetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptActiveAddrInformServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyDynamicUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptDeputyPeerListUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptAllReplicaPresenceListUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrWelcomeServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrByeServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptNackReceiveServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptMasterStatusInfoGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrCkptInfoSyncServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrCkptInfoGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrSectionInfoUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrCkptDeleteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrCkptWriteServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrSectionExpTimeSetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptCheckpointReplicaRemoveServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptReplicaAppInfoNotifyServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptActiveCallbackNotifyServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT _ckptSectionCheckServer_5_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clCkptRemSvrWelcomeServer_5_1_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);


#ifdef __cplusplus
}
#endif
#endif /*_CKPTEO_SERVER_H_*/
