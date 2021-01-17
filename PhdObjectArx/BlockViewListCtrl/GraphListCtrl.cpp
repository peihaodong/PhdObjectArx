#include "stdafx.h"
#include <math.h>
#include "GraphListCtrl.h"
#include "GraphButton.h"
#include "Resource.h"
// #include "Utils.h"
#include "axlock.h"

AC_DECLARE_EXTENSION_MODULE(ZYBlockViewDLL);
// #if _MSC_VER <= 1200
// 	// For VC6
// 	#define Graph_Color_Sel ::GetSysColor(COLOR_HIGHLIGHT)
// #else
// 	#define Graph_Color_Sel ::GetSysColor(COLOR_HOTLIGHT)
// #endif
#define Graph_Color_Sel RGB(255, 0, 0)

IMPLEMENT_DYNCREATE(CGraphListCtrl, CWnd)

CGraphListCtrl::CGraphListCtrl(  )
{
	m_bAllowDefault = false;	// 是否允许设置默认项
	m_bAllowSel = true;			// 是否允许选择
	m_bShowCaption = false;		// 是否显示标题
	m_bSortByFixedRow = false;	// 是否固定行，按列自由增减处理
	m_nCurSel = -1;				// 当前选择项
	m_nCurDefault = -1;			// 默认选项，绘制红旗标注，若没有设置为-1
	m_nBarState = SB_VERT;

	// 控件的显示控制数据
	m_nFixedRowNum = 2;				// 固定行数
	m_nFixedColNum = 2;				// 固定列数

	m_sizeItem = CSize(120, 120);	// 每项尺寸
	m_nCaptionHeight = 12;
	m_nMargin = 6;

	CDC* pDc = acedGetAcadFrame()->GetDC();
	m_colBk = pDc->GetBkColor();		// 背景色
	m_colText = pDc->GetTextColor();	// 文字颜色
	m_colTextBk = GetSysColor(COLOR_MENU);	// 文字背景色
	m_font;

	// 用于控制tip的变量
	m_nMouseItem = -1;
	m_nOldMouseItem = -1;

	// 用于控制滚动条的变量
	m_nVScrollMax = -1;
	m_nHScrollMax = -1;

	// 成员
	// 数据库
	m_pCurDb = NULL;

	// 控制Item的显示
	m_nRenderMode = AcGsView::k2DOptimized;
	m_viewVector = AcGeVector3d::kZAxis;
	m_bSetUserView = false;

	m_pOwnerBtn = NULL;;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	BOOL bSuc = RegisterWindowClass();

	NONCLIENTMETRICS ncm;
	::ZeroMemory(&ncm, sizeof(NONCLIENTMETRICS));
	ncm.cbSize = sizeof(NONCLIENTMETRICS);

	VERIFY(::SystemParametersInfo(SPI_GETNONCLIENTMETRICS,
		sizeof(NONCLIENTMETRICS), &ncm, 0));

	m_font.CreateFontIndirect(&ncm.lfMenuFont);

	m_pOrbitModel = acgsGetGsManager()->createAutoCADModel();
	ResetDefaultIcon();
}

CGraphListCtrl::~CGraphListCtrl()
{
	DeleteAllItem();

	if (IsWindow(m_TitleTip.m_hWnd))
		m_TitleTip.DestroyWindow();

	acgsGetGsManager()->destroyAutoCADModel(m_pOrbitModel);
	if (NULL != GetSafeHwnd())
	{
		DestroyWindow();
	}
}

