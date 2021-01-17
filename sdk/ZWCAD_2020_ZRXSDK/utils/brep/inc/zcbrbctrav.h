#ifndef ZC_BRBCTRAV_H
#define ZC_BRBCTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrBrep;
class ZcBrComplex;


class DllImpExp ZcBrBrepComplexTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrBrepComplexTraverser);
    ZcBrBrepComplexTraverser();
    ZcBrBrepComplexTraverser(const ZcBrBrepComplexTraverser& src);
    ~ZcBrBrepComplexTraverser();

    // Assignment operator
    ZcBrBrepComplexTraverser& operator =(const ZcBrBrepComplexTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setBrepAndComplex(const ZcBrComplex& complex);
    ZcBr::ErrorStatus   setBrep         (const ZcBrBrep& brep);
    ZcBr::ErrorStatus   getBrep         (ZcBrBrep& brep) const;
    ZcBr::ErrorStatus   setComplex      (const ZcBrComplex& complex);
    ZcBr::ErrorStatus   getComplex      (ZcBrComplex& complex) const;
};


#endif

