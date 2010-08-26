/******************************************************************************
 *
 * clOmClassId.h
 *
 ******************************************************************************
 * This code is auto-generated by OpenClovis IDE Version 3.1
 *
 ***************************** Description ************************************
 *
 * This is a header for OM class IDs
 *
 *****************************************************************************/

#ifndef _CL_OM_CLASS_ID_H_
#define _CL_OM_CLASS_ID_H_
                                                                                                                                                                                    
#ifdef __cplusplus
extern "C"
{
#endif

#include <clOmCommonClassTypes.h>

#define OM_APP_MIN_CLASS_TYPE (CL_OM_CMN_CLASS_TYPE_END + 1)
#define OM_APP_MAX_CLASS_TYPE (CL_OM_ALARM_SAAMFTRAPOBJECT_CLASS_TYPE)

enum ClOmClassIdsT
{
    CL_OM_CLASS_TYPE_START = CL_OM_CMN_CLASS_TYPE_END + 1,
    CL_OM_PROV_SAAMFSCALARS_CLASS_TYPE,
    CL_OM_PROV_SAAMFAPPLICATIONTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFNODETABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSGTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSUTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSITABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSUSPERSIRANKTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSGSIRANKTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSGSURANKTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSISIDEPTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCOMPTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCOMPCSTYPESUPPORTEDTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCSITABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCSICSIDEPTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCSINAMEVALUETABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFCSTYPEATTRNAMETABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSUSITABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFHEALTHCHECKTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFSCOMPCSITABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFPROXYPROXIEDTABLE_CLASS_TYPE,
    CL_OM_PROV_SAAMFTRAPOBJECT_CLASS_TYPE,
    CL_OM_ALARM_SAAMFTRAPOBJECT_CLASS_TYPE  
};

#ifdef __cplusplus
}
#endif
#endif /* _CL_OM_CLASS_ID_H_ */

