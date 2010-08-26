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
*               and unmarshall funtions of ClMetricT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_METRIC_T_H_
#define _XDR_CL_METRIC_T_H_

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
#include "xdrClMetricIdT.h"

struct _ClMetricT_4_0_0;


ClRcT  clXdrMarshallClMetricT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallClMetricT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayClMetricT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(ClMetricT_4_0_0), (multiplicity), clXdrMarshallClMetricT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayClMetricT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(ClMetricT_4_0_0), (multiplicity), clXdrUnmarshallClMetricT_4_0_0)

#define clXdrMarshallPointerClMetricT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(ClMetricT_4_0_0), (multiplicity), clXdrMarshallClMetricT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerClMetricT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(ClMetricT_4_0_0), clXdrUnmarshallClMetricT_4_0_0)

#define clXdrMarshallPtrClMetricT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(ClMetricT_4_0_0), (multiplicity), clXdrMarshallClMetricT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrClMetricT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(ClMetricT_4_0_0),multiplicity, clXdrUnmarshallClMetricT_4_0_0)


typedef ClMetricT ClMetricT_4_0_0;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_METRIC_T_H_*/
