#include "StdAfx.h"
#include "PhdEntity.h"
#include "PhdUtility.h"
#include "PhdConver.h"
#include "PhdInline.h"



AcDbWipeout* PhdEntity::CreateWipeout(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax)
{
	double dLength = ptMax.x - ptMin.x;
	double dWidth = ptMax.y - ptMin.y;
	AcDbWipeout* pWipeout = new AcDbWipeout;
	pWipeout->setDatabaseDefaults();
	AcGeVector3d Udirection(dLength, 0, 0);
	AcGeVector3d Vdirection(0, dWidth, 0);
	pWipeout->setOrientation(ptMin, Udirection, Vdirection);

	pWipeout->setDisplayOpt(AcDbRasterImage::kTransparent, Adesk::kTrue);
	pWipeout->setDisplayOpt(AcDbRasterImage::kShow, true);
	pWipeout->setClipBoundaryToWholeImage();

	return pWipeout;
}

AcDbPolyline* PhdEntity::CreatePolyline(const AcGePoint3dArray& ptArr)
{
	if (ptArr.length() < 2)
		return NULL;
	AcGePoint2dArray pt2ds;
	for (int i = 0; i < ptArr.length(); i++)
		pt2ds.append(ptArr[i].convert2d(AcGePlane::kXYPlane));
	//创建多段线
	AcDbPolyline* pPoly = new AcDbPolyline();
	for (int i = 0; i < pt2ds.length(); ++i)
		pPoly->addVertexAt(i, pt2ds[i]);
	return pPoly;
}

AcDbPolyline* PhdEntity::CreatePolyline(const AcGePoint3dArray& arrpt,
	const AcArray<double>& arrdBulge)
{
	//创建多段线
	AcDbPolyline* pPoly = new AcDbPolyline();
	for (int i = 0; i < arrpt.length(); i++)
		pPoly->addVertexAt(i, PhdConver::ToPt2d(arrpt[i]),arrdBulge[i]);
	return pPoly;
}

bool PhdEntity::IsClosedPline(AcDbPolyline* pPline)
{
	bool bClosed = pPline->isClosed();
	if (bClosed)
		return true;

	AcGePoint3d ptStart, ptEnd;
	pPline->getStartPoint(ptStart);
	pPline->getEndPoint(ptEnd);
	if (ptStart.isEqualTo(ptEnd))
		return true;
	else
		return false;
}

AcDbPolyline* PhdEntity::CreatePolyline(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax)
{
	AcDbPolyline* pPoly = new AcDbPolyline();
	pPoly->addVertexAt(0, AcGePoint2d(ptMin.x, ptMin.y));
	pPoly->addVertexAt(1, AcGePoint2d(ptMax.x, ptMin.y));
	pPoly->addVertexAt(2, AcGePoint2d(ptMax.x, ptMax.y));
	pPoly->addVertexAt(3, AcGePoint2d(ptMin.x, ptMax.y));
	pPoly->setClosed(true);
	return pPoly;
}

bool PhdEntity::CreateRegion(const AcArray<AcDbEntity*>& arrpEnt, AcArray<AcDbRegion*>& arrpRegion)
{
	AcDbVoidPtrArray curves;
	for (int i = 0; i < arrpEnt.length(); ++i)
		curves.append(static_cast<void*>(arrpEnt.at(i)));

	AcDbVoidPtrArray regions;
	AcDbRegion* pRegion = NULL;
	Acad::ErrorStatus es = AcDbRegion::createFromCurves(curves, regions);
	if (es == Acad::eOk)
	{
		for (int i = 0; i < regions.length(); ++i)
		{
			pRegion = (AcDbRegion*)regions[i];
			if (NULL != pRegion)
				arrpRegion.append(pRegion);
		}
		return true;
	}
	else
	{// 如果创建不成功，也要删除已经生成的面域;
		for (int i = 0; i < regions.length(); i++)
			delete (AcRxObject*)regions[i];
		return false;
	}
}

bool PhdEntity::CreateRegion(AcDbEntity* pEnt, AcArray<AcDbRegion*>& arrpRegion)
{
	AcDbVoidPtrArray curves;
	curves.append(static_cast<void*>(pEnt));

	AcDbVoidPtrArray regions;
	AcDbRegion* pRegion = NULL;
	Acad::ErrorStatus es = AcDbRegion::createFromCurves(curves, regions);
	if (es == Acad::eOk)
	{
		for (int i = 0; i < regions.length(); ++i)
		{
			pRegion = (AcDbRegion*)regions[i];
			if (NULL != pRegion)
				arrpRegion.append(pRegion);
		}
		return true;
	}
	else
	{// 如果创建不成功，也要删除已经生成的面域;
		for (int i = 0; i < regions.length(); i++)
			delete (AcRxObject*)regions[i];
		return false;
	}
}

