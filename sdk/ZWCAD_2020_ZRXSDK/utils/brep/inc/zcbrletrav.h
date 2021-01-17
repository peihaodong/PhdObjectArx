#ifndef ZC_BRLETRAV_H
#define ZC_BRLETRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcGeCurve2d;
class ZcGeCurve3d;
class ZcGeNurbCurve2d;
class ZcGeNurbCurve3d;
class ZcBrLoop;
class ZcBrEdge;
class ZcBrFaceLoopTraverser;
class ZcBrEdgeLoopTraverser;


class DllImpExp ZcBrLoopEdgeTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrLoopEdgeTraverser);
    ZcBrLoopEdgeTraverser();
    ZcBrLoopEdgeTraverser(const ZcBrLoopEdgeTraverser& src);
    ~ZcBrLoopEdgeTraverser();

    // Assignment operator
    ZcBrLoopEdgeTraverser& operator =   (const ZcBrLoopEdgeTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setLoopAndEdge  (ZcBrEdgeLoopTraverser& edgeLoop);
    ZcBr::ErrorStatus   setLoop         (ZcBrFaceLoopTraverser& loop);
    ZcBr::ErrorStatus   getLoop         (ZcBrLoop& loop) const;
    ZcBr::ErrorStatus   setEdge         (ZcBrEdge& edge);
    ZcBr::ErrorStatus   getEdge         (ZcBrEdge& edge) const;

    // Downward links
    // Edge usage by loop (n::1)
    ZcBr::ErrorStatus   getEdgeOrientToLoop(ZSoft::Boolean& orient) const;
    ZcBr::ErrorStatus   getParamCurve   (ZcGeCurve2d*& pcurve) const;
	ZcBr::ErrorStatus	getOrientedCurve(ZcGeCurve3d*& curve) const;
    ZcBr::ErrorStatus   getParamCurveAsNurb(ZcGeNurbCurve2d& nurb,
		                                 const double&    fitTolRequired = *(double*)NULL,
										 double&          fitTolAchieved = *(double*)NULL) const;
	ZcBr::ErrorStatus	getOrientedCurveAsNurb(ZcGeNurbCurve3d& nurb,
		                                 const double&    fitTolRequired = *(double*)NULL,
										 double&          fitTolAchieved = *(double*)NULL) const;

    // Queries & Initialisers
    ZcBr::ErrorStatus   setLoopAndEdge  (const ZcBrEdgeLoopTraverser& edgeLoop);
    ZcBr::ErrorStatus   setLoop         (const ZcBrFaceLoopTraverser& faceLoop);
    ZcBr::ErrorStatus   setLoop         (const ZcBrLoop& loop);
    ZcBr::ErrorStatus   setEdge         (const ZcBrEdge& edge);
};


#endif
