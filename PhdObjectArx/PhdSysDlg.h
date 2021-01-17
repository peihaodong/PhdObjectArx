#pragma once


namespace PhdSysDlg {

	//���ܣ���ʾһ������Ի���
	void AlertBox(LPCTSTR msg);

	//���ܣ���ʾһ����ֹ�Ծ���Ի���
	void StopAlertBox(LPCTSTR msg);

	//���ܣ���ʾһ����ʾ�Ի���
	void PromptBox(LPCTSTR msg);

	//���ܣ���ʾһ�����ʶԻ���
	//������defButton-Ĭ��Yes��ť����ԴID���⽫�����س��Ƿ����Yes��
	//���أ��û�����İ�ť����ԴID��OK = IDYES(���û��Զ����)�� NO = IDNO��
	UINT QuestionBox(LPCTSTR msg, UINT defButton = IDYES);

	// Summary: ��ʾһ��AutoCAD��׼ʰȡ�ļ��ĶԻ�����ʾ�û����ļ���
	// Parameters:
	//   prompt				- �Ի�����⡣
	//   def				- Ĭ�ϵ��ļ�����
	//   ext				- Ĭ�ϵ��ļ���չ����
	//   fname				- ����������û�ѡ�����ļ�ȫ·����
	//   defIsDirectory		- Ĭ���ļ�����ָ������·�������ļ���true����·����false�����ļ���
	//   allowArbitraryExt	- �Ƿ������������չ����
	// Returns: ����ɹ�����Acad::eOk��ʧ�ܷ���Acad::eInvalidInput��
	bool getFileNameForRead(LPCTSTR prompt, LPCTSTR def,
		LPCTSTR ext, CString& fname,
		bool defIsDirectory = true,
		bool allowArbitraryExt = false);

	// Summary: ��ʾһ��AutoCAD��׼ʰȡ�ļ��ĶԻ�����ʾ�û������ļ���
	// Parameters:
	//   prompt				- �Ի�����⡣
	//   def				- Ĭ�ϵ��ļ�����
	//   ext				- Ĭ�ϵ��ļ���չ����
	//   fname				- ����������û�ѡ�����ļ�ȫ·����
	//   defIsDirectory		- Ĭ���ļ�����ָ������·�������ļ���true����·����false�����ļ���
	//   allowArbitraryExt	- �Ƿ������������չ����
	// Returns: ����ɹ�����Acad::eOk��ʧ�ܷ���Acad::eInvalidInput��
	bool getFileNameForWrite(LPCTSTR prompt, LPCTSTR def,
		LPCTSTR ext, CString& fname,
		bool defIsDirectory = true,
		bool allowArbitraryExt = false);

	//���ܣ�����ϵͳ�Ի���-ѡ���ļ�����ѡ��
	// 	std::vector<CString> vecFileType;
	// 	vecFileType.push_back(_T("xls"));
	// 	vecFileType.push_back(_T("xlsx"));
	bool SelFileByDlg(const std::vector<CString>& vecFileType, CString& strPath);
	//���ܣ�����ϵͳ�Ի���-ѡ���ļ������Զ�ѡ��
	bool SelFileByDlg(const std::vector<CString>& vecFileType, std::vector<CString>& vecFilePath);
	//���ܣ�����ϵͳ�Ի���-ѡ���ļ���
	//Note��ѡ����ļ���·����󲻴�'//'
	bool SelDirByDlg(CString& strDirPath);
	//���ܣ�����ϵͳ�Ի���-����ļ�
	bool SaveFileByDlg(CString& strSavePath, const std::vector<CString>& vecFileType, 
		LPCTSTR szFileName = NULL);

}


