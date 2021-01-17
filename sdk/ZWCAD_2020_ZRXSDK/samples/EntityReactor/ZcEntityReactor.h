
#pragma once
#include "dbmain.h"

class ZcEntityReactor : public AcDbEntityReactor
{
public:
	ZcEntityReactor();
	~ZcEntityReactor();

public:
	bool addReactorToObject(AcDbObject* dbObj);
	bool delReactorFromObject(AcDbObject* dbObj);
	bool delAllReactor();

public:
	virtual void openedForModify(const AcDbObject* dbObj);
	virtual void modified(const AcDbObject* dbObj);
	virtual void erased(const AcDbObject* dbObj, Adesk::Boolean pErasing /* = true */);
	virtual void copied(const AcDbObject* dbObj, const AcDbObject* newObj);
	virtual void modifiedXData(const AcDbObject* dbObj);

public:
	static void printObjInfo(const AcDbObject* pObj);
	static AcDbObject* selectObject(AcDb::OpenMode openMode);

private:
	AcDbObjectIdArray m_objIdList;

};
