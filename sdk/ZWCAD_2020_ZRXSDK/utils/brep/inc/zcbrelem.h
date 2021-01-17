#ifndef ZC_BRELEM_H
#define ZC_BRELEM_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrment.h"


// forward class declarations
class ZcBrMeshEntity;


class DllImpExp ZcBrElement : public ZcBrMeshEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrElement);
    virtual ~ZcBrElement();
    
protected:
    ZcBrElement();
    ZcBrElement(const ZcBrElement& src);
    ZcBrElement&		operator =      (const ZcBrElement& src);
};


#endif

