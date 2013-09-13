
/*********************************************************************
* ModuleName  : idl
*********************************************************************/
/*********************************************************************
* Description :ClientSide Stub routines
*
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*
*********************************************************************/

#include <netinet/in.h>
#include <string.h>
#include <clBufferApi.h>
#include <clRmdApi.h>
#include <clIdlApi.h>
#include <clEoApi.h>
#include <clXdrApi.h>
#include <clHandleApi.h>
#include "ckptEockptServerExtCliServerFuncClient.h"
extern ClIdlClntT gIdlClnt;


ClRcT _ckptCheckpointWriteVectorClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClHandleT ckptHandle, CL_IN ClUint32T nodeAddr, CL_IN ClUint32T portId, CL_IN ClUint32T numberOfElements, CL_IN ClCkptDifferenceIOVectorElementT_4_0_0* pDifferenceIoVector, CL_OUT ClUint32T* pError, CL_INOUT ClVersionT* pVersion)
{
    ClRcT rc = CL_OK;
    ClVersionT funcVer = {4, 0, 0};
    ClUint32T funcNo = CL_EO_GET_FULL_FN_NUM(CL_EO_NATIVE_COMPONENT_TABLE_ID, 47);
    ClBufferHandleT inMsgHdl = 0;
    ClBufferHandleT outMsgHdl = 0;
    ClIocAddressT address = {{0}};
    ClIdlHandleObjT* pHandleObj = NULL;
    ClUint32T tempFlags = 0;

    rc = clHandleCheckout(gIdlClnt.idlDbHdl,handle,(void **)&pHandleObj);
    if( rc != CL_OK )
    {
        return rc ;
    }
    if (CL_IDL_ADDRESSTYPE_IOC == pHandleObj->address.addressType)
    {
        address = pHandleObj->address.address.iocAddress;
    }
    else if (CL_IDL_ADDRESSTYPE_NAME == pHandleObj->address.addressType)
    {
        rc = saNameToObjectReferenceGet(&(pHandleObj->address.address.nameAddress.name),
                                        pHandleObj->address.address.nameAddress.attrCount,
                                        pHandleObj->address.address.nameAddress.attr,
                                        pHandleObj->address.address.nameAddress.contextCookie,
                                        (ClUint64T*)&address);
        if (CL_OK != rc)
        {
            return rc;
        }
    }
    else
    {
        return CL_IDL_RC(CL_ERR_INVALID_PARAMETER);
    }

    rc = clBufferCreate(&inMsgHdl);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClHandleT(&(ckptHandle), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint32T(&(nodeAddr), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint32T(&(portId), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint32T(&(numberOfElements), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallArrayClCkptDifferenceIOVectorElementT_4_0_0(pDifferenceIoVector, numberOfElements, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClVersionT(pVersion, inMsgHdl, 1);
    if (CL_OK != rc)
    {
        return rc;
    }


    rc = clBufferCreate(&outMsgHdl);
    if (CL_OK != rc)
    {
        return rc;
    }

    tempFlags |= pHandleObj->flags |
                 (CL_RMD_CALL_NON_PERSISTENT | CL_RMD_CALL_NEED_REPLY);
    tempFlags &= ~CL_RMD_CALL_ASYNC;

    rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, outMsgHdl, tempFlags, &(pHandleObj->options), NULL);
    if(CL_OK != rc)
    {
        clBufferDelete(&outMsgHdl);
    return rc;
    }


    rc = clXdrUnmarshallClVersionT( outMsgHdl, pVersion);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrUnmarshallClUint32T( outMsgHdl, pError);
    if (CL_OK != rc)
    {
        return rc;
    }

    clBufferDelete(&outMsgHdl);
    
    rc = clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;
}


static void _ckptCheckpointWriteVectorAsyncCallback_4_0_0(ClRcT rc, void *pIdlCookie, ClBufferHandleT inMsgHdl, ClBufferHandleT outMsgHdl)
{
    ClIdlCookieT* pCookie = (ClIdlCookieT*)pIdlCookie;
    ClRcT retVal = CL_OK;
    ClHandleT  ckptHandle;
    ClUint32T  nodeAddr;
    ClUint32T  portId;
    ClUint32T  numberOfElements;
    ClCkptDifferenceIOVectorElementT_4_0_0* pDifferenceIoVector;
    ClUint32T  pError;
    ClVersionT  pVersion;

    memset(&(ckptHandle), 0, sizeof(ClHandleT));
    memset(&(nodeAddr), 0, sizeof(ClUint32T));
    memset(&(portId), 0, sizeof(ClUint32T));
    memset(&(numberOfElements), 0, sizeof(ClUint32T));
    memset(&(pDifferenceIoVector), 0, sizeof(ClCkptDifferenceIOVectorElementT_4_0_0*));
    memset(&(pError), 0, sizeof(ClUint32T));
    memset(&(pVersion), 0, sizeof(ClVersionT));


    retVal = clXdrUnmarshallClHandleT(inMsgHdl, &(ckptHandle));
    if (CL_OK != retVal)
    {
        goto L0;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(nodeAddr));
    if (CL_OK != retVal)
    {
        goto L1;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(portId));
    if (CL_OK != retVal)
    {
        goto L2;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(numberOfElements));
    if (CL_OK != retVal)
    {
        goto L3;
    }

    retVal = clXdrUnmarshallPtrClCkptDifferenceIOVectorElementT_4_0_0(inMsgHdl, (void**)&(pDifferenceIoVector), numberOfElements);
    if (CL_OK != retVal)
    {
        goto L4;
    }

    if (CL_OK == rc)
    {
        retVal = clXdrUnmarshallClVersionT(outMsgHdl, &(pVersion));
        if (CL_OK != retVal)
        {
            goto L5;
        }
    }

    if (CL_OK == rc)
    {
        retVal = clXdrUnmarshallClUint32T(outMsgHdl, &(pError));
        if (CL_OK != retVal)
        {
            goto L6;
        }
    }

    if (rc != CL_OK)
    {
        retVal = rc;
    }

    ((CkptEo_ckptCheckpointWriteVectorAsyncCallbackT_4_0_0)(pCookie->actualCallback))(pCookie->handle, ckptHandle, nodeAddr, portId, numberOfElements, pDifferenceIoVector, &(pError), &(pVersion), retVal, pCookie->pCookie);
    goto L7;

L7: 
L6: 
L5: 
L4: 
L3: 
L2: 
L1: 

L0:  clHeapFree(pCookie);
     clBufferDelete(&outMsgHdl);
     return;
}


ClRcT _ckptCheckpointWriteVectorClientAsync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClHandleT  ckptHandle, CL_IN ClUint32T  nodeAddr, CL_IN ClUint32T  portId, CL_IN ClUint32T  numberOfElements, CL_IN ClCkptDifferenceIOVectorElementT_4_0_0* pDifferenceIoVector, CL_OUT ClUint32T* pError, CL_INOUT ClVersionT* pVersion,CL_IN CkptEo_ckptCheckpointWriteVectorAsyncCallbackT_4_0_0 fpAsyncCallback, CL_IN void *cookie)
{
    ClRcT rc = CL_OK;
    ClVersionT funcVer = {4, 0, 0};
    ClUint32T funcNo = CL_EO_GET_FULL_FN_NUM(CL_EO_NATIVE_COMPONENT_TABLE_ID, 47);
    ClBufferHandleT inMsgHdl = 0;
    ClBufferHandleT outMsgHdl = 0;
    ClIocAddressT address = {{0}};
    ClIdlHandleObjT* pHandleObj = NULL;
    ClRmdAsyncOptionsT asyncOptions;
    ClUint32T tempFlags = 0;
    ClIdlCookieT* pCookie = NULL;

    rc = clHandleCheckout(gIdlClnt.idlDbHdl,handle,(void **)&pHandleObj);
    if(rc != CL_OK)
    {
        return rc;
    }
    if (CL_IDL_ADDRESSTYPE_IOC == pHandleObj->address.addressType)
    {
        address = pHandleObj->address.address.iocAddress;
    }
    else if (CL_IDL_ADDRESSTYPE_NAME == pHandleObj->address.addressType)
    {
        rc = saNameToObjectReferenceGet(&(pHandleObj->address.address.nameAddress.name),
                                        pHandleObj->address.address.nameAddress.attrCount,
                                        pHandleObj->address.address.nameAddress.attr,
                                        pHandleObj->address.address.nameAddress.contextCookie,
                                        (ClUint64T*)&address);
        if (CL_OK != rc)
        {
            goto L;
        }
    }
    else
    {
        rc = CL_IDL_RC(CL_ERR_INVALID_PARAMETER);
        goto L;
    }

    rc = clBufferCreate(&inMsgHdl);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClHandleT(&(ckptHandle), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(nodeAddr), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(portId), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(numberOfElements), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallArrayClCkptDifferenceIOVectorElementT_4_0_0(pDifferenceIoVector, numberOfElements, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClVersionT(pVersion, inMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L;
    }

    if(fpAsyncCallback != NULL)
    {
        

        pCookie = clHeapAllocate(sizeof(ClIdlCookieT));
        if (NULL == pCookie)
        {
            return CL_IDL_RC(CL_ERR_NO_MEMORY);
        }
        
        asyncOptions.pCookie = NULL;
        asyncOptions.fpCallback = NULL;
        
        rc = clBufferCreate(&outMsgHdl);
        if (CL_OK != rc)
        {
            goto L2;
        }

        tempFlags |= pHandleObj->flags |
                     (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT | CL_RMD_CALL_NEED_REPLY);
        
        pCookie->pCookie = cookie;
        pCookie->actualCallback = (void(*)())fpAsyncCallback;
        pCookie->handle = handle;
        asyncOptions.pCookie = pCookie;
        asyncOptions.fpCallback = _ckptCheckpointWriteVectorAsyncCallback_4_0_0;

        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, outMsgHdl, tempFlags, &(pHandleObj->options), &asyncOptions);
        if (CL_OK != rc)
        {
            goto LL;
         }
    }
    else
    {
        tempFlags |= pHandleObj->flags |
                         (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT);
        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, 0, tempFlags, &(pHandleObj->options),NULL);
        if(CL_OK != rc)
        {
               goto L;
        }
    }
    
    
    clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;

LL: clBufferDelete(&outMsgHdl);
L2:  clHeapFree(pCookie);
L:
     clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;
}


ClRcT _ckptSectionOverwriteVectorClientSync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClHandleT ckptHandle, CL_IN ClUint32T nodeAddr, CL_IN ClUint32T portId, CL_IN ClUint16T srcClient, CL_IN ClCkptSectionIdT_4_0_0* pSecId, CL_IN ClInt64T expryTime, CL_IN ClUint64T dataSize, CL_IN ClDifferenceVectorT* pDifferenceVector, CL_INOUT ClVersionT* pVersion)
{
    ClRcT rc = CL_OK;
    ClVersionT funcVer = {4, 0, 0};
    ClUint32T funcNo = CL_EO_GET_FULL_FN_NUM(CL_EO_NATIVE_COMPONENT_TABLE_ID, 48);
    ClBufferHandleT inMsgHdl = 0;
    ClBufferHandleT outMsgHdl = 0;
    ClIocAddressT address = {{0}};
    ClIdlHandleObjT* pHandleObj = NULL;
    ClUint32T tempFlags = 0;

    rc = clHandleCheckout(gIdlClnt.idlDbHdl,handle,(void **)&pHandleObj);
    if( rc != CL_OK )
    {
        return rc ;
    }
    if (CL_IDL_ADDRESSTYPE_IOC == pHandleObj->address.addressType)
    {
        address = pHandleObj->address.address.iocAddress;
    }
    else if (CL_IDL_ADDRESSTYPE_NAME == pHandleObj->address.addressType)
    {
        rc = saNameToObjectReferenceGet(&(pHandleObj->address.address.nameAddress.name),
                                        pHandleObj->address.address.nameAddress.attrCount,
                                        pHandleObj->address.address.nameAddress.attr,
                                        pHandleObj->address.address.nameAddress.contextCookie,
                                        (ClUint64T*)&address);
        if (CL_OK != rc)
        {
            return rc;
        }
    }
    else
    {
        return CL_IDL_RC(CL_ERR_INVALID_PARAMETER);
    }

    rc = clBufferCreate(&inMsgHdl);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClHandleT(&(ckptHandle), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint32T(&(nodeAddr), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint32T(&(portId), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint16T(&(srcClient), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClCkptSectionIdT_4_0_0(pSecId, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClInt64T(&(expryTime), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClUint64T(&(dataSize), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClDifferenceVectorT(pDifferenceVector, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clXdrMarshallClVersionT(pVersion, inMsgHdl, 1);
    if (CL_OK != rc)
    {
        return rc;
    }


    rc = clBufferCreate(&outMsgHdl);
    if (CL_OK != rc)
    {
        return rc;
    }

    tempFlags |= pHandleObj->flags |
                 (CL_RMD_CALL_NON_PERSISTENT | CL_RMD_CALL_NEED_REPLY);
    tempFlags &= ~CL_RMD_CALL_ASYNC;

    rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, outMsgHdl, tempFlags, &(pHandleObj->options), NULL);
    if(CL_OK != rc)
    {
        clBufferDelete(&outMsgHdl);
    return rc;
    }


    rc = clXdrUnmarshallClVersionT( outMsgHdl, pVersion);
    if (CL_OK != rc)
    {
        return rc;
    }

    clBufferDelete(&outMsgHdl);
    
    rc = clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;
}


static void _ckptSectionOverwriteVectorAsyncCallback_4_0_0(ClRcT rc, void *pIdlCookie, ClBufferHandleT inMsgHdl, ClBufferHandleT outMsgHdl)
{
    ClIdlCookieT* pCookie = (ClIdlCookieT*)pIdlCookie;
    ClRcT retVal = CL_OK;
    ClHandleT  ckptHandle;
    ClUint32T  nodeAddr;
    ClUint32T  portId;
    ClUint16T  srcClient;
    ClCkptSectionIdT_4_0_0  pSecId;
    ClInt64T  expryTime;
    ClUint64T  dataSize;
    ClDifferenceVectorT  pDifferenceVector;
    ClVersionT  pVersion;

    memset(&(ckptHandle), 0, sizeof(ClHandleT));
    memset(&(nodeAddr), 0, sizeof(ClUint32T));
    memset(&(portId), 0, sizeof(ClUint32T));
    memset(&(srcClient), 0, sizeof(ClUint16T));
    memset(&(pSecId), 0, sizeof(ClCkptSectionIdT_4_0_0));
    memset(&(expryTime), 0, sizeof(ClInt64T));
    memset(&(dataSize), 0, sizeof(ClUint64T));
    memset(&(pDifferenceVector), 0, sizeof(ClDifferenceVectorT));
    memset(&(pVersion), 0, sizeof(ClVersionT));


    retVal = clXdrUnmarshallClHandleT(inMsgHdl, &(ckptHandle));
    if (CL_OK != retVal)
    {
        goto L0;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(nodeAddr));
    if (CL_OK != retVal)
    {
        goto L1;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(portId));
    if (CL_OK != retVal)
    {
        goto L2;
    }

    retVal = clXdrUnmarshallClUint16T(inMsgHdl, &(srcClient));
    if (CL_OK != retVal)
    {
        goto L3;
    }

    retVal = clXdrUnmarshallClCkptSectionIdT_4_0_0(inMsgHdl, &(pSecId));
    if (CL_OK != retVal)
    {
        goto L4;
    }

    retVal = clXdrUnmarshallClInt64T(inMsgHdl, &(expryTime));
    if (CL_OK != retVal)
    {
        goto L5;
    }

    retVal = clXdrUnmarshallClUint64T(inMsgHdl, &(dataSize));
    if (CL_OK != retVal)
    {
        goto L6;
    }

    retVal = clXdrUnmarshallClDifferenceVectorT(inMsgHdl, &(pDifferenceVector));
    if (CL_OK != retVal)
    {
        goto L7;
    }

    if (CL_OK == rc)
    {
        retVal = clXdrUnmarshallClVersionT(outMsgHdl, &(pVersion));
        if (CL_OK != retVal)
        {
            goto L8;
        }
    }

    if (rc != CL_OK)
    {
        retVal = rc;
    }

    ((CkptEo_ckptSectionOverwriteVectorAsyncCallbackT_4_0_0)(pCookie->actualCallback))(pCookie->handle, ckptHandle, nodeAddr, portId, srcClient, &(pSecId), expryTime, dataSize, &(pDifferenceVector), &(pVersion), retVal, pCookie->pCookie);
    goto L9;

L9: 
L8: 
L7: 
L6: 
L5: 
L4: 
L3: 
L2: 
L1: 

L0:  clHeapFree(pCookie);
     clBufferDelete(&outMsgHdl);
     return;
}


ClRcT _ckptSectionOverwriteVectorClientAsync_4_0_0(CL_IN ClIdlHandleT handle, CL_IN ClHandleT  ckptHandle, CL_IN ClUint32T  nodeAddr, CL_IN ClUint32T  portId, CL_IN ClUint16T  srcClient, CL_IN ClCkptSectionIdT_4_0_0* pSecId, CL_IN ClInt64T  expryTime, CL_IN ClUint64T  dataSize, CL_IN ClDifferenceVectorT* pDifferenceVector, CL_INOUT ClVersionT* pVersion,CL_IN CkptEo_ckptSectionOverwriteVectorAsyncCallbackT_4_0_0 fpAsyncCallback, CL_IN void *cookie)
{
    ClRcT rc = CL_OK;
    ClVersionT funcVer = {4, 0, 0};
    ClUint32T funcNo = CL_EO_GET_FULL_FN_NUM(CL_EO_NATIVE_COMPONENT_TABLE_ID, 48);
    ClBufferHandleT inMsgHdl = 0;
    ClBufferHandleT outMsgHdl = 0;
    ClIocAddressT address = {{0}};
    ClIdlHandleObjT* pHandleObj = NULL;
    ClRmdAsyncOptionsT asyncOptions;
    ClUint32T tempFlags = 0;
    ClIdlCookieT* pCookie = NULL;

    rc = clHandleCheckout(gIdlClnt.idlDbHdl,handle,(void **)&pHandleObj);
    if(rc != CL_OK)
    {
        return rc;
    }
    if (CL_IDL_ADDRESSTYPE_IOC == pHandleObj->address.addressType)
    {
        address = pHandleObj->address.address.iocAddress;
    }
    else if (CL_IDL_ADDRESSTYPE_NAME == pHandleObj->address.addressType)
    {
        rc = saNameToObjectReferenceGet(&(pHandleObj->address.address.nameAddress.name),
                                        pHandleObj->address.address.nameAddress.attrCount,
                                        pHandleObj->address.address.nameAddress.attr,
                                        pHandleObj->address.address.nameAddress.contextCookie,
                                        (ClUint64T*)&address);
        if (CL_OK != rc)
        {
            goto L;
        }
    }
    else
    {
        rc = CL_IDL_RC(CL_ERR_INVALID_PARAMETER);
        goto L;
    }

    rc = clBufferCreate(&inMsgHdl);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClHandleT(&(ckptHandle), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(nodeAddr), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(portId), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint16T(&(srcClient), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClCkptSectionIdT_4_0_0(pSecId, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClInt64T(&(expryTime), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint64T(&(dataSize), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClDifferenceVectorT(pDifferenceVector, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClVersionT(pVersion, inMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L;
    }

    if(fpAsyncCallback != NULL)
    {
        

        pCookie = clHeapAllocate(sizeof(ClIdlCookieT));
        if (NULL == pCookie)
        {
            return CL_IDL_RC(CL_ERR_NO_MEMORY);
        }
        
        asyncOptions.pCookie = NULL;
        asyncOptions.fpCallback = NULL;
        
        rc = clBufferCreate(&outMsgHdl);
        if (CL_OK != rc)
        {
            goto L2;
        }

        tempFlags |= pHandleObj->flags |
                     (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT | CL_RMD_CALL_NEED_REPLY);
        
        pCookie->pCookie = cookie;
        pCookie->actualCallback = (void(*)())fpAsyncCallback;
        pCookie->handle = handle;
        asyncOptions.pCookie = pCookie;
        asyncOptions.fpCallback = _ckptSectionOverwriteVectorAsyncCallback_4_0_0;

        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, outMsgHdl, tempFlags, &(pHandleObj->options), &asyncOptions);
        if (CL_OK != rc)
        {
            goto LL;
         }
    }
    else
    {
        tempFlags |= pHandleObj->flags |
                         (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT);
        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, 0, tempFlags, &(pHandleObj->options),NULL);
        if(CL_OK != rc)
        {
               goto L;
        }
    }
    
    
    clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;

LL: clBufferDelete(&outMsgHdl);
L2:  clHeapFree(pCookie);
L:
     clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;
}



static void clCkptRemSvrCkptWriteVectorAsyncCallback_4_0_0(ClRcT rc, void *pIdlCookie, ClBufferHandleT inMsgHdl, ClBufferHandleT outMsgHdl)
{
    ClIdlCookieT* pCookie = (ClIdlCookieT*)pIdlCookie;
    ClRcT retVal = CL_OK;
    ClVersionT  pVersion;
    ClHandleT  ckptHandle;
    ClUint32T  nodeAddr;
    ClUint32T  portId;
    ClUint32T  numberOfElements;
    ClCkptDifferenceIOVectorElementT_4_0_0* pDifferenceIoVector;

    memset(&(pVersion), 0, sizeof(ClVersionT));
    memset(&(ckptHandle), 0, sizeof(ClHandleT));
    memset(&(nodeAddr), 0, sizeof(ClUint32T));
    memset(&(portId), 0, sizeof(ClUint32T));
    memset(&(numberOfElements), 0, sizeof(ClUint32T));
    memset(&(pDifferenceIoVector), 0, sizeof(ClCkptDifferenceIOVectorElementT_4_0_0*));


    retVal = clXdrUnmarshallClHandleT(inMsgHdl, &(ckptHandle));
    if (CL_OK != retVal)
    {
        goto L0;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(nodeAddr));
    if (CL_OK != retVal)
    {
        goto L1;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(portId));
    if (CL_OK != retVal)
    {
        goto L2;
    }

    retVal = clXdrUnmarshallClUint32T(inMsgHdl, &(numberOfElements));
    if (CL_OK != retVal)
    {
        goto L3;
    }

    retVal = clXdrUnmarshallPtrClCkptDifferenceIOVectorElementT_4_0_0(inMsgHdl, (void**)&(pDifferenceIoVector), numberOfElements);
    if (CL_OK != retVal)
    {
        goto L4;
    }

    if (CL_OK == rc)
    {
        retVal = clXdrUnmarshallClVersionT(outMsgHdl, &(pVersion));
        if (CL_OK != retVal)
        {
            goto L5;
        }
    }

    if (rc != CL_OK)
    {
        retVal = rc;
    }

    ((CkptEoClCkptRemSvrCkptWriteVectorAsyncCallbackT_4_0_0)(pCookie->actualCallback))(pCookie->handle, &(pVersion), ckptHandle, nodeAddr, portId, numberOfElements, pDifferenceIoVector, retVal, pCookie->pCookie);
    goto L6;

L6: 
L5: 
L4: 
L3: 
L2: 
L1: 

L0:  clHeapFree(pCookie);
     clBufferDelete(&outMsgHdl);
     return;
}


ClRcT clCkptRemSvrCkptWriteVectorClientAsync_4_0_0(CL_IN ClIdlHandleT handle, CL_INOUT ClVersionT* pVersion, CL_IN ClHandleT  ckptHandle, CL_IN ClUint32T  nodeAddr, CL_IN ClUint32T  portId, CL_IN ClUint32T  numberOfElements, CL_IN ClCkptDifferenceIOVectorElementT_4_0_0* pDifferenceIoVector,CL_IN CkptEoClCkptRemSvrCkptWriteVectorAsyncCallbackT_4_0_0 fpAsyncCallback, CL_IN void *cookie)
{
    ClRcT rc = CL_OK;
    ClVersionT funcVer = {4, 0, 0};
    ClUint32T funcNo = CL_EO_GET_FULL_FN_NUM(CL_EO_NATIVE_COMPONENT_TABLE_ID, 49);
    ClBufferHandleT inMsgHdl = 0;
    ClBufferHandleT outMsgHdl = 0;
    ClIocAddressT address = {{0}};
    ClIdlHandleObjT* pHandleObj = NULL;
    ClRmdAsyncOptionsT asyncOptions;
    ClUint32T tempFlags = 0;
    ClIdlCookieT* pCookie = NULL;

    rc = clHandleCheckout(gIdlClnt.idlDbHdl,handle,(void **)&pHandleObj);
    if(rc != CL_OK)
    {
        return rc;
    }
    if (CL_IDL_ADDRESSTYPE_IOC == pHandleObj->address.addressType)
    {
        address = pHandleObj->address.address.iocAddress;
    }
    else if (CL_IDL_ADDRESSTYPE_NAME == pHandleObj->address.addressType)
    {
        rc = saNameToObjectReferenceGet(&(pHandleObj->address.address.nameAddress.name),
                                        pHandleObj->address.address.nameAddress.attrCount,
                                        pHandleObj->address.address.nameAddress.attr,
                                        pHandleObj->address.address.nameAddress.contextCookie,
                                        (ClUint64T*)&address);
        if (CL_OK != rc)
        {
            goto L;
        }
    }
    else
    {
        rc = CL_IDL_RC(CL_ERR_INVALID_PARAMETER);
        goto L;
    }

    rc = clBufferCreate(&inMsgHdl);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClHandleT(&(ckptHandle), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(nodeAddr), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(portId), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClUint32T(&(numberOfElements), inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallArrayClCkptDifferenceIOVectorElementT_4_0_0(pDifferenceIoVector, numberOfElements, inMsgHdl, 0);
    if (CL_OK != rc)
    {
        goto L;
    }

    rc = clXdrMarshallClVersionT(pVersion, inMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L;
    }

    if(fpAsyncCallback != NULL)
    {
        

        pCookie = clHeapAllocate(sizeof(ClIdlCookieT));
        if (NULL == pCookie)
        {
            return CL_IDL_RC(CL_ERR_NO_MEMORY);
        }
        
        asyncOptions.pCookie = NULL;
        asyncOptions.fpCallback = NULL;
        
        rc = clBufferCreate(&outMsgHdl);
        if (CL_OK != rc)
        {
            goto L2;
        }

        tempFlags |= pHandleObj->flags |
                     (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT | CL_RMD_CALL_NEED_REPLY);
        
        pCookie->pCookie = cookie;
        pCookie->actualCallback = (void(*)())fpAsyncCallback;
        pCookie->handle = handle;
        asyncOptions.pCookie = pCookie;
        asyncOptions.fpCallback = clCkptRemSvrCkptWriteVectorAsyncCallback_4_0_0;

        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, outMsgHdl, tempFlags, &(pHandleObj->options), &asyncOptions);
        if (CL_OK != rc)
        {
            goto LL;
         }
    }
    else
    {
        tempFlags |= pHandleObj->flags |
                         (CL_RMD_CALL_ASYNC | CL_RMD_CALL_NON_PERSISTENT);
        rc = clRmdWithMsgVer(address, &funcVer, funcNo, inMsgHdl, 0, tempFlags, &(pHandleObj->options),NULL);
        if(CL_OK != rc)
        {
               goto L;
        }
    }
    
    
    clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;

LL: clBufferDelete(&outMsgHdl);
L2:  clHeapFree(pCookie);
L:
     clHandleCheckin(gIdlClnt.idlDbHdl,handle);
    return rc;
}


