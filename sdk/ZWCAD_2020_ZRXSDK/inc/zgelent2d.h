

#ifndef ZC_GELENT2D_H
#define ZC_GELENT2D_H

#include "zgecurv2d.h"
#include "zgepnt2d.h"
#include "zgevec2d.h"
#pragma pack (push, 8)

class ZcGeCircArc2d;

class
GE_DLLEXPIMPORT
ZcGeLinearEnt2d : public ZcGeCurve2d
{
public:

    ZSoft::Boolean   intersectWith  (const ZcGeLinearEnt2d& line, ZcGePoint2d& intPnt,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean   overlap        (const ZcGeLinearEnt2d& line,
                                     ZcGeLinearEnt2d*& overlap,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean   isParallelTo   (const ZcGeLinearEnt2d& line,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean   isPerpendicularTo(const ZcGeLinearEnt2d& line,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean   isColinearTo   (const ZcGeLinearEnt2d& line,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;

    void             getPerpLine    (const ZcGePoint2d& pnt, ZcGeLine2d& perpLine) const;

    ZcGePoint2d      pointOnLine    () const;
    ZcGeVector2d     direction      () const;
    void             getLine        (ZcGeLine2d& line) const;

    ZcGeLinearEnt2d& operator =     (const ZcGeLinearEnt2d& line);

protected:
    ZcGeLinearEnt2d ();
    ZcGeLinearEnt2d (const ZcGeLinearEnt2d&);
};

#pragma pack (pop)
#endif
