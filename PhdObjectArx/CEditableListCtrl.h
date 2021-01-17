#if !defined(EDITABLELIST)
#define  EDITABLELIST

#pragma once
#include <zacuilistctrl.h>
//#include "resource.h"

#define IDC_LIST_EDITBOX 0xffff
#define MSG_ITEMCHANGED  (WM_USER+222)

//双击编辑单元格
class CEditableListCtrl :public CListCtrl
{
protected:

public:
	CEditableListCtrl();
	virtual~CEditableListCtrl();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	CEdit m_editbox;
	int m_nRow;
	int m_nCol;

// 	COLORREF m_OddItemBkColor;//奇数行背景颜色
// 	COLORREF m_EvenItemBkColor;//偶数行背景颜色
// 	COLORREF m_OddItemTextColor;//奇数行文本颜色
// 	COLORREF m_EvenItemTextColor;//偶数行文本颜色

	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point); 
	//修改焦点事件
	afx_msg BOOL OnNMSetfocusList(NMHDR *pNMHDR, LRESULT *pResult);

// 	//用于颜色风格
// 	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(EDITABLELIST)





