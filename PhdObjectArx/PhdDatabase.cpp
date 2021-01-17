#include "StdAfx.h"
#include "PhdDatabase.h"
#include "PhdInline.h"
#include "PhdUtility.h"

#pragma region �ڲ�����
bool PhdDatabase::GetObjectIdArrayFromAcDbIdMapping(const AcDbIdMapping& adim,
	const AcDbObjectIdArray& adoiaInput,
	AcDbObjectIdArray& adoiaPair)
{
	AcDbIdPair   adip;
	int          i, iLength;
	AcDbObjectId adoi;
	bool         b;

	adoiaPair.removeAll();

	// If no id needs to be found
	if (adoiaInput.isEmpty())
		return false;

	// For each input id find the pair
	iLength = adoiaInput.length();
	for (i = 0; i < iLength; i++)
	{
		adoi = adoiaInput.at(i);
		adip.setKey(adoi);
		b = adim.compute(adip);
		adoi = adip.value();
		adoiaPair.append(adoi);
	}
	return true;
}


#pragma endregion

bool PhdDatabase::InsertDwg(LPCTSTR szDwgPath, const AcGePoint3d& ptInsert, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbDatabase* pTempDb = new AcDbDatabase(false);
	Acad::ErrorStatus es = pTempDb->readDwgFile(szDwgPath, _SH_DENYNO);
	if (Acad::eOk != es)
		return false;

	AcGeMatrix3d XForm;
	AcGePoint3d fromPt = AcGePoint3d::kOrigin;
	XForm.setToTranslation(ptInsert - fromPt);

	es = pDb->insert(XForm, pTempDb);//�������ݿ�;
	if (Acad::eOk != es)
	{
		DEL(pTempDb);
		return false;
	}
	DEL(pTempDb);
	return true;
}

bool PhdDatabase::InsertBlkDef(LPCTSTR szDwgPath, LPCTSTR szBlkName, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbBlockTableRecordPointer pInsertBlkTblRcd(szBlkName,pDb,AcDb::kForRead);
	if (Acad::eOk == pInsertBlkTblRcd.openStatus())
		return false;	//���ݿ����иÿ鶨��
	
	AcDbDatabase* pTempDb = new AcDbDatabase(false);
	Acad::ErrorStatus es = pTempDb->readDwgFile(szDwgPath, _SH_DENYNO);
	AcDbBlockTable* pBlkTbl = NULL;
	es = pTempDb->getBlockTable(pBlkTbl, AcDb::kForRead);//�򿪿��
	if (Acad::eOk != es)
	{
		DEL(pTempDb);
		return false;
	}
		
	AcDbBlockTableRecord* pBlkTblRcd = NULL;
	es = pBlkTbl->getAt(szBlkName, pBlkTblRcd, AcDb::kForRead);//��ָ���Ŀ���¼
	if (Acad::eOk != es)
	{
		pBlkTbl->close();
		DEL(pTempDb);
		return false;	//ͼֽ��û�иÿ鶨��
	}
	pBlkTbl->close();	//�رտ��
	AcDbObjectId idBlkDef = pBlkTblRcd->objectId();
	pBlkTblRcd->close();//�رտ���¼

	AcDbObjectId idTbl = pDb->blockTableId();
	AcDbObjectIdArray idarrClone;
	AcDbIdMapping idMap;
	idarrClone.append(idBlkDef);
	//��pTempDb���ݿ��е�idarrCloneʵ���¡��idTbl��
	es = pTempDb->wblockCloneObjects(idarrClone, idTbl, idMap, AcDb::kDrcIgnore);
	if (Acad::eOk != es)
	{
		DEL(pTempDb);
		return false;
	}

	DEL(pTempDb);
	return true;
}

