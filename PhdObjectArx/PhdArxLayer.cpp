#include "StdAfx.h"
#include "PhdArxLayer.h"


AcDbObjectId Phd::PhdArxLayer::GetLayerId(const CString& strLayerName, bool bCreate /*= true*/, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(strLayerName, pDb, AcDb::kForRead);
	if (pLayerTblRcd.openStatus() != Acad::eOk)
	{
		if (bCreate)
		{//创建图层
			AcDbLayerTablePointer pLayerTable(pDb, AcDb::kForWrite);
			if (Acad::eOk != pLayerTable.openStatus())
				return AcDbObjectId::kNull;
			AcDbLayerTableRecord* pRc = new AcDbLayerTableRecord();
			pRc->setName(strLayerName);
			if (Acad::eOk != pLayerTable->add(pRc))
			{
				DEL(pRc);
				return AcDbObjectId::kNull;
			}
			else
			{
				pRc->close();
				return pRc->objectId();
			}
		}
		else
			return AcDbObjectId::kNull;
	}
	return pLayerTblRcd->objectId();
}

bool Phd::PhdArxLayer::IsExist(LPCTSTR szLayerName, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(szLayerName, pDb, AcDb::kForRead);
	if (pLayerTblRcd.openStatus() != Acad::eOk)
		return false;
	else
		return true;
}

bool Phd::PhdArxLayer::SetEntLayer(const AcDbObjectId& idEnt, const AcDbObjectId& idLayer)
{
	if (!idLayer)
		return false;
	AcDbEntityPointer pEnt(idEnt, AcDb::kForWrite);
	if (pEnt.openStatus() != Acad::eOk)
		return false;
	if (idLayer)
		pEnt->setLayer(idLayer);
	return true;
}

bool Phd::PhdArxLayer::SetLayerOff(const AcDbObjectId& idLayer, bool bOff /*= true*/)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(idLayer,AcDb::kForWrite);
	if (Acad::eOk != pLayerTblRcd.openStatus())
		return false;
	if (bOff)
	{
		if (!pLayerTblRcd->isOff())
			pLayerTblRcd->setIsOff(bOff);
	}
	else
	{
		if (pLayerTblRcd->isOff())
			pLayerTblRcd->setIsOff(bOff);
	}
	
	return true;
}

CString Phd::PhdArxLayer::GetLayerName(const AcDbObjectId& idLayer)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(idLayer,AcDb::kForRead);
	if (Acad::eOk != pLayerTblRcd.openStatus())
		return _T("");
	TCHAR* szName = NULL;
	pLayerTblRcd->getName(szName);
	CString strName = szName;
	return strName;
}

AcDbObjectIdArray Phd::PhdArxLayer::GetEntIdsOfLayer(LPCTSTR szLayerName, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectIdArray arrid;
	AcDbBlockTableRecordPointer pBlkTblRcd(ACDB_MODEL_SPACE, pDb, AcDb::kForRead);
	if (pBlkTblRcd.openStatus() != Acad::eOk)
		return arrid;

	AcDbBlockTableRecordIterator* pBTRIter = NULL;
	Acad::ErrorStatus es = pBlkTblRcd->newIterator(pBTRIter);
	if (Acad::eOk != es)
		return arrid;

	for (pBTRIter->start(); !pBTRIter->done(); pBTRIter->step())
	{
		AcDbEntity* pTempEnt = NULL;
		es = pBTRIter->getEntity(pTempEnt, AcDb::kForRead);
		if (Acad::eOk != es)
			continue;
		TCHAR* pLayerName = NULL;
		pLayerName = pTempEnt->layer();
		if (_tcscmp(pLayerName,szLayerName) == 0)
			arrid.append(pTempEnt->objectId());
		acutDelString(pLayerName);
		pTempEnt->close();
	}
	DEL(pBTRIter);
	return arrid;
}

bool Phd::PhdArxLayer::SetColorIndex(const AcDbObjectId& idLayer,int nColorIndex)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(idLayer, AcDb::kForWrite);
	if (Acad::eOk != pLayerTblRcd.openStatus())
		return false;
	AcCmColor color;//设置图层颜色
	color.setColorIndex(nColorIndex);
	pLayerTblRcd->setColor(color);
	return true;
}

int Phd::PhdArxLayer::GetLayerColorIndex(const AcDbObjectId& idLayer)
{
	AcDbLayerTableRecordPointer pLayerTblRcd(idLayer, AcDb::kForWrite);
	if (Acad::eOk != pLayerTblRcd.openStatus())
		return 0;
	auto color = pLayerTblRcd->color();
	int nIndex = color.colorIndex();
	return nIndex;
}

AcDbObjectIdArray Phd::PhdArxLayer::GetLayerIdsOnDb(AcDbDatabase* pDb)
{
	AcDbObjectIdArray arrid;
	AcDbLayerTablePointer pTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pTbl.openStatus())
		return arrid;
	AcDbLayerTableIterator* pIt = NULL;
	Acad::ErrorStatus es = pTbl->newIterator(pIt);
	if (Acad::eOk != es)
		return arrid;

	for (pIt->start(); !pIt->done(); pIt->step())
	{
		AcDbObjectId id;
		pIt->getRecordId(id);
		if (AcDbObjectId::kNull != id)
			arrid.append(id);
	}
	DEL(pIt);

	return arrid;
}

bool Phd::PhdArxLayer::SetEntLayer(const AcDbObjectIdArray& arridEnt, const AcDbObjectId& idLayer)
{
	if (!idLayer)
		return false;
	for (int i = 0; i < arridEnt.length(); i++)
	{
		AcDbEntityPointer pEnt(arridEnt[i], AcDb::kForWrite);
		if (pEnt.openStatus() != Acad::eOk)
			continue;
		pEnt->setLayer(idLayer);
	}
	
	return true;
}
