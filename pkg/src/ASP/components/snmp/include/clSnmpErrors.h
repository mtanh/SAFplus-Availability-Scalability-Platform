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

/**
 *  \file
 *  \brief Header file of error Messages that are SNMP subagent specific.
 *  \ingroup snmp_apis
 */

/**
 *  \addtogroup snmp_apis
 *  \{
 */

#ifndef _CL_SNMP_ERRORS_H_
#define _CL_SNMP_ERRORS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <clCommon.h>
#include <clCommonErrors.h>

/**
 * Error macro definitions for SNMP subagent.
 */
#define CL_SNMP_RC(ERROR_CODE)  CL_RC(CL_CID_SNMP, (ERROR_CODE))

#ifdef __cplusplus
}
#endif

#endif                          /* _CL_SNMP_ERRORS_H_ */

/** \} */
