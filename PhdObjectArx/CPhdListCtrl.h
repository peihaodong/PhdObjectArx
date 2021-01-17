#pragma once

//设置属性：
// View->Report；一般为报表
// Edit Labels->TRUE;    控件可以重命名
// Always Show Selection->TRUE; 设置选中焦点

//列表控件
class CPhdListCtrl :public CListCtrl
{
	DECLARE_DYNAMIC(CPhdListCtrl)

public:
	void SetDblClkEditFlag(bool bFlag);
	void SetSingleItemFlag(bool bFlag);
	
private:
	bool m_bDceFlag;	//双击编辑标记
	bool m_bSiFlag;		//选择单个单元格的标记

	int  m_nSelItem;
	int  m_nSelSubItem;

public:
	// Summary: 	设置行被选中（Always Show Selection->TRUE）
	bool SetItemSelected(int nIndexRow);

	//************************************
	// Summary: 	设置行颜色	(通过重绘消息来设置，目前有红色、蓝色、默认颜色：2、1、0)
	// Parameters: 	
	//    nIndexRow		- 	输入行索引
	//    nColorIndex		- 	输入颜色索引（自己在重绘消息中设置的）
	// Returns:   	
	//************************************
	bool SetItemBGColor(int nIndexRow, int nColorIndex);

	//************************************
	// Summary: 	得到被选中的行索引
	// Parameters: 	
	// Returns:   	
	//************************************
	int GetSeledRow() const;
	AcArray<int> GetSelectedItems() const;

	//************************************
	// Summary: 	重命名
	// Parameters: 	
	//    nIndexRow		- 	输入行索引
	// Returns:   	
	//************************************
	bool Rename(int nIndexRow);


	//////////////////////////////////////////////////////////////////////////
public:
	CPhdListCtrl();
	~CPhdListCtrl();

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg BOOL OnLvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
};

