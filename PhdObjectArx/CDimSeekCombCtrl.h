#pragma once


class CDimSeekCombCtrl : public CComboBox
{
	//��Ϊ��ȷ������ʱ����������һ���������ĺ�
	//.CPP�ļ������������IMPLEMENT_DYNAMIC������.H�ļ��бض���DECLARE_DYNAMIC������
	DECLARE_DYNAMIC(CDimSeekCombCtrl)

public:
	CDimSeekCombCtrl(void);
	~CDimSeekCombCtrl(void);

	int AddString(LPCTSTR lpszString);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszString);
	void ResetContent();

	void SetDimSeek(bool bValue);//�Ƿ���ģ������

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);//����������Ϣ����Ϣӳ��

private:
	void DimSeek();//ģ���������ܵı�д

private:
	CEdit* m_pEdit;//�༭�ؼ�ָ��
	CStringArray m_arrString;//��Ͽؼ����ַ�������
	bool m_bDimSeek;//�Ƿ���ģ�������ı��

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnDropdown();//��������״̬ʱ����
};
