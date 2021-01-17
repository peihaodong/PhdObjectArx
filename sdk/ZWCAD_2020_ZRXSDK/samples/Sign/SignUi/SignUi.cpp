// SignUi.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


extern void createSign();
void initApp();
void unloadApp();
void RegisterZrxApp();


/////////////////////////////////////////////////////////////////////////////
// ZRX EntryPoint
extern "C" AcRx::AppRetCode 
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    AcRxDynamicLinker *pLinker = acrxDynamicLinker;
    switch (msg) {
    case AcRx::kInitAppMsg:
        // Comment out the following line if your
        // application should be locked into memory
        pLinker->unlockApplication(pkt);
        pLinker->registerAppMDIAware(pkt);
        // check if the arx app is loaded or not.
        // if not, load it as UI so that we won't have
        // proxy if this dll is unloaded by OS
        if (!::acrxAppIsLoaded(_T("SignDb.zrx")))
        {
            if (!pLinker->loadModule(_T("SignDb.zrx"), false, true))
                return AcRx::kRetError;
        }
        // bump the reference count 
        pLinker->loadModule(_T("SignDb.zrx"), false, false);
        initApp();
        break;
    case AcRx::kUnloadAppMsg:
        pLinker->unloadModule(_T("SignDb.zrx"));
        unloadApp();
        break;
    }
    return AcRx::kRetOK;
}


// Init this application. Register your
// commands, reactors...
void initApp()
{
	acedRegCmds->addCommand(_T("ZSDK_SIGN"), _T("ZSDK_SIGN"), _T("SIGN"), ACRX_CMD_MODAL, createSign);
    RegisterZrxApp();

	InitAcUiDLL();
}

// Unload this application. Unregister all objects
// registered in initApp.
void unloadApp()
{
    acedRegCmds->removeGroup(_T("ZSDK_SIGN"));
}

void RegisterZrxApp()
{
    // Fill the AppInfo structure with our demand loading details.
    AcadAppInfo appInfo;
    appInfo.setAppName(_T("SignUi"));// Application Name
    appInfo.setModuleName(acedGetAppName());// ARX File Location
    appInfo.setAppDesc(_T("SignUi Sample")); // Description
    appInfo.setLoadReason( // Specify when we want this to load
        AcadApp::LoadReasons(
        AcadApp::kOnCommandInvocation |
        AcadApp::kOnLoadRequest));
    
    appInfo.writeToRegistry(false,true);// Write the AppInfo to the registry, don't write to DBX registry section.
    appInfo.writeGroupNameToRegistry(_T("ZSDK_SIGN")); // Write the Group Name
    appInfo.writeCommandNameToRegistry(_T("SIGN"),_T("SIGN"));// Write our command.
}