AcArray<CString> PhdDatabase::GetBlkDefNames(const CString& strDwgPath)
{
	AcArray<CString> arrBlkName;
	AcDbDatabase* pTempDb = new AcDbDatabase(false);
	Acad::ErrorStatus es = pTempDb->readDwgFile(strDwgPath, _SH_DENYNO);
	if (Acad::eOk != es)
		return arrBlkName;

	AcDbBlockTable* pBlkTbl = NULL;
	es = pTempDb->getBlockTable(pBlkTbl, AcDb::kForRead);//�򿪿��
	if (Acad::eOk != es)
		return arrBlkName;
	AcDbBlockTableIterator* pIt = NULL;
	pBlkTbl->newIterator(pIt);
	pBlkTbl->close();

	for (pIt->start(); !pIt->done(); pIt->step())
	{
		AcDbBlockTableRecord* pBTRecord = NULL;
		if (pIt->getRecord(pBTRecord, AcDb::kForRead) == Acad::eOk)
		{
			TCHAR* szName = NULL;
			pBTRecord->getName(szName);
			CString BlockName = szName;
			if (_tcslen(szName) > 0)//���˵�����Ϊ�յĿ��;
			{
				if (BlockName.Find(_T("Model_Space")) == -1 && BlockName.Find(_T("Paper_Space")) == -1)
					arrBlkName.append(BlockName);
			}
			acutDelString(szName);//���������̬�ַ���;
			pBTRecord->close();
		}
	}
	DEL(pIt);
	DEL(pTempDb);

	return arrBlkName;
}

AcDbExtents PhdDatabase::GetDbExtent(AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbExtents extent;

	AcDbBlockTableRecordPointer pBlkTblRcd(ACDB_MODEL_SPACE, pDb, AcDb::kForRead);
	if (pBlkTblRcd.openStatus() != Acad::eOk)
		return extent;

	AcDbBlockTableRecordIterator* pBTRIter = NULL;
	Acad::ErrorStatus es = pBlkTblRcd->newIterator(pBTRIter);
	if (Acad::eOk != es)
		return extent;

	for (pBTRIter->start(); !pBTRIter->done(); pBTRIter->step())
	{
		AcDbEntity* pTempEnt = NULL;
		es = pBTRIter->getEntity(pTempEnt, AcDb::kForRead);
		if (Acad::eOk != es)
			continue;
		AcDbExtents es;
		pTempEnt->getGeomExtents(es);
		extent.addExt(es);
		pTempEnt->close();
	}
	DEL(pBTRIter);
	return extent;
}

AcDbObjectIdArray PhdDatabase::GetDbEntId(AcDbDatabase* pDb /*= acdbCurDwg()*/)
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
		arrid.append(pTempEnt->objectId());
		pTempEnt->close();
	}
	DEL(pBTRIter);
	return arrid;
}

bool PhdDatabase::DbSaveToDwg(AcDbDatabase* pDb, LPCTSTR szDwgPath,
	bool bBak /*= false*/)
{
	/*
	CadR14	= AcDb::kDHL_1014,
	Cad2000	= AcDb::kDHL_1015,
	Cad2004 = AcDb::kDHL_1800,
	Cad2007 = AcDb::kDHL_1021,
	Cad2010 = AcDb::kDHL_1024,
	Cad2013 = AcDb::kDHL_1027,
	Cad2018 = AcDb::kDHL_1032,
	AcDb::kDHL_CURRENT = AcDb::kDHL_1032
	*/
	//����
	AcDb::AcDbDwgVersion ver = pDb->originalFileVersion();
	pDb->closeInput(true);//��ͼֽ�����ݿ�Ĺ����ϵ�
	auto es = pDb->saveAs(szDwgPath, bBak, ver);
	return Acad::eOk == es;
}

bool PhdDatabase::DbSaveToDxf(AcDbDatabase* pDb, LPCTSTR szDxfPath,
	const AcDb::AcDbDwgVersion dwgVer)
{
	Acad::ErrorStatus es = pDb->dxfOut(szDxfPath, 16, dwgVer);
	return Acad::eOk == es;
}

bool PhdDatabase::DbSaveToDwgOrDxf(AcDbDatabase* pDb, LPCTSTR szPath)
{
	CString strPath = szPath;
	int nFindIndex = strPath.ReverseFind(_T('.'));
	if (nFindIndex == -1)
		return false;
	CString strSuffix = strPath.Right(strPath.GetLength() - nFindIndex);
	if (_tcscmp(strSuffix, _T(".dwg")) == 0)
	{
		return DbSaveToDwg(pDb, strPath);
	}
	else if (_tcscmp(strSuffix, _T(".dxf")) == 0)
	{
		return DbSaveToDxf(pDb, strPath);
	}
	else
		return false;
}

bool PhdDatabase::DbSaveToDxf(AcDbDatabase* pDb, LPCTSTR szDxfPath)
{
	AcDb::AcDbDwgVersion ver = pDb->originalFileVersion();
	pDb->closeInput(true);//��ͼֽ�����ݿ�Ĺ����ϵ�
	Acad::ErrorStatus es = pDb->dxfOut(szDxfPath, 16, ver);
	return Acad::eOk == es;
}

