#pragma once



namespace PhdConver {

	/*
	asPnt3d();		//��ads_pointת����AcGePoint3d
	asVec3d();		//��ads_pointת����AcGeVector3d
	asDblArray();	//��AcGePoint3d��AcGeVector3dת����ads_point

	AcDbObject::objectId();				//��ָ�뵽ID
	AcDbDatabase::getAcDbObjectId();	//�Ӿ����ID
	AcDbObjectId::handle();				//��ID�����
	AcDbObject::getAcDbHandle();		//��ָ�뵽���
	*/

#pragma region תΪ�ַ���
	//���ܣ�IdתΪ�ַ����������;����
	CString IdToStr(const AcDbObjectId& id);

	//���ܣ���תΪ�ַ���
	//������prec-С����λ�������Ϊ-1��ʹ��AutoCAD LUPRECϵͳ�����ĵ�ǰֵ��	unit-���ַ�����ʽ��Ϊ��Ч��AutoCAD LUNITSֵ�ĵ�λ;���-1��ʹ�õ�ǰ��LUNITSֵ
	CString PtToStr(const AcGePoint3d& pt, int prec = -1, int unit = -1);
	CString PtToStr(const AcGePoint2d& pt, int prec = -1, int unit = -1);

	//���ܣ�����תΪ�ַ���
	CString VecToStr(const AcGeVector3d& vec,int prec = -1, int unit = -1);
	CString VecToStr(const AcGeVector2d& vec, int prec = -1, int unit = -1);

	//���ܣ��Ƕ�תΪ�ַ���
	CString AngleToStr(const double angle,int prec = -1, int unit = -1);

	//���ܣ�������תΪ�ַ���
	CString DoubleToStr(const double realVal, int prec = -1, int unit = -1);

	//���ܣ�����תΪ�ַ���
	CString IntToStr(const int intVal);

	//���ܣ�ָ�루��ַ��תΪ�ַ���
	CString PtrToStr(void* ptr);

	//���ܣ����ݿ�����֣��ļ�����תΪ�ַ���
	CString DbToStr(AcDbDatabase* pDb);

	//���ܣ�����ֵתΪ�ַ���
	CString BoolToStr(bool b);

#pragma endregion

#pragma region תΪ����
	//���ܣ�������ת�������������룩
	int ToInt(double dValue);

	//���ܣ�������ת����������ȡ����
	int ToIntOfTop(double dValue);

	//���ܣ�������ת����������ȡ����
	int ToIntOfBottom(double dValue);
#pragma endregion


	//���ܣ�����������С����λ������ֵ
	//������unDot-С����λ��
	double UpdateOnDotNum(double dValue,unsigned int unDot);

	//���ܣ��Ƕ�ת��Ϊ����
	double ToRadian(double dAngle);
	//���ܣ�����ת��Ϊ�Ƕ�
	double ToAngle(double dRadian);

	//���ܣ�ads_nameתΪId
	bool AdsnameToId(const ads_name objName,AcDbObjectId& id);
	//���ܣ�IdתΪads_name
	bool IdToAdsname(const AcDbObjectId& id,ads_name& name);

	//���ܣ�תΪ��ά��
	AcGePoint2d ToPt2d(const AcGePoint3d& pt);
	//���ܣ�תΪ��ά��
	AcGePoint3d ToPt3d(const AcGePoint2d& pt, double z = 0);

	//���ܣ��û�����ϵת��Ϊ��������ϵ
	AcGePoint3d UcsToWcsPt(const AcGePoint3d &point);
	//���ܣ��û�����ϵת��Ϊ��ʾ����ϵ
	AcGePoint2d UcsToDcsPt(const AcGePoint3d& pt);
	//���ܣ���������ϵת�����û�����ϵ
	AcGePoint3d WcsToUcsPt(const AcGePoint3d &point);
	//���ܣ���������ת��ʾ����
	AcGePoint3d WcsToDcsPt(const AcGePoint3d &point);
	
	// Summary:   ���ַ�תΪASCII��
	// Time:	  2019��12��30�� peihaodong
	// Explain:	  
	int ToASCII(TCHAR s);
	// Summary:   ��ASCII��תΪ�ַ�
	// Time:	  2019��12��30�� peihaodong
	// Explain:	  
	TCHAR ToChar(int n);


}

