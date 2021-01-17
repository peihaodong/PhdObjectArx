#include "StdAfx.h"
#include "CDimSeekCombCtrl.h"


//��Ϊ��ȷ������ʱ����������һ���������ĺ�
//.CPP�ļ������������IMPLEMENT_DYNAMIC������.H�ļ��бض���DECLARE_DYNAMIC������
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

	// ����edit�ؼ���״̬
	CString strText;			//ȡ�������ַ���
	int nStart = 0, nEnd = 0;	//ȡ�ù��λ��
	m_pEdit->GetWindowText(strText);
	m_pEdit->GetSel(nStart, nEnd);

	CComboBox::ResetContent();//���CComboBox���������

	bool bFind = false;//�Ƿ���ƥ����ı��
	if (!strText.IsEmpty())
	{
		//���ƥ����
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

	if (GetCount() == 0)	//û�еĻ���ʾ����
	{
		for (int nIndex = 0; nIndex < m_arrString.GetSize(); ++nIndex)
		{
			CComboBox::AddString(m_arrString[nIndex]);
		}
	}

	//��ʾ�����б�
	if (!GetDroppedState())//�����ؼ�û�򿪾Ͱ�����
	{
		::SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW))); // �����û����
		ShowDropDown(TRUE);// ��ʾ������
	}

	if (bFind)
		SetCurSel(0);//��ƥ���ѡ�е�һ��

	//����ѡ����
	m_pEdit->SetWindowTextW(strText);
	m_pEdit->SetSel(nStart, nEnd);

	if (GetCount() >= 8 || GetCount() == 0)
		CComboBox::SetMinVisibleItems(8);//���������б�ɼ������С����
	else
		CComboBox::SetMinVisibleItems(GetCount());
}

BEGIN_MESSAGE_MAP(CDimSeekCombCtrl, CComboBox)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, &CDimSeekCombCtrl::OnCbnDropdown)
END_MESSAGE_MAP()


void CDimSeekCombCtrl::OnCbnDropdown()
{
	if (GetCount() >= 8 || GetCount() == 0)
		CComboBox::SetMinVisibleItems(8);//���������б�ɼ������С����
	else
		CComboBox::SetMinVisibleItems(GetCount());
}

void CDimSeekCombCtrl::SetDimSeek(bool bValue)
{
	m_bDimSeek = bValue;
}
