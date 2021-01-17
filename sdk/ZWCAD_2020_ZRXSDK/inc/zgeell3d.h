

#ifndef ZC_GEELL3D_H
#define ZC_GEELL3D_H

#include "zgecurv3d.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgeintrvl.h"
#include "zgeponc3d.h"
#include "zgeplane.h"
#pragma pack (push, 8)

class ZcGeEllipArc2d;
class ZcGeCircArc3d;
class ZcGeLineEnt3d;
class ZcGePlanarEnt;

class
GE_DLLEXPIMPORT
ZcGeEllipArc3d : public ZcGeCurve3d
{
public:

    ZcGeEllipArc3d();
    ZcGeEllipArc3d(const ZcGeEllipArc3d& ell);
    ZcGeEllipArc3d(const ZcGeCircArc3d& arc);
    ZcGeEllipArc3d(const ZcGePoint3d& cent, const ZcGeVector3d& majorAxis,
                   const ZcGeVector3d& minorAxis, double majorRadius,
                   double minorRadius);
    ZcGeEllipArc3d(const ZcGePoint3d& cent, const ZcGeVector3d& majorAxis,
                   const ZcGeVector3d& minorAxis, double majorRadius,
                   double minorRadius, double ang1, double ang2);

    ZcGePoint3d    closestPointToPlane(const ZcGePlanarEnt& plane,
                                  ZcGePoint3d& pointOnPlane,
                                  const ZcGeTol& = ZcGeContext::gTol) const;

    ZSoft::Boolean intersectWith (const ZcGeLinearEnt3d& line, int& intn,
                                  ZcGePoint3d& p1, ZcGePoint3d& p2,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;  
    ZSoft::Boolean intersectWith (const ZcGePlanarEnt& plane, int& numOfIntersect,
                                  ZcGePoint3d& p1, ZcGePoint3d& p2,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean projIntersectWith(const ZcGeLinearEnt3d& line,
                                  const ZcGeVector3d& projDir, int &numInt,
                                  ZcGePoint3d& pntOnEllipse1,
                                  ZcGePoint3d& pntOnEllipse2,
                                  ZcGePoint3d& pntOnLine1,
                                  ZcGePoint3d& pntOnLine2,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    void           getPlane      (ZcGePlane& plane) const;

    ZSoft::Boolean isCircular    (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isInside      (const ZcGePoint3d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d    center        () const;
    double         minorRadius   () const;
    double         majorRadius   () const;
    ZcGeVector3d   minorAxis     () const;
    ZcGeVector3d   majorAxis     () const;
    ZcGeVector3d   normal        () const; 
    double         startAng      () const;
    double         endAng        () const;
    ZcGePoint3d    startPoint    () const;
    ZcGePoint3d    endPoint      () const;

    ZcGeEllipArc3d& setCenter     (const ZcGePoint3d& cent);
    ZcGeEllipArc3d& setMinorRadius(double rad);
    ZcGeEllipArc3d& setMajorRadius(double rad);
    ZcGeEllipArc3d& setAxes       (const ZcGeVector3d& majorAxis, const ZcGeVector3d& minorAxis);
    ZcGeEllipArc3d& setAngles     (double startAngle, double endAngle);
    ZcGeEllipArc3d& set           (const ZcGePoint3d& cent,
                                   const ZcGeVector3d& majorAxis,
                                   const ZcGeVector3d& minorAxis,
                                   double majorRadius, double minorRadius);
    ZcGeEllipArc3d& set           (const ZcGePoint3d& cent,
                                   const ZcGeVector3d& majorAxis,
                                   const ZcGeVector3d& minorAxis,
                                   double majorRadius, double minorRadius,
                                   double startAngle, double endAngle);
    ZcGeEllipArc3d& set           (const ZcGeCircArc3d&);

    ZcGeEllipArc3d& operator =    (const ZcGeEllipArc3d& ell);
};

#pragma pack (pop)
#endif
