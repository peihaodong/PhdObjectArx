

#ifndef _zduiButton_h
#define _zduiButton_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "zAdUiTheme.h"  

#ifdef _ZSOFT_WINDOWS_
class CZdUiOwnerDrawButton;
class CZdUiTrackButtonDraw;

class CZdUiODButtonThemeModReactor : public CZdUiThemeModifiedReactor  
{
public:
    CZdUiODButtonThemeModReactor(CZdUiOwnerDrawButton* pBtn);  
    virtual void ThemeModified(const CZdUiTheme * pTheme, ZdUiThemeElement element);  

private:
    CZdUiOwnerDrawButton * m_pBtn;
};

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiOwnerDrawButton : public CButton {
    friend class CZdUiODButtonThemeModReactor;  

	DECLARE_DYNAMIC(CZdUiOwnerDrawButton)

public:
                CZdUiOwnerDrawButton ();
virtual         ~CZdUiOwnerDrawButton ();

protected:
        CPoint  m_lastMousePoint;
        CRect   m_tipRect;
        CZdUiTheme * m_pTheme;  

protected:
        CWnd    *m_zduiParent;

virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual void    OnDrawTip (CDC& dc);
virtual BOOL    OnDrawTipText (CZdUiDrawTipText& dtt);
virtual ZDUI_REPLY OnGetTipSupport (CPoint& p);
virtual BOOL    OnGetTipRect (CRect& r);
virtual BOOL    OnGetTipText (CString& text);
virtual BOOL    OnHitTipRect (CPoint& p);
public:
        CWnd    *GetZdUiParent ();
        void    SetZdUiParent (CWnd *w);

virtual void    SetTracking(BOOL b) { m_bIsTrackButton = b; };
virtual CZdUiTheme * SetTheme(CZdUiTheme *pTheme);  

protected:
static const UINT_PTR m_timerEvent;
        BOOL    m_bEnableDragDrop   : 1;
        BOOL    m_bEnableFastDraw   : 1;
        BOOL    m_bEnablePointedAt  : 1;
        BOOL    m_bIsPointedAt      : 1;
        BOOL    m_bIsStatic         : 1;
        BOOL    m_bIsToolButton     : 1;
        BOOL    m_bIsTrackButton    : 1;
        UINT_PTR  m_timerId;

        int     m_nPartId;
        int     m_nStateId;
        UINT    m_uEdge;
        BOOL    m_bMouseHover;

virtual void    DrawBorder(CDC *pDC,CRect &r,COLORREF cr);
virtual void    DrawHotBorder();
virtual void    DrawButton(
                    CDC& dc, int w, int h,
	                BOOL isDefault,
	                BOOL isDisabled,
                    BOOL isSelected,
	                BOOL isFocused
                );
virtual void    DrawPushButtonBorder (
                    CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected
                );
virtual void    DrawToolButtonBorder (
                    CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused
                );
        void    DrawTransparentBitmap (
                    CDC& dc,
                    CBitmap& bmp,
                    int x, int y, int w, int h,
                    BOOL isDisabled
                );
        BOOL    GetIsPointedAt ();
        void    SetIsPointedAt (BOOL isPointedAt);
virtual BOOL    OnAutoLoad ();
virtual void    OnDragDrop (HDROP hDropInfo);
virtual void    OnPointedAt (BOOL isPointedAt);
virtual BOOL    OnReload (LPCTSTR strResId);
        void    StartTimer (DWORD ms=50);
        void    StopTimer ();

virtual void ThemeModified(ZdUiThemeElement element);  
public:
        BOOL    AutoLoad ();
        BOOL    GetEnableDragDrop ();
        void    SetEnableDragDrop (BOOL allow);
        BOOL    GetEnableFastDraw ();
        void    SetEnableFastDraw (BOOL allow);
        BOOL    GetEnablePointedAt ();
        void    SetEnablePointedAt (BOOL allow);
        BOOL    GetIsStatic ();
        void    SetIsStatic (BOOL isStatic);
        BOOL    GetIsToolButton ();
        void    SetIsToolButton (BOOL isToolButton);
        BOOL    Reload (LPCTSTR strResId);

public:
	
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void PreSubclassWindow();

protected:
	
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg UINT OnGetDlgCode();
    afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	afx_msg void OnNcDestroy();
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnDestroy( );
    afx_msg LRESULT OnThemeChanged(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

private:
    CZdUiODButtonThemeModReactor* m_pThemeModReactor;  
    HANDLE                        m_hVS;               
};

#pragma warning(pop)

class ZDUI_PORT CZdUiBitmapButton : public CZdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CZdUiBitmapButton)

public:
                CZdUiBitmapButton ();
