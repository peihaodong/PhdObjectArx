

#pragma once

#include "zAcString.h"
#include "zAcValue.h"

class ZcValue;
class ZcDbLinkedData;
class ZcDbDataLink;
class ZcDbDataLinkManager;
class ZcDbImpDataLinkManager;
class ZcDbDataAdapter;
class ZcTableSystemInternals;


#define ZCDB_DATA_ADAPTER_EXCEL         ZCRX_T("AcExcel")

class ZcDbDataLink : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDataLink);

    ZCDB_PORT ZcDbDataLink(void);
    ZCDB_PORT virtual ~ZcDbDataLink(void);

    ZCDB_PORT ZcString name                 (void) const;
    ZCDB_PORT Zcad::ErrorStatus setName     (const ZTCHAR* pszName);
    ZCDB_PORT const ZTCHAR* description      (void) const;
    ZCDB_PORT Zcad::ErrorStatus setDescription(const ZTCHAR* pszDescription);
    ZCDB_PORT ZcString getToolTip           (void) const;
    ZCDB_PORT Zcad::ErrorStatus setToolTip  (const ZTCHAR* pszToolTip);
    ZCDB_PORT const ZTCHAR* dataAdapterId    (void) const;
    ZCDB_PORT Zcad::ErrorStatus setDataAdapterId(const ZTCHAR* pszAdapterId);
    ZCDB_PORT const ZTCHAR* connectionString (void) const;
    ZCDB_PORT Zcad::ErrorStatus setConnectionString(const ZTCHAR* pszConnectionString);
    ZCDB_PORT ZcDb::DataLinkOption option   (void) const;
    ZCDB_PORT Zcad::ErrorStatus setOption   (ZcDb::DataLinkOption nOption);
    ZCDB_PORT int   updateOption            (void) const;
    ZCDB_PORT Zcad::ErrorStatus setUpdateOption(int nOption);
    ZCDB_PORT Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);
    ZCDB_PORT Zcad::ErrorStatus getUpdateStatus(ZcDb::UpdateDirection* pDir, 
                                             SYSTEMTIME* pTime, 
                                             ZcString* pErrMessage) const;
    ZCDB_PORT Zcad::ErrorStatus setUpdateStatus(const ZTCHAR* pszErrMessage);
    ZCDB_PORT bool  isValid                 (void) const;
    ZCDB_PORT int   getTargets              (ZcDbObjectIdArray& targetIds) const;
    ZCDB_PORT Zcad::ErrorStatus getSourceFiles(ZcDb::DataLinkGetSourceContext nContext, 
                                             ZcStringArray& files) const;
    ZCDB_PORT Zcad::ErrorStatus repathSourceFiles(LPCTSTR pszBasePath, 
                                             ZcDb::PathOption nOption);
    ZCDB_PORT Zcad::ErrorStatus getCustomData(const ZTCHAR* pszKey, 
                                             ZcValue* pData) const;
    ZCDB_PORT Zcad::ErrorStatus setCustomData(const ZTCHAR* pszKey, 
                                             const ZcValue* pData);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};

typedef ZcArray<ZcDbDataLink*> ZcDbDataLinkArray;

class ZcDbDataLinkManager : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDataLinkManager);

    ZCDB_PORT virtual ~ZcDbDataLinkManager(void);

    ZCDB_PORT Zcad::ErrorStatus createDataLink(const ZTCHAR* pszAdapterId, 
                                             const ZTCHAR* pszName, 
                                             const ZTCHAR* pszDescription, 
                                             const ZTCHAR* pszConnectionString, 
                                             ZcDbObjectId& idDataLink);
    ZCDB_PORT Zcad::ErrorStatus getDataLink (const ZTCHAR* pszName, 
                                             ZcDbObjectId& idDataLink) const;
    ZCDB_PORT Zcad::ErrorStatus getDataLink (const ZTCHAR* pszName, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT int   dataLinkCount           (void) const;
    ZCDB_PORT int   getDataLink             (ZcDbObjectIdArray& dataLinks) const;
    ZCDB_PORT Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink);
    ZCDB_PORT Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink, 
                                             ZcDbObjectId& idDataLink);
    Zcad::ErrorStatus removeDataLink        (const ZTCHAR* pszKey, 
                                             ZcDbObjectId& idDataLink);
    ZCDB_PORT Zcad::ErrorStatus removeDataLink(const ZcDbObjectId& idDataLink);

    ZCDB_PORT Zcad::ErrorStatus update      (const ZcDbObjectIdArray& dataIds, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    ZCDB_PORT Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

protected:
    ZCDB_PORT ZcDbDataLinkManager(void);

private:
    void        *   mpImpObj;
    friend class ZcTableSystemInternals;
    friend class ZcDbImpDataLinkManager;
};
