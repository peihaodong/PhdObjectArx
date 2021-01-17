// SignDbCom.h : main header file for the SignDbCom DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "SignDbCom_h.h"


// CSignDbComApp
// See SignDbCom.cpp for the implementation of this class
//

class CSignDbComApp : public CWinApp
{
public:
	CSignDbComApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
