

#ifndef ZC_GECSPL2D_H
#define ZC_GECSPL2D_H

class ZcGePointOnCurve2d;
class ZcGeCurve2dIntersection;
class ZcGeInterval;
class ZcGePlane;

#include "zgesent2d.h"
#include "zgept2dar.h"
#include "zgevc2dar.h"
#include "zgevec2d.h"
#include "zgekvec.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeCubicSplineCurve2d : public ZcGeSplineEnt2d
{
public:

    ZcGeCubicSplineCurve2d();
    ZcGeCubicSplineCurve2d(const ZcGeCubicSplineCurve2d& spline);

    ZcGeCubicSplineCurve2d(const ZcGePoint2dArray& fitPnts,
			   const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCubicSplineCurve2d(const ZcGePoint2dArray& fitPnts,
			   const ZcGeVector2d& startDeriv,
			   const ZcGeVector2d& endDeriv,
                           const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCubicSplineCurve2d(const ZcGeCurve2d& curve,
                           double epsilon = ZcGeContext::gTol.equalPoint());

	ZcGeCubicSplineCurve2d(const ZcGeKnotVector& knots,
	                       const ZcGePoint2dArray& fitPnts,
			       const ZcGeVector2dArray& firstDerivs,
	                       ZSoft::Boolean isPeriodic = ZSoft::kFalse );

    int                     numFitPoints   ()        const;
    ZcGePoint2d             fitPointAt     (int idx) const;
    ZcGeCubicSplineCurve2d& setFitPointAt  (int idx, const ZcGePoint2d& point);
    ZcGeVector2d            firstDerivAt   (int idx) const;
    ZcGeCubicSplineCurve2d& setFirstDerivAt(int idx, const ZcGeVector2d& deriv);

    ZcGeCubicSplineCurve2d&  operator = (const ZcGeCubicSplineCurve2d& spline);
};

#pragma pack (pop)
#endif
