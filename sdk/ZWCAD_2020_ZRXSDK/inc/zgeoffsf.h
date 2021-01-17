

#ifndef ZC_GEOFFSF_H
#define ZC_GEOFFSF_H

#include "zgegbl.h"
#include "zgepnt3d.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGePlane;
class ZcGeBoundedPlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;

class
GX_DLLEXPIMPORT
ZcGeOffsetSurface : public ZcGeSurface
{
public:
    ZcGeOffsetSurface();
    ZcGeOffsetSurface(ZcGeSurface* baseSurface,
                      double offsetDist,
                      ZSoft::Boolean makeCopy = ZSoft::kTrue);
    ZcGeOffsetSurface(const ZcGeOffsetSurface& offset);

    ZSoft::Boolean    isPlane        () const;
    ZSoft::Boolean    isBoundedPlane () const;
    ZSoft::Boolean    isSphere       () const;
    ZSoft::Boolean    isCylinder     () const;
    ZSoft::Boolean    isCone         () const;
    ZSoft::Boolean    isTorus        () const;

        ZSoft::Boolean    getSurface(ZcGeSurface*&) const;

    void              getConstructionSurface (ZcGeSurface*& base) const;

    double            offsetDist     () const;

    ZcGeOffsetSurface& set        (ZcGeSurface*, double offsetDist,
                                    ZSoft::Boolean makeCopy = ZSoft::kTrue);

    ZcGeOffsetSurface& operator =  (const ZcGeOffsetSurface& offset);
};

#pragma pack (pop)
#endif
