# Copyright (C) 2002-2012 OpenClovis Solutions Inc.  All Rights Reserved.
# This file is available  under  a  commercial  license  from  the
# copyright  holder or the GNU General Public License Version 2.0.
#
# The source code for  this program is not published  or otherwise
# divested of  its trade secrets, irrespective  of  what  has been
# deposited with the U.S. Copyright office.
#
# This program is distributed in the  hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied  warranty  of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# For more  information,  see the  file COPYING provided with this
# material.


# This file is included at the top of all other makefiles
# It discovers the environment and sets standard variables.

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
SAFPLUS_HA_DIR ?= $(patsubst %/,%, $(dir $(realpath $(mkfile_path)/..)))

# Link with Google's performance toolkit http://code.google.com/p/gperftools
# GPERFTOOLS := 1
ifeq ($(SAFPLUS_HA_DIR),/opt/safplus/7.0/sdk)
SAFPLUS_HA_INSTALLED:=1
endif

#ifdef S7  # SAFplus v7
$(info Using SAFplus7 located in $(SAFPLUS_HA_DIR))

#? By default we link with the local Linux distribution's installed libraries.  Override this to 0 if you are doing a crossbuild.
USE_DIST_LIB ?= 1  

#? If this is included from an application makefile, the application build may choose to not build SAFplus 
ifndef SAFPLUS_HA_INSTALLED  # by default don't build HA if we are getting it from the installed location
BUILD_SAFPLUS ?=1
else
BUILD_SAFPLUS ?=0
endif

SAFPLUS_MAKE_DIR := $(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))

#$(info A: $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
#$(info B: $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
#$(info C: $(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST))))))
#$(info D: $(patsubst %/,%,$(dir $(realpath $(SAFPLUS_MAKE_DIR)))))

ifdef CROSS
include $(SAFPLUS_MAKE_DIR)/$(CROSS)
SYSTEM_INC_DIR ?= $(CROSS_SYS_ROOT)/usr/include
$(info Running crossbuild using definitions in $(SAFPLUS_MAKE_DIR)/$(CROSS), g++ is $(COMPILER), sysroot is $(CROSS_SYS_ROOT))
else
SYSTEM_INC_DIR ?= /usr/include
$(info Native build)
endif

SAFPLUS_SRC_DIR ?= $(patsubst %/,%,$(dir $(realpath $(SAFPLUS_MAKE_DIR))))
SAFPLUS_TOP_DIR ?= $(patsubst %/,%,$(dir $(realpath $(SAFPLUS_SRC_DIR))))
SAFPLUS_INC_DIR ?= $(SAFPLUS_SRC_DIR)/include
SAFPLUS_3RDPARTY_DIR ?= $(SAFPLUS_SRC_DIR)/3rdparty

$(info SAFplus source: $(SAFPLUS_SRC_DIR))
$(info SAFplus include: $(SAFPLUS_INC_DIR))
$(info System include: $(SYSTEM_INC_DIR))

COMPILER ?= g++
LOCAL_COMPILER ?= g++

# we need to have -Wno-deprecated-warnings because boost uses std::auto_ptr
COMPILE_CPP ?= $(COMPILER) -std=c++11 -Wno-deprecated-declarations  -g -O0 -fPIC -c $(CPP_FLAGS) -o
LINK_SO     ?= $(COMPILER) $(LINK_FLAGS) -g -shared -o
LINK_EXE    ?= $(COMPILER) -g -O0 -fPIC $(LINK_FLAGS) -o

# Use these variables if you are building something to run on the local machine (a tool or something)
LOCAL_COMPILE_CPP ?= $(LOCAL_COMPILER) -std=c++11 -Wno-deprecated-declarations  -g -O0 -fPIC -c $(LOCAL_CPP_FLAGS) -o
LOCAL_LINK_SO     ?= $(LOCAL_COMPILER) $(LOCAL_LINK_FLAGS) -g -shared -o
LOCAL_LINK_EXE    ?= $(LOCAL_COMPILER) -g -O0 -fPIC $(LOCAL_LINK_FLAGS) -o
LOCAL_TARGET_OS ?= $(shell uname -r)
__TMP_LOCAL_TARGET_PLATFORM := $(shell $(LOCAL_COMPILER) -dumpmachine)
LOCAL_TARGET_PLATFORM ?= $(__TMP_LOCAL_TARGET_PLATFORM)

