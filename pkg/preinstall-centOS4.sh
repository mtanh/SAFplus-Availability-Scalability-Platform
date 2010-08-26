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

/bin/echo -e "This script installs standard packages required to use OpenClovis from\nyour installation media.  If you did a 'development' Linux install, you should\nhave all the needed packages, but just in case, I'll try to install them."

if [ `whoami` != "root" ] ; then
/bin/echo -e "\nYou must be root to run this installer."
exit 2
fi

if [ -e /usr/bin/yum ] ; then
/bin/echo
else
/bin/echo -e "\nThe package manager yum (/usr/bin/yum) does not exist.\nYour installation is either corrupt or not CentOS4."
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
RESULT=$?
if [ $RESULT == "200" ] ; then
  echo -e "\nThe package manager is already running; this could be because the automatic\nupdater is running, or you may have a package manager open.\nRetrying after 15 seconds..."
  sleep 15
  installRequired $1 $2 $3 $4 $5
elif [ $RESULT == "1" ] ; then
  echo -e "\nUnknown error running the package manager '/usr/bin/yum'.\nPlease fix and rerun this pre-installer.\n"
  exit 11
fi
}

installRequired pkgconfig

# Put updateKernel after at least one installation because the function does not check for yum conflicts or errors
updateKernel

installRequired libtool libtool-libs
installRequired gcc gcc-c++
installRequired kernel-devel
installRequired kernel-headers
installRequired db4 db4-devel db4-utils
installRequired gdbm gdbm-devel
installRequired e2fsprogs e2fsprogs-devel
installRequired sqlite sqlite-devel

/bin/echo -e "\nInstallation of prerequisite packages completed."

/bin/echo -e "\nPlease ensure that you have the latest packages installed.\n\nYou can update to the latest packages by running:\n'/usr/bin/yum -y update'\n\nThen reboot your machine.  Failure to do these 2 steps may result in an\ninstallation problem of the 'tipc' package (during the ./install.sh step)."

exit 0
