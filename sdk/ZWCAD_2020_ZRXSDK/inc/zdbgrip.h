

#ifndef ZD_DBGRIP_H
#define ZD_DBGRIP_H

#include "zacdb.h"
#include "zacarray.h"
#include "zdbdimdata.h"


class ZcGiViewport;
class ZcDbEntity;
class ZcDbGripData;
class ZcGiWorldDraw;
class ZcGiViewportDraw;
class ZcDbCustomOsnapMode;

namespace ZcDbGripOperations {
    enum ReturnValue {
        eOk         = 0,
        eFailure,
        eNoRedrawGrip,
        eGripHotToWarm,
        eGetNewGripPoints
    };

    enum DrawType {
        kWarmGrip  = 0,
        kHoverGrip,
        kHotGrip,
        kDragImageGrip
    };

    enum GripStatus {
        kGripStart = 0,
        kGripEnd,
        kGripAbort,
        kStretch,
        kMove,
        kRotate,
        kScale,
        kMirror,
        kDimFocusChanged,
        kPopUpMenu
    };

    enum GripFlags {
        kSkipWhenShared           = 0x1,
        kDisableRubberBandLine    = 0x2,
        kDisableModeKeywords      = 0x4,
        kDrawAtDragImageGripPoint = 0x8,
        kTriggerGrip              = 0x10,
        kTurnOnForcedPick         = 0x20,
        kMapGripHotToRtClk        = 0x40,
        kGizmosEnabled            = 0x80,
        kGripIsPerViewport        = 0x100,
        kGripEditTip              = 0x200,
		kGripIsDisabled           = 0x400,
		kGripRightClickIsNewStyle = 0x800,
		kGripSynergyPrompt        = 0x1000,
    };

    enum GripContextFlags {
        kSharedGrip    = 0x1,
        kMultiHotGrip  = 0x2
    };

    enum GetGripPointsFlags {
        kGripPointsOnly = 0x1,
        kCyclableGripsOnly = 0x02,
		kDynamicDimMode = 0x04,
		kNoMultiModesGrip = 0x08,
    };
    enum MoveGripPointsFlags {
        kOsnapped                = 0x1,
        kPolar                   = 0x2,
        kOtrack                  = 0x4,
        kZdir                    = 0x8,
        kKeyboard                = 0x10,
		kDragging                = 0x20,
    };

};

typedef ZcArray<ZcDbGripData*, ZcArrayMemCopyReallocator<ZcDbGripData*>> ZcDbGripDataPtrArray;
typedef ZcArray<ZcDbGripData, ZcArrayObjectCopyReallocator<ZcDbGripData>> ZcDbGripDataArray;

typedef ZcDbGripOperations::ReturnValue (*GripOperationPtr)(ZcDbGripData* pThis,
    const ZcDbObjectId& entId, int contextFlags);

typedef void (*ContextMenuItemIndexPtr)(unsigned int itemIndex);

typedef ZcDbGripOperations::ReturnValue (*GripRtClkHandler)(ZcDbGripDataArray& hotGrips,
    const ZcDbObjectIdArray& ents, ZTCHAR *& menuName, HMENU& menu,
    ContextMenuItemIndexPtr& cb);

typedef ZcDbGripOperations::ReturnValue (*GripRightClickHandler)(ZcDbGripDataArray& hotGrips,
	const ZcDbObjectIdArray& ents, ZcRxObject*& handler);

typedef bool (*GripWorldDrawPtr)(ZcDbGripData* pThis, ZcGiWorldDraw* pWd,
    const ZcDbObjectId& entId, ZcDbGripOperations::DrawType type,
    ZcGePoint3d* imageGripPoint, double dGripSize);

typedef void (*GripViewportDrawPtr)(ZcDbGripData* pThis, ZcGiViewportDraw* pWd,
    const ZcDbObjectId& entId, ZcDbGripOperations::DrawType type,
    ZcGePoint3d* imageGripPoint, int gripSize);

