

#ifndef ZC_GEPLIN3D_H
#define ZC_GEPLIN3D_H

#include "zgecurv3d.h"
#include "zgekvec.h"
#include "zgept3dar.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgesent3d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGePolyline3d : public ZcGeSplineEnt3d
{
public:

    ZcGePolyline3d();
    ZcGePolyline3d( const ZcGePolyline3d& src );
    ZcGePolyline3d( const ZcGePoint3dArray& points);
    ZcGePolyline3d( const ZcGeKnotVector& knots,
                    const ZcGePoint3dArray& cntrlPnts );

    ZcGePolyline3d( const ZcGeCurve3d& crv, double apprEps );

    int              numFitPoints () const;
    ZcGePoint3d      fitPointAt   (int idx) const;
    ZcGeSplineEnt3d& setFitPointAt(int idx, const ZcGePoint3d& point);

    ZcGePolyline3d& operator =     (const ZcGePolyline3d& pline);
};

#pragma pack (pop)
#endif

