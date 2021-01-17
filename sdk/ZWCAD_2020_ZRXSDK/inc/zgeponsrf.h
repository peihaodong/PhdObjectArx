

#ifndef ZC_GEPONSRF_H
#define ZC_GEPONSRF_H

#include "zgepent3d.h"
#pragma pack (push, 8)

class ZcGeSurface;

class
GE_DLLEXPIMPORT
ZcGePointOnSurface : public ZcGePointEnt3d
{
public:
    ZcGePointOnSurface();
    ZcGePointOnSurface(const ZcGeSurface& surf);
    ZcGePointOnSurface(const ZcGeSurface& surf, const ZcGePoint2d& param);
    ZcGePointOnSurface(const ZcGePointOnSurface& src);

    ZcGePointOnSurface& operator =     (const ZcGePointOnSurface& src);

    const ZcGeSurface*  surface        () const;
    ZcGePoint2d         parameter      () const;

    ZcGePoint3d         point          () const;
    ZcGePoint3d         point          (const ZcGePoint2d& param );
    ZcGePoint3d         point          (const ZcGeSurface& surf,
                                        const ZcGePoint2d& param);

    ZcGeVector3d        normal         () const;
    ZcGeVector3d        normal         (const ZcGePoint2d& param );
    ZcGeVector3d        normal         (const ZcGeSurface& surf,
                                        const ZcGePoint2d& param);

    ZcGeVector3d        uDeriv         (int order) const;
    ZcGeVector3d        uDeriv         (int order, const ZcGePoint2d& param);
    ZcGeVector3d        uDeriv         (int order, const ZcGeSurface& surf,
                                        const ZcGePoint2d& param);

    ZcGeVector3d        vDeriv         (int order) const;
    ZcGeVector3d        vDeriv         (int order, const ZcGePoint2d& param);
    ZcGeVector3d        vDeriv         (int order, const ZcGeSurface& surf,
                                        const ZcGePoint2d& param);

    ZcGeVector3d        mixedPartial   () const;
    ZcGeVector3d        mixedPartial   (const ZcGePoint2d& param);
    ZcGeVector3d        mixedPartial   (const ZcGeSurface& surf,
                                        const ZcGePoint2d& param);

    ZcGeVector3d        tangentVector  (const ZcGeVector2d& vec) const;
    ZcGeVector3d        tangentVector  (const ZcGeVector2d& vec,
                                        const ZcGePoint2d& param);
    ZcGeVector3d        tangentVector  (const ZcGeVector2d& vec,
                                        const ZcGeSurface& vecSurf,
                                        const ZcGePoint2d& param);

    ZcGeVector2d        inverseTangentVector  (const ZcGeVector3d& vec) const;
    ZcGeVector2d        inverseTangentVector  (const ZcGeVector3d& vec,
                                               const ZcGePoint2d& param);
    ZcGeVector2d        inverseTangentVector  (const ZcGeVector3d& vec,
                                               const ZcGeSurface& surf,
                                               const ZcGePoint2d& param);

    ZcGePointOnSurface& setSurface     (const ZcGeSurface& surf);
    ZcGePointOnSurface& setParameter   (const ZcGePoint2d& param);
};

#pragma pack (pop)
#endif