bool PhdDatabase::DbSaveToDwg(AcDbDatabase* pDb, LPCTSTR szDwgPath,
	const AcDb::AcDbDwgVersion dwgVer, bool bBak /*= false*/)
{
	/*
	CadR14	= AcDb::kDHL_1014,
	Cad2000	= AcDb::kDHL_1015,
	Cad2004 = AcDb::kDHL_1800,
	Cad2007 = AcDb::kDHL_1021,
	Cad2010 = AcDb::kDHL_1024,
	Cad2013 = AcDb::kDHL_1027,
	Cad2018 = AcDb::kDHL_1032,
	AcDb::kDHL_CURRENT = AcDb::kDHL_1032
	*/
	//����
	AcDb::AcDbDwgVersion ver = pDb->originalFileVersion();
	pDb->closeInput(true);//��ͼֽ�����ݿ�Ĺ����ϵ�
	auto es = pDb->saveAs(szDwgPath, bBak, dwgVer);
	return Acad::eOk == es;
}

void PhdDatabase::SwitchCurDatabase(AcDbDatabase* pDb)
{
	acdbHostApplicationServices()->setWorkingDatabase(pDb);
}

AcDbDatabase* PhdDatabase::GetDwgDbPointer(LPCTSTR szDwgPath)
{
	AcDbDatabase* pDbDwg = new AcDbDatabase(false);
	Acad::ErrorStatus es = pDbDwg->readDwgFile(szDwgPath, _SH_DENYNO);
	if (Acad::eOk != es)
	{
		DEL(pDbDwg);
		return NULL;
	}
	else
		return pDbDwg;
}

AcDbDatabase* PhdDatabase::GetDxfDbPointer(LPCTSTR szDxfPath)
{
	AcDbDatabase* pDbDxf = new AcDbDatabase(false);
	Acad::ErrorStatus es = pDbDxf->dxfIn(szDxfPath);
	if (Acad::eOk != es)
	{
		DEL(pDbDxf);
		return NULL;
	}
	else
		return pDbDxf;
}

AcDbDatabase* PhdDatabase::GetDwgOrDxfDbPointer(LPCTSTR szPath)
{
	CString strPath = szPath;
	int nFindIndex = strPath.ReverseFind(_T('.'));
	if (nFindIndex == -1)
		return NULL;
	CString strSuffix = strPath.Right(strPath.GetLength() - nFindIndex);
	if (_tcscmp(strSuffix, _T(".dwg")) == 0)
	{
		return GetDwgDbPointer(strPath);
	}
	else if (_tcscmp(strSuffix, _T(".dxf")) == 0)
	{
		return GetDxfDbPointer(strPath);
	}
	else
		return NULL;
}

