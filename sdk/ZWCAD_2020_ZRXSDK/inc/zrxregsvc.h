

#ifndef   _ZRXREGSVC_H
#define   _ZRXREGSVC_H 1

#include "zrxdlinkr.h"
#include "zadesk.h"
#pragma pack (push, 8)

bool zcrxLoadModule(const ZTCHAR * moduleName, bool printit, bool asCmd=false);

bool zcrxLoadApp(const ZTCHAR * appname, bool asCmd=false);

bool zcrxUnloadModule(const ZTCHAR * moduleName, bool asCmd=false);

bool zcrxUnloadApp(const ZTCHAR * appName, bool asCmd=false);

void *zcrxLoadedApps();

bool ZSOFT_STDCALL zcrxAppIsLoaded(const ZTCHAR  *pAppName);

const ZTCHAR * zcrxProductKey();

const ZTCHAR * zcrxObjectDBXRegistryKey();

ZSoft::UInt32 zcrxProductLCID();

ZcadApp::ErrorStatus zcrxRegisterApp(ZcadApp::LoadReasons alr,
        const ZTCHAR  *logicalName, bool bDwgU = false);

ZcadApp::ErrorStatus zcrxUnregisterApp(const ZTCHAR  *logicalname,
                                       bool bDwgU = false);

void * zcrxGetServiceSymbolAddr(const ZTCHAR * serviceName, const ZTCHAR * symbol);

void* zcrxRegisterService(const ZTCHAR * serviceName);

bool zcrxServiceIsRegistered(const ZTCHAR * serviceName);

bool zcrxUnlockApplication(void* appId);

bool zcrxApplicationIsLocked(const ZTCHAR * modulename);

bool zcrxLockApplication(void* appId);

bool zcrxIsAppMDIAware(const ZTCHAR  * moduleName);

bool zcrxRegisterAppMDIAware(void* appId);

bool zcrxRegisterAppNotMDIAware(void* appId);

#pragma pack (pop)
#endif
