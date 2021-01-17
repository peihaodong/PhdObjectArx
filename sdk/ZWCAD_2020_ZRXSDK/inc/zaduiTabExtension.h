

#ifndef _zduiTabExtension_h
#define _zduiTabExtension_h
#pragma pack (push, 8)


class ZDUI_PORT CZdUiTabExtensionManager {
public:
                CZdUiTabExtensionManager ();
virtual         ~CZdUiTabExtensionManager ();    

private:
        CString m_dlgName;              
        CZdUiTabMainDialog *m_pDlg;     
        CZdUiTab *m_pTabCtrl;

        BOOL    AddApplicationTabs (LPCTSTR pszAppName);
public:

        int     AddExtendedTabs ();

virtual BOOL    AddTab (
                    HINSTANCE hInstRes,
                    UINT uTemplateID,
                    LPCTSTR pszTabName,         
                    CZdUiTabChildDialog *pDialog
                );

virtual LPCTSTR GetDialogName ();

        void    Initialize (CZdUiTab *pTabCtrl, CZdUiTabMainDialog *pDlg);

        CZdUiTab* GetTabControl() const {return m_pTabCtrl;}
};

#pragma pack (pop)
#endif


