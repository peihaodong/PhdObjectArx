#pragma once
#include "GraphListCtrl.h"
#include "Resize2.h"
#include "Icon2.h"
#define  CXTButton CButton

// CGraphButton
class   CGraphButton 
	: public CXTButton, public CXTResize
{
	DECLARE_DYNAMIC(CGraphButton)

public:
	CGraphButton();
	virtual ~CGraphButton();

public:
	void SetIcon(HICON hIcon);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   清理
	// Parameter: 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void Clear();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置每项图片的大小
	// Parameter: 
	//   int nWidth	- 
	//   int nHeight	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetItemSize(int nWidth, int nHeight);
	void SetItemSize(CSize size);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置显示的项的排布方式
	// Parameter: 
	//   int nCols	- 
	//   int nRows	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetLayer(int nCols, int nRows);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置当前数据库
	// Parameter: 
	//   AcDbDatabase * pDb	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetCurDatabase(AcDbDatabase* pDb);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   插入项
	// Parameter: 
	//   IN int nItem	- 
	//   IN CString strBlockName	- 
	//   IN CString strTitleName	- 
	// Returns:
	//   Acad::ErrorStatus
	// ------------------------------------------------------------------------------------------------------------------------
	Acad::ErrorStatus InsertListItem(IN int nItem, IN CString strBlockName, IN CString strTitleName=_T(""), DWORD dwData = 0 );
	Acad::ErrorStatus InsertListItem(IN int nItem, IN AcDbObject* pEnt, IN LPCTSTR lpszTitleName = _T(""), DWORD dwData = 0);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置选中项
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetCurSel(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   显示标题
	// Parameter: 
	//   bool bShow	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void ShowCaption(bool bShow = true);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   是否显示标题
	// Parameter: 
	// Returns:
	//   bool
	// ------------------------------------------------------------------------------------------------------------------------
	bool IsCaptionShow();
public:
	int GetListCurSel();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   得到指定项的名称
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CString，如果没有，返回空字符串
	// ------------------------------------------------------------------------------------------------------------------------
	CString GetListItemTitle(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   得到选中项
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CGraphBlockViewWnd*
	// ------------------------------------------------------------------------------------------------------------------------
	CGraphBlockViewWnd* GetItem(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   得到附加数据
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   DWORD
	// ------------------------------------------------------------------------------------------------------------------------
	DWORD GetItemData(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   设置附加数据
	// Parameter: 
	//   int nItem	- 
	//   DWORD dwData	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetItemData(int nItem, DWORD dwData);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   返回块名，如果没有，返回空串
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CString
	// ------------------------------------------------------------------------------------------------------------------------
	CString GetListItemBlockName(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   得到项数
	// Parameter: 
	// Returns:
	//   int
	// ------------------------------------------------------------------------------------------------------------------------
	int GetItemCount();

	CGraphBlockViewWnd* GetGraphWnd() {return &m_showCtrl;};

public:
	void OnListClick(int nSel, int nNewSel, bool bMsg = true);
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();

	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual void PreSubclassWindow();
	virtual void PostNcDestroy();

	void InterceptParentWndProc();
	void UnInterceptParentWndProc();

	void ShowList();
	void HideList();

protected:
	static LRESULT CALLBACK ParentWindowProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
	static BOOL IsMsgOK(HWND hWnd, UINT nMsg, LPARAM lParam);
	static BOOL HideTip(HWND hWnd, UINT nMsg, LPARAM lParam);
	static BOOL KeepFocus(HWND hWnd, UINT nMsg, LPARAM lParam);
	static WNDPROC m_parentWndProc;
	static int m_nTimes;

	static CGraphButton* m_pActiveBtn;
private:
	CSize m_sizeItem;
	CPoint m_ptList;
	int m_nColCount;
	int m_nRowCount;

	int m_nGrip;
	int m_nBtnWid;
	int m_nIconSize;

	CGraphListCtrl m_listCtrl;
	CGraphBlockViewWnd m_showCtrl;

	CWnd* m_pParentWnd;

	CXTPImageManagerIconHandle m_icon;
};

