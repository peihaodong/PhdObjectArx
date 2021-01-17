#pragma once

struct SCircleInfo
{
	AcDbObjectId m_id;
	double m_dRadius;			//�뾶
};

struct SPlineInfo
{
	AcDbObjectId m_id;
	double m_dPerimeter;			//�ܳ�
	double m_dArea;					//���
	int m_nSegCount;				//����
	AcArray<double> m_arrBulge;		//ÿ��͹��
	AcGeVector3d m_firstNormal;			//ƽ�淨����
};

struct SEllipseInfo
{
	AcDbObjectId m_id;
	double m_dMajorRadius;		//����뾶
	double m_dMinorRadius;		//����뾶
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

#pragma region ɸѡԲ
	bool FiltrateCircle();
	SCircleInfo AnalyzeCircle(const AcDbObjectId& idEnt) const;
	bool IsEqual(const SCircleInfo& circle1,const SCircleInfo& circle2) const;
	void ModifyCircleDiameter(const std::vector<SCircleInfo>& vecCircle) const;
	void GetEntId(const std::vector<SCircleInfo>& vecCir);
#pragma endregion

#pragma region ɸѡ�����
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

#pragma region ɸѡ��Բ
	bool FiltrateEllipse();
	SEllipseInfo AnalyzeEllipse(const AcDbObjectId& idEnt) const;
	bool IsEqual(const SEllipseInfo& ellipse1, const SEllipseInfo& ellipse2) const;
	void GetEntId(const std::vector<SEllipseInfo>& vecEll);
#pragma endregion
	

private:
	AcDbObjectIdArray m_arridSelled;	
	AcDbObjectId m_idEnt;
	int m_nEntType;	//0:Բ	1:�����	2:��Բ
	double m_dDiameter;	//ֱ��

	AcDbObjectIdArray m_arridFiltrate;
};

