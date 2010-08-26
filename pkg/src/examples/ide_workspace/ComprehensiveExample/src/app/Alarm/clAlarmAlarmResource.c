/******************************************************************************
 *
 * clAlarmAlarmResource.c
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 3.1
 *
 *****************************************************************************/

#include <clAlarmOAMPConfig.h>
#include <clDebugApi.h>

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Additional #includes and globals go here.
 */

/*
 * ---END_APPLICATION_CODE---
 */


/************** Alarm functions ************/

/**
 * The constructor function will be called when a resource
 * being managed by the alarm library is create by it.
 * This function is called on per resource basis, so a user
 * can do some operation ( like allocation of some resource)
 * that is necessary for each resource being managed.
 */
ClRcT clAlarmALARMRESOURCEAlarmConstructor( void *pThis, void *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;

    return rc;
}

/**
 * The destructor function is called by the alarm client library
 * either when the object is deleted from the north bound or the
 * when the alarm library is finalized. So this function allows to
 * do the counter operation (like deallocation for the resources)
 * to what was done in alarm constructor.
 */
ClRcT clAlarmALARMRESOURCEAlarmDestructor ( void *pThis , void  *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;

    return rc;
}
