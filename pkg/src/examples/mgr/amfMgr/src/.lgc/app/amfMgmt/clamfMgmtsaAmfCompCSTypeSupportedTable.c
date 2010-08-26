/******************************************************************************
 *
 * clamfMgmtsaAmfCompCSTypeSupportedTable.c
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 3.1
 *
 *****************************************************************************/

#include <clamfMgmtOAMPConfig.h>
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


#define clprintf(severity, ...)   clAppLog(CL_LOG_HANDLE_APP, severity, 10,                                   CL_LOG_AREA_UNSPECIFIED, CL_LOG_CONTEXT_UNSPECIFIED,                                  __VA_ARGS__)

/*
 * ---BEGIN_APPLICATION_CODE---
 */

/*
 * Additional user defined functions go here.
 */


/*
 * ---END_APPLICATION_CODE---
 */

/**** Prov functions */


/**
 * The Contructor function is called by the provisioning library when an object 
 * of the managed resource is created. Inside this function the callback functions
 * for validate, update, rollback and read functions are assigned. 
 * Inside this function, a user can add his or her own logic which need to be 
 * done on a per object basis. If this logic involves allocation of some resource, 
 * it can be freed in the destructor function, which is called when the managed 
 * resource is deleted.
 */ 
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvConstructor( void *pThis, void *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;

    /* Override "semantic check" virtual method in provClass*/
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectStart = clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvObjectStart;      
    ((CL_OM_PROV_CLASS*)pThis)->clProvValidate = (fp)clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvValidate;    
    ((CL_OM_PROV_CLASS*)pThis)->clProvUpdate = (fp)clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvUpdate;    
    ((CL_OM_PROV_CLASS*)pThis)->clProvRollback = (fp)clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvRollback;
    ((CL_OM_PROV_CLASS*)pThis)->clProvRead = (fp)clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvRead;
    ((CL_OM_PROV_CLASS*)pThis)->clProvObjectEnd = clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvObjectEnd;      
    
    /*
     * ---BEGIN_APPLICATION_CODE---
    */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
     
    return rc;
}

/**
 * This function is called by the provisioning library when the managed resource 
 * is deleted. This can have logic of deleting the resources which might have 
 * been allocated in the constructor function.
 */ 
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvDestructor ( void *pThis , void  *pUsrData, ClUint32T usrDataLen )
{
    ClRcT rc = CL_OK;
    
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;  
}

/**
 * This function is called by the provisioning library before forwarding any of the
 * transaction requests to this application on this managed resource. Please refer the file
 * clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEOAMPConfig.h for detailed documentation for this function.
 */
void clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvObjectStart(ClCorMOIdPtrT pMoId, ClHandleT txnHandle)
{
    /*
     * ---BEGIN_APPLICATION_CODE---
    */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
    */
}

/**
 * This function is called by the provisioning library whenever the object modification 
 * operation is done on the resource being managed. This callback is called to validate
 * the job. For a single job request, this is called once before calling update or 
 * rollback based on the success or failure of this function. For a request containing
 * multiple jobs, this function is called for all the jobs for validating them.
 * Only when validation for all the jobs are success, the update callback is called for
 * all the jobs. In case of failure, the rollback it called for all the jobs till which
 * the failure was detected.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 *
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 */ 
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvValidate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;
    
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
        
    return rc;
}

/**
 * This function is called by the provisioning library whenever the object modification 
 * operation is done on the resource being managed. This is called to update the jobs
 * after being validated in validate phase.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 *
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 */ 
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvUpdate(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
     
    switch (pProvTxnData->provCmd)
    {
        case CL_COR_OP_CREATE :
        case CL_COR_OP_CREATE_AND_SET:
            
        /*
         * ---BEGIN_APPLICATION_CODE---
         */

        /*
         * ---END_APPLICATION_CODE---
         */

        break;
        case CL_COR_OP_SET:
        
        /*
         * ---BEGIN_APPLICATION_CODE---
         */
    
        /*
         * ---END_APPLICATION_CODE---
         */

        break;

        case  CL_COR_OP_DELETE:

        /*
         * ---BEGIN_APPLICATION_CODE---
         */

        /*
         * ---END_APPLICATION_CODE---
         */

        break;
        default:
            clprintf (CL_LOG_SEV_ERROR, "Prov command is not proper");

    }

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;   
}


/**
 * This function is called by the provisioning library whenever the object 
 * modification operation is done on the resource being managed. For a single job 
 * request, this function is called if the validate function is failed. For a 
 * multiple job request, on encountering a validate failure, this function is 
 * called to rollback all the jobs before the one (including) on which the 
 * validation failure is reported.
 *
 * The pThis is a pointer to the provisioning class. 
 * The txnHandle is the unique handle for all the jobs which are part of same session. So for
 * a session containing multiple jobs, then it is unique of all the jobs and it can be used
 * to identify them.
 * 
 * The pProvTxnData is a pointer to the ClProvTxnDataT structure which contains 
 * the information about the job being performed on the managed resource. 
 * The pProvTxnData->provCmd stores the operation type which can be 
 * CL_COR_OP_CREATE_AND_SET, CL_COR_OP_CREATE, CL_COR_OP_SET or CL_COR_OP_DELETE
 * based on what is the operation happening on the resource.
 * In the case of set operation, the various fields of pProvTxnData provide the
 * the details about the operation which is happening on the resource. It contain 
 * MOID of the managed resource and information about the attribute on which set
 * operation is done. For a create, create-set and delete operation, the pProvTxnData 
 * contains the MOID of the resource on which the given operation is done.
 */
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvRollback(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;
}

/**
 * This function is called to perform a get operation on the transient attribute
 * which is owned by the primary object implementer (OI). As the COR doesn't have
 * the latest value of the transient attribute, it is obtained from the OI. This
 * function is called in the OI's context which it can use to fill the latest
 * value of the runtime or transient attribute.
 *
 * The pThis is pointer to the provisioning class.
 * The txnHandle is used to identify the jobs which are part of same bundle request.
 * For single request this field is of not much significance, but for a multiple job
 * request, this feild is used to identify all the jobs which are part of same
 * bundle request sent by COR.
 *
 * The pProvTxnData contains the information about the attribute jobs. It contains 
 * the MOId of the managed resource, the attribute identifier, its type (array or 
 * simple), its basic type (data type), index (in case it is array attriubte), 
 * size and the pointer (allocated by the library) to the memory on which the 
 * data can be copied.
 *
 * For a request containing only single job, this function is called only once. But
 * for a multiple job request, this is called for all the attributes one at a time.
 */ 
ClRcT clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvRead(CL_OM_PROV_CLASS* pThis, ClHandleT txnHandle, ClProvTxnDataT* pProvTxnData)
{
    ClRcT rc = CL_OK;

    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */

    return rc;
}

/**
 * This function is called by the provisioning library after all the transaction requests
 * for this managed resource are forwarded to this application. Please refer the file
 * clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEOAMPConfig.h for detailed documentation for this function.
 */
void clamfMgmtSAAMFCOMPCSTYPESUPPORTEDTABLEProvObjectEnd(ClCorMOIdPtrT pMoId, ClHandleT txnHandle)
{
    /*
     * ---BEGIN_APPLICATION_CODE---
     */

    clprintf(CL_LOG_SEV_INFO, "Inside the function %s", __FUNCTION__);

    /*
     * ---END_APPLICATION_CODE---
     */
}


