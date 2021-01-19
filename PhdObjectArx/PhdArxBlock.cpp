#include "StdAfx.h"
#include "PhdArxBlock.h"


Phd::PhdArxBlock::PhdArxBlock()
	:m_apPhdArxDatabase(std::make_shared<Phd::PhdArxDatabase>())
{

}

bool Phd::PhdArxBlock::GetIdsOnBlock(LPCTSTR szBlkTblRcdName, AcDbObjectIdArray& arrid, AcDbDatabase* pDb /*= acdbCurDwg()*/)
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

AcDbObjectId Phd::PhdArxBlock::GetBlkDefId(LPCTSTR szBlkName, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbBlockTableRecordPointer pBlkTblRec(szBlkName, pDb, AcDb::kForRead);
	return (Acad::eOk == pBlkTblRec.openStatus()) ? pBlkTblRec->objectId() : AcDbObjectId::kNull;
}

AcDbObjectId Phd::PhdArxBlock::GetBlkDefId(const AcDbObjectId& idRef)
{
	AcDbObjectPointer<AcDbBlockReference> pRef(idRef,AcDb::kForRead);
	if (Acad::eOk != pRef.openStatus())
		return AcDbObjectId::kNull;
	AcDbObjectId idDef = pRef->blockTableRecord();
	return idDef;
}

AcArray<CString> Phd::PhdArxBlock::GetBlkNamesOnDb(AcDbDatabase* pDb /*= acdbCurDwg()*/)
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
			if (_tcslen(szName) > 0)//过滤掉名称为空的块表;
			{
				if (BlockName.Find(_T("Model_Space")) == -1 && BlockName.Find(_T("Paper_Space")) == -1)
					arrBlkName.append(BlockName);
			}
			acutDelString(szName);//必须清除动态字符串;
			pBTRecord->close();
		}
	}
	DEL(pIt);

	return arrBlkName;
}

AcDbObjectIdArray Phd::PhdArxBlock::GetBlkIdsOnDb(AcDbDatabase* pDb /*= acdbCurDwg()*/)
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
			if (_tcslen(szName) > 0)//过滤掉名称为空的块表;
			{
				if (BlockName.Find(_T("Model_Space")) == -1 && BlockName.Find(_T("Paper_Space")) == -1)
					arridBlkDef.append(pBTRecord->objectId());
			}
			acutDelString(szName);//必须清除动态字符串;
			pBTRecord->close();
		}
	}
	DEL(pIt);

	return arridBlkDef;
}

bool Phd::PhdArxBlock::CreateBlock(LPCTSTR szDwgPath,LPCTSTR szBlkName, AcDbObjectId& idBlkDef,
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

bool Phd::PhdArxBlock::CreateBlock(const AcArray<AcDbEntity*>& arrpEnt, 
	const AcGePoint3d& ptBase, LPCTSTR szBlkName, AcDbObjectId& idBlkDef, 
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	idBlkDef = GetBlkDefId(szBlkName,pDb);
	if (AcDbObjectId::kNull == idBlkDef)
	{
		//创建块表记录
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
			pCopy->close();		//关闭实体
		}
		newBlkRec->close();		//关闭块表记录
		return true;
	}

	return true;
}

AcGePoint3d Phd::PhdArxBlock::GetBlkRefPosition(const AcDbObjectId& idRef)
{
	AcDbObjectPointer<AcDbBlockReference> pRef(idRef,AcDb::kForRead);
	if (Acad::eOk != pRef.openStatus())
		return AcGePoint3d::kOrigin;
	return pRef->position();
}

CString Phd::PhdArxBlock::GetBlkName(const AcDbObjectId& idBlk)
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

bool Phd::PhdArxBlock::CreateBlock(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase, LPCTSTR szBlkName, 
	AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//创建块表记录
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
		pCopy->close();		//关闭实体
	}
	newBlkRec->close();		//关闭块表记录
	return true;
}

AcArray<CString> Phd::PhdArxBlock::GetAttTagsOnBlk(const AcDbObjectId& idBlkDef)
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

std::map<CString, CString> Phd::PhdArxBlock::GetAttInfoOnBlkRef(const AcDbObjectId& idRef)
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

CString Phd::PhdArxBlock::GetAttTextOnBlkRef(const AcDbObjectId& idRef, LPCTSTR szAttTag)
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

bool Phd::PhdArxBlock::GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, 
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

CString Phd::PhdArxBlock::GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag)
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

bool Phd::PhdArxBlock::SetAttTextOnBlkRef(const AcDbObjectId& idRef, LPCTSTR szTag, LPCTSTR szText)
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

