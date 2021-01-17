
#ifndef __DBMAIN_H__
#define __DBMAIN_H__

#include <stddef.h>
#include "adesk.h"
#ifdef _ZSOFT_WINDOWS_
#include <share.h>
#endif
#include "gepnt3d.h"
#include "gevec3d.h"
#include "geline3d.h"
#include "AcHeapOpers.h"
#include "adesk.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"

#include "acdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "ads.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"

#include "../inc/zdbmain.h"

#ifndef ACDBG_FORMAL
#define ACDBG_FORMAL		ZCDBG_PARAM_DEC
#endif //#ifndef ACDBG_FORMAL

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AC_SRCH_BLOCK
#define AC_SRCH_BLOCK		ZC_SRCH_BLOCK
#endif //#ifndef AC_SRCH_BLOCK

#ifndef AC_SRCH_DEFAULT
#define AC_SRCH_DEFAULT		ZC_SRCH_DEFAULT
#endif //#ifndef AC_SRCH_DEFAULT

#ifndef AC_SRCH_DIM_TEXT
#define AC_SRCH_DIM_TEXT		ZC_SRCH_DIM_TEXT
#endif //#ifndef AC_SRCH_DIM_TEXT

#ifndef AC_SRCH_LINK_DESC
#define AC_SRCH_LINK_DESC		ZC_SRCH_LINK_DESC
#endif //#ifndef AC_SRCH_LINK_DESC

#ifndef AC_SRCH_LINK_URL
#define AC_SRCH_LINK_URL		ZC_SRCH_LINK_URL
#endif //#ifndef AC_SRCH_LINK_URL

#ifndef AC_SRCH_MATCH_CASE
#define AC_SRCH_MATCH_CASE		ZC_SRCH_MATCH_CASE
#endif //#ifndef AC_SRCH_MATCH_CASE

#ifndef AC_SRCH_TEXT
#define AC_SRCH_TEXT		ZC_SRCH_TEXT
#endif //#ifndef AC_SRCH_TEXT

#ifndef AC_SRCH_WHOLE_WORD
#define AC_SRCH_WHOLE_WORD		ZC_SRCH_WHOLE_WORD
#endif //#ifndef AC_SRCH_WHOLE_WORD

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcCmColorBase
#define AcCmColorBase		ZcCmColorBase
#endif //#ifndef AcCmColorBase

#ifndef AcCmComplexColor
#define AcCmComplexColor		ZcCmComplexColor
#endif //#ifndef AcCmComplexColor

#ifndef AcCmEntityColor
#define AcCmEntityColor		ZcCmEntityColor
#endif //#ifndef AcCmEntityColor

#ifndef AcCmTransparency
#define AcCmTransparency		ZcCmTransparency
#endif //#ifndef AcCmTransparency

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDb3dSolid
#define AcDb3dSolid		ZcDb3dSolid
#endif //#ifndef AcDb3dSolid

#ifndef AcDbAbstractViewTable
#define AcDbAbstractViewTable		ZcDbAbstractViewTable
#endif //#ifndef AcDbAbstractViewTable

#ifndef AcDbAnnotationScale
#define AcDbAnnotationScale		ZcDbAnnotationScale
#endif //#ifndef AcDbAnnotationScale

#ifndef AcDbAnnotationScaleReactor
#define AcDbAnnotationScaleReactor		ZcDbAnnotationScaleReactor
#endif //#ifndef AcDbAnnotationScaleReactor

#ifndef AcDbAuditInfo
#define AcDbAuditInfo		ZcDbAuditInfo
#endif //#ifndef AcDbAuditInfo

#ifndef AcDbBlockBegin
#define AcDbBlockBegin		ZcDbBlockBegin
#endif //#ifndef AcDbBlockBegin

#ifndef AcDbBlockEnd
#define AcDbBlockEnd		ZcDbBlockEnd
#endif //#ifndef AcDbBlockEnd

#ifndef AcDbBlockReference
#define AcDbBlockReference		ZcDbBlockReference
#endif //#ifndef AcDbBlockReference

#ifndef AcDbBlockTable
#define AcDbBlockTable		ZcDbBlockTable
#endif //#ifndef AcDbBlockTable

