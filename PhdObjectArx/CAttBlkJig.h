#pragma once


//属性块参照拖动
class CAttBlkJig :public AcEdJig
{
public:
	CAttBlkJig();
	~CAttBlkJig();

	bool BeginDrag(const AcDbObjectId& idBlkDef, AcDbBlockReference*& pEntDrag);

	virtual DragStatus sampler();
	virtual Adesk::Boolean update();
	virtual AcDbEntity* entity() const;

protected:
	AcDbBlockReference* m_pEntDrag;	//要拖动的实体
	AcGePoint3d m_ptBase;	//基点
	int m_nSection;			//阶段

private:
	std::shared_ptr<Phd::PhdArxBlock> m_apPhdArxBlock;

};