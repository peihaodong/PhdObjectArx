
#ifndef __RXMFCAPI_H__
#define __RXMFCAPI_H__

#include "AdAChar.h"
#include "AcStatusBar.h"

#include "core_rxmfcapi.h"
#include "../inc/zrxmfcapi.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcApGetDatabase
#define AcApGetDatabase		ZcApGetDatabase
#endif //#ifndef AcApGetDatabase

#ifndef AcApStatusBar
#define AcApStatusBar		ZcApStatusBar
#endif //#ifndef AcApStatusBar

#ifndef AcChildFrmSettings
#define AcChildFrmSettings		ZcChildFrmSettings
#endif //#ifndef AcChildFrmSettings



#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcPane
#define AcPane		ZcPane
#endif //#ifndef AcPane

#ifndef AcStatusBar
#define AcStatusBar		ZcStatusBar
#endif //#ifndef AcStatusBar

#ifndef AcStatusBarMenuItem
#define AcStatusBarMenuItem		ZcStatusBarMenuItem
#endif //#ifndef AcStatusBarMenuItem

#ifndef AcStatusBarType
#define AcStatusBarType		ZcStatusBarType
#endif //#ifndef AcStatusBarType

#ifndef WM_ACAD_KEEPFOCUS
#define WM_ACAD_KEEPFOCUS		WM_ZCAD_KEEPFOCUS
#endif //#ifndef WM_ACAD_KEEPFOCUS

#ifndef acedAddDropTarget
#define acedAddDropTarget		zcedAddDropTarget
#endif //#ifndef acedAddDropTarget

#ifndef acedDrawingStatusBarsVisible
#define acedDrawingStatusBarsVisible		zcedDrawingStatusBarsVisible
#endif //#ifndef acedDrawingStatusBarsVisible

#ifndef acedDwgPoint
#define acedDwgPoint		zcedDwgPoint
#endif //#ifndef acedDwgPoint

#ifndef acedEndOverrideDropTarget
#define acedEndOverrideDropTarget		zcedEndOverrideDropTarget
#endif //#ifndef acedEndOverrideDropTarget

#ifndef acedGetAcadDoc
#define acedGetAcadDoc		zcedGetZcadDoc
#endif //#ifndef acedGetAcadDoc

#ifndef acedGetAcadDockCmdLine
#define acedGetAcadDockCmdLine		zcedGetZcadDockCmdLine
#endif //#ifndef acedGetAcadDockCmdLine

#ifndef acedGetAcadDwgView
#define acedGetAcadDwgView		zcedGetZcadDwgView
#endif //#ifndef acedGetAcadDwgView

#ifndef acedGetAcadFrame
#define acedGetAcadFrame		zcedGetZcadFrame
#endif //#ifndef acedGetAcadFrame

#ifndef acedGetAcadBrandingResourceInstance
#define acedGetAcadBrandingResourceInstance		zcedGetZcadBrandingResourceInstance
#endif //#ifndef acedGetAcadBrandingResourceInstance

#ifndef acedGetAcadTextCmdLine
#define acedGetAcadTextCmdLine		zcedGetZcadTextCmdLine
#endif //#ifndef acedGetAcadTextCmdLine

#ifndef acedGetAcadWinApp
#define acedGetAcadWinApp		zcedGetZcadWinApp
#endif //#ifndef acedGetAcadWinApp

#ifndef acedGetApplicationStatusBar
#define acedGetApplicationStatusBar		zcedGetApplicationStatusBar
#endif //#ifndef acedGetApplicationStatusBar


#ifndef acedGetIUnknownForCurrentCommand
#define acedGetIUnknownForCurrentCommand		zcedGetIUnknownForCurrentCommand
#endif //#ifndef acedGetIUnknownForCurrentCommand

#ifndef acedGetMenu
#define acedGetMenu		zcedGetMenu
#endif //#ifndef acedGetMenu

#ifndef acedGetRegistryCompany
#define acedGetRegistryCompany		zcedGetRegistryCompany
#endif //#ifndef acedGetRegistryCompany

#ifndef acedGetAcadBrandingResourceInstance
#define acedGetAcadBrandingResourceInstance		zcedGetZcadBrandingResourceInstance
#endif //#ifndef acedGetAcadBrandingResourceInstance

#ifndef acedIsInputPending
#define acedIsInputPending		zcedIsInputPending
#endif //#ifndef acedIsInputPending

#ifndef acedRegisterCustomDropTarget
#define acedRegisterCustomDropTarget		zcedRegisterCustomDropTarget
#endif //#ifndef acedRegisterCustomDropTarget


#ifndef acedRemoveDropTarget
#define acedRemoveDropTarget		zcedRemoveDropTarget
#endif //#ifndef acedRemoveDropTarget

#ifndef acedRevokeCustomDropTarget
#define acedRevokeCustomDropTarget		zcedRevokeCustomDropTarget
#endif //#ifndef acedRevokeCustomDropTarget


#ifndef acedSetIUnknownForCurrentCommand
#define acedSetIUnknownForCurrentCommand		zcedSetIUnknownForCurrentCommand
#endif //#ifndef acedSetIUnknownForCurrentCommand


#ifndef acedShowDrawingStatusBars
#define acedShowDrawingStatusBars		zcedShowDrawingStatusBars
#endif //#ifndef acedShowDrawingStatusBars

#ifndef acedStartOverrideDropTarget
#define acedStartOverrideDropTarget		zcedStartOverrideDropTarget
#endif //#ifndef acedStartOverrideDropTarget

#ifndef acedUnregisterStatusBarMenuItem
#define acedUnregisterStatusBarMenuItem		zcedUnregisterStatusBarMenuItem
#endif //#ifndef acedUnregisterStatusBarMenuItem

#ifndef acedSetChildFrameSettings
#define acedSetChildFrameSettings		zcedSetChildFrameSettings
#endif //#ifndef acedSetChildFrameSettings

#ifndef acedSetStatusBarPaneID
#define acedSetStatusBarPaneID		zcedSetStatusBarPaneID
#endif //#ifndef acedSetStatusBarPaneID



#ifndef _ARX_CUSTOM_DRAG_N_DROP_
#define _ARX_CUSTOM_DRAG_N_DROP_		_ZRX_CUSTOM_DRAG_N_DROP_
#endif //#ifndef _ARX_CUSTOM_DRAG_N_DROP_

#ifndef acedHatchPalletteDialog
#define acedHatchPalletteDialog		zcedHatchPalletteDialog
#endif //#ifndef acedHatchPalletteDialog

int ZDCHatchGetRegistryHPFileName(CString& strHPFileName);
int ZDCHatchWriteRegistryHPFileName(CString strHPFileName);

#ifndef ADCHatchGetRegistryHPFileName
#define ADCHatchGetRegistryHPFileName		ZDCHatchGetRegistryHPFileName
#endif //#ifndef ADCHatchGetRegistryHPFileName

#ifndef ADCHatchWriteRegistryHPFileName
#define ADCHatchWriteRegistryHPFileName		ZDCHatchWriteRegistryHPFileName
#endif //#ifndef ADCHatchWriteRegistryHPFileName

#endif //#ifndef __RXMFCAPI_H__