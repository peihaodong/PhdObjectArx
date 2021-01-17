

#ifndef ZC_GEPLANAR_H
#define ZC_GEPLANAR_H

#include "zgesurf.h"
#include "zgevec3d.h"
#pragma pack (push, 8)

class ZcGeLineSeg3d;
class ZcGeLinearEnt3d;
class ZcGeCircArc3d;

class
GE_DLLEXPIMPORT
ZcGePlanarEnt : public ZcGeSurface
{
public:

    ZSoft::Boolean  intersectWith    (const ZcGeLinearEnt3d& linEnt, ZcGePoint3d& pnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d     closestPointToLinearEnt (const ZcGeLinearEnt3d& line,
                                             ZcGePoint3d& pointOnLine,
                                             const ZcGeTol& tol
                                               = ZcGeContext::gTol) const;
    ZcGePoint3d     closestPointToPlanarEnt (const ZcGePlanarEnt& otherPln,
                                             ZcGePoint3d& pointOnOtherPln,
                                             const ZcGeTol& tol
                                               = ZcGeContext::gTol) const;

    ZSoft::Boolean isParallelTo      (const ZcGeLinearEnt3d& linEnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isParallelTo      (const ZcGePlanarEnt& otherPlnEnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo (const ZcGeLinearEnt3d& linEnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo (const ZcGePlanarEnt& linEnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isCoplanarTo      (const ZcGePlanarEnt& otherPlnEnt,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    void              get            (ZcGePoint3d&, ZcGeVector3d& uVec,
                                      ZcGeVector3d& vVec) const;
    void              get            (ZcGePoint3d&, ZcGePoint3d& origin,
                                      ZcGePoint3d&) const;

    ZcGePoint3d    pointOnPlane      () const;
    ZcGeVector3d   normal            () const;
    void           getCoefficients(double& a, double& b, double& c, double& d) const;
    void           getCoordSystem(ZcGePoint3d& origin, ZcGeVector3d& axis1,
                                  ZcGeVector3d& axis2) const;

    ZcGePlanarEnt& operator =        (const ZcGePlanarEnt& src);

protected:
    ZcGePlanarEnt ();
    ZcGePlanarEnt (const ZcGePlanarEnt&);
};

#pragma pack (pop)
#endif
