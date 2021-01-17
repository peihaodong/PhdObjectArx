
#ifndef __ACGI_H__
#define __ACGI_H__

#include "rxobject.h"
#include "AdAChar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "gepnt2d.h"
#include "dbcolor.h"
#include "acdb.h"
#include "AcGiStyleAttributes.h"
#include "assert.h"
#include "acgiparameter.h"

#include "../inc/zacgi.h"

#ifndef ACGI_SERVICES
#define ACGI_SERVICES		ZCGI_SERVICES
#endif //#ifndef ACGI_SERVICES

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcCmEntityColor
#define AcCmEntityColor		ZcCmEntityColor
#endif //#ifndef AcCmEntityColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbImpText
#define AcDbImpText		ZcDbImpText
#endif //#ifndef AcDbImpText

#ifndef AcDbLayerTableRecord
#define AcDbLayerTableRecord		ZcDbLayerTableRecord
#endif //#ifndef AcDbLayerTableRecord

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbPolyline
#define AcDbPolyline		ZcDbPolyline
#endif //#ifndef AcDbPolyline

#ifndef AcGeMatrix2d
#define AcGeMatrix2d		ZcGeMatrix2d
#endif //#ifndef AcGeMatrix2d

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint2dArray
#define AcGePoint2dArray		ZcGePoint2dArray
#endif //#ifndef AcGePoint2dArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiArcType
#define AcGiArcType		ZcGiArcType
#endif //#ifndef AcGiArcType

#ifndef AcGiClipBoundary
#define AcGiClipBoundary		ZcGiClipBoundary
#endif //#ifndef AcGiClipBoundary

#ifndef AcGiColorIntensity
#define AcGiColorIntensity		ZcGiColorIntensity
#endif //#ifndef AcGiColorIntensity

#ifndef AcGiColorRGB
#define AcGiColorRGB		ZcGiColorRGB
#endif //#ifndef AcGiColorRGB

#ifndef AcGiColorRGBA
#define AcGiColorRGBA		ZcGiColorRGBA
#endif //#ifndef AcGiColorRGBA

#ifndef AcGiCommonDraw
#define AcGiCommonDraw		ZcGiCommonDraw
#endif //#ifndef AcGiCommonDraw

#ifndef AcGiContext
#define AcGiContext		ZcGiContext
#endif //#ifndef AcGiContext

#ifndef AcGiContextImp
#define AcGiContextImp		ZcGiContextImp
#endif //#ifndef AcGiContextImp

#ifndef AcGiContextualColors
#define AcGiContextualColors		ZcGiContextualColors
#endif //#ifndef AcGiContextualColors

#ifndef AcGiContextualColors2
#define AcGiContextualColors2		ZcGiContextualColors2
#endif //#ifndef AcGiContextualColors2

#ifndef AcGiDeviationType
#define AcGiDeviationType		ZcGiDeviationType
#endif //#ifndef AcGiDeviationType

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGiDrawableTraits
#define AcGiDrawableTraits		ZcGiDrawableTraits
#endif //#ifndef AcGiDrawableTraits

#ifndef AcGiEdgeData
#define AcGiEdgeData		ZcGiEdgeData
#endif //#ifndef AcGiEdgeData

#ifndef AcGiEdgeStyle
#define AcGiEdgeStyle		ZcGiEdgeStyle
#endif //#ifndef AcGiEdgeStyle

#ifndef AcGiEdgeStyleMask
#define AcGiEdgeStyleMask		ZcGiEdgeStyleMask
#endif //#ifndef AcGiEdgeStyleMask

#ifndef AcGiEdgeStyleMaskValues
#define AcGiEdgeStyleMaskValues		ZcGiEdgeStyleMaskValues
#endif //#ifndef AcGiEdgeStyleMaskValues

#ifndef AcGiFaceData
#define AcGiFaceData		ZcGiFaceData
#endif //#ifndef AcGiFaceData

