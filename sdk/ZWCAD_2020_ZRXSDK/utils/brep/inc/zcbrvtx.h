#ifndef ZC_BRVTX_H
#define ZC_BRVTX_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcGePoint3d;
class ZcGeCurve3d;


class DllImpExp ZcBrVertex : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrVertex);
    ZcBrVertex();
    ZcBrVertex(const ZcBrVertex& src);
    ~ZcBrVertex();

    // Assignment operator
    ZcBrVertex&         operator =      (const ZcBrVertex& src);

    // Geometry (Note: deprecated function)
    ZcBr::ErrorStatus   getPoint        (ZcGePoint3d*& pt) const;

	// Set-Membership Classification (Note: deprecated functions)
    ZcBr::ErrorStatus   getPointRelationToVertex(const ZcGePoint3d& point, ZcBr::Relation& relation) const;
    ZcBr::ErrorStatus   getCurveRelationToVertex(const ZcGeCurve3d& curve, ZcBr::Relation& relation) const;

    // Geometry
    ZcBr::ErrorStatus   getPoint        (ZcGePoint3d& pt) const;
};


#endif

