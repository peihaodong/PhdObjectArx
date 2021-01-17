#ifndef ZC_BRBVTRAV_H
#define ZC_BRBVTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrBrep;
class ZcBrVertex;


class DllImpExp ZcBrBrepVertexTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrBrepVertexTraverser);
    ZcBrBrepVertexTraverser();
    ZcBrBrepVertexTraverser(const ZcBrBrepVertexTraverser& src);
    ~ZcBrBrepVertexTraverser();

    // Assignment operator
    ZcBrBrepVertexTraverser& operator =	(const ZcBrBrepVertexTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setBrepAndVertex(const ZcBrVertex& vertex);
    ZcBr::ErrorStatus   setBrep         (const ZcBrBrep& brep);
    ZcBr::ErrorStatus   getBrep         (ZcBrBrep& brep) const;
    ZcBr::ErrorStatus   setVertex       (const ZcBrVertex& vertex);
    ZcBr::ErrorStatus   getVertex       (ZcBrVertex& vertex) const;
};


#endif

