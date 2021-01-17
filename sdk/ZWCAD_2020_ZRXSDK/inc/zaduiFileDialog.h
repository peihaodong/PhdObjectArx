

#ifndef _zduiFileDialog_h
#define _zduiFileDialog_h
#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifndef kDialogOptionNone
#define kDialogOptionNone       0
#endif

#ifndef kDialogOptionUseTips
#define kDialogOptionUseTips    1
#endif

#ifndef kDialogOptionUseTipsForContextHelp
#define kDialogOptionUseTipsForContextHelp       2
#endif

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)

class ZDUI_PORT CZdUiFileDialog : public CFileDialog {
    DECLARE_DYNAMIC(CZdUiFileDialog);

public:
                CZdUiFileDialog (
                    BOOL bOpenFileDialog,
                    LPCTSTR lpszDefExt=NULL,
                    LPCTSTR lpszFileName=NULL,
                    DWORD dwFlags=OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    LPCTSTR lpszFilter=NULL,
                    CWnd *pParentWnd=NULL,
                    HINSTANCE hDialogResource=NULL                     
                );
virtual         ~CZdUiFileDialog ();

protected:
virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual ZDUI_REPLY OnNotifyControlChange (UINT controlId, LPARAM lParam);
virtual ZDUI_REPLY OnNotifyControlValid (UINT controlId, BOOL isValid);
virtual ZDUI_REPLY OnNotifyGeneric (UINT controlId, LPARAM lParam);
virtual ZDUI_REPLY OnNotifyUpdateTip (CWnd *control);

private:
        HINSTANCE m_commandResourceInstance;
        BOOL    m_commandWindowWasEnabled;
        HWND    m_commandWindowWithFocus;
        
protected:
        ZDUI_COMMAND_STATE m_commandState;

        void    BeginEditorCommand ();
        void    CancelEditorCommand ();
        void    CompleteEditorCommand (BOOL restoreDialogs=TRUE);
        void    MakeDialogsVisible (BOOL visible);
public:
        BOOL    EditorCommandCancelled ();

protected:
        CString m_contextHelpFileName;
        CString m_contextHelpFullPathName;
        CString m_contextHelpPrefix;    

virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath);
public:
        LPCTSTR GetContextHelpFileName ();    
        void    SetContextHelpFileName (LPCTSTR pFileName);
        LPCTSTR GetContextHelpFullPathName ();    
        void    SetContextHelpFullPathName (LPCTSTR pFullPathName);
        LPCTSTR GetContextHelpPrefix ();    
        void    SetContextHelpPrefix (LPCTSTR pPrefix);
        void    SetDialogName (LPCTSTR name);
        void    SetDialogHelpTag (LPCTSTR tag) {m_dlgHelpTag = tag;}
        void    GetDialogName (CString& name) {name = m_dlgName;}
        void    GetDialogHelpTag (CString& tag) {tag = m_dlgHelpTag;}

private:
        HINSTANCE m_hDialogResourceSaved;
        CString m_dlgHelpTag;       
        CString m_dlgName;          

protected:
        int    m_bUseTips;
        HINSTANCE m_hDialogResource;
        HICON   m_hIcon;
        CZdUiTextTip *m_pTextTip;
        CToolTipCtrl *m_pToolTip;
        CString m_rootKey;
        CWnd* m_pParent;

virtual void    OnInitDialogBegin ();
virtual void    OnInitDialogFinish ();
public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
        int    GetUseTips ();
        void    SetUseTips (int useTips);
        HICON   GetDialogIcon();
        void    SetDialogIcon(HICON hIcon);        
virtual void OnDialogHelp();    
virtual BOOL DoDialogHelp();

public:
    
    enum { IDD = 0 };

	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual INT_PTR DoModal();
	protected:
    virtual void DoDataExchange(CDataExchange* pDX);    
	virtual void PostNcDestroy();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
    
    virtual BOOL OnInitDialog();
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);    
	
    afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


