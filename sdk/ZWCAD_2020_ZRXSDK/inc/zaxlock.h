

#ifndef _ZAXLOCK_H
#define _ZAXLOCK_H

#include "zacadstrc.h"

#pragma pack (push, 8)

class ZcDbDatabase;
class ZcDbObjectId;

class ZcAxDocLock
{
public:

    enum DocLockType
    {
        kNormal         = 0,    
        kCurDocSwitch   = 1

    };

    ZcAxDocLock();    
    ZcAxDocLock(const ZcDbObjectId& objectId, DocLockType = kNormal);
    ZcAxDocLock(ZcDbDatabase * pDatabase, DocLockType = kNormal);

    ~ZcAxDocLock();

    Zcad::ErrorStatus lockStatus() const;

private:

    void lockDocument(ZcDbDatabase* pDatabase, DocLockType lockType = kNormal);
    void initialize();

    Zcad::ErrorStatus   m_lockStatus;
    void*               m_pDocToUnlock;
    void*               m_pCurDocToRestore;
    bool                m_restoreActivation;
};

#pragma pack (pop)

#endif      
