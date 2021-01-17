

#ifndef   _ZCED_H
#define   _ZCED_H

#include "zadesk.h"
#include "zrxnames.h"
#include "zrxevent.h"

#pragma pack (push, 8)

struct IDispatch;
#define ZCED_SERVICES  ZCRX_T("ZcEdServices")
#define ZCED_EDITOR_OBJ ZCRX_T("ZcEditor")

enum ZcadContextMenuMode {
    kDefault = 0,           
    kEdit,                  
    kCommand,               
    kHotGrip,               
    kOsnap,
#ifndef _ZSOFT_WINDOWS_
	kCMPaperSpace
#endif 
};

enum xrefSubcommandActivities
{    
    kStart = 0,
    kStartItem = 2,
    kEndItem = 3,
    kEnd = 4,
    kWillAbort = 5,
    kAborted = 6,
    kStartXBindBlock = 7,
    kStartXBindSymbol = 8
};

enum undoSubcommandActivities
{
    kNone = 0,
    kOne = 1,
    kAll = 2
};

#pragma pack (pop)
#include "zaccmd.h"
#pragma pack (push, 8)

#if defined(__cplusplus)

struct ZcEdCommandStruc;
class ZcString;

extern "C" {
#endif

int zcedCmdLookup(const ZTCHAR* cmdStr, int globalLookup,
                  ZcEdCommandStruc* retStruc,
                  int skipUndef = FALSE);

int zcedCmdLookup2(const ZTCHAR* cmdStr, int globalLookup,
                   ZcEdCommandStruc* retStruc,
                   int sf = ZCRX_CMD_DEFUN);

int zcedCmdUndefine(const ZTCHAR* cmdStr, int undefIt);

int zcedPopCommandDirectory(const ZTCHAR* cmdDirName);

class ZcApDocument;
Zcad::ErrorStatus zcedGetCommandForDocument(ZcApDocument* pDoc,
                                            ZTCHAR*& pGlobalCmdName);

ZSoft::Boolean zcedSetOLELock(int handle, int flags=0);

ZSoft::Boolean zcedClearOLELock(int handle);

void zcedPostCommandPrompt();
 
#if defined(__cplusplus)

}

Zcad::ErrorStatus zcedSyncFileOpen(const ZTCHAR *pszFileToOpen,
                                   const wchar_t* wszPassword = NULL);

ZSoft::Boolean zcedSetColorDialog(int& nColor, ZSoft::Boolean bAllowMetaColor,
    int nCurLayerColor);

ZSoft::Boolean zcedSetColorDialogTrueColor( ZcCmColor& color, ZSoft::Boolean bAllowMetaColor,
                                           const ZcCmColor& curLayerColor, ZcCm::DialogTabs tabs = (ZcCm::DialogTabs)(ZcCm::kACITab | ZcCm::kTrueColorTab  | ZcCm::kColorBookTab) );
#ifdef _ZSOFT_WINDOWS_
typedef void (WINAPI* ZcEdColorDialogCallbackFunction)(void *pCallbackData, const ZcCmColor& newColor);
ZSoft::Boolean zcedSetColorDialogTrueColorWithCallback( ZcCmColor& color,
                                                        ZSoft::Boolean bAllowMetaColor,
                                                        const ZcCmColor& curLayerColor,
                                                        ZcCm::DialogTabs tabs = (ZcCm::DialogTabs)(ZcCm::kACITab | ZcCm::kTrueColorTab  | ZcCm::kColorBookTab),
                                                        ZcEdColorDialogCallbackFunction callback = NULL,
														void * pCallbackData = NULL);
#endif

ZSoft::Boolean zcedSetColorPrompt( ZTCHAR* promptString,
                                   ZcCmColor& color,
                                   ZSoft::Boolean bAllowMetaColor);

ZSoft::Boolean zcedIsMenuGroupLoaded(const ZTCHAR *pszGroupName);
bool zcedLoadPartialMenu(const TCHAR* pszMenuFile);

void zcedSendModelessOperationStart(const ZTCHAR* strContext);
void zcedSendModelessOperationEnded(const ZTCHAR* strContext);

void zcedUpdateDisplay();

void zcedUpdateDisplayPause (bool bEnable);

bool zcedIsUpdateDisplayPaused (void);

ZSoft::Boolean zcedInitDialog(ZSoft::Boolean useDialog = ZSoft::kTrue);

void
zcedDisableDefaultZRXExceptionHandler(ZSoft::Boolean disable = ZSoft::kTrue);

