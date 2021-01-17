

#ifndef ZC_GEPONC2D_H
#define ZC_GEPONC2D_H

#include "zgepent2d.h"
#pragma pack (push, 8)

class ZcGeCurve2d;

class
GE_DLLEXPIMPORT
ZcGePointOnCurve2d : public ZcGePointEnt2d
{
public:
    ZcGePointOnCurve2d  ();
    ZcGePointOnCurve2d  (const ZcGeCurve2d& crv);
    ZcGePointOnCurve2d  (const ZcGeCurve2d& crv, double param);
    ZcGePointOnCurve2d  (const ZcGePointOnCurve2d& src);

    ZcGePointOnCurve2d& operator =     (const ZcGePointOnCurve2d& src);

    const ZcGeCurve2d*  curve          () const;
    double              parameter      () const;

    ZcGePoint2d         point          () const;
    ZcGePoint2d         point          (double param);
    ZcGePoint2d         point          (const ZcGeCurve2d& crv, double param);

    ZcGeVector2d        deriv          (int order) const;
    ZcGeVector2d        deriv          (int order, double param);
    ZcGeVector2d        deriv          (int order, const ZcGeCurve2d& crv,
                                        double param);

    ZSoft::Boolean      isSingular     (const ZcGeTol&  tol =
                                        ZcGeContext::gTol) const;
    ZSoft::Boolean      curvature      (double& res);
    ZSoft::Boolean      curvature      (double param, double& res);

    ZcGePointOnCurve2d& setCurve       (const ZcGeCurve2d& crv);
    ZcGePointOnCurve2d& setParameter   (double param);
};

#pragma pack (pop)
#endif

