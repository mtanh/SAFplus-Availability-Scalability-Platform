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


/*
 * ---BEGIN_APPLICATION_CODE---
 */
 
#include "clCompAppMain.h"
#include <clCkptApi.h>
#include "../ev/ev.h"
#include <arpa/inet.h>
#include <clCorUtilityApi.h>
#include <clCorApi.h>
#include <clCorMetaData.h>
#include <clCorServiceId.h>
#include <clCorMetaStruct.h>
#include <clAlarmUtils.h>

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

extern ClRcT clcsa105CompEO0ClientInstall(void);

#endif

/*
 * This template has a few default clprintfs. These can be disabled by 
 * changing clprintf to a null function
 */
 
#define clprintf(severity, ...)   clAppLog(gEvalLogStream, severity, 10, \
                                  CL_LOG_AREA_UNSPECIFIED, CL_LOG_CONTEXT_UNSPECIFIED,\
                                  __VA_ARGS__)

/*
 * ---BEGIN_APPLICATION_CODE---
 */

static ClRcT checkpoint_initialize(void);
static ClRcT checkpoint_finalize(void);
static ClRcT checkpoint_write_counter(ClUint32T);
static ClRcT checkpoint_read_counter(ClUint32T*);
static ClRcT update_counter_in_cor(time_t, ClCorObjectHandleT,  ClUint32T);
static ClRcT raise_alarm_on_counter(ClCorMOIdT, ClNameT, ClUint32T);


/*
 * ---END_APPLICATION_CODE---
 */

/******************************************************************************
 * Global Variables.
 *****************************************************************************/

ClPidT mypid;
ClCpmHandleT cpmHandle;
ClLogStreamHandleT gEvalLogStream = CL_HANDLE_INVALID_VALUE;

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Declare other global variables here.
 */

char appname[80];               // component instance name
ClUint32T delta_t   = 1000;     // time between printouts  in milliseconds
ClUint32T counter   = 0;        // the value we print out.
ClUint32T counter_threshold   = 55;        // the value determining the counter threshold.
static int            running  = 1; /* Running state: 0=suspended; 1=resumed */
static int            exiting  = 0; /* Flag that tells main loop to exit     */
static ClAmsHAStateT  ha_state = CL_AMS_HA_STATE_NONE; /* HA state           */

#define CKPT_NAME     "csa105Ckpt"  // checkpoint name for this app
static ClCkptSvcHdlT  ckpt_svc_handle;   // handle for checkpoint service
static ClCkptHdlT     ckpt_handle;  // handle for our checkpoint
#define CKPT_SID_NAME "0"           // checkpoint section id
static ClCkptSectionIdT ckpt_sid = {
    (ClUint16T)sizeof (CKPT_SID_NAME)-1,
    (ClUint8T*)CKPT_SID_NAME
};

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
    COMP_EO_CLIENTLIB_MSO,      /* Lib: MSO Management                      */
    COMP_EO_CLIENTLIB_PROV,     /* Lib: Provisioning Management             */
    COMP_EO_CLIENTLIB_ALARM,    /* Lib: Alarm Management                    */
    COMP_EO_CLIENTLIB_DEBUG,    /* Lib: Debug Service                       */
    COMP_EO_CLIENTLIB_GMS,      /* Lib: Cluster/Group Membership Service    */
    COMP_EO_CLIENTLIB_PM        /* Lib: Performance Management              */
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
    ClCorObjectHandleT  objH = 0;
    ClCorMOIdT          moId ;

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


    rc = clcsa105CompEO0ClientInstall();

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