typedef void (*GripOpStatusPtr)(ZcDbGripData* pThis, const ZcDbObjectId& entId,
    ZcDbGripOperations::GripStatus stat);

typedef const ZTCHAR * (*GripToolTipPtr)(ZcDbGripData* pThis);

typedef const ZTCHAR * (*GripCLIPromptPtr)(ZcDbGripData* pThis);

typedef const ZTCHAR * (*GripCLIDisplayStringPtr)(ZcDbGripData* pThis);


typedef void (*GripDimensionPtr)(ZcDbGripData* pThis, const ZcDbObjectId& entId,
    double dimScale, ZcDbDimDataPtrArray& dimData); 

typedef ZcDbGripOperations::ReturnValue (*GripInputPointPtr)(
    ZcDbGripData* pThis, const ZcDbObjectId& entId, bool& changedPoint,
    ZcGePoint3d& newPoint, const ZcGiViewport& viewContext,
    const ZcDbObjectId& viewportId, bool pointComputed, int history,
    const ZcGePoint3d& lastPoint, const ZcGePoint3d& rawPoint,
    const ZcGePoint3d& grippedPoint, const ZcGePoint3d& cartesianSnappedPoint,
    const ZcGePoint3d& osnappedPoint, ZcDb::OsnapMask osnapMask,
    const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,
    ZcDb::OsnapMask osnapOverrides,
    const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,
    const ZcArray<ZcDbObjectId>& pickedEntities,
    const ZcArray< ZcDbObjectIdArray,
        ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& nestedPickedEntities,
    const ZcArray<ZSoft::GsMarker>& gsSelectionMark,
    const ZcArray<ZcDbObjectId>& keyPointEntities,
    const ZcArray< ZcDbObjectIdArray,
        ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& nestedKeyPointEntities,
    const ZcArray<ZSoft::GsMarker>& keyPointGsSelectionMark,
    const ZcArray<ZcGeCurve3d*>& alignmentPaths, const ZcGePoint3d& computedPoint); 

class ZcDbGripData {
public:
    ZcDbGripData();
    ZcDbGripData(const ZcGePoint3d&, void*, GripOperationPtr hotGrip = NULL,
        GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
        GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
        GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
        GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0,
        ZcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);

    ZcDbGripData(const ZcGePoint3d&, void*, ZcRxClass*,
        GripOperationPtr hotGrip = NULL,
        GripOperationPtr hoverGrip = NULL, GripRtClkHandler RtClk = NULL,
        GripWorldDrawPtr wd = NULL, GripViewportDrawPtr vd = NULL,
        GripOpStatusPtr stat = NULL, GripToolTipPtr tt = NULL,
        GripDimensionPtr hoverDim = NULL, GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0,
        ZcGePoint3d* altBasePt = NULL, GripInputPointPtr inputPointFunc = NULL);

    ~ZcDbGripData() {}

    ZcDbGripData(const ZcDbGripData&);

    ZcDbGripData&             operator = (const ZcDbGripData&);

    void                      setAllData(const ZcGePoint3d&, void*,
        GripOperationPtr hotGrip = NULL, GripOperationPtr hoverGrip = NULL,
        GripRtClkHandler RtClk = NULL, GripWorldDrawPtr wd = NULL,
        GripViewportDrawPtr vd = NULL, GripOpStatusPtr stat = NULL,
        GripToolTipPtr tt = NULL, GripDimensionPtr hoverDim = NULL,
        GripDimensionPtr hotGripDim = NULL,
        unsigned int bitFlags = 0, ZcGePoint3d* altBasePt = NULL,
        GripInputPointPtr inputPointFunc = NULL,
        ZcRxClass* appDataZcRxClass = NULL);

    const ZcGePoint3d&        gripPoint() const;
    void                      setGripPoint(const ZcGePoint3d& pt);

    void*                     appData() const;
    void                      setAppData(void* appData);

    ZcRxClass*                appDataZcRxClass() const;
    void                      setAppDataZcRxClass(ZcRxClass* pClass);

    GripOperationPtr          hotGripFunc() const;
    void                      setHotGripFunc(GripOperationPtr pFunc);

