#include "StdAfx.h"
#include "CCellSelectableListCtrl.h"


CCellSelectableListCtrl::CCellSelectableListCtrl(void)
	: m_nSelItem(-1)
	, m_nSelSubItem(-1)
{
}

CCellSelectableListCtrl::~CCellSelectableListCtrl(void)
{
}
BEGIN_MESSAGE_MAP(CCellSelectableListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CCellSelectableListCtrl::OnNMCustomdraw)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CCellSelectableListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);

	*pResult = CDRF_DODEFAULT;

	if (CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage)
	{
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if ((CDDS_ITEMPREPAINT | CDDS_SUBITEM) == pLVCD->nmcd.dwDrawStage)
	{
		int nItem = static_cast<int>(pLVCD->nmcd.dwItemSpec);
		int nSubItem = pLVCD->iSubItem;

		if (nItem == m_nSelItem &&
			nSubItem == m_nSelSubItem)
		{
			pLVCD->clrText = RGB(0xFF, 0xFF, 0xFF);
			pLVCD->clrTextBk = RGB(0x00, 0x00, 0x99);
		}
		else
		{
			pLVCD->clrText = RGB(0x00, 0x00, 0x00);
			pLVCD->clrTextBk = RGB(0xFF, 0xFF, 0xFF);
		}
		*pResult = CDRF_DODEFAULT;
	}
}

void CCellSelectableListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	LVHITTESTINFO stInfo = { 0 };
	stInfo.pt.x = point.x;
	stInfo.pt.y = point.y;
	if (HitTest(&stInfo) >= 0 ||
		SubItemHitTest(&stInfo) >= 0)
	{
		m_nSelItem = stInfo.iItem;
		m_nSelSubItem = stInfo.iSubItem;
	}
	else
	{
		m_nSelItem = m_nSelSubItem = -1;
	}
	Invalidate();
}

void CCellSelectableListCtrl::PreSubclassWindow()
{
	// 必须是Report模式
	ASSERT(this->GetStyle() & LVS_REPORT);

	DWORD dwExStyle = this->GetExtendedStyle();
	dwExStyle |= LVS_EX_GRIDLINES;
	dwExStyle &= ~LVS_EX_FULLROWSELECT;
	this->SetExtendedStyle(dwExStyle);

	CListCtrl::PreSubclassWindow();
}


void CCellSelectableListCtrl::SelectSubItem(int nItem, int nSubItem)
{
	m_nSelItem = nItem;
	m_nSelSubItem = nSubItem;
	Invalidate();
}