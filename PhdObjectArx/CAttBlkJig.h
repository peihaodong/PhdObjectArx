#pragma once


//���Կ�����϶�
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
	AcDbBlockReference* m_pEntDrag;	//Ҫ�϶���ʵ��
	AcGePoint3d m_ptBase;	//����
	int m_nSection;			//�׶�

};