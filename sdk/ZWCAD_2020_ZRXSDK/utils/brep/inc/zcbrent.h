//
#ifndef ZC_BRENT_H
#define ZC_BRENT_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zgegbl.h"
#include "zcbrgbl.h"
#include "zcbrprops.h"


// forward class declarations
class ZcDbFullSubentPath;
class ZcGeBoundBlock3d;
class ZcGePoint3d;
class ZcGeLinearEnt3d;
class ZcBrHit;
class ZcBrBrep;
class ZcBrEntityImp;
class ZcBrBrepData;


class DllImpExp ZcBrEntity : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrEntity);
    virtual ~ZcBrEntity();
    
    // Equivalence                    
    ZSoft::Boolean      isEqualTo       (const ZcRxObject* other) const;
    
    // Queries & Initialisers
    ZSoft::Boolean      isNull          () const;
    ZcBr::ErrorStatus   setSubentPath   (ZcDbFullSubentPath& subpath);
    ZcBr::ErrorStatus   getSubentPath   (ZcDbFullSubentPath& subPath) const;
	
	ZSoft::Boolean		checkEntity		() const;
	void*				getEntity		() const;
	ZcBr::ErrorStatus	setEntity		(void*	pData,
										 ZcDbFullSubentPath& subPath = *(ZcDbFullSubentPath*)NULL);

    // Geometric bounds (i.e., model space bounding box)
    ZcBr::ErrorStatus   getBoundBlock   (ZcGeBoundBlock3d& block) const;

    // Set-Membership Classification
    ZcBr::ErrorStatus   getPointContainment(const ZcGePoint3d& point,
                                            ZcGe::PointContainment& containment,
                                            ZcBrEntity*& container) const;

    ZcBr::ErrorStatus   getLineContainment(const ZcGeLinearEnt3d& line,
                                           const ZSoft::UInt32& numHitsWanted,
                                           ZSoft::UInt32&       numHitsFound,
                                           ZcBrHit*&            hits) const;

    // Upward link to brep owner of subentity (1::1)
    ZcBr::ErrorStatus   getBrep         (ZcBrBrep& brep) const;

	// Validation
	ZcBr::ErrorStatus	setValidationLevel(const ZcBr::ValidationLevel& level = *(ZcBr::ValidationLevel*)NULL);
	ZcBr::ErrorStatus	getValidationLevel(ZcBr::ValidationLevel& level) const;
	ZSoft::Boolean		brepChanged		() const;

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(const ZcDbFullSubentPath& path);
    ZcBr::ErrorStatus   get				(ZcDbFullSubentPath& path) const;
	ZcBr::ErrorStatus	set				(ZcBrBrepData* data);
	ZcBr::ErrorStatus	get				(ZcBrBrepData*& data) const;

	// Geometric properties
	ZcBr::ErrorStatus	getMassProps	(ZcBrMassProps& massProps,
		                                 const double&  density     = *(double*)NULL,
		                                 const double&  tolRequired = *(double*)NULL,
		                                 double&        tolAchieved = *(double*)NULL) const;
	ZcBr::ErrorStatus	getVolume		(double&       volume,
		                                 const double& tolRequired = *(double*)NULL,
		                                 double&       tolAchieved = *(double*)NULL) const;
	ZcBr::ErrorStatus	getSurfaceArea	(double&       area,
		                                 const double& tolRequired = *(double*)NULL,
		                                 double&       tolAchieved = *(double*)NULL) const;
	ZcBr::ErrorStatus	getPerimeterLength(double&       length,
		                                   const double& tolRequired = *(double*)NULL,
		                                   double&       tolAchieved = *(double*)NULL) const;

    void* internalImp() const { return mpImp; }

protected:
    ZcBrEntity();
    ZcBrEntity(const ZcBrEntity& src);
    ZcBrEntity&         operator =      (const ZcBrEntity& src);

    ZcBrEntityImp*      mpImp;
};


#endif

