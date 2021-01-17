

#ifndef ZCDB_LSTATE_H
#define ZCDB_LSTATE_H

#include "zdbmain.h"
#include "zacarray.h"
#include "zAcString.h"

#pragma pack(push, 8)

class ZcDbImpLayerStateManager;
class ZcDbLayerStateManagerReactor;

class ZcDbLayerStateManager: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayerStateManager);
    
    ZcDbLayerStateManager();
    ZcDbLayerStateManager(ZcDbDatabase *pHostDb);
    virtual ~ZcDbLayerStateManager();

    enum LayerStateMask {
        kNone           = 0x0000,
        kOn             = 0x0001,
        kFrozen         = 0x0002,
        kLocked         = 0x0004,
        kPlot           = 0x0008,
        kNewViewport    = 0x0010,
        kColor          = 0x0020,
        kLineType       = 0x0040,
        kLineWeight     = 0x0080,
        kPlotStyle      = 0x0100,
        kCurrentViewport = 0x0200,
		kTransparency   = 0x0400,
        kAll            = kOn | kFrozen | kLocked | kPlot | kNewViewport |
                          kColor | kLineType | kLineWeight | kPlotStyle |
                          kCurrentViewport | kTransparency,

        kStateIsHidden  = 0x8000,        
        kLastRestored   = 0x10000,        
        kDecomposition  = kAll | 0x20000
    };

    enum {
        kUndefDoNothing = 0,
        kUndefTurnOff = 1,
        kUndefFreeze = 2,
        kRestoreAsOverrides = 4
    };

    bool                addReactor(ZcDbLayerStateManagerReactor * pReactor);
    bool                removeReactor(ZcDbLayerStateManagerReactor * pReactor);

    ZcDbObjectId        layerStatesDictionaryId(bool bCreateIfNotPresent=false);
    bool                hasLayerState(const ZTCHAR *sName);
    Zcad::ErrorStatus   saveLayerState(const ZTCHAR *sName, LayerStateMask mask);
    Zcad::ErrorStatus   restoreLayerState(const ZTCHAR *sName);
    Zcad::ErrorStatus   setLayerStateMask(const ZTCHAR *sName,
                                          LayerStateMask mask);
    Zcad::ErrorStatus   getLayerStateMask(const ZTCHAR *sName,
                                          LayerStateMask &returnMask);
    Zcad::ErrorStatus   deleteLayerState(const ZTCHAR *sName);
    Zcad::ErrorStatus   renameLayerState(const ZTCHAR *sName,
                                         const ZTCHAR *sNewName);
    Zcad::ErrorStatus   importLayerState(const ZTCHAR *sFilename);
    Zcad::ErrorStatus   importLayerState(const ZTCHAR *sFilename, ZcString & sName);

    Zcad::ErrorStatus   exportLayerState(const ZTCHAR *sNameToExport,
                                         const ZTCHAR *sFilename);

    Zcad::ErrorStatus   saveLayerState(const ZTCHAR *sName, LayerStateMask mask, const ZcDbObjectId& idVp);
    Zcad::ErrorStatus   restoreLayerState(const ZTCHAR *sName, const ZcDbObjectId& idVp, int nRestoreFlags = 0, const LayerStateMask* pClientMask = NULL);

    Zcad::ErrorStatus   setLayerStateDescription(const ZTCHAR* sName,
                                                 const ZTCHAR* sDesc);
    Zcad::ErrorStatus   getLayerStateDescription(const ZTCHAR* sName, ZTCHAR*& sDesc);
    bool                layerStateHasViewportData(const ZTCHAR* sName);
    
	Zcad::ErrorStatus   importLayerStateFromDb(const ZTCHAR *pStateName, ZcDbDatabase* pDb);
	Zcad::ErrorStatus   getLayerStateNames(ZcStringArray& lsArray, bool bIncludeHidden = true, bool bIncludeXref = true);
	Zcad::ErrorStatus   getLastRestoredLayerState(ZcString & sName, ZcDbObjectId &restoredLSId);
	Zcad::ErrorStatus   getLayerStateLayers(ZcStringArray& layerArray, const ZTCHAR* sName, bool bInvert = false);
	bool                compareLayerStateToDb(const ZTCHAR* sName, const ZcDbObjectId& idVp);
	Zcad::ErrorStatus   addLayerStateLayers(const ZTCHAR *sName, const ZcDbObjectIdArray& layerIds);
	Zcad::ErrorStatus   removeLayerStateLayers(const ZTCHAR *sName, const ZcStringArray& layerNames);
	bool                isDependentLayerState(const ZTCHAR *sName);
	ZcDbDatabase *      getDatabase() const;
	void				setDatabase(ZcDbDatabase* pDb);
	
private:
    friend class ZcDbImpDatabase;
    ZcDbImpLayerStateManager *mpImpLSM;
};

class ZcDbLayerStateManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLayerStateManagerReactor);

    virtual void layerStateCreated(const ZTCHAR * layerStateName,
                                   const ZcDbObjectId& layerStateId);
    virtual void layerStateCompareFailed(const ZTCHAR * layerStateName,
                                         const ZcDbObjectId& layerStateId);

    virtual void layerStateToBeRestored(const ZTCHAR * layerStateName,
                                        const ZcDbObjectId& layerStateId);
    virtual void layerStateRestored(const ZTCHAR * layerStateName,
                                    const ZcDbObjectId& layerStateId);
    virtual void abortLayerStateRestore(const ZTCHAR * layerStateName,
                                        const ZcDbObjectId& layerStateId);

    virtual void layerStateToBeDeleted(const ZTCHAR * layerStateName,
                                       const ZcDbObjectId& layerStateId);
    virtual void layerStateDeleted(const ZTCHAR * layerStateName);
    virtual void abortLayerStateDelete(const ZTCHAR * layerStateName,
                                       const ZcDbObjectId& layerStateId);

    virtual void layerStateToBeRenamed(const ZTCHAR * oldLayerStateName,
                                       const ZTCHAR * newLayerStateName);
    virtual void layerStateRenamed(const ZTCHAR * oldLayerStateName,
                                   const ZTCHAR * newLayerStateName);
    virtual void abortLayerStateRename(const ZTCHAR * oldLayerStateName,
                                       const ZTCHAR * newLayerStateName);

};

#pragma pack(pop)

#endif
