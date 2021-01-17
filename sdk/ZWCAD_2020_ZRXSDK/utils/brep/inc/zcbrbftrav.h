#ifndef ZC_BRBFTRAV_H
#define ZC_BRBFTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrBrep;
class ZcBrFace;


class DllImpExp ZcBrBrepFaceTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrBrepFaceTraverser);
    ZcBrBrepFaceTraverser();
    ZcBrBrepFaceTraverser(const ZcBrBrepFaceTraverser& src);
    ~ZcBrBrepFaceTraverser();

    // Assignment operator
    ZcBrBrepFaceTraverser& operator =   (const ZcBrBrepFaceTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setBrep         (ZcBrBrep& brep);
    ZcBr::ErrorStatus   getBrep         (ZcBrBrep& brep) const;
    ZcBr::ErrorStatus   setFace         (ZcBrFace& face);
    ZcBr::ErrorStatus   getFace         (ZcBrFace& face) const;
    ZcBr::ErrorStatus   setBrepAndFace  (const ZcBrFace& face);
    ZcBr::ErrorStatus   setBrep         (const ZcBrBrep& brep);
    ZcBr::ErrorStatus   setFace         (const ZcBrFace& face);
};


#endif

