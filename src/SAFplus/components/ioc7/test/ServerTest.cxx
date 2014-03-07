/*
 * Copyright (C) 2002-2014 OpenClovis Solutions Inc.  All Rights Reserved.
 *
 * This file is available  under  a  commercial  license  from  the
 * copyright  holder or the GNU General Public License Version 2.0.
 *
 * The source code for  this program is not published  or otherwise
 * divested of  its trade secrets, irrespective  of  what  has been
 * deposited with the U.S. Copyright office.
 *
 * This program is distributed in the  hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied  warranty  of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * For more  information, see  the file  COPYING provided with this
 * material.
 */

#include "clSafplusMsgServer.hxx"
#include <clIocProtocols.h>

//Auto scanning
#define IOC_PORT 0

namespace SAFplus
{
    int
    main(void)
    {
        MsgHandlerProto handler;

        // Port comunication
        safplusMsgServer = new SafplusMsgServer(IOC_PORT);

        // Handle IOC Heartbeat protocol
        safplusMsgServer.RegisterHandler(CL_IOC_PROTO_HB, handler, NULL);

        // Handle IOC Control Protocol
        safplusMsgServer.RegisterHandler(CL_IOC_PROTO_CTL, handler, NULL);

        safplusMsgServer.Start();

    }

} /* namespace SAFplus */
