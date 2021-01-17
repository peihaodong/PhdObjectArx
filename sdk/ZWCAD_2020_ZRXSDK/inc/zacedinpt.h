

#ifndef _ZCEDINPT_H
#define _ZCEDINPT_H

#include "zrxobject.h"
#include "zdbmain.h"

#pragma pack (push, 8)

#pragma warning (disable: 4786)

class ZcEdInputPointFilter;
class ZcEdInputPointMonitor;
class ZcApDocument;
class ZcEdInputContextReactor;
class ZcDbCustomOsnapMode;
class ZcEdSubSelectFilter;

class ZcEdInputPointManager
{
  public:
	virtual ~ZcEdInputPointManager() { }
    virtual Zcad::ErrorStatus     registerPointFilter(ZcEdInputPointFilter* pFilter) = 0;

    virtual Zcad::ErrorStatus     revokePointFilter() = 0;

    virtual ZcEdInputPointFilter* currentPointFilter() const = 0;

    virtual Zcad::ErrorStatus addPointMonitor(ZcEdInputPointMonitor* pMonitor) = 0;

    virtual Zcad::ErrorStatus removePointMonitor(ZcEdInputPointMonitor* pMonitor) = 0;

    virtual Zcad::ErrorStatus addInputContextReactor(ZcEdInputContextReactor* pReactor) = 0;

    virtual Zcad::ErrorStatus removeInputContextReactor(ZcEdInputContextReactor* pReact) = 0;

    virtual Zcad::ErrorStatus disableSystemCursorGraphics() = 0;

    virtual Zcad::ErrorStatus enableSystemCursorGraphics() = 0;

    virtual int systemCursorDisableCount() const = 0;

    virtual Zcad::ErrorStatus turnOnForcedPick() = 0;

    virtual Zcad::ErrorStatus turnOffForcedPick() = 0;

    virtual int forcedPickCount() const = 0;

    virtual int mouseHasMoved() const = 0;

    virtual Zcad::ErrorStatus turnOnSubentityWindowSelection() = 0;
    virtual Zcad::ErrorStatus turnOffSubentityWindowSelection() = 0;

	virtual void enableMultiSubentPathSelection(bool bEnable) = 0;

    virtual Zcad::ErrorStatus addSubSelectFilter(
            ZcEdSubSelectFilter* pSSSubFilter) = 0;

    virtual Zcad::ErrorStatus removeSubSelectFilter(
            ZcEdSubSelectFilter* pSSSubFilter) = 0;

};


class ZcEdImpInputPointFilterResult;
class ZcEdImpInputPointManager;

#ifdef _ZSOFT_WINDOWS_
	#ifndef ZCAD_PORT
		#define ZCAD_PORT
	#endif
#else
	#undef ZCAD_PORT
	#define ZCAD_PORT
#endif // _ZSOFT_WINDOWS_

class ZCAD_PORT ZcEdInputPoint
{
private:
	ZcEdImpInputPointManager* m_pImpMgr;
	ZcEdInputPoint(ZcEdImpInputPointManager* pImpMgr);
	ZcEdInputPoint & operator=(const ZcEdInputPoint&);
public:
	ZcApDocument*                            document() const;
	bool                                     pointComputed() const;
	int                                      history() const;
	const ZcGePoint3d&                       lastPoint() const;
	const ZcGePoint3d&                       rawPoint() const;
	const ZcGePoint3d&                       grippedPoint() const;
	const ZcGePoint3d&                       cartesianSnappedPoint() const;
	const ZcGePoint3d&                       osnappedPoint() const;
	const ZcDb::OsnapMask                    osnapMask() const;
	const ZcArray<ZcDbCustomOsnapMode*>&     customOsnapModes() const;
	const ZcDb::OsnapMask                    osnapOverrides() const;
	const ZcArray<ZcDbCustomOsnapMode*>&     customOsnapOverrides() const;
	const ZcArray<ZcDbObjectId>&             pickedEntities() const;
	const ZcArray<ZcDbObjectIdArray, ZcArrayObjectCopyReallocator<ZcDbObjectIdArray>>& nestedPickedEntities() const;
	const ZcArray<ZSoft::GsMarker>&          gsSelectionMark() const;
	const ZcArray<ZcDbObjectId>&             keyPointEntities() const;
	const ZcArray<ZcDbObjectIdArray, ZcArrayObjectCopyReallocator<ZcDbObjectIdArray>>&nestedKeyPointEntities() const;
	const ZcArray<ZSoft::GsMarker>&          keyPointGsSelectionMark() const;
	const ZcArray<ZcGeCurve3d*>&             alignmentPaths() const;
	const ZcGePoint3d&                       computedPoint() const;
	const ZTCHAR*                            tooltipString() const;
	ZcGiViewportDraw*                        drawContext() const;
	friend class ZcEdImpInputPointManager;
};

