
#include "stdafx.h"
#include "GraphTitleTip.h"


CGraphTitleTip::CGraphTitleTip()
{
	// Register the window class if it has not already been registered.
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();
	if(!(::GetClassInfo(hInst, GRAPH_TITLETIP_CLASSNAME, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style			= CS_SAVEBITS;
		wndcls.lpfnWndProc		= ::DefWindowProc;
		wndcls.cbClsExtra		= wndcls.cbWndExtra = 0;
		wndcls.hInstance		= hInst;
		wndcls.hIcon			= NULL;
		wndcls.hCursor			= LoadCursor( hInst, IDC_ARROW );
		wndcls.hbrBackground	= (HBRUSH)(COLOR_INFOBK +1);
		wndcls.lpszMenuName		= NULL;
		wndcls.lpszClassName	= GRAPH_TITLETIP_CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
			AfxThrowResourceException();
	}

    m_dwLastLButtonDown = ULONG_MAX;
    m_dwDblClickMsecs = GetDoubleClickTime();
}

CGraphTitleTip::~CGraphTitleTip()
{
}


BEGIN_MESSAGE_MAP(CGraphTitleTip, CWnd)
	//{{AFX_MSG_MAP(CGraphTitleTip)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CGraphTitleTip message handlers

BOOL CGraphTitleTip::Create(CWnd * pParentWnd)
{
	ASSERT_VALID(pParentWnd);

	DWORD dwStyle = WS_BORDER | WS_POPUP; 
	DWORD dwExStyle = WS_EX_TOOLWINDOW | WS_EX_TOPMOST;
	m_pParentWnd = pParentWnd;

	return CreateEx(dwExStyle,
                    GRAPH_TITLETIP_CLASSNAME,
                    NULL,
                    dwStyle, 
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT, 
		            NULL,
                    NULL,
                    NULL );
}


// Show 		 - Show the titletip if needed
// rectTitle	 - The rectangle within which the original 
//				    title is constrained - in client coordinates
// lpszTitleText - The text to be displayed
// xoffset		 - Number of pixel that the text is offset from
//				   left border of the cell
void CGraphTitleTip::Show(LPRECT rcTitle, LPCTSTR lpszTitleText, int xoffset /*=0*/,
                     LPRECT lpHoverRect /*=NULL*/,
                     CFont* pFont /*=NULL*/,
                     COLORREF crTextClr /* CLR_DEFAULT */,
                     COLORREF crBackClr /* CLR_DEFAULT */)
{
	ASSERT( ::IsWindow( GetSafeHwnd() ) );

    if (!rcTitle)
        return;

	CRect rectTitle(rcTitle);
	if (rectTitle.IsRectEmpty())
	{
		return;
	}

	// If titletip is already displayed, don't do anything.
	if( IsWindowVisible() ) 
		return;

    m_rectHover = (lpHoverRect != NULL)? lpHoverRect : rectTitle;
    m_rectHover.right++; m_rectHover.bottom++;

	m_pParentWnd->ClientToScreen( m_rectHover );
    ScreenToClient( m_rectHover );

	// Do not display the titletip is app does not have focus
	if( GetFocus() == NULL )
		return;

	// Define the rectangle outside which the titletip will be hidden.
	// We add a buffer of one pixel around the rectangle
	m_rectTitle.top    = -1;
	m_rectTitle.left   = -xoffset-1;
	m_rectTitle.right  = rectTitle.Width() -xoffset;
	m_rectTitle.bottom = rectTitle.Height() +1;

	// Determine the width of the text
	m_pParentWnd->ClientToScreen( rectTitle );

	CClientDC dc(this);
	CString strTitle = _T("");
    strTitle += _T(" ");
    strTitle += lpszTitleText; 
    strTitle += _T(" ");

	CFont font, *pOldFont = NULL;
    if (pFont)
    {
	    pOldFont = dc.SelectObject( pFont );
    }
    else
    {
        // use same font as ctrl
		font.FromHandle((HFONT)::GetStockObject(SYSTEM_FONT));
		pOldFont = dc.SelectObject( &font);
    }

	CSize size = dc.GetTextExtent( strTitle );
	if(rectTitle.Height()<size.cy) rectTitle.top = rectTitle.bottom+size.cy;

    TEXTMETRIC tm;
    dc.GetTextMetrics(&tm);
    size.cx += tm.tmOverhang;

	CRect rectDisplay = rectTitle;
	rectDisplay.left += xoffset;
	rectDisplay.right = rectDisplay.left + size.cx + xoffset;
    
    // Do not display if the text fits within available space
    if ( rectDisplay.right > rectTitle.right-xoffset )
    {
        // Show the titletip
        SetWindowPos( &wndTop, rectDisplay.left, rectDisplay.top, 
            rectDisplay.Width(), rectDisplay.Height(), 
            SWP_SHOWWINDOW|SWP_NOACTIVATE );
        
        // FNA - handle colors correctly
        if (crBackClr != CLR_DEFAULT)
        {
		    CBrush backBrush(crBackClr);
		    CBrush* pOldBrush = dc.SelectObject(&backBrush);
		    CRect rect;
		    dc.GetClipBox(&rect);     // Erase the area needed 

		    dc.PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),  PATCOPY);
		    dc.SelectObject(pOldBrush);
	    }
        // Set color
        if (crTextClr != CLR_DEFAULT)//FNA
            dc.SetTextColor(crTextClr);//FA

        dc.SetBkMode( TRANSPARENT );
		dc.SetBkColor(::GetBkColor(::GetDC(0)));
        dc.TextOut( 0, 0, strTitle );
//         SetCapture();
    }
    
    dc.SelectObject( pOldFont );
}

