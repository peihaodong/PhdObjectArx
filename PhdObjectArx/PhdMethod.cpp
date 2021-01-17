#include "StdAfx.h"
#include "PhdMethod.h"
#include <TlHelp32.h>
#include "PhdInline.h"
// #include "PhdDimStyle.h"
// #include "PhdGroup.h"
// #include "PhdLayer.h"
// #include "PhdLinetype.h"
// #include "PhdTextStyle.h"
// #include "PhdBlock.h"


#pragma region �ڲ�����
void PhdMethod::StringAdded(int nSum, CString& FinalStr, int divisionValue,
	int SingleTransValue, int LastTransValue)
{
	int quotientNum = nSum / (divisionValue + 1);
	int remainderNum = nSum % (divisionValue + 1);
	TCHAR newStr = TCHAR(remainderNum + SingleTransValue);//��λ�ַ�
	FinalStr.Insert(0, newStr);
	if (quotientNum == 0)
	{
		return;
	}
	else if (0 < quotientNum && quotientNum <= divisionValue)
	{
		newStr = TCHAR(quotientNum + LastTransValue);//ǰλ�ַ�
		FinalStr.Insert(0, newStr);
	}
	else if (quotientNum > divisionValue)
	{
		StringAdded(quotientNum, FinalStr, divisionValue, SingleTransValue, LastTransValue);
	}
}

CTime PhdMethod::GetTime(LPCTSTR szTime)
{
	int nYear = 1980, nMonth = 1, nDay = 1, nHour = 1, nMin = 1, nSec = 1;
	CString strTemp = szTime;
	std::vector<CString> vecNumber;
	while (true)
	{
		int nFindIndex = strTemp.Find(_T('-'));
		if (-1 == nFindIndex)
		{
			if (strTemp != _T(""))
				vecNumber.push_back(strTemp);
			break;
		}
		CString strNum = strTemp.Left(nFindIndex);
		vecNumber.push_back(strNum);
		strTemp = strTemp.Right(strTemp.GetLength()-nFindIndex-1);
	}
	int nCount = vecNumber.size();
	if (nCount > 0)
		nYear = _wtoi(vecNumber[0]);
	if (nCount > 1)
		nMonth = _wtoi(vecNumber[1]);
	if (nCount > 2)
		nDay = _wtoi(vecNumber[2]);
	if (nCount > 3)
		nHour = _wtoi(vecNumber[3]);
	if (nCount > 4)
		nMin = _wtoi(vecNumber[4]);
	if (nCount > 5)
		nSec = _wtoi(vecNumber[5]);

	CTime t(nYear, nMonth, nDay, nHour, nMin, nSec);
	return t;
}

#pragma endregion

CString PhdMethod::GetAddedString(const CString& str, int nNum, std::vector<CString>& vecStr)
{
	//��a�� 97  ��z�� 122  ��A�� 65  ��Z�� 90  ��0�� 48  ��9�� 57	
	TCHAR szEnd = str.GetAt(str.GetLength() - 1);
	CString strValue;
	if ((nNum < 1) || !((szEnd >= _T('0') && szEnd <= _T('9')) || (szEnd >= _T('a') && szEnd <= _T('z')) || (szEnd >= _T('A') && szEnd <= _T('Z'))))
		return strValue;

	strValue = str;
	strValue.Delete(strValue.GetLength() - 1);

	int nStr = (int)szEnd;//�ַ�����ֵ
	for (int i = 0; i < nNum; i++)
	{
		if (szEnd >= _T('0') && szEnd <= _T('9'))//����
		{
			CString FinalStr;
			int nSum = (nStr - 48) + i;//�ܵ���ֵ
			StringAdded(nSum, FinalStr, 9, 48, 48);
			vecStr.push_back(strValue + FinalStr);
			if (i == nNum - 1)
				strValue += FinalStr;
		}
		else if (szEnd >= _T('a') && szEnd <= _T('z'))//Сд��ĸ
		{
			CString FinalStr;
			int nSum = (nStr - 97) + i;//�ܵ���ֵ
			StringAdded(nSum, FinalStr, 25, 97, 96);
			vecStr.push_back(strValue + FinalStr);
			if (i == nNum - 1)
				strValue += FinalStr;
		}
		else if (szEnd >= _T('A') && szEnd <= _T('Z'))//��д��ĸ
		{
			CString FinalStr;
			int nSum = (nStr - 65) + i;//�ܵ���ֵ
			StringAdded(nSum, FinalStr, 25, 65, 64);
			vecStr.push_back(strValue + FinalStr);
			if (i == nNum - 1)
				strValue += FinalStr;
		}
	}
	return strValue;
}