    GripOperationPtr          hoverFunc() const;
    void                      setHoverFunc(GripOperationPtr pFunc);
    
    GripRtClkHandler          rtClk() const;
    void                      setRtClk(GripRtClkHandler pFunc);
    
	GripRightClickHandler     righClick() const;
	void                      setRightClick(GripRightClickHandler pFunc);

    GripWorldDrawPtr          worldDraw() const;
    void                      setWorldDraw(GripWorldDrawPtr pFunc);
    
    GripViewportDrawPtr       viewportDraw() const;
    void                      setViewportDraw(GripViewportDrawPtr pFunc);
    
    GripOpStatusPtr           gripOpStatFunc() const;
    void                      setGripOpStatFunc(GripOpStatusPtr pFunc);

    GripToolTipPtr            toolTipFunc() const;
    void                      setToolTipFunc(GripToolTipPtr pFunc);

    GripDimensionPtr          hoverDimensionFunc() const;
    void                      setHoverDimensionFunc(GripDimensionPtr pFunc);

    GripDimensionPtr          hotGripDimensionFunc() const;
    void                      setHotGripDimensionFunc(GripDimensionPtr pFunc);

    ZcGePoint3d*              alternateBasePoint() const;
    void                      setAlternateBasePoint(ZcGePoint3d* altBasePt);

	GripCLIPromptPtr          getCLIPromptFunc()const;
	void                      setCLIPromptFunc(GripCLIPromptPtr pFunc);

	GripCLIDisplayStringPtr   getCLIDisplayStringFunc()const;
	void                      setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc);

    unsigned int              bitFlags() const;
    void                      setBitFlags(unsigned int flags);

    bool                      skipWhenShared() const;
    void                      setSkipWhenShared(bool skip);

    bool                      isRubberBandLineDisabled() const;
    void                      disableRubberBandLine(bool disable);

    bool                      areModeKeywordsDisabled() const;
    void                      disableModeKeywords(bool disable);

    bool                      drawAtDragImageGripPoint() const;
    void                      setDrawAtDragImageGripPoint(bool atDragPoint);

    bool                      triggerGrip() const;
    void                      setTriggerGrip(bool trigger);

    GripInputPointPtr         inputPointFunc() const;
    void                      setInputPointFunc(GripInputPointPtr pFunc);

    bool                      forcedPickOn() const;
    void                      setForcedPickOn(bool on);

    bool                      mapGripHotToRtClk() const;
    void                      setMapGripHotToRtClk(bool on);

    bool                      gizmosEnabled() const;
    void                      setGizmosEnabled(bool on);

    bool                      gripIsPerViewport() const;
    void                      setGripIsPerViewport(bool on);

	bool                      gripIsDisabled() const;
	void                      disableGrip(bool disable);

	bool                      gripRightClickIsNewStyle() const;
private:
    ZcGePoint3d         m_gripPt;
    ZcGePoint3d*        m_pAltBasePt;
    void*               m_pAppData;
    GripOperationPtr    m_pHotGripFunc;
    GripOperationPtr    m_pHoverFunc;
	union {
		GripRtClkHandler oldHandler;
		GripRightClickHandler newHandler;
	} m_pRtClk;
    GripWorldDrawPtr    m_pWorldDraw;
    GripViewportDrawPtr m_pViewportDraw;
    GripOpStatusPtr     m_pGripOpStatFunc;
    GripToolTipPtr      m_pToolTipFunc;
    GripDimensionPtr    m_pHoverDimensionFunc;
    GripDimensionPtr    m_pHotGripDimensionFunc;
    unsigned int        m_bitFlags;
    GripInputPointPtr   m_pInputPointFunc;
    ZcRxClass*          m_pAppDataClass;
	GripCLIPromptPtr          m_pCLIPromptFunc;
	GripCLIDisplayStringPtr   m_pCLIDisplayStringFunc;
};

