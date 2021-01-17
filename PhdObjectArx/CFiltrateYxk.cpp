#include "StdAfx.h"
#include "CFiltrateYxk.h"
#include "../../PhdNotes/NameSpace/PhdUiPr.h"
#include "../../PhdNotes/NameSpace/PhdUtility.h"
#include "../../PhdNotes/NameSpace/PhdSelSet.h"
#include "../../PhdNotes/NameSpace/PhdConver.h"
#include "../../PhdNotes/NameSpace/PhdEntity.h"



CFiltrateYxk::CFiltrateYxk()
	:m_nEntType(-1)
	,m_dDiameter(0)
{
}


CFiltrateYxk::~CFiltrateYxk()
{
}

bool CFiltrateYxk::Start()
{
	//��ѡҪɸѡ��ʵ��
	if (!SelEnts())
		return false;
	ClearSelectedState();
	//ѡȡ����ʵ��
	if (!SelSingleEnt())
		return false;

	if (0 == m_nEntType)
	{//Բ
		int initFlag = RSG_NOZERO + RSG_NONEG;	//����Ǹ�
		if (!PhdUiPr::GetDouble(_T("����Բֱ��"), m_dDiameter,
			m_dDiameter, initFlag))
			return false;
		if (!FiltrateCircle())
			return false;
	}
	else if (1 == m_nEntType)
	{//�����
		if (!FiltratePline())
			return false;
	}
	else if (2 == m_nEntType)
	{//��Բ
		if (!FiltrateEllipse())
			return false;
	}

	ShowCount();//��ʾ����
	PhdUtility::SetEntSelected(m_arridFiltrate);//����ʵ�屻ѡ��

	return true;
}

bool CFiltrateYxk::ShowDifferent(const AcDbObjectId& id1, const AcDbObjectId& id2) const
{
	if (!IsHole(id1))
	{
		acutPrintf(_T("\n�������ο�"));
		return false;
	}
	if (!IsHole(id2))
	{
		acutPrintf(_T("\n�������ο�"));
		return false;
	}

	SPlineInfo info1 = AnalyzePline(id1);
	SPlineInfo info2 = AnalyzePline(id2);
	IsEqualShow(info1, info2);
	return true;
}

bool CFiltrateYxk::SelEnts()
{
	resbuf* pRb = acutBuildList(-4, _T("<OR"), 
		RTDXF0, _T("CIRCLE"), RTDXF0, _T("LWPOLYLINE"),RTDXF0,_T("ELLIPSE"),
		-4, _T("OR>"),RTNONE);
	if (!PhdSelSet::SelEnts(_T("ѡȡɸѡ��Χ"),pRb, m_arridSelled))
		return false;
	
	return true;
}

bool CFiltrateYxk::SelSingleEnt()
{
	AcArray<AcRxClass*> arrclassType;
	arrclassType.append(AcDbCircle::desc());
	arrclassType.append(AcDbPolyline::desc());
	arrclassType.append(AcDbEllipse::desc());
	AcGePoint3d pt;
	if (!PhdUiPr::SelEnt(_T("ѡȡҪɸѡ�����ο�"), arrclassType, m_idEnt, pt))
		return false;

	AcDbEntityPointer pEnt(m_idEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	if (pEnt->isKindOf(AcDbCircle::desc()))
	{
		m_nEntType = 0;
		AcDbCircle* pClrcle = AcDbCircle::cast(pEnt);
		m_dDiameter = pClrcle->radius() * 2;
	}	
	else if (pEnt->isKindOf(AcDbPolyline::desc()))
		m_nEntType = 1;
	else if (pEnt->isKindOf(AcDbEllipse::desc()))
		m_nEntType = 2;

	return true;
}

void CFiltrateYxk::ClearSelectedState() const
{
	acedSSSetFirst(NULL, NULL);	//��ѡ��״̬���
}

void CFiltrateYxk::ShowCount() const
{
	int nCount = m_arridFiltrate.length();
	CString str;
	str.Format(_T("\n��ͬ���ο�����%d��"),nCount);
	acutPrintf(str);
}

bool CFiltrateYxk::FiltrateCircle()
{
	//������
	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), true);

	SCircleInfo info = AnalyzeCircle(m_idEnt);

	std::vector<SCircleInfo> vecInfo;
	int nCount = m_arridSelled.length();
	for (int i = 0; i < nCount; i++)
	{
		AcDbObjectId idTemp = m_arridSelled[i];
		if (m_idEnt == idTemp)
			continue;
		SCircleInfo infoTemp = AnalyzeCircle(idTemp);
		if (IsEqual(info,infoTemp))
			vecInfo.push_back(infoTemp);

		PhdUtility::SetProgressBar(i, nCount);
	}
	vecInfo.push_back(info);

	ModifyCircleDiameter(vecInfo);

	GetEntId(vecInfo);

	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), false);

	return true;
}

