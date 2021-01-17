#ifndef ZC_BRCPLX_H
#define ZC_BRCPLX_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


class DllImpExp ZcBrComplex : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrComplex);
    ZcBrComplex();
    ZcBrComplex(const ZcBrComplex& src);
    ~ZcBrComplex();

    // Assignment operator
    ZcBrComplex&	operator =      (const ZcBrComplex& src);
};


#endif
