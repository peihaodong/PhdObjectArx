#include "StdAfx.h"
#include "PhdBlock.h"
#include "PhdInline.h"
#include "PhdDatabase.h"


bool PhdBlock::GetIdsOnBlock(LPCTSTR szBlkTblRcdName, AcDbObjectIdArray& arrid, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbBlockTableRecordPointer pBlkTblRcd(szBlkTblRcdName, pDb, AcDb::kForRead);
	if (pBlkTblRcd.openStatus() != Acad::eOk)
		return false;

	AcDbBlockTableRecordIterator* pBTRIter = NULL;
	Acad::ErrorStatus es = pBlkTblRcd->newIterator(pBTRIter);
	if (Acad::eOk != es)
		return false;

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
	return true;
}

AcDbObjectId PhdBlock::GetBlkDefId(LPCTSTR szBlkName, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbBlockTableRecordPointer pBlkTblRec(szBlkName, pDb, AcDb::kForRead);
	return (Acad::eOk == pBlkTblRec.openStatus()) ? pBlkTblRec->objectId() : AcDbObjectId::kNull;
}

AcDbObjectId PhdBlock::GetBlkDefId(const AcDbObjectId& idRef)
{
	AcDbObjectPointer<AcDbBlockReference> pRef(idRef,AcDb::kForRead);
	if (Acad::eOk != pRef.openStatus())
		return AcDbObjectId::kNull;
	AcDbObjectId idDef = pRef->blockTableRecord();
	return idDef;
}

AcArray<CString> PhdBlock::GetBlkNamesOnDb(AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcArray<CString> arrBlkName;
	AcDbBlockTablePointer pBlkTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pBlkTbl.openStatus())
		return arrBlkName;
	AcDbBlockTableIterator* pIt = NULL;
	Acad::ErrorStatus es = pBlkTbl->newIterator(pIt);
	if (Acad::eOk != es)
		return arrBlkName;

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

	return arrBlkName;
}

AcDbObjectIdArray PhdBlock::GetBlkIdsOnDb(AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectIdArray arridBlkDef;
	AcDbBlockTablePointer pBlkTbl(pDb, AcDb::kForRead);
	if (Acad::eOk != pBlkTbl.openStatus())
		return arridBlkDef;
	AcDbBlockTableIterator* pIt = NULL;
	Acad::ErrorStatus es = pBlkTbl->newIterator(pIt);
	if (Acad::eOk != es)
		return arridBlkDef;

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
					arridBlkDef.append(pBTRecord->objectId());
			}
			acutDelString(szName);//���������̬�ַ���;
			pBTRecord->close();
		}
	}
	DEL(pIt);

	return arridBlkDef;
}

bool PhdBlock::CreateBlock(LPCTSTR szDwgPath,LPCTSTR szBlkName, AcDbObjectId& idBlkDef,
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	idBlkDef = GetBlkDefId(szBlkName);
	if (AcDbObjectId::kNull == idBlkDef)
	{
		AcDbDatabase* pDwg = new AcDbDatabase(Adesk::kFalse);
		Acad::ErrorStatus es = pDwg->readDwgFile(szDwgPath);
		es = pDb->insert(idBlkDef, szBlkName, pDwg);
		if (es != Acad::eOk)
		{
			DEL(pDwg);
			return false;
		}
		DEL(pDwg);
		return true;
	}

	return true;
}

bool PhdBlock::CreateBlock(const AcArray<AcDbEntity*>& arrpEnt, 
	const AcGePoint3d& ptBase, LPCTSTR szBlkName, AcDbObjectId& idBlkDef, 
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	idBlkDef = GetBlkDefId(szBlkName,pDb);
	if (AcDbObjectId::kNull == idBlkDef)
	{
		//��������¼
		AcDbBlockTablePointer pBlkTbl(pDb, AcDb::kForWrite);
		if (Acad::eOk != pBlkTbl.openStatus())
			return false;

		AcDbBlockTableRecord* newBlkRec = new AcDbBlockTableRecord();
		Acad::ErrorStatus es = newBlkRec->setName(szBlkName);
		if (es == Acad::eOk)
		{
			es = pBlkTbl->add(idBlkDef, newBlkRec);
		}
		else
		{
			DEL(newBlkRec);
			return false;
		}

		AcDbObjectId idTemp;
		AcGeVector3d vec = AcGePoint3d::kOrigin - ptBase;
		AcGeMatrix3d mat;
		mat.setTranslation(vec);
		for (int i = 0; i < arrpEnt.length(); i++)
		{
			AcDbEntity* pCopy = AcDbEntity::cast(arrpEnt[i]->clone());
			pCopy->transformBy(mat);
			es = newBlkRec->appendZcDbEntity(idTemp, pCopy);
			pCopy->close();		//�ر�ʵ��
		}
		newBlkRec->close();		//�رտ���¼
		return true;
	}

	return true;
}