class ZCAD_PORT ZcEdInputPointFilterResult
{
private:
	ZcEdImpInputPointFilterResult* m_pImp;
	ZcEdInputPointFilterResult();
	ZcEdInputPointFilterResult& operator=(const ZcEdInputPointFilterResult&);
public:
	~ZcEdInputPointFilterResult();
	void                             setNewPoint(const ZcGePoint3d& newValue);
	void                             setDisplayOsnapGlyph(bool newValue);
	void                             setNewTooltipString(const ZTCHAR* newValue);
	void                             setRetry(bool newValue);

	const ZcGePoint3d&               newPoint() const;
	bool                             displayOsnapGlyph() const;
	const ZTCHAR*                    newTooltipString() const;
	bool							 retry() const;

	friend class ZcEdImpInputPointManager;
};

class ZcEdImpInputPointMonitorResult;
class ZCAD_PORT ZcEdInputPointMonitorResult
{
private:
	ZcEdImpInputPointMonitorResult* m_pImp; 
	ZcEdInputPointMonitorResult();
	ZcEdInputPointMonitorResult& operator=(const ZcEdInputPointMonitorResult&);
public:
	~ZcEdInputPointMonitorResult();
	void setAdditionalTooltipString(const ZTCHAR*);

	bool appendToTooltipStr() const;
	const ZTCHAR* additionalTooltipString() const;

	friend class ZcEdImpInputPointManager;
};

class ZcEdInputPointFilter : public ZcRxObject
{

  public:
    ZCRX_DECLARE_MEMBERS(ZcEdInputPointFilter);

    virtual Zcad::ErrorStatus processInputPoint(
          bool&                        changedPoint,
          ZcGePoint3d&                 newPoint,
          bool&                        displayOsnapGlyph,

          bool&                        changedTooltipStr,
          ZTCHAR*&                     newTooltipString,

          bool&                        retry,

          ZcGiViewportDraw*           drawContext,

          ZcApDocument*              document,

          bool                       pointComputed,

          int                        history,

          const ZcGePoint3d&               lastPoint,

          const ZcGePoint3d&               rawPoint,

          const ZcGePoint3d&               grippedPoint,

          const ZcGePoint3d&               cartesianSnappedPoint,

          const ZcGePoint3d&               osnappedPoint,
          ZcDb::OsnapMask                  osnapMask,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,

          ZcDb::OsnapMask                  osnapOverrides,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,

          const ZcArray<ZcDbObjectId>&     pickedEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                           nestedPickedEntities,
          const ZcArray<ZSoft::GsMarker>&  gsSelectionMark,

          const ZcArray<ZcDbObjectId>&     keyPointEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                           nestedKeyPointEntities,
          const ZcArray<ZSoft::GsMarker>&  keyPointGsSelectionMark,

          const ZcArray<ZcGeCurve3d*>&       alignmentPaths,

          const ZcGePoint3d&               computedPoint,

          const ZTCHAR*                      tooltipString) {	return Zcad::eOk; }
		  ZCAD_PORT virtual Zcad::ErrorStatus processInputPoint(const ZcEdInputPoint& input, ZcEdInputPointFilterResult& output);
	  virtual ZcEdInputPointFilter* revokeInputFilter(ZcEdInputPointFilter* revokedFilter)                { return this; }
};

