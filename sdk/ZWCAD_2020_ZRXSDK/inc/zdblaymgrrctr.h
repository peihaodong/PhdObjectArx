
#ifndef   _ZCDB_LAYOUT_MANAGER_REACTOR_H
#define   _ZCDB_LAYOUT_MANAGER_REACTOR_H

#include "zrxobject.h"
#include "zdbid.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

class ZcDbLayoutManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayoutManagerReactor);

    virtual void layoutCreated(const ZTCHAR * newLayoutName,
                               const ZcDbObjectId& layoutId);
    virtual void layoutToBeRemoved(const ZTCHAR * layoutName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutRemoved(const ZTCHAR * layoutName,
                               const ZcDbObjectId& layoutId);
    virtual void abortLayoutRemoved(const ZTCHAR * layoutName,
                                    const ZcDbObjectId& layoutId);
    virtual void layoutToBeCopied(const ZTCHAR * layoutName,
                                  const ZcDbObjectId& oldLayoutId);
    virtual void layoutCopied(const ZTCHAR * oldLayoutName,
                              const ZcDbObjectId& oldLayoutId,
                              const ZTCHAR * newLayoutname,
                              const ZcDbObjectId& newLayoutId);
    virtual void abortLayoutCopied(const ZTCHAR * layoutName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutToBeRenamed(const ZTCHAR * oldName,
                                   const ZTCHAR * newName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutRenamed(const ZTCHAR * oldName,
                               const ZTCHAR * newName,
                               const ZcDbObjectId& layoutId);
    virtual void abortLayoutRename(const ZTCHAR * oldName,
                                   const ZTCHAR * newName,
                                   const ZcDbObjectId& layoutId);
    virtual void layoutSwitched(const ZTCHAR * newLayoutname,
                                const ZcDbObjectId& newLayoutId);
    virtual void plotStyleTableChanged(const ZTCHAR * newTableName,
                                       const ZcDbObjectId& layoutId);
    virtual void layoutsReordered();
	virtual void refreshLayoutTabs();
};

#pragma pack (pop)
#endif 