#ifndef AcGiFillType
#define AcGiFillType		ZcGiFillType
#endif //#ifndef AcGiFillType

#ifndef AcGiGeometry
#define AcGiGeometry		ZcGiGeometry
#endif //#ifndef AcGiGeometry

#ifndef AcGiImageOrg
#define AcGiImageOrg		ZcGiImageOrg
#endif //#ifndef AcGiImageOrg

#ifndef AcGiImageOrient
#define AcGiImageOrient		ZcGiImageOrient
#endif //#ifndef AcGiImageOrient

#ifndef AcGiImpEdgeData
#define AcGiImpEdgeData		ZcGiImpEdgeData
#endif //#ifndef AcGiImpEdgeData

#ifndef AcGiImpFaceData
#define AcGiImpFaceData		ZcGiImpFaceData
#endif //#ifndef AcGiImpFaceData

#ifndef AcGiImpTextStyle
#define AcGiImpTextStyle		ZcGiImpTextStyle
#endif //#ifndef AcGiImpTextStyle

#ifndef AcGiImpVariant
#define AcGiImpVariant		ZcGiImpVariant
#endif //#ifndef AcGiImpVariant

#ifndef AcGiImpVertexData
#define AcGiImpVertexData		ZcGiImpVertexData
#endif //#ifndef AcGiImpVertexData

#ifndef AcGiMapper
#define AcGiMapper		ZcGiMapper
#endif //#ifndef AcGiMapper

#ifndef AcGiNonEntityTraits
#define AcGiNonEntityTraits		ZcGiNonEntityTraits
#endif //#ifndef AcGiNonEntityTraits

#ifndef AcGiOrientationType
#define AcGiOrientationType		ZcGiOrientationType
#endif //#ifndef AcGiOrientationType

#ifndef AcGiRegenType
#define AcGiRegenType		ZcGiRegenType
#endif //#ifndef AcGiRegenType

#ifndef AcGiRequestScanLines
#define AcGiRequestScanLines		ZcGiRequestScanLines
#endif //#ifndef AcGiRequestScanLines

#ifndef AcGiRotationFilterType
#define AcGiRotationFilterType		ZcGiRotationFilterType
#endif //#ifndef AcGiRotationFilterType

#ifndef AcGiScaleFilterType
#define AcGiScaleFilterType		ZcGiScaleFilterType
#endif //#ifndef AcGiScaleFilterType

#ifndef AcGiScaleType
#define AcGiScaleType		ZcGiScaleType
#endif //#ifndef AcGiScaleType

#ifndef AcGiSelectionMarkerACADReserveEnd
#define AcGiSelectionMarkerACADReserveEnd		ZcGiSelectionMarkerZCADReserveEnd
#endif //#ifndef AcGiSelectionMarkerACADReserveEnd

#ifndef AcGiSelectionMarkerACADReserveStart
#define AcGiSelectionMarkerACADReserveStart		ZcGiSelectionMarkerZCADReserveStart
#endif //#ifndef AcGiSelectionMarkerACADReserveStart

#ifndef AcGiSelectionMarkerACADSelectionPreviewOff
#define AcGiSelectionMarkerACADSelectionPreviewOff		ZcGiSelectionMarkerZCADSelectionPreviewOff
#endif //#ifndef AcGiSelectionMarkerACADSelectionPreviewOff

#ifndef AcGiSelectionMarkerACADSelectionPreviewOn
#define AcGiSelectionMarkerACADSelectionPreviewOn		ZcGiSelectionMarkerZCADSelectionPreviewOn
#endif //#ifndef AcGiSelectionMarkerACADSelectionPreviewOn

#ifndef AcGiSentScanLines
#define AcGiSentScanLines		ZcGiSentScanLines
#endif //#ifndef AcGiSentScanLines

#ifndef AcGiServices
#define AcGiServices		ZcGiServices
#endif //#ifndef AcGiServices

