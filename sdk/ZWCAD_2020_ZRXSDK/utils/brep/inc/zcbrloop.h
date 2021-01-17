#ifndef ZC_BRLOOP_H
#define ZC_BRLOOP_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcBrFace;


class DllImpExp ZcBrLoop : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrLoop);
    ZcBrLoop();
    ZcBrLoop(const ZcBrLoop& src);
    ~ZcBrLoop();

    // Assignment operator
    ZcBrLoop&           operator =      (const ZcBrLoop& src);

    // Upward links
    // Face usage of loop (1::1)
    ZcBr::ErrorStatus   getFace         (ZcBrFace& face) const;

	// Loop type (e.g., exterior vs. interior)
	ZcBr::ErrorStatus   getType			(ZcBr::LoopType& type) const;
};


#endif
