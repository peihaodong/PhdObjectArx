
#pragma once

#include "Afxtempl.h"
#include "GraphBlockViewWnd.h"
#include "GraphTitleTip.h"
#include "AcadVistualDeclare.h"


class   AedOrbitIcon : public AcGiDrawable
{
	AcGsNode* m_pNode;
	AcGsView* m_pAcGsView;
	AcDbEntity* m_pEnt;			// 真正显示的实体
public:

	AedOrbitIcon(): m_pAcGsView(NULL), m_pNode(NULL), m_pEnt(NULL) {}
	virtual ~AedOrbitIcon() {SetShowEnt(NULL);}
	void setGsView(AcGsView* pView) 
	{
		m_pAcGsView=pView;
	}

	AcGsView* gsView() {return m_pAcGsView;}

	void SetShowEnt(AcDbEntity* pEnt) 
	{
		if (NULL != m_pEnt)
		{
			AcDbEntityPointer pEntPtr;
			pEntPtr.acquire(m_pEnt);
		}

		m_pEnt = pEnt;
	}

public:
	_setAttributes;
	virtual Adesk::UInt32   subSetAttributes   (AcGiDrawableTraits * traits)
	{
		traits->setTrueColor (AcCmEntityColor(0,200,0));
		return kDrawableNone;
	}

public:
	_worldDraw;
	virtual Adesk::Boolean  subWorldDraw       (AcGiWorldDraw * wd)
	{

		//  		AcGsDCRect view_rect;
		//  		m_pAcGsView->getViewport (view_rect);
		//  
		//  		int nViewportX = (view_rect.m_max.x - view_rect.m_min.x) + 1;
		//  		int nViewportY = (view_rect.m_max.y - view_rect.m_min.y) + 1;
		//  		AcGeMatrix3d scale = m_pAcGsView->viewingMatrix() * m_pAcGsView->worldToDeviceMatrix().inverse();
		//  		AcGeVector3d viewDir = m_pAcGsView->target()-m_pAcGsView->position();
		// 
		//  		pViewportDraw->geometry().circle(m_pAcGsView->target(),radius,viewDir);

		if (NULL != m_pEnt)
		{
			double fScale = 0.2;

			AcDbEntity* pEnt = AcDbEntity::cast(m_pEnt->clone());
			pEnt->setDatabaseDefaults(m_pEnt->database());

			AcGsDCRect view_rect;
			m_pAcGsView->getViewport (view_rect);

			double fViewportX = (view_rect.m_max.x - view_rect.m_min.x);
			double fViewportY = (view_rect.m_max.y - view_rect.m_min.y);
			AcGeMatrix3d scale = m_pAcGsView->viewingMatrix() * m_pAcGsView->worldToDeviceMatrix().inverse();
			AcGeVector3d vecNormal = m_pAcGsView->position() - m_pAcGsView->target();
			AcGeVector3d vecUp = m_pAcGsView->upVector();
			fViewportX *= scale.scale() * 0.9;
			fViewportY *= scale.scale() * 0.9;

			vecUp.normalize();
			vecNormal.normalize();
			AcGeVector3d vecRight = vecUp.crossProduct(vecNormal);
			AcGePoint3d ptLeftDown = m_pAcGsView->target();
			ptLeftDown -= vecUp * fViewportY / 2;
			ptLeftDown -= vecRight * fViewportX / 2;

			AcDbExtents extents;
			pEnt->getGeomExtents(extents);

			AcGeMatrix3d mat;
			mat.setToAlignCoordSys(extents.minPoint(), AcGeVector3d::kXAxis, AcGeVector3d::kYAxis, AcGeVector3d::kZAxis, 
				ptLeftDown, vecRight, vecUp, vecNormal);

			fViewportX *= fScale;
			fViewportY *= fScale;
			double dXScale = (double)fViewportX / (extents.maxPoint().x - extents.minPoint().x);
			double dYScale = (double)fViewportY / (extents.maxPoint().y - extents.minPoint().y);
			AcGeMatrix3d matScale;
			matScale.setToScaling(min(dXScale, dYScale), ptLeftDown);

			Acad::ErrorStatus er = pEnt->transformBy(mat);
			er = pEnt->transformBy(matScale);

			pEnt->worldDraw(wd);

			delete pEnt;
		}

		return true;
	}

public:
	_viewportDraw;
	virtual void            subViewportDraw    (AcGiViewportDraw * pViewportDraw)
	{
	}
	// 	AcGeMatrix3d SetToTransform(const AcDbExtents& ext)
	// 	{
	// 
	// 		return mat;
	// 	}
	// 
	virtual Adesk::Boolean  isPersistent    (void) const
	{ 
		return Adesk::kFalse;
	};    

