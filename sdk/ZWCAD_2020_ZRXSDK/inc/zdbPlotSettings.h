

#ifndef ZD_DBPLOTSETTINGS_H
#define ZD_DBPLOTSETTINGS_H

#include "zdbmain.h"
#include "zdbdict.h"

#pragma pack(push, 8)

class ZcDbPlotSettings: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPlotSettings);

    ZcDbPlotSettings(); 
    ZcDbPlotSettings(bool ModelType);
    virtual ~ZcDbPlotSettings();
    using ZcDbObject::copyFrom;

    virtual Zcad::ErrorStatus 
    getClassID                 (CLSID* pClsid) const;
    Zcad::ErrorStatus 
    copyFrom                   (ZcDbPlotSettings *fromPlotSettings);

    enum PlotPaperUnits {
        kInches,
        kMillimeters,
        kPixels
    };

    enum PlotRotation {
        k0degrees,
        k90degrees,
        k180degrees,
        k270degrees
    };

    enum PlotType {
        kDisplay,
        kExtents,
        kLimits,
        kView,
        kWindow,
        kLayout
    };

    enum StdScaleType {
        kScaleToFit,
        k1_128in_1ft,
        k1_64in_1ft,                  // 1/64"= 1'
        k1_32in_1ft,                  // 1/32"= 1'
        k1_16in_1ft,                  // 1/16"= 1'
        k3_32in_1ft,                  // 3/32"= 1'
        k1_8in_1ft,                   // 1/8" = 1'
        k3_16in_1ft,                  // 3/16"= 1'
        k1_4in_1ft,                   // 1/4" = 1'
        k3_8in_1ft,                   // 3/8" = 1'
        k1_2in_1ft,                   // 1/2" = 1'
        k3_4in_1ft,                   // 3/4" = 1'
        k1in_1ft,                     // 1"= 1'
        k3in_1ft,                     // 3"= 1'
        k6in_1ft,                     // 6"= 1'
        k1ft_1ft,                     // 1'= 1'
        k1_1,                         // 1:1
        k1_2,                         // 1:2
        k1_4,                         // 1:4
		k1_5,						  // 1:5
        k1_8,                         // 1:8
        k1_10,                        // 1:10
        k1_16,                        // 1:16
        k1_20,                        // 1:20
        k1_30,                        // 1:30
        k1_40,                        // 1:40
        k1_50,                        // 1:50
        k1_100,                       // 1:100
        k2_1,                         // 2:1
        k4_1,                         // 4:1
        k8_1,                         // 8:1
        k10_1,                        // 10:1
        k100_1,                       // 100:1
        k1000_1,                      // 1000:1
        k1and1_2in_1ft                // 1 1/2" = 1'
    };

    enum ShadePlotType {
        kAsDisplayed    = 0,
        kWireframe      = 1,
        kHidden         = 2,
        kRendered       = 3,
        kVisualStyle    = 4,
        kRenderPreset   = 5
    };

    enum ShadePlotResLevel {
        kDraft,
        kPreview,
        kNormal,
        kPresentation,
        kMaximum,
        kCustom
    };

    Zcad::ErrorStatus 
    addToPlotSettingsDict(ZcDbDatabase *towhichDb);

    
    Zcad::ErrorStatus 
    getPlotSettingsName        (const ZTCHAR *& plotSettingsName) const;

    Zcad::ErrorStatus 
    getPlotSettingsName        (ZTCHAR *& plotSettingsName) const;

    Zcad::ErrorStatus 
    setPlotSettingsName        (const ZTCHAR * plotSettingsName);

    Zcad::ErrorStatus 
    getPlotCfgName             (const ZTCHAR *& plotCfgName) const;

    Zcad::ErrorStatus    
    getPlotPaperMargins        (double& printableXmin,
                                double& printableYmin,
                                double& printableXmax,
                                double& printableYmax) const;
    Zcad::ErrorStatus 
    getPlotPaperSize           (double& paperWidth,
                                double& paperHeight) const;
    Zcad::ErrorStatus 
    getCanonicalMediaName      (const ZTCHAR *& mediaName) const;

    Zcad::ErrorStatus 
    getPlotOrigin              (double& x,
                                double& y) const;

    ZcDbPlotSettings::PlotPaperUnits 
    plotPaperUnits             () const;

    ZSoft::Boolean    
    plotViewportBorders        () const;

    void              
    setPlotViewportBorders     (ZSoft::Boolean plotViewportBorders);

    ZSoft::Boolean    
    plotPlotStyles             () const;

    void              
    setPlotPlotStyles          (ZSoft::Boolean plotPlotStyles);

    ZSoft::Boolean    
    showPlotStyles             () const;

    void              
    setShowPlotStyles          (ZSoft::Boolean showPlotStyles);

    ZcDbPlotSettings::PlotRotation   
    plotRotation               () const;

    ZSoft::Boolean    
    plotCentered               () const;

    ZSoft::Boolean    
    plotHidden                 () const;

    void              
    setPlotHidden              (ZSoft::Boolean plotHidden);

    ZcDbPlotSettings::ShadePlotType    
    shadePlot                  () const;

    Zcad::ErrorStatus              
    setShadePlot               (ZcDbPlotSettings::ShadePlotType shadePlot);

    ZcDbPlotSettings::ShadePlotResLevel
    shadePlotResLevel          () const;

    Zcad::ErrorStatus
    setShadePlotResLevel       (ZcDbPlotSettings::ShadePlotResLevel resLevel);

    ZSoft::Int16
    shadePlotCustomDPI         () const;

    Zcad::ErrorStatus
    setShadePlotCustomDPI      (ZSoft::Int16 val);

    ZcDbPlotSettings::PlotType 
    plotType                   () const;

    Zcad::ErrorStatus 
    getPlotWindowArea          (double& xmin,
                                double& ymin,
                                double& xmax, 
                                double& ymax) const;

    Zcad::ErrorStatus 
    getPlotViewName            (const ZTCHAR *& viewName) const;

    ZSoft::Boolean    
    useStandardScale           () const;

    Zcad::ErrorStatus 
    getCustomPrintScale        (double& numerator,
                                double& denominator) const;

    Zcad::ErrorStatus 
    getCurrentStyleSheet       (const ZTCHAR *& styleSheetName) const;

    ZcDbPlotSettings::StdScaleType 
    stdScaleType               () const;

    Zcad::ErrorStatus 
    getStdScale                (double& scale) const;

    ZSoft::Boolean    
    scaleLineweights           () const;

    void              
    setScaleLineweights        (ZSoft::Boolean scaleLineweights);

    ZSoft::Boolean    
    printLineweights           () const;

    void              
    setPrintLineweights        (ZSoft::Boolean printLineweights);

    ZSoft::Boolean    
    drawViewportsFirst         () const;

    void              
    setDrawViewportsFirst      (ZSoft::Boolean drawViewportsFirst);

    ZSoft::Boolean    
    modelType                  () const;

    ZcDbObjectId
    shadePlotId                () const;

    Zcad::ErrorStatus
    setShadePlot               (const ZcDbPlotSettings::ShadePlotType type,
                                const ZcDbObjectId shadePlotId);

    bool
    plotWireframe              () const;

    bool
    plotAsRaster               () const;

};

#pragma pack(pop)

#endif
