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

#ifndef _MSGCLTSRV_SERVER_H_
#define _MSGCLTSRV_SERVER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <clXdrApi.h>
#include <clIdlApi.h>
#include <ipi/clRmdIpi.h>
#include "../clientIDDefinitions.h"
#include "xdrSaMsgQueueStatusT.h"
#include "xdrSaMsgQueueCreationAttributesT.h"
#include "xdrClMsgMessageIovecT.h"



ClRcT clMsgCltSrvIdlSyncDefer(ClIdlHandleT *pIdlHdl);
        
ClRcT clMsgCltSrvClientInstall(void);

ClRcT clMsgCltSrvClientUninstall(void);

extern ClRcT clMsgQueueStatusGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clMsgQueueUnlinkServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clMsgQueueInfoGetServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clMsgQueueMoveMessagesServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);
extern ClRcT clMsgMessageReceivedServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inmSgHdl , ClBufferHandleT outMsgHdl);


#ifdef __cplusplus
}
#endif
#endif /*_MSGCLTSRV_SERVER_H_*/
