

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zAcFdUi.h"
#include "zDbField.h"
#include <afxtempl.h>

class ZcTcUiSystemInternals;
class CZcFdUiFieldDialog;
class CZcFdUiFieldOptionDialog;
class CZcFdUiImpFieldDialog;
class CZcFdUiFieldDialogHook;

typedef CTypedPtrArray<CPtrArray, CZcFdUiFieldDialogHook*>  ZcFdUiFieldDialogHookArray;

class ZCFDUI_PORT CZcFdUiFieldDialogHook : public CObject
{
public:
    CZcFdUiFieldDialogHook(void);
    ~CZcFdUiFieldDialogHook(void);
    virtual BOOL    CreateInstance          (CZcFdUiFieldDialogHook*& pHook);

    virtual int     GetEvaluatorIds         (CStringArray& evalIds);
    virtual BOOL    BeginFieldDialog        (CZcFdUiFieldDialog* pFieldDlg, 
                                             ZcDbDatabase* pDb, 
                                             int nContext);
    virtual BOOL    EndFieldDialog          (int nRet);
    virtual BOOL    SetFieldToEdit          (ZcDbField* pField);
    ZcDbDatabase *  GetDatabase             (void) const;
    virtual BOOL    GetCategoryNames        (UINT uMinUnusedCatId,
                                             CStringArray& catNames,
                                             CUIntArray& catIds);
    virtual BOOL    GetFieldNames           (UINT uCatId, 
                                             UINT uMinUnusedFieldId,
                                             CStringArray& fieldNames, 
                                             CUIntArray& fieldIds,
                                             BOOL& bSort);
    virtual BOOL    GetOptionDialog         (UINT uFieldId, 
                                             CZcFdUiFieldOptionDialog*& pOptionDlg);
    virtual CString GetPreview              (LPCTSTR pszFormatType, 
                                             LPCTSTR pszFormat);
    virtual BOOL    UpdateFieldCode         (void);
    virtual BOOL    OnFieldSelected         (UINT uFieldId);
    virtual BOOL    CreateField             (UINT uFieldId, 
                                             ZcDbField*& pField);

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;
};

