#include "StdAfx.h"
#include "CPhdPersistReactor.h"
#include "PhdInline.h"


ACRX_DXF_DEFINE_MEMBERS(CPhdPersistReactor, AcDbObject,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	0, CPhdPersistReactor, ZwCad);

CPhdPersistReactor::CPhdPersistReactor()
{
}


CPhdPersistReactor::~CPhdPersistReactor()
{
}

Acad::ErrorStatus CPhdPersistReactor::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();
	AcDbObject::dwgInFields(pFiler);

	pFiler->readSoftPointerId((AcDbSoftPointerId*)&m_idChanger);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CPhdPersistReactor::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();
	AcDbObject::dwgOutFields(pFiler);

	pFiler->writeSoftPointerId((AcDbSoftPointerId&)m_idChanger);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CPhdPersistReactor::dxfInFields(AcDbDxfFiler* pFiler)
{
	return Acad::eNotImplementedYet;
}

Acad::ErrorStatus CPhdPersistReactor::dxfOutFields(AcDbDxfFiler* pFiler) const
{
	return Acad::eNotImplementedYet;
}

void CPhdPersistReactor::modified(const AcDbObject* dbObj)
{

}

void CPhdPersistReactor::erased(const AcDbObject* dbObj, Adesk::Boolean pErasing /*= true*/)
{
	AcDbEntity* pObserver = AcDbEntity::cast(dbObj);
	if (pObserver != NULL && pErasing)
	{
		AcDbObjectPointer<AcDbEntity> pChanger(m_idChanger, AcDb::kForWrite);
		if (pChanger.openStatus() != Acad::eOk)
			return;
		pChanger->erase();
	}
}

void CPhdPersistReactor::SetChangerId(const AcDbObjectId& id)
{
	assertWriteEnabled();
	m_idChanger = id;
}

bool CPhdPersistReactor::AttachReactor(const AcDbObjectId& idObserve, const AcDbObjectId& idChanger)
{
	AcDbDictionary* pNamedDict = NULL;//有名对象字典指针
	CPhdPersistReactor* pRct = new CPhdPersistReactor();
	pRct->SetChangerId(idChanger);
	acdbCurDwg()->getNamedObjectsDictionary(pNamedDict, AcDb::kForWrite);

	AcDbDictionary* pReactorDict = new AcDbDictionary;//反应器字典
	AcDbObjectId DictId;//新字典Id
	auto es = pNamedDict->setAt(_T("*U"), pReactorDict, DictId);
	pNamedDict->close();

	AcDbObjectId idReactor;
	es = pReactorDict->setAt(_T("*U"), pRct, idReactor);
	pRct->close();
	pReactorDict->close();
	if (Acad::eOk != es)
	{
		DEL(pRct);
		return false;
	}
	AcDbObjectPointer<AcDbEntity> pObserve(idObserve, AcDb::kForWrite);
	if (pObserve.openStatus() != Acad::eOk)
		return false;
	pObserve->addPersistentReactor(idReactor);
	return true;
}

void CPhdPersistReactor::AddReactor()
{
	CPhdPersistReactor::rxInit();
	acrxBuildClassHierarchy();
}

void CPhdPersistReactor::RemoveReactor()
{
	deleteAcRxClass(CPhdPersistReactor::desc());
}
