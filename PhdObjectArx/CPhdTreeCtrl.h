#pragma once

// Has buttons->TRUE;			�ڵ�� + -
// Has lines->TRUE;				�ڵ���������
// Track Select->TRUE;			��׷��(ѡ��ʱ����ɫ)
// Always Show Selection->TRUE; ����ѡ�н���Ĺؼ�
// Edit Labels->TRUE;			�ؼ�����������

//���ؼ�
class CPhdTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CPhdTreeCtrl)

public:
	//************************************
	// Summary: 	�õ��ڵ����
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	//************************************
	int GetItemDepth(HTREEITEM hItem) const;

	//************************************
	// Summary: 	�õ��ڵ�·��
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	// Explain:		·���������'\\'
	//************************************
	CString GetItemPath(HTREEITEM hItem) const;

	//************************************
	// Summary: 	�õ��ڵ������е��ӽڵ�item
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	//************************************
	AcArray<HTREEITEM> GetAllChildItem(HTREEITEM hItem) const;

	//************************************
	// Summary: 	�õ����еĽڵ�(�ݹ�)
	// Parameters: 	
	// Returns:   	
	//************************************
	AcArray<HTREEITEM> GetAllItems() const;

	//************************************
	// Summary: 	�õ��ڵ������е��ӽڵ�����
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	//************************************
	AcArray<CString> GetAllChildName(HTREEITEM hItem) const;

	// Summary:   �õ������ֵܽڵ������
	// Time:	  2019��10��28��
	// Explain:	  
	AcArray<CString> GetOthersSiblingName(HTREEITEM hItem) const;

	//************************************
	// Summary: 	���ýڵ㱻ѡ�У�Always Show Selection->TRUE��
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	//************************************
	bool SetItemSelected(HTREEITEM hItem);

	//************************************
	// Summary: 	�ڵ���������Edit Labels->TRUE��
	// Parameters: 	
	//    hItem		- 	����ڵ�ָ��
	// Returns:   	
	//************************************
	bool Rename(HTREEITEM hItem);

	//************************************
	// Summary: 	ͨ���ļ���·����ʼ�����ؼ�
	// Parameters: 	
	//    strDirPath		- 	�����ļ���·��
	//    hRoot		- 	�����Ŀ¼�ڵ�ָ��
	// Returns:   	
	//************************************
	BOOL InitTreeCtrlByDirPath(const CString& strDirPath, HTREEITEM hRoot);

	// Summary:   ͨ���ı��õ��ڵ���
	// Time:	  2019��11��20�� peihaodong
	// Explain:	  
	AcArray<HTREEITEM> GetItemsByText(LPCTSTR szText);

protected:

	void GetItemsByText(LPCTSTR szText,HTREEITEM hParent,AcArray<HTREEITEM>& arrItem);

	//************************************
	// Summary: 	�õ���ǰ������λ�õĽڵ�ָ�룬������ڽڵ��ϣ��򷵻�NULLָ��
	// Parameters: 	
	// Returns:   	
	//************************************
	HTREEITEM GetItemByCurPoint();

	//************************************
	// Summary: 	�õ��ڵ������еĽڵ�item(�ݹ�)
	// Parameters: 	
	//    arrItem		- 	����ڵ������е��ӽڵ�
	//    hItem		- 	�������ӽڵ�Ľڵ�item
	// Returns:   	
	//************************************
	void GetAllItems(AcArray<HTREEITEM>& arrItem, HTREEITEM hItem) const;
private:


	//////////////////////////////////////////////////////////////////////////
public:
	CPhdTreeCtrl();
	~CPhdTreeCtrl();

public:
	DECLARE_MESSAGE_MAP()

	afx_msg BOOL OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
};

