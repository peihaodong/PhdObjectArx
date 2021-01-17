
#include "stdafx.h"

#include "SampleDlg.h"
#include "AcExtensionModule.h"


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

static void initApp()
{

	CAcModuleResourceOverride resOverride;

	acedRegCmds->addCommand(_T("ZRX_DLG_SAMPLE"), 
		_T("ZRXDLGSAMPLE"), 
		_T("DLGSAMPLE"), 
		ACRX_CMD_MODAL, 
		dialogCreate,
		NULL,
		-1,
		theArxDLL.ModuleResourceInstance());

}


static void unloadApp()
{

	// Do other cleanup tasks here  
	acedRegCmds->removeGroup(_T("ZRX_DLG_SAMPLE"));  
}


//////////////////////////////////////////////////////////////
//
// Entry points
//
//////////////////////////////////////////////////////////////

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
	case AcRx::kInitDialogMsg:

		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}
