#pragma once
#include <dbwipe.h>


namespace PhdEntity {

#pragma region ���򸲸�
	//���ܣ��������򸲸�
	AcDbWipeout* CreateWipeout(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax);
	AcDbWipeout* CreateWipeout(const AcGePoint3dArray& ptArr);

#pragma endregion

#pragma region �����
	//���ܣ����������
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& ptArr);
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& arrpt,
		const AcArray<double>& arrdBulge);
	AcDbPolyline* CreatePolyline(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax);

	//�жϸö�����Ƿ��Ǳպ϶����
	bool IsClosedPline(AcDbPolyline* pPline);
#pragma endregion

#pragma region ����
	//���ܣ���������
	bool CreateRegion(const AcArray<AcDbEntity*>& arrpEnt, AcArray<AcDbRegion*>& arrpRegion);
	bool CreateRegion(AcDbEntity* pEnt, AcArray<AcDbRegion*>& arrpRegion);

#pragma endregion

#pragma region Բ��
	//���ܣ�����Բ��
	AcDbArc* CreateArc(const AcGePoint3d& ptStart, const AcGePoint3d& ptOnArc, const AcGePoint3d& ptEnd);
	AcDbArc* CreateArc(const AcGePoint3d& ptStart,  const AcGePoint3d& ptEnd, double dRadius);
	//���ܣ�Բ�ġ���ʼ�㡢��ֹ�����Բ������֪��˭����ʼ�����ֹ�㣩
	AcDbArc* CreateArcByPt(const AcGePoint3d& ptCenter, const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	// Summary:   ͨ��Բ�ġ���ʼ�㡢��ֹ�㴴��Բ��
	// Time:	  2019��11��29�� peihaodong
	// Explain:	  
	AcDbArc* CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd);
	AcDbArc* CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, 
		const AcGePoint3d& ptEnd,const AcDbObjectId& idProEnt);
	// Summary:   ͨ��3�㴴��Բ������֪��˭����ʼ�����ֹ�㣩
	// Time:	  2020��6��24�� peihaodong
	// Explain:	  
	AcDbArc* CreateArcBy3Pt(const AcGePoint3d& pt1,const AcGePoint3d& ptOnArc,
		const AcGePoint3d& pt2);

	// Summary:   �õ�Բ���е�����
	// Time:	  2020��2��17�� peihaodong
	// Explain:	  
	AcGePoint3d GetArcMidPt(AcDbArc* pArc);

	// Summary:   �޸�Բ�������
	// Time:	  2020��3��6�� peihaodong
	// Explain:	  
	bool ModifyArcPt(AcDbArc* pArc, const AcGePoint3d& ptFrom, const AcGePoint3d& ptTo);
#pragma endregion

#pragma region ��������
	//���ܣ�������ptΪ���ĵ�ĵ�������
	AcDbText* CreateTextForCenter(double dHeight, const AcGePoint3d& pt,LPCTSTR szText);
	AcDbText* CreateTextForCenter(const AcGePoint3d& pt, LPCTSTR szText,
		const AcDbObjectId& idProEnt);
	AcDbText* CreateTextForLeftTop(double dHeight,const AcGePoint3d& pt,LPCTSTR szText);
	AcDbText* CreateTextForLeft(double dHeight, const AcGePoint3d& pt, LPCTSTR szText);
	AcDbText* CreateTextForLeft(double dHeight, const AcGePoint3d& pt,
		LPCTSTR szText,AcDbEntity* pProEnt);
	AcDbText* CreateTextForLeft(const AcGePoint3d& pt,LPCTSTR szText, 
		const AcDbObjectId& idProEnt);

#pragma endregion

#pragma region ���
	//���ܣ��������
	AcDbTable* CreateTable(const AcGePoint3d& ptInster);
#pragma endregion

#pragma region ֱ��
	// Summary:   ����ֱ��
	// Time:	  2019��11��5�� peihaodong
	// Explain:	  
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd);
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd, AcDbEntity* pProEnt);
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd, const AcDbObjectId& idProEnt);
#pragma endregion

#pragma region ����
	AcDbLeader* CreateLeader(const AcGePoint3dArray& arrpt,
		double dArrowSize,double dDimScale);
#pragma endregion

#pragma region ��
	AcDbPoint* CreatePoint(const AcGePoint3d& pt);

#pragma endregion

#pragma region Բ
	AcDbCircle* CreateCircle(const AcGePoint3d& ptCenter, double dRadius);

#pragma endregion

}

