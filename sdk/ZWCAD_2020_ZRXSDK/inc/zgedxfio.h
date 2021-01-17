

#ifndef ZC_GEDXFIO_H
#define ZC_GEDXFIO_H

#include "zdbfiler.h"
#include "zgefileio.h"
#include "zgelibver.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeDxfIO
{
public:

    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeMatrix2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeScale2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint2dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector2dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeMatrix3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeScale3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePoint3dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeVector3dArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeTol&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeInterval&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeKnotVector&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeDoubleArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeIntArray&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveBoundary&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePosition2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLine2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLineSeg2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeRay2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCircArc2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipArc2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCubicSplineCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCompositeCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetCurve2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePolyline2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePosition3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePointOnSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLine3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeRay3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeLineSeg3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePlane&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundedPlane&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCircArc3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipArc3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCubicSplineCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCompositeCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGePolyline3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeAugPolyline3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalCurve3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCone&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCylinder&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeTorus&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeExternalSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeOffsetSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeNurbSurface&);
    static
   Zcad::ErrorStatus outFields(ZcDbDxfFiler*,const ZcGeExternalBoundedSurface&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeSphere&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundBlock2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeBoundBlock3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveCurveInt2d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeCurveCurveInt3d&);
    static
    Zcad::ErrorStatus outFields(ZcDbDxfFiler*, const ZcGeEllipCone&);

    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeMatrix2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeScale2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint2dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector2dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeMatrix3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeScale3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePoint3dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeVector3dArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeTol&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeInterval&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeKnotVector&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeDoubleArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeIntArray&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveBoundary&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePosition2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLine2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLineSeg2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeRay2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCircArc2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipArc2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCubicSplineCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCompositeCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetCurve2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePolyline2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePosition3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePointOnSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLine3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeRay3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeLineSeg3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePlane&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundedPlane&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCircArc3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipArc3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCubicSplineCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCompositeCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGePolyline3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeAugPolyline3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalCurve3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCone&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCylinder&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeTorus&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeOffsetSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeNurbSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeExternalBoundedSurface&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeSphere&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundBlock2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeBoundBlock3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveCurveInt2d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeCurveCurveInt3d&);
    static
    Zcad::ErrorStatus inFields(ZcDbDxfFiler*, ZcGeEllipCone&);

    static const ZcGeLibVersion  ZcGeDxfIOVersion;
};

#pragma pack (pop)
#endif