Zcad::ErrorStatus zcedVportTableRecords2Vports();

Zcad::ErrorStatus zcedVports2VportTableRecords();

Zcad::ErrorStatus
zcedVPLayer(const ZcDbObjectId& vpId, const ZcDbObjectIdArray& layerIds,
    ZcDb::VpFreezeOps operation);

void zcedRegenLayers(const ZcDbObjectIdArray& layerIds, int nParam1, int nParam2);

#define zcedServices  \
ZcEdServices::cast(zcrxServiceDictionary->at(ZCED_SERVICES))

class ZcEdServices: public ZcRxService 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdServices);
    virtual ZcEdCommand* newZcEdCommand(ZcRxFunctionPtr cmdFcnAddr,
        ZSoft::Int32 cmdFlags) const = 0;
};

class ZcDbDatabase;

class ZcEditorReactor: public ZcRxEventReactor 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEditorReactor);
    ZcEditorReactor() : mVeto(0) {}

    virtual void unknownCommand  (const ZTCHAR* cmdStr, ZcDbVoidPtrArray *al);
    virtual void commandWillStart(const ZTCHAR* cmdStr);
    virtual void commandEnded    (const ZTCHAR* cmdStr);
    virtual void commandCancelled(const ZTCHAR* cmdStr);
    virtual void commandFailed   (const ZTCHAR* cmdStr);

    virtual void lispWillStart   (const ZTCHAR* firstLine);
    virtual void lispEnded       ();
    virtual void lispCancelled   ();

    ZSOFT_DEPRECATED virtual void beginClose(ZcDbDatabase* pDwg);

    virtual void beginDxfIn      (ZcDbDatabase*);
    virtual void abortDxfIn      (ZcDbDatabase*);
    virtual void dxfInComplete   (ZcDbDatabase*);
    
    virtual void beginDxfOut     (ZcDbDatabase*);
    virtual void abortDxfOut     (ZcDbDatabase*);
    virtual void dxfOutComplete  (ZcDbDatabase*);

    virtual void beginDwgOpen    (ZTCHAR* filename);
    virtual void endDwgOpen      (const ZTCHAR* filename, ZcDbDatabase* pDb);
    virtual void initialDwgFileOpenComplete(ZcDbDatabase* pDwg);

    virtual void dwgFileOpened(ZcDbDatabase*, ZTCHAR* fileName);
    virtual void databaseConstructed(ZcDbDatabase*);
    virtual void databaseToBeDestroyed(ZcDbDatabase*);
    virtual void beginSave    (ZcDbDatabase*, const ZTCHAR* pIntendedName);
    virtual void saveComplete (ZcDbDatabase*, const ZTCHAR* pActualName);
    virtual void abortSave    (ZcDbDatabase*);

    virtual void beginInsert(ZcDbDatabase* pTo, const ZTCHAR* pBlockName,
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

    virtual void beginDeepClone       (ZcDbDatabase* pTo, ZcDbIdMapping&);
    virtual void beginDeepCloneXlation(ZcDbIdMapping&, Zcad::ErrorStatus*);
    virtual void abortDeepClone       (ZcDbIdMapping&);
    virtual void endDeepClone         (ZcDbIdMapping&);

    virtual void sysVarChanged        (const ZTCHAR* varName, ZSoft::Boolean success);
    virtual void sysVarWillChange     (const ZTCHAR* varName);

    virtual void beginAttach (ZcDbDatabase* pTo, const ZTCHAR*,
                              ZcDbDatabase* pFrom);
    virtual void otherAttach (ZcDbDatabase* pTo, ZcDbDatabase* pFrom);
    virtual void abortAttach (ZcDbDatabase* pFrom);
    virtual void endAttach   (ZcDbDatabase* pTo);
    virtual void redirected  (ZcDbObjectId  newId, ZcDbObjectId oldId);
    virtual void comandeered (ZcDbDatabase* pTo, ZcDbObjectId id,
                              ZcDbDatabase* pFrom);
    virtual void beginRestore(ZcDbDatabase* pTo, const ZTCHAR*,
                              ZcDbDatabase* pFrom);
    virtual void abortRestore(ZcDbDatabase* pTo);
    virtual void endRestore  (ZcDbDatabase* pTo);

    virtual void xrefSubcommandBindItem   (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);
    virtual void xrefSubcommandAttachItem (ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath);
    virtual void xrefSubcommandOverlayItem(ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath);
    virtual void xrefSubcommandDetachItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);
    virtual void xrefSubcommandPathItem   (int activity, ZcDbObjectId blockId,
                                           const ZTCHAR* pNewPath);
    virtual void xrefSubcommandReloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);
    virtual void xrefSubcommandUnloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId);

    virtual void undoSubcommandAuto       (int activity, ZSoft::Boolean state);
    virtual void undoSubcommandControl    (int activity, int option);
    virtual void undoSubcommandBegin      (int activity);
    virtual void undoSubcommandEnd        (int activity);
    virtual void undoSubcommandMark       (int activity);
    virtual void undoSubcommandBack       (int activity);
    virtual void undoSubcommandNumber     (int activity, int num);

    virtual void pickfirstModified();
    virtual void layoutSwitched(const ZTCHAR* newLayoutName);

    virtual void docFrameMovedOrResized(ZSoft::LongPtr hwndDocFrame, bool bMoved);
    virtual void mainFrameMovedOrResized(ZSoft::LongPtr hwndMainFrame, bool bMoved);

    virtual void beginDoubleClick(const ZcGePoint3d& clickPoint);
    virtual void beginRightClick(const ZcGePoint3d& clickPoint);

    virtual void toolbarBitmapSizeWillChange(ZSoft::Boolean bLarge);
    virtual void toolbarBitmapSizeChanged(ZSoft::Boolean bLarge);

    virtual void beginWblockObjects (ZcDbDatabase* pFrom, ZcDbIdMapping& );

    virtual void partialOpenNotice(ZcDbDatabase* pDb);
    virtual void objectsLazyLoaded(const ZcDbObjectIdArray& idArray);

    virtual void beginQuit();
    virtual void quitAborted();
    virtual void quitWillStart();

    virtual void modelessOperationWillStart(const ZTCHAR* contextStr);
    virtual void modelessOperationEnded(const ZTCHAR* contextStr);

    virtual void cmdIUnkModified(const ZTCHAR* strCommand);
    virtual Zcad::ErrorStatus xrefSubCommandStart(
            ZcXrefSubCommand subcmd,
            const ZcDbObjectIdArray& btrIds,
            const ZTCHAR* const * btrNames,
            const ZTCHAR* const * paths);
    virtual void preXrefLockFile(ZcDbObjectId btrId);

    virtual void viewChanged();

