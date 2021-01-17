
#ifndef __GEDWGIO_H__
#define __GEDWGIO_H__

#include "dbfiler.h"
#include "gefileio.h"
#include "gelibver.h"

#include "../inc/zgedwgio.h"

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcGeAugPolyline3d
#define AcGeAugPolyline3d		ZcGeAugPolyline3d
#endif //#ifndef AcGeAugPolyline3d

#ifndef AcGeBoundBlock2d
#define AcGeBoundBlock2d		ZcGeBoundBlock2d
#endif //#ifndef AcGeBoundBlock2d

#ifndef AcGeBoundBlock3d
#define AcGeBoundBlock3d		ZcGeBoundBlock3d
#endif //#ifndef AcGeBoundBlock3d

#ifndef AcGeBoundedPlane
#define AcGeBoundedPlane		ZcGeBoundedPlane
#endif //#ifndef AcGeBoundedPlane

#ifndef AcGeCircArc2d
#define AcGeCircArc2d		ZcGeCircArc2d
#endif //#ifndef AcGeCircArc2d

#ifndef AcGeCircArc3d
#define AcGeCircArc3d		ZcGeCircArc3d
#endif //#ifndef AcGeCircArc3d

#ifndef AcGeCompositeCurve2d
#define AcGeCompositeCurve2d		ZcGeCompositeCurve2d
#endif //#ifndef AcGeCompositeCurve2d

#ifndef AcGeCompositeCurve3d
#define AcGeCompositeCurve3d		ZcGeCompositeCurve3d
#endif //#ifndef AcGeCompositeCurve3d

#ifndef AcGeCone
#define AcGeCone		ZcGeCone
#endif //#ifndef AcGeCone

#ifndef AcGeCubicSplineCurve2d
#define AcGeCubicSplineCurve2d		ZcGeCubicSplineCurve2d
#endif //#ifndef AcGeCubicSplineCurve2d

#ifndef AcGeCubicSplineCurve3d
#define AcGeCubicSplineCurve3d		ZcGeCubicSplineCurve3d
#endif //#ifndef AcGeCubicSplineCurve3d

#ifndef AcGeCurveBoundary
#define AcGeCurveBoundary		ZcGeCurveBoundary
#endif //#ifndef AcGeCurveBoundary

#ifndef AcGeCurveCurveInt2d
#define AcGeCurveCurveInt2d		ZcGeCurveCurveInt2d
#endif //#ifndef AcGeCurveCurveInt2d

#ifndef AcGeCurveCurveInt3d
#define AcGeCurveCurveInt3d		ZcGeCurveCurveInt3d
#endif //#ifndef AcGeCurveCurveInt3d

#ifndef AcGeCylinder
#define AcGeCylinder		ZcGeCylinder
#endif //#ifndef AcGeCylinder

#ifndef AcGeDoubleArray
#define AcGeDoubleArray		ZcGeDoubleArray
#endif //#ifndef AcGeDoubleArray

#ifndef AcGeDwgIO
#define AcGeDwgIO		ZcGeDwgIO
#endif //#ifndef AcGeDwgIO

#ifndef AcGeDwgIOVersion
#define AcGeDwgIOVersion		ZcGeDwgIOVersion
#endif //#ifndef AcGeDwgIOVersion

#ifndef AcGeEllipArc2d
#define AcGeEllipArc2d		ZcGeEllipArc2d
#endif //#ifndef AcGeEllipArc2d

#ifndef AcGeEllipArc3d
#define AcGeEllipArc3d		ZcGeEllipArc3d
#endif //#ifndef AcGeEllipArc3d

#ifndef AcGeEllipCone
#define AcGeEllipCone		ZcGeEllipCone
#endif //#ifndef AcGeEllipCone

#ifndef AcGeExternalBoundedSurface
#define AcGeExternalBoundedSurface		ZcGeExternalBoundedSurface
#endif //#ifndef AcGeExternalBoundedSurface

#ifndef AcGeExternalCurve2d
#define AcGeExternalCurve2d		ZcGeExternalCurve2d
#endif //#ifndef AcGeExternalCurve2d

#ifndef AcGeExternalCurve3d
#define AcGeExternalCurve3d		ZcGeExternalCurve3d
#endif //#ifndef AcGeExternalCurve3d

#ifndef AcGeExternalSurface
#define AcGeExternalSurface		ZcGeExternalSurface
#endif //#ifndef AcGeExternalSurface

#ifndef AcGeIntArray
#define AcGeIntArray		ZcGeIntArray
#endif //#ifndef AcGeIntArray

