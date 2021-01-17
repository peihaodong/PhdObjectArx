#ifndef ZC_BRSHELL_H
#define ZC_BRSHELL_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcBrComplex;


class DllImpExp ZcBrShell : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrShell);
    ZcBrShell();
    ZcBrShell(const ZcBrShell& src);
    ~ZcBrShell();

    // Assignment operator
    ZcBrShell&          operator =      (const ZcBrShell& src);

    // Upward links
    // Complex usage of shell (1::1)
    ZcBr::ErrorStatus   getComplex		(ZcBrComplex& complex) const;

	// Shell type (e.g., exterior vs. interior)
	ZcBr::ErrorStatus   getType			(ZcBr::ShellType& shellType) const;
};


#endif
