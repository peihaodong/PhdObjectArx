

#ifndef ZC_GEPLANE_H
#define ZC_GEPLANE_H

#include "zgeplanar.h"
#pragma pack (push, 8)

class ZcGeBoundedPlane;
class ZcGeLine3d;

class
GE_DLLEXPIMPORT
ZcGePlane : public ZcGePlanarEnt
{
public:

    static const ZcGePlane kXYPlane;
    static const ZcGePlane kYZPlane;
    static const ZcGePlane kZXPlane;

    ZcGePlane();
    ZcGePlane(const ZcGePlane& src);
    ZcGePlane(const ZcGePoint3d& origin, const ZcGeVector3d& normal);

    ZcGePlane(const ZcGePoint3d& pntU, const ZcGePoint3d& org, const ZcGePoint3d& pntV);

    ZcGePlane(const ZcGePoint3d& org, const ZcGeVector3d& uAxis,
              const ZcGeVector3d& vAxis);
    ZcGePlane(double a, double b, double c, double d);

    double         signedDistanceTo (const ZcGePoint3d& pnt) const;

    ZSoft::Boolean intersectWith    (const ZcGeLinearEnt3d& linEnt, ZcGePoint3d& resultPnt,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean intersectWith    (const ZcGePlane& otherPln, ZcGeLine3d& resultLine,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean intersectWith    (const ZcGeBoundedPlane& bndPln, ZcGeLineSeg3d& resultLineSeg,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePlane&     set              (const ZcGePoint3d& pnt, const ZcGeVector3d& normal);
    ZcGePlane&     set              (const ZcGePoint3d& pntU, const ZcGePoint3d& org,
                                     const ZcGePoint3d& pntV);
    ZcGePlane&     set              (double a, double b, double c, double d);
    ZcGePlane&     set              (const ZcGePoint3d& org,
                                     const ZcGeVector3d& uAxis,
                                     const ZcGeVector3d& vAxis);

    ZcGePlane&     operator =       (const ZcGePlane& src);
};

#pragma pack (pop)
#endif
