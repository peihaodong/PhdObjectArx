

#ifndef ZC_GECYLNDR_H
#define ZC_GECYLNDR_H

#include "zgegbl.h"
#include "zgesurf.h"
#include "zgevec3d.h"
#include "zgeintrvl.h"
#include "zgearc3d.h"
#pragma pack (push, 8)

class ZcGeCircArc3d;

class
GX_DLLEXPIMPORT
ZcGeCylinder : public ZcGeSurface
{
public:
    ZcGeCylinder ();
    ZcGeCylinder (double radius, const ZcGePoint3d& origin,
                  const ZcGeVector3d& axisOfSymmetry);
    ZcGeCylinder (double radius, const ZcGePoint3d& origin,
                  const ZcGeVector3d& axisOfSymmetry,
                  const ZcGeVector3d& refAxis,
                  const ZcGeInterval& height,
                  double startAngle, double endAngle);
    ZcGeCylinder (const ZcGeCylinder&);

    double         radius        () const;
    ZcGePoint3d    origin        () const;
    void           getAngles     (double& start, double& end) const;
    void           getHeight     (ZcGeInterval& height) const;
    double         heightAt      (double u) const;
    ZcGeVector3d   axisOfSymmetry() const;
    ZcGeVector3d   refAxis       () const;
    ZSoft::Boolean isOuterNormal () const;
    ZSoft::Boolean isClosed      (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeCylinder&  setRadius     (double radius);
    ZcGeCylinder&  setAngles     (double start, double end);
    ZcGeCylinder&  setHeight     (const ZcGeInterval& height);
    ZcGeCylinder&  set           (double radius, const ZcGePoint3d& origin,
                                  const ZcGeVector3d& axisOfSym);
    ZcGeCylinder&  set           (double radius, const ZcGePoint3d& origin,
                                  const ZcGeVector3d& axisOfSym,
                                  const ZcGeVector3d& refAxis,
                                  const ZcGeInterval& height,
                                  double startAngle, double endAngle);

    ZcGeCylinder&  operator =    (const ZcGeCylinder& cylinder);

    ZSoft::Boolean intersectWith (const ZcGeLinearEnt3d& linEnt, int& intn,
                                  ZcGePoint3d& p1, ZcGePoint3d& p2,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
};

#pragma pack (pop)
#endif
