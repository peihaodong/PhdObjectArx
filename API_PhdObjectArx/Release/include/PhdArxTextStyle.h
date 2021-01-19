#pragma once

//文字样式
namespace Phd{

class PHD_OBJECTARX_API PhdArxTextStyle
{
public:
	//功能：得到数据库所有的文字样式名
	AcArray<CString> GetAllTextStyleName(AcDbDatabase *pDb = acdbCurDwg());

	// Summary:   得到文字样式id
	// Time:	  2019年12月9日 peihaodong
	// Explain:	  
	AcDbObjectId GetTextStyleId(LPCTSTR szName, AcDbDatabase *pDb = acdbCurDwg());
	AcDbObjectId GetTextStyleIdOfMText(const AcDbObjectId& idMText);
	
	// Summary:   得到文字样式的宽度比例
	// Time:	  2019年12月9日 peihaodong
	// Explain:	  
	double GetWidthScale(const AcDbObjectId& idTextStyle);

	// Summary:   得到数据库所有的文字样式id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetTextStyleIdsOnDb(AcDbDatabase* pDb);



};

}