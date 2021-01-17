

#ifndef _zcuiDialog_h
#define _zcuiDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

class ZCUI_PORT CZcUiDialog : public CZdUiDialog {
    DECLARE_DYNAMIC(CZcUiDialog);

public:
                CZcUiDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiDialog ();

protected:
virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath);

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual int IsMultiDocumentActivationEnabled();
virtual int EnableMultiDocumentActivation(BOOL bEnable);

virtual void    OnDialogHelp();     
	virtual BOOL    OnInitDialog();
public:
    
    enum { IDD = 0 };

	protected:
    virtual void OnOK();
	virtual void OnCancel();
    virtual void DoDataExchange(CDataExchange* pDX);

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiDialogBar : public CZdUiDialogBar {
    DECLARE_DYNAMIC(CZcUiDialogBar);

public:
                CZcUiDialogBar ();
virtual         ~CZcUiDialogBar ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();

public:
    
    enum { IDD = 0 };

	protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiFileDialog : public CZdUiFileDialog {
    DECLARE_DYNAMIC(CZcUiFileDialog);

public:
                CZcUiFileDialog (
                    BOOL bOpenFileDialog,
                    LPCTSTR lpszDefExt=NULL,
                    LPCTSTR lpszFileName=NULL,
                    DWORD dwFlags=OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                    LPCTSTR lpszFilter=NULL,
                    CWnd *pParentWnd=NULL
                );
virtual         ~CZcUiFileDialog ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);

public:
    
    enum { IDD = 0 };

	protected:
    virtual void OnOK();
	virtual void OnCancel();
    virtual void DoDataExchange(CDataExchange* pDX);

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiTabChildDialog : public CZdUiTabChildDialog {
    DECLARE_DYNAMIC(CZcUiTabChildDialog);

public:
                CZcUiTabChildDialog (
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabChildDialog ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual BOOL OnMainDialogHelp();
virtual void    OnDialogHelp();

public:
    
    enum { IDD = 0 };

	protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiTabMainDialog : public CZdUiTabMainDialog {
    DECLARE_DYNAMIC(CZcUiTabMainDialog);

public:
  	            CZcUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZcUiTabMainDialog ();

public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
virtual void    EnableFloatingWindows (BOOL allow);
virtual void    OnDialogHelp();
virtual int IsMultiDocumentActivationEnabled();
virtual int EnableMultiDocumentActivation(BOOL bEnable);

public:
virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);

public:
	
	enum { IDD = 0 };

	protected:
    virtual void OnOK();
	virtual void OnCancel();
	virtual void DoDataExchange(CDataExchange* pDX);

protected:

    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif


