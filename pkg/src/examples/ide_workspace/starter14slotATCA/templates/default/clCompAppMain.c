/******************************************************************************
 *
 * clCompAppMain.c
 *
 ***************************** Legal Notice ***********************************
 *
 * This file is autogenerated by OpenClovis IDE, Copyright (C) 2002-2006 by 
 * OpenClovis. All rights reserved.
 *
 ***************************** Description ************************************
 *
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

/******************************************************************************
 * Include files needed to compile this file
 *****************************************************************************/

/*
 * POSIX Includes.
 */
 
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * Basic ASP Includes.
 */

#include <clCommon.h>
#include <clOsalApi.h>
#include <clIocServices.h>

/*
 * ASP Client Includes.
 */

#include <clRmdApi.h>
#include <clDebugApi.h>
#include <clOmApi.h>
#include <clOampRtApi.h>
#include <clProvApi.h>
#include <clAlarmApi.h>

#include <clEoApi.h>
#include <clCpmApi.h>
#include <clIdlApi.h>
${idlIncludeFile}

/*
 * ---BEGIN_APPLICATION_CODE---
 */
 
#include "clCompAppMain.h"

/*
 * ---END_APPLICATION_CODE---
 */

/******************************************************************************
 * Optional Features
 *****************************************************************************/

/*
 * This is necessary if the component wishes to provide a service that will
 * be used by other components.
 */

#if HAS_EO_SERVICES

extern ClRcT cl${eo}ClientInstall(void);

#endif

/*
 * This template has a few default clprintfs. These can be disabled by 
 * changing clprintf to a null function
 */
 
#define clprintf(severity, ...)   clAppLog(CL_LOG_HANDLE_APP, severity, 10, \
                                  CL_LOG_AREA_UNSPECIFIED, CL_LOG_CONTEXT_UNSPECIFIED,\
                                  __VA_ARGS__)

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * ---END_APPLICATION_CODE---
 */

/******************************************************************************
 * Global Variables.
 *****************************************************************************/

pid_t mypid;
ClCpmHandleT cpmHandle;

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Declare other global variables here.
 */

/*
 * ---END_APPLICATION_CODE---
 */

/*
 * Description of this EO
 */

ClEoConfigT clEoConfig =
{
    COMP_EO_NAME,               /* EO Name                                  */
    COMP_EO_THREAD_PRIORITY,    /* EO Thread Priority                       */
    COMP_EO_NUM_THREAD,         /* No of EO thread needed                   */
    COMP_IOC_PORT,              /* Required Ioc Port                        */
    COMP_EO_USER_CLIENT_ID, 
    COMP_EO_USE_THREAD_MODEL,   /* Thread Model                             */
    clCompAppInitialize,        /* Application Initialize Callback          */
    clCompAppFinalize,          /* Application Terminate Callback           */
    clCompAppStateChange,       /* Application State Change Callback        */
    clCompAppHealthCheck,       /* Application Health Check Callback        */
};

/*
 * Basic libraries used by this EO. The first 6 libraries are mandatory, the
 * others can be enabled or disabled by setting to CL_TRUE or CL_FALSE.
 */

ClUint8T clEoBasicLibs[] =
{
    COMP_EO_BASICLIB_OSAL,      /* Lib: Operating System Adaptation Layer   */
    COMP_EO_BASICLIB_TIMER,     /* Lib: Timer                               */
    COMP_EO_BASICLIB_BUFFER,    /* Lib: Buffer Management                   */
    COMP_EO_BASICLIB_IOC,       /* Lib: Intelligent Object Communication    */
    COMP_EO_BASICLIB_RMD,       /* Lib: Remote Method Dispatch              */
    COMP_EO_BASICLIB_EO,        /* Lib: Execution Object                    */
    COMP_EO_BASICLIB_OM,        /* Lib: Object Management                   */
    COMP_EO_BASICLIB_HAL,       /* Lib: Hardware Adaptation Layer           */
    COMP_EO_BASICLIB_DBAL,      /* Lib: Database Adaptation Layer           */
};

/*
 * Client libraries used by this EO. All are optional and can be enabled
 * or disabled by setting to CL_TRUE or CL_FALSE.
 */

ClUint8T clEoClientLibs[] =
{
    COMP_EO_CLIENTLIB_COR,      /* Lib: Common Object Repository            */
    COMP_EO_CLIENTLIB_CM,       /* Lib: Chassis Management                  */
    COMP_EO_CLIENTLIB_NAME,     /* Lib: Name Service                        */
    COMP_EO_CLIENTLIB_LOG,      /* Lib: Log Service                         */
    COMP_EO_CLIENTLIB_TRACE,    /* Lib: Trace Service                       */
    COMP_EO_CLIENTLIB_DIAG,     /* Lib: Diagnostics                         */
    COMP_EO_CLIENTLIB_TXN,      /* Lib: Transaction Management              */
    CL_FALSE,                   /* NA */
    COMP_EO_CLIENTLIB_PROV,     /* Lib: Provisioning Management             */
    COMP_EO_CLIENTLIB_ALARM,    /* Lib: Alarm Management                    */
    COMP_EO_CLIENTLIB_DEBUG,    /* Lib: Debug Service                       */
    COMP_EO_CLIENTLIB_GMS       /* Lib: Cluster/Group Membership Service    */
};

/******************************************************************************
 * Application Life Cycle Management Functions
 *****************************************************************************/

/*
 * clCompAppInitialize
 * -------------------
 * This function is invoked when the application is to be initialized.
 */

ClRcT
clCompAppInitialize(
    ClUint32T argc,
    ClCharT *argv[])
{
    ClNameT             appName;
    ClCpmCallbacksT     callbacks;
    ClVersionT          version;
    ClIocPortT          iocPort;
    ClRcT               rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    /*
     * Declare other local variables here.
     */

    /*
     * ---END_APPLICATION_CODE---
     */

    /*
     * Get the pid for the process and store it in global variable.
     */

    mypid = getpid();

    /*
     * Initialize and register with CPM. 'version' specifies the version of
     * AMF with which this application would like to interface. 'callbacks'
     * is used to register the callbacks this component expects to receive.
     */

    version.releaseCode                         = 'B';
    version.majorVersion                        = 01;
    version.minorVersion                        = 01;
    
    callbacks.appHealthCheck                    = NULL;
    callbacks.appTerminate                      = clCompAppTerminate;
    callbacks.appCSISet                         = clCompAppAMFCSISet;
    callbacks.appCSIRmv                         = clCompAppAMFCSIRemove;
    callbacks.appProtectionGroupTrack           = NULL;
        
    /*
     * Get IOC Address, Port and Name. Register with AMF.
     */

    clEoMyEoIocPortGet(&iocPort);

    if ( (rc = clCpmClientInitialize(&cpmHandle, &callbacks, &version)) ) 
        goto errorexit;

    /*
     * If this component will provide a service, register it now.
     */

#if HAS_EO_SERVICES


    rc = cl${eo}ClientInstall();

#endif

    /*
     * Do the application specific initialization here.
     */

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    // ...

    /*
     * ---END_APPLICATION_CODE---
     */

    /*
     * Now register the component with AMF. At this point it is
     * ready to provide service, i.e. take work assignments.
     */

    if ( (rc = clCpmComponentNameGet(cpmHandle, &appName)) ) 
        goto errorexit;
    if ( (rc = clCpmComponentRegister(cpmHandle, &appName, NULL)) ) 
        goto errorexit;

    /*
     * Print out standard information for this component.
     */

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%d]. Initializing\n", appName.value, mypid);
    clprintf (CL_LOG_SEV_INFO, "   IOC Address             : 0x%x\n", clIocLocalAddressGet());
    clprintf (CL_LOG_SEV_INFO, "   IOC Port                : 0x%x\n", iocPort);

    /*
     * This is where the application code starts. If the main thread usage
     * policy is CL_EO_USE_THREAD_FOR_APP, then return from this fn only 
     * after the application terminates. If the main thread usage policy is
     * CL_EO_USE_THREAD_FOR_RECV, then return from this fn after doing the
     * application specific initialization and registration.
     */

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    // ...

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;

errorexit:

    clprintf (CL_LOG_SEV_ERROR, "Component [%s] : PID [%d]. Initialization error [0x%x]\n",
              appName.value, mypid, rc);

    return rc;
}

/*
 * clCompAppFinalize
 * -----------------
 * This function is invoked when the application is to be terminated.
 */

