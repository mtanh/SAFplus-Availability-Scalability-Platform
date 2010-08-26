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
* Description : Unmarshall routine for ClLogStreamOwnerDataIDLT
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/
#include "xdrClLogStreamOwnerDataIDLT.h"

ClRcT clXdrUnmarshallClLogStreamOwnerDataIDLT_4_0_0(ClBufferHandleT msg , void* pGenVar)
{
    ClLogStreamOwnerDataIDLT_4_0_0* pVar = (ClLogStreamOwnerDataIDLT_4_0_0*)pGenVar;
    ClRcT     rc     = CL_OK;
    ClUint32T length = 0;

    if ((void*)0 == pVar)
    {
        return CL_XDR_RC(CL_ERR_NULL_POINTER);
    }

    clXdrUnmarshallClUint32T(msg, &length);
    if( 0 == length)
    {
        pGenVar = NULL;
    }
    else
    {

    rc = clXdrUnmarshallClUint16T(msg,&(pVar->streamId));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint64T(msg,&(pVar->streamMcastAddr));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint32T(msg,&(pVar->dsId));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint16T(msg,&(pVar->isNewStream));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint32T(msg,&(pVar->openCnt));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint32T(msg,&(pVar->ackerCnt));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint32T(msg,&(pVar->nonAckerCnt));
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClLogStreamAttrIDLT_4_0_0(msg,&(pVar->streamAttr));
    if (CL_OK != rc)
    {
        return rc;
    }

    }

    return rc;
}


