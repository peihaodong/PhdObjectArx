// E:\Work\hyaed\Src\Vc\AG\AGControlPackage\Source\CommonFile\GraphCtrl\GraphButton.cpp : 实现文件
//

#include "stdafx.h"
#include "GraphButton.h"
#include "resource.h"

// CGraphButton
#define IDC_GRAPH_LIST 0x8001
#define IDC_GRAPH_SHOW 0x8002

IMPLEMENT_DYNAMIC(CGraphButton, CXTButton)

int CGraphButton::m_nTimes = 0;
WNDPROC CGraphButton::m_parentWndProc = NULL;
CGraphButton* CGraphButton::m_pActiveBtn = NULL;
CGraphButton::CGraphButton()
: CXTResize(this)
, m_nBtnWid(16)
, m_nIconSize(10)
, m_nGrip(3)
{
	SetItemSize(0, 0);
	m_nColCount = 1;
	m_nRowCount = 5;

#ifdef _USE_XTP
	SetXButtonStyle(BS_XT_SEMIFLAT | BS_XT_WINXP_COMPAT);
#endif

}

CGraphButton::~CGraphButton()
{
	Clear();
}


BEGIN_MESSAGE_MAP(CGraphButton, CXTButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CGraphButton 消息处理程序



void CGraphButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 

	CXTButton::OnLButtonDown(nFlags, point);

	ShowList();
}

void CGraphButton::SetItemSize( int nWidth, int nHeight )
{
	m_sizeItem.cx = nWidth;
	m_sizeItem.cy = nHeight;
}

void CGraphButton::SetItemSize( CSize size )
{
	m_sizeItem = size;
}

void CGraphButton::SetLayer( int nCols, int nRows )
{
	m_nColCount = nCols;
	m_nRowCount = nRows;
}

void CGraphButton::SetCurDatabase( AcDbDatabase* pDb )
{
	m_listCtrl.SetCurDatabase(pDb);
}

Acad::ErrorStatus CGraphButton::InsertListItem( IN int nItem, IN CString strBlockName, IN CString strTitleName/*=_T("") */, DWORD dwData )
{
	return m_listCtrl.InsertItem(nItem, strBlockName, strTitleName, dwData);
}

Acad::ErrorStatus CGraphButton::InsertListItem( IN int nItem, IN AcDbObject* pEnt, IN LPCTSTR lpszTitleName /*= _T("")*/, DWORD dwData )
{
	return m_listCtrl.InsertItem(nItem, pEnt, lpszTitleName, dwData);
}

void CGraphButton::OnListClick( int nSel, int nNewSel, bool bMsg )
{
// 	if (nNewSel >= 0 && nNewSel != nSel)
// 	{
		m_listCtrl.SetCurSel(nNewSel);

		// 如果与显示控件关联，则不发送消息
		CGraphBlockViewWnd* pWnd = NULL;
		if (-1 < nNewSel)
			pWnd = m_listCtrl.GetItem(nNewSel);

		if (NULL != pWnd)
			pWnd->CopyObjectsTo(&m_showCtrl);
		
		if (GetOwner() && bMsg)
		{
			GetOwner()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), CBN_SELCHANGE), (LPARAM)GetSafeHwnd());
		}

		HideList();
}

void CGraphButton::PreSubclassWindow()
{
	// TODO: 
	CXTButton::PreSubclassWindow();

#ifdef _USE_XTP
	SetFlag(xtResizeNoSizeIcon);
	CXTResize::Init();
#endif

	CRect rc;
	GetClientRect(rc);

	CSize sz = m_sizeItem;
	if (sz.cx == 0 || sz.cy == 0)
	{
		sz = rc.Size();
		sz.cx -= m_nBtnWid;
	}

	if (!m_listCtrl.Create(CRect(CPoint(0, 0), sz), this, 0, WS_POPUP | WS_BORDER))
	{
		return;
	}

	m_listCtrl.ShowItemCaption();

	rc.DeflateRect(m_nGrip, m_nGrip, m_nGrip + m_nBtnWid, m_nGrip);
	if (!m_showCtrl.Create(NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, rc, this, IDC_GRAPH_SHOW))
	{
		return;
	}

	m_showCtrl.EnablePan(false);
	m_showCtrl.EnableOrbin(false);
	m_showCtrl.EnableZoom(false);
	m_showCtrl.EnableWindow(FALSE);

#ifdef _USE_XTP

	SetResize(-1, m_listCtrl.GetSafeHwnd(), SZ_BOTTOM_LEFT, SZ_BOTTOM_RIGHT);
	SetResize(IDC_GRAPH_SHOW, SZ_TOP_LEFT, SZ_BOTTOM_RIGHT);
#endif

	InterceptParentWndProc();

	CAcModuleResourceOverride rs;

	HICON hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICONDROPDOWN));
	m_icon = hIcon;
}

