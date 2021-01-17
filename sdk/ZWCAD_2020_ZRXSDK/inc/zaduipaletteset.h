

#ifndef _ZDUI_PALETTE_SET_H_
#define _ZDUI_PALETTE_SET_H_

#include "zadesk.h"
#include <afxtempl.h>

class CZdUiPalette;
class CZdUiImpPaletteSet;

#define PSS_AUTO_ROLLUP                  0x00000002 
#define PSS_PROPERTIES_MENU              0x00000004 
#define PSS_CLOSE_BUTTON                 0x00000008 
#define PSS_EDIT_NAME                    0x00000010 
#define PSS_SNAP                         0x00000020 
#define PSS_SINGLE_PALETTE_TAB           0x00000040 
#define PSS_USE_SINGLE_PALETTE_TAB_NAME  0x00000080 
#define PSS_SINGLE_ROW_HORZ_DOCK         0x00000200 
#define PSS_NOTIFY                       0x00000400 
#define PSS_SINGLE_ROW_NOVERTRESIZE      0x00000800 
#define PSS_SINGLE_COL_VERT_DOCK         0x00001000 
#define PSS_NO_ROLLUP_BUTTON             0x00002000 
#define PSS_NO_ICON                      0x00004000 
#define PSS_NO_TITLEBAR                  0x00008000 

#define ZDUI_HT_CAPTION 	                        1 
#define ZDUI_HT_OPTION_BUTTON                       2 
#define ZDUI_HT_ROLLUP_BUTTON                       3 
#define ZDUI_HT_CLOSE_BUTTON                        4 
#define ZDUI_HT_GRIP                                5 
#define ZDUI_HT_TABS                                6 
#define ZDUI_HT_PALETTE	                            7 
#define ZDUI_HT_TAB_OVERFLOW                        8 
#define ZDUI_HT_PALETTESET                          9 

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)

class ZDUI_PORT CZdUiPaletteSet : public CZdUiDockControlBar
{
    friend class CZdUiImpPaletteSet;
    friend class CZdUiPalette;
    friend class CZdUiPaletteSetDockFrame;
    friend class CZdUiAnchorBar;
    friend class CZdUiDockDragContext;
    DECLARE_DYNCREATE(CZdUiPaletteSet);

public:
    CZdUiPaletteSet(int nStyle = 0);
    virtual ~CZdUiPaletteSet();

    BOOL Create(LPCTSTR strTitle, DWORD dwStyle, const RECT &rect,
                CWnd *pwndParent,
                DWORD dwPaletteSetStyle = PSS_PROPERTIES_MENU | PSS_AUTO_ROLLUP | PSS_CLOSE_BUTTON | PSS_SNAP);

    DWORD GetPaletteSetStyle();
    
    void SetPaletteSetStyle(DWORD dwStyle);

    BOOL AutoRollupStyle();
    BOOL PropertiesMenuStyle();
    BOOL CloseButtonStyle();
    BOOL SinglePaletteTabStyle();
    BOOL UseSinglePaletteTabNameStyle();
    BOOL EditNameStyle();
    BOOL SnapStyle();

    CString GetName();
    
    BOOL SetName(LPCTSTR pszName);

    CZdUiTheme* GetTheme();                   
    
    CZdUiTheme* SetTheme(CZdUiTheme* pTheme);

    int GetOpacity() const;

    BOOL SetOpacity(int nOpacity);

    CZdUiPalette* GetActivePalette();
    int GetActivePaletteTabIndex();
    
    BOOL SetActivePalette (CZdUiPalette* pPalette);
    BOOL SetActivePalette (int nPaletteIndex);

    BOOL SetAutoRollup(BOOL bSet = TRUE);

    BOOL GetAutoRollup();

    void RollOut(bool bDelay = false);

    void RollUp();

    int AddPalette(CZdUiPalette* pPalette);
    
    int InsertPalette(int iIndex, CZdUiPalette* pPalette);
    
    BOOL RemovePalette(CZdUiPalette* pPalette);
    BOOL RemovePalette(int nPaletteIndex);
    
    int GetPaletteCount();
    
