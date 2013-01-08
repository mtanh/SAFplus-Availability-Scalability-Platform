from string import Template

clConfigHeaderFileTemplate = Template("""
/*******************************************************************************
*
* This headerfile is auto-generated by OpenClovis IDE
*
* clCompConfig.h for ${cpmName}
*
********************************************************************************/

#ifndef CL_COMP_CFG
#define CL_COMP_CFG

#ifdef __cplusplus
extern "C" {
#endif

#include <clCommon.h>   
#include <clEoApi.h>                                                                                                                          
                                                                                                                             
#define COMP_NAME       "${cpmName}"
#define COMP_EO_NAME    "${eoName}"

#define HAS_EO_SERVICES ${hasEOServices}

#define COMP_EO_THREAD_PRIORITY ${eoThreadPriority}
#define COMP_EO_NUM_THREAD ${eoNumThread}
#define COMP_IOC_PORT ${iocPort}
#define COMP_EO_USER_CLIENT_ID (CL_EO_USER_CLIENT_ID_START + ${maxNoClients})
#define COMP_EO_USE_THREAD_MODEL ${threadPolicy}
                                                                                                                             
/* Component EO Basic Libraries */
#define COMP_EO_BASICLIB_OSAL   CL_TRUE
#define COMP_EO_BASICLIB_TIMER   CL_TRUE
#define COMP_EO_BASICLIB_BUFFER   CL_TRUE
#define COMP_EO_BASICLIB_IOC   CL_TRUE
#define COMP_EO_BASICLIB_RMD   CL_TRUE
#define COMP_EO_BASICLIB_EO   CL_TRUE
#define COMP_EO_BASICLIB_OM   ${omLibEnable}
#define COMP_EO_BASICLIB_HAL  ${halLibEnable}
#define COMP_EO_BASICLIB_DBAL  ${dbalLibEnable}
                                                                                                                             
/* Component EO Client Libraries */                                                                                                                            

#define COMP_EO_CLIENTLIB_COR   ${corClLib}
#define COMP_EO_CLIENTLIB_CM    ${cmClLib}                  
#define COMP_EO_CLIENTLIB_NAME    ${nameClLib}                  
#define COMP_EO_CLIENTLIB_LOG    ${logClLib}                  
#define COMP_EO_CLIENTLIB_TRACE    CL_FALSE                 
#define COMP_EO_CLIENTLIB_DIAG    CL_FALSE
#define COMP_EO_CLIENTLIB_TXN    ${txnClLib}
#define COMP_EO_CLIENTLIB_MSO    ${msoLib}
#define COMP_EO_CLIENTLIB_PROV    ${provLib}
#define COMP_EO_CLIENTLIB_ALARM    ${alarmClLib}
#define COMP_EO_CLIENTLIB_DEBUG    ${debugClLib}
#define COMP_EO_CLIENTLIB_GMS    CL_FALSE
#define COMP_EO_CLIENTLIB_PM    ${pmLib}

#ifdef __cplusplus
}
#endif                                                                                                                             

#endif

""")

clConfigCFileTemplate = Template("""
/******************************************************************************
 *
 * clCompCfg.c
 *
 ***************************** Legal Notice ***********************************
 *
 * This file is autogenerated by OpenClovis IDE, Copyright (C) 2002-2009 by 
 * OpenClovis. All rights reserved.
 *
 ***************************** Description ************************************
 *
 * This file defines OpenClovis related component configuration.
 * 
 *****************************************************************************/

#include<clEoApi.h>
#include<clCompCfg.h>


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
    NULL,                       /* Application Initialize Callback          */
    NULL,                       /* Application Terminate Callback           */
    NULL,                       /* Application State Change Callback        */
    NULL,                       /* Application Health Check Callback        */
    NULL,
    ${needSerialization},
};

/*
 * Basic libraries used by this EO. The first 6 libraries are
 * mandatory, the others can be enabled or disabled by setting to
 * CL_TRUE or CL_FALSE.
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
 * Client libraries used by this EO. All are optional and can be
 * enabled or disabled by setting to CL_TRUE or CL_FALSE.
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
    COMP_EO_CLIENTLIB_PM        /* Lib: PM Management                       */
};

""")