#ifndef AcDbBlockTableRecord
#define AcDbBlockTableRecord		ZcDbBlockTableRecord
#endif //#ifndef AcDbBlockTableRecord

#ifndef AcDbBody
#define AcDbBody		ZcDbBody
#endif //#ifndef AcDbBody

#ifndef AcDbColor
#define AcDbColor		ZcDbColor
#endif //#ifndef AcDbColor

#ifndef AcDbCurve
#define AcDbCurve		ZcDbCurve
#endif //#ifndef AcDbCurve

#ifndef AcDbDataLinkManager
#define AcDbDataLinkManager		ZcDbDataLinkManager
#endif //#ifndef AcDbDataLinkManager

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDatabaseIterator
#define AcDbDatabaseIterator		ZcDbDatabaseIterator
#endif //#ifndef AcDbDatabaseIterator

#ifndef AcDbDatabaseReactor
#define AcDbDatabaseReactor		ZcDbDatabaseReactor
#endif //#ifndef AcDbDatabaseReactor

#ifndef AcDbDate
#define AcDbDate		ZcDbDate
#endif //#ifndef AcDbDate

#ifndef AcDbDictionary
#define AcDbDictionary		ZcDbDictionary
#endif //#ifndef AcDbDictionary

#ifndef AcDbDictionaryWithDefault
#define AcDbDictionaryWithDefault		ZcDbDictionaryWithDefault
#endif //#ifndef AcDbDictionaryWithDefault

#ifndef AcDbDimStyleTable
#define AcDbDimStyleTable		ZcDbDimStyleTable
#endif //#ifndef AcDbDimStyleTable

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

#ifndef AcDbEllipse
#define AcDbEllipse		ZcDbEllipse
#endif //#ifndef AcDbEllipse

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbEntityReactor
#define AcDbEntityReactor		ZcDbEntityReactor
#endif //#ifndef AcDbEntityReactor

#ifndef AcDbExtents2d 
#define ZcDbExtents2d AcDbExtents2d
#endif 

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbField
#define AcDbField		ZcDbField
#endif //#ifndef AcDbField

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcDbFullSubentPathArray
#define AcDbFullSubentPathArray		ZcDbFullSubentPathArray
#endif //#ifndef AcDbFullSubentPathArray

#ifndef AcDbGripData
#define AcDbGripData		ZcDbGripData
#endif //#ifndef AcDbGripData

#ifndef AcDbGripDataPtrArray
#define AcDbGripDataPtrArray		ZcDbGripDataPtrArray
#endif //#ifndef AcDbGripDataPtrArray

#ifndef AcDbHandle
#define AcDbHandle		ZcDbHandle
#endif //#ifndef AcDbHandle

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbImpDatabase
#define AcDbImpDatabase		ZcDbImpDatabase
#endif //#ifndef AcDbImpDatabase

#ifndef AcDbImpObject
#define AcDbImpObject		ZcDbImpObject
#endif //#ifndef AcDbImpObject

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbLayerFilter
#define AcDbLayerFilter		ZcDbLayerFilter
#endif //#ifndef AcDbLayerFilter

#ifndef AcDbLayerStateManager
#define AcDbLayerStateManager		ZcDbLayerStateManager
#endif //#ifndef AcDbLayerStateManager

#ifndef AcDbLayerTable
#define AcDbLayerTable		ZcDbLayerTable
#endif //#ifndef AcDbLayerTable

#ifndef AcDbLinetypeTable
#define AcDbLinetypeTable		ZcDbLinetypeTable
#endif //#ifndef AcDbLinetypeTable

#ifndef AcDbMline
#define AcDbMline		ZcDbMline
#endif //#ifndef AcDbMline

#ifndef AcDbMlineStyle
#define AcDbMlineStyle		ZcDbMlineStyle
#endif //#ifndef AcDbMlineStyle

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectContextManager
#define AcDbObjectContextManager		ZcDbObjectContextManager
#endif //#ifndef AcDbObjectContextManager

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbObjectIdGraph
#define AcDbObjectIdGraph		ZcDbObjectIdGraph
#endif //#ifndef AcDbObjectIdGraph

