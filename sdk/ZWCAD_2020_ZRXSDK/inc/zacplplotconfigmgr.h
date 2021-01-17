

#ifndef ZCPLPLOTCONFIGMGR_H
#define ZCPLPLOTCONFIGMGR_H

#include "zAdAChar.h"
#include "zacpl.h"
#include "zacarray.h"
#include "zacplobject.h"

class ZcPlPlotConfig;
class ZRThin_Plot_Config_Manager;
class ZRError_Handler;

enum DeviceType {
    kSystemPrinter = 0,
    kPC3File = 1,
    kOneOffConfig = 2,      
    kUninitialized = -1
};

class ZcPlPlotConfigInfo : public ZcPlObject
{
public:
    ZCPL_PORT ZcPlPlotConfigInfo();
    ZCPL_PORT ZcPlPlotConfigInfo(const ZTCHAR * pDevName,
                                 const ZTCHAR * pFullPath,
                                 DeviceType devType);
    
    ZCPL_PORT ZcPlPlotConfigInfo(const ZcPlPlotConfigInfo &copy);

    ZCPL_PORT Zcad::ErrorStatus copyFrom(const ZcRxObject* pSrc);

    ZCPL_PORT const ZcPlPlotConfigInfo& operator=(const ZcPlPlotConfigInfo& src);

    ZCPL_PORT virtual ~ZcPlPlotConfigInfo();

    ZCPL_DECLARE_MEMBERS(ZcPlPlotConfigInfo);

    ZCPL_PORT const ZTCHAR * fullPath() const;

    ZCPL_PORT void setFullPath(const ZTCHAR * pPath);

    ZCPL_PORT const ZTCHAR * deviceName() const;

    ZCPL_PORT void setDeviceName(const ZTCHAR * pDevName);

    ZCPL_PORT DeviceType deviceType() const;

    ZCPL_PORT void setDeviceType(DeviceType devType);
};

class ZSOFT_NO_VTABLE ZcPlPlotConfigManager
{
public:

    enum RefreshCode {
        kAll,
        kRefreshDevicesList,
        kRefreshStyleList,
        kRefreshSystemDevicesList,
        kRefreshPC3DevicesList
    };
    
    enum StyTypes {
        kUndefined      = 0,
        kRegular        = 0x01,
        kTranslation    = 0x02,
        kColorDep       = 0x04,
        kAllTypes       = 0x07
    };
    
    enum StdConfigs {
        kNoneDevice,
        kDefaultWindowsSysPrinter,
        kDWF6ePlot,
        kDWFePlotOptForPlotting,
        kDWFePlotOptForViewing,
        kPublishToWebDWF,
        kPublishToWebJPG,
        kPublishToWebPNG,
		kDWFxePlot,
		kPublishToWebDWFx,
		kPDFePlot,
		kPDFePlotGeneralDocs,
		kPDFePlotHighQuality,
		kPDFePlotSmallerFile,
		kPDFePlotWebMobile,
    };

    virtual bool getDevicesList(ZcArray<ZcPlPlotConfigInfo, 
        ZcArrayObjectCopyReallocator <ZcPlPlotConfigInfo> > &deviceList);

    virtual bool getStyleList(ZcArray<ZTCHAR *> &list,
                              long styType = kAllTypes);

    virtual void refreshList(RefreshCode refreshCode = kAll);

    virtual Zcad::ErrorStatus getCurrentConfig(ZcPlPlotConfig*& pConfig);

    virtual Zcad::ErrorStatus setCurrentConfig(ZcPlPlotConfig*& pConfig, 
                                               const ZTCHAR * pDeviceName);

    virtual const ZTCHAR * getStdConfigName(StdConfigs stdConfig);

    virtual ZRThin_Plot_Config_Manager* thinPltCfgMgr();

    virtual ZRError_Handler* errorHandler();

    virtual ZRError_Handler* zcadErrorHandler(); 
};

ZCPL_PORT ZcPlPlotConfigManager* __stdcall zcplPlotConfigManagerPtr();
#define zcplPlotConfigManager zcplPlotConfigManagerPtr()

#endif 
