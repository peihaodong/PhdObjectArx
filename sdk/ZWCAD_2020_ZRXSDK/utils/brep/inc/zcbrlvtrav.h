#ifndef ZC_BRLVTRAV_H
#define ZC_BRLVTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcGePoint2d;
class ZcBrLoop;
class ZcBrVertex;
class ZcBrFaceLoopTraverser;
class ZcBrVertexLoopTraverser;


class DllImpExp ZcBrLoopVertexTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrLoopVertexTraverser);
    ZcBrLoopVertexTraverser();
    ZcBrLoopVertexTraverser(const ZcBrLoopVertexTraverser& src);
    ~ZcBrLoopVertexTraverser();

    // Assignment operator
    ZcBrLoopVertexTraverser& operator = (const ZcBrLoopVertexTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setLoop         (ZcBrFaceLoopTraverser& faceLoop);
    ZcBr::ErrorStatus   getLoop         (ZcBrLoop& loop) const;
    ZcBr::ErrorStatus   getVertex       (ZcBrVertex& vertex) const;

    // Downward links
    // Vertex usage by loop (n::1)
    ZcBr::ErrorStatus   getParamPoint	(ZcGePoint2d*& ppoint) const;
    ZcBr::ErrorStatus   getParamPoint	(ZcGePoint2d& ppoint) const;

    // Queries & Initialisers
	ZcBr::ErrorStatus	setLoopAndVertex(const ZcBrVertexLoopTraverser& vertexLoop);
    ZcBr::ErrorStatus   setLoop         (const ZcBrFaceLoopTraverser& faceLoop);
	ZcBr::ErrorStatus   setLoop         (const ZcBrLoop& loop);
    ZcBr::ErrorStatus   setVertex       (const ZcBrVertex& vertex);
};


#endif
