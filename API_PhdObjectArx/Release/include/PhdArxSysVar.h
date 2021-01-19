#pragma once

namespace Phd{

class PHD_OBJECTARX_API PhdArxSysVar
{
public:
	PhdArxSysVar();

public:
	//���ܣ�����ϵͳ����
	bool GetSysVar(LPCTSTR varName,int& val);
	bool SetSysVar(LPCTSTR varName,int val);
	
	//���ܣ�������ϵͳ����
	bool GetSysVar(LPCTSTR varName, double& val);
	bool SetSysVar(LPCTSTR varName, double val);

	//���ܣ��ַ���ϵͳ����
	bool GetSysVar(LPCTSTR varName, CString& val);
	bool SetSysVar(LPCTSTR varName, LPCTSTR val);

	//���ܣ���ά��ϵͳ����
	bool GetSysVar(LPCTSTR varName, AcGePoint3d& val);
	bool SetSysVar(LPCTSTR varName, const AcGePoint3d& val);

	//���ܣ���ά��ϵͳ����
	bool GetSysVar(LPCTSTR varName, AcGePoint2d& val);
	bool SetSysVar(LPCTSTR varName, const AcGePoint2d& val);

private:
	std::shared_ptr<Phd::PhdArxInline> m_apPhdArxInline;



};

}