inline ZcDbGripData::ZcDbGripData() : m_pAppData(NULL), m_pAppDataClass(NULL),
    m_pHotGripFunc(NULL), m_pHoverFunc(NULL),
    m_pWorldDraw(NULL), m_pViewportDraw(NULL), m_pGripOpStatFunc(NULL),
    m_pToolTipFunc(NULL), m_pHoverDimensionFunc(NULL),
    m_pHotGripDimensionFunc(NULL), m_bitFlags(0), m_pAltBasePt(NULL),
    m_pInputPointFunc(NULL), m_pCLIPromptFunc(NULL), m_pCLIDisplayStringFunc(NULL)
{
	setRtClk(NULL);
}

inline ZcDbGripData::ZcDbGripData(const ZcGePoint3d& pt, void* AppData,
    GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
    GripRtClkHandler RtClk, GripWorldDrawPtr wd,
    GripViewportDrawPtr vd, GripOpStatusPtr stat,
    GripToolTipPtr tt, GripDimensionPtr hoverDim,
    GripDimensionPtr hotGripDim,
    unsigned int bitFlags, ZcGePoint3d* altBasePt,
    GripInputPointPtr inputPointFunc) :
    m_gripPt(pt), m_pAppData(AppData), m_pAppDataClass(NULL), m_pHotGripFunc(hotGrip),
    m_pHoverFunc(hoverGrip), m_pWorldDraw(wd),
    m_pViewportDraw(vd), m_pGripOpStatFunc(stat),
    m_pToolTipFunc(tt), m_pHoverDimensionFunc(hoverDim),
    m_pHotGripDimensionFunc(hotGripDim),
    m_bitFlags(bitFlags), m_pAltBasePt(altBasePt),
    m_pInputPointFunc(inputPointFunc), m_pCLIPromptFunc(NULL), m_pCLIDisplayStringFunc(NULL)
{
	setRtClk(RtClk);
}

inline ZcDbGripData::ZcDbGripData(const ZcGePoint3d& pt, void* AppData,
    ZcRxClass* pAppDataClass,
    GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
    GripRtClkHandler RtClk, GripWorldDrawPtr wd,
    GripViewportDrawPtr vd, GripOpStatusPtr stat,
    GripToolTipPtr tt, GripDimensionPtr hoverDim,
    GripDimensionPtr hotGripDim,
    unsigned int bitFlags, ZcGePoint3d* altBasePt,
    GripInputPointPtr inputPointFunc) :
    m_gripPt(pt), m_pAppData(AppData), m_pAppDataClass(pAppDataClass),
    m_pHotGripFunc(hotGrip), m_pHoverFunc(hoverGrip),
    m_pWorldDraw(wd), m_pViewportDraw(vd), m_pGripOpStatFunc(stat),
    m_pToolTipFunc(tt), m_pHoverDimensionFunc(hoverDim),
    m_pHotGripDimensionFunc(hotGripDim),
    m_bitFlags(bitFlags), m_pAltBasePt(altBasePt),
	m_pInputPointFunc(inputPointFunc), m_pCLIPromptFunc(NULL), m_pCLIDisplayStringFunc(NULL)
{
	setRtClk(RtClk);
}
inline ZcDbGripData::ZcDbGripData(const ZcDbGripData& src)
{
    m_gripPt = src.gripPoint();
    m_pAppData = src.appData();
    m_pAppDataClass = src.appDataZcRxClass();
    m_pHotGripFunc = src.hotGripFunc();
    m_pHoverFunc = src.hoverFunc();
    m_pRtClk.oldHandler = src.rtClk();
    m_pWorldDraw = src.worldDraw();
    m_pViewportDraw = src.viewportDraw();
    m_pGripOpStatFunc = src.gripOpStatFunc();
    m_pToolTipFunc= src.toolTipFunc();
    m_pHoverDimensionFunc= src.hoverDimensionFunc();
    m_pHotGripDimensionFunc= src.hotGripDimensionFunc();
    m_bitFlags = src.bitFlags();
    m_pAltBasePt = src.alternateBasePoint();
    m_pInputPointFunc = src.inputPointFunc();
	m_pCLIPromptFunc = src.getCLIPromptFunc();
	m_pCLIDisplayStringFunc = src.getCLIDisplayStringFunc();
}

