
#ifndef __DBENTS_H__
#define __DBENTS_H__

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "dbmtext.h"
#include "dbbackground.h"
#include "dbdim.h"
#include "gept2dar.h"
#include "gedblar.h"
#include "dbsymtb.h"
#include "gemat3d.h"
#include "AcDbXref.h"
#include "acgi.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"

#include "../inc/zdbents.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDb2dPolyline
#define AcDb2dPolyline		ZcDb2dPolyline
#endif //#ifndef AcDb2dPolyline

#ifndef AcDb2dVertex
#define AcDb2dVertex		ZcDb2dVertex
#endif //#ifndef AcDb2dVertex

#ifndef AcDb3dPolyline
#define AcDb3dPolyline		ZcDb3dPolyline
#endif //#ifndef AcDb3dPolyline

#ifndef AcDb3dPolylineVertex
#define AcDb3dPolylineVertex		ZcDb3dPolylineVertex
#endif //#ifndef AcDb3dPolylineVertex

#ifndef AcDbAbstractViewTableRecord
#define AcDbAbstractViewTableRecord		ZcDbAbstractViewTableRecord
#endif //#ifndef AcDbAbstractViewTableRecord

#ifndef AcDbAnnotationScale
#define AcDbAnnotationScale		ZcDbAnnotationScale
#endif //#ifndef AcDbAnnotationScale

#ifndef AcDbArc
#define AcDbArc		ZcDbArc
#endif //#ifndef AcDbArc

#ifndef AcDbAttribute
#define AcDbAttribute		ZcDbAttribute
#endif //#ifndef AcDbAttribute

#ifndef AcDbAttributeDefinition
#define AcDbAttributeDefinition		ZcDbAttributeDefinition
#endif //#ifndef AcDbAttributeDefinition

#ifndef AcDbBlockBegin
#define AcDbBlockBegin		ZcDbBlockBegin
#endif //#ifndef AcDbBlockBegin

#ifndef AcDbBlockEnd
#define AcDbBlockEnd		ZcDbBlockEnd
#endif //#ifndef AcDbBlockEnd

#ifndef AcDbBlockReference
#define AcDbBlockReference		ZcDbBlockReference
#endif //#ifndef AcDbBlockReference

#ifndef AcDbCircle
#define AcDbCircle		ZcDbCircle
#endif //#ifndef AcDbCircle

#ifndef AcDbCurve
#define AcDbCurve		ZcDbCurve
#endif //#ifndef AcDbCurve

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbFace
#define AcDbFace		ZcDbFace
#endif //#ifndef AcDbFace

#ifndef AcDbFaceRecord
#define AcDbFaceRecord		ZcDbFaceRecord
#endif //#ifndef AcDbFaceRecord

#ifndef AcDbField
#define AcDbField		ZcDbField
#endif //#ifndef AcDbField

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcDbGripDataPtrArray
#define AcDbGripDataPtrArray		ZcDbGripDataPtrArray
#endif //#ifndef AcDbGripDataPtrArray

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbLine
#define AcDbLine		ZcDbLine
#endif //#ifndef AcDbLine

#ifndef AcDbMInsertBlock
#define AcDbMInsertBlock		ZcDbMInsertBlock
#endif //#ifndef AcDbMInsertBlock

#ifndef AcDbMText
#define AcDbMText		ZcDbMText
#endif //#ifndef AcDbMText

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbObjectIterator
#define AcDbObjectIterator		ZcDbObjectIterator
#endif //#ifndef AcDbObjectIterator

#ifndef AcDbPoint
#define AcDbPoint		ZcDbPoint
#endif //#ifndef AcDbPoint

#ifndef AcDbPolyFaceMesh
#define AcDbPolyFaceMesh		ZcDbPolyFaceMesh
#endif //#ifndef AcDbPolyFaceMesh

#ifndef AcDbPolyFaceMeshVertex
#define AcDbPolyFaceMeshVertex		ZcDbPolyFaceMeshVertex
#endif //#ifndef AcDbPolyFaceMeshVertex

#ifndef AcDbPolygonMesh
#define AcDbPolygonMesh		ZcDbPolygonMesh
#endif //#ifndef AcDbPolygonMesh

#ifndef AcDbPolygonMeshVertex
#define AcDbPolygonMeshVertex		ZcDbPolygonMeshVertex
#endif //#ifndef AcDbPolygonMeshVertex

#ifndef AcDbSequenceEnd
#define AcDbSequenceEnd		ZcDbSequenceEnd
#endif //#ifndef AcDbSequenceEnd

#ifndef AcDbShape
#define AcDbShape		ZcDbShape
#endif //#ifndef AcDbShape

#ifndef AcDbSolid
#define AcDbSolid		ZcDbSolid
#endif //#ifndef AcDbSolid

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

#ifndef AcDbHelix
#define AcDbHelix		ZcDbHelix
#endif //#ifndef AcDbHelix

#ifndef AcDbText
#define AcDbText		ZcDbText
#endif //#ifndef AcDbText

#ifndef AcDbTrace
#define AcDbTrace		ZcDbTrace
#endif //#ifndef AcDbTrace

#ifndef AcDbVertex
#define AcDbVertex		ZcDbVertex
#endif //#ifndef AcDbVertex

#ifndef AcDbViewport
#define AcDbViewport		ZcDbViewport
#endif //#ifndef AcDbViewport

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcDbXrefObjectId
#define AcDbXrefObjectId		ZcDbXrefObjectId
#endif //#ifndef AcDbXrefObjectId

#ifndef AcGeDoubleArray
#define AcGeDoubleArray		ZcGeDoubleArray
#endif //#ifndef AcGeDoubleArray

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

#ifndef AcGeScale3d
#define AcGeScale3d		ZcGeScale3d
#endif //#ifndef AcGeScale3d

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGiDrawableTraits
#define AcGiDrawableTraits		ZcGiDrawableTraits
#endif //#ifndef AcGiDrawableTraits

#ifndef AcGiToneOperatorParameters
#define AcGiToneOperatorParameters		ZcGiToneOperatorParameters
#endif //#ifndef AcGiToneOperatorParameters

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiViewportTraits
#define AcGiViewportTraits		ZcGiViewportTraits
#endif //#ifndef AcGiViewportTraits

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcDbFrame
#define AcDbFrame		ZcDbFrame
#endif //#ifndef Adesk

#ifndef AcDbOleFrame
#define AcDbOleFrame		ZcDbOleFrame
#endif //#ifndef Adesk

#ifndef AcDbSurface
#define AcDbSurface		ZcDbSurface
#endif //#ifndef Adesk

#ifndef AcDbPlaneSurface
#define AcDbPlaneSurface		ZcDbPlaneSurface
#endif //#ifndef Adesk

#ifndef treatAsAcDbBlockRefForExplode
#define treatAsAcDbBlockRefForExplode		treatAsZcDbBlockRefForExplode
#endif //#ifndef treatAsAcDbBlockRefForExplode

#endif //#ifndef __DBENTS_H__
