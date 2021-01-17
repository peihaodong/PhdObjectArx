

#ifndef ZC_GEFILEIO_H
#define ZC_GEFILEIO_H

#include "zgegbl.h"
#include "zgedll.h"
#include "zdbfiler.h"
#include "zgept2dar.h"
#include "zgevc2dar.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#include "zgedblar.h"
#include "zgeintarr.h"
#pragma pack (push, 8)
     
class ZcGeEntity2d;
class ZcGeEntity3d;
class ZcGePoint2d;
class ZcGeVector2d;
class ZcGeMatrix2d;
class ZcGeScale2d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcGeMatrix3d;
class ZcGeScale3d;
class ZcGeTol;
class ZcGeInterval;
class ZcGeKnotVector;
class ZcGeCurveBoundary;
class ZcGePosition2d;
class ZcGePointOnCurve2d;
class ZcGeLine2d;
class ZcGeLineSeg2d;
class ZcGeRay2d;
class ZcGeCircArc2d;
class ZcGeEllipArc2d;
class ZcGeExternalCurve2d;
class ZcGeCubicSplineCurve2d;
class ZcGeCompositeCurve2d;
class ZcGeOffsetCurve2d;
class ZcGeNurbCurve2d;
class ZcGePolyline2d;
class ZcGePosition3d;
class ZcGePointOnCurve3d;
class ZcGePointOnSurface;
class ZcGeLine3d;
class ZcGeRay3d;
class ZcGeLineSeg3d;
class ZcGePlane;
class ZcGeBoundedPlane;
class ZcGeBoundBlock2d;
class ZcGeBoundBlock3d;
class ZcGeCircArc3d;
class ZcGeEllipArc3d;
class ZcGeCubicSplineCurve3d;
class ZcGeCompositeCurve3d;
class ZcGeOffsetCurve3d;
class ZcGeNurbCurve3d;
class ZcGePolyline3d;
class ZcGeAugPolyline3d;
class ZcGeExternalCurve3d;
class ZcGeSurface;
class ZcGeCone;
class ZcGeCylinder;
class ZcGeTorus;
class ZcGeExternalSurface;
class ZcGeOffsetSurface;
class ZcGeNurbSurface;
class ZcGeExternalBoundedSurface;
class ZcGeSphere;
class ZcGeCurveCurveInt2d;
class ZcGeCurveCurveInt3d;
class ZcGeEllipCone;
     
class ZcGeFiler;
class ZcGeLibVersion;

class 
GE_DLLEXPIMPORT
ZcGeFileIO
{
public:

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePoint2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeVector2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeMatrix2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeScale2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePoint2dArray&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeVector2dArray&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePoint3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeVector3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeMatrix3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeScale3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePoint3dArray&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeVector3dArray&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeTol&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeInterval&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeKnotVector&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeDoubleArray&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static
 Zcad::ErrorStatus outFields(ZcGeFiler* filer, const ZcGeIntArray& ent,
                                const ZcGeLibVersion& version);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCurveBoundary&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePosition2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePointOnCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeLine2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeLineSeg2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeRay2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCircArc2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeEllipArc2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeExternalCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCubicSplineCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCompositeCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeOffsetCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeNurbCurve2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePolyline2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePosition3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePointOnCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePointOnSurface&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeLine3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeRay3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeLineSeg3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePlane&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeBoundedPlane&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCircArc3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeEllipArc3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCubicSplineCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCompositeCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeOffsetCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeNurbCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGePolyline3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeAugPolyline3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeExternalCurve3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCone&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCylinder&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeTorus&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeExternalSurface&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeOffsetSurface&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeNurbSurface&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeExternalBoundedSurface&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeSphere&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeBoundBlock2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeBoundBlock3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCurveCurveInt2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeCurveCurveInt3d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeLibVersion&);

 static 
 Zcad::ErrorStatus outFields(ZcGeFiler*, const ZcGeEllipCone&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePoint2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeVector2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeMatrix2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeScale2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePoint2dArray&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeVector2dArray&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePoint3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeVector3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeMatrix3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeScale3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePoint3dArray&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeVector3dArray&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeTol&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeInterval&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeKnotVector&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeDoubleArray&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static
 Zcad::ErrorStatus inFields(ZcGeFiler* filer, ZcGeIntArray& ent,
                                const ZcGeLibVersion& version);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCurveBoundary&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePosition2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePointOnCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeLine2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeLineSeg2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeRay2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCircArc2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeEllipArc2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeExternalCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCubicSplineCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCompositeCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeOffsetCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeNurbCurve2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePolyline2d&,
                             const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePosition3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePointOnCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePointOnSurface&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeLine3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeRay3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeLineSeg3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePlane&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeBoundedPlane&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCircArc3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeEllipArc3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCubicSplineCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCompositeCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeOffsetCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeNurbCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGePolyline3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeAugPolyline3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeExternalCurve3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCone&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCylinder&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeTorus&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeExternalSurface&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeOffsetSurface&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeNurbSurface&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeExternalBoundedSurface&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);
 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeSphere&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeBoundBlock2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeBoundBlock3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCurveCurveInt2d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeCurveCurveInt3d&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeEllipCone&,
                            const ZcGeLibVersion& = ZcGe::gLibVersion);

 static 
 Zcad::ErrorStatus inFields(ZcGeFiler*, ZcGeLibVersion&);
     