CString CGraphButton::GetListItemTitle( int nItem )
{
	CGraphBlockViewWnd* pItem = m_listCtrl.GetItem(nItem);
	if (NULL == pItem)
	{
		return _T("");
	}

	return pItem->GetName();
}

CString CGraphButton::GetListItemBlockName( int nItem )
{
	CGraphBlockViewWnd* pItem = m_listCtrl.GetItem(nItem);
	if (NULL == pItem)
	{
		return _T("");
	}

	return pItem->m_strBlockName;
}

int CGraphButton::GetListCurSel()
{
	return m_listCtrl.GetCurSel();
}

void CGraphButton::OnSize(UINT nType, int cx, int cy)
{
	CXTButton::OnSize(nType, cx, cy);
#ifdef _USE_XTP

	CXTResize::Size();
#endif
}

void CGraphButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
   UINT uStyle = DFCS_BUTTONPUSH;

   // This code only works with buttons.
   ASSERT(NULL != lpDrawItemStruct);
   ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

   CXTButton::DrawItem(lpDrawItemStruct);

   CBitmap bit;
   bit.LoadBitmap(IDI_ICONDROPDOWN);

   CRect rc;
   GetClientRect(rc);
   rc.left = rc.right - m_nBtnWid;
   rc.top += (rc.Height() - m_nBtnWid) / 2;
   CPoint pt(rc.TopLeft());

   CDC dc;
   dc.Attach(lpDrawItemStruct->hDC);

   m_icon.Draw(&dc, pt, CSize(m_nIconSize, m_nIconSize));
   dc.Detach();

   m_showCtrl.Invalidate();
}

void CGraphButton::SetCurSel( int nItem )
{
	OnListClick(-1, nItem, false);
}

CGraphBlockViewWnd* CGraphButton::GetItem( int nItem )
{
	return m_listCtrl.GetItem(nItem);
}

DWORD CGraphButton::GetItemData( int nItem )
{
	CGraphBlockViewWnd* pItem = GetItem(nItem);
	if (NULL != pItem)
	{
		return pItem->GetData();
	}

	return 0;
}

void CGraphButton::InterceptParentWndProc()
{
	CWnd *pwndParent = GetParent();
	if (!pwndParent) return;
	if (!pwndParent->GetSafeHwnd()) return;

	// GET Parent WinProc & SET our function
	m_nTimes++;
	if (m_parentWndProc)
		return;
	m_parentWndProc = (WNDPROC)::SetWindowLongPtr(
		pwndParent->GetSafeHwnd(), 
		GWLP_WNDPROC,
		(long)(WNDPROC)ParentWindowProc);

}

void CGraphButton::UnInterceptParentWndProc()
{
	HWND hWnd = GetSafeHwnd();
	// ASSERT
	CWnd *pwndParent = GetParent();
	if (!pwndParent) return;
	if (!pwndParent->GetSafeHwnd()) return;

	// SET Parent WinProc = UNINTERCEPT
	m_nTimes--;
	if (m_parentWndProc && m_nTimes < 1)
	{
		(WNDPROC)::SetWindowLongPtr(
			pwndParent->GetSafeHwnd(), 
			GWLP_WNDPROC, 
			(long)(WNDPROC)m_parentWndProc);

		m_parentWndProc = NULL;
	}
}

LRESULT CALLBACK CGraphButton::ParentWindowProc( HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam )
{
	if (nMsg==WM_COMMAND || 
		nMsg==WM_SYSCOMMAND ||
		nMsg==WM_SYSKEYDOWN ||
		nMsg==WM_LBUTTONDOWN ||
		nMsg==WM_NCLBUTTONDOWN)
	{
		// ASSERT
		if (!IsMsgOK(hWnd, nMsg, lParam) && m_pActiveBtn)
		{
			m_pActiveBtn->HideList();
		}
	}

	if (nMsg == WM_MOUSEMOVE)
	{
		HideTip(hWnd, nMsg, lParam);
	}

	// CALL Parent
	if (!m_parentWndProc) 
		return NULL;

	if (m_pActiveBtn && nMsg == WM_ACAD_KEEPFOCUS)
	{
		if (KeepFocus(hWnd, nMsg, lParam))
		{
			return TRUE;
		}

		LRESULT lRs = CallWindowProc( m_parentWndProc, hWnd, nMsg, wParam, lParam );
		if (!lRs)
		{
			m_pActiveBtn->HideList();
		}

		return lRs;
	}

	return CallWindowProc( m_parentWndProc, hWnd, nMsg, wParam, lParam );

}

