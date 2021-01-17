#pragma once

#pragma warning( disable: 4275 4251 )

#include "zacarray.h"
#include "zgepnt3d.h"

#include "zdbmain.h"
#include "zdbents.h"

#pragma pack (push, 8)

class ZcDbImpDataCell;
class ZcDbImpDataColumn;

class ZcDbDataCell : public ZcRxObject
{
public:
    enum CellType {
        kUnknown = 0,
        kInteger,
        kDouble,
        kCharPtr,
        kPoint,
        kObjectId,
        kHardOwnerId,
        kSoftOwnerId,
        kHardPtrId,
        kSoftPtrId,
        kBool,
        kVector
    };

    ZcDbDataCell();
    ZcDbDataCell(const ZcDbDataCell& rCell);

    ZcDbDataCell(bool b);
    ZcDbDataCell(int i);
    ZcDbDataCell(double d);
    ZcDbDataCell(const ZTCHAR * pChar);
    ZcDbDataCell(const ZcGePoint3d& point);
    ZcDbDataCell(const ZcGeVector3d& vec);
    ZcDbDataCell(const ZcDbObjectId& id);
    ZcDbDataCell(const ZcDbHardOwnershipId& hoId);
    ZcDbDataCell(const ZcDbSoftOwnershipId& soId);
    ZcDbDataCell(const ZcDbHardPointerId&   hpId);
    ZcDbDataCell(const ZcDbSoftPointerId&   spId);

    virtual ~ZcDbDataCell();
    ZCRX_DECLARE_MEMBERS(ZcDbDataCell);

    virtual void init();

    virtual ZcDbDataCell& operator = (const ZcDbDataCell &cell);
    virtual ZcDbDataCell& operator = (bool b);
    virtual ZcDbDataCell& operator = (int i);
    virtual ZcDbDataCell& operator = (double d);
    virtual ZcDbDataCell& operator = (const ZTCHAR * pChar);
    virtual ZcDbDataCell& operator = (const ZcGePoint3d &pt);
    virtual ZcDbDataCell& operator = (const ZcGeVector3d &vec);
    virtual ZcDbDataCell& operator = (const ZcDbObjectId &id);
    virtual ZcDbDataCell& operator = (const ZcDbHardOwnershipId &hoId);
    virtual ZcDbDataCell& operator = (const ZcDbSoftOwnershipId &soId);
    virtual ZcDbDataCell& operator = (const ZcDbHardPointerId   &hpId);
    virtual ZcDbDataCell& operator = (const ZcDbSoftPointerId   &spId);

    virtual operator bool() const;
    virtual operator int() const;
    virtual operator double() const;
    virtual operator const ZTCHAR *() const;
    virtual operator ZcGePoint3d&()const;
    virtual operator ZcGeVector3d&()const;
    virtual operator ZcDbObjectId&() const;
    virtual operator ZcDbHardOwnershipId&() const;
    virtual operator ZcDbSoftOwnershipId&() const;
    virtual operator ZcDbHardPointerId&() const;
    virtual operator ZcDbSoftPointerId&() const;

    virtual bool operator == (const ZcDbDataCell &cell) const;
    virtual bool operator != (const ZcDbDataCell &cell) const;

    virtual ZcDbDataCell::CellType type() const;

private:
    friend class ZcDbSystemInternals;

    ZcDbImpDataCell* mpImpDataCell;
};

typedef ZcArray<ZcDbDataCell, ZcArrayObjectCopyReallocator<ZcDbDataCell> >
    ZcDbDataCellArray;

class ZcDbDataColumn : public ZcRxObject
{
public:
    ZcDbDataColumn();
    ZcDbDataColumn(const ZcDbDataColumn& rCol);
    ZcDbDataColumn(const ZcDbDataCell::CellType type,
        const ZTCHAR * pColName = NULL);

    virtual ~ZcDbDataColumn();
    ZCRX_DECLARE_MEMBERS(ZcDbDataColumn);

    virtual ZSoft::UInt32 physicalLength() const;
    virtual ZSoft::UInt32 growLength() const;
    virtual Zcad::ErrorStatus setPhysicalLength(ZSoft::UInt32 n);
    virtual Zcad::ErrorStatus setGrowLength(ZSoft::UInt32 n);

    virtual ZcDbDataColumn& operator = (const ZcDbDataColumn& col);

