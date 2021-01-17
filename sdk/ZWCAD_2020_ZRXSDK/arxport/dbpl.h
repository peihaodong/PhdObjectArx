
#ifndef __DBPL_H__
#define __DBPL_H__

#include "dbmain.h"
#include "dbcurve.h"

#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "dbboiler.h"

#include "../inc/zdbpl.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDb2dPolyline
#define AcDb2dPolyline		ZcDb2dPolyline
#endif //#ifndef AcDb2dPolyline

#ifndef AcDbCurve
#define AcDbCurve		ZcDbCurve
#endif //#ifndef AcDbCurve

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcDbGripDataPtrArray
#define AcDbGripDataPtrArray		ZcDbGripDataPtrArray
#endif //#ifndef AcDbGripDataPtrArray

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbPolyline
#define AcDbPolyline		ZcDbPolyline
#endif //#ifndef AcDbPolyline

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcGeCircArc2d
#define AcGeCircArc2d		ZcGeCircArc2d
#endif //#ifndef AcGeCircArc2d

#ifndef AcGeCircArc3d
#define AcGeCircArc3d		ZcGeCircArc3d
#endif //#ifndef AcGeCircArc3d

#ifndef AcGeDoubleArray
#define AcGeDoubleArray		ZcGeDoubleArray
#endif //#ifndef AcGeDoubleArray

#ifndef AcGeLineSeg2d
#define AcGeLineSeg2d		ZcGeLineSeg2d
#endif //#ifndef AcGeLineSeg2d

#ifndef AcGeLineSeg3d
#define AcGeLineSeg3d		ZcGeLineSeg3d
#endif //#ifndef AcGeLineSeg3d

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePlane
#define AcGePlane		ZcGePlane
#endif //#ifndef AcGePlane

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBPL_H__
