
#include "stdafx.h"

[!if MFC_EXT_SHARED]
#include "SampleDlg.h"
#include "AcExtensionModule.h"
[!else]
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
[!endif]


[!if MFC_EXT_SHARED]
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern HWND adsw_acadMainWnd();

AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);

void dialogCreate()
{

	// Modal
	SampleDlg dlg(CWnd::FromHandle(adsw_acadMainWnd()));
	int nReturnValue = dlg.DoModal();

}
[!else]
void helloWorld()
{ 
	acutPrintf(_T("\nHello World!"));
}
[!endif]

void initApp()
{ 
	// register a command with the AutoCAD command mechanism
	[!if MFC_EXT_SHARED]
	CAcModuleResourceOverride resOverride;

	acedRegCmds->addCommand(_T("ZRX_DLG_SAMPLE"), 
		_T("ZRXDLGSAMPLE"), 
		_T("DLGSAMPLE"), 
		ACRX_CMD_MODAL, 
		dialogCreate,
		NULL,
		-1,
		theArxDLL.ModuleResourceInstance());
	[!else]
	acedRegCmds->addCommand(_T("HELLOWORLD_COMMANDS"),
		_T("Hello"),
		_T("Hello"),
		ACRX_CMD_TRANSPARENT,
		helloWorld);
	[!endif]
}

void unloadApp()
{ 
	[!if MFC_EXT_SHARED]
	acedRegCmds->removeGroup(_T("ZRX_DLG_SAMPLE"));  
	[!else]
	acedRegCmds->removeGroup(_T("HELLOWORLD_COMMANDS"));
	[!endif]
}

//////////////////////////////////////////////////////////////
//
// Entry points
//
//////////////////////////////////////////////////////////////
[!if MFC_EXT_SHARED]
extern "C" int APIENTRY
	DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		theArxDLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		theArxDLL.DetachInstance();  
	}
	return 1;   // ok
}
[!endif]

extern "C" AcRx::AppRetCode zcrxEntryPoint( AcRx::AppMsgCode msg, void* appId)
{
	switch( msg ) 
	{
	case AcRx::kInitAppMsg: 
		acrxDynamicLinker->unlockApplication(appId);
		acrxDynamicLinker->registerAppMDIAware(appId);
		initApp(); 
		break;
	case AcRx::kUnloadAppMsg: 
		unloadApp(); 
		break;
[!if MFC_EXT_SHARED]
	case AcRx::kInitDialogMsg:

		break;
[!endif]
	default:
		break;
	}
	return AcRx::kRetOK;
}