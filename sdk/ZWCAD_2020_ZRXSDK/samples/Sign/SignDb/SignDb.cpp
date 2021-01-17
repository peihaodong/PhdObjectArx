// SignDb.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ZsdkSign.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifndef ZSDKSIGNDB_SERVICE
#define ZSDKSIGNDB_SERVICE _T("ZSDKSIGNDB_SERVICE")
#endif

void initApp();
void unloadApp();

void RegisterZrxApp();


/////////////////////////////////////////////////////////////////////////////
// ZRX EntryPoint
extern "C" AcRx::AppRetCode 
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg) {
	case AcRx::kInitAppMsg:
		// Comment out the following line if your
		// application should be locked into memory
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	}
	return AcRx::kRetOK;
}


// Init this application. Register your
// reactors, custom classes...
void initApp()
{
	ZsdkSign::rxInit();
	acrxBuildClassHierarchy();
	acrxRegisterService(ZSDKSIGNDB_SERVICE);
	RegisterZrxApp();

	ZsdkSign::initCLSID();
}

// Unload this application. Unregister all objects
// registered in initApp.
void unloadApp()
{
	deleteAcRxClass(ZsdkSign::desc());
	delete acrxServiceDictionary->remove(ZSDKSIGNDB_SERVICE);
}

//----- Register the Application in the ZWCAD registry (demand loading)

// This function registers this ZRX Application
// on ZWCAD for demandload and in the
// Windows Registry.
void RegisterZrxApp()
{
	// Fill the AppInfo structure with our demand loading details.
	AcadAppInfo appInfo;
	appInfo.setAppName(_T("SignDb"));// AppName
	// Get the DBX file path.
	HMODULE hModule = GetModuleHandle(_T("SignDb.zrx"));
    TCHAR modulePath[512];
    DWORD pathLength = GetModuleFileName(hModule, modulePath, 512);
	if (pathLength)
		appInfo.setModuleName(modulePath); // Set the DBX file path.
	appInfo.setAppDesc(_T("SignDb Sample"));// Description
	appInfo.setLoadReason(
		AcadApp::LoadReasons(// Specify when we want this app to load.
		AcadApp::kOnProxyDetection |
		AcadApp::kOnLoadRequest));
	
	appInfo.writeToRegistry(true,true);// Write the AppInfo to the registry, include the DBX registry section.
}