protected:
    Zcad::ErrorStatus veto();

private:
    ZSoft::UInt8 mVeto;

friend class ZcEditorImp;
};

class ZcEditorReactor2 : public ZcEditorReactor
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEditorReactor2);

    virtual void beginDocClose(ZcDbDatabase* pDwg) {}

    virtual void docCloseAborted(ZcDbDatabase* pDwg) {}

    virtual void docCloseWillStart(ZcDbDatabase* pDwg) {}

    virtual void layoutToBeSwitched (const ZTCHAR *oldLayoutName, const ZTCHAR *newLayoutName) {}

    virtual void dwgViewResized (ZSoft::LongPtr hwndDwgView) {}

};

#define zcedEditor ZcEditor::cast(zcrxSysRegistry()->at(ZCED_EDITOR_OBJ))

class ZcEditor: public ZcRxEvent 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEditor);
    virtual void addReactor   (ZcRxEventReactor * newObj) = 0;
    virtual void removeReactor(ZcRxEventReactor * delObj) = 0;
};

class ZcEdUIContext : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdUIContext);
    virtual void* getMenuContext(const ZcRxClass *, 
                                 const ZcDbObjectIdArray&)=0;
    virtual void* getMenuContext(const ZcRxClass*,
                                 const ZcDbObjectIdArray&,
                                 const ZcArray<ZcDbFullSubentPathArray,
                                               ZcArrayObjectCopyReallocator<ZcDbFullSubentPathArray> >& subentIds);

    virtual void  onCommand(ZSoft::UInt32 ) =0;
    virtual void  OnUpdateMenu();
};

ZSoft::Boolean zcedAddObjectContextMenu(ZcRxClass *pClass, 
                                        ZcEdUIContext *pContext,
                                        const void *appId);
ZSoft::Boolean zcedRemoveObjectContextMenu(ZcRxClass *pClass, 
                                           ZcEdUIContext *pContext);

ZSoft::Boolean zcedAddDefaultContextMenu(ZcEdUIContext *pContext, 
                                         const void *appId, 
                                         const ZTCHAR* appName=NULL);
ZSoft::Boolean zcedRemoveDefaultContextMenu(ZcEdUIContext *pContext);