#ifndef AcGiStyleAttributes
#define AcGiStyleAttributes		ZcGiStyleAttributes
#endif //#ifndef AcGiStyleAttributes

#ifndef AcGiSubEntityTraits
#define AcGiSubEntityTraits		ZcGiSubEntityTraits
#endif //#ifndef AcGiSubEntityTraits

#ifndef AcGiSubEntityTraitsImp
#define AcGiSubEntityTraitsImp		ZcGiSubEntityTraitsImp
#endif //#ifndef AcGiSubEntityTraitsImp

#ifndef AcGiTextHook
#define AcGiTextHook		ZcGiTextHook
#endif //#ifndef AcGiTextHook

#ifndef AcGiTextStyle
#define AcGiTextStyle		ZcGiTextStyle
#endif //#ifndef AcGiTextStyle

#ifndef AcGiVariant
#define AcGiVariant		ZcGiVariant
#endif //#ifndef AcGiVariant

#ifndef AcGiVertexData
#define AcGiVertexData		ZcGiVertexData
#endif //#ifndef AcGiVertexData

#ifndef AcGiViewport
#define AcGiViewport		ZcGiViewport
#endif //#ifndef AcGiViewport

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiViewportGeometry
#define AcGiViewportGeometry		ZcGiViewportGeometry
#endif //#ifndef AcGiViewportGeometry

#ifndef AcGiViewportTraits
#define AcGiViewportTraits		ZcGiViewportTraits
#endif //#ifndef AcGiViewportTraits

#ifndef AcGiVisibility
#define AcGiVisibility		ZcGiVisibility
#endif //#ifndef AcGiVisibility

#ifndef AcGiVisualStyleTraits
#define AcGiVisualStyleTraits		ZcGiVisualStyleTraits
#endif //#ifndef AcGiVisualStyleTraits

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcGiWorldGeometry
#define AcGiWorldGeometry		ZcGiWorldGeometry
#endif //#ifndef AcGiWorldGeometry

#ifndef AcGiWorldSegmentCallback
#define AcGiWorldSegmentCallback		ZcGiWorldSegmentCallback
#endif //#ifndef AcGiWorldSegmentCallback

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef GiSelectionMarkerACADReserveEnd
#define GiSelectionMarkerACADReserveEnd		GiSelectionMarkerZCADReserveEnd
#endif //#ifndef GiSelectionMarkerACADReserveEnd

#ifndef GiSelectionMarkerACADReserveStart
#define GiSelectionMarkerACADReserveStart		GiSelectionMarkerZCADReserveStart
#endif //#ifndef GiSelectionMarkerACADReserveStart

#ifndef GiSelectionMarkerACADSelectionPreviewOff
#define GiSelectionMarkerACADSelectionPreviewOff		GiSelectionMarkerZCADSelectionPreviewOff
#endif //#ifndef GiSelectionMarkerACADSelectionPreviewOff

#ifndef GiSelectionMarkerACADSelectionPreviewOn
#define GiSelectionMarkerACADSelectionPreviewOn		GiSelectionMarkerZCADSelectionPreviewOn
#endif //#ifndef GiSelectionMarkerACADSelectionPreviewOn

#ifndef ZcGiSelectionMarkerACADReserveEnd
#define ZcGiSelectionMarkerACADReserveEnd		ZcGiSelectionMarkerZCADReserveEnd
#endif //#ifndef ZcGiSelectionMarkerACADReserveEnd

#ifndef ZcGiSelectionMarkerACADReserveStart
#define ZcGiSelectionMarkerACADReserveStart		ZcGiSelectionMarkerZCADReserveStart
#endif //#ifndef ZcGiSelectionMarkerACADReserveStart

#ifndef ZcGiSelectionMarkerACADSelectionPreviewOff
#define ZcGiSelectionMarkerACADSelectionPreviewOff		ZcGiSelectionMarkerZCADSelectionPreviewOff
#endif //#ifndef ZcGiSelectionMarkerACADSelectionPreviewOff

