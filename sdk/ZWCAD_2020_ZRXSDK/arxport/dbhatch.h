
#ifndef __DBHATCH_H__
#define __DBHATCH_H__

#include "acdb.h"
#include "dbmain.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "gevptar.h"
#include "geintarr.h"

#include "../inc/zdbhatch.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbHatch
#define AcDbHatch		ZcDbHatch
#endif //#ifndef AcDbHatch

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbRegion
#define AcDbRegion		ZcDbRegion
#endif //#ifndef AcDbRegion

#ifndef AcGeDoubleArray
#define AcGeDoubleArray		ZcGeDoubleArray
#endif //#ifndef AcGeDoubleArray

#ifndef AcGeIntArray
#define AcGeIntArray		ZcGeIntArray
#endif //#ifndef AcGeIntArray

#ifndef AcGePlane
#define AcGePlane		ZcGePlane
#endif //#ifndef AcGePlane

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint2dArray
#define AcGePoint2dArray		ZcGePoint2dArray
#endif //#ifndef AcGePoint2dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGeVoidPointerArray
#define AcGeVoidPointerArray		ZcGeVoidPointerArray
#endif //#ifndef AcGeVoidPointerArray

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBHATCH_H__
