
#ifndef __ACFDUIFIELDDIALOGHOOK_H__
#define __ACFDUIFIELDDIALOGHOOK_H__

#include "AcFdUi.h"
#include "DbField.h"
#include <afxtempl.h>

#include "../inc/zAcFdUiFieldDialogHook.h"

#ifndef ACFDUI_PORT
#define ACFDUI_PORT		ZCFDUI_PORT
#endif //#ifndef ACFDUI_PORT

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbField
#define AcDbField		ZcDbField
#endif //#ifndef AcDbField

#ifndef AcFdUi
#define AcFdUi		ZcFdUi
#endif //#ifndef AcFdUi

#ifndef AcFdUiFieldDialogHookArray
#define AcFdUiFieldDialogHookArray		ZcFdUiFieldDialogHookArray
#endif //#ifndef AcFdUiFieldDialogHookArray

#ifndef AcFdUiSystemInternals
#define AcFdUiSystemInternals		ZcFdUiSystemInternals
#endif //#ifndef AcFdUiSystemInternals

#ifndef AcTcUiSystemInternals
#define AcTcUiSystemInternals		ZcTcUiSystemInternals
#endif //#ifndef AcTcUiSystemInternals

#ifndef CAcFdUiFieldDialog
#define CAcFdUiFieldDialog		CZcFdUiFieldDialog
#endif //#ifndef CAcFdUiFieldDialog

#ifndef CAcFdUiFieldDialogHook
#define CAcFdUiFieldDialogHook		CZcFdUiFieldDialogHook
#endif //#ifndef CAcFdUiFieldDialogHook

#ifndef CAcFdUiFieldOptionDialog
#define CAcFdUiFieldOptionDialog		CZcFdUiFieldOptionDialog
#endif //#ifndef CAcFdUiFieldOptionDialog

#ifndef CAcFdUiImpFieldDialog
#define CAcFdUiImpFieldDialog		CZcFdUiImpFieldDialog
#endif //#ifndef CAcFdUiImpFieldDialog

#endif //#ifndef __ACFDUIFIELDDIALOGHOOK_H__
