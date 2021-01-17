#pragma once

//块
namespace PhdBlock {

	// Summary:   得到块表记录中所有实体id（通过块名）
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szBlkTblRcdName-块表记录名（模型空间的名字是：ACDB_MODEL_SPACE）
	bool GetIdsOnBlock(LPCTSTR szBlkTblRcdName,AcDbObjectIdArray& arrid,
		AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   得到块表记录中所有实体id（通过块定义id）
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	bool GetIdsOnBlock(const AcDbObjectId& idBlkTblRcd,AcDbObjectIdArray& arrid);

	// Summary:   得到块定义Id（通过块名）
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	AcDbObjectId GetBlkDefId(LPCTSTR szBlkName,AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   得到块定义id（通过块参照id）
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	AcDbObjectId GetBlkDefId(const AcDbObjectId& idRef);
	// Summary:   得到块定义id（通过块名）
	// Time:	  2019年11月27日 peihaodong
	// Explain:	  如果数据库中没有该块定义，就从目标图纸拷贝到数据库中
	AcDbObjectId GetBlkDefId(LPCTSTR szBlkName, LPCTSTR szDwgPath,
		AcDbDatabase* pDb = acdbCurDwg());

	//功能：得到数据库所有的块名
	AcArray<CString> GetBlkNamesOnDb(AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   得到数据库中所有的块定义id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetBlkIdsOnDb(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   通过图纸在pDb数据库创建块定义
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  如果pDb存在szBlkName块定义，返回pDb中的块定义
	bool CreateBlock(LPCTSTR szDwgPath, LPCTSTR szBlkName, AcDbObjectId& idBlkDef,
		AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   在pDb创建块定义
	// Time:	  2019年12月16日 peihaodong
	// Explain:	  arrid是pDb中的实体
	bool CreateBlock(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase,
		LPCTSTR szBlkName,AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());
	bool CreateBlock(const AcArray<AcDbEntity*>& arrpEnt, const AcGePoint3d& ptBase,
		LPCTSTR szBlkName, AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   通过块参照id得到该块参照的插入点
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	AcGePoint3d GetBlkRefPosition(const AcDbObjectId& idRef);

	// Summary:   得到块定义或块参照的名称
	// Time:	  2019年11月21日 peihaodong
	// Explain:	  
	CString GetBlkName(const AcDbObjectId& idBlk);

#pragma region 属性块
	//功能：得到属性块属性名称
	AcArray<CString> GetAttTagsOnBlk(const AcDbObjectId& idBlkDef);

	//功能：得到属性块参照属性信息
	std::map<CString, CString> GetAttInfoOnBlkRef(const AcDbObjectId& idRef);

	//功能：得到属性块参照某一属性的文本
	CString GetAttTextOnBlkRef(const AcDbObjectId& idRef,LPCTSTR szAttTag);
	CString GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag);
	bool GetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szAttTag,
		CString& strAttValue);

	//功能：设置属性块参照属性文本
	bool SetAttTextOnBlkRef(const AcDbObjectId& idRef,LPCTSTR szTag,LPCTSTR szText);
	bool SetAttTextOnBlkRef(AcDbBlockReference* pBlkRef, LPCTSTR szTag, LPCTSTR szText);
	bool SetAttTextOnBlkRef(const AcDbObjectId& idRef,const std::map<CString,CString>& mapData);

	//功能：创建属性块参照
	AcDbBlockReference* CreateAttBlkRef(const AcDbObjectId& idBlkDef,const AcGePoint3d& ptInsert);
	AcDbBlockReference* CreateAttBlkRef(const AcDbObjectId& idBlkDef, const AcGePoint3d& ptInsert, 
		const std::map<CString, CString>& mapAtt);

	// Summary:   该块参照存不存在该名字的属性
	// Time:	  2019年12月26日 peihaodong
	// Explain:	  
	bool IsExistAtt(AcDbBlockReference* pBlkRef,LPCTSTR szAttName);

#pragma endregion

#pragma region 匿名块
	//功能：创建匿名块
	bool CreateAnonyBlk(LPCTSTR szDwgPath,AcDbObjectId& idBlkDef,AcDbDatabase* pDb = acdbCurDwg());
	// Summary:   创建匿名块
	// Time:	  2019年12月5日 peihaodong
	// Explain:	  pDb-匿名块定义所在的数据库指针
	bool CreateAnonyBlk(const AcDbObjectIdArray& arrid, const AcGePoint3d& ptBase, 
		AcDbObjectId& idBlkDef, AcDbDatabase* pDb = acdbCurDwg());
	
#pragma endregion



}

