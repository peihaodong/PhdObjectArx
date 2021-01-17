#include "StdAfx.h"
#include "PhdUtility.h"
#include "PhdInline.h"
#include "PhdConver.h"
#include "PhdEntity.h"


AcDbObjectId PhdUtility::PostToModelSpace(AcDbEntity* pEnt, AcDbDatabase *pDb /*= acdbCurDwg()*/)
{
	// 检查输入参数的有效性;
	assert(pEnt);		// 等效于assert (pEnt != NULL);

	// 获得当前图形数据库的块表;
	AcDbBlockTable *pBlkTbl = NULL;
	pDb->getBlockTable(pBlkTbl, AcDb::kForRead);

	// 获得模型空间对应的块表记录;
	AcDbBlockTableRecord *pBlkTblRcd = NULL;
	pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd, AcDb::kForWrite);
	pBlkTbl->close();

	// 将实体添加到模型空间的块表记录;
	AcDbObjectId entId;
	Acad::ErrorStatus es = pBlkTblRcd->appendAcDbEntity(entId, pEnt);
	if (es != Acad::eOk)
	{
		pBlkTblRcd->close();
		acutPrintf(_T("添加失败"));
		delete pEnt;	// 添加失败时，要delete;
		pEnt = NULL;

		return AcDbObjectId::kNull;
	}

	// 关闭模型空间块表记录和实体;
	pBlkTblRcd->close();
	pEnt->close();

	return entId;
}

AcDbObjectId PhdUtility::PostToPaperSpace(AcDbEntity* pEnt, AcDbDatabase *pDb /*= acdbCurDwg()*/)
{
	assert(pEnt);		// 等效于assert (pEnt != NULL);

						// 获得当前图形数据库的块表;
	AcDbBlockTable *pBlkTbl = NULL;
	pDb->getBlockTable(pBlkTbl, AcDb::kForRead);

	// 获得布局空间对应的块表记录;
	Acad::ErrorStatus es;
	AcDbBlockTableRecord *pBlkTblRcd = NULL;
	es = pBlkTbl->getAt(ACDB_PAPER_SPACE, pBlkTblRcd, AcDb::kForWrite);
	pBlkTbl->close();

	// 将实体添加到布局空间的块表记录;
	AcDbObjectId entId;
	es = pBlkTblRcd->appendAcDbEntity(entId, pEnt);
	if (es != Acad::eOk)
	{
		pBlkTblRcd->close();
		acutPrintf(_T("添加失败"));
		delete pEnt;	// 添加失败时，要delete;
		pEnt = NULL;

		return AcDbObjectId::kNull;
	}

	// 关闭布局空间块表记录和实体;
	pBlkTblRcd->close();
	pEnt->close();

	return entId;
}

bool PhdUtility::ModifyEntByScale(AcDbEntity* pEnt, double dScale, const AcGePoint3d& ptBase)
{
	AcGeMatrix3d mtx;
	mtx.setToScaling(dScale, ptBase);
	Acad::ErrorStatus es = pEnt->transformBy(mtx);
	if (Acad::eOk == es)
		return true;
	else
		return false;
}

bool PhdUtility::ModifyEntByScale(const AcArray<AcDbEntity*>& arrpEnt, double dScale,
	const AcGePoint3d& ptBase)
{
	AcGeMatrix3d mtx;
	mtx.setToScaling(dScale, ptBase);
	for (int i = 0; i < arrpEnt.length(); i++)
	{
		Acad::ErrorStatus es = arrpEnt[i]->transformBy(mtx);
		int a = 0;
	}
	return true;
}

AcArray<AcDbEntity*> PhdUtility::ExplodeEnt(AcDbEntity* pEnt)
{
	AcArray<AcDbEntity*> arrExpEnt;
	AcDbVoidPtrArray exArr;
	if (pEnt->explode(exArr) == Acad::eOk)
	{
		for (int i = 0; i < exArr.length(); i++)
		{
			AcDbEntity* pExpEnt = (AcDbEntity*)exArr.at(i);
			arrExpEnt.append(pExpEnt);
		}
	}

	return arrExpEnt;
}

AcArray<AcDbEntity*> PhdUtility::ExplodeEnt(const AcDbObjectId& idEnt)
{
	AcArray<AcDbEntity*> arrExpEnt;
	AcDbEntityPointer pEnt(idEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return arrExpEnt;
	return ExplodeEnt(pEnt);
}

bool PhdUtility::MoveEnt(AcDbEntity* pEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest)
{
	assert(pEnt);

	// 设置变换矩阵的参数
	AcGeMatrix3d xform;
	AcGeVector3d vec(ptDest.x - ptBase.x, ptDest.y - ptBase.y,
		ptDest.z - ptBase.z);
	xform.setToTranslation(vec);
	Acad::ErrorStatus es = pEnt->transformBy(xform);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool PhdUtility::MoveEnt(const AcArray<AcDbEntity*>& arrEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest)
{
	// 设置变换矩阵的参数
	AcGeMatrix3d xform;
	AcGeVector3d vec(ptDest.x - ptBase.x, ptDest.y - ptBase.y,
		ptDest.z - ptBase.z);
	xform.setToTranslation(vec);
	for (int i = 0; i < arrEnt.length(); i++)
	{
		if (!arrEnt[i])
			continue;
		Acad::ErrorStatus es = arrEnt[i]->transformBy(xform);
	}
	return true;
}

bool PhdUtility::MoveEnt(const AcDbObjectId& idEnt, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest)
{
	AcDbEntityPointer pEnt(idEnt,AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	// 设置变换矩阵的参数
	AcGeMatrix3d xform;
	AcGeVector3d vec(ptDest.x - ptBase.x, ptDest.y - ptBase.y,
		ptDest.z - ptBase.z);
	xform.setToTranslation(vec);
	Acad::ErrorStatus es = pEnt->transformBy(xform);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool PhdUtility::MoveEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d &ptBase, const AcGePoint3d &ptDest)
{
	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i],AcDb::kForWrite);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		MoveEnt(pEnt,ptBase,ptDest);
	}
	return true;
}

