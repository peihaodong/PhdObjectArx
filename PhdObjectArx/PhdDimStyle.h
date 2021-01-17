#pragma once

//标注样式
namespace PhdDimStyle {

	//功能：得到标注样式Id
	//************************************
	// Method:    GetDimStyleId
	// FullName:  PhdDimStyle::GetDimStyleId
	// Access:    public 
	// Returns:   AcDbObjectId
	// Qualifier:
	// Parameter: LPCTSTR szDimStyleName
	// Parameter: AcDbDatabase * pDb
	//************************************
	AcDbObjectId GetDimStyleId(LPCTSTR szDimStyleName, AcDbDatabase* pDb = acdbCurDwg());

	//功能：创建标注样式
	AcDbObjectId CreateDimStyle(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   得到数据库所有的标注样式id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetDimStyleIdsOnDb(AcDbDatabase* pDb);




}

