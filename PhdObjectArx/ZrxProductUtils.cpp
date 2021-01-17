#include "StdAfx.h"
#include "ZrxProductUtils.h"

CString ZrxProductUtils::CadProductName()
{
	// return acdbHostApplicationServices()->product();
	CString strRegPath = GetLocalMachineRegistryPath();
	strRegPath.TrimRight(_T("\\/"));
	int pos = strRegPath.ReverseFind(_T('\\'));

	CString strLan = strRegPath.Mid(pos + 1);
	strRegPath = strRegPath.Left(pos);
	strRegPath.TrimRight(_T("\\"));

	pos = strRegPath.ReverseFind(_T('\\'));
	CString strYear = strRegPath.Mid(pos + 1);
	strRegPath = strRegPath.Left(pos);
	strRegPath.TrimRight(_T("\\"));

	pos = strRegPath.ReverseFind(_T('\\'));
	CString strProduct = strRegPath.Mid(pos + 1);
	strRegPath = strRegPath.Left(pos);
	strRegPath.TrimRight(_T("\\"));

	return strProduct;
}

CString ZrxProductUtils::Manufactor()
{
	return _T("ZWSOFT");
}

CString ZrxProductUtils::Year()
{
	return acdbHostApplicationServices()->versionString();
}

CString ZrxProductUtils::Language()
{
	auto lcid = GetThreadLocale();
	TCHAR szName[LOCALE_NAME_MAX_LENGTH];
	if (LCIDToLocaleName(lcid, szName, LOCALE_NAME_MAX_LENGTH, 0) == 0)
	{
		return _T("");
	}

	return szName;
}

CString ZrxProductUtils::Platform()
{
#if _WIN64
	return _T("x64");
#else
	return _T("Win32");
#endif
}

CString ZrxProductUtils::GetLocalMachineRegistryPath()
{
	return acdbHostApplicationServices()->getMachineRegistryProductRootKey();
}

CString ZrxProductUtils::GetCurDir()
{
	TCHAR szPath[_MAX_PATH];
	::GetModuleFileName(_hdllInstance, szPath, _MAX_PATH);

	TCHAR szDrive[_MAX_DRIVE];
	TCHAR szDir[_MAX_DIR];
	TCHAR szFname[_MAX_FNAME];
	TCHAR szExt[_MAX_EXT];
	_tsplitpath_s(szPath, szDrive, szDir, szFname, szExt);

	return CString(szDrive) + szDir;
}

const CStringArray& ZrxProductUtils::Split(LPCTSTR szToSplit, CStringArray& ar, LPCTSTR szSperator)
{
	CString strToSplit(szToSplit);
	while (!strToSplit.IsEmpty())
	{
		int pos = strToSplit.FindOneOf(szSperator);
		if (pos < 0)
		{
			ar.Add(strToSplit);
			break;
		}
		else if (pos > 0)
		{
			ar.Add(strToSplit.Left(pos));
		}

		strToSplit = strToSplit.Mid(pos + 1);
	}

	return ar;
}

const CStringArray& ZrxProductUtils::Split(LPCTSTR szToSplit, CStringArray& ar, TCHAR ch)
{
	TCHAR sz[] = { ch, _T('\0') };
	return Split(szToSplit, ar, sz);
}

int ZrxProductUtils::Find(const CStringArray& ar, LPCTSTR sz)
{
	for (int i = 0; i < ar.GetSize(); i++)
	{
		if (ar[i].CompareNoCase(sz) == 0)
		{
			return i;
		}
	}

	return -1;
}

bool ZrxProductUtils::Find(const CStringArray& ar, LPCTSTR sz, int* pos)
{
	auto _pos = Find(ar, sz);
	if (nullptr != pos)
	{
		*pos = _pos;
	}
	return _pos >= 0;
}

