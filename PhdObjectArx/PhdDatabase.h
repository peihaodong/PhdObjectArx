#pragma once


namespace PhdDatabase {

	bool GetObjectIdArrayFromAcDbIdMapping(const AcDbIdMapping& adim,
		const AcDbObjectIdArray& adoiaInput,AcDbObjectIdArray& adoiaPair);

	// Summary:   �����ݿⱣ��Ϊdwgͼֽ
	// Time:	  2020��1��7�� peihaodong
	// Explain:	  �û����ֶ��ͷ����ݿ�ָ��
	bool DbSaveToDwg(AcDbDatabase* pDb,LPCTSTR szDwgPath,bool bBak = false);
	bool DbSaveToDwg(AcDbDatabase* pDb, LPCTSTR szDwgPath, 
		const AcDb::AcDbDwgVersion dwgVer, bool bBak = false);

	// Summary:   ����Ϊdxfͼֽ
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	bool DbSaveToDxf(AcDbDatabase* pDb,LPCTSTR szDxfPath,
		const AcDb::AcDbDwgVersion dwgVer);
	bool DbSaveToDxf(AcDbDatabase* pDb, LPCTSTR szDxfPath);
	// Summary:   ����Ϊdwg��dxfͼֽ
	// Time:	  2020��4��15�� peihaodong
	// Explain:	  
	bool DbSaveToDwgOrDxf(AcDbDatabase* pDb, LPCTSTR szPath);

