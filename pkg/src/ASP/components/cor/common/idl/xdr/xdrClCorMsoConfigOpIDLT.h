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
*               and unmarshall funtions of ClCorMsoConfigOpIDLT_4_0_0 
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/

#ifndef _XDR_CL_COR_MSO_CONFIG_OP_IDLT_H_
#define _XDR_CL_COR_MSO_CONFIG_OP_IDLT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "clXdrApi.h"
#include "clCorTxnJobStream.h"
#include "clTimerApi.h"
#include "clCorNotifyApi.h"
#include "clCorClient.h"
#include "clIocApi.h"
#include "clCorDmData.h"
#include "clCorMetaData.h"
#include "clCorSync.h"


typedef enum _ClCorMsoConfigOpIDLT_4_0_0
{
    COR_MSOCONFIG_CLIENT_TO_SERVER,
    COR_MSOCONFIG_SERVER_TO_SERVER
} ClCorMsoConfigOpIDLT_4_0_0;


#define      clXdrMarshallClCorMsoConfigOpIDLT_4_0_0               clXdrMarshallClInt32T

#define      clXdrUnmarshallClCorMsoConfigOpIDLT_4_0_0             clXdrUnmarshallClInt32T

#define      clXdrMarshallArrayClCorMsoConfigOpIDLT_4_0_0          clXdrMarshallArrayClInt32T

#define      clXdrUnmarshallArrayClCorMsoConfigOpIDLT_4_0_0        clXdrUnmarshallArrayClInt32T

#define      clXdrMarshallPointerClCorMsoConfigOpIDLT_4_0_0        clXdrMarshallPointerClInt32T

#define      clXdrUnmarshallPointerClCorMsoConfigOpIDLT_4_0_0      clXdrUnmarshallPointerClInt32T

#define      clXdrMarshallPtrClCorMsoConfigOpIDLT_4_0_0            clXdrMarshallPtrClInt32T

#define      clXdrUnmarshallPtrClCorMsoConfigOpIDLT_4_0_0          clXdrUnmarshallPtrClInt32T



typedef ClCorMsoConfigOpIDLT_4_0_0 ClCorMsoConfigOpIDLT;



#ifdef __cplusplus
}
#endif

#endif /*_XDR_CL_COR_MSO_CONFIG_OP_IDLT_H_*/
