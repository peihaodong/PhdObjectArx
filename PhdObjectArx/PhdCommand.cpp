#include "StdAfx.h"
#include "PhdCommand.h"
#include "PhdUtility.h"
#include "PhdInline.h"



void PhdCommand::CommandEchoOff()
{
	resbuf var;
	int nRs = acedGetVar(_T("CMDECHO"), &var);
	if (var.resval.rint)//打开了命令回显
		acedCommand(RTSTR, _T("CMDECHO"), RTSHORT, 0, RTNONE);
}

bool PhdCommand::SetDimLineScale(double dValue)
{
	int nRet = acedCommand(RTSTR, _T("DIMLFAC"), RTREAL, dValue, RTNONE);
	return nRet == RTNORM;
}

bool PhdCommand::SetDimScale(double dValue)
{
	int nRet = acedCommand(RTSTR, _T("DIMSCALE"), RTREAL, dValue, RTNONE);
	return nRet == RTNORM;
}

bool PhdCommand::SetWipeoutShow(bool bShow /*= false*/)
{
	int nRet;
	if (bShow)
		nRet = acedCommand(RTSTR, _T("wipeout"), RTSTR, _T("f"), RTSTR, _T("on"), RTNONE);
	else
		nRet = acedCommand(RTSTR, _T("wipeout"), RTSTR, _T("f"), RTSTR, _T("off"), RTNONE);
	return nRet == RTNORM;
}

bool PhdCommand::SetFilletRadius(double dRadius)
{
	int nRet = acedCommand(RTSTR, _T("_fillet"), RTSTR, _T("r"), RTREAL, dRadius, RTNONE);
	return nRet == RTNORM;
}

AcDbObjectId PhdCommand::FilletByCommand(const AcDbObjectId& id1, const AcDbObjectId& id2)
{
	AcDbPoint* pt = new AcDbPoint(AcGePoint3d::kOrigin);
	AcDbObjectId ptId = PhdUtility::PostToModelSpace(pt);

	AcDbObjectId idArc;
	ads_name name1, name2;
	acdbGetAdsName(name1, id1);
	acdbGetAdsName(name2, id2);
	int nRet = acedCommand(RTSTR, _T("_fillet"), RTENAME, name1, RTENAME, name2, RTNONE);
	if (nRet != RTNORM)
		return AcDbObjectId::kNull;
	//得到圆弧id
	ads_name lastEnt;
	acdbEntLast(lastEnt);
	acdbGetObjectId(idArc, lastEnt);
	if (idArc == ptId)
	{
		AcDbObjectPointer<AcDbPoint> pPt(ptId, AcDb::kForWrite);
		if (Acad::eOk == pPt.openStatus())
			pPt->erase();
		return AcDbObjectId::kNull;
	}
	else
	{
		AcDbObjectPointer<AcDbPoint> pPt(ptId, AcDb::kForWrite);
		if (Acad::eOk == pPt.openStatus())
			pPt->erase();
	}
	return idArc;
}