void CGraphTitleTip::Hide()
{
  	if (!::IsWindow(GetSafeHwnd()))
        return;

    if (GetCapture()->GetSafeHwnd() == GetSafeHwnd())
        ReleaseCapture();

	ShowWindow( SW_HIDE );
}

void CGraphTitleTip::OnMouseMove(UINT nFlags, CPoint point) 
{
    // Forward the message
    ClientToScreen( &point );
    CWnd *pWnd = WindowFromPoint( point );
    if ( pWnd == this ) 
        pWnd = m_pParentWnd;
    
    int hittest = (int)pWnd->SendMessage(WM_NCHITTEST,0,MAKELONG(point.x,point.y));
    
    if (hittest == HTCLIENT) {
        pWnd->ScreenToClient( &point );
        pWnd->PostMessage( WM_MOUSEMOVE, nFlags, MAKELONG(point.x,point.y) );
    } else {
        pWnd->PostMessage( WM_NCMOUSEMOVE, hittest, MAKELONG(point.x,point.y) );
    }
}

BOOL CGraphTitleTip::PreTranslateMessage(MSG* pMsg) 
{
    // Used to qualify WM_LBUTTONDOWN messages as double-clicks
    DWORD dwTick=0;
    BOOL bDoubleClick=FALSE;

    CWnd *pWnd;
	int hittest;
	switch (pMsg->message)
	{
	case WM_LBUTTONDOWN:
       // Get tick count since last LButtonDown
        dwTick = GetTickCount();
        bDoubleClick = ((dwTick - m_dwLastLButtonDown) <= m_dwDblClickMsecs);
        m_dwLastLButtonDown = dwTick;
        // NOTE: DO NOT ADD break; STATEMENT HERE! Let code fall through

	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
        {
            POINTS pts = MAKEPOINTS( pMsg->lParam );
		    POINT  point;
		    point.x = pts.x;
		    point.y = pts.y;
		    ClientToScreen( &point );
		    pWnd = WindowFromPoint( point );
		    if( pWnd == this ) 
			    pWnd = m_pParentWnd;

		    hittest = (int)pWnd->SendMessage(WM_NCHITTEST,0,MAKELONG(point.x,point.y));

		    if (hittest == HTCLIENT) {
			    pWnd->ScreenToClient( &point );
			    pMsg->lParam = MAKELONG(point.x,point.y);
		    } else {
			    switch (pMsg->message) {
			    case WM_LBUTTONDOWN: 
				    pMsg->message = WM_NCLBUTTONDOWN;
				    break;
			    case WM_RBUTTONDOWN: 
				    pMsg->message = WM_NCRBUTTONDOWN;
				    break;
			    case WM_MBUTTONDOWN: 
				    pMsg->message = WM_NCMBUTTONDOWN;
				    break;
			    }
			    pMsg->wParam = hittest;
			    pMsg->lParam = MAKELONG(point.x,point.y);
		    }

            Hide();

            // If this is the 2nd WM_LBUTTONDOWN in x milliseconds,
            // post a WM_LBUTTONDBLCLK message instead of a single click.
            pWnd->PostMessage(  bDoubleClick ? WM_LBUTTONDBLCLK : pMsg->message,
                                pMsg->wParam,
                                pMsg->lParam);
		    return TRUE;	
        }
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
        Hide();
		m_pParentWnd->PostMessage( pMsg->message, pMsg->wParam, pMsg->lParam );
		return TRUE;
	}

	if( GetFocus() == NULL )
	{
        Hide();
		return TRUE;
	}

	return CWnd::PreTranslateMessage(pMsg);
}
