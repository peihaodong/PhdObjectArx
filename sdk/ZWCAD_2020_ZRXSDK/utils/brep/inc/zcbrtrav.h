#ifndef ZC_BRTRAV_H
#define ZC_BRTRAV_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"


// forward class declarations
class ZcBrTraverserImp;
class ZcBrTraverserData;


class DllImpExp ZcBrTraverser : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrTraverser);
    virtual ~ZcBrTraverser();
    
    // Equivalence                    
    ZSoft::Boolean      isEqualTo       (const ZcRxObject* other) const;
                        
    // Queries & Initialisers
    ZSoft::Boolean      isNull          () const;

    // Topological traversal
    ZSoft::Boolean      done            () const;
    ZcBr::ErrorStatus   next            ();
    ZcBr::ErrorStatus   restart         ();

	// Validation
	ZcBr::ErrorStatus	setValidationLevel(const ZcBr::ValidationLevel& = *(ZcBr::ValidationLevel*)NULL);
	ZcBr::ErrorStatus	getValidationLevel(ZcBr::ValidationLevel& validationLevel) const;
	ZSoft::Boolean		brepChanged		() const;

    // Queries & Initialisers
	// (Note: obsolete function)
	ZcBr::ErrorStatus	set				(ZcBrTraverserData* traverserData);
	ZcBr::ErrorStatus	get				(ZcBrTraverserData*& traverserData) const;

protected:
    ZcBrTraverser();
    ZcBrTraverser(const ZcBrTraverser& src);
    ZcBrTraverser&      operator =      (const ZcBrTraverser& src);

    ZcBrTraverserImp*   mpImp;
};


#endif