inline ZcDbGripData& ZcDbGripData::operator = (const ZcDbGripData& rtSide)
{
    m_gripPt = rtSide.gripPoint();
    m_pAppData = rtSide.appData();
    m_pAppDataClass = rtSide.appDataZcRxClass();
    m_pHotGripFunc = rtSide.hotGripFunc();
    m_pHoverFunc = rtSide.hoverFunc();
    m_pRtClk.oldHandler = rtSide.rtClk();
    m_pWorldDraw = rtSide.worldDraw();
    m_pViewportDraw = rtSide.viewportDraw();
    m_pGripOpStatFunc = rtSide.gripOpStatFunc();
    m_pToolTipFunc= rtSide.toolTipFunc();
    m_pHoverDimensionFunc= rtSide.hoverDimensionFunc();
    m_pHotGripDimensionFunc= rtSide.hotGripDimensionFunc();
    m_bitFlags = rtSide.bitFlags();
    m_pAltBasePt = rtSide.alternateBasePoint();
    m_pInputPointFunc = rtSide.inputPointFunc();
	m_pCLIPromptFunc = rtSide.getCLIPromptFunc();
	m_pCLIDisplayStringFunc = rtSide.getCLIDisplayStringFunc();

    return *this;
}

inline void ZcDbGripData::setAllData(const ZcGePoint3d& pt, void* AppData,
        GripOperationPtr hotGrip, GripOperationPtr hoverGrip,
        GripRtClkHandler RtClk, GripWorldDrawPtr wd,
        GripViewportDrawPtr vd, GripOpStatusPtr stat,
        GripToolTipPtr tt, GripDimensionPtr hoverDim,
        GripDimensionPtr hotGripDim,
        unsigned int bitFlags, ZcGePoint3d* altBasePt,
        GripInputPointPtr inputPointFunc,
        ZcRxClass* pAppDataClass)
{
    m_gripPt = pt;
    m_pAppData = AppData;
    m_pAppDataClass = pAppDataClass;
    m_pHotGripFunc = hotGrip;
	setRtClk(RtClk);
    m_pHoverFunc = hoverGrip;
    m_pWorldDraw = wd;
    m_pViewportDraw = vd;
    m_pGripOpStatFunc = stat;
    m_pToolTipFunc= tt;
    m_pHoverDimensionFunc = hoverDim;
    m_pHotGripDimensionFunc = hotGripDim;
    m_bitFlags = bitFlags;
    m_pAltBasePt = altBasePt;
    m_pInputPointFunc = inputPointFunc;
}

inline const ZcGePoint3d&
ZcDbGripData::gripPoint() const
{
    return m_gripPt;
}

inline void
ZcDbGripData::setGripPoint(const ZcGePoint3d& pt)
{
    m_gripPt = pt;
}

inline void*
ZcDbGripData::appData() const
{
    return m_pAppData;
}

inline void
ZcDbGripData::setAppData(void* appData)
{
    m_pAppData = appData;
}

inline ZcRxClass*
ZcDbGripData::appDataZcRxClass() const
{
    return m_pAppDataClass;
}

inline void
ZcDbGripData::setAppDataZcRxClass(ZcRxClass* appDataClass)
{
    m_pAppDataClass = appDataClass;
}

inline GripOperationPtr
ZcDbGripData::hotGripFunc() const
{
    return m_pHotGripFunc;
}

inline void
ZcDbGripData::setHotGripFunc(GripOperationPtr pFunc)
{
    m_pHotGripFunc = pFunc;
}

inline GripOperationPtr
ZcDbGripData::hoverFunc() const
{
    return m_pHoverFunc;
}

inline void
ZcDbGripData::setHoverFunc(GripOperationPtr pFunc)
{
    m_pHoverFunc = pFunc;
}

inline GripRtClkHandler
ZcDbGripData::rtClk() const
{
    return m_pRtClk.oldHandler;
}

