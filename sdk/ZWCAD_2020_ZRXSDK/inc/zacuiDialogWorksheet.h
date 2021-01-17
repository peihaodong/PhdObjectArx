

#ifndef ZCUIDLGWORKSHEET_H
#define ZCUIDLGWORKSHEET_H

#include "zaduiDIalogWorksheet.h"

class ZCUI_PORT CZcUiDialogWorksheet : public CZdUiDialogWorksheet
{
    DECLARE_DYNAMIC(CZcUiDialogWorksheet);

public:
	CZcUiDialogWorksheet(UINT ID, CWnd* pParent = NULL, HINSTANCE hResInst=NULL);   
    ~CZcUiDialogWorksheet();

	enum { IDD = 0 };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
    afx_msg void OnNcPaint();
    afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg void OnNcLButtonDown( UINT nHitTest, CPoint point );
    afx_msg void OnNcLButtonUp( UINT nHitTest, CPoint point );
    afx_msg void OnNcMouseMove(UINT nHitTest,CPoint point);
    afx_msg void OnMouseMove(UINT nHitTest,CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
    afx_msg void OnSysColorChange();
	
	DECLARE_MESSAGE_MAP()
};

#endif 
