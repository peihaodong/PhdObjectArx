
#ifndef __DBXUTIL_H__
#define __DBXUTIL_H__

#include "acadstrc.h"
#include "adesk.h"
#include "adsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "acutmem.h"

#include "windows.h"

#include "../inc/zdbxutil.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbOle2Frame
#define AcDbOle2Frame		ZcDbOle2Frame
#endif //#ifndef AcDbOle2Frame

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbCreateViewByViewport
#define acdbCreateViewByViewport		zcdbCreateViewByViewport
#endif //#ifndef acdbCreateViewByViewport

#ifndef acdbDwkFileExists
#define acdbDwkFileExists		zcdbDwkFileExists
#endif //#ifndef acdbDwkFileExists

#ifndef acdbEcs2Ucs
#define acdbEcs2Ucs		zcdbEcs2Ucs
#endif //#ifndef acdbEcs2Ucs

#ifndef acdbEcs2Wcs
#define acdbEcs2Wcs		zcdbEcs2Wcs
#endif //#ifndef acdbEcs2Wcs

#ifndef acdbForceTextAdjust
#define acdbForceTextAdjust		zcdbForceTextAdjust
#endif //#ifndef acdbForceTextAdjust

#ifndef acdbGetArcLengthSymbolPlacement
#define acdbGetArcLengthSymbolPlacement		zcdbGetArcLengthSymbolPlacement
#endif //#ifndef acdbGetArcLengthSymbolPlacement

#ifndef acdbGetCurVportId
#define acdbGetCurVportId		zcdbGetCurVportId
#endif //#ifndef acdbGetCurVportId

#ifndef acdbGetCurVportTableRecordId
#define acdbGetCurVportTableRecordId		zcdbGetCurVportTableRecordId
#endif //#ifndef acdbGetCurVportTableRecordId

#ifndef acdbGetDimAngExtOn
#define acdbGetDimAngExtOn		zcdbGetDimAngExtOn
#endif //#ifndef acdbGetDimAngExtOn

#ifndef acdbGetDimBreakSize
#define acdbGetDimBreakSize		zcdbGetDimBreakSize
#endif //#ifndef acdbGetDimBreakSize

#ifndef acdbGetDimExt1Linetype
#define acdbGetDimExt1Linetype		zcdbGetDimExt1Linetype
#endif //#ifndef acdbGetDimExt1Linetype

#ifndef acdbGetDimExt2Linetype
#define acdbGetDimExt2Linetype		zcdbGetDimExt2Linetype
#endif //#ifndef acdbGetDimExt2Linetype

#ifndef acdbGetDimExtensionLength
#define acdbGetDimExtensionLength		zcdbGetDimExtensionLength
#endif //#ifndef acdbGetDimExtensionLength

#ifndef acdbGetDimFlipArrow
#define acdbGetDimFlipArrow		zcdbGetDimFlipArrow
#endif //#ifndef acdbGetDimFlipArrow

#ifndef acdbGetDimFlipArrowWhich
#define acdbGetDimFlipArrowWhich		zcdbGetDimFlipArrowWhich
#endif //#ifndef acdbGetDimFlipArrowWhich

#ifndef acdbGetDimJogSymbolPosition
#define acdbGetDimJogSymbolPosition		zcdbGetDimJogSymbolPosition
#endif //#ifndef acdbGetDimJogSymbolPosition

#ifndef acdbGetDimJogSymbolSize
#define acdbGetDimJogSymbolSize		zcdbGetDimJogSymbolSize
#endif //#ifndef acdbGetDimJogSymbolSize

#ifndef acdbGetDimLineLinetype
#define acdbGetDimLineLinetype		zcdbGetDimLineLinetype
#endif //#ifndef acdbGetDimLineLinetype

#ifndef acdbGetDimTextBackground
#define acdbGetDimTextBackground		zcdbGetDimTextBackground
#endif //#ifndef acdbGetDimTextBackground

