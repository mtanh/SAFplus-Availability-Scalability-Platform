################################################################################
# ModuleName  : SampleModel
# $File$
# $Author$
# $Date$
################################################################################
# Description :
# usage: python clConfig.py <args>
# create clCompConfig.h
###############################################################################
import sys
import string
import os
import xml.dom.minidom
from string import Template
from string import upper, lower
import time
import getpass
import shutil

clConfigHeaderFileTemplate = Template("""
/*******************************************************************************
*
* This headerfile is auto-generated by OpenClovis IDE
*
* clCompConfig.h for ${cpmName}
*
* 
* Date: ${DateTime}
* User: ${User} 
* 
*
********************************************************************************/

#ifndef CL_COMP_CFG
#define CL_COMP_CFG

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
#define COMP_EO_CLIENTLIB_NA    CL_FALSE
#define COMP_EO_CLIENTLIB_PROV    ${provLib}
#define COMP_EO_CLIENTLIB_ALARM    ${alarmClLib}
#define COMP_EO_CLIENTLIB_DEBUG    ${debugClLib}
#define COMP_EO_CLIENTLIB_GMS    CL_FALSE
                                                                                                                             
#endif

""")

compMakefileTemplate = Template("""
################################################################################
#
# This Makefile is auto-generated by OpenClovis IDE
#
# Makefile for ${exeName}
#
# This Makefile assumes the following:
#	- CLOVIS_ROOT environment variable is specified properly
#	- Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
# 
# Date: ${DateTime}
# User: ${User} 
# 
#
################################################################################

# Component name (using all lowercase):

EXENAME	:= ${exeName}

# List local source files needed for the component server:

SRC_FILES	:= $(wildcard *.c)

# List other ASP components of which client libraries your component
# depends on:

DEP_COMP_LIST	:= utils osal timer buffer ioc rmd eo amf event ckpt dbal debug cor prov alarm om hal name txn idl log
# FIXME: Indirect dependencies via client library needs need to be
# added by hand for now:
DEP_COMP_LIST	+= cnt

# List ASP libraries needed to get this server built (or None):

ASP_LIBS	:= libClTimer.a  \\
		\tlibClBuffer.a  \\
		\tlibClOsal.a  \\
		\tlibClCnt.a  \\
		\t${omClientLib} \\
		\tlibClHal.a  \\
		\tlibClCorClient.a  \\
		\tlibClEo.a  \\
		\t${cmClientLib} \\
		\t${provClientLib} \\
		\t${alarmClientLib} \\
		\tlibClIoc.a \\
		\tlibClRmd.a \\
		\tlibClUtils.a \\
		\tlibClAmfClient.a \\
		\tlibClDbal.a \\
		\tlibClGDBM.so \\
		\tlibClCkpt.a \\
		\tlibClEventClient.a \\
		\tlibClTxnAgent.a  \\
		\tlibClLogClient.a \\
		\tlibClIdl.a  \\
		\tlibClDebugClient.a \\
		\tlibClNameClient.a \\
		${idlLib}
                   
# List any third party libs needed to get this server built (or None):
THIRD_PARTY_EZXML_PATH = $(CLOVIS_ROOT)/ASP/3rdparty/ezxml/stable                                                                                                                                                                                    
                                                                                                                                                                                    
EXTRA_CPPFLAGS  := -I$(THIRD_PARTY_EZXML_PATH)


# List any system libraries needed to get this server built (or None):

SYS_LIBS	:= -lpthread -lgdbm -ldl

# Executable name (when building server exectuable):
# Notice the '=' in the assignment.

EXE_NAME	= $(EXENAME)

CPPFLAGS   += -I$(ASP_CONFIG)

include $(CLOVIS_ROOT)/ASP/mk/make-server.mk
""")

