#ifndef ZC_BRELTRAV_H
#define ZC_BRELTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrLoop;
class ZcBrEdge;
class ZcBrLoopEdgeTraverser;
class ZcBrVertexEdgeTraverser;


class DllImpExp ZcBrEdgeLoopTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrEdgeLoopTraverser);
    ZcBrEdgeLoopTraverser();
    ZcBrEdgeLoopTraverser(const ZcBrEdgeLoopTraverser& src);
    ~ZcBrEdgeLoopTraverser();

    // Assignment operator
    ZcBrEdgeLoopTraverser& operator =   (const ZcBrEdgeLoopTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setEdgeAndLoop  (ZcBrLoopEdgeTraverser& loopEdge);
    ZcBr::ErrorStatus   setEdge         (ZcBrEdge& edge);
    ZcBr::ErrorStatus   getEdge         (ZcBrEdge& edge) const;
    ZcBr::ErrorStatus   getLoop         (ZcBrLoop& loop) const;
    ZcBr::ErrorStatus   setEdgeAndLoop  (const ZcBrLoopEdgeTraverser& loopEdge);
    ZcBr::ErrorStatus   setEdge         (const ZcBrVertexEdgeTraverser& vertexEdge);
    ZcBr::ErrorStatus   setEdge         (const ZcBrEdge& edge);
    ZcBr::ErrorStatus   setLoop         (const ZcBrLoop& loop);
};


#endif

