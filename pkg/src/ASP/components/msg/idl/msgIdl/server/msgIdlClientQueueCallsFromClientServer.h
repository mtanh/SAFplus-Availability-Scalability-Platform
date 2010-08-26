
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

#ifndef _MSGIDLCLIENTQUEUECALLSFROMCLIENT_SERVER_H_
#define _MSGIDLCLIENTQUEUECALLSFROMCLIENT_SERVER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <clXdrApi.h>
#include <clIdlApi.h>
#include <ipi/clRmdIpi.h>
#include "../clientIDDefinitions.h"
#include "xdrSaMsgMessageT.h"
#include "xdrSaMsgQueueStatusT.h"
#include "xdrSaMsgQueueCreationAttributesT.h"
#include "xdrSaMsgQueueOpenFlagsT.h"



ClRcT clMsgClientQueueOpen_4_0_0(CL_IN ClHandleT  msgHandle, CL_IN ClNameT*  pQueueName, CL_IN SaMsgQueueCreationAttributesT_4_0_0*  pCreationAttributes, CL_IN SaMsgQueueOpenFlagsT_4_0_0  openFlags, CL_IN ClInt64T  timeout, CL_OUT ClHandleT*  pQHandle);

ClRcT clMsgClientQueueOpenResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode,CL_OUT  ClHandleT  pQHandle);

ClRcT clMsgClientQueueClose_4_0_0(CL_IN ClHandleT  queueHandle);

ClRcT clMsgClientQueueCloseResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode);

ClRcT clMsgClientQueueUnlink_4_0_0(CL_IN ClHandleT  msgHandle, CL_IN ClNameT*  pQueueName);

ClRcT clMsgClientQueueUnlinkResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode);

ClRcT clMsgClientQueueStatusGet_4_0_0(CL_IN ClHandleT  msgHandle, CL_IN ClNameT*  pQueueName, CL_OUT SaMsgQueueStatusT_4_0_0*  pQueueStatus);

ClRcT clMsgClientQueueStatusGetResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode,CL_OUT  SaMsgQueueStatusT_4_0_0  pQueueStatus);

ClRcT clMsgClientMessageCancel_4_0_0(CL_IN ClHandleT  queueHandle);

ClRcT clMsgClientMessageCancelResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode);

ClRcT clMsgClientQueueRetentionTimeSet_4_0_0(CL_IN ClHandleT  queueHandle, CL_IN ClInt64T*  pRetenTime);

ClRcT clMsgClientQueueRetentionTimeSetResponseSend_4_0_0(CL_IN ClIdlHandleT idlHdl,CL_IN ClRcT retCode);


#ifdef __cplusplus
}
#endif
#endif /*_MSGIDLCLIENTQUEUECALLSFROMCLIENT_SERVER_H_*/
