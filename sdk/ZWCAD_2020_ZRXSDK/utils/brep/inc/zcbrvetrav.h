#ifndef ZC_BRVETRAV_H
#define ZC_BRVETRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrEdge;
class ZcBrVertex;


class DllImpExp ZcBrVertexEdgeTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrVertexEdgeTraverser);
    ZcBrVertexEdgeTraverser();
    ZcBrVertexEdgeTraverser(const ZcBrVertexEdgeTraverser& src);
    ~ZcBrVertexEdgeTraverser();

    // Assignment operator
    ZcBrVertexEdgeTraverser& operator =	(const ZcBrVertexEdgeTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setVertex		(const ZcBrVertex& vertex);
    ZcBr::ErrorStatus   getVertex       (ZcBrVertex& vertex) const;
    ZcBr::ErrorStatus   setEdge         (const ZcBrEdge& edge);
    ZcBr::ErrorStatus   getEdge         (ZcBrEdge& edge) const;
};


#endif

