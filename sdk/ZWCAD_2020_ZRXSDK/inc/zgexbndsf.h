

#ifndef ZC_GEXBNDSF_H
#define ZC_GEXBNDSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGeExternalSurface;
class ZcGeCurveBoundary;

class
GX_DLLEXPIMPORT
ZcGeExternalBoundedSurface : public ZcGeSurface
{
public:
   ZcGeExternalBoundedSurface();
   ZcGeExternalBoundedSurface(void* surfaceDef, ZcGe::ExternalEntityKind surfaceKind,
                              ZSoft::Boolean makeCopy = ZSoft::kTrue);
   ZcGeExternalBoundedSurface(const ZcGeExternalBoundedSurface&);

   ZcGe::ExternalEntityKind   externalSurfaceKind  () const;
   ZSoft::Boolean             isDefined            () const;
   void                       getExternalSurface   (void*& surfaceDef) const;

    void getBaseSurface        (ZcGeSurface*& surfaceDef) const;

	void getBaseSurface        (ZcGeExternalSurface& unboundedSurfaceDef) const;

    ZSoft::Boolean isPlane() const;
    ZSoft::Boolean isSphere() const;
    ZSoft::Boolean isCylinder() const;
    ZSoft::Boolean isCone() const;
    ZSoft::Boolean isTorus() const;
    ZSoft::Boolean isNurbs() const;
    ZSoft::Boolean isExternalSurface() const;

    int          numContours  () const;
    void         getContours  (int& numContours, ZcGeCurveBoundary*& curveBoundaries) const;

    ZcGeExternalBoundedSurface& set  (void* surfaceDef,
                                      ZcGe::ExternalEntityKind surfaceKind,
                                      ZSoft::Boolean makeCopy = ZSoft::kTrue);

    ZcGeExternalBoundedSurface& operator = (const ZcGeExternalBoundedSurface&);

        ZSoft::Boolean               isOwnerOfSurface() const;
    ZcGeExternalBoundedSurface&  setToOwnSurface();
};

#pragma pack (pop)
#endif
