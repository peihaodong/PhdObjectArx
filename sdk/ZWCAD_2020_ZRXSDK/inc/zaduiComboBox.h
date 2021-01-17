

#ifndef _zduiComboBox_h
#define _zduiComboBox_h

#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)

class CZdUiComboBoxDraw;
class ZDUI_PORT CZdUiComboBox : public CComboBox {
    DECLARE_DYNAMIC(CZdUiComboBox)

public:
                CZdUiComboBox ();
virtual         ~CZdUiComboBox ();

public:
        
        void    GetLBString (int nIndex, CString& rString);

protected:
        CPoint  m_lastMousePoint;
        CRect   m_tipRect;
        CString m_sToolTipText;
		CZdUiComboBoxDraw* m_pDraw;
		CZdUiTheme* m_pTheme;

public:
	virtual BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL    OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
	virtual void    DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void    MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw ();
        BOOL    IsStatic ();

		void    SetDraw(CZdUiComboBoxDraw* pDraw);	
		bool    IsThemed() const;
		void    SetIsThemed(bool bValue);
		CZdUiTheme* GetTheme() const;
		void SetTheme(CZdUiTheme* pTheme);

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

        CString  GetToolTipText      (void) const;
        BOOL     SetToolTipText      (const CString& sText);

protected:
        BOOL    m_bAutoDeleteEBox       : 1;    
        BOOL    m_bAutoDeleteLBox       : 1;    
        BOOL    m_bSubclassedControls   : 1;    
        CZdUiEdit *m_pComboEBox;                
        CZdUiListBox *m_pComboLBox;             

public:
        CZdUiEdit *GetEditBox ();
        void    SetEditBox (CZdUiEdit *control, BOOL autoDelete);
        CZdUiListBox *GetListBox ();
        void    SetListBox (CZdUiListBox *control, BOOL autoDelete);

public:
        DWORD   GetStyleMask ();
        BOOL    IsStyleMaskSet (DWORD mask);
        void    SetStyleMask (DWORD mask);

public:

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
    afx_msg LRESULT  OnGetToolTipText  (WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

inline void CZdUiComboBox::SetDraw(CZdUiComboBoxDraw* pDraw)
{ 
	m_pDraw = pDraw;
}

inline CZdUiTheme* CZdUiComboBox::GetTheme() const
{
	return m_pTheme;
}

#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