compMakefileTemplate = Template("""
################################################################################
#
# This Makefile is auto-generated by OpenClovis IDE
#
# Makefile for ${exeName}
#
# This Makefile assumes the following:
#   - CLOVIS_ROOT environment variable is specified properly
#   - Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
################################################################################
include $(CLOVIS_ROOT)/SAFplus/mk/preface.mk

# Component name (using all lowercase):

EXENAME := ${exeName}

# List local source files needed for the component server:

SRC_FILES := $(wildcard *.c)
CPP_FILES := $(wildcard *.C) $(wildcard *.cxx)

# List other ASP components of which client libraries your component
# depends on:

DEP_COMP_LIST := utils osal timer buffer ioc rmd eo amf event ckpt dbal debug cor prov mso pm alarm om hal name txn idl log cm fault
# FIXME: Indirect dependencies via client library needs need to be
# added by hand for now:
DEP_COMP_LIST += cnt

${extraLibs}

# List ASP libraries needed to get this server built (or None):

ASP_LIBS := libmw.a

# List any third party libs needed to get this server built (or None):
THIRD_PARTY_EZXML_PATH = $(CLOVIS_ROOT)/ASP/3rdparty/ezxml/stable

EXTRA_CPPFLAGS := -I$(THIRD_PARTY_EZXML_PATH)


# Executable name (when building server exectuable):
# Notice the '=' in the assignment.

EXE_NAME = $(EXENAME)

CPPFLAGS += -I$(ASP_CONFIG) ${idlXdrInclude}

ifeq ($(ASP_BUILD),0)
	LDFLAGS += -Wl,-rpath-link $(ASP_LIBDIR)
endif

BUILD_CPLUSPLUS = ${Build_Cpp}

# ---BEGIN_APPLICATION_CODE---
# Note if you make changes only within these existing APPLICATION_CODE blocks,
# then your changes will be preserved even if you make modifications in the
# IDE and regenerate the source.

# Important variables:
# OBJ_DIR  - Where all the object files are generated
# LIB_DIR  - Where all the libs are generated
# BIN_DIR  - Where the final product is generated

# To add libraries to the link line and to the dependencies append them to 
# EXTRA_LDLIBS.  For example, let's make a library named "libmystuff.a":
# EXTRA_LDLIBS    += $(LIB_DIR)/libmystuff.a

# To recursively make in dependent subdirectories, append them to SUB_DIRS
# SUB_DIRS += 

# ---END_APPLICATION_CODE---
 
include $(CLOVIS_ROOT)/ASP/mk/make-server.mk

# ---BEGIN_APPLICATION_CODE---
# Define additional targets BELOW, so that they are not used as the default 
# target.

# To make specific additional targets (other then C or c++ files in this
# directory -- these are automatically added), add them here.  For example,
# to add a script that needs to be copied:
# all: $(BIN_DIR)/myScript

# Add the rules to build the additional targets here:
# For example:
# $(BIN_DIR)/myScript: myScript.sh
#       $(MKDIR) $(BIN_DIR)
#       $(CP) $< $@

# Above I had an example of an external library "libmystuff.a".  Now I must 
# define the target to build it.  Let us imagine that the source for this 
# library exists in a subdirectory called "common" off of the parent.

# $(LIB_DIR)/libmystuff.a: ../common/mystuff.c
#   $(MAKE) -C ../common

# Note that the OpenClovis defined make variables will still be defined in the
# invocation of this sub-makefile.  They must be used to ensure that binaries
# and libraries are placed in the correct directories, and that the correct
# compiler is used (the compiler changes when doing cross-builds).

# For more information (and an example Makefile) see the OpenClovis SDK user 
# guide.

# ---END_APPLICATION_CODE---

""")

extraLibTemplate = Template("""
EXTRA_SHARED_LDFLAGS =${libPaths}${libNames}
""")