#ifndef acdbGetDimTolAlign
#define acdbGetDimTolAlign		zcdbGetDimTolAlign
#endif //#ifndef acdbGetDimTolAlign

#ifndef acdbGetDynDimStyleId
#define acdbGetDynDimStyleId		zcdbGetDynDimStyleId
#endif //#ifndef acdbGetDynDimStyleId

#ifndef acdbGetExemptCheckFlag
#define acdbGetExemptCheckFlag		zcdbGetExemptCheckFlag
#endif //#ifndef acdbGetExemptCheckFlag

#ifndef acdbGetExtnames
#define acdbGetExtnames		zcdbGetExtnames
#endif //#ifndef acdbGetExtnames

#ifndef acdbGetFixedLengthExtLineEnabled
#define acdbGetFixedLengthExtLineEnabled		zcdbGetFixedLengthExtLineEnabled
#endif //#ifndef acdbGetFixedLengthExtLineEnabled

#ifndef acdbGetLargeRadDimJogAngle
#define acdbGetLargeRadDimJogAngle		zcdbGetLargeRadDimJogAngle
#endif //#ifndef acdbGetLargeRadDimJogAngle

#ifndef acdbGetPreviewBitmapFromDwg
#define acdbGetPreviewBitmapFromDwg		zcdbGetPreviewBitmapFromDwg
#endif //#ifndef acdbGetPreviewBitmapFromDwg

#ifndef acdbGetProxyInfo
#define acdbGetProxyInfo		zcdbGetProxyInfo
#endif //#ifndef acdbGetProxyInfo

#ifndef acdbGetRadialExtensionAngles
#define acdbGetRadialExtensionAngles		zcdbGetRadialExtensionAngles
#endif //#ifndef acdbGetRadialExtensionAngles

#ifndef acdbGetReservedString
#define acdbGetReservedString		zcdbGetReservedString
#endif //#ifndef acdbGetReservedString

#ifndef acdbGetUnitsConversion
#define acdbGetUnitsConversion		zcdbGetUnitsConversion
#endif //#ifndef acdbGetUnitsConversion

#ifndef acdbGetViewportVisualStyle
#define acdbGetViewportVisualStyle		zcdbGetViewportVisualStyle
#endif //#ifndef acdbGetViewportVisualStyle

#ifndef acdbIsInLongTransaction
#define acdbIsInLongTransaction		zcdbIsInLongTransaction
#endif //#ifndef acdbIsInLongTransaction

#ifndef acdbIsReservedString
#define acdbIsReservedString		zcdbIsReservedString
#endif //#ifndef acdbIsReservedString

#ifndef acdbOleGetOriginalSelectedFontName
#define acdbOleGetOriginalSelectedFontName		zcdbOleGetOriginalSelectedFontName
#endif //#ifndef acdbOleGetOriginalSelectedFontName

#ifndef acdbOleGetOriginalSelectedFontPointSize
#define acdbOleGetOriginalSelectedFontPointSize		zcdbOleGetOriginalSelectedFontPointSize
#endif //#ifndef acdbOleGetOriginalSelectedFontPointSize

#ifndef acdbOleGetOriginalSelectedTextSizeInAcadUnits
#define acdbOleGetOriginalSelectedTextSizeInAcadUnits		zcdbOleGetOriginalSelectedTextSizeInZcadUnits
#endif //#ifndef acdbOleGetOriginalSelectedTextSizeInAcadUnits

#ifndef acdbOleGetOriginalWidthHeight
#define acdbOleGetOriginalWidthHeight		zcdbOleGetOriginalWidthHeight
#endif //#ifndef acdbOleGetOriginalWidthHeight

#ifndef acdbOleGetRotationMatrix
#define acdbOleGetRotationMatrix		zcdbOleGetRotationMatrix
#endif //#ifndef acdbOleGetRotationMatrix

