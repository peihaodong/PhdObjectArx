#include "StdAfx.h"
#include "CAjmdlxJig.h"


CAjmdlxCsm::CAjmdlxCsm(const AcGePoint3d& pt, double dT1, double dT2, double dR,
	double dAdd /*= 0.01*/)
	:m_bAppend(false)
	,m_ptBase(pt)
	,m_dT1(dT1)
	,m_dT2(dT2)
	,m_dR(dR)
	,m_dAdd(dAdd)
	,m_pPolyline(NULL)
	, m_apPhdArxUtility(std::make_shared<Phd::PhdArxUtility>())
	,m_apPhdArxEntity(std::make_shared<Phd::PhdArxEntity>())
{
	
}

CAjmdlxCsm::~CAjmdlxCsm()
{
	if (!m_bAppend)
	{
		DEL(m_pPolyline);
	}
}

void CAjmdlxCsm::SetBasePoint(const AcGePoint3d& pt)
{
	assertWriteEnabled();
	m_ptBase = pt;
}

void CAjmdlxCsm::SetT1(double dT1)
{
	assertWriteEnabled();
	m_dT1 = dT1;
}

void CAjmdlxCsm::SetT2(double dT2)
{
	assertWriteEnabled();
	m_dT2 = dT2;
}

void CAjmdlxCsm::SetR(double dR)
{
	assertWriteEnabled();
	m_dR = dR;
}

void CAjmdlxCsm::SetAdd(double dAdd)
{
	assertWriteEnabled();
	m_dAdd = dAdd;
}

AcDbObjectId CAjmdlxCsm::Append()
{
	m_bAppend = true;
	AcDbObjectId idPolyline = m_apPhdArxUtility->PostToModelSpace(m_pPolyline);
	return idPolyline;
}

Adesk::Boolean CAjmdlxCsm::worldDraw(AcGiWorldDraw* mode)
{
	DEL(m_pPolyline);
	//绘制直线
	double dMin = 0, dMax = 0;
	if (m_dT2 > m_dT1)
	{
		dMin = m_dT1;
		dMax = m_dT2;
	}
	else
	{
		dMin = m_dT2;
		dMax = m_dT1;
	}
	AcGePoint3dArray arrpt;
	for (double t = dMin; t < dMax; t += m_dAdd)
	{
		AcGePoint3d pt;
		pt.x = m_ptBase.x + m_dR * t * cos(t);
		pt.y = m_ptBase.y + m_dR * t * sin(t);
		pt.z = m_ptBase.z;
		arrpt.append(pt);
	}
	AcGePoint3d ptEnd;
	ptEnd.x = m_ptBase.x + m_dR * dMax * cos(dMax);
	ptEnd.y = m_ptBase.y + m_dR * dMax * sin(dMax);
	ptEnd.z = m_ptBase.z;
	arrpt.append(ptEnd);

	m_pPolyline = m_apPhdArxEntity->CreatePolyline(arrpt);
	mode->geometry().draw(m_pPolyline);

	return Adesk::kTrue;
}


//////////////////////////////////////////////////////////////////////////

CAjmdlxJig::CAjmdlxJig( double dT1, double dT2, double dR,
	double dAdd /*= 0.01*/)
	:m_ptBase(AcGePoint3d::kOrigin)
	,m_dT1(dT1)
	,m_dT2(dT2)
	,m_dR(dR)
	,m_dAdd(dAdd)
	,m_pAjmdlxCsm(NULL)
{
}


CAjmdlxJig::~CAjmdlxJig()
{
}

bool CAjmdlxJig::BeginDrag(CAjmdlxCsm*& pDragEnt)
{
	m_pAjmdlxCsm = new CAjmdlxCsm(m_ptBase,m_dT1,m_dT2,m_dR,m_dAdd);

	DragStatus st = kNormal;
	CString str;
	str.Format(_T("\n%s:"),_T("指定位置"));
	setDispPrompt(str);
	st = drag();
	if (kNormal != st)
	{
		DEL(m_pAjmdlxCsm);
		return false;
	}

	pDragEnt = m_pAjmdlxCsm;
	return true;
}

AcDbEntity* CAjmdlxJig::entity() const
{
	return m_pAjmdlxCsm;
}

ZcEdJig::DragStatus CAjmdlxJig::sampler()
{
	setUserInputControls((AcEdJig::UserInputControls)
		(kAccept3dCoordinates
			| kNullResponseAccepted));

	DragStatus st = kNormal;

	AcGePoint3d pt;
	st = acquirePoint(pt);
	if (kNormal == st)
	{
		if (pt.isEqualTo(m_ptBase))
			st = kNoChange;
		else
			m_ptBase = pt;
	}

	return st;
}

Adesk::Boolean CAjmdlxJig::update()
{
	m_pAjmdlxCsm->SetBasePoint(m_ptBase);
	return true;
}

