#ifndef ZC_BRHIT_H
#define ZC_BRHIT_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"


// forward class declarations
class ZcGePoint3d;
class ZcBrEntity;
class ZcBrHitData;
class ZcBrImpHit;


// this is a temporary typedef to guarantee binary compatibility
typedef ZcBrHitData ZcBrHitPath;


class DllImpExp ZcBrHit : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrHit);
    ZcBrHit();
    ZcBrHit(const ZcBrHit& src);
    ~ZcBrHit();

    // Assignment operator
    ZcBrHit&            operator =      (const ZcBrHit& src);

    // Equivalence                    
    ZSoft::Boolean      isEqualTo       (const ZcRxObject* other) const;
    
    // Queries & Initialisers
    ZSoft::Boolean      isNull          () const;
	// (Note: obsolete function)
    ZcBr::ErrorStatus   setHitPath	    (ZcBrHitPath& hitPath);

    // Geometry (Note: deprecated function)
    ZcBr::ErrorStatus   getPoint        (ZcGePoint3d*& point) const;

    // Topological Containment
    ZcBr::ErrorStatus   getEntityHit    (ZcBrEntity*& entityHit) const;
    ZcBr::ErrorStatus   getEntityEntered(ZcBrEntity*& entityEntered) const;

	// Topology
	ZcBr::ErrorStatus   getEntityAssociated(ZcBrEntity*& entity) const;

    // Geometry
    ZcBr::ErrorStatus   getPoint        (ZcGePoint3d& point) const;

	// Validation
	ZcBr::ErrorStatus	setValidationLevel(const ZcBr::ValidationLevel& validationLevel = *(ZcBr::ValidationLevel*)NULL);
	ZcBr::ErrorStatus	getValidationLevel(ZcBr::ValidationLevel& validationLevel) const;
	ZSoft::Boolean		brepChanged		() const;

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(ZcBrHitData* hitData);
    ZcBr::ErrorStatus   get				(ZcBrHitData*& hitData) const;

protected:
    ZcBrImpHit*         mpImp;
};


#endif

