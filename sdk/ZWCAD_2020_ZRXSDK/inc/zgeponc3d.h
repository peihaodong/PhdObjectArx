

#ifndef ZC_GEPONC3D_H
#define ZC_GEPONC3D_H

#include "zgepent3d.h"
#pragma pack (push, 8)

class ZcGeCurve3d;

class
GE_DLLEXPIMPORT
ZcGePointOnCurve3d : public ZcGePointEnt3d
{
public:
    ZcGePointOnCurve3d();
    ZcGePointOnCurve3d(const ZcGeCurve3d& crv);
    ZcGePointOnCurve3d(const ZcGeCurve3d& crv, double param);
    ZcGePointOnCurve3d(const ZcGePointOnCurve3d& src);

    ZcGePointOnCurve3d& operator =     (const ZcGePointOnCurve3d& src);

    const ZcGeCurve3d*  curve          () const;
    double              parameter      () const;

    ZcGePoint3d         point          () const;
    ZcGePoint3d         point          (double param);
    ZcGePoint3d         point          (const ZcGeCurve3d& crv, double param);

    ZcGeVector3d        deriv          (int order) const;
    ZcGeVector3d        deriv          (int order, double param);
    ZcGeVector3d        deriv          (int order, const ZcGeCurve3d& crv,
                                        double param);

    ZSoft::Boolean      isSingular     (const ZcGeTol& tol =
	                                ZcGeContext::gTol) const;
    ZSoft::Boolean     	curvature      (double& res);
    ZSoft::Boolean     	curvature      (double param, double& res);

    ZcGePointOnCurve3d& setCurve       (const ZcGeCurve3d& crv);
    ZcGePointOnCurve3d& setParameter   (double param);
};

#pragma pack (pop)
#endif

