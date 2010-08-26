/*********************************************************************
* ModuleName  : idl
*********************************************************************/
/*********************************************************************
* Description :Server Stub routines
*     
* THIS FILE IS AUTO-GENERATED BY OPENCLOVIS IDE. EDIT THIS FILE AT
* YOUR OWN RISK. ANY CHANGE TO THIS FILE WILL BE OVERWRITTEN ON
* RE-GENERATION.
*     
*********************************************************************/
#include <netinet/in.h>
#include <clBufferApi.h>
#include <clRmdApi.h>
#include <clEoApi.h>
#include <ipi/clRmdIpi.h>
#include <string.h>
#include "ckptEockptServerMasterDeputyServer.h"
#include "ckptEoServer.h"

extern ClUint32T  ckptEoidlSyncKey;
extern ClHandleDatabaseHandleT  ckptEoidlDatabaseHdl;



ClRcT clCkptDeputyMasterInfoSyncupServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inMsgHdl, ClBufferHandleT outMsgHdl)
{
    ClIdlContextInfoT *pIdlCtxInfo = NULL;
    ClRcT rc = CL_OK;
    ClVersionT  pVersion;
    ClUint32T  numOfCkpts;
    CkptXlationDBEntryT_4_0_0*  pXlationInfo;
    CkptMasterDBInfoIDLT_4_0_0  pMasterInfo;
    ClUint32T  mastHdlCount;
    CkptMasterDBEntryIDLT_4_0_0*  pMasterDBInfo;
    ClUint32T  peerCount;
    CkptPeerListInfoT_4_0_0*  pPeerListInfo;
    ClUint32T  clientHdlCount;
    CkptMasterDBClientInfoT_4_0_0*  pClientDBInfo;

    memset(&(pVersion), 0, sizeof(ClVersionT));
    memset(&(numOfCkpts), 0, sizeof(ClUint32T));
    memset(&(pXlationInfo), 0, sizeof(CkptXlationDBEntryT_4_0_0*));
    memset(&(pMasterInfo), 0, sizeof(CkptMasterDBInfoIDLT_4_0_0));
    memset(&(mastHdlCount), 0, sizeof(ClUint32T));
    memset(&(pMasterDBInfo), 0, sizeof(CkptMasterDBEntryIDLT_4_0_0*));
    memset(&(peerCount), 0, sizeof(ClUint32T));
    memset(&(pPeerListInfo), 0, sizeof(CkptPeerListInfoT_4_0_0*));
    memset(&(clientHdlCount), 0, sizeof(ClUint32T));
    memset(&(pClientDBInfo), 0, sizeof(CkptMasterDBClientInfoT_4_0_0*));


    rc = clXdrUnmarshallClVersionT( inMsgHdl,&(pVersion));
    if (CL_OK != rc)
    {
        goto LL0;
    }





    pIdlCtxInfo = (ClIdlContextInfoT *)clHeapAllocate(sizeof(ClIdlContextInfoT));
    if(pIdlCtxInfo == NULL)
    {
       return CL_IDL_RC(CL_ERR_NO_MEMORY);
    }
    memset(pIdlCtxInfo, 0, sizeof(ClIdlContextInfoT));
    pIdlCtxInfo->idlDeferMsg = outMsgHdl; 
    pIdlCtxInfo->inProgress  = CL_FALSE;
    rc = clIdlSyncPrivateInfoSet(ckptEoidlSyncKey, (void *)pIdlCtxInfo);
    if (CL_OK != rc)
    {
        clHeapFree(pIdlCtxInfo);
        goto L0;
    }
    rc = clCkptDeputyMasterInfoSyncup_4_0_0(&(pVersion), &(numOfCkpts), &pXlationInfo, &(pMasterInfo), &(mastHdlCount), &pMasterDBInfo, &(peerCount), &pPeerListInfo, &(clientHdlCount), &pClientDBInfo);
    if(pIdlCtxInfo->inProgress == CL_FALSE)
    {
      clHeapFree(pIdlCtxInfo);
      pIdlCtxInfo = NULL;
    }
    if (CL_OK != rc)
    {
       goto L0;
    }
    
    if(pIdlCtxInfo != NULL)
    {
      clHeapFree(pIdlCtxInfo);
      return rc;
    }
    
    rc = clXdrMarshallClVersionT(&(pVersion), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L1;
    }

    rc = clXdrMarshallClUint32T(&(numOfCkpts), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L2;
    }

    rc = clXdrMarshallCkptMasterDBInfoIDLT_4_0_0(&(pMasterInfo), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L3;
    }

    rc = clXdrMarshallClUint32T(&(mastHdlCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L4;
    }

    rc = clXdrMarshallClUint32T(&(peerCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L5;
    }

    rc = clXdrMarshallClUint32T(&(clientHdlCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L6;
    }

    rc = clXdrMarshallPtrCkptXlationDBEntryT_4_0_0(pXlationInfo, numOfCkpts, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L7;
    }

    rc = clXdrMarshallPtrCkptMasterDBEntryIDLT_4_0_0(pMasterDBInfo, mastHdlCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L8;
    }

    rc = clXdrMarshallPtrCkptPeerListInfoT_4_0_0(pPeerListInfo, peerCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L9;
    }

    rc = clXdrMarshallPtrCkptMasterDBClientInfoT_4_0_0(pClientDBInfo, clientHdlCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L10;
    }

L10:    return rc;

LL0:  clXdrMarshallClVersionT(&(pVersion), 0, 1);

    return rc;


L0:  clXdrMarshallClVersionT(&(pVersion), 0, 1);
L1:  clXdrMarshallClUint32T(&(numOfCkpts), 0, 1);
L2:  clXdrMarshallCkptMasterDBInfoIDLT_4_0_0(&(pMasterInfo), 0, 1);
L3:  clXdrMarshallClUint32T(&(mastHdlCount), 0, 1);
L4:  clXdrMarshallClUint32T(&(peerCount), 0, 1);
L5:  clXdrMarshallClUint32T(&(clientHdlCount), 0, 1);
L6:  clXdrMarshallPtrCkptXlationDBEntryT_4_0_0(pXlationInfo, numOfCkpts, 0, 1);
L7:  clXdrMarshallPtrCkptMasterDBEntryIDLT_4_0_0(pMasterDBInfo, mastHdlCount, 0, 1);
L8:  clXdrMarshallPtrCkptPeerListInfoT_4_0_0(pPeerListInfo, peerCount, 0, 1);
L9:  clXdrMarshallPtrCkptMasterDBClientInfoT_4_0_0(pClientDBInfo, clientHdlCount, 0, 1);

    return rc;
}

ClRcT clCkptDeputyMasterInfoSyncupResponseSend_4_0_0(ClIdlHandleT idlHdl,ClRcT retCode,CL_INOUT  ClVersionT  pVersion,CL_OUT  ClUint32T  numOfCkpts,CkptXlationDBEntryT_4_0_0*  pXlationInfo,CL_OUT  CkptMasterDBInfoIDLT_4_0_0  pMasterInfo,CL_OUT  ClUint32T  mastHdlCount,CkptMasterDBEntryIDLT_4_0_0*  pMasterDBInfo,CL_OUT  ClUint32T  peerCount,CkptPeerListInfoT_4_0_0*  pPeerListInfo,CL_OUT  ClUint32T  clientHdlCount,CkptMasterDBClientInfoT_4_0_0*  pClientDBInfo)
{
    ClIdlSyncInfoT    *pIdlSyncDeferInfo = NULL;
    ClRcT              rc                = CL_OK;
    ClBufferHandleT outMsgHdl     = 0;
    
    rc = clHandleCheckout(ckptEoidlDatabaseHdl,idlHdl,(void **)&pIdlSyncDeferInfo);
    if( rc != CL_OK)
    {
      goto Label0; 
    }
    outMsgHdl = pIdlSyncDeferInfo->idlRmdDeferMsg;
    
    rc = clXdrMarshallClVersionT(&(pVersion), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L1;
    }

    rc = clXdrMarshallClUint32T(&(numOfCkpts), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L2;
    }

    rc = clXdrMarshallCkptMasterDBInfoIDLT_4_0_0(&(pMasterInfo), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L3;
    }

    rc = clXdrMarshallClUint32T(&(mastHdlCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L4;
    }

    rc = clXdrMarshallClUint32T(&(peerCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L5;
    }

    rc = clXdrMarshallClUint32T(&(clientHdlCount), outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L6;
    }

    rc = clXdrMarshallPtrCkptXlationDBEntryT_4_0_0(pXlationInfo, numOfCkpts, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L7;
    }

    rc = clXdrMarshallPtrCkptMasterDBEntryIDLT_4_0_0(pMasterDBInfo, mastHdlCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L8;
    }

    rc = clXdrMarshallPtrCkptPeerListInfoT_4_0_0(pPeerListInfo, peerCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L9;
    }

    rc = clXdrMarshallPtrCkptMasterDBClientInfoT_4_0_0(pClientDBInfo, clientHdlCount, outMsgHdl, 1);
    if (CL_OK != rc)
    {
        goto L10;
    }

    rc = clIdlSyncResponseSend(pIdlSyncDeferInfo->idlRmdDeferHdl,outMsgHdl,
                                retCode);
    goto Label1; 
L1:  clXdrMarshallClVersionT(&(pVersion), 0, 1);
L2:  clXdrMarshallClUint32T(&(numOfCkpts), 0, 1);
L3:  clXdrMarshallCkptMasterDBInfoIDLT_4_0_0(&(pMasterInfo), 0, 1);
L4:  clXdrMarshallClUint32T(&(mastHdlCount), 0, 1);
L5:  clXdrMarshallClUint32T(&(peerCount), 0, 1);
L6:  clXdrMarshallClUint32T(&(clientHdlCount), 0, 1);
L7:  clXdrMarshallPtrCkptXlationDBEntryT_4_0_0(pXlationInfo, numOfCkpts, 0, 1);
L8:  clXdrMarshallPtrCkptMasterDBEntryIDLT_4_0_0(pMasterDBInfo, mastHdlCount, 0, 1);
L9:  clXdrMarshallPtrCkptPeerListInfoT_4_0_0(pPeerListInfo, peerCount, 0, 1);
L10:  clXdrMarshallPtrCkptMasterDBClientInfoT_4_0_0(pClientDBInfo, clientHdlCount, 0, 1);

    clHandleCheckin(ckptEoidlDatabaseHdl, idlHdl);
    clHandleDestroy(ckptEoidlDatabaseHdl, idlHdl);
    return rc;
Label1:
    clHandleCheckin(ckptEoidlDatabaseHdl, idlHdl);
    clHandleDestroy(ckptEoidlDatabaseHdl, idlHdl);
Label0:
    return rc;
}

ClRcT clCkptLeaderAddrUpdateServer_4_0_0(ClEoDataT eoData, ClBufferHandleT inMsgHdl, ClBufferHandleT outMsgHdl)
{
    ClIdlContextInfoT *pIdlCtxInfo = NULL;
    ClRcT rc = CL_OK;
    ClUint32T  masterAddr;
    ClUint32T  deputyAddr;

    memset(&(masterAddr), 0, sizeof(ClUint32T));
    memset(&(deputyAddr), 0, sizeof(ClUint32T));


    rc = clXdrUnmarshallClUint32T( inMsgHdl,&(masterAddr));
    if (CL_OK != rc)
    {
        goto LL0;
    }

    rc = clXdrUnmarshallClUint32T( inMsgHdl,&(deputyAddr));
    if (CL_OK != rc)
    {
        goto LL1;
    }

    pIdlCtxInfo = (ClIdlContextInfoT *)clHeapAllocate(sizeof(ClIdlContextInfoT));
    if(pIdlCtxInfo == NULL)
    {
       return CL_IDL_RC(CL_ERR_NO_MEMORY);
    }
    memset(pIdlCtxInfo, 0, sizeof(ClIdlContextInfoT));
    pIdlCtxInfo->idlDeferMsg = outMsgHdl; 
    pIdlCtxInfo->inProgress  = CL_FALSE;
    rc = clIdlSyncPrivateInfoSet(ckptEoidlSyncKey, (void *)pIdlCtxInfo);
    if (CL_OK != rc)
    {
        clHeapFree(pIdlCtxInfo);
        goto L0;
    }
    rc = clCkptLeaderAddrUpdate_4_0_0(masterAddr, deputyAddr);
    if(pIdlCtxInfo->inProgress == CL_FALSE)
    {
      clHeapFree(pIdlCtxInfo);
      pIdlCtxInfo = NULL;
    }
    if (CL_OK != rc)
    {
       goto L0;
    }
    
    rc = clXdrMarshallClUint32T(&(masterAddr), 0, 1);
    if (CL_OK != rc)
    {
        goto L1;
    }

    rc = clXdrMarshallClUint32T(&(deputyAddr), 0, 1);
    if (CL_OK != rc)
    {
        goto L2;
    }

    if(pIdlCtxInfo != NULL)
    {
      clHeapFree(pIdlCtxInfo);
      return rc;
    }
    
L2:    return rc;

LL1:  clXdrMarshallClUint32T(&(deputyAddr), 0, 1);
LL0:  clXdrMarshallClUint32T(&(masterAddr), 0, 1);

    return rc;

L0:  clXdrMarshallClUint32T(&(masterAddr), 0, 1);
L1:  clXdrMarshallClUint32T(&(deputyAddr), 0, 1);


    return rc;
}

ClRcT clCkptLeaderAddrUpdateResponseSend_4_0_0(ClIdlHandleT idlHdl,ClRcT retCode)
{
    ClIdlSyncInfoT    *pIdlSyncDeferInfo = NULL;
    ClRcT              rc                = CL_OK;
    ClBufferHandleT outMsgHdl     = 0;
    
    rc = clHandleCheckout(ckptEoidlDatabaseHdl,idlHdl,(void **)&pIdlSyncDeferInfo);
    if( rc != CL_OK)
    {
      goto Label0; 
    }
    outMsgHdl = pIdlSyncDeferInfo->idlRmdDeferMsg;
    
    rc = clIdlSyncResponseSend(pIdlSyncDeferInfo->idlRmdDeferHdl,outMsgHdl,
                                retCode);
    

    

    clHandleCheckin(ckptEoidlDatabaseHdl, idlHdl);
    clHandleDestroy(ckptEoidlDatabaseHdl, idlHdl);
Label0:
    return rc;
}

