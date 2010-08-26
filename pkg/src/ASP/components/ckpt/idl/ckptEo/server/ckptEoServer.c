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
#undef __CLIENT__
#define __SERVER__

#include <netinet/in.h>
#include <clBufferApi.h>
#include <clRmdApi.h>
#include <clEoApi.h>
#include <ipi/clRmdIpi.h>
#include <string.h>
#include "ckptEockptServerActivePeerServer.h"
#include "ckptEoServer.h"
#include "ckptEoFuncTable.h"

ClHandleDatabaseHandleT  ckptEoidlDatabaseHdl = 0;
ClUint32T                ckptEoidlSyncKey     = 0;

ClRcT clCkptEoIdlSyncDefer(ClIdlHandleT *pIdlHdl)
{
    return clIdlSyncDefer(ckptEoidlDatabaseHdl, ckptEoidlSyncKey, pIdlHdl);
}    
    
ClRcT clCkptEoClientInstall(void)
{
    ClEoExecutionObjT* pEoObj = NULL;
    ClRcT rc = CL_OK;

    rc = clEoMyEoObjectGet(&pEoObj);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clEoClientInstallTables(pEoObj,CL_EO_SERVER_SYM_MOD(gAspFuncTable,CkptEo));
    if (CL_OK != rc)
    {
        return rc;
    }
    
    rc = clOsalTaskKeyCreate(&ckptEoidlSyncKey,NULL);
    if (CL_OK != rc)
    {
        return rc;
    }

    rc = clHandleDatabaseCreate(NULL,&ckptEoidlDatabaseHdl);

    return rc;
}

ClRcT clCkptEoClientUninstall(void)
{
    ClEoExecutionObjT* pEoObj = NULL;
    ClRcT rc = CL_OK;

    rc = clEoMyEoObjectGet(&pEoObj);
    if (CL_OK != rc)
    {
        return rc;
    }
    rc = clOsalTaskKeyDelete(ckptEoidlSyncKey);
    if (CL_OK != rc)
    {
        return rc;
    }
    rc = clHandleDatabaseDestroy(ckptEoidlDatabaseHdl);
    if (CL_OK != rc)
    {
        return rc;
    }

    clEoClientUninstallTables(pEoObj,CL_EO_SERVER_SYM_MOD(gAspFuncTable,CkptEo));

    return rc;
}

    