    CZdUiPalette * GetPalette(int nIndex);

    int GetTabIndex(CZdUiPalette* pPalette);

    void GetFullRect(CRect & rect);
    BOOL GetNonClientSize(CSize& size);
    virtual BOOL Load(IUnknown* pUnk);
    
    virtual BOOL Save(IUnknown* pUnk);

    BOOL RolledUp();

    typedef enum {
        kLeft = 0,
        kRight
    } ZdUiTitleBarLocation ;

    ZdUiTitleBarLocation TitleBarLocation();

    void SetTitleBarLocation(ZdUiTitleBarLocation loc);

    virtual void TitleBarLocationUpdated(ZdUiTitleBarLocation newLoc) {;}

    void UpdateTabs();

    void EnableDocking(DWORD dwDockStyle);

    virtual BOOL NameEditValidation(CEdit* pEdit);

    CFont   *  GetWindowFont();

protected:
    
    virtual void EditName();
    
    BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);

    virtual BOOL AddContextMenuItems(CMenu * pMenu, int nHitFlag, int nRightClkTab = 0);

    virtual bool CanFrameworkTakeFocus();

    virtual void GetMinimumSize(CSize& size);
    virtual void GetMaximumSize(CSize& size);

    virtual int GetTopReservedHeight();
    virtual int GetBottomReservedHeight();

    virtual void PaletteAdded(CZdUiPalette* pPalette) { return; }

    virtual void PaletteRemoved(CZdUiPalette* pPalette) { return; }

    virtual void PaletteActivated(CZdUiPalette* pActivated,
                                  CZdUiPalette* pDeactivated) { return; }

    virtual void AutoRollupChanged(BOOL bAutoRollupIsOn) { return; }

    virtual void OnTabDrag(CPtrArray & arrayPalettes);

    void GetAdjustedClientRect(CRect & rect);

    virtual void ThemeModified(ZdUiThemeElement element);  

    virtual void OnContextMenu(CWnd* pWnd, CPoint pos);

    public:
    virtual BOOL PreTranslateMessage(MSG * msg);

    static bool SetGlobalTransparency(UINT flag); 
    static UINT GetGlobalTransparency(); 
    bool SetAllowTransparency(CString key, bool bDefault); 
    
    void OnTogglePin(); 

protected:
    
    afx_msg int     OnCreate(LPCREATESTRUCT lpCs);
    afx_msg BOOL    OnEraseBkgnd(CDC *pdc);
    afx_msg void    OnLButtonDown(UINT nFlags, CPoint pt);
    afx_msg void    OnLButtonUp(UINT nFlags, CPoint pt);
    afx_msg void    OnLButtonDblClk(UINT nFlags, CPoint pt);
    afx_msg void    OnMouseMove(UINT nFlags, CPoint pt);
    afx_msg LRESULT OnNcCalcSize(WPARAM wParam, LPARAM lParam);
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
	afx_msg void    OnPaint();
    afx_msg void    OnNcPaint();
    afx_msg void    OnSetFocus(CWnd * pOldWnd);
    afx_msg void    OnSize(UINT nType, int cx, int cy);
    afx_msg void    OnActivate( UINT nState, CWnd* pWndOther, BOOL bMinimized );
    afx_msg void    OnWindowPosChanging (WINDOWPOS* lpwndpos);
	afx_msg void	OnWindowPosChanged (WINDOWPOS* lpwndpos);
    afx_msg LRESULT OnFloatStatus(WPARAM wParam, LPARAM lParam); 
    afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);  
    afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);  
    afx_msg void    OnMenuClose(); 
    afx_msg void    OnMenuMove(); 
    afx_msg void    OnMenuSize(); 
    afx_msg void    OnOptionTranslucency(); 
    afx_msg void    EditPaletteName();
    afx_msg LRESULT OnGetPaletteCount(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnGetPaletteName(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnSetPaletteActive(WPARAM wParam,LPARAM lParam);
    DECLARE_MESSAGE_MAP()

protected:
    CZdUiImpPaletteSet * m_pImpPS;
};

#pragma warning(pop)
#endif
#endif 
