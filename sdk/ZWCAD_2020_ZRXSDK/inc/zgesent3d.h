

#ifndef ZC_GESPNT3D_H
#define ZC_GESPNT3D_H

#include "zgecurv3d.h"
#include "zgekvec.h"
#include "zgept3dar.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgept3dar.h"
#pragma pack (push, 8)

class ZcGeKnotVector;

class
GE_DLLEXPIMPORT
ZcGeSplineEnt3d : public ZcGeCurve3d
{
public:

    ZSoft::Boolean    isRational            () const;
    int               degree                () const;
    int               order                 () const;
    int               numKnots              () const;
    const
    ZcGeKnotVector&   knots                 () const;
    int               numControlPoints      () const;
    int               continuityAtKnot      (int idx, const ZcGeTol& tol =
                                             ZcGeContext::gTol ) const;

    double            startParam            () const;
    double            endParam              () const;
    ZcGePoint3d       startPoint            () const;
    ZcGePoint3d       endPoint              () const;

    ZSoft::Boolean    hasFitData            () const;

    double            knotAt                (int idx) const;
    ZcGeSplineEnt3d&  setKnotAt             (int idx, double val);

    ZcGePoint3d       controlPointAt        (int idx) const;
    ZcGeSplineEnt3d&  setControlPointAt     (int idx, const ZcGePoint3d& pnt);

    ZcGeSplineEnt3d&  operator =            (const ZcGeSplineEnt3d& spline);

protected:
    ZcGeSplineEnt3d ();
    ZcGeSplineEnt3d (const ZcGeSplineEnt3d&);
};

#pragma pack (pop)
#endif

