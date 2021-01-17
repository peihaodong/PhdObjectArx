#pragma once


class CDimSeekCombCtrl : public CComboBox
{
	//是为了确定运行时对象属于哪一个类而定义的宏
	//.CPP文件中如果看见有IMPLEMENT_DYNAMIC，则在.H文件中必定有DECLARE_DYNAMIC的声明
	DECLARE_DYNAMIC(CDimSeekCombCtrl)

public:
	CDimSeekCombCtrl(void);
	~CDimSeekCombCtrl(void);

	int AddString(LPCTSTR lpszString);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszString);
	void ResetContent();

	void SetDimSeek(bool bValue);//是否开启模糊搜索

protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);//处理命令消息的消息映射

private:
	void DimSeek();//模糊搜索功能的编写

private:
	CEdit* m_pEdit;//编辑控件指针
	CStringArray m_arrString;//组合控件的字符串集合
	bool m_bDimSeek;//是否开启模糊搜索的标记

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnDropdown();//处于下拉状态时触发
};
