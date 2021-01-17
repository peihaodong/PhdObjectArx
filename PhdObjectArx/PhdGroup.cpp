#include "StdAfx.h"
#include "PhdGroup.h"
#include "PhdInline.h"



AcDbObjectId PhdGroup::CreateGroup(LPCTSTR szGourpName, AcDbDatabase* pDb /*= acdbCurDwg()*/, bool bSelectable /*= true*/)
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

bool PhdGroup::CreateGroup(const AcDbObjectIdArray& ents, LPCTSTR szGroupName, AcDbObjectId& IdGroup, bool bSelectable /*= true*/)
{
	IdGroup = CreateGroup(szGroupName, acdbCurDwg(), bSelectable);
	AcDbObjectPointer<AcDbGroup> pGroup(IdGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
	{
		return false;
	}

	return Acad::eOk == pGroup->append(ents);
}

AcDbObjectId PhdGroup::CreateAnonGroup(AcDbDatabase *pDb /*= acdbCurDwg()*/, bool bSelectable /*= true*/)
{
	AcDbGroup *pGroup = new AcDbGroup();
	AcDbDictionary *pGroupDict = NULL;
	pDb->getGroupDictionary(pGroupDict, AcDb::kForWrite);
	AcDbObjectId pGroupId;
	Acad::ErrorStatus es = pGroupDict->setAt(_T("*U"), pGroup, pGroupId);//�������Ϊ*����ᴴ��������
	pGroupDict->close();
	pGroup->setSelectable(bSelectable);//������Ŀ�ѡ��
	pGroup->close();

	return pGroupId;
}

bool PhdGroup::HasGroup(LPCTSTR szGroupName, AcDbObjectId& IdGroup, AcDbDatabase* pDb /*= acdbCurDwg()*/)
{
	if (NULL == szGroupName)
		return false;

	AcDbObjectPointer<AcDbDictionary> GDic;
	AcDbDictionary  * pGroupDict = NULL;
	if (pDb->getGroupDictionary(pGroupDict, AcDb::kForWrite) != Acad::eOk)
		return FALSE;

	GDic.acquire(pGroupDict);
	//��ѯ�Ƿ���ͬ�������
	return (GDic->getAt(szGroupName, IdGroup) == Acad::eOk);
}

bool PhdGroup::AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectId& idEnt)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;

	pGroup->append(idEnt);
	return true;
}

AcDbObjectId PhdGroup::GetGroupId(const AcDbObjectId& ent)
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

bool PhdGroup::GetGroupEnts(AcDbObjectIdArray& IdArray, const AcDbObjectId& IdGroup)
{
	AcDbObjectPointer<AcDbGroup> pGroup(IdGroup, AcDb::kForRead);
	if (Acad::eOk != pGroup.openStatus())
	{
		return false;
	}

	pGroup->allEntityIds(IdArray);
	return true;
}

bool PhdGroup::ResetGroup(const AcDbObjectIdArray& ents, const AcDbObjectId& IdGroup)
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

AcDbObjectIdArray PhdGroup::GetGroupIdsOnDb(AcDbDatabase* pDb)
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

bool PhdGroup::GroupRemoveEnt(const AcDbObjectId& idGroup, 
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

bool PhdGroup::DeleteGroup(const AcDbObjectId& idGroup)
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

bool PhdGroup::AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectIdArray& arridEnt)
{
	AcDbObjectPointer<AcDbGroup> pGroup(idGroup, AcDb::kForWrite);
	if (Acad::eOk != pGroup.openStatus())
		return false;

	for (int i = 0; i < arridEnt.length(); i++)
		pGroup->append(arridEnt[i]);
	
	return true;
}
