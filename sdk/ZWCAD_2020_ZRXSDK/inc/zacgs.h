

#ifndef _ZCGS_H
#define _ZCGS_H

#include "zadesk.h"
#include "stdlib.h"
#include "zAdAChar.h"
#include "zgs.h"

#pragma pack (push, 8)

ZSoft::Boolean zcgsGetDisplayInfo           (int & drawingWidth,    
                                             int & drawingHeight,     
                                             int & aspectWidth,
                                             int & aspectHeight);

ZSoft::Boolean zcgsGetViewportInfo          (int   viewportNumber,
                                             int & left,    
                                             int & bottom,
                                             int & right,    
                                             int & top);    
class ZcGiDrawable;
class ZcGsScreenShot {      
    public:
    virtual ZSoft::Boolean getSize          (int & width,             
                                             int & height,
                                             int & depth) const = 0; 

    virtual ZSoft::Boolean getColorMap      (int             index,
                                             ZSoft::UInt8 & red,
                                             ZSoft::UInt8 & green,
                                             ZSoft::UInt8 & blue) const = 0;

    virtual void const * getScanline        (int offsetFromLeft,
                                             int offsetFromTop) const = 0;

#ifdef new
#define DISABLING_LEAK_CHECK
#undef new
#endif
    void * operator new (size_t size);

    void operator delete (void * p);   

#ifdef _DEBUG
        void * operator new (size_t size, const char *, int) { return operator new(size); }
#if _MSC_VER >= 1200
        
        void operator delete (void * p, const char *, int) { delete p; }
#endif 
#endif 

#ifdef DISABLING_LEAK_CHECK
#define new DEBUG_NEW
#undef DISABLING_LEAK_CHECK
#endif

    ZcGsScreenShot();
    virtual ~ZcGsScreenShot () = 0;
};

#define ScreenShot ZcGsScreenShot

ZcGsScreenShot * zcgsGetScreenShot          (int          viewportNumber);

void zcgsSetViewportRenderFlag              (int          viewportNumber);

ZSoft::Boolean zcgsDisplayImage             (int          viewportNumber,
                                             ZSoft::Int32 originLeft,    
                                             ZSoft::Int32 originTop,    
                                             int          imageWidth,    
                                             int          imageHeight,    
                                             void const * imageData,        
                                             int          hasTransparency);

ZSoft::Boolean zcgsRemoveAnonymousGraphics  (int viewportNumber);

typedef void (*zcgsCustomUpdateMethod)      (void * pParm, int left, int right, int bottom, int top);
ZSoft::Boolean zcgsSetCustomUpdateMethod    (zcgsCustomUpdateMethod custom_update_method, void * pParm);

void zcgsRedrawShortTermGraphics            (int minx, int miny, int maxx, int maxy);

struct ZcGs
{
    enum LinePattern      { eSolid                         = 0,
                            eDashed                        = 1,
                            eDotted                        = 2,
                            eDashDot                       = 3,
                            eShortDash                     = 4,
                            eMediumDash                    = 5,
                            eLongDash                      = 6,
                            eDoubleShortDash               = 7,
                            eDoubleMediumDash              = 8,
                            eDoubleLongDash                = 9,
                            eMediumLongDash                = 10,
                            eMediumDashShortDashShortDash  = 11,
                            eLongDashShortDash             = 12,
                            eLongDashDotDot                = 13,
                            eLongDashDot                   = 14,
                            eMediumDashDotShortDashDot     = 15,
                            eSparseDot                     = 16,
                            eDefaultLinePattern            = eDotted };
};

void              zcgsSetHighlightColor       (ZSoft::UInt16 colorIndex);
ZSoft::UInt16     zcgsGetHighlightColor       (void);
void              zcgsSetHighlightLinePattern (ZcGs::LinePattern pattern);
ZcGs::LinePattern zcgsGetHighlightLinePattern (void);
void              zcgsSetHighlightLineWeight  (ZSoft::UInt16 weight);
ZSoft::UInt16     zcgsGetHighlightLineWeight  (void);

class ZcGsView;
class ZcGsModel;
class ZcGsManager;

ZSoft::Boolean  zcgsSetViewParameters         (int viewportNumber, const ZcGsView * pView,
                                               bool bRegenRequired, bool bRescaleRequired,
                                               bool bSyncRequired = false);
ZSoft::Boolean  zcgsGetViewParameters         (int viewportNumber, ZcGsView * pView);
ZSoft::Boolean  zcgsSetLensLength             (int viewportNumber, const double & lensLength);
ZSoft::Boolean  zcgsGetLensLength             (int viewportNumber, double & lensLength);
void            zcgsWriteViewToUndoController (int viewportNumber);
ZSoft::Boolean  zcgsSetView2D                 (int viewportNumber);

class CView;

ZcGsView *      zcgsGetGsView               (int viewportNumber, bool bCreateIfNone);

ZcGsManager *   zcgsGetGsManager            (CView * pView = NULL); 

class ZcGeVector3d;
ZSoft::Boolean  zcgsGetOrthoViewParameters  (int viewportNumber, 
                                             ZcDb::OrthographicView view,
                                             ZcGeVector3d * pViewDir,
                                             ZcGeVector3d * pUpVector);

void			zcgsSetLineWeightDisplay	(ZcGsDevice*, bool val);

class ZcGs2DViewLimitManager 
{      
public:
    virtual                ~ZcGs2DViewLimitManager  (void) { }
    virtual bool            testView                (ZcGePoint3d const & target,
                                                     double              dFieldHeight)  = 0;
};

ZcGs2DViewLimitManager *    zcgsCreate2DViewLimitManager  (int viewportNumber);
void                        zcgsDestroy2DViewLimitManager (ZcGs2DViewLimitManager * pLimitManager);

#pragma pack (pop)
#endif 
