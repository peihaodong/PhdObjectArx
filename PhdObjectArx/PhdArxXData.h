#pragma once

//扩展数据
namespace Phd{

class PHD_OBJECTARX_API PhdArxXData
{
public:
	//************************************
	// Summary: 	设置实体的扩展数据
	//************************************
	bool SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, LPCTSTR value);
	bool SetXData(AcDbEntity* pEnt, LPCTSTR szAppName,  int value);
	bool SetXData(AcDbEntity* pEnt, LPCTSTR szAppName,  double value);
	bool SetXData(AcDbEntity* pEnt, LPCTSTR szAppName, const AcGePoint3d& value);
	bool SetXData(const AcDbObjectId& id, LPCTSTR szAppName, int value);
	bool SetXData(const AcDbObjectId& id, LPCTSTR szAppName, LPCTSTR value);
	bool SetXData(const AcDbObjectId& id, LPCTSTR szAppName,  double value);
	bool SetXData(const AcDbObjectId& id, LPCTSTR szAppName, const AcGePoint3d& value);

	//************************************
	// Summary: 	读取实体的扩展数据 	
	//************************************
	bool GetXData(AcDbEntity* pEnt, LPCTSTR szAppName,int& value);
	bool GetXData(AcDbEntity* pEnt, LPCTSTR szAppName,  CString& value);
	bool GetXData(AcDbEntity* pEnt, LPCTSTR szAppName,  double& value);
	bool GetXData(AcDbEntity* pEnt, LPCTSTR szAppName, AcGePoint3d& value);
	bool GetXData(const AcDbObjectId& id, LPCTSTR szAppName, int& value);
	bool GetXData(const AcDbObjectId& id, LPCTSTR szAppName,  CString& value);
	bool GetXData(const AcDbObjectId& id, LPCTSTR szAppName,  double& value);
	bool GetXData(const AcDbObjectId& id, LPCTSTR szAppName, AcGePoint3d& value);

	bool IsExistXData(AcDbEntity* pEnt, LPCTSTR szAppName);
	bool IsExistXData(const AcDbObjectId& id, LPCTSTR szAppName);

};

}