private:
    static
    Zcad::ErrorStatus writeBoolean(ZcGeFiler*, ZSoft::Boolean,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readBoolean(ZcGeFiler*, ZSoft::Boolean*,
                               const ZcGeLibVersion&);
    Zcad::ErrorStatus writeBool(ZcGeFiler*, bool,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readBool(ZcGeFiler*, bool*,
                               const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writeLong(ZcGeFiler*, ZSoft::Int32,
                             const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readLong(ZcGeFiler*, ZSoft::Int32*,
                            const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writeDouble(ZcGeFiler*, double,
                             const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readDouble(ZcGeFiler*, double*,
                              const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writePoint2d(ZcGeFiler*, const ZcGePoint2d&,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readPoint2d(ZcGeFiler*, ZcGePoint2d*,
                               const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writeVector2d(ZcGeFiler*, const ZcGeVector2d&,
                                 const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readVector2d(ZcGeFiler*, ZcGeVector2d*,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writePoint3d(ZcGeFiler*, const ZcGePoint3d&,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readPoint3d(ZcGeFiler*, ZcGePoint3d*,
                               const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writeVector3d(ZcGeFiler*, const ZcGeVector3d&,
                                 const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus readVector3d(ZcGeFiler*, ZcGeVector3d*,
                                const ZcGeLibVersion&);
    static
    Zcad::ErrorStatus writeZcGeSurface(ZcGeFiler*, const ZcGeSurface&,
                                    const ZcGeLibVersion& version);
    static
    Zcad::ErrorStatus readZcGeSurface(ZcGeFiler*, ZcGeSurface&,
                                   const ZcGeLibVersion& version);
    static
    Zcad::ErrorStatus writeZcGeEntity2d(ZcGeFiler* filer,
	            const ZcGeEntity2d& ent, const ZcGeLibVersion& version);
	static
    Zcad::ErrorStatus readZcGeEntity2d(ZcGeFiler* filer, ZcGeEntity2d*& ent,
	            ZcGe::EntityId id, const ZcGeLibVersion& version);
    static
    Zcad::ErrorStatus writeZcGeEntity3d(ZcGeFiler* filer,
	            const ZcGeEntity3d& ent, const ZcGeLibVersion& version);
    static
    Zcad::ErrorStatus readZcGeEntity3d(ZcGeFiler* filer, ZcGeEntity3d*& ent,
	            ZcGe::EntityId id, const ZcGeLibVersion& version);

    static
    Zcad::ErrorStatus writeBytes(ZcGeFiler* filer, const void* buf,
                    ZSoft::UInt32 len, const ZcGeLibVersion& version);
    static
    Zcad::ErrorStatus readBytes(ZcGeFiler* filer, void* buf,
                    ZSoft::UInt32 len, const ZcGeLibVersion& version);

	friend class ZcGeFileIOX;

};
     
#pragma pack (pop)
#endif