BOOL CGraphListCtrl::RegisterWindowClass( HINSTANCE hInstance /*= NULL*/ )
{
	if (NULL == hInstance)
		hInstance = AfxGetInstanceHandle();
#ifdef _USE_XTP


	return XTPDrawHelpers()->RegisterWndClass(hInstance, GRAPHCTRL_CLASSNAME, CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW);
#else
	WNDCLASS wndcls;

	if (!(::GetClassInfo(hInstance, GRAPHCTRL_CLASSNAME, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInstance;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = GRAPHCTRL_CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
#endif
}



BOOL CGraphListCtrl::Create(const RECT& rect,
							CWnd* pParentWnd,
							UINT nID,
							DWORD dwStyle)
{
	ASSERT(pParentWnd->GetSafeHwnd());

// 	BOOL b = RegisterWindowClass();

	if (!CWnd::Create(GRAPHCTRL_CLASSNAME, NULL,
		dwStyle,
		rect,
		pParentWnd, 
		nID))
	{
		return FALSE;
	}

	return TRUE;
}

BEGIN_MESSAGE_MAP(CGraphListCtrl, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_GETDLGCODE()
	ON_WM_NCDESTROY()
	ON_WM_MOUSEWHEEL()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CGraphListCtrl::PreSubclassWindow()
{
	CWnd::PreSubclassWindow();

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	m_nCaptionHeight = tm.tmHeight + 
		tm.tmExternalLeading + 
		(tm.tmHeight / 4);
}

void CGraphListCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	OnDraw(&dc);
}

void CGraphListCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	int nSel = GetItemByPoint(point);
	if(nSel >= 0)
	{
		if (NULL != m_pOwnerBtn)
		{
			m_pOwnerBtn->OnListClick(GetCurSel(), nSel);
		}
		else
		{
			if (m_bAllowSel)
				OnSetCurSel(nSel, true);
		}
	}

	CWnd::OnLButtonUp(nFlags, point);
}

void CGraphListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	int nSel = GetItemByPoint(point);
	if(nSel >= 0)
	{
 		SendMessageToParent(m_nCurSel, NM_DBLCLK);

		if(m_bAllowSel) SetCurSel(nSel);
		if(m_bAllowDefault) SetDefault(nSel);
 	}

	CWnd::OnLButtonDblClk(nFlags, point);
}

void CGraphListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
// 	::SetCapture(NULL);
	HideTip();
	int nItemCount = GetItemCount();
	if( nItemCount <= 0)
	{
		CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
	if(m_nCurSel < 0)
	{
		OnSetCurSel(0);  
		CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
	int nRow = GetTopRowNum();
	int nCol = GetTopColumnNum();
	int nCurSel = m_nCurSel;
	switch (nChar)
	{
	case VK_RIGHT:
		{
			nCurSel ++;
			if(nCurSel >= nItemCount)
				break;
			if(nCurSel / m_nFixedColNum == nRow )
			{
				OnSetCurSel(nCurSel);  
			}
		}
		break;
	case VK_DOWN:
		nCurSel += m_nFixedColNum;
		if(nCurSel >= nItemCount)
		{
			SendMessage(WM_VSCROLL, SB_BOTTOM, 0);
			break;
		}
		OnSetCurSel(nCurSel);  
		break;
	case VK_LEFT:   
		nCurSel --;
		if(nCurSel < 0)
			break;
		if(nCurSel / m_nFixedColNum == nRow )
		{
			OnSetCurSel(nCurSel);  
		}
		break;
	case VK_UP:     
		nCurSel -= m_nFixedColNum;
		if(nCurSel < 0)
			break;  
		OnSetCurSel(nCurSel);  
		break;  
	case VK_NEXT:   
		SendMessage(WM_VSCROLL, SB_PAGEDOWN, 0);
		break;
	case VK_PRIOR:  
		SendMessage(WM_VSCROLL, SB_PAGEUP, 0);
		break;
	case VK_HOME:
		SendMessage(WM_VSCROLL, SB_TOP, 0);
		break;
	case VK_END:    
		SendMessage(WM_VSCROLL, SB_BOTTOM, 0);
		break;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

UINT CGraphListCtrl::OnGetDlgCode()
{
	UINT nCode = DLGC_WANTARROWS | DLGC_WANTCHARS; //DLGC_WANTALLKEYS
	//  if (!IsCTRLpressed())
	//      nCode |= DLGC_WANTTAB;

	return nCode;
}

void CGraphListCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	do
	{
		CRect rc;
		GetClientRect(rc);
		if (!rc.PtInRect(point))
		{
			break;
		}

		m_nMouseItem = GetItemByPoint(point);
		if (m_nMouseItem == m_nOldMouseItem)
		{
			break;
		}

		if (m_nOldMouseItem > -1)
		{
			HideTip();
// 			::SetCapture(NULL);
		}

		if (m_nMouseItem < 0)
		{
			m_nOldMouseItem = m_nMouseItem;
			break;
		}

		if(m_bShowCaption && (m_nMouseItem >= 0))
		{
			int nVertScroll = GetScrollPos(SB_VERT), 
				nHorzScroll = GetScrollPos(SB_HORZ);

			CString str;
			CRect rt = GetItemRect(m_nMouseItem);
			rt.OffsetRect(-nHorzScroll, -nVertScroll);
			CRect rtCaption = rt;
			int iWide = m_nCaptionHeight;
			//if( rtCaption.Height()>iWide)rtCaption.top += iWide;		
			rtCaption.top = rtCaption.bottom-iWide;
			CString strName = GetItem(m_nMouseItem)->GetName(); 
			ShowTip(rtCaption, strName, rt);
		}

		m_nOldMouseItem = m_nMouseItem;
	} while (false);

	CWnd::OnMouseMove(nFlags, point);
}

void CGraphListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int scrollPos = GetScrollPos32(SB_HORZ);
	CSize size    = GetItemSizeWithCaption();

	CRect rt;
	GetClientRect(rt);

	int nPageWid = rt.Width() - (rt.Width() % size.cx);
	if (rt.Width() < size.cx)
	{
		nPageWid = size.cx;
	}
	// mod by yanghailong.2010.08.30
	// 对图片来说，显示半张是没有意义的。
	switch (nSBCode)
	{
	case SB_LINERIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			int xScroll = size.cx;
			SetScrollPos32(SB_HORZ, scrollPos + xScroll);
			if (GetScrollPos32(SB_HORZ) == scrollPos)
				break;          // didn't work
		}
		break;

	case SB_LINELEFT:
		SetScrollPos32(SB_HORZ, max(0, scrollPos - size.cx));
		break;

	case SB_PAGERIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			int pos = min(m_nHScrollMax, scrollPos + nPageWid);
			SetScrollPos32(SB_HORZ, pos);
		}
		break;

	case SB_PAGELEFT:
		if (scrollPos > 0)
		{
			int pos = max(0, scrollPos - nPageWid);
			SetScrollPos32(SB_HORZ, pos);
		}
		break;

	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		{
			SetScrollPos32(SB_HORZ, nPos);
		}
		break;

	case SB_LEFT:
		if (scrollPos > 0)
		{
			SetScrollPos32(SB_HORZ, 0);
		}
		break;

	case SB_RIGHT:
		if (scrollPos < m_nHScrollMax)
		{
			SetScrollPos32(SB_HORZ, m_nHScrollMax);
		}
		break;
	default: 
		break;
	}

	Invalidate();
}

void CGraphListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int scrollPos = GetScrollPos32(SB_VERT);
	CSize size    = GetItemSizeWithCaption();
	CRect rt;
	GetClientRect(rt);

	int nPageHeight = rt.Height() - rt.Height() % size.cy;
	if (rt.Height() < size.cy)
	{
		nPageHeight = size.cy;
	}

	switch (nSBCode)
	{
	case SB_LINEDOWN:
		if (scrollPos < m_nVScrollMax)
		{

			int yScroll = size.cy;
			SetScrollPos32(SB_VERT, scrollPos + yScroll);
			if (GetScrollPos32(SB_VERT) == scrollPos)
			{    
				break;          // didn't work
			}
		}
		break;

	case SB_LINEUP:
		{
			int yScroll = size.cy;
			SetScrollPos32(SB_VERT, max(0, scrollPos - yScroll));

			//RedrawWindow(NULL, NULL, RDW_ RDW_FRAME);
		}
		break;

	case SB_PAGEDOWN:
		if (scrollPos < m_nVScrollMax)
		{         
			scrollPos = min(m_nVScrollMax, scrollPos + size.cy);
			SetScrollPos32(SB_VERT, scrollPos);
		}
		break;

	case SB_PAGEUP:
		if (scrollPos > 0)
		{ 
			scrollPos = max(0, scrollPos - size.cy);
			SetScrollPos32(SB_VERT, scrollPos);
		}
		break;

	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		{
			SetScrollPos32(SB_VERT, GetScrollPos32(SB_VERT, TRUE));
		}
		break;

	case SB_TOP:
		if (scrollPos > 0)
		{
			SetScrollPos32(SB_VERT, 0);
		}
		break;

	case SB_BOTTOM:
		if (scrollPos < m_nVScrollMax)
		{
			SetScrollPos32(SB_VERT, m_nVScrollMax);
		}
	default: 
		break;
	}

	Invalidate();
}

