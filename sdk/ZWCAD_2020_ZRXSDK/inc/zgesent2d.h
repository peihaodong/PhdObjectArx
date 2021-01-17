

#ifndef ZC_GESPNT2d_H
#define ZC_GESPNT2d_H

#include "zgecurv2d.h"
#include "zgekvec.h"
#include "zgept2dar.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#include "zgept2dar.h"
#pragma pack (push, 8)

class ZcGeKnotVector;

class 
GE_DLLEXPIMPORT
ZcGeSplineEnt2d : public ZcGeCurve2d
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
                                             ZcGeContext::gTol) const;

    double            startParam            () const;
    double            endParam              () const;
    ZcGePoint2d       startPoint            () const;
    ZcGePoint2d       endPoint              () const;

    ZSoft::Boolean    hasFitData            () const;

    double            knotAt                (int idx) const;
    ZcGeSplineEnt2d&  setKnotAt             (int idx, double val);

    ZcGePoint2d       controlPointAt        (int idx) const;
    ZcGeSplineEnt2d&  setControlPointAt     (int idx, const ZcGePoint2d& pnt);

    ZcGeSplineEnt2d&  operator =            (const ZcGeSplineEnt2d& spline);

protected:
    ZcGeSplineEnt2d ();
    ZcGeSplineEnt2d (const ZcGeSplineEnt2d&);
};

#pragma pack (pop)
#endif