SCircleInfo CFiltrateYxk::AnalyzeCircle(const AcDbObjectId& idEnt) const
{
	SCircleInfo circle;
	AcDbObjectPointer<AcDbCircle> pCircle(idEnt,AcDb::kForRead);
	if (Acad::eOk != pCircle.openStatus())
		return circle;
	circle.m_dRadius = pCircle->radius();
	circle.m_id = pCircle->objectId();
	return circle;
}

bool CFiltrateYxk::IsEqual(const SCircleInfo& circle1, const SCircleInfo& circle2) const
{
// 	if (circle1.m_dRadius == circle2.m_dRadius)
// 		return true;
// 	else
// 		return false;

	if (PhdInline::IsEqual(circle1.m_dRadius, circle2.m_dRadius))
		return true;
	else
		return false;
}

bool CFiltrateYxk::IsEqual(const SEllipseInfo& ellipse1, const SEllipseInfo& ellipse2) const
{
// 	if (ellipse1.m_dMajorRadius == ellipse2.m_dMajorRadius &&
// 		ellipse1.m_dMinorRadius == ellipse2.m_dMinorRadius)
// 		return true;
// 	else
// 		return false;

	if (PhdInline::IsEqual(ellipse1.m_dMajorRadius, ellipse2.m_dMajorRadius) &&
		PhdInline::IsEqual(ellipse1.m_dMinorRadius, ellipse2.m_dMinorRadius))
		return true;
	else
		return false;
}

bool CFiltrateYxk::IsEqual(const SPlineInfo& pline1, const SPlineInfo& pline2) const
{
	if (!PhdInline::IsEqual(pline1.m_dPerimeter, pline2.m_dPerimeter) ||
		!PhdInline::IsEqual(pline1.m_dArea, pline2.m_dArea) ||
		!PhdInline::IsEqual(pline1.m_nSegCount, pline2.m_nSegCount) )
	{
		return false;
	}

	if (pline1.m_firstNormal != pline2.m_firstNormal)
		return false;

// 	for (int i = 0; i < pline1.m_nSegCount; i++)
// 	{
// 		double dBulge1 = pline1.m_arrBulge[i];
// 		double dBulge2 = pline2.m_arrBulge[i];
// 		if (!PhdInline::IsEqual(dBulge1, dBulge2))
// 			return false;
// 	}

	return true;
}

bool CFiltrateYxk::IsEqualShow(const SPlineInfo& pline1, const SPlineInfo& pline2) const
{
	CString str;
	if (!PhdInline::IsEqual(pline1.m_dPerimeter, pline2.m_dPerimeter))
	{
		str.Format(_T("\nͼ��1���ܳ���%lf��ͼ��2���ܳ���%lf"), pline1.m_dPerimeter, pline2.m_dPerimeter);
		acutPrintf(str);
	}
	if (!PhdInline::IsEqual(pline1.m_dArea, pline2.m_dArea))
	{
		str.Format(_T("\nͼ��1�������%lf��ͼ��2�������%lf"), pline1.m_dArea, pline2.m_dArea);
		acutPrintf(str);
	}
	if (!PhdInline::IsEqual(pline1.m_nSegCount, pline2.m_nSegCount))
	{
		str.Format(_T("\nͼ��1�Ķ�����%d��ͼ��2�Ķ�����%d"), pline1.m_nSegCount, pline2.m_nSegCount);
		acutPrintf(str);
	}
	if (pline1.m_firstNormal != pline2.m_firstNormal)
	{
		str.Format(_T("\nͼ��1�ķ�������%s��ͼ��2�ķ�������%s"),
			PhdConver::VecToStr(pline1.m_firstNormal), PhdConver::VecToStr(pline2.m_firstNormal));
		acutPrintf(str);
	}


// 	for (int i = 0; i < pline1.m_nSegCount; i++)
// 	{
// 		double dBulge1 = pline1.m_arrBulge[i];
// 		double dBulge2 = pline2.m_arrBulge[i];
// 		if (!PhdInline::IsEqual(dBulge1, dBulge2))
// 		{
// 			str.Format(_T("\nͼ��1�ĵ�%d��͹�ȣ�%lf��ͼ��2�ĵ�%d��͹�ȣ�%lf"),
// 				dBulge1, dBulge2);
// 			acutPrintf(str);
// 		}
// 	}

	return true;
}

