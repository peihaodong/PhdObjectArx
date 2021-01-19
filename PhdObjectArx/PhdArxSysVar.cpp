#include "StdAfx.h"
#include "PhdArxSysVar.h"


Phd::PhdArxSysVar::PhdArxSysVar()
	:m_apPhdArxInline(std::make_shared<Phd::PhdArxInline>())
{

}

bool Phd::PhdArxSysVar::GetSysVar(LPCTSTR varName, int& val)
{
	assert(varName);

	resbuf rb;
	if (acedGetVar(varName, &rb) == RTNORM) 
	{
		ASSERT(rb.restype == RTSHORT);
		val = rb.resval.rint;
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxSysVar::SetSysVar(LPCTSTR varName, const AcGePoint2d& val)
{
	ASSERT(varName != NULL);

	resbuf rb;
	rb.restype = RTPOINT;
	m_apPhdArxInline->CopyAdsPt(rb.resval.rpoint, asDblArray(val));

	if (acedSetVar(varName, &rb) != RTNORM)
		return false;
	else
		return true;
}

bool Phd::PhdArxSysVar::SetSysVar(LPCTSTR varName, const AcGePoint3d& val)
{
	ASSERT(varName != NULL);

	resbuf rb;
	rb.restype = RT3DPOINT;
	m_apPhdArxInline->CopyAdsPt(rb.resval.rpoint, asDblArray(val));

	if (acedSetVar(varName, &rb) != RTNORM)
		return false;
	else
		return true;
}

bool Phd::PhdArxSysVar::SetSysVar(LPCTSTR varName, LPCTSTR val)
{
	ASSERT(varName != NULL);

	resbuf rb;
	rb.restype = RTSTR;
	rb.resval.rstring = const_cast<TCHAR*>(val);

	if (acedSetVar(varName, &rb) != RTNORM)
		return false;
	else
		return true;
}

bool Phd::PhdArxSysVar::SetSysVar(LPCTSTR varName, double val)
{
	ASSERT(varName != NULL);

	resbuf rb;
	rb.restype = RTREAL;
	rb.resval.rreal = val;

	if (acedSetVar(varName, &rb) != RTNORM)
		return false;
	else
		return true;
}

bool Phd::PhdArxSysVar::SetSysVar(LPCTSTR varName, int val)
{
	assert(varName);

	resbuf rb;
	rb.restype = RTSHORT;
	rb.resval.rint = val;

	if (acedSetVar(varName, &rb) != RTNORM) 
		return false;
	else
		return true;
}

bool Phd::PhdArxSysVar::GetSysVar(LPCTSTR varName, AcGePoint3d& val)
{
	resbuf rb;
	if (acedGetVar(varName, &rb) == RTNORM) 
	{
		ASSERT(rb.restype == RT3DPOINT);
		val.set(rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxSysVar::GetSysVar(LPCTSTR varName, AcGePoint2d& val)
{
	resbuf rb;
	if (acedGetVar(varName, &rb) == RTNORM)
	{
		ASSERT(rb.restype == RTPOINT);
		val.set(rb.resval.rpoint[X], rb.resval.rpoint[Y]);
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxSysVar::GetSysVar(LPCTSTR varName, CString& val)
{
	resbuf rb;
	if (acedGetVar(varName, &rb) == RTNORM) 
	{
		ASSERT(rb.restype == RTSTR);
		val = rb.resval.rstring;
		free(rb.resval.rstring);
		return true;
	}
	else
		return false;
}

bool Phd::PhdArxSysVar::GetSysVar(LPCTSTR varName, double& val)
{
	resbuf rb;
	if (acedGetVar(varName, &rb) == RTNORM) 
	{
		ASSERT(rb.restype == RTREAL);
		val = rb.resval.rreal;
		return true;
	}
	else
		return false;
}
