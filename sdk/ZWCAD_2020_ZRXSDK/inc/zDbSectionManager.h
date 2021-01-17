
#pragma once

#include "zAdAChar.h"
#include "zDbSection.h"

class ZcDbSection;
class ZcDbSectionManagerIterator;
class ZcDbImpSectionManager;

class ZcDbSectionManager : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSectionManager);

    ZCDB_PORT Zcad::ErrorStatus getSection  (const ZTCHAR* pszName,
                                             ZcDbObjectId& id) const;
    ZCDB_PORT Zcad::ErrorStatus getSection  (const ZTCHAR* pszName,
                                             ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT Zcad::ErrorStatus getLiveSection(ZcDbObjectId& id) const;
    ZCDB_PORT Zcad::ErrorStatus getLiveSection(ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT int   numSections             (void) const;
    ZCDB_PORT Zcad::ErrorStatus newIterator (ZcDbSectionManagerIterator*& pIterator) const;
    ZCDB_PORT Zcad::ErrorStatus getUniqueSectionName(const ZTCHAR* pszBaseName,
                                             ZTCHAR*& pszUniqueName) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getClassID  (CLSID* pClsid) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

public:

    ZCDB_PORT ZcDbSectionManager(void);
    ZCDB_PORT ~ZcDbSectionManager(void);
};

class ZcDbSectionManagerIterator
{
public:
    ZCDB_PORT virtual ~ZcDbSectionManagerIterator(void);

    ZCDB_PORT void  start                   (void);
    ZCDB_PORT void  step                    (void);
    ZCDB_PORT bool  done                    (void) const;

    ZCDB_PORT ZcDbObjectId      getSection  (void) const;
    ZCDB_PORT Zcad::ErrorStatus getSection  (ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode openMode) const;

protected:
    ZCDB_PORT ZcDbSectionManagerIterator(ZcDbSectionManager* pMgr);

protected:
    void            *   mpImpObj;

    friend class ZcDbImpSectionManager;
};