inline void
ZcDbGripData::setRtClk(GripRtClkHandler pFunc)
{
	m_bitFlags &= ~ZcDbGripOperations::kGripRightClickIsNewStyle;
	m_pRtClk.oldHandler = pFunc;
}

inline
GripRightClickHandler ZcDbGripData::righClick() const
{
	return m_pRtClk.newHandler;
}

inline 
void ZcDbGripData::setRightClick(GripRightClickHandler pFunc)
{
	m_bitFlags |= ZcDbGripOperations::kGripRightClickIsNewStyle;
	m_pRtClk.newHandler = pFunc;
}


inline GripWorldDrawPtr
ZcDbGripData::worldDraw() const
{
    return m_pWorldDraw;
}

inline void
ZcDbGripData::setWorldDraw(GripWorldDrawPtr pFunc)
{
    m_pWorldDraw = pFunc;
}

inline GripViewportDrawPtr
ZcDbGripData::viewportDraw() const
{
    return m_pViewportDraw;
}

inline void
ZcDbGripData::setViewportDraw(GripViewportDrawPtr pFunc)
{
    m_pViewportDraw = pFunc;
}

inline GripOpStatusPtr
ZcDbGripData::gripOpStatFunc() const
{
    return m_pGripOpStatFunc;
}

inline void
ZcDbGripData::setGripOpStatFunc(GripOpStatusPtr pFunc)
{
    m_pGripOpStatFunc = pFunc;
}
 
inline GripToolTipPtr
ZcDbGripData::toolTipFunc() const
{
    return m_pToolTipFunc;
}

inline void
ZcDbGripData::setToolTipFunc(GripToolTipPtr pFunc)
{
    m_pToolTipFunc = pFunc;
}

inline GripDimensionPtr
ZcDbGripData::hoverDimensionFunc() const
{
    return m_pHoverDimensionFunc;
}

inline void
ZcDbGripData::setHoverDimensionFunc(GripDimensionPtr pFunc)
{
    m_pHoverDimensionFunc = pFunc;
}

inline GripDimensionPtr
ZcDbGripData::hotGripDimensionFunc() const
{
    return m_pHotGripDimensionFunc;
}

inline void
ZcDbGripData::setHotGripDimensionFunc(GripDimensionPtr pFunc)
{
    m_pHotGripDimensionFunc = pFunc;
}

inline ZcGePoint3d*
ZcDbGripData::alternateBasePoint() const
{
    return m_pAltBasePt;
}

inline void
ZcDbGripData::setAlternateBasePoint(ZcGePoint3d* altBasePt)
{
    m_pAltBasePt = altBasePt;
}

inline unsigned int
ZcDbGripData::bitFlags() const
{
    return m_bitFlags;
}

inline void
ZcDbGripData::setBitFlags(unsigned int flags)
{
    m_bitFlags = flags;
}

inline bool
ZcDbGripData::skipWhenShared() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kSkipWhenShared);
}

inline void
ZcDbGripData::setSkipWhenShared(bool skip)
{
    if (skip)
        m_bitFlags |= ZcDbGripOperations::kSkipWhenShared;
    else
        m_bitFlags &= ~ZcDbGripOperations::kSkipWhenShared;
}

inline bool
ZcDbGripData::isRubberBandLineDisabled() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kDisableRubberBandLine);
}

inline void
ZcDbGripData::disableRubberBandLine(bool disable)
{
    if (disable)
        m_bitFlags |= ZcDbGripOperations::kDisableRubberBandLine;
    else
        m_bitFlags &= ~ZcDbGripOperations::kDisableRubberBandLine;
}

inline bool
ZcDbGripData::areModeKeywordsDisabled() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kDisableModeKeywords);
}

inline void
ZcDbGripData::disableModeKeywords(bool disable)
{
    if (disable)
        m_bitFlags |= ZcDbGripOperations::kDisableModeKeywords;
    else
        m_bitFlags &= ~ZcDbGripOperations::kDisableModeKeywords;
}

inline bool
ZcDbGripData::drawAtDragImageGripPoint() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kDrawAtDragImageGripPoint);
}

