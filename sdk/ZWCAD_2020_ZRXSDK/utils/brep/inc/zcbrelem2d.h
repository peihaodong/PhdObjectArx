#ifndef ZC_BRELEM2D_H
#define ZC_BRELEM2D_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrelem.h"


// forward class declarations
class ZcGeVector3d;
class ZcBrElement;
class AcBrElement2dData;


class DllImpExp ZcBrElement2d : public ZcBrElement
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrElement2d);
    ZcBrElement2d();
    ZcBrElement2d(const ZcBrElement2d& src);
    ~ZcBrElement2d();
    
    // Assignment operator
    ZcBrElement2d&		operator =      (const ZcBrElement2d& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(AcBrElement2dData* data);
	ZcBr::ErrorStatus	get				(AcBrElement2dData*& data) const;

    // Geometry (for stereolithography support)
    ZcBr::ErrorStatus   getNormal		(ZcGeVector3d& normal) const;
};


#endif

