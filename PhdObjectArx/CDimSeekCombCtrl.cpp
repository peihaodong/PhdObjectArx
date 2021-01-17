#include "StdAfx.h"
#include "CDimSeekCombCtrl.h"


//是为了确定运行时对象属于哪一个类而定义的宏
//.CPP文件中如果看见有IMPLEMENT_DYNAMIC，则在.H文件中必定有DECLARE_DYNAMIC的声明
IMPLEMENT_DYNAMIC(CDimSeekCombCtrl, CComboBox)

CDimSeekCombCtrl::CDimSeekCombCtrl(void)
{
	m_pEdit = NULL;
	m_bDimSeek = true;
}


CDimSeekCombCtrl::~CDimSeekCombCtrl(void)
{
	if (m_pEdit)
	{
		if (::IsWindow(m_hWnd))
		{
			m_pEdit->UnsubclassWindow();
		}
		delete m_pEdit;
		m_pEdit = NULL;
	}
}

int CDimSeekCombCtrl::AddString(LPCTSTR lpszString)
{
	m_arrString.Add(lpszString);
	return CComboBox::AddString(lpszString);
}

int CDimSeekCombCtrl::DeleteString(UINT nIndex)
{
	m_arrString.RemoveAt(nIndex);
	return CComboBox::DeleteString(nIndex);
}

int CDimSeekCombCtrl::InsertString(int nIndex, LPCTSTR lpszString)
{
	m_arrString.InsertAt(nIndex, lpszString);
	return CComboBox::InsertString(nIndex, lpszString);
}

void CDimSeekCombCtrl::ResetContent()
{
	m_arrString.RemoveAll();
	CComboBox::ResetContent();
}

BOOL CDimSeekCombCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (HIWORD(wParam) == EN_CHANGE)
	{
		if (m_bDimSeek)
			DimSeek();

		return true;
	}
	else
		return CComboBox::OnCommand(wParam, lParam);
}

void CDimSeekCombCtrl::DimSeek()
{
	if (m_pEdit == NULL)
	{
		m_pEdit = new CEdit();
		m_pEdit->SubclassWindow(GetDlgItem(1001)->GetSafeHwnd());
	}

	// 保存edit控件的状态
	CString strText;			//取得输入字符串
	int nStart = 0, nEnd = 0;	//取得光标位置
	m_pEdit->GetWindowText(strText);
	m_pEdit->GetSel(nStart, nEnd);

	CComboBox::ResetContent();//清空CComboBox里面的数据

	bool bFind = false;//是否有匹配项的标记
	if (!strText.IsEmpty())
	{
		//添加匹配项
		for (int nIndex = 0; nIndex < m_arrString.GetSize(); ++nIndex)
		{
			int nFindIndex = m_arrString[nIndex].Find(strText);
			if (nFindIndex == 0)
			{
				CComboBox::AddString(m_arrString[nIndex]);
				bFind = true;
			}
		}
	}

	if (GetCount() == 0)	//没有的话显示所有
	{
		for (int nIndex = 0; nIndex < m_arrString.GetSize(); ++nIndex)
		{
			CComboBox::AddString(m_arrString[nIndex]);
		}
	}

	//显示下拉列表
	if (!GetDroppedState())//下拉控件没打开就把它打开
	{
		::SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW))); // 设置用户光标
		ShowDropDown(TRUE);// 显示下拉框
	}

	if (bFind)
		SetCurSel(0);//有匹配项，选中第一个

	//设置选择项
	m_pEdit->SetWindowTextW(strText);
	m_pEdit->SetSel(nStart, nEnd);

	if (GetCount() >= 8 || GetCount() == 0)
		CComboBox::SetMinVisibleItems(8);//设置下拉列表可见项的最小个数
	else
		CComboBox::SetMinVisibleItems(GetCount());
}

BEGIN_MESSAGE_MAP(CDimSeekCombCtrl, CComboBox)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, &CDimSeekCombCtrl::OnCbnDropdown)
END_MESSAGE_MAP()


void CDimSeekCombCtrl::OnCbnDropdown()
{
	if (GetCount() >= 8 || GetCount() == 0)
		CComboBox::SetMinVisibleItems(8);//设置下拉列表可见项的最小个数
	else
		CComboBox::SetMinVisibleItems(GetCount());
}

void CDimSeekCombCtrl::SetDimSeek(bool bValue)
{
	m_bDimSeek = bValue;
}