bool PhdUtility::RotateEnt(AcDbEntity *pEnt, const AcGePoint3d &ptBase, double rotation)
{
	assert(pEnt);

	AcGeMatrix3d xform;
	xform.setToRotation(rotation, AcGeVector3d::kZAxis, ptBase);//参数二是输入旋转轴向量
	Acad::ErrorStatus es = pEnt->transformBy(xform);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool PhdUtility::RotateEnt(const AcArray<AcDbEntity*>& arrpEnt, const AcGePoint3d &ptBase, double rotation)
{
	AcGeMatrix3d xform;
	xform.setToRotation(rotation, AcGeVector3d::kZAxis, ptBase);
	for (int i = 0; i < arrpEnt.length(); i++)
	{
		arrpEnt[i]->transformBy(xform);
	}
	return true;
}

AcArray<AcDbCurve*> PhdUtility::OffsetCurve(AcDbCurve* pCurve, double dOffsetDist)
{
	AcArray<AcDbCurve*> arrOffsetCurve;
	AcDbVoidPtrArray osArr;
	if (pCurve->getOffsetCurves(dOffsetDist, osArr) == Acad::eOk)
	{
		for (int i = 0; i < osArr.length(); ++i)
		{
			AcDbCurve* pOsCurve = (AcDbCurve*)osArr.at(i);
			arrOffsetCurve.append(pOsCurve);
		}
	}
	return arrOffsetCurve;
}

bool PhdUtility::GetPosAngNegValue(AcDbCurve* pCurve, const AcGePoint3d& ptBase, 
	const AcGeVector3d& vecNormal)
{
	AcGePoint3d ptNew = ptBase + vecNormal;
	bool bFlag = true;

	//算出实体平面法向量
	AcGePlane plane;
	AcDb::Planarity type;
	pCurve->getPlane(plane, type);
	AcGeVector3d vecNormalNew = plane.normal();
	//根据偏移点（鼠标点），找出矩形上距离该点最近的点ptClosed
	AcGePoint3d ptClosed;
	pCurve->getClosestPointTo(ptNew, ptClosed);
	//算出矩形上经过ptClosed的切线，即经过该点的那条边vecDerive
	AcGeVector3d vecDerive;
	pCurve->getFirstDeriv(ptClosed, vecDerive);
	//算出ptNew点到ptClosed点的距离dDistance
	double dDistance = ptNew.distanceTo(ptClosed);
	//使用ptClosed得到一个偏移向量vecOffsetdir
	AcGeVector3d vecOffsetdir = ptNew - ptClosed;
	//vecOffset和vecDerive做叉乘，算出法向量vecOffsetNormal，看vecOffsetNormal和
	//vecNormal是否同向，如果同向偏移距离为dOffset，如果不同向偏移距离为-dOffset
	AcGeVector3d vecOffsetNormal = vecOffsetdir.crossProduct(vecDerive);
	bool bCodirectional = vecOffsetNormal.isCodirectionalTo(vecNormalNew);
	if (!bCodirectional)
		bFlag = !bFlag;
	//如果是直线，取反
	if (pCurve->isKindOf(AcDbLine::desc()))
		bFlag = !bFlag;

	return bFlag;
}

AcArray<AcDbCurve*> PhdUtility::OffsetCurve(double dOffset, const AcGePoint3d& pt,
	AcDbCurve* pCurve, bool bOpposite /*= false*/)
{
	dOffset = std::fabs(dOffset);//绝对值
	//算出实体平面法向量
	AcGePlane plane;
	AcDb::Planarity type;
	pCurve->getPlane(plane, type);
	AcGeVector3d vecNormal = plane.normal();
	//根据偏移点（鼠标点），找出矩形上距离该点最近的点ptClosed
	AcGePoint3d ptClosed;
	//pCurve->getClosestPointTo(pt, ptClosed);
	ptClosed = GetClosedPtInCurve(pCurve, pt);
	//算出矩形上经过ptClosed的切线，即经过该点的那条边vecDerive
	AcGeVector3d vecDerive;
	pCurve->getFirstDeriv(ptClosed, vecDerive);
	//算出pt点到ptClosed点的距离dDistance
	double dDistance = pt.distanceTo(ptClosed);
	//使用ptClosed得到一个偏移向量vecOffsetdir
	AcGeVector3d vecOffsetdir = pt - ptClosed;
	//vecOffset和vecDerive做叉乘，算出法向量vecOffsetNormal，看vecOffsetNormal和
	//vecNormal是否同向，如果同向偏移距离为dOffset，如果不同向偏移距离为-dOffset
	AcGeVector3d vecOffsetNormal = vecOffsetdir.crossProduct(vecDerive);
	bool bCodirectional = vecOffsetNormal.isCodirectionalTo(vecNormal);
	if (!bCodirectional)
		dOffset = -dOffset;
	//如果是直线，取反
	if (pCurve->isKindOf(AcDbLine::desc()))
		dOffset = -dOffset;
	if (bOpposite)
		dOffset = -dOffset;
	//偏移实体
	AcArray<AcDbCurve*> arrOffsetCurve;
	AcDbVoidPtrArray osArr;
	if (pCurve->getOffsetCurves(dOffset, osArr) == Acad::eOk)
	{
		for (int i = 0; i < osArr.length(); ++i)
		{
			AcDbCurve* pOsCurve = (AcDbCurve*)osArr.at(i);
			arrOffsetCurve.append(pOsCurve);
		}
	}
	return arrOffsetCurve;
}

AcArray<AcDbCurve*> PhdUtility::SplitCurve(AcDbCurve* pCurve, const AcGePoint3dArray& arrSplitPt)
{
	AcArray<AcDbCurve*> arrSplitCurve;
	AcDbVoidPtrArray spArr;
	AcGePoint3dArray arrptClosed;
	for (int i = 0; i < arrSplitPt.length(); i++)
	{
		AcGePoint3d pt;
		//pCurve->getClosestPointTo(arrSplitPt.at(i), pt);
		pt = GetClosedPtInCurve(pCurve, arrSplitPt.at(i));
		arrptClosed.append(pt);
	}

	if (pCurve->getSplitCurves(arrptClosed, spArr) == Acad::eOk)
	{
		for (int i = 0; i < spArr.length(); i++)
		{
			AcDbCurve* pSplitCurve = (AcDbCurve*)spArr.at(i);
			arrSplitCurve.append(pSplitCurve);
		}
	}

	return arrSplitCurve;
}

AcArray<AcDbCurve*> PhdUtility::SplitCurve(const AcDbObjectId& idCurve,
	const AcGePoint3dArray& arrSplitPt)
{
	AcArray<AcDbCurve*> arrpSplit;
	AcDbObjectPointer<AcDbCurve> pCurve(idCurve,AcDb::kForRead);
	if (Acad::eOk != pCurve.openStatus())
		return arrpSplit;
	arrpSplit = SplitCurve(pCurve, arrSplitPt);
	return arrpSplit;
}

bool PhdUtility::ExtendCurveByDist(AcDbPolyline* pPline, bool isStartPt,
	double dDist)
{
	if (pPline->numVerts() < 2)
		return false;
	if (isStartPt)
	{
		AcGePoint3d sPt, sPt2;
		pPline->getStartPoint(sPt);
		pPline->getPointAt(1, sPt2);

		double td1, td2;
		pPline->getDistAtPoint(sPt, td1);
		pPline->getDistAtPoint(sPt2, td2);
		double off = td2 - td1;

		double sParam = fabs(dDist) / off;

		if (pPline->extend(-sParam) != Acad::eOk)
			return false;
		else
			return true;
	}
	else
	{
		AcGePoint3d ePt, ePt2;
		pPline->getEndPoint(ePt);
		pPline->getPointAt(pPline->numVerts() - 2, ePt2);

		double td1, td2;
		pPline->getDistAtPoint(ePt2, td1);
		pPline->getDistAtPoint(ePt, td2);
		double off = td2 - td1;

		double eparam = fabs(dDist) / off;
		if (pPline->extend(eparam) != Acad::eOk)
			return false;
		else
			return true;
	}
}

bool PhdUtility::ExtendCurve(AcDbCurve* pBorder, AcDbCurve* pExtend,
	const AcGePoint3d& ptExtend)
{
	AcGePoint3dArray arrptInter;
	pExtend->intersectWith(pBorder, AcDb::kExtendThis, arrptInter);
	if (arrptInter.length() == 0)
		return false;

	AcGePoint3d ptStart, ptEnd;
	pExtend->getStartPoint(ptStart);
	pExtend->getEndPoint(ptEnd);
	double dDistStart = ptExtend.distanceTo(ptStart);
	double dDistEnd = ptExtend.distanceTo(ptEnd);
	Acad::ErrorStatus es;
	if (dDistStart < dDistEnd)
	{
		es = pExtend->extend(true, arrptInter[0]);
	}
	else
	{
		es = pExtend->extend(false, arrptInter[0]);
	}
	return es == Acad::eOk;
}

bool PhdUtility::TrimCurve(AcDbCurve* pBorder, AcDbCurve* pTrim,
	const AcGePoint3d& ptTrim, AcDbCurve*& pNewTrim)
{
	AcGePoint3dArray arrptInter;
	pTrim->intersectWith(pBorder, AcDb::kOnBothOperands, arrptInter);
	if (arrptInter.length() == 0)
		return false;

	AcArray<AcDbCurve*> arrSplit = SplitCurve(pTrim, arrptInter[0]);
	if (arrSplit.length() != 2)
	{
		for (int i = 0; i < arrSplit.length(); i++)
			DEL(arrSplit[i]);
		return false;
	}

	if (IsPtOnCurve(ptTrim, arrSplit[0]))
	{
		pNewTrim = arrSplit[1];
		DEL(arrSplit[0]);
		return true;
	}
	else if (IsPtOnCurve(ptTrim, arrSplit[1]))
	{
		pNewTrim = arrSplit[0];
		DEL(arrSplit[1]);
		return true;
	}
	else
	{
		for (int i = 0; i < arrSplit.length(); i++)
			DEL(arrSplit[i]);
		return false;
	}
}

AcArray<AcDbCurve*> PhdUtility::SplitCurve(AcDbCurve* pCurve, const AcGePoint3d& ptSplit)
{
	AcArray<AcDbCurve*> arrSplitCurve;
	AcDbVoidPtrArray spArr;
	AcGePoint3dArray arrptClosed;
	AcGePoint3d pt;
	//pCurve->getClosestPointTo(ptSplit, pt);
	pt = GetClosedPtInCurve(pCurve, ptSplit);
	arrptClosed.append(pt);

	if (pCurve->getSplitCurves(arrptClosed, spArr) == Acad::eOk)
	{
		for (int i = 0; i < spArr.length(); i++)
		{
			AcDbCurve* pSplitCurve = (AcDbCurve*)spArr.at(i);
			arrSplitCurve.append(pSplitCurve);
		}
	}

	return arrSplitCurve;
}

AcGeCircArc2d PhdUtility::GetGeCircArc(AcDbArc* pArc)
{
	AcGePoint3d centerPt = pArc->center();
	double dRadius = pArc->radius();
	double dStartAngle = pArc->startAngle();
	double dEndAngle = pArc->endAngle();
	AcGeCircArc2d geCircArc;
	geCircArc.set(centerPt.convert2d(AcGePlane::kXYPlane), dRadius, dStartAngle, dEndAngle);
	return geCircArc;
}

AcGeLineSeg2d PhdUtility::GetGeLineSeg2d(const AcDbObjectId& idLine)
{
	AcGeLineSeg2d geLine;
	AcDbObjectPointer<AcDbLine> pLine(idLine,AcDb::kForRead);
	if (Acad::eOk != pLine.openStatus())
		return geLine;
	AcGePoint3d ptStart = pLine->startPoint();
	AcGePoint3d ptEnd = pLine->endPoint();
	geLine.set(ptStart.convert2d(AcGePlane::kXYPlane), ptEnd.convert2d(AcGePlane::kXYPlane));
	return geLine;
}

AcGeCircArc2d PhdUtility::GetGeCircArc(AcDbCircle* pCircle)
{
	AcGePoint3d centerPt = pCircle->center();
	double dRadius = pCircle->radius();
	AcGeCircArc2d geCircArc;
	geCircArc.set(centerPt.convert2d(AcGePlane::kXYPlane), dRadius);
	return geCircArc;
}

bool PhdUtility::GetIntersectPoint(const AcGeLine2d& geLine, const AcGeCircArc2d& geCircArc, int& nNum, AcGePoint3dArray& arrptIntersect)
{
	nNum = 0;
	AcGePoint2d pt1, pt2;
	if (!geCircArc.intersectWith(geLine, nNum, pt1, pt2))
		return false;
	if (nNum == 1)
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
	else if (nNum == 2)
	{
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
		arrptIntersect.append(AcGePoint3d(pt2.x, pt2.y, 0));
	}
	return true;
}

AcGeVector3d PhdUtility::GetProjectVector(const AcGePoint3d& ptBase, const AcGeVector3d& vctOffset, const AcGeVector3d& vctDirection)
{
	AcGePoint3d ptOffset = ptBase + vctOffset;
	AcGeLine3d geLine(ptBase, vctDirection);
	AcGePoint3d ptTarget = geLine.closestPointTo(ptOffset);
	return ptTarget - ptBase;
}

AcGeVector3d PhdUtility::GetTangentLineVec(const AcGePoint3d& ptOnCurve, const AcDbObjectId& idCurve)
{
	AcDbObjectPointer<AcDbCurve> pCurve(idCurve, AcDb::kForRead);
	if (Acad::eOk != pCurve.openStatus())
		return AcGeVector3d::kIdentity;
	AcGePoint3d pt;
	//pCurve->getClosestPointTo(ptOnCurve, pt);
	pt = GetClosedPtInCurve(pCurve, ptOnCurve);
	AcGeVector3d vecTangLine;
	pCurve->getFirstDeriv(pt, vecTangLine);
	return vecTangLine;
}

AcGeVector3dArray PhdUtility::GetTangLineVecs(const AcGePoint3d& pt, const AcDbObjectId& idCurve)
{
	//公差
	double dTol = 0.01;
	AcGeTol tol;
	tol.setEqualPoint(dTol);
	//
	AcGeVector3dArray arrvec;
	AcDbObjectPointer<AcDbCurve> pCurve(idCurve, AcDb::kForRead);
	if (Acad::eOk != pCurve.openStatus())
		return arrvec;
	AcGePoint3d ptOnCurve;
	//pCurve->getClosestPointTo(pt, ptOnCurve);
	ptOnCurve = GetClosedPtInCurve(pCurve, pt);

	if (pCurve->isKindOf(AcDbCircle::desc()) ||
		pCurve->isKindOf(AcDbEllipse::desc()))
	{//圆、椭圆
		AcGeVector3d vecDeriv;
		pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
		arrvec.append(vecDeriv);
		arrvec.append(vecDeriv.negate());
		return arrvec;
	}
	else if (pCurve->isKindOf(AcDbLine::desc()) ||
		pCurve->isKindOf(AcDbArc::desc()))
	{//直线、圆弧
		AcGeVector3d vecDeriv;
		pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
		AcGePoint3d ptStart, ptEnd;
		pCurve->getStartPoint(ptStart);
		pCurve->getEndPoint(ptEnd);
		if (ptOnCurve.isEqualTo(ptStart, tol))
		{
			arrvec.append(vecDeriv);
			return arrvec;
		}
		else if (ptOnCurve.isEqualTo(ptEnd, tol))
		{
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
		else
		{
			arrvec.append(vecDeriv);
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
	}
	else if (pCurve->isKindOf(AcDbPolyline::desc()))
	{//多段线
		AcDbPolyline* pPline = AcDbPolyline::cast(pCurve);
		int nCountVerts = pPline->numVerts();
		if (nCountVerts < 2)
			return arrvec;
		AcGePoint3dArray arrVertex;//顶点集合
		AcArray<double> arrBulge;	//凸度集合
		bool bClosed = pPline->isClosed();
		for (int i = 0; i < nCountVerts; i++)
		{
			AcGePoint3d ptTemp;
			pPline->getPointAt(i, ptTemp);
			arrVertex.append(ptTemp);
			if (!bClosed && i == nCountVerts - 1)
				continue;
			double dBugle = 0;
			pPline->getBulgeAt(i, dBugle);
			arrBulge.append(dBugle);
		}
		bool bIsVertex = false;
		int nIndexVertex = -1;
		for (int i = 0; i < arrVertex.length(); i++)
		{
			if (ptOnCurve.isEqualTo(arrVertex[i], tol))
			{
				bIsVertex = true;
				nIndexVertex = i;
				break;
			}
		}
		if (!bIsVertex)
		{
			AcGeVector3d vecDeriv;
			pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
			arrvec.append(vecDeriv);
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
		else
		{
			if (bClosed)
			{
				if (nIndexVertex == 0)
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nCountVerts - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nCountVerts - 1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nCountVerts - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[0] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nCountVerts - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else if (nIndexVertex == nCountVerts - 1)
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[0] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
			}
			else
			{
				if (nIndexVertex == 0)
				{
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else if (nIndexVertex == nCountVerts - 1)
				{
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
			}
		}
	}
	else
		return arrvec;
}

bool PhdUtility::GetTangentLineVecs(AcDbPolyline* pPline, const AcGePoint3d& pt, 
	AcGeVector3dArray& arrvec)
{
	AcGePoint3d ptOnCurve;
	ptOnCurve = GetClosedPtInCurve(pPline, pt);
	int nCountVerts = pPline->numVerts();
	if (nCountVerts < 2)
		return false;

	AcGePoint3dArray arrVertex;//顶点集合
	AcArray<double> arrBulge;	//凸度集合
	bool bClosed = PhdEntity::IsClosedPline(pPline);
	bool bClosedFlag = pPline->isClosed();
	for (int i = 0; i < nCountVerts; i++)
	{
		AcGePoint3d ptTemp;
		pPline->getPointAt(i, ptTemp);
		arrVertex.append(ptTemp);
		if (bClosed && !bClosedFlag && (i == nCountVerts - 1))
			continue;
		if (!bClosed && (i == nCountVerts - 1))
			continue;
		double dBugle = 0;
		pPline->getBulgeAt(i, dBugle);
		arrBulge.append(dBugle);
	}

	bool bIsVertex = false;//是否是端点
	int nIndexVertex = -1;//端点索引
	for (int i = 0; i < arrVertex.length(); i++)
	{
		if (ptOnCurve.isEqualTo(arrVertex[i]))
		{
			bIsVertex = true;
			nIndexVertex = i;
			break;
		}
	}
	if (!bIsVertex)
	{
		AcGeVector3d vecDeriv;
		pPline->getFirstDeriv(ptOnCurve, vecDeriv);
		arrvec.append(vecDeriv);
		arrvec.append(vecDeriv.negate());
		return true;
	}
	else
	{
		if (bClosed)//闭合线段
		{
			if (nIndexVertex == 0)//线段第一点
			{
				//第一条方向
				if (arrBulge[nIndexVertex] == 0)//是直线
				{
					AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
					arrvec.append(vecDeriv);
				}
				else//不是直线
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex] > 0)
						vecDeriv = vec.perpVector();//逆时针
					else
						vecDeriv = vec.perpVector().negate();//顺时针
					arrvec.append(vecDeriv);
				}
				//第二条方向
				int nEndIndex = arrBulge.length() - 1;
				if (arrBulge[nEndIndex] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nEndIndex] - arrVertex[0];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nEndIndex, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[0] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nEndIndex] > 0)
						vecDeriv = vec.perpVector().negate();//逆时针
					else
						vecDeriv = vec.perpVector();//顺时针
					arrvec.append(vecDeriv);
				}
				return true;
			}
			else
			{
				//第一条方向
				if (arrBulge[nIndexVertex] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex] > 0)
						vecDeriv = vec.perpVector();//逆时针
					else
						vecDeriv = vec.perpVector().negate();//顺时针
					arrvec.append(vecDeriv);
				}
				//第二条方向
				if (arrBulge[nIndexVertex - 1] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex - 1, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex - 1] > 0)
						vecDeriv = vec.perpVector().negate();//逆时针
					else
						vecDeriv = vec.perpVector();//顺时针
					arrvec.append(vecDeriv);
				}
				return true;
			}
		}
		else//非闭合线段
		{
			if (nIndexVertex == 0)
			{
				if (arrBulge[nIndexVertex] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex] > 0)
						vecDeriv = vec.perpVector();//逆时针
					else
						vecDeriv = vec.perpVector().negate();//顺时针
					arrvec.append(vecDeriv);
				}
				return true;
			}
			else if (nIndexVertex == nCountVerts - 1)
			{
				if (arrBulge[nIndexVertex - 1] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex - 1, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex - 1] > 0)
						vecDeriv = vec.perpVector().negate();//逆时针
					else
						vecDeriv = vec.perpVector();//顺时针
					arrvec.append(vecDeriv);
				}
				return true;
			}
			else
			{
				//第一条方向
				if (arrBulge[nIndexVertex] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex] > 0)
						vecDeriv = vec.perpVector();//逆时针
					else
						vecDeriv = vec.perpVector().negate();//顺时针
					arrvec.append(vecDeriv);
				}
				//第二条方向
				if (arrBulge[nIndexVertex - 1] == 0)
				{
					AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
					arrvec.append(vecDeriv);
				}
				else
				{
					AcGeCircArc2d segArc;
					pPline->getArcSegAt(nIndexVertex - 1, segArc);
					AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
					AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
					AcGeVector3d vecDeriv;
					if (arrBulge[nIndexVertex - 1] > 0)
						vecDeriv = vec.perpVector().negate();//逆时针
					else
						vecDeriv = vec.perpVector();//顺时针
					arrvec.append(vecDeriv);
				}
				return true;
			}
		}
	}
}

