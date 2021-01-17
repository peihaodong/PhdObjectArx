

#ifndef __ZCGSMANAGER_H__
#define __ZCGSMANAGER_H__
#pragma pack (push, 8)

class ZcDbViewportTableRecord;
class ZcGiDrawable;
class ZcGsClassFactory;
class ZcGsView;
class ZcGsModel;
class ZcGsDevice;
struct ZcGsClientViewInfo;

class ZcGsManager
{
public:
                                ZcGsManager             (void) { }
    virtual                    ~ZcGsManager             (void) { }

    virtual ZcGsModel *         createZWCADModel      (void)                          = 0;
    virtual ZcGsView *          createZWCADViewport   (ZcDbViewportTableRecord * vp)  = 0;    
    virtual ZcGsView *          createZWCADView       (ZcGiDrawable * drawable)       = 0;

    virtual ZcGsDevice *        createZWCADDevice     (HWND hWnd)                     = 0;
    virtual ZcGsDevice *        createZWCADOffScreenDevice()                          = 0;

    virtual void                destroyZWCADModel     (ZcGsModel  * model)            = 0;
    virtual void                destroyZWCADView      (ZcGsView   * view)             = 0;
    virtual void                destroyZWCADDevice    (ZcGsDevice * device)           = 0;
    
    virtual ZcGsClassFactory *  getGSClassFactory       (void)                          = 0;
    virtual ZcGsModel        *  getDBModel              (void)                          = 0;
    virtual ZcGsDevice       *  getGUIDevice            (void)                          = 0;
};

#pragma pack (pop)
#endif 