#ifndef acdbOleGetSelectedFontName
#define acdbOleGetSelectedFontName		zcdbOleGetSelectedFontName
#endif //#ifndef acdbOleGetSelectedFontName

#ifndef acdbOleGetSelectedFontPointSize
#define acdbOleGetSelectedFontPointSize		zcdbOleGetSelectedFontPointSize
#endif //#ifndef acdbOleGetSelectedFontPointSize

#ifndef acdbOleGetSelectedTextSizeInAcadUnits
#define acdbOleGetSelectedTextSizeInAcadUnits		zcdbOleGetSelectedTextSizeInZcadUnits
#endif //#ifndef acdbOleGetSelectedTextSizeInAcadUnits

#ifndef acdbOleHitTest
#define acdbOleHitTest		zcdbOleHitTest
#endif //#ifndef acdbOleHitTest

#ifndef acdbOleSetOriginalSelectedFontName
#define acdbOleSetOriginalSelectedFontName		zcdbOleSetOriginalSelectedFontName
#endif //#ifndef acdbOleSetOriginalSelectedFontName

#ifndef acdbOleSetOriginalSelectedFontPointSize
#define acdbOleSetOriginalSelectedFontPointSize		zcdbOleSetOriginalSelectedFontPointSize
#endif //#ifndef acdbOleSetOriginalSelectedFontPointSize

#ifndef acdbOleSetOriginalSelectedTextSizeInAcadUnits
#define acdbOleSetOriginalSelectedTextSizeInAcadUnits		zcdbOleSetOriginalSelectedTextSizeInZcadUnits
#endif //#ifndef acdbOleSetOriginalSelectedTextSizeInAcadUnits

#ifndef acdbOleSetOriginalWidthHeight
#define acdbOleSetOriginalWidthHeight		zcdbOleSetOriginalWidthHeight
#endif //#ifndef acdbOleSetOriginalWidthHeight

#ifndef acdbOleSetSelectedFontName
#define acdbOleSetSelectedFontName		zcdbOleSetSelectedFontName
#endif //#ifndef acdbOleSetSelectedFontName

#ifndef acdbOleSetSelectedFontPointSize
#define acdbOleSetSelectedFontPointSize		zcdbOleSetSelectedFontPointSize
#endif //#ifndef acdbOleSetSelectedFontPointSize

#ifndef acdbOleSetSelectedTextSizeInAcadUnits
#define acdbOleSetSelectedTextSizeInAcadUnits		zcdbOleSetSelectedTextSizeInZcadUnits
#endif //#ifndef acdbOleSetSelectedTextSizeInAcadUnits

#ifndef acdbQueueForRegen
#define acdbQueueForRegen		zcdbQueueForRegen
#endif //#ifndef acdbQueueForRegen

#ifndef acdbSetArcLengthSymbolPlacement
#define acdbSetArcLengthSymbolPlacement		zcdbSetArcLengthSymbolPlacement
#endif //#ifndef acdbSetArcLengthSymbolPlacement

#ifndef acdbSetDimAngExtOn
#define acdbSetDimAngExtOn		zcdbSetDimAngExtOn
#endif //#ifndef acdbSetDimAngExtOn

#ifndef acdbSetDimBreakSize
#define acdbSetDimBreakSize		zcdbSetDimBreakSize
#endif //#ifndef acdbSetDimBreakSize

#ifndef acdbSetDimExt1Linetype
#define acdbSetDimExt1Linetype		zcdbSetDimExt1Linetype
#endif //#ifndef acdbSetDimExt1Linetype

#ifndef acdbSetDimExt2Linetype
#define acdbSetDimExt2Linetype		zcdbSetDimExt2Linetype
#endif //#ifndef acdbSetDimExt2Linetype

#ifndef acdbSetDimExtensionLength
#define acdbSetDimExtensionLength		zcdbSetDimExtensionLength
#endif //#ifndef acdbSetDimExtensionLength

