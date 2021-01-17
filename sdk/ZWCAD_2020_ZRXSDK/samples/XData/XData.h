// XData.h : main header file for the XData DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CXDataApp
// See XData.cpp for the implementation of this class
//

class CXDataApp : public CWinApp
{
public:
	CXDataApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
