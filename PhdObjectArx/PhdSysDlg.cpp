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
	CString strType = _T("�����ļ�(*.*)|*.*||");
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

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strType);//���������Ի��������λ��
	if (IDOK != dlg.DoModal())
		return false;

	strPath = dlg.GetPathName();
	return true;
}

bool PhdSysDlg::SelDirByDlg(CString& strDirPath)
{
	CFolderPickerDialog fd(NULL, 0, NULL, 0);//���������ã�OFN_ALLOWMULTISELECT  ���Զ�ѡ
	if (fd.DoModal() != IDOK)
		return false;

	strDirPath = fd.GetPathName();
	return true;
	/*
	������
	lpszFolder����ʼĿ¼
	dwFlags�����Ի����ڱ�־λ
	pParentWnd�������ھ��
	dwSize��The size of the OPENFILENAME structure.OPENFILENAME�ṹ�Ĵ�С
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
	CFileDialog dlg(FALSE, NULL, szFileName, OFN_OVERWRITEPROMPT, strType);//��������ָ���ļ���չ���� ��������ָ��Ĭ���ļ���(�������·���������ô�λ��)
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
		strSavePath += strFileExt;//�ļ�����·��
	}
	else
	{
		CString strRight = strSavePath.Right(strSavePath.GetLength() -nIndexFind-1);
		if (strRight.CompareNoCase(strFileExt) != 0)
		{
			strFileExt.Insert(0, _T('.'));
			strSavePath += strFileExt;//�ļ�����·��
		}
	}
	
	return true;
}

bool PhdSysDlg::SelFileByDlg(const std::vector<CString>& vecFileType, std::vector<CString>& vecFilePath)
{
	CString strType = _T("�����ļ�(*.*)|*.*||");
	for (int i = 0; i < vecFileType.size(); i++)
	{
		CString strTemp;
		strTemp.Format(_T("(*.%s)|*.%s|"), vecFileType[i], vecFileType[i]);
		strType.Insert(0, strTemp);
	}
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, strType);//���������Ի��������λ��
	if (IDOK != dlg.DoModal())
		return false;

	POSITION pPos = dlg.GetStartPosition();//����ѡ���˶���ļ�������õ���һ���ļ�λ��
	while (pPos)
	{
		CString strFilePath = dlg.GetNextPathName(pPos);//����ѡ���˶���ļ�������õ���һ���ļ�λ�ã�ͬʱ���ص�ǰ�ļ�����
		vecFilePath.push_back(strFilePath);
	}
	return true;
}
