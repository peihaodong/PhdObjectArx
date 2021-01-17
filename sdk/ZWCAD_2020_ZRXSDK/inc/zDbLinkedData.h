

#pragma once

#include "zAcValue.h"
#include "zDbDataLink.h"

class ZcDbLinkedData : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinkedData);

    ZCDB_PORT ZcDbLinkedData(void);
    ZCDB_PORT virtual ~ZcDbLinkedData(void);

    ZCDB_PORT virtual Zcad::ErrorStatus clear(void);
    ZCDB_PORT virtual bool isEmpty          (void) const;

    ZCDB_PORT virtual const ZTCHAR* name     (void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setName(const ZTCHAR* pszName);
    ZCDB_PORT virtual const ZTCHAR* description(void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setDescription(const ZTCHAR* pszDescription);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};

typedef ZcArray<ZcDbLinkedData*> ZcDbDataArray;