LINK_LIBS ?=

TARGET_OS ?= linux # $(shell uname -r)
__TMP_TARGET_PLATFORM := $(shell $(COMPILER) -dumpmachine)
TARGET_PLATFORM ?= $(__TMP_TARGET_PLATFORM)

MGT_SRC_DIR ?= $(SAFPLUS_SRC_DIR)/../../mgt
TAE_DIR ?= $(SAFPLUS_SRC_DIR)/../../tae

# create the necessary directories for building SAFplus
ifeq ($(BUILD_SAFPLUS),1)
NOOP := $(shell mkdir -p $(SAFPLUS_SRC_DIR)/../target/$(strip $(TARGET_PLATFORM)))
NOOP := $(shell mkdir -p $(SAFPLUS_SRC_DIR)/../target/$(LOCAL_TARGET_PLATFORM))
endif

__TMP_SAFPLUS_TARGET := $(shell (cd $(SAFPLUS_SRC_DIR)/../target/$(strip $(TARGET_PLATFORM)); pwd))
SAFPLUS_TARGET ?= $(__TMP_SAFPLUS_TARGET)

# Put compilation tools (that you have to build) here
__TMP_SAFPLUS_TOOL_TARGET := $(shell (cd $(SAFPLUS_SRC_DIR)/../target/$(LOCAL_TARGET_PLATFORM); pwd))
SAFPLUS_TOOL_TARGET ?= $(__TMP_SAFPLUS_TOOL_TARGET)

SAFPLUS_CODEBLOCKS_BIN_DIR ?= /opt/SAFplus/7.0/ide/bin/

# NOOP := $(shell echo $(SAFPLUS_TARGET))

#? All 3rdparty libs, etc will go here by default i.e. configure --prefix=$(INSTALL_DIR)
INSTALL_DIR ?=  $(SAFPLUS_TARGET)/install
TEST_DIR ?= $(SAFPLUS_TARGET)/test
LIB_DIR ?= $(SAFPLUS_TARGET)/lib
PLUGIN_DIR ?= $(SAFPLUS_TARGET)/plugin
BIN_DIR ?= $(SAFPLUS_TARGET)/bin
# All objects that should end up into libmw.so:
MWOBJ_DIR ?= $(SAFPLUS_TARGET)/mwobj
# All other objects
OBJ_DIR ?= $(SAFPLUS_TARGET)/obj

LOCAL_OBJ_DIR ?= $(SAFPLUS_TOOL_TARGET)/obj

# Figure out which protobuf
TMP:=$(shell which protoc) # Forces the evaluation right now
ifeq ($(strip $(TMP)),)
TMP := $(INSTALL_DIR)/bin/protoc

endif
PROTOC ?= $(TMP)

PROTOBUFVER ?= p$(word 2,$(shell $(PROTOC) --version))
$(info protoc is $(PROTOC). Protobuf version is $(PROTOBUFVER))

$(info SAFplus libraries: $(LIB_DIR))
$(info )
ifeq ($(BUILD_SAFPLUS),1)
NOOP := $(shell mkdir -p $(INSTALL_DIR))
NOOP := $(shell mkdir -p $(TEST_DIR))
NOOP := $(shell mkdir -p $(LIB_DIR))
NOOP := $(shell mkdir -p $(BIN_DIR))
NOOP := $(shell mkdir -p $(PLUGIN_DIR))
NOOP := $(shell mkdir -p $(MWOBJ_DIR))
NOOP := $(shell mkdir -p $(OBJ_DIR))
NOOP := $(shell mkdir -p $(SAFPLUS_TOOL_TARGET)/bin)
endif

PKG_CONFIG_PATH ?= /lib/pkgconfig:$(INSTALL_DIR)/lib/pkgconfig
LOCAL_PKG_CONFIG_PATH ?= /lib/pkgconfig:$(LOCAL_INSTALL_DIR)/lib/pkgconfig
PKG_CONFIG ?= PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config

# Determine XML2 location
PKG_XML2_CFLAGS ?= $(shell $(PKG_CONFIG) --cflags libxml-2.0)
ifeq ($(strip $(PKG_XML2_CFLAGS)),)
$(info pkg-config was unable to determine libxml-2.0 header file location.  Using default)
XML2_CFLAGS ?= -I$(SAFPLUS_SRC_DIR)/3rdparty/base/libxml2-2.9.0/include
else
XML2_CFLAGS ?= $(PKG_XML2_CFLAGS)
endif