void ZrxProductUtils::Connect(const CStringArray& ar, TCHAR ch, TCHAR* buffer, int bufferLength)
{
	TCHAR sperator[] = { ch, _T('\0') };
	Connect(ar, sperator, buffer, bufferLength);
}

void ZrxProductUtils::Connect(const CStringArray& ar, LPCTSTR sperator, TCHAR* buffer, int bufferLength)
{
	_tcsset_s(buffer, bufferLength, 0);
	for (int i = 0; i < ar.GetSize(); ++i)
	{
		_tcscat_s(buffer, bufferLength, ar[i]);
		_tcscat_s(buffer, bufferLength, sperator);
	}

	int length = _tcslen(buffer);
	buffer[length - _tcslen(sperator)] = _T('\0');
	
}

void ZrxProductUtils::Connect(const CStringArray& ar, TCHAR ch, CString& buffer)
{
	buffer.Empty();
	for (int i = 0; i < ar.GetSize(); ++i)
	{
		buffer.Append(ar[i]);
		buffer.AppendChar(ch);
	}

	if (ar.GetSize() > 0)
	{
		buffer.Delete(buffer.GetLength() - 1);
	}

	
}

CString ZrxProductUtils::GetCurZrxPath()
{
	TCHAR szPath[_MAX_PATH];
	::GetModuleFileName(_hdllInstance, szPath, _MAX_PATH);

	return szPath;
}

void ZrxProductUtils::SplitPath(LPCTSTR szPath, CString& sDrive, CString& sDir, CString& sFname, CString& sExt)
{
	_tsplitpath_s(szPath,
		sDrive.GetBuffer(_MAX_DRIVE), _MAX_DRIVE,
		sDir.GetBuffer(_MAX_DIR), _MAX_DIR,
		sFname.GetBuffer(_MAX_FNAME), _MAX_FNAME,
		sExt.GetBuffer(_MAX_EXT), _MAX_EXT);

	sDrive.ReleaseBuffer();
	sDir.ReleaseBuffer();
	sFname.ReleaseBuffer();
	sExt.ReleaseBuffer();
}

CString ZrxProductUtils::GetCurZrxFile()
{
	CString sFname;
	CString sExt;
	SplitPath(GetCurZrxPath(), CString(), CString(), sFname, sExt);

	return sFname + sExt;
}

bool ZrxProductUtils::IsFileExists(LPCTSTR szPath)
{
	CFileStatus st;
	return CFile::GetStatus(szPath, st);
}

CString ZrxProductUtils::GetFolder(LPCTSTR szPath)
{
	CString strPath(szPath);
	strPath.TrimRight(_T("\\/"));

	int pos = strPath.ReverseFind(_T('\\'));
	int pos2 = strPath.ReverseFind(_T('/'));
	pos = max(pos, pos2);

	if (pos < 0)
	{
		return _T("");
	}

	return strPath.Left(pos + 1);
}

HRESULT ZrxProductUtils::GetZcadPreferencesFiles(IZcadPreferencesFiles** pFiles)
{
// 	IDispatch* pDispatch = acedGetIDispatch(FALSE);
// 	if (nullptr == pDispatch)
// 	{
// 		return -1;
// 	}
// 
// 	IZcadApplication* pApp = nullptr;
// 	auto hr = pDispatch->QueryInterface(IID_IZcadApplication, (void**)& pApp);
// 	if (FAILED(hr))
// 	{
// 		return hr;
// 	}
// 
// 	IZcadPreferences* pPreferences = nullptr;
// 	hr = pApp->get_Preferences(&pPreferences);
// 	pApp->Release();
// 	if (FAILED(hr))
// 	{
// 		return hr;
// 	}
// 
// 	// IAcadPreferencesFiles* pFiles = nullptr;
// 	hr = pPreferences->get_Files(pFiles);
// 	pPreferences->Release();
// 	if (FAILED(hr))
// 	{
// 		return hr;
// 	}

	return S_OK;
}
