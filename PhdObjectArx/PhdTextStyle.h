#pragma once

//������ʽ
namespace PhdTextStyle {

	//���ܣ��õ����ݿ����е�������ʽ��
	AcArray<CString> GetAllTextStyleName(AcDbDatabase *pDb = acdbCurDwg());

	// Summary:   �õ�������ʽid
	// Time:	  2019��12��9�� peihaodong
	// Explain:	  
	AcDbObjectId GetTextStyleId(LPCTSTR szName, AcDbDatabase *pDb = acdbCurDwg());
	AcDbObjectId GetTextStyleIdOfMText(const AcDbObjectId& idMText);
	
	// Summary:   �õ�������ʽ�Ŀ�ȱ���
	// Time:	  2019��12��9�� peihaodong
	// Explain:	  
	double GetWidthScale(const AcDbObjectId& idTextStyle);

	// Summary:   �õ����ݿ����е�������ʽid
	// Time:	  2020��3��23�� peihaodong
	// Explain:	  
	AcDbObjectIdArray GetTextStyleIdsOnDb(AcDbDatabase* pDb);



}
