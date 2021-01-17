#ifndef ZC_BRMETRAV_H
#define ZC_BRMETRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcBrMesh2d;
class ZcBrElement2d;


class DllImpExp ZcBrMesh2dElement2dTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMesh2dElement2dTraverser);
    ZcBrMesh2dElement2dTraverser();
    ZcBrMesh2dElement2dTraverser(const ZcBrMesh2dElement2dTraverser& src);
    ~ZcBrMesh2dElement2dTraverser();
    
    // Assignment operator
    ZcBrMesh2dElement2dTraverser& operator =(const ZcBrMesh2dElement2dTraverser& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setMeshAndElement(const ZcBrElement2d& element2d);
    ZcBr::ErrorStatus   setMesh         (const ZcBrMesh2d& mesh2d);
    ZcBr::ErrorStatus   getMesh         (ZcBrMesh2d& mesh2d) const;
    ZcBr::ErrorStatus   setElement		(const ZcBrElement2d& element2d);
    ZcBr::ErrorStatus   getElement		(ZcBrElement2d& element2d) const;
};


#endif

