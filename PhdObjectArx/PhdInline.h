#pragma once

#ifndef DEL
#define DEL(ptr) if (NULL != (ptr)){ delete (ptr); (ptr) = NULL;}
#endif

#ifndef PI
#define PI (atan(1.0)*4)		
#endif

#ifndef ReturnfalseNotTrue
#define ReturnfalseNotTrue(b) if (!(b)) return false;
#endif

#ifndef ReturnfalseNoteOk
#define ReturnfalseNoteOk(es) if (Acad::eOk != (es)) return false;
#endif

#ifndef Struct_Key
#define Struct_Key
struct SKey
{
	CString m_strName;
	CString m_strValue;

	SKey() {}
	SKey(LPCTSTR szName,LPCTSTR szValue)
	:m_strName(szName),m_strValue(szValue){}
};
#endif


namespace PhdInline {

	//���ܣ���ads_point���п���
	void CopyAdsPt(ads_point ptSource,ads_point ptTarget);
	//���ܣ���ʵ�������п���
	void CopyEname(ads_name nameSource,ads_name nameTarget);

	//���ܣ��õ������е�
	AcGePoint3d MidPt(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	//���ܣ�����������
	AcGePoint3d RelativePt(const AcGePoint3d& pt, double x, double y);
	//���ܣ����������
	// Parameters: 	
	//    pt		- 	�����ʼ��
	//    angle		- 	�����������ʼ��ļн�(����)
	//    distance		- 	�������㵽��ʼ��ľ���
	AcGePoint3d PolarPt(const AcGePoint3d& pt, double angle, double distance);

	//���ܣ��ж�����ʵ���Ƿ����
	bool IsEqual(double d1, double d2,double dTolerance = 0.0001);

	//�Ƿ�������
	bool IsOddNumber(int nNum);
}