AcGeVector3dArray PhdUtility::GetTangLineVecs(const AcGePoint3d& pt, AcDbCurve* pCurve)
{
	//公差
	double dTol = 0.01;
	AcGeTol tol;
	tol.setEqualPoint(dTol);
	//
	AcGeVector3dArray arrvec;
	AcGePoint3d ptOnCurve;
	//pCurve->getClosestPointTo(pt, ptOnCurve);
	ptOnCurve = GetClosedPtInCurve(pCurve, pt);

	if (pCurve->isKindOf(AcDbCircle::desc()) ||
		pCurve->isKindOf(AcDbEllipse::desc()))
	{//圆、椭圆
		AcGeVector3d vecDeriv;
		pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
		arrvec.append(vecDeriv);
		arrvec.append(vecDeriv.negate());
		return arrvec;
	}
	else if (pCurve->isKindOf(AcDbLine::desc()) ||
		pCurve->isKindOf(AcDbArc::desc()))
	{//直线、圆弧
		AcGeVector3d vecDeriv;
		pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
		AcGePoint3d ptStart, ptEnd;
		pCurve->getStartPoint(ptStart);
		pCurve->getEndPoint(ptEnd);
		if (ptOnCurve.isEqualTo(ptStart, tol))
		{
			arrvec.append(vecDeriv);
			return arrvec;
		}
		else if (ptOnCurve.isEqualTo(ptEnd, tol))
		{
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
		else
		{
			arrvec.append(vecDeriv);
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
	}
	else if (pCurve->isKindOf(AcDbPolyline::desc()))
	{//多段线
		AcDbPolyline* pPline = AcDbPolyline::cast(pCurve);
		int nCountVerts = pPline->numVerts();
		if (nCountVerts < 2)
			return arrvec;
		AcGePoint3dArray arrVertex;//顶点集合
		AcArray<double> arrBulge;	//凸度集合
		bool bClosed = PhdEntity::IsClosedPline(pPline);
		bool bClosedFlag = pPline->isClosed();
		for (int i = 0; i < nCountVerts; i++)
		{
			AcGePoint3d ptTemp;
			pPline->getPointAt(i, ptTemp);
			arrVertex.append(ptTemp);
			if (bClosed && !bClosedFlag && (i == nCountVerts-1))
				continue;
			if (!bClosed && (i == nCountVerts - 1))
				continue;
			double dBugle = 0;
			pPline->getBulgeAt(i, dBugle);
			arrBulge.append(dBugle);
		}
		bool bIsVertex = false;
		int nIndexVertex = -1;
		for (int i = 0; i < arrVertex.length(); i++)
		{
			if (ptOnCurve.isEqualTo(arrVertex[i], tol))
			{
				bIsVertex = true;
				nIndexVertex = i;
				break;
			}
		}
		if (!bIsVertex)
		{
			AcGeVector3d vecDeriv;
			pCurve->getFirstDeriv(ptOnCurve, vecDeriv);
			arrvec.append(vecDeriv);
			arrvec.append(vecDeriv.negate());
			return arrvec;
		}
		else
		{
			if (bClosed)
			{
				if (nIndexVertex == 0)//闭合，是线段第一点
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)//是直线
					{
						AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else//不是直线
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nCountVerts - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nCountVerts - 1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nCountVerts - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[0] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nCountVerts - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else if (nIndexVertex == nCountVerts - 1)
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[0] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
			}
			else
			{
				if (nIndexVertex == 0)
				{
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[1] - arrVertex[0];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else if (nIndexVertex == nCountVerts - 1)
				{
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
				else
				{
					//第一条方向
					if (arrBulge[nIndexVertex] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex + 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex] > 0)
							vecDeriv = vec.perpVector();//逆时针
						else
							vecDeriv = vec.perpVector().negate();//顺时针
						arrvec.append(vecDeriv);
					}
					//第二条方向
					if (arrBulge[nIndexVertex - 1] == 0)
					{
						AcGeVector3d vecDeriv = arrVertex[nIndexVertex - 1] - arrVertex[nIndexVertex];
						arrvec.append(vecDeriv);
					}
					else
					{
						AcGeCircArc2d segArc;
						pPline->getArcSegAt(nIndexVertex - 1, segArc);
						AcGePoint3d ptCenter = PhdConver::ToPt3d(segArc.center());
						AcGeVector3d vec = arrVertex[nIndexVertex] - ptCenter;
						AcGeVector3d vecDeriv;
						if (arrBulge[nIndexVertex - 1] > 0)
							vecDeriv = vec.perpVector().negate();//逆时针
						else
							vecDeriv = vec.perpVector();//顺时针
						arrvec.append(vecDeriv);
					}
					return arrvec;
				}
			}
		}
	}
	else
		return arrvec;
}

AcGeVector2d PhdUtility::GetMidVectorOfLines(AcDbLine* pLine1, AcDbLine* pLine2)
{

	AcGeLine2d geLine1 = GetGeLine2d(pLine1);
	AcGeLine2d geLine2 = GetGeLine2d(pLine2);
	AcGePoint3d ptInter;
	GetIntersectPoint(geLine1, geLine2, ptInter);
	AcGePoint3d ptEnd1, ptEnd2;
	if (!ptInter.isEqualTo(pLine1->startPoint()))
	{
		ptEnd1 = pLine1->startPoint();
	}
	else
	{
		ptEnd1 = pLine1->endPoint();
	}
	if (!ptInter.isEqualTo(pLine2->startPoint()))
	{
		ptEnd2 = pLine2->startPoint();
	}
	else
	{
		ptEnd2 = pLine2->endPoint();
	}
	AcGeVector2d vec1 = ptEnd1.convert2d(AcGePlane::kXYPlane) - ptInter.convert2d(AcGePlane::kXYPlane);
	AcGeVector2d vec2 = ptEnd2.convert2d(AcGePlane::kXYPlane) - ptInter.convert2d(AcGePlane::kXYPlane);
	AcGeVector2d midVector = vec1.normal() + vec2.normal();
	return midVector;
}

double PhdUtility::GetAngle(const AcGePoint3d& pt, const AcGeVector3d& vec)
{
	AcGePoint3d ptX = pt;
	ptX.x += 1;
	AcGeVector3d vecX = ptX - pt;
	double dAngle = vecX.angleTo(vec, AcGeVector3d::kZAxis);
	return dAngle;
}

double PhdUtility::GetCurveLength(AcDbCurve* pCurve)
{
	double dLength = 0;
	double endParam = 0;
	pCurve->getEndParam(endParam);
	pCurve->getDistAtParam(endParam, dLength);

	return dLength;
}

bool PhdUtility::IsPtOnCurve(const AcGePoint3d& pt, AcDbCurve* pCurve,
	double dTol /*= 0*/)
{
	double dLength = 0;
	if (Acad::eInvalidInput != pCurve->getDistAtPoint(pt, dLength))
		return true;
	else
	{
		if (dTol == 0)
			return false;
		else 
		{
			AcGePoint3d ptOnCurve;
			//pCurve->getClosestPointTo(pt, ptOnCurve);
			ptOnCurve = GetClosedPtInCurve(pCurve, pt);
			AcGeTol tol;
			tol.setEqualPoint(dTol);
			if (pt.isEqualTo(ptOnCurve, tol))
				return true;
			else
				return false;
		}
	}
}

double PhdUtility::GetAngleOfLines(AcDbLine* pLine1, AcDbLine* pLine2)
{
	AcGeLine2d geLine1 = GetGeLine2d(pLine1);
	AcGeLine2d geLine2 = GetGeLine2d(pLine2);
	AcGePoint3d ptInter;
	if (!GetIntersectPoint(geLine1, geLine2, ptInter))
		return 0;
	AcGePoint3d ptEnd1, ptEnd2;
	if (!ptInter.isEqualTo(pLine1->startPoint()))
		ptEnd1 = pLine1->startPoint();
	else
		ptEnd1 = pLine1->endPoint();
	
	if (!ptInter.isEqualTo(pLine2->startPoint()))
		ptEnd2 = pLine2->startPoint();
	
	else
		ptEnd2 = pLine2->endPoint();
	
	AcGeVector2d vec1 = ptEnd1.convert2d(AcGePlane::kXYPlane) - ptInter.convert2d(AcGePlane::kXYPlane);
	AcGeVector2d vec2 = ptEnd2.convert2d(AcGePlane::kXYPlane) - ptInter.convert2d(AcGePlane::kXYPlane);
	double dAngle = vec1.angleTo(vec2);
	return dAngle;
}

AcGePoint3d PhdUtility::GetClosedPtInCurve(AcDbCurve* pCurve, 
	const AcGePoint3d& pt)
{
	double dLength = 0;
	if (Acad::eInvalidInput == pCurve->getDistAtPoint(pt, dLength))
	{
		AcGePoint3d ptOnCurve;
		pCurve->getClosestPointTo(pt, ptOnCurve);
		return ptOnCurve;
	}
	else
		return pt;
}

bool PhdUtility::GetClosedPtInCurve(const AcDbObjectId& idCurve, 
	const AcGePoint3d& pt, AcGePoint3d& ptClosed)
{
	AcDbObjectPointer<AcDbCurve> pCurve(idCurve,AcDb::kForRead);
	if (Acad::eOk != pCurve.openStatus())
		return false;
	ptClosed = GetClosedPtInCurve(pCurve, pt);
	return true;
}

AcGePoint3dArray PhdUtility::SortPtArr(const AcGePoint3dArray& PointArr, bool bVertical /*= false*/)
{
	AcGePoint3dArray tempPointArr = PointArr;
	if (bVertical)//是垂直的
		std::sort(tempPointArr.asArrayPtr(), tempPointArr.asArrayPtr() + tempPointArr.length(), [](const AcGePoint3d& a, const AcGePoint3d& b) {return a.y < b.y; });
	else
		std::sort(tempPointArr.asArrayPtr(), tempPointArr.asArrayPtr() + tempPointArr.length(), [](const AcGePoint3d& a, const AcGePoint3d& b) {return a.x < b.x; });

	return tempPointArr;
}

void PhdUtility::ShowProgressBar(const CString& strName, bool bStart)
{
	if (bStart)
		acedSetStatusBarProgressMeter(strName, 0, 100);//显示进度条
	else
		acedRestoreStatusBar();//关闭进度条
}

void PhdUtility::SetProgressBar(int nCurIndex, int nSum)
{
	int nNum = (nCurIndex + 1) * 100 / nSum;
	acedSetStatusBarProgressMeterPos(nNum);//设置进度条的进度
}

void PhdUtility::SetEntSelected(const AcDbObjectIdArray& arridEnt, bool bSeled /*= true*/, bool bHighlight /*= false*/)
{
//	acedSSDel(ent, ssname);		//将实体从集合中删除掉
	acedSSSetFirst(NULL,NULL);	//将选中状态清除
	if (bSeled)
	{
		//使实体被选中
		ads_name ssname, ent;
		acdbNameClear(ssname);
		for (int i = 0; i < arridEnt.length(); ++i)
		{
			acdbGetAdsName(ent, arridEnt.at(i));
			acedSSAdd(ent, ssname, ssname);//将实体增加到集合中
		}
		acedSSSetFirst(ssname, NULL);//把实体变为选中状态
	}

	if (bHighlight)
	{
		for (int i = 0; i < arridEnt.length(); ++i)
		{
			AcDbEntityPointer pEnt(arridEnt.at(i), AcDb::kForWrite);
			if (pEnt.openStatus() != Acad::eOk)
				continue;
			pEnt->highlight();//设置实体为高亮状态
		}
	}
}

bool PhdUtility::SetEntToBottom(const AcDbObjectId& id, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId spaceId = pDb->currentSpaceId();
	AcDbObjectPointer<AcDbBlockTableRecord> pBTR(spaceId, AcDb::kForRead);
	if (pBTR.openStatus() != Acad::eOk)
		return false;
	AcDbSortentsTable *pSortTab = NULL;
	AcDbObjectIdArray idarrTemp;
	idarrTemp.append(id);
	Acad::ErrorStatus es = pBTR->getSortentsTable(pSortTab, AcDb::kForWrite, true);
	if (Acad::eOk != es)
		return false;
	pSortTab->moveToBottom(idarrTemp);
	pSortTab->close();
	return true;
}

bool PhdUtility::StretchEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptCorner1, const AcGePoint3d& ptCorner2, const AcGePoint3d& ptBase, const AcGePoint3d& ptTarget)
{
	AcGeVector3d stretchVec = ptTarget - ptBase;//拉伸距离
	AcGeBoundBlock3d box;
	box.set(ptCorner1, AcGeVector3d((ptCorner2 - ptCorner1).x, 0, 0),
		AcGeVector3d(0, (ptCorner2 - ptCorner1).y, 0),
		AcGeVector3d(0, 0, (ptCorner2 - ptCorner1).z));
	for (int i = 0; i < arrid.length(); ++i)
	{
		AcDbObjectPointer<AcDbEntity> pEnt(arrid[i], AcDb::kForWrite);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcGePoint3dArray arrpt;
		if (Acad::eOk != pEnt->getStretchPoints(arrpt))
			continue;
		AcDbIntArray arrint;
		bool bFound = false;
		for (int j = 0; j < arrpt.length(); ++j)
		{
			AcGePoint3d pt = arrpt[j];
			if (box.contains(pt))
			{
				arrint.append(j);
				bFound = true;
			}
		}
		if (bFound)
		{
			pEnt->moveStretchPointsAt(arrint, stretchVec);
		}
	}
	return true;
}

AcDbObjectIdArray PhdUtility::GetEntIdByPt(const AcGePoint3d& pt, bool bAll /*= false*/)
{
	AcDbObjectIdArray arrid;
	ads_name ssname;

	if (bAll)
	{
		//得到通过该点的所有实体
		if (RTNORM != acedSSGet(_T("C"), asDblArray(pt), asDblArray(pt), NULL, ssname))
			return arrid;
	}
	else
	{
		//得到位于该点最上面的实体
		if (RTNORM != acedSSGet(NULL, asDblArray(pt),NULL,NULL, ssname))
			return arrid;
	}
	//遍历选择集
	long lLength = 0;
	acedSSLength(ssname, &lLength);
	for (int i = 0; i < lLength; i++)
	{
		ads_name name;
		acedSSName(ssname, i, name);
		AcDbObjectId id;
		acdbGetObjectId(id, name);
		arrid.append(id);
	}
	acedSSFree(ssname);

	return arrid;
}

AcArray<CString> PhdUtility::GetAllDwgPath(LPCTSTR szFolderPath)
{
	AcArray<CString> arrDwgPath;
	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.dwg"), szFolderPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		if (finder.IsDirectory() || finder.IsDots())
			continue;
		CString strDwgPath = finder.GetFilePath();
		arrDwgPath.append(strDwgPath);
	}
	return arrDwgPath;
}

