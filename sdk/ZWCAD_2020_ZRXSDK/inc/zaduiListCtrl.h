

#ifndef _zduiListCtrl_h
#define _zduiListCtrl_h

#include "zadesk.h"

#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiListCtrl : public CListCtrl {
    DECLARE_DYNAMIC(CZdUiListCtrl);

public:
                CZdUiListCtrl ();
virtual         ~CZdUiListCtrl ();

protected:
        CPoint  m_lastMousePoint;
        int     m_tipIndex;
        int     m_tipItem;
        CRect   m_tipRect;

public:
        CZdUiHeaderCtrl m_headerCtrl;

        int     ColumnCount ();
virtual void    GetContentExtent (
                    int item, int index, LPCTSTR text, int& width, int& height
                );
        BOOL    GetItemAtPoint (CPoint& p, int& item, int& index);
        BOOL    GetSubItemRect (int item, int index, CRect& rect);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw ();

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
    virtual void PreSubclassWindow();

protected:
    
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


