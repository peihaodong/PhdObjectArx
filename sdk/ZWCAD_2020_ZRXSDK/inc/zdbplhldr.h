

#ifndef ZD_DBPLACEHOLDER_H
#define ZD_DBPLACEHOLDER_H

#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbPlaceHolder : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPlaceHolder);
    ZcDbPlaceHolder() {}
    virtual ~ZcDbPlaceHolder();

    virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
					  ZcDbObject*& pClonedObject,
					  ZcDbIdMapping& idMap,
					  ZSoft::Boolean isPrimary
					  = ZSoft::kTrue) const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
};

#pragma pack (pop)

#endif