int CGraphListCtrl::GetScrollPos32(int nBar, BOOL bGetTrackPos /* = FALSE */)
{
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);

	if (bGetTrackPos)
	{
		if (GetScrollInfo(nBar, &si, SIF_TRACKPOS))
			return si.nTrackPos;
	}
	else
	{
		if (GetScrollInfo(nBar, &si, SIF_POS))
			return si.nPos;
	}

	return 0;
}

BOOL CGraphListCtrl::SetScrollPos32(int nBar, int nPos, BOOL bRedraw /* = TRUE */)
{
	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask  = SIF_POS;
	si.nPos   = nPos;
	return SetScrollInfo(nBar, &si, bRedraw);
}

void CGraphListCtrl::OnSize(UINT nType, int cx, int cy)
{
	if (!::IsWindow(m_hWnd))
	{
		return;
	}

	CalItemSize();
	ResetScrollBars();
	CWnd::OnSize(nType, cx, cy);

}

BOOL CGraphListCtrl::OnEraseBkgnd(CDC* pDC)
{
	//do nothing
	return TRUE;
}

void CGraphListCtrl::OnDraw(CDC* pDC)
{
	CRect clipRect;
	if(pDC->GetClipBox(&clipRect) == ERROR)
	{
		return;
	}
	EraseBkgnd(pDC);
	DrawItem(pDC);
}
void CGraphListCtrl::DrawItem(CDC* pDC )
{
	for(int i = 0; i < m_arrayItem.GetSize(); i ++)
	{
		DrawItem(i, pDC);
	}
}

void CGraphListCtrl::DrawItem( CGraphBlockViewWnd* pWnd, CRect rc, int nType, CDC* pDC )
{
	rc.InflateRect(1,1);
	DrawItemBackground(pDC, rc, GetBkColor(), nType);

	rc.DeflateRect(1, 1);

	if (m_bShowCaption)
	{
		CRect rtCaption(rc);
		rc.bottom -= m_nCaptionHeight;
		rtCaption.top = rc.bottom;
		CString str = pWnd->GetName();

		DrawItemCaption(pDC, rtCaption, str, nType % 4 == 2);
	}

	pWnd->MoveWindow(rc);
}

void CGraphListCtrl::DrawItem( int nItem, CDC* pDC )
{
	int nVertScroll = GetScrollPos(SB_VERT), 
		nHorzScroll = GetScrollPos(SB_HORZ);
	
	CRect rcItem = GetItemRect(nItem);
	CRect rcClient;
	GetClientRect(rcClient);
	rcClient.OffsetRect(nHorzScroll, nVertScroll);

	if( !(rcClient.PtInRect(rcItem.TopLeft()) ||
		rcClient.PtInRect(rcItem.BottomRight()) ||
		rcClient.PtInRect(CPoint(rcItem.left, rcItem.bottom)) ||
		rcClient.PtInRect(CPoint(rcItem.right, rcItem.top))) )
	{
		m_arrayItem[nItem]->ShowWindow(SW_HIDE);
	}
	else
	{
		m_arrayItem[nItem]->ShowWindow(SW_SHOW);

		rcItem.OffsetRect(-rcClient.left, -rcClient.top);
		rcItem.DeflateRect(m_nMargin / 2, m_nMargin / 2);

		int nType = 0;
		if (m_nCurSel == nItem)
		{
			nType = 2;
		}
		else if(m_nMouseItem == nItem)
		{
			nType = 1;
		}

		// 不在边框上体现是否默认, mod by yhl, 2010-12-29
// 		if (m_nCurDefault == nItem)
// 		{
// 			nType += 4;
// 		}

		DrawItem(m_arrayItem[nItem], rcItem, nType, pDC);
	}
}

void CGraphListCtrl::DrawItem( CGraphBlockViewWnd* pWnd )
{
	CPaintDC DC(this);
	int nItem = GetItem(pWnd);
	if (nItem > -1)
	{
		DrawItem(nItem, &DC);
	}
}
void CGraphListCtrl::DrawItemBackground(IN CDC* pDC,
										IN CRect rt,
										IN COLORREF color,
										IN int nType)
{
	switch(nType)
	{
	case 0://正常
		pDC->Draw3dRect(&rt,  RGB(255, 255, 255), RGB(128, 128, 128));
		break;
	case 1://鼠标经过
		pDC->Draw3dRect(&rt,  RGB(255, 255, 255), RGB(128, 128, 128));
		rt.InflateRect(1, 1);
		pDC->Draw3dRect(&rt, RGB(225, 225, 225), RGB(0, 0, 0));
		break;
	case 2://选中
		//         pDC->Draw3dRect(&rt,  RGB(128, 128, 128), RGB(255, 255, 255));
		//         rt.InflateRect(1, 1);
		//         pDC->Draw3dRect(&rt, RGB(0, 0, 0), RGB(225, 225, 225));
		if ( m_bShowCaption )
		{
			// 			pDC->Draw3dRect(&rt,  RGB(128, 128, 128), RGB(255, 255, 255));
			// 			rt.InflateRect(1, 1);
			// 			pDC->Draw3dRect(&rt, RGB(0, 0, 0), RGB(225, 225, 225));

			CPen pen;
			pen.CreatePen(PS_SOLID,3,Graph_Color_Sel);
			CPen* pOldPen = pDC->SelectObject(&pen);
			//pDC-> SelectObject(GetStockObject(NULL_BRUSH));//透明画刷
			pDC->Rectangle(&rt);
			pDC->SelectObject(pOldPen);
		}
		else
		{
			rt.InflateRect(1,1);
			CPen pen;
			pen.CreatePen(PS_SOLID,3,Graph_Color_Sel);
			CPen* pOldPen = pDC->SelectObject(&pen);
			//pDC-> SelectObject(GetStockObject(NULL_BRUSH));//透明画刷
			pDC->Rectangle(&rt);
			pDC->SelectObject(pOldPen);
		}


		break;
	} 
}

// default 由图块来控制。此函数废除
// void CGraphListCtrl::DrawDefaultItemBackground(IN CDC* pDC,
// 											   IN CRect rt,
// 											   IN COLORREF color )
// {
// 	HBRUSH hOldBrush = NULL;
// 	CBrush brushSel(RGB(0, 0, 0));
// 	hOldBrush = (HBRUSH)pDC-> SelectObject(brushSel);
// 	pDC->Rectangle(&rt);
// 	pDC->SelectObject(hOldBrush);