class ZcEdInputPointMonitor : public ZcRxObject
{
    public:
    ZCRX_DECLARE_MEMBERS(ZcEdInputPointMonitor);

    virtual Zcad::ErrorStatus monitorInputPoint(

          bool&                             appendToTooltipStr,
          ZTCHAR*&                            additionalTooltipString,

          ZcGiViewportDraw*                   drawContext,

          ZcApDocument*                       document,
          bool                                pointComputed,
          int                                 history,
          const ZcGePoint3d&                  lastPoint,
          const ZcGePoint3d&                  rawPoint,
          const ZcGePoint3d&                  grippedPoint,
          const ZcGePoint3d&                  cartesianSnappedPoint,
          const ZcGePoint3d&                  osnappedPoint,
          ZcDb::OsnapMask                     osnapMask,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapModes,
          ZcDb::OsnapMask                     osnapOverrides,
          const ZcArray<ZcDbCustomOsnapMode*>& customOsnapOverrides,
          const ZcArray<ZcDbObjectId>&        apertureEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >& 
                                              nestedApertureEntities,
          const ZcArray<ZSoft::GsMarker>&     gsSelectionMark,
          const ZcArray<ZcDbObjectId>&        keyPointEntities,
          const ZcArray< ZcDbObjectIdArray, ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                                              nestedKeyPointEntities,
          const ZcArray<ZSoft::GsMarker>&     keyPointGsSelectionMark,
          const ZcArray<ZcGeCurve3d*>&        alignmentPaths,
          const ZcGePoint3d&                  computedPoint,
          const ZTCHAR*                         tooltipString) {	return Zcad::eOk; }
		  ZCAD_PORT virtual Zcad::ErrorStatus monitorInputPoint(const ZcEdInputPoint& input, ZcEdInputPointMonitorResult& output);

    virtual bool
        excludeFromOsnapCalculation (const ZcArray<ZcDbObjectId>& nestedEntity,
                                     ZSoft::GsMarker gsSelectionMark)
                                    { return false; }
};

class ZcEdInputContextReactor
{
public:
	virtual ~ZcEdInputContextReactor() { }
    virtual void beginGetPoint(const ZcGePoint3d* pointIn,
                               const ZTCHAR* promptString,
                               int   initGetFlags,
                               const ZTCHAR* pKeywords) { }

    virtual void endGetPoint(Zcad::PromptStatus returnStatus,
                             const ZcGePoint3d& pointOut,
                             const ZTCHAR*& pKeyword) { }

    virtual void beginGetAngle(const ZcGePoint3d* pointIn,
                               const ZTCHAR* promptString,
                               int   initGetFlags,
                               const ZTCHAR* pKeywords) { }

    virtual void endGetAngle(Zcad::PromptStatus returnStatus,
                             double& angle,
                             const ZTCHAR*& pKeyword) { }

    virtual void beginGetDistance(const ZcGePoint3d* pointIn,
                                  const ZTCHAR* promptString,
                                  int   initGetFlags,
                                  const ZTCHAR* pKeywords) { }

    virtual void endGetDistance(Zcad::PromptStatus returnStatus,
                                double& distance,
                                const ZTCHAR*& pKeyword) { }

    virtual void beginGetOrientation(const ZcGePoint3d* pointIn,
                                     const ZTCHAR* promptString,
                                     int   initGetFlags,
                                     const ZTCHAR* pKeywords) { }

    virtual void endGetOrientation(Zcad::PromptStatus returnStatus,
                                   double& angle,
                                   const ZTCHAR*& pKeyword) { }

