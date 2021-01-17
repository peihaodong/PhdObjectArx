

#ifndef   _ZXREFLOCK_H
#define   _ZXREFLOCK_H

#include "zrxnames.h"
#include "zdbidar.h"
#pragma pack (push, 8)

class ZcDbDatabase;
class ZcDbIdMapping;
class ZcDwgFileHandle;

class ZcEdXrefFileLock
{
public:
     ZcEdXrefFileLock();
    ~ZcEdXrefFileLock();

    Zcad::ErrorStatus lockFile(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus releaseFile(
                        int& retstatus,
                        bool bSkipSaveback = false,
                        bool bReload = true);

    Zcad::ErrorStatus consistencyCheck(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid,
                         ZcDbObjectIdArray& outofSyncBTRids);

    Zcad::ErrorStatus consistencyCheck(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus consistencyChecklocal(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus xloadctlType(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    int               getlockxloadctlType() const { return mXldctltype; }

    const ZcDbObjectIdArray& getoutofSyncIdArray() const { return mXBTRidArray; }

    Zcad::ErrorStatus reloadFile(
                         int& retstatus,
                         const ZcDbObjectIdArray& BTRids,
                         const int xldctltype = -1);

    Zcad::ErrorStatus reloadFile(
                         int& retstatus,
                         const int xldctltype = -1);

    void              setInternalTNmgmt(bool bTNmgmt);

private:
    ZcDwgFileHandle*    mdwgfile;
    ZcDbDatabase*       mpXDB;
    ZcDbDatabase*       mpXDBlockFile;
    int                 mXldctltype;
    ZcDbObjectId        mXBTRid;
    ZcDbObjectIdArray   mXBTRidArray;
    bool                mbIntTNmgmt;

};

#pragma pack (pop)
#endif  
