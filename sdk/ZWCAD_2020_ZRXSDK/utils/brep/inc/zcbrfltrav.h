#ifndef ZC_BRFLTRAV_H
#define ZC_BRFLTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrFace;
class ZcBrLoop;
class ZcBrShellFaceTraverser;


class DllImpExp ZcBrFaceLoopTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrFaceLoopTraverser);
    ZcBrFaceLoopTraverser();
    ZcBrFaceLoopTraverser(const ZcBrFaceLoopTraverser& src);
    ~ZcBrFaceLoopTraverser();

    // Assignment operator
    ZcBrFaceLoopTraverser& operator =   (const ZcBrFaceLoopTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setFace         (ZcBrFace& face);
    ZcBr::ErrorStatus   getFace         (ZcBrFace& face) const;
    ZcBr::ErrorStatus   setLoop         (ZcBrLoop& loop);
    ZcBr::ErrorStatus   getLoop         (ZcBrLoop& loop) const;
    ZcBr::ErrorStatus   setFaceAndLoop	(const ZcBrLoop& loop);
    ZcBr::ErrorStatus   setFace         (const ZcBrFace& face);
    ZcBr::ErrorStatus   setLoop         (const ZcBrLoop& loop);
    ZcBr::ErrorStatus   setFace         (const ZcBrShellFaceTraverser& shellFaceTrav);
};


#endif