	virtual AcDbObjectId    id              (void) const
	{
		return AcDbObjectId::kNull;
	}

	virtual void            setGsNode       (AcGsNode * gsnode)
	{
		m_pNode = gsnode;
	}
	virtual AcGsNode*       gsNode          (void) const
	{
		return m_pNode;
	}

};






class CGraphButton;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Message

#define GRAPHCTRL_CLASSNAME    _T("MFCGraphListBlockCtrl")

class CGraphListCtrl;
class CGraphBlockViewWnd;

typedef CTypedPtrArray<CObArray, CGraphBlockViewWnd*> GRAPH_ITEM;

typedef struct {
	NMHDR hdr;
	int   nItem;	
} NM_GRAPHLIST;

class   CGraphListCtrl : public CWnd
{
	DECLARE_DYNCREATE(CGraphListCtrl)
public:
	CGraphListCtrl( );
	~CGraphListCtrl();
public:
	BOOL Create(const RECT& rect,
		CWnd* parent, 
		UINT nID,
		DWORD dwStyle = WS_CHILD   | WS_BORDER |
		WS_TABSTOP | WS_VISIBLE);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   显示标题
	void ShowItemCaption(bool bShow = true);
	bool IsShowItemCaption() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   将实体或块加入List
	Acad::ErrorStatus InsertItem(IN int nItem, IN LPCTSTR strBlockName, IN LPCTSTR szTitleName=_T(""), DWORD dwData = 0 );
	Acad::ErrorStatus InsertItem(IN int nItem, IN AcDbObject* pEnt, IN LPCTSTR lpszTitleName = _T(""), DWORD dwData = 0);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   总数
	int   GetItemCount();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   删除
	void  DeleteAllItem();
	void  DeleteItem(IN int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   选中
	void  SetCurSel(IN int nItem);
	int   GetCurSel();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   默认
	void SetDefault(IN int nItem);
	int GetDefault();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   编号与指针的转换
	CGraphBlockViewWnd* GetItem(IN int nItem);
	int GetItem(IN CGraphBlockViewWnd* pItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   附加数据
	void  SetItemData(IN int nItem, DWORD lParam);
	DWORD GetItemData(IN int nItem);

	void ReDraw( ); //pk 重合图形

	//设置布局：2*2；4*5
	void SetLayer( int nColumn, int nRow, int unused=0 );

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置选择
	void EnableSel(bool bEnable);
	bool IsEnableSel() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置默认
	void EnableDefault(bool bEnable);
	bool IsEnableDefault() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   重置默认图标
	void ResetDefaultIcon();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置默认图标
	void SetDefaultIcon(AcDbEntity* pEnt);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   为List绑定一个数据库
	void SetCurDatabase(AcDbDatabase* pDb);

	void SetSortByHorScroll(bool bSortByHor=false);	  //按水平方向摆放图

	void SetViewMode( AcGeVector3d viewVector,AcGsView::RenderMode nRenderMode=AcGsView::kGouraudShaded);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 绘制控制

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   背景颜色
	void SetTextBkColor(IN COLORREF color);
	COLORREF GetTextBkColor() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   文字颜色
	void SetTextColor(IN COLORREF color);
	COLORREF GetTextColor() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   背景色
	void  SetBkColor(IN COLORREF color);
	COLORREF GetBkColor();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   注册窗口类
	BOOL RegisterWindowClass(HINSTANCE hInstance = NULL);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   提示控件
	// Parameters: 
	// Returns:
	//   CGraphTitleTip*
	// ------------------------------------------------------------------------------------------------------------------------
	virtual CGraphTitleTip* GetTitleTip();
// 	CFont GetFont();
protected:
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   向父窗口发送消息
	LRESULT SendMessageToParent(IN int nItem, IN int nMessage);
	LRESULT SendCommandToParent(IN int nMessage);


	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   得到项的Rect
	CRect GetItemRect(IN int nItem);
	CRect GetItemRect(IN CGraphBlockViewWnd* pItem);
	int   GetItemByPoint(IN CPoint pt);

	void ResetScrollBars();
	void EnableScrollBars(int nBar, BOOL bEnable = TRUE);
	BOOL IsVisibleVScroll();
	BOOL IsVisibleHScroll();

	void OnSetCurSel(int nItem, bool bMsg = true);
	void OnDefaultChanged(int nOldItem, int nNewItem);

	void OnScroll(UINT nFlags, short zDelta);
protected:

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Message Map
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void PreSubclassWindow();

	
	DECLARE_MESSAGE_MAP()
private:
	virtual void  OnDraw(CDC* pDC);

	void CalItemSize();
	void  EraseBkgnd(CDC* pDC);
	void  DrawItem(CDC* pDC);
	void  DrawItem(CGraphBlockViewWnd* pWnd, CRect rc, int nType, CDC* pDC);
	void  DrawItem(int nItem, CDC* pDC);
	void  DrawItem(CGraphBlockViewWnd* pWnd);
	void  DrawItemCaption(IN CDC*    pDC,
		IN CRect   rt,
		IN CString strName,
		IN BOOL    bSel);
	void  DrawItemBackground(IN CDC* pDC,
		IN CRect rt,
		IN COLORREF color,
		IN int nType = 0); //0=正常；1=鼠标经过；2=当前选中；

	int   GetMinVisibleItem();
	int   GetMaxVisibleItem();
	int   GetTopColumnNum();
	int   GetTopRowNum();

	CRect GetVirtualRect();
	CSize GetItemSizeWithCaption();
	int   GetScrollPos32(int nBar, BOOL bGetTrackPos = FALSE);
	BOOL  SetScrollPos32(int nBar, int nPos, BOOL bRedraw = TRUE);

	void HideTip();
	void ShowTip(LPRECT rc, LPCTSTR szTitle, LPRECT rcBk);

	bool GetDefaultIconId(AcDbObjectId& id);

	Acad::ErrorStatus GetBlock(LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord);
	Acad::ErrorStatus GetBlock1(LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord);
	Acad::ErrorStatus GetBlock2(LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord);
	Acad::ErrorStatus GetBlock3(LPCTSTR szBlockName, AcDbBlockTableRecord*& pBlockRecord);

	CGraphBlockViewWnd* CreateItem(AcGiDrawable* pDraw);
	CGraphBlockViewWnd* CreateItem(LPCTSTR szBlockName);
	void CreateItem(CGraphBlockViewWnd* pItem);
	Acad::ErrorStatus InsertItem(int nItem, CGraphBlockViewWnd* pItem, LPCTSTR szTitleName, DWORD dwData);

private:
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 对数据进行整理
	// 首先是控件的控制数据
	bool		m_bAllowDefault;			// 是否允许设置默认项
	bool		m_bAllowSel;				// 是否允许选择
	bool		m_bShowCaption;				// 是否显示标题
	bool		m_bSortByFixedRow;			// 是否固定行，按列自由增减处理
	int			m_nCurSel;					// 当前选择项
	int			m_nCurDefault;				// 默认选项，绘制红旗标注，若没有设置为-1
	int			m_nBarState;

	// 控件的显示控制数据
	int			m_nFixedRowNum;				// 固定行数
	int			m_nFixedColNum;				// 固定列数

	CSize		m_sizeItem;					// 每项尺寸
	int			m_nCaptionHeight;
	int			m_nMargin;

	COLORREF	m_colBk;					// 背景色
	COLORREF	m_colText;					// 文字颜色
	COLORREF	m_colTextBk;				// 文字背景色
	CFont		m_font;

	// 用于控制tip的变量
	int			m_nMouseItem;
	int			m_nOldMouseItem;

	// 用于控制滚动条的变量
	int			m_nVScrollMax;
	int			m_nHScrollMax;

	// 成员
	CGraphTitleTip	m_TitleTip;
	GRAPH_ITEM		m_arrayItem;
	// 数据库
	AcDbDatabase* m_pCurDb;
	AcDbDatabase m_DefDb;

	// 控制Item的显示
	AcGsView::RenderMode	m_nRenderMode;
	AcGeVector3d			m_viewVector;
	bool					m_bSetUserView;

	AedOrbitIcon m_OrbitIcon;
	AcGsModel* m_pOrbitModel;

	CGraphButton* m_pOwnerBtn;
private:
	friend CGraphBlockViewWnd;
	friend class CGraphButton;
};


