

#ifndef _zrxdlinkr_h
#define _zrxdlinkr_h 1

class ZcRxDLinkerReactor;
class ZcRxService;

#include "zrxobject.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

struct ZcadApp
{
    enum LoadReasons {
        kOnProxyDetection       = 0x01,
        kOnZWCADStartup       = 0x02,
        kOnCommandInvocation    = 0x04,
        kOnLoadRequest          = 0x08,
        kLoadDisabled           = 0x10,
        kTransparentlyLoadable  = 0x20,
        kOnIdleLoad             = 0x40
    };

    enum ErrorStatus {
        eOk             = 0,
        eInvalidKey     = 1,
        eInvalidSubKey  = 2,
        eKeyNotFound    = 3,
        eOutOfMemory    = 4,
        eInvalidValue   = 5,
        eValueNotFound  = 6,
        eKeyExists      = 7,
        eRegAccessDenied= 8,
        eRejected       = 9,
        eUnknownError   = 10
    };
};

class ZSOFT_NO_VTABLE ZcRxDynamicLinker: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxDynamicLinker);

    virtual void*          getSymbolAddress (const ZTCHAR * serviceName,
                                             const char * symbol) const = 0;

	virtual void*          getSymbolAddress (const ZTCHAR * serviceName,
		                                     const ZTCHAR * symbol) const = 0;

	virtual bool           initListedModules(const ZTCHAR * fileName) = 0;

    virtual bool           loadModule       (const ZTCHAR * fileName,
                                             bool printit,
                                             bool asCmd=false) = 0;
    virtual bool           loadApp          (const ZTCHAR  * appName,
                                             ZcadApp::LoadReasons al,
                                             bool printit,
                                             bool asCmd=false) = 0;

    virtual ZcRxObject*    registerService  (const ZTCHAR * serviceName,
                                             ZcRxService* serviceObj) = 0;

    virtual bool           unloadModule     (const ZTCHAR * fileName,
                                            bool asCmd=false) = 0;
    virtual bool           unloadApp        (const ZTCHAR * appName,
                                            bool asCmd=false) = 0;

    virtual void           addReactor       (ZcRxDLinkerReactor* newReactor) =0;

    virtual void           removeReactor    (ZcRxDLinkerReactor* oldReactor) =0;

    virtual bool           isApplicationLocked(const ZTCHAR * modulename) const =0;
    virtual bool           lockApplication  (void* appId) const = 0;
    virtual bool           unlockApplication(void* appId) const = 0;

    virtual bool           isAppMDIAware(const ZTCHAR * modulename) const =0;
    virtual bool           registerAppMDIAware(void* appId) const =0;
    virtual bool           registerAppNotMDIAware(void* appId) const =0;
 
    virtual bool           isAppBusy(const ZTCHAR * modulename) const =0;
    virtual void           setAppBusy(const ZTCHAR * modulename, bool bBusyFlag) const =0;

    virtual ZSoft::UInt32  ProductLcid() const =0;

};

#define zcrxDynamicLinker                                               \
ZcRxDynamicLinker::cast(zcrxSysRegistry()->at(ZCRX_DYNAMIC_LINKER))

class ZSOFT_NO_VTABLE ZcRxDLinkerReactor: public ZcRxObject
{
  public:
    ZCRX_DECLARE_MEMBERS(ZcRxDLinkerReactor);

    virtual void rxAppWillBeLoaded(const ZTCHAR  * moduleName);
    virtual void rxAppLoaded(const ZTCHAR  * moduleName);
    virtual void rxAppLoadAborted(const ZTCHAR  * moduleName);

    virtual void rxAppWillBeUnloaded(const ZTCHAR  * moduleName);
    virtual void rxAppUnloaded(const ZTCHAR  * moduleName);
    virtual void rxAppUnloadAborted(const ZTCHAR  * moduleName);
};

#pragma pack (pop)
#endif