AcGePoint3d PhdBlock::GetBlkRefPosition(const AcDbObjectId& idRef)
{
	AcDbObjectPointer<AcDbBlockReference> pRef(idRef,AcDb::kForRead);
	if (Acad::eOk != pRef.openStatus())
		return AcGePoint3d::kOrigin;
	return pRef->position();
}

CString PhdBlock::GetBlkName(const AcDbObjectId& idBlk)
{
	CString strBlkName;
	AcDbObjectId idBlkDef;

	AcDbObjectPointer<AcDbBlockReference> pRef(idBlk,AcDb::kForRead);
	if (Acad::eOk == pRef.openStatus())
		idBlkDef = pRef->blockTableRecord();
	else
		idBlkDef = idBlk;
	
	AcDbBlockTableRecordPointer pBlkTblRcd(idBlkDef, AcDb::kForRead);
	if (Acad::eOk != pBlkTblRcd.openStatus())
		return strBlkName;
	TCHAR* szName = NULL;
	pBlkTblRcd->getName(szName);
	strBlkName = szName;

	return strBlkName;
}

bool PhdBlock::CreateBlock(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase, LPCTSTR szBlkName, 
	AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//��������¼
	AcDbBlockTablePointer pBlkTbl(pDb, AcDb::kForWrite);
	if (Acad::eOk != pBlkTbl.openStatus())
		return false;

	AcDbBlockTableRecord* newBlkRec = new AcDbBlockTableRecord();
	Acad::ErrorStatus es = newBlkRec->setName(szBlkName);
	if (es == Acad::eOk)
	{
		es = pBlkTbl->add(idBlkDef, newBlkRec);
	}
	else
	{
		DEL(newBlkRec);
		return false;
	}

	AcDbObjectId idTemp;
	AcGeVector3d vec = AcGePoint3d::kOrigin - ptBase;
	AcGeMatrix3d mat;
	mat.setTranslation(vec);
	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i], AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		pCopy->transformBy(mat);
		es = newBlkRec->appendZcDbEntity(idTemp, pCopy);
		pCopy->close();		//�ر�ʵ��
	}
	newBlkRec->close();		//�رտ���¼
	return true;
}

AcArray<CString> PhdBlock::GetAttTagsOnBlk(const AcDbObjectId& idBlkDef)
{
	AcArray<CString> arrTags;
	AcDbBlockTableRecordPointer pBlkRc(idBlkDef, AcDb::kForRead);
	if (Acad::eOk != pBlkRc.openStatus())
		return arrTags;
	if (!pBlkRc->hasAttributeDefinitions())
		return arrTags;

	AcDbBlockTableRecordIterator* pIter = NULL;
	if (Acad::eOk != pBlkRc->newIterator(pIter))
		return arrTags;
	AcDbObjectId attId;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		if (Acad::eOk != pIter->getEntityId(attId))
			continue;
		AcDbObjectPointer<AcDbAttributeDefinition> pDef(attId, AcDb::kForRead);
		if (Acad::eOk != pDef.openStatus())
			continue;
		arrTags.append(pDef->tagConst());
	}
	DEL(pIter);
	return arrTags;
}

std::map<CString, CString> PhdBlock::GetAttInfoOnBlkRef(const AcDbObjectId& idRef)
{
	std::map<CString, CString> maptag;
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(idRef, AcDb::kForRead);
	if (pBlkRef.openStatus() != Acad::eOk)
		return maptag;

	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return maptag;

	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForRead) != Acad::eOk)
			continue;
		maptag.insert(std::pair<CString, CString>(pAtt->tagConst(), pAtt->textStringConst()));
		pAtt->close();
	}
	DEL(pIter);
	return maptag;
}

