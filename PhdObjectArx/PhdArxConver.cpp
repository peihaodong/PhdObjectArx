#include "StdAfx.h"
#include "PhdArxConver.h"

CString Phd::PhdArxConver::IdToStr(const AcDbObjectId& id)
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

CString Phd::PhdArxConver::PtToStr(const AcGePoint3d& pt, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100], zstr[100];

	acdbRToS(pt.x, unit, prec, xstr);
	acdbRToS(pt.y, unit, prec, ystr);
	acdbRToS(pt.z, unit, prec, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

CString Phd::PhdArxConver::VecToStr(const AcGeVector3d& vec, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100], zstr[100];

	acdbRToS(vec.x, unit, prec, xstr);
	acdbRToS(vec.y, unit, prec, ystr);
	acdbRToS(vec.z, unit, prec, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

CString Phd::PhdArxConver::AngleToStr(const double angle, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR tmpStr[100];

	CString str;
	acdbAngToS(angle, unit, prec, tmpStr);
	str = tmpStr;
	return str;
}

CString Phd::PhdArxConver::DoubleToStr(const double realVal, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR tmpStr[100];

	CString str;
	acdbRToS(realVal, unit, prec, tmpStr);
	str = tmpStr;
	return str;
}

CString Phd::PhdArxConver::IntToStr(const int intVal)
{
	CString str;
	str.Format(_T("%d"), intVal);
	return str;
}

CString Phd::PhdArxConver::PtrToStr(void* ptr)
{
	CString str;
	str.Format(_T("%p"), ptr);
	return str;
}

CString Phd::PhdArxConver::DbToStr(AcDbDatabase* pDb)
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

CString Phd::PhdArxConver::BoolToStr(bool b)
{
	CString str;
	if (b)
		str = _T("True");
	else
		str = _T("False");

	return str;
}

int Phd::PhdArxConver::ToInt(double dValue)
{
	return floor(dValue + 0.5);
}

int Phd::PhdArxConver::ToIntOfTop(double dValue)
{
	return ceil(dValue);
}

int Phd::PhdArxConver::ToIntOfBottom(double dValue)
{
	return floor(dValue);
}

double Phd::PhdArxConver::UpdateOnDotNum(double dValue, unsigned int unDot)
{
	TCHAR str[100];
	acdbRToS(dValue, -1, unDot, str);
	return _wtof(str);
}

double Phd::PhdArxConver::ToRadian(double dAngle)
{
	return(dAngle * (PI / 180.0));
}

double Phd::PhdArxConver::ToAngle(double dRadian)
{
	return(dRadian * (180.0 / PI));
}

bool Phd::PhdArxConver::AdsnameToId(const ads_name objName, AcDbObjectId& id)
{
	Acad::ErrorStatus es = acdbGetObjectId(id, objName);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxConver::IdToAdsname(const AcDbObjectId& id, ads_name& name)
{
	Acad::ErrorStatus es = acdbGetAdsName(name, id);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

AcGePoint2d Phd::PhdArxConver::ToPt2d(const AcGePoint3d& pt)
{
	return AcGePoint2d(pt.x, pt.y);
}

AcGePoint3d Phd::PhdArxConver::ToPt3d(const AcGePoint2d& pt, double z /*= 0*/)
{
	return AcGePoint3d(pt.x, pt.y, z);
}

AcGePoint3d Phd::PhdArxConver::UcsToWcsPt(const AcGePoint3d &point)
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

AcGePoint2d Phd::PhdArxConver::UcsToDcsPt(const AcGePoint3d& pt)
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

AcGePoint3d Phd::PhdArxConver::WcsToUcsPt(const AcGePoint3d &point)
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

AcGePoint3d Phd::PhdArxConver::WcsToDcsPt(const AcGePoint3d &point)
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

int Phd::PhdArxConver::ToASCII(TCHAR s)
{
	int n = s;
	return n;
}

TCHAR Phd::PhdArxConver::ToChar(int n)
{
	TCHAR s = n;
	return s;
}

CString Phd::PhdArxConver::VecToStr(const AcGeVector2d& vec, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100];

	acdbRToS(vec.x, unit, prec, xstr);
	acdbRToS(vec.y, unit, prec, ystr);

	CString str;
	str.Format(_T("(%s, %s)"), xstr, ystr);
	return str;
}

CString Phd::PhdArxConver::PtToStr(const AcGePoint2d& pt, int prec /*= -1*/, int unit /*= -1*/)
{
	TCHAR xstr[100], ystr[100];

	acdbRToS(pt.x, unit, prec, xstr);
	acdbRToS(pt.y, unit, prec, ystr);

	CString str;
	str.Format(_T("(%s, %s)"), xstr, ystr);
	return str;
}