#ifndef AcDbObjectIterator
#define AcDbObjectIterator		ZcDbObjectIterator
#endif //#ifndef AcDbObjectIterator

#ifndef AcDbObjectReactor
#define AcDbObjectReactor		ZcDbObjectReactor
#endif //#ifndef AcDbObjectReactor

#ifndef AcDbRegAppTable
#define AcDbRegAppTable		ZcDbRegAppTable
#endif //#ifndef AcDbRegAppTable

#ifndef AcDbRegion
#define AcDbRegion		ZcDbRegion
#endif //#ifndef AcDbRegion

#ifndef AcDbSectionManager
#define AcDbSectionManager		ZcDbSectionManager
#endif //#ifndef AcDbSectionManager

#ifndef AcDbServices
#define AcDbServices		ZcDbServices
#endif //#ifndef AcDbServices

#ifndef AcDbSpaceIterator
#define AcDbSpaceIterator		ZcDbSpaceIterator
#endif //#ifndef AcDbSpaceIterator

#ifndef AcDbSpatialFilter
#define AcDbSpatialFilter		ZcDbSpatialFilter
#endif //#ifndef AcDbSpatialFilter

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

#ifndef AcDbSymbolTable
#define AcDbSymbolTable		ZcDbSymbolTable
#endif //#ifndef AcDbSymbolTable

#ifndef AcDbSystemInternals
#define AcDbSystemInternals		ZcDbSystemInternals
#endif //#ifndef AcDbSystemInternals

#ifndef AcDbTableStyle
#define AcDbTableStyle		ZcDbTableStyle
#endif //#ifndef AcDbTableStyle

#ifndef AcDbTextStyleTable
#define AcDbTextStyleTable		ZcDbTextStyleTable
#endif //#ifndef AcDbTextStyleTable

#ifndef AcDbTransactionManager
#define AcDbTransactionManager		ZcDbTransactionManager
#endif //#ifndef AcDbTransactionManager

#ifndef AcDbUCSTable
#define AcDbUCSTable		ZcDbUCSTable
#endif //#ifndef AcDbUCSTable

#ifndef AcDbUndoController
#define AcDbUndoController		ZcDbUndoController
#endif //#ifndef AcDbUndoController

#ifndef AcDbViewTable
#define AcDbViewTable		ZcDbViewTable
#endif //#ifndef AcDbViewTable

#ifndef AcDbViewTableRecord
#define AcDbViewTableRecord		ZcDbViewTableRecord
#endif //#ifndef AcDbViewTableRecord

#ifndef AcDbViewport
#define AcDbViewport		ZcDbViewport
#endif //#ifndef AcDbViewport

#ifndef AcDbViewportTable
#define AcDbViewportTable		ZcDbViewportTable
#endif //#ifndef AcDbViewportTable

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcDbXObject
#define AcDbXObject		ZcDbXObject
#endif //#ifndef AcDbXObject

#ifndef AcDwgFileHandle
#define AcDwgFileHandle		ZcDwgFileHandle
#endif //#ifndef AcDwgFileHandle

#ifndef AcFdFieldValue
#define AcFdFieldValue		ZcFdFieldValue
#endif //#ifndef AcFdFieldValue

#ifndef AcFileDependencyManager
#define AcFileDependencyManager		ZcFileDependencyManager
#endif //#ifndef AcFileDependencyManager

#ifndef AcGeFastTransform
#define AcGeFastTransform		ZcGeFastTransform
#endif //#ifndef AcGeFastTransform

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

#ifndef AcGiContext
#define AcGiContext		ZcGiContext
#endif //#ifndef AcGiContext

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGiDrawableTraits
#define AcGiDrawableTraits		ZcGiDrawableTraits
#endif //#ifndef AcGiDrawableTraits

#ifndef AcGiMapper
#define AcGiMapper		ZcGiMapper
#endif //#ifndef AcGiMapper

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcGsModel
#define AcGsModel		ZcGsModel
#endif //#ifndef AcGsModel

