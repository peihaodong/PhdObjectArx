#pragma once

//块参照拖动
class CBlockJig :public AcEdJig
{
public:
	CBlockJig();
	~CBlockJig();

	void SetType(int nType);
	void SetScale(double dScale);

	bool BeginDrag(const AcDbObjectId& idBlkDef, AcDbBlockReference*& pEntDrag);

	virtual DragStatus sampler();
	virtual Adesk::Boolean update();
	virtual AcDbEntity* entity() const;

protected:
	AcDbBlockReference* m_pEntDrag;	//要拖动的实体
	AcGePoint3d m_ptBase;	//基点
	double m_dAngle;		//角度
	int m_nSection;			//阶段

	int m_nType;//

	double m_dScale;
};