bool PhdDatabase::DbCopyOfBlock(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou, 
	const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, LPCTSTR szBlkNameTar, 
	AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, arridSou, ptBaseSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget��
	es = pDbTarget->insert(idBlkDefTar, szBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;
	
	return true;
}

bool PhdDatabase::DbCopyOfBlock(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
	LPCTSTR szBlkNameTar, AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget��
	es = pDbTarget->insert(idBlkDefTar, szBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
	const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, const AcGePoint3d& ptBaseTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, arridSou, ptBaseSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ�ʵ�忽����pDbTarget��
	AcGeMatrix3d XForm;
//	AcGePoint3d fromPt = AcGePoint3d::kOrigin;
	XForm.setToTranslation(ptBaseTar - ptBaseSou);
	es = pDbTarget->insert(XForm, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
	const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
	LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, arridSou, ptBaseSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget�У�����pDbTarget���ݿ�szCpBlkNameTar�鶨����
	//��ʵ�忽����szNewBlkNameTar�鶨����
	es = pDbTarget->insert(idBlkDefTar, szCpBlkNameTar, szNewBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::CopyAmongDbOfBlkTbl(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou, const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, const AcGePoint3d& ptBaseTar, AcDbObjectIdArray& arridTar)
{
	AcDbIdMapping idMap;
	AcDbObjectId idCurSpace = pDbTarget->currentSpaceId();//���ݿ⵱ǰģ�Ϳռ��id
	AcDbObjectIdArray clones;
	clones.append(arridSou);
	//��pDbSource���ݿ��е�clonesʵ���¡��idCurSpace��
	Acad::ErrorStatus es = pDbSource->wblockCloneObjects(clones, idCurSpace, idMap,
		AcDb::kDrcIgnore);//д���¡ �����ض���ģʽ
	if (Acad::eOk != es)
		return false;

	//�õ��������ʵ��
	if (!GetObjectIdArrayFromAcDbIdMapping(idMap, clones, arridTar))
		return false;

	//�ƶ�ʵ��λ��
	AcGeVector3d vec = ptBaseTar - ptBaseSou;
	AcGeMatrix3d mat;
	mat.setTranslation(vec);
	for (int i = 0; i < arridTar.length(); i++)
	{
		AcDbEntity* pEntTemp = NULL;
		if (Acad::eOk != acdbOpenAcDbEntity(pEntTemp, arridTar[i], AcDb::kForWrite))
			continue;
		pEntTemp->transformBy(mat);
		pEntTemp->close();
	}
	return true;
}

bool PhdDatabase::CopyWithinDbOfBlkTbl(AcDbDatabase* pDb, const AcDbObjectIdArray& arrid,
	const AcGePoint3d& ptBase, const AcDbObjectId& idBlkDef, const AcGePoint3d& ptBaseCopied, 
	AcDbObjectIdArray& arridCopied)
{
	AcDbIdMapping idMap;
	AcDbObjectIdArray clones;
	clones.append(arrid);
	AcDbObjectId idBlkDefCopied = idBlkDef;
	//��pDbSource���ݿ��е�clonesʵ���¡��idCurSpace��
	Acad::ErrorStatus es = pDb->deepCloneObjects(clones, idBlkDefCopied, idMap,
		AcDb::kDrcIgnore);//д���¡ �����ض���ģʽ
	if (Acad::eOk != es)
		return false;

	//�õ��������ʵ��
	if (!GetObjectIdArrayFromAcDbIdMapping(idMap, clones, arridCopied))
		return false;

	//�ƶ�ʵ��λ��
	AcGeVector3d vec = ptBaseCopied - ptBase;
	AcGeMatrix3d mat;
	mat.setTranslation(vec);
	for (int i = 0; i < arridCopied.length(); i++)
	{
		AcDbEntity* pEntTemp = NULL;
		if (Acad::eOk != acdbOpenAcDbEntity(pEntTemp, arridCopied[i], AcDb::kForWrite))
			continue;
		pEntTemp->transformBy(mat);
		pEntTemp->close();
	}
	return true;
}

bool PhdDatabase::DbCopyOfBlkDef(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar, LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget�У�����pDbTarget���ݿ�szCpBlkNameTar�鶨����
	//��ʵ�忽����szNewBlkNameTar�鶨����
	es = pDbTarget->insert(idBlkDefTar, szCpBlkNameTar, szNewBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou, AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar, LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, idBlkDefSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget�У�����pDbTarget���ݿ�szCpBlkNameTar�鶨����
	//��ʵ�忽����szNewBlkNameTar�鶨����
	es = pDbTarget->insert(idBlkDefTar, szCpBlkNameTar, szNewBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfEnts(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
	const AcGePoint3d& ptBaseTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ�ʵ�忽����pDbTarget��
	AcGeMatrix3d XForm;
	AcGePoint3d fromPt = AcGePoint3d::kOrigin;
	XForm.setToTranslation(ptBaseTar - fromPt);
	es = pDbTarget->insert(XForm, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
	AcDbDatabase* pDbTarget, const AcGePoint3d& ptBaseTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, idBlkDefSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ�ʵ�忽����pDbTarget��
	AcGeMatrix3d XForm;
	AcGePoint3d fromPt = AcGePoint3d::kOrigin;
	XForm.setToTranslation(ptBaseTar - fromPt);
	es = pDbTarget->insert(XForm, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}

bool PhdDatabase::DbCopyOfBlock(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou, 
	AcDbDatabase* pDbTarget, LPCTSTR szBlkNameTar, AcDbObjectId& idBlkDefTar)
{
	//��ָ����ʵ�������һ����ʱͼ�����ݿ�
	AcDbDatabase* pDbTemp = NULL;	//ע�⣺����ǧ������new
	Acad::ErrorStatus es = pDbSource->wblock(pDbTemp, idBlkDefSou);
	if (Acad::eOk != es)
		return false;
	//�Ѹ���ʱͼ�����ݿ���Ϊ�鶨�忽����pDbTarget��
	es = pDbTarget->insert(idBlkDefTar, szBlkNameTar, pDbTemp);
	DEL(pDbTemp);
	if (Acad::eOk != es)
		return false;

	return true;
}