CString PhdBlock::GetAttTextOnBlkRef(const AcDbObjectId& idRef, LPCTSTR szAttTag)
{
	CString strTest;
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(idRef, AcDb::kForRead);
	if (pBlkRef.openStatus() != Acad::eOk)
		return strTest;
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return strTest;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForRead) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szAttTag, strTempTag) == 0)
		{
			strTest = pAtt->textStringConst();
			pAtt->close();
			break;
		}
		pAtt->close();
	}
	DEL(pIter);
	return strTest;
}

bool PhdBlock::GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, 
	LPCTSTR szAttTag, CString& strAttValue)
{
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return false;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForRead) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szAttTag, strTempTag) == 0)
		{
			strAttValue = pAtt->textStringConst();
			pAtt->close();
			DEL(pIter);
			return true;
		}
		pAtt->close();
	}
	DEL(pIter);
	return false;
}

CString PhdBlock::GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag)
{
	CString strTest;
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return strTest;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForRead) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szAttTag, strTempTag) == 0)
		{
			strTest = pAtt->textStringConst();
			pAtt->close();
			break;
		}
		pAtt->close();
	}
	DEL(pIter);
	return strTest;
}

bool PhdBlock::SetAttTextOnBlkRef(const AcDbObjectId& idRef, LPCTSTR szTag, LPCTSTR szText)
{
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(idRef, AcDb::kForWrite);
	if (pBlkRef.openStatus() != Acad::eOk)
		return false;
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return false;
	bool bFlag = false;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForWrite) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szTag, strTempTag) == 0)
		{
			pAtt->setTextString(szText);
			pAtt->close();
			bFlag = true;
			break;
		}	
		pAtt->close();
	}
	DEL(pIter);
	return bFlag;
}

bool PhdBlock::SetAttTextOnBlkRef(AcDbBlockReference* pBlkRef,
	LPCTSTR szTag, LPCTSTR szText)
{
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return false;
	bool bFlag = false;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForWrite) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szTag, strTempTag) == 0)
		{
			pAtt->setTextString(szText);
			pAtt->close();
			bFlag = true;
			break;
		}
		pAtt->close();
	}
	DEL(pIter);
	return bFlag;
}

AcDbBlockReference* PhdBlock::CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert)
{
	AcDbBlockReference* pBlkRef = new AcDbBlockReference(ptInsert, idBlkDef);
	//�ж�ָ���Ŀ���Ƿ�������Զ���
	AcDbBlockTableRecordPointer pBlkTblRcd(idBlkDef, AcDb::kForWrite);
	if (Acad::eOk != pBlkTblRcd.openStatus())
		return pBlkRef;
	if (!pBlkTblRcd->hasAttributeDefinitions())
		return pBlkRef;
	//��������¼�����������ڷ��ʿ鶨���е�����ʵ��
	AcDbBlockTableRecordIterator* pIter = NULL;
	Acad::ErrorStatus es = pBlkTblRcd->newIterator(pIter);
	if (Acad::eOk != es)
		return pBlkRef;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != pIter->getEntity(pEnt, AcDb::kForRead))
			continue;
		//��������Զ��壬���������������
		AcDbAttributeDefinition* pAttDef = AcDbAttributeDefinition::cast(pEnt);
		if (pAttDef != NULL)
		{
			//����һ���µ����Զ���
			AcDbAttribute* pAtt = new AcDbAttribute();
			//�����Զ��������Զ���Ķ�������
			pAtt->setPropertiesFrom(pBlkRef);
			pAtt->setLayer(pBlkRef->layerId());
			//�������Զ������������
			pAtt->setInvisible(pAttDef->isInvisible());
			pAtt->setPosition(pAttDef->position());
			pAtt->setHeight(pAttDef->height());
			pAtt->setWidthFactor(pAttDef->widthFactor());
			pAtt->setRotation(pAttDef->rotation());
			pAtt->setHorizontalMode(pAttDef->horizontalMode());
			pAtt->setVerticalMode(pAttDef->verticalMode());
			pAtt->setAlignmentPoint(pAttDef->alignmentPoint());
			pAtt->setTextStyle(pAttDef->textStyle());
			pAtt->setAttributeFromBlock(pBlkRef->blockTransform());
			//������Զ����Tag��Prompt��TextString
			pAtt->setTag(pAttDef->tagConst());
			pAtt->setFieldLength(pAttDef->fieldLength());
			pAtt->setTextString(pAttDef->textStringConst());
			//������ɫ
			pAtt->setColorIndex(pAttDef->colorIndex());
			//������׷�����Զ���
			pBlkRef->appendAttribute(pAtt);
			pAtt->close();
		}
		pEnt->close();
	}
	DEL(pIter);

	return pBlkRef;
}