bool Phd::PhdArxBlock::SetAttTextOnBlkRef(AcDbBlockReference* pBlkRef,
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

AcDbBlockReference* Phd::PhdArxBlock::CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert)
{
	AcDbBlockReference* pBlkRef = new AcDbBlockReference(ptInsert, idBlkDef);
	//判断指定的块表是否包含属性定义
	AcDbBlockTableRecordPointer pBlkTblRcd(idBlkDef, AcDb::kForWrite);
	if (Acad::eOk != pBlkTblRcd.openStatus())
		return pBlkRef;
	if (!pBlkTblRcd->hasAttributeDefinitions())
		return pBlkRef;
	//创建块表记录遍历器，用于访问块定义中的所有实体
	AcDbBlockTableRecordIterator* pIter = NULL;
	Acad::ErrorStatus es = pBlkTblRcd->newIterator(pIter);
	if (Acad::eOk != es)
		return pBlkRef;
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != pIter->getEntity(pEnt, AcDb::kForRead))
			continue;
		//如果是属性定义，就向块参照添加属性
		AcDbAttributeDefinition* pAttDef = AcDbAttributeDefinition::cast(pEnt);
		if (pAttDef != NULL)
		{
			//创建一个新的属性对象
			AcDbAttribute* pAtt = new AcDbAttribute();
			//从属性定义获得属性对象的对象特征
			pAtt->setPropertiesFrom(pBlkRef);
			pAtt->setLayer(pBlkRef->layerId());
			//设置属性对象的其它特性
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
			//获得属性对象的Tag、Prompt和TextString
			pAtt->setTag(pAttDef->tagConst());
			pAtt->setFieldLength(pAttDef->fieldLength());
			pAtt->setTextString(pAttDef->textStringConst());
			//设置颜色
			pAtt->setColorIndex(pAttDef->colorIndex());
			//向块参照追加属性对象
			pBlkRef->appendAttribute(pAtt);
			pAtt->close();
		}
		pEnt->close();
	}
	DEL(pIter);

	return pBlkRef;
}

bool Phd::PhdArxBlock::IsExistAtt(AcDbBlockReference* pBlkRef, LPCTSTR szAttName)
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

bool Phd::PhdArxBlock::CreateAnonyBlk(LPCTSTR szDwgPath, AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
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

AcDbObjectId Phd::PhdArxBlock::GetBlkDefId(LPCTSTR szBlkName, LPCTSTR szDwgPath,
	AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	AcDbObjectId idBlkDef = AcDbObjectId::kNull;
	AcDbBlockTableRecordPointer pInsertBlkTblRcd(szBlkName, pDb, AcDb::kForRead);
	if (Acad::eOk == pInsertBlkTblRcd.openStatus())
	{
		idBlkDef = pInsertBlkTblRcd->objectId();
		return idBlkDef;//当前数据库存在该块，返回该块定义id
	}
	//打开图纸
	AcDbDatabase* pDbDwg = m_apPhdArxDatabase->GetDwgDbPointer(szDwgPath);
	if (!pDbDwg)
		return AcDbObjectId::kNull;
	//从图纸数据库得到块定义id
	idBlkDef = GetBlkDefId(szBlkName, pDbDwg);
	if (AcDbObjectId::kNull == idBlkDef)
	{
		DEL(pDbDwg);//释放数据库指针
		return idBlkDef;
	}
	//将图纸数据库中的块定义拷贝到pDb数据库中
	if (!m_apPhdArxDatabase->DbCopyOfBlock(pDbDwg,idBlkDef,pDb, szBlkName, idBlkDef))
	{
		DEL(pDbDwg);//释放数据库指针
		return idBlkDef;
	}

	DEL(pDbDwg);//释放数据库指针
	return idBlkDef;
}

bool Phd::PhdArxBlock::CreateAnonyBlk(const AcDbObjectIdArray& arrid,const AcGePoint3d& ptBase,
	AcDbObjectId& idBlkDef, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	//创建匿名块表记录
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
		pCopy->close();		//关闭实体
	}
	newBlkRec->close();		//关闭块表记录
	return true;
}

AcDbBlockReference* Phd::PhdArxBlock::CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert, const std::map<CString, CString>& mapAtt)
{
	AcDbBlockReference* pBlkRef = new AcDbBlockReference(ptInsert, idBlkDef);
	//判断指定的块表是否包含属性定义
	AcDbBlockTableRecordPointer pBlkTblRcd(pBlkRef->blockTableRecord(), AcDb::kForWrite);
	if (Acad::eOk != pBlkTblRcd.openStatus())
		return pBlkRef;
	if (!pBlkTblRcd->hasAttributeDefinitions())
		return pBlkRef;
	//创建块表记录遍历器，用于访问块定义中的所有实体
	AcDbBlockTableRecordIterator* pIter = NULL;
	pBlkTblRcd->newIterator(pIter);
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != pIter->getEntity(pEnt, AcDb::kForRead))
			continue;
		//如果是属性定义，就向块参照添加属性
		AcDbAttributeDefinition* pAttDef = AcDbAttributeDefinition::cast(pEnt);
		if (pAttDef != NULL)
		{
			//创建一个新的属性对象
			AcDbAttribute* pAtt = new AcDbAttribute();
			//从属性定义获得属性对象的对象特征
			pAtt->setPropertiesFrom(pBlkRef);
			pAtt->setLayer(pBlkRef->layerId());
			//设置属性对象的其它特性
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
			//获得属性对象的Tag、Prompt和TextString
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
			//向块参照追加属性对象
			pBlkRef->appendAttribute(pAtt);
			pAtt->close();
		}
		pEnt->close();
	}
	DEL(pIter);

	return pBlkRef;
}

bool Phd::PhdArxBlock::SetAttTextOnBlkRef(const AcDbObjectId& idRef, const std::map<CString, CString>& mapData)
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

bool Phd::PhdArxBlock::GetIdsOnBlock(const AcDbObjectId& idBlkTblRcd, AcDbObjectIdArray& arrid)
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