void CGraphButton::ShowList()
{
	if (NULL != m_pActiveBtn)
	{
		HideList();
		SetFocus();
		return;
	}



	// 点击按钮
	// 显示位置
	CRect rc;
	GetWindowRect(rc);
	rc.DeflateRect(m_nGrip, m_nGrip, m_nGrip + m_nBtnWid, m_nGrip);
	rc.OffsetRect(0, m_nGrip + rc.Height());

	CSize szItem = m_sizeItem;
	if (szItem.cx == 0 || szItem.cy == 0)
	{
		szItem = rc.Size();
	}

	rc.right = rc.left + m_nColCount * szItem.cx;
	rc.bottom = rc.top + m_nRowCount * szItem.cy;

	if (m_listCtrl.m_bSortByFixedRow)
	{
		if (m_listCtrl.GetItemCount() > m_nRowCount * m_nColCount)
		{
			rc.bottom += GetSystemMetrics(SM_CYHSCROLL) + GetSystemMetrics(SM_CYBORDER);
		}
	}
	else
	{
		if (m_listCtrl.GetItemCount() > m_nRowCount * m_nColCount)
		{
			rc.right += GetSystemMetrics(SM_CXVSCROLL) + GetSystemMetrics(SM_CXBORDER);
		}
	}

	m_listCtrl.SetLayer(m_nColCount, m_nRowCount);
	m_listCtrl.m_pOwnerBtn = this;

	m_listCtrl.MoveWindow(rc);
	m_listCtrl.ReDraw();

	m_listCtrl.ShowWindow(SW_SHOW);
	if (GetOwner())
	{
		GetOwner()->SendMessage(WM_NCACTIVATE, TRUE);
		GetOwner()->SetRedraw(TRUE);
	}

	m_pActiveBtn = this;
}

void CGraphButton::HideList()
{
	if (m_pActiveBtn)
	{
		m_listCtrl.ShowWindow(SW_HIDE);
		m_listCtrl.HideTip();
		m_pActiveBtn = NULL;
	}
}

BOOL CGraphButton::IsMsgOK( HWND hWnd, UINT nMsg,/* WPARAM wParam,*/ LPARAM lParam )
{
	// ASSERT
	if (!hWnd) 
	{
		return FALSE;
	}

	if (!m_pActiveBtn) 
	{
		return TRUE;
	}

	if ((HWND)lParam != m_pActiveBtn->GetSafeHwnd()) 
	{
		return FALSE;
	}

	if (nMsg != WM_COMMAND) 
	{
		if (nMsg == WM_LBUTTONDOWN)
		{
			return TRUE;
		}
		return FALSE;
	}

	//check if mouse pos is in drop down rect
	CRect rc;
	CPoint pt;
	m_pActiveBtn->GetWindowRect(rc);
	GetCursorPos(&pt);
	if (!rc.PtInRect(pt))
		return FALSE;

	return TRUE;

}

BOOL CGraphButton::HideTip( HWND hWnd, UINT nMsg, LPARAM lParam )
{
	if (!m_pActiveBtn)
	{
		return FALSE;
	}

	CRect rc;
	m_pActiveBtn->m_listCtrl.GetWindowRect(rc);
	CPoint pt;
	GetCursorPos(&pt);
	if (!rc.PtInRect(pt))
	{
		m_pActiveBtn->m_listCtrl.HideTip();
	}

	return TRUE;
}

void CGraphButton::ShowCaption( bool bShow )
{
	m_listCtrl.ShowItemCaption(bShow);
}

bool CGraphButton::IsCaptionShow()
{
	return m_listCtrl.IsShowItemCaption();
}

BOOL CGraphButton::KeepFocus( HWND hWnd, UINT nMsg, LPARAM lParam )
{
	if (!m_pActiveBtn)
	{
		return FALSE;
	}

	CRect rc;
	CPoint pt;
	m_pActiveBtn->m_listCtrl.GetWindowRect(rc);
	GetCursorPos(&pt);
	if (!rc.PtInRect(pt))
	{
		return FALSE;
	}

	return TRUE;
}

void CGraphButton::SetItemData( int nItem, DWORD dwData )
{
	m_listCtrl.SetItemData(nItem, dwData);
}

int CGraphButton::GetItemCount()
{
	return m_listCtrl.GetItemCount();
}

void CGraphButton::Clear()
{
	m_showCtrl.freeTempEntities();
	m_listCtrl.DeleteAllItem();

}
void CGraphButton::PostNcDestroy()
{
	// TODO: 

	CXTButton::PostNcDestroy();
}

void CGraphButton::OnDestroy()
{
	Clear();
	UnInterceptParentWndProc();


	CXTButton::OnDestroy();
}

BOOL CGraphButton::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	m_listCtrl.OnScroll(nFlags, zDelta);
	return TRUE;
}