void CFiltrateYxk::ModifyCircleDiameter(const std::vector<SCircleInfo>& vecCircle) const
{
	for (int i = 0; i < vecCircle.size(); i++)
	{
		AcDbObjectId idEnt = vecCircle[i].m_id;
		AcDbObjectPointer<AcDbCircle> pCir(idEnt,AcDb::kForWrite);
		if (Acad::eOk != pCir.openStatus())
			continue;
		pCir->setRadius(m_dDiameter/2);
	}
}

void CFiltrateYxk::GetEntId(const std::vector<SCircleInfo>& vecCir)
{
	for (int i = 0; i < vecCir.size(); i++)
	{
		m_arridFiltrate.append(vecCir[i].m_id);
	}
}

void CFiltrateYxk::GetEntId(const std::vector<SEllipseInfo>& vecEll)
{
	for (int i = 0; i < vecEll.size(); i++)
	{
		m_arridFiltrate.append(vecEll[i].m_id);
	}
}

void CFiltrateYxk::GetEntId(const std::vector<SPlineInfo>& vecPline)
{
	for (int i = 0; i < vecPline.size(); i++)
	{
		m_arridFiltrate.append(vecPline[i].m_id);
	}
}

bool CFiltrateYxk::FiltratePline()
{
	//�жϵ���ʵ���Ƿ��ǿ�
	if (!IsHole(m_idEnt))
	{
		acutPrintf(_T("\n��ͼ�β������ο�"));
		return false;
	}

	//������
	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), true);

	SPlineInfo info = AnalyzePline(m_idEnt);

	std::vector<SPlineInfo> vecInfo;
	int nCount = m_arridSelled.length();
	for (int i = 0; i < nCount; i++)
	{
		AcDbObjectId idTemp = m_arridSelled[i];
		if (m_idEnt == idTemp)
			continue;
		if (!IsHole(idTemp))
			continue;

		SPlineInfo infoTemp = AnalyzePline(idTemp);
		if (IsEqual(info, infoTemp))
			vecInfo.push_back(infoTemp);

		PhdUtility::SetProgressBar(i,nCount);
	}
	vecInfo.push_back(info);

	GetEntId(vecInfo);

	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), false);

	return true;
}

SPlineInfo CFiltrateYxk::AnalyzePline(const AcDbObjectId& idEnt) const
{
	SPlineInfo pline;
	AcDbObjectPointer<AcDbPolyline> pPline(idEnt, AcDb::kForRead);
	if (Acad::eOk != pPline.openStatus())
		return pline;
	
	pline.m_id = pPline->objectId();
	pline.m_dPerimeter = GetPlinePerimeter(pPline);		//�ܳ�
	pline.m_dArea = GetPlineArea(pPline);				//���
	pline.m_nSegCount = GetPlineSegCount(pPline);		//����
//	pline.m_arrBulge = GetPlineBulge(pPline);			//͹��
	pline.m_firstNormal = GetPlineFirstNormal(pPline);	//������

	return pline;
}

int CFiltrateYxk::GetPlineSegCount(AcDbPolyline* pPline) const
{
	bool bIsClosed = pPline->isClosed();
	int nNumVerts = pPline->numVerts();
	if (bIsClosed)
		return nNumVerts;
	else
		return nNumVerts - 1;
}

