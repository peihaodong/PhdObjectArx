

#ifndef ZC_GESPHERE_H
#define ZC_GESPHERE_H

#include "zgegbl.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zgeintrvl.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGeCircArc3d;

class
GX_DLLEXPIMPORT
ZcGeSphere : public ZcGeSurface
{
public:
    ZcGeSphere();
    ZcGeSphere(double radius, const ZcGePoint3d& center);
    ZcGeSphere(double radius, const ZcGePoint3d& center,
               const ZcGeVector3d& northAxis, const ZcGeVector3d& refAxis,
               double startAngleU, double endAngleU,
               double startAngleV, double endAngleV);
    ZcGeSphere(const ZcGeSphere& sphere);

    double         radius            () const;
    ZcGePoint3d    center            () const;
    void           getAnglesInU      (double& start, double& end) const;
    void           getAnglesInV      (double& start, double& end) const;
    ZcGeVector3d   northAxis         () const;
    ZcGeVector3d   refAxis           () const;
    ZcGePoint3d    northPole         () const;
    ZcGePoint3d    southPole         () const;
    ZSoft::Boolean isOuterNormal     () const;
    ZSoft::Boolean isClosed       (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeSphere&    setRadius         (double);
    ZcGeSphere&    setAnglesInU      (double start, double end);
    ZcGeSphere&    setAnglesInV      (double start, double end);
    ZcGeSphere&    set               (double radius, const ZcGePoint3d& center);
    ZcGeSphere&    set               (double radius, const ZcGePoint3d& center,
                                      const ZcGeVector3d& northAxis,
                                      const ZcGeVector3d& refAxis,
                                      double startAngleU,
                                      double endAngleU,
                                      double startAngleV,
                                      double endAngleV);

    ZcGeSphere&    operator =     (const ZcGeSphere& sphere);

    ZSoft::Boolean intersectWith  (const ZcGeLinearEnt3d&, int& intn,
                                   ZcGePoint3d& p1, ZcGePoint3d& p2,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

	ZcGeSphere& setrefAxis (ZcGeVector3d val);		// INTERNAL USE ONLY
	ZcGeSphere& setnorthAxis (ZcGeVector3d val);	// INTERNAL USE ONLY

};

#pragma pack (pop)
#endif
