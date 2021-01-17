
#pragma once

#include "Afxtempl.h"
#include "GraphBlockViewWnd.h"
#include "GraphTitleTip.h"
#include "AcadVistualDeclare.h"


class   AedOrbitIcon : public AcGiDrawable
{
	AcGsNode* m_pNode;
	AcGsView* m_pAcGsView;
	AcDbEntity* m_pEnt;			// ������ʾ��ʵ��
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
	//   ��ʾ����
	void ShowItemCaption(bool bShow = true);
	bool IsShowItemCaption() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ��ʵ�������List
	Acad::ErrorStatus InsertItem(IN int nItem, IN LPCTSTR strBlockName, IN LPCTSTR szTitleName=_T(""), DWORD dwData = 0 );
	Acad::ErrorStatus InsertItem(IN int nItem, IN AcDbObject* pEnt, IN LPCTSTR lpszTitleName = _T(""), DWORD dwData = 0);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����
	int   GetItemCount();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ɾ��
	void  DeleteAllItem();
	void  DeleteItem(IN int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ѡ��
	void  SetCurSel(IN int nItem);
	int   GetCurSel();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   Ĭ��
	void SetDefault(IN int nItem);
	int GetDefault();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �����ָ���ת��
	CGraphBlockViewWnd* GetItem(IN int nItem);
	int GetItem(IN CGraphBlockViewWnd* pItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ��������
	void  SetItemData(IN int nItem, DWORD lParam);
	DWORD GetItemData(IN int nItem);

	void ReDraw( ); //pk �غ�ͼ��

	//���ò��֣�2*2��4*5
	void SetLayer( int nColumn, int nRow, int unused=0 );

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����ѡ��
	void EnableSel(bool bEnable);
	bool IsEnableSel() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����Ĭ��
	void EnableDefault(bool bEnable);
	bool IsEnableDefault() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����Ĭ��ͼ��
	void ResetDefaultIcon();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����Ĭ��ͼ��
	void SetDefaultIcon(AcDbEntity* pEnt);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ΪList��һ�����ݿ�
	void SetCurDatabase(AcDbDatabase* pDb);

	void SetSortByHorScroll(bool bSortByHor=false);	  //��ˮƽ����ڷ�ͼ

	void SetViewMode( AcGeVector3d viewVector,AcGsView::RenderMode nRenderMode=AcGsView::kGouraudShaded);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ���ƿ���

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ������ɫ
	void SetTextBkColor(IN COLORREF color);
	COLORREF GetTextBkColor() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ������ɫ
	void SetTextColor(IN COLORREF color);
	COLORREF GetTextColor() const;

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����ɫ
	void  SetBkColor(IN COLORREF color);
	COLORREF GetBkColor();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ע�ᴰ����
	BOOL RegisterWindowClass(HINSTANCE hInstance = NULL);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ��ʾ�ؼ�
	// Parameters: 
	// Returns:
	//   CGraphTitleTip*
	// ------------------------------------------------------------------------------------------------------------------------
	virtual CGraphTitleTip* GetTitleTip();
// 	CFont GetFont();
protected:
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �򸸴��ڷ�����Ϣ
	LRESULT SendMessageToParent(IN int nItem, IN int nMessage);
	LRESULT SendCommandToParent(IN int nMessage);


	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �õ����Rect
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
		IN int nType = 0); //0=������1=��꾭����2=��ǰѡ�У�

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
	// �����ݽ�������
	// �����ǿؼ��Ŀ�������
	bool		m_bAllowDefault;			// �Ƿ���������Ĭ����
	bool		m_bAllowSel;				// �Ƿ�����ѡ��
	bool		m_bShowCaption;				// �Ƿ���ʾ����
	bool		m_bSortByFixedRow;			// �Ƿ�̶��У�����������������
	int			m_nCurSel;					// ��ǰѡ����
	int			m_nCurDefault;				// Ĭ��ѡ����ƺ����ע����û������Ϊ-1
	int			m_nBarState;

	// �ؼ�����ʾ��������
	int			m_nFixedRowNum;				// �̶�����
	int			m_nFixedColNum;				// �̶�����

	CSize		m_sizeItem;					// ÿ��ߴ�
	int			m_nCaptionHeight;
	int			m_nMargin;

	COLORREF	m_colBk;					// ����ɫ
	COLORREF	m_colText;					// ������ɫ
	COLORREF	m_colTextBk;				// ���ֱ���ɫ
	CFont		m_font;

	// ���ڿ���tip�ı���
	int			m_nMouseItem;
	int			m_nOldMouseItem;

	// ���ڿ��ƹ������ı���
	int			m_nVScrollMax;
	int			m_nHScrollMax;

	// ��Ա
	CGraphTitleTip	m_TitleTip;
	GRAPH_ITEM		m_arrayItem;
	// ���ݿ�
	AcDbDatabase* m_pCurDb;
	AcDbDatabase m_DefDb;

	// ����Item����ʾ
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


