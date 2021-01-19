#pragma once

namespace Phd{

class PHD_OBJECTARX_API PhdArxSysVar
{
public:
	PhdArxSysVar();

public:
	//功能：整数系统变量
	bool GetSysVar(LPCTSTR varName,int& val);
	bool SetSysVar(LPCTSTR varName,int val);
	
	//功能：浮点数系统变量
	bool GetSysVar(LPCTSTR varName, double& val);
	bool SetSysVar(LPCTSTR varName, double val);

	//功能：字符串系统变量
	bool GetSysVar(LPCTSTR varName, CString& val);
	bool SetSysVar(LPCTSTR varName, LPCTSTR val);

	//功能：三维点系统变量
	bool GetSysVar(LPCTSTR varName, AcGePoint3d& val);
	bool SetSysVar(LPCTSTR varName, const AcGePoint3d& val);

	//功能：二维点系统变量
	bool GetSysVar(LPCTSTR varName, AcGePoint2d& val);
	bool SetSysVar(LPCTSTR varName, const AcGePoint2d& val);

private:
	std::shared_ptr<Phd::PhdArxInline> m_apPhdArxInline;



};

}