bool PhdMethod::ClearDir(LPCTSTR szDirPath)
{
	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.*"), szDirPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		if (finder.IsDots())
			continue;

		if (finder.IsDirectory())
		{
			//�ݹ�ɾ���ļ�������
			if (!ClearDir(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
				
			//ɾ�����ļ���
			if (!RemoveDirectory(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
		else
		{
			//ɾ���ļ�
			if (!DeleteFile(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
	}

	finder.Close();
	return true;
}

bool PhdMethod::DeleteDir(LPCTSTR szDirPath)
{
	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.*"), szDirPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		if (finder.IsDots())
			continue;

		if (finder.IsDirectory())
		{
			//�ݹ�ɾ���ļ�������
			if (!DeleteDir(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
		else
		{
			//ɾ���ļ�
			if (!DeleteFile(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
	}

	finder.Close();
	//ɾ�������ļ���
	if (!RemoveDirectory(szDirPath))
		return false;
	else
		return true;
}

bool PhdMethod::CopyDir(LPCTSTR szOldDirPath, LPCTSTR szNewDirPath)
{
	if (!::PathIsDirectory(szOldDirPath))
		return false;

	if (!::PathFileExists(szNewDirPath))
		if (!CreateDirectory(szNewDirPath, nullptr))
			return false;

	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.*"), szOldDirPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		CString strNewDir = szNewDirPath;
		if (finder.IsDots())
			continue;

		if (finder.IsDirectory())
		{
			if (!CopyDir(finder.GetFilePath(), strNewDir + _T('\\') + finder.GetFileName()))
			{
				finder.Close();
				return FALSE;
			}
		}
		else
		{
			if (!CopyFile(finder.GetFilePath(), strNewDir + _T('\\') + finder.GetFileName(), FALSE))
			{
				finder.Close();
				return FALSE;
			}
		}
	}
	finder.Close();

	return TRUE;
}

bool PhdMethod::CopyDirOfFile(LPCTSTR szOldDirPath, LPCTSTR szNewDirPath)
{
	if (!::PathIsDirectory(szOldDirPath))
		return false;
	if (!::PathIsDirectory(szNewDirPath))
		return false;

	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.*"), szOldDirPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		CString strNewDir = szNewDirPath;
		if (finder.IsDots())
			continue;

		if (finder.IsDirectory())
		{
			if (!CopyDir(finder.GetFilePath(), strNewDir + _T('\\') + finder.GetFileName()))
			{
				finder.Close();
				return FALSE;
			}
		}
		else
		{
			if (!CopyFile(finder.GetFilePath(), strNewDir + _T('\\') + finder.GetFileName(), FALSE))
			{
				finder.Close();
				return FALSE;
			}
		}
	}
	finder.Close();

	return TRUE;
}

bool PhdMethod::DeleteFileOrDir(LPCTSTR szPath)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_ALLOWUNDO |   //����Żػ���վ
// 		FOF_FILESONLY |
// 		FOF_NOCONFIRMATION; //������ȷ�϶Ի���
// 	FileOp.pFrom = szPath;
// 	FileOp.pTo = NULL;      //һ��Ҫ��NULL
// 	FileOp.wFunc = FO_DELETE;    //ɾ������
// 	return SHFileOperation(&FileOp) == 0;

	if (!::PathFileExists(szPath))
		return false;

	if (::PathIsDirectory(szPath))
	{//�ļ���
		//ɾ��Ŀ¼�е��ļ���Ŀ¼
		if (!ClearDir(szPath))
			return false;
		//ɾ�������Ŀ¼
		if (!::RemoveDirectory(szPath))
			return false;
	}
	else
	{//�ļ�
		//ɾ���ļ�
		if (!::DeleteFile(szPath))
			return false;
	}

	return true;
}

bool PhdMethod::CopyFileOrDir(LPCTSTR szFrom, LPCTSTR szTo)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //������ȷ�϶Ի���
// 		FOF_NOCONFIRMMKDIR; //��Ҫʱֱ�Ӵ���һ���ļ���,�����û�ȷ��
// 	FileOp.pFrom = szFrom;
// 	FileOp.pTo = szTo;
// 	FileOp.wFunc = FO_COPY;
// 	return SHFileOperation(&FileOp) == 0;

	if (!::PathFileExists(szFrom))
		return false;

	if (::PathIsDirectory(szFrom))
	{//�ļ���
		if (!CopyDir(szFrom, szTo))
			return false;
	}
	else
	{//�ļ�
		if (!CopyFile(szFrom, szTo, FALSE))
			return false;
	}

	return true;
}

bool PhdMethod::MoveFileOrDir(LPCTSTR szFrom, LPCTSTR szTo)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //������ȷ�϶Ի���
// 		FOF_NOCONFIRMMKDIR; //��Ҫʱֱ�Ӵ���һ���ļ���,�����û�ȷ��
// 	FileOp.pFrom = szFrom;
// 	FileOp.pTo = szTo;
// 	FileOp.wFunc = FO_MOVE;
// 	return SHFileOperation(&FileOp) == 0;

	return ::MoveFile(szFrom, szTo);
}

bool PhdMethod::RenameFileOrDir(LPCTSTR szOldName, LPCTSTR szNewName)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //������ȷ�϶Ի���
// 		FOF_FILESONLY;
// 	FileOp.pFrom = szOldName;
// 	FileOp.pTo = szNewName;
// 	FileOp.wFunc = FO_RENAME;
// 	return SHFileOperation(&FileOp) == 0;

	return ::MoveFile(szOldName, szNewName);
}

bool PhdMethod::OpenFile(LPCTSTR szFilePath, LPCTSTR szParame /*= NULL*/)
{
	HINSTANCE hNewExe = ShellExecute(NULL, _T("open"), szFilePath, szParame, NULL, SW_SHOW);
	if ((DWORD)hNewExe > 32)
		return true;
	else
		return false;
	/*
	hWnd������ָ�������ھ�������������ù��̳��ִ���ʱ��������ΪWindows��Ϣ���ڵĸ����ڡ����磬���Խ�������ΪӦ�ó��������ھ������Application.Handle��Ҳ���Խ�������Ϊ���洰�ھ������GetDesktopWindow������ã���
	lpOperation������ָ��Ҫ���еĲ��������С�open��������ʾִ����FileName����ָ���ĳ��򣬻����FileName����ָ�����ļ����ļ��У���print��������ʾ��ӡ��FileName����ָ�����ļ�����explore��������ʾ�����FileName����ָ�����ļ��С���������Ϊnilʱ����ʾִ��Ĭ�ϲ�����open����
	lpFileName������ָ��Ҫ�򿪵��ļ�����Ҫִ�еĳ����ļ�����Ҫ������ļ�������
	lpParameters����FileName������һ����ִ�г�����˲���ָ�������в���������˲���ӦΪnil��PChar(0)��
	lpDirectory������ָ��Ĭ��Ŀ¼��
	lpShowCmd����FileName������һ����ִ�г�����˲���ָ�����򴰿ڵĳ�ʼ��ʾ��ʽ������˲���Ӧ����Ϊ0��
	*/
}

bool PhdMethod::LaunchExe(LPCTSTR szFilePath, LPCTSTR szParame /*= NULL*/)
{
	//����ZWCAD
	CString OutputPath = szFilePath;
	if (szParame)
	{
		CString strParam = szParame;
		OutputPath = OutputPath + _T(" ") + strParam;
	}

	STARTUPINFO si; //һЩ�ر���������
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	PROCESS_INFORMATION pi; //�ر��������ý���

	//CString sCommand = _T(" /b D:\\work\\GitHub\\Setup\\OUTPUT\\Release_AUTOCAD\\load.scr");
	//CString sCommand = _T(" /b \"./showui.scr\"");
	//BOOL bRet = CreateProcess(NULL, OutputPath.GetBuffer(OutputPath.GetLength()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	//BOOL bRet = CreateProcess(OutputPath.GetBuffer(OutputPath.GetLength()), sCommand.GetBuffer(OutputPath.GetLength()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	BOOL bRet = CreateProcess(NULL, OutputPath.GetBuffer(OutputPath.GetLength()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	
	return bRet;
}

bool PhdMethod::CloseCurOpenedFile(LPCTSTR szFileName)
{
	HWND hWnd = NULL;
	hWnd = FindWindow(NULL, szFileName);
	if (hWnd != NULL)
	{
		SendMessage(hWnd, WM_CLOSE, 0, 0);
		return true;
	}
	return false;
}

CString PhdMethod::GetAppDirPath()
{
	//�˷���Ҳ����
// 	CString strPath;
// 	DWORD nSize = GetModuleFileName(NULL, strPath.GetBuffer(MAX_PATH), MAX_PATH);
// 	strPath.ReleaseBuffer();

	TCHAR lpFileName[MAX_PATH];
	GetModuleFileName(AfxGetInstanceHandle(), lpFileName, MAX_PATH);

	CString strFileName = lpFileName;
	int nIndex = strFileName.ReverseFind(_T('\\'));

	CString strPath;

	if (nIndex > 0)
		strPath = strFileName.Left(nIndex);
	else
		strPath = _T("");
	return strPath;
}

void PhdMethod::CloseProcess(LPCTSTR sProcessName)
{
	bool bFind = false;
	if (sProcessName == NULL)
		return;
	PROCESSENTRY32 pe32;
	//��ʹ������ṹǰ�����������Ĵ�С
	pe32.dwSize = sizeof(pe32);
	//��ϵͳ�����еĽ����ĸ����գ��õ����վ��
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return;
	//	DWORD hMsDevId = 0;
	AcArray<DWORD> arrProId;
	//�������̿��գ�������ʾÿ�����̵���Ϣ
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);//��õ�һ�����̵ľ��
	while (bMore)
	{
		if (_tcsicmp(pe32.szExeFile, sProcessName) == 0)//�ҵ��������
		{
			//			hMsDevId = pe32.th32ProcessID;//�õ�����ID
			arrProId.append(pe32.th32ProcessID);
			bFind = true;//�Ƿ��ҵ��ı��
//			break;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);//�����һ�����̵ľ��
	}
	//��Ҫ���������snapshot����
	::CloseHandle(hProcessSnap);
	if (bFind)
	{
		for (int i = 0; i < arrProId.length(); i++)
		{
			//��������
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, arrProId.at(i));//ͨ��ID�õ�������̵ľ��
			::TerminateProcess(hProcess, 4);//��ָֹ�����̼������е��߳�
		}
	}
}

int PhdMethod::GetProcessExitReturn(LPCTSTR szFilePath, LPCTSTR szParame /*= NULL*/)
{
	SHELLEXECUTEINFO  ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	//ShExecInfo.lpVerb = _T("runas");	//�ù���ԱȨ�����г���
	ShExecInfo.lpFile = szFilePath;
	ShExecInfo.lpParameters = szParame;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);

	DWORD dwResult = WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD dwExitCode;
	GetExitCodeProcess(ShExecInfo.hProcess, &dwExitCode);
	CloseHandle(ShExecInfo.hProcess);

	return dwExitCode;
}

void PhdMethod::RemoveSameEle(std::vector<double>& vecElement, double dTolerance /*= 0.0001*/)
{
	for (int i = 0; i < vecElement.size() - 1; i++)
	{
		for (int j = i + 1; j < vecElement.size(); j++)
		{
			if (PhdInline::IsEqual(vecElement.at(i), vecElement.at(j), dTolerance))
			{
				vecElement.erase(vecElement.begin() + j);
				i--;
				break;
			}
		}
	}
}

AcArray<CString> PhdMethod::GetAllDwgPath(LPCTSTR szFolderPath)
{
	AcArray<CString> arrDwgPath;
	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.dwg"), szFolderPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		if (finder.IsDirectory() || finder.IsDots())
			continue;
		CString strDwgPath = finder.GetFilePath();
		arrDwgPath.append(strDwgPath);
	}
	return arrDwgPath;
}

bool PhdMethod::LaunchCAD(CString strCadPath)
{
	STARTUPINFO si; //һЩ�ر���������
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	PROCESS_INFORMATION pi; //�ر��������ý���
	bool bRet = CreateProcessW(NULL, strCadPath.GetBuffer(strCadPath.GetLength()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	return bRet;
}

CString PhdMethod::GetUniqueName(LPCTSTR szPath)
{
	CString strUniqueName;
	if (!szPath)
		return _T("");
	CString strPath = szPath;
	int nFind = strPath.ReverseFind(_T('\\'));
	CString strFolder,strName;
	if (nFind != -1)
	{
		strFolder = strPath.Left(nFind + 1);
		strName = strPath.Right(strPath.GetLength() - nFind - 1);
	}
	else
		strName = strPath;
		
	if (3 <= strPath.GetLength())
	{
		TCHAR sLastOne = strPath.GetAt(strPath.GetLength() - 1);
		TCHAR sLastTwo = strPath.GetAt(strPath.GetLength() - 2);
		TCHAR slastThree = strPath.GetAt(strPath.GetLength() - 3);
		if (sLastOne == _T(')') && slastThree == _T('(') && 
			sLastTwo >= _T('0') && sLastTwo <= _T('9'))
		{
			CString strLastName = strName.Left(strName.GetLength() - 3);
			CString strNum = sLastTwo;
			int nNum = _wtoi(strNum);
			strNum.Format(_T("%d"),++nNum);
			strUniqueName = strFolder + strLastName + _T('(') + strNum + _T(')');
			return strUniqueName;
		}
	}
	
	strUniqueName = strFolder + strName + _T("(1)");
	return strUniqueName;
}

bool PhdMethod::FileIsExist(LPCTSTR szFilePath)
{
	//�ж��ļ����ļ����Ƿ����
	BOOL rec = ::PathFileExists(szFilePath);
	return rec;
}

CString PhdMethod::GetCurSystemTime()
{
	CTime time = CTime::GetCurrentTime(); //��ȡϵͳ����
//	CString date = time.Format(_T("%Y-%m-%d %H:%M:%S %W-%A"));//2006-10-13 17:23:47 41-Friday
	CString date = time.Format(_T("%Y-%m-%d-%H-%M-%S"));
	return date;
}

bool PhdMethod::CompareTime(LPCTSTR szTime1, LPCTSTR szTime2)
{
	CTime time1 = GetTime(szTime1);
	CTime time2 = GetTime(szTime2);
	if (time1 > time2)
		return true;
	else
		return false;
}

CString PhdMethod::PathToName(LPCTSTR szPath)
{
	CString strPath = szPath;
	int nFindIndex = strPath.ReverseFind(_T('\\'));
	if (nFindIndex == -1)
		return strPath;
	strPath = strPath.Right(strPath.GetLength() - nFindIndex - 1);
	return strPath;
}

int PhdMethod::GetStringCount(LPCTSTR str, TCHAR s)
{
	CString strTemp = str;
	int nCount = 0;
	for (int i = 0; i < strTemp.GetLength(); i++)
	{
		TCHAR a = strTemp[i];
		if (a == s)
			nCount++;
	}
	return nCount;
}

CString PhdMethod::GetAppDataLocalFolder()
{
	TCHAR szPath[_MAX_PATH];
	::SHGetSpecialFolderPath(nullptr, szPath, CSIDL_LOCAL_APPDATA, TRUE);
	CString strAppData = szPath;
	return strAppData;
}

CString PhdMethod::GetAppDataRoamingFolder()
{
	TCHAR szPath[_MAX_PATH];
	::SHGetSpecialFolderPath(nullptr, szPath, CSIDL_APPDATA, TRUE);
	CString strLocalAppData = szPath;
	return strLocalAppData;
}

bool PhdMethod::GetHostNameAndIP(CString& strName, CString& strIp)
{
	USES_CONVERSION;

	char name[_MAX_PATH];
	gethostname(name, 128);//���������
	strName = A2T(name);
	HOSTENT* pHost = NULL;
	pHost = gethostbyname(name);//��������ṹ
	auto ip = inet_ntoa(*((in_addr *)pHost->h_addr));
	strIp = A2T(ip);
	return true;
}

CString PhdMethod::EncryptDecode(LPCTSTR szStr, int nNum)
{
	CString strTemp = szStr;
	if (strTemp == _T(""))
		return _T("");

	CString strNew;
	for (int i = 0; i < strTemp.GetLength(); i++)
	{
		TCHAR s = strTemp[i];
		int n = s;
		int nEncrypt = n ^ nNum;
		s = nEncrypt;
		CString str = s;
		strNew += str;
	}
	return strNew;
}

CString PhdMethod::Encrypt(LPCTSTR szStr, int nNum)
{
	CString strTemp = szStr;
	if (strTemp == _T(""))
		return _T("");

	CString strNew;
	for (int i = 0; i < strTemp.GetLength(); i++)
	{
		TCHAR s = strTemp[i];
		int n = s;
		int nEncrypt = n + nNum;
		s = nEncrypt;
		CString str = s;
		strNew += str;
	}
	return strNew;
}

CString PhdMethod::Decode(LPCTSTR szStr, int nNum)
{
	CString strTemp = szStr;
	if (strTemp == _T(""))
		return _T("");

	CString strNew;
	for (int i = 0; i < strTemp.GetLength(); i++)
	{
		TCHAR s = strTemp[i];
		int n = s;
		int nEncrypt = n - nNum;
		s = nEncrypt;
		CString str = s;
		strNew += str;
	}
	return strNew;
}

CString PhdMethod::Decode(TCHAR szS, int nNum)
{
	CString strNew;
	int n = szS;
	int nEncrypt = n - nNum;
	szS = nEncrypt;
	strNew = szS;
	return strNew;
}

int PhdMethod::GetRandomInt(int a, int b)
{
	srand((unsigned)time(NULL));
	int nNum = (rand() % (b - a + 1)) + a;
	return nNum;
}

CTime PhdMethod::GetTimeOfDayLast(const CTime& time, int nDay)
{
	CTimeSpan addTime(nDay,0,0,0);
	CTime timeNew = time + addTime;
	return timeNew;
}

// void PhdMethod::PurgeDatabase(AcDbDatabase* pDb)
// {
// 	//��
// 	AcDbObjectIdArray arridBlock = PhdBlock::GetBlkIdsOnDb(pDb);
// 	pDb->purge(arridBlock);
// 	for (int i = 0; i < arridBlock.length(); i++)
// 	{
// 		AcDbBlockTableRecordPointer pBlkTblRcd(arridBlock[i], AcDb::kForWrite);
// 		if (Acad::eOk != pBlkTblRcd.openStatus())
// 			continue;
// 		pBlkTblRcd->erase();
// 	}
// 	//��ע��ʽ
// 	AcDbObjectIdArray arridDimStyle = PhdDimStyle::GetDimStyleIdsOnDb(pDb);
// 	pDb->purge(arridDimStyle);
// 	for (int i = 0; i < arridDimStyle.length(); i++)
// 	{
// 		AcDbDimStyleTableRecordPointer pDimStyTblRcd(arridDimStyle[i], AcDb::kForWrite);
// 		if (Acad::eOk != pDimStyTblRcd.openStatus())
// 			continue;
// 		pDimStyTblRcd->erase();
// 	}
// 	//��
// 	AcDbObjectIdArray arridGroup = PhdGroup::GetGroupIdsOnDb(pDb);
// 	pDb->purge(arridGroup);
// 	for (int i = 0; i < arridGroup.length(); i++)
// 	{
// 		AcDbObjectPointer<AcDbGroup> pGroup(arridGroup[i], AcDb::kForWrite);
// 		if (Acad::eOk != pGroup.openStatus())
// 			continue;
// 		pGroup->erase();
// 	}
// 	//ͼ��
// 	AcDbObjectIdArray arridLayer = PhdLayer::GetLayerIdsOnDb(pDb);
// 	pDb->purge(arridLayer);
// 	for (int i = 0; i < arridLayer.length(); i++)
// 	{
// 		AcDbLayerTableRecordPointer pLayerTblRcd(arridLayer[i], AcDb::kForWrite);
// 		if (Acad::eOk != pLayerTblRcd.openStatus())
// 			continue;
// 		pLayerTblRcd->erase();
// 	}
// 	//����
// 	AcDbObjectIdArray arridLinetype = PhdLinetype::GetLinetypeIdsOnDb(pDb);
// 	pDb->purge(arridLinetype);
// 	for (int i = 0; i < arridLinetype.length(); i++)
// 	{
// 		AcDbLinetypeTableRecordPointer pLinetypeTblRcd(arridLinetype[i], AcDb::kForWrite);
// 		if (Acad::eOk != pLinetypeTblRcd.openStatus())
// 			continue;
// 		pLinetypeTblRcd->erase();
// 	}
// 	//������ʽ
// 	AcDbObjectIdArray arridTextStyle = PhdTextStyle::GetTextStyleIdsOnDb(pDb);
// 	pDb->purge(arridTextStyle);
// 	for (int i = 0; i < arridTextStyle.length(); i++)
// 	{
// 		AcDbTextStyleTableRecordPointer pTextStyleTblRcd(arridTextStyle[i], AcDb::kForWrite);
// 		if (Acad::eOk != pTextStyleTblRcd.openStatus())
// 			continue;
// 		pTextStyleTblRcd->erase();
// 	}
// }
