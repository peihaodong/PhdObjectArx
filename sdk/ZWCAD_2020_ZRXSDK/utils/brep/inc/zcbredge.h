#ifndef ZC_BREDGE_H
#define ZC_BREDGE_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zgegbl.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcGePoint3d;
class ZcGeCurve3d;
class ZcGeNurbCurve3d;
class ZcBrVertex;


class DllImpExp ZcBrEdge : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrEdge);
    ZcBrEdge();
    ZcBrEdge(const ZcBrEdge& src);
    ~ZcBrEdge();

    // Assignment operator
    ZcBrEdge&           operator =      (const ZcBrEdge& src);

    // Geometry
    ZcBr::ErrorStatus   getCurveType    (ZcGe::EntityId& type) const;
    ZcBr::ErrorStatus   getCurve        (ZcGeCurve3d*& curve) const;
    ZcBr::ErrorStatus   getOrientToCurve(ZSoft::Boolean& bOrientToCurve) const;

    // Downward links
    // Vertex usage by edge (2::1, 1::1 or 0::1)
    ZcBr::ErrorStatus   getVertex1      (ZcBrVertex& vertex) const;
    ZcBr::ErrorStatus   getVertex2      (ZcBrVertex& vertex) const;

	// Set-Membership Classification (Note: deprecated functions)
    ZcBr::ErrorStatus   getPointRelationToEdge(const ZcGePoint3d& point, ZcBr::Relation& relation) const;
    ZcBr::ErrorStatus   getCurveRelationToEdge(const ZcGeCurve3d& curve, ZcBr::Relation& relation) const;

    // Geometry
    ZcBr::ErrorStatus   getCurveAsNurb	(ZcGeNurbCurve3d& nurb,
		                                 const double&    fitTolRequired = *(double*)NULL,
										 double&          fitTolAchieved = *(double*)NULL) const;
};


#endif