#ifndef ZcGiSelectionMarkerACADSelectionPreviewOn
#define ZcGiSelectionMarkerACADSelectionPreviewOn		ZcGiSelectionMarkerZCADSelectionPreviewOn
#endif //#ifndef ZcGiSelectionMarkerACADSelectionPreviewOn

#ifndef acadWindowId
#define acadWindowId		zcadWindowId
#endif //#ifndef acadWindowId

#ifndef acgiId
#define acgiId		zcgiId
#endif //#ifndef acgiId

#ifndef acgiIsValidClipBoundary
#define acgiIsValidClipBoundary		zcgiIsValidClipBoundary
#endif //#ifndef acgiIsValidClipBoundary

#ifndef kAcGiABGR
#define kAcGiABGR		kZcGiABGR
#endif //#ifndef kAcGiABGR

#ifndef kAcGiARGB
#define kAcGiARGB		kZcGiARGB
#endif //#ifndef kAcGiARGB

#ifndef kAcGiArcChord
#define kAcGiArcChord		kZcGiArcChord
#endif //#ifndef kAcGiArcChord

#ifndef kAcGiArcSector
#define kAcGiArcSector		kZcGiArcSector
#endif //#ifndef kAcGiArcSector

#ifndef kAcGiArcSimple
#define kAcGiArcSimple		kZcGiArcSimple
#endif //#ifndef kAcGiArcSimple

#ifndef kAcGiBGR
#define kAcGiBGR		kZcGiBGR
#endif //#ifndef kAcGiBGR

#ifndef kAcGiBGRA
#define kAcGiBGRA		kZcGiBGRA
#endif //#ifndef kAcGiBGRA

#ifndef kAcGiBitonal
#define kAcGiBitonal		kZcGiBitonal
#endif //#ifndef kAcGiBitonal

#ifndef kAcGiClockwise
#define kAcGiClockwise		kZcGiClockwise
#endif //#ifndef kAcGiClockwise

#ifndef kAcGiColorIntensity1
#define kAcGiColorIntensity1		kZcGiColorIntensity1
#endif //#ifndef kAcGiColorIntensity1

#ifndef kAcGiColorIntensity2
#define kAcGiColorIntensity2		kZcGiColorIntensity2
#endif //#ifndef kAcGiColorIntensity2

#ifndef kAcGiColorIntensity3
#define kAcGiColorIntensity3		kZcGiColorIntensity3
#endif //#ifndef kAcGiColorIntensity3

#ifndef kAcGiColorIntensity4
#define kAcGiColorIntensity4		kZcGiColorIntensity4
#endif //#ifndef kAcGiColorIntensity4

#ifndef kAcGiColorIntensity5
#define kAcGiColorIntensity5		kZcGiColorIntensity5
#endif //#ifndef kAcGiColorIntensity5

#ifndef kAcGiColorIntensity6
#define kAcGiColorIntensity6		kZcGiColorIntensity6
#endif //#ifndef kAcGiColorIntensity6

#ifndef kAcGiCounterClockwise
#define kAcGiCounterClockwise		kZcGiCounterClockwise
#endif //#ifndef kAcGiCounterClockwise

#ifndef kAcGiEdgeColorMask
#define kAcGiEdgeColorMask		kZcGiEdgeColorMask
#endif //#ifndef kAcGiEdgeColorMask

#ifndef kAcGiFillAlways
#define kAcGiFillAlways		kZcGiFillAlways
#endif //#ifndef kAcGiFillAlways

#ifndef kAcGiFillNever
#define kAcGiFillNever		kZcGiFillNever
#endif //#ifndef kAcGiFillNever

#ifndef kAcGiForExplode
#define kAcGiForExplode		kZcGiForExplode
#endif //#ifndef kAcGiForExplode

#ifndef kAcGiGray
#define kAcGiGray		kZcGiGray
#endif //#ifndef kAcGiGray