AcDbArc* PhdEntity::CreateArc(const AcGePoint3d& ptStart, const AcGePoint3d& ptOnArc, const AcGePoint3d& ptEnd)
{
	// 使用几何类获得圆心、半径;
	AcGeCircArc2d geArc(ptStart.convert2d(AcGePlane::kXYPlane), ptOnArc.convert2d(AcGePlane::kXYPlane), ptEnd.convert2d(AcGePlane::kXYPlane));
	AcGePoint2d ptCenter = geArc.center();
	double radius = geArc.radius();

	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();
	AcDbArc* pArc = new AcDbArc(AcGePoint3d(ptCenter.x, ptCenter.y, 0), radius, startAngle, endAngle);

	return pArc;
}

AcDbArc* PhdEntity::CreateArcByPt(const AcGePoint3d& ptCenter, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	// 计算半径;
	double radius = ptCenter.distanceTo(pt1);
	// 计算起始和终止角度;
	AcGeVector2d vecStart(pt1.x - ptCenter.x, pt1.y - ptCenter.y);
	AcGeVector2d vecEnd(pt2.x - ptCenter.x, pt2.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();
	double dBulge = PhdUtility::GetArcBulge(startAngle, endAngle);
	if (0 > dBulge)
	{
		vecStart = AcGeVector2d(pt2.x - ptCenter.x, pt2.y - ptCenter.y);
		vecEnd = AcGeVector2d(pt1.x - ptCenter.x, pt1.y - ptCenter.y);
		startAngle = vecStart.angle();
		endAngle = vecEnd.angle();
		dBulge = PhdUtility::GetArcBulge(startAngle, endAngle);
		if (0 > dBulge)
			return NULL;
	}
	AcDbArc* pArc = new AcDbArc(ptCenter, radius, startAngle, endAngle);

	return pArc;
}

AcDbArc* PhdEntity::CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, 
	const AcGePoint3d& ptEnd)
{
	// 计算半径;
	double radius = ptCenter.distanceTo(ptStart);
	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();
	
	AcDbArc* pArc = new AcDbArc(ptCenter, radius, startAngle, endAngle);

	return pArc;
}

AcDbArc* PhdEntity::CreateArcBy3Pt(const AcGePoint3d& pt1,
	const AcGePoint3d& ptOnArc, const AcGePoint3d& pt2)
{
	AcGeCircArc2d geArc(PhdConver::ToPt2d(pt1),
		PhdConver::ToPt2d(ptOnArc), PhdConver::ToPt2d(pt2));
	AcGePoint2d ptCenter = geArc.center();
	double dRadius = geArc.radius();
	AcDbCircle* pCircle = CreateCircle(PhdConver::ToPt3d(ptCenter),dRadius);
	std::shared_ptr<AcDbCircle> apCircle(pCircle);
	AcGePoint3dArray arrptSplit;
	arrptSplit.append(pt1);
	arrptSplit.append(pt2);
	AcArray<AcDbCurve*> arrpSplit = PhdUtility::SplitCurve(pCircle,arrptSplit);
	if (arrptSplit.length() != 2)
	{
		for (int i = 0; i < arrpSplit.length(); i++)
			DEL(arrpSplit[i]);
		return nullptr;
	}
	AcDbArc* pArcSplit1 = AcDbArc::cast(arrpSplit[0]);
	AcDbArc* pArcSplit2 = AcDbArc::cast(arrpSplit[1]);
	if (!pArcSplit1 || !pArcSplit2)
	{
		for (int i = 0; i < arrpSplit.length(); i++)
			DEL(arrpSplit[i]);
		return nullptr;
	}
	//判断该点是否在圆弧上
	if (PhdUtility::IsPtOnCurve(ptOnArc, pArcSplit1))
	{
		DEL(pArcSplit2);
		return pArcSplit1;
	}
	else
	{
		DEL(pArcSplit1);
		return pArcSplit2;
	}
}

