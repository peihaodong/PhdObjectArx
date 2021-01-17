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
	//   ����
	// Parameter: 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void Clear();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ����ÿ��ͼƬ�Ĵ�С
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
	//   ������ʾ������Ų���ʽ
	// Parameter: 
	//   int nCols	- 
	//   int nRows	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetLayer(int nCols, int nRows);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ���õ�ǰ���ݿ�
	// Parameter: 
	//   AcDbDatabase * pDb	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetCurDatabase(AcDbDatabase* pDb);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ������
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
	//   ����ѡ����
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetCurSel(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ��ʾ����
	// Parameter: 
	//   bool bShow	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void ShowCaption(bool bShow = true);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �Ƿ���ʾ����
	// Parameter: 
	// Returns:
	//   bool
	// ------------------------------------------------------------------------------------------------------------------------
	bool IsCaptionShow();
public:
	int GetListCurSel();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �õ�ָ���������
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CString�����û�У����ؿ��ַ���
	// ------------------------------------------------------------------------------------------------------------------------
	CString GetListItemTitle(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �õ�ѡ����
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CGraphBlockViewWnd*
	// ------------------------------------------------------------------------------------------------------------------------
	CGraphBlockViewWnd* GetItem(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �õ���������
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   DWORD
	// ------------------------------------------------------------------------------------------------------------------------
	DWORD GetItemData(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ���ø�������
	// Parameter: 
	//   int nItem	- 
	//   DWORD dwData	- 
	// Returns:
	//   void
	// ------------------------------------------------------------------------------------------------------------------------
	void SetItemData(int nItem, DWORD dwData);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   ���ؿ��������û�У����ؿմ�
	// Parameter: 
	//   int nItem	- 
	// Returns:
	//   CString
	// ------------------------------------------------------------------------------------------------------------------------
	CString GetListItemBlockName(int nItem);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   �õ�����
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

