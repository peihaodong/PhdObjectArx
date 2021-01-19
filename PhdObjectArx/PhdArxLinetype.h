#pragma once

//线型
namespace Phd{

class PHD_OBJECTARX_API PhdArxLinetype
{
public:
	//功能：设置实体线型
	bool SetEntLinetype(const AcDbObjectId& idEnt, LPCTSTR szLinetypeName);

	//功能：得到实体线型名
	CString GetLinetypeName(const AcDbObjectId& idEnt);

	// Summary:   得到数据库所有的线型id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetLinetypeIdsOnDb(AcDbDatabase* pDb);



};

}