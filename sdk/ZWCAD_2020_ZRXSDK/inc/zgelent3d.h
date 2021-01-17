

#ifndef ZC_GELENT3D_H
#define ZC_GELENT3D_H

#include "zgecurv3d.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#pragma pack (push, 8)

class ZcGeLine3d;
class ZcGeCircArc3d;
class ZcGePlanarEnt;
class
GE_DLLEXPIMPORT
ZcGeLinearEnt3d : public ZcGeCurve3d
{
public:

    ZSoft::Boolean intersectWith (const ZcGeLinearEnt3d& line,
                                  ZcGePoint3d& intPt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean intersectWith (const ZcGePlanarEnt& plane, ZcGePoint3d& intPnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean projIntersectWith(const ZcGeLinearEnt3d& line,
                                  const ZcGeVector3d& projDir,
                                  ZcGePoint3d& pntOnThisLine,
                                  ZcGePoint3d& pntOnOtherLine,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean overlap       (const ZcGeLinearEnt3d& line,
                                  ZcGeLinearEnt3d*& overlap,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isOn          (const ZcGePoint3d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn          (const ZcGePoint3d& pnt, double& param,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn          (double param,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn          (const ZcGePlane& plane,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isParallelTo  (const ZcGeLinearEnt3d& line,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isParallelTo  (const ZcGePlanarEnt& plane,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo(const ZcGeLinearEnt3d& line,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo(const ZcGePlanarEnt& plane,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isColinearTo  (const ZcGeLinearEnt3d& line,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    void          getPerpPlane   (const ZcGePoint3d& pnt, ZcGePlane& plane) const;

    ZcGePoint3d    pointOnLine   () const;
    ZcGeVector3d   direction     () const;
    void           getLine       (ZcGeLine3d&) const;

	ZcGeVector3d   velocity       () const;	// INTERNAL USE ONLY

    ZcGeLinearEnt3d& operator =  (const ZcGeLinearEnt3d& line);

protected:
    ZcGeLinearEnt3d ();
    ZcGeLinearEnt3d (const ZcGeLinearEnt3d&);
};

#pragma pack (pop)
#endif
