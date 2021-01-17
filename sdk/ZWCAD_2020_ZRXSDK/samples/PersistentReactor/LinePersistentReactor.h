#pragma once

class LinePersistentReactor : public AcDbObject
{
public:
	ACRX_DECLARE_MEMBERS(LinePersistentReactor);
	LinePersistentReactor();
	LinePersistentReactor(AcDbObjectId objId);
	virtual ~LinePersistentReactor(void);

public:
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;

	virtual void modified(const ZcDbObject* dbObj);

private:
	AcDbObjectId m_objId;
};