    virtual Zcad::ErrorStatus setColumnType(ZcDbDataCell::CellType type);
    virtual ZcDbDataCell::CellType columnType() const;
    virtual Zcad::ErrorStatus setColumnName(const ZTCHAR * pName);
    virtual const ZTCHAR * columnName() const;

    virtual Zcad::ErrorStatus getCellAt(ZSoft::UInt32 index, ZcDbDataCell& outCell) const;
    virtual Zcad::ErrorStatus setCellAt(ZSoft::UInt32 index, const ZcDbDataCell& cell);
    virtual Zcad::ErrorStatus appendCell(const ZcDbDataCell& cell);
    virtual Zcad::ErrorStatus insertCellAt(ZSoft::UInt32 index, const ZcDbDataCell& cell);
    virtual Zcad::ErrorStatus removeCellAt(ZSoft::UInt32 index);
    virtual Zcad::ErrorStatus getIndexAtCell(const ZcDbDataCell& cell, ZSoft::UInt32& index) const;

    virtual ZSoft::UInt32 numCells() const;

private:
    friend class ZcDbSystemInternals;
    friend class ZcDbImpDataColumn;
    ZcDbImpDataColumn* mpImpDataColumn;
};

class ZcDbDataTable : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDataTable);
    
    ZcDbDataTable();
    virtual ~ZcDbDataTable(); 
   
    virtual ZcDbDataTable& operator = (const ZcDbDataTable& table);

    virtual ZSoft::UInt32 numColumns() const;
    virtual ZSoft::UInt32 numRows() const;

    virtual Zcad::ErrorStatus setNumRowsPhysicalSize(ZSoft::UInt32 n);
    virtual Zcad::ErrorStatus setNumRowsGrowSize(ZSoft::UInt32 n);
    virtual ZSoft::UInt32 numRowsPhysicalSize() const;
    virtual ZSoft::UInt32 numRowsGrowSize() const;
    virtual Zcad::ErrorStatus setNumColsPhysicalSize(ZSoft::UInt32 n);
    virtual Zcad::ErrorStatus setNumColsGrowSize(ZSoft::UInt32 n);
    virtual ZSoft::UInt32 numColsPhysicalSize() const;
    virtual ZSoft::UInt32 numColsGrowSize() const;

    virtual const ZTCHAR * tableName() const;
    virtual Zcad::ErrorStatus setTableName(const ZTCHAR * pName);

    virtual Zcad::ErrorStatus getColumnAt(ZSoft::UInt32 index,
        const ZcDbDataColumn*& pCol) const;
    virtual Zcad::ErrorStatus getColumnNameAt(ZSoft::UInt32 index,
        ZTCHAR *& pName) const;
    virtual Zcad::ErrorStatus getColumnTypeAt(ZSoft::UInt32 index, 
        ZcDbDataCell::CellType& type) const;
    virtual Zcad::ErrorStatus getColumnIndexAtName(
        const ZTCHAR * pName, ZSoft::UInt32& index) const;

    virtual Zcad::ErrorStatus appendColumn(
        ZcDbDataCell::CellType type, const ZTCHAR * pColName = NULL);
    virtual Zcad::ErrorStatus insertColumnAt(ZSoft::UInt32 index, 
        ZcDbDataCell::CellType type, const ZTCHAR * pColName = NULL);
    virtual Zcad::ErrorStatus removeColumnAt(ZSoft::UInt32 index);

    virtual Zcad::ErrorStatus getRowAt(ZSoft::UInt32 index, 
        ZcDbDataCellArray& outRow) const;
    virtual Zcad::ErrorStatus setRowAt(ZSoft::UInt32 index,
        const ZcDbDataCellArray& row, bool bValidate = true);
    virtual Zcad::ErrorStatus appendRow(
        const ZcDbDataCellArray& row, bool bValidate = true);

    virtual Zcad::ErrorStatus insertRowAt(ZSoft::UInt32 index,
        const ZcDbDataCellArray& row, bool bValidate = true);
    virtual Zcad::ErrorStatus removeRowAt(ZSoft::UInt32 index);

    virtual Zcad::ErrorStatus getCellAt(ZSoft::UInt32 row, ZSoft::UInt32 col,
        ZcDbDataCell& outCell) const;
    virtual Zcad::ErrorStatus setCellAt(ZSoft::UInt32 row, ZSoft::UInt32 col,
        const ZcDbDataCell& cell);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);
};

#pragma pack (pop)