// 	CPen pen;
// 	pen.CreatePen(PS_SOLID,3,color);
// 	CPen* pOldPen = pDC->SelectObject(&pen);
// 
// 	rt.DeflateRect(1,1);
// 	int nWide = rt.Height()/3;
// 	CRect rtDraw;
// 	rtDraw.bottom = rt.bottom;
// 	rtDraw.left = rt.left;
// 	rtDraw.top = rt.bottom-nWide;
// 	rtDraw.right = rt.left+nWide;
// 
// 	CXTPImageManagerIcon::DrawIconComposited(pDC, rtDraw.TopLeft(), rtDraw.Size(), m_hIconDefault);
// 	pDC->DrawIcon(rtDraw.left+2,rtDraw.bottom-30,m_hIconDefault);
// 
// 	pDC->SelectObject(GetStockObject(NULL_BRUSH));//透明画刷
// 	pDC->Rectangle(&rt);  
// 	pDC->SelectObject(pOldPen);
// 
// }

void CGraphListCtrl::DrawItemCaption(IN CDC*    pDC,
									 IN CRect   rt,
									 IN CString strName,
									 IN BOOL    bSel)
{
	//     CBrush brushSel(RGB(0, 120, 240));
	//     CBrush brushNormal(RGB(166, 210, 255));
// 	CBrush brushSel(RGB(0, 60, 110)); //pk
// 	CBrush brushNormal(RGB(166, 210, 255));
	HBRUSH hOldBrush = NULL;
	CBrush bush;
	bush.CreateSolidBrush(m_colTextBk);
	hOldBrush = (HBRUSH)pDC-> SelectObject(&bush);//透明画刷
	// hOldBrush = (HBRUSH)pDC->SelectObject(brushSel);
	//pDC->SetTextColor(RGB(255, 255, 255)); //pk
	COLORREF colText = pDC->SetTextColor(GetTextColor());
	COLORREF colBk = pDC->SetBkColor(m_colTextBk);
	CFont* pFont = pDC->SelectObject(&m_font);

	CSize size = pDC->GetTextExtent(strName);
	//	rt.InflateRect(2,2);
	// pDC->Rectangle(&rt);//pk
	// 	rt.DeflateRect(2,2);
	//pDC->Draw3dRect(&rt, RGB(255, 255, 255), RGB(128, 128, 128)); 

// 	pDC->SetBkMode(TRANSPARENT);
	if(size.cx > rt.Width())
	{
		pDC->SetTextAlign(TA_LEFT);
// 		rt.DeflateRect(2, 2);
		pDC->IntersectClipRect(&rt);
		pDC->FillSolidRect(rt, m_colTextBk);
		pDC->TextOut(rt.left, rt.top, strName);

		CRgn rgn;
		CRect rtOld;
		GetClientRect(&rtOld);
		rgn.CreateRectRgn(rtOld.left, rtOld.top, rtOld.right, rtOld.bottom);
		pDC->SelectClipRgn(&rgn);
	} else
	{
		pDC->SetTextAlign(TA_CENTER);
		pDC->FillSolidRect(rt, m_colTextBk);
		pDC->TextOut(rt.left + rt.Width() / 2, rt.top+2, strName);
	}

	pDC->SelectObject(pFont);
	pDC->SetBkColor(colBk);
	pDC->SetTextColor(colText);
	pDC->SelectObject(hOldBrush);
}

CRect CGraphListCtrl::GetVirtualRect()
{
	int nMinItem = 0;
	int nMaxItem = GetItemCount() - 1;
	CSize szItem = GetItemSizeWithCaption();

	CRect rcResult;
	if (!m_bSortByFixedRow)
	{
		rcResult.top = (nMinItem / m_nFixedColNum) * szItem.cy;
		rcResult.bottom = (nMaxItem / m_nFixedColNum + 1) * szItem.cy;
		rcResult.left = 0;
		rcResult.right = m_nFixedColNum * szItem.cx;
	}
	else
	{
		rcResult.top = 0;
		rcResult.bottom = m_nFixedRowNum * szItem.cy;
		rcResult.left = (nMinItem / m_nFixedRowNum) * szItem.cx;
		rcResult.right = (nMaxItem / m_nFixedRowNum + 1) * szItem.cx;
	}

	return rcResult;
}

CRect CGraphListCtrl::GetItemRect(IN int nItem)
{
	CSize szItem = GetItemSizeWithCaption();

	CRect rcResult;
	if (m_bSortByFixedRow)
	{
		rcResult.left = (nItem / m_nFixedRowNum) * szItem.cx;
		rcResult.top = (nItem % m_nFixedRowNum) * szItem.cy;
	}
	else
	{
		rcResult.left = (nItem % m_nFixedColNum) * szItem.cx;
		rcResult.top = (nItem / m_nFixedColNum) * szItem.cy;
	}

	rcResult.right = rcResult.left + szItem.cx;
	rcResult.bottom = rcResult.top + szItem.cy;

	return rcResult;
}

CRect CGraphListCtrl::GetItemRect(IN CGraphBlockViewWnd* pItem)
{
	return GetItemRect(GetItem(pItem));
}

int CGraphListCtrl::GetMinVisibleItem()
{
	CSize sizeItem = GetItemSizeWithCaption();
	if (!m_bSortByFixedRow)
	{
		int nVertScroll = GetScrollPos32(SB_VERT);
		int nRow = nVertScroll / sizeItem.cy;
		return nRow * m_nFixedColNum;
	}
	else
	{
		int nHorzScroll = GetScrollPos(SB_HORZ);
		int nCol = nHorzScroll / sizeItem.cx;
		return nCol * m_nFixedRowNum;
	}
}

CSize CGraphListCtrl::GetItemSizeWithCaption()
{
	CSize size(m_nMargin, m_nMargin);
	size.cy += m_bShowCaption ? m_nCaptionHeight : 0;

	size += m_sizeItem;
	return size;
}

int CGraphListCtrl::GetItemByPoint(IN CPoint pt)
{
	pt.Offset(GetScrollPos(SB_HORZ),
		GetScrollPos(SB_VERT));

	CSize szItem = GetItemSizeWithCaption();
	int nCol = pt.x / szItem.cx;
	int nRow = pt.y / szItem.cy;
	int nItem = -1;
	if (m_bSortByFixedRow)
	{
		nItem = m_nFixedRowNum * nCol + nRow;
	}
	else
	{
		nItem = m_nFixedColNum * nRow + nCol;
	}

	return nItem < GetItemCount() ? nItem : -1;
}