virtual         ~CZdUiBitmapButton ();
	enum Constants
    {
        ThemedSize = 24,
    };
	BOOL    GetAutoSizeToBitmap ();
	void    SetAutoSizeToBitmap (BOOL autoSizeToBitmap);
	void    SizeToBitmap ();
	void    SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);
    virtual BOOL IsThemed() const;
    virtual void SetIsThemed(BOOL isThemed);
    virtual void EnableThemedState(BOOL bEnableHover, BOOL bEnableClick);
    virtual CZdUiTheme * SetTheme(CZdUiTheme *pTheme);
    virtual void SetThemeBackground(ZdUiThemeElement nElement);
    BOOL CenterImage() const;
    void SetCenterImage(BOOL center);
    BOOL LoadBitmap (LPCTSTR strResId);
protected:
virtual void    DrawButton(
                    CDC& dc, int w, int h,
	                BOOL isDefault,
	                BOOL isDisabled,
                    BOOL isSelected,
	                BOOL isFocused
                );
virtual void DrawButtonImage(CDC* pDC, const CRect& rect, BOOL isSelected, BOOL isDisabled);
virtual void DrawFocusMark(CDC* pDC, CRect& rect, BOOL isDefault, BOOL isSelected, BOOL isFocused);
virtual BOOL    OnAutoLoad ();
virtual BOOL    OnReload (LPCTSTR strResId);
	virtual void DrawThemedButton(CDC& dc, int x, int y, int width, int height, int statusId);
    virtual void ThemeModified(ZdUiThemeElement element);
    enum ImageType
    {
        kImageType_Undefined,
        kImageType_Bitmap,
        kImageType_Icon,
        kImageType_RCDATA
    };
    BOOL LoadIconResource(LPCTSTR strResId, HINSTANCE hInst = NULL);
    BOOL LoadRCDATAResource(LPCTSTR strResId, HINSTANCE hInst = NULL);
    BOOL LoadBitmapResource (LPCTSTR strResId, CBitmap& bmp, HINSTANCE hInst = NULL);
    virtual BOOL OnLoadBitmap (LPCTSTR strResId);
    void ClearImages(bool bClearResId = false);
    void CalcBitmapSize();
    void SaveAndCalcSize(LPCTSTR strResId, ImageType type);
protected:
        BOOL    m_bAutoSizeToBitmap;
	    CBitmap m_bmp;
		void *  m_image;
        CString m_bmpResId;
	    int     m_bmpHeight;
	    int     m_bmpWidth;
        int     m_bmpX;
        int     m_bmpY;
        int     m_focusRectOffset;
		BOOL    m_isThemed;
		BOOL    m_enableThemedHoverState;
		BOOL    m_enableThemedClickState;
		BOOL    m_centerImage;
		ZdUiThemeElement m_backgroundElement; 
		ImageType m_imageType;

protected:

	DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiBitmapStatic : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZdUiBitmapStatic)

public:
	            CZdUiBitmapStatic ();
virtual         ~CZdUiBitmapStatic ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiDropSite : public CZdUiBitmapStatic {
	DECLARE_DYNAMIC(CZdUiDropSite)

public:
	            CZdUiDropSite ();
virtual         ~CZdUiDropSite ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiToolButton : public CZdUiBitmapButton {
	DECLARE_DYNAMIC(CZdUiToolButton)

public:
	            CZdUiToolButton ();
virtual         ~CZdUiToolButton ();

public:

protected:

	DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiTrackButton : public CZdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CZdUiTrackButton)

public:
	            CZdUiTrackButton();
                CZdUiTrackButton(const CZdUiTrackButtonDraw & pDraw);
virtual         ~CZdUiTrackButton();

public:
	
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

virtual CZdUiTheme * GetTheme() const;
virtual CZdUiTheme * SetTheme(CZdUiTheme *pTheme);  

static  CZdUiTrackButtonDraw * SetDefaultDraw(CZdUiTrackButtonDraw * pDraw);
        CZdUiTrackButtonDraw * SetDraw(CZdUiTrackButtonDraw * pDraw);

virtual void    SetTracking(BOOL b);

protected:
virtual void    DrawButton(
                    CDC& dc, int w, int h,
	                BOOL isDefault,
	                BOOL isDisabled,
                    BOOL isSelected,
	                BOOL isFocused
                );
virtual void    DrawBorder(CDC *pDC,CRect &r,COLORREF cr);
virtual void    DrawHotBorder();
virtual void    DrawPushButtonBorder (CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected);
virtual void    DrawToolButtonBorder (CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused);

virtual ZDUI_REPLY OnGetTipSupport (CPoint& p);

    afx_msg void OnNcPaint();
    afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

    virtual void releaseDraw();

private:
    static CZdUiTrackButtonDraw * s_pDefaultDraw;
    CZdUiTrackButtonDraw * m_pDraw;

};
#endif

#pragma pack (pop)
#endif


