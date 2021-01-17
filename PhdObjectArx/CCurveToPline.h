#pragma once
//多段线数据
struct SPlineData
{
	AcArray<AcDbEntity*> m_arrEntPointer;	//组成该多段线的线段指针
	AcDbPolyline* m_pPline;
	bool m_bClosed;

	SPlineData();
};

//将相连的直线或圆弧转为多段线
class CCurveToPline
{
public:
	CCurveToPline(const AcDbObjectIdArray& idArr);
	CCurveToPline(const AcArray<AcDbEntity*>& pArr);
	~CCurveToPline();

	AcArray<AcDbPolyline*> TranslatePline();

private:
	//数据初始化
	void InitData();
	//过滤实体是不是直线或圆弧
	bool IsStandard(AcDbEntity* pEnt) const;
	//多段线组成线段计算
	AcArray<SPlineData> CalculateComponentCurve(const AcArray<AcDbEntity*>& arrPointer);
	//创建多段线
	void CreatePolyline(const AcArray<SPlineData>& arrPlineData);

#pragma region 多段线组成线段计算
	void ConnectPolyline(AcArray<AcDbEntity*>& arrpChild, AcArray<SPlineData>& arrPline) const;	//连接多段线
	AcGePoint3dArray GetSumPointForEnt(const AcArray<AcDbEntity*>& EntPointerArr) const;		//得到数组中所有实体的起点和终点
	AcGePoint3dArray GetSingleElementOnArr(const AcGePoint3dArray& SumPointArr) const;			//得到数组中的单独点
	AcGePoint3dArray GetBothSamePtArr(const AcGePoint3dArray& SumPointArr) const;				//得到数组中两个相同点的数组集合
	AcArray<AcDbEntity*> SortChildEnts(AcArray<AcDbEntity*>& EntPointerArr, const AcGePoint3d& singlePt) const;//把实体按连接的顺序排好
	AcDbEntity* GetEntByPointOnArr(const AcGePoint3d& point, const AcArray<AcDbEntity*>& EntPointerArr) const;//通过点得到数组中的实体
	AcGePoint3d GetAnotherPoint(AcDbEntity* pEnt, const AcGePoint3d& point) const;				//得到另一个点
#pragma endregion

#pragma region 创建多段线
	void CreatePolylineByArr(AcArray<AcDbEntity*>& polyEntArr);			//根据数组创建多段线;
	void GetEntStartAndEndPoint(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt,
		const AcGePoint3dArray& singlePtArr) const;						//得到数组中第一个实体的起点和端点;
	AcGePoint3d GetAnotherElement(const AcGePoint3dArray& pointArr, const AcGePoint3d& point) const;//得到数组中另一个元素的值
	void GetPolylinePointsAndBulges(const AcArray<AcDbEntity*>& polyEntArr, const AcGePoint3d& point, AcGePoint3dArray& polylinePointArr,
		AcArray<double>& polylineBulgeArr) const;						//得到多段线的点和凸度;
	double GetEntBulge(AcDbCurve*& pCurve) const;						//得到这个实体的凸度;
	void GetFirstEntInfor(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt, double& dBulge) const;
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& polylinePointArr, const AcArray<double>& polylineBulgeArr,
		bool bClosed,AcDbEntity* pProEnt) const;//创建多段线;
#pragma endregion

private:
	//构造类型
	int m_nConstructType;		

	//公差
	double m_dTol;		
	AcGeTol m_tol;

	//要操作的实体指针
	AcArray<AcDbEntity*> m_arrPointer;

	//多段线
	AcArray<SPlineData> m_arrPline;
	AcArray<SPlineData> m_arrNewPline;

};

