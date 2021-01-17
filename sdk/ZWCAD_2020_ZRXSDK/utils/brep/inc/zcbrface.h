//
#ifndef ZC_BRFACE_H
#define ZC_BRFACE_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zgegbl.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcGeSurface;
class ZcGeNurbSurface;
class ZcGeExternalBoundedSurface;
class ZcGeCurve3d;
class ZcGePoint3d;
class ZcBrShell;


class DllImpExp ZcBrFace : public ZcBrEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrFace);
    ZcBrFace();
    ZcBrFace(const ZcBrFace& src);
    ~ZcBrFace();

    // Assignment operator
    ZcBrFace&           operator =      (const ZcBrFace& src);

    // Geometry
    ZcBr::ErrorStatus   getSurfaceType  (ZcGe::EntityId& type) const;
    ZcBr::ErrorStatus   getSurface      (ZcGeSurface*& surface) const;
    ZcBr::ErrorStatus   getOrientToSurface(ZSoft::Boolean& bOrientToSurface) const;
	ZcBr::ErrorStatus	getArea			(double&		area, 
										 const double&	tolRequired = *(double*)NULL,										
										 double&		tolAchieved = *(double*)NULL) const;

	// Set-Membership Classification Note: deprecated functions)
    ZcBr::ErrorStatus   getPointRelationToFace(const ZcGePoint3d& point, ZcBr::Relation& relation) const;
    ZcBr::ErrorStatus   getCurveRelationToFace(const ZcGeCurve3d& curve, ZcBr::Relation& relation) const;

    // Geometry
    ZcBr::ErrorStatus   getSurfaceAsNurb(ZcGeNurbSurface& nurb,
		                                 const double&    fitTolRequired = *(double*)NULL,
										 double&          fitTolAchieved = *(double*)NULL) const;
    ZcBr::ErrorStatus   getSurfaceAsTrimmedNurbs(ZSoft::UInt32&                numNurbs,
		                                         ZcGeExternalBoundedSurface**& ppNurbs) const;

    // Upward links
    // Shell usage of face (1::1)
    ZcBr::ErrorStatus   getShell        (ZcBrShell& shell) const;
};


#endif

