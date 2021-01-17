
#ifndef __DBSYMTB_H__
#define __DBSYMTB_H__

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbbackground.h"
#include "gevec2d.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"

#include "../inc/zdbsymtb.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcCmEntityColor
#define AcCmEntityColor		ZcCmEntityColor
#endif //#ifndef AcCmEntityColor

#ifndef AcCmTransparency
#define AcCmTransparency		ZcCmTransparency
#endif //#ifndef AcCmTransparency

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbAbstractViewTable
#define AcDbAbstractViewTable		ZcDbAbstractViewTable
#endif //#ifndef AcDbAbstractViewTable

#ifndef AcDbAbstractViewTableIterator
#define AcDbAbstractViewTableIterator		ZcDbAbstractViewTableIterator
#endif //#ifndef AcDbAbstractViewTableIterator

#ifndef AcDbAbstractViewTableRecord
#define AcDbAbstractViewTableRecord		ZcDbAbstractViewTableRecord
#endif //#ifndef AcDbAbstractViewTableRecord

#ifndef AcDbAnnotationScale
#define AcDbAnnotationScale		ZcDbAnnotationScale
#endif //#ifndef AcDbAnnotationScale

#ifndef AcDbBlockBegin
#define AcDbBlockBegin		ZcDbBlockBegin
#endif //#ifndef AcDbBlockBegin

#ifndef AcDbBlockEnd
#define AcDbBlockEnd		ZcDbBlockEnd
#endif //#ifndef AcDbBlockEnd

#ifndef AcDbBlockReference
#define AcDbBlockReference		ZcDbBlockReference
#endif //#ifndef AcDbBlockReference

#ifndef AcDbBlockReferenceIdIterator
#define AcDbBlockReferenceIdIterator		ZcDbBlockReferenceIdIterator
#endif //#ifndef AcDbBlockReferenceIdIterator

#ifndef AcDbBlockTable
#define AcDbBlockTable		ZcDbBlockTable
#endif //#ifndef AcDbBlockTable

#ifndef AcDbBlockTableIterator
#define AcDbBlockTableIterator		ZcDbBlockTableIterator
#endif //#ifndef AcDbBlockTableIterator

#ifndef AcDbBlockTableRecord
#define AcDbBlockTableRecord		ZcDbBlockTableRecord
#endif //#ifndef AcDbBlockTableRecord

#ifndef AcDbBlockTableRecordIterator
#define AcDbBlockTableRecordIterator		ZcDbBlockTableRecordIterator
#endif //#ifndef AcDbBlockTableRecordIterator

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDimStyleTable
#define AcDbDimStyleTable		ZcDbDimStyleTable
#endif //#ifndef AcDbDimStyleTable

#ifndef AcDbDimStyleTableIterator
#define AcDbDimStyleTableIterator		ZcDbDimStyleTableIterator
#endif //#ifndef AcDbDimStyleTableIterator

#ifndef AcDbDimStyleTableRecord
#define AcDbDimStyleTableRecord		ZcDbDimStyleTableRecord
#endif //#ifndef AcDbDimStyleTableRecord

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDwgVersion
#define AcDbDwgVersion		ZcDbDwgVersion
#endif //#ifndef AcDbDwgVersion

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbImpBlockTableRecord
#define AcDbImpBlockTableRecord		ZcDbImpBlockTableRecord
#endif //#ifndef AcDbImpBlockTableRecord

#ifndef AcDbImpBlockTableRecordIterator
#define AcDbImpBlockTableRecordIterator		ZcDbImpBlockTableRecordIterator
#endif //#ifndef AcDbImpBlockTableRecordIterator

#ifndef AcDbLayerTable
#define AcDbLayerTable		ZcDbLayerTable
#endif //#ifndef AcDbLayerTable

#ifndef AcDbLayerTableIterator
#define AcDbLayerTableIterator		ZcDbLayerTableIterator
#endif //#ifndef AcDbLayerTableIterator

#ifndef AcDbLayerTableRecord
#define AcDbLayerTableRecord		ZcDbLayerTableRecord
#endif //#ifndef AcDbLayerTableRecord

#ifndef AcDbLinetypeTable
#define AcDbLinetypeTable		ZcDbLinetypeTable
#endif //#ifndef AcDbLinetypeTable

