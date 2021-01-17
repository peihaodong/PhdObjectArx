

#ifndef   _ZCPLPLOTFACTORY_H
#define   _ZCPLPLOTFACTORY_H

#include "zacpl.h"

class ZcPlPlotEngine;

class ZcPlPlotFactory
{
public:

    enum PreviewEngineFlags {
        kShowPlot            = 0x0001,  
        kShowNextSheet       = 0x0002,  
        kShowPreviousSheet   = 0x0004   
    };

    static ZCPL_PORT Zcad::ErrorStatus createPublishEngine(ZcPlPlotEngine *& pEngine);
    static ZCPL_PORT Zcad::ErrorStatus createPreviewEngine(ZcPlPlotEngine *& pPreview, 
                                                           long nPreviewFlags = kShowPlot);
};

enum ProcessPlotState
{
    kNotPlotting = 0,       
    kForegroundPlotting,    
    kBackgroundPlotting     
                            
};

ZCPL_PORT ProcessPlotState __stdcall zcplProcessPlotState();

#endif 
