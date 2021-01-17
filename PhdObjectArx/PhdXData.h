#pragma once

//��չ����
namespace PhdXData {

	//************************************
	// Summary: 	����ʵ�����չ����
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
	// Summary: 	��ȡʵ�����չ���� 	
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

}
