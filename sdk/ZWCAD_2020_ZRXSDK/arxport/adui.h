
#ifndef __ADUI_H__
#define __ADUI_H__
#include "../inc/zadui.h"


#include <winreg.h>


#include <afxole.h>

#include "aduiRegistryAccess.h"

#include "aduiMessage.h"
#include "aduiDropTarget.h"
#include "aduiTabExtension.h"
#include "aduiTextTip.h"
#include "aduiButton.h"
#include "aduiTabCtrl.h"

#include "aduiBaseDialog.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiFileDialog.h"
#include "aduiTabChildDialog.h"
#include "aduiTabMainDialog.h"

#include "aduiEdit.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiComboBox.h"

#include "aduiDock.h"

#include "aduiVolumeDescriptor.h"
#include "aduiPathname.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"


#ifndef ADUI_PORT
#define ADUI_PORT		ZDUI_PORT
#endif //#ifndef ADUI_PORT

#ifndef AdUiAlertDialog
#define AdUiAlertDialog		ZdUiAlertDialog
#endif //#ifndef AdUiAlertDialog

#ifndef AdUiDataValidationLevel
#define AdUiDataValidationLevel		ZdUiDataValidationLevel
#endif //#ifndef AdUiDataValidationLevel

#ifndef AdUiFindContextHelpFullPath
#define AdUiFindContextHelpFullPath		ZdUiFindContextHelpFullPath
#endif //#ifndef AdUiFindContextHelpFullPath

#ifndef AdUiGetThemeManager
#define AdUiGetThemeManager		ZdUiGetThemeManager
#endif //#ifndef AdUiGetThemeManager

#ifndef AdUiSetDockBarMinWidth
#define AdUiSetDockBarMinWidth		ZdUiSetDockBarMinWidth
#endif //#ifndef AdUiSetDockBarMinWidth

#ifndef AdUiSubstituteShellFont
#define AdUiSubstituteShellFont		ZdUiSubstituteShellFont
#endif //#ifndef AdUiSubstituteShellFont

#ifndef CAdUiBaseDialog
#define CAdUiBaseDialog		CZdUiBaseDialog
#endif //#ifndef CAdUiBaseDialog

#ifndef CAdUiComboBox
#define CAdUiComboBox		CZdUiComboBox
#endif //#ifndef CAdUiComboBox

#ifndef CAdUiDialog
#define CAdUiDialog		CZdUiDialog
#endif //#ifndef CAdUiDialog

#ifndef CAdUiDialogBar
#define CAdUiDialogBar		CZdUiDialogBar
#endif //#ifndef CAdUiDialogBar

#ifndef CAdUiDialogWorksheet
#define CAdUiDialogWorksheet		CZdUiDialogWorksheet
#endif //#ifndef CAdUiDialogWorksheet

#ifndef CAdUiDropTarget
#define CAdUiDropTarget		CZdUiDropTarget
#endif //#ifndef CAdUiDropTarget

#ifndef CAdUiFileDialog
#define CAdUiFileDialog		CZdUiFileDialog
#endif //#ifndef CAdUiFileDialog

#ifndef CAdUiPalette
#define CAdUiPalette		CZdUiPalette
#endif //#ifndef CAdUiPalette

#ifndef CAdUiPaletteSet
#define CAdUiPaletteSet		CZdUiPaletteSet
#endif //#ifndef CAdUiPaletteSet

#ifndef CAdUiTab
#define CAdUiTab		CZdUiTab
#endif //#ifndef CAdUiTab

#ifndef CAdUiTabChildDialog
#define CAdUiTabChildDialog		CZdUiTabChildDialog
#endif //#ifndef CAdUiTabChildDialog

#ifndef CAdUiTabExtensionManager
#define CAdUiTabExtensionManager		CZdUiTabExtensionManager
#endif //#ifndef CAdUiTabExtensionManager

#ifndef CAdUiTabMainDialog
#define CAdUiTabMainDialog		CZdUiTabMainDialog
#endif //#ifndef CAdUiTabMainDialog

#ifndef CAdUiTheme
#define CAdUiTheme		CZdUiTheme
#endif //#ifndef CAdUiTheme

#ifndef CAdUiThemeManager
#define CAdUiThemeManager		CZdUiThemeManager
#endif //#ifndef CAdUiThemeManager

#ifndef CAdUiThemeMgrReactor
#define CAdUiThemeMgrReactor		CZdUiThemeMgrReactor
#endif //#ifndef CAdUiThemeMgrReactor

#ifndef CAduiLabelEdit
#define CAduiLabelEdit		CZduiLabelEdit
#endif //#ifndef CAduiLabelEdit

#ifndef InitAdUiDLL
#define InitAdUiDLL		InitZdUiDLL
#endif //#ifndef InitAdUiDLL

#ifndef _ADUI_BUILD
#define _ADUI_BUILD		_ZDUI_BUILD
#endif //#ifndef _ADUI_BUILD

#endif //#ifndef __ADUI_H__
