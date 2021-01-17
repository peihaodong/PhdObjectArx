

#pragma once

#include "zDbFormattedTableData.h"

class ZcDbTableContent : public ZcDbFormattedTableData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableContent);

    ZCDB_PORT ZcDbTableContent(void);
    ZCDB_PORT virtual ~ZcDbTableContent(void);

    ZCDB_PORT virtual ZcDbObjectId tableStyleId(void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setTableStyleId(const ZcDbObjectId& idTableStyle);
    ZCDB_PORT virtual const ZTCHAR* cellStyle(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setCellStyle(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszCellStyle);
    ZCDB_PORT virtual double rowHeight      (int nRow) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setRowHeight(int nRow, 
                                             double fWidth);
    ZCDB_PORT virtual double columnWidth    (int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setColumnWidth(int nCol, 
                                             double fWidth);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};
