#include "StdAfx.h"
#include "CAttBlkJig.h"
#include "PhdBlock.h"
#include "PhdInline.h"


CAttBlkJig::CAttBlkJig()
	:m_pEntDrag(NULL), m_nSection(0),  m_ptBase(AcGePoint3d::kOrigin)
{
}

CAttBlkJig::~CAttBlkJig()
{
}

bool CAttBlkJig::BeginDrag(const AcDbObjectId& idBlkDef, AcDbBlockReference*& pEntDrag)
{
	m_pEntDrag = PhdBlock::CreateAttBlkRef(idBlkDef, AcGePoint3d::kOrigin);

	DragStatus st = kNormal;
	while (kNormal == st && m_nSection < 1)
	{
		if (0 == m_nSection)
		{
			setDispPrompt(_T("\nָ�������:"));
			st = drag();
		}
		m_nSection++;
	}

	if (st != kNormal || m_nSection < 1)
	{
		DEL(m_pEntDrag);
		return false;
	}
	//�޸�����
	m_pEntDrag->setPosition(AcGePoint3d::kOrigin);
	m_pEntDrag->setRotation(0);
	AcGeMatrix3d matrMove;
	AcGeVector3d vecMove(m_ptBase.x , m_ptBase.y ,m_ptBase.z );
	matrMove.setToTranslation(vecMove);
	m_pEntDrag->transformBy(matrMove);

	pEntDrag = m_pEntDrag;
	return true;
}

ZcEdJig::DragStatus CAttBlkJig::sampler()
{//AcEdJig::kNoNegativeResponseAccepted//�����ܸ���	AcEdJig::kNoZeroResponseAccepted//��������
	setUserInputControls((AcEdJig::UserInputControls)
		(kAccept3dCoordinates	//������ά��
			| kNullResponseAccepted));	//���ܿ�����

	DragStatus st = kNormal;
	if (0 == m_nSection)
	{
		AcGePoint3d pt;
		st = acquirePoint(pt);
		if (kNormal == st)
		{
			if (pt.isEqualTo(m_ptBase))
				st = kNoChange;
			else
				m_ptBase = pt;
		}
	}

	return st;
}

Adesk::Boolean CAttBlkJig::update()
{
	m_pEntDrag->setPosition(m_ptBase);
	
	return true;
}

AcDbEntity* CAttBlkJig::entity() const
{
	return m_pEntDrag;
}
