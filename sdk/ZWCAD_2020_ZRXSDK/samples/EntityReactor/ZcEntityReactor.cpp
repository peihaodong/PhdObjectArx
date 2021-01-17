
#include "StdAfx.h"
#include "adscodes.h"
#include "ZcEntityReactor.h"


ZcEntityReactor::ZcEntityReactor()
{
	m_objIdList.removeAll();
}

ZcEntityReactor::~ZcEntityReactor()
{
	delAllReactor();
}

bool ZcEntityReactor::addReactorToObject(AcDbObject* dbObj)
{
	if (dbObj == NULL)
	{
		return false;
	}

	ASSERT(dbObj->isWriteEnabled() == Adesk::kTrue);

	if (m_objIdList.contains(dbObj->objectId()))
	{
		return false;
	}
	else
	{
		dbObj->addReactor(this);
		m_objIdList.append(dbObj->objectId());
		return true;
	}
}

bool ZcEntityReactor::delReactorFromObject(AcDbObject* dbObj)
{
	if (dbObj == NULL)
	{
		return false;
	}

	int nIndex = -1;
	if (m_objIdList.find(dbObj->objectId(), nIndex))
	{
		dbObj->removeReactor(this);
		m_objIdList.removeAt(nIndex);
		return true;
	}

	return false;
}

bool ZcEntityReactor::delAllReactor()
{
	Acad::ErrorStatus es;
	AcDbObject* pObj = NULL;
	int nLength = m_objIdList.length();
	for (int i = 0; i < nLength; i++)
	{
		es = acdbOpenObject(pObj, m_objIdList[i], AcDb::kForWrite, true);
		if (es == Acad::eOk)
		{
			pObj->removeReactor(this);
			pObj->close();
		}
		else
		{
			return false;
		}
	}

	m_objIdList.removeAll();
	return true;
}

void ZcEntityReactor::openedForModify(const AcDbObject* dbObj)
{
	if (!dbObj->isKindOf(AcDbEntity::desc()))
	{
		acutPrintf(_T("\nObject is not a valid Entity!"));
		return;
	}

	AcDbEntity* pEnt = AcDbEntity::cast(dbObj);
	CString strLayer;
	strLayer.Format(_T("\nCurrent Entity:%s .The layerName:%s ."), pEnt->isA()->name(), pEnt->layer());
	acutPrintf(strLayer);
}

void ZcEntityReactor::modified(const AcDbObject* dbObj)
{
	if (!dbObj->isKindOf(AcDbEntity::desc()))
	{
		acutPrintf(_T("\nObject is not a valid Entity!"));
		return;
	}

	AcDbEntity* pEnt = AcDbEntity::cast(dbObj);
	CString strLayer;
	strLayer.Format(_T("\nEntity:%s has been modified.The layerName:%s.\n"), pEnt->isA()->name(), pEnt->layer());
	acutPrintf(strLayer);
}

void ZcEntityReactor::erased(const AcDbObject* dbObj, Adesk::Boolean pErasing /* = true */)
{
	if (pErasing)
	{
		acutPrintf(_T("\nEntity:%s has been erased."), dbObj->isA()->name());
	}
	else
	{
		acutPrintf(_T("\nEntity:%s has been (Un)erased."), dbObj->isA()->name());
	}
}

void ZcEntityReactor::copied(const AcDbObject* dbObj, const AcDbObject* newObj)
{
	acutPrintf(_T("\nOriginal Entity:"));
	printObjInfo(dbObj);

	acutPrintf(_T("\nCopied Entity:"));
	printObjInfo(newObj);
}

void ZcEntityReactor::modifiedXData(const AcDbObject* dbObj)
{
	acutPrintf(_T("\nThe XData of Entity:%s has been modified."), dbObj->isA()->name());
}

void ZcEntityReactor::printObjInfo(const AcDbObject* pObj)
{
	if (pObj == NULL)
	{
		acutPrintf(_T("\nObject is NULL!"));
		return;
	}

	AcDbHandle objHand;
	ACHAR handBuff[17];
	pObj->getAcDbHandle(objHand);
	objHand.getIntoAsciiBuffer(handBuff);

	acutPrintf(_T("\n(className==%s, handle==%s, id==%lx, database==%lx)"), pObj->isA()->name(), handBuff, pObj->objectId().asOldId(), pObj->database());
}

AcDbObject* ZcEntityReactor::selectObject(AcDb::OpenMode openMode)
{
	int nRet = 0;
	ads_name en;
	ads_point pt;

	nRet = acedEntSel(_T("\nSelect an entity:"), en, pt);
	if (nRet != RTNORM)
	{
		return NULL;
	}

	AcDbObjectId eId;
	Acad::ErrorStatus retStat;
	retStat = acdbGetObjectId(eId, en);
	if (retStat != Acad::eOk)
	{
		acutPrintf(_T("\nacdbGetObjectId failed!"));
		return NULL;
	}

	AcDbObject* obj = NULL;
	if ((retStat = acdbOpenObject(obj, eId, openMode)) != Acad::eOk)
	{
		acutPrintf(_T("\nOpen Failed!"));
		return NULL;
	}

	return obj;
}