snmpAgentMakefileTemplate = Template("""
################################################################################
#
# This Makefile is auto-generated by OpenClovis IDE
#
# Makefile for ${exeName}
#
# This Makefile assumes the following:
#	- CLOVIS_ROOT environment variable is specified properly
#	- Entire source tree under $(CLOVIS_ROOT)/ASP is checked out
#
# 
# Date: ${DateTime}
# User: ${User} 
# 
#
################################################################################

# Component name (using all lowercase):

EXENAME	:= ${exeName}

# List local source files needed for the component server:

SRC_FILES	:= $(wildcard *.c)\\
	    \t$(wildcard ./mib2c/*.c)\\
		\t$(wildcard ./mdl_config/*.c)\\
		\t$(wildcard ./static/*.c)

# List other ASP components of which client libraries your component
# depends on:

DEP_COMP_LIST	:= utils osal timer buffer ioc rmd eo amf event ckpt dbal debug cor prov alarm om hal name txn idl log med
# FIXME: Indirect dependencies via client library needs need to be
# added by hand for now:
DEP_COMP_LIST	+= cnt

EXTRA_SHARED_LDFLAGS=-L$(ASP_LIB) -L/usr/local/lib -lpthread

THIRDPARTY_LIBS=`net-snmp-config --libs` `net-snmp-config --agent-libs`

EXTRA_CFLAGS=-I. `net-snmp-config --cflags` -I$(CLOVIS_ROOT)/ASP/components/alarm/include \
				\t-I$(CLOVIS_ROOT)/ASP/components/amf/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/eo/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/name/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/med/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/cor/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/ioc/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/rmd/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/event/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/debug/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/buffer/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/cnt/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/utils/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/osal/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/timer/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/om/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/txn/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/log/include \\
				\t-I$(CLOVIS_ROOT)/ASP/components/snmp/include \\
				\t-I$(MODEL_PATH)/config \\
				\t-I./mib2c \\
				\t-I./mdl_config \\
				\t-I./static \\

EXTRA_CFLAGS += -D_CL_SNMP_SERVER_ -fno-strict-aliasing

# List ASP libraries needed to get this server built (or None):

ASP_LIBS	:= libClTimer.a  \\
		\tlibClBuffer.a  \\
		\tlibClOsal.a  \\
		\tlibClCnt.a  \\
		\t${omClientLib} \\
		\tlibClHal.a  \\
		\tlibClCorClient.a  \\
		\tlibClEo.a  \\
		\t${cmClientLib} \\
		\t${provClientLib} \\
		\t${alarmClientLib} \\
		\tlibClIoc.a \\
		\tlibClRmd.a \\
		\tlibClUtils.a \\
		\tlibClAmfClient.a \\
		\tlibClDbal.a \\
		\tlibClGDBM.so \\
		\tlibClCkpt.a \\
		\tlibClEventClient.a \\
		\tlibClTxnAgent.a  \\
		\tlibClLogClient.a \\
		\tlibClIdl.a  \\
		\tlibClDebugClient.a \\
		\tlibClNameClient.a \\
        \tlibClMedClient.a\\
		${idlLib}
                   
# List any third party libs needed to get this server built (or None):
THIRD_PARTY_EZXML_PATH = $(CLOVIS_ROOT)/ASP/3rdparty/ezxml/stable                                                                                                                                                                                    
                                                                                                                                                                                    
EXTRA_CPPFLAGS  := -I$(THIRD_PARTY_EZXML_PATH)


# List any system libraries needed to get this server built (or None):

SYS_LIBS	:= -lpthread -lgdbm -ldl

# Executable name (when building server exectuable):
# Notice the '=' in the assignment.

EXE_NAME	= $(EXENAME)

CPPFLAGS   += -I$(ASP_CONFIG)

include $(CLOVIS_ROOT)/ASP/mk/make-server.mk
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
# Date: ${DateTime}
# User: ${User} 
#
################################################################################
                                                                                                                                                                                    
# Subdirectories having Makefiles and need recursive escalation:
# common should always be before client and server
                                                                                                                                                                                    
SUBDIRS          = ${idlSubDir} ${compList}
                                                                                                                                                                                    
#
# If you have any ordering dependence among subdirectories, list them as
# target-prerequisite pairs.
#
                                                                                                                                                                                    
include $(CLOVIS_ROOT)/ASP/mk/make-subdir.mk

""")