#define min(x,y) ((x<y)? x: y)
    strncpy(appname, appName.value, min(sizeof appname, appName.length));
    appname[min(sizeof appname - 1, appName.length)] = 0;

    // Setup console redirection for demo purposes
     clEvalAppLogStreamOpen(appname, &gEvalLogStream);
    /*
     * Print out standard information for this component.
     */

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%ld]. Initializing", appname, mypid);
    clprintf (CL_LOG_SEV_INFO, "   IOC Address             : 0x%x", clIocLocalAddressGet());
    clprintf (CL_LOG_SEV_INFO, "   IOC Port                : 0x%x", iocPort);

    /*
     * This is where the application code starts. If the main thread usage
     * policy is CL_EO_USE_THREAD_FOR_APP, then return from this fn only 
     * after the application terminates. If the main thread usage policy is
     * CL_EO_USE_THREAD_FOR_RECV, then return from this fn after doing the
     * application specific initialization and registration. Main thread usage
     * policy can be set through IDE from Component porperty -> Eo properties.
     */

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO,"csa105: instantiated as component instance %s.", appname);

    clprintf(CL_LOG_SEV_INFO,"%s: cpmHandle = 0x%llx", appname, cpmHandle);
    if (ha_state != CL_AMS_HA_STATE_ACTIVE)
    {
        clprintf(CL_LOG_SEV_INFO,"%s: Waiting for CSI assignment...", appname);
    }
    if ((rc = checkpoint_initialize()) != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to initialize  checkpoint",
                    appname, rc);
        return rc;
    }
    if ((rc = checkpoint_read_counter(&counter)) != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to read checkpoint", appname, rc);
        checkpoint_finalize();
        return rc;
    }
#if defined(CL_INST)
if ((rc = clDataTapInit(DATA_TAP_DEFAULT_FLAGS, 105)) != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to initialize data tap",
                    appname, rc);
    }
#endif

    clCorMoIdInitialize(&moId);
    clCorMoIdAppend(&moId, CLASS_CHASSIS_MO, 0);
    clCorMoIdAppend(&moId, CLASS_CSA105RES_MO, 0);
    clCorMoIdServiceSet(&moId, CL_COR_SVC_ID_PROVISIONING_MANAGEMENT);
    rc = clCorObjectHandleGet(&moId, &objH);
    if (CL_OK != rc)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed while getting the object handle. rc[0x%x] ", appname, rc);
        return rc;
    }

    while (!exiting)
    {
        if (running && ha_state == CL_AMS_HA_STATE_ACTIVE)
        {
            clprintf(CL_LOG_SEV_INFO,"%s: Hello World! (count = %d)", appname, counter);
#ifdef CL_INST
            if ((rc = clDataTapSend(counter)) != CL_OK && (rc != CL_ERR_INVALID_PARAMETER))
            {
                clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to send data tap data",
                            appname, rc);
            }
#endif
            if ((rc = update_counter_in_cor(time(0), objH, counter)) != CL_OK)
            {
                clprintf(CL_LOG_SEV_ERROR,"%s: [0x%x]: cor update failed. Exiting.",
                            appname, rc);
                break;
            }

            /* Checkpoint new counter number */
            rc = checkpoint_write_counter(counter);
            if (rc != CL_OK)
            {
                clprintf(CL_LOG_SEV_ERROR,"%s: [0x%x]: Checkpoint write failed. Exiting.",
                            appname, rc);
                break;
            }
            
            if (counter_threshold <= counter)
            {
                clCorMoIdServiceSet(&moId, CL_COR_SVC_ID_ALARM_MANAGEMENT);
                if (( rc = raise_alarm_on_counter (moId, appName, counter)) != CL_OK)
                {
                    clprintf(CL_LOG_SEV_ERROR,"%s: Error [0x%x]: Alarm raise has failed. Exiting. ",
                                appname, rc);
                    counter = 0;
                    break;
                }
                counter = 0;
                continue;
            }
            counter++;
        }
        usleep((useconds_t)delta_t*1000);
    }


    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;

errorexit:

    clprintf (CL_LOG_SEV_ERROR, "Component [%s] : PID [%ld]. Initialization error [0x%x]",
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

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%ld]. Terminating",
              compName->value, mypid);

    /*
     * ---BEGIN_APPLICATION_CODE--- 
     */

    checkpoint_finalize(); 

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

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%ld]. Terminated", compName->value, mypid);
    clCpmResponse(cpmHandle, invocation, CL_OK);
    
    clEvalAppLogStreamClose(gEvalLogStream);

    return rc;

