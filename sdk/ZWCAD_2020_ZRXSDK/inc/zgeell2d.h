

#ifndef ZC_GEELL2D_H
#define ZC_GEELL2D_H

#include "zgecurv2d.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#include "zgeponc2d.h"
#include "zgeintrvl.h"
#pragma pack (push, 8)

class ZcGeCircArc2d;
class ZcGePlanarEnt;
class ZcGeEllipArc2d;
class ZcGeLinearEnt2d;

class
GE_DLLEXPIMPORT
ZcGeEllipArc2d : public ZcGeCurve2d
{
public:
    ZcGeEllipArc2d();
    ZcGeEllipArc2d(const ZcGeEllipArc2d& ell);
    ZcGeEllipArc2d(const ZcGeCircArc2d& arc);
    ZcGeEllipArc2d(const ZcGePoint2d& cent, const ZcGeVector2d& majorAxis,
                   const ZcGeVector2d& minorAxis, double majorRadius,
                   double minorRadius);
    ZcGeEllipArc2d(const ZcGePoint2d& cent, const ZcGeVector2d& majorAxis,
                   const ZcGeVector2d& minorAxis, double majorRadius,
                   double minorRadius, double startAngle, double endAngle);

    ZSoft::Boolean intersectWith (const ZcGeLinearEnt2d& line, int& intn,
                                  ZcGePoint2d& p1, ZcGePoint2d& p2,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isCircular    (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isInside      (const ZcGePoint2d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint2d    center        () const;
    double         minorRadius   () const;
    double         majorRadius   () const;
    ZcGeVector2d   minorAxis     () const;
    ZcGeVector2d   majorAxis     () const;
    double         startAng      () const;
    double         endAng        () const;
    ZcGePoint2d    startPoint    () const;
    ZcGePoint2d    endPoint      () const;
    ZSoft::Boolean isClockWise   () const;

    ZcGeEllipArc2d& setCenter     (const ZcGePoint2d& cent);
    ZcGeEllipArc2d& setMinorRadius(double rad);
    ZcGeEllipArc2d& setMajorRadius(double rad);
    ZcGeEllipArc2d& setAxes       (const ZcGeVector2d& majorAxis, const ZcGeVector2d& minorAxis);
    ZcGeEllipArc2d& setAngles     (double startAngle, double endAngle);
    ZcGeEllipArc2d& set           (const ZcGePoint2d& cent,
                                   const ZcGeVector2d& majorAxis,
                                   const ZcGeVector2d& minorAxis,
                                   double majorRadius, double minorRadius);
    ZcGeEllipArc2d& set           (const ZcGePoint2d& cent,
                                   const ZcGeVector2d& majorAxis,
                                   const ZcGeVector2d& minorAxis,
                                   double majorRadius, double minorRadius,
                                   double startAngle, double endAngle);
    ZcGeEllipArc2d& set           (const ZcGeCircArc2d& arc);

    ZcGeEllipArc2d& operator =    (const ZcGeEllipArc2d& ell);
};

#pragma pack (pop)
#endif

