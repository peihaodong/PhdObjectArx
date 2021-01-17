
#ifndef __ACUI_H__
#define __ACUI_H__

#include "../inc/zacui.h"

#include "acuiButton.h"
#include "acuiDialogWorksheet.h"
#include "acuiDialog.h"
#include "acuiTabCtrl.h"
#include "aced.h"

#include "acuiDock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"

#include "acuiComboBox.h"

#include "acuiString.h"

#include "acuiPathname.h"

#include "acuiNavDialog.h"

#include "../inc/zacui.h"

#ifndef ACUI_PORT
#define ACUI_PORT		ZCUI_PORT
#endif //#ifndef ACUI_PORT

#ifndef AcUiAppResourceInstance
#define AcUiAppResourceInstance		ZcUiAppResourceInstance
#endif //#ifndef AcUiAppResourceInstance

#ifndef AcUiContextHelpFileName
#define AcUiContextHelpFileName		ZcUiContextHelpFileName
#endif //#ifndef AcUiContextHelpFileName

#ifndef AcUiEnableToolTips
#define AcUiEnableToolTips		ZcUiEnableToolTips
#endif //#ifndef AcUiEnableToolTips

#ifndef AcUiFindContextHelpFullPath
#define AcUiFindContextHelpFullPath		ZcUiFindContextHelpFullPath
#endif //#ifndef AcUiFindContextHelpFullPath

#ifndef AcUiIsInputPending
#define AcUiIsInputPending		ZcUiIsInputPending
#endif //#ifndef AcUiIsInputPending

#ifndef AcUiMainWindow
#define AcUiMainWindow		ZcUiMainWindow
#endif //#ifndef AcUiMainWindow

#ifndef AcUiRootKey
#define AcUiRootKey		ZcUiRootKey
#endif //#ifndef AcUiRootKey

#ifndef CAcUiRegistryAccess
#define CAcUiRegistryAccess		CZcUiRegistryAccess
#endif //#ifndef CAcUiRegistryAccess

#ifndef CAcUiRegistryDeleteAccess
#define CAcUiRegistryDeleteAccess		CZcUiRegistryDeleteAccess
#endif //#ifndef CAcUiRegistryDeleteAccess

#ifndef CAcUiRegistryWriteAccess
#define CAcUiRegistryWriteAccess		CZcUiRegistryWriteAccess
#endif //#ifndef CAcUiRegistryWriteAccess

#ifndef CAcUiTabChildDialog
#define CAcUiTabChildDialog		CZcUiTabChildDialog
#endif //#ifndef CAcUiTabChildDialog

#ifndef CAcUiTabExtension
#define CAcUiTabExtension		CZcUiTabExtension
#endif //#ifndef CAcUiTabExtension

#ifndef CAdUiRegistryAccess
#define CAdUiRegistryAccess		CZdUiRegistryAccess
#endif //#ifndef CAdUiRegistryAccess

#ifndef CAdUiRegistryDeleteAccess
#define CAdUiRegistryDeleteAccess		CZdUiRegistryDeleteAccess
#endif //#ifndef CAdUiRegistryDeleteAccess

#ifndef CAdUiRegistryWriteAccess
#define CAdUiRegistryWriteAccess		CZdUiRegistryWriteAccess
#endif //#ifndef CAdUiRegistryWriteAccess

#ifndef InitAcUiDLL
#define InitAcUiDLL		InitZcUiDLL
#endif //#ifndef InitAcUiDLL

#ifndef _ACUI_BUILD
#define _ACUI_BUILD		_ZCUI_BUILD
#endif //#ifndef _ACUI_BUILD

#ifndef aced
#define aced		zced
#endif //#ifndef aced

#ifndef acuiButton
#define acuiButton		zcuiButton
#endif //#ifndef acuiButton

#ifndef acuiComboBox
#define acuiComboBox		zcuiComboBox
#endif //#ifndef acuiComboBox

#ifndef acuiDialog
#define acuiDialog		zcuiDialog
#endif //#ifndef acuiDialog

#ifndef acuiDialogWorksheet
#define acuiDialogWorksheet		zcuiDialogWorksheet
#endif //#ifndef acuiDialogWorksheet

#ifndef acuiDock
#define acuiDock		zcuiDock
#endif //#ifndef acuiDock

#ifndef acuiEdit
#define acuiEdit		zcuiEdit
#endif //#ifndef acuiEdit

#ifndef acuiHeaderCtrl
#define acuiHeaderCtrl		zcuiHeaderCtrl
#endif //#ifndef acuiHeaderCtrl

#ifndef acuiListBox
#define acuiListBox		zcuiListBox
#endif //#ifndef acuiListBox

#ifndef acuiListCtrl
#define acuiListCtrl		zcuiListCtrl
#endif //#ifndef acuiListCtrl

#ifndef acuiNavDialog
#define acuiNavDialog		zcuiNavDialog
#endif //#ifndef acuiNavDialog

#ifndef acuiPathname
#define acuiPathname		zcuiPathname
#endif //#ifndef acuiPathname

#ifndef acuiString
#define acuiString		zcuiString
#endif //#ifndef acuiString

#ifndef acuiTabCtrl
#define acuiTabCtrl		zcuiTabCtrl
#endif //#ifndef acuiTabCtrl


#endif //#ifndef __ACUI_H__
