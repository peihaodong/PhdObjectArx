
#ifndef __ARXHEADERS_H__
#define __ARXHEADERS_H__

#include "dbxHeaders.h"
//----- editor API
#include "accmd.h"
#include "aced.h"
#include "acdocman.h"
#include "actrans.h"
#include "acedsel.h"
#include "acedxref.h"
#include "lngtrans.h"
#include "dbltrans.h"
#include "acaplmgr.h"
#include "acedinet.h"
#include "acedinpt.h"
#include "AcDblClkEdit.h"
#include "AcGradThumbEng.h"

//----- Db sub-system specific
#include "dbjig.h"
#include "dbmatch.h"
#include "dbInterferencePE.h"
#include "dbosnap.h"
#include "xreflock.h"

//----- ext.
#include "clipdata.h"

//----- Graphic System
#ifdef _AFXEXT
#include "gs.h"
#endif // _AFXEXT
#include "AcGsManager.h"

//----- Plot
#include "AcPl.h"
#include "AcPlDSDData.h"
#include "AcPlDSDEntry.h"
#include "AcPlHostAppServices.h"
#include "AcPlObject.h"
#include "AcPlPlotConfig.h"
#include "AcPlPlotConfigMgr.h"
#include "AcPlPlotEngine.h"
#include "AcPlPlotErrorHandler.h"
#include "AcPlPlotErrorHandlerLock.h"
#include "AcPlPlotFactory.h"
#include "AcPlPlotInfo.h"
#include "AcPlPlotInfoValidator.h"
#include "AcPlPlotLogger.h"
#include "AcPlPlotLoggingErrorHandler.h"
#include "AcPlPlotProgress.h"
#include "acplplotreactor.h"
#include "acplplotreactormgr.h"

//----- Publish API
#include "acpublishreactors.h"
#include "acpublishuireactors.h"

//----- Publish/Plot API for DWF
#include "acdmmapi.h"
#include "acdmmeplotproperties.h"
#include "acdmmeplotproperty.h"
#include "acdmmutils.h"

//----- MFC Extensions
#ifdef _AFXEXT
#pragma warning (disable: 4275)
#include "adui.h"
#include "AcExtensionModule.h"
#include "aduiBaseDialog.h"
#include "aduiButton.h"
#include "aduiComboBox.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiDialogWorksheet.h"
#include "aduiDock.h"
#include "aduiDropTarget.h"
#include "aduiEdit.h"
#include "aduiFileDialog.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiMessage.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"
#include "aduiPathname.h"
#include "aduiRegistryAccess.h"
#include "aduiTabChildDialog.h"
#include "aduiTabCtrl.h"
#include "aduiTabExtension.h"
#include "aduiTabMainDialog.h"
#include "aduiTextTip.h"
#include "aduiTheme.h"
#include "aduiVolumeDescriptor.h"
#include "aduipathenums.h"

//----- MFC Extensions
#include "acui.h"
#include "rxmfcapi.h"
#include "AcStatusBar.h"
#include "acuiButton.h"
#include "acuiComboBox.h"
#include "acuiDialog.h"
#include "acuiDialogWorksheet.h"
#include "acuidock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"
#include "acuiNavDialog.h"
#include "acuiPathname.h"
#include "acuiString.h"
#include "acuiTabCtrl.h"

//----- navigation dialog
#include "aNav.h"
#include "aNavArray.h"
#include "aNavData.h"
#include "aNavDataArray.h"
#include "aNavDialog.h"
#include "aNavFilter.h"
#include "aNavFilterArray.h"
#include "aNavListCtrl.h"

//----- Tool Palette API
#include "dcdispid.h"

//- Field API

#endif // _AFXEXT

//----- ZDS
#include "adsdlg.h"
#include "adsrxdef.h"
#include "adslib.h"

//----- Utils
#include "acssgetfilter.h"
//#include "acutasrt.h"
#include "arxEntryPoint.h"
#include "AcApDMgr.h"

//----- COM extensions
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif // __ATLCOM_H__

//----- Legacy headers
#ifdef _INC_LEAGACY_HEADERS_
#include "ol_errno.h"	//----- R12 ELP ERRNO CODES
#endif // _INC_LEAGACY_HEADERS_

//----- ASI/ASE extensions
#ifdef _ASE_SUPPORT_
#include "asisys.h"
#include "asiappl.h"
#include "csptypes.h"
#include "avoidtry.h"
#include "asiucode.h"
#include "asiconst.h"
#include "asisdata.h"
#include "asiclass.h"
#include "aseconst.h"
#include "aseclass.h"
#endif // _ASE_SUPPORT_

#include "../inc/zarxHeaders.h"


#endif //#ifndef __ARXHEADERS_H__
