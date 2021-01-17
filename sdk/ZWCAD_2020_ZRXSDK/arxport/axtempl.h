
#ifndef __AXTEMPL_H__
#define __AXTEMPL_H__

#include "adesk.h"
#include "axobjref.h"
#include "axboiler.h"
#include "oleaprot.h"

#include "opmext.h"
#include "opmimp.h"
#include "dbobjptr.h"
#include "rxregsvc.h"

#include "../inc/zaxtempl.h"

#ifndef ACAD_LWEIGHT
#define ACAD_LWEIGHT		ZCAD_LWEIGHT
#endif //#ifndef ACAD_LWEIGHT

#ifndef ACAX_VARIANT_FALSE
#define ACAX_VARIANT_FALSE		ZCAX_VARIANT_FALSE
#endif //#ifndef ACAX_VARIANT_FALSE

#ifndef ACAX_VARIANT_TRUE
#define ACAX_VARIANT_TRUE		ZCAX_VARIANT_TRUE
#endif //#ifndef ACAX_VARIANT_TRUE

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AD_LWEIGHT
#define AD_LWEIGHT		ZD_LWEIGHT
#endif //#ifndef AD_LWEIGHT

#ifndef AcAxArrayPolar
#define AcAxArrayPolar		ZcAxArrayPolar
#endif //#ifndef AcAxArrayPolar

#ifndef AcAxArrayRectangular
#define AcAxArrayRectangular		ZcAxArrayRectangular
#endif //#ifndef AcAxArrayRectangular

#ifndef AcAxCopy
#define AcAxCopy		ZcAxCopy
#endif //#ifndef AcAxCopy

#ifndef AcAxErase
#define AcAxErase		ZcAxErase
#endif //#ifndef AcAxErase

#ifndef AcAxGetBoundingBox
#define AcAxGetBoundingBox		ZcAxGetBoundingBox
#endif //#ifndef AcAxGetBoundingBox

#ifndef AcAxGetColor
#define AcAxGetColor		ZcAxGetColor
#endif //#ifndef AcAxGetColor

#ifndef AcAxGetDatabase
#define AcAxGetDatabase		ZcAxGetDatabase
#endif //#ifndef AcAxGetDatabase

#ifndef AcAxGetExtensionDictionary
#define AcAxGetExtensionDictionary		ZcAxGetExtensionDictionary
#endif //#ifndef AcAxGetExtensionDictionary

#ifndef AcAxGetHandle
#define AcAxGetHandle		ZcAxGetHandle
#endif //#ifndef AcAxGetHandle

#ifndef AcAxGetHyperlinks
#define AcAxGetHyperlinks		ZcAxGetHyperlinks
#endif //#ifndef AcAxGetHyperlinks

#ifndef AcAxGetLayer
#define AcAxGetLayer		ZcAxGetLayer
#endif //#ifndef AcAxGetLayer

#ifndef AcAxGetLineWeight
#define AcAxGetLineWeight		ZcAxGetLineWeight
#endif //#ifndef AcAxGetLineWeight

#ifndef AcAxGetLinetype
#define AcAxGetLinetype		ZcAxGetLinetype
#endif //#ifndef AcAxGetLinetype

#ifndef AcAxGetLinetypeScale
#define AcAxGetLinetypeScale		ZcAxGetLinetypeScale
#endif //#ifndef AcAxGetLinetypeScale

#ifndef AcAxGetMaterial
#define AcAxGetMaterial		ZcAxGetMaterial
#endif //#ifndef AcAxGetMaterial

#ifndef AcAxGetObjectId32
#define AcAxGetObjectId32		ZcAxGetObjectId32
#endif //#ifndef AcAxGetObjectId32

#ifndef AcAxGetObjectName
#define AcAxGetObjectName		ZcAxGetObjectName
#endif //#ifndef AcAxGetObjectName

#ifndef AcAxGetOleLinkManager
#define AcAxGetOleLinkManager		ZcAxGetOleLinkManager
#endif //#ifndef AcAxGetOleLinkManager

#ifndef AcAxGetOwnerId
#define AcAxGetOwnerId		ZcAxGetOwnerId
#endif //#ifndef AcAxGetOwnerId

#ifndef AcAxGetPlotStyleName
#define AcAxGetPlotStyleName		ZcAxGetPlotStyleName
#endif //#ifndef AcAxGetPlotStyleName

#ifndef AcAxGetShadowDisplay
#define AcAxGetShadowDisplay		ZcAxGetShadowDisplay
#endif //#ifndef AcAxGetShadowDisplay

