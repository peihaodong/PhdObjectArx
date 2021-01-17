

#ifndef ZC_GECSINT_H
#define ZC_GECSINT_H

#include "zadesk.h"
#include "zgeent3d.h"
#include "zgeponc3d.h"
#include "zgeponsrf.h"
#include "zgeintrvl.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeCurve3d;

class ZcGeSurface;

class  
GX_DLLEXPIMPORT
ZcGeCurveSurfInt : public ZcGeEntity3d
{

public:

    ZcGeCurveSurfInt ();
    ZcGeCurveSurfInt (const ZcGeCurve3d& crv, const ZcGeSurface& srf,
                         const ZcGeTol& tol = ZcGeContext::gTol );
    ZcGeCurveSurfInt (const ZcGeCurveSurfInt& src);

    const ZcGeCurve3d  *curve           () const;
    const ZcGeSurface  *surface         () const;
    ZcGeTol            tolerance        () const;

    int  numIntPoints (ZcGeIntersectError& err) const;
    ZcGePoint3d  intPoint (int intNum, ZcGeIntersectError& err) const;
    void               getIntParams (int intNum,
                                         double& param1, ZcGePoint2d& param2, ZcGeIntersectError& err) const;
    void               getPointOnCurve (int intNum, ZcGePointOnCurve3d&, ZcGeIntersectError& err) const;
    void               getPointOnSurface (int intNum, ZcGePointOnSurface&, ZcGeIntersectError& err) const;
    void			   getIntConfigs (int intNum, ZcGe::csiConfig& lower, 
								ZcGe::csiConfig& higher, ZSoft::Boolean& smallAngle, ZcGeIntersectError& err) const;

    ZcGeCurveSurfInt& set (const ZcGeCurve3d& cvr,
                                     const ZcGeSurface& srf,
                                     const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCurveSurfInt& operator = (const ZcGeCurveSurfInt& crvInt);
};
#pragma pack (pop)
#endif
