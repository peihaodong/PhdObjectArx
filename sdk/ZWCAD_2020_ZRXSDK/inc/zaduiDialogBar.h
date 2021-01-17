

#ifndef _zduiDialogBar_h
#define _zduiDialogBar_h
#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiDialogBar : public CDialogBar {
    DECLARE_DYNAMIC(CZdUiDialogBar);

public:
                CZdUiDialogBar ();
virtual         ~CZdUiDialogBar ();

protected:
virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual ZDUI_REPLY OnNotifyControlChange (UINT controlId, LPARAM lParam);
virtual ZDUI_REPLY OnNotifyControlValid (UINT controlId, BOOL isValid);
virtual ZDUI_REPLY OnNotifyGeneric (UINT controlId, LPARAM lParam);
virtual ZDUI_REPLY OnNotifyUpdateTip (CWnd *control);

protected:
        BOOL    m_bUseTips;
        CZdUiTextTip *m_pTextTip;
        CToolTipCtrl *m_pToolTip;
        CString m_rootKey;

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
        BOOL    GetUseTips ();
        void    SetUseTips (BOOL useTips);

public:
    
    enum { IDD = 0 };

	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
    virtual void DoDataExchange(CDataExchange* pDX);    
	virtual void PostNcDestroy();

protected:
    
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
    afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