#ifndef kAcGiHideOrShadeCommand
#define kAcGiHideOrShadeCommand		kZcGiHideOrShadeCommand
#endif //#ifndef kAcGiHideOrShadeCommand

#ifndef kAcGiInvisible
#define kAcGiInvisible		kZcGiInvisible
#endif //#ifndef kAcGiInvisible

#ifndef kAcGiJitterMask
#define kAcGiJitterMask		kZcGiJitterMask
#endif //#ifndef kAcGiJitterMask

#ifndef kAcGiMaxColorIntensity
#define kAcGiMaxColorIntensity		kZcGiMaxColorIntensity
#endif //#ifndef kAcGiMaxColorIntensity

#ifndef kAcGiMaxDevForBoundary
#define kAcGiMaxDevForBoundary		kZcGiMaxDevForBoundary
#endif //#ifndef kAcGiMaxDevForBoundary

#ifndef kAcGiMaxDevForCircle
#define kAcGiMaxDevForCircle		kZcGiMaxDevForCircle
#endif //#ifndef kAcGiMaxDevForCircle

#ifndef kAcGiMaxDevForCurve
#define kAcGiMaxDevForCurve		kZcGiMaxDevForCurve
#endif //#ifndef kAcGiMaxDevForCurve

#ifndef kAcGiMaxDevForFacet
#define kAcGiMaxDevForFacet		kZcGiMaxDevForFacet
#endif //#ifndef kAcGiMaxDevForFacet

#ifndef kAcGiMaxDevForIsoline
#define kAcGiMaxDevForIsoline		kZcGiMaxDevForIsoline
#endif //#ifndef kAcGiMaxDevForIsoline

#ifndef kAcGiMinColorIntensity
#define kAcGiMinColorIntensity		kZcGiMinColorIntensity
#endif //#ifndef kAcGiMinColorIntensity

#ifndef kAcGiNoEdgeStyleMask
#define kAcGiNoEdgeStyleMask		kZcGiNoEdgeStyleMask
#endif //#ifndef kAcGiNoEdgeStyleMask

#ifndef kAcGiNoOrientation
#define kAcGiNoOrientation		kZcGiNoOrientation
#endif //#ifndef kAcGiNoOrientation

#ifndef kAcGiOverhangMask
#define kAcGiOverhangMask		kZcGiOverhangMask
#endif //#ifndef kAcGiOverhangMask

#ifndef kAcGiPalette
#define kAcGiPalette		kZcGiPalette
#endif //#ifndef kAcGiPalette

#ifndef kAcGiRGB
#define kAcGiRGB		kZcGiRGB
#endif //#ifndef kAcGiRGB

#ifndef kAcGiRGBA
#define kAcGiRGBA		kZcGiRGBA
#endif //#ifndef kAcGiRGBA

#ifndef kAcGiRenderCommand
#define kAcGiRenderCommand		kZcGiRenderCommand
#endif //#ifndef kAcGiRenderCommand

#ifndef kAcGiSaveWorldDrawForProxy
#define kAcGiSaveWorldDrawForProxy		kZcGiSaveWorldDrawForProxy
#endif //#ifndef kAcGiSaveWorldDrawForProxy

#ifndef kAcGiSaveWorldDrawForR12
#define kAcGiSaveWorldDrawForR12		kZcGiSaveWorldDrawForR12
#endif //#ifndef kAcGiSaveWorldDrawForR12

#ifndef kAcGiShadedDisplay
#define kAcGiShadedDisplay		kZcGiShadedDisplay
#endif //#ifndef kAcGiShadedDisplay

#ifndef kAcGiSilhouette
#define kAcGiSilhouette		kZcGiSilhouette
#endif //#ifndef kAcGiSilhouette

#ifndef kAcGiStandardDisplay
#define kAcGiStandardDisplay		kZcGiStandardDisplay
#endif //#ifndef kAcGiStandardDisplay

