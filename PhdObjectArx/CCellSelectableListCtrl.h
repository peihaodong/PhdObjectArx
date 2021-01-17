#pragma once

//单击选中单元格
class CCellSelectableListCtrl : public CListCtrl
{
public:
	CCellSelectableListCtrl();
	~CCellSelectableListCtrl();
	void SelectSubItem(int nItem, int nSubItem);
protected:
	int        m_nSelItem;
	int        m_nSelSubItem;

	virtual void PreSubclassWindow();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

