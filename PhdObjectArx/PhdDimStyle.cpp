#include "StdAfx.h"
#include "PhdDimStyle.h"
#include "PhdInline.h"



AcDbObjectId PhdDimStyle::GetDimStyleId(LPCTSTR szDimStyleName,AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbDimStyleTableRecordPointer pDimStlTblRcd(szDimStyleName, pDb, AcDb::kForRead);
	if (Acad::eOk != pDimStlTblRcd.openStatus())
		return AcDbObjectId::kNull;

	return pDimStlTblRcd->objectId();
}

AcDbObjectId PhdDimStyle::CreateDimStyle(AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbDimStyleTable* pnewdimtable = NULL;
	Acad::ErrorStatus es = pDb->getSymbolTable(pnewdimtable, AcDb::kForWrite);
	if (Acad::eOk != es)
		return AcDbObjectId::kNull;
	AcDbDimStyleTableRecord *pnewdimrecord = new AcDbDimStyleTableRecord();
	pnewdimrecord->setDimasz(20);//设置箭头大小
	pnewdimrecord->setDimdec(2); //小数点后两位
	pnewdimrecord->setDimscale(10);	//设置标注全局比例
	pnewdimrecord->setDimzin(8);//十进制小数显示时，抑制后续零
	pnewdimrecord->setDimexe(30);//设置尺寸界线超出尺寸线距离为400
	pnewdimrecord->setDimexo(0);//设置尺寸界线的起点偏移量为300
	pnewdimrecord->setDimtxt(30);//设置文字高度
	pnewdimrecord->setDimtad(1);//设置文字位置-垂直为上方，水平默认为居中，不用设置
	pnewdimrecord->setDimgap(10);//设置文字位置-从尺寸线的偏移量
	pnewdimrecord->setDimtih(0);
	pnewdimrecord->setDimtix(1);//设置标注文字始终绘制在尺寸界线之间
	pnewdimrecord->setDimtofl(1);//即使箭头放置于测量点之外，尺寸线也将绘制在测量点之间
	AcCmColor color;
	color.setColorIndex(1);
	pnewdimrecord->setDimclrd(color);        //尺寸线颜色
	pnewdimrecord->setDimclre(color);        //尺寸边界线颜色
	pnewdimrecord->setDimclrt(color);        //文字颜色

	AcDbObjectId dimrecordid;
	pnewdimtable->add(dimrecordid, pnewdimrecord);
	pnewdimtable->close();
	pnewdimrecord->close();
	return dimrecordid;
}

AcDbObjectIdArray PhdDimStyle::GetDimStyleIdsOnDb(AcDbDatabase* pDb)
{
	AcDbObjectIdArray arrid;
	AcDbDimStyleTablePointer pDimStyTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pDimStyTbl.openStatus())
		return arrid;
	AcDbDimStyleTableIterator* pIt = NULL;
	Acad::ErrorStatus es = pDimStyTbl->newIterator(pIt);
	if (Acad::eOk != es)
		return arrid;

	for (pIt->start(); !pIt->done(); pIt->step())
	{
// 		AcDbDimStyleTableRecord* pTRecord = NULL;
// 		if (pIt->getRecord(pTRecord, AcDb::kForRead) == Acad::eOk)
// 		{
// 			arrid.append(pTRecord->objectId());
// 			pTRecord->close();
// 		}
		AcDbObjectId id;
		pIt->getRecordId(id);
		if (AcDbObjectId::kNull != id)
			arrid.append(id);
	}
	DEL(pIt);

	return arrid;
}
