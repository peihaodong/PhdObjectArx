#ifndef ZC_BRNODE_H
#define ZC_BRNODE_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zgegbl.h"
#include "zcbrgbl.h"
#include "zcbrment.h"


// forward class declarations
class ZcGePoint3d;
class ZcBrMeshEntity;
class ZcBrNodeData;


class DllImpExp ZcBrNode : public ZcBrMeshEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrNode);
    ZcBrNode();
    ZcBrNode(const ZcBrNode& src);
    ~ZcBrNode();
    
    // Assignment operator
    ZcBrNode&           operator =      (const ZcBrNode& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(ZcBrNodeData* nodeData);
    ZcBr::ErrorStatus   get				(ZcBrNodeData*& nodeData) const;

    // Geometry
    ZcBr::ErrorStatus   getPoint        (ZcGePoint3d& point) const;
};


#endif

