

#ifndef _zduiTabChildDialog_h
#define _zduiTabChildDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
class ZDUI_PORT CZdUiTabChildDialog : public CZdUiDialog {
friend class CZdUiTab;

    DECLARE_DYNAMIC(CZdUiTabChildDialog);

public:
                CZdUiTabChildDialog (
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );

private:
        BOOL    m_bDirty;
        HWND    m_hWndFocus;
        CZdUiTab *m_pZcadTab;

        void    SetZcadTabPointer (CZdUiTab *pZcadTab);
        BOOL    TranslateTabKey ();
public:
        CZdUiTab *GetZcadTabPointer ();
        CZdUiTabMainDialog *GetMainDialog ();
        int     GetTabIndex ();
        BOOL    IsDirty ();
virtual void    OnTabActivation (BOOL bActivate);
virtual BOOL    OnTabChanging ();
        void    SetZcadTabChildFocus (HWND hWndFocus);

        void    SetDirty (BOOL bDirty=TRUE);

        void    SetValidationInfo (CDataExchange *pDX);

protected:
virtual void    OnInitDialogBegin ();
virtual void    OnInitDialogFinish ();

public:
    
    enum { IDD = 0 };

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual void OnMainDialogCancel();
    virtual void OnMainDialogOK();
    virtual BOOL OnMainDialogHelp();     
    virtual void OnMainDialogApply();
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    
	virtual void OnCancel();
	virtual void OnOK();

protected:
    
    afx_msg void OnSize(UINT nType, int cx, int cy);
    
    afx_msg LRESULT OnResizePage(WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};
#endif

#pragma pack (pop)
#endif