ClRcT clCompAppFinalize()
{
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    /*
     * ---END_APPLICATION_CODE---
     */

    return CL_OK;
}

/*
 * clCompAppTerminate
 * ------------------
 * This function is invoked when the application is to be terminated.
 */

ClRcT
clCompAppTerminate(
    ClInvocationT       invocation,
    const ClNameT       *compName)
{
    ClRcT rc = CL_OK;

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%d]. Terminating\n",
              compName->value, mypid);

    /*
     * ---BEGIN_APPLICATION_CODE--- 
     */

    // ...

    /*
     * ---END_APPLICATION_CODE---
     */
    
    /*
     * Unregister with AMF and send back a response
     */

    if ( (rc = clCpmComponentUnregister(cpmHandle, compName, NULL)) )
        goto errorexit;
    if ( (rc = clCpmClientFinalize(cpmHandle)) )
        goto errorexit;

    clCpmResponse(cpmHandle, invocation, CL_OK);

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%d]. Terminated\n", compName->value, mypid);

    return rc;

errorexit:

    clprintf (CL_LOG_SEV_ERROR, "Component [%s] : PID [%d]. Termination error [0x%x]\n",
              compName->value, mypid, rc);

    return rc;
}

/*
 * clCompAppStateChange
 * ---------------------
 * This function is invoked to change the state of an EO.
 *
 * WARNING: This function is deprecated, and may not be supported in the future.
 * Usage of this feature is discouraged.
 */

ClRcT
clCompAppStateChange(
    ClEoStateT eoState)
{
    switch (eoState)
    {
        case CL_EO_STATE_SUSPEND:
        {
            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            break;
        }

        case CL_EO_STATE_RESUME:
        {
            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            break;
        }
        
        default:
        {
            break;
        }
    }
 
    return CL_OK;
}

/*
 * clCompAppHealthCheck
 * --------------------
 * This function is invoked to perform a healthcheck on the application. The
 * health check logic is application specific.
 */

ClRcT
clCompAppHealthCheck(
    ClEoSchedFeedBackT* schFeedback)
{
    /*
     * Add code for application specific health check below. The defaults
     * indicate EO is healthy and polling interval is unaltered.
     */

    /*
     * ---BEGIN_APPLICATION_CODE---
     */
    
    schFeedback->freq   = CL_EO_DEFAULT_POLL; 
    schFeedback->status = CL_CPM_EO_ALIVE;

    /*
     * ---END_APPLICATION_CODE---
     */

    return CL_OK;
}

/******************************************************************************
 * Application Work Assignment Functions
 *****************************************************************************/

/*
 * clCompAppAMFCSISet
 * ------------------
 * This function is invoked when a CSI assignment is made or the state
 * of a CSI is changed.
 */

ClRcT
clCompAppAMFCSISet(
    ClInvocationT       invocation,
    const ClNameT       *compName,
    ClAmsHAStateT       haState,
    ClAmsCSIDescriptorT csiDescriptor)
{
    /*
     * Print information about the CSI Set
     */

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%d]. CSI Set Received\n", 
              compName->value, mypid);

    clCompAppAMFPrintCSI(csiDescriptor, haState);

    /*
     * Take appropriate action based on state
     */

    switch ( haState )
    {
        case CL_AMS_HA_STATE_ACTIVE:
        {
            /*
             * AMF has requested application to take the active HA state 
             * for the CSI.
             */

            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            clCpmResponse(cpmHandle, invocation, CL_OK);
            break;
        }

        case CL_AMS_HA_STATE_STANDBY:
        {
            /*
             * AMF has requested application to take the standby HA state 
             * for this CSI.
             */

            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            clCpmResponse(cpmHandle, invocation, CL_OK);
            break;
        }

        case CL_AMS_HA_STATE_QUIESCED:
        {
            /*
             * AMF has requested application to quiesce the CSI currently
             * assigned the active or quiescing HA state. The application 
             * must stop work associated with the CSI immediately.
             */

            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            clCpmResponse(cpmHandle, invocation, CL_OK);
            break;
        }

        case CL_AMS_HA_STATE_QUIESCING:
        {
            /*
             * AMF has requested application to quiesce the CSI currently
             * assigned the active HA state. The application must stop work
             * associated with the CSI gracefully and not accept any new
             * workloads while the work is being terminated.
             */

            /*
             * ---BEGIN_APPLICATION_CODE---
             */

            // ...

            /*
             * ---END_APPLICATION_CODE---
             */

            clCpmCSIQuiescingComplete(cpmHandle, invocation, CL_OK);
            break;
        }

        default:
        {
            break;
        }
    }

    return CL_OK;
}