#------------------------------------------------------------------------------
def processComponent(cmpList, connList):

	global idlFile
	global globalEOMap
	idlExists = 0
	eoList = []
       	if os.path.exists(idlFile):       	    
		idlDoc  = xml.dom.minidom.parse(idlFile)
		eoList = idlDoc.getElementsByTagName("EO")
		idlExists = 1
	symbolMap = dict()
	for cmp in cmpList:
		cpmName = cmp.attributes["Name"].value
		cpmName = string.replace(cpmName, " ", "_")
		cpmName = string.replace(cpmName, "-", "_")
		symbolMap["cpmName"] = cpmName
		eo = cmp.getElementsByTagName("EOProperties")[0]
		symbolMap["eoName"]        = eo.attributes["eoname"].value
		symbolMap["eoThreadPri"]   = eo.attributes["threadpriority"].value
		eoThreadCount = int(eo.attributes["threadcount"].value)
		#Mininum Thread Count should be 2.
		if eoThreadCount < 2:
		    eoThreadCount = 2
		symbolMap["eoNumThread"]   = eoThreadCount
		symbolMap["iocPort"]       = eo.attributes["iocportnumber"].value
		symbolMap["threadPolicy"]  = eo.attributes["mainthreadusagepolicy"].value
		symbolMap["eoName"]  = eo.attributes["eoname"].value
		symbolMap["maxNoClients"]  = eo.attributes["maxNoClients"].value
		eoThreadPriority = eo.attributes["threadpriority"].value
		if eoThreadPriority == "PRIORITY_LOW":
			eoThreadPriority = "CL_OSAL_THREAD_PRI_LOW"
		if eoThreadPriority == "PRIORITY_MEDIUM":
			eoThreadPriority = "CL_OSAL_THREAD_PRI_MEDIUM"
		if eoThreadPriority == "PRIORITY_HIGH":
			eoThreadPriority = "CL_OSAL_THREAD_PRI_HIGH"		
		symbolMap["eoThreadPriority"] = eoThreadPriority
			
		libObj = eo.getElementsByTagName("basiclib")[0]
		cliObj = eo.getElementsByTagName("eoclientlib")[0]

		symbolMap["omLibEnable"]   = libObj.attributes["OM"].value
		symbolMap["halLibEnable"]  = libObj.attributes["HAL"].value
		symbolMap["dbalLibEnable"] = libObj.attributes["DBAL"].value

		symbolMap["corClLib"]      = cliObj.attributes["COR"].value
		symbolMap["cmClLib"]       = cliObj.attributes["CM"].value
		symbolMap["nameClLib"]     = cliObj.attributes["NameService"].value
		symbolMap["logClLib"]      = cliObj.attributes["LOG"].value
		symbolMap["traceClLib"]    = cliObj.attributes["Trace"].value
		symbolMap["diagClLib"]     = cliObj.attributes["Diagnostics"].value
		symbolMap["txnClLib"]      = cliObj.attributes["Transaction"].value        
		symbolMap["provLib"]      = cliObj.attributes["Prov"].value
		symbolMap["alarmClLib"]    = cliObj.attributes["Alarm"].value
		symbolMap["debugClLib"]    = cliObj.attributes["Debug"].value        

		symbolMap["hasEOServices"] = 0
		globalEOMap[cpmName] = 0
		if idlExists == 1:
			for eo in eoList:
				eoName = symbolMap["eoName"]
				if eo.attributes["name"].value == symbolMap["eoName"]:
					serviceList = eo.getElementsByTagName("Service")
					if len(serviceList) > 0:
						symbolMap["hasEOServices"] = 1
						globalEOMap[cpmName] = eoName
				
		result = clConfigHeaderFileTemplate.safe_substitute(symbolMap, DateTime=date, User=user)
		if os.path.exists(cpmName) == False:       	    
			os.mkdir(cpmName)   
		    
		file = cpmName + "/" + "clCompCfg.h"     
		fd = open(file , "w")
		fd.write(result)
		fd.close()
		isSNMPAgent = "false"
		try:
			isSNMPAgent = cmp.attributes["isSNMPSubAgent"].value
		except:
			print ""
		snmpdestApphFile = cpmName + "/" + snmpTemplateApphFile
		snmpdestAppCFile = cpmName + "/" + snmpTemplateAppCFile
		destApphFile = cpmName + "/" + templateApphFile
		destAppCFile = cpmName + "/" + templateAppCFile
		proxydestApphFile = cpmName + "/" + proxyTemplateApphFile
		proxydestAppCFile = cpmName + "/" + proxyTemplateAppCFile
		if isSNMPAgent == "true":
				if os.path.isfile(destApphFile):
					os.remove(destApphFile)
				if os.path.isfile(destAppCFile):
					os.remove(destAppCFile)
				if os.path.isfile(proxydestApphFile):
					os.remove(proxydestApphFile)
				if os.path.isfile(proxydestAppCFile):
					os.remove(proxydestAppCFile)
				if (codeGenMode == "true") or not (os.path.isfile(snmpdestApphFile)):
					shutil.copyfile(snmpTemplateApphFilePath, snmpdestApphFile)
				if (codeGenMode == "true") or not (os.path.isfile(snmpdestAppCFile)):
					shutil.copyfile(snmpTemplateAppCFilePath, snmpdestAppCFile)
		else:
			if os.path.isfile(snmpdestApphFile):
				os.remove(snmpdestApphFile)
			if os.path.isfile(snmpdestAppCFile):
				os.remove(snmpdestAppCFile)
			isProxy = isProxyComponent(cmp, connList)
			if isProxy == "false":
				if os.path.isfile(proxydestApphFile):
					os.remove(proxydestApphFile)
				if os.path.isfile(proxydestAppCFile):
					os.remove(proxydestAppCFile)
				if (codeGenMode == "true") or not (os.path.isfile(destApphFile)):
					shutil.copyfile(templateApphFilePath, destApphFile)
				if (codeGenMode == "true") or not (os.path.isfile(destAppCFile)):
					shutil.copyfile(templateAppCFilePath, destAppCFile)
			else:
				if os.path.isfile(destApphFile):
					os.remove(destApphFile)
				if os.path.isfile(destAppCFile):
					os.remove(destAppCFile)
				if (codeGenMode == "true") or not (os.path.isfile(proxydestApphFile)):
					shutil.copyfile(proxyTemplateApphFilePath, proxydestApphFile)
				if (codeGenMode == "true") or not (os.path.isfile(proxydestAppCFile)):
					shutil.copyfile(proxyTemplateAppCFilePath, proxydestAppCFile)
