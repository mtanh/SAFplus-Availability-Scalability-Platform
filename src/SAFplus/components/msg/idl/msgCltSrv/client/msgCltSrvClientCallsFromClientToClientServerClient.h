
/*********************************************************************
* ModuleName  : idl
*********************************************************************/
/*********************************************************************
* Description : This file contains the declartions for client stub
*               routines
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/
#ifndef _MSG_CLT_SRV_CLIENT_CALLS_FROM_CLIENT_TO_CLIENT_SERVER_CLIENT_H_
#define _MSG_CLT_SRV_CLIENT_CALLS_FROM_CLIENT_TO_CLIENT_SERVER_CLIENT_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <clXdrApi.h>
#include <clIdlApi.h>
#include "../clientIDDefinitions.h"
#include "xdrSaMsgQueueStatusT.h"
#include "xdrSaMsgQueueCreationAttributesT.h"
#include "xdrClMsgMessageIovecT.h"



ClRcT clMsgQueueStatusGetClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN SaNameT* pQueueName, CL_OUT SaMsgQueueStatusT_4_0_0* pQueueStatus);

ClRcT clMsgQueueUnlinkClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN SaNameT* pQueueName);

ClRcT clMsgQueueInfoGetClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN SaNameT* pQName, CL_OUT SaMsgQueueCreationAttributesT_4_0_0* pQAttrs);

ClRcT clMsgQueueMoveMessagesClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN SaNameT* pQName, CL_IN ClUint32T openFlags, CL_IN ClUint16T qDelete);

ClRcT clMsgMessageReceivedClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClUint32T sendType, CL_IN SaNameT* pDestination, CL_IN ClMsgMessageIovecT_4_0_0* pMessage, CL_IN ClInt64T sendTime, CL_IN ClHandleT senderHandle, CL_IN ClInt64T timeout);

typedef void (*MsgCltSrvClMsgMessageReceivedAsyncCallbackT_4_0_0) (CL_IN ClIdlHandleT handle, CL_IN ClUint32T  sendType, CL_IN SaNameT* pDestination, CL_IN ClMsgMessageIovecT_4_0_0* pMessage, CL_IN ClInt64T  sendTime, CL_IN ClHandleT  senderHandle, CL_IN ClInt64T  timeout, CL_IN ClRcT rc, CL_IN void* pCookie);

typedef MsgCltSrvClMsgMessageReceivedAsyncCallbackT_4_0_0 MsgCltSrvClMsgMessageReceivedAsyncCallbackT;

ClRcT clMsgMessageReceivedClientAsync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClUint32T  sendType, CL_IN SaNameT* pDestination, CL_IN ClMsgMessageIovecT_4_0_0* pMessage, CL_IN ClInt64T  sendTime, CL_IN ClHandleT  senderHandle, CL_IN ClInt64T  timeout,CL_IN MsgCltSrvClMsgMessageReceivedAsyncCallbackT_4_0_0 fpAsyncCallback, CL_IN void *cookie);


#ifdef __cplusplus
}
#endif
#endif /*_MSG_CLT_SRV_CLIENT_CALLS_FROM_CLIENT_TO_CLIENT_SERVER_CLIENT_H_*/
