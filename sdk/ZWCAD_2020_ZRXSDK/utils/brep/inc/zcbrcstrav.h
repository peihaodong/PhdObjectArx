#ifndef ZC_BRCSTRAV_H
#define ZC_BRCSTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrComplex;
class ZcBrShell;
class ZcBrBrepComplexTraverser;


class DllImpExp ZcBrComplexShellTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrComplexShellTraverser);
    ZcBrComplexShellTraverser();
    ZcBrComplexShellTraverser(const ZcBrComplexShellTraverser& src);
    ~ZcBrComplexShellTraverser();

    // Assignment operator
    ZcBrComplexShellTraverser& operator =(const ZcBrComplexShellTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setComplexAndShell(const ZcBrShell& shell);
    ZcBr::ErrorStatus   setComplex      (const ZcBrBrepComplexTraverser& 						brepcompshell);
    ZcBr::ErrorStatus   setComplex	(const ZcBrComplex& complex);
    ZcBr::ErrorStatus   getComplex      (ZcBrComplex& complex) const;
    ZcBr::ErrorStatus   setShell        (const ZcBrShell& shell);
    ZcBr::ErrorStatus   getShell        (ZcBrShell& shell) const;
};


#endif

