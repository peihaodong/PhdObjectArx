#include "StdAfx.h"
#include "PhdSysDlg.h"


void PhdSysDlg::AlertBox(LPCTSTR msg)
{
	AfxMessageBox(msg, MB_OK | MB_ICONEXCLAMATION);
}

void PhdSysDlg::StopAlertBox(LPCTSTR msg)
{
	AfxMessageBox(msg, MB_OK | MB_ICONSTOP);
}

void PhdSysDlg::PromptBox(LPCTSTR msg)
{
	AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
}

UINT PhdSysDlg::QuestionBox(LPCTSTR msg, UINT defButton /*= IDYES*/)
{
	UINT theDefault = (defButton == IDYES) ? MB_DEFBUTTON1 : MB_DEFBUTTON2;
	return(AfxMessageBox(msg, MB_YESNO | MB_ICONQUESTION | theDefault));
}

bool PhdSysDlg::getFileNameForRead(LPCTSTR prompt, LPCTSTR def, LPCTSTR ext, CString& fname, bool defIsDirectory /*= true*/, bool allowArbitraryExt /*= false*/)
{
	int flags = 2;          // disable the silly "type it" button
	if (false)
		flags += 1;
	if (allowArbitraryExt)
		flags += 4;     // enable arbitrary extension
	if (defIsDirectory)
		flags += 16;    // interpret default path as directory, not filename

	resbuf* rb = acutNewRb(RTSTR);
	rb->resval.rstring = NULL;

	short result = acedGetFileD(prompt, def, ext, flags, rb);

	if (result != RTNORM) 
	{
		acutRelRb(rb);
		return false;
	}
	else 
	{
		fname = rb->resval.rstring;
		acutRelRb(rb);
		return true;
	}
}

bool PhdSysDlg::getFileNameForWrite(LPCTSTR prompt, LPCTSTR def, LPCTSTR ext, CString& fname, bool defIsDirectory /*= true*/, bool allowArbitraryExt /*= false*/)
{
	int flags = 2;          // disable the silly "type it" button
	if (true)
		flags += 1;
	if (allowArbitraryExt)
		flags += 4;     // enable arbitrary extension
	if (defIsDirectory)
		flags += 16;    // interpret default path as directory, not filename

	resbuf* rb = acutNewRb(RTSTR);
	rb->resval.rstring = NULL;

	short result = acedGetFileD(prompt, def, ext, flags, rb);

	if (result != RTNORM)
	{
		acutRelRb(rb);
		return false;
	}
	else
	{
		fname = rb->resval.rstring;
		acutRelRb(rb);
		return true;
	}
}

bool PhdSysDlg::SelFileByDlg(const std::vector<CString>& vecFileType, CString& strPath)
{
	CString strType = _T("所有文件(*.*)|*.*||");
	for (int i = 0; i < vecFileType.size(); i++)
	{
		CString strTemp;
		strTemp.Format(_T("(*.%s)|*.%s|"), vecFileType[i], vecFileType[i]);
		strType.Insert(0, strTemp);
	}

	if (vecFileType.size() > 1)
	{
		CString strFront, strLast;
		strFront.Format(_T("(*.%s"), vecFileType[0]);
		strLast.Format(_T("*.%s"), vecFileType[0]);
		for (int i = 1; i < vecFileType.size(); i++)
		{
			CString strTemp;
			strTemp.Format(_T(";*.%s"), vecFileType[i]);
			strFront += strTemp;
			strLast += strTemp;
		}
		CString strSumExt = strFront + _T(")|") + strLast + _T("|");
		strType.Insert(0, strSumExt);
	}

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strType);//参数三：对话框打开所在位置
	if (IDOK != dlg.DoModal())
		return false;

	strPath = dlg.GetPathName();
	return true;
}

bool PhdSysDlg::SelDirByDlg(CString& strDirPath)
{
	CFolderPickerDialog fd(NULL, 0, NULL, 0);//参数二设置：OFN_ALLOWMULTISELECT  可以多选
	if (fd.DoModal() != IDOK)
		return false;

	strDirPath = fd.GetPathName();
	return true;
	/*
	参数：
	lpszFolder：初始目录
	dwFlags：个性化窗口标志位
	pParentWnd：父窗口句柄
	dwSize：The size of the OPENFILENAME structure.OPENFILENAME结构的大小
	*/
}

bool PhdSysDlg::SaveFileByDlg(CString& strSavePath, const std::vector<CString>& vecFileType, LPCTSTR szFileName /*= NULL*/)
{
	if (vecFileType.size() == 0)
		return false;
	CString strType = _T("|");
	for (int i = 0; i < vecFileType.size(); i++)
	{
		CString strTemp;
		strTemp.Format(_T("(*.%s)|*.%s|"), vecFileType[i], vecFileType[i]);
		strType.Insert(0, strTemp);
	}
	CFileDialog dlg(FALSE, NULL, szFileName, OFN_OVERWRITEPROMPT, strType);//参数二：指定文件扩展名； 参数三：指定默认文件名(输入绝对路径可以设置打开位置)
	if (IDOK != dlg.DoModal())
		return false;
	std::vector<CString> vecReverse;
	for (int i = vecFileType.size() - 1; i > -1; i--)
		vecReverse.push_back(vecFileType[i]);

	int nIndex = dlg.m_ofn.nFilterIndex;
	strSavePath = dlg.GetPathName();
	CString strFileExt = vecReverse[nIndex - 1];
	int nIndexFind = strSavePath.ReverseFind(_T('.'));
	if (nIndexFind == -1)
	{
		strFileExt.Insert(0, _T('.'));
		strSavePath += strFileExt;//文件完整路径
	}
	else
	{
		CString strRight = strSavePath.Right(strSavePath.GetLength() -nIndexFind-1);
		if (strRight.CompareNoCase(strFileExt) != 0)
		{
			strFileExt.Insert(0, _T('.'));
			strSavePath += strFileExt;//文件完整路径
		}
	}
	
	return true;
}

bool PhdSysDlg::SelFileByDlg(const std::vector<CString>& vecFileType, std::vector<CString>& vecFilePath)
{
	CString strType = _T("所有文件(*.*)|*.*||");
	for (int i = 0; i < vecFileType.size(); i++)
	{
		CString strTemp;
		strTemp.Format(_T("(*.%s)|*.%s|"), vecFileType[i], vecFileType[i]);
		strType.Insert(0, strTemp);
	}
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, strType);//参数三：对话框打开所在位置
	if (IDOK != dlg.DoModal())
		return false;

	POSITION pPos = dlg.GetStartPosition();//对于选择了多个文件的情况得到第一个文件位置
	while (pPos)
	{
		CString strFilePath = dlg.GetNextPathName(pPos);//对于选择了多个文件的情况得到下一个文件位置，同时返回当前文件名。
		vecFilePath.push_back(strFilePath);
	}
	return true;
}
