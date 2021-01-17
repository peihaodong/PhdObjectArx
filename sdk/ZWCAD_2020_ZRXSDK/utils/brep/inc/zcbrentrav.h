#ifndef ZC_BRENTRAV_H
#define ZC_BRENTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zgegbl.h"
#include "zcbrgbl.h"
#include "zcbrtrav.h"


// forward class declarations
class ZcGePoint2d;
class ZcGeVector3d;
class ZcBrElement2d;
class ZcBrNode;
class ZcBrMesh2dElement2dTraverser;


class DllImpExp ZcBrElement2dNodeTraverser : public ZcBrTraverser
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrElement2dNodeTraverser);
    ZcBrElement2dNodeTraverser();
    ZcBrElement2dNodeTraverser(const ZcBrElement2dNodeTraverser& src);
    ~ZcBrElement2dNodeTraverser();
    
    // Assignment operator
    ZcBrElement2dNodeTraverser& operator =(const ZcBrElement2dNodeTraverser& src);

    // Queries & Initialisers
	ZcBr::ErrorStatus   setElement		(const ZcBrMesh2dElement2dTraverser& mesh2dElement2dTraverser);
    ZcBr::ErrorStatus   setElement		(const ZcBrElement2d& element);
    ZcBr::ErrorStatus   getElement		(ZcBrElement2d& element) const;
    ZcBr::ErrorStatus   setNode         (const ZcBrNode& node);
    ZcBr::ErrorStatus   getNode         (ZcBrNode& node) const;

	// Upward links
	// Node usage by original face (1::1)
    ZcBr::ErrorStatus   getSurfaceNormal(ZcGeVector3d& vector) const;
    ZcBr::ErrorStatus   getParamPoint	(ZcGePoint2d& point) const;
};


#endif

