

#ifndef _zdui_h
#define _zdui_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zadui_port.h"

class ZDUI_PORT CZdUiThemeManager;    

void ZDUI_PORT InitZdUiDLL();

int  ZDUI_PORT ZdUiAlertDialog (
    LPCTSTR captionText,
    LPCTSTR msg0Text,
    LPCTSTR button0Text,                      
    LPCTSTR button1Text,
    UINT defButton = 0          
);

int  ZDUI_PORT ZdUiDataValidationLevel ();      

BOOL ZDUI_PORT ZdUiFindContextHelpFullPath (
    LPCTSTR fileName, CString& fullPath
);

void ZDUI_PORT ZdUiSubstituteShellFont (CWnd& dlg, CFont& font);
CZdUiThemeManager ZDUI_PORT * ZdUiGetThemeManager();  

bool ZDUI_PORT ZdUiSetDockBarMinWidth(int width);

class ZDUI_PORT CZdUiBaseDialog;
class ZDUI_PORT CZdUiComboBox;
class ZDUI_PORT CZdUiDialog;
class ZDUI_PORT CZdUiDialogBar;
class ZDUI_PORT CZdUiFileDialog;
class ZDUI_PORT CZdUiTab;
class ZDUI_PORT CZdUiTabChildDialog;
class ZDUI_PORT CZdUiTabExtensionManager;
class ZDUI_PORT CZdUiTabMainDialog;
class ZDUI_PORT CZdUiDialogWorksheet;  
class ZDUI_PORT CZdUiDropTarget;
class ZDUI_PORT CZdUiTheme;            
class ZDUI_PORT CZdUiPalette;
class ZDUI_PORT CZdUiPaletteSet;
class ZDUI_PORT CZdUiThemeMgrReactor;  
class ZDUI_PORT CZduiLabelEdit;

#define MOVEX               0x00001
#define MOVEY               0x00002
#define MOVEXY              0x00003
#define ELASTICX            0x00010
#define ELASTICY            0x00020
#define ELASTICXY           0x00030

#pragma pack (push, 8)
typedef struct _dlgControlTag {
    DWORD       id;
    DWORD       flags;
    DWORD       pct;
} DLGCTLINFO, *PDLGCTLINFO;

#pragma pack (pop)

namespace ZdUi
{
    enum ZdUiIconMode{
        kSmall = 0,
        kLarge
    };

    enum ZdUiImage
    {
        kImageSmall      = 1,
        kImageLarge      = 2,

        kImageEnable     = 4,
        kImageDisable    = 8,
    };

};
#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#include <winreg.h>

#include <afxole.h>

#include "zaduiRegistryAccess.h"

#include "zaduiMessage.h"
#include "zaduiDropTarget.h"
#include "zaduiTabExtension.h"
#include "zaduiTextTip.h"
#include "zaduiButton.h"
#include "zaduiTabCtrl.h"

#include "zaduiBaseDialog.h"
#include "zaduiDialog.h"
#include "zaduiDialogBar.h"
#include "zaduiFileDialog.h"
#include "zaduiTabChildDialog.h"
#include "zaduiTabMainDialog.h"

#include "zaduiEdit.h"
#include "zaduiHeaderCtrl.h"
#include "zaduiListBox.h"
#include "zaduiListCtrl.h"
#include "zaduiComboBox.h"

#include "zaduiDock.h"

#include "zaduiVolumeDescriptor.h"
#include "zaduiPathname.h"
#include "zaduiPalette.h"
#include "zaduiPaletteSet.h"
#else
#include "zaduiPathname.h"
#endif
#endif


