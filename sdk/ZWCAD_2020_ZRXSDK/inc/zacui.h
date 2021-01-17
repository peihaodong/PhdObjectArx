

#ifndef _zacui_h
#define _zacui_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifdef  _ZCUI_BUILD
#  define   ZCUI_PORT  __declspec(dllexport)
#else
#  define   ZCUI_PORT  __declspec(dllimport)
#endif

#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
ZCUI_PORT void InitZcUiDLL();

ZCUI_PORT HINSTANCE ZcUiAppResourceInstance ();
ZCUI_PORT LPCTSTR ZcUiContextHelpFileName();
ZCUI_PORT BOOL ZcUiEnableToolTips ();
ZCUI_PORT BOOL ZcUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);
ZCUI_PORT BOOL ZcUiIsInputPending ();
ZCUI_PORT CWnd * ZcUiMainWindow ();
ZCUI_PORT void ZcUiRootKey (CString& rootKey);

typedef CZdUiRegistryAccess         CZcUiRegistryAccess;
typedef CZdUiRegistryDeleteAccess   CZcUiRegistryDeleteAccess;
typedef CZdUiRegistryWriteAccess    CZcUiRegistryWriteAccess;


#include "zacuiButton.h"
#include "zacuiDialogWorksheet.h"
#include "zacuiDialog.h"
#include "zacuiTabCtrl.h"

typedef CZcUiTabChildDialog         CZcUiTabExtension;

#include "zaced.h"

#include "zacuiDock.h"
#include "zacuiEdit.h"
#include "zacuiHeaderCtrl.h"
#include "zacuiListBox.h"
#include "zacuiListCtrl.h"

#include "zacuiComboBox.h"

#include "zacuiString.h"

#include "zacuiPathname.h"

#include "zacuiNavDialog.h"
#else
#include "zacuipathname.h"
#endif

#endif