bool PhdBlock::IsExistAtt(AcDbBlockReference* pBlkRef, LPCTSTR szAttName)
{
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return false;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForRead) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		if (_tcsicmp(szAttName, strTempTag) == 0)
		{
			pAtt->close();
			DEL(pIter);
			return true;
		}
		pAtt->close();
	}
	DEL(pIter);
	return false;
}

bool PhdBlock::CreateAnonyBlk(LPCTSTR szDwgPath, AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbDatabase* pDwg = new AcDbDatabase(Adesk::kFalse);
	Acad::ErrorStatus es = pDwg->readDwgFile(szDwgPath);
	es = pDb->insert(idBlkDef, _T("*U"), pDwg);
	if (es != Acad::eOk)
	{
		DEL(pDwg);
		return false;
	}
	DEL(pDwg);
	return true;
}

AcDbObjectId PhdBlock::GetBlkDefId(LPCTSTR szBlkName, LPCTSTR szDwgPath,
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId idBlkDef = AcDbObjectId::kNull;
	AcDbBlockTableRecordPointer pInsertBlkTblRcd(szBlkName, pDb, AcDb::kForRead);
	if (Acad::eOk == pInsertBlkTblRcd.openStatus())
	{
		idBlkDef = pInsertBlkTblRcd->objectId();
		return idBlkDef;//��ǰ���ݿ���ڸÿ飬���ظÿ鶨��id
	}
	//��ͼֽ
	AcDbDatabase* pDbDwg = PhdDatabase::GetDwgDbPointer(szDwgPath);
	if (!pDbDwg)
		return AcDbObjectId::kNull;
	//��ͼֽ���ݿ�õ��鶨��id
	idBlkDef = GetBlkDefId(szBlkName, pDbDwg);
	if (AcDbObjectId::kNull == idBlkDef)
	{
		DEL(pDbDwg);//�ͷ����ݿ�ָ��
		return idBlkDef;
	}
	//��ͼֽ���ݿ��еĿ鶨�忽����pDb���ݿ���
	if (!PhdDatabase::DbCopyOfBlock(pDbDwg,idBlkDef,pDb, szBlkName, idBlkDef))
	{
		DEL(pDbDwg);//�ͷ����ݿ�ָ��
		return idBlkDef;
	}

	DEL(pDbDwg);//�ͷ����ݿ�ָ��
	return idBlkDef;
}

bool PhdBlock::CreateAnonyBlk(const AcDbObjectIdArray& arrid,const AcGePoint3d& ptBase,
	AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//������������¼
	AcDbBlockTablePointer pBlkTbl(pDb,AcDb::kForWrite);
	if (Acad::eOk != pBlkTbl.openStatus())
		return false;

	AcDbBlockTableRecord* newBlkRec = new AcDbBlockTableRecord;
	newBlkRec->setPathName(_T(""));    // constructor doesn't do it properly

	Acad::ErrorStatus es = newBlkRec->setName(_T("*U"));
	if (es == Acad::eOk)
		es = pBlkTbl->add(idBlkDef, newBlkRec);
	else
	{
		DEL(newBlkRec);
		return false;
	}

	AcDbObjectId idTemp;
	AcGeVector3d vec = AcGePoint3d::kOrigin - ptBase;
	AcGeMatrix3d mat;
	mat.setTranslation(vec);
	for (int i = 0; i < arrid.length(); i++)
	{
		AcDbEntityPointer pEnt(arrid[i], AcDb::kForRead);
		if (Acad::eOk != pEnt.openStatus())
			continue;
		AcDbEntity* pCopy = AcDbEntity::cast(pEnt->clone());
		pCopy->transformBy(mat);
		es = newBlkRec->appendZcDbEntity(idTemp, pCopy);
		pCopy->close();		//�ر�ʵ��
	}
	newBlkRec->close();		//�رտ���¼
	return true;
}

