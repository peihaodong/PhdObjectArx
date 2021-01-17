// DatabaseOp.h : main header file for the DatabaseOp DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDatabaseOpApp
// See DatabaseOp.cpp for the implementation of this class
//

class CDatabaseOpApp : public CWinApp
{
public:
	CDatabaseOpApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