double CFiltrateYxk::GetPlineArea(AcDbPolyline* pPline) const
{
	AcArray<AcDbEntity*> arrpEnt;
	arrpEnt.append(pPline);
	AcArray<AcDbRegion*> arrpRegion;
	
	if (!PhdEntity::CreateRegion(arrpEnt, arrpRegion))
		return 0;

	int nCount = arrpRegion.length();
	double dArea = 0;
	arrpRegion[0]->getArea(dArea);

	for (int i = 0; i < nCount; i++)
		delete arrpRegion[i];

	return dArea;
}

AcArray<double> CFiltrateYxk::GetPlineBulge(AcDbPolyline* pPline) const
{
	AcArray<double> arrBulge;
	int nSegCount = GetPlineSegCount(pPline);
	double dBulge = 0;
	for (int i = 0; i < nSegCount; i++)
	{
		if (Acad::eOk != pPline->getBulgeAt(i,dBulge))
			continue;
		arrBulge.append(dBulge);
	}

	return arrBulge;
}

AcGeVector3d CFiltrateYxk::GetPlineFirstNormal(AcDbPolyline* pPline) const
{
	AcGeVector3d vec1, vec2;
	AcGePoint3d pt1, pt2, pt3;
	
	int nSegCount = GetPlineSegCount(pPline);
	for (int i = 0; i < nSegCount; i++)
	{
		pPline->getPointAt(i, pt1);
		pPline->getPointAt(i+1, pt2);
		pPline->getPointAt(i+2, pt3);
		vec1 = pt2 - pt1;
		vec2 = pt3 - pt2;
		if (!vec1.isParallelTo(vec2))
			break;
	}

	AcGeVector3d vecNormal = vec1.crossProduct(vec2).normal();
	return vecNormal;
}

bool CFiltrateYxk::IsHole(const AcDbObjectId& idEnt) const
{
	AcDbObjectPointer<AcDbPolyline> pPline(idEnt,AcDb::kForRead);
	if (Acad::eOk != pPline.openStatus())
		return false;

	//�պ�
	bool bClosed = pPline->isClosed();
	if (!bClosed)
	{
		AcGePoint3d ptStart, ptEnd;
		pPline->getStartPoint(ptStart);
		pPline->getEndPoint(ptEnd);
		if (!ptStart.isEqualTo(ptEnd))
			return false; 
	}
	//����
	AcArray<AcDbEntity*> arrpEnt;
	arrpEnt.append(pPline);
	AcArray<AcDbRegion*> arrpRegion;
	if (!PhdEntity::CreateRegion(arrpEnt, arrpRegion))
		return false;
	int nCount = arrpRegion.length();
	for (int i = 0; i < nCount; i++)
		delete arrpRegion[i];

	if (nCount != 1)
		return false;
	else
		return true;
}

double CFiltrateYxk::GetPlinePerimeter(AcDbPolyline* pPline) const
{
	return PhdUtility::GetCurveLength(pPline);
}

bool CFiltrateYxk::FiltrateEllipse()
{
	//������
	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), true);

	SEllipseInfo info = AnalyzeEllipse(m_idEnt);

	std::vector<SEllipseInfo> vecInfo;
	int nCount = m_arridSelled.length();
	for (int i = 0; i < nCount; i++)
	{
		AcDbObjectId idTemp = m_arridSelled[i];
		if (m_idEnt == idTemp)
			continue;
		SEllipseInfo infoTemp = AnalyzeEllipse(idTemp);
		if (IsEqual(info, infoTemp))
			vecInfo.push_back(infoTemp);

		PhdUtility::SetProgressBar(i, nCount);
	}
	vecInfo.push_back(info);

	GetEntId(vecInfo);

	PhdUtility::ShowProgressBar(_T("ɸѡ���ο�"), false);

	return true;
}

SEllipseInfo CFiltrateYxk::AnalyzeEllipse(const AcDbObjectId& idEnt) const
{
	SEllipseInfo ell;
	AcDbObjectPointer<AcDbEllipse> pEll(idEnt, AcDb::kForRead);
	if (Acad::eOk != pEll.openStatus())
		return ell;
	ell.m_dMajorRadius = pEll->majorRadius();
	ell.m_dMinorRadius = pEll->minorRadius();
	ell.m_id = pEll->objectId();
	return ell;
}