#ifndef kAcGiVisible
#define kAcGiVisible		kZcGiVisible
#endif //#ifndef kAcGiVisible

#ifndef kAcGiXLeftToRightBottomFirst
#define kAcGiXLeftToRightBottomFirst		kZcGiXLeftToRightBottomFirst
#endif //#ifndef kAcGiXLeftToRightBottomFirst

#ifndef kAcGiXLeftToRightTopFirst
#define kAcGiXLeftToRightTopFirst		kZcGiXLeftToRightTopFirst
#endif //#ifndef kAcGiXLeftToRightTopFirst

#ifndef kAcGiXRightToLeftBottomFirst
#define kAcGiXRightToLeftBottomFirst		kZcGiXRightToLeftBottomFirst
#endif //#ifndef kAcGiXRightToLeftBottomFirst

#ifndef kAcGiXRightToLeftTopFirst
#define kAcGiXRightToLeftTopFirst		kZcGiXRightToLeftTopFirst
#endif //#ifndef kAcGiXRightToLeftTopFirst

#ifndef kAcGiYBottomToTopLeftFirst
#define kAcGiYBottomToTopLeftFirst		kZcGiYBottomToTopLeftFirst
#endif //#ifndef kAcGiYBottomToTopLeftFirst

#ifndef kAcGiYBottomToTopRightFirst
#define kAcGiYBottomToTopRightFirst		kZcGiYBottomToTopRightFirst
#endif //#ifndef kAcGiYBottomToTopRightFirst

#ifndef kAcGiYTopToBottomLeftFirst
#define kAcGiYTopToBottomLeftFirst		kZcGiYTopToBottomLeftFirst
#endif //#ifndef kAcGiYTopToBottomLeftFirst

#ifndef kAcGiYTopToBottomRightFirst
#define kAcGiYTopToBottomRightFirst		kZcGiYTopToBottomRightFirst
#endif //#ifndef kAcGiYTopToBottomRightFirst

#ifndef mpAcGiImpEdgeData
#define mpAcGiImpEdgeData		mpZcGiImpEdgeData
#endif //#ifndef mpAcGiImpEdgeData

#ifndef mpAcGiImpFaceData
#define mpAcGiImpFaceData		mpZcGiImpFaceData
#endif //#ifndef mpAcGiImpFaceData

#ifndef mpAcGiImpTextStyle
#define mpAcGiImpTextStyle		mpZcGiImpTextStyle
#endif //#ifndef mpAcGiImpTextStyle

#ifndef mpAcGiImpVariant
#define mpAcGiImpVariant		mpZcGiImpVariant
#endif //#ifndef mpAcGiImpVariant

#ifndef mpAcGiImpVertexData
#define mpAcGiImpVertexData		mpZcGiImpVertexData
#endif //#ifndef mpAcGiImpVertexData

#ifndef kDrawUseAcGiEntityForDgnLineType
#define kDrawUseAcGiEntityForDgnLineType kDrawUseZcGiEntityForDgnLineType
#endif 

#ifndef AcGiPositionTransformBehavior
#define AcGiPositionTransformBehavior	ZcGiPositionTransformBehavior
#endif 

#ifndef AcGiScaleTransformBehavior
#define AcGiScaleTransformBehavior		ZcGiScaleTransformBehavior
#endif 

#ifndef AcGiOrientationTransformBehavior
#define AcGiOrientationTransformBehavior	ZcGiOrientationTransformBehavior
#endif 

#ifndef AcGiGdiDrawObject
#define AcGiGdiDrawObject	ZcGiGdiDrawObject
#endif 

#ifndef AcGiPixelBGRA32
#define AcGiPixelBGRA32	ZcGiPixelBGRA32
#endif 

#ifndef AcGiImageBGRA32
#define AcGiImageBGRA32	ZcGiImageBGRA32
#endif 

#endif //#ifndef __ACGI_H__