int CGraphListCtrl::GetMaxVisibleItem()
{
	int nMaxNum = GetMinVisibleItem() + m_nFixedRowNum * m_nFixedColNum;
	nMaxNum--;
	return nMaxNum < GetItemCount() ? nMaxNum : GetItemCount() - 1;
}

void CGraphListCtrl::EraseBkgnd(CDC* pDC)
{
	CRect clipRect;
	CBrush burshBk(GetBkColor());

	if(pDC->GetClipBox(&clipRect) == ERROR)
	{
		return;
	}
	pDC->FillRect(&clipRect, &burshBk);
}


CGraphBlockViewWnd* CGraphListCtrl::GetItem(IN int nItem)
{
	ASSERT((nItem >= 0) && (nItem < GetItemCount()));
	return m_arrayItem.GetAt(nItem);
}

int CGraphListCtrl::GetItem( IN CGraphBlockViewWnd* pItem )
{
	for(int i = 0; i < m_arrayItem.GetSize(); i ++)
	{
		if(m_arrayItem.GetAt(i) == pItem)
		{
			return i;
		}
	}

	return -1;
}
void CGraphListCtrl::SetItemData(IN int nItem, DWORD lParam)
{
	ASSERT((nItem >= 0) && (nItem < GetItemCount()));
	m_arrayItem[nItem]->SetData(lParam);
}

DWORD CGraphListCtrl::GetItemData(IN int nItem)
{
	ASSERT((nItem >= 0) && (nItem < GetItemCount()));
	return m_arrayItem[nItem]->GetData();
}

int CGraphListCtrl::GetItemCount()
{
	return m_arrayItem.GetSize();
}

void CGraphListCtrl::SetBkColor(IN COLORREF color)
{
	m_colBk = color;
}

COLORREF CGraphListCtrl::GetBkColor()
{
	return m_colBk;
}

void CGraphListCtrl::DeleteAllItem()
{
	SetDefault(-1);
	m_nCurSel = -1;
	m_nOldMouseItem = -1;
	for(int i = 0; i < m_arrayItem.GetSize(); i ++)
	{
		delete m_arrayItem[i];
	}
	m_arrayItem.RemoveAll();

	if(IsWindow(m_hWnd))
		Invalidate();
}

void CGraphListCtrl::DeleteItem(IN int nItem)
{
	ASSERT((nItem >= 0) && (nItem < GetItemCount()));
	m_nCurSel = -1;
	delete m_arrayItem[nItem];
	m_arrayItem.RemoveAt(nItem);

	Invalidate();
}

void CGraphListCtrl::OnSetCurSel( int nItem, bool bMsg )
{
	if (!m_bAllowSel)
	{
		return;
	}

	m_nCurSel = nItem;
	if (-1 != m_nCurSel)
	{
		int nVertScroll = GetScrollPos(SB_VERT), 
			nHorzScroll = GetScrollPos(SB_HORZ);

		CRect rt = GetItemRect(m_nCurSel);
		rt.OffsetRect(-nHorzScroll, -nVertScroll);
		CRect rtClient;
		GetClientRect(rtClient);
		if( !rtClient.PtInRect( CPoint(rt.left + rt.Width() / 2,
			rt.top  + rt.Height() / 2) ) )
		{
			if((rtClient.left > rt.left) || (rtClient.right < rt.right) )
			{
				rt.OffsetRect(nHorzScroll, nVertScroll);
				SetScrollPos32(SB_HORZ, rt.left);
			} else if((rtClient.top > rt.top) || (rtClient.bottom < rt.bottom) )
			{
				rt.OffsetRect(nHorzScroll, nVertScroll);
				SetScrollPos32(SB_VERT, rt.top);
			} else
			{
				rt.OffsetRect(nHorzScroll, nVertScroll);
				SetScrollPos32(SB_HORZ, rt.left);
				SetScrollPos32(SB_VERT, rt.top);
			}
		}
	}

	Invalidate();
	if (bMsg)
	{
		SendCommandToParent(LBN_SELCHANGE);
	}
}

void CGraphListCtrl::SetCurSel(IN int nItem)
{
	OnSetCurSel(nItem, false);
}

int CGraphListCtrl::GetCurSel()
{
	return m_nCurSel;
}
void CGraphListCtrl::SetDefault( IN int nItem)
{
	if (!m_bAllowDefault)
	{
		return;
	}

	if( m_nCurDefault == nItem ) return ;

	OnDefaultChanged(m_nCurDefault, nItem);
	m_nCurDefault = nItem;
	Invalidate();
}
int CGraphListCtrl::GetDefault()
{
	return m_nCurDefault;
}


BOOL CGraphListCtrl::IsVisibleVScroll()
{ 
	return ((m_nBarState == SB_BOTH) || (m_nBarState == SB_VERT));
} 

BOOL CGraphListCtrl::IsVisibleHScroll()
{ 
	return ((m_nBarState == SB_BOTH) || (m_nBarState == SB_HORZ));
}


void CGraphListCtrl::EnableScrollBars(int nBar, BOOL bEnable /*=TRUE*/)
{
	if (bEnable)
	{
		if (!IsVisibleHScroll() && (nBar == SB_BOTH || nBar == SB_HORZ))
		{
			CWnd::EnableScrollBarCtrl(SB_HORZ, bEnable);
			m_nBarState |= SB_HORZ;
		}

		if (!IsVisibleVScroll() && (nBar == SB_BOTH || nBar == SB_VERT))
		{
			CWnd::EnableScrollBarCtrl(SB_VERT, bEnable);
			m_nBarState |= SB_VERT;
		}
	}
	else
	{
		if ( IsVisibleHScroll() && (nBar == SB_BOTH || nBar == SB_HORZ))
		{
			CWnd::EnableScrollBarCtrl(SB_HORZ, bEnable);
			m_nBarState &= ~SB_HORZ;
		}

		if ( IsVisibleVScroll() && (nBar == SB_BOTH || nBar == SB_VERT))
		{
			CWnd::EnableScrollBarCtrl(SB_VERT, bEnable);
			m_nBarState &= ~SB_VERT;
		}
	}
}

