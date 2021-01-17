

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif 

#ifdef  ZCFD_API
#  define   ZCFDUI_PORT  __declspec(dllexport)
#else
#  define   ZCFDUI_PORT  
#endif

class CZcFdUiFieldManager;
class ZcDbField;
class ZcDbDatabase;
#define ZCFDUI_CATEGORY_ID_ALL              -1
#define ZCFDUI_CATID_USER_FIRST             1000
#define ZCFDUI_FIELDID_USER_FIRST           50000
ZCFDUI_PORT CZcFdUiFieldManager* ZcFdUiGetFieldManager(void);
ZCFDUI_PORT int ZcFdUiInvokeFieldDialog(ZcDbField*& pNewField, 
                                        BOOL bEdit,
                                        ZcDbDatabase* pDb,
                                        CWnd* pParent = NULL);
