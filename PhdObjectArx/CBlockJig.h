#pragma once

//������϶�
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
	AcDbBlockReference* m_pEntDrag;	//Ҫ�϶���ʵ��
	AcGePoint3d m_ptBase;	//����
	double m_dAngle;		//�Ƕ�
	int m_nSection;			//�׶�

	int m_nType;//

	double m_dScale;

private:
	std::shared_ptr<Phd::PhdArxInline> m_apPhdArxInline;
	std::shared_ptr<Phd::PhdArxUtility> m_apPhdArxUtility;
};