#ifndef acdbSetDimFlipArrow
#define acdbSetDimFlipArrow		zcdbSetDimFlipArrow
#endif //#ifndef acdbSetDimFlipArrow

#ifndef acdbSetDimFlipArrowWhich
#define acdbSetDimFlipArrowWhich		zcdbSetDimFlipArrowWhich
#endif //#ifndef acdbSetDimFlipArrowWhich

#ifndef acdbSetDimJogSymbolPosition
#define acdbSetDimJogSymbolPosition		zcdbSetDimJogSymbolPosition
#endif //#ifndef acdbSetDimJogSymbolPosition

#ifndef acdbSetDimJogSymbolSize
#define acdbSetDimJogSymbolSize		zcdbSetDimJogSymbolSize
#endif //#ifndef acdbSetDimJogSymbolSize

#ifndef acdbSetDimLineLinetype
#define acdbSetDimLineLinetype		zcdbSetDimLineLinetype
#endif //#ifndef acdbSetDimLineLinetype

#ifndef acdbSetDimTextBackground
#define acdbSetDimTextBackground		zcdbSetDimTextBackground
#endif //#ifndef acdbSetDimTextBackground

#ifndef acdbSetDimTolAlign
#define acdbSetDimTolAlign		zcdbSetDimTolAlign
#endif //#ifndef acdbSetDimTolAlign

#ifndef acdbSetExemptCheckFlag
#define acdbSetExemptCheckFlag		zcdbSetExemptCheckFlag
#endif //#ifndef acdbSetExemptCheckFlag

#ifndef acdbSetExtnames
#define acdbSetExtnames		zcdbSetExtnames
#endif //#ifndef acdbSetExtnames

#ifndef acdbSetFixedLengthExtLineEnabled
#define acdbSetFixedLengthExtLineEnabled		zcdbSetFixedLengthExtLineEnabled
#endif //#ifndef acdbSetFixedLengthExtLineEnabled

#ifndef acdbSetLargeRadDimJogAngle
#define acdbSetLargeRadDimJogAngle		zcdbSetLargeRadDimJogAngle
#endif //#ifndef acdbSetLargeRadDimJogAngle

#ifndef acdbSetRadialExtensionAngles
#define acdbSetRadialExtensionAngles		zcdbSetRadialExtensionAngles
#endif //#ifndef acdbSetRadialExtensionAngles

#ifndef acdbSetViewportVisualStyle
#define acdbSetViewportVisualStyle		zcdbSetViewportVisualStyle
#endif //#ifndef acdbSetViewportVisualStyle

#ifndef acdbUcs2Ecs
#define acdbUcs2Ecs		zcdbUcs2Ecs
#endif //#ifndef acdbUcs2Ecs

#ifndef acdbUcs2Wcs
#define acdbUcs2Wcs		zcdbUcs2Wcs
#endif //#ifndef acdbUcs2Wcs

#ifndef acdbUcsMatrix
#define acdbUcsMatrix		zcdbUcsMatrix
#endif //#ifndef acdbUcsMatrix

#ifndef acdbWcs2Ecs
#define acdbWcs2Ecs		zcdbWcs2Ecs
#endif //#ifndef acdbWcs2Ecs

#ifndef acdbWcs2Ucs
#define acdbWcs2Ucs		zcdbWcs2Ucs
#endif //#ifndef acdbWcs2Ucs

#ifndef acdbXlateReservedString
#define acdbXlateReservedString		zcdbXlateReservedString
#endif //#ifndef acdbXlateReservedString

#ifndef acutmem
#define acutmem		zcutmem
#endif //#ifndef acutmem

#ifndef ads_point
#define ads_point		zds_point
#endif //#ifndef ads_point

#ifndef acdbSwapBlockEntities
#define acdbSwapBlockEntities		zcdbSwapBlockEntities
#endif //#ifndef acdbSwapBlockEntities

#endif //#ifndef __DBXUTIL_H__
