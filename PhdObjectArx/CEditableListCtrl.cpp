#include "stdafx.h"
#include "CEditableListCtrl.h"


CEditableListCtrl::CEditableListCtrl()
{
// 	m_OddItemBkColor = 0xFEF1E3;//奇数行背景颜色
// 	m_EvenItemBkColor = 0xFFFFFF;//偶数行背景颜色
// 	m_OddItemTextColor = GetSysColor(COLOR_BTNTEXT);//奇数行文本颜色
// 	m_EvenItemTextColor = GetSysColor(COLOR_BTNTEXT);//偶数行文本颜色
}

CEditableListCtrl::~CEditableListCtrl()
{

}

BOOL CEditableListCtrl::PreTranslateMessage(MSG* pMsg)
{
	BOOL bHandledMsg = FALSE;

	if (pMsg->hwnd == m_editbox.m_hWnd)
	{
		switch (pMsg->message)
		{
		case WM_KEYDOWN:
		{
			switch (pMsg->wParam)
			{
			case VK_RETURN://回车则确认
				if (m_nRow != -1)
				{
					CString ItemText;
					m_editbox.GetWindowText(ItemText);
					this->SetItemText(m_nRow, m_nCol, ItemText);
					::PostMessage(GetParent()->m_hWnd, MSG_ITEMCHANGED, (WPARAM)MAKELONG(m_nRow, m_nCol), (LPARAM)this->m_hWnd);
				}
			case VK_ESCAPE://ESC键取消编辑
				m_editbox.ShowWindow(0);
				m_nCol = m_nRow = -1;
				bHandledMsg = TRUE;
				break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	else if (pMsg->message==WM_MOUSEWHEEL)
	{
		m_editbox.ShowWindow(0);
		m_nCol = m_nRow = -1;
	}
	return (bHandledMsg ? TRUE : CListCtrl::PreTranslateMessage(pMsg));
}

void CEditableListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	LVHITTESTINFO ht;
	ht.pt = point;
	if (SubItemHitTest(&ht)!=-1)
	{
		m_nRow = ht.iItem;
		m_nCol = ht.iSubItem;
		if (m_editbox.m_hWnd==NULL)
		{
			RECT rect;
			rect.left = rect.top = 0;
			rect.bottom = 20;
			rect.right = 100;
			//creat box
			m_editbox.Create(WS_CHILD | ES_LEFT | WS_BORDER | ES_AUTOHSCROLL
				| ES_WANTRETURN | ES_MULTILINE, rect, this, IDC_LIST_EDITBOX);
			m_editbox.SetFont(this->GetFont(), FALSE);
		}
		CRect rect;
		GetSubItemRect(ht.iItem, ht.iSubItem, LVIR_LABEL, rect);
		CString strInfo = this->GetItemText(ht.iItem, ht.iSubItem);
		m_editbox.SetWindowText(strInfo);
		m_editbox.MoveWindow(&rect, TRUE);
		m_editbox.ShowWindow(1);
		//设置焦点及光标
		int nLength = strInfo.GetLength();
		m_editbox.SetSel(nLength, nLength, FALSE);
		m_editbox.SetFocus();
	}
	CListCtrl::OnLButtonDblClk(nFlags, point);
}

BOOL CEditableListCtrl::OnNMSetfocusList(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_editbox.m_hWnd != NULL)
	{
		m_editbox.ShowWindow(0);
		if (m_nRow != -1)
		{
			CString text;
			m_editbox.GetWindowText(text);
			SetItemText(m_nRow, m_nCol, text);
		}
	}
	m_nCol = m_nRow = -1;
	*pResult = 0;

	return FALSE;
}

// void CEditableListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
// {
// 	LPNMLVCUSTOMDRAW pNMCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
// 	*pResult = 0;
// 	int nItemIndex = pNMCD->nmcd.dwItemSpec;
// 	if (pNMCD->nmcd.dwDrawStage == CDDS_PREPAINT){
// 		*pResult = CDRF_NOTIFYITEMDRAW;
// 	}
// 	else{		
// 		if (nItemIndex % 2 == 0){//偶数行 比如 0、2、4、6
// 			pNMCD->clrTextBk = m_EvenItemBkColor;
// 			pNMCD->clrText = m_EvenItemTextColor;
// 		}
// 		else{	//奇数行 比如 1、3、5、7
// 			pNMCD->clrTextBk = m_OddItemBkColor;
// 			pNMCD->clrText = m_OddItemTextColor;
// 		}
// 		*pResult = CDRF_NEWFONT;
// 	}
// }

BEGIN_MESSAGE_MAP(CEditableListCtrl, CListCtrl)
	ON_WM_LBUTTONDBLCLK()
	//ON_NOTIFY_REFLECT(NM_CUSTOMDRAW,&CEditableListCtrl::OnNMCustomdraw)
	ON_NOTIFY_REFLECT_EX(NM_SETFOCUS, &CEditableListCtrl::OnNMSetfocusList)
END_MESSAGE_MAP()