#pragma once

// Has buttons->TRUE;			节点带 + -
// Has lines->TRUE;				节点线连起来
// Track Select->TRUE;			热追踪(选中时亮蓝色)
// Always Show Selection->TRUE; 设置选中焦点的关键
// Edit Labels->TRUE;			控件可以重命名

//树控件
class CPhdTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CPhdTreeCtrl)

public:
	//************************************
	// Summary: 	得到节点深度
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	//************************************
	int GetItemDepth(HTREEITEM hItem) const;

	//************************************
	// Summary: 	得到节点路径
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	// Explain:		路径最后会带有'\\'
	//************************************
	CString GetItemPath(HTREEITEM hItem) const;

	//************************************
	// Summary: 	得到节点下所有的子节点item
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	//************************************
	AcArray<HTREEITEM> GetAllChildItem(HTREEITEM hItem) const;

	//************************************
	// Summary: 	得到所有的节点(递归)
	// Parameters: 	
	// Returns:   	
	//************************************
	AcArray<HTREEITEM> GetAllItems() const;

	//************************************
	// Summary: 	得到节点下所有的子节点名称
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	//************************************
	AcArray<CString> GetAllChildName(HTREEITEM hItem) const;

	// Summary:   得到其他兄弟节点的名称
	// Time:	  2019年10月28日
	// Explain:	  
	AcArray<CString> GetOthersSiblingName(HTREEITEM hItem) const;

	//************************************
	// Summary: 	设置节点被选中（Always Show Selection->TRUE）
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	//************************************
	bool SetItemSelected(HTREEITEM hItem);

	//************************************
	// Summary: 	节点重命名（Edit Labels->TRUE）
	// Parameters: 	
	//    hItem		- 	输入节点指针
	// Returns:   	
	//************************************
	bool Rename(HTREEITEM hItem);

	//************************************
	// Summary: 	通过文件夹路径初始化树控件
	// Parameters: 	
	//    strDirPath		- 	输入文件夹路径
	//    hRoot		- 	输入根目录节点指针
	// Returns:   	
	//************************************
	BOOL InitTreeCtrlByDirPath(const CString& strDirPath, HTREEITEM hRoot);

	// Summary:   通过文本得到节点项
	// Time:	  2019年11月20日 peihaodong
	// Explain:	  
	AcArray<HTREEITEM> GetItemsByText(LPCTSTR szText);

protected:

	void GetItemsByText(LPCTSTR szText,HTREEITEM hParent,AcArray<HTREEITEM>& arrItem);

	//************************************
	// Summary: 	得到当前点所在位置的节点指针，如果不在节点上，则返回NULL指针
	// Parameters: 	
	// Returns:   	
	//************************************
	HTREEITEM GetItemByCurPoint();

	//************************************
	// Summary: 	得到节点下所有的节点item(递归)
	// Parameters: 	
	//    arrItem		- 	输出节点下所有的子节点
	//    hItem		- 	输入有子节点的节点item
	// Returns:   	
	//************************************
	void GetAllItems(AcArray<HTREEITEM>& arrItem, HTREEITEM hItem) const;
private:
	std::shared_ptr<Phd::PhdArxMethod> m_apPhdArxMethod;

	//////////////////////////////////////////////////////////////////////////
public:
	CPhdTreeCtrl();
	~CPhdTreeCtrl();

public:
	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
};

