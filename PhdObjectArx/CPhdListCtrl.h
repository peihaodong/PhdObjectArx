#pragma once

//�������ԣ�
// View->Report��һ��Ϊ����
// Edit Labels->TRUE;    �ؼ�����������
// Always Show Selection->TRUE; ����ѡ�н���

//�б�ؼ�
class CPhdListCtrl :public CListCtrl
{
	DECLARE_DYNAMIC(CPhdListCtrl)

public:
	void SetDblClkEditFlag(bool bFlag);
	void SetSingleItemFlag(bool bFlag);
	
private:
	bool m_bDceFlag;	//˫���༭���
	bool m_bSiFlag;		//ѡ�񵥸���Ԫ��ı��

	int  m_nSelItem;
	int  m_nSelSubItem;

public:
	// Summary: 	�����б�ѡ�У�Always Show Selection->TRUE��
	bool SetItemSelected(int nIndexRow);

	//************************************
	// Summary: 	��������ɫ	(ͨ���ػ���Ϣ�����ã�Ŀǰ�к�ɫ����ɫ��Ĭ����ɫ��2��1��0)
	// Parameters: 	
	//    nIndexRow		- 	����������
	//    nColorIndex		- 	������ɫ�������Լ����ػ���Ϣ�����õģ�
	// Returns:   	
	//************************************
	bool SetItemBGColor(int nIndexRow, int nColorIndex);

	//************************************
	// Summary: 	�õ���ѡ�е�������
	// Parameters: 	
	// Returns:   	
	//************************************
	int GetSeledRow() const;
	AcArray<int> GetSelectedItems() const;

	//************************************
	// Summary: 	������
	// Parameters: 	
	//    nIndexRow		- 	����������
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