AcDbArc* PhdEntity::CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, 
	const AcGePoint3d& ptEnd, const AcDbObjectId& idProEnt)
{
	AcDbEntityPointer pEnt(idProEnt, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return NULL;

	// 计算半径;
	double radius = ptCenter.distanceTo(ptStart);
	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();

	AcDbArc* pArc = new AcDbArc(ptCenter, radius, startAngle, endAngle);
	if (pEnt)
		pArc->setPropertiesFrom(pEnt);

	return pArc;
}

AcDbText* PhdEntity::CreateTextForCenter(double dHeight, const AcGePoint3d& pt, LPCTSTR szText)
{
	AcDbText* pText = new AcDbText(pt, szText, AcDbObjectId::kNull, dHeight);
	pText->setHorizontalMode(AcDb::kTextMid); 
	pText->setVerticalMode(AcDb::kTextVertMid);
	pText->setAlignmentPoint(pt);
	return pText;
}

AcDbText* PhdEntity::CreateTextForCenter(const AcGePoint3d& pt, LPCTSTR szText, const AcDbObjectId& idProEnt)
{
	AcDbObjectPointer<AcDbText> pText(idProEnt,AcDb::kForRead);
	if (Acad::eOk != pText.openStatus())
		return NULL;
	double dHeight = pText->height();
	double dWidthScale = pText->widthFactor();
	AcDbObjectId idTextStyle = pText->textStyle();

	AcDbText* pNewText = new AcDbText(pt, szText, idTextStyle, dHeight);
	pNewText->setPropertiesFrom(pText);
	pNewText->setHorizontalMode(AcDb::kTextCenter);
	pNewText->setVerticalMode(AcDb::kTextVertMid);
	pNewText->setAlignmentPoint(pt);
	pNewText->setWidthFactor(dWidthScale);
	
	return pNewText;
}

AcDbText* PhdEntity::CreateTextForLeftTop(double dHeight, const AcGePoint3d& pt, LPCTSTR szText)
{
	AcDbText* pText = new AcDbText(pt, szText, AcDbObjectId::kNull, dHeight);
	pText->setHorizontalMode(AcDb::kTextLeft);
	pText->setVerticalMode(AcDb::kTextTop);
	pText->setAlignmentPoint(pt);
	return pText;
}

AcDbText* PhdEntity::CreateTextForLeft(double dHeight, const AcGePoint3d& pt, LPCTSTR szText)
{
	AcDbText* pText = new AcDbText(pt, szText, AcDbObjectId::kNull, dHeight);
 	pText->setAlignmentPoint(pt);
	return pText;
}

AcDbText* PhdEntity::CreateTextForLeft(const AcGePoint3d& pt, LPCTSTR szText, const AcDbObjectId& idProEnt)
{
	AcDbObjectPointer<AcDbText> pText(idProEnt,AcDb::kForRead);
	if (Acad::eOk != pText.openStatus())
		return NULL;
	double dHeight = pText->height();	//字高
	AcDbObjectId idTextStyle = pText->textStyle();	//文字样式
	double dWidthScale = pText->widthFactor();	//宽度比例

	AcDbText* pNewText = new AcDbText(pt, szText, idTextStyle, dHeight);
	pNewText->setWidthFactor(dWidthScale);
	pNewText->setPropertiesFrom(pText);

	return pNewText;
}

AcDbText* PhdEntity::CreateTextForLeft(double dHeight, const AcGePoint3d& pt, LPCTSTR szText, AcDbEntity* pProEnt)
{
	AcDbText* pText = new AcDbText(pt, szText, AcDbObjectId::kNull, dHeight);
	pText->setAlignmentPoint(pt);
	if (pProEnt)
		pText->setPropertiesFrom(pProEnt);
	return pText;
}

AcDbTable* PhdEntity::CreateTable(const AcGePoint3d& ptInster)
{
	AcDbTable *pTab = new AcDbTable;

	//格式设置
	AcDbDictionary *pDict = NULL;
	AcDbObjectId idTblStyle;
	acdbHostApplicationServices()->workingDatabase()->getTableStyleDictionary(pDict, AcDb::kForRead);
	pDict->getAt(_T("Standard"), idTblStyle);
	pDict->close();
	pTab->setTableStyle(idTblStyle);
	AcDbTextStyleTable* pTextStyle = NULL;
	acdbHostApplicationServices()->workingDatabase()->getTextStyleTable(pTextStyle, AcDb::kForRead);
	AcDbObjectId textID;
	pTextStyle->getAt(_T("Standard"), textID);
	pTextStyle->close();
	if (!textID.isNull())
	{
		pTab->setTextStyle(textID);
	}
	pTab->setPosition(ptInster);		//插入点
	//初始化表格
	pTab->setNumRows(6);			//初始化表格行数
	pTab->setNumColumns(6);			//初始化表格列数
	pTab->generateLayout();			//此函数将根据当前表样式更新表对象
	pTab->setRowHeight(0, 1000);	//设置表格行高
	for (int i = 1; i < 6; i++)
	{
		pTab->setRowHeight(i, 700);	//设置表格行宽
	}
	pTab->setTextHeight(450);		//设置表格文字高度
	pTab->setColumnWidth(0, 1300);	//设置表格列宽
	pTab->setColumnWidth(1, 2700);
	pTab->setColumnWidth(2, 1800);
	pTab->setColumnWidth(3, 1800);
	pTab->setColumnWidth(4, 1800);
	pTab->setColumnWidth(5, 1800);
	pTab->mergeCells(0, 0, 0, 1);	//合并单元格
	pTab->setTextString(0, 0, _T("位置"));	
	pTab->setTextString(0, 2, _T("单件重(kg)"));
	pTab->setTextString(0, 3, _T("数量(件)"));
	pTab->setTextString(0, 4, _T("小计(kg)"));
	pTab->setTextString(0, 5, _T("总重(kg)"));
	
	return pTab;
}

AcDbLine* PhdEntity::CreateLine(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd)
{
	AcDbLine* pLine = new AcDbLine(ptStart,ptEnd);
	return pLine;
}

AcDbLine* PhdEntity::CreateLine(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, const AcDbObjectId& idProEnt)
{
	AcDbEntityPointer pEnt(idProEnt,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return NULL;
	AcDbLine* pLine = new AcDbLine(ptStart, ptEnd);
	if (pEnt)
		pLine->setPropertiesFrom(pEnt);
	return pLine;
}

AcDbLine* PhdEntity::CreateLine(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, AcDbEntity* pProEnt)
{
	AcDbLine* pLine = new AcDbLine(ptStart, ptEnd);
	if (pProEnt)
		pLine->setPropertiesFrom(pProEnt);
	return pLine;
}

AcDbLeader* PhdEntity::CreateLeader(const AcGePoint3dArray& arrpt, 
	double dArrowSize, double dDimScale)
{
	if (arrpt.length() < 2)
		return NULL;
	AcDbLeader* pLeader = new AcDbLeader;
	for (int i = 0; i < arrpt.length(); i++)
	{
		pLeader->appendVertex(arrpt[i]);
	}
	pLeader->setDimasz(dArrowSize);	//箭头大小
	pLeader->setDimldrblk(_T("实心闭合")); //箭头实心闭合
	pLeader->setDimscale(dDimScale);	//设置标注全局比例
	return pLeader;
}

AcDbPoint* PhdEntity::CreatePoint(const AcGePoint3d& pt)
{
	AcDbPoint* pPt = new AcDbPoint(pt);
	return pPt;
}

AcDbArc* PhdEntity::CreateArc(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, double dRadius)
{
	AcGeCircArc2d geCircle1(ptStart.convert2d(AcGePlane::kXYPlane), dRadius);
	AcGeCircArc2d geCircle2(ptEnd.convert2d(AcGePlane::kXYPlane), dRadius);
	AcGePoint3dArray arrptInter;
	int nNum = 0;
	bool bRet = PhdUtility::GetIntersectPoint(geCircle1, geCircle2, nNum, arrptInter);
	if (!bRet)
		return NULL;
	AcGePoint3d ptCenter;	//圆心点
	if (1 == nNum)
	{
		AcGePoint3d pt = arrptInter[0];
		// 计算起始和终止角度;
		AcGeVector2d vecStart(ptStart.x - pt.x, ptStart.y - pt.y);
		AcGeVector2d vecEnd(ptEnd.x - pt.x, ptEnd.y - pt.y);
		double startAngle = vecStart.angle();
		double endAngle = vecEnd.angle();
		double dBulge = PhdUtility::GetArcBulge(startAngle, endAngle);
		if (0 > dBulge)
			return NULL;
		ptCenter = pt;
	}
	else if (2 == nNum)
	{
		AcGePoint3d pt1 = arrptInter[0];
		AcGePoint3d pt2 = arrptInter[1];
		// 计算起始和终止角度;
		AcGeVector2d vecStart(ptStart.x - pt1.x, ptStart.y - pt1.y);
		AcGeVector2d vecEnd(ptEnd.x - pt1.x, ptEnd.y - pt1.y);
		double startAngle = vecStart.angle();
		double endAngle = vecEnd.angle();
		double dBulge = PhdUtility::GetArcBulge(startAngle, endAngle);
		if (0 > dBulge)
		{
			vecStart = AcGeVector2d(ptStart.x - pt2.x, ptStart.y - pt2.y);
			vecEnd = AcGeVector2d(ptEnd.x - pt2.x, ptEnd.y - pt2.y);
			startAngle = vecStart.angle();
			endAngle = vecEnd.angle();
			dBulge = PhdUtility::GetArcBulge(startAngle, endAngle);
			if (0 > dBulge)
				return NULL;
			ptCenter = pt2;
		}
		else
		{
			ptCenter = pt1;
		}
	}
	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();
	AcDbArc* pArc = new AcDbArc(ptCenter, dRadius, startAngle, endAngle);

	return pArc;
}

AcDbWipeout* PhdEntity::CreateWipeout(const AcGePoint3dArray& ptArr)
{
	if (ptArr.length() < 3)
		return NULL;

	Acad::ErrorStatus es = AcDbWipeout::createImageDefinition();
	if (es != Acad::eOk)
		return NULL;

	AcGePoint3dArray pts3d = ptArr;
	if (!pts3d[0].isEqualTo(pts3d.last()))
		pts3d.append(pts3d[0]);

	AcDbWipeout* pWipeout = new AcDbWipeout;
	pWipeout->setDatabaseDefaults();

	AcDbExtents extents;
	for (int i = 0; i < pts3d.length(); ++i)
		extents.addPoint(pts3d.at(i));

	AcGePoint3d minPt = extents.minPoint(), maxPt = extents.maxPoint();
	AcGePoint3d originPnt(minPt);
	AcGeVector3d Udirection(maxPt.x - minPt.x, 0, 0);//长度
	AcGeVector3d Vdirection(0, maxPt.y - minPt.y, 0);//宽度
	pWipeout->setOrientation(originPnt, Udirection, Vdirection);

	AcGeMatrix3d PixelToModel, ModelToPixel;
	pWipeout->getPixelToModelTransform(PixelToModel);
	ModelToPixel = PixelToModel.invert();
	for (int i = 0; i < pts3d.length(); i++)
		pts3d[i].transformBy(ModelToPixel);

	AcGePoint2dArray pts2d;
	for (int i = 0; i < pts3d.length(); ++i)
		pts2d.append(pts3d[i].convert2d(AcGePlane::kXYPlane));

	pWipeout->setDisplayOpt(AcDbRasterImage::kTransparent, Adesk::kTrue);
	pWipeout->setDisplayOpt(AcDbRasterImage::kShow, true);
	es = pWipeout->setClipBoundaryToWholeImage();
	es = pWipeout->setClipBoundary(AcDbRasterImage::kPoly, pts2d);

	return pWipeout;
}

AcGePoint3d PhdEntity::GetArcMidPt(AcDbArc* pArc)
{
	double dStartParam = 0, dEndParam = 0;
	pArc->getStartParam(dStartParam);
	pArc->getEndParam(dEndParam);
	double dMidParam = ((dEndParam - dStartParam) / 2) + dStartParam;
	AcGePoint3d ptMid;
	pArc->getPointAtParam(dMidParam, ptMid);
	return ptMid;
}

bool PhdEntity::ModifyArcPt(AcDbArc* pArc, const AcGePoint3d& ptFrom,
	const AcGePoint3d& ptTo)
{
	AcGePoint3d ptStart, ptEnd;
	pArc->getStartPoint(ptStart);
	pArc->getEndPoint(ptEnd);
	double dRadius = pArc->radius();
	AcGePoint3d ptCenter = pArc->center();

	double dStartParam = 0, dEndParam = 0, dFromParam = 0;
	pArc->getStartParam(dStartParam);
	pArc->getEndParam(dEndParam);
	AcGePoint3d ptClosed;
	pArc->getClosestPointTo(ptFrom, ptClosed);
	pArc->getParamAtPoint(ptClosed, dFromParam);

	if ((dFromParam - dStartParam) < ((dEndParam - dStartParam) / 2))
	{//修改起始点
		ptStart = ptTo;
	}
	else
	{//修改终止点
		ptEnd = ptTo;
	}

	// 计算起始和终止角度;
	AcGeVector2d vecStart(ptStart.x - ptCenter.x, ptStart.y - ptCenter.y);
	AcGeVector2d vecEnd(ptEnd.x - ptCenter.x, ptEnd.y - ptCenter.y);
	double startAngle = vecStart.angle();
	double endAngle = vecEnd.angle();

	pArc->setStartAngle(startAngle);
	pArc->setEndAngle(endAngle);

	return true;
}

AcDbCircle* PhdEntity::CreateCircle(const AcGePoint3d& ptCenter, double dRadius)
{
	AcDbCircle* pCircle = new AcDbCircle(ptCenter, AcGeVector3d(0, 0, 1), dRadius);
	return pCircle;
}
