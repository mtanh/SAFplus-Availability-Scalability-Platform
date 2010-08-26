#!/bin/bash
###############################################################################
#
# Copyright (C) 2002-2009 by OpenClovis Inc. All  Rights Reserved.
# 
# The source code for  this program is not published  or otherwise 
# divested of  its trade secrets, irrespective  of  what  has been 
# deposited with the U.S. Copyright office.
# 
# This program is  free software; you can redistribute it and / or
# modify  it under  the  terms  of  the GNU General Public License
# version 2 as published by the Free Software Foundation.
# 
# This program is distributed in the  hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied  warranty  of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
# 
# You  should  have  received  a  copy of  the  GNU General Public
# License along  with  this program. If  not,  write  to  the 
# Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#
###############################################################################

/bin/echo -e "\nPrerequisite installation\n\nThis script installs required software using your distribution's package\nmanager.  It will either need your CDROMs or access the packages over the\ninternet, depending on your package manager's configuration.\n\nIt must be run as root.\n\n"

if [ `whoami` != "root" ] ; then
/bin/echo -e "\nYou must be root to run this installer."
exit 2
fi

if [ -e /usr/bin/yum ] ; then
/bin/echo
else
/bin/echo -e "\nThe package manager yum (/usr/bin/yum) does not exist.\nYour installation is either corrupt or not Fedora."
exit 1
fi

function updateKernel() {
echo -e "\nThe machine must be updated to latest offered version of the Linux kernel.\nI will update it now if needed.\n"
/usr/bin/yum -y update kernel | grep "Installed:"
if [ $? == "0" ] ; then
  echo -e "\n\nKernel updated.  You must now reboot and restart this preinstall script!!\n"
  exit 10
else
  echo -e "\nKernel update was NOT needed.\n"
fi
}

function installRequired () {
echo "Installing $1 $2 $3 $4 $5"
/usr/bin/yum -y install $1 $2 $3 $4 $5
# 2>> preinstall.log >> preinstall.log
RESULT=$?
if [ $RESULT == "200" ] ; then
  echo -e "\nThe package manager is already running; this could be because the automatic\nupdater is running, or you may have a package manager open.\nRetrying after 15 seconds..."
  sleep 15
  installRequired $1 $2 $3 $4 $5
elif [ $RESULT == "1" ] ; then
  echo -e "\nPossible error running the package manager '/usr/bin/yum'.\nPlease fix if needed and rerun this pre-installer.\n"
fi
}

#touch preinstall.log

installRequired pkgconfig

# Put updateKernel after at least one installation because the function does not check for yum conflicts
updateKernel

installRequired libtool-ltdl-devel
installRequired gcc gcc-c++
installRequired kernel-devel
installRequired kernel-headers
installRequired e2fsprogs e2fsprogs-devel
installRequired gdbm-devel db4-devel db4-utils
installRequired sqlite sqlite-devel

/bin/echo -e "\nInstallation of prerequisite packages successful"
exit 0
