#ifndef ZC_BRM2DCTL_H
#define ZC_BRM2DCTL_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrmctl.h"


// forward class declarations
class ZcBrMeshControl;


class DllImpExp ZcBrMesh2dControl : public ZcBrMeshControl
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMesh2dControl);
    ZcBrMesh2dControl();
    ZcBrMesh2dControl(const ZcBrMesh2dControl& src);
    ~ZcBrMesh2dControl();
    
    // Assignment operator
    ZcBrMesh2dControl&	operator =      (const ZcBrMesh2dControl& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   setMaxAspectRatio(const double& maxAspectRatio = *(double*)NULL);
    ZcBr::ErrorStatus   getMaxAspectRatio(double& maxAspectRatio) const;
    ZcBr::ErrorStatus   setElementShape	(const ZcBr::Element2dShape& elementShape = *(ZcBr::Element2dShape*)NULL);
    ZcBr::ErrorStatus   getElementShape	(ZcBr::Element2dShape& elementShape) const;
    ZcBr::ErrorStatus   setMinSubdivisionsInU(const ZSoft::UInt32& minSubsU = *(ZSoft::UInt32*)NULL);
	ZcBr::ErrorStatus   getMinSubdivisionsInU(ZSoft::UInt32& minSubsU) const;
    ZcBr::ErrorStatus   setMinSubdivisionsInV(const ZSoft::UInt32& minSubsV = *(ZSoft::UInt32*)NULL);
	ZcBr::ErrorStatus   getMinSubdivisionsInV(ZSoft::UInt32& minSubsV) const;
};


#endif