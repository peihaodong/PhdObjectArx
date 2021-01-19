#include "StdAfx.h"
#include "CBlockJig.h"



CBlockJig::CBlockJig()
	:m_pEntDrag(NULL), m_nSection(0), m_dAngle(0)
	, m_ptBase(AcGePoint3d::kOrigin)
	, m_nType(2)
	, m_dScale(1)
	, m_apPhdArxInline(std::make_shared<Phd::PhdArxInline>())
	, m_apPhdArxUtility(std::make_shared<Phd::PhdArxUtility>())
{
}

CBlockJig::~CBlockJig()
{
}

void CBlockJig::SetType(int nType)
{
	m_nType = nType;
}

void CBlockJig::SetScale(double dScale)
{
	if (dScale > 0)
		m_dScale = dScale;
}

bool CBlockJig::BeginDrag(const AcDbObjectId& idBlkDef, AcDbBlockReference*& pEntDrag)
{
	m_pEntDrag = new AcDbBlockReference(AcGePoint3d::kOrigin,idBlkDef);
	if (m_dScale != 1)
	{
		m_apPhdArxUtility->ModifyEntByScale(m_pEntDrag,m_dScale,AcGePoint3d::kOrigin);
	}

	DragStatus st = kNormal;
	while (kNormal == st && m_nSection < m_nType)
	{
		if (0 == m_nSection)
		{
			setDispPrompt(_T("\n指定插入点:"));
			st = drag();
		}
		else if (1 == m_nSection)
		{
			setDispPrompt(_T("\n指定旋转角度<0>:"));
			st = drag();
			int a = 0;
		}
		m_nSection++;
	}

	if (st == kNull && m_nSection == m_nType)
	{
		m_dAngle = 0;
		m_pEntDrag->setRotation(m_dAngle);
	}
	else if (st != kNormal || m_nSection < m_nType)
	{
		DEL(m_pEntDrag);
		return false;
	}

	pEntDrag = m_pEntDrag;
	return true;
}

ZcEdJig::DragStatus CBlockJig::sampler()
{//AcEdJig::kNoNegativeResponseAccepted//不接受负数	AcEdJig::kNoZeroResponseAccepted//不接受零
	setUserInputControls((AcEdJig::UserInputControls)
		(kAccept3dCoordinates	//接受三维点
			| kNullResponseAccepted));	//接受空输入

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
	else if (1 == m_nSection)
	{
		double dAngle = m_dAngle;
		st = acquireAngle(dAngle, m_ptBase);
		if (kNormal == st)
		{
			if (m_apPhdArxInline->IsEqual(dAngle, m_dAngle))
				st = kNoChange;
			else
				m_dAngle = dAngle;
		}
	}

	return st;
}

Adesk::Boolean CBlockJig::update()
{
	m_pEntDrag->setPosition(m_ptBase);
	m_pEntDrag->setRotation(m_dAngle);

	return true;
}

AcDbEntity* CBlockJig::entity() const
{
	return m_pEntDrag;
}
