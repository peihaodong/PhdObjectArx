#include "StdAfx.h"
#include "PhdArxLinetype.h"


bool Phd::PhdArxLinetype::SetEntLinetype(const AcDbObjectId& idEnt, LPCTSTR szLinetypeName)
{
	AcDbObjectId idLinetype;
	AcDbLinetypeTableRecordPointer pLtTblRcd(szLinetypeName, acdbCurDwg(), AcDb::kForRead);
	if (Acad::eOk != pLtTblRcd.openStatus())
	{
		// 加载线型
		if (Acad::eOk != acdbLoadLineTypeFile(szLinetypeName, _T("zwcad.lin"), acdbCurDwg()))//zwcad.lin	acad.lin
			if (Acad::eOk != acdbLoadLineTypeFile(szLinetypeName, _T("zwcadiso.lin"), acdbCurDwg()))//zwcadiso.lin		acadiso.lin
				return false;

		pLtTblRcd.open(szLinetypeName, acdbCurDwg(), AcDb::kForRead);
		if (Acad::eOk != pLtTblRcd.openStatus())
			return false;
	}
	idLinetype = pLtTblRcd->objectId();

	AcDbEntityPointer pEnt(idEnt, AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;

	pEnt->setLinetype(idLinetype);//设置线型

	return true;
}

CString Phd::PhdArxLinetype::GetLinetypeName(const AcDbObjectId& idEnt)
{
	AcDbEntityPointer pEnt(idEnt, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return _T("");
	TCHAR* pLinetypeName = pEnt->linetype();

	CString strLinetypeName;
	if (_tcsicmp(pLinetypeName, _T("BYLAYER")) == 0)
	{
		AcDbObjectId layeId = pEnt->layerId();

		AcDbLayerTableRecord* pLayerTblRcd = NULL;
		AcDbObjectId lintyId;
		if (Acad::eOk == acdbOpenObject(pLayerTblRcd, layeId, AcDb::kForRead))
		{
			lintyId = pLayerTblRcd->linetypeObjectId();
			pLayerTblRcd->close();
		}

		AcDbLinetypeTableRecord* pLinetypeTblRcd = NULL;
		if (Acad::eOk == acdbOpenObject(pLinetypeTblRcd, lintyId, AcDb::kForRead))
		{
			TCHAR* pLayerLinetypeName = NULL;
			pLinetypeTblRcd->getName(pLayerLinetypeName);
			strLinetypeName = pLayerLinetypeName;
			pLinetypeTblRcd->close();
			acutDelString(pLayerLinetypeName);
		}
	}
	else
	{
		strLinetypeName = pLinetypeName;
	}
	acutDelString(pLinetypeName);

	return strLinetypeName;
}

AcDbObjectIdArray Phd::PhdArxLinetype::GetLinetypeIdsOnDb(AcDbDatabase* pDb)
{
	AcDbObjectIdArray arrid;
	AcDbLinetypeTablePointer pTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pTbl.openStatus())
		return arrid;
	AcDbLinetypeTableIterator* pIt = NULL;
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
