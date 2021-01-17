
#ifndef __AXBOILER_H__
#define __AXBOILER_H__

#include "axobjref.h"
#include "adesk.h" 

#include "../inc/zaxboiler.h"

#ifndef ACAD_LWEIGHT
#define ACAD_LWEIGHT		ZCAD_LWEIGHT
#endif //#ifndef ACAD_LWEIGHT

#ifndef ACCMCOLORACCESS
#define ACCMCOLORACCESS		ZCCMCOLORACCESS
#endif //#ifndef ACCMCOLORACCESS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AD_LWEIGHT
#define AD_LWEIGHT		ZD_LWEIGHT
#endif //#ifndef AD_LWEIGHT

#ifndef AXAUTOEXP
#define AXAUTOEXP		ZXAUTOEXP
#endif //#ifndef AXAUTOEXP

#ifndef AXAUTO_DLL
#define AXAUTO_DLL		ZXAUTO_DLL
#endif //#ifndef AXAUTO_DLL

#ifndef AcAxArrayPolar
#define AcAxArrayPolar		ZcAxArrayPolar
#endif //#ifndef AcAxArrayPolar

#ifndef AcAxArrayRectangular
#define AcAxArrayRectangular		ZcAxArrayRectangular
#endif //#ifndef AcAxArrayRectangular

#ifndef AcAxCopy
#define AcAxCopy		ZcAxCopy
#endif //#ifndef AcAxCopy

#ifndef AcAxEnableShadowDisplay
#define AcAxEnableShadowDisplay		ZcAxEnableShadowDisplay
#endif //#ifndef AcAxEnableShadowDisplay

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

#ifndef RaiseAcAXException
#define RaiseAcAXException		RaiseZcAXException
#endif //#ifndef RaiseAcAXException

#ifndef RaiseArxException
#define RaiseArxException		RaiseZrxException
#endif //#ifndef RaiseArxException

#ifndef AcAxGetIUnknownOfObject
#define AcAxGetIUnknownOfObject		ZcAxGetIUnknownOfObject
#endif //#ifndef AcAxGetIUnknownOfObject

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

#ifndef AcAxGetObjectId64
#define AcAxGetObjectId64		ZcAxGetObjectId64
#endif //#ifndef AcAxGetObjectId64

#ifndef AcAxGetObjectName
#define AcAxGetObjectName		ZcAxGetObjectName
#endif //#ifndef AcAxGetObjectName

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

#ifndef AcCmColorAccess
#define AcCmColorAccess		ZcCmColorAccess
#endif //#ifndef AcCmColorAccess

#ifndef AcColor
#define AcColor		ZcColor
#endif //#ifndef AcColor

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

#ifndef AcExtendOption
#define AcExtendOption		ZcExtendOption
#endif //#ifndef AcExtendOption

#ifndef AcShadowDisplayType
#define AcShadowDisplayType		ZcShadowDisplayType
#endif //#ifndef AcShadowDisplayType

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef GetAcCmColor
#define GetAcCmColor		GetZcCmColor
#endif //#ifndef GetAcCmColor

#ifndef IAcadAcCmColor
#define IAcadAcCmColor		IZcadZcCmColor
#endif //#ifndef IAcadAcCmColor

#ifndef IAcadAcCmColorAccess
#define IAcadAcCmColorAccess		IZcadZcCmColorAccess
#endif //#ifndef IAcadAcCmColorAccess

#ifndef IAcadBaseDatabase
#define IAcadBaseDatabase		IZcadBaseDatabase
#endif //#ifndef IAcadBaseDatabase

#ifndef IAcadBaseObject
#define IAcadBaseObject		IZcadBaseObject
#endif //#ifndef IAcadBaseObject

#ifndef IAcadBaseObject2
#define IAcadBaseObject2		IZcadBaseObject2
#endif //#ifndef IAcadBaseObject2

#ifndef IAcadBaseSubEntity
#define IAcadBaseSubEntity		IZcadBaseSubEntity
#endif //#ifndef IAcadBaseSubEntity

#ifndef IAcadDictionary
#define IAcadDictionary		IZcadDictionary
#endif //#ifndef IAcadDictionary

#ifndef IAcadHyperlinks
#define IAcadHyperlinks		IZcadHyperlinks
#endif //#ifndef IAcadHyperlinks

#ifndef IAcadAcCmColor
#define IAcadAcCmColor		IZcadZcCmColor
#endif //#ifndef IAcadAcCmColor

#ifndef IAcadAcCmColorAccess
#define IAcadAcCmColorAccess		IZcadZcCmColorAccess
#endif //#ifndef IAcadAcCmColorAccess

#ifndef IID_IAcadAcCmColorAccess
#define IID_IAcadAcCmColorAccess		IID_IZcadZcCmColorAccess
#endif //#ifndef IID_IAcadAcCmColorAccess

#ifndef IID_IAcadBaseDatabase
#define IID_IAcadBaseDatabase		IID_IZcadBaseDatabase
#endif //#ifndef IID_IAcadBaseDatabase

#ifndef IID_IAcadBaseObject
#define IID_IAcadBaseObject		IID_IZcadBaseObject
#endif //#ifndef IID_IAcadBaseObject

#ifndef IID_IAcadBaseObject2
#define IID_IAcadBaseObject2		IID_IZcadBaseObject2
#endif //#ifndef IID_IAcadBaseObject2

#ifndef IID_IAcadBaseSubEntity
#define IID_IAcadBaseSubEntity		IID_IZcadBaseSubEntity
#endif //#ifndef IID_IAcadBaseSubEntity

#ifndef IID_IAcadAcCmColorAccess
#define IID_IAcadAcCmColorAccess		IID_IZcadZcCmColorAccess
#endif //#ifndef IID_IAcadAcCmColorAccess

#ifndef LPACADACCMCOLORACCESS
#define LPACADACCMCOLORACCESS		LPZCADZCCMCOLORACCESS
#endif //#ifndef LPACADACCMCOLORACCESS

#ifndef LPACADBASEDATABASE
#define LPACADBASEDATABASE		LPZCADBASEDATABASE
#endif //#ifndef LPACADBASEDATABASE

#ifndef LPACADBASEOBJECT
#define LPACADBASEOBJECT		LPZCADBASEOBJECT
#endif //#ifndef LPACADBASEOBJECT

#ifndef LPACADBASEOBJECT2
#define LPACADBASEOBJECT2		LPZCADBASEOBJECT2
#endif //#ifndef LPACADBASEOBJECT2

#ifndef LPACADSUBENTITY
#define LPACADSUBENTITY		LPZCADSUBENTITY
#endif //#ifndef LPACADSUBENTITY

#ifndef SetAcCmColor
#define SetAcCmColor		SetZcCmColor
#endif //#ifndef SetAcCmColor

#ifndef AcAxGetTransparency
#define AcAxGetTransparency ZcAxGetTransparency
#endif 

#ifndef AcAxPutTransparency
#define AcAxPutTransparency	ZcAxPutTransparency
#endif 
#endif //#ifndef __AXBOILER_H__