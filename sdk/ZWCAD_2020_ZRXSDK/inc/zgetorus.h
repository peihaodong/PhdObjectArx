

#ifndef ZC_GETORUS_H
#define ZC_GETORUS_H

#include "zgegbl.h"
#include "zgesurf.h"
#include "zgeintrvl.h"
#include "zgevec3d.h"
#pragma pack (push, 8)

class ZcGeCircArc3d;

class
GX_DLLEXPIMPORT
ZcGeTorus : public ZcGeSurface
{
public:
    ZcGeTorus();
    ZcGeTorus(double majorRadius, double minorRadius,
              const ZcGePoint3d& origin, const ZcGeVector3d& axisOfSymmetry);
    ZcGeTorus(double majorRadius, double minorRadius,
              const ZcGePoint3d&  origin, const ZcGeVector3d& axisOfSymmetry,
              const ZcGeVector3d& refAxis,
              double startAngleU, double endAngleU,
              double startAngleV, double endAngleV);
    ZcGeTorus(const ZcGeTorus& torus);

    double          majorRadius    () const;
    double          minorRadius    () const;
    void            getAnglesInU   (double& start, double& end) const;
    void            getAnglesInV   (double& start, double& end) const;
    ZcGePoint3d     center         () const;
    ZcGeVector3d    axisOfSymmetry () const;
    ZcGeVector3d    refAxis        () const;
    ZSoft::Boolean  isOuterNormal  () const;

    ZcGeTorus&      setMajorRadius (double radius);
    ZcGeTorus&      setMinorRadius (double radius);
    ZcGeTorus&      setAnglesInU   (double start, double end);
    ZcGeTorus&      setAnglesInV   (double start, double end);
    ZcGeTorus&      set            (double majorRadius, double minorRadius,
                                    const ZcGePoint3d& origin,
                                    const ZcGeVector3d& axisOfSymmetry);
    ZcGeTorus&      set            (double majorRadius, double minorRadius,
                                    const ZcGePoint3d&  origin,
                                    const ZcGeVector3d& axisOfSymmetry,
                                    const ZcGeVector3d& refAxis,
                                    double startAngleU, double endAngleU,
                                    double startAngleV, double endAngleV);

	ZcGeTorus&		set				(const ZcGePoint3d& cent,
									 const ZcGeVector3d& nrm,
									 const ZcGeVector3d& refVec, double radius,
								     double startAngle, double endAngle);	// INTERNAL USE ONLY

	ZcGeTorus&      set				(const ZcGePoint3d& cent,
									const ZcGeVector3d& nrm,
									double radius);			// INTERNAL USE ONLY

    ZcGeTorus&      operator =     (const ZcGeTorus& torus);

    ZSoft::Boolean  intersectWith  (const ZcGeLinearEnt3d& linEnt, int& intn,
                                    ZcGePoint3d& p1, ZcGePoint3d& p2,
                                    ZcGePoint3d& p3, ZcGePoint3d& p4,
                                    const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isLemon     () const;
    ZSoft::Boolean isApple     () const;
    ZSoft::Boolean isVortex    () const;
    ZSoft::Boolean isDoughnut  () const;
    ZSoft::Boolean isDegenerate() const;
    ZSoft::Boolean isHollow    () const;
};

#pragma pack (pop)
#endif
