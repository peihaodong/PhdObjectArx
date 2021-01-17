

#ifndef _zduiDialog_h
#define _zduiDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
class ZDUI_PORT CZdUiDialog : public CZdUiBaseDialog {
    DECLARE_DYNAMIC(CZdUiDialog);

public:
                CZdUiDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CZdUiDialog ();

protected:
virtual void    OnInitDialogBegin ();
virtual void    OnInitDialogFinish ();

private:
        LPVOID  m_pElastic;

        CString m_dlgHelpTag;       
        
protected:
        BOOL    m_bEnableElasticMessageMap; 
        UINT    m_templateid;               

public:
        BOOL    AddControl (CWnd *pControl);
        BOOL    AutoLoadControl (CWnd *pControl);
        BOOL    ForceControlRepaint (CWnd *pControl, BOOL bForce);
        BOOL    ForceControlResize (CWnd *pControl, LPRECT prect);
        BOOL    GetColumnSizes (CListCtrl *pList);
        CSize   *GetCurrentDelta ();
        BOOL    GetDialogData (LPCTSTR valueName, CString& data);
        BOOL    GetDialogData (LPCTSTR valueName, DWORD& data);
        BOOL    GetDialogKey (CString& key);
        BOOL    GetDialogName (CString& name);
        void    GetDialogHelpTag (CString& tag);        
        void    GetElasticMinMaxInfo (MINMAXINFO& mmi);
        LPVOID  GetElasticPointer ();
        BOOL    GetPixelData (CRect& r);
        void    LockDialogHeight ();
        void    LockDialogWidth ();
        BOOL    MoveControlX (UINT id, LONG lMovePct);
        BOOL    MoveControlXY (UINT id, LONG lMoveXPct, LONG lMoveYPct);
        BOOL    MoveControlY (UINT id, LONG lMovePct);
        BOOL    ReloadControl (CWnd *pControl, LPCTSTR lpResString);
        BOOL    RemoveControl (CWnd *pControl);
        BOOL    SaveColumnSizes (CListCtrl *pList);
        BOOL    SetControlProperty (PDLGCTLINFO lp, DWORD numElements);
        BOOL    SetDialogData (LPCTSTR valueName, LPCTSTR data);
        BOOL    SetDialogData (LPCTSTR valueName, DWORD data);
        void    SetDialogMaxExtents (int width, int height);
        void    SetDialogMinExtents (int width, int height);
        void    SetDialogName (LPCTSTR name);
        void    SetDialogHelpTag (LPCTSTR tag);        
        void    SetElasticSize (CSize& size, BOOL bRefreshDialog);
        void    SetPersistency (BOOL bFlag);
        void    SetRootKey (LPCTSTR key);
        void    SetTabSize (LPARAM lParam, BOOL bRefreshDialog);
        BOOL    StorePixelData ();
        BOOL    StretchControlX (UINT id, LONG lStretchPct);
        BOOL    StretchControlXY (UINT id, LONG lStretchXPct, LONG lStretchYPct);
        BOOL    StretchControlY (UINT id, LONG lStretchPct);

public:
    
    enum { IDD = 0 };

	protected:
    virtual void DoDataExchange(CDataExchange* pDX);

public:
    virtual void OnDialogHelp();    
    virtual BOOL DoDialogHelp();                        
            
protected:
    
    afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);    
    virtual void OnOK();                                    
    afx_msg void OnSize(UINT nType, int cx, int cy);        
	
    DECLARE_MESSAGE_MAP()
};
#endif

#pragma pack (pop)
#endif


