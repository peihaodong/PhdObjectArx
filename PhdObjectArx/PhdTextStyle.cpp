#include "StdAfx.h"
#include "PhdTextStyle.h"
#include "PhdInline.h"



AcArray<CString> PhdTextStyle::GetAllTextStyleName(AcDbDatabase *pDb /*= acdbCurDwg()*/)
{
	AcArray<CString> arrTSName;
	AcDbTextStyleTable* pTextStyleTbl = NULL;
	pDb->getSymbolTable(pTextStyleTbl, AcDb::kForRead);
	AcDbTextStyleTableIterator* pIt = NULL;
	pTextStyleTbl->newIterator(pIt);
	for (pIt->start(); !pIt->done(); pIt->step())
	{
		AcDbTextStyleTableRecord* pRcd = NULL;
		if (pIt->getRecord(pRcd, AcDb::kForRead) == Acad::eOk)
		{
			TCHAR* szName = NULL;
			pRcd->getName(szName);
			if (_tcslen(szName) > 0)//过滤掉名称为空的文字样式;
				arrTSName.append(szName);

			acutDelString(szName);
			pRcd->close();
		}
	}
	DEL(pIt);
	pTextStyleTbl->close();

	return arrTSName;
}

AcDbObjectId PhdTextStyle::GetTextStyleId(LPCTSTR szName, AcDbDatabase *pDb /*= acdbCurDwg()*/)
{
	AcDbTextStyleTableRecordPointer pTextStyleTblRcd(szName,pDb,AcDb::kForRead);
	if (Acad::eOk != pTextStyleTblRcd.openStatus())
		return AcDbObjectId::kNull;
	return pTextStyleTblRcd->objectId();
}

AcDbObjectId PhdTextStyle::GetTextStyleIdOfMText(const AcDbObjectId& idMText)
{
	AcDbObjectPointer<AcDbMText> pMText(idMText,AcDb::kForRead);
	if (Acad::eOk != pMText.openStatus())
		return AcDbObjectId::kNull;
	AcDbObjectId idTextStyle = pMText->textStyle();
	return idTextStyle;
}

double PhdTextStyle::GetWidthScale(const AcDbObjectId& idTextStyle)
{
	AcDbTextStyleTableRecordPointer pTextStyleTblRcd(idTextStyle, AcDb::kForRead);
	if (Acad::eOk != pTextStyleTblRcd.openStatus())
		return 1;
	double dScale = pTextStyleTblRcd->xScale();
	return dScale;
}

AcDbObjectIdArray PhdTextStyle::GetTextStyleIdsOnDb(AcDbDatabase* pDb)
{
	AcDbObjectIdArray arrid;
	AcDbTextStyleTablePointer pTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pTbl.openStatus())
		return arrid;
	AcDbTextStyleTableIterator* pIt = NULL;
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
