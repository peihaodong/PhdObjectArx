

#ifndef   _ZCRX_EVENT_H__
#define   _ZCRX_EVENT_H__

#include "zacarray.h"
#include "zrxobject.h"
#include "zAdAChar.h"
#include "zdbid.h"
#pragma pack (push, 8)

#define ZCRX_EVENT_OBJ ZCRX_T("ZcRxEvent")

class ZcDbDatabase;
class ZcGeMatrix3d;
class ZcDbIdMapping;
class ZcGePoint3d;

enum ZcXrefSubCommand {
    kAttach = 0,
    kBind = 1,
    kDetach = 2,
    kOverlay = 3,
    kPath = 4,
    kReload = 5,
    kResolve = 6,
    kUnload = 7,
    kXBind = 8
};

class ZcRxEventReactor: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcRxEventReactor);

    virtual void dwgFileOpened(ZcDbDatabase*, ZTCHAR * fileName);
    virtual void initialDwgFileOpenComplete(ZcDbDatabase*);
    virtual void databaseConstructed(ZcDbDatabase*);
    virtual void databaseToBeDestroyed(ZcDbDatabase*);

    virtual void beginSave    (ZcDbDatabase*, const ZTCHAR * pIntendedName);
    virtual void saveComplete (ZcDbDatabase*, const ZTCHAR * pActualName);
    virtual void abortSave    (ZcDbDatabase*);

    virtual void beginDxfIn      (ZcDbDatabase*);
    virtual void abortDxfIn      (ZcDbDatabase*);
    virtual void dxfInComplete   (ZcDbDatabase*);
    
    virtual void beginDxfOut     (ZcDbDatabase*);
    virtual void abortDxfOut     (ZcDbDatabase*);
    virtual void dxfOutComplete  (ZcDbDatabase*);

    virtual void beginInsert(ZcDbDatabase* pTo, const ZTCHAR * pBlockName,
                             ZcDbDatabase* pFrom);
    virtual void beginInsert(ZcDbDatabase* pTo, const ZcGeMatrix3d& xform,
                             ZcDbDatabase* pFrom);
    virtual void otherInsert(ZcDbDatabase* pTo, ZcDbIdMapping& idMap,
                             ZcDbDatabase* pFrom);
    virtual void abortInsert(ZcDbDatabase* pTo);
    virtual void endInsert  (ZcDbDatabase* pTo);

    virtual void wblockNotice(ZcDbDatabase* pDb);
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom,
                             const ZcGePoint3d*& insertionPoint);
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom,
                             ZcDbObjectId blockId);
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom); 
    virtual void otherWblock(ZcDbDatabase* pTo, ZcDbIdMapping&,
                             ZcDbDatabase* pFrom);
    virtual void abortWblock(ZcDbDatabase* pTo);
    virtual void endWblock  (ZcDbDatabase* pTo);
    virtual void beginWblockObjects(ZcDbDatabase*, ZcDbIdMapping&);

    virtual void beginDeepClone       (ZcDbDatabase* pTo, ZcDbIdMapping&);
    virtual void beginDeepCloneXlation(ZcDbIdMapping&, Zcad::ErrorStatus*);
    virtual void abortDeepClone       (ZcDbIdMapping&);
    virtual void endDeepClone         (ZcDbIdMapping&);

    virtual void partialOpenNotice  (ZcDbDatabase* pDb);
    virtual void beginAttach (ZcDbDatabase* pTo, const ZTCHAR *,
                              ZcDbDatabase* pFrom);
    virtual void otherAttach (ZcDbDatabase* pTo, ZcDbDatabase* pFrom);
    virtual void abortAttach (ZcDbDatabase* pFrom);
    virtual void endAttach   (ZcDbDatabase* pTo);
    virtual void redirected  (ZcDbObjectId  newId, ZcDbObjectId oldId);
    virtual void comandeered (ZcDbDatabase* pTo, ZcDbObjectId id,
                              ZcDbDatabase* pFrom);
    virtual void beginRestore(ZcDbDatabase* pTo, const ZTCHAR *,
                              ZcDbDatabase* pFrom);
    virtual void abortRestore(ZcDbDatabase* pTo);
    virtual void endRestore  (ZcDbDatabase* pTo);

	virtual void xrefSubcommandBindItem   (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);
	virtual void xrefSubcommandAttachItem (ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath);
	virtual void xrefSubcommandOverlayItem(ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath);
	virtual void xrefSubcommandDetachItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);
	virtual void xrefSubcommandPathItem   (int activity, ZcDbObjectId blockId, const ZTCHAR* pNewPath);
	virtual void xrefSubcommandReloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);	
	virtual void xrefSubcommandUnloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);

    virtual void xrefSubCommandStart(ZcDbDatabase* pHostDb,
            ZcXrefSubCommand op, const ZcArray<ZcDbObjectId>& ids,
            const ZTCHAR* const* btrNames,
            const ZTCHAR* const* paths, bool& vetoOp);

    virtual void xrefSubCommandAborted(ZcDbDatabase* pHostDb,
            ZcXrefSubCommand op, const ZcArray<ZcDbObjectId>& ids,
            const ZTCHAR* const* btrNames,
            const ZTCHAR* const* paths);

	virtual void xrefSubCommandEnd(ZcDbDatabase* pHostDb,
			ZcXrefSubCommand op, const ZcArray<ZcDbObjectId>& ids,
			const ZTCHAR* const* btrNames, 
			const ZTCHAR* const* paths);
    virtual void preXrefLockFile(ZcDbDatabase* pDb,
            ZcDbObjectId btrId);
};

#define zcrxEvent ZcRxEvent::cast(zcrxSysRegistry()->at(ZCRX_EVENT_OBJ))

class ZcRxEvent: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcRxEvent);
    virtual void addReactor   (ZcRxEventReactor * newObj) = 0;
    virtual void removeReactor(ZcRxEventReactor * delObj) = 0;
};

#pragma pack (pop)
#endif
