#include "StdAfx.h"
#include "CCurveToPline.h"


CCurveToPline::CCurveToPline(const AcDbObjectIdArray& idArr)
	:m_nConstructType(0)
{
	//初始化数据
	InitData();
	//将要处理的实体指针添加到成员函数
	for (int i = 0; i < idArr.length(); i++)
	{
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != acdbOpenAcDbEntity(pEnt,idArr[i],AcDb::kForRead))
			continue;
		if (IsStandard(pEnt))
			m_arrPointer.append(pEnt);
		else
			pEnt->close();
	}
	//多段线组成线段计算
	m_arrPline = CalculateComponentCurve(m_arrPointer);
}

CCurveToPline::CCurveToPline(const AcArray<AcDbEntity*>& pArr)
	:m_nConstructType(1)
{
	//初始化数据
	InitData();
	//将要处理的实体指针添加到成员函数
	for (int i = 0; i < pArr.length(); i++)
	{
		if (IsStandard(pArr[i]))
			m_arrPointer.append(pArr[i]);
	}
	//多段线组成线段计算
	m_arrPline = CalculateComponentCurve(m_arrPointer);
}

CCurveToPline::~CCurveToPline()
{
}

AcArray<AcDbPolyline*> CCurveToPline::TranslatePline()
{
	//创建多段线
	CreatePolyline(m_arrPline);
	//
	AcArray<AcDbPolyline*> arrPline;
	for (int i = 0; i < m_arrNewPline.length(); i++)
	{
		arrPline.append(m_arrNewPline[i].m_pPline);
	}
	return arrPline;
}

void CCurveToPline::InitData()
{
	//设置公差
	m_dTol = 0.00001;
	m_tol.setEqualPoint(m_dTol);
}

bool CCurveToPline::IsStandard(AcDbEntity* pEnt) const
{
	if (pEnt->isKindOf(AcDbLine::desc()) || pEnt->isKindOf(AcDbArc::desc()))
		return true;
	else
		return false;
}

AcArray<SPlineData> CCurveToPline::CalculateComponentCurve(const AcArray<AcDbEntity*>& arrPointer)
{
	AcArray<SPlineData> arrPline;

	AcArray<AcDbEntity*> EntPointerArr = arrPointer;
	while (EntPointerArr.length())
	{
		ConnectPolyline(EntPointerArr, arrPline);
	}

	return arrPline;
}

void CCurveToPline::CreatePolyline(const AcArray<SPlineData>& arrPlineData)
{
	for (int i = 0; i < arrPlineData.length(); i++)
	{
		AcArray<AcDbEntity*> arrEnt = arrPlineData[i].m_arrEntPointer;
		CreatePolylineByArr(arrEnt);//创建多段线
	}
}

AcDbPolyline* CCurveToPline::CreatePolyline(const AcGePoint3dArray& polylinePointArr, const AcArray<double>& polylineBulgeArr,
	bool bClosed, AcDbEntity* pProEnt) const
{
	AcDbPolyline *pPoly = new AcDbPolyline();
	for (int i = 0; i < polylinePointArr.length(); i++)
	{
		pPoly->addVertexAt(i, polylinePointArr[i].convert2d(AcGePlane::kXYPlane), polylineBulgeArr[i]);
	}
	if (bClosed)
		pPoly->setClosed(true);
	if (pProEnt)
		pPoly->setPropertiesFrom(pProEnt);

	return pPoly;
}

void CCurveToPline::ConnectPolyline(AcArray<AcDbEntity*>& arrpChild, AcArray<SPlineData>& arrPline) const
{
	AcGePoint3dArray SumPointArr = GetSumPointForEnt(arrpChild);//得到id数组中所有实体的起点和终点
	AcGePoint3dArray singlePtArr = GetSingleElementOnArr(SumPointArr);//数组中单个点的数组
	if (singlePtArr.length() != 0)
	{//有单个点
		AcArray<AcDbEntity*> arrpOnePline = SortChildEnts(arrpChild, singlePtArr.at(0));//把实体按连接的顺序排好
		if (arrpOnePline.length() > 1)
		{
			SPlineData sp;
			sp.m_arrEntPointer = arrpOnePline;
			arrPline.append(sp);
		}
	}
	else
	{
		AcGePoint3dArray bothSamePtArr = GetBothSamePtArr(SumPointArr);//数组中两个相同点的数组集合
		if (bothSamePtArr.length() == 0)
			return;

		AcArray<AcDbEntity*> arrpOnePline = SortChildEnts(arrpChild, bothSamePtArr.at(0));
		if (arrpOnePline.length() > 1)
		{
			SPlineData sp;
			sp.m_arrEntPointer = arrpOnePline;
			arrPline.append(sp);
		}
	}
}

AcGePoint3dArray CCurveToPline::GetSumPointForEnt(const AcArray<AcDbEntity*>& EntPointerArr) const
{
	AcGePoint3dArray sumPtArr;
	for (int i = 0; i < EntPointerArr.length(); i++)
	{
		AcDbCurve* pCurve = AcDbCurve::cast(EntPointerArr.at(i));
		AcGePoint3d startPt, endPt;
		pCurve->getStartPoint(startPt);
		pCurve->getEndPoint(endPt);
		sumPtArr.append(startPt);
		sumPtArr.append(endPt);
	}
	return sumPtArr;
}

