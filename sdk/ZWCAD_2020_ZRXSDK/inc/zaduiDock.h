

#ifndef _zduiDock_h
#define _zduiDock_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zadesk.h"
#include <afxpriv.h>                    
#include "zAdAChar.h"

#pragma pack (push, 8)
class CPaletteSetTooltip;
class CZdUiDockFrame;

#define ZDUI_DOCK_POSITION_TOOL_KEY     ZDUI_XML_DOCK_TOOL_INFO
#define ZDUI_DOCK_STARTUP_TOOL_KEY      ZDUI_XML_DOCK_STARTUP_INFO
#define ZDUI_XML_ROOT                   ZCRX_T("ZdUiTools")
#define ZDUI_XML_DOCK_TOOL_INFO         ZCRX_T("ToolsInfo")
#define ZDUI_XML_DOCK_TOOL              ZCRX_T("Tool")
#define ZDUI_XML_DOCK_TOOL_CLSID        ZCRX_T("CLSID")
#define ZDUI_XML_DOCK_STARTUP_INFO      ZCRX_T("StartupInfo")
#define ZDUI_XML_DOCK_STARTUP_TOOL_NAME ZCRX_T("ToolName")
#define ZDUI_XML_DOCK_STARTUP_CMD_NAME  ZCRX_T("Command")

#define ID_ZDUI_ALLOWDOCK           0x1001
#define ID_ZDUI_HIDEBAR             0x1002

#define ZDUI_DOCK_CS_DESTROY_ON_CLOSE  0x01    
#define ZDUI_DOCK_CS_STDMOUSECLICKS    0x02    

#define ZDUI_DOCK_NF_SIZECHANGED       0x01
#define ZDUI_DOCK_NF_STATECHANGED      0x02
#define ZDUI_DOCK_NF_FRAMECHANGED      0x02

#pragma warning(push)

