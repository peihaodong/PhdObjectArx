

#ifndef   _ZCAPLMGR_H
#define   _ZCAPLMGR_H

#include "zAcDbLMgr.h"
#pragma pack (push, 8)

class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;

template <class T> class ZcArrayMemCopyReallocator;
template <class T, class R > class ZcArray;
typedef ZcArray<ZcGePoint2d> ZcGePoint2dArray;

class ZcApLayoutManager : public ZcDbLayoutManager {
  public:

    virtual int               
    pageSetup                 (ZcDbObjectId layoutBTRId = ZcDbObjectId::kNull, 
                               void* pParent = NULL, 
                               ZSoft::Boolean isPageSetupDlg = TRUE) = 0;
    virtual void              
    updateCurrentPaper        (ZSoft::Boolean zoomToPaper = FALSE  ) = 0;

    virtual void              
    updateLayoutTabs          () = 0;

    virtual const ZTCHAR *
    findActiveTab             () = 0;
                              
    virtual ZSoft::Boolean    
    showTabs                  () = 0;

    virtual void              
    setShowTabs               (ZSoft::Boolean showTabs           ) = 0;

    virtual ZSoft::Boolean    
    showPageSetup             () = 0;

    virtual void              
    setShowPageSetup          (ZSoft::Boolean showPageSetupDlg   ) = 0;

    virtual ZSoft::Boolean    
    createViewports           () = 0;

    virtual void              
    setCreateViewports        (ZSoft::Boolean createViewports    ) = 0;

    virtual ZSoft::Boolean    
    showPaperBackground       () = 0;

    virtual void              
    setShowPaperBackground    (ZSoft::Boolean showPaperBackground) = 0;

    virtual ZSoft::Boolean    
    showPaperMargins          () = 0; 

    virtual void              
    setShowPaperMargins       (ZSoft::Boolean showPaperMargins   ) = 0;

    virtual ZSoft::Boolean    
    showPrintBorder           () = 0;

    virtual void              
    setShowPrintBorder        (ZSoft::Boolean showPrintBorder    ) = 0;

    virtual ZTCHAR *
    getNextNewLayoutName      (ZcDbDatabase* useDb = NULL) = 0;

    virtual void 
    setDefaultPlotConfig      (ZcDbObjectId layoutBTRId) = 0;

    virtual Zcad::ErrorStatus   
    getClipBoundaryElaboration(ZcDbObjectId clipId,
                               ZcGePoint2dArray *&clipBoundary) = 0;

    virtual Zcad::ErrorStatus 
    pointInViewports          (const ZcGePoint3d &pickPt, 
                               ZcDbObjectIdArray &viewports) = 0;

	virtual void setCaptureOnLayoutSwitch(ZSoft::Boolean bCaptureOnLayout   ) = 0;

};
#pragma pack (pop)
#endif 