AcGePoint3dArray CCurveToPline::GetSingleElementOnArr(const AcGePoint3dArray& SumPointArr) const
{
	AcGePoint3dArray singleArr;
	for (int i = 0; i < SumPointArr.length(); i++)
	{
		int nFlag = 0;
		for (int j = 0; j < SumPointArr.length(); j++)
		{
			if (SumPointArr.at(i).isEqualTo(SumPointArr.at(j), m_tol))
			{
				nFlag++;
			}
		}
		if (1 == nFlag)
		{
			singleArr.append(SumPointArr.at(i));
		}
	}

	return singleArr;
}

AcGePoint3dArray CCurveToPline::GetBothSamePtArr(const AcGePoint3dArray& SumPointArr) const
{
	AcGePoint3dArray BothSamePtArr;
	for (int i = 0; i < SumPointArr.length(); i++)
	{
		int nFlag = 0;
		for (int j = 0; j < SumPointArr.length(); j++)
		{
			if (SumPointArr.at(i).isEqualTo(SumPointArr.at(j), m_tol))
			{
				nFlag++;
			}
		}
		if (2 == nFlag)
		{
			BothSamePtArr.append(SumPointArr.at(i));
		}
	}

	return BothSamePtArr;
}

AcArray<AcDbEntity*> CCurveToPline::SortChildEnts(AcArray<AcDbEntity*>& EntPointerArr, const AcGePoint3d& singlePt) const
{
	AcArray<AcDbEntity*> arrpChild;
	AcGePoint3d tempPt = singlePt;
	while (1)
	{
		AcDbEntity* pEnt = GetEntByPointOnArr(tempPt, EntPointerArr);
		EntPointerArr.remove(pEnt);
		arrpChild.append(pEnt);

		AcGePoint3d anotherPt = GetAnotherPoint(pEnt, tempPt);//得到实体的另一点
		AcGePoint3dArray SumPointArr = GetSumPointForEnt(EntPointerArr);//得到id数组中所有实体的起点和终点
		AcGePoint3dArray singlePtArr = GetSingleElementOnArr(SumPointArr);//数组中单个点的数组
		BOOL bHas = singlePtArr.contains(anotherPt);
		if (!bHas)
			break;

		tempPt = anotherPt;
	}

	return arrpChild;
}

AcDbEntity* CCurveToPline::GetEntByPointOnArr(const AcGePoint3d& point, const AcArray<AcDbEntity*>& EntPointerArr) const
{
	AcDbEntity* pEnt = NULL;
	for (int i = 0; i < EntPointerArr.length(); i++)
	{
		AcDbCurve* pCurve = AcDbCurve::cast(EntPointerArr.at(i));
		AcGePoint3d startPt, endPt;
		pCurve->getStartPoint(startPt);
		pCurve->getEndPoint(endPt);
		if (point.isEqualTo(startPt, m_tol) || point.isEqualTo(endPt, m_tol))
		{
			pEnt = EntPointerArr.at(i);
		}
	}

	return pEnt;
}

AcGePoint3d CCurveToPline::GetAnotherPoint(AcDbEntity* pEnt, const AcGePoint3d& point) const
{
	AcGePoint3d anotherPt;
	AcDbCurve* pCurve = AcDbCurve::cast(pEnt);
	AcGePoint3d startPt, endPt;
	pCurve->getStartPoint(startPt);
	pCurve->getEndPoint(endPt);
	if (point.isEqualTo(startPt, m_tol))
	{
		anotherPt = endPt;
	}
	else if (point.isEqualTo(endPt, m_tol))
	{
		anotherPt = startPt;
	}

	return anotherPt;
}

void CCurveToPline::CreatePolylineByArr(AcArray<AcDbEntity*>& polyEntArr)
{
	AcGePoint3dArray polylinePointArr;
	AcArray<double> polylineBulgeArr;

	AcDbEntity* pProEnt = polyEntArr[0];
	AcGePoint3dArray SumPointArr = GetSumPointForEnt(polyEntArr);//得到id数组中所有实体的起点和终点
	AcGePoint3dArray singlePtArr = GetSingleElementOnArr(SumPointArr);//数组中单个点的数组
	AcGePoint3d startPt, endPt;//这个多段线的真正起点和真正端点
	bool bClosed = false;
	if (singlePtArr.length() != 0)
	{
		bClosed = false;
		GetEntStartAndEndPoint(polyEntArr, startPt, endPt, singlePtArr);
		//得到多段线的点和凸度;
		GetPolylinePointsAndBulges(polyEntArr, startPt, polylinePointArr, polylineBulgeArr);
		polylinePointArr.append(endPt);
	}
	else
	{//此多段线是闭合的
		bClosed = true;
		double dBulge = 0.0;
		GetFirstEntInfor(polyEntArr, startPt, endPt, dBulge);
		polyEntArr.remove(polyEntArr.at(0));
		polylinePointArr.append(startPt);
		polylineBulgeArr.append(dBulge);
		//得到多段线的点和凸度;
		GetPolylinePointsAndBulges(polyEntArr, endPt, polylinePointArr, polylineBulgeArr);
	}

	//创建多段线;
	if (polylinePointArr.length() > 1)
	{
		AcDbPolyline* pPoly = CreatePolyline(polylinePointArr, polylineBulgeArr, bClosed, pProEnt);
		SPlineData pldata;
		pldata.m_arrEntPointer = polyEntArr;
		pldata.m_bClosed = bClosed;
		pldata.m_pPline = pPoly;
		m_arrNewPline.append(pldata);
	}
}