AcArray<CString> PhdUtility::GetAllDwgName(LPCTSTR szFolderPath)
{
	AcArray<CString> arrDwgPath;
	CFileFind finder;
	CString path;
	path.Format(_T("%s\\*.dwg"), szFolderPath);
	BOOL bWorking = finder.FindFile(path);
	while (bWorking)
	{
		bWorking = finder.FindNextFileW();
		if (finder.IsDirectory() || finder.IsDots())
			continue;
		CString strDwgName = finder.GetFileTitle();
		arrDwgPath.append(strDwgName);
	}
	return arrDwgPath;
}

AcDbExtents PhdUtility::GetEntExtents(const AcDbObjectId& idEnt)
{
	AcDbExtents es;
	AcDbEntityPointer pEnt(idEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return es;
	pEnt->getGeomExtents(es);
	return es;
}

AcDbExtents PhdUtility::GetEntExtents(const AcArray<AcDbEntity*>& arrEnt)
{
	AcDbExtents extents;
	for (int i = 0; i < arrEnt.length(); i++)
	{
		AcDbExtents ext;
		arrEnt[i]->getGeomExtents(ext);
		extents.addExt(ext);
	}
	return extents;
}

AcDbExtents PhdUtility::GetEntExtents(const AcDbObjectIdArray& arrid)
{
	AcDbExtents extents;
	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i],AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcDbExtents ext;
		pEnt->getGeomExtents(ext);
		extents.addExt(ext);
	}
	return extents;
}

bool PhdUtility::DeleteEnt(const AcDbObjectId& idEnt)
{
	AcDbEntityPointer pEnt(idEnt,AcDb::kForWrite);
	Acad::ErrorStatus es = pEnt.openStatus();
	if (Acad::eOk != es)
		return false;
	es = pEnt->erase();
	return es == Acad::eOk;
}

void PhdUtility::DeleteEnt(AcArray<AcDbEntity*>& arrpEnt)
{
	for (int i = 0; i < arrpEnt.length(); i++)
	{
		if (arrpEnt[i])
			DEL(arrpEnt[i]);
	}
}

AcArray<AcDbEntity*> PhdUtility::CopyEnt(const AcDbObjectIdArray& arrid)
{
	AcArray<AcDbEntity*> arrEnt;
//	for (int i = 0; i < arrid.length(); i++)
	for (int i = (arrid.length()-1); i >= 0; i--)
	{
		AcDbEntityPointer pEnt(arrid[i],AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;;
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		if (pCopy)
		{
			arrEnt.append(pCopy);
		}
	}
	return arrEnt;
}

AcDbEntity* PhdUtility::MirrorEnt(AcDbEntity* pEnt, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	AcGeMatrix3d mat;
	mat.setToMirroring(AcGeLine3d(pt1, pt2));
	AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
	pCopy->transformBy(mat);

	AcGeMatrix3d mat2;
	mat2.setToMirroring(AcGePlane::kXYPlane);
	pCopy->transformBy(mat2);
	return pCopy;
}

AcArray<AcDbEntity*> PhdUtility::MirrorEnt(const AcArray<AcDbEntity*>& arrp, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	AcArray<AcDbEntity*> arrpEnt;
	AcGeMatrix3d mat;
	mat.setToMirroring(AcGeLine3d(pt1, pt2));

	for (int i = 0; i < arrp.length(); i++)
	{
		AcDbEntity* pEnt = arrp[i];
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		pCopy->transformBy(mat);
		arrpEnt.append(pCopy);
	}

	return arrpEnt;
}

AcArray<AcDbEntity*> PhdUtility::MirrorEnt(const AcDbObjectIdArray& arrid, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	AcArray<AcDbEntity*> arrpEnt;
	AcGeMatrix3d mat;
	mat.setToMirroring(AcGeLine3d(pt1, pt2));

	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i], AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		pCopy->transformBy(mat);
		arrpEnt.append(pCopy);
	}

	return arrpEnt;
}

