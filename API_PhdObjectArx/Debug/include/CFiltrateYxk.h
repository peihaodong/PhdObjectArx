#pragma once

struct SCircleInfo
{
	AcDbObjectId m_id;
	double m_dRadius;			//半径
};

struct SPlineInfo
{
	AcDbObjectId m_id;
	double m_dPerimeter;			//周长
	double m_dArea;					//面积
	int m_nSegCount;				//段数
	AcArray<double> m_arrBulge;		//每段凸度
	AcGeVector3d m_firstNormal;			//平面法向量
};

struct SEllipseInfo
{
	AcDbObjectId m_id;
	double m_dMajorRadius;		//主轴半径
	double m_dMinorRadius;		//副轴半径
};

class CFiltrateYxk
{
public:
	CFiltrateYxk();
	~CFiltrateYxk();

	bool Start();

	bool ShowDifferent(const AcDbObjectId& id1,const AcDbObjectId& id2) const;

private:
	bool SelEnts();
	bool SelSingleEnt();
 
	void ClearSelectedState() const;
	void ShowCount() const;

#pragma region 筛选圆
	bool FiltrateCircle();
	SCircleInfo AnalyzeCircle(const AcDbObjectId& idEnt) const;
	bool IsEqual(const SCircleInfo& circle1,const SCircleInfo& circle2) const;
	void ModifyCircleDiameter(const std::vector<SCircleInfo>& vecCircle) const;
	void GetEntId(const std::vector<SCircleInfo>& vecCir);
#pragma endregion

#pragma region 筛选多段线
	bool FiltratePline();
	SPlineInfo AnalyzePline(const AcDbObjectId& idEnt) const;
	bool IsHole(const AcDbObjectId& idEnt) const;
	double GetPlinePerimeter(AcDbPolyline* pPline) const;
	int GetPlineSegCount(AcDbPolyline* pPline) const;
	double GetPlineArea(AcDbPolyline* pPline) const;
	AcArray<double> GetPlineBulge(AcDbPolyline* pPline) const;
	AcGeVector3d GetPlineFirstNormal(AcDbPolyline* pPline) const;
	bool IsEqual(const SPlineInfo& pline1, const SPlineInfo& pline2) const;
	bool IsEqualShow(const SPlineInfo& pline1, const SPlineInfo& pline2) const;
	void GetEntId(const std::vector<SPlineInfo>& vecPline);

#pragma endregion

#pragma region 筛选椭圆
	bool FiltrateEllipse();
	SEllipseInfo AnalyzeEllipse(const AcDbObjectId& idEnt) const;
	bool IsEqual(const SEllipseInfo& ellipse1, const SEllipseInfo& ellipse2) const;
	void GetEntId(const std::vector<SEllipseInfo>& vecEll);
#pragma endregion
	

private:
	AcDbObjectIdArray m_arridSelled;	
	AcDbObjectId m_idEnt;
	int m_nEntType;	//0:圆	1:多段线	2:椭圆
	double m_dDiameter;	//直径

	AcDbObjectIdArray m_arridFiltrate;

private:
	std::shared_ptr<Phd::PhdArxUiPr> m_apPhdArxUiPr;
	std::shared_ptr<Phd::PhdArxUtility> m_apPhdArxUtility;
	std::shared_ptr<Phd::PhdArxSelSet> m_apPhdArxSelSet;
	std::shared_ptr<Phd::PhdArxInline> m_apPhdArxInline;
	std::shared_ptr<Phd::PhdArxConver> m_apPhdArxConver;
	std::shared_ptr<Phd::PhdArxEntity> m_apPhdArxEntity;
};

