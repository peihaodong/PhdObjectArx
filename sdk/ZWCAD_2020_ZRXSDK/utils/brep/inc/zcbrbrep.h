#ifndef ZC_BRBREP_H
#define ZC_BRBREP_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrent.h"


// forward class declarations
class ZcDbEntity;
class ZcDb3dSolid;
class ZcDbSurface;
class ZcGePoint3d;
class ZcGeCurve3d;


class DllImpExp ZcBrBrep : public ZcBrEntity
{
public:
	using ZcBrEntity::set;
	using ZcBrEntity::get;

    friend class ZcBrEntityImp;

    ZCRX_DECLARE_MEMBERS(ZcBrBrep);
    ZcBrBrep();
    ZcBrBrep(const ZcBrBrep& src);
    ~ZcBrBrep();

    // Assignment operator
    ZcBrBrep&           operator =      (const ZcBrBrep& src);

	// Set-Membership Classification (Note: deprecated functions)
    ZcBr::ErrorStatus   getPointRelationToBrep(const ZcGePoint3d& point, ZcBr::Relation& relation) const;
    ZcBr::ErrorStatus   getCurveRelationToBrep(const ZcGeCurve3d& curve, ZcBr::Relation& relation) const;

    // Queries & Initialisers
	ZcBr::ErrorStatus	set				(const ZcDbEntity& entity);
	ZcBr::ErrorStatus	get				(ZcDb3dSolid*& pSolid) const;
	ZcBr::ErrorStatus	get				(ZcDbSurface*& pSurface) const;
};


#endif