AcDbBlockReference* PhdBlock::CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert, const std::map<CString, CString>& mapAtt)
{
	AcDbBlockReference* pBlkRef = new AcDbBlockReference(ptInsert, idBlkDef);
	//�ж�ָ���Ŀ���Ƿ�������Զ���
	AcDbBlockTableRecordPointer pBlkTblRcd(pBlkRef->blockTableRecord(), AcDb::kForWrite);
	if (Acad::eOk != pBlkTblRcd.openStatus())
		return pBlkRef;
	if (!pBlkTblRcd->hasAttributeDefinitions())
		return pBlkRef;
	//��������¼�����������ڷ��ʿ鶨���е�����ʵ��
	AcDbBlockTableRecordIterator* pIter = NULL;
	pBlkTblRcd->newIterator(pIter);
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != pIter->getEntity(pEnt, AcDb::kForRead))
			continue;
		//��������Զ��壬���������������
		AcDbAttributeDefinition* pAttDef = AcDbAttributeDefinition::cast(pEnt);
		if (pAttDef != NULL)
		{
			//����һ���µ����Զ���
			AcDbAttribute* pAtt = new AcDbAttribute();
			//�����Զ��������Զ���Ķ�������
			pAtt->setPropertiesFrom(pBlkRef);
			pAtt->setLayer(pBlkRef->layerId());
			//�������Զ������������
			pAtt->setInvisible(pAttDef->isInvisible());
			pAtt->setPosition(pAttDef->position());
			pAtt->setHeight(pAttDef->height());
			pAtt->setWidthFactor(pAttDef->widthFactor());
			pAtt->setRotation(pAttDef->rotation());
			pAtt->setHorizontalMode(pAttDef->horizontalMode());
			pAtt->setVerticalMode(pAttDef->verticalMode());
			pAtt->setAlignmentPoint(pAttDef->alignmentPoint());
			pAtt->setTextStyle(pAttDef->textStyle());
			pAtt->setAttributeFromBlock(pBlkRef->blockTransform());
			//������Զ����Tag��Prompt��TextString
			pAtt->setTag(pAttDef->tagConst());
			pAtt->setFieldLength(pAttDef->fieldLength());
			for (std::map<CString, CString>::const_iterator iter = mapAtt.begin(); iter != mapAtt.end(); iter++)
			{
				if (_tcsicmp(pAttDef->tagConst(), iter->first) == 0)
				{
					pAtt->setTextString(iter->second);
					break;
				}
			}
			//������׷�����Զ���
			pBlkRef->appendAttribute(pAtt);
			pAtt->close();
		}
		pEnt->close();
	}
	DEL(pIter);

	return pBlkRef;
}

bool PhdBlock::SetAttTextOnBlkRef(const AcDbObjectId& idRef, const std::map<CString, CString>& mapData)
{
	AcDbObjectPointer<AcDbBlockReference> pBlkRef(idRef, AcDb::kForWrite);
	if (pBlkRef.openStatus() != Acad::eOk)
		return false;
	AcDbObjectIterator* pIter = pBlkRef->attributeIterator();
	if (!pIter)
		return false;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbObjectId attId = pIter->objectId();
		AcDbAttribute* pAtt = NULL;
		if (pBlkRef->openAttribute(pAtt, attId, AcDb::kForWrite) != Acad::eOk)
			continue;
		CString strTempTag = pAtt->tagConst();
		std::map<CString, CString>::const_iterator iter;
		for (iter = mapData.begin(); iter != mapData.end(); ++iter)
		{
			if (_tcsicmp(strTempTag,iter->first) == 0)
				pAtt->setTextString(iter->second);
		}
		pAtt->close();
	}
	DEL(pIter);
	return true;
}

bool PhdBlock::GetIdsOnBlock(const AcDbObjectId& idBlkTblRcd, AcDbObjectIdArray& arrid)
{
	AcDbBlockTableRecordPointer pBlkTblRcd(idBlkTblRcd, AcDb::kForRead);
	Acad::ErrorStatus es = pBlkTblRcd.openStatus();
	if (es != Acad::eOk)
		return false;

	AcDbBlockTableRecordIterator* pBTRIter = NULL;
	 es = pBlkTblRcd->newIterator(pBTRIter);
	if (Acad::eOk != es)
		return false;

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
	return true;
}
