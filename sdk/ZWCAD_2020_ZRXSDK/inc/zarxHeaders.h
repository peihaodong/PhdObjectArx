
#pragma once
#include "zdbxHeaders.h"

#pragma pack (push, 8)
#pragma warning (disable: 4311 4312 4275)

#pragma comment (lib ,"ZWCAD.lib")
#pragma comment (lib, "ZwZrx.lib")
#ifdef _AFXEXT
	#pragma comment (lib ,"ZwUI.lib")
	#pragma comment (lib ,"ZdUI.lib")
#endif // #ifdef _AFXEXT

#include "zaccmd.h"
#include "zaced.h"
#include "zacdocman.h"
#include "zactrans.h"
#include "zacedsel.h"
#include "zacedxref.h"
#include "zlngtrans.h"
#include "zdbltrans.h"
#include "zAcApLMgr.h"
#include "zacedInet.h"
#include "zacedinpt.h"
#include "zAcDblClkEdit.h"
#include "zAcGradThumbEng.h"

#include "zdbjig.h"
#include "zdbmatch.h"
#include "zdbInterferencePE.h"
#include "zdbosnap.h"
#include "zxreflock.h"

#include "zclipdata.h"

#ifdef _AFXEXT
#include "zgs.h"
#endif
#include "zAcGsManager.h"

#include "zacpl.h"
#include "zacpldsddata.h"
#include "zacpldsdentry.h"
#include "zacplhostappservices.h"
#include "zacplobject.h"
#include "zacplplotconfig.h"
#include "zacplplotconfigmgr.h"
#include "zacplplotengine.h"
#include "zacplploterrorhandler.h"
#include "zacplploterrorhandlerlock.h"
#include "zacplplotfactory.h"
#include "zacplplotinfo.h"
#include "zacplplotinfovalidator.h"
#include "zacplplotlogger.h"
#include "zacplplotloggingerrorhandler.h"
#include "zacplplotprogress.h"
#include "zacplplotreactor.h"
#include "zacplplotreactormgr.h"

#include "zAcPublishReactors.h"
#include "zacpublishuireactors.h"

#include "zacdmmapi.h"
#include "zacdmmeplotproperties.h"
#include "zacdmmeplotproperty.h"
#include "zacdmmutils.h"

#ifdef _AFXEXT
#pragma warning (disable: 4275)
#include "zadui.h"
#include "zAcExtensionModule.h"
#include "zaduiBaseDialog.h"
#include "zaduiButton.h"
#include "zaduiComboBox.h"
#include "zaduiDialog.h"
#include "zaduiDialogBar.h"
#include "zaduiDialogWorksheet.h"
#include "zaduiDock.h"
#include "zaduiDropTarget.h"
#include "zaduiEdit.h"
#include "zaduiFileDialog.h"
#include "zaduiHeaderCtrl.h"
#include "zaduiListBox.h"
#include "zaduiListCtrl.h"
#include "zaduiMessage.h"
#include "zaduiPalette.h"
#include "zaduiPaletteSet.h"
#include "zaduiPathname.h"
#include "zaduiRegistryAccess.h"
#include "zaduiTabChildDialog.h"
#include "zaduiTabCtrl.h"
#include "zaduiTabExtension.h"
#include "zaduiTabMainDialog.h"
#include "zaduiTextTip.h"
#include "zaduiTheme.h"
#include "zaduiThemeManager.h"
#include "zaduiVolumeDescriptor.h"
#include "zaduiCoupledGroupCtrl.h"
#include "zaduiGroupCtrl.h"
#include "zaduipathenums.h"

#include "zacui.h"
#include "zrxmfcapi.h"
#include "zAcStatusBar.h"
#include "zacuiButton.h"
#include "zacuiComboBox.h"
#include "zacuiDialog.h"
#include "zacuiDialogWorksheet.h"
#include "zacuidock.h"
#include "zacuiEdit.h"
#include "zacuiHeaderCtrl.h"
#include "zacuiListBox.h"
#include "zacuiListCtrl.h"
#include "zacuiNavDialog.h"
#include "zacuiPathname.h"
#include "zacuiString.h"
#include "zacuiTabCtrl.h"

#include "zaNav.h"
#include "zaNavArray.h"
#include "zaNavData.h"
#include "zaNavDataArray.h"
#include "zaNavDialog.h"
#include "zaNavFilter.h"
#include "zaNavFilterArray.h"
#include "zaNavListCtrl.h"

#include "zAcTc.h"
#include "zAcTcUiManager.h"
#include "zAcTcUI.h"
#include "zAcTcUiCatalogView.h"
#include "zAcTcUiCatalogViewItem.h"
#include "zAcTcUiPaletteView.h"
#include "zAcTcUiToolPalette.h"
#include "zAcTcUiToolPaletteSet.h"
#include "zAcTcUiToolPaletteGroup.h"
#include "zAcTcUiScheme.h"
#include "zAcTc_i.h"		
#include "zdcdispid.h"

#include "zAcFdUi.h"
#include "zAcFdUiFieldDialog.h"
#include "zAcFdUiFieldDialogHook.h"
#include "zAcFdUiFieldFormatDialog.h"
#include "zAcFdUiFieldFormatList.h"
#include "zAcFdUiFieldManager.h"
#include "zAcFdUiFieldOptionDialog.h"
#include "zAcFdUtil.h"

#endif

#include "zadsdlg.h"
#include "zadsrxdef.h"
#include "zadslib.h"

#include "zacssgetfilter.h"
#include "zacutasrt.h"
#include "zarxEntryPoint.h"
#include "zAcApDMgr.h"

#ifdef __ATLCOM_H__
#include "zdynpropmgr.h"
#endif

#ifdef _INC_LEAGACY_HEADERS_
#include "zol_errno.h"
#endif

#ifdef _ASE_SUPPORT_
#include "zasisys.h"
#include "zasiappl.h"
#include "zcsptypes.h"
#include "zavoidtry.h"
#include "zasiucode.h"
#include "zasiconst.h"
#include "zasisdata.h"
#include "zasiclass.h"
#include "zaseconst.h"
#include "zaseclass.h"
#endif

#ifdef _RENDER_SUPPORT_
#include "averror.h"
#include "avlib.h"
#endif

#pragma pack (pop)