#ifndef AcGeInterval
#define AcGeInterval		ZcGeInterval
#endif //#ifndef AcGeInterval

#ifndef AcGeKnotVector
#define AcGeKnotVector		ZcGeKnotVector
#endif //#ifndef AcGeKnotVector

#ifndef AcGeLibVersion
#define AcGeLibVersion		ZcGeLibVersion
#endif //#ifndef AcGeLibVersion

#ifndef AcGeLine2d
#define AcGeLine2d		ZcGeLine2d
#endif //#ifndef AcGeLine2d

#ifndef AcGeLine3d
#define AcGeLine3d		ZcGeLine3d
#endif //#ifndef AcGeLine3d

#ifndef AcGeLineSeg2d
#define AcGeLineSeg2d		ZcGeLineSeg2d
#endif //#ifndef AcGeLineSeg2d

#ifndef AcGeLineSeg3d
#define AcGeLineSeg3d		ZcGeLineSeg3d
#endif //#ifndef AcGeLineSeg3d

#ifndef AcGeMatrix2d
#define AcGeMatrix2d		ZcGeMatrix2d
#endif //#ifndef AcGeMatrix2d

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGeNurbCurve2d
#define AcGeNurbCurve2d		ZcGeNurbCurve2d
#endif //#ifndef AcGeNurbCurve2d

#ifndef AcGeNurbCurve3d
#define AcGeNurbCurve3d		ZcGeNurbCurve3d
#endif //#ifndef AcGeNurbCurve3d

#ifndef AcGeNurbSurface
#define AcGeNurbSurface		ZcGeNurbSurface
#endif //#ifndef AcGeNurbSurface

#ifndef AcGeOffsetCurve2d
#define AcGeOffsetCurve2d		ZcGeOffsetCurve2d
#endif //#ifndef AcGeOffsetCurve2d

#ifndef AcGeOffsetCurve3d
#define AcGeOffsetCurve3d		ZcGeOffsetCurve3d
#endif //#ifndef AcGeOffsetCurve3d

#ifndef AcGeOffsetSurface
#define AcGeOffsetSurface		ZcGeOffsetSurface
#endif //#ifndef AcGeOffsetSurface

#ifndef AcGePlane
#define AcGePlane		ZcGePlane
#endif //#ifndef AcGePlane

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint2dArray
#define AcGePoint2dArray		ZcGePoint2dArray
#endif //#ifndef AcGePoint2dArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGePointOnCurve2d
#define AcGePointOnCurve2d		ZcGePointOnCurve2d
#endif //#ifndef AcGePointOnCurve2d

#ifndef AcGePointOnCurve3d
#define AcGePointOnCurve3d		ZcGePointOnCurve3d
#endif //#ifndef AcGePointOnCurve3d

#ifndef AcGePointOnSurface
#define AcGePointOnSurface		ZcGePointOnSurface
#endif //#ifndef AcGePointOnSurface

#ifndef AcGePolyline2d
#define AcGePolyline2d		ZcGePolyline2d
#endif //#ifndef AcGePolyline2d

#ifndef AcGePolyline3d
#define AcGePolyline3d		ZcGePolyline3d
#endif //#ifndef AcGePolyline3d

#ifndef AcGePosition2d
#define AcGePosition2d		ZcGePosition2d
#endif //#ifndef AcGePosition2d

#ifndef AcGePosition3d
#define AcGePosition3d		ZcGePosition3d
#endif //#ifndef AcGePosition3d

#ifndef AcGeRay2d
#define AcGeRay2d		ZcGeRay2d
#endif //#ifndef AcGeRay2d

#ifndef AcGeRay3d
#define AcGeRay3d		ZcGeRay3d
#endif //#ifndef AcGeRay3d

#ifndef AcGeScale2d
#define AcGeScale2d		ZcGeScale2d
#endif //#ifndef AcGeScale2d

#ifndef AcGeScale3d
#define AcGeScale3d		ZcGeScale3d
#endif //#ifndef AcGeScale3d

#ifndef AcGeSphere
#define AcGeSphere		ZcGeSphere
#endif //#ifndef AcGeSphere

#ifndef AcGeTol
#define AcGeTol		ZcGeTol
#endif //#ifndef AcGeTol

#ifndef AcGeTorus
#define AcGeTorus		ZcGeTorus
#endif //#ifndef AcGeTorus

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGeVector2dArray
#define AcGeVector2dArray		ZcGeVector2dArray
#endif //#ifndef AcGeVector2dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGeVector3dArray
#define AcGeVector3dArray		ZcGeVector3dArray
#endif //#ifndef AcGeVector3dArray

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __GEDWGIO_H__