snmpAgentMakefileTemplate = Template("""
################################################################################
#
# This Makefile is auto-generated by OpenClovis IDE
#
# Makefile for ${exeName}
#
# This Makefile assumes the following:
#   - CLOVIS_ROOT environment variable is specified properly
#   - Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
################################################################################
include $(CLOVIS_ROOT)/SAFplus/mk/preface.mk

# Component name (using all lowercase):

EXENAME := ${exeName}

# List local source files needed for the component server:

SRC_FILES := $(wildcard *.c)\\
             $(wildcard ./mib2c/*.c)\\
             $(wildcard ./mdl_config/*.c)\\
             $(wildcard ./static/*.c)
CPP_FILES := $(wildcard *.C) $(wildcard *.cxx)

# List other ASP components of which client libraries your component
# depends on:

DEP_COMP_LIST := utils osal timer buffer ioc rmd eo amf event ckpt dbal debug cor prov mso pm alarm om hal name txn idl log med cm fault
# FIXME: Indirect dependencies via client library needs need to be
# added by hand for now:
DEP_COMP_LIST += cnt

EXTRA_SHARED_LDFLAGS=-L$(ASP_LIB) -L/usr/local/lib${libPaths} -lpthread${libNames}

ifndef NET_SNMP_CONFIG
  ifdef WIND_VER
    NET_SNMP_CONFIG:=$(TOOLSCHAIN_DIR)/local/bin/net-snmp-config
  else
    NET_SNMP_CONFIG:=$(TOOLSCHAIN_DIR)/bin/net-snmp-config
  endif
endif

THIRDPARTY_LIBS=`$(NET_SNMP_CONFIG) --libs` `$(NET_SNMP_CONFIG) --agent-libs`

EXTRA_CFLAGS=-I. `$(NET_SNMP_CONFIG) --cflags` -I$(CLOVIS_ROOT)/ASP/components/alarm/include \
                 -I$(CLOVIS_ROOT)/ASP/components/amf/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/eo/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/name/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/med/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/cor/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/ioc/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/rmd/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/event/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/debug/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/buffer/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/cnt/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/utils/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/osal/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/timer/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/om/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/txn/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/log/include \\
                 -I$(CLOVIS_ROOT)/ASP/components/snmp/include \\
                 -I$(MODEL_PATH)/config \\
                 -I./mib2c \\
                 -I./mdl_config \\
                 -I./static \\
                 -DNETSNMP_NO_INLINE \\

EXTRA_CFLAGS += -D_CL_SNMP_SERVER_ -fno-strict-aliasing

# List ASP libraries needed to get this server built (or None):

ASP_LIBS := libmw.a

# List any third party libs needed to get this server built (or None):
THIRD_PARTY_EZXML_PATH = $(CLOVIS_ROOT)/ASP/3rdparty/ezxml/stable                                                                                                                                                                                    
                                                                                                                                                                                    
EXTRA_CPPFLAGS := -I$(THIRD_PARTY_EZXML_PATH)


# Executable name (when building server exectuable):
# Notice the '=' in the assignment.

EXE_NAME = $(EXENAME)

CPPFLAGS += -I$(ASP_CONFIG) ${idlXdrInclude}

ifeq ($(ASP_BUILD),0)
	LDFLAGS += -Wl,-rpath-link $(ASP_LIBDIR)
endif

BUILD_CPLUSPLUS = ${Build_Cpp}

# ---BEGIN_APPLICATION_CODE---


# ---END_APPLICATION_CODE---

include $(CLOVIS_ROOT)/ASP/mk/make-server.mk
# ---BEGIN_APPLICATION_CODE---


# ---END_APPLICATION_CODE---
""")


appMakeFileTemplate = Template("""

################################################################################
#
# 
# This Makefile is auto-generated by OpenClovis IDE
# Makefile for components
#
# This Makefile assumes the following:
#       - CLOVIS_ROOT environment variable is specified properly
#       - Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
################################################################################

# Subdirectories having Makefiles and need recursive escalation:
# common should always be before client and server

SUBDIRS = ${idlSubDir} ${compList}

ifeq ($(SNMP_BUILD),1)
    SUBDIRS += ${snmpAgent}
endif

#
# If you have any ordering dependence among subdirectories, list them as
# target-prerequisite pairs.
#

# ---BEGIN_APPLICATION_CODE---

# ---END_APPLICATION_CODE---

include $(CLOVIS_ROOT)/ASP/mk/make-subdir.mk

# ---BEGIN_APPLICATION_CODE---

# Additional targets can be defined here

# ---END_APPLICATION_CODE---

""")

clCompPortHeaderFileTemplate = Template("""
/*******************************************************************************
*
* This headerfile is auto-generated by OpenClovis IDE
*
* clCompPorts.h
*
********************************************************************************/

#ifndef CL_COMP_PORT
#define CL_COMP_PORT

#ifdef __cplusplus
extern "C" {
#endif

/* Component EO port ids */
${portIdDefs}

#ifdef __cplusplus
}
#endif                                                                                                                             

#endif

""")

portIdDefTemplate = Template("""
#define ${compName}_PORT			${iocPort}
""")