inline void
ZcDbGripData::setDrawAtDragImageGripPoint(bool atDragPoint)
{
    if (atDragPoint)
        m_bitFlags |= ZcDbGripOperations::kDrawAtDragImageGripPoint;
    else
        m_bitFlags &= ~ZcDbGripOperations::kDrawAtDragImageGripPoint;
}

inline bool
ZcDbGripData::triggerGrip() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kTriggerGrip);
}

inline void
ZcDbGripData::setTriggerGrip(bool trigger)
{
    if (trigger)
        m_bitFlags |= ZcDbGripOperations::kTriggerGrip
            | ZcDbGripOperations::kSkipWhenShared;
    else
        m_bitFlags &= ~(ZcDbGripOperations::kTriggerGrip
            | ZcDbGripOperations::kSkipWhenShared);
}

inline GripInputPointPtr
ZcDbGripData::inputPointFunc() const
{
    return m_pInputPointFunc;
}

inline void
ZcDbGripData::setInputPointFunc(GripInputPointPtr pFunc)
{
    m_pInputPointFunc = pFunc;
}

inline bool
ZcDbGripData::forcedPickOn() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kTurnOnForcedPick);
}

inline void
ZcDbGripData::setForcedPickOn(bool on)
{
    if (on)
        m_bitFlags |= ZcDbGripOperations::kTurnOnForcedPick;
    else
        m_bitFlags &= ~ZcDbGripOperations::kTurnOnForcedPick;
}

inline bool
ZcDbGripData::mapGripHotToRtClk() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kMapGripHotToRtClk);
}

inline void
ZcDbGripData::setMapGripHotToRtClk(bool on)
{
    if (on)
        m_bitFlags |= ZcDbGripOperations::kMapGripHotToRtClk;
    else
        m_bitFlags &= ~ZcDbGripOperations::kMapGripHotToRtClk;
}

inline bool
ZcDbGripData::gizmosEnabled() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kGizmosEnabled);
}

inline void
ZcDbGripData::setGizmosEnabled(bool on)
{
    if (on)
        m_bitFlags |= ZcDbGripOperations::kGizmosEnabled;
    else
        m_bitFlags &= ~ZcDbGripOperations::kGizmosEnabled;
}

inline bool
ZcDbGripData::gripIsPerViewport() const
{
    return !!(m_bitFlags & ZcDbGripOperations::kGripIsPerViewport);
}

inline void
ZcDbGripData::setGripIsPerViewport(bool on)
{
    if (on)
        m_bitFlags |= ZcDbGripOperations::kGripIsPerViewport;
    else
        m_bitFlags &= ~ZcDbGripOperations::kGripIsPerViewport;
}

inline 
bool ZcDbGripData::gripIsDisabled() const
{
	return !!(m_bitFlags & ZcDbGripOperations::kGripIsDisabled);
}

inline 
void ZcDbGripData::disableGrip(bool disable)
{
	if (disable)
		m_bitFlags |= ZcDbGripOperations::kGripIsDisabled;
	else
		m_bitFlags &= ~ZcDbGripOperations::kGripIsDisabled;
}

inline 
bool ZcDbGripData::gripRightClickIsNewStyle() const
{
	return !!(m_bitFlags & ZcDbGripOperations::kGripRightClickIsNewStyle);
}

inline 
GripCLIPromptPtr ZcDbGripData::getCLIPromptFunc() const
{
	return m_pCLIPromptFunc;
}

inline 
void ZcDbGripData::setCLIPromptFunc(GripCLIPromptPtr pFunc)
{
	m_pCLIPromptFunc = pFunc;
}

inline 
GripCLIDisplayStringPtr ZcDbGripData::getCLIDisplayStringFunc() const
{
	return m_pCLIDisplayStringFunc;
}

inline 
void ZcDbGripData::setCLIDisplayStringFunc(GripCLIDisplayStringPtr pFunc)
{
	m_pCLIDisplayStringFunc = pFunc;
}

#endif 



