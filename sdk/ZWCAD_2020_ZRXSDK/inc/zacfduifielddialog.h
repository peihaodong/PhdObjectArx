

#pragma once

#include "zadui.h"
#include "zAcFdUi.h"
#include "zacui.h"

class ZcFdUiSystemInternals;
class CZcFdUiFieldOptionDialog;
class CZcFdUiImpFieldDialog;

#define ZCFDUI_FD_CREATE_FIELD         1
#define ZCFDUI_FD_EDIT_FIELD           2

class ZCFDUI_PORT CZcFdUiFieldDialog : public CZcUiDialog
{
    friend CZcFdUiImpFieldDialog;

    DECLARE_DYNAMIC(CZcFdUiFieldDialog)

public:
    CZcFdUiFieldDialog(CWnd* pParent = NULL);
    virtual ~CZcFdUiFieldDialog();

    INT_PTR         DoModal                 (ZcDbField*& pField,
                                             BOOL bEdit, 
                                             ZcDbDatabase* pDb);
    ZcDbField   *   GetFieldToEdit          (void) const;
    BOOL            SetFieldCodeReadOnly    (BOOL bReadOnly = TRUE);
    CString         GetFieldCode            (void) const;
    BOOL            SetFieldCode            (LPCTSTR pszExpr);
    BOOL            IsFieldCodeDirty        (void);
    CEdit       *   GetFieldCodeEditCtrl    (void);
    BOOL            GetCurrentField         (UINT* pFieldId, 
                                             UINT* pCatId) const;
    BOOL            SelectField             (UINT uFieldId, 
                                             UINT uCatId);
    CZcFdUiFieldOptionDialog* GetOptionDialog(void) const;

public:
    
    void            BeginEditorCommand      (void);
    void            CompleteEditorCommand   (BOOL restoreDialogs = TRUE);
    void            CancelEditorCommand     (void);

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

protected:
    virtual BOOL    OnInitDialog            (void);
    virtual void    OnOK                    (void);
    virtual void    OnCancel                (void);

    afx_msg void    OnCbnSelChangeCategoryList(void);
    afx_msg void    OnLbnSelChangeFieldNameList(void);
    afx_msg void    OnEnChangeFieldCode     (void);
    afx_msg void    OnDialogHelp            (void);
    afx_msg LRESULT OnFormatChanged         (WPARAM wParam,
                                             LPARAM lParam);
    afx_msg LRESULT OnBeginFormatExDialog   (WPARAM wParam,
                                             LPARAM lParam);
    afx_msg LRESULT OnEndFormatExDialog     (WPARAM wParam,
                                             LPARAM lParam);

protected:
    void            *   mpImpObj;

private:
    friend class ZcFdUiSystemInternals;    
};
