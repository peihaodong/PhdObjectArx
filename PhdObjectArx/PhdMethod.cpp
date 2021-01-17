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


#pragma region 内部函数
void PhdMethod::StringAdded(int nSum, CString& FinalStr, int divisionValue,
	int SingleTransValue, int LastTransValue)
{
	int quotientNum = nSum / (divisionValue + 1);
	int remainderNum = nSum % (divisionValue + 1);
	TCHAR newStr = TCHAR(remainderNum + SingleTransValue);//个位字符
	FinalStr.Insert(0, newStr);
	if (quotientNum == 0)
	{
		return;
	}
	else if (0 < quotientNum && quotientNum <= divisionValue)
	{
		newStr = TCHAR(quotientNum + LastTransValue);//前位字符
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
	//‘a’ 97  ‘z’ 122  ‘A’ 65  ‘Z’ 90  ‘0’ 48  ‘9’ 57	
	TCHAR szEnd = str.GetAt(str.GetLength() - 1);
	CString strValue;
	if ((nNum < 1) || !((szEnd >= _T('0') && szEnd <= _T('9')) || (szEnd >= _T('a') && szEnd <= _T('z')) || (szEnd >= _T('A') && szEnd <= _T('Z'))))
		return strValue;

	strValue = str;
	strValue.Delete(strValue.GetLength() - 1);

	int nStr = (int)szEnd;//字符的码值
	for (int i = 0; i < nNum; i++)
	{
		if (szEnd >= _T('0') && szEnd <= _T('9'))//数字
		{
			CString FinalStr;
			int nSum = (nStr - 48) + i;//总的码值
			StringAdded(nSum, FinalStr, 9, 48, 48);
			vecStr.push_back(strValue + FinalStr);
			if (i == nNum - 1)
				strValue += FinalStr;
		}
		else if (szEnd >= _T('a') && szEnd <= _T('z'))//小写字母
		{
			CString FinalStr;
			int nSum = (nStr - 97) + i;//总的码值
			StringAdded(nSum, FinalStr, 25, 97, 96);
			vecStr.push_back(strValue + FinalStr);
			if (i == nNum - 1)
				strValue += FinalStr;
		}
		else if (szEnd >= _T('A') && szEnd <= _T('Z'))//大写字母
		{
			CString FinalStr;
			int nSum = (nStr - 65) + i;//总的码值
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
			//递归删除文件夹内容
			if (!ClearDir(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
				
			//删除空文件夹
			if (!RemoveDirectory(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
		else
		{
			//删除文件
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
			//递归删除文件夹内容
			if (!DeleteDir(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
		else
		{
			//删除文件
			if (!DeleteFile(finder.GetFilePath()))
			{
				finder.Close();
				return false;
			}
		}
	}

	finder.Close();
	//删除本身文件夹
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
// 	FileOp.fFlags = FOF_ALLOWUNDO |   //允许放回回收站
// 		FOF_FILESONLY |
// 		FOF_NOCONFIRMATION; //不出现确认对话框
// 	FileOp.pFrom = szPath;
// 	FileOp.pTo = NULL;      //一定要是NULL
// 	FileOp.wFunc = FO_DELETE;    //删除操作
// 	return SHFileOperation(&FileOp) == 0;

	if (!::PathFileExists(szPath))
		return false;

	if (::PathIsDirectory(szPath))
	{//文件夹
		//删除目录中的文件和目录
		if (!ClearDir(szPath))
			return false;
		//删除本身空目录
		if (!::RemoveDirectory(szPath))
			return false;
	}
	else
	{//文件
		//删除文件
		if (!::DeleteFile(szPath))
			return false;
	}

	return true;
}

bool PhdMethod::CopyFileOrDir(LPCTSTR szFrom, LPCTSTR szTo)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //不出现确认对话框
// 		FOF_NOCONFIRMMKDIR; //需要时直接创建一个文件夹,不需用户确定
// 	FileOp.pFrom = szFrom;
// 	FileOp.pTo = szTo;
// 	FileOp.wFunc = FO_COPY;
// 	return SHFileOperation(&FileOp) == 0;

	if (!::PathFileExists(szFrom))
		return false;

	if (::PathIsDirectory(szFrom))
	{//文件夹
		if (!CopyDir(szFrom, szTo))
			return false;
	}
	else
	{//文件
		if (!CopyFile(szFrom, szTo, FALSE))
			return false;
	}

	return true;
}

bool PhdMethod::MoveFileOrDir(LPCTSTR szFrom, LPCTSTR szTo)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //不出现确认对话框
// 		FOF_NOCONFIRMMKDIR; //需要时直接创建一个文件夹,不需用户确定
// 	FileOp.pFrom = szFrom;
// 	FileOp.pTo = szTo;
// 	FileOp.wFunc = FO_MOVE;
// 	return SHFileOperation(&FileOp) == 0;

	return ::MoveFile(szFrom, szTo);
}

bool PhdMethod::RenameFileOrDir(LPCTSTR szOldName, LPCTSTR szNewName)
{
// 	SHFILEOPSTRUCT FileOp = { 0 };
// 	FileOp.fFlags = FOF_NOCONFIRMATION |   //不出现确认对话框
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
	hWnd：用于指定父窗口句柄。当函数调用过程出现错误时，它将作为Windows消息窗口的父窗口。例如，可以将其设置为应用程序主窗口句柄，即Application.Handle，也可以将其设置为桌面窗口句柄（用GetDesktopWindow函数获得）。
	lpOperation：用于指定要进行的操作。其中“open”操作表示执行由FileName参数指定的程序，或打开由FileName参数指定的文件或文件夹；“print”操作表示打印由FileName参数指定的文件；“explore”操作表示浏览由FileName参数指定的文件夹。当参数设为nil时，表示执行默认操作“open”。
	lpFileName：用于指定要打开的文件名、要执行的程序文件名或要浏览的文件夹名。
	lpParameters：若FileName参数是一个可执行程序，则此参数指定命令行参数，否则此参数应为nil或PChar(0)。
	lpDirectory：用于指定默认目录。
	lpShowCmd：若FileName参数是一个可执行程序，则此参数指定程序窗口的初始显示方式，否则此参数应设置为0。
	*/
}

bool PhdMethod::LaunchExe(LPCTSTR szFilePath, LPCTSTR szParame /*= NULL*/)
{
	//启动ZWCAD
	CString OutputPath = szFilePath;
	if (szParame)
	{
		CString strParam = szParame;
		OutputPath = OutputPath + _T(" ") + strParam;
	}

	STARTUPINFO si; //一些必备参数设置
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	PROCESS_INFORMATION pi; //必备参数设置结束

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
	//此方法也可以
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
	//在使用这个结构前，先设置它的大小
	pe32.dwSize = sizeof(pe32);
	//给系统内所有的进程拍个快照，得到快照句柄
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return;
	//	DWORD hMsDevId = 0;
	AcArray<DWORD> arrProId;
	//遍历进程快照，轮流显示每个进程的信息
	BOOL bMore = ::Process32First(hProcessSnap, &pe32);//获得第一个进程的句柄
	while (bMore)
	{
		if (_tcsicmp(pe32.szExeFile, sProcessName) == 0)//找到这个进程
		{
			//			hMsDevId = pe32.th32ProcessID;//得到进程ID
			arrProId.append(pe32.th32ProcessID);
			bFind = true;//是否找到的标记
//			break;
		}
		bMore = ::Process32Next(hProcessSnap, &pe32);//获得下一个进程的句柄
	}
	//不要忘记清除掉snapshot对象
	::CloseHandle(hProcessSnap);
	if (bFind)
	{
		for (int i = 0; i < arrProId.length(); i++)
		{
			//结束进程
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, arrProId.at(i));//通过ID得到这个进程的句柄
			::TerminateProcess(hProcess, 4);//终止指定进程及其所有的线程
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
	//ShExecInfo.lpVerb = _T("runas");	//用管理员权限运行程序
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
	STARTUPINFO si; //一些必备参数设置
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWNORMAL;
	PROCESS_INFORMATION pi; //必备参数设置结束
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
	//判断文件或文件夹是否存在
	BOOL rec = ::PathFileExists(szFilePath);
	return rec;
}

CString PhdMethod::GetCurSystemTime()
{
	CTime time = CTime::GetCurrentTime(); //获取系统日期
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
	gethostname(name, 128);//获得主机名
	strName = A2T(name);
	HOSTENT* pHost = NULL;
	pHost = gethostbyname(name);//获得主机结构
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
// 	//块
// 	AcDbObjectIdArray arridBlock = PhdBlock::GetBlkIdsOnDb(pDb);
// 	pDb->purge(arridBlock);
// 	for (int i = 0; i < arridBlock.length(); i++)
// 	{
// 		AcDbBlockTableRecordPointer pBlkTblRcd(arridBlock[i], AcDb::kForWrite);
// 		if (Acad::eOk != pBlkTblRcd.openStatus())
// 			continue;
// 		pBlkTblRcd->erase();
// 	}
// 	//标注样式
// 	AcDbObjectIdArray arridDimStyle = PhdDimStyle::GetDimStyleIdsOnDb(pDb);
// 	pDb->purge(arridDimStyle);
// 	for (int i = 0; i < arridDimStyle.length(); i++)
// 	{
// 		AcDbDimStyleTableRecordPointer pDimStyTblRcd(arridDimStyle[i], AcDb::kForWrite);
// 		if (Acad::eOk != pDimStyTblRcd.openStatus())
// 			continue;
// 		pDimStyTblRcd->erase();
// 	}
// 	//组
// 	AcDbObjectIdArray arridGroup = PhdGroup::GetGroupIdsOnDb(pDb);
// 	pDb->purge(arridGroup);
// 	for (int i = 0; i < arridGroup.length(); i++)
// 	{
// 		AcDbObjectPointer<AcDbGroup> pGroup(arridGroup[i], AcDb::kForWrite);
// 		if (Acad::eOk != pGroup.openStatus())
// 			continue;
// 		pGroup->erase();
// 	}
// 	//图层
// 	AcDbObjectIdArray arridLayer = PhdLayer::GetLayerIdsOnDb(pDb);
// 	pDb->purge(arridLayer);
// 	for (int i = 0; i < arridLayer.length(); i++)
// 	{
// 		AcDbLayerTableRecordPointer pLayerTblRcd(arridLayer[i], AcDb::kForWrite);
// 		if (Acad::eOk != pLayerTblRcd.openStatus())
// 			continue;
// 		pLayerTblRcd->erase();
// 	}
// 	//线型
// 	AcDbObjectIdArray arridLinetype = PhdLinetype::GetLinetypeIdsOnDb(pDb);
// 	pDb->purge(arridLinetype);
// 	for (int i = 0; i < arridLinetype.length(); i++)
// 	{
// 		AcDbLinetypeTableRecordPointer pLinetypeTblRcd(arridLinetype[i], AcDb::kForWrite);
// 		if (Acad::eOk != pLinetypeTblRcd.openStatus())
// 			continue;
// 		pLinetypeTblRcd->erase();
// 	}
// 	//文字样式
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
