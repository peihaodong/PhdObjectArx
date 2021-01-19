#pragma once


namespace Phd {

class PHD_OBJECTARX_API PhdArxXRecord
{
public:
	//************************************
	// Summary:  设置扩展记录到有名对象字典中
	// Parameter:
	//      szDictinaryName -    有名对象字典中的字典名
	//		szRecordName - 字典中的记录名
	//		dValue - 输入的double型数据
	//      pDb -    数据库
	// Return:   
	// Notice:   
	// Update Time: 2020-10-21 16:13:30
	//************************************
	bool SetXRecordOfNameDictionary(LPCTSTR szDictinaryName,
		LPCTSTR szRecordName, double dValue, AcDbDatabase* pDb = acdbCurDwg());

	//************************************
	// Summary:  得到扩展记录从有名对象字典中
	// Parameter:
	//      szDictinaryName -    有名对象字典中的字典名
	//      szRecordName -    字典中的记录名
	//      dValue -    输出的double型数据
	//      pDb -    数据库
	// Return:   
	// Notice:   
	// Update Time: 2020-10-21 16:42:20
	//************************************
	bool GetXRecordOfNameDictionary(LPCTSTR szDictinaryName,
		LPCTSTR szRecordName, double& dValue, AcDbDatabase* pDb = acdbCurDwg());
};

}