
#pragma once

#define GRAPH_TITLETIP_CLASSNAME _T("sCGraphTitleTip")

/////////////////////////////////////////////////////////////////////////////
// CGraphTitleTip window

class CGraphTitleTip : public CWnd
{
// Construction
public:
	CGraphTitleTip();
	virtual ~CGraphTitleTip();
	virtual BOOL Create( CWnd *pParentWnd);

// Attributes
public:

// Operations
public:
	void Show(LPRECT rectTitle,
              LPCTSTR lpszTitleText, 
              int xoffset = 0,
              LPRECT lpHoverRect = NULL, 
              CFont* pFont = NULL,
              COLORREF crTextClr = CLR_DEFAULT,
              COLORREF crBackClr = CLR_DEFAULT);
    void Hide();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	CWnd  *m_pParentWnd;
	CRect  m_rectTitle;
    CRect  m_rectHover;
    DWORD  m_dwLastLButtonDown;
    DWORD  m_dwDblClickMsecs;

protected:
	//{{AFX_MSG(CGraphTitleTip)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

