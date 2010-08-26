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
 * ModuleName  : event
 * $File: //depot/dev/main/Andromeda/ASP/components/event/test/unit-test/emAutomatedTestSuite/emApp/emTestApp.h $
 * $Author: bkpavan $
 * $Date: 2006/11/10 $
 *******************************************************************************/

/*******************************************************************************
 * Description :
 *******************************************************************************/

#ifndef _CL_TEST_APP_H_
# define _CL_TEST_APP_H_

# ifdef __cplusplus
extern "C"
{
# endif

# include "clCommon.h"
# include "clCommonErrors.h"
# include "clOsalApi.h"
# include "clCntApi.h"
# include "clCommon.h"
# include "clEventErrors.h"
# include "clEventApi.h"
# include "clEventExtApi.h"
    extern ClCntHandleT gEvtTestInitInfo;
    extern ClCntHandleT gChanHandleInitInfo;
    extern ClOsalMutexIdT gEvtTestInitMutex;
    void clEvtTestAppDeliverCallback(ClEventSubscriptionIdT subscriptionId,
                                     ClEventHandleT eventHandle,
                                     ClSizeT eventDataSize);
    ClRcT clEvtTestAppInit(ClUint32T cData, ClBufferHandleT inMsg,
                           ClBufferHandleT outMsg);
    ClRcT clEvtTestAppFin(ClUint32T cData, ClBufferHandleT inMsg,
                          ClBufferHandleT outMsg);
    ClRcT clEvtTestAppOpen(ClUint32T cData, ClBufferHandleT inMsg,
                           ClBufferHandleT outMsg);

    ClRcT clEvtTestAppClose(ClUint32T cData, ClBufferHandleT inMsg,
                            ClBufferHandleT outMsg);

    ClRcT clEvtTestAppFilterGet(ClUint32T filterNo,
                                ClEventFilterArrayT **ppArray);
    ClRcT clEvtTestAppFilterGet(ClUint32T filterNo,
                                ClEventFilterArrayT **ppArray);

    ClRcT clEvtTestAppSub(ClUint32T cData, ClBufferHandleT inMsg,
                          ClBufferHandleT outMsg);
    ClRcT clEvtTestAppUnsub(ClUint32T cData, ClBufferHandleT inMsg,
                            ClBufferHandleT outMsg);
    ClRcT clEvtTestAppPub(ClUint32T cData, ClBufferHandleT inMsg,
                          ClBufferHandleT outMsg);
    ClRcT clEvtTestAppAttSet(ClUint32T cData, ClBufferHandleT inMsg,
                             ClBufferHandleT outMsg);
    ClRcT clEvtTestAppEvtAlloc(ClUint32T cData, ClBufferHandleT inMsg,
                               ClBufferHandleT outMsg);
    ClRcT clEvtTestAppResultGet(ClUint32T cData, ClBufferHandleT inMsg,
                                ClBufferHandleT outMsg);
    ClRcT clEvtTestAppReset(ClUint32T cData, ClBufferHandleT inMsg,
                            ClBufferHandleT outMsg);

# ifdef __cplusplus
}
# endif

#endif                          /* _CL_TEST_APP_H_ */
