// PhdObjectArx.cpp : ���� DLL �ĳ�ʼ�����̡�
//
// by yhl.

#include "stdafx.h"
#include "Resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//-----------------------------------------------------------------------------
//- Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(PhdObjectArxDLL)
	//- Now you can use the CAcModuleResourceOverride class in
	//- your application to switch to the correct resource instance.
	//- Please see the ObjectARX Documentation for more details

//-----------------------------------------------------------------------------
//- DLL Entry Point
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	//- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved) ;

	if ( dwReason == DLL_PROCESS_ATTACH ) {
		_hdllInstance =hInstance ;
		PhdObjectArxDLL.AttachInstance(hInstance);
		InitAcUiDLL();
	} else if ( dwReason == DLL_PROCESS_DETACH ) {
		PhdObjectArxDLL.DetachInstance();
	}
	return (TRUE) ;
}

