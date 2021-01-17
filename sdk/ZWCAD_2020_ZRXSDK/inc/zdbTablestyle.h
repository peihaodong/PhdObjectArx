
#ifndef __ZDBTABLESTYLE_H__
#define __ZDBTABLESTYLE_H__

#pragma once

#include "zdbmain.h"

#include "zAdAChar.h"
#include "zAcValue.h"
#include "zAcString.h"
#include "zDbFormattedTableData.h"

#pragma pack (push, 8)

class ZcDbTableTemplate;
class ZcDbTableStyle : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableStyle);

    ZcDbTableStyle();
    virtual ~ZcDbTableStyle();

    virtual Zcad::ErrorStatus   getName(ZTCHAR*& pszName) const;
    virtual Zcad::ErrorStatus   setName(const ZTCHAR * pszName);

    virtual const ZTCHAR*        description(void) const;
    virtual Zcad::ErrorStatus   setDescription(const ZTCHAR * pszDescription);

    virtual ZSoft::UInt32       bitFlags() const;
    virtual Zcad::ErrorStatus   setBitFlags(ZSoft::UInt32 flags);

    virtual ZcDb::FlowDirection flowDirection(void) const; 
    virtual Zcad::ErrorStatus   setFlowDirection(ZcDb::FlowDirection flow);

    ZSOFT_DEPRECATED virtual double horzCellMargin(void) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setHorzCellMargin(double dCellMargin);

    ZSOFT_DEPRECATED virtual double vertCellMargin(void) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setVertCellMargin(double dCellMargin);

    ZSOFT_DEPRECATED virtual bool isTitleSuppressed(void) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus suppressTitleRow(bool bValue);

    ZSOFT_DEPRECATED virtual bool isHeaderSuppressed(void) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus suppressHeaderRow(bool bValue);

    virtual ZcDbObjectId        textStyle(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setTextStyle(const ZcDbObjectId id,
                                            int rowTypes = ZcDb::kAllRows);
    
    virtual double              textHeight(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setTextHeight(double dHeight,
                                              int rowTypes = ZcDb::kAllRows);

    virtual ZcDb::CellAlignment alignment(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setAlignment(ZcDb::CellAlignment alignment,
                                             int rowTypes = ZcDb::kAllRows);

    virtual ZcCmColor           color(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setColor(const ZcCmColor& color,
                                         int rowTypes = ZcDb::kAllRows);

    virtual ZcCmColor           backgroundColor(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setBackgroundColor(const ZcCmColor& color,
                                                   int rowTypes = ZcDb::kAllRows);

    ZSOFT_DEPRECATED virtual bool isBackgroundColorNone(ZcDb::RowType rowType = ZcDb::kDataRow) const;
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus setBackgroundColorNone(bool bValue,
                                                       int rowTypes = ZcDb::kAllRows);
	
    virtual Zcad::ErrorStatus   getDataType(ZcValue::DataType& nDataType,
                                            ZcValue::UnitType& nUnitType) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus   getDataType(ZcValue::DataType& nDataType,
                                            ZcValue::UnitType& nUnitType,
                                            ZcDb::RowType rowType) const;
    virtual Zcad::ErrorStatus   setDataType(ZcValue::DataType nDataType,
                                            ZcValue::UnitType nUnitType);
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus   setDataType(ZcValue::DataType nDataType,
                                            ZcValue::UnitType nUnitType,
                                            int rowTypes);

    ZSOFT_DEPRECATED virtual const ZTCHAR* format (void) const;
    
    ZSOFT_DEPRECATED virtual const ZTCHAR* format (ZcDb::RowType rowType) const;
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus   setFormat(const ZTCHAR* pszFormat);
    
    ZSOFT_DEPRECATED virtual Zcad::ErrorStatus   setFormat(const ZTCHAR* pszFormat,
                                          int rowTypes);

    virtual ZcDb::LineWeight    gridLineWeight(ZcDb::GridLineType gridLineType, 
                                               ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridLineWeight(ZcDb::LineWeight lineWeight,
                                                  int gridLineTypes = ZcDb::kAllGridLines, 
                                                  int rowTypes = ZcDb::kAllRows);
    virtual ZcCmColor           gridColor(ZcDb::GridLineType gridLineType, 
                                          ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridColor(const ZcCmColor color,
                                             int gridLineTypes = ZcDb::kAllGridLines, 
                                             int rowTypes = ZcDb::kAllRows);
    virtual ZcDb::Visibility    gridVisibility(ZcDb::GridLineType gridLineType, 
                                               ZcDb::RowType rowType = ZcDb::kDataRow) const;
    virtual Zcad::ErrorStatus   setGridVisibility(ZcDb::Visibility visible,
                                                  int gridLineTypes = ZcDb::kAllGridLines, 
                                                  int rowTypes = ZcDb::kAllRows);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;
	virtual Zcad::ErrorStatus	audit(ZcDbAuditInfo* pAuditInfo);

    virtual Zcad::ErrorStatus   postTableStyleToDb(ZcDbDatabase* pDb, 
                                                   const ZTCHAR* styleName, 
                                                   ZcDbObjectId& tableStyleId);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    const ZTCHAR *   createCellStyle         (void);
    Zcad::ErrorStatus createCellStyle       (const ZTCHAR* pszCellStyle);
    Zcad::ErrorStatus createCellStyle       (const ZTCHAR* pszCellStyle, 
                                             const ZTCHAR* pszFromCellStyle);
    Zcad::ErrorStatus renameCellStyle       (const ZTCHAR* pszOldName, 
                                             const ZTCHAR* pszNewName);
    Zcad::ErrorStatus deleteCellStyle       (const ZTCHAR* pszCellStyle);
    Zcad::ErrorStatus copyCellStyle         (const ZTCHAR* pszSrcCellStyle, 
                                             const ZTCHAR* pszTargetCellStyle);
    Zcad::ErrorStatus copyCellStyle         (const ZcDbTableStyle* pSrc, 
                                             const ZTCHAR* pszSrcCellStyle,
                                             const ZTCHAR* pszTargetCellStyle);
    Zcad::ErrorStatus getUniqueCellStyleName(const ZTCHAR* pszBaseName, 
                                             ZcString& sUniqueName) const;
    bool            isCellStyleInUse        (const ZTCHAR* pszCellStyle) const;
    int             numCellStyles           (void) const;
    int             getCellStyles           (ZcStringArray& cellstyles) const;

    ZcDbObjectId    textStyle               (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setTextStyle          (const ZcDbObjectId& id, 
                                             const ZTCHAR* pszCellStyle);

    double          textHeight              (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setTextHeight         (double dHeight, 
                                             const ZTCHAR* pszCellStyle);

    ZcDb::CellAlignment alignment           (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setAlignment          (ZcDb::CellAlignment alignment, 
                                             const ZTCHAR* pszCellStyle);

    ZcCmColor       color                   (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setColor              (const ZcCmColor& color, 
                                             const ZTCHAR* pszCellStyle);

    ZcCmColor       backgroundColor         (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setBackgroundColor    (const ZcCmColor& color, 
                                             const ZTCHAR* pszCellStyle);

    Zcad::ErrorStatus getDataType           (ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType,
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setDataType           (ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType,
                                             const ZTCHAR* pszCellStyle);

    const ZTCHAR *   format                  (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setFormat             (const ZTCHAR* pszFormat, 
                                             const ZTCHAR* pszCellStyle);

    int             cellClass               (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setCellClass          (int nClass, 
                                             const ZTCHAR* pszCellStyle);

    double          rotation                (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setRotation           (double fRotation, 
                                             const ZTCHAR* pszCellStyle);

    bool            isMergeAllEnabled       (const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus enableMergeAll        (bool bEnable, 
                                             const ZTCHAR* pszCellStyle);

    double          margin                  (ZcDb::CellMargin nMargin,
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setMargin             (ZcDb::CellMargin nMargins, 
                                             double fMargin,
                                             const ZTCHAR* pszCellStyle);

    ZcDb::LineWeight gridLineWeight         (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLineWeight     (ZcDb::LineWeight lineWeight, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    ZcCmColor       gridColor               (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridColor          (const ZcCmColor color, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    ZcDb::Visibility gridVisibility         (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridVisibility     (ZcDb::Visibility visible, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    double          gridDoubleLineSpacing   (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridDoubleLineSpacing(double fSpacing, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    ZcDb::GridLineStyle gridLineStyle       (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLineStyle      (ZcDb::GridLineStyle nLineStyle, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    ZcDbObjectId    gridLinetype            (ZcDb::GridLineType gridLineType, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridLinetype       (const ZcDbObjectId& id, 
                                             ZcDb::GridLineType gridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    Zcad::ErrorStatus getGridProperty       (ZcGridProperty& gridProp, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZTCHAR* pszCellStyle) const;
    Zcad::ErrorStatus setGridProperty       (const ZcGridProperty& gridProp, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZTCHAR* pszCellStyle);
    
    ZcDbObjectId    getTemplate             (void) const;
    Zcad::ErrorStatus getTemplate           (ZcDbTableTemplate*& pTemplate, 
                                             ZcDb::OpenMode mode);
    Zcad::ErrorStatus setTemplate           (const ZcDbObjectId& templateId, 
                                             ZcDb::MergeCellStyleOption nOption);
    Zcad::ErrorStatus setTemplate           (ZcDbTableTemplate* pTemplate, 
                                             ZcDb::MergeCellStyleOption nOption,
                                             ZcDbObjectId& templateId);
    ZcDbObjectId    removeTemplate          (void);

	ZcString cellStyleName( ZSoft::Int32 cellstyle )const;
};



#pragma pack (pop)

#endif 
