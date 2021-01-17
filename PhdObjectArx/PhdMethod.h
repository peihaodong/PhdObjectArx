#pragma once


namespace PhdMethod {

#pragma region �ڲ�����
	void StringAdded(int nSum, CString& FinalStr, int divisionValue,
		int SingleTransValue, int LastTransValue);

	CTime GetTime(LPCTSTR szTime);
#pragma endregion

	//���ܣ��ַ�������
	// Parameters: 	
	//    str		- 	�����ַ���������ַ����������֡�Сд��ĸ����д��ĸ��β��
	//    nNum		- 	�������ӵ�����
	//    arrStr		- 	����ڼ����е��ַ�������
	// Returns:   	��������������ַ���
	CString GetAddedString(const CString& str, int nNum, std::vector<CString>& vecStr);

	//���ܣ������ļ���(���ļ���������ļ����ļ��ж�ɾ�������Ǳ�����ɾ��)
	bool ClearDir(LPCTSTR szDirPath);
	// Summary:   ɾ���ļ��б������������е��ļ�
	// Time:	  2019��11��8�� peihaodong
	// Explain:	  
	bool DeleteDir(LPCTSTR szDirPath);

	// Summary:   �����ļ���
	// Time:	  2019��11��8�� peihaodong
	// Explain:	  
	bool CopyDir(LPCTSTR szOldDirPath,LPCTSTR szNewDirPath);

	// Summary:   ���ļ����е��ļ���������һ��Ŀ¼��
	// Time:	  2019��11��8�� peihaodong
	// Explain:	  
	bool CopyDirOfFile(LPCTSTR szOldDirPath, LPCTSTR szNewDirPath);

	// Summary:   ɾ���ļ����ļ���
	// Time:	  2019��11��6�� peihaodong
	// Explain:	  
	bool DeleteFileOrDir(LPCTSTR szPath);

	// Summary:   �����ļ����ļ���
	// Time:	  2019��11��6�� peihaodong
	// Explain:	  
	bool CopyFileOrDir(LPCTSTR szFrom,LPCTSTR szTo);

	// Summary:   �ƶ��ļ����ļ���
	// Time:	  2019��11��6�� peihaodong
	// Explain:	  
	bool MoveFileOrDir(LPCTSTR szFrom, LPCTSTR szTo);

	// Summary:   �������ļ����ļ���
	// Time:	  2019��11��6�� peihaodong
	// Explain:	  
	bool RenameFileOrDir(LPCTSTR szOldName,LPCTSTR szNewName);

	//���ܣ���ָ���ļ�
	bool OpenFile(LPCTSTR szFilePath,LPCTSTR szParame = NULL);

	//������������exe
	bool LaunchExe(LPCTSTR szFilePath, LPCTSTR szParame = NULL);

	//���ܣ��رյ�ǰ�򿪵��ļ�
	//szFileName-���������ϵĳ�������
	bool CloseCurOpenedFile(LPCTSTR szFileName);

	//���ܣ��õ���ǰ��������Ŀ¼
	CString GetAppDirPath();

	//���ܣ��رյ�ǰ����
	void CloseProcess(LPCTSTR sProcessName);

	//���ܣ��õ�ĳһ�����˳��ķ���ֵ
	// Parameters: 	
	//    strFilePath		- 	�����ļ�·��
	//    strParame		- 	����ִ���ļ�����Ĳ���
	int GetProcessExitReturn(LPCTSTR szFilePath, LPCTSTR szParame = NULL);

	//���ܣ��Ƴ��ظ�Ԫ��
	template <class  T>
	void RemoveSameElement(std::vector<T>& vecElement)
	{
		std::sort(vecElement.begin(), vecElement.end());
		auto last = std::unique(vecElement.begin(), vecElement.end());
		vecElement.erase(last, vecElement.end());
	}
	void RemoveSameEle(std::vector<double>& vecElement,
		double dTolerance = 0.0001);

// 	// Summary:   ɾ�������ж�Ӧ��Ԫ��
// 	// Time:	  2019��11��25�� peihaodong
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

	//���ܣ��õ�Ŀ¼�����е�dwgͼֽ·��
	AcArray<CString> GetAllDwgPath(LPCTSTR szFolderPath);

	//���ܣ�����cad
	bool LaunchCAD(CString strCadPath);

	// Summary:   �õ���һ�޶�������
	// Time:	  2019��10��28��
	// Explain:	  
	CString GetUniqueName(LPCTSTR szPath);

	// Summary:   �ж��ļ����ļ����Ƿ����
	// Time:	  2019��11��1��
	// Explain:	  
	bool FileIsExist(LPCTSTR szFilePath);

	// Summary:   ��ȡ��ǰϵͳʱ��
	// Time:	  2019��11��1��
	// Explain:	  
	CString GetCurSystemTime();

	// Summary:   ʱ��Ƚ�
	// Time:	  2019��11��1��
	// Explain:	  ���time1����time2����true
	bool CompareTime(LPCTSTR szTime1,LPCTSTR szTime2);

	// Summary:   �õ�·�����ļ�����������׺��
	// Time:	  2019��12��18�� peihaodong
	// Explain:	  
	CString PathToName(LPCTSTR szPath);

	// Summary:   �õ��ַ�����ĳ���ַ�������
	// Time:	  2019��12��26�� peihaodong
	// Explain:	  
	int GetStringCount(LPCTSTR str, TCHAR s);

	//�õ�ϵͳĿ¼·������󲻴�'\\'��
	CString GetAppDataLocalFolder();
	CString GetAppDataRoamingFolder();
	
	// Summary:   �����������IP
	// Time:	  2019��12��27�� peihaodong
	// Explain:	  
	bool GetHostNameAndIP(CString& strName,CString& strIp);

	// Summary:   ���ܡ�����
	// Time:	  2019��12��30�� peihaodong
	// Explain:	  
	CString EncryptDecode(LPCTSTR szStr,int nNum);
	CString Encrypt(LPCTSTR szStr, int nNum);
	CString Decode(LPCTSTR szStr, int nNum);
	CString Decode(TCHAR szS, int nNum);

	// Summary:   ���[a,b]֮����������
	// Time:	  2019��12��30�� peihaodong
	// Explain:	  
	int GetRandomInt(int a,int b);

	// Summary:   �õ�time����nDay���Ժ������
	// Time:	  2019��12��30�� peihaodong
	// Explain:	  
	CTime GetTimeOfDayLast(const CTime& time,int nDay);

// 	// Summary:   �������ݿ�
// 	// Time:	  2020��3��23�� peihaodong
// 	// Explain:	  
// 	void PurgeDatabase(AcDbDatabase* pDb);

}

