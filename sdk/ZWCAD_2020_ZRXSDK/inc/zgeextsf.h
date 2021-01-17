

#ifndef ZC_GEEXTSF_H
#define ZC_GEEXTSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#pragma pack (push, 8)

class ZcGePlane;
class ZcGeCylinder;
class ZcGeCone;
class ZcGeSphere;
class ZcGeTorus;
class ZcGeNurbSurface;
class surface;

class
GX_DLLEXPIMPORT
ZcGeExternalSurface : public ZcGeSurface
{
public:
   ZcGeExternalSurface();
   ZcGeExternalSurface(void* surfaceDef, ZcGe::ExternalEntityKind surfaceKind,
                       ZSoft::Boolean makeCopy = ZSoft::kTrue);
   ZcGeExternalSurface(const ZcGeExternalSurface&);

   void getExternalSurface(void*& surfaceDef) const;

   ZcGe::ExternalEntityKind  externalSurfaceKind() const;

   ZSoft::Boolean    isPlane      () const;
   ZSoft::Boolean    isSphere     () const;
   ZSoft::Boolean    isCylinder   () const;
   ZSoft::Boolean    isCone       () const;
   ZSoft::Boolean    isTorus      () const;
   ZSoft::Boolean    isNurbSurface() const;
   ZSoft::Boolean    isDefined    () const;

   ZSoft::Boolean isNativeSurface(ZcGeSurface*& nativeSurface) const;

   ZcGeExternalSurface& operator = (const ZcGeExternalSurface& src);

   ZcGeExternalSurface& set(void* surfaceDef,
                            ZcGe::ExternalEntityKind surfaceKind,
                            ZSoft::Boolean makeCopy = ZSoft::kTrue);

   ZSoft::Boolean       isOwnerOfSurface    () const;
   ZcGeExternalSurface& setToOwnSurface     ();
};

#pragma pack (pop)
#endif
