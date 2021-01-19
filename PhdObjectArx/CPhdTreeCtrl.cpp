#include "StdAfx.h"
#include "CPhdTreeCtrl.h"


IMPLEMENT_DYNAMIC(CPhdTreeCtrl, CTreeCtrl)

CPhdTreeCtrl::CPhdTreeCtrl()
	:m_apPhdArxMethod(std::make_shared<Phd::PhdArxMethod>())
{
}


CPhdTreeCtrl::~CPhdTreeCtrl()
{
}

int CPhdTreeCtrl::GetItemDepth(HTREEITEM hItem) const
{
	int i = 0;
	while (hItem)
	{
		hItem = GetParentItem(hItem);
		i++;
	}
	return i;
}

CString CPhdTreeCtrl::GetItemPath(HTREEITEM hItem) const
{
	CString str;
	while (hItem)
	{
		str = GetItemText(hItem) + _T('\\') + str;
		hItem = GetParentItem(hItem);
	}

// 	int nIndex = str.ReverseFind(_T('\\'));
// 	if (nIndex != -1)
// 		str = str.Left(nIndex);
	
	return str;
}

AcArray<HTREEITEM> CPhdTreeCtrl::GetAllChildItem(HTREEITEM hItem) const
{
	AcArray<HTREEITEM> arrItem;
	if (!ItemHasChildren(hItem))
		return arrItem;

	HTREEITEM hChildItem = GetChildItem(hItem);
	while (hChildItem != NULL)
	{
		arrItem.append(hChildItem);
		hChildItem = GetNextSiblingItem(hChildItem);
	}
	return arrItem;
}

void CPhdTreeCtrl::GetAllItems(AcArray<HTREEITEM>& arrItem, HTREEITEM hItem) const
{
	HTREEITEM hChildItem = GetChildItem(hItem);
	while (hChildItem != NULL)
	{
		arrItem.append(hChildItem);
		if (ItemHasChildren(hChildItem))
			GetAllItems(arrItem,hChildItem);
		hChildItem = GetNextSiblingItem(hChildItem);
	}
}

AcArray<HTREEITEM> CPhdTreeCtrl::GetAllItems() const
{
	AcArray<HTREEITEM> arrItem;
	HTREEITEM hItem = GetRootItem();
	while (hItem != NULL)
	{
		arrItem.append(hItem);
		GetAllItems(arrItem, hItem);
		hItem = GetNextSiblingItem(hItem);
	}
	return arrItem;
}

AcArray<CString> CPhdTreeCtrl::GetAllChildName(HTREEITEM hItem) const
{
	AcArray<CString> arrName;
	if (!ItemHasChildren(hItem))
		return arrName;

	HTREEITEM hChildItem = GetChildItem(hItem);
	while (hChildItem != NULL)
	{
		arrName.append(GetItemText(hChildItem));
		hChildItem = GetNextSiblingItem(hChildItem);
	}
	return arrName;
}

AcArray<CString> CPhdTreeCtrl::GetOthersSiblingName(HTREEITEM hItem) const
{
	HTREEITEM hParent = GetParentItem(hItem);
	AcArray<CString> arrText;
	if (!hParent)
		return arrText;
	AcArray<HTREEITEM> arrItem = GetAllChildItem(hParent);
	for (int i = 0; i < arrItem.length(); i++)
	{
		if (hItem == arrItem[i])
			continue;
		arrText.append(GetItemText(arrItem[i]));
	}
	return arrText;
}

