#include "StdAfx.h"
#include "LinePersistentReactor.h"

ACRX_DXF_DEFINE_MEMBERS(LinePersistentReactor, AcDbObject, 
						AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
						0, LINEPERSISTENTREACTOR, PersistentReactor);

LinePersistentReactor::LinePersistentReactor()
{
}

LinePersistentReactor::LinePersistentReactor(AcDbObjectId objId)
{
	m_objId = objId;
}

LinePersistentReactor::~LinePersistentReactor(void)
{
}


Acad::ErrorStatus LinePersistentReactor::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();

	AcDbObject::dwgInFields(pFiler);

	pFiler->readItem((AcDbSoftPointerId*)&m_objId);

	return pFiler->filerStatus();
}

Acad::ErrorStatus LinePersistentReactor::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();

	AcDbObject::dwgOutFields(pFiler);

	pFiler->writeItem((AcDbSoftPointerId&)m_objId);

	return pFiler->filerStatus();
}

void LinePersistentReactor::modified(const ZcDbObject* dbObj)
{
	assertReadEnabled();

	if (dbObj->isKindOf(AcDbLine::desc()))
	{
		AcDbLine* pLine = AcDbLine::cast(dbObj);
		if (!pLine)
			return;

		AcGePoint3d spt = pLine->startPoint();
		AcGePoint3d ept = pLine->endPoint();

		AcDbCircle* pCircle = NULL;
		acdbOpenAcDbEntity((AcDbEntity*&)pCircle, m_objId, ZcDb::kForWrite);
		if (!pCircle)
			return;

		double radius = pCircle->radius();
		AcGePoint3d cen = spt + (spt - ept).normalize() * radius;

		pCircle->setCenter(cen);

		pCircle->close();
	}
	else if (dbObj->isKindOf(AcDbCircle::desc()))
	{
		AcDbCircle* pCircle = AcDbCircle::cast(dbObj);
		if (!pCircle)
			return;
		
		AcDbLine* pLine = NULL;
		acdbOpenAcDbEntity((AcDbEntity*&)pLine, m_objId, ZcDb::kForWrite);
		if (!pLine)
			return;

		AcGePoint3d spt = pLine->startPoint();
		AcGePoint3d ept = pLine->endPoint();
		double radius = pCircle->radius();
		AcGePoint3d cen = pCircle->center();

		spt = cen - (cen - ept).normalize() * radius;

		pLine->setStartPoint(spt);

		pLine->close();
	}
}
