

#ifndef ZC_GESURF_H
#define ZC_GESURF_H

#include "zgeent3d.h"
#include "zgevc3dar.h"
#pragma pack (push, 8)

class ZcGePoint2d;
class ZcGeCurve3d;
class ZcGePointOnCurve3d;
class ZcGePointOnSurface;
class ZcGePointOnSurfaceData;
class ZcGeInterval;

class
GE_DLLEXPIMPORT
ZcGeSurface : public ZcGeEntity3d
{
public:

    ZcGePoint2d     paramOf        (const ZcGePoint3d& pnt,
                                    const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean  isOn           (const ZcGePoint3d& pnt,
                                    const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean  isOn           (const ZcGePoint3d& pnt, ZcGePoint2d& paramPoint,
                                    const ZcGeTol& tol = ZcGeContext::gTol ) const;

    ZcGePoint3d closestPointTo(const ZcGePoint3d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    void getClosestPointTo(const ZcGePoint3d& pnt, ZcGePointOnSurface& result,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;
	
    double          distanceTo     (const ZcGePoint3d& pnt,
                                    const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean  isNormalReversed () const;
    ZcGeSurface&    reverseNormal    ();

    ZcGeSurface&    operator =     (const ZcGeSurface& otherSurface);

    void   getEnvelope  (ZcGeInterval& intrvlX, ZcGeInterval& intrvlY) const;

    ZSoft::Boolean isClosedInU       (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isClosedInV       (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d   evalPoint   (const ZcGePoint2d& param) const;
    ZcGePoint3d   evalPoint   (const ZcGePoint2d& param, int derivOrd,
                               ZcGeVector3dArray& derivatives) const;
    ZcGePoint3d   evalPoint   (const ZcGePoint2d& param, int derivOrd,
                               ZcGeVector3dArray& derivatives,
                               ZcGeVector3d& normal) const;
protected:
    ZcGeSurface ();
    ZcGeSurface (const ZcGeSurface&);
};

#pragma pack (pop)
#endif