#ifndef AcAxGetTrueColor
#define AcAxGetTrueColor		ZcAxGetTrueColor
#endif //#ifndef AcAxGetTrueColor

#ifndef AcAxGetVisible
#define AcAxGetVisible		ZcAxGetVisible
#endif //#ifndef AcAxGetVisible

#ifndef AcAxGetXData
#define AcAxGetXData		ZcAxGetXData
#endif //#ifndef AcAxGetXData

#ifndef AcAxHasExtensionDictionary
#define AcAxHasExtensionDictionary		ZcAxHasExtensionDictionary
#endif //#ifndef AcAxHasExtensionDictionary

#ifndef AcAxHighlight
#define AcAxHighlight		ZcAxHighlight
#endif //#ifndef AcAxHighlight

#ifndef AcAxIntersectWith
#define AcAxIntersectWith		ZcAxIntersectWith
#endif //#ifndef AcAxIntersectWith

#ifndef AcAxMirror
#define AcAxMirror		ZcAxMirror
#endif //#ifndef AcAxMirror

#ifndef AcAxMirror3D
#define AcAxMirror3D		ZcAxMirror3D
#endif //#ifndef AcAxMirror3D

#ifndef AcAxMove
#define AcAxMove		ZcAxMove
#endif //#ifndef AcAxMove

#ifndef AcAxObjectRef
#define AcAxObjectRef		ZcAxObjectRef
#endif //#ifndef AcAxObjectRef

#ifndef AcAxOleLinkManager
#define AcAxOleLinkManager		ZcAxOleLinkManager
#endif //#ifndef AcAxOleLinkManager

#ifndef AcAxPutColor
#define AcAxPutColor		ZcAxPutColor
#endif //#ifndef AcAxPutColor

#ifndef AcAxPutLayer
#define AcAxPutLayer		ZcAxPutLayer
#endif //#ifndef AcAxPutLayer

#ifndef AcAxPutLineWeight
#define AcAxPutLineWeight		ZcAxPutLineWeight
#endif //#ifndef AcAxPutLineWeight

#ifndef AcAxPutLinetype
#define AcAxPutLinetype		ZcAxPutLinetype
#endif //#ifndef AcAxPutLinetype

#ifndef AcAxPutLinetypeScale
#define AcAxPutLinetypeScale		ZcAxPutLinetypeScale
#endif //#ifndef AcAxPutLinetypeScale

#ifndef AcAxPutMaterial
#define AcAxPutMaterial		ZcAxPutMaterial
#endif //#ifndef AcAxPutMaterial

#ifndef AcAxPutPlotStyleName
#define AcAxPutPlotStyleName		ZcAxPutPlotStyleName
#endif //#ifndef AcAxPutPlotStyleName

#ifndef AcAxPutShadowDisplay
#define AcAxPutShadowDisplay		ZcAxPutShadowDisplay
#endif //#ifndef AcAxPutShadowDisplay

#ifndef AcAxPutTrueColor
#define AcAxPutTrueColor		ZcAxPutTrueColor
#endif //#ifndef AcAxPutTrueColor

#ifndef AcAxPutVisible
#define AcAxPutVisible		ZcAxPutVisible
#endif //#ifndef AcAxPutVisible

#ifndef AcAxRotate
#define AcAxRotate		ZcAxRotate
#endif //#ifndef AcAxRotate

#ifndef AcAxRotate3D
#define AcAxRotate3D		ZcAxRotate3D
#endif //#ifndef AcAxRotate3D

#ifndef AcAxScaleEntity
#define AcAxScaleEntity		ZcAxScaleEntity
#endif //#ifndef AcAxScaleEntity

#ifndef AcAxSetXData
#define AcAxSetXData		ZcAxSetXData
#endif //#ifndef AcAxSetXData

#ifndef AcAxTransformBy
#define AcAxTransformBy		ZcAxTransformBy
#endif //#ifndef AcAxTransformBy

#ifndef AcAxUpdate
#define AcAxUpdate		ZcAxUpdate
#endif //#ifndef AcAxUpdate

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcColor
#define AcColor		ZcColor
#endif //#ifndef AcColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath		ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbObjectPointer
#define AcDbObjectPointer		ZcDbObjectPointer
#endif //#ifndef AcDbObjectPointer

#ifndef AcExtendOption
#define AcExtendOption		ZcExtendOption
#endif //#ifndef AcExtendOption

#ifndef AcOpmEditable
#define AcOpmEditable		ZcOpmEditable
#endif //#ifndef AcOpmEditable

