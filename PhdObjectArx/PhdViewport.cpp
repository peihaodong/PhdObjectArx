#include "StdAfx.h"
#include "PhdViewport.h"
#include "PhdInline.h"

#define VIEW_FU			_T("viewport_fu")	//俯视图
#define VIEW_ZHU		_T("viewport_zhu")	//主视图
#define VIEW_LI			_T("viewport_li")	//立体图
#define VIEW_YOU		_T("viewport_you")	//右视图
#define VIEW_ZUO		_T("viewport_zuo")	//左视图
#define VIEW_SI			_T("viewport_Si")	//四视图

//视图方向
#define ViewDirection_Fu	AcGeVector3d(0,0,1)		//俯视图方向
#define ViewDirection_Zhu	AcGeVector3d(0,-1,0)	//主视图方向
#define ViewDirection_You	AcGeVector3d(1,0,0)		//右视图方向
#define ViewDirection_Zuo	AcGeVector3d(-1,0,0)	//左视图方向
#define ViewDirection_Li	AcGeVector3d(1,-1,1)	//立体图方向

void PhdViewport::CreateViewport()
{
	AcDbViewportTable *pViewTab = NULL;
	acdbHostApplicationServices()->workingDatabase()->getViewportTable(pViewTab, AcDb::kForWrite);

	AcDbObjectId idFindView = AcDbObjectId::kNull;
	pViewTab->getAt(VIEW_SI, idFindView);
	if (idFindView != AcDbObjectId::kNull)
	{
		pViewTab->close();
		acutPrintf(_T("\n已存在视图"));
		return;
	}

	AcDbViewportTableRecord *pRec1 = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pRec2 = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pRec3 = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pRec4 = new AcDbViewportTableRecord;
	pRec1->setLowerLeftCorner(AcGePoint2d(0, 0));
	pRec1->setUpperRightCorner(AcGePoint2d(0.5, 0.5));
	pRec2->setLowerLeftCorner(AcGePoint2d(0.5, 0));
	pRec2->setUpperRightCorner(AcGePoint2d(1, 0.5));
	pRec3->setLowerLeftCorner(AcGePoint2d(0, 0.5));
	pRec3->setUpperRightCorner(AcGePoint2d(0.5, 1));
	pRec4->setLowerLeftCorner(AcGePoint2d(0.5, 0.5));
	pRec4->setUpperRightCorner(AcGePoint2d(1, 1));
	//方向
	pRec1->setViewDirection(ViewDirection_Zhu);//主视图		
	pRec2->setViewDirection(ViewDirection_You);	//右视图	
	pRec3->setViewDirection(ViewDirection_Fu);	//俯视图
	pRec4->setViewDirection(ViewDirection_Li);//立体图
	//名称
	pRec1->setName(VIEW_SI);
	pRec2->setName(VIEW_SI);
	pRec3->setName(VIEW_SI);
	pRec4->setName(VIEW_SI);
	//中心点
	//高
	pRec1->setHeight(430);
	pRec2->setHeight(430);
	pRec3->setHeight(430);
	pRec4->setHeight(430);
	//宽
/*	pRec1->setWidth();*/
	//添加到视图表
	pViewTab->add(pRec1);
	pViewTab->add(pRec2);
	pViewTab->add(pRec3);
	pViewTab->add(pRec4);

	AcDbViewportTableRecord *pRecfst = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pReczst = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pRecLtt = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pRecyst = new AcDbViewportTableRecord;
	AcDbViewportTableRecord *pReczuost = new AcDbViewportTableRecord;
	//俯视图
	pRecfst->setLowerLeftCorner(AcGePoint2d(0, 0));
	pRecfst->setUpperRightCorner(AcGePoint2d(1, 1));
	pRecfst->setViewDirection(ViewDirection_Fu);
	pRecfst->setName(VIEW_FU);
	pRecfst->setHeight(430);//高
	//主视图
	pReczst->setLowerLeftCorner(AcGePoint2d(0, 0));
	pReczst->setUpperRightCorner(AcGePoint2d(1, 1));
	pReczst->setViewDirection(ViewDirection_Zhu);
	pReczst->setName(VIEW_ZHU);
	pReczst->setHeight(430);//高
	//立体图
	pRecLtt->setLowerLeftCorner(AcGePoint2d(0, 0));
	pRecLtt->setUpperRightCorner(AcGePoint2d(1, 1));
	pRecLtt->setViewDirection(ViewDirection_Li);
	pRecLtt->setName(VIEW_LI);
	pRecLtt->setHeight(430);//高
	//右视图
	pRecyst->setLowerLeftCorner(AcGePoint2d(0, 0));
	pRecyst->setUpperRightCorner(AcGePoint2d(1, 1));
	pRecyst->setViewDirection(ViewDirection_You);
	pRecyst->setName(VIEW_YOU);
	pRecyst->setHeight(430);//高
	//左视图
	pReczuost->setLowerLeftCorner(AcGePoint2d(0, 0));
	pReczuost->setUpperRightCorner(AcGePoint2d(1, 1));
	pReczuost->setViewDirection(ViewDirection_Zuo);
	pReczuost->setName(VIEW_ZUO);
	pReczuost->setHeight(430);//高

	pViewTab->add(pRecfst);
	pViewTab->add(pReczst);
	pViewTab->add(pRecLtt);
	pViewTab->add(pRecyst);
	pViewTab->add(pReczuost);

	pViewTab->close();
	pRec1->close();
	pRec2->close();
	pRec3->close();
	pRec4->close();

	pRecfst->close();
	pRecLtt->close();
	pRecyst->close();
	pReczst->close();
	pReczuost->close();
	acutPrintf(_T("\n已创建四个视图!"));
}

