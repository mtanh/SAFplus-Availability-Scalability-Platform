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
/*
 * Build: 4.2.0
 */
/*******************************************************************************
 * ModuleName  : om
 * File        : omCompId.h
 *******************************************************************************/

/*******************************************************************************
 * Description :
 * This module contains the definitions for the Base Object. Also, this  
 * file contains the function prototypes of the interfaces that are      
 * exported.                                                             
 *                                                                       
 *************************************************************************/
/* !!!!! WARNING THIS FILE IS GENERATED USING THE TOOLS */
/* DO NOT EDIT THIS FILE */
/* DATE CREATED : Thu Jun 30 17:36:11 IST 2005 */
#ifndef _om_CompId_h_
#define _om_CompId_h_

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES */
#include <clCommon.h>

/* DEFINES */


/* FORWARD DECLARATION */

#undef COMP_PREFIX
#define COMP_PREFIX "om"
#undef COMP_NAME
#define COMP_NAME "Object Manager"
#undef  MODULE_STR
#define MODULE_STR "[Object Manager] "
extern ClInt32T omDebugVar;
#define COMP_DEBUG_VAR		omDebugVar
#define COMP_DEBUG_VAR_PTR	&omDebugVar

#ifdef __cplusplus
}
#endif

#endif  /* _om_CompId_h_ */
