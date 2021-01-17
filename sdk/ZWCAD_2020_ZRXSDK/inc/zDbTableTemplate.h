

#pragma once

#include "zDbTableContent.h"

class ZcDbTable;
class ZcDbTableTemplate : public ZcDbTableContent
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableTemplate);

    ZcDbTableTemplate(void);
    ZcDbTableTemplate(const ZcDbTable* pTable, ZcDb::TableCopyOption nCopyOption);
    virtual ~ZcDbTableTemplate(void);

    virtual Zcad::ErrorStatus capture       (const ZcDbTable* pTable, ZcDb::TableCopyOption nCopyOption);
    virtual Zcad::ErrorStatus createTable   (ZcDbTable*& pTable, ZcDb::TableCopyOption nCopyOption);

    virtual Zcad::ErrorStatus dwgInFields   (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields  (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields   (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields  (ZcDbDxfFiler* pFiler) const;
};
