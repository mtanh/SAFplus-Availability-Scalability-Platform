/*
 * Copyright (C) 2002-2009 by OpenClovis Inc. All  Rights Reserved.
 * 
 * The source code for  this program is not published  or otherwise 
 * divested of  its trade secrets, irrespective  of  what  has been 
 * deposited with the U.S. Copyright office
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

/*******************************************************************************
 * ModuleName  : com
 * $File: //depot/dev/main/Andromeda/IDE/plugins/com.clovis.cw.workspace/templates/default/clCompAppMain.h $
 * $Author: bkpavan $
 * $Date: 2007/01/03 $
 *******************************************************************************/

/*******************************************************************************
 * Description :
 * This file provides a skeleton for writing a SAF aware component. Application
 * specific code should be added between the ---BEGIN_APPLICATION_CODE--- and
 * ---END_APPLICATION_CODE--- separators.
 *
 * Template Version: 1.0
 *
 ***************************** Editor Commands ********************************
 * For vi/vim
 * :set shiftwidth=4
 * :set softtabstop=4
 * :set expandtab
 *****************************************************************************/

#ifndef CL_COMP_APP_MAIN
#define CL_COMP_APP_MAIN

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 * Include files needed to compile this file
 *****************************************************************************/

#include "./clCompCfg.h"

#ifndef COMP_NAME
#error "COMP_NAME is not defined. Bad or missing ./clCompCfg.h"
#endif

/******************************************************************************
 * Utility macros
 *****************************************************************************/

#define STRING_HA_STATE(S)                                                  \
(   ((S) == CL_AMS_HA_STATE_ACTIVE)             ? "Active" :                \
    ((S) == CL_AMS_HA_STATE_STANDBY)            ? "Standby" :               \
    ((S) == CL_AMS_HA_STATE_QUIESCED)           ? "Quiesced" :              \
    ((S) == CL_AMS_HA_STATE_QUIESCING)          ? "Quiescing" :             \
    ((S) == CL_AMS_HA_STATE_NONE)               ? "None" :                  \
                                                  "Unknown" )

#define STRING_CSI_FLAGS(S)                                                 \
(   ((S) == CL_AMS_CSI_FLAG_ADD_ONE)            ? "Add One" :               \
    ((S) == CL_AMS_CSI_FLAG_TARGET_ONE)         ? "Target One" :            \
    ((S) == CL_AMS_CSI_FLAG_TARGET_ALL)         ? "Target All" :            \
                                                  "Unknown" )

/******************************************************************************
 * Application Life Cycle Management Functions
 *****************************************************************************/

ClRcT 
clCompAppInitialize(
        ClUint32T           argc,
        ClCharT             *argv[]);

ClRcT
clCompAppFinalize();

ClRcT
clCompAppStateChange(
        ClEoStateT          eoState);

ClRcT
clCompAppHealthCheck(
        ClEoSchedFeedBackT* schFeedback);

ClRcT
clCompAppTerminate(
        ClInvocationT       invocation,
        const ClNameT       *compName);

/******************************************************************************
 * Application Work Assignment Functions
 *****************************************************************************/

ClRcT
clCompAppAMFCSISet(
        ClInvocationT       invocation,
        const ClNameT       *compName,
        ClAmsHAStateT       haState,
        ClAmsCSIDescriptorT csiDescriptor);

ClRcT
clCompAppAMFCSIRemove(
        ClInvocationT       invocation,
        const ClNameT       *compName,
        const ClNameT       *csiName,
        ClAmsCSIFlagsT      csiFlags);

/******************************************************************************
 * Utility functions 
 *****************************************************************************/

ClRcT
clCompAppAMFPrintCSI(
    ClAmsCSIDescriptorT csiDescriptor,
    ClAmsHAStateT haState);
#ifdef __cplusplus
}
#endif

#endif // CL_COMP_APP_MAIN
