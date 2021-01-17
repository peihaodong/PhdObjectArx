
#ifndef ZCDB_OBJECTCONTEXTMANAGER_H
#define ZCDB_OBJECTCONTEXTMANAGER_H

#pragma once

#include "zacdb.h"
#include "zdbmain.h"
#include "zAcString.h"

class ZcDbObjectContextCollection;
class ZcDbObjectContext;
class ZcDbImpObjectContextManager;

#pragma pack (push, 8)

class ZcDbObjectContextManager: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectContextManager);
    ZcDbObjectContextManager();
    virtual ~ZcDbObjectContextManager();
    Zcad::ErrorStatus registerContextCollection(
                                  const ZcString&              collectionName,
                                  ZcDbObjectContextCollection* pCollection);
    Zcad::ErrorStatus unregisterContextCollection(
                                  const ZcString& collectionName);
    ZcDbObjectContextCollection* const contextCollection(
                                  const ZcString& collectionName) const;

private:
    ZcDbImpObjectContextManager* mpImp;

    friend class ZcDbContextDataSubManager;
};

#pragma pack (pop)

#endif
