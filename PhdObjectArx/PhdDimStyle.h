#pragma once

//��ע��ʽ
namespace PhdDimStyle {

	//���ܣ��õ���ע��ʽId
	//************************************
	// Method:    GetDimStyleId
	// FullName:  PhdDimStyle::GetDimStyleId
	// Access:    public 
	// Returns:   AcDbObjectId
	// Qualifier:
	// Parameter: LPCTSTR szDimStyleName
	// Parameter: AcDbDatabase * pDb
	//************************************
	AcDbObjectId GetDimStyleId(LPCTSTR szDimStyleName, AcDbDatabase* pDb = acdbCurDwg());

	//���ܣ�������ע��ʽ
	AcDbObjectId CreateDimStyle(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   �õ����ݿ����еı�ע��ʽid
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetDimStyleIdsOnDb(AcDbDatabase* pDb);




}

