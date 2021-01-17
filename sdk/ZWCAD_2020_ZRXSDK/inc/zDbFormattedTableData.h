

#pragma once

#include "zDbLinkedTableData.h"
#include "zDbTableIterator.h"

struct ZcGridProperty
{
    ZcDb::GridProperty  mnPropMask;
    ZcDb::GridLineStyle mnLineStyle;
    ZcDb::LineWeight    mnLineWeight;
    ZcDbHardPointerId   mLinetype;
    ZcCmColor           mColor;
    ZcDb::Visibility    mnVisibility;
    double              mfDoubleLineSpacing;
};

class ZcDbFormattedTableData : public ZcDbLinkedTableData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFormattedTableData);

    ZCDB_PORT ZcDbFormattedTableData(void);
    ZCDB_PORT ~ZcDbFormattedTableData(void);

    ZCDB_PORT virtual int insertRowAndInherit(int nIndex, 
                                             int nInheritFrom,
                                             int nNumRows);
    ZCDB_PORT virtual int insertColumnAndInherit(int nIndex, 
                                             int nInheritFrom,
                                             int nNumCols);

    ZCDB_PORT virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idField, 
                                             ZcDb::CellOption nFlag);
    ZCDB_PORT virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             int nIndex, 
                                             const ZcDbObjectId& idField, 
                                             ZcDb::CellOption nFlag);

    ZCDB_PORT virtual Zcad::ErrorStatus merge(const ZcCellRange& range);
    ZCDB_PORT virtual Zcad::ErrorStatus unmerge(const ZcCellRange& range);
    ZCDB_PORT virtual bool isMerged         (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcCellRange getMergeRange(int nRow, 
                                             int nCol) const;

    ZCDB_PORT virtual bool isFormatEditable (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual double rotation       (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual double rotation       (int nRow, 
                                             int nCol,
                                             int nIndex) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setRotation(int nRow, 
                                             int nCol, 
                                             double fRotation);
    ZCDB_PORT virtual Zcad::ErrorStatus setRotation(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             double fRotation);
    ZCDB_PORT virtual double scale          (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual double scale          (int nRow, 
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setScale(int nRow, 
                                             int nCol, 
                                             double fScale);
    ZCDB_PORT virtual Zcad::ErrorStatus setScale(int nRow, 
                                             int nCol, 
                                             int nIndex,
                                             double fScale);
    ZCDB_PORT virtual bool isAutoScale      (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual bool isAutoScale      (int nRow, 
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setAutoScale(int nRow, 
                                             int nCol, 
                                             bool bAutoScale);
    ZCDB_PORT virtual Zcad::ErrorStatus setAutoScale(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             bool bAutoScale);
    ZCDB_PORT virtual ZcDb::CellAlignment alignment(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setAlignment(int nRow, 
                                             int nCol, 
                                             ZcDb::CellAlignment nAlignment);
    ZCDB_PORT virtual ZcCmColor contentColor(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcCmColor contentColor(int nRow, 
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setContentColor(int nRow, 
                                             int nCol, 
                                             const ZcCmColor& color);
    ZCDB_PORT virtual Zcad::ErrorStatus setContentColor(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZcCmColor& color);
    ZCDB_PORT virtual ZcDbObjectId textStyle(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual ZcDbObjectId textStyle(int nRow, 
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setTextStyle(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idTextStyle);
    ZCDB_PORT virtual Zcad::ErrorStatus setTextStyle(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZcDbObjectId& idTextStyle);
    ZCDB_PORT virtual double textHeight     (int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual double textHeight     (int nRow, 
                                             int nCol,
                                             int nContent) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setTextHeight(int nRow, 
                                             int nCol, 
                                             double fTextHeight);
    ZCDB_PORT virtual Zcad::ErrorStatus setTextHeight(int nRow, 
                                             int nCol,
                                             int nContent,
                                             double fTextHeight);
    ZCDB_PORT virtual ZcCmColor backgroundColor(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setBackgroundColor(int nRow, 
                                             int nCol, 
                                             const ZcCmColor& color);
    ZCDB_PORT virtual ZcDb::CellContentLayout contentLayout(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setContentLayout(int nRow, 
                                             int nCol, 
                                             ZcDb::CellContentLayout nLayout);

    ZCDB_PORT virtual ZcDb::FlowDirection flowDirection(void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setFlowDirection(ZcDb::FlowDirection nDir);
    ZCDB_PORT virtual double margin         (int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargin) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setMargin(int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargins, 
                                             double fMargin);
    ZCDB_PORT virtual bool isMergeAllEnabled(int nRow, 
                                             int nCol) const;
    ZCDB_PORT virtual Zcad::ErrorStatus enableMergeAll(int nRow, 
                                             int nCol,
                                             bool bEnable);

    ZCDB_PORT virtual ZcDb::GridLineStyle gridLineStyle(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridLineStyle(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes,
                                             ZcDb::GridLineStyle nLineStyle);
    ZCDB_PORT virtual ZcDb::LineWeight gridLineWeight(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridLineWeight(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::LineWeight nLineWeight);
    ZCDB_PORT virtual ZcDbObjectId gridLinetype(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridLinetype(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcDbObjectId& idLinetype);
    ZCDB_PORT virtual ZcCmColor gridColor   (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridColor(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcCmColor& color);
    ZCDB_PORT virtual ZcDb::Visibility gridVisibility(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridVisibility(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::Visibility nVisibility);
    ZCDB_PORT virtual double gridDoubleLineSpacing(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridDoubleLineSpacing(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             double fSpacing);
    ZCDB_PORT virtual Zcad::ErrorStatus getGridProperty(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcGridProperty& gridProp) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setGridProperty(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);
    ZCDB_PORT virtual Zcad::ErrorStatus setGridProperty(const ZcCellRange& range,
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);

    ZCDB_PORT virtual ZcDb::CellProperty getOverride(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    ZCDB_PORT virtual ZcDb::GridProperty getOverride(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    ZCDB_PORT virtual Zcad::ErrorStatus setOverride(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             ZcDb::CellProperty nOverride);
    ZCDB_PORT virtual Zcad::ErrorStatus setOverride(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcDb::GridProperty nOverride);
    ZCDB_PORT virtual Zcad::ErrorStatus removeAllOverrides(int nRow, 
                                             int nCol);

    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
};
