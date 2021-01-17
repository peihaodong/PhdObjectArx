#pragma once

#include <dbents.h>
#include <acgi.h>
#include <AcString.h>

class ZsdkSign :
	public AcDbEntity
{
public:
	ZsdkSign(void);
	virtual ~ZsdkSign(void);
public:
	ACRX_DECLARE_MEMBERS(ZsdkSign);
	virtual Adesk::Boolean worldDraw(AcGiWorldDraw* wd);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const;
	virtual Acad::ErrorStatus explode(AcDbVoidPtrArray& entitySet) const;
	virtual void list() const;
	virtual Acad::ErrorStatus getGripPoints(AcGePoint3dArray& gripPoints,
		AcDbIntArray& osnapModes,
		AcDbIntArray& geomIds) const;
	virtual Acad::ErrorStatus moveGripPointsAt(const AcDbIntArray& indices,
		const AcGeVector3d& offset);
	virtual Acad::ErrorStatus transformBy(const AcGeMatrix3d& xform);
	virtual Acad::ErrorStatus getClassID(CLSID* pClsid) const;


	virtual AcGeVector3d normal() const;
	virtual void setNormal(const AcGeVector3d v);

	virtual AcGePoint3d center() const;
	virtual void setCenter(const AcGePoint3d c);

	virtual double radius() const;
	virtual void setRadius(const double r);

	virtual AcCmColor textTrueColor() const;
	virtual void setTextTrueColor(const AcCmColor& color);

	virtual AcString text() const;
	virtual void setText(const AcString& t);

	static void initCLSID();
private:
	static bool   s_bHasClsid;
	static CLSID  s_clsid;		      // COM wrapper's CLSID, for OPM exposure

	AcGeVector3d mNormal;
	AcGePoint3d mCenter;
	double mRadius;
	AcCmColor mTextColor;
	AcString mText;
};

