#include "StdAfx.h"
#include "PhdConver.h"
#include "PhdInline.h"



CString PhdConver::IdToStr(const AcDbObjectId& id)
{
	CString strId = _T("AcDbObjectId::kNull");
	AcDbObject* tmpObj = NULL;

	if (!id.isNull()) 
	{
		Acad::ErrorStatus es = acdbOpenObject(tmpObj, id, AcDb::kForRead);
		if (es == Acad::eOk) 
		{
			CString strClassName = tmpObj->isA()->name();
			AcDbHandle handle;
			tmpObj->getAcDbHandle(handle);
			TCHAR tmpStr[256];
			handle.getIntoAsciiBuffer(tmpStr);
			CString strHandle = tmpStr;

			strId.Format(_T("<%-20s %-4s>"),
				strClassName, strHandle);

			tmpObj->close();
		}
	}

	return strId;
}

CString PhdConver::PtToStr(const AcGePoint3d& pt, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100], zstr[100];

	acdbRToS(pt.x, unit, prec, xstr);
	acdbRToS(pt.y, unit, prec, ystr);
	acdbRToS(pt.z, unit, prec, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

CString PhdConver::VecToStr(const AcGeVector3d& vec, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100], zstr[100];

	acdbRToS(vec.x, unit, prec, xstr);
	acdbRToS(vec.y, unit, prec, ystr);
	acdbRToS(vec.z, unit, prec, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

CString PhdConver::AngleToStr(const double angle, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR tmpStr[100];

	CString str;
	acdbAngToS(angle, unit, prec, tmpStr);
	str = tmpStr;
	return str;
}

CString PhdConver::DoubleToStr(const double realVal, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR tmpStr[100];

	CString str;
	acdbRToS(realVal, unit, prec, tmpStr);
	str = tmpStr;
	return str;
}

CString PhdConver::IntToStr(const int intVal)
{
	CString str;
	str.Format(_T("%d"), intVal);
	return str;
}

CString PhdConver::PtrToStr(void* ptr)
{
	CString str;
	str.Format(_T("%p"), ptr);
	return str;
}

CString PhdConver::DbToStr(AcDbDatabase* pDb)
{
	CString str = _T("NULL");
	if (pDb == NULL) {
		return str;
	}

	const TCHAR* fname;
	Acad::ErrorStatus es = pDb->getFilename(fname);
	if (es == Acad::eOk)
		str.Format(_T("%p  \"%s\""), pDb, fname);
	else {
		// see if we can get name from a document
		AcApDocument* doc = acDocManager->document(pDb);
		if (doc) {
			str.Format(_T("%p  \"%s\""), pDb, doc->fileName());
		}
		else {
			// last resort, just use the pointer value.  eNotApplicable
			// happens frequently on temporary databases, otherwise we
			// would like to know what is going on.
			if (es == Acad::eNotApplicable)
				str.Format(_T("%p"), pDb);
		}
	}

	return str;
}

CString PhdConver::BoolToStr(bool b)
{
	CString str;
	if (b)
		str = _T("True");
	else
		str = _T("False");

	return str;
}

int PhdConver::ToInt(double dValue)
{
	return floor(dValue + 0.5);
}

int PhdConver::ToIntOfTop(double dValue)
{
	return ceil(dValue);
}

int PhdConver::ToIntOfBottom(double dValue)
{
	return floor(dValue);
}

double PhdConver::UpdateOnDotNum(double dValue, unsigned int unDot)
{
	TCHAR str[100];
	acdbRToS(dValue, -1, unDot, str);
	return _wtof(str);
}

double PhdConver::ToRadian(double dAngle)
{
	return(dAngle * (PI / 180.0));
}

double PhdConver::ToAngle(double dRadian)
{
	return(dRadian * (180.0 / PI));
}

bool PhdConver::AdsnameToId(const ads_name objName, AcDbObjectId& id)
{
	Acad::ErrorStatus es = acdbGetObjectId(id, objName);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool PhdConver::IdToAdsname(const AcDbObjectId& id, ads_name& name)
{
	Acad::ErrorStatus es = acdbGetAdsName(name, id);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

AcGePoint2d PhdConver::ToPt2d(const AcGePoint3d& pt)
{
	return AcGePoint2d(pt.x, pt.y);
}

AcGePoint3d PhdConver::ToPt3d(const AcGePoint2d& pt, double z /*= 0*/)
{
	return AcGePoint3d(pt.x, pt.y, z);
}

AcGePoint3d PhdConver::UcsToWcsPt(const AcGePoint3d &point)
{
	// 转换成世界坐标 ;
	AcGePoint3d pt;
	struct resbuf rbFrom, rbTo;
	rbFrom.restype = RTSHORT;
	rbFrom.resval.rint = 1; // from UCS;
	rbTo.restype = RTSHORT;
	rbTo.resval.rint = 0; // to WCS;

	acedTrans(asDblArray(point), &rbFrom, &rbTo, Adesk::kFalse, asDblArray(pt));

	return pt;
}

AcGePoint2d PhdConver::UcsToDcsPt(const AcGePoint3d& pt)
{
	resbuf fromRb, toRb;
	ads_point newPt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = AcDb::kUserCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = AcDb::kCurDisplayCS;

	short result = acedTrans(asDblArray(pt), &fromRb, &toRb, FALSE, newPt);
	ASSERT(result == RTNORM);

	return asPnt2d(newPt);
}

AcGePoint3d PhdConver::WcsToUcsPt(const AcGePoint3d &point)
{
	// 转换成用户坐标	;
	AcGePoint3d pt;
	struct resbuf rbFrom, rbTo;
	rbFrom.restype = RTSHORT;
	rbFrom.resval.rint = 0; // from WCS;
	rbTo.restype = RTSHORT;
	rbTo.resval.rint = 1; // to UCS;

	acedTrans(asDblArray(point), &rbFrom, &rbTo, Adesk::kFalse, asDblArray(pt));

	return pt;
}

AcGePoint3d PhdConver::WcsToDcsPt(const AcGePoint3d &point)
{
	// 转换成显示坐标	
	AcGePoint3d pt;
	struct resbuf rbFrom, rbTo;
	rbFrom.restype = RTSHORT;
	rbFrom.resval.rint = 0; // from WCS
	rbTo.restype = RTSHORT;
	rbTo.resval.rint = 2; // to DCS

	acedTrans(asDblArray(point), &rbFrom, &rbTo, Adesk::kFalse, asDblArray(pt));

	return pt;
}

int PhdConver::ToASCII(TCHAR s)
{
	int n = s;
	return n;
}

TCHAR PhdConver::ToChar(int n)
{
	TCHAR s = n;
	return s;
}

CString PhdConver::VecToStr(const AcGeVector2d& vec, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100];

	acdbRToS(vec.x, unit, prec, xstr);
	acdbRToS(vec.y, unit, prec, ystr);

	CString str;
	str.Format(_T("(%s, %s)"), xstr, ystr);
	return str;
}

CString PhdConver::PtToStr(const AcGePoint2d& pt, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100];

	acdbRToS(pt.x, unit, prec, xstr);
	acdbRToS(pt.y, unit, prec, ystr);

	CString str;
	str.Format(_T("(%s, %s)"), xstr, ystr);
	return str;
}

