/*
 * Copyright (C) 2002-2009 by OpenClovis Inc. All  Rights Reserved.
 * 
 * The source code for  this program is not published  or otherwise 
 * divested of  its trade secrets, irrespective  of  what  has been 
 * deposited with the U.S. Copyright office.
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
/*
 * Build: 4.2.0
 */
#ifndef _CL_POOL_IPI_H_
#define _CL_POOL_IPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <clCommon.h>

/*************************************************************************
 *  Constant and Macro Definitions
 ************************************************************************/
#define CL_POOL_MAX_SIZE                    (0)
#define CL_POOL_ALIGNMENT  (0x8)
#define CL_POOL_ALIGNMENT_MASK (CL_POOL_ALIGNMENT-1)
/*************************************************************************
 *  Data Types
 ************************************************************************/
typedef ClPtrT ClPoolT;
typedef ClPtrT ClExtendedPoolT;

typedef enum
{
    CL_POOL_DEFAULT_FLAG    = 0x0,
    CL_POOL_LAZY_FLAG       = 0x1,
    CL_POOL_DEBUG_FLAG      = 0x2,
} ClPoolFlagsT;

/*Chunk config to be fetched by EO*/
typedef struct ClPoolConfig
{
    ClUint32T chunkSize; /*size of the memory chunk*/
    ClUint32T initialPoolSize; /*initial pool size*/
    ClUint32T incrementPoolSize; /*pool extension on exhaustion*/
    ClUint32T maxPoolSize; /*max possible pool size - upper limit*/
} ClPoolConfigT;

typedef struct ClPoolStats
{
    ClPoolConfigT poolConfig;
    ClUint32T numExtendedPools;
    ClUint32T maxNumExtendedPools;
    ClUint32T numAllocs;
    ClUint32T numFrees;
    ClUint32T maxNumAllocs;
} ClPoolStatsT;

typedef enum
{
    CL_POOL_SHRINK_DEFAULT, /*shrink 50 % of the free list*/
    CL_POOL_SHRINK_ONE,/*shrink 1 extended pool from free list*/
    CL_POOL_SHRINK_ALL,/*shrink all from free list*/
} ClPoolShrinkFlagsT;

typedef struct ClPoolShrinkOptions
{
    ClPoolShrinkFlagsT shrinkFlags;
} ClPoolShrinkOptionsT;

/************************************************************************/
ClRcT
clPoolCreate( CL_OUT ClPoolT *pHandle, CL_IN ClPoolFlagsT flags,
        CL_IN const ClPoolConfigT *pPoolConfig );
/************************************************************************/
ClRcT
clPoolDestroy( CL_IN ClPoolT poolHandle);
/************************************************************************/
ClRcT clPoolShrink( CL_IN ClPoolT poolHandle,
        CL_IN const ClPoolShrinkOptionsT *pShrinkOptions );
/************************************************************************/
ClRcT
clPoolAllocate( CL_IN ClPoolT poolHandle, CL_OUT ClUint8T** ppChunk,
        CL_OUT void **ppCookie );
/************************************************************************/
ClRcT
clPoolFree( CL_IN ClUint8T* pChunk, CL_IN void *pCookie );
/************************************************************************/
ClRcT
clPoolStatsGet( CL_IN ClPoolT pool, CL_OUT ClPoolStatsT *pPoolStats );
/***************************************************************************/
ClRcT
clPoolChunkSizeGet(CL_IN void *pCookie, CL_OUT ClUint32T* pSize);
/***************************************************************************/
ClRcT
clPoolStartGet(CL_IN void *pCookie,CL_OUT void **ppAddress);
/************************************************************************/
ClRcT clPoolDestroyForce( CL_IN ClPoolT poolHandle );
/************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _CL_POOL_IPI_H_ */