    virtual void beginGetCorner(const ZcGePoint3d* firstCorner,
                                const ZTCHAR* promptString,
                                int   initGetFlags,
                                const ZTCHAR* pKeywords) { }
    
    virtual void endGetCorner(Zcad::PromptStatus returnStatus,
                              ZcGePoint3d& secondCorner,
                              const ZTCHAR*& pKeyword) { }

    virtual void beginGetScaleFactor(const ZcGePoint3d* pointIn,
                                     const ZTCHAR* promptString,
                                     int   initGetFlags,
                                     const ZTCHAR* pKeywords) { }

    virtual void endGetScaleFactor(Zcad::PromptStatus returnStatus,
                                   double& distance,
                                   const ZTCHAR*& pKeyword) { }

    virtual void beginGetString(const ZTCHAR* promptString,
                                int   initGetFlags) { }

    virtual void endGetString (Zcad::PromptStatus returnStatus,
                               ZTCHAR* pString) { }

    virtual void beginGetKeyword(const ZTCHAR* promptString,
                                 int   initGetFlags,
                                 const ZTCHAR* pKeywords) { }

    virtual void endGetKeyword (Zcad::PromptStatus returnStatus,
                                const ZTCHAR*& pKeyword) { }

    virtual void beginGetInteger(const int* dfault, 
                                const ZTCHAR* promptString,
                                int   initGetFlags,
                                const ZTCHAR* pKeywords) { }

    virtual void endGetInteger(Zcad::PromptStatus returnStatus,
                               int& retValue,
                               const ZTCHAR*& pKeyword) { }

    virtual void beginGetColor(const int* dfault, 
                               const ZTCHAR* promptString,
                               int   initGetFlags,
                               const ZTCHAR* pKeywords) { }

    virtual void endGetColor(Zcad::PromptStatus returnStatus,
                             int& retValue,
                             const ZTCHAR*& pKeyword) { }

    virtual void beginGetReal(const double* dfault, 
                              const ZTCHAR* promptString,
                              int   initGetFlags,
                              const ZTCHAR* pKeywords) { }

    virtual void endGetReal(Zcad::PromptStatus returnStatus,
                            double& returnValue,
                            const ZTCHAR*& pKeyword) { }

    virtual void beginEntsel(const ZTCHAR* promptString,
                             int   initGetFlags,
                             const ZTCHAR* pKeywords) { }

    virtual void endEntsel(Zcad::PromptStatus returnStatus,
                           ZcDbObjectId& entPicked,
                           ZcGePoint3d& pickPoint,
                           const ZTCHAR* pKeyword) { }

    virtual void beginNentsel(const ZTCHAR*    promptString,
                              ZSoft::Boolean pickFlag,
                              int            initGetFlags,
                              const ZTCHAR*    pKeywords) { }

    virtual void endNentsel(Zcad::PromptStatus returnStatus,
                            ZcDbObjectId entPicked,
                            const ZcGePoint3d&  pickPoint,
                            const ZcGeMatrix3d& xform,
                            const resbuf* referenceStack,
                            const ZTCHAR*   pKeyword) { }

    virtual void beginSSGet(const ZTCHAR*  pPrompt,
                            int          initGetFlags,
                            const ZTCHAR*  pKeywords,
                            const ZTCHAR*  pSSControls,
                            const ZcArray<ZcGePoint3d>& points,
                            const resbuf*               entMask) { }

    virtual void endSSGet(Zcad::PromptStatus returnStatus,
                          const ZcArray<ZcDbObjectId>& ss) { }

    virtual void beginDragSequence(const ZTCHAR*  promptString) { }

    virtual void endDragSequence(Zcad::PromptStatus returnStatus,
                                 ZcGePoint3d&  pickPoint,
                                 ZcGeVector3d& vec) { }

    virtual void beginQuiescentState() { }

    virtual void endQuiescentState() { }
};


#pragma pack (pop)
#endif  
