

#ifndef _zduiHeaderCtrl_h
#define _zduiHeaderCtrl_h
#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiHeaderCtrl : public CHeaderCtrl {
    DECLARE_DYNAMIC(CZdUiHeaderCtrl)

public:
                CZdUiHeaderCtrl ();
virtual         ~CZdUiHeaderCtrl ();

protected:
        
        CPoint  m_lastMousePoint;
        int     m_tipItem;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (
                    int item, LPCTSTR text, int& width, int& height
                );
        int     GetItemAtPoint (CPoint& p);
        BOOL    GetItemRect (int idx, CRect& rItem);
        BOOL    GetText (int idx, CString& text);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw (int idx);

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

public:

protected:
    
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


