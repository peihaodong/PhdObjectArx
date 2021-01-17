

#ifndef   _ZCPLPLOTINFO_H
#define   _ZCPLPLOTINFO_H

#include "zacplobject.h"

class ZcPlPlotConfig;
class ZcRxObject;
class ZcDbPlotSettings;

class ZcPlPlotInfo : public ZcPlObject
{
public:
    ZCPL_PORT ZcPlPlotInfo();
    ZCPL_PORT virtual ~ZcPlPlotInfo();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotInfo);
    
public:

    enum MergeStatus {
        kNoChanges              = 0x00000000,
        kPlotCfgName            = 0x00000001,
        kPlotPaperMargins       = 0x00000002,
        kPlotPaperSize          = 0x00000004,
        kCanonicalMediaName     = 0x00000008,
        kPlotOrigin             = 0x00000010,
        kPlotPaperUnits         = 0x00000020,
        kPlotViewportBorders    = 0x00000040,
        kPlotPlotStyles         = 0x00000080,
        kShowPlotStyles         = 0x00000100,
        kPlotRotation           = 0x00000200,
        kPlotCentered           = 0x00000400,
        kPlotHidden             = 0x00000800,
        kShadePlot              = 0x00001000,
        kShadePlotResLevel      = 0x00002000,
        kShadePlotCustomDPI     = 0x00004000,
        kPlotType               = 0x00008000,
        kPlotWindowArea         = 0x00010000,
        kPlotViewName           = 0x00020000,
        kScale                  = 0x00040000,
        kCurrentStlyeSheet      = 0x00080000,
        kScaleLineWeights       = 0x00100000,
        kPrintLineWeights       = 0x00200000,
        kDrawViewportsFirst     = 0x00400000
    };
    
    ZCPL_PORT Zcad::ErrorStatus copyFrom(const ZcRxObject* pOther);

    ZCPL_PORT void setLayout(ZcDbObjectId& layoutId);

    ZCPL_PORT ZcDbObjectId layout() const;

    ZCPL_PORT void setOverrideSettings(const ZcDbPlotSettings* pOverrides);

    ZCPL_PORT const ZcDbPlotSettings* overrideSettings() const;

    ZCPL_PORT void setDeviceOverride(const ZcPlPlotConfig* pconf);

    ZCPL_PORT const ZcDbPlotSettings* validatedSettings() const;

    ZCPL_PORT Zcad::ErrorStatus setValidatedSettings(const ZcDbPlotSettings* pValidatedSettings);

    ZCPL_PORT const ZcPlPlotConfig* validatedConfig() const;

    ZCPL_PORT void setValidatedConfig(const ZcPlPlotConfig* pConfig);

    ZCPL_PORT const ZcPlPlotConfig* deviceOverride() const;

    ZCPL_PORT bool isValidated() const;

    ZCPL_PORT unsigned long mergeStatus() const;

    ZCPL_PORT bool isCompatibleDocument(const ZcPlPlotInfo* pOtherInfo) const;
};

#endif 
