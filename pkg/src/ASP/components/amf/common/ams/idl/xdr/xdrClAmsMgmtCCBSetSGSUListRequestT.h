/*
 * Copyright (C) 2002-2009 by OpenClovis Inc. All  Rights Reserved.
 * 
 * The source code for  this program is not published  or otherwise 
 * divested of  its trade secrets, irrespective  of  what  has been 
 * deposited with the U.S. Copyright office.
 * 
 * This program is  free software; you can redistribute it and / or
 * modify  it under  the  terms  of  the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the  hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied  warranty  of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 * 
 * You  should  have  received  a  copy of  the  GNU General Public
 * License along  with  this program. If  not,  write  to  the 
 * Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */


/*********************************************************************
* ModuleName  : idl
*********************************************************************/
/*********************************************************************
* Description : This file contains the declarations for marshall 
*               and unmarshall funtions of clAmsMgmtCCBSetSGSUListRequestT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_AMS_MGMT_CCB_SET_SGSU_LIST_REQUEST_T_H_
#define _XDR_CL_AMS_MGMT_CCB_SET_SGSU_LIST_REQUEST_T_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "clAmsEntities.h"
#include "clAmsMgmtCommon.h"
#include "clMetricApi.h"
#include "clIocApi.h"
#include "clAmsNotifications.h"
#include "clAmsMgmtServerApi.h"
#include "xdrClAmsEntityConfigT.h"

struct _clAmsMgmtCCBSetSGSUListRequestT_4_0_0;


ClRcT  clXdrMarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayclAmsMgmtCCBSetSGSUListRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0), (multiplicity), clXdrMarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayclAmsMgmtCCBSetSGSUListRequestT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0), (multiplicity), clXdrUnmarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0)

#define clXdrMarshallPointerclAmsMgmtCCBSetSGSUListRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0), (multiplicity), clXdrMarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerclAmsMgmtCCBSetSGSUListRequestT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0), clXdrUnmarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0)

#define clXdrMarshallPtrclAmsMgmtCCBSetSGSUListRequestT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0), (multiplicity), clXdrMarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrclAmsMgmtCCBSetSGSUListRequestT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(clAmsMgmtCCBSetSGSUListRequestT_4_0_0),multiplicity, clXdrUnmarshallclAmsMgmtCCBSetSGSUListRequestT_4_0_0)


typedef clAmsMgmtCCBSetSGSUListRequestT clAmsMgmtCCBSetSGSUListRequestT_4_0_0;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_AMS_MGMT_CCB_SET_SGSU_LIST_REQUEST_T_H_*/