bool CPhdTreeCtrl::SetItemSelected(HTREEITEM hItem)
{
	if (!hItem)
		return false;

	SelectItem(hItem);
	SetItemState(hItem, LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
	SetFocus();
	return true;
}

bool CPhdTreeCtrl::Rename(HTREEITEM hItem)
{
	if (!hItem)
		return false;

	SetFocus();
	CEdit* pmyEdit = EditLabel(hItem);
	ASSERT(pmyEdit != NULL);
	
	return true;
}

BOOL CPhdTreeCtrl::InitTreeCtrlByDirPath(const CString& strDirPath, HTREEITEM hRoot)
{
	BOOL bRet = ::PathIsDirectory(strDirPath);//判断路径是不是文件夹
	if (!bRet)
		return FALSE;

	CFileFind ff;
	CString szPathAll = strDirPath;
	szPathAll += _T("\\*.*");
	BOOL b = ff.FindFile(szPathAll);
	if (!b)
		return FALSE;

	int i = 0;
	while (b)
	{
		b = ff.FindNextFileW();
		if (ff.IsDots())
			continue;
		if (ff.IsDirectory())
		{
			HTREEITEM hItem;
			hItem = InsertItem(ff.GetFileName(), hRoot);
			InitTreeCtrlByDirPath(ff.GetFilePath(), hItem);
		}
		else
		{
			InsertItem(ff.GetFileName(), hRoot);
		}
		Expand(hRoot, TVE_EXPAND);
		i++;
	}
	ff.Close();

	return TRUE;
}

AcArray<HTREEITEM> CPhdTreeCtrl::GetItemsByText(LPCTSTR szText)
{
	AcArray<HTREEITEM> arrItem;
	HTREEITEM hRoot = GetRootItem();
	if (ItemHasChildren(hRoot))
	{
		GetItemsByText(szText, hRoot, arrItem);
	}
	return arrItem;
}

void CPhdTreeCtrl::GetItemsByText(LPCTSTR szText, HTREEITEM hParent, AcArray<HTREEITEM>& arrItem)
{
	CString strText = GetItemText(hParent);
	int nFindIndex = strText.Find(szText);
	if (nFindIndex == 0)
		arrItem.append(hParent);

	HTREEITEM hChildItem = GetChildItem(hParent);
	while (hChildItem != NULL)
	{
		if (ItemHasChildren(hChildItem))
		{
			GetItemsByText(szText, hChildItem, arrItem);
		}
		else
		{
			strText = GetItemText(hChildItem);
			nFindIndex = strText.Find(szText);
			if (nFindIndex == 0)
				arrItem.append(hChildItem);
		}
		hChildItem = GetNextSiblingItem(hChildItem);
	}
}

HTREEITEM CPhdTreeCtrl::GetItemByCurPoint()
{
	SetFocus();
	CPoint point;
	GetCursorPos(&point);
	ScreenToClient(&point);//屏幕坐标转换为客户端坐标
	UINT flag;
	return HitTest(point, &flag);//得到当前点所在位置的节点指针，如果不在节点上，则返回NULL指针
	//SelectItem(selectItem);//用这个函数使节点被选中，如果指针为NULL，则什么都不选
}

BEGIN_MESSAGE_MAP(CPhdTreeCtrl, CTreeCtrl)
	ON_NOTIFY_REFLECT_EX(TVN_ENDLABELEDIT, &CPhdTreeCtrl::OnTvnEndlabeledit)
END_MESSAGE_MAP()


BOOL CPhdTreeCtrl::OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	*pResult = 0;

	TV_ITEM* ptvItem = &pTVDispInfo->item;
	CString LabelStr = ptvItem->pszText;  // 获取修改后的名称

	HTREEITEM curItem = ptvItem->hItem;
	if (!curItem)
		return FALSE;
	CString strLastText = GetItemText(curItem);//获取修改前的名称
	

	if (LabelStr == _T(""))  // 对新输入的名称作一些限制  
		LabelStr = strLastText;

	// 设置新名称  
	AcArray<CString> arrText = GetOthersSiblingName(curItem);

	if (arrText.contains(LabelStr))
	{
		CString strNewText;
		CString strTemp = LabelStr;
		while (true)
		{
			strNewText = m_apPhdArxMethod->GetUniqueName(strTemp);
			if (!arrText.contains(strNewText))
			{
				SetItemText(curItem, strNewText);
				break;
			}
			strTemp = strNewText;
		}
	}
	else
		SetItemText(curItem, LabelStr);

	return FALSE;//返回FALSE可以让父窗口进行进一步的处理
}
