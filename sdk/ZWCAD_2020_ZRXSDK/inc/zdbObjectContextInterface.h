
#pragma once
#pragma pack (push, 8)

#include "zacdb.h"
#include "zdbmain.h"

class ZcDbObjectContext;

class ZcDbObjectContextInterface : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbObjectContextInterface);
    virtual bool supportsCollection (
                            const ZcDbObject* pObject,
                            const ZcString&   collectionName ) const = 0;
    virtual bool hasContext ( const ZcDbObject*        pObject,
                              const ZcDbObjectContext& context ) const = 0;
    virtual Zcad::ErrorStatus addContext (
                                ZcDbObject*              pObject,
                                const ZcDbObjectContext& context ) const = 0;
    virtual Zcad::ErrorStatus removeContext (
                                ZcDbObject*              pObject,
                                const ZcDbObjectContext& context ) const = 0;
};

#pragma pack (pop)

