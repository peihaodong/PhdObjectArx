#include "StdAfx.h"
#include "PhdArxXData.h"


bool Phd::PhdArxXData::SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, int value)
{
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdInteger32, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::GetXData(AcDbEntity* pEnt, LPCTSTR szAppName, int& value)
{
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdInteger32 == pTemp->restype)
			{
				value = pTemp->resval.rint;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::IsExistXData(AcDbEntity* pEnt, LPCTSTR szAppName)
{
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		acutRelRb(pRb);
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxXData::IsExistXData(const AcDbObjectId& id, LPCTSTR szAppName)
{
	AcDbEntityPointer pEnt(id, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		acutRelRb(pRb);
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxXData::GetXData(const AcDbObjectId& id, LPCTSTR szAppName, AcGePoint3d& value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;

	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdWorldXCoord == pTemp->restype)
			{
				value[X] = pTemp->resval.rpoint[X];
				value[Y] = pTemp->resval.rpoint[Y];
				value[Z] = pTemp->resval.rpoint[Z];
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(const AcDbObjectId& id, LPCTSTR szAppName, double& value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;

	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdReal == pTemp->restype)
			{
				value = pTemp->resval.rreal;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(const AcDbObjectId& id, LPCTSTR szAppName, CString& value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;

	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdAsciiString == pTemp->restype)
			{
				value = pTemp->resval.rstring;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(const AcDbObjectId& id, LPCTSTR szAppName, int& value)
{
	AcDbEntityPointer pEnt(id,AcDb::kForRead);
	if (Acad::eOk != pEnt.openStatus())
		return false;

	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdInteger32 == pTemp->restype)
			{
				value = pTemp->resval.rint;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(AcDbEntity* pEnt, LPCTSTR szAppName, AcGePoint3d& value)
{
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdWorldXCoord == pTemp->restype)
			{
				value[X] = pTemp->resval.rpoint[X];
				value[Y] = pTemp->resval.rpoint[Y];
				value[Z] = pTemp->resval.rpoint[Z];
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(AcDbEntity* pEnt, LPCTSTR szAppName, double& value)
{
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdReal == pTemp->restype)
			{
				value = pTemp->resval.rreal;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::GetXData(AcDbEntity* pEnt, LPCTSTR szAppName, CString& value)
{
	struct resbuf *pRb = pEnt->xData(szAppName);
	if (pRb)
	{
		struct resbuf *pTemp = pRb;
		pTemp = pTemp->rbnext;
		while (pTemp)
		{
			if (AcDb::kDxfXdAsciiString == pTemp->restype)
			{
				value = pTemp->resval.rstring;
				acutRelRb(pRb);
				return true;
			}
			pTemp = pTemp->rbnext;
		}
	}
	acutRelRb(pRb);
	return false;
}

bool Phd::PhdArxXData::SetXData(const AcDbObjectId& id, LPCTSTR szAppName, const AcGePoint3d& value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdWorldXCoord, asDblArray(value), RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(const AcDbObjectId& id, LPCTSTR szAppName, double value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdReal, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(const AcDbObjectId& id, LPCTSTR szAppName, LPCTSTR value)
{
	AcDbEntityPointer pEnt(id, AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdAsciiString, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(const AcDbObjectId& id, LPCTSTR szAppName, int value)
{
	AcDbEntityPointer pEnt(id,AcDb::kForWrite);
	if (Acad::eOk != pEnt.openStatus())
		return false;
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdInteger32, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, const AcGePoint3d& value)
{
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdWorldXCoord, asDblArray(value), RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, double value)
{
	acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdReal, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}

bool Phd::PhdArxXData::SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, LPCTSTR value)
{
	auto rt = acdbRegApp(szAppName);
	struct resbuf*rb = acutBuildList(AcDb::kDxfRegAppName, szAppName, AcDb::kDxfXdAsciiString, value, RTNONE);
	Acad::ErrorStatus es = pEnt->setXData(rb);
	acutRelRb(rb);
	if (Acad::eOk != es)
		return false;
	else
		return true;
}