bool PhdCommand::OrientationEnt(const AcDbObjectId& idEnt)
{
	AcDbEntityPointer pEnt(idEnt, AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	AcDbExtents extent;
	pEnt->getGeomExtents(extent);
	pEnt->highlight();	//设置实体为高亮状态
	AcGePoint3d ptMin = extent.minPoint();
	AcGePoint3d ptMax = extent.maxPoint();
	double dWidth = fabs(ptMax.x - ptMin.x);
	double dHeight = fabs(ptMax.y - ptMin.y);
	AcGePoint3d CenterPt;
	CenterPt.x = (ptMax.x + ptMin.x) / 2;
	CenterPt.y = (ptMax.y + ptMin.y) / 2;
	ptMax.x = CenterPt.x + (dWidth / 2) * 2;
	ptMax.y = CenterPt.y + (dHeight / 2) * 2;
	ptMin.x = CenterPt.x - (dWidth / 2) * 2;
	ptMin.y = CenterPt.y - (dHeight / 2) * 2;

	CString strCommand;
	strCommand.Format(_T("ZOOM\nw\n%lf,%lf,%lf\n%lf,%lf,%lf\n"), ptMin.x, ptMin.y, ptMin.z, ptMax.x, ptMax.y, ptMax.z);
	acDocManager->sendStringToExecute(acDocManager->curDocument(), strCommand, true, false, false);
	return true;
}

bool PhdCommand::ZoomAllEnt()
{
	int nRet = acedCommand(RTSTR, _T("zoom"), RTSTR, _T("a"),  RTNONE);
	return nRet == RTNORM;
}

bool PhdCommand::SplineToPline(const AcDbObjectIdArray& arridSpline,
	AcDbObjectIdArray& arridPline, int nPrecision /*= 10*/)
{
	CommandEchoOff();//关闭命令回显

	AcArray<AcDbEntity*> arrpEntCopy = PhdUtility::CopyEnt(arridSpline);
	AcDbObjectIdArray arridCopy;
	for (int i = 0; i < arrpEntCopy.length(); i++)
	{
		AcDbObjectId idTemp = PhdUtility::PostToModelSpace(arrpEntCopy[i]);
		if (idTemp)
			arridCopy.append(idTemp);
	}
	//将id转为ads_name
	ads_name ssname;
	for (int i = 0; i < arridCopy.length(); i++)
	{
		ads_name ent;
		acdbGetAdsName(ent, arridCopy[i]);
		acedSSAdd(ent, ssname, ssname);//将实体增加到集合中
	}
	//调用cad命令
	AcDbPoint* pt = new AcDbPoint(AcGePoint3d::kOrigin);
	AcDbObjectId ptId = PhdUtility::PostToModelSpace(pt);

	acedCommand(RTSTR, _T("PEDIT"), RTSTR, _T("M"), RTPICKS, ssname,
		RTSTR, _T(""), RTSTR, _T("Y"), RTSHORT, nPrecision, RTSTR, _T("X"), RTNONE);

	ads_name ssname2;
	ads_name ent2;
	acdbGetAdsName(ent2, ptId);
	while (true)
	{
		ads_name entTemp;
		acdbNameClear(entTemp);
		acdbEntNext(ent2, entTemp);
		if (acdbNameNil(entTemp))
			break;
		acedSSAdd(entTemp, ssname2, ssname2);
		acdbNameSet(entTemp, ent2);
	}

	PhdUtility::DeleteEnt(ptId);

	//将ads_name转id
	long lLen = 0;
	acedSSLength(ssname2, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name entTemp;
		acedSSName(ssname2, index, entTemp);
		AcDbObjectId objId;
		acdbGetObjectId(objId, entTemp);
		arridPline.append(objId);
	}

	if (arridPline.length() > 0)
		return true;
	else
		return false;
}

bool PhdCommand::SplineToPline2(AcDbSpline* pSpline, AcDbObjectId& idPline)
{
	CommandEchoOff();//关闭命令回显

	AcDbEntity* pEntCopy = AcDbEntity::cast(pSpline->clone());
	AcDbObjectId idCopy = PhdUtility::PostToModelSpace(pEntCopy);
	if (idCopy == AcDbObjectId::kNull)
	{
		DEL(pEntCopy);
		return false;
	}
	//将id转为ads_name
	ads_name ssname, ent;
	acdbGetAdsName(ent, idCopy);
	acedSSAdd(ent, ssname, ssname);
	//调用cad命令
	AcDbPoint* pt = new AcDbPoint(AcGePoint3d::kOrigin);
	AcDbObjectId ptId = PhdUtility::PostToModelSpace(pt);

	//调用cad命令
	acedCommand(RTSTR, _T("FLATTEN"), RTPICKS, ssname, RTSTR, _T(""),
		RTSTR, _T("n"), RTNONE);

	ads_name ssname2;
	ads_name ent2;
	acdbGetAdsName(ent2, ptId);
	while (true)
	{
		ads_name entTemp;
		acdbNameClear(entTemp);
		acdbEntNext(ent2, entTemp);
		if (acdbNameNil(entTemp))
			break;
		acedSSAdd(entTemp, ssname2, ssname2);
		acdbNameSet(entTemp, ent2);
	}

	PhdUtility::DeleteEnt(ptId);

	//将ads_name转id
	AcDbObjectIdArray arridPline;
	long lLen = 0;
	acedSSLength(ssname2, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name entTemp;
		acedSSName(ssname2, index, entTemp);
		AcDbObjectId objId;
		acdbGetObjectId(objId, entTemp);
		arridPline.append(objId);
	}

	if (arridPline.length() == 1)
	{
		idPline = arridPline[0];
		return true;
	}
	else
		return false;
}

bool PhdCommand::SplineToPline(AcDbSpline* pSpline, AcDbObjectId& idPline, int nPrecision /*= 10*/)
{
	CommandEchoOff();//关闭命令回显

	AcDbEntity* pEntCopy = AcDbEntity::cast(pSpline->clone());
	AcDbObjectId idCopy = PhdUtility::PostToModelSpace(pEntCopy);
	if (idCopy == AcDbObjectId::kNull)
	{
		DEL(pEntCopy);
		return false;
	}
	//将id转为ads_name
	ads_name ssname, ent;
	acdbGetAdsName(ent, idCopy);
	acedSSAdd(ent, ssname, ssname);
	//调用cad命令
	AcDbPoint* pt = new AcDbPoint(AcGePoint3d::kOrigin);
	AcDbObjectId ptId = PhdUtility::PostToModelSpace(pt);

	acedCommand(RTSTR, _T("PEDIT"), RTSTR, _T("M"), RTPICKS, ssname,
		RTSTR, _T(""), RTSTR, _T("Y"), RTSHORT, nPrecision, RTSTR, _T("X"), RTNONE);

	ads_name ssname2;
	ads_name ent2;
	acdbGetAdsName(ent2, ptId);
	while (true)
	{
		ads_name entTemp;
		acdbNameClear(entTemp);
		acdbEntNext(ent2, entTemp);
		if (acdbNameNil(entTemp))
			break;
		acedSSAdd(entTemp, ssname2, ssname2);
		acdbNameSet(entTemp, ent2);
	}

	PhdUtility::DeleteEnt(ptId);

	//将ads_name转id
	AcDbObjectIdArray arridPline;
	long lLen = 0;
	acedSSLength(ssname2, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name entTemp;
		acedSSName(ssname2, index, entTemp);
		AcDbObjectId objId;
		acdbGetObjectId(objId, entTemp);
		arridPline.append(objId);
	}

	if (arridPline.length() == 1)
	{
		idPline = arridPline[0];
		return true;
	}
	else
		return false;
}

bool PhdCommand::SplineToPline(const AcDbObjectId& idSpline, 
	AcDbObjectId& idPline, int nPrecision /*= 10*/)
{
	CommandEchoOff();//关闭命令回显

	AcDbEntity* pEntCopy = PhdUtility::CopyEnt(idSpline);
	AcDbObjectId idCopy = PhdUtility::PostToModelSpace(pEntCopy);
	if (idCopy == AcDbObjectId::kNull)
	{
		DEL(pEntCopy);
		return false;
	}
	//将id转为ads_name
	ads_name ssname, ent;
	acdbGetAdsName(ent, idCopy);
	acedSSAdd(ent, ssname, ssname);
	//调用cad命令
	AcDbPoint* pt = new AcDbPoint(AcGePoint3d::kOrigin);
	AcDbObjectId ptId = PhdUtility::PostToModelSpace(pt);

	acedCommand(RTSTR, _T("PEDIT"), RTSTR, _T("M"), RTPICKS, ssname,
		RTSTR, _T(""), RTSTR, _T("Y"), RTSHORT, nPrecision, RTSTR, _T("X"), RTNONE);

	ads_name ssname2;
	ads_name ent2;
	acdbGetAdsName(ent2, ptId);
	while (true)
	{
		ads_name entTemp;
		acdbNameClear(entTemp);	
		acdbEntNext(ent2, entTemp);
		if (acdbNameNil(entTemp))		
			break;
		acedSSAdd(entTemp, ssname2, ssname2);
		acdbNameSet(entTemp, ent2);		
	}

	PhdUtility::DeleteEnt(ptId);

	//将ads_name转id
	AcDbObjectIdArray arridPline;
	long lLen = 0;
	acedSSLength(ssname2, &lLen);
	for (long index = 0; index < lLen; index++)
	{
		ads_name entTemp;
		acedSSName(ssname2, index, entTemp);
		AcDbObjectId objId;
		acdbGetObjectId(objId, entTemp);
		arridPline.append(objId);
	}

	if (arridPline.length() == 1)
	{
		idPline = arridPline[0];
		return true;
	}
	else
		return false;
}
