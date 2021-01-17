#pragma once

//图层
namespace PhdLayer {

	//功能：得到图层id
	//bCreate-输入布尔值：图层不存在是否创建
	AcDbObjectId GetLayerId(const CString& strLayerName, bool bCreate = true,
		AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   pDb是否存在此名字的图层
	// Time:	  2019年12月23日 peihaodong
	// Explain:	  
	bool IsExist(LPCTSTR szLayerName, AcDbDatabase* pDb = acdbCurDwg());

	//功能：设置实体图层
	bool SetEntLayer(const AcDbObjectId& idEnt, const AcDbObjectId& idLayer);
	bool SetEntLayer(const AcDbObjectIdArray& arridEnt, const AcDbObjectId& idLayer);

	// Summary:   设置图层关闭
	// Time:	  2019年11月18日 peihaodong
	// Explain:	  
	bool SetLayerOff(const AcDbObjectId& idLayer,bool bOff = true);

	// Summary:   得到图层名
	// Time:	  2019年11月18日 peihaodong
	// Explain:	  
	CString GetLayerName(const AcDbObjectId& idLayer);

	// Summary:   得到pDb数据库中szLayerName图层下的所有实体ID
	// Time:	  2019年12月18日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetEntIdsOfLayer(LPCTSTR szLayerName,
		AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   设置图层颜色
	// Time:	  2019年12月23日 peihaodong
	// Explain:	  
	bool SetColorIndex(const AcDbObjectId& idLayer, int nColorIndex);

	// Summary:   得到图层颜色索引
	// Time:	  2019年12月23日 peihaodong
	// Explain:	  
	int GetLayerColorIndex(const AcDbObjectId& idLayer);

	// Summary:   得到数据库所有的图层id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetLayerIdsOnDb(AcDbDatabase* pDb);

}

