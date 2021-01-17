

#ifndef _ZSUMMINFO_H_
#define _ZSUMMINFO_H_

#include "zadesk.h"
#include "zeoktest.h"

#pragma pack (push, 8)

class ZSOFT_NO_VTABLE ZcDbDatabaseSummaryInfo : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabaseSummaryInfo);

    virtual Zcad::ErrorStatus getTitle(ZTCHAR*& title) const = 0;
    virtual Zcad::ErrorStatus setTitle(const ZTCHAR* title) = 0;

    virtual Zcad::ErrorStatus getSubject(ZTCHAR*& subject) const = 0;
    virtual Zcad::ErrorStatus setSubject(const ZTCHAR* subject) = 0;

    virtual Zcad::ErrorStatus getAuthor(ZTCHAR*& author) const = 0;
    virtual Zcad::ErrorStatus setAuthor(const ZTCHAR* author) = 0;

    virtual Zcad::ErrorStatus getKeywords(ZTCHAR*& keywordlist) const = 0;
    virtual Zcad::ErrorStatus setKeywords(const ZTCHAR* keywordlist) = 0;

    virtual Zcad::ErrorStatus getComments(ZTCHAR*& comments) const = 0;
    virtual Zcad::ErrorStatus setComments(const ZTCHAR* comments) = 0;

    virtual Zcad::ErrorStatus getLastSavedBy(ZTCHAR*& lastSavedBy) const = 0;
    virtual Zcad::ErrorStatus setLastSavedBy(const ZTCHAR* lastSavedBy) = 0;

    virtual Zcad::ErrorStatus getRevisionNumber(ZTCHAR*& revisionNumber) const = 0;
    virtual Zcad::ErrorStatus setRevisionNumber(const ZTCHAR* revisionNumber) = 0;

    virtual Zcad::ErrorStatus getHyperlinkBase(ZTCHAR*& HyperlinkBase) const = 0;
    virtual Zcad::ErrorStatus setHyperlinkBase(const ZTCHAR* HyperlinkBase) = 0;

    virtual int numCustomInfo() const = 0;

    virtual Zcad::ErrorStatus addCustomSummaryInfo(const ZTCHAR* key, const ZTCHAR* value ) = 0;

    virtual Zcad::ErrorStatus deleteCustomSummaryInfo(const int index) = 0;
    virtual Zcad::ErrorStatus deleteCustomSummaryInfo(const ZTCHAR* key) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(const int index, ZTCHAR*& key,
                               ZTCHAR *& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (const int index, const ZTCHAR* key,
                               const ZTCHAR *value ) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(const ZTCHAR *customInfoKey,
                               ZTCHAR *& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (const ZTCHAR *customInfoKey,
                               const ZTCHAR *value ) = 0;

    virtual ZcDbDatabase* database() const = 0; 
    virtual void setDatabase(ZcDbDatabase *pDb) = 0; 

    virtual ~ZcDbDatabaseSummaryInfo() {};
  protected:
    ZcDbDatabaseSummaryInfo();
};

Zcad::ErrorStatus ZSOFT_STDCALL zcdbGetSummaryInfo(
                                 ZcDbDatabase* pDb, 
                                 ZcDbDatabaseSummaryInfo*& pInfo);

Zcad::ErrorStatus ZSOFT_STDCALL zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo,
                                ZcDbDatabase *pDb);

inline Zcad::ErrorStatus zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo)
{
    return ::zcdbPutSummaryInfo(pInfo, pInfo->database());
}

class ZSOFT_NO_VTABLE ZcDbSummaryInfoReactor {
public:
    virtual void summaryInfoHasChanged(
                     const ZcDbDatabase* pDb, 
                     const ZcDbDatabaseSummaryInfo* pDbProp) {};
    virtual ~ZcDbSummaryInfoReactor() {};
};

class ZSOFT_NO_VTABLE ZcDbSummaryInfoManager {
public:
    virtual void  addReactor(ZcDbSummaryInfoReactor* pReact) = 0;
    virtual void  removeReactor(ZcDbSummaryInfoReactor* pReact) = 0;
};

ZcDbSummaryInfoManager* ZSOFT_STDCALL zcdbSummaryInfoManager();

inline void initZcDbSummaryInfoManager() {};
inline void deleteZcDbSummaryInfoManager() {};

#pragma pack (pop)
#endif 


