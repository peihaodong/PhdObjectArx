

#ifndef ZCPLPLOTCONFIG_H
#define ZCPLPLOTCONFIG_H

#include "zacpl.h"

#include "zacarray.h"
#include "zgepnt2d.h"
#include "zgeblok2d.h"
#include "zdblayout.h"

class ZRPlot_Config;
class ZRMedia_Size;
class ZRMedia_Description;

class ZcPlPlotConfig : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPlotConfig)

public:
    enum PlotToFileCapability {
        kNoPlotToFile       = 0,
        kPlotToFileAllowed  = 1,
        kMustPlotToFile     = 2
    };
        
public:
    ZCPL_PORT virtual ~ZcPlPlotConfig();

    ZCPL_PORT virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* pSrc);

    ZCPL_PORT virtual void getDescriptionFields(ZTCHAR*& pDriverName,
                                                ZTCHAR*& pLocationName,
                                                ZTCHAR*& pComment,
                                                ZTCHAR*& pPortName,
                                                ZTCHAR*& pServerName,
                                                ZTCHAR*& pTagLine) const;

    ZCPL_PORT virtual const ZTCHAR* deviceName() const;

    ZCPL_PORT virtual const ZTCHAR* fullPath() const;

    ZCPL_PORT virtual unsigned int maxDeviceDPI() const;

    ZCPL_PORT virtual unsigned long deviceType() const;

    ZCPL_PORT virtual void getCanonicalMediaNameList(ZcArray<ZTCHAR*> &mediaList) const;

    ZCPL_PORT virtual void getLocalMediaName(const ZTCHAR* pCanonicalMediaName,
                                             ZTCHAR* &pLocalMediaName) const;

    ZCPL_PORT virtual void getMediaBounds(const ZTCHAR* pCanonicalMediaName,
                                          ZcGePoint2d &pageSize, 
                                          ZcGeBoundBlock2d &printableArea) const;

    ZCPL_PORT virtual void refreshMediaNameList();

    ZCPL_PORT virtual bool isPlotToFile() const;
    ZCPL_PORT virtual Zcad::ErrorStatus setPlotToFile(bool bPlotToFile);

    ZCPL_PORT virtual Zcad::ErrorStatus getDefaultFileExtension(const ZTCHAR*& pDefaultExtension) const;

    ZCPL_PORT virtual PlotToFileCapability plotToFileCapability() const;

    ZCPL_PORT virtual bool saveToPC3(const ZTCHAR* pPC3Name);

    ZCPL_PORT virtual ZRPlot_Config* plotConfig() const;

    ZCPL_PORT virtual unsigned long isCustomPossible(double width, double height, 
                                  bool bIsDimensional, bool bIsSheet, int dpi, const
                                  ZTCHAR * pPC3Dir) const;

    ZCPL_PORT virtual bool matchMediaSize(double page_x, double page_y,
                                  double printable_w, double printable_h, 
                                  ZcDbLayout::PlotPaperUnits units, 
                                  bool bIsSheet, int dpi, 
                                  const ZTCHAR * pTargetCanonicalName,
                                  ZTCHAR *& pNearestSizeName,
                                  ZTCHAR *& pLocalizedName,
                                  double & scaleFactor);

    ZCPL_PORT virtual Zcad::ErrorStatus makeCustomMediaFromSizeDesc( 
        ZRMedia_Size * pSize, ZRMedia_Description * pDesc,
        bool bSameDriver, bool bSavePC3,
        const ZTCHAR * pSourceEntry, const ZTCHAR * pSourceName,
        ZTCHAR *& pCanonicalSizeName, ZTCHAR *& pLocalizedSizeName,
        ZTCHAR *& pPMPPath, ZTCHAR *& pPC3Path, int dpi, double & scaleFactor);

protected:
    friend class ZcPlPlotConfigManagerImp;
    friend class ZcPlPlotInfoImp;
    friend class ZcPlPlotInfoValidatorImp;
    ZcPlPlotConfig(ZRPlot_Config* pConfig, const ZTCHAR* pDevName,
                   const ZTCHAR* pFullPath, unsigned long nDevType);

    ZcPlPlotConfig(const ZcPlPlotConfig* pOther);

private:
    ZcPlPlotConfig();

};

#endif 
