#pragma once
#include <zacadi.h>

class ZrxProductUtils
{
public:
	
	/// <summary>
	/// 产品名称
	/// </summary>
	/// <returns>产品名称</returns>
	static CString CadProductName();

	/// <summary>
	/// 产品厂家
	/// </summary>
	/// <returns>产品厂家</returns>
	static CString Manufactor();

	/// <summary>
	/// 版本字符串
	/// </summary>
	/// <returns>版本</returns>
	static CString Year();

	/// <summary>
	/// 当前CAD语言版本
	/// </summary>
	/// <returns>语言</returns>
	static CString Language();

	static CString Platform();

	static CString GetLocalMachineRegistryPath();

	static CString GetCurDir();

	static const CStringArray& Split(LPCTSTR szToSplit, CStringArray& ar, LPCTSTR szSperator);
	static const CStringArray& Split(LPCTSTR szToSplit, CStringArray& ar, TCHAR ch = _T(';'));

	static int Find(const CStringArray& ar, LPCTSTR sz);
	static bool Find(const CStringArray& ar, LPCTSTR sz, int* pos);
	static void Connect(const CStringArray& ar, TCHAR ch, TCHAR* buffer, int bufferLength);
	static void Connect(const CStringArray& ar, LPCTSTR sperator, TCHAR* buffer, int bufferLength);
	static void Connect(const CStringArray& ar, TCHAR ch, CString& buffer);

	static CString GetCurZrxPath();

	static void SplitPath(LPCTSTR szPath, CString& sDrive, CString& sDir, CString& sFname, CString& sExt);
	static CString GetCurZrxFile();

	static bool IsFileExists(LPCTSTR szPath);

	static CString GetFolder(LPCTSTR szPath);

	static HRESULT GetZcadPreferencesFiles(IZcadPreferencesFiles** pFiles);
};