bool    zcedSetCMBaseAlias(LPCTSTR  strAlias, ZcadContextMenuMode mode);
LPCTSTR zcedGetCMBaseAlias(ZcadContextMenuMode mode);

Zcad::ErrorStatus zcedMspace();  
Zcad::ErrorStatus zcedPspace();  
Zcad::ErrorStatus zcedSetCurrentVPort(int vpnumber);
Zcad::ErrorStatus zcedSetCurrentVPort(const ZcDbViewport* pVp);

int zcedIsDragging(void);

Zcad::ErrorStatus
zcedSetCurrentView(ZcDbViewTableRecord *pVwRec, ZcDbViewport *pVP);

Zcad::ErrorStatus zcedRestoreCurrentView(const ZcDbObjectId& namedViewId);

Zcad::ErrorStatus zcedSetCurrentUCS(const ZcGeMatrix3d & mat);
Zcad::ErrorStatus zcedGetCurrentUCS(ZcGeMatrix3d& mat);
Zcad::ErrorStatus zcedRestorePreviousUCS();

class ZcDbFcf;
class ZcDbMText;

void zcedEditToleranceInteractive(ZcDbFcf* pTol);

int zcedEditMTextInteractive(ZcDbMText* pMText, bool useNewUI = false, bool allowTabs = false);

ZSoft::UInt32    zcedGetRGB(int color);

Zcad::ErrorStatus zcedGetCurrentSelectionSet(ZcDbObjectIdArray& sset);

Zcad::ErrorStatus zcedGetFullSubentPathsForCurrentSelection(
        const ZcDbObjectId&      selectedObject,
        ZcDbFullSubentPathArray& selectedSubentities);

class ZcDbHatch;
class ZcDbEntity;

#define zcedGetIDispatch ZwcadGetIDispatch
extern "C" IDispatch *zcedGetIDispatch (BOOL bAddRef);

ZcDbObjectId zcedActiveViewportId();

ZcDbObjectId zcedViewportIdFromNumber(int nVpNum);

int zcedNumberOfViewports();

ZcDbObjectId zcedGetCurViewportObjectId();

Zcad::ErrorStatus 
zcedConvertEntityToHatch(ZcDbHatch* pHatch, ZcDbEntity*& pEnt, bool transferId);

enum ZcEdDrawOrderCmdType {
    kDrawOrderNone = 0,
    kDrawOrderBottom,
    kDrawOrderTop,
    kDrawOrderBelow,
    kDrawOrderAbove
};

Zcad::ErrorStatus  zcedDrawOrderInherit(ZcDbObjectId parent,
                                        ZcDbObjectIdArray &childArray,
                                        ZcEdDrawOrderCmdType cmd);

Zcad::ErrorStatus
zcedCreateViewportByView(ZcDbDatabase *pDb,
                         const ZcDbObjectId& view, 
                         const ZcGePoint2d& location, 
                         double scale,
                         ZcDbObjectId& viewportId);

Zcad::ErrorStatus
zcedCreateEnhancedViewportOnDrop(const ZTCHAR *filename,
                                 const ZTCHAR *viewName,
                                 const ZcGePoint2d location,
                                 double scale,
                                 ZcDbObjectId labelBlockId,
                                 ZcDbObjectId& sheetViewId,
                                 ZcDbObjectId& viewportId);

Zcad::ErrorStatus
zcedCreateEnhancedViewportOnDropDWG(const ZTCHAR *filename,
                                    ZcDbExtents *extents,
                                    const ZcGePoint2d location,
                                    double scale,
                                    ZcDbObjectId labelBlockId,
                                    ZcDbObjectId& sheetViewId,
                                    ZcDbObjectId& viewportId);

const ZcString* zcedGetUnitsValueString (ZcDb::UnitsValue units);

bool zcdbCanonicalToSystemRange(int eUnits, const ZcString& strIn, ZcString& strOut);

bool zcdbSystemRangeToCanonical(int eUnits, const ZcString& strIn, ZcString& strOut);

Zcad::ErrorStatus zcedTraceBoundary(const ZcGePoint3d& seedPoint, bool detectIslands, ZcDbVoidPtrArray& resultingBoundarySet);

enum BlockEditModeFlags {
    kBlkEditModeNone   = 0x0,
    kBlkEditModeActive = 0x01,
    kBlkEditModeOpen   = 0x02,
    kBlkEditModeDirty  = 0x04
};

unsigned int zcedGetBlockEditMode();

#endif 

#pragma pack (pop)
#include "zdbjig.h"

#endif
