

#ifndef ZC_GEARC3D_H
#define ZC_GEARC3D_H

#include "zgecurv3d.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgeplane.h"
#include "zgegblabb.h"
#pragma pack (push, 8)
class ZcGeLine3d;
class ZcGeCircArc2d;
class ZcGePlanarEnt;

class 
GE_DLLEXPIMPORT
ZcGeCircArc3d : public ZcGeCurve3d
{
public:
    ZcGeCircArc3d();
    ZcGeCircArc3d(const ZcGeCircArc3d& arc);
    ZcGeCircArc3d(const ZcGePoint3d& cent,
                  const ZcGeVector3d& nrm, double radius);
    ZcGeCircArc3d(const ZcGePoint3d& cent, const ZcGeVector3d& nrm,
                  const ZcGeVector3d& refVec, double radius,
                  double startAngle, double endAngle);
    ZcGeCircArc3d(const ZcGePoint3d& startPoint, const ZcGePoint3d& pnt, const ZcGePoint3d& endPoint);

    ZcGePoint3d    closestPointToPlane (const ZcGePlanarEnt& plane,
                                        ZcGePoint3d& pointOnPlane,
                                        const ZcGeTol& tol
                                        = ZcGeContext::gTol) const;

    ZSoft::Boolean intersectWith  (const ZcGeLinearEnt3d& line, int& intn,
                                   ZcGePoint3d& p1, ZcGePoint3d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean intersectWith  (const ZcGeCircArc3d& arc, int& intn,
                                   ZcGePoint3d& p1, ZcGePoint3d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean  intersectWith (const ZcGePlanarEnt& plane, int& numOfIntersect,
                                   ZcGePoint3d& p1, ZcGePoint3d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean projIntersectWith (const ZcGeLinearEnt3d& line,
                                      const ZcGeVector3d& projDir, int& numInt,
                                      ZcGePoint3d& pntOnArc1,
                                      ZcGePoint3d& pntOnArc2,
                                      ZcGePoint3d& pntOnLine1,
                                      ZcGePoint3d& pntOnLine2,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean tangent        (const ZcGePoint3d& pnt, ZcGeLine3d& line,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean tangent        (const ZcGePoint3d& pnt, ZcGeLine3d& line,
                                   const ZcGeTol& tol, ZcGeError& error) const;

    void           getPlane       (ZcGePlane& plane) const;

    ZSoft::Boolean isInside       (const ZcGePoint3d& pnt,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d    center         () const;
    ZcGeVector3d   normal         () const;
    ZcGeVector3d   refVec         () const;
    double         radius         () const;
    double         startAng       () const;
    double         endAng         () const;
    ZcGePoint3d    startPoint     () const;
    ZcGePoint3d    endPoint       () const;

    ZcGeCircArc3d& setCenter      (const ZcGePoint3d&);
    ZcGeCircArc3d& setAxes        (const ZcGeVector3d& normal,
                                   const ZcGeVector3d& refVec);
    ZcGeCircArc3d& setRadius      (double);
    ZcGeCircArc3d& setAngles      (double startAngle, double endAngle);

    ZcGeCircArc3d& set            (const ZcGePoint3d& cent,
                                   const ZcGeVector3d& nrm, double radius);
    ZcGeCircArc3d& set            (const ZcGePoint3d& cent,
                                   const ZcGeVector3d& nrm,
                                   const ZcGeVector3d& refVec, double radius,
                                   double startAngle, double endAngle);
    ZcGeCircArc3d& set            (const ZcGePoint3d& startPoint, const ZcGePoint3d& pnt,
                                   const ZcGePoint3d& endPoint);
    ZcGeCircArc3d& set            (const ZcGePoint3d& startPoint, const ZcGePoint3d& pnt,
                                   const ZcGePoint3d& endPoint, ZcGeError& error);

    ZcGeCircArc3d& set            (const ZcGeCurve3d& curve1,
                                   const ZcGeCurve3d& curve2,
                                   double radius, double& param1, double& param2,
								   ZSoft::Boolean& success);

    ZcGeCircArc3d& set            (const ZcGeCurve3d& curve1,
                                   const ZcGeCurve3d& curve2,
                                   const ZcGeCurve3d& curve3,
                                   double& param1, double& param2, double& param3,
								   ZSoft::Boolean& success);

    ZcGeCircArc3d& operator =     (const ZcGeCircArc3d& arc);
};

#pragma pack (pop)
#endif
