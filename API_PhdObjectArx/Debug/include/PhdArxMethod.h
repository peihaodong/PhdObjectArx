#pragma once

namespace Phd{

class PHD_OBJECTARX_API PhdArxMethod
{

#pragma region 内部函数
	void StringAdded(int nSum, CString& FinalStr, int divisionValue,
		int SingleTransValue, int LastTransValue);

	CTime GetTime(LPCTSTR szTime);
#pragma endregion

public:
	PhdArxMethod();

public:
	//功能：字符串自增
	// Parameters: 	
	//    str		- 	输入字符串（最后字符必须以数字、小写字母、大写字母结尾）
	//    nNum		- 	输入增加的数字
	//    arrStr		- 	输出期间所有的字符串集合
	// Returns:   	返回最后自增的字符串
	CString GetAddedString(const CString& str, int nNum, std::vector<CString>& vecStr);

	//功能：清理文件夹(将文件夹里面的文件和文件夹都删掉，但是本身不会删掉)
	bool ClearDir(LPCTSTR szDirPath);
	// Summary:   删除文件夹本身和里面的所有的文件
	// Time:	  2019年11月8日 peihaodong
	// Explain:	  
	bool DeleteDir(LPCTSTR szDirPath);

	// Summary:   拷贝文件夹
	// Time:	  2019年11月8日 peihaodong
	// Explain:	  
	bool CopyDir(LPCTSTR szOldDirPath,LPCTSTR szNewDirPath);

	// Summary:   将文件夹中的文件拷贝到另一个目录中
	// Time:	  2019年11月8日 peihaodong
	// Explain:	  
	bool CopyDirOfFile(LPCTSTR szOldDirPath, LPCTSTR szNewDirPath);

	// Summary:   删除文件或文件夹
	// Time:	  2019年11月6日 peihaodong
	// Explain:	  
	bool DeleteFileOrDir(LPCTSTR szPath);

	// Summary:   复制文件或文件夹
	// Time:	  2019年11月6日 peihaodong
	// Explain:	  
	bool CopyFileOrDir(LPCTSTR szFrom,LPCTSTR szTo);

	// Summary:   移动文件或文件夹
	// Time:	  2019年11月6日 peihaodong
	// Explain:	  
	bool MoveFileOrDir(LPCTSTR szFrom, LPCTSTR szTo);

	// Summary:   重命名文件或文件夹
	// Time:	  2019年11月6日 peihaodong
	// Explain:	  
	bool RenameFileOrDir(LPCTSTR szOldName,LPCTSTR szNewName);

	//功能：打开指定文件
	bool OpenFile(LPCTSTR szFilePath,LPCTSTR szParame = NULL);

	//创建进程启动exe
	bool LaunchExe(LPCTSTR szFilePath, LPCTSTR szParame = NULL);

	//功能：关闭当前打开的文件
	//szFileName-输入桌面上的程序名称
	bool CloseCurOpenedFile(LPCTSTR szFileName);

	//功能：得到当前程序所在目录
	CString GetAppDirPath();

	//功能：关闭当前进程
	void CloseProcess(LPCTSTR sProcessName);

	//功能：得到某一进程退出的返回值
	// Parameters: 	
	//    strFilePath		- 	输入文件路径
	//    strParame		- 	输入执行文件所需的参数
	int GetProcessExitReturn(LPCTSTR szFilePath, LPCTSTR szParame = NULL);

	//功能：移除重复元素
	template <class  T>
	void RemoveSameElement(std::vector<T>& vecElement)
	{
		std::sort(vecElement.begin(), vecElement.end());
		auto last = std::unique(vecElement.begin(), vecElement.end());
		vecElement.erase(last, vecElement.end());
	}
	void RemoveSameEle(std::vector<double>& vecElement,
		double dTolerance = 0.0001);

// 	// Summary:   删除容器中对应的元素
// 	// Time:	  2019年11月25日 peihaodong
// 	// Explain:	  
// 	template <class T>
// 	std::vector<T> RemoveElement(const std::vector<T>& vecElement,
// 		const std::vector<T>& vecDelEle)
// 	{
// 		std::vector<T> vecNew;
// 		for (int i = 0; i < vecElement.size(); i++)
// 		{
// 			bool bSame = false;
// 			for (int j = 0; j < vecDelEle.size(); j++)
// 			{
// 				if (vecElement[i] == vecDelEle[j])
// 				{
// 					bSame = true;
// 					break;
// 				}
// 			}
// 			if (!bSame)
// 				vecNew.push_back(vecElement[i]);
// 		}
// 		return vecNew;
// 	}

	//功能：得到目录下所有的dwg图纸路径
	AcArray<CString> GetAllDwgPath(LPCTSTR szFolderPath);

	//功能：启动cad
	bool LaunchCAD(CString strCadPath);

	// Summary:   得到独一无二的名称
	// Time:	  2019年10月28日
	// Explain:	  
	CString GetUniqueName(LPCTSTR szPath);

	// Summary:   判断文件或文件夹是否存在
	// Time:	  2019年11月1日
	// Explain:	  
	bool FileIsExist(LPCTSTR szFilePath);

	// Summary:   获取当前系统时间
	// Time:	  2019年11月1日
	// Explain:	  
	CString GetCurSystemTime();

	// Summary:   时间比较
	// Time:	  2019年11月1日
	// Explain:	  如果time1大于time2返回true
	bool CompareTime(LPCTSTR szTime1,LPCTSTR szTime2);

	// Summary:   得到路径的文件名（包含后缀）
	// Time:	  2019年12月18日 peihaodong
	// Explain:	  
	CString PathToName(LPCTSTR szPath);

	// Summary:   得到字符串中某个字符的数量
	// Time:	  2019年12月26日 peihaodong
	// Explain:	  
	int GetStringCount(LPCTSTR str, TCHAR s);

	//得到系统目录路径（最后不带'\\'）
	CString GetAppDataLocalFolder();
	CString GetAppDataRoamingFolder();
	
	// Summary:   获得主机名和IP
	// Time:	  2019年12月27日 peihaodong
	// Explain:	  
	bool GetHostNameAndIP(CString& strName,CString& strIp);

	// Summary:   加密、解密
	// Time:	  2019年12月30日 peihaodong
	// Explain:	  
	CString EncryptDecode(LPCTSTR szStr,int nNum);
	CString Encrypt(LPCTSTR szStr, int nNum);
	CString Decode(LPCTSTR szStr, int nNum);
	CString Decode(TCHAR szS, int nNum);

	// Summary:   获得[a,b]之间的随机整数
	// Time:	  2019年12月30日 peihaodong
	// Explain:	  
	int GetRandomInt(int a,int b);

	// Summary:   得到time日期nDay天以后的日期
	// Time:	  2019年12月30日 peihaodong
	// Explain:	  
	CTime GetTimeOfDayLast(const CTime& time,int nDay);

// 	// Summary:   清理数据库
// 	// Time:	  2020年3月23日 peihaodong
// 	// Explain:	  
// 	void PurgeDatabase(AcDbDatabase* pDb);

private:
	std::shared_ptr<Phd::PhdArxInline> m_apPhdArxInline;
};

}