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
*               and unmarshall funtions of ClAlarmUtilPayLoadListT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/
#ifndef _XDR_CL_ALARM_UTIL_PAY_LOAD_LIST_T_H_
#define _XDR_CL_ALARM_UTIL_PAY_LOAD_LIST_T_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"
#include "xdrClAlarmUtilPayLoadT.h"
#include <clAlarmUtils.h>



ClRcT  clXdrMarshallClAlarmUtilPayLoadListT(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallClAlarmUtilPayLoadListT(ClBufferHandleT, void *);

#define clXdrMarshallArrayClAlarmUtilPayLoadListT(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(ClAlarmUtilPayLoadListT), (multiplicity), clXdrMarshallClAlarmUtilPayLoadListT, (msg), (isDelete))

#define clXdrUnmarshallArrayClAlarmUtilPayLoadListT(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(ClAlarmUtilPayLoadListT), (multiplicity), clXdrUnmarshallClAlarmUtilPayLoadListT)

#define clXdrMarshallPointerClAlarmUtilPayLoadListT(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(ClAlarmUtilPayLoadListT), (multiplicity), clXdrMarshallClAlarmUtilPayLoadListT, (msg), (isDelete))

#define clXdrUnmarshallPointerClAlarmUtilPayLoadListT(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(ClAlarmUtilPayLoadListT), clXdrUnmarshallClAlarmUtilPayLoadListT)

#define clXdrMarshallPtrClAlarmUtilPayLoadListT(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(ClAlarmUtilPayLoadListT), (multiplicity), clXdrMarshallClAlarmUtilPayLoadListT, (msg), (isDelete))

#define clXdrUnmarshallPtrClAlarmUtilPayLoadListT(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(ClAlarmUtilPayLoadListT),multiplicity, clXdrUnmarshallClAlarmUtilPayLoadListT)
#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_ALARM_UTIL_PAY_LOAD_LIST_T_H_*/

