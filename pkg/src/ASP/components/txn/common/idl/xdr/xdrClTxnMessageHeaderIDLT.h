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
*               and unmarshall funtions of ClTxnMessageHeaderIDLT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_TXN_MESSAGE_HEADER_IDLT_H_
#define _XDR_CL_TXN_MESSAGE_HEADER_IDLT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "clTxnCommonDefn.h"
#include "clIocApi.h"
#include "xdrClTxnMessageTypeT.h"
#include "xdrClIocPhysicalAddressT.h"

struct _ClTxnMessageHeaderIDLT_4_0_0;

typedef struct _ClTxnMessageHeaderIDLT_4_0_0 {
    ClVersionT    version;
    ClTxnMessageTypeT_4_0_0    msgType;
    ClIocPhysicalAddressT_4_0_0    srcAddr;
    ClUint32T    srcStatus;
    ClUint32T    msgCount;

}ClTxnMessageHeaderIDLT_4_0_0;


ClRcT  clXdrMarshallClTxnMessageHeaderIDLT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallClTxnMessageHeaderIDLT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayClTxnMessageHeaderIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0), (multiplicity), clXdrMarshallClTxnMessageHeaderIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayClTxnMessageHeaderIDLT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0), (multiplicity), clXdrUnmarshallClTxnMessageHeaderIDLT_4_0_0)

#define clXdrMarshallPointerClTxnMessageHeaderIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0), (multiplicity), clXdrMarshallClTxnMessageHeaderIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerClTxnMessageHeaderIDLT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0), clXdrUnmarshallClTxnMessageHeaderIDLT_4_0_0)

#define clXdrMarshallPtrClTxnMessageHeaderIDLT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0), (multiplicity), clXdrMarshallClTxnMessageHeaderIDLT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrClTxnMessageHeaderIDLT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(ClTxnMessageHeaderIDLT_4_0_0),multiplicity, clXdrUnmarshallClTxnMessageHeaderIDLT_4_0_0)


typedef ClTxnMessageHeaderIDLT_4_0_0 ClTxnMessageHeaderIDLT;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_TXN_MESSAGE_HEADER_IDLT_H_*/
