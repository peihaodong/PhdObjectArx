

#ifndef ZC_GECSPL3D_H
#define ZC_GECSPL3D_H

class ZcGePointOnCurve3d;
class ZcGeCurve3dIntersection;
class ZcGeInterval;
class ZcGePlane;

#include "zgesent3d.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#include "zgevec3d.h"
#include "zgekvec.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeCubicSplineCurve3d : public ZcGeSplineEnt3d
{
public:

    ZcGeCubicSplineCurve3d();
    ZcGeCubicSplineCurve3d(const ZcGeCubicSplineCurve3d& spline);

    ZcGeCubicSplineCurve3d(const ZcGePoint3dArray& fitPnts,
			   const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCubicSplineCurve3d(const ZcGePoint3dArray& fitPnts,
			   const ZcGeVector3d& startDeriv,
			   const ZcGeVector3d& endDeriv,
                           const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCubicSplineCurve3d(const ZcGeCurve3d& curve,
                           double epsilon = ZcGeContext::gTol.equalPoint());

    ZcGeCubicSplineCurve3d(const ZcGeKnotVector& knots,
	                   const ZcGePoint3dArray& fitPnts,
			   const ZcGeVector3dArray& firstDerivs,
	                   ZSoft::Boolean isPeriodic = ZSoft::kFalse);

    int                     numFitPoints   ()        const;
    ZcGePoint3d             fitPointAt     (int idx) const;
    ZcGeCubicSplineCurve3d& setFitPointAt  (int idx, const ZcGePoint3d& point);
    ZcGeVector3d            firstDerivAt   (int idx) const;
    ZcGeCubicSplineCurve3d& setFirstDerivAt(int idx, const ZcGeVector3d& deriv);

    ZcGeCubicSplineCurve3d&  operator = (const ZcGeCubicSplineCurve3d& spline);
};

#pragma pack (pop)
#endif
