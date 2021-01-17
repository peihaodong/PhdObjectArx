

#ifndef ZC_GEPLIN2D_H
#define ZC_GEPLIN2D_H

#include "zgecurv2d.h"
#include "zgekvec.h"
#include "zgept2dar.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#include "zgesent2d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGePolyline2d : public ZcGeSplineEnt2d
{
public:
    ZcGePolyline2d();
    ZcGePolyline2d(const ZcGePolyline2d& src);
    ZcGePolyline2d(const ZcGePoint2dArray&);
    ZcGePolyline2d(const ZcGeKnotVector& knots,
                   const ZcGePoint2dArray& points);

    ZcGePolyline2d(const ZcGeCurve2d& crv, double apprEps);

    int              numFitPoints () const;
    ZcGePoint2d      fitPointAt   (int idx) const;
    ZcGeSplineEnt2d& setFitPointAt(int idx, const ZcGePoint2d& point);

    ZcGePolyline2d& operator =     (const ZcGePolyline2d& pline);
};

#pragma pack (pop)
#endif