AcArray<AcDbEntity*> PhdUtility::CopyEnt(const AcArray<AcDbEntity*>& arrp)
{
	AcArray<AcDbEntity*> arrEnt;
	for (int i = (arrp.length() - 1); i >= 0; i--)
	{
		AcDbEntity* pEnt = arrp[i];
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		if (pCopy)
		{
			arrEnt.append(pCopy);
		}
	}
	return arrEnt;
}

AcDbEntity* PhdUtility::CopyEnt(const AcDbObjectId& idEnt)
{
	AcDbEntityPointer pEnt(idEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return NULL;
	AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
	return pCopy;
}

int PhdUtility::GetLineType(const AcDbObjectId& idLine, double& dPosition)
{
	AcDbObjectPointer<AcDbLine> pLine(idLine,AcDb::kForRead);
	if (Acad::eOk != pLine.openStatus())
		return 0;
	AcGePoint3d ptStart = pLine->startPoint();
	AcGePoint3d ptEnd = pLine->endPoint();
	if (PhdInline::IsEqual(ptStart.y,ptEnd.y) && !PhdInline::IsEqual(ptStart.x,ptEnd.x))
	{
		dPosition = ptStart.y;
		return 1;
	}
	else if (PhdInline::IsEqual(ptStart.x, ptEnd.x) && !PhdInline::IsEqual(ptStart.y, ptEnd.y))
	{
		dPosition = ptStart.x;
		return 2;
	}
	return 0;
}

int PhdUtility::GetLineType(AcDbLine* pLine, double& dPosition)
{
	AcGePoint3d ptStart = pLine->startPoint();
	AcGePoint3d ptEnd = pLine->endPoint();
	if (PhdInline::IsEqual(ptStart.y, ptEnd.y) && !PhdInline::IsEqual(ptStart.x, ptEnd.x))
	{
		dPosition = ptStart.y;
		return 1;
	}
	else if (PhdInline::IsEqual(ptStart.x, ptEnd.x) && !PhdInline::IsEqual(ptStart.y, ptEnd.y))
	{
		dPosition = ptStart.x;
		return 2;
	}
	else if (PhdUtility::PtIsEqual(ptStart,ptEnd,1))//如果两个点相等，则判断这条直线是水平
	{
		dPosition = ptStart.y;
		return 1;
	}
	
	return 0;
}

bool PhdUtility::GetExtentsPt(const AcDbObjectId& idEnt, AcGePoint3d& ptMax, AcGePoint3d& ptMin)
{
	AcDbEntityPointer pEnt(idEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	AcDbExtents extents;
	pEnt->getGeomExtents(extents);
	ptMax = extents.maxPoint();
	ptMin = extents.minPoint();
	return true;
}

bool PhdUtility::GetExtentsPt(const AcDbObjectIdArray& arrid, AcGePoint3d& ptMax, AcGePoint3d& ptMin)
{
	AcDbExtents extents;
	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i],AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcDbExtents ex;
		pEnt->getGeomExtents(ex);
		extents.addExt(ex);
	}
	ptMax = extents.maxPoint();
	ptMin = extents.minPoint();
	return true;
}

bool PhdUtility::GetExtentsPt(AcDbEntity* pEnt, AcGePoint3d& ptMax, AcGePoint3d& ptMin)
{
	AcDbExtents extents;
	auto es = pEnt->getGeomExtents(extents);
	if (Acad::eOk != es)
		return false;
	ptMax = extents.maxPoint();
	ptMin = extents.minPoint();
	return true;
}

bool PhdUtility::PtIsEqual(const AcGePoint3d& pt1, const AcGePoint3d& pt2, int nDotNum)
{
	double dX1 = PhdConver::UpdateOnDotNum(pt1.x, nDotNum);
	double dY1 = PhdConver::UpdateOnDotNum(pt1.y, nDotNum);
	double dZ1 = PhdConver::UpdateOnDotNum(pt1.z, nDotNum);
	double dX2 = PhdConver::UpdateOnDotNum(pt2.x, nDotNum);
	double dY2 = PhdConver::UpdateOnDotNum(pt2.y, nDotNum);
	double dZ2 = PhdConver::UpdateOnDotNum(pt2.z, nDotNum);
	if (dX1 == dX2 && dY1 == dY2 && dZ1 == dZ2)
		return true;
	else
		return false;
}

bool PhdUtility::LineIsCoincide(AcDbLine* pLine1, AcDbLine* pLine2)
{
	AcGePoint3d ptStart1 = pLine1->startPoint();
	AcGePoint3d ptEnd1 = pLine1->endPoint();
	AcGePoint3d ptStart2 = pLine2->startPoint();
	AcGePoint3d ptEnd2 = pLine2->endPoint();
	if (PtIsEqual(ptStart1, ptStart2, 0) && PtIsEqual(ptEnd1, ptEnd2, 0))
		return true;
	else if (PtIsEqual(ptStart1, ptEnd2, 0) && PtIsEqual(ptEnd1, ptStart2, 0))
		return true;
	else
		return false;
}

bool PhdUtility::LineIsCompleteContain(AcDbLine* pLongLine, AcDbLine* pShortLine)
{
	double dLongLength = GetCurveLength(pLongLine);
	double dShortLength = GetCurveLength(pShortLine);
	if (dShortLength > dLongLength || PhdInline::IsEqual(dShortLength,dLongLength,1))
		return false;
	AcGePoint3d ptStart = pShortLine->startPoint();
	AcGePoint3d ptEnd = pShortLine->endPoint();
	if (IsPtOnCurve(ptStart, pLongLine) && IsPtOnCurve(ptEnd, pLongLine))
		return true;
	else
		return false;
}

AcGePoint3dArray PhdUtility::RemoveSamePt(const AcGePoint3dArray& arrpt)
{
	AcGePoint3dArray arrptSingle;
	for (int i = 0; i < arrpt.length(); i++)
	{
		AcGePoint3d pt = arrpt[i];
		bool bContains = false;
		for (int j = 0; j < arrptSingle.length(); j++)
		{
			if (PhdUtility::PtIsEqual(pt, arrptSingle[j], 0))
			{
				bContains = true;
				break;
			}
		}
		if (!bContains)
			arrptSingle.append(pt);
	}
	return arrptSingle;
}

CString PhdUtility::GetEntLayerName(AcDbEntity* pEnt)
{
	TCHAR* pLayerName = pEnt->layer();
	CString strLayerName = pLayerName;
	acutDelString(pLayerName);
	return strLayerName;
}

