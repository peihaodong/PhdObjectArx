#pragma once


namespace PhdGroup {

	//������
	AcDbObjectId CreateGroup(LPCTSTR szGourpName, AcDbDatabase* pDb = acdbCurDwg(), bool bSelectable = true);
	bool CreateGroup(const AcDbObjectIdArray& ents, LPCTSTR szGroupName, AcDbObjectId& IdGroup, bool bSelectable = true);

	//���ܣ�����������
	AcDbObjectId CreateAnonGroup(AcDbDatabase *pDb = acdbCurDwg(), bool bSelectable = true);

	//���ܣ�ͨ������Ѱ����
	bool HasGroup(LPCTSTR szGroupName, AcDbObjectId& IdGroup , AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ�ʵ����ӵ���
	bool AppendToGroup(const AcDbObjectId& idGroup,const AcDbObjectId& idEnt);
	bool AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectIdArray& arridEnt);

	//���ܣ��õ���ʵ�����id�������ʵ��û����ӵ��飬�򷵻ؿ�
	AcDbObjectId GetGroupId(const AcDbObjectId& ent);

	//���ܣ��õ���������ʵ��
	bool GetGroupEnts(AcDbObjectIdArray& IdArray, const AcDbObjectId& IdGroup);

	//���ܣ����¹�������
	bool ResetGroup(const AcDbObjectIdArray& ents, const AcDbObjectId& IdGroup);

	// Summary:   �õ����ݿ����е���id
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetGroupIdsOnDb(AcDbDatabase* pDb);

	//ɾ�����е�ĳ��ʵ��
	bool GroupRemoveEnt(const AcDbObjectId& idGroup,const AcDbObjectId& idDelEnt);

	//ɾ����
	bool DeleteGroup(const AcDbObjectId& idGroup);
}