#------------------------------------------------------------------------------
def isProxyComponent(comp, connList):
	compKey = comp.attributes["CWKEY"].value
	for conn in connList:
		startKey = conn.attributes["Start"].value
		if startKey == compKey:
			return "true"
	return "false"
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
#Script Execution Starts Here.
date = unicode(time.strftime("%D at %H:%M:%S", time.localtime()))
user = getpass.getuser()

templatedir = sys.argv[2] 
codeGenMode = sys.argv[3]
idlFile = sys.argv[4]
globalEOMap = dict()

templateApphFile="clCompAppMain.h"
templateAppCFile="clCompAppMain.c"
templateApphFilePath=templatedir + "/" + "clCompAppMain.h"
templateAppCFilePath=templatedir + "/" + "clCompAppMain.c"


proxyTemplateApphFile="clProxyCompAppMain.h"
proxyTemplateAppCFile="clProxyCompAppMain.c"
proxyTemplateApphFilePath=templatedir + "/" + "clProxyCompAppMain.h"
proxyTemplateAppCFilePath=templatedir + "/" + "clProxyCompAppMain.c"

snmpTemplateApphFile="clSnmpAppMain.h"
snmpTemplateAppCFile="clSnmpAppMain.c"
snmpTemplateApphFilePath=templatedir + "/" + snmpTemplateApphFile
snmpTemplateAppCFilePath=templatedir + "/" + snmpTemplateAppCFile


componentXml  = sys.argv[1]
componentDoc  = xml.dom.minidom.parse(componentXml)
componentList = componentDoc.getElementsByTagName("component:SAFComponent");
relationList = componentDoc.getElementsByTagName("component:Relation");
proxyProxiedList = []
for relation in relationList:
	connType = relation.attributes["Type"].value
	if connType == "Proxy_Proxied":
		proxyProxiedList.append(relation)
processComponent(componentList, proxyProxiedList)
#Generate Makefile for App
compList = ""
appMakefile = open("Makefile", "w")
for component in componentList:
	cpmName = component.attributes["Name"].value
	compList += cpmName + " "

idlExists=0
#------------------------------------------------------------------------------

#Generate Makefile for each Component 
for component in componentList:
	cpmName = component.attributes["Name"].value
	map = dict()
	map["DateTime"]=date
	map["User"]=user
	map["compName"] = cpmName
	imageName = component.attributes["InstantiationCMD"].value
	if imageName == None or imageName == "":
		imageName = "asp_" + cpmName
	map["exeName"] = imageName
	map["cmClientLib"] = ""
	map["alarmClientLib"] = ""
	map["omClientLib"] = ""
	map["provClientLib"] = ""
	eo = component.getElementsByTagName("EOProperties")[0]
	cliObj = eo.getElementsByTagName("eoclientlib")[0]
	
	if cliObj.attributes["CM"].value == "CL_TRUE":
		map["cmClientLib"] = "libClCm.a"
		
	if cliObj.attributes["Alarm"].value == "CL_TRUE":
		map["alarmClientLib"] = "libClAlarmClient.a"

	if cliObj.attributes["Prov"].value == "CL_TRUE":
		map["provClientLib"] = "libClProv.a"

	basicLibObj = eo.getElementsByTagName("basiclib")[0]
	if basicLibObj.attributes["OM"].value == "CL_TRUE":
		map["omClientLib"] = "libClOmClient.a"

	map["idlLib"] = ""
	if globalEOMap[cpmName] != 0:
		idlExists = 1
		eoName = globalEOMap[cpmName];
		EoName = upper(eoName[0]) + eoName[1:]
		map["idlLib"] = "libCl" + EoName + "Server.a"

	file = cpmName + "/Makefile" 	
	compMakefile = open(file, "w")
	isSNMPAgent = "false"
	try:
		isSNMPAgent = component.attributes["isSNMPSubAgent"].value
	except:
		print ""
	if isSNMPAgent == "true":
		compMakefile.write(snmpAgentMakefileTemplate.safe_substitute(map))
	else:
		compMakefile.write(compMakefileTemplate.safe_substitute(map))
	compMakefile.close()

idlSubDir = ""
if idlExists == 1:
	idlSubDir = "idl"
appMakefile.write(appMakeFileTemplate.safe_substitute(compList = compList, DateTime = date, User = user, idlSubDir = idlSubDir))
appMakefile.close()
	
