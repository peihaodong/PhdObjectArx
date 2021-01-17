
#ifndef __DBEVAL_H__
#define __DBEVAL_H__

#include "dbmain.h"
#include "dbents.h"
#include "AcString.h"
#include "adscodes.h"
#include "adsdef.h"

#include "../inc/zdbeval.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEvalCoectable
#define AcDbEvalCoectable		ZcDbEvalCoectable
#endif //#ifndef AcDbEvalCoectable

#ifndef AcDbEvalContext
#define AcDbEvalContext		ZcDbEvalContext
#endif //#ifndef AcDbEvalContext

#ifndef AcDbEvalContextIterator
#define AcDbEvalContextIterator		ZcDbEvalContextIterator
#endif //#ifndef AcDbEvalContextIterator

#ifndef AcDbEvalContextPair
#define AcDbEvalContextPair		ZcDbEvalContextPair
#endif //#ifndef AcDbEvalContextPair

#ifndef AcDbEvalEdgeInfo
#define AcDbEvalEdgeInfo		ZcDbEvalEdgeInfo
#endif //#ifndef AcDbEvalEdgeInfo

#ifndef AcDbEvalEdgeInfoArray
#define AcDbEvalEdgeInfoArray		ZcDbEvalEdgeInfoArray
#endif //#ifndef AcDbEvalEdgeInfoArray

#ifndef AcDbEvalExpr
#define AcDbEvalExpr		ZcDbEvalExpr
#endif //#ifndef AcDbEvalExpr

#ifndef AcDbEvalExprPtrArray
#define AcDbEvalExprPtrArray		ZcDbEvalExprPtrArray
#endif //#ifndef AcDbEvalExprPtrArray

#ifndef AcDbEvalGraph
#define AcDbEvalGraph		ZcDbEvalGraph
#endif //#ifndef AcDbEvalGraph

#ifndef AcDbEvalIdMap
#define AcDbEvalIdMap		ZcDbEvalIdMap
#endif //#ifndef AcDbEvalIdMap

#ifndef AcDbEvalNodeId
#define AcDbEvalNodeId		ZcDbEvalNodeId
#endif //#ifndef AcDbEvalNodeId

#ifndef AcDbEvalNodeIdArray
#define AcDbEvalNodeIdArray		ZcDbEvalNodeIdArray
#endif //#ifndef AcDbEvalNodeIdArray

#ifndef AcDbEvalVariant
#define AcDbEvalVariant		ZcDbEvalVariant
#endif //#ifndef AcDbEvalVariant

#ifndef AcDbEvalVariantArray
#define AcDbEvalVariantArray		ZcDbEvalVariantArray
#endif //#ifndef AcDbEvalVariantArray

#ifndef AcDbImpEvalContext
#define AcDbImpEvalContext		ZcDbImpEvalContext
#endif //#ifndef AcDbImpEvalContext

#ifndef AcDbImpEvalContextIterator
#define AcDbImpEvalContextIterator		ZcDbImpEvalContextIterator
#endif //#ifndef AcDbImpEvalContextIterator

#ifndef AcDbImpEvalExpr
#define AcDbImpEvalExpr		ZcDbImpEvalExpr
#endif //#ifndef AcDbImpEvalExpr

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

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

#endif //#ifndef __DBEVAL_H__
