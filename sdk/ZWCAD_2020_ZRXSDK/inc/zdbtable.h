
#pragma once

#include "zdbmain.h"
#include "zdbents.h"

#include "zAcField.h"
#include "zDbLinkedTableData.h"
#include "zDbFormattedTableData.h"

#pragma pack(push, 8)

class ZcDbTableIterator;
class ZcDbTableTemplate;

typedef ZcDbFullSubentPathArray ZcSubentPathArray;

class ZcDbTable: public ZcDbBlockReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTable);

    enum TableStyleOverrides {

        kTitleSuppressed             = 1,
        kHeaderSuppressed            = 2,
        kFlowDirection               = 3,
        kHorzCellMargin              = 4,
        kVertCellMargin              = 5,
        kTitleRowColor               = 6,
        kHeaderRowColor              = 7,
        kDataRowColor                = 8,
        kTitleRowFillNone            = 9,
        kHeaderRowFillNone           = 10,
        kDataRowFillNone             = 11,
        kTitleRowFillColor           = 12,
        kHeaderRowFillColor          = 13,
        kDataRowFillColor            = 14,
        kTitleRowAlignment           = 15,
        kHeaderRowAlignment          = 16,
        kDataRowAlignment            = 17,
        kTitleRowTextStyle           = 18,
        kHeaderRowTextStyle          = 19,
        kDataRowTextStyle            = 20,
        kTitleRowTextHeight          = 21,
        kHeaderRowTextHeight         = 22,
        kDataRowTextHeight           = 23,

        kTitleRowDataType            = 24,
        kHeaderRowDataType           = 25,
        kDataRowDataType             = 26,

        kTitleHorzTopColor           = 40,
        kTitleHorzInsideColor        = 41,
        kTitleHorzBottomColor        = 42,
        kTitleVertLeftColor          = 43,
        kTitleVertInsideColor        = 44,
        kTitleVertRightColor         = 45,

        kHeaderHorzTopColor          = 46,
        kHeaderHorzInsideColor       = 47,
        kHeaderHorzBottomColor       = 48,
        kHeaderVertLeftColor         = 49,
        kHeaderVertInsideColor       = 50,
        kHeaderVertRightColor        = 51,

        kDataHorzTopColor            = 52,
        kDataHorzInsideColor         = 53,
        kDataHorzBottomColor         = 54,
        kDataVertLeftColor           = 55,
        kDataVertInsideColor         = 56,
        kDataVertRightColor          = 57,

        kTitleHorzTopLineWeight      = 70,
        kTitleHorzInsideLineWeight   = 71,
        kTitleHorzBottomLineWeight   = 72,
        kTitleVertLeftLineWeight     = 73,
        kTitleVertInsideLineWeight   = 74,
        kTitleVertRightLineWeight    = 75,

        kHeaderHorzTopLineWeight     = 76,
        kHeaderHorzInsideLineWeight  = 77,
        kHeaderHorzBottomLineWeight  = 78,
        kHeaderVertLeftLineWeight    = 79,
        kHeaderVertInsideLineWeight  = 80,
        kHeaderVertRightLineWeight   = 81,

        kDataHorzTopLineWeight       = 82,
        kDataHorzInsideLineWeight    = 83,
        kDataHorzBottomLineWeight    = 84,
        kDataVertLeftLineWeight      = 85,
        kDataVertInsideLineWeight    = 86,
        kDataVertRightLineWeight     = 87,

        kTitleHorzTopVisibility      = 100,
        kTitleHorzInsideVisibility   = 101,
        kTitleHorzBottomVisibility   = 102,
        kTitleVertLeftVisibility     = 103,
        kTitleVertInsideVisibility   = 104,
        kTitleVertRightVisibility    = 105,

        kHeaderHorzTopVisibility     = 106,
        kHeaderHorzInsideVisibility  = 107,
        kHeaderHorzBottomVisibility  = 108,
        kHeaderVertLeftVisibility    = 109,
        kHeaderVertInsideVisibility  = 110,
        kHeaderVertRightVisibility   = 111,

        kDataHorzTopVisibility       = 112,
        kDataHorzInsideVisibility    = 113,
        kDataHorzBottomVisibility    = 114,
        kDataVertLeftVisibility      = 115,
        kDataVertInsideVisibility    = 116,
        kDataVertRightVisibility     = 117,

        kCellAlignment               = 130,
        kCellBackgroundFillNone      = 131,
        kCellBackgroundColor         = 132,
        kCellContentColor            = 133,
        kCellTextStyle               = 134,
        kCellTextHeight              = 135,
        kCellTopGridColor            = 136,
        kCellRightGridColor          = 137,
        kCellBottomGridColor         = 138,
        kCellLeftGridColor           = 139,
        kCellTopGridLineWeight       = 140,
        kCellRightGridLineWeight     = 141,
        kCellBottomGridLineWeight    = 142,
        kCellLeftGridLineWeight      = 143,
        kCellTopVisibility           = 144,
        kCellRightVisibility         = 145,
        kCellBottomVisibility        = 146,
        kCellLeftVisibility          = 147,
		
        kCellDataType                = 148,
		
    };

    ZcDbTable();
	
    ZcDbTable(const ZcDbLinkedTableData* pTable, ZcDb::TableCopyOption nCopyOption);
	
    virtual ~ZcDbTable();

    virtual ZcDbObjectId        tableStyle() const;
    virtual Zcad::ErrorStatus   setTableStyle(const ZcDbObjectId& id);

    virtual ZcGeVector3d        direction() const;
    virtual Zcad::ErrorStatus   setDirection(const ZcGeVector3d& horzVec);

    virtual ZSoft::UInt32       numRows() const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setNumRows(int nRows);

    virtual ZSoft::UInt32       numColumns() const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setNumColumns(int nCols);

    virtual double              width() const;
    virtual Zcad::ErrorStatus   setWidth(double width);

    virtual double              columnWidth(int col) const;
    virtual Zcad::ErrorStatus   setColumnWidth(int col, double width);
    virtual Zcad::ErrorStatus   setColumnWidth(double width);

    virtual double              height() const;
    virtual Zcad::ErrorStatus   setHeight(double height);

    virtual double              rowHeight(int row) const;
    virtual Zcad::ErrorStatus   setRowHeight(int row, double height);
    virtual Zcad::ErrorStatus   setRowHeight(double height);
	virtual double				minimumColumnWidth(int col) const;
	virtual double				minimumRowHeight(int row) const;    
	virtual double				minimumTableWidth() const;
	virtual double				minimumTableHeight() const;

    ZSOFT_DEPRECATED virtual double horzCellMargin() const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setHorzCellMargin(double gap);

    ZSOFT_DEPRECATED virtual double vertCellMargin() const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setVertCellMargin(double gap);

    virtual ZcDb::FlowDirection flowDirection() const; 
    virtual Zcad::ErrorStatus   setFlowDirection(ZcDb::FlowDirection flow);

    ZSOFT_DEPRECATED virtual bool isTitleSuppressed() const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus suppressTitleRow(bool value);

    ZSOFT_DEPRECATED virtual bool isHeaderSuppressed() const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus suppressHeaderRow(bool value);

    ZSOFT_DEPRECATED virtual ZcDb::CellAlignment alignment(ZcDb::RowType type =
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus   setAlignment(ZcDb::CellAlignment align,
                                          int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual bool isBackgroundColorNone(ZcDb::RowType type = 
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setBackgroundColorNone(bool value,
                                          int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual ZcCmColor backgroundColor(ZcDb::RowType type =
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setBackgroundColor(const ZcCmColor& color,
                                          int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual ZcCmColor contentColor(ZcDb::RowType type = 
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setContentColor(const ZcCmColor& color,
                                          int nRowType = ZcDb::kAllRows);
	
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus getDataType(ZcValue::DataType& nDataType,
                                            ZcValue::UnitType& nUnitType,
                                            ZcDb::RowType type) const;

    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setDataType(ZcValue::DataType nDataType,
                                            ZcValue::UnitType nUnitType);

    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setDataType(ZcValue::DataType nDataType,
                                            ZcValue::UnitType nUnitType,
                                            int nRowTypes);

    ZSOFT_DEPRECATED virtual const ZTCHAR* format(ZcDb::RowType type);
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setFormat(const ZTCHAR* pszFormat);
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setFormat(const ZTCHAR* pszFormat, 
                                          int nRowTypes);
	
    ZSOFT_DEPRECATED virtual ZcDbObjectId  textStyle(ZcDb::RowType type =
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setTextStyle(const ZcDbObjectId& id,
                                          int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual double textHeight(ZcDb::RowType type =
                                          ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setTextHeight(double height,
                                          int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual ZcDb::LineWeight gridLineWeight(ZcDb::GridLineType gridlineType,
                                ZcDb::RowType type = ZcDb::kDataRow) const; 
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setGridLineWeight(ZcDb::LineWeight lwt,
                                               int nBorders,
                                               int nRows);

    ZSOFT_DEPRECATED virtual ZcCmColor gridColor(ZcDb::GridLineType gridlineType,
                                ZcDb::RowType type = ZcDb::kDataRow) const; 
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setGridColor(const ZcCmColor& color,
                                               int nBorders,
                                               int nRows);

    ZSOFT_DEPRECATED virtual ZcDb::Visibility gridVisibility(ZcDb::GridLineType gridlineType,
                                ZcDb::RowType type = ZcDb::kDataRow) const; 
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setGridVisibility(ZcDb::Visibility visible,
                                               int nBorders,
                                               int nRows);

    ZSOFT_DEPRECATED virtual bool tableStyleOverrides(
                                               ZcDbIntArray& overrides) const;
    ZSOFT_DEPRECATED virtual void clearTableStyleOverrides(int options = 0);

    virtual ZcDb::CellType      cellType(int row, 
                                         int col) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setCellType(int row, 
                                         int col,
                                         ZcDb::CellType type);

    virtual Zcad::ErrorStatus   getCellExtents(int row, 
                                         int col,
                                         bool isOuterCell,
                                         ZcGePoint3dArray& pts) const;

    virtual ZcGePoint3d         attachmentPoint(int row, 
                                          int col) const; 

    virtual ZcDb::CellAlignment alignment(int row, 
                                          int col) const;
    virtual Zcad::ErrorStatus   setAlignment(int row, 
                                          int col,
                                          ZcDb::CellAlignment align);

    virtual bool                isBackgroundColorNone(int row, 
                                          int col) const;
    virtual Zcad::ErrorStatus   setBackgroundColorNone(int row, 
                                          int col, 
                                          bool value);

    virtual ZcCmColor           backgroundColor(int row, 
                                          int col) const;
    virtual Zcad::ErrorStatus   setBackgroundColor(int row, 
                                          int col,
                                          const ZcCmColor& color);

    virtual ZcCmColor           contentColor(int row, 
                                             int col) const;
    virtual Zcad::ErrorStatus   setContentColor(int row, 
                                             int col,
                                             const ZcCmColor& color);

    virtual bool                cellStyleOverrides(int row, 
                                         int col, 
                                         ZcDbIntArray& overrides) const;
                                         
    void                        clearCellOverrides(int row, int column);
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus deleteCellContent(int row,
                                             int col);
    ZSOFT_DEPRECATED virtual ZcDb::RowType rowType(int row) const;

    Zcad::ErrorStatus       getDataType(int row, int col,
                                        ZcValue::DataType& nDataType,
                                        ZcValue::UnitType& nUnitType) const;

    Zcad::ErrorStatus       setDataType(int row, int col, 
                                        ZcValue::DataType nDataType,
                                        ZcValue::UnitType nUnitType);

    ZcValue                 value(int row, int col) const;

    Zcad::ErrorStatus       setValue(int row, int col, 
                                     const ZcValue& val);

    Zcad::ErrorStatus       setValue(int row, int col, 
                                     LPCTSTR pszText,
                                     ZcValue::ParseOption nOption);

    Zcad::ErrorStatus       resetValue(int row, int col);
    
    const ZTCHAR* format(int row, int col) const;
    
    ZSOFT_DEPRECATED Zcad::ErrorStatus setFormat(int row, int col, 
                                                   const ZTCHAR* pszFormat);
	
    virtual const ZTCHAR*         textStringConst(int row, 
                                                int col) const;
    virtual ZTCHAR*               textString(int row, 
                                           int col) const;
	
    virtual Zcad::ErrorStatus	 textString(int row, int col, 
                                   ZcValue::FormatOption nOption,
                                   ZcString& sText) const;
	
    virtual Zcad::ErrorStatus   setTextString(int row, 
                                           int col,
                                           const ZTCHAR* text);

    virtual ZcDbObjectId        fieldId(int row, int col) const;
    virtual Zcad::ErrorStatus   setFieldId(int row, int col, const ZcDbObjectId& fieldId);
	
    virtual Zcad::ErrorStatus   setFieldId(int row, int col, const ZcDbObjectId& fieldId, 
											ZcDb::CellOption nFlag);
	
    virtual ZcDbObjectId        textStyle(int row, 
                                          int col) const;
    virtual Zcad::ErrorStatus   setTextStyle(int row, 
                                          int col,
                                          const ZcDbObjectId& id);

    virtual double              textHeight(int row,
                                           int col) const;
    virtual Zcad::ErrorStatus   setTextHeight(int row, 
                                           int col,
                                           double height);

    ZSOFT_DEPRECATED virtual ZcDb::RotationAngle textRotation(int row,
                                              int col) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus  setTextRotation(int row, 
                                              int col,
                                              ZcDb::RotationAngle rot);

    ZSOFT_DEPRECATED virtual bool isAutoScale(int row,
                                              int col) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setAutoScale(int row, 
                                              int col,
                                              bool autoFit);

    virtual ZcDbObjectId        blockTableRecordId(int row, 
                                                   int col) const;

    virtual Zcad::ErrorStatus   setBlockTableRecordId(int row, 
                                                      int col,
                                                      const ZcDbObjectId& blkId,
                                                      bool autoFit = false);

    ZSOFT_DEPRECATED virtual double blockScale(int row,
                                               int col) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setBlockScale(int row, 
                                              int col,
                                              double scale);

    ZSOFT_DEPRECATED virtual double blockRotation(int row,
                                              int col) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setBlockRotation(int row, 
                                              int col,
                                              double rotAng);

    virtual Zcad::ErrorStatus   getBlockAttributeValue(int row, 
                                           int col, 
                                           const ZcDbObjectId& attdefId,
                                           ZTCHAR*& value) const;
    virtual Zcad::ErrorStatus   setBlockAttributeValue(int row, 
                                           int col,
                                           const ZcDbObjectId& attdefId,
                                           const ZTCHAR* value);

    virtual ZcCmColor           gridColor(int row, 
                                          int col,
                                          ZcDb::CellEdgeMask iEdge) const;
    virtual Zcad::ErrorStatus   setGridColor(int row, 
                                          int col,
                                          short nEdges,
                                          const ZcCmColor& color);

    virtual ZcDb::Visibility    gridVisibility(int row, 
                                          int col,
                                          ZcDb::CellEdgeMask iEdge) const;
    virtual Zcad::ErrorStatus   setGridVisibility(int row, 
                                          int col,
                                          short nEdges,
                                          ZcDb::Visibility value);

    virtual ZcDb::LineWeight    gridLineWeight(int row, 
                                          int col,
                                          ZcDb::CellEdgeMask iEdge) const;
    virtual Zcad::ErrorStatus   setGridLineWeight(int row, 
                                          int col,
                                          short nEdges,
                                          ZcDb::LineWeight value);

    virtual Zcad::ErrorStatus   insertColumns(int col, 
                                              double width,
                                              int nCols = 1);
    virtual Zcad::ErrorStatus   deleteColumns(int col, 
                                              int nCols = 1);

    virtual Zcad::ErrorStatus   insertRows(int row, 
                                           double height,
                                           int nRows = 1);

    virtual Zcad::ErrorStatus   deleteRows(int row, 
                                           int nRows = 1);

    virtual Zcad::ErrorStatus   mergeCells(int minRow, int maxRow,
                                           int minCol, int maxCol);
    virtual Zcad::ErrorStatus   unmergeCells(int minRow, int maxRow,
                                           int minCol, int maxCol);

    virtual bool                isMergedCell(int row, int col, 
                                             int* minRow = NULL, 
                                             int* maxRow = NULL,
                                             int* minCol = NULL, 
                                             int* maxCol = NULL) const;

    virtual Zcad::ErrorStatus generateLayout();
    virtual Zcad::ErrorStatus recomputeTableBlock(bool forceUpdate = true);

    virtual bool              hitTest(const ZcGePoint3d& wpt, 
                                      const ZcGeVector3d& wviewVec,
                                      double wxaper,
                                      double wyaper,
                                      int& resultRowIndex, 
                                      int& resultColumnIndex);
	
    bool                      hitTest(const ZcGePoint3d& wpt, 
                                      const ZcGeVector3d& wviewVec,
                                      double wxaper,
                                      double wyaper,
                                      int& resultRowIndex, 
                                      int& resultColumnIndex,
                                      int& contentIndex,
                                      ZcDb::TableHitItem& nItem);
	
    virtual Zcad::ErrorStatus select(const ZcGePoint3d& wpt, 
                                     const ZcGeVector3d& wvwVec, 
                                     const ZcGeVector3d& wvwxVec, 
                                     double wxaper,
                                     double wyaper,
                                     bool allowOutside,
                                     bool bInPickFirst, 
                                     int& resultRowIndex, 
                                     int& resultColumnIndex,
                                     ZcDbFullSubentPathArray* pPaths = NULL) const;

    virtual Zcad::ErrorStatus selectSubRegion(const ZcGePoint3d& wpt1, 
                                     const ZcGePoint3d& wpt2,
                                     const ZcGeVector3d& wvwVec, 
                                     const ZcGeVector3d& wvwxVec,
                                     double wxaper,
                                     double wyaper,                             
                                     ZcDb::SelectType seltype,
                                     bool bIncludeCurrentSelection,
                                     bool bInPickFirst,                             
                                     int& rowMin,
                                     int& rowMax,
                                     int& colMin,
                                     int& colMax,
                                     ZcDbFullSubentPathArray* pPaths = NULL) const;

    virtual bool reselectSubRegion(ZcDbFullSubentPathArray& paths) const;
            
    virtual Zcad::ErrorStatus getSubSelection(int& rowMin,
                                      int& rowMax,
                                      int& colMin,
                                      int& colMax) const;
	
    ZcCellRange     getSubSelection         (void) const;
	
    virtual Zcad::ErrorStatus setSubSelection(int rowMin,
                                      int rowMax,
                                      int colMin,
                                      int colMax);
	
    Zcad::ErrorStatus setSubSelection       (const ZcCellRange& range);
	
    virtual void              clearSubSelection();

    virtual bool              hasSubSelection() const;

    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler*);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler*);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    virtual Zcad::ErrorStatus subClose();
    virtual void              objectClosed(const ZcDbObjectId objId);
    virtual void              erased(const ZcDbObject* dbObj,
                                      ZSoft::Boolean pErasing = true);
	
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual void              list() const;

    virtual ZSoft::Boolean    worldDraw(ZcGiWorldDraw* worldDraw);

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&, 
                                            ZcDbIntArray&,
                                            ZcDbIntArray & geomIds) const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray&,
                                               const ZcGeVector3d&);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getOsnapPoints(ZcDb::OsnapMode osnapMode,
                                             ZSoft::GsMarker  gsSelectionMark,
                                             const ZcGePoint3d&  pickPoint,
                                             const ZcGePoint3d&  lastPoint,
                                             const ZcGeMatrix3d& viewXform,
                                             ZcGePoint3dArray&      snapPoints,
                                             ZcDbIntArray&   geomIds)
                                             const;

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d& xform,
                                                 ZcDbEntity*& ent) const;

    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
    virtual Zcad::ErrorStatus setPosition(const ZcGePoint3d&);

    virtual Zcad::ErrorStatus setNormal(const ZcGeVector3d& newVal);

    virtual Zcad::ErrorStatus select_next_cell(int dir,
                                     int& resultRowIndex, 
                                     int& resultColumnIndex,
                                     ZcDbFullSubentPathArray* pPaths = NULL,
                                     bool bSupportTextCellOnly = true) const;

    virtual void              setRegen();
    virtual void              suppressInvisibleGrid(bool value);
    virtual Zcad::ErrorStatus getCellExtents(int row, 
                                         int col,
                                         double& cellWidth,
                                         double& cellHeight,
                                         bool bAdjustForMargins) const;
	
    bool isRegenerateTableSuppressed() const;
    void suppressRegenerateTable(bool bSuppress);

    Zcad::ErrorStatus setSize               (int nRows, 
                                             int nCols);
    bool            canInsert               (int nIndex, 
                                             bool bRow) const;
    Zcad::ErrorStatus insertRowsAndInherit  (int nIndex, 
                                             int nInheritFrom,
                                             int nNumRows);
    Zcad::ErrorStatus insertColumnsAndInherit(int col, 
                                             int nInheritFrom, 
                                             int nNumCols);
    bool            canDelete               (int nIndex, 
                                             int nCount,
                                             bool bRow) const;
    bool            isEmpty                 (int nRow, 
                                             int nCol) const;
    ZcCellRange     getMergeRange           (int nRow, 
                                             int nCol) const;
    ZcDbTableIterator* getIterator          (void) const;
    ZcDbTableIterator* getIterator          (const ZcCellRange* pRange, 
                                             ZcDb::TableIteratorOption nOption) const;
    bool            isContentEditable       (int nRow, 
                                             int nCol) const;
    bool            isFormatEditable        (int nRow, 
                                             int nCol) const;
    ZcDb::CellState cellState               (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus setCellState          (int nRow, 
                                             int nCol, 
                                             ZcDb::CellState nLock);

    int             numContents             (int nRow, 
                                             int nCol) const;
    int             createContent           (int nRow, 
                                             int nCol, 
                                             int nIndex);
    Zcad::ErrorStatus moveContent           (int nRow, 
                                             int nCol, 
                                             int nFromIndex, 
                                             int nToIndex);
    Zcad::ErrorStatus deleteContent         (int nRow, 
                                             int nCol);
    Zcad::ErrorStatus deleteContent         (int nRow, 
                                             int nCol, 
                                             int nIndex);
    Zcad::ErrorStatus deleteContent         (const ZcCellRange& range);

    ZcDb::CellContentType contentType       (int nRow, 
                                             int nCol) const;
    ZcDb::CellContentType contentType       (int nRow, 
                                             int nCol, 
                                             int nIndex) const;

    ZcValue value                           (int row,
                                             int col, 
                                             int nContent) const;
    ZcValue value                           (int row,
                                             int col, 
                                             int nContent,
                                             ZcValue::FormatOption nOption) const;
    Zcad::ErrorStatus setValue              (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcValue& val);
    Zcad::ErrorStatus setValue              (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcValue& val,
                                             ZcValue::ParseOption nOption);
    Zcad::ErrorStatus setValue              (int row, 
                                             int col, 
                                             int nContent, 
                                             LPCTSTR pszText, 
                                             ZcValue::ParseOption nOption);
    ZcString        dataFormat              (int row,
                                             int col) const;
    ZcString        dataFormat              (int row,
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setDataFormat         (int row, 
                                             int col, 
                                             const ZTCHAR* pszFormat);
    Zcad::ErrorStatus setDataFormat         (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZTCHAR* pszFormat);
    ZcString        textString              (int row,
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus textString            (int row, 
                                             int col, 
                                             int nContent, 
                                             ZcValue::FormatOption nOption,
                                             ZcString& sText) const;
    Zcad::ErrorStatus setTextString         (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZTCHAR* text);
    bool            hasFormula              (int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZcString        getFormula              (int nRow,
                                             int nCol, 
                                             int nContent) const;
    Zcad::ErrorStatus setFormula            (int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZTCHAR* pszFormula);
    ZcDbObjectId    fieldId                 (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setFieldId            (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcDbObjectId& fieldId, 
                                             ZcDb::CellOption nFlag);
    ZcDbObjectId    blockTableRecordId      (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setBlockTableRecordId (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcDbObjectId& blkId, 
                                             bool autoFit);
    Zcad::ErrorStatus getBlockAttributeValue(int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcDbObjectId& attdefId, 
                                             ZTCHAR*& value) const;
    Zcad::ErrorStatus setBlockAttributeValue(int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcDbObjectId& attdefId, 
                                             const ZTCHAR* value);
    int             getCustomData           (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus setCustomData         (int nRow, 
                                             int nCol, 
                                             int nData);
    Zcad::ErrorStatus getCustomData         (int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             ZcValue* pData) const;
    Zcad::ErrorStatus setCustomData         (int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             const ZcValue* pData);
    const ZTCHAR *   cellStyle               (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus setCellStyle          (int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszCellStyle);
    double          margin                  (int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargin) const;
    Zcad::ErrorStatus setMargin             (int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargins, 
                                             double fMargin);
    ZcGePoint3d     attachmentPoint         (int row, 
                                             int col,
                                             int content) const;
    ZcCmColor       contentColor            (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setContentColor       (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcCmColor& color);
    Zcad::ErrorStatus getDataType           (int row, 
                                             int col, 
                                             int nContent, 
                                             ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType) const;
    Zcad::ErrorStatus setDataType           (int row, 
                                             int col, 
                                             int nContent, 
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    ZcDbObjectId    textStyle               (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setTextStyle          (int row, 
                                             int col, 
                                             int nContent, 
                                             const ZcDbObjectId& id);
    double          textHeight              (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setTextHeight         (int row, 
                                             int col, 
                                             int nContent, 
                                             double height);
	double          rotation                (void) const;
	double          rotation                (int row, 
											int col, 
											int nContent) const;
	Zcad::ErrorStatus setRotation           (double fAngle);
	Zcad::ErrorStatus setRotation           (int row, 
											int col, 
											int nContent, 
											double fAngle);
    bool            isAutoScale             (int row, 
                                             int col, 
                                             int nContent) const;
    Zcad::ErrorStatus setAutoScale          (int row, 
                                             int col, 
                                             int nContent, 
                                             bool autoFit);
	double          scale                   (int row, 
											 int col, 
		                                     int nContent) const;
	Zcad::ErrorStatus setScale              (int row, 
											 int col, 
		                                     int nContent, 
		                                     double scale);
    ZcDb::CellContentLayout contentLayout  (int row, 
                                             int col) const;
    Zcad::ErrorStatus setContentLayout      (int row, 
                                             int col, 
                                             ZcDb::CellContentLayout nLayout);
    bool            isMergeAllEnabled       (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus enableMergeAll        (int nRow, 
                                             int nCol,
                                             bool bEnable);
    ZcDb::CellProperty getOverride          (int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZcDb::GridProperty getOverride          (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setOverride           (int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             ZcDb::CellProperty nOverride);
    Zcad::ErrorStatus setOverride           (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcDb::GridProperty nOverride);
    Zcad::ErrorStatus removeAllOverrides    (int nRow, 
                                             int nCol);
    ZcDb::GridLineStyle gridLineStyle       (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridLineStyle      (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::GridLineStyle nLineStyle);
    ZcDb::LineWeight gridLineWeight         (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridLineWeight     (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::LineWeight nLineWeight);
    ZcDbObjectId    gridLinetype            (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridLinetype       (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcDbObjectId& idLinetype);
    ZcCmColor       gridColor               (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridColor          (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridlineTypes, 
                                             const ZcCmColor& color);
    ZcDb::Visibility gridVisibility         (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridVisibility     (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::Visibility nVisibility);
    double          gridDoubleLineSpacing   (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    Zcad::ErrorStatus setGridDoubleLineSpacing(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes,
                                             double fSpacing);
    Zcad::ErrorStatus getGridProperty       (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcGridProperty& gridProp) const;
    Zcad::ErrorStatus setGridProperty       (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);
    Zcad::ErrorStatus setGridProperty       (const ZcCellRange& rangeIn, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);

    bool            isLinked                (int nRow, 
                                             int nCol) const;
    ZcDbObjectId getDataLink                (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus getDataLink           (int nRow, 
                                             int nCol, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    int             getDataLink             (const ZcCellRange* pRange, 
                                             ZcDbObjectIdArray& dataLinkIds) const;
    Zcad::ErrorStatus setDataLink           (int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    Zcad::ErrorStatus setDataLink           (const ZcCellRange& range, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    ZcCellRange     getDataLinkRange        (int nRow, 
                                             int nCol) const;
    Zcad::ErrorStatus removeDataLink        (int nRow, 
                                             int nCol);
    Zcad::ErrorStatus removeDataLink        (void);
    Zcad::ErrorStatus updateDataLink        (int nRow, 
                                             int nCol, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    Zcad::ErrorStatus updateDataLink        (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

    bool            isBreakEnabled          (void) const;
    Zcad::ErrorStatus enableBreak           (bool bEnable);
    ZcDb::TableBreakFlowDirection breakFlowDirection(void) const;
    Zcad::ErrorStatus setBreakFlowDirection (ZcDb::TableBreakFlowDirection nDir);
    double          breakHeight             (int nIndex) const;
    Zcad::ErrorStatus setBreakHeight        (int nIndex, 
                                             double fHeight);
    ZcGeVector3d    breakOffset             (int nIndex) const;
    Zcad::ErrorStatus setBreakOffset        (int nIndex, 
                                             const ZcGeVector3d& vec);
    ZcDb::TableBreakOption breakOption      (void) const;
    Zcad::ErrorStatus setBreakOption        (ZcDb::TableBreakOption nOption);
    double          breakSpacing            (void) const;
    Zcad::ErrorStatus setBreakSpacing       (double fSpacing);
    Zcad::ErrorStatus copyFrom              (const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption);
    Zcad::ErrorStatus copyFrom              (const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption, 
                                             const ZcCellRange& srcRange, 
                                             const ZcCellRange& targetRange,
                                             ZcCellRange* pNewTargetRangeOut);
    Zcad::ErrorStatus copyFrom              (const ZcDbTable* pSrc, 
                                             ZcDb::TableCopyOption nOption, 
                                             const ZcCellRange& srcRange, 
                                             const ZcCellRange& targetRange,
                                             ZcCellRange* pNewTargetRangeOut);
    Zcad::ErrorStatus fill                  (const ZcCellRange& fillRange, 
                                             const ZcCellRange& srcRange, 
                                             ZcDb::TableFillOption nOption);
    const ZTCHAR *   getColumnName           (int nIndex) const;
    Zcad::ErrorStatus setColumnName         (int nIndex, 
                                             const ZTCHAR* pszName);
    ZcString        getToolTip              (int nRow,
                                             int nCol) const;
    Zcad::ErrorStatus setToolTip            (int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszToolTip);
    Zcad::ErrorStatus createTemplate        (ZcDbTableTemplate*& pTemplate, 
                                             ZcDb::TableCopyOption nCopyOption);
    Zcad::ErrorStatus getIndicatorSize      (double& fWidth, 
                                             double& fHeight) const;
protected:
    
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const;

};

#pragma pack(pop)