PKG_XML2_LINK ?=$(shell $(PKG_CONFIG) --libs libxml-2.0)
ifeq ($(strip $(PKG_XML2_LINK)),)
$(info pkg-config was unable to determine libxml-2.0 location.  Using default)
XML2_LINK ?= -L$(INSTALL_DIR)/lib -lxml2
else
XML2_LINK ?= $(PKG_XML2_LINK)
endif

#? Flags (include directories) needed to compile programs using the SAFplus Mgt component.
SAFPLUS_MGT_INC_FLAGS := -I$(SAFPLUS_SRC_DIR)/mgt $(XML2_CFLAGS)

# Determine boost location
# For SAFplus RPM/DEBIAN package generation, distribution provided libraries need to be used
ifeq ($(strip $(USE_DIST_LIB)),0)
DISTRIBUTION_LIB = 0
BOOST_INC_DIR ?= $(INSTALL_DIR)/include
# $(shell (cd $(SAFPLUS_SRC_DIR)/../../boost; pwd))
BOOST_LIB_DIR ?= $(INSTALL_DIR)/lib
else
DISTRIBUTION_LIB = 1
BOOST_INC_DIR = $(SYSTEM_INC_DIR)
# Need to fix the BOOST_LIB_DIR path for handling various linux distributions
BOOST_LIB_DIR ?= /usr/lib:/usr/lib64
endif

ifdef GPERFTOOLS
GPERFTOOLS_LINK := -ltcmalloc
else
GPERFTOOLS_LINK :=
endif

# Determine protobuf location

ifeq ($(TARGET_PLATFORM),i686-linux-gnu)  # Nasty hardcoding because g++ -dumpmachine uses i686- but linux directory structure uses i386-
PROTOBUF_LIB_DIR ?= /usr/lib/i386-linux-gnu
else
PROTOBUF_LIB_DIR ?= /usr/lib/$(TARGET_PLATFORM)
endif

ifeq ($(LOCAL_TARGET_PLATFORM),i686-linux-gnu)  # Nasty hardcoding because g++ -dumpmachine uses i686- but linux directory structure uses i386-
LOCAL_PROTOBUF_LIB_DIR ?= /usr/lib/i386-linux-gnu
else
LOCAL_PROTOBUF_LIB_DIR ?= /usr/lib/$(LOCAL_TARGET_PLATFORM)
endif

PROTOBUF_LINK ?= -L$(PROTOBUF_LIB_DIR) $(shell PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config --libs protobuf) -lprotoc
PROTOBUF_FLAGS ?= $(shell PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config --cflags protobuf)

LOCAL_PROTOBUF_LINK ?= -L/usr/lib -L$(LOCAL_PROTOBUF_LIB_DIR) -lprotobuf -lprotoc
LOCAL_PROTOBUF_FLAGS ?= $(shell PKG_CONFIG_PATH=$(PKG_CONFIG_PATH) pkg-config --cflags protobuf)

$(info PKG_CONFIG_PATH: $(PKG_CONFIG_PATH)  PROTOBUF_FLAGS is $(PROTOBUF_FLAGS) PROTOBUF_LINK is $(PROTOBUF_LINK))
$(info LOCAL_PROTOBUF_FLAGS is $(LOCAL_PROTOBUF_FLAGS) LOCAL_PROTOBUF_LINK is $(LOCAL_PROTOBUF_LINK) local cfg path is $(LOCAL_PKG_CONFIG_PATH))

ifdef SAFPLUS_WITH_BOOST_CHRONO
  ifeq ($(strip $(SAFPLUS_WITH_BOOST_CHRONO)),true)
    BOOST_CHRONO_LIB:=-lboost_chrono
    BOOST_CHRONO_CFLAGS:=-DUSE_BOOST_CHRONO
  else
    BOOST_CHRONO_LIB:=
    BOOST_CHRONO_CFLAGS:=
  endif
else
  BOOST_CHRONO_LIB:=-lboost_chrono
  BOOST_CHRONO_CFLAGS:=-DUSE_BOOST_CHRONO
endif