errorexit:

    clprintf (CL_LOG_SEV_ERROR, "Component [%s] : PID [%ld]. Termination error [0x%x]",
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
     * ---BEGIN_APPLICATION_CODE--- 
     */

    ClRcT       rc = CL_OK;
    ClCorMOIdT  moId ;
    ClCorAddrT  addr = {0};

    addr.nodeAddress = clIocLocalAddressGet();
    clEoMyEoIocPortGet(&addr.portId);

    clCpmResponse(cpmHandle, invocation, CL_OK);
    clCorMoIdInitialize(&moId);
    clCorMoIdAppend(&moId, CLASS_CHASSIS_MO, 0);
    clCorMoIdAppend(&moId, CLASS_CSA105RES_MO, 0);
    clCorMoIdServiceSet(&moId, CL_COR_SVC_ID_PROVISIONING_MANAGEMENT);

    /*
     * ---END_APPLICATION_CODE---
     */

    /*
     * Print information about the CSI Set
     */

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%ld]. CSI Set Received", 
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

            if (ha_state == CL_AMS_HA_STATE_STANDBY)
            {
                checkpoint_read_counter(&counter);
            }
            ha_state = haState;
            rc = clCorPrimaryOISet(&moId, &addr);
            if (CL_OK != rc)
            {
                clprintf(CL_LOG_SEV_ERROR,"%s: Failed while making the OI as a primary OI. rc[0x%x] ", appname, rc);
                return rc;
            }

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

            ha_state = haState;

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

            ha_state = haState;
            rc = clCorPrimaryOIClear(&moId, &addr);
            if (CL_OK != rc)
            {
                clprintf(CL_LOG_SEV_ERROR,"%s: ERROR [0x%x]: Failed while clearing the primary OI status.", 
                        appname, rc);
                return rc;
            }

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

            ha_state = haState;

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

    clprintf (CL_LOG_SEV_INFO, "Component [%s] : PID [%ld]. CSI Remove Received", 
              compName->value, mypid);

    clprintf (CL_LOG_SEV_INFO, "   CSI                     : %s", csiName->value);
    clprintf (CL_LOG_SEV_INFO, "   CSI Flags               : 0x%x", csiFlags);

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
    clprintf (CL_LOG_SEV_INFO, "   CSI Flags               : [%s]",
              STRING_CSI_FLAGS(csiDescriptor.csiFlags));

    if (CL_AMS_CSI_FLAG_TARGET_ALL != csiDescriptor.csiFlags)
    {
        clprintf (CL_LOG_SEV_INFO, "   CSI Name                : [%s]", 
                  csiDescriptor.csiName.value);
    }

    if (CL_AMS_CSI_FLAG_ADD_ONE == csiDescriptor.csiFlags)
    {
        ClUint32T i = 0;
        
        clprintf (CL_LOG_SEV_INFO, "   Name Value Pairs        : ");
        for (i = 0; i < csiDescriptor.csiAttributeList.numAttributes; i++)
        {
            clprintf (CL_LOG_SEV_INFO, "       Name            : [%s]",
                      csiDescriptor.csiAttributeList.
                      attribute[i].attributeName);
            clprintf (CL_LOG_SEV_INFO, "       Value           : [%s]",
                      csiDescriptor.csiAttributeList.
                      attribute[i].attributeValue);
        }
    }
    
    clprintf (CL_LOG_SEV_INFO, "   HA State                : [%s]",
              STRING_HA_STATE(haState));

    if (CL_AMS_HA_STATE_ACTIVE == haState)
    {
        clprintf (CL_LOG_SEV_INFO, "   Active Descriptor       : ");
        clprintf (CL_LOG_SEV_INFO, "     Transition Descriptor : [%d]",
                  csiDescriptor.csiStateDescriptor.
                  activeDescriptor.transitionDescriptor);
        clprintf (CL_LOG_SEV_INFO, "       Active Component    : [%s]",
                  csiDescriptor.csiStateDescriptor.
                  activeDescriptor.activeCompName.value);
    }
    else if (CL_AMS_HA_STATE_STANDBY == haState)
    {
        clprintf (CL_LOG_SEV_INFO, "   Standby Descriptor      : ");
        clprintf (CL_LOG_SEV_INFO, "       Standby Rank        : [%d]",
                  csiDescriptor.csiStateDescriptor.
                  standbyDescriptor.standbyRank);
        clprintf (CL_LOG_SEV_INFO, "       Active Component    : [%s]",
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
static ClRcT
checkpoint_initialize()
{
    ClRcT      rc = CL_OK;
    ClVersionT ckpt_version = {'B', 1, 1};
    ClNameT    ckpt_name = { strlen(CKPT_NAME), CKPT_NAME };
    ClUint32T  counter_no;
    ClCkptCheckpointCreationAttributesT create_atts = {
        .creationFlags     = CL_CKPT_WR_ALL_REPLICAS,
        .checkpointSize    = sizeof(ClUint32T),
        .retentionDuration = (ClTimeT)0,
        .maxSections       = 2,
        .maxSectionSize    = sizeof(ClUint32T),
        .maxSectionIdSize  = (ClSizeT)64
    };
    ClCkptSectionCreationAttributesT section_atts = {
        .sectionId = &ckpt_sid,
        .expirationTime = (ClTimeT)CL_TIME_END
    };

    clprintf(CL_LOG_SEV_INFO,"%s: checkpoint_initialize", appname);

    /* Initialize checkpointing service instance */
    rc = clCkptInitialize(&ckpt_svc_handle, /* Checkpoint service handle */
                            NULL,           /* Optional callbacks table */
                            &ckpt_version); /* Required verison number */
    if (rc != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed to initialize checkpoint service", appname);
        return rc;
    }
    clprintf(CL_LOG_SEV_ERROR,"%s: Checkpoint service initialized (handle=0x%llx)",
                appname, ckpt_svc_handle);
    //
    // Create the checkpoint for read and write.  
    rc = clCkptCheckpointOpen(ckpt_svc_handle,      // Service handle
                              &ckpt_name,           // Checkpoint name
                              &create_atts,         // Optional creation attr.
                              (CL_CKPT_CHECKPOINT_WRITE |
                               CL_CKPT_CHECKPOINT_READ |
                               CL_CKPT_CHECKPOINT_CREATE),
                              (ClTimeT)-1,          // No timeout
                              &ckpt_handle);        // Checkpoint handle
    if (rc != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to open checkpoint",
                    appname, rc);
        (void)clCkptFinalize(ckpt_svc_handle);
        return rc;
    }
    clprintf(CL_LOG_SEV_INFO,"%s: Checkpoint opened (handle=0x%llx)", appname, ckpt_handle);

    /*
    * Try to create a section so that updates can operate by overwriting
    * the scetion over and over again.
    * If subsequent processes come through here, they will fail to create
    * the section.  That is OK, even though it will cause an error message
    * If the section create fails because the section is already there, then
    * read the counter number
    */
    // Put data in network byte order
    counter_no = htonl(counter);

    rc = clCkptSectionCreate(ckpt_handle,       // Checkpoint handle 
                             &section_atts,     // Section attributes
                             (ClUint8T*)&counter_no,// Initial data
                            (ClSizeT)sizeof(counter_no)); // Size of data 
    if (rc != CL_OK && (CL_GET_ERROR_CODE(rc) != CL_ERR_ALREADY_EXIST))
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: Failed to create checkpoint section",
                    appname);
        (void)clCkptCheckpointClose(ckpt_handle);
        (void)clCkptFinalize(ckpt_svc_handle);
        return rc;
    }
    else if (rc != CL_OK && (CL_GET_ERROR_CODE(rc) == CL_ERR_ALREADY_EXIST))
    {
        rc = checkpoint_read_counter(&counter);
        if (rc != CL_OK)
        {
            clprintf(CL_LOG_SEV_ERROR,"%s: Failed [0x%x] to read Ckpt section",
                        appname, rc);
            (void)clCkptCheckpointClose(ckpt_handle);
            (void)clCkptFinalize(ckpt_svc_handle);
            return rc;
        }
    }
    else
    {
        clprintf(CL_LOG_SEV_INFO,"%s: Section created", appname);
    }
   
    return rc;
}

