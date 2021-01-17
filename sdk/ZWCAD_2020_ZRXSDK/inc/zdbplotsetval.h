

#ifndef ZD_DBPLOTSETVAL_H
#define ZD_DBPLOTSETVAL_H
#include "zAdAChar.h"

#pragma pack (push, 8)
template <class T, class R> class ZcArray;
class ZcDbPlotSettings;

typedef ZcDbPlotSettings::PlotPaperUnits PlotPaperUnits;
typedef ZcDbPlotSettings::PlotRotation   PlotRotation;
typedef ZcDbPlotSettings::PlotType       PlotType;
typedef ZcDbPlotSettings::StdScaleType   StdScaleType;

class ZcDbPlotSettingsValidator {
public:    
    virtual Zcad::ErrorStatus 
    setPlotCfgName            (ZcDbPlotSettings* pPlotSet,
                               const ZTCHAR * plotDeviceName,
                               const ZTCHAR * mediaName = NULL     ) = 0;
    virtual Zcad::ErrorStatus 
    setCanonicalMediaName     (ZcDbPlotSettings* pPlotSet,
                               const ZTCHAR * mediaName            ) = 0;
    virtual Zcad::ErrorStatus
    setPlotOrigin             (ZcDbPlotSettings *pPlotSet, 
                               const double xCoordinate,
                               const double yCoordinate         ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotPaperUnits         (ZcDbPlotSettings* pPlotSet,
                               const PlotPaperUnits units       ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotRotation           (ZcDbPlotSettings* pPlotSet,
                               const PlotRotation rotationType  ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotCentered           (ZcDbPlotSettings* pPlotSet,
                               ZSoft::Boolean isCentered        ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotType               (ZcDbPlotSettings* pPlotSet,
                               const PlotType plotAreaType      ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotWindowArea         (ZcDbPlotSettings* pPlotSet,
                               const double xmin,
                               const double ymin,
                               const double xmax,
                               const double ymax                ) = 0;
    virtual Zcad::ErrorStatus 
    setPlotViewName           (ZcDbPlotSettings* pPlotSet,
                               const ZTCHAR * viewName             ) = 0;
    virtual Zcad::ErrorStatus 
    setUseStandardScale       (ZcDbPlotSettings* pPlotSet,
                               ZSoft::Boolean useStandard       ) = 0;
    virtual Zcad::ErrorStatus 
    setCustomPrintScale       (ZcDbPlotSettings* pPlotSet,
                               const double numerator,
                               const double denominator         ) = 0;
    virtual Zcad::ErrorStatus 
    setCurrentStyleSheet      (ZcDbPlotSettings* pPlotSet,
                               const ZTCHAR * styleSheetName       ) = 0;
    virtual Zcad::ErrorStatus 
    setStdScaleType           (ZcDbPlotSettings* pPlotSet,
                               const StdScaleType scaleType     ) = 0;
    virtual Zcad::ErrorStatus 
    setStdScale               (ZcDbPlotSettings* pPlotSet,
                               const double standardScale       ) = 0;
    virtual Zcad::ErrorStatus               
    plotDeviceList            (ZcArray<const ZTCHAR *> & deviceList) = 0;

    virtual Zcad::ErrorStatus               
    canonicalMediaNameList    (ZcDbPlotSettings* pPlotSet,
                               ZcArray<const ZTCHAR *> & mediaList ) = 0;
    virtual Zcad::ErrorStatus
    getLocaleMediaName        (ZcDbPlotSettings *pPlotSet,
                               const ZTCHAR *  canonicalName,
                               const ZTCHAR *& localeName          ) = 0;
    virtual Zcad::ErrorStatus
    getLocaleMediaName        (ZcDbPlotSettings *pPlotSet,
                               int index,
                               const ZTCHAR *& localeName          ) = 0;
    virtual Zcad::ErrorStatus
    setClosestMediaName       (ZcDbPlotSettings* pPlotSet,
                               const double paperWidth,
                               const double paperHeight,
                               const PlotPaperUnits units,       
                               ZSoft::Boolean matchPrintableArea) = 0;
    virtual Zcad::ErrorStatus               
    plotStyleSheetList        (ZcArray<const ZTCHAR *> & styleList ) = 0;

    virtual void              
    refreshLists              (ZcDbPlotSettings* pPlotSet       ) = 0;

    virtual void
    setZoomToPaperOnUpdate    (ZcDbPlotSettings* pPlotSet,
                               ZSoft::Boolean doZoom            ) = 0;

    virtual Zcad::ErrorStatus
    setDefaultPlotConfig       (ZcDbPlotSettings* pPlotSet      ) = 0;
};
#pragma pack (pop)
#endif 
