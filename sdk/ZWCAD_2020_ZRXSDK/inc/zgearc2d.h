

#ifndef ZC_GEARC2D_H
#define ZC_GEARC2D_H

#include "zgecurv2d.h"
#include "zgepnt2d.h"
#include "zgevec2d.h"
#pragma pack (push, 8)

class ZcGeLine2d;
class ZcGeLinearEnt2d;

class
GE_DLLEXPIMPORT
ZcGeCircArc2d : public ZcGeCurve2d
{
public:
    ZcGeCircArc2d();
    ZcGeCircArc2d(const ZcGeCircArc2d& arc);
    ZcGeCircArc2d(const ZcGePoint2d& cent, double radius);
    ZcGeCircArc2d(const ZcGePoint2d& cent, double radius,
                  double startAngle, double endAngle,
                  const ZcGeVector2d& refVec = ZcGeVector2d::kXAxis,
                  ZSoft::Boolean isClockWise = ZSoft::kFalse);
    ZcGeCircArc2d(const ZcGePoint2d& startPoint, const ZcGePoint2d& point, 
                  const ZcGePoint2d& endPoint);

    ZcGeCircArc2d(const ZcGePoint2d& startPoint, const ZcGePoint2d& endPoint, double bulge, 
                  ZSoft::Boolean bulgeFlag = ZSoft::kTrue);

    ZSoft::Boolean intersectWith  (const ZcGeLinearEnt2d& line, int& intn,
                                   ZcGePoint2d& p1, ZcGePoint2d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean intersectWith  (const ZcGeCircArc2d& arc, int& intn,
                                   ZcGePoint2d& p1, ZcGePoint2d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean tangent        (const ZcGePoint2d& pnt, ZcGeLine2d& line,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean tangent        (const ZcGePoint2d& pnt, ZcGeLine2d& line,
                                   const ZcGeTol& tol, ZcGeError& error) const;

    ZSoft::Boolean isInside       (const ZcGePoint2d& pnt,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint2d    center         () const;
    double         radius         () const;
    double         startAng       () const;
    double         endAng         () const;
    ZSoft::Boolean isClockWise    () const;
    ZcGeVector2d   refVec         () const;
    ZcGePoint2d    startPoint     () const;
    ZcGePoint2d    endPoint       () const;

    ZcGeCircArc2d& setCenter      (const ZcGePoint2d& cent);
    ZcGeCircArc2d& setRadius      (double radius);
    ZcGeCircArc2d& setAngles      (double startAng, double endAng);
    ZcGeCircArc2d& setToComplement();
    ZcGeCircArc2d& setRefVec      (const ZcGeVector2d& vec);
    ZcGeCircArc2d& set            (const ZcGePoint2d& cent, double radius);
    ZcGeCircArc2d& set            (const ZcGePoint2d& cent, double radius,
                                   double ang1, double ang2,
                                   const ZcGeVector2d& refVec =
                                   ZcGeVector2d::kXAxis,
                                   ZSoft::Boolean isClockWise = ZSoft::kFalse);
    ZcGeCircArc2d& set            (const ZcGePoint2d& startPoint, const ZcGePoint2d& pnt,
                                   const ZcGePoint2d& endPoint);
    ZcGeCircArc2d& set            (const ZcGePoint2d& startPoint, const ZcGePoint2d& pnt,
                                   const ZcGePoint2d& endPoint, ZcGeError& error);

    ZcGeCircArc2d& set            (const ZcGePoint2d& startPoint, 
                                   const ZcGePoint2d& endPoint,
                                   double bulge, ZSoft::Boolean bulgeFlag = ZSoft::kTrue);
    ZcGeCircArc2d& set            (const ZcGeCurve2d& curve1,
                                   const ZcGeCurve2d& curve2,
                                   double radius, double& param1, double& param2,
								   ZSoft::Boolean& success);

    ZcGeCircArc2d& set            (const ZcGeCurve2d& curve1,
                                   const ZcGeCurve2d& curve2,
                                   const ZcGeCurve2d& curve3,
                                   double& param1, double& param2, double& param3,
								   ZSoft::Boolean& success);

    ZcGeCircArc2d& operator =     (const ZcGeCircArc2d& arc);
};

#pragma pack (pop)
#endif