void CCurveToPline::GetEntStartAndEndPoint(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt, const AcGePoint3dArray& singlePtArr) const
{
	AcDbEntity* pEnt = polyEntArr.at(0);

	if (pEnt->isKindOf(AcDbCurve::desc()))
	{
		AcDbCurve* pCurve = AcDbCurve::cast(pEnt);
		AcGePoint3d tempStartPt, tempEndPt;
		pCurve->getStartPoint(tempStartPt);
		pCurve->getEndPoint(tempEndPt);
		if (singlePtArr.contains(tempStartPt))
		{
			startPt = tempStartPt;
			endPt = GetAnotherElement(singlePtArr, tempStartPt);
		}
		else if (singlePtArr.contains(tempEndPt))
		{
			startPt = tempEndPt;
			endPt = GetAnotherElement(singlePtArr, tempEndPt);
		}
	}
}

AcGePoint3d CCurveToPline::GetAnotherElement(const AcGePoint3dArray& pointArr, const AcGePoint3d& point) const
{
	AcGePoint3d anotherPt;
	int nIndex = pointArr.find(point);
	if (nIndex == 0)
	{
		anotherPt = pointArr.at(1);
	}
	else if (nIndex == 1)
	{
		anotherPt = pointArr.at(0);
	}

	return anotherPt;
}

void CCurveToPline::GetPolylinePointsAndBulges(const AcArray<AcDbEntity*>& polyEntArr, const AcGePoint3d& point, AcGePoint3dArray& polylinePointArr, AcArray<double>& polylineBulgeArr) const
{
	AcGePoint3d tempPt = point;
	for (int i = 0; i < polyEntArr.length(); i++)
	{
		AcDbEntity* pEnt = polyEntArr.at(i);
		if (pEnt->isKindOf(AcDbCurve::desc()))
		{
			AcDbCurve* pCurve = AcDbCurve::cast(pEnt);
			AcGePoint3d startPt, endPt;
			pCurve->getStartPoint(startPt);
			pCurve->getEndPoint(endPt);
			//得到这个实体的凸度;
			double dBulge = GetEntBulge(pCurve);
			if (tempPt.isEqualTo(startPt, m_tol))
			{
				tempPt = endPt;
				polylinePointArr.append(startPt);
				polylineBulgeArr.append(dBulge);
			}
			else if (tempPt.isEqualTo(endPt, m_tol))
			{
				tempPt = startPt;
				polylinePointArr.append(endPt);
				polylineBulgeArr.append(-dBulge);
			}
		}
	}
}

double CCurveToPline::GetEntBulge(AcDbCurve*& pCurve) const
{
	double dBulge = 0.0;
	if (pCurve->isKindOf(AcDbArc::desc()))
	{
		AcDbArc* pArc = AcDbArc::cast(pCurve);
		double dStartAngle = pArc->startAngle();
		double dEndAngle = pArc->endAngle();
		double dAlfa = dEndAngle - dStartAngle;

		if (dAlfa < 0.0)//如果终点角度小于起点角度;
		{
			dAlfa = 2 * (atan(1.0) * 4) + dAlfa;
		}
		dBulge = tan((dAlfa) / 4.0);
	}

	return dBulge;
}

void CCurveToPline::GetFirstEntInfor(const AcArray<AcDbEntity*>& polyEntArr, AcGePoint3d& startPt, AcGePoint3d& endPt, double& dBulge) const
{
	AcGePoint3d StartPtEnt1, EndPtEnt1;
	AcDbCurve* pCurve = AcDbCurve::cast(polyEntArr.at(0));
	pCurve->getStartPoint(StartPtEnt1);
	pCurve->getEndPoint(EndPtEnt1);
	//得到这个实体的凸度;
	dBulge = GetEntBulge(pCurve);

	pCurve = AcDbCurve::cast(polyEntArr.at(1));
	AcGePoint3d StartPtEnt2, EndPtEnt2;
	pCurve->getStartPoint(StartPtEnt2);
	pCurve->getEndPoint(EndPtEnt2);
	if (StartPtEnt1.isEqualTo(StartPtEnt2, m_tol) || StartPtEnt1.isEqualTo(EndPtEnt2, m_tol))
	{
		startPt = EndPtEnt1;
		endPt = StartPtEnt1;
		dBulge = -dBulge;
	}
	else
	{
		startPt = StartPtEnt1;
		endPt = EndPtEnt1;
	}
}

SPlineData::SPlineData()
	:m_pPline(NULL)
	,m_bClosed(false)
{

}