void CGraphListCtrl::ResetScrollBars()
{
	if( !::IsWindow(GetSafeHwnd())) 
	{
		return;
	}

	CRect rt;
	GetClientRect(rt);

	if (rt.left == rt.right || rt.top == rt.bottom)
	{
		return;
	}

	if (IsVisibleVScroll())
	{
		rt.right += 
			(GetSystemMetrics(SM_CXVSCROLL) + GetSystemMetrics(SM_CXBORDER)) ;//- 20;
	}
	if (IsVisibleHScroll())
	{
		rt.bottom += 
			(GetSystemMetrics(SM_CYHSCROLL) + GetSystemMetrics(SM_CYBORDER));
	}

	CRect VisibleRect(rt);
	CRect VirtualRect = GetVirtualRect();

	SCROLLINFO si;
	si.cbSize = sizeof(SCROLLINFO);
	si.fMask = SIF_PAGE;
	si.nPage = VisibleRect.Width();
	SetScrollInfo(SB_HORZ, &si, FALSE); //pk
	si.nPage = VisibleRect.Height();
	SetScrollInfo(SB_VERT, &si, FALSE);

	if (VisibleRect.Height() < VirtualRect.Height()) //pk  
		VisibleRect.right -= ::GetSystemMetrics(SM_CXVSCROLL);
	if (VisibleRect.Height() < VirtualRect.Height()) //pk  
	{
		if (IsVisibleVScroll()) EnableScrollBars(SB_VERT, TRUE); 
		m_nVScrollMax = VirtualRect.Height(); 
	}
	else
		m_nVScrollMax = 0;

	if (VisibleRect.Width() < VirtualRect.Width())   //pk  
		VisibleRect.bottom -= ::GetSystemMetrics(SM_CYHSCROLL);


	if (VisibleRect.Width() < VirtualRect.Width())
	{
		if (IsVisibleHScroll()) EnableScrollBars(SB_HORZ, TRUE);  //pk
		m_nHScrollMax = VirtualRect.Width() ;// 
	}
	else
		m_nHScrollMax = 0;

	ASSERT(m_nVScrollMax < INT_MAX && m_nHScrollMax < INT_MAX); // This should be fine

	//pk
	if( m_bSortByFixedRow ) m_nVScrollMax = 0;
	else					m_nHScrollMax = 0;

 	if (IsVisibleVScroll()) SetScrollRange(SB_VERT, 0, m_nVScrollMax, TRUE);
	if (IsVisibleHScroll()) SetScrollRange(SB_HORZ, 0, m_nHScrollMax, TRUE); //pk
}

LRESULT CGraphListCtrl::SendMessageToParent(IN int nItem, IN int nMessage)
{
	NM_GRAPHLIST nmgv;  
	nmgv.nItem        = nItem;
	nmgv.hdr.hwndFrom = m_hWnd;
	nmgv.hdr.idFrom   = GetDlgCtrlID();
	nmgv.hdr.code     = nMessage;
	CWnd *pOwner = GetOwner();
	if (pOwner && IsWindow(pOwner->m_hWnd))
	{
		return pOwner->SendMessage(WM_NOTIFY,
			nmgv.hdr.idFrom,
			(LPARAM)&nmgv);
	} else
	{
		return 0;
	}
}



void CGraphListCtrl::ReDraw( )
{
	ResetScrollBars();
	Invalidate();
}

//设置布局：2*2；4*5
void CGraphListCtrl::SetLayer( int nColumn, int nRow, int unused )
{
	m_nFixedRowNum = nRow;
	m_nFixedColNum = nColumn;

	CalItemSize();
}

void CGraphListCtrl::CalItemSize()
{
	CRect rc;
	GetClientRect(&rc);

	// 计算每行每列的尺寸
	int nRowCount = m_nFixedRowNum > 0 ? m_nFixedRowNum : 0;
	int nColCount = m_nFixedColNum > 0 ? m_nFixedColNum : 0;
	int nCaptionHeight = m_bShowCaption ? m_nCaptionHeight : 0;

	// 设置滚动条
	m_nBarState = m_bSortByFixedRow ? SB_HORZ : SB_VERT;

	m_sizeItem.cx = rc.Width() / m_nFixedColNum;
	m_sizeItem.cy = rc.Height() / m_nFixedRowNum;

	CSize szMargin(m_nMargin, m_nMargin + nCaptionHeight);
	m_sizeItem -= szMargin;
}

void CGraphListCtrl::SetDefaultIcon( AcDbEntity* pEnt )
{
	m_OrbitIcon.SetShowEnt(pEnt);
	if (!pEnt->isPersistent())
	{
		m_DefDb.addAcDbObject(pEnt);
		pEnt->close();
	}
}
void CGraphListCtrl::SetCurDatabase(AcDbDatabase* pDb)
{
	m_pCurDb = pDb;
}

void CGraphListCtrl::SetViewMode( AcGeVector3d viewVector,AcGsView::RenderMode nRenderMode)
{
	m_viewVector = viewVector;
	m_nRenderMode = nRenderMode;
	m_bSetUserView = true;
}

void CGraphListCtrl::SetSortByHorScroll(bool bSortByHor ) 	  //按水平方向摆放图
{
	m_bSortByFixedRow = bSortByHor;

	CalItemSize();
	ResetScrollBars();
}

void CGraphListCtrl::OnNcDestroy()
{
	DeleteAllItem();

	CWnd::OnNcDestroy();
}

LRESULT CGraphListCtrl::SendCommandToParent( IN int nMessage )
{
	if (GetOwner())
	{
		return GetOwner()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), nMessage), (LPARAM)GetSafeHwnd());
	}

	return 0;
}

void CGraphListCtrl::HideTip()
{
	if (m_nOldMouseItem > -1)
	{
		m_nOldMouseItem = -1;
		
		GetTitleTip()->Hide();
	}
}

void CGraphListCtrl::ShowTip( LPRECT rc, LPCTSTR szTitle, LPRECT rcBk )
{
	GetTitleTip()->Show(rc, szTitle, 0, NULL, &m_font, GetTextColor(), GetBkColor());
}

void CGraphListCtrl::OnDefaultChanged( int nOldItem, int nNewItem )
{
	if (nOldItem != -1)
	{
		CGraphBlockViewWnd* pWnd = GetItem(nOldItem);

		if (pWnd->m_pView)
		{
			pWnd->m_pView->erase(&m_OrbitIcon);
		}
		m_OrbitIcon.setGsView(NULL);
// 		pWnd->SetDefault(FALSE, m_pOrbitModel);
	}

	if (-1 != nNewItem)
	{
		CGraphBlockViewWnd* pWnd = GetItem(nNewItem);

		if (pWnd->m_pView)
		{
			pWnd->m_pView->add(&m_OrbitIcon, m_pOrbitModel);
		}
		m_OrbitIcon.setGsView(pWnd->m_pView);
// 		pWnd->SetDefault(TRUE, m_pOrbitModel);
	}
}

