#include "StdAfx.h"
#include "PhdArxGroup.h"

AcDbObjectId Phd::PhdArxGroup::CreateGroup(LPCTSTR szGourpName, AcDbDatabase* pDb /*= acdbCurDwg()*/, bool bSelectable /*= true*/)
{
	AcDbObjectId IdGroup;
	if (HasGroup(szGourpName, IdGroup, pDb))
	{
		return IdGroup;
	}

	AcDbDictionary* pDict;
	if (Acad::eOk != pDb->getGroupDictionary(pDict, AcDb::kForRead))
	{
		return IdGroup;
	}

	AcDbObjectPointer<AcDbDictionary> Dict;
	Dict.acquire(pDict);

	AcDbObjectPointer<AcDbGroup> pGroup;
	pGroup.create();
	CString strName(szGourpName);
	if (strName.GetLength() == 0)
	{
		strName = _T("*");
	}

	pGroup->setSelectable(bSelectable);
	Dict->upgradeOpen();
	Dict->setAt(strName, pGroup.object(), IdGroup);
	Dict->downgradeOpen();
	return IdGroup;
}

bool Phd::PhdArxGroup::CreateGroup(const AcDbObjectIdArray& ents, LPCTSTR szGroupName, AcDbObjectId& IdGroup, bool bSelectable /*= true*/)
{
	IdGroup = CreateGroup(szGroupName, acdbCurDwg(), bSelectable);
	AcDbObjectPointer<AcDbGroup> pGroup(IdGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
	{
		return false;
	}

	return Acad::eOk == pGroup->append(ents);
}

AcDbObjectId Phd::PhdArxGroup::CreateAnonGroup(AcDbDatabase *pDb /*= acdbCurDwg()*/, bool bSelectable /*= true*/)
{
	AcDbGroup *pGroup = new AcDbGroup();
	AcDbDictionary *pGroupDict = NULL;
	pDb->getGroupDictionary(pGroupDict, AcDb::kForWrite);
	AcDbObjectId pGroupId;
	Acad::ErrorStatus es = pGroupDict->setAt(_T("*U"), pGroup, pGroupId);//如果组名为*，则会创建匿名组
	pGroupDict->close();
	pGroup->setSelectable(bSelectable);//设置组的可选性
	pGroup->close();

	return pGroupId;
}

bool Phd::PhdArxGroup::HasGroup(LPCTSTR szGroupName, AcDbObjectId& IdGroup, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	if (NULL == szGroupName)
		return false;

	AcDbObjectPointer<AcDbDictionary> GDic;
	AcDbDictionary  * pGroupDict = NULL;
	if (pDb->getGroupDictionary(pGroupDict, AcDb::kForWrite) != Acad::eOk)
		return FALSE;

	GDic.acquire(pGroupDict);
	//查询是否有同名组存在
	return (GDic->getAt(szGroupName, IdGroup) == Acad::eOk);
}

bool Phd::PhdArxGroup::AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectId& idEnt)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;

	pGroup->append(idEnt);
	return true;
}

AcDbObjectId Phd::PhdArxGroup::GetGroupId(const AcDbObjectId& ent)
{
	AcDbEntityPointer pEnt(ent, AcDb::kForRead);
	Acad::ErrorStatus es = pEnt.openStatus();
	if (Acad::eOk != es)
	{
		return AcDbObjectId::kNull;
	}

	const AcDbVoidPtrArray* pReactors = pEnt->reactors();
	if (NULL == pReactors || 0 == pReactors->length())
		return AcDbObjectId::kNull;

	for (int index = 0; index < pReactors->length(); index++)
	{
		if (!acdbIsPersistentReactor(pReactors->at(index)))
			continue;

		AcDbObjectId IdReactor = acdbPersistentReactorObjectId(pReactors->at(index));
		if (!IdReactor.isValid())
			continue;

		AcDbObjectPointer<AcDbObject> pObj(IdReactor, AcDb::kForRead);
		es = pObj.openStatus();
		if (Acad::eOk == es && pObj->isKindOf(AcDbGroup::desc()))
		{
			return IdReactor;
		}
	}

	return AcDbObjectId::kNull;
}

bool Phd::PhdArxGroup::GetGroupEnts(AcDbObjectIdArray& IdArray, const AcDbObjectId& IdGroup)
{
	AcDbObjectPointer<AcDbGroup> pGroup(IdGroup, AcDb::kForRead);
	if (Acad::eOk != pGroup.openStatus())
	{
		return false;
	}

	pGroup->allEntityIds(IdArray);
	return true;
}

bool Phd::PhdArxGroup::ResetGroup(const AcDbObjectIdArray& ents, const AcDbObjectId& IdGroup)
{
	AcDbObjectPointer<AcDbGroup> pGroup(IdGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
	{
		return false;
	}

	pGroup->clear();
	pGroup->append(ents);
	return true;
}

AcDbObjectIdArray Phd::PhdArxGroup::GetGroupIdsOnDb(AcDbDatabase* pDb)
{
	AcDbObjectIdArray arrid;
	AcDbDictionary *pGroupDict = NULL;
	pDb->getGroupDictionary(pGroupDict, AcDb::kForRead);
	AcDbDictionaryIterator* pIt = pGroupDict->newIterator();
	if (!pIt)
		return arrid;
	for (; !pIt->done(); pIt->next())
	{
		arrid.append(pIt->objectId());
	}
	DEL(pIt);
	return arrid;
}

bool Phd::PhdArxGroup::GroupRemoveEnt(const AcDbObjectId& idGroup, 
	const AcDbObjectId& idDelEnt)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup,AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;
	Acad::ErrorStatus es = pGroup->remove(idDelEnt);
	if (es != Acad::eOk)
		return false;
	else
		return true;
}

bool Phd::PhdArxGroup::DeleteGroup(const AcDbObjectId& idGroup)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;
	Acad::ErrorStatus es = pGroup->erase();
	if (es != Acad::eOk)
		return false;
	else
		return true;
}

bool Phd::PhdArxGroup::AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectIdArray& arridEnt)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;

	for (int i = 0; i < arridEnt.length(); i++)
		pGroup->append(arridEnt[i]);
	
	return true;
}
