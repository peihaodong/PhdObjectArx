

#ifndef _zduiListBox_h
#define _zduiListBox_h
#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiListBox : public CListBox {
    DECLARE_DYNAMIC(CZdUiListBox);

public:
                CZdUiListBox ();
virtual         ~CZdUiListBox ();

protected:
        CPoint  m_lastMousePoint;
        int     m_tipItem;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (
                    int item, LPCTSTR text, int& width, int& height
                );
        int     GetItemAtPoint (CPoint& p);
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

protected:
        BOOL    m_bComboBoxDraw;
        CZdUiComboBox *m_pComboBox;

public:
        CZdUiComboBox *GetComboBox ();
        void    SetComboBox (CZdUiComboBox *control);
        BOOL    GetComboBoxDraw ();
        void    SetComboBoxDraw (BOOL comboBoxDraw);

public:
    
    virtual int  CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
    virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

protected:
    
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnDestroy();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


