
#ifndef __DBLSTATE_H__
#define __DBLSTATE_H__

#include "dbmain.h"
#include "acarray.h"
#include "acstring.h"

#include "../inc/zdblstate.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbImpDatabase
#define AcDbImpDatabase		ZcDbImpDatabase
#endif //#ifndef AcDbImpDatabase

#ifndef AcDbImpLayerStateManager
#define AcDbImpLayerStateManager		ZcDbImpLayerStateManager
#endif //#ifndef AcDbImpLayerStateManager

#ifndef AcDbLayerStateManager
#define AcDbLayerStateManager		ZcDbLayerStateManager
#endif //#ifndef AcDbLayerStateManager

#ifndef AcDbLayerStateManagerReactor
#define AcDbLayerStateManagerReactor		ZcDbLayerStateManagerReactor
#endif //#ifndef AcDbLayerStateManagerReactor

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcStringArray
#define AcStringArray		ZcStringArray
#endif //#ifndef AcStringArray

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBLSTATE_H__
