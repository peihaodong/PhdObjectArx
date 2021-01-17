#ifndef ZC_BRSFTRAV_H
#define ZC_BRSFTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrShell;
class ZcBrFace;
class ZcBrComplexShellTraverser;


class DllImpExp ZcBrShellFaceTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrShellFaceTraverser);
    ZcBrShellFaceTraverser();
    ZcBrShellFaceTraverser(const ZcBrShellFaceTraverser& src);
    ~ZcBrShellFaceTraverser();

    // Assignment operator
    ZcBrShellFaceTraverser& operator =  (const ZcBrShellFaceTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setShellAndFace	(const ZcBrFace& face);
    ZcBr::ErrorStatus   setShell        (const ZcBrComplexShellTraverser& complexShellTraverser);
    ZcBr::ErrorStatus   setShell        (const ZcBrShell& shell);
    ZcBr::ErrorStatus   getShell        (ZcBrShell& shell) const;
    ZcBr::ErrorStatus   setFace         (const ZcBrFace& face);
    ZcBr::ErrorStatus   getFace         (ZcBrFace& face) const;
};


#endif