	//���ܣ���ͼֽ���뵽���ݿ�
	bool InsertDwg(LPCTSTR szDwgPath,const AcGePoint3d& ptInsert,AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ���ͼֽ�еĿ鶨����뵽���ݿ�
	bool InsertBlkDef(LPCTSTR szDwgPath,LPCTSTR szBlkName,AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ��õ�ͼֽ�����еĿ���
	AcArray<CString> GetBlkDefNames(const CString& strDwgPath);

	// Summary:   �õ����ݿ�ģ�Ϳռ�����ʵ����������
	// Time:	  2019��10��31��
	// Explain:	  
	AcDbExtents GetDbExtent(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   �õ����ݿ�ģ�Ϳռ�����ʵ���id
	// Time:	  2019��10��31��
	// Explain:	  
	AcDbObjectIdArray GetDbEntId(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   �л���ǰ���ݿ�
	// Time:	  2019��12��17�� peihaodong
	// Explain:	  
	void SwitchCurDatabase(AcDbDatabase* pDb);

#pragma region wblock insert readDwgFile
	// Summary:   �õ�dwgͼֽ���ݿ�ָ��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  ʹ�����Ҫdelete����dwgͼֽ�����ǹر�״̬������ͬʱ��ȡ
	AcDbDatabase* GetDwgDbPointer(LPCTSTR szDwgPath);
	// Summary:   �õ�dxfͼֽ���ݿ�ָ��
	// Time:	  2020��4��15�� peihaodong
	// Explain:	   ʹ�����Ҫdelete����dwgͼֽ�����ǹر�״̬������ͬʱ��ȡ
	AcDbDatabase* GetDxfDbPointer(LPCTSTR szDxfPath);
	// Summary:   
	// Time:	  2020��4��15�� peihaodong
	// Explain:	  
	AcDbDatabase* GetDwgOrDxfDbPointer(LPCTSTR szPath);

	// Summary:   ��pDbSource���ݿ��е�arridSouʵ����ptBaseSouΪ���㣬
	//			�Կ鶨�����ʽ������pDbTarget���ݿ���
	// Time:	  2019��12��12�� peihaodong
	// Explain:	  szBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource,const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou,AcDbDatabase* pDbTarget,LPCTSTR szBlkNameTar,
		AcDbObjectId& idBlkDefTar);
	// Summary:   ��pDbSource���ݿ��еĿ鶨��idBlkDefSou������pDbTarget���ݿ���
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
		 AcDbDatabase* pDbTarget, LPCTSTR szBlkNameTar,AcDbObjectId& idBlkDefTar);
	// Summary:   ��pDbSource�����е�����ʵ��(��ǰ���ݿ���ڵ�ʵ��)
	//			��Ϊ�鶨�忽����pDbTarget���ݿ���
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
		LPCTSTR szBlkNameTar, AcDbObjectId& idBlkDefTar);
	
	// Summary:   ��pDbSource���ݿ��е�ʵ��arridSou��ptBaseSouΪ���㣬��ԭʵ����ʽ
	//			������pDbTarget���ݿ���ptBaseTarλ��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget,
		const AcGePoint3d& ptBaseTar );
	// Summary:   ��pDbSource���ݿ��еĿ鶨��idBlkDefSou��ԭʵ����ʽ������pDbTarget
	//			���ݿ�ptBaseTarλ��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
		 AcDbDatabase* pDbTarget,const AcGePoint3d& ptBaseTar);
	// Summary:   ��pDbSource���ݿ��е�����ʵ��(��ǰ���ݿ���ڵ�ʵ��)
	//			��ԭʵ����ʽ������pDbTarget
	//			���ݿ�ptBaseTarλ��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
		const AcGePoint3d& ptBaseTar);

	//�����⣬ʵ��ʧ�ܣ���֪���ǲ��������ӿ�bug
	// Summary:   ��pDbSource���ݿ��е�arridSouʵ����ptBaseSouΪ���㣬��ΪszNewBlkNameTar
	//			�鶨�忽����pDbTarget���ݿ��У�����pDbTarget���ݿ�szCpBlkNameTar�鶨���е�ʵ��
	//			�������µĿ鶨��szNewBlkNameTar��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szNewBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
			const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);
	// Summary:   ��pDbSource���ݿ��еĿ鶨��idBlkDefSou����ΪszNewBlkNameTar
	//			�鶨�忽����pDbTarget���ݿ��У�����pDbTarget���ݿ�szCpBlkNameTar�鶨���е�ʵ��
	//			�������µĿ鶨��szNewBlkNameTar��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szNewBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
			AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);
	// Summary:   ��pDbSource���ݿ��е�����ʵ��(��ǰ���ݿ���ڵ�ʵ��)����ΪszNewBlkNameTar
	//			�鶨�忽����pDbTarget���ݿ��У�����pDbTarget���ݿ�szCpBlkNameTar�鶨���е�ʵ��
	//			�������µĿ鶨��szNewBlkNameTar��
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  szNewBlkNameTar-����������������飬����_T("*U")
	// Return:	  �õ��鶨��id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource,AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);

#pragma endregion

#pragma region wblockCloneObjects deepCloneObjects
	// Summary:   ���ݿ�俽������pDbSource���ݿ��е�arridSouʵ����ptBaseSouΪ���㣬
	//			������pDbTarget���ݿ�ptBaseTarλ�ã�arridTar��ʵ�忽������pDbTarget
	//			���ݿ��е�ID
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  pDbSource��pDbTarget�����ǲ�ͬ�����ݿ�
	bool CopyAmongDbOfBlkTbl(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, const AcGePoint3d& ptBaseTar,
		AcDbObjectIdArray& arridTar);

	// Summary:   ���ݿ��ڿ�������pDb���ݿ��е�arridʵ����ptBaseΪ���㣬������pDb���ݿ��idBlkDef
	//			�鶨���ptBaseCopiedλ�ã�arridCopied�ǿ������ʵ��ID
	// Time:	  2019��12��13�� peihaodong
	// Explain:	  
	bool CopyWithinDbOfBlkTbl(AcDbDatabase* pDb, const AcDbObjectIdArray& arrid,
		const AcGePoint3d& ptBase, const AcDbObjectId& idBlkDef,const AcGePoint3d& ptBaseCopied,
		AcDbObjectIdArray& arridCopied);

#pragma endregion


}
