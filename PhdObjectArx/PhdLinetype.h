#pragma once

//����
namespace PhdLinetype {

	//���ܣ�����ʵ������
	bool SetEntLinetype(const AcDbObjectId& idEnt, LPCTSTR szLinetypeName);

	//���ܣ��õ�ʵ��������
	CString GetLinetypeName(const AcDbObjectId& idEnt);

	// Summary:   �õ����ݿ����е�����id
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetLinetypeIdsOnDb(AcDbDatabase* pDb);



}

