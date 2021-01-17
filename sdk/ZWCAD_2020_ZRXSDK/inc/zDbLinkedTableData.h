

#pragma once

#include "zDbLinkedData.h"
#include "zDbTableIterator.h"
#include "zAcCell.h"

class ZcDbLinkedTableData : public ZcDbLinkedData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinkedTableData);

    ZCDB_PORT ZcDbLinkedTableData(void);
    ZCDB_PORT virtual ~ZcDbLinkedTableData(void);

    ZCDB_PORT virtual Zcad::ErrorStatus clear(void);
    ZCDB_PORT virtual Zcad::ErrorStatus copyFrom(const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption);
    ZCDB_PORT virtual Zcad::ErrorStatus copyFrom(const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption, 
                                             const ZcCellRange& srcRange, 
                                             const ZcCellRange& targetRange,
                                             ZcCellRange* pNewTargetRange);
    ZCDB_PORT ZcDbTableIterator* getIterator(void) const;
    ZCDB_PORT ZcDbTableIterator* getIterator(const ZcCellRange* pRange, 
                                             ZcDb::TableIteratorOption nOption) const;

    ZCDB_PORT virtual Zcad::ErrorStatus setSize(int nRows, int nCols);
    ZCDB_PORT virtual int numColumns        (void) const;
    ZCDB_PORT virtual const ZTCHAR* getColumnName(int nIndex) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setColumnName(int nIndex, 
                                             const ZTCHAR* pszName);
    ZCDB_PORT virtual int appendColumn      (int nNumCols);
    ZCDB_PORT virtual int insertColumn      (int nIndex, 
                                             int nNumCols);
    ZCDB_PORT virtual Zcad::ErrorStatus deleteColumn(int nIndex, 
                                             int nNumColsToDelete);

    ZCDB_PORT virtual int numRows           (void) const;
    ZCDB_PORT virtual bool canInsert        (int nIndex, 
                                             bool bRow) const;
    ZCDB_PORT virtual int appendRow         (int nNumRows);
    ZCDB_PORT virtual int insertRow         (int nIndex, 
                                             int nNumRows);
    ZCDB_PORT virtual bool canDelete        (int nIndex, 
                                             int nCount, 
                                             bool bRow) const;
    ZCDB_PORT virtual Zcad::ErrorStatus deleteRow(int nIndex, 
                                             int nNumRowsToDelete);

    ZCDB_PORT virtual bool isContentEditable(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDb::CellState cellState(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setCellState(int nRow, 
                                             int nCol, 
                                             ZcDb::CellState nCellState);
    ZCDB_PORT virtual ZcString getToolTip   (int nRow,
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setToolTip(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszToolTip);
    ZCDB_PORT virtual int getCustomData     (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setCustomData(int nRow, 
                                             int nCol, 
                                             int nData);
    ZCDB_PORT virtual Zcad::ErrorStatus getCustomData(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             ZcValue* pData) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setCustomData(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             const ZcValue* pData);
    ZCDB_PORT virtual bool isLinked         (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDbObjectId getDataLink(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getDataLink(int nRow, 
                                             int nCol, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT virtual int getDataLink       (const ZcCellRange* pRange, 
                                             ZcDbObjectIdArray& dataLinkIds) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setDataLink(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    ZCDB_PORT virtual Zcad::ErrorStatus setDataLink(const ZcCellRange& range, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    ZCDB_PORT virtual ZcCellRange getDataLinkRange(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus removeDataLink(int nRow, 
                                             int nCol);
    ZCDB_PORT virtual Zcad::ErrorStatus removeDataLink(void);
    ZCDB_PORT virtual Zcad::ErrorStatus updateDataLink(int nRow,
                                             int nCol, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    ZCDB_PORT virtual Zcad::ErrorStatus updateDataLink(ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

    ZCDB_PORT virtual int numContents       (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual int createContent     (int nRow, 
                                             int nCol, 
                                             int nIndex);
    ZCDB_PORT virtual Zcad::ErrorStatus moveContent(int nRow, 
                                             int nCol, 
                                             int nFromIndex, 
                                             int nToIndex);
    ZCDB_PORT virtual Zcad::ErrorStatus deleteContent(int nRow, 
                                             int nCol, 
                                             int nContent);
    ZCDB_PORT virtual Zcad::ErrorStatus deleteContent(int nRow, 
                                             int nCol);
    ZCDB_PORT virtual Zcad::ErrorStatus deleteContent(const ZcCellRange& range);

    ZCDB_PORT virtual ZcDb::CellContentType contentType(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDb::CellContentType contentType(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getDataType(int nRow, 
                                             int nCol, 
                                             ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getDataType(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setDataType(int nRow, 
                                             int nCol, 
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    ZCDB_PORT virtual Zcad::ErrorStatus setDataType(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    ZCDB_PORT virtual ZcString dataFormat   (int nRow,
                                             int nCol) const;
    ZCDB_PORT virtual ZcString dataFormat   (int nRow,
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setDataFormat(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszFormat);
    ZCDB_PORT virtual Zcad::ErrorStatus setDataFormat(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZTCHAR* pszFormat);
    ZCDB_PORT virtual Zcad::ErrorStatus getValue(int nRow, 
                                             int nCol, 
                                             ZcValue& value) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             ZcValue::FormatOption nOption,
                                             ZcValue& value) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             const ZcValue& value);
    ZCDB_PORT virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcValue& value);
    ZCDB_PORT virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcValue& value,
                                             ZcValue::ParseOption nOption);
    ZCDB_PORT virtual ZcString getText      (int nRow,
                                             int nCol) const;
    ZCDB_PORT virtual ZcString getText      (int nRow,
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual ZcString getText      (int nRow,
                                             int nCol, 
                                             int nContent, 
                                             ZcValue::FormatOption nOption) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setText(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszText);
    ZCDB_PORT virtual Zcad::ErrorStatus setText(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZTCHAR* pszText);
    ZCDB_PORT virtual bool hasFormula       (int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual ZcString getFormula   (int nRow,
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setFormula(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZTCHAR* pszFormula);
    ZCDB_PORT virtual ZcDbObjectId getFieldId(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDbObjectId getFieldId(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idField);
    ZCDB_PORT virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idField);
    ZCDB_PORT virtual Zcad::ErrorStatus getField(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcDbField*& pField,
                                             ZcDb::OpenMode mode) const;
    ZCDB_PORT virtual ZcDbObjectId getBlockTableRecordId(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDbObjectId getBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idBTR);
    ZCDB_PORT virtual Zcad::ErrorStatus setBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idBTR);
    ZCDB_PORT virtual ZcString getBlockAttributeValue(int nRow,
                                             int nCol, 
                                             const ZcDbObjectId& idAttDef) const;
    ZCDB_PORT virtual ZcString getBlockAttributeValue(int nRow,
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idAttDef) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setBlockAttributeValue(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idAttDef, 
                                             const ZTCHAR* pszAttValue);
    ZCDB_PORT virtual Zcad::ErrorStatus setBlockAttributeValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idAttDef, 
                                             const ZTCHAR* pszAttValue);

    ZCDB_PORT virtual Zcad::ErrorStatus evaluateFormula(void);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};
