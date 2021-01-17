

#ifndef   _ZCPLPLOTENGINE_H
#define   _ZCPLPLOTENGINE_H

#include "zAdAChar.h"
#include "zacpl.h"
#include "zacplobject.h"

class ZcViewport;
class PlotEnvironment;
class ZcPlPlotProgress;
class ZcPlPlotInfo;
class ZcDbPlotSettings;
class ZcPlPlotConfig;

enum PreviewStatus {
    kNormal = 0,
    kPlot,
    kCancel,
    kNext,
    kPrevious
};

struct ZCPL_PREVIEWENDPLOT {
    PreviewStatus nStatus;
};

class ZcPlPlotPageInfo : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPlotPageInfo);

public:
    ZCPL_PORT ZcPlPlotPageInfo();
    ZCPL_PORT virtual ~ZcPlPlotPageInfo();

    ZCPL_PORT ZSoft::Int32 entityCount() const;
    ZCPL_PORT ZSoft::Int32 rasterCount() const;
    ZCPL_PORT ZSoft::Int32 oleObjectCount() const;
    ZCPL_PORT ZSoft::Int32 gradientCount() const;
    ZCPL_PORT ZSoft::Int32 shadedViewportType() const;
};

#ifndef _ZSOFT_WINDOWS_
class ZCPL_PORT ZcPlPlotEngine{
#else
class ZSOFT_NO_VTABLE ZcPlPlotEngine {
#endif 
public:
    virtual Zcad::ErrorStatus beginPlot(ZcPlPlotProgress* pPlotProgress, void* pParams = NULL);
    virtual Zcad::ErrorStatus endPlot(void* pParams = NULL);

    virtual Zcad::ErrorStatus beginDocument(ZcPlPlotInfo& plotInfo, 
                                            const ZTCHAR * pDocname,
                                            void *pParams = NULL,
                                            ZSoft::Int32 nCopies = 1, 
                                            bool bPlotToFile = false, 
                                            const ZTCHAR * pFileName = NULL);
    virtual Zcad::ErrorStatus endDocument(void* pParams = NULL);

    virtual Zcad::ErrorStatus beginPage(ZcPlPlotPageInfo& pageInfo, 
                                        ZcPlPlotInfo& plotInfo, 
                                        bool bLastPage, 
                                        void* pParams = NULL);
    virtual Zcad::ErrorStatus endPage(void* pParams = NULL);
    
    virtual Zcad::ErrorStatus beginGenerateGraphics(void* pParams = NULL);
    virtual Zcad::ErrorStatus beginGenerateGraphics(ZcViewport*& pViewport, void* pParams = NULL);
    virtual Zcad::ErrorStatus endGenerateGraphics(void* pParams = NULL);
    
    virtual void destroy();
    virtual bool isBackgroundPackaging() const;
};

#endif 