#ifndef AcGsNode
#define AcGsNode		ZcGsNode
#endif //#ifndef AcGsNode

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef AcHeapOpers
#define AcHeapOpers		ZcHeapOpers
#endif //#ifndef AcHeapOpers

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcRxService
#define AcRxService		ZcRxService
#endif //#ifndef AcRxService

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acdbActiveDatabaseArray
#define acdbActiveDatabaseArray		zcdbActiveDatabaseArray
#endif //#ifndef acdbActiveDatabaseArray

#ifndef acdbAlloc
#define acdbAlloc		zcdbAlloc
#endif //#ifndef acdbAlloc

#ifndef acdbAlloc_dbg
#define acdbAlloc_dbg		zcdbAlloc_dbg
#endif //#ifndef acdbAlloc_dbg

#ifndef acdbCleanUp
#define acdbCleanUp		zcdbCleanUp
#endif //#ifndef acdbCleanUp

#ifndef acdbDisplayPreviewFromDwg
#define acdbDisplayPreviewFromDwg		zcdbDisplayPreviewFromDwg
#endif //#ifndef acdbDisplayPreviewFromDwg

#ifndef acdbDxfOutAs2000
#define acdbDxfOutAs2000		zcdbDxfOutAs2000
#endif //#ifndef acdbDxfOutAs2000

#ifndef acdbDxfOutAs2004
#define acdbDxfOutAs2004		zcdbDxfOutAs2004
#endif //#ifndef acdbDxfOutAs2004

#ifndef acdbDxfOutAsR12
#define acdbDxfOutAsR12		zcdbDxfOutAsR12
#endif //#ifndef acdbDxfOutAsR12

#ifndef acdbFree
#define acdbFree		zcdbFree
#endif //#ifndef acdbFree

#ifndef acdbFreeResBufContents
#define acdbFreeResBufContents		zcdbFreeResBufContents
#endif //#ifndef acdbFreeResBufContents

#ifndef acdbGetAdsName
#define acdbGetAdsName		zcdbGetZdsName
#endif //#ifndef acdbGetAdsName

#ifndef acdbGetObjectId
#define acdbGetObjectId		zcdbGetObjectId
#endif //#ifndef acdbGetObjectId

#ifndef acdbGetThumbnailBitmapFromDxfFile
#define acdbGetThumbnailBitmapFromDxfFile		zcdbGetThumbnailBitmapFromDxfFile
#endif //#ifndef acdbGetThumbnailBitmapFromDxfFile

#ifndef acdbGroupCodeToType
#define acdbGroupCodeToType		zcdbGroupCodeToType
#endif //#ifndef acdbGroupCodeToType

#ifndef acdbIsCustomObject
#define acdbIsCustomObject		zcdbIsCustomObject
#endif //#ifndef acdbIsCustomObject

#ifndef acdbIsPersistentReactor
#define acdbIsPersistentReactor		zcdbIsPersistentReactor
#endif //#ifndef acdbIsPersistentReactor

#ifndef acdbLoadLineTypeFile
#define acdbLoadLineTypeFile		zcdbLoadLineTypeFile
#endif //#ifndef acdbLoadLineTypeFile

#ifndef acdbLoadMlineStyleFile
#define acdbLoadMlineStyleFile		zcdbLoadMlineStyleFile
#endif //#ifndef acdbLoadMlineStyleFile

#ifndef acdbOpenAcDbEntity
#define acdbOpenAcDbEntity		zcdbOpenZcDbEntity
#endif //#ifndef acdbOpenAcDbEntity

#ifndef acdbOpenAcDbObject
#define acdbOpenAcDbObject		zcdbOpenZcDbObject
#endif //#ifndef acdbOpenAcDbObject

#ifndef acdbOpenObject
#define acdbOpenObject		zcdbOpenObject
#endif //#ifndef acdbOpenObject

#ifndef acdbOriginalXrefFullPathFor
#define acdbOriginalXrefFullPathFor		zcdbOriginalXrefFullPathFor
#endif //#ifndef acdbOriginalXrefFullPathFor

#ifndef acdbPersistentReactorObjectId
#define acdbPersistentReactorObjectId		zcdbPersistentReactorObjectId
#endif //#ifndef acdbPersistentReactorObjectId