void CGraphListCtrl::ResetDefaultIcon()
{
	AcDbObjectId blkId;
	if (!GetDefaultIconId(blkId))
	{
		return;
	}

	AcDbBlockReference* pRef = new AcDbBlockReference(AcGePoint3d::kOrigin, blkId);
	m_DefDb.addAcDbObject(pRef);

	SetDefaultIcon(AcDbEntity::cast(pRef->clone()));
}

bool CGraphListCtrl::GetDefaultIconId( AcDbObjectId& id )
{
	CString strBlockName = _T("_DEFAULTICON");
	Acad::ErrorStatus es = Acad::eOk;
	DWORD dwErrorCode = 0;

	AcDbBlockTableRecordPointer pBlkRc(strBlockName, &m_DefDb, AcDb::kForRead);
	if (Acad::eOk == pBlkRc.openStatus())
	{
		id = pBlkRc->objectId();
		return true;
	}

	// 首先，释放资源
	HMODULE hModel = _hdllInstance;
	HRSRC hRs = ::FindResource(hModel, MAKEINTRESOURCE(IDR_DWGDEFAULTICON), _T("DWG"));
	if (!hRs)
	{
		dwErrorCode = GetLastError();
		hModel = AfxFindResourceHandle(MAKEINTRESOURCE(IDR_DWGDEFAULTICON), _T("DWG"));
		if (hModel)
		{
			hRs = ::FindResource(hModel, MAKEINTRESOURCE(IDR_DWGDEFAULTICON), _T("DWG"));
		}
	}

	if (!hRs)
	{
		dwErrorCode = GetLastError();
		return false;
	}

	DWORD dwLen = ::SizeofResource(hModel, hRs);
	if (0 == dwLen)
	{
		dwErrorCode = GetLastError();
		return false;
	}

	HGLOBAL hHandle = ::LoadResource(hModel, hRs);
	LPVOID pVoid = ::LockResource(hHandle);

	TCHAR szPath[_MAX_PATH];
	memset(szPath, 0, sizeof(TCHAR) * MAX_PATH);
	int nLenth = ::GetModuleFileName(hModel, szPath, MAX_PATH);

	TCHAR szDrive[_MAX_DRIVE];
	TCHAR szDir[_MAX_DIR];
	TCHAR szFname[_MAX_FNAME];
	TCHAR szFext[_MAX_EXT];
	_tsplitpath(szPath, szDrive, szDir, szFname, szFext);

	CString strPath = szDrive;
	strPath += szDir;
	strPath += _T("~temp.dwg");
	CFile file(strPath, CFile::modeCreate | CFile::modeWrite);
	file.Write(pVoid, dwLen);
	file.Close();

	do 
	{
		// 打开dwg
		AcDbDatabase FileDb(false);
		AcDbDatabase* pTempDb = NULL;
		es = FileDb.readDwgFile(strPath);
		if (Acad::eOk != es)
			break;

		es = FileDb.wblock(pTempDb);
		if (Acad::eOk != es)
			break;

		es = m_DefDb.insert(id, strBlockName, pTempDb);
 		delete pTempDb;
		if (Acad::eOk != es)
			break;
	} while (false);

	CFile::Remove(strPath);
	return Acad::eOk == es;
}

Acad::ErrorStatus CGraphListCtrl::GetBlock( LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord )
{
// 	return GetBlock1(szBlockName, pBlockRecord);
// 	return GetBlock2(szBlockName, pBlockRecord);
	return GetBlock3(szBlockName, pBlockRecord);
}

Acad::ErrorStatus CGraphListCtrl::GetBlock1( LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord )
{
	Acad::ErrorStatus es;
	pBlockRecord = NULL;

	AcDbBlockTableRecordPointer pSrcRc(szBlockName, m_pCurDb, AcDb::kForRead);
	es = pSrcRc.openStatus();
	if (Acad::eOk != es)
		return es;

	AcDbBlockTablePointer pDestTbl(&m_DefDb, AcDb::kForRead);
	es = pDestTbl.openStatus();
	if (Acad::eOk != es)
		return es;

	AcDbBlockTableRecordPointer pDestRc;
	pDestRc.create();
	es = pDestRc.openStatus();
	if (Acad::eOk != es)
		return es;

	es = pDestRc->setName(szBlockName);
	if (Acad::eOk != es)
		return es;

	pDestTbl->upgradeOpen();
	es = pDestTbl->add(pDestRc.object());
	pDestTbl->downgradeOpen();
	if (Acad::eOk != es)
		return es;

	AcDbBlockTableRecordIterator* pIter = NULL;
	es = pSrcRc->newIterator(pIter);
	if (Acad::eOk != es)
		return es;

	AcDbObjectId objId;
	AcDbIdMapping idMap;
	AcDbObject* pObject = NULL;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		es = pIter->getEntityId(objId);
		if (Acad::eOk != es)
			continue;

		AcDbEntityPointer pEnt(objId, AcDb::kForRead);
		es = pEnt.openStatus();
		if (Acad::eOk != es)
			continue;

		if (pEnt->isKindOf(AcDbText::desc()))
		{
			continue;
		}

		es = pEnt->deepClone(pDestRc.object(), pObject, idMap, true);
		if (Acad::eOk != es)
			continue;

		pObject->close();
	}

	pBlockRecord = pDestRc.object();
	return es;
}

Acad::ErrorStatus CGraphListCtrl::GetBlock2( LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord )
{
	Acad::ErrorStatus es;
	pBlockRecord = NULL;

	AcDbBlockTableRecordPointer pSrcRc(szBlockName, m_pCurDb, AcDb::kForRead);
	es = pSrcRc.openStatus();
	if (Acad::eOk != es)
		return es;

	AcDbBlockTablePointer pDestTbl(&m_DefDb, AcDb::kForWrite);
	es = pDestTbl.openStatus();
	if (Acad::eOk != es)
		return es;

	AcDbBlockTableRecord* pDestRc = NULL;
	AcDbIdMapping idMap;
	es = pSrcRc->deepClone(pDestTbl.object(), (AcDbObject*&)pDestRc, idMap, false);
	if (Acad::eOk != es)
		return es;

	pDestRc->close();
	pBlockRecord = pDestRc;
	return es;
}

Acad::ErrorStatus CGraphListCtrl::GetBlock3( LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord )
{
	AcDbBlockTableRecordPointer pBlkRc(szBlockName, m_pCurDb, AcDb::kForRead);
	pBlockRecord = pBlkRc.object();
	return pBlkRc.openStatus();
}

