

#ifndef ZCPLPLOTREACTOR_H
#define ZCPLPLOTREACTOR_H

#include "zAdAChar.h"
#include "zacpl.h"
#include "zacplobject.h"

class ZcPlPlotInfo;
class ZcPlPlotPageInfo;
class ZcPlPlotProgress;

class ZcPlPlotReactor : public ZcRxObject 
{
public:

    enum PlotType {
        kPlot,
        kPreview,
        kBackgroundPackaging,
        kBackgroundPlot
    };

    ZCPL_PORT virtual void beginPlot(ZcPlPlotProgress* pPlotProgress, PlotType type);

    ZCPL_PORT virtual void beginDocument(ZcPlPlotInfo& plotInfo,
                                         const ZTCHAR * pDocname,
                               ZSoft::Int32 nCopies = 1, bool bPlotToFile = false,
                               const ZTCHAR * pFilename = NULL);

    ZCPL_PORT virtual void beginPage(ZcPlPlotPageInfo& pageInfo, ZcPlPlotInfo& plotInfo,
                           bool bLastPage);

    ZCPL_PORT virtual void endPage(ZcPlPlotProgress::SheetCancelStatus status);

    ZCPL_PORT virtual void endDocument(ZcPlPlotProgress::PlotCancelStatus status);

    ZCPL_PORT virtual void endPlot(ZcPlPlotProgress::PlotCancelStatus status);

    ZCPL_PORT virtual void plotCancelled();

    ZCPL_PORT virtual void pageCancelled();

    ZCPL_PORT virtual ~ZcPlPlotReactor();
    
protected:
    ZCPL_PORT ZcPlPlotReactor();
};

#endif 