#ifndef AcDbLinetypeTableIterator
#define AcDbLinetypeTableIterator		ZcDbLinetypeTableIterator
#endif //#ifndef AcDbLinetypeTableIterator

#ifndef AcDbLinetypeTableRecord
#define AcDbLinetypeTableRecord		ZcDbLinetypeTableRecord
#endif //#ifndef AcDbLinetypeTableRecord

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbRegAppTable
#define AcDbRegAppTable		ZcDbRegAppTable
#endif //#ifndef AcDbRegAppTable

#ifndef AcDbRegAppTableIterator
#define AcDbRegAppTableIterator		ZcDbRegAppTableIterator
#endif //#ifndef AcDbRegAppTableIterator

#ifndef AcDbRegAppTableRecord
#define AcDbRegAppTableRecord		ZcDbRegAppTableRecord
#endif //#ifndef AcDbRegAppTableRecord

#ifndef AcDbSortentsTable
#define AcDbSortentsTable		ZcDbSortentsTable
#endif //#ifndef AcDbSortentsTable

#ifndef AcDbSymbolTable
#define AcDbSymbolTable		ZcDbSymbolTable
#endif //#ifndef AcDbSymbolTable

#ifndef AcDbSymbolTableIterator
#define AcDbSymbolTableIterator		ZcDbSymbolTableIterator
#endif //#ifndef AcDbSymbolTableIterator

#ifndef AcDbSymbolTableRecord
#define AcDbSymbolTableRecord		ZcDbSymbolTableRecord
#endif //#ifndef AcDbSymbolTableRecord

#ifndef AcDbTextStyleTable
#define AcDbTextStyleTable		ZcDbTextStyleTable
#endif //#ifndef AcDbTextStyleTable

#ifndef AcDbTextStyleTableIterator
#define AcDbTextStyleTableIterator		ZcDbTextStyleTableIterator
#endif //#ifndef AcDbTextStyleTableIterator

#ifndef AcDbTextStyleTableRecord
#define AcDbTextStyleTableRecord		ZcDbTextStyleTableRecord
#endif //#ifndef AcDbTextStyleTableRecord

#ifndef AcDbUCSTable
#define AcDbUCSTable		ZcDbUCSTable
#endif //#ifndef AcDbUCSTable

#ifndef AcDbUCSTableIterator
#define AcDbUCSTableIterator		ZcDbUCSTableIterator
#endif //#ifndef AcDbUCSTableIterator

#ifndef AcDbUCSTableRecord
#define AcDbUCSTableRecord		ZcDbUCSTableRecord
#endif //#ifndef AcDbUCSTableRecord

#ifndef AcDbViewTable
#define AcDbViewTable		ZcDbViewTable
#endif //#ifndef AcDbViewTable

#ifndef AcDbViewTableIterator
#define AcDbViewTableIterator		ZcDbViewTableIterator
#endif //#ifndef AcDbViewTableIterator

#ifndef AcDbViewTableRecord
#define AcDbViewTableRecord		ZcDbViewTableRecord
#endif //#ifndef AcDbViewTableRecord

#ifndef AcDbViewportTable
#define AcDbViewportTable		ZcDbViewportTable
#endif //#ifndef AcDbViewportTable

#ifndef AcDbViewportTableIterator
#define AcDbViewportTableIterator		ZcDbViewportTableIterator
#endif //#ifndef AcDbViewportTableIterator

#ifndef AcDbViewportTableRecord
#define AcDbViewportTableRecord		ZcDbViewportTableRecord
#endif //#ifndef AcDbViewportTableRecord

#ifndef AcDbAnnotationScaleView
#define AcDbAnnotationScaleView	ZcDbAnnotationScaleView
#endif //AcDbAnnotationScaleView

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

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

#ifndef AcGsNode
#define AcGsNode		ZcGsNode
#endif //#ifndef AcGsNode

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acgiviewport
#define acgiviewport		zcgiviewport
#endif //#ifndef acgiviewport

#ifndef acgivisualstyle
#define acgivisualstyle		zcgivisualstyle
#endif //#ifndef acgivisualstyle

#ifndef appendAcDbEntity
#define appendAcDbEntity		appendZcDbEntity
#endif //#ifndef appendAcDbEntity

#endif //#ifndef __DBSYMTB_H__
