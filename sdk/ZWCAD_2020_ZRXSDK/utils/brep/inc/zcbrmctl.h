#ifndef ZC_BRMCTL_H
#define ZC_BRMCTL_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"


// forward class declarations
class ZcBrImpMeshControl;


class DllImpExp ZcBrMeshControl : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMeshControl);
    virtual ~ZcBrMeshControl();

    // Equivalence                    
    ZSoft::Boolean      isEqualTo       (const ZcRxObject* other) const;
    
    // Queries & Initialisers
    ZcBr::ErrorStatus   setMaxSubdivisions(const ZSoft::UInt32& maxSubs = *(ZSoft::UInt32*)NULL);
	ZcBr::ErrorStatus   getMaxSubdivisions(ZSoft::UInt32& maxSubs) const;
    ZcBr::ErrorStatus   setMaxNodeSpacing(const double& maxNodeSpace = *(double*)NULL);
    ZcBr::ErrorStatus   getMaxNodeSpacing(double& maxNodeSpace) const;
    ZcBr::ErrorStatus   setAngTol		(const double& angTol = *(double*)NULL);
    ZcBr::ErrorStatus   getAngTol		(double& angTol) const;
    ZcBr::ErrorStatus   setDistTol		(const double& distTol = *(double*)NULL);
    ZcBr::ErrorStatus   getDistTol		(double& distTol) const;

protected:
    ZcBrMeshControl();
    ZcBrMeshControl(const ZcBrMeshControl& src);
    ZcBrMeshControl&	operator =      (const ZcBrMeshControl& src);

    ZcBrImpMeshControl*	mpImp;
};


#endif