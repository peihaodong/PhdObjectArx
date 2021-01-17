#pragma once
//���������
struct SPlineData
{
	AcArray<AcDbEntity*> m_arrEntPointer;	//��ɸö���ߵ��߶�ָ��
	AcDbPolyline* m_pPline;
	bool m_bClosed;

	SPlineData();
};

//��������ֱ�߻�Բ��תΪ�����
class CCurveToPline
{
public:
	CCurveToPline(const AcDbObjectIdArray& idArr);
	CCurveToPline(const AcArray<AcDbEntity*>& pArr);
	~CCurveToPline();

	AcArray<AcDbPolyline*> TranslatePline();

private:
	//���ݳ�ʼ��
	void InitData();
	//����ʵ���ǲ���ֱ�߻�Բ��
	bool IsStandard(AcDbEntity* pEnt) const;
	//���������߶μ���
	AcArray<SPlineData> CalculateComponentCurve(const AcArray<AcDbEntity*>& arrPointer);
	//���������
	void CreatePolyline(const AcArray<SPlineData>& arrPlineData);

#pragma region ���������߶μ���
	void ConnectPolyline(AcArray<AcDbEntity*>& arrpChild, AcArray<SPlineData>& arrPline) const;	//���Ӷ����
	AcGePoint3dArray GetSumPointForEnt(const AcArray<AcDbEntity*>& EntPointerArr) const;		//�õ�����������ʵ��������յ�
	AcGePoint3dArray GetSingleElementOnArr(const AcGePoint3dArray& SumPointArr) const;			//�õ������еĵ�����
	AcGePoint3dArray GetBothSamePtArr(const AcGePoint3dArray& SumPointArr) const;				//�õ�������������ͬ������鼯��
	AcArray<AcDbEntity*> SortChildEnts(AcArray<AcDbEntity*>& EntPointerArr, const AcGePoint3d& singlePt) const;//��ʵ�尴���ӵ�˳���ź�
	AcDbEntity* GetEntByPointOnArr(const AcGePoint3d& point, const AcArray<AcDbEntity*>& EntPointerArr) const;//ͨ����õ������е�ʵ��
	AcGePoint3d GetAnotherPoint(AcDbEntity* pEnt, const AcGePoint3d& point) const;				//�õ���һ����
#pragma endregion

#pragma region ���������
	void CreatePolylineByArr(AcArray<AcDbEntity*>& polyEntArr);			//�������鴴�������;
	void GetEntStartAndEndPoint(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt,
		const AcGePoint3dArray& singlePtArr) const;						//�õ������е�һ��ʵ������Ͷ˵�;
	AcGePoint3d GetAnotherElement(const AcGePoint3dArray& pointArr, const AcGePoint3d& point) const;//�õ���������һ��Ԫ�ص�ֵ
	void GetPolylinePointsAndBulges(const AcArray<AcDbEntity*>& polyEntArr, const AcGePoint3d& point, AcGePoint3dArray& polylinePointArr,
		AcArray<double>& polylineBulgeArr) const;						//�õ�����ߵĵ��͹��;
	double GetEntBulge(AcDbCurve*& pCurve) const;						//�õ����ʵ���͹��;
	void GetFirstEntInfor(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt, double& dBulge) const;
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& polylinePointArr, const AcArray<double>& polylineBulgeArr,
		bool bClosed,AcDbEntity* pProEnt) const;//���������;
#pragma endregion

private:
	//��������
	int m_nConstructType;		

	//����
	double m_dTol;		
	AcGeTol m_tol;

	//Ҫ������ʵ��ָ��
	AcArray<AcDbEntity*> m_arrPointer;

	//�����
	AcArray<SPlineData> m_arrPline;
	AcArray<SPlineData> m_arrNewPline;

};

