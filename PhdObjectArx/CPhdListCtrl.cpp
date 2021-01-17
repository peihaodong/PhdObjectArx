#include "StdAfx.h"
#include "CPhdListCtrl.h"

IMPLEMENT_DYNAMIC(CPhdListCtrl, CListCtrl)

CPhdListCtrl::CPhdListCtrl()
	: m_nSelItem(-1)
	, m_nSelSubItem(-1)
	,m_bDceFlag(false)
	, m_bSiFlag(false)
{
}


CPhdListCtrl::~CPhdListCtrl()
{
}

void CPhdListCtrl::SetDblClkEditFlag(bool bDbeFlag)
{
	m_bDceFlag = bDbeFlag;
}

void CPhdListCtrl::SetSingleItemFlag(bool bFlag)
{
	m_bSiFlag = bFlag;
	if (bFlag)//可以选择单个单元格
	{

	}
}

bool CPhdListCtrl::SetItemSelected(int nIndexRow)
{
	int nCount = GetItemCount();
	if (nIndexRow >= nCount)
		return false;

	SetItemState(nIndexRow, LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
	SetFocus();//关键
	return true;
}

bool CPhdListCtrl::SetItemBGColor(int nIndexRow, int nColorIndex)
{
	return SetItemData(nIndexRow, nColorIndex);
}

int CPhdListCtrl::GetSeledRow() const
{
	POSITION pos = GetFirstSelectedItemPosition();
	return GetNextSelectedItem(pos);
}

AcArray<int> CPhdListCtrl::GetSelectedItems() const
{
	AcArray<int> arrSeledIndex;
	POSITION pos = GetFirstSelectedItemPosition();
	if (pos == NULL)
		return arrSeledIndex;
	else
	{
		while (pos)
		{
			int nIndex = GetNextSelectedItem(pos);
			arrSeledIndex.append(nIndex);
		}
	}
	return arrSeledIndex;
}

bool CPhdListCtrl::Rename(int nIndexRow)
{
	if (nIndexRow >= 0 && GetItemCount() > nIndexRow)
	{
		SetFocus();
		CEdit* pLabelEdit = EditLabel(nIndexRow);
		ASSERT(pLabelEdit != NULL);
		return true;
	}
	return false;
}

BEGIN_MESSAGE_MAP(CPhdListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT_EX(NM_CUSTOMDRAW, &CPhdListCtrl::OnNMCustomdraw)
	ON_NOTIFY_REFLECT_EX(LVN_ENDLABELEDIT, &CPhdListCtrl::OnLvnEndlabeledit)
END_MESSAGE_MAP()

BOOL CPhdListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	NMCUSTOMDRAW nmCustomDraw = pLVCD->nmcd;
	switch (nmCustomDraw.dwDrawStage)
	{
	case CDDS_ITEMPREPAINT:
	{
		if (2 == nmCustomDraw.lItemlParam)//红色
		{
			pLVCD->clrTextBk = RGB(51, 153, 255);
			pLVCD->clrText = RGB(255, 255, 255);
		}
		else if (1 == nmCustomDraw.lItemlParam)//蓝色
		{
			pLVCD->clrTextBk = RGB(255, 0, 0);		//背景颜色
			pLVCD->clrText = RGB(255, 255, 255);		//文字颜色
		}
		else if (0 == nmCustomDraw.lItemlParam)//默认颜色
		{
			pLVCD->clrTextBk = RGB(255, 255, 255);
			pLVCD->clrText = RGB(0, 0, 0);
		}
		else
		{
			//
		}
		break;
	}
	default:
		break;
	}

	*pResult = 0;
	*pResult |= CDRF_NOTIFYPOSTPAINT;		//必须有，不然就没有效果
	*pResult |= CDRF_NOTIFYITEMDRAW;		//必须有，不然就没有效果

	return false;
}

BOOL CPhdListCtrl::OnLvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	*pResult = 0;

	int nIndexRow = pDispInfo->item.iItem;//当前编辑的第几行
	CString strText = pDispInfo->item.pszText;// 获取修改后的名称

	if (strText == _T(""))  // 对新输入的名称作一些限制  
		return FALSE;

	// 设置新名称  
	SetItemText(nIndexRow, 0, strText);
	return FALSE;
}
