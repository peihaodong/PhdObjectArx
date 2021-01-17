

#ifndef _zcuiDock_h
#define _zcuiDock_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

class ZCUI_PORT CZcUiDockFrame : public CZdUiDockFrame {
    DECLARE_DYNCREATE(CZcUiDockFrame);

public:
	            CZcUiDockFrame ();
virtual         ~CZcUiDockFrame ();

public:

protected:
    
    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam);

    DECLARE_MESSAGE_MAP()
};

class ZCUI_PORT CZcUiDockControlBar : public CZdUiDockControlBar {
    DECLARE_DYNCREATE(CZcUiDockControlBar);

public:
    CZcUiDockControlBar () {}

protected:
    virtual bool CanFrameworkTakeFocus ();
};

class ZCUI_PORT CZcUiPaletteSetDockFrame : public CZdUiPaletteSetDockFrame {
    DECLARE_DYNCREATE(CZcUiPaletteSetDockFrame);

public:
	            CZcUiPaletteSetDockFrame ();
virtual         ~CZcUiPaletteSetDockFrame ();

public:

protected:
    
    afx_msg LRESULT OnZCADKeepFocus (WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif


