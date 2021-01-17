

#ifndef ZC_GEBNDPLN_H
#define ZC_GEBNDPLN_H

#include "zgeplanar.h"
#include "zgeplane.h"
#pragma pack (push, 8)

class ZcGePlane;
class ZcGeVector3d;
class ZcGePoint3d;
class ZcGePoint2d;
class ZcGeLineSeg3d;

class
GE_DLLEXPIMPORT
ZcGeBoundedPlane : public ZcGePlanarEnt
{
public:
    ZcGeBoundedPlane();
    ZcGeBoundedPlane(const ZcGeBoundedPlane& plane);
    ZcGeBoundedPlane(const ZcGePoint3d& origin, const ZcGeVector3d& uVec,
                     const ZcGeVector3d& vVec);
    ZcGeBoundedPlane(const ZcGePoint3d& p1, const ZcGePoint3d& origin,
                     const ZcGePoint3d& p2);

    ZSoft::Boolean    intersectWith (const ZcGeLinearEnt3d& linEnt, ZcGePoint3d& point,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean    intersectWith (const ZcGePlane& plane, ZcGeLineSeg3d& results,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean    intersectWith (const ZcGeBoundedPlane& plane, ZcGeLineSeg3d& result,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeBoundedPlane& set           (const ZcGePoint3d& origin,
                                     const ZcGeVector3d& uVec,
                                     const ZcGeVector3d& vVec);
    ZcGeBoundedPlane& set           (const ZcGePoint3d& p1,
                                     const ZcGePoint3d& origin,
                                     const ZcGePoint3d& p2);

    ZcGeBoundedPlane& operator =    (const ZcGeBoundedPlane& bplane);
};

#pragma pack (pop)
#endif