#ifndef AcOpmGetCategoryCommandButtons
#define AcOpmGetCategoryCommandButtons		ZcOpmGetCategoryCommandButtons
#endif //#ifndef AcOpmGetCategoryCommandButtons

#ifndef AcOpmGetCategoryDescription
#define AcOpmGetCategoryDescription		ZcOpmGetCategoryDescription
#endif //#ifndef AcOpmGetCategoryDescription

#ifndef AcOpmGetCategoryName
#define AcOpmGetCategoryName		ZcOpmGetCategoryName
#endif //#ifndef AcOpmGetCategoryName

#ifndef AcOpmGetCategoryWeight
#define AcOpmGetCategoryWeight		ZcOpmGetCategoryWeight
#endif //#ifndef AcOpmGetCategoryWeight

#ifndef AcOpmGetCommandButtons
#define AcOpmGetCommandButtons		ZcOpmGetCommandButtons
#endif //#ifndef AcOpmGetCommandButtons

#ifndef AcOpmGetCustomPropertyCtrl
#define AcOpmGetCustomPropertyCtrl		ZcOpmGetCustomPropertyCtrl
#endif //#ifndef AcOpmGetCustomPropertyCtrl

#ifndef AcOpmGetDisplayName
#define AcOpmGetDisplayName		ZcOpmGetDisplayName
#endif //#ifndef AcOpmGetDisplayName

#ifndef AcOpmGetDisplayString
#define AcOpmGetDisplayString		ZcOpmGetDisplayString
#endif //#ifndef AcOpmGetDisplayString

#ifndef AcOpmGetParentCategory
#define AcOpmGetParentCategory		ZcOpmGetParentCategory
#endif //#ifndef AcOpmGetParentCategory

#ifndef AcOpmGetPredefinedStrings
#define AcOpmGetPredefinedStrings		ZcOpmGetPredefinedStrings
#endif //#ifndef AcOpmGetPredefinedStrings

#ifndef AcOpmGetPredefinedValue
#define AcOpmGetPredefinedValue		ZcOpmGetPredefinedValue
#endif //#ifndef AcOpmGetPredefinedValue

#ifndef AcOpmGetPropTextColor
#define AcOpmGetPropTextColor		ZcOpmGetPropTextColor
#endif //#ifndef AcOpmGetPropTextColor

#ifndef AcOpmGetPropertyIcon
#define AcOpmGetPropertyIcon		ZcOpmGetPropertyIcon
#endif //#ifndef AcOpmGetPropertyIcon

#ifndef AcOpmGetPropertyWeight
#define AcOpmGetPropertyWeight		ZcOpmGetPropertyWeight
#endif //#ifndef AcOpmGetPropertyWeight

#ifndef AcOpmIsPropFullView
#define AcOpmIsPropFullView		ZcOpmIsPropFullView
#endif //#ifndef AcOpmIsPropFullView

#ifndef AcOpmMapPropertyToCategory
#define AcOpmMapPropertyToCategory		ZcOpmMapPropertyToCategory
#endif //#ifndef AcOpmMapPropertyToCategory

#ifndef AcOpmMapPropertyToPage
#define AcOpmMapPropertyToPage		ZcOpmMapPropertyToPage
#endif //#ifndef AcOpmMapPropertyToPage

#ifndef AcOpmShowProperty
#define AcOpmShowProperty		ZcOpmShowProperty
#endif //#ifndef AcOpmShowProperty

#ifndef AcShadowDisplayType
#define AcShadowDisplayType		ZcShadowDisplayType
#endif //#ifndef AcShadowDisplayType

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef CProxy_AcadObjectEvents
#define CProxy_AcadObjectEvents		CProxy_ZcadObjectEvents
#endif //#ifndef CProxy_AcadObjectEvents

#ifndef IAcPiCategorizeProperties
#define IAcPiCategorizeProperties		IZcPiCategorizeProperties
#endif //#ifndef IAcPiCategorizeProperties

#ifndef IAcPiCategorizePropertiesImpl
#define IAcPiCategorizePropertiesImpl		IZcPiCategorizePropertiesImpl
#endif //#ifndef IAcPiCategorizePropertiesImpl

#ifndef IAcPiPropCommandButtons
#define IAcPiPropCommandButtons		IZcPiPropCommandButtons
#endif //#ifndef IAcPiPropCommandButtons

#ifndef IAcPiPropCommandButtonsImpl
#define IAcPiPropCommandButtonsImpl		IZcPiPropCommandButtonsImpl
#endif //#ifndef IAcPiPropCommandButtonsImpl