#ifndef acdbRealloc
#define acdbRealloc		zcdbRealloc
#endif //#ifndef acdbRealloc

#ifndef acdbRealloc_dbg
#define acdbRealloc_dbg		zcdbRealloc_dbg
#endif //#ifndef acdbRealloc_dbg

#ifndef acdbResurrectMeNow
#define acdbResurrectMeNow		zcdbResurrectMeNow
#endif //#ifndef acdbResurrectMeNow

#ifndef acdbSaveAs2000
#define acdbSaveAs2000		zcdbSaveAs2000
#endif //#ifndef acdbSaveAs2000

#ifndef acdbSaveAs2004
#define acdbSaveAs2004		zcdbSaveAs2004
#endif //#ifndef acdbSaveAs2004

#ifndef acdbSaveAsR14
#define acdbSaveAsR14		zcdbSaveAsR14
#endif //#ifndef acdbSaveAsR14

#ifndef acdbSetDbmod
#define acdbSetDbmod	zcdbSetDbmod
#endif	//#ifndef acdbSetDbmod

#ifndef acdbServices
#define acdbServices		zcdbServices
#endif //#ifndef acdbServices

#ifndef acdbSetDefaultAcGiContext
#define acdbSetDefaultAcGiContext		zcdbSetDefaultZcGiContext
#endif //#ifndef acdbSetDefaultAcGiContext

#ifndef acdbSetReferenced
#define acdbSetReferenced		zcdbSetReferenced
#endif //#ifndef acdbSetReferenced

#ifndef acdbTextFind
#define acdbTextFind		zcdbTextFind
#endif //#ifndef acdbTextFind

#ifndef acdbValidateSetup
#define acdbValidateSetup		zcdbValidateSetup
#endif //#ifndef acdbValidateSetup

#ifndef addAcDbObject
#define addAcDbObject		addZcDbObject
#endif //#ifndef addAcDbObject

#ifndef ads_name
#define ads_name		zds_name
#endif //#ifndef ads_name

#ifndef dwgFileWasSavedByAutodeskSoftware
#define dwgFileWasSavedByAutodeskSoftware		dwgFileWasSavedByZwSoftSoftware
#endif //#ifndef dwgFileWasSavedByAutodeskSoftware

#ifndef getAcDbHandle
#define getAcDbHandle		getZcDbHandle
#endif //#ifndef getAcDbHandle

#ifndef getAcDbObjectId
#define getAcDbObjectId		getZcDbObjectId
#endif //#ifndef getAcDbObjectId

#ifndef isAcDbObjectIdsInFlux
#define isAcDbObjectIdsInFlux		isZcDbObjectIdsInFlux
#endif //#ifndef isAcDbObjectIdsInFlux

#ifndef setAcDbObjectIdsInFlux
#define setAcDbObjectIdsInFlux		setZcDbObjectIdsInFlux
#endif //#ifndef setAcDbObjectIdsInFlux

#ifndef accmGetColorFromACIName
#define accmGetColorFromACIName		zccmGetColorFromACIName
#endif //#ifndef accmGetColorFromACIName

#ifndef accmGetColorFromRGBName
#define accmGetColorFromRGBName		zccmGetColorFromRGBName
#endif //#ifndef accmGetColorFromRGBName

#ifndef accmGetColorFromColorBookName
#define accmGetColorFromColorBookName		zccmGetColorFromColorBookName
#endif //#ifndef accmGetColorFromColorBookName

#ifndef accmGetLocalizedColorNames
#define accmGetLocalizedColorNames		zccmGetLocalizedColorNames
#endif //#ifndef accmGetLocalizedColorNames

#ifndef acdbAddAnnotationScaleReactor
#define acdbAddAnnotationScaleReactor		zcdbAddAnnotationScaleReactor
#endif //#ifndef acdbAddAnnotationScaleReactor

#ifndef acdbRemoveAnnotationScaleReactor
#define acdbRemoveAnnotationScaleReactor		zcdbRemoveAnnotationScaleReactor
#endif //#ifndef acdbAddAnnotationScaleReactor

#endif //#ifndef __DBMAIN_H__