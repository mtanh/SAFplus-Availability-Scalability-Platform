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
*               and unmarshall funtions of CkptPrimInfoT 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CKPT_PRIM_INFO_T_H_
#define _XDR_CKPT_PRIM_INFO_T_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"

#include "clCkptApi.h"
#include "../common/clCkptCommon.h"

struct _CkptPrimInfoT_4_0_0;

typedef struct _CkptPrimInfoT_4_0_0 {
    ClUint16T    delOn;
    ClInt32T    retentionTmr;
    ClUint32T    refCount;

}CkptPrimInfoT_4_0_0;


ClRcT  clXdrMarshallCkptPrimInfoT_4_0_0(void *,ClBufferHandleT , ClUint32T);

ClRcT  clXdrUnmarshallCkptPrimInfoT_4_0_0(ClBufferHandleT, void *);

#define clXdrMarshallArrayCkptPrimInfoT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallArray((pointer), sizeof(CkptPrimInfoT_4_0_0), (multiplicity), clXdrMarshallCkptPrimInfoT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallArrayCkptPrimInfoT_4_0_0(msg,pointer, multiplicity) \
clXdrUnmarshallArray((msg),(pointer), sizeof(CkptPrimInfoT_4_0_0), (multiplicity), clXdrUnmarshallCkptPrimInfoT_4_0_0)

#define clXdrMarshallPointerCkptPrimInfoT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPointer((pointer), sizeof(CkptPrimInfoT_4_0_0), (multiplicity), clXdrMarshallCkptPrimInfoT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPointerCkptPrimInfoT_4_0_0(msg,pointer) \
clXdrUnmarshallPointer((msg),(pointer), sizeof(CkptPrimInfoT_4_0_0), clXdrUnmarshallCkptPrimInfoT_4_0_0)

#define clXdrMarshallPtrCkptPrimInfoT_4_0_0(pointer, multiplicity, msg, isDelete) \
clXdrMarshallPtr((pointer), sizeof(CkptPrimInfoT_4_0_0), (multiplicity), clXdrMarshallCkptPrimInfoT_4_0_0, (msg), (isDelete))

#define clXdrUnmarshallPtrCkptPrimInfoT_4_0_0(msg,pointer,multiplicity) \
clXdrUnmarshallPtr((msg),(pointer), sizeof(CkptPrimInfoT_4_0_0),multiplicity, clXdrUnmarshallCkptPrimInfoT_4_0_0)


typedef CkptPrimInfoT_4_0_0 CkptPrimInfoT;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CKPT_PRIM_INFO_T_H_*/
