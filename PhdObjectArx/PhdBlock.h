#pragma once

//��
namespace PhdBlock {

	// Summary:   �õ�����¼������ʵ��id��ͨ��������
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szBlkTblRcdName-����¼����ģ�Ϳռ�������ǣ�ACDB_MODEL_SPACE��
	bool GetIdsOnBlock(LPCTSTR szBlkTblRcdName,AcDbObjectIdArray& arrid,
		AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   �õ�����¼������ʵ��id��ͨ���鶨��id��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	bool GetIdsOnBlock(const AcDbObjectId& idBlkTblRcd,AcDbObjectIdArray& arrid);

	// Summary:   �õ��鶨��Id��ͨ��������
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	AcDbObjectId GetBlkDefId(LPCTSTR szBlkName,AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   �õ��鶨��id��ͨ�������id��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	AcDbObjectId GetBlkDefId(const AcDbObjectId& idRef);
	// Summary:   �õ��鶨��id��ͨ��������
	// Time:	  2019��11��27�� peihaodong
	// Explain:	  ������ݿ���û�иÿ鶨�壬�ʹ�Ŀ��ͼֽ���������ݿ���
	AcDbObjectId GetBlkDefId(LPCTSTR szBlkName, LPCTSTR szDwgPath,
		AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ��õ����ݿ����еĿ���
	AcArray<CString> GetBlkNamesOnDb(AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   �õ����ݿ������еĿ鶨��id
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetBlkIdsOnDb(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   ͨ��ͼֽ��pDb���ݿⴴ���鶨��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  ���pDb����szBlkName�鶨�壬����pDb�еĿ鶨��
	bool CreateBlock(LPCTSTR szDwgPath, LPCTSTR szBlkName, AcDbObjectId& idBlkDef,
		AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   ��pDb�����鶨��
	// Time:	  2019��12��16�� peihaodong
	// Explain:	  arrid��pDb�е�ʵ��
	bool CreateBlock(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase,
		LPCTSTR szBlkName,AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());
	bool CreateBlock(const AcArray<AcDbEntity*>& arrpEnt, const AcGePoint3d& ptBase,
		LPCTSTR szBlkName, AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   ͨ�������id�õ��ÿ���յĲ����
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	AcGePoint3d GetBlkRefPosition(const AcDbObjectId& idRef);

	// Summary:   �õ��鶨������յ�����
	// Time:	  2019��11��21�� peihaodong
	// Explain:	  
	CString GetBlkName(const AcDbObjectId& idBlk);

#pragma region ���Կ�
	//���ܣ��õ����Կ���������
	AcArray<CString> GetAttTagsOnBlk(const AcDbObjectId& idBlkDef);

	//���ܣ��õ����Կ����������Ϣ
	std::map<CString, CString> GetAttInfoOnBlkRef(const AcDbObjectId& idRef);

	//���ܣ��õ����Կ����ĳһ���Ե��ı�
	CString GetAttTextOnBlkRef(const AcDbObjectId& idRef,LPCTSTR szAttTag);
	CString GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag);
	bool GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag,
		CString& strAttValue);

	//���ܣ��������Կ���������ı�
	bool SetAttTextOnBlkRef(const AcDbObjectId& idRef,LPCTSTR szTag,LPCTSTR szText);
	bool SetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szTag, LPCTSTR szText);
	bool SetAttTextOnBlkRef(const AcDbObjectId& idRef,const std::map<CString,CString>& mapData);

	//���ܣ��������Կ����
	AcDbBlockReference* CreateAttBlkRef(const AcDbObjectId& idBlkDef,const AcGePoint3d& ptInsert);
	AcDbBlockReference* CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert, 
		const std::map<CString, CString>& mapAtt);

	// Summary:   �ÿ���մ治���ڸ����ֵ�����
	// Time:	  2019��12��26�� peihaodong
	// Explain:	  
	bool IsExistAtt(AcDbBlockReference* pBlkRef,LPCTSTR szAttName);

#pragma endregion

#pragma region ������
	//���ܣ�����������
	bool CreateAnonyBlk(LPCTSTR szDwgPath,AcDbObjectId& idBlkDef,AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   ����������
	// Time:	  2019��12��5�� peihaodong
	// Explain:	  pDb-�����鶨�����ڵ����ݿ�ָ��
	bool CreateAnonyBlk(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase, 
		AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());
	
#pragma endregion



}

