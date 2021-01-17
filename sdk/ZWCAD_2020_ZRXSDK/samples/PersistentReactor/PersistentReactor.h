// PersistentReactor.h : main header file for the PersistentReactor DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPersistentReactorApp
// See PersistentReactor.cpp for the implementation of this class
//

class CPersistentReactorApp : public CWinApp
{
public:
	CPersistentReactorApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