/*
 * clCompAppAMFCSIRemove
 * ---------------------
 * This function is invoked when a CSI assignment is to be removed.
 */

ClRcT
clCompAppAMFCSIRemove(
    ClInvocationT       invocation,
    const ClNameT       *compName,
    const ClNameT       *csiName,
    ClAmsCSIFlagsT      csiFlags)
{
    /*
     * Print information about the CSI Remove
     */

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%d]. CSI Remove Received\n", 
              compName->value, mypid);

    clprintf (CL_LOG_SEV_INFO, "   CSI                     : %s\n", csiName->value);
    clprintf (CL_LOG_SEV_INFO, "   CSI Flags               : 0x%x\n", csiFlags);

    /*
     * Add application specific logic for removing the work for this CSI.
     */

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    // ...

    /*
     * ---END_APPLICATION_CODE---
     */

    clCpmResponse(cpmHandle, invocation, CL_OK);

    return CL_OK;
}

/******************************************************************************
 * Utility functions 
 *****************************************************************************/

/*
 * clCompAppAMFPrintCSI
 * --------------------
 * Print information received in a CSI set request.
 */

ClRcT clCompAppAMFPrintCSI(ClAmsCSIDescriptorT csiDescriptor,
                           ClAmsHAStateT haState)
{
    clprintf (CL_LOG_SEV_INFO, "   CSI Flags               : [%s]\n",
              STRING_CSI_FLAGS(csiDescriptor.csiFlags));

    if (CL_AMS_CSI_FLAG_TARGET_ALL != csiDescriptor.csiFlags)
    {
        clprintf (CL_LOG_SEV_INFO, "   CSI Name                : [%s]\n", 
                  csiDescriptor.csiName.value);
    }

    if (CL_AMS_CSI_FLAG_ADD_ONE == csiDescriptor.csiFlags)
    {
        ClUint32T i = 0;
        
        clprintf (CL_LOG_SEV_INFO, "   Name Value Pairs        : \n");
        for (i = 0; i < csiDescriptor.csiAttributeList.numAttributes; i++)
        {
            clprintf (CL_LOG_SEV_INFO, "       Name            : [%s]\n",
                      csiDescriptor.csiAttributeList.
                      attribute[i].attributeName);
            clprintf (CL_LOG_SEV_INFO, "       Value           : [%s]\n",
                      csiDescriptor.csiAttributeList.
                      attribute[i].attributeValue);
        }
    }
    
    clprintf (CL_LOG_SEV_INFO, "   HA State                : [%s]\n",
              STRING_HA_STATE(haState));

    if (CL_AMS_HA_STATE_ACTIVE == haState)
    {
        clprintf (CL_LOG_SEV_INFO, "   Active Descriptor       : \n");
        clprintf (CL_LOG_SEV_INFO, "     Transition Descriptor : [%d]\n",
                  csiDescriptor.csiStateDescriptor.
                  activeDescriptor.transitionDescriptor);
        clprintf (CL_LOG_SEV_INFO, "       Active Component    : [%s]\n",
                  csiDescriptor.csiStateDescriptor.
                  activeDescriptor.activeCompName.value);
    }
    else if (CL_AMS_HA_STATE_STANDBY == haState)
    {
        clprintf (CL_LOG_SEV_INFO, "   Standby Descriptor      : \n");
        clprintf (CL_LOG_SEV_INFO, "       Standby Rank        : [%d]\n",
                  csiDescriptor.csiStateDescriptor.
                  standbyDescriptor.standbyRank);
        clprintf (CL_LOG_SEV_INFO, "       Active Component    : [%s]\n",
                  csiDescriptor.csiStateDescriptor.
                  standbyDescriptor.activeCompName.value);
    }

    return CL_OK;
}

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Insert any other utility functions here.
 */

/*
 * ---END_APPLICATION_CODE---
 */

