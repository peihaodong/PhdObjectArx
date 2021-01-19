#pragma once

namespace Phd{

class PHD_OBJECTARX_API PhdArxSysDlg
{
public:
	//功能：显示一个警告对话框
	void AlertBox(LPCTSTR msg);

	//功能：显示一个终止性警告对话框
	void StopAlertBox(LPCTSTR msg);

	//功能：显示一个提示对话框
	void PromptBox(LPCTSTR msg);

	//功能：显示一个疑问对话框
	//参数：defButton-默认Yes按钮的资源ID，这将决定回车是否等于Yes。
	//返回：用户点击的按钮的资源ID，OK = IDYES(或用户自定义的)， NO = IDNO。
	UINT QuestionBox(LPCTSTR msg, UINT defButton = IDYES);

	// Summary: 显示一个AutoCAD标准拾取文件的对话框，提示用户打开文件。
	// Parameters:
	//   prompt				- 对话框标题。
	//   def				- 默认的文件名。
	//   ext				- 默认的文件扩展名。
	//   fname				- 输出变量，用户选择后的文件全路径。
	//   defIsDirectory		- 默认文件名所指定的是路径还是文件，true，是路径，false，是文件。
	//   allowArbitraryExt	- 是否允许任意的扩展名。
	// Returns: 如果成功返回Acad::eOk，失败返回Acad::eInvalidInput。
	bool getFileNameForRead(LPCTSTR prompt, LPCTSTR def,
		LPCTSTR ext, CString& fname,
		bool defIsDirectory = true,
		bool allowArbitraryExt = false);

	// Summary: 显示一个AutoCAD标准拾取文件的对话框，提示用户保存文件。
	// Parameters:
	//   prompt				- 对话框标题。
	//   def				- 默认的文件名。
	//   ext				- 默认的文件扩展名。
	//   fname				- 输出变量，用户选择后的文件全路径。
	//   defIsDirectory		- 默认文件名所指定的是路径还是文件，true，是路径，false，是文件。
	//   allowArbitraryExt	- 是否允许任意的扩展名。
	// Returns: 如果成功返回Acad::eOk，失败返回Acad::eInvalidInput。
	bool getFileNameForWrite(LPCTSTR prompt, LPCTSTR def,
		LPCTSTR ext, CString& fname,
		bool defIsDirectory = true,
		bool allowArbitraryExt = false);

	//功能：调用系统对话框-选择文件（单选）
	// 	std::vector<CString> vecFileType;
	// 	vecFileType.push_back(_T("xls"));
	// 	vecFileType.push_back(_T("xlsx"));
	bool SelFileByDlg(const std::vector<CString>& vecFileType, CString& strPath);
	//功能：调用系统对话框-选择文件（可以多选）
	bool SelFileByDlg(const std::vector<CString>& vecFileType, std::vector<CString>& vecFilePath);
	//功能：调用系统对话框-选择文件夹
	//Note：选择的文件夹路径最后不带'//'
	bool SelDirByDlg(CString& strDirPath);
	//功能：调用系统对话框-另存文件
	bool SaveFileByDlg(CString& strSavePath, const std::vector<CString>& vecFileType, 
		LPCTSTR szFileName = NULL);

};

}