static ClRcT
checkpoint_finalize(void)
{
    (void)clCkptCheckpointClose(ckpt_handle);
    (void)clCkptFinalize(ckpt_svc_handle);
    return CL_OK;
}

static ClRcT
checkpoint_write_counter(ClUint32T counter)
{
    ClRcT rc = CL_OK;
    ClUint32T counter_no;

    /* Putting data in network byte order */
    counter_no = htonl(counter);

    /* Write checkpoint */
    rc = clCkptSectionOverwrite(ckpt_handle,
    &ckpt_sid,
    &counter_no,
    sizeof(ClUint32T));
    return rc;
}

static ClRcT
checkpoint_read_counter(ClUint32T *counter)
{
    ClRcT rc = CL_OK;
    ClUint32T err_idx; /* Error index in ioVector */
    ClUint32T counter_no;

    ClCkptIOVectorElementT iov = {
        .sectionId  = ckpt_sid,
        .dataBuffer = (ClPtrT)&counter_no,
        .dataSize   = sizeof(ClUint32T),
        .dataOffset = (ClOffsetT)0,
        .readSize   = sizeof(ClUint32T)
    };

    rc = clCkptCheckpointRead(ckpt_handle, &iov, 1, &err_idx);
    if (rc != CL_OK)
    {
        clprintf(CL_LOG_SEV_ERROR,"Error: [0x%x] from checkpoint read, err_idx = %u",
                    rc, err_idx);
    }

    /* FIXME: How to process this err_idx? */
    *counter = ntohl(counter_no);

    return rc;
}

