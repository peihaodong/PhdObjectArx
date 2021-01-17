
#ifndef __ACGS_H__
#define __ACGS_H__

#include "adesk.h"
#include "stdlib.h"
#include "AdAChar.h"

#include "../inc/zacgs.h"

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGs
#define AcGs		ZcGs
#endif //#ifndef AcGs

#ifndef AcGs2DViewLimitManager
#define AcGs2DViewLimitManager		ZcGs2DViewLimitManager
#endif //#ifndef AcGs2DViewLimitManager

#ifndef AcGsManager
#define AcGsManager		ZcGsManager
#endif //#ifndef AcGsManager

#ifndef AcGsScreenShot
#define AcGsScreenShot		ZcGsScreenShot
#endif //#ifndef AcGsScreenShot

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acgsCreate2DViewLimitManager
#define acgsCreate2DViewLimitManager		zcgsCreate2DViewLimitManager
#endif //#ifndef acgsCreate2DViewLimitManager

#ifndef acgsCustomUpdateMethod
#define acgsCustomUpdateMethod		zcgsCustomUpdateMethod
#endif //#ifndef acgsCustomUpdateMethod

#ifndef acgsDestroy2DViewLimitManager
#define acgsDestroy2DViewLimitManager		zcgsDestroy2DViewLimitManager
#endif //#ifndef acgsDestroy2DViewLimitManager

#ifndef acgsDisplayImage
#define acgsDisplayImage		zcgsDisplayImage
#endif //#ifndef acgsDisplayImage

#ifndef acgsGetDisplayInfo
#define acgsGetDisplayInfo		zcgsGetDisplayInfo
#endif //#ifndef acgsGetDisplayInfo

#ifndef acgsGetGsManager
#define acgsGetGsManager		zcgsGetGsManager
#endif //#ifndef acgsGetGsManager

#ifndef acgsGetGsView
#define acgsGetGsView		zcgsGetGsView
#endif //#ifndef acgsGetGsView

#ifndef acgsGetHighlightColor
#define acgsGetHighlightColor		zcgsGetHighlightColor
#endif //#ifndef acgsGetHighlightColor

#ifndef acgsGetHighlightLinePattern
#define acgsGetHighlightLinePattern		zcgsGetHighlightLinePattern
#endif //#ifndef acgsGetHighlightLinePattern

#ifndef acgsGetHighlightLineWeight
#define acgsGetHighlightLineWeight		zcgsGetHighlightLineWeight
#endif //#ifndef acgsGetHighlightLineWeight

#ifndef acgsGetLensLength
#define acgsGetLensLength		zcgsGetLensLength
#endif //#ifndef acgsGetLensLength

#ifndef acgsGetOrthoViewParameters
#define acgsGetOrthoViewParameters		zcgsGetOrthoViewParameters
#endif //#ifndef acgsGetOrthoViewParameters

#ifndef acgsGetScreenShot
#define acgsGetScreenShot		zcgsGetScreenShot
#endif //#ifndef acgsGetScreenShot

#ifndef acgsGetViewParameters
#define acgsGetViewParameters		zcgsGetViewParameters
#endif //#ifndef acgsGetViewParameters

#ifndef acgsGetViewportInfo
#define acgsGetViewportInfo		zcgsGetViewportInfo
#endif //#ifndef acgsGetViewportInfo

#ifndef acgsRedrawShortTermGraphics
#define acgsRedrawShortTermGraphics		zcgsRedrawShortTermGraphics
#endif //#ifndef acgsRedrawShortTermGraphics

#ifndef acgsRemoveAnonymousGraphics
#define acgsRemoveAnonymousGraphics		zcgsRemoveAnonymousGraphics
#endif //#ifndef acgsRemoveAnonymousGraphics

#ifndef acgsSetCustomUpdateMethod
#define acgsSetCustomUpdateMethod		zcgsSetCustomUpdateMethod
#endif //#ifndef acgsSetCustomUpdateMethod

#ifndef acgsSetHighlightColor
#define acgsSetHighlightColor		zcgsSetHighlightColor
#endif //#ifndef acgsSetHighlightColor

#ifndef acgsSetHighlightLinePattern
#define acgsSetHighlightLinePattern		zcgsSetHighlightLinePattern
#endif //#ifndef acgsSetHighlightLinePattern

#ifndef acgsSetHighlightLineWeight
#define acgsSetHighlightLineWeight		zcgsSetHighlightLineWeight
#endif //#ifndef acgsSetHighlightLineWeight

#ifndef acgsSetLensLength
#define acgsSetLensLength		zcgsSetLensLength
#endif //#ifndef acgsSetLensLength

#ifndef acgsSetView2D
#define acgsSetView2D		zcgsSetView2D
#endif //#ifndef acgsSetView2D

#ifndef acgsSetViewParameters
#define acgsSetViewParameters		zcgsSetViewParameters
#endif //#ifndef acgsSetViewParameters

#ifndef acgsSetViewportRenderFlag
#define acgsSetViewportRenderFlag		zcgsSetViewportRenderFlag
#endif //#ifndef acgsSetViewportRenderFlag

#ifndef acgsWriteViewToUndoController
#define acgsWriteViewToUndoController		zcgsWriteViewToUndoController
#endif //#ifndef acgsWriteViewToUndoController

#ifndef acgsSetLineWeightDisplay
#define acgsSetLineWeightDisplay		zcgsSetLineWeightDisplay
#endif //#ifndef acgsSetLineWeightDisplay

#endif //#ifndef __ACGS_H__