#ifdef _ZSOFT_WINDOWS_
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiDockControlBar : public CControlBar
{
    friend class CZdUiDockFrame;
    friend class CZdUiPaletteSetDockFrame;
    friend class CZdUiDockDragContext;
    friend class CZdUiDockBar;
    friend class CZdUiImpPaletteSet;
    friend class CZdUiDockBarMutator;

private:
	static CObArray * m_paBars;				    
	CSize             m_FloatSize;              
   	CSize			  m_HorzDockSize;			
	CSize			  m_VertDockSize;			
    CPoint			  m_FloatingPosition;		
	bool			  m_bAllowDockingMenuItemState;  
    int               m_Style;                  
    CSize             m_PrevSize;
    BOOL              m_bPrevFloating;
	CZdUiBitmapButton m_closeBtn;//NPD_ZDUI
    CZdUiBitmapButton m_pinBtn;//NPD_ZDUI
    CLSID             m_ID;
    bool              m_bShowCloseButton;       

    static int        m_nLastBarID;
    static bool       m_bToolsRestartMode;

    CRect             m_PersistedDockRect;      
    CRect             m_PersistedFloatRect;

private:
	void        SetDockFlag (DWORD dwStyle);
	void        Resized (int cx, int cy, BOOL bFloating, int flags);
    LRESULT     AddMenuItems (WPARAM wParam, LPARAM lParam);
	static void RemoveBars ();
    void        OnUpdateCmdUI (CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	void        PaintBar (CDC *pDC);
	void        Draw3DRect (CDC *pDC, LPRECT lpRect, CPen *pPenGray);
    LRESULT     WindowProc (UINT nMsg, WPARAM wParam, LPARAM lParam);
    void        LoadDefaultLocation(UINT nOrientation, RECT *pSizeFloating);

public:
    CZdUiDockControlBar (int nStyle = ZDUI_DOCK_CS_STDMOUSECLICKS);

	BOOL Create (CWnd * pParent, LPCTSTR lpszTitle, UINT nID,
                 DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
                 const RECT & rect = CFrameWnd::rectDefault);
	BOOL Create (LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
	     	     DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
                 UINT nID, CCreateContext* pContext = NULL);
    
    void EnableDocking (DWORD dwDockStyle);
    void TileInRow ();
	BOOL IsFloating ();

    void DockControlBar (UINT nOrientation, RECT *pRect);
    void RestoreControlBar (UINT nPreferredOrientation = AFX_IDW_DOCKBAR_LEFT,
                            CRect *pSizeFloating = NULL);

    void InitFloatingPosition (CRect *pSizeFloating);
    void GetFloatingRect (CRect *pFloatingPos);

    void GetPersistedDockingRect(CRect *pDockRect);
    void GetPersistedFloatingRect(CRect *pFloatRect);

    static void SetToolsRestartMode ( bool bMode );
    static bool GetToolsRestartMode (  );

    void SetAllowDockingMenuItemState(bool bState) { m_bAllowDockingMenuItemState = bState; }
    bool AllowDockingMenuItemState() { return m_bAllowDockingMenuItemState; }

    void SetToolID (CLSID* pCLSID);
    CLSID* GetToolID () { return &m_ID; }
    DWORD GetDockStyle () { return m_dwDockStyle; }

    virtual bool CanFrameworkTakeFocus () { return false; }

    virtual BOOL Load(IUnknown* pUnk);
    
    virtual BOOL Save(IUnknown* pUnk);

    virtual CSize CalcFixedLayout (BOOL bStretch, BOOL bHorz);
    bool Anchored();

    bool AdjustVertDockedBarHeight(int nHeight);
#ifdef _DEBUG
    void AssertValid() const;
#endif

	protected:
	virtual BOOL OnCommand (WPARAM wParam, LPARAM lParam);

public:
    virtual ~CZdUiDockControlBar();

protected:
	enum {
		btnWidth = 12,
		btnHeight = 12,
        idCloseBtn = 10001,
        idPinBtn = 10002
	};

protected:

    afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnAllowDock ();
    afx_msg void OnAnchor ();
    afx_msg void OnAnchorLeft();
    afx_msg void OnAnchorRight();
	afx_msg void OnHideBar ();
    afx_msg void OnContextMenu (CWnd* pWnd, CPoint point);
	afx_msg int  OnCreate (LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint ();

protected:
    void GetUsedRect (CRect& rect);
    void ShowCloseButton(bool bShow) { m_bShowCloseButton = bShow;};
    bool CloseButtonVisible(){return m_bShowCloseButton;};

    virtual void PaintControlBar (CDC *pDC);
    virtual BOOL CreateControlBar (LPCREATESTRUCT lpCreateStruct);
    virtual void SizeChanged (CRect *lpRect, BOOL bFloating, int flags) {}
    virtual bool OnClosing ();
    virtual void GetFloatingMinSize (long *pnMinWidth, long *pnMinHeight);
    virtual BOOL AddCustomMenuItems(LPARAM hMenu); 
    virtual void OnUserSizing (UINT nSide, LPRECT pRect) { }
    
    DECLARE_DYNAMIC (CZdUiDockControlBar)
    DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiDockFrame : public CMiniDockFrameWnd   
{
    DECLARE_DYNCREATE (CZdUiDockFrame)

public:
                CZdUiDockFrame ();

public:
        enum ContainedBarType { Unknown, Standard, ZwSoftBar } ;

        enum ContainedBarType GetContainedBarType ();
protected:
        enum ContainedBarType m_nContainedBarType;	
        bool m_bZOrderChanged;

        bool CanFrameworkTakeFocus ();
        void ForceChildRepaint ();

public:
    
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnClose();
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint pt);
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
	afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnWindowPosChanging (WINDOWPOS* lpwndpos);
	afx_msg void OnPaint ();
    afx_msg void OnGetMinMaxInfo (MINMAXINFO FAR* lpMMI);
    afx_msg void OnSizing (UINT nSide, LPRECT pRect);

	bool CanZWCADTakeFocus ();

    DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiPaletteSetDockFrame : public CMiniDockFrameWnd   
{
    friend class CZdUiImpPaletteSet;
    friend class CZdUiDockDragContext;
    friend class CZdUiDockBarMutator;
    friend class CZdUiAnchorBar;

    DECLARE_DYNCREATE (CZdUiPaletteSetDockFrame)

public:
        CZdUiPaletteSetDockFrame ();
        virtual ~CZdUiPaletteSetDockFrame ();

        virtual BOOL Create(CWnd* pParent, DWORD dwBarStyle);

public:
        enum ContainedBarType { Unknown, Standard, ZwSoftBar } ;

        enum ContainedBarType GetContainedBarType ();

        void SetAutoRollup(BOOL bSet);

        virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);

    typedef enum {
        kLeft = 0,
        kRight
    } ZdUiTitleBarLocation ;

    CZdUiPaletteSetDockFrame::ZdUiTitleBarLocation TitleBarLocation();
    void SetTitleBarLocation(CZdUiPaletteSetDockFrame::ZdUiTitleBarLocation);

protected:
        enum ContainedBarType m_nContainedBarType;	
        bool m_bZOrderChanged;

        bool CanFrameworkTakeFocus ();
        void ForceChildRepaint ();

public:
    
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
    virtual BOOL PreTranslateMessage(MSG * msg);

    afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void    OnDestroy();
    afx_msg void    OnSize(UINT nType, int cx, int cy);
    afx_msg void    OnClose();
    afx_msg void    OnLButtonDown(UINT nHitTest, CPoint pt);
	afx_msg void    OnNcLButtonDown(UINT nHitTest, CPoint pt);
    afx_msg void    OnNcRButtonDown(UINT nHitTest, CPoint pt);
    afx_msg void    OnNcRButtonUp(UINT nHitTest, CPoint pt);
    afx_msg void    OnNcLButtonUp(UINT nHitTest, CPoint pt);
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
    afx_msg void    OnMouseMove(UINT nHitTest, CPoint pt);
    afx_msg void    OnNcMouseMove(UINT nHitTest, CPoint pt);
	afx_msg int     OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void    OnWindowPosChanging (WINDOWPOS* lpwndpos);
	afx_msg void    OnPaint ();
    afx_msg void    OnNcPaint ();
    afx_msg LRESULT OnDisplayChange(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnNcCalcSize(WPARAM wParam, LPARAM lParam);
    afx_msg void    OnActivate( UINT nState, CWnd* pWndOther, BOOL bMinimized );
    afx_msg BOOL    OnNcActivate(BOOL bActive);
    afx_msg void    OnGetMinMaxInfo (MINMAXINFO FAR* lpMMI);
    afx_msg void    OnSizing (UINT nSide, LPRECT pRect);
    afx_msg void    OnShowWindow( BOOL bShow, UINT nStatus );
    afx_msg BOOL    OnSetCursor(CWnd *pwnd, UINT nHitTest, UINT msg);
    afx_msg void    OnSetFocus(CWnd * pOldWnd);
    afx_msg void    OnTimer(UINT_PTR nIdEvent);
    afx_msg void    OnContextMenu(CWnd* pWnd, CPoint pos);
    afx_msg BOOL    OnEraseBkgnd(CDC* pDC);
    afx_msg LRESULT OnEnterSizeMove(WPARAM, LPARAM);
    afx_msg LRESULT OnExitSizeMove(WPARAM, LPARAM);
    afx_msg void    OnSettingChange( UINT uFlags, LPCTSTR lpszSection );

    virtual LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
    
    virtual LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
    
    virtual LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
    
    virtual LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
    
    virtual LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
    
    virtual LRESULT  OnDragScroll(WPARAM wParam, LPARAM lParam);

	bool CanZWCADTakeFocus ();

    BOOL HitTest(CPoint pt, UINT& nFlag, DWORD& dwData);

    CZdUiPaletteSet* GetPaletteSet();

    DECLARE_MESSAGE_MAP()

private:

    enum ZdUiSkBtnItems {
        kBtnUnknown     = -1,
        kBtnPushPin     = 0,
        kBtnOptionMenu  = 1,
        kBtnClose       = 2,
        kBtnIcon        = 3,
    };

    enum ZdUiSkIds {
        kRollupTimerId = 0x3011,
        kRolloutTimerId = 0x3012,
        kCursorCheckTimerId = 0x3013
    };

    enum ZdUiSkUiFlags {
        kImgListUnpinnedLeft        = 0,
		kImgListUnpinnedRight       = 1,
        kImgListPinnedLeft          = 2,
		kImgListPinnedRight			= 3, 
        kImgListOptionMenuLeft      = 4,
        kImgListOptionMenuRight     = 5,
        kImgListClose               = 6,
        kImgList_Count              = 7,
    };

    void ncPaint(UINT nPtFlags);
    void windowToNonClient(CRect & rect);
    void nonclientToWindow(CRect & rect);
    void getRegion(CRgn & rgn);
    void getBorderRects(CRect & rectTop, CRect & rectBottom, CRect & rectSide);
    int getMetrics(UINT nItem);
    void getWndCaptionRect(CRect & rect);
    void getWndStatusRect(CRect & rect);
    void getWndSizerRect(CRect & rect);
    void getButtonItemRect(ZdUiSkBtnItems eBtn, CRect & rect);
    void GetNonClientSize(CSize& size);
    int  GetTopGrabbableHeight();
    void SnapToRect(CRect & rect, WINDOWPOS * pWndpos,
                    int nPaletteWidth, int nPaletteHeight,
                    bool bSnapInside, bool bSnapOutside);
    void InitFonts();
    BOOL isImgListItemValid(int nItem);
    
    void OnOptionsMenu();

    void OnSystemMenu(CPoint pos);

    void buttonBlt(CDC *pDC,int nImage, CRect &rcBtn);
    bool btnPress(ZdUiSkBtnItems eBtn, LPPOINT pt);

    void btnPressOptionMenu();
    void btnPressPushPin();
    void btnPressClose();

    void setWindowRgn();

    void    doDrawCaption(CDC *pdc);    
    void    doDrawStatus(CDC *pdc);
    void    doDrawSizer(CDC *pdc);
    void    doDrawButton(CDC *pdc, ZdUiSkBtnItems btnItem, BOOL erase = false);
    void    doDrawBorder();

    void        displayTip(LPPOINT pt);

    void        SetRollupDelay();
    DWORD       GetRollupDelay() {
        return m_bDelayRolledOut ? m_nHoldopenDelay : m_nRollupDelay; }
    void        SetRolloutDelay();
    DWORD       GetRolloutDelay() { return m_nRolloutDelay; }

    void        RollOut(CPoint * pPt, bool bDelay = false);
    void        rollupDlg(BOOL bRollup = TRUE);
    void        SetRolloutTimer();
    void        SetRollupTimer();
    BOOL RolledUp() { return (! m_rectSize.IsRectEmpty()); }
    CRect m_rectSize;                     
    CSize m_sizeShadow;
    CRect m_rectCaptionText;
    CImageList m_imgListGui;
    CImageList m_imgListIcon;
    DWORD m_dwUiTransientFlags;
    bool  m_bRolloutTimerSet;
    bool  m_bRollupTimerSet;
    static DWORD m_nRollupDelay;
    static DWORD m_nRolloutDelay;
    static DWORD m_nHoldopenDelay;
    CPaletteSetTooltip* m_pToolTip;
    BOOL  m_bAllowSnapping;
    CZdUiDropTarget* m_pDropTarget;
    ZdUiTitleBarLocation m_orphanTitleBarLoc;
    bool m_bUserEnteredAutoHideMode;
    CRect m_rectWorkArea;
    bool m_bDelayRolledOut;
};
#endif
#pragma warning(pop)

void ZDUI_PORT ZdUiSaveDockingToolPositions (); 
void ZDUI_PORT ZdUiShowDockControlBars (bool bShow); 
bool ZDUI_PORT ZdUiRegisterDockingTool (                                
    LPCTSTR lpszToolName, LPCTSTR lpszCommand, UINT nToolbarID
);
bool ZDUI_PORT ZdUiRegisterTool (
    LPCTSTR lpszToolName, LPCTSTR lpszCommand, CLSID* pID
);

ZDUI_PORT CRuntimeClass* ZdUiSetFloatingFrameClass(CRuntimeClass* pNewClass);
ZDUI_PORT void ZdUiRegisterFloatingFrameClassAddress(CRuntimeClass** pClass);
ZDUI_PORT void ZdUiRegisterPaletteSetFloatingFrameClass(CRuntimeClass* pClass); 
ZDUI_PORT CRuntimeClass* ZdUiGetRegisteredPaletteSetFloatingFrameClass(void);

typedef HRESULT ZDUI_LOADFN(IUnknown** ppZdUiRootNode);
typedef HRESULT ZDUI_SAVEFN(IUnknown* pZdUiRootNode);

#ifdef _ZSOFT_WINDOWS_
void ZDUI_PORT ZdUiEnableDocking (                                      
	CFrameWnd *pFrame, DWORD dwDockStyle, ZDUI_LOADFN* pLoadFcn, ZDUI_SAVEFN* pSaveFcn);
#endif

bool ZDUI_PORT CanStealFocusFromDockedWindow ();                        
void ZDUI_PORT GetSystemVirtualScreen(RECT &rect);

void ZDUI_PORT ZdUiEnableDockControlBars(BOOL bEnable, CStringArray* pToolIds = NULL);

#pragma pack (pop)
#endif
