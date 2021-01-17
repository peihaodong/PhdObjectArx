#ifndef ZC_BRBETRAV_H
#define ZC_BRBETRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrBrep;
class ZcBrEdge;


class DllImpExp ZcBrBrepEdgeTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrBrepEdgeTraverser);
    ZcBrBrepEdgeTraverser();
    ZcBrBrepEdgeTraverser(const ZcBrBrepEdgeTraverser& src);
    ~ZcBrBrepEdgeTraverser();

    // Assignment operator
    ZcBrBrepEdgeTraverser& operator =   (const ZcBrBrepEdgeTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setBrepAndEdge  (const ZcBrEdge& edge);
    ZcBr::ErrorStatus   setBrep         (const ZcBrBrep& brep);
    ZcBr::ErrorStatus   getBrep         (ZcBrBrep& brep) const;
    ZcBr::ErrorStatus   setEdge         (const ZcBrEdge& edge);
    ZcBr::ErrorStatus   getEdge         (ZcBrEdge& edge) const;
};


#endif