ClRcT
update_counter_in_cor(time_t now, ClCorObjectHandleT objH, ClUint32T counter)
{
    static time_t last_update = 0;      // when did we last update cor?
    const int MAX_UPDATE_FREQ = 5;      // update only every 5 seconds (or less)
    ClRcT           rc = CL_OK;

    if (now - last_update > MAX_UPDATE_FREQ)
    {
    //
    // TODO:
    // Whatever code has to be run to update the counter value in cor
    // should go here
        rc = clCorObjectAttributeSet(CL_COR_SIMPLE_TXN, objH, NULL, CSA105RES_COUNTER, 
                CL_COR_INVALID_ATTR_IDX, &counter, sizeof(counter));
        if (CL_OK != rc)
        {
            clprintf(CL_LOG_SEV_ERROR,"%s: [0x%x] : Failed while setting the value of counter variable.",
                    appname, rc);
            return rc;
        }

    //
    // And here, we update the last_update value to show that we
    // updated cor.
    last_update = now;
    }
    return CL_OK;
}


  
static ClRcT
raise_alarm_on_counter (ClCorMOIdT moId , ClNameT compName, ClUint32T counter)
{
    ClRcT           rc = CL_OK;
    static ClUint32T       iterator = 0, lastCounter = 0;
    ClCharT str [80] = {0};
    ClAlarmInfoT *pAlarmInfo = {0};
    ClAlarmHandleT alarmHandle = {0};
    ClUint8T * pBuf = NULL;
    ClUint32T size = 0;
    ClAlarmUtilPayLoadListPtrT pPayloadList = NULL;

    
    if (lastCounter != counter)
    {
        lastCounter = counter;
        iterator = 0;
    }


    pPayloadList = clHeapAllocate(sizeof(ClAlarmUtilPayLoadListT));
    if (pPayloadList == NULL)
    {
        clprintf(CL_LOG_SEV_ERROR,"Failed to allocate the memory for the alarm payload list.");
        return CL_ERR_NO_MEMORY;
    }

    pPayloadList->numPayLoadEnteries = 1;
    pPayloadList->pPayload = clHeapAllocate(sizeof(ClAlarmUtilPayLoadT));
    if (NULL == pPayloadList->pPayload)
    {
        clprintf(CL_LOG_SEV_ERROR,"Failed while allocating payload array.");
        clHeapFree(pPayloadList);
        return CL_ERR_NO_MEMORY;
    }

    pPayloadList->pPayload[0].numTlvs = 1;
    clCorMoIdClone(&moId, &pPayloadList->pPayload[0].pMoId);

    pPayloadList->pPayload[0].pTlv = clHeapAllocate(sizeof(ClAlarmUtilTlvT));
    if (NULL == pPayloadList->pPayload[0].pTlv)
    {
        clprintf(CL_LOG_SEV_ERROR,"Failed while allocating the pTlv array. ");
        clAlarmUtilPayloadListFree(pPayloadList);
        return CL_ERR_NO_MEMORY;
    }

    sprintf(str, "[%s]: The Alarm has been raised as the counter became [%d] for [%d] time", 
            appname, counter, ++iterator);

    pPayloadList->pPayload[0].pTlv[0].type = CL_COR_UINT8;
    pPayloadList->pPayload[0].pTlv[0].value = clHeapAllocate(strlen(str) + 1);
    if (NULL == pPayloadList->pPayload[0].pTlv[0].value)
    {
        clprintf(CL_LOG_SEV_ERROR,"Failed while allocating the value for the attribute.");
        clAlarmUtilPayloadListFree(pPayloadList);
        return CL_ERR_NO_MEMORY;
    }


    pPayloadList->pPayload[0].pTlv[0].length = strlen(str) + 1;

    memset(pPayloadList->pPayload[0].pTlv[0].value, 0, strlen(str) + 1);

    memcpy(pPayloadList->pPayload[0].pTlv[0].value, str, strlen(str));


    rc = clAlarmUtilPayloadFlatten(pPayloadList, &size, &pBuf);
    if (CL_OK != rc)
    {
        clprintf(CL_LOG_SEV_ERROR,"[%s]. Failed while getting the flat buffer for the payload. rc[0x%x]", 
                appname, rc);
        return rc;
    }

    pAlarmInfo = clHeapAllocate (sizeof(ClAlarmInfoT) + size);
    if (NULL == pAlarmInfo)
    {
        clprintf(CL_LOG_SEV_ERROR,"[%s]: Failed to allocate the memory for alarm information. ", appname);
        clAlarmUtilPayloadListFree(pPayloadList);
        clAlarmUtilPayloadBufFree(pBuf);
        return CL_ERR_NO_MEMORY;
    }

    pAlarmInfo->moId = moId;
    pAlarmInfo->probCause = CL_ALARM_PROB_CAUSE_THRESHOLD_CROSSED; 
    pAlarmInfo->severity = CL_ALARM_SEVERITY_WARNING;
    memcpy (&pAlarmInfo->compName, &compName, sizeof(ClNameT));
    pAlarmInfo->alarmState = CL_ALARM_STATE_ASSERT;
    pAlarmInfo->len = size;

    memcpy(pAlarmInfo->buff, pBuf, pAlarmInfo->len);

    clAlarmUtilPayloadListFree(pPayloadList);
    clAlarmUtilPayloadBufFree(pBuf);

    clprintf(CL_LOG_SEV_ERROR,"[%s]: Raising the alarm as the counter threashold has reached. ", appname); 

    rc = clAlarmRaise (pAlarmInfo, &alarmHandle);
    if (CL_OK != rc)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: [0x%x]: The alarm raise has failed. ", appname, rc);
        clHeapFree(pAlarmInfo);
        return rc;
    }  

    pAlarmInfo->alarmState = CL_ALARM_STATE_CLEAR;
    rc = clAlarmRaise (pAlarmInfo, &alarmHandle);
    if (CL_OK != rc)
    {
        clprintf(CL_LOG_SEV_ERROR,"%s: [0x%x]: The alarm clear has failed. ", appname, rc);
        clHeapFree(pAlarmInfo);
        return rc;
    }
        
    clHeapFree(pAlarmInfo);
    return rc;
}
/*
 * ---END_APPLICATION_CODE---
 */