LINK_STD_LIBS += $(PROTOBUF_LINK) -L$(BOOST_LIB_DIR) -lboost_thread $(BOOST_CHRONO_LIB) -lboost_system -lboost_filesystem -lpthread -lrt -ldl $(GPERFTOOLS_LINK)
LINK_SO_LIBS += $(PROTOBUF_LINK) -L$(BOOST_LIB_DIR) -lboost_thread $(BOOST_CHRONO_LIB) -lboost_system -lboost_filesystem -lpthread -lrt -ldl $(GPERFTOOLS_LINK)

CPP_FLAGS := $(CPP_FLAGS) -I$(SAFPLUS_INC_DIR) -I$(BOOST_INC_DIR) $(PROTOBUF_FLAGS) -I. -I$(SYSTEM_INC_DIR) -DSAFplus7 $(BOOST_CHRONO_CFLAGS)
LOCAL_CPP_FLAGS := $(CPP_FLAGS) -I$(BOOST_INC_DIR) $(PROTOBUF_FLAGS) -I. -DSAFplus7 $(BOOST_CHRONO_CFLAGS)

ifdef GNU_PROFILE
CPP_FLAGS += -pg
LINK_FLAGS += -pg
endif

PYANG_PLUGINPATH_EXT ?= $(PYANG_PLUGINPATH)
ifeq ($(PYANG_PLUGINPATH_EXT),)
export PYANG_PLUGINPATH:=$(shell pwd)
endif

SAFplusRpcGen ?= $(SAFPLUS_TOOL_TARGET)/bin/protoc-gen-rpc

# Function to do Management codegen from .yang
define SAFPLUS_YANG_GEN
	PYTHONPATH=$(MGT_SRC_DIR)/3rdparty/pyang PYANG_PLUGINPATH=$(MGT_SRC_DIR)/pyplugin $(MGT_SRC_DIR)/3rdparty/pyang/bin/pyang --path=$(SAFPLUS_SRC_DIR)/yang -f y2cpp $(strip $1) --y2cpp-output=$(strip $2) --y2cpp-sdkdir $(SAFPLUS_SRC_DIR)
endef


# Function to do RPC codegen from .yang
define SAFPLUS_YANG_RPC_GEN
	PYTHONPATH=$$PYTHONPATH:$(MGT_SRC_DIR)/3rdparty/pyang:/usr/local/lib PYANG_PLUGINPATH=$$PYANG_PLUGINPATH:$(MGT_SRC_DIR)/pyplugin $(MGT_SRC_DIR)/3rdparty/pyang/bin/pyang --path=$(SAFPLUS_SRC_DIR)/yang -f y2cpp $(strip $1).yang --y2cpp-output=`pwd` --y2cpp-sdkdir=$(SAFPLUS_SRC_DIR) --y2cpp-rpc
	LD_LIBRARY_PATH=/usr/local/lib:/usr/lib protoc -I$(SAFPLUS_3RDPARTY_DIR) -I$(dir $1.proto) -I$(SAFPLUS_SRC_DIR)/rpc --cpp_out=$(PROTOBUFVER)/$(strip $2) $(strip $1).proto
	LD_LIBRARY_PATH=/usr/local/lib:/usr/lib $(SAFplusRpcGen) -I$(SAFPLUS_3RDPARTY_DIR) -I$(dir $1.proto) -I$(SAFPLUS_SRC_DIR)/rpc --rpc_out=$(PROTOBUFVER)/$(strip $2) --rpc_opts=$(strip $3) $(strip $1).proto
endef

#1. Google protoc generated
#2. Rename pb.h => pb.hxx, pb.cc => pb.cxx if param = true
#3. Code generated fro SAFplus RPC architecture 
define SAFPLUS_RPC_GEN
	$(PROTOC) -I$(SAFPLUS_3RDPARTY_DIR) -I$(dir $1.proto) -I$(SAFPLUS_SRC_DIR)/rpc --cpp_out=$(PROTOBUFVER)/$2 $1.proto
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:/usr/local/lib:/usr/lib $(SAFplusRpcGen) -I$(SAFPLUS_3RDPARTY_DIR) -I$(dir $1.proto) -I$(SAFPLUS_SRC_DIR)/rpc --rpc_out=$(PROTOBUFVER)/$2 --rpc_opts=$(strip $3) $1.proto
endef

$(info local obj: $(LOCAL_OBJ_DIR) local tgt: $(SAFPLUS_TOOL_TARGET) local compiler: $(LOCAL_COMPILE_CPP))