void PhdViewport::ShowViewportSi()
{
	acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_SI, RTNONE);
}

void PhdViewport::ShowViewportFu()
{
	acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_FU, RTNONE);
}

void PhdViewport::ShowViewportZhu()
{
	acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_ZHU, RTNONE);
}

void PhdViewport::ShowViewportLi()
{
	acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_LI, RTNONE);
}

void PhdViewport::ShowViewportZuo()
{
	acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_ZUO, RTNONE);
}

void PhdViewport::ShowViewportDan()
{
	AcDbObjectId idViewport = acedActiveViewportId();
	AcDbViewportTableRecordPointer pViewport(idViewport, AcDb::kForRead);
	if (Acad::eOk != pViewport.openStatus())
		return;
	AcGeVector3d vec = pViewport->viewDirection();
	pViewport->close();
	if (vec == ViewDirection_Fu)
	{
		acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_FU, RTNONE);
	}
	else if (vec == ViewDirection_Zhu)
	{
		acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_ZHU, RTNONE);
	}
	else if (vec == ViewDirection_You)
	{
		acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_YOU, RTNONE);
	}
	else if (vec == ViewDirection_Zuo)
	{
		acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_ZUO, RTNONE);
	}
	else if (vec == ViewDirection_Li)
	{
		acedCommand(RTSTR, _T("VPORTS"), RTSTR, _T("R"), RTSTR, VIEW_LI, RTNONE);
	}
	else
	{
	}
}

bool PhdViewport::SetViewportRange(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax,
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId idViewport = GetViewportId(pDb);

	AcDbViewportTableRecordPointer pVpTblRcd(idViewport,AcDb::kForWrite);
	if (Acad::eOk != pVpTblRcd.openStatus())
		return false;
	double dHeight = ptMax.y - ptMin.y;
	double dWidth = ptMax.x - ptMin.x;
	pVpTblRcd->setHeight(dHeight);	//高
	pVpTblRcd->setWidth(dWidth);	//宽
	return true;
}

AcDbObjectId PhdViewport::GetViewportId(AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId idViewport = pDb->viewportTableId();
	AcDbViewportTablePointer pViewportTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pViewportTbl.openStatus())
		return AcDbObjectId::kNull;
	AcDbViewportTableIterator* pIter = NULL;
	Acad::ErrorStatus es = pViewportTbl->newIterator(pIter);
	if (Acad::eOk != es)
		return AcDbObjectId::kNull;

	AcDbObjectIdArray arrid;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbViewportTableRecord* pVPRecord = NULL;
		if (pIter->getRecord(pVPRecord, AcDb::kForRead) == Acad::eOk)
		{
			arrid.append(pVPRecord->objectId());
			pVPRecord->close();
		}
	}
	DEL(pIter);

	if (arrid.length() == 0)
		return AcDbObjectId::kNull;
	else
		return arrid[0];
}

bool PhdViewport::SetViewportRange(double dX, double dY, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId idViewport = GetViewportId(pDb);
	AcDbViewportTableRecordPointer pVpTblRcd(idViewport, AcDb::kForWrite);
	if (Acad::eOk != pVpTblRcd.openStatus())
		return false;
	pVpTblRcd->setHeight(dY);	//高
	pVpTblRcd->setWidth(dX);	//宽
	AcGePoint2d ptCenter(dX/2,dY/2);
	pVpTblRcd->setCenterPoint(ptCenter);	//中点
	return true;
}
