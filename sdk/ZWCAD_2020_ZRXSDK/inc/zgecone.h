

#ifndef ZC_GECONE_H
#define ZC_GECONE_H

#include "zgegbl.h"
#include "zgeintrvl.h"
#include "zgevec3d.h"
#include "zgesurf.h"
#include "zgearc3d.h"
#pragma pack (push, 8)

class ZcGePoint3d;
class ZcGeVector3d;
class ZcGeCircArc3d;
class ZcGeInterval;
class ZcGeLinearEnt3d;

class 
GX_DLLEXPIMPORT
ZcGeCone : public ZcGeSurface
{
public:
    ZcGeCone();
    ZcGeCone(double cosineAngle, double sineAngle,
             const  ZcGePoint3d& baseOrigin, double baseRadius,
             const  ZcGeVector3d& axisOfSymmetry);
    ZcGeCone(double cosineAngle, double sineAngle,
             const  ZcGePoint3d& baseOrigin, double baseRadius,
             const  ZcGeVector3d& axisOfSymmetry,
             const  ZcGeVector3d& refAxis, const  ZcGeInterval& height,
             double startAngle, double endAngle);
    ZcGeCone(const ZcGeCone& cone);

    double           baseRadius        () const;
    ZcGePoint3d      baseCenter        () const;
    void             getAngles         (double& start, double& end) const;
    double           halfAngle         () const;
    void             getHalfAngle      (double& cosineAngle, double& sineAngle)
                                                 const;
    void             getHeight         (ZcGeInterval& range) const;
    double           heightAt          (double u) const;
    ZcGeVector3d     axisOfSymmetry    () const;
    ZcGeVector3d     refAxis           () const;
    ZcGePoint3d      apex              () const;
    ZSoft::Boolean   isClosed          (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean   isOuterNormal     () const;

    ZcGeCone&        setBaseRadius     (double radius);
    ZcGeCone&        setAngles         (double startAngle, double endAngle);
    ZcGeCone&        setHeight         (const ZcGeInterval& height);
    ZcGeCone&        set               (double cosineAngle, double sineAngle,
                                        const  ZcGePoint3d& baseCenter,
                                        double baseRadius,
                                        const  ZcGeVector3d& axisOfSymmetry);
    ZcGeCone&        set               (double cosineAngle, double sineAngle,
                                        const  ZcGePoint3d& baseCenter,
                                        double baseRadius,
                                        const  ZcGeVector3d& axisOfSymmetry,
                                        const  ZcGeVector3d& refAxis,
                                        const  ZcGeInterval& height,
                                        double startAngle, double endAngle);

    ZcGeCone&        operator =        (const ZcGeCone& cone);

    ZSoft::Boolean   intersectWith     (const ZcGeLinearEnt3d& linEnt, int& intn,
                                        ZcGePoint3d& p1, ZcGePoint3d& p2,
                                        const ZcGeTol& tol = ZcGeContext::gTol) const;
};

#pragma pack (pop)
#endif