#ifndef IAcPiPropertyDisplay
#define IAcPiPropertyDisplay		IZcPiPropertyDisplay
#endif //#ifndef IAcPiPropertyDisplay

#ifndef IAcPiPropertyDisplayImpl
#define IAcPiPropertyDisplayImpl		IZcPiPropertyDisplayImpl
#endif //#ifndef IAcPiPropertyDisplayImpl

#ifndef IAcadAcCmColor
#define IAcadAcCmColor		IZcadZcCmColor
#endif //#ifndef IAcadAcCmColor

#ifndef IAcadBaseDatabase
#define IAcadBaseDatabase		IZcadBaseDatabase
#endif //#ifndef IAcadBaseDatabase

#ifndef IAcadBaseDatabaseImpl
#define IAcadBaseDatabaseImpl		IZcadBaseDatabaseImpl
#endif //#ifndef IAcadBaseDatabaseImpl

#ifndef IAcadBaseObject
#define IAcadBaseObject		IZcadBaseObject
#endif //#ifndef IAcadBaseObject

#ifndef IAcadBaseObject2
#define IAcadBaseObject2		IZcadBaseObject2
#endif //#ifndef IAcadBaseObject2

#ifndef IAcadBaseObject2Impl
#define IAcadBaseObject2Impl		IZcadBaseObject2Impl
#endif //#ifndef IAcadBaseObject2Impl

#ifndef IAcadBaseObjectImpl
#define IAcadBaseObjectImpl		IZcadBaseObjectImpl
#endif //#ifndef IAcadBaseObjectImpl

#ifndef IAcadBaseSubEntity
#define IAcadBaseSubEntity		IZcadBaseSubEntity
#endif //#ifndef IAcadBaseSubEntity

#ifndef IAcadBaseSubEntityImpl
#define IAcadBaseSubEntityImpl		IZcadBaseSubEntityImpl
#endif //#ifndef IAcadBaseSubEntityImpl

#ifndef IAcadDatabase
#define IAcadDatabase		IZcadDatabase
#endif //#ifndef IAcadDatabase

#ifndef IAcadDictionary
#define IAcadDictionary		IZcadDictionary
#endif //#ifndef IAcadDictionary

#ifndef IAcadEntityDispatchImpl
#define IAcadEntityDispatchImpl		IZcadEntityDispatchImpl
#endif //#ifndef IAcadEntityDispatchImpl

#ifndef IAcadHyperlinks
#define IAcadHyperlinks		IZcadHyperlinks
#endif //#ifndef IAcadHyperlinks

#ifndef IAcadObject
#define IAcadObject		IZcadObject
#endif //#ifndef IAcadObject

#ifndef IAcadObjectDispatchImpl
#define IAcadObjectDispatchImpl		IZcadObjectDispatchImpl
#endif //#ifndef IAcadObjectDispatchImpl

#ifndef IAcadObjectEvents
#define IAcadObjectEvents		IZcadObjectEvents
#endif //#ifndef IAcadObjectEvents

#ifndef IAcadShadowDisplay
#define IAcadShadowDisplay		IZcadShadowDisplay
#endif //#ifndef IAcadShadowDisplay

#ifndef IAcadShadowDisplayImpl
#define IAcadShadowDisplayImpl		IZcadShadowDisplayImpl
#endif //#ifndef IAcadShadowDisplayImpl

#ifndef IID_IAcadBaseObject
#define IID_IAcadBaseObject		IID_IZcadBaseObject
#endif //#ifndef IID_IAcadBaseObject

#ifndef IID_IAcadDatabase
#define IID_IAcadDatabase		IID_IZcadDatabase
#endif //#ifndef IID_IAcadDatabase

#ifndef IID_IAcadObjectEvents
#define IID_IAcadObjectEvents		IID_IZcadObjectEvents
#endif //#ifndef IID_IAcadObjectEvents


#ifndef acdbOpenObject
#define acdbOpenObject		zcdbOpenObject
#endif //#ifndef acdbOpenObject

#ifndef acrxProductLCID
#define acrxProductLCID		zcrxProductLCID
#endif //#ifndef acrxProductLCID

#ifndef pAcadBaseObject
#define pAcadBaseObject		pZcadBaseObject
#endif //#ifndef pAcadBaseObject

#ifndef pAcadObject
#define pAcadObject		pZcadObject
#endif //#ifndef pAcadObject

#ifndef pAcadObjectEvents
#define pAcadObjectEvents		pZcadObjectEvents
#endif //#ifndef pAcadObjectEvents

#endif //#ifndef __AXTEMPL_H__
