

#ifndef ZC_GEDWGIO_H
#define ZC_GEDWGIO_H

#include "zdbfiler.h"
#include "zgefileio.h"
#include "zgelibver.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeDwgIO
{
public:

    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeMatrix2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeScale2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint2dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector2dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeMatrix3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeScale3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePoint3dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeVector3dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeTol&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeInterval&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeKnotVector&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeDoubleArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeIntArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveBoundary&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePosition2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLine2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLineSeg2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeRay2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCircArc2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipArc2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCubicSplineCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCompositeCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePolyline2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePosition3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePointOnSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLine3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeRay3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeLineSeg3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePlane&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundedPlane&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCircArc3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipArc3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCubicSplineCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCompositeCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGePolyline3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeAugPolyline3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCone&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCylinder&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeTorus&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeExternalSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeOffsetSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeNurbSurface&);
    static
   Zcad::ErrorStatus outFields(ZcDbDwgFiler*,const ZcGeExternalBoundedSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeSphere&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundBlock2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeBoundBlock3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveCurveInt2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeCurveCurveInt3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDwgFiler*, const ZcGeEllipCone&);

    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeMatrix2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeScale2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint2dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector2dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeMatrix3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeScale3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePoint3dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeVector3dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeTol&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeInterval&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeKnotVector&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeDoubleArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeIntArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveBoundary&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePosition2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLine2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLineSeg2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeRay2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCircArc2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipArc2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCubicSplineCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCompositeCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePolyline2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePosition3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePointOnSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLine3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeRay3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeLineSeg3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePlane&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundedPlane&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCircArc3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipArc3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCubicSplineCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCompositeCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGePolyline3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeAugPolyline3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCone&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCylinder&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeTorus&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeOffsetSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeNurbSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeExternalBoundedSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeSphere&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundBlock2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeBoundBlock3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveCurveInt2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeCurveCurveInt3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDwgFiler*, ZcGeEllipCone&);

    static const ZcGeLibVersion  ZcGeDwgIOVersion;
};

#pragma pack (pop)
#endif
