#ifndef ZC_BRMENT_H
#define ZC_BRMENT_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"


// forward class declarations
class ZcBrEntity;
class ZcBrImpMeshEntity;


class DllImpExp ZcBrMeshEntity : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMeshEntity);
    virtual ~ZcBrMeshEntity();

    // Equivalence                    
    ZSoft::Boolean      isEqualTo       (const ZcRxObject* other) const;
    
    // Queries & Initialisers
    ZSoft::Boolean      isNull          () const;
    
	// Topology
	ZcBr::ErrorStatus   getEntityAssociated(ZcBrEntity*& entity) const;

	// Validation
	ZcBr::ErrorStatus	setValidationLevel(const ZcBr::ValidationLevel& = *(ZcBr::ValidationLevel*)NULL);
	ZcBr::ErrorStatus	getValidationLevel(ZcBr::ValidationLevel& validationLevel) const;
	ZSoft::Boolean		brepChanged		() const;

protected:
    ZcBrMeshEntity();
    ZcBrMeshEntity(const ZcBrMeshEntity&);
    ZcBrMeshEntity&     operator =      (const ZcBrMeshEntity&);

    ZcBrImpMeshEntity*	mpImp;
};


#endif

