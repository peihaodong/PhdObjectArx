#ifndef ZC_BRBSTRAV_H
#define ZC_BRBSTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrBrep;
class ZcBrShell;


class DllImpExp ZcBrBrepShellTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrBrepShellTraverser);
    ZcBrBrepShellTraverser();
    ZcBrBrepShellTraverser(const ZcBrBrepShellTraverser& src);
    ~ZcBrBrepShellTraverser();

    // Assignment operator
    ZcBrBrepShellTraverser& operator =(const ZcBrBrepShellTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setBrepAndShell	(const ZcBrShell& shell);
    ZcBr::ErrorStatus   setBrep			(const ZcBrBrep& brep);
    ZcBr::ErrorStatus   getBrep			(ZcBrBrep& brep) const;
    ZcBr::ErrorStatus   setShell		(const ZcBrShell& shell);
    ZcBr::ErrorStatus   getShell		(ZcBrShell& shell) const;
};


#endif

