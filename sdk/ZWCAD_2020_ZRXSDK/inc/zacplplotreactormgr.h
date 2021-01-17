

#ifndef ZCPLPLOTREACTORMGR_H
#define ZCPLPLOTREACTORMGR_H

#include "zacpl.h"

class ZSOFT_NO_VTABLE ZcPlPlotReactorMgr
{
public:

    ZCPL_PORT void addReactor(ZcPlPlotReactor* pReactor);

    ZCPL_PORT void removeReactor(ZcPlPlotReactor* pReactor);
};

ZCPL_PORT ZcPlPlotReactorMgr* __stdcall zcplPlotReactorMgrPtr();
#define zcplPlotReactorMgr zcplPlotReactorMgrPtr()

#endif 
