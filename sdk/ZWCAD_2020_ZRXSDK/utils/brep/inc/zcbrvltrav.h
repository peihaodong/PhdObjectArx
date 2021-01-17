#ifndef ZC_BRVLTRAV_H
#define ZC_BRVLTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrLoop;
class ZcBrVertex;
class ZcBrLoopVertexTraverser;


class DllImpExp ZcBrVertexLoopTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrVertexLoopTraverser);
    ZcBrVertexLoopTraverser();
    ZcBrVertexLoopTraverser(const ZcBrVertexLoopTraverser& src);
    ~ZcBrVertexLoopTraverser();

    // Assignment operator
    ZcBrVertexLoopTraverser& operator =	(const ZcBrVertexLoopTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setVertexAndLoop(const ZcBrLoopVertexTraverser& LoopVertexTraverser);
    ZcBr::ErrorStatus   setVertex       (const ZcBrVertex& vertex);
    ZcBr::ErrorStatus   getVertex       (ZcBrVertex& vertex) const;
    ZcBr::ErrorStatus   setLoop         (const ZcBrLoop& loop);
    ZcBr::ErrorStatus   getLoop         (ZcBrLoop& loop) const;
};


#endif

