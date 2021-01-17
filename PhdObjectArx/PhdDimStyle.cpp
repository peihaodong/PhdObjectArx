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
	pnewdimrecord->setDimasz(20);//���ü�ͷ��С
	pnewdimrecord->setDimdec(2); //С�������λ
	pnewdimrecord->setDimscale(10);	//���ñ�עȫ�ֱ���
	pnewdimrecord->setDimzin(8);//ʮ����С����ʾʱ�����ƺ�����
	pnewdimrecord->setDimexe(30);//���óߴ���߳����ߴ��߾���Ϊ400
	pnewdimrecord->setDimexo(0);//���óߴ���ߵ����ƫ����Ϊ300
	pnewdimrecord->setDimtxt(30);//�������ָ߶�
	pnewdimrecord->setDimtad(1);//��������λ��-��ֱΪ�Ϸ���ˮƽĬ��Ϊ���У���������
	pnewdimrecord->setDimgap(10);//��������λ��-�ӳߴ��ߵ�ƫ����
	pnewdimrecord->setDimtih(0);
	pnewdimrecord->setDimtix(1);//���ñ�ע����ʼ�ջ����ڳߴ����֮��
	pnewdimrecord->setDimtofl(1);//��ʹ��ͷ�����ڲ�����֮�⣬�ߴ���Ҳ�������ڲ�����֮��
	AcCmColor color;
	color.setColorIndex(1);
	pnewdimrecord->setDimclrd(color);        //�ߴ�����ɫ
	pnewdimrecord->setDimclre(color);        //�ߴ�߽�����ɫ
	pnewdimrecord->setDimclrt(color);        //������ɫ

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