bool CGraphListCtrl::IsShowItemCaption() const
{
	return m_bShowCaption;
}

void CGraphListCtrl::EnableSel( bool bEnable )
{
	m_bAllowSel = bEnable;
}

bool CGraphListCtrl::IsEnableSel() const
{
	return m_bAllowSel;
}

void CGraphListCtrl::EnableDefault( bool bEnable )
{
	m_bAllowDefault = bEnable;
}

bool CGraphListCtrl::IsEnableDefault() const
{
	return m_bAllowDefault;
}

void CGraphListCtrl::SetTextColor( IN COLORREF color )
{
	m_colText = color;
}

COLORREF CGraphListCtrl::GetTextColor() const
{
	return m_colText;
}

void CGraphListCtrl::SetTextBkColor( IN COLORREF color )
{
	m_colTextBk = color;
}

COLORREF CGraphListCtrl::GetTextBkColor() const
{
	return m_colTextBk;
}

int CGraphListCtrl::GetTopColumnNum()
{
	int nHorzScroll = GetScrollPos32(SB_HORZ);
	CSize size = GetItemSizeWithCaption();
	return nHorzScroll / size.cx;
}

int CGraphListCtrl::GetTopRowNum()
{
	int nVertScroll = GetScrollPos32(SB_VERT);
	CSize size = GetItemSizeWithCaption();
	return nVertScroll / size.cy;
}

void CGraphListCtrl::ShowItemCaption( bool bShow /*= TRUE*/ )
{
	m_bShowCaption = bShow;
}

CGraphBlockViewWnd* CGraphListCtrl::CreateItem( AcGiDrawable* pDraw )
{
	CGraphBlockViewWnd* pItem = new CGraphBlockViewWnd;
	pItem->InitDrawable(pDraw);
	CreateItem(pItem);

	return pItem;
}

CGraphBlockViewWnd* CGraphListCtrl::CreateItem( LPCTSTR szBlockName )
{
	CGraphBlockViewWnd* pItem = new CGraphBlockViewWnd;
	pItem->InitBlockView(szBlockName, m_pCurDb);
	CreateItem(pItem);

	return pItem;
}

void CGraphListCtrl::CreateItem( CGraphBlockViewWnd* pItem )
{
	if( m_bSetUserView )
	{
		pItem->SetViewMode(m_nRenderMode);
		pItem->SetViewDir(m_viewVector);
	}

	CRect rect(CPoint(0, 0), GetItemSizeWithCaption());
	DWORD dwStyle = WS_CHILD | SS_NOTIFY;
	dwStyle &= ~WS_VISIBLE;
	pItem->Create(_T(""),dwStyle, rect,this);

	pItem->SetGraphList(this);
	pItem->EnableWindow(FALSE);
// 	pItem->ShowWindow(SW_HIDE);
// 	pItem->SetParent(this);
// 	pItem->MoveWindow(&rect);
	pItem->Zoom();

}

Acad::ErrorStatus CGraphListCtrl::InsertItem( int nItem, CGraphBlockViewWnd* pItem, LPCTSTR szTitleName, DWORD dwData )
{
	pItem->SetName(szTitleName);
	pItem->SetData(dwData);
	if(nItem >= GetItemCount())
	{
		m_arrayItem.Add(pItem);
	} 
	else
	{
		m_arrayItem.InsertAt(nItem, pItem);
	}

	ReDraw();
	return Acad::eOk;
}

Acad::ErrorStatus CGraphListCtrl::InsertItem( IN int nItem, IN AcDbObject* pEnt, IN LPCTSTR szTitleName /*= _T("")*/, DWORD dwData )
{
	CGraphBlockViewWnd* pItem = CreateItem(pEnt);
	return InsertItem(nItem, pItem, szTitleName, dwData);
}

Acad::ErrorStatus CGraphListCtrl::InsertItem(IN int nItem, IN LPCTSTR szBlockName, IN LPCTSTR szTitleName, DWORD dwData ) 
{
	CGraphBlockViewWnd* pItem = CreateItem(szBlockName);
	return InsertItem(nItem, pItem, szTitleName, dwData);
 #if 0
	if( m_pCurDb == NULL || m_hWnd == NULL ) return Acad::eNotApplicable;
	if(nItem < 0) nItem = 0;
	Acad::ErrorStatus es = Acad::eOk;

	AcDbBlockTableRecord* pBlockRecord = NULL;
	es = GetBlock(strBlockName, pBlockRecord);
	if (Acad::eOk != es)
		return es;

	es = InsertItem(nItem, pBlockRecord, strTitleName, dwData);
	if (Acad::eOk != es)
		return es;

	if (nItem >= m_arrayItem.GetSize())
	{
		nItem = m_arrayItem.GetSize() - 1;
	}

	CGraphBlockViewWnd* pItem = GetItem(nItem);
	if (NULL == pItem)
	{
		return Acad::eNotApplicable;
	}

	pItem->m_strBlockName = strBlockName;
	return es;
 #endif

}

BOOL CGraphListCtrl::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	OnScroll(nFlags, zDelta);
	return TRUE;
}

void CGraphListCtrl::OnScroll( UINT nFlags, short zDelta )
{
	int nBar = m_bSortByFixedRow ? SB_HORZ : SB_VERT;
	int nMaxPos = m_bSortByFixedRow ? m_nHScrollMax : m_nVScrollMax;
	int nMinPos = 0;

	int nScrolPos = GetScrollPos32(nBar);
	nScrolPos -= zDelta;
	if (0 > nScrolPos)
		nScrolPos = 0;
	else if (nMaxPos < nScrolPos)
		nScrolPos = nMaxPos;

	SetScrollPos32(nBar,  nScrolPos, TRUE);
	Invalidate();
}

void CGraphListCtrl::OnLButtonDown( UINT nFlags, CPoint point )
{
	SetFocus();
	CWnd::OnLButtonDown(nFlags, point);
}

int CGraphListCtrl::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	int hr = CWnd::OnCreate(lpCreateStruct);
	if (0 != hr)
		return hr;

	return hr;
}

CGraphTitleTip* CGraphListCtrl::GetTitleTip()
{
	if (IsWindow(m_hWnd) &&!IsWindow(m_TitleTip.m_hWnd))
	{
		m_TitleTip.Create(this);
	}
	
	return &m_TitleTip;
}

// CFont CGraphListCtrl::GetFont()
// {
// 	return m_fontCaption;
// }