#if !defined(EDITABLELIST)
#define  EDITABLELIST

#pragma once
#include <zacuilistctrl.h>
//#include "resource.h"

#define IDC_LIST_EDITBOX 0xffff
#define MSG_ITEMCHANGED  (WM_USER+222)

//˫���༭��Ԫ��
class CEditableListCtrl :public CListCtrl
{
protected:

public:
	CEditableListCtrl();
	virtual~CEditableListCtrl();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	CEdit m_editbox;
	int m_nRow;
	int m_nCol;

// 	COLORREF m_OddItemBkColor;//�����б�����ɫ
// 	COLORREF m_EvenItemBkColor;//ż���б�����ɫ
// 	COLORREF m_OddItemTextColor;//�������ı���ɫ
// 	COLORREF m_EvenItemTextColor;//ż�����ı���ɫ

	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point); 
	//�޸Ľ����¼�
	afx_msg BOOL OnNMSetfocusList(NMHDR *pNMHDR, LRESULT *pResult);

// 	//������ɫ���
// 	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(EDITABLELIST)