bool PhdUtility::IsAccordId(const AcDbObjectId& idEnt, const AcArray<AcRxClass*>& arrType)
{
	AcDbEntityPointer pEnt(idEnt, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	for (int i = 0; i < arrType.length(); i++)
	{
		if (pEnt->isKindOf(arrType[i]))
			return true;
	}
	return false;
}

bool PhdUtility::IsContainsPt(const AcGePoint3dArray& arrPt, const AcGePoint3d& pt, double dTol /*= 0.01*/)
{
	//公差
	AcGeTol tol;
	tol.setEqualPoint(dTol);
	//
	for (int i = 0; i < arrPt.length(); i++)
	{
		if (arrPt[i].isEqualTo(pt, tol))
			return true;
	}
	return false;
}

bool PhdUtility::ReversePolylinePt(AcDbPolyline* pPline)
{
	bool bClosed = pPline->isClosed();
	AcGePoint3dArray arrPt;	//点集合
	AcArray<double> arrBulge;	//凸度集合
	int nCount = pPline->numVerts();
	if (bClosed)
	{
		for (int i = 0; i < nCount; i++)
		{
			AcGePoint3d ptTemp;
			double dBulgeTemp = 0;
			pPline->getPointAt(i, ptTemp);
			pPline->getBulgeAt(i, dBulgeTemp);
			if (dBulgeTemp != 0)
				dBulgeTemp = -dBulgeTemp;
			arrPt.append(ptTemp);
			arrBulge.append(dBulgeTemp);
		}
		//删除点
		for (int i = nCount - 1; i > 0; i--)
			pPline->removeVertexAt(i);
		//设置第一点
		pPline->setBulgeAt(0, arrBulge[nCount - 1]);
		//增加点
		for (int i = 1; i < nCount; i++)
		{
			pPline->addVertexAt(i, PhdConver::ToPt2d(arrPt[nCount - i]),
				arrBulge[nCount - i - 1]);
		}
	}
	else
	{
		for (int i = 0; i < nCount; i++)
		{
			AcGePoint3d ptTemp;
			double dBulgeTemp = 0;
			pPline->getPointAt(i, ptTemp);
			pPline->getBulgeAt(i, dBulgeTemp);
			if (dBulgeTemp != 0)
				dBulgeTemp = -dBulgeTemp;
			arrPt.append(ptTemp);
			arrBulge.append(dBulgeTemp);
		}
		//删除点
		for (int i = nCount - 1; i > 0; i--)
			pPline->removeVertexAt(i);
		//设置第一点
		pPline->setPointAt(0, PhdConver::ToPt2d(arrPt[nCount - 1]));
		pPline->setBulgeAt(0, arrBulge[nCount - 2]);
		//增加点
		for (int i = 1; i < nCount - 1; i++)
		{
			pPline->addVertexAt(i, PhdConver::ToPt2d(arrPt[nCount - i - 1]),
				arrBulge[nCount - i - 2]);
		}
		//设置最后一点
		pPline->addVertexAt(nCount - 1, PhdConver::ToPt2d(arrPt[0]),
			arrBulge[nCount - 1]);
	}
	return true;
}

AcDbPolyline* PhdUtility::ReversePlinePt(AcDbPolyline* pPline)
{
	bool bClosed = pPline->isClosed();
	AcGePoint3dArray arrPt;	//点集合
	AcArray<double> arrBulge;	//凸度集合
	int nCount = pPline->numVerts();
	if (bClosed)
	{
		for (int i = 0; i < nCount; i++)
		{
			AcGePoint3d ptTemp;
			double dBulgeTemp = 0;
			pPline->getPointAt(i, ptTemp);
			pPline->getBulgeAt(i, dBulgeTemp);
			if (dBulgeTemp != 0)
				dBulgeTemp = -dBulgeTemp;
			arrPt.append(ptTemp);
			arrBulge.append(dBulgeTemp);
		}
		//新建对象
		AcDbPolyline* pPlineNew = new AcDbPolyline;
		for (int i = 0; i < nCount; i++)
		{
			if (i == 0)
			{
				pPlineNew->addVertexAt(i, PhdConver::ToPt2d(arrPt[0]),
					arrBulge[nCount - 1]);
			}
			else
			{
				pPlineNew->addVertexAt(i, PhdConver::ToPt2d(arrPt[nCount - i]),
					arrBulge[nCount - i - 1]);
			}
		}
		pPlineNew->setClosed(true);
		return pPlineNew;
	}
	else
	{
		for (int i = 0; i < nCount; i++)
		{
			AcGePoint3d ptTemp;
			double dBulgeTemp = 0;
			pPline->getPointAt(i, ptTemp);
			pPline->getBulgeAt(i, dBulgeTemp);
			if (dBulgeTemp != 0)
				dBulgeTemp = -dBulgeTemp;
			arrPt.append(ptTemp);
			arrBulge.append(dBulgeTemp);
		}
		//新建对象
		AcDbPolyline* pPlineNew = new AcDbPolyline;
		for (int i = 0; i < nCount - 1; i++)
		{
			if (i == 0)
			{
				pPlineNew->addVertexAt(i, PhdConver::ToPt2d(arrPt[nCount - 1]),
					arrBulge[nCount - 2]);
			}
			else
			{
				pPlineNew->addVertexAt(i, PhdConver::ToPt2d(arrPt[nCount - i - 1]),
					arrBulge[nCount - i - 2]);
			}
		}
		//设置最后一点
		pPlineNew->addVertexAt(nCount - 1, PhdConver::ToPt2d(arrPt[0]),
			arrBulge[nCount - 1]);
		return pPlineNew;
	}
}

AcDbPolyline* PhdUtility::Pline2dToPline(AcDb2dPolyline* p2dPline)
{
	if (!p2dPline)
		return NULL;

	AcDbPolyline* pPline = new AcDbPolyline();

	Acad::ErrorStatus ret;
	AcDb::Poly2dType type;
	type = p2dPline->polyType();
	if ((type == AcDb::k2dSimplePoly) || (type == AcDb::k2dFitCurvePoly))
	{
		ret = pPline->convertFrom((AcDbEntity *&)p2dPline, Adesk::kFalse);
		if (ret != Acad::eOk) {
			delete pPline;
			pPline = NULL;
			return NULL;
		}
	}
	else
		return NULL;

	return pPline;
}

bool PhdUtility::IsMirrorArc(AcDbArc* pArc)
{
	AcGeVector3d vec = pArc->normal();
	if (vec.isEqualTo(AcGeVector3d(0, 0, 1)))
		return false;
	else
		return true;
}

bool PhdUtility::FilletCurve(double dRadius, AcDbLine* pLine1, const AcGePoint3d& pt1, AcDbArc* pArc2, const AcGePoint3d& pt2, AcDbArc*& pArcFillet)
{
	//偏移线段
	AcArray<AcDbCurve*> arrpOffset1 = OffsetCurve(dRadius, pt2, pLine1);
	AcArray<AcDbCurve*> arrpOffset2 = OffsetCurve(dRadius, pt1, pArc2);
	if (arrpOffset1.length() != 1 || arrpOffset2.length() != 1)
	{
		for (int i = 0; i < arrpOffset1.length(); i++)
			DEL(arrpOffset1[i]);
		for (int i = 0; i < arrpOffset2.length(); i++)
			DEL(arrpOffset2[i]);
		return false;
	}
	AcDbLine* pLineOffset1 = AcDbLine::cast(arrpOffset1[0]);
	AcDbArc* pArcOffset2 = AcDbArc::cast(arrpOffset2[0]);
	if (!pLineOffset1 || !pArcOffset2)
	{
		for (int i = 0; i < arrpOffset1.length(); i++)
			DEL(arrpOffset1[i]);
		for (int i = 0; i < arrpOffset2.length(); i++)
			DEL(arrpOffset2[i]);
		return false;
	}

	//求圆心
	AcGePoint3dArray arrptInter;
	pLineOffset1->intersectWith(pArcOffset2, AcDb::kExtendBoth, arrptInter);
	DEL(pLineOffset1);
	DEL(pArcOffset2);
	if (arrptInter.length() == 0)
		return false;
	AcGePoint3d ptCenter;
	if (arrptInter.length() == 1)
		ptCenter = arrptInter[0];
	else if (arrptInter.length() == 2)
	{
		double dDist1 = arrptInter[0].distanceTo(pt1);
		double dDist2 = arrptInter[1].distanceTo(pt1);
		if (dDist1 < dDist2)
			ptCenter = arrptInter[0];
		else
			ptCenter = arrptInter[1];
	}
	else
		return false;

	//求切点
	AcDbCircle* pCircleTemp = PhdEntity::CreateCircle(ptCenter, dRadius);
	AcGePoint3dArray arrptInter1, arrptInter2;
	pCircleTemp->intersectWith(pLine1, AcDb::kOnBothOperands, arrptInter1);
	pCircleTemp->intersectWith(pArc2, AcDb::kOnBothOperands, arrptInter2);
	DEL(pCircleTemp);
	if (arrptInter1.length() != 1 || arrptInter2.length() != 1)
		return false;

	//求两圆弧的交点
	arrptInter.removeAll();
	pLine1->intersectWith(pArc2, AcDb::kOnBothOperands, arrptInter);
	AcGePoint3d ptInter;
	if (arrptInter.length() == 1)
	{
		ptInter = arrptInter[0];
	}
	else if (arrptInter.length() == 2)
	{
		double dDist1 = arrptInter[0].distanceTo(pt1);
		double dDist2 = arrptInter[1].distanceTo(pt1);
		if (dDist1 < dDist2)
			ptInter = arrptInter[0];
		else
			ptInter = arrptInter[1];
	}
	else
		return false;

	//第一次修改圆弧（所选点在端点和交点之间）
	ModifyLinePtToInterPt(pLine1, pt1, ptInter);
	ModifyArcPtToInterPt(pArc2, pt2, ptInter);

	//创建圆角圆弧
	AcDbArc* pArcFillet1 = PhdEntity::CreateArcByPt2(ptCenter, arrptInter1[0], arrptInter2[0]);
	AcDbArc* pArcFillet2 = PhdEntity::CreateArcByPt2(ptCenter, arrptInter2[0], arrptInter1[0]);
	AcGePoint3d ptMid1 = PhdEntity::GetArcMidPt(pArcFillet1);
	AcGePoint3d ptMid2 = PhdEntity::GetArcMidPt(pArcFillet2);
	double dDistTemp1 = ptInter.distanceTo(ptMid1);
	double dDistTemp2 = ptInter.distanceTo(ptMid2);
	if (dDistTemp1 < dDistTemp2)
	{
		pArcFillet = pArcFillet1;
		DEL(pArcFillet2);
	}
	else
	{
		pArcFillet = pArcFillet2;
		DEL(pArcFillet1);
	}

	//第二次修改圆弧（交点处修改圆弧）
	ModifyLinePt(pLine1, ptInter, arrptInter1[0]);
	PhdEntity::ModifyArcPt(pArc2, ptInter, arrptInter2[0]);

	return true;
}

void PhdUtility::ModifyLinePtToInterPt(AcDbLine* pLine, const AcGePoint3d& ptOnLine, const AcGePoint3d& ptInter)
{
	double dStartParam = 0, dEndParam = 0, dOnArcParam = 0, dInterParam = 0;
	pLine->getStartParam(dStartParam);
	pLine->getEndParam(dEndParam);
	AcGePoint3d ptOnArcClosed, ptInterClosed;
	//pLine->getClosestPointTo(ptOnLine, ptOnArcClosed);
	//pLine->getClosestPointTo(ptInter, ptInterClosed);
	ptOnArcClosed = GetClosedPtInCurve(pLine, ptOnLine);
	ptInterClosed = GetClosedPtInCurve(pLine, ptInter);
	pLine->getParamAtPoint(ptOnArcClosed, dOnArcParam);
	pLine->getParamAtPoint(ptInterClosed, dInterParam);

	AcGePoint3d ptStart, ptEnd;
	if (dOnArcParam < dInterParam)
	{
		pLine->getPointAtParam(dStartParam, ptStart);
		pLine->getPointAtParam(dInterParam, ptEnd);
	}
	else
	{
		pLine->getPointAtParam(dInterParam, ptStart);
		pLine->getPointAtParam(dEndParam, ptEnd);
	}
	pLine->setStartPoint(ptStart);
	pLine->setEndPoint(ptEnd);
}

void PhdUtility::ModifyArcPtToInterPt(AcDbArc* pArc, const AcGePoint3d& ptOnArc, const AcGePoint3d& ptInter)
{
	double dStartParam = 0, dEndParam = 0, dOnArcParam = 0, dInterParam = 0;
	pArc->getStartParam(dStartParam);
	pArc->getEndParam(dEndParam);
	AcGePoint3d ptOnArcClosed, ptInterClosed;
	//pArc->getClosestPointTo(ptOnArc, ptOnArcClosed);
	//pArc->getClosestPointTo(ptInter, ptInterClosed);
	ptOnArcClosed = GetClosedPtInCurve(pArc, ptOnArc);
	ptInterClosed = GetClosedPtInCurve(pArc, ptInter);
	pArc->getParamAtPoint(ptOnArcClosed, dOnArcParam);
	pArc->getParamAtPoint(ptInterClosed, dInterParam);

	AcGePoint3d ptCenter = pArc->center();

	AcGePoint3d ptStart, ptEnd;
	if (dOnArcParam < dInterParam)
	{
		pArc->getPointAtParam(dStartParam, ptStart);
		pArc->getPointAtParam(dInterParam, ptEnd);
	}
	else
	{
		pArc->getPointAtParam(dInterParam, ptStart);
		pArc->getPointAtParam(dEndParam, ptEnd);
	}

	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();

	pArc->setStartAngle(startAngle);
	pArc->setEndAngle(endAngle);
}

void PhdUtility::ModifyLinePt(AcDbLine* pLine, const AcGePoint3d& ptFrom, const AcGePoint3d& ptTo)
{
	AcGePoint3d ptStart, ptEnd;
	pLine->getStartPoint(ptStart);
	pLine->getEndPoint(ptEnd);

	double dStartParam = 0, dEndParam = 0, dFromParam = 0;
	pLine->getStartParam(dStartParam);
	pLine->getEndParam(dEndParam);
	AcGePoint3d ptClosed;
	//pLine->getClosestPointTo(ptFrom, ptClosed);
	ptClosed = GetClosedPtInCurve(pLine, ptFrom);
	pLine->getParamAtPoint(ptClosed, dFromParam);

	if ((dFromParam - dStartParam) < ((dEndParam - dStartParam) / 2))
	{//修改起始点
		ptStart = ptTo;
	}
	else
	{//修改终止点
		ptEnd = ptTo;
	}

	pLine->setStartPoint(ptStart);
	pLine->setEndPoint(ptEnd);
}

CString PhdUtility::GetRcStr(int nID)
{
	CAcModuleResourceOverride rs;
	CString str;
	str.LoadStringW(nID);
	return str;
}

AcGeVector3dArray PhdUtility::GetPerpVec(const AcGeVector3d& vecDirec)
{
	AcGeVector3dArray arrvec;
	AcGeVector3d vecPerp = vecDirec.perpVector();
	arrvec.append(vecPerp);
	vecPerp = vecPerp.negate();
	arrvec.append(vecPerp);
	return arrvec;
}

bool PhdUtility::IsAntiClockWise(const AcGePoint3dArray& arrpt)
{
	double area = 0;
	area = GetPtArrayArea(arrpt);
	if (area > 0)
		return TRUE;
	else if (area < 0)
		return FALSE;
	else return FALSE;
}

double PhdUtility::GetPtArrayArea(const AcGePoint3dArray& arrpt)
{
	int len = arrpt.length();
	double area = 0.0;
	if (len < 3)
		return FALSE;
	AcGePoint3d  spt, p1, p2;
	spt = arrpt.at(0);
	for (int i = 0; i < len - 1; i++) 
	{
		p1 = arrpt.at(i);
		p2 = arrpt.at(i + 1);
		area += (p1.x*p2.y - p2.x*p1.y);
	}
	area = (area + (p2.x*spt.y - spt.x*p2.y)) / 2.0;
	return area;
}

int PhdUtility::GetPlineSegIndexByPt(AcDbPolyline* pPline, const AcGePoint3d& pt,
	bool& bIsArc)
{
	if (!IsPtOnCurve(pt, pPline))
		return -1;

	double dLength = 0;
	Acad::ErrorStatus es = pPline->getDistAtPoint(pt, dLength);
	if (Acad::eOk != es)
		return -1;
	int nNumVerts = pPline->numVerts();
	if (nNumVerts < 2)
		return -1;

	double dLenLast = 0, dLenNext = 0;
	AcGePoint3d ptLast, ptNext;

	for (int i = 0; i < nNumVerts-1; i++)
	{
		pPline->getPointAt(i, ptLast);
		pPline->getPointAt(i + 1, ptNext);
		pPline->getDistAtPoint(ptLast, dLenLast);
		if (i == nNumVerts - 2)
		{
			double dEndParam = 0;
			pPline->getEndParam(dEndParam);
			pPline->getDistAtParam(dEndParam,dLenNext);
		}
		else
			pPline->getDistAtPoint(ptNext, dLenNext);

		if (dLength >= dLenLast && dLength <= dLenNext)
		{
			double dBulge = 0;
			pPline->getBulgeAt(i,dBulge);
			if (dBulge == 0)
				bIsArc = false;
			else
				bIsArc = true;
			return i;
		}
	}

	return -1;
}

int PhdUtility::JudgeVectorLeftOrRight(const AcGeVector3d& vec1,
	const AcGeVector3d& vec2)
{
	double dValue = vec1.x * vec2.y - vec2.x * vec1.y;
	if (dValue > 0)
		return 1;
	else
		return 2;
}

bool PhdUtility::PtIsInClosePline(const AcGePoint3d& pt,
	AcDbPolyline* pPline)
{
	//创建面域
	AcArray<AcDbRegion*> arrRegion;
	if (!PhdEntity::CreateRegion(pPline, arrRegion))
		return false;
	//判断点是否在面域上
	AcGePlane plane;
	bool bFlag = false;
	for (int i = 0; i < arrRegion.length(); i++)
	{
		//创建射线，根据射线与面域边线相交的点数为奇数就说明点在面域上的理论
		AcDbRay* pRay = new AcDbRay;
		pRay->setBasePoint(pt);
		pRay->setUnitDir(AcGeVector3d(1, 0, 0));

		plane = AcGePlane(AcGePoint3d(0, 0, 0), AcGeVector3d(0, 0, 1));
		AcGePoint3dArray ptArray;
		Acad::ErrorStatus es = arrRegion[i]->intersectWith(pRay, AcDb::kOnBothOperands, 
			plane, ptArray, 0, 0);//AcDb::kExtendArg
		DEL(pRay);
		if (es != Acad::eOk)
			continue;
		int iNum = ptArray.length();
		if ((iNum % 2) == 0) 
			continue;
		bFlag = true;
		break;
	}
	for (int i = 0; i < arrRegion.length(); i++)
	{
		DEL(arrRegion[i]);
	}
	return bFlag;
}

bool PhdUtility::IsColinear(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3)
{
	AcGeLineSeg2d line1(PhdConver::ToPt2d(pt1),PhdConver::ToPt2d(pt2));
	AcGeLineSeg2d line2(PhdConver::ToPt2d(pt2), PhdConver::ToPt2d(pt3));
	bool bRt = line1.isColinearTo(line2);
	return bRt;
}

bool PhdUtility::PlineAddPts(AcDbPolyline* pPline, const AcGePoint3dArray& arrpt)
{
	AcDbPolyline* pTempPline = AcDbPolyline::cast(pPline->clone());
	if (!pTempPline)
		return false;
	AcGePoint3d ptStart;
	pTempPline->getStartPoint(ptStart);
	for (int i = 0; i < arrpt.length(); i++)
	{
		AcArray<AcDbCurve*> arrpSplit = SplitCurve(pTempPline, arrpt[i]);
		if (arrpSplit.length() != 2)
		{
			for (int j = 0; j < arrpSplit.length(); j++)
				DEL(arrpSplit[j]);
			DEL(pTempPline);
			return false;
		}
		AcDbPolyline* pPline1 = AcDbPolyline::cast(arrpSplit[0]);
		AcDbPolyline* pPline2 = AcDbPolyline::cast(arrpSplit[1]);

		AcGePoint3dArray arrptTemp;
		AcArray<double> arrdTemp;
		AcGePoint3d ptCurStart;
		pPline1->getStartPoint(ptCurStart);
		if (ptStart.isEqualTo(ptCurStart))
		{
			int nNumVerts = pPline1->numVerts();
			for (int j = 0; j < nNumVerts-1; j++)
			{
				AcGePoint3d pt;
				double dBulge = 0;
				pPline1->getPointAt(j, pt);
				pPline1->getBulgeAt(j, dBulge);
				arrptTemp.append(pt);
				arrdTemp.append(dBulge);
			}
			nNumVerts = pPline2->numVerts();
			for (int j = 0; j < nNumVerts; j++)
			{
				AcGePoint3d pt;
				double dBulge = 0;
				pPline2->getPointAt(j, pt);
				pPline2->getBulgeAt(j, dBulge);
				arrptTemp.append(pt);
				arrdTemp.append(dBulge);
			}
		}
		else
		{
			int nNumVerts = pPline2->numVerts();
			for (int j = 0; j < nNumVerts - 1; j++)
			{
				AcGePoint3d pt;
				double dBulge = 0;
				pPline2->getPointAt(j, pt);
				pPline2->getBulgeAt(j, dBulge);
				arrptTemp.append(pt);
				arrdTemp.append(dBulge);
			}
			nNumVerts = pPline1->numVerts();
			for (int j = 0; j < nNumVerts; j++)
			{
				AcGePoint3d pt;
				double dBulge = 0;
				pPline1->getPointAt(j, pt);
				pPline1->getBulgeAt(j, dBulge);
				arrptTemp.append(pt);
				arrdTemp.append(dBulge);
			}
		}
		//创建新的多段线
		AcDbPolyline* pNewPline = PhdEntity::CreatePolyline(arrptTemp, arrdTemp);
		DEL(pTempPline);
		pTempPline = pNewPline;
		pTempPline->getStartPoint(ptStart);
		for (int j = 0; j < arrpSplit.length(); j++)
			DEL(arrpSplit[j]);
	}
	//得到新的点和凸度
	AcGePoint2dArray arrptNew;
	AcArray<double> arrdNew;
	for (int i = 0; i < pTempPline->numVerts(); i++)
	{
		AcGePoint2d pt;
		double dBulge = 0;
		pTempPline->getPointAt(i, pt);
		pTempPline->getBulgeAt(i, dBulge);
		arrptNew.append(pt);
		arrdNew.append(dBulge);
	}
	DEL(pTempPline);
	//
	int nNumVerts = pPline->numVerts();
	for (int i = nNumVerts - 1; i > 0; i--)
		pPline->removeVertexAt(i);
	for (int i = 1; i < arrptNew.length(); i++)
		pPline->addVertexAt(i, arrptNew[i], arrdNew[i]);

	return true;
}

bool PhdUtility::FilletCurve(double dRadius, AcDbArc* pArc1, const AcGePoint3d& pt1, AcDbArc* pArc2, const AcGePoint3d& pt2, AcDbArc*& pArcFillet)
{
	//偏移线段
	AcArray<AcDbCurve*> arrpOffset1 = OffsetCurve(dRadius, pt2, pArc1);
	AcArray<AcDbCurve*> arrpOffset2 = OffsetCurve(dRadius, pt1, pArc2);
	if (arrpOffset1.length() != 1 || arrpOffset2.length() != 1)
	{
		for (int i = 0; i < arrpOffset1.length(); i++)
			DEL(arrpOffset1[i]);
		for (int i = 0; i < arrpOffset2.length(); i++)
			DEL(arrpOffset2[i]);
		return false;
	}
	AcDbArc* pArcOffset1 = AcDbArc::cast(arrpOffset1[0]);
	AcDbArc* pArcOffset2 = AcDbArc::cast(arrpOffset2[0]);
	if (!pArcOffset1 || !pArcOffset2)
	{
		for (int i = 0; i < arrpOffset1.length(); i++)
			DEL(arrpOffset1[i]);
		for (int i = 0; i < arrpOffset2.length(); i++)
			DEL(arrpOffset2[i]);
		return false;
	}
	//求圆心
	AcGePoint3dArray arrptInter;
	pArcOffset1->intersectWith(pArcOffset2, AcDb::kExtendBoth, arrptInter);
	DEL(pArcOffset1);
	DEL(pArcOffset2);
	if (arrptInter.length() == 0)
		return false;
	AcGePoint3d ptCenter;
	if (arrptInter.length() == 1)
		ptCenter = arrptInter[0];
	else if (arrptInter.length() == 2)
	{
		double dDist1 = arrptInter[0].distanceTo(pt1);
		double dDist2 = arrptInter[1].distanceTo(pt2);
		if (dDist1 < dDist2)
			ptCenter = arrptInter[0];
		else
			ptCenter = arrptInter[1];
	}
	else
		return false;
	//求切点
	AcDbCircle* pCircleTemp = PhdEntity::CreateCircle(ptCenter, dRadius);
	AcGePoint3dArray arrptInter1, arrptInter2;
	pCircleTemp->intersectWith(pArc1, AcDb::kOnBothOperands, arrptInter1);
	pCircleTemp->intersectWith(pArc2, AcDb::kOnBothOperands, arrptInter2);
	DEL(pCircleTemp);
	if (arrptInter1.length() != 1 || arrptInter2.length() != 1)
		return false;
	//求两圆弧的交点
	arrptInter.removeAll();
	pArc1->intersectWith(pArc2, AcDb::kOnBothOperands, arrptInter);
	AcGePoint3d ptInter;
	if (arrptInter.length() == 1)
	{
		ptInter = arrptInter[0];
	}
	else if (arrptInter.length() == 2)
	{
		double dDist1 = arrptInter[0].distanceTo(pt1);
		double dDist2 = arrptInter[1].distanceTo(pt1);
		if (dDist1 < dDist2)
			ptInter = arrptInter[0];
		else
			ptInter = arrptInter[1];
	}
	else
		return false;
	//第一次修改圆弧（所选点在端点和交点之间）
	ModifyArcPtToInterPt(pArc1, pt1, ptInter);
	ModifyArcPtToInterPt(pArc2, pt2, ptInter);

	//创建圆角圆弧
	AcDbArc* pArcFillet1 = PhdEntity::CreateArcByPt2(ptCenter, arrptInter1[0], arrptInter2[0]);
	AcDbArc* pArcFillet2 = PhdEntity::CreateArcByPt2(ptCenter, arrptInter2[0], arrptInter1[0]);
	AcGePoint3d ptMid1 = PhdEntity::GetArcMidPt(pArcFillet1);
	AcGePoint3d ptMid2 = PhdEntity::GetArcMidPt(pArcFillet2);
	double dDistTemp1 = ptInter.distanceTo(ptMid1);
	double dDistTemp2 = ptInter.distanceTo(ptMid2);
	if (dDistTemp1 < dDistTemp2)
	{
		pArcFillet = pArcFillet1;
		DEL(pArcFillet2);
	}
	else
	{
		pArcFillet = pArcFillet2;
		DEL(pArcFillet1);
	}

	//第二次修改圆弧（交点处修改圆弧）
	PhdEntity::ModifyArcPt(pArc1, ptInter, arrptInter1[0]);
	PhdEntity::ModifyArcPt(pArc2, ptInter, arrptInter2[0]);

	return true;
}

CString PhdUtility::GetCurZrxFilePath()
{
	TCHAR szPath[_MAX_PATH];
	::GetModuleFileName(_hdllInstance, szPath, _MAX_PATH);
	return szPath;
}

CString PhdUtility::GetCurZrxFolderPath()
{
	TCHAR szPath[_MAX_PATH];
	::GetModuleFileName(_hdllInstance, szPath, _MAX_PATH);
	CString strZrxPath = szPath;
	int nIndex = strZrxPath.ReverseFind(_T('\\'));
	CString strFloder = strZrxPath.Left(nIndex + 1);
	return strFloder;
}

bool PhdUtility::LoadCadMenu(const CString& strMenuFileName, const CString& strMenuGroupName)
{
	CString strFilePath = strMenuFileName;

	CFileStatus st;
	if (!CFile::GetStatus(strFilePath, st))
		return false;

	if (strMenuGroupName.GetLength() < 1 || strFilePath.GetLength() < 1)
		return false;

	CString strCmdLoad;
	strFilePath.Replace(_T("\\"), _T("\\\\"));
	if (_T("") != strMenuGroupName && strFilePath.GetLength() > 0)
	{
		//加载有组名的菜单文件
		strCmdLoad.Format(_T("(if (null (menugroup \"%s\")) (command \"menuload\" \"%s\"))"), strMenuGroupName, strFilePath);
	}
	else
	{
		strCmdLoad.Format(_T("(command \"menuload\" \"%s\")"), strFilePath);
	}

	int erStat = ads_queueexpr((LPTSTR)(LPCTSTR)strCmdLoad);//此函数，相当于程序结束后，给CAD发送一个加载菜单的命令

	return true;
}

bool PhdUtility::UnloadCadMenu(const CString& strMenuGroupName)
{
	CString strCmdLoad;
	strCmdLoad.Format(_T("(command \"menuunload\" \"%s\")"), strMenuGroupName);
	int erStat = ads_queueexpr((LPTSTR)(LPCTSTR)strCmdLoad);
	return true;
}

bool PhdUtility::LoadZrxFile(LPCTSTR szFilePath)
{
	bool bRet = false;

	CFileStatus st;
	if (!CFile::GetStatus(szFilePath, st))
		return false;

	try
	{
		bRet = acrxLoadModule(st.m_szFullName, true, false);
	}
	catch (...)
	{
		bRet = false;
	}

	return bRet;
}

bool PhdUtility::AddSearchPath(LPCTSTR szSearchDir)
{
	CFileStatus st;
	if (!CFile::GetStatus(szSearchDir, st) || !(st.m_attribute & CFile::directory))
	{
		// 文件夹不存在，错误
		return false;
	}

	CString strSumPath;
	TCHAR szValue[1024];
	memset(szValue, 0, 1024 * sizeof(TCHAR));
	acedGetEnv(_T("ZWCAD"), szValue);//ACAD
	strSumPath = szValue;
	if (strSumPath.GetAt(strSumPath.GetLength() - 1) != _T(';'))
		strSumPath += _T(';');

	strSumPath = strSumPath + szSearchDir + _T(';');
	acedSetEnv(_T("ZWCAD"), strSumPath);//ACAD

	return true;
}

bool PhdUtility::GetIntersectPoint(const AcGeLineSeg2d& geLine, const AcGeCircArc2d& geCircArc, int& nNum, AcGePoint3dArray& arrptIntersect)
{
	nNum = 0;
	AcGePoint2d pt1, pt2;
	if (!geCircArc.intersectWith(geLine, nNum, pt1, pt2))
		return false;
	if (nNum == 1)
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
	else if (nNum == 2)
	{
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
		arrptIntersect.append(AcGePoint3d(pt2.x, pt2.y, 0));
	}
	return true;
}

bool PhdUtility::GetIntersectPoint(const AcGeLineSeg2d& geLine1, const AcGeLineSeg2d& geLine2, AcGePoint3d& ptIntersect)
{
	AcGePoint2d pt2d;
	bool bRet = geLine1.intersectWith(geLine2, pt2d);
	if (!bRet)
		return false;
	ptIntersect = AcGePoint3d(pt2d.x, pt2d.y, 0);
	return true;
}

bool PhdUtility::GetIntersectPoint(const AcGeLineSeg2d& geLine1, const AcGeLine2d& geLine2, AcGePoint3d& ptIntersect)
{
	AcGePoint2d pt2d;
	bool bRet = geLine1.intersectWith(geLine2, pt2d);
	if (!bRet)
		return false;
	ptIntersect = AcGePoint3d(pt2d.x, pt2d.y, 0);
	return true;
}

bool PhdUtility::GetIntersectPoint(const AcGeLine2d& geLine1, const AcGeLine2d& geLine2, 
	AcGePoint3d& ptIntersect)
{
	AcGePoint2d pt2d;
	bool bRet = geLine1.intersectWith(geLine2, pt2d);
	if (!bRet)
		return false;
	ptIntersect = AcGePoint3d(pt2d.x, pt2d.y, 0);
	return true;
}

AcArray<AcDbEntity*> PhdUtility::AnnularMatrix(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase, int nCurNum, int nSum)
{
	AcArray<AcDbEntity*> arrpMatrix;

	if (nSum < 2 || arrid.length() == 0)
		return arrpMatrix;

	AcArray<double> arrAngle;
	double dAngle = 360 / nSum;
	for (int i = 1; i < nCurNum; i++)
	{
		double dAngleTemp = dAngle * i;
		arrAngle.append(dAngleTemp);
	}

	for (int i = 0; i < arrAngle.length(); i++)
	{
		AcArray<AcDbEntity*> arrpCopy = PhdUtility::CopyEnt(arrid);
		PhdUtility::RotateEnt(arrpCopy, ptBase, PhdConver::ToRadian(arrAngle[i]));
		arrpMatrix.append(arrpCopy);
	}

	return arrpMatrix;
}

AcArray<AcDbEntity*> PhdUtility::AnnularMatrix(const AcArray<AcDbEntity*>& arrp,
	const AcGePoint3d& ptBase, int nYxcs, int nSum)
{
	AcArray<AcDbEntity*> arrpMatrix;

	if (nYxcs < 2 || arrp.length() == 0)
		return arrpMatrix;

	AcArray<double> arrAngle;
	double dAngle = 360.0 / nSum;
	for (int i = 1; i < nYxcs; i++)
	{
		double dAngleTemp = dAngle * i;
		arrAngle.append(dAngleTemp);
	}

	for (int i = 0; i < arrAngle.length(); i++)
	{
		AcArray<AcDbEntity*> arrpCopy = PhdUtility::CopyEnt(arrp);
		PhdUtility::RotateEnt(arrpCopy, ptBase, PhdConver::ToRadian(arrAngle[i]));
		arrpMatrix.append(arrpCopy);
	}

	return arrpMatrix;
}

double PhdUtility::GetArcBulge(AcDbArc* pArc)
{
	double dStartAngle = pArc->startAngle();
	double dEndAngle = pArc->endAngle();
	double dAlfa = dEndAngle - dStartAngle;

	if (dAlfa < 0.0)//如果终点角度小于起点角度;
	{
		dAlfa = 2 * (atan(1.0) * 4) + dAlfa;
	}
	double dBulge = 0.0;
	dBulge = tan((dAlfa) / 4.0);

	return dBulge;
}

double PhdUtility::GetArcBulge(const AcGeCircArc2d& geArc)
{
	double dStartAngle = geArc.startAng();
	double dEndAngle = geArc.endAng();
	double dAlfa = dEndAngle - dStartAngle;

	if (dAlfa < 0.0)//如果终点角度小于起点角度;
	{
		dAlfa = 2 * (atan(1.0) * 4) + dAlfa;
	}
	double dBulge = 0.0;
	dBulge = tan((dAlfa) / 4.0);

	return dBulge;
}

double PhdUtility::GetArcBulge(AcDbCurve* pCurve)
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

double PhdUtility::GetArcBulge(const AcDbObjectId& idArc)
{
	AcDbObjectPointer<AcDbArc> pArc(idArc,AcDb::kForRead);
	if (Acad::eOk != pArc.openStatus())
		return 0;

	double dStartAngle = pArc->startAngle();
	double dEndAngle = pArc->endAngle();
	double dAlfa = dEndAngle - dStartAngle;

	if (dAlfa < 0.0)//如果终点角度小于起点角度;
	{
		dAlfa = 2 * (atan(1.0) * 4) + dAlfa;
	}
	double dBulge = 0.0;
	dBulge = tan((dAlfa) / 4.0);

	return dBulge;
}

AcGeLine2d PhdUtility::GetGeLine2d(AcDbLine* pLine)
{
	AcGePoint3d ptStart = pLine->startPoint();
	AcGePoint3d ptEnd = pLine->endPoint();
	AcGeLine2d geLine;
	geLine.set(ptStart.convert2d(AcGePlane::kXYPlane), ptEnd.convert2d(AcGePlane::kXYPlane));
	return geLine;
}

AcGeLineSeg2d PhdUtility::GetGeLineSeg2d(AcDbLine* pLine)
{
	AcGePoint3d ptStart = pLine->startPoint();
	AcGePoint3d ptEnd = pLine->endPoint();
	AcGeLineSeg2d geLine;
	geLine.set(ptStart.convert2d(AcGePlane::kXYPlane), ptEnd.convert2d(AcGePlane::kXYPlane));
	return geLine;
}

AcGeCircArc2d PhdUtility::GetGeCircArc2d(AcDbPolyline* pPolyline, unsigned int unIndex)
{
	AcGeCircArc2d geCircArc;
	Acad::ErrorStatus es = pPolyline->getArcSegAt(unIndex, geCircArc);
	return geCircArc;
}

AcGeLineSeg2d PhdUtility::GetGeLineSeg2d(AcDbPolyline* pPolyline, unsigned int unIndex)
{
	AcGeLineSeg2d geLine;
	Acad::ErrorStatus es = pPolyline->getLineSegAt(unIndex, geLine);
	return geLine;
}

double PhdUtility::GetArcBulge(double dAngleStart, double dAngleEnd)
{
	double dAlfa = dAngleEnd - dAngleStart;

	if (dAlfa < 0.0)//如果终点角度小于起点角度;
	{
		dAlfa = 2 * (atan(1.0) * 4) + dAlfa;
	}
	double dBulge = 0.0;
	dBulge = tan((dAlfa) / 4.0);

	return dBulge;
}

bool PhdUtility::GetIntersectPoint(const AcGeCircArc2d& geCirArc1, const AcGeCircArc2d& geCirArc2, int& nNum, AcGePoint3dArray& arrptIntersect)
{
	AcGePoint2d pt1, pt2;
	nNum = 0;
	bool bRet = geCirArc1.intersectWith(geCirArc2, nNum, pt1, pt2);
	if (!bRet)
		return false;
	if (1 == nNum)
	{
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
	}
	else if (2 == nNum)
	{
		arrptIntersect.append(AcGePoint3d(pt1.x, pt1.y, 0));
		arrptIntersect.append(AcGePoint3d(pt2.x, pt2.y, 0));
	}
	return true;
}

bool PhdUtility::ModifyEntByScale(const AcDbObjectId& idEnt, double dScale, const AcGePoint3d& ptBase)
{
	AcDbEntityPointer pEnt(idEnt, AcDb::kForWrite);
	if (pEnt.openStatus() != Acad::eOk)
		return false;
	AcGeMatrix3d mtx;
	mtx.setToScaling(dScale, ptBase);
	Acad::ErrorStatus es = pEnt->transformBy(mtx);
	if (Acad::eOk == es)
		return true;
	else
		return false;
}
