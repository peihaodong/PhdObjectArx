

#ifndef ZD_DBDICTDFLT_H
#define ZD_DBDICTDFLT_H

#include "zdbdict.h"

#pragma pack(push, 8)

class ZcDbImpDictionaryWithDefault;

class ZcDbDictionaryWithDefault : public ZcDbDictionary
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDictionaryWithDefault);
    ZcDbDictionaryWithDefault();
    virtual ~ZcDbDictionaryWithDefault();

    Zcad::ErrorStatus setDefaultId(const ZcDbObjectId& newId);
    ZcDbObjectId defaultId() const;

    virtual Zcad::ErrorStatus getObjectBirthVersion(
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);
};

#pragma pack(pop)

#endif
