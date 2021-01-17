#pragma once


namespace PhdDatabase {

	bool GetObjectIdArrayFromAcDbIdMapping(const AcDbIdMapping& adim,
		const AcDbObjectIdArray& adoiaInput,AcDbObjectIdArray& adoiaPair);

	// Summary:   将数据库保存为dwg图纸
	// Time:	  2020年1月7日 peihaodong
	// Explain:	  用户需手动释放数据库指针
	bool DbSaveToDwg(AcDbDatabase* pDb,LPCTSTR szDwgPath,bool bBak = false);
	bool DbSaveToDwg(AcDbDatabase* pDb, LPCTSTR szDwgPath, 
		const AcDb::AcDbDwgVersion dwgVer, bool bBak = false);

	// Summary:   保存为dxf图纸
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	bool DbSaveToDxf(AcDbDatabase* pDb,LPCTSTR szDxfPath,
		const AcDb::AcDbDwgVersion dwgVer);
	bool DbSaveToDxf(AcDbDatabase* pDb, LPCTSTR szDxfPath);
	// Summary:   保存为dwg或dxf图纸
	// Time:	  2020年4月15日 peihaodong
	// Explain:	  
	bool DbSaveToDwgOrDxf(AcDbDatabase* pDb, LPCTSTR szPath);

	//功能：将图纸插入到数据库
	bool InsertDwg(LPCTSTR szDwgPath,const AcGePoint3d& ptInsert,AcDbDatabase* pDb = acdbCurDwg());

	//功能：将图纸中的块定义插入到数据库
	bool InsertBlkDef(LPCTSTR szDwgPath,LPCTSTR szBlkName,AcDbDatabase* pDb = acdbCurDwg());

	//功能：得到图纸中所有的块名
	AcArray<CString> GetBlkDefNames(const CString& strDwgPath);

	// Summary:   得到数据库模型空间所有实体的外包矩形
	// Time:	  2019年10月31日
	// Explain:	  
	AcDbExtents GetDbExtent(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   得到数据库模型空间所有实体的id
	// Time:	  2019年10月31日
	// Explain:	  
	AcDbObjectIdArray GetDbEntId(AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   切换当前数据库
	// Time:	  2019年12月17日 peihaodong
	// Explain:	  
	void SwitchCurDatabase(AcDbDatabase* pDb);

#pragma region wblock insert readDwgFile
	// Summary:   得到dwg图纸数据库指针
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  使用完后要delete；该dwg图纸必须是关闭状态；不可同时获取
	AcDbDatabase* GetDwgDbPointer(LPCTSTR szDwgPath);
	// Summary:   得到dxf图纸数据库指针
	// Time:	  2020年4月15日 peihaodong
	// Explain:	   使用完后要delete；该dwg图纸必须是关闭状态；不可同时获取
	AcDbDatabase* GetDxfDbPointer(LPCTSTR szDxfPath);
	// Summary:   
	// Time:	  2020年4月15日 peihaodong
	// Explain:	  
	AcDbDatabase* GetDwgOrDxfDbPointer(LPCTSTR szPath);

	// Summary:   将pDbSource数据库中的arridSou实体以ptBaseSou为基点，
	//			以块定义的形式拷贝到pDbTarget数据库中
	// Time:	  2019年12月12日 peihaodong
	// Explain:	  szBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource,const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou,AcDbDatabase* pDbTarget,LPCTSTR szBlkNameTar,
		AcDbObjectId& idBlkDefTar);
	// Summary:   将pDbSource数据库中的块定义idBlkDefSou拷贝到pDbTarget数据库中
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
		 AcDbDatabase* pDbTarget, LPCTSTR szBlkNameTar,AcDbObjectId& idBlkDefTar);
	// Summary:   将pDbSource数据中的所有实体(当前数据库存在的实体)
	//			作为块定义拷贝到pDbTarget数据库中
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlock(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
		LPCTSTR szBlkNameTar, AcDbObjectId& idBlkDefTar);
	
	// Summary:   将pDbSource数据库中的实体arridSou以ptBaseSou为基点，以原实体形式
	//			拷贝到pDbTarget数据库中ptBaseTar位置
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget,
		const AcGePoint3d& ptBaseTar );
	// Summary:   将pDbSource数据库中的块定义idBlkDefSou以原实体形式拷贝到pDbTarget
	//			数据库ptBaseTar位置
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
		 AcDbDatabase* pDbTarget,const AcGePoint3d& ptBaseTar);
	// Summary:   将pDbSource数据库中的所有实体(当前数据库存在的实体)
	//			以原实体形式拷贝到pDbTarget
	//			数据库ptBaseTar位置
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	bool DbCopyOfEnts(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget,
		const AcGePoint3d& ptBaseTar);

	//有问题，实行失败，不知道是不是中望接口bug
	// Summary:   将pDbSource数据库中的arridSou实体以ptBaseSou为基点，作为szNewBlkNameTar
	//			块定义拷贝到pDbTarget数据库中，并把pDbTarget数据库szCpBlkNameTar块定义中的实体
	//			拷贝到新的块定义szNewBlkNameTar中
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szNewBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
			const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);
	// Summary:   将pDbSource数据库中的块定义idBlkDefSou，作为szNewBlkNameTar
	//			块定义拷贝到pDbTarget数据库中，并把pDbTarget数据库szCpBlkNameTar块定义中的实体
	//			拷贝到新的块定义szNewBlkNameTar中
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szNewBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource, const AcDbObjectId& idBlkDefSou,
			AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);
	// Summary:   将pDbSource数据库中的所有实体(当前数据库存在的实体)，作为szNewBlkNameTar
	//			块定义拷贝到pDbTarget数据库中，并把pDbTarget数据库szCpBlkNameTar块定义中的实体
	//			拷贝到新的块定义szNewBlkNameTar中
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  szNewBlkNameTar-块名，如果是匿名块，输入_T("*U")
	// Return:	  得到块定义id-idBlkDefTar
	bool DbCopyOfBlkDef(AcDbDatabase* pDbSource,AcDbDatabase* pDbTarget, LPCTSTR szCpBlkNameTar,
			LPCTSTR szNewBlkNameTar, AcDbObjectId& idBlkDefTar);

#pragma endregion

#pragma region wblockCloneObjects deepCloneObjects
	// Summary:   数据库间拷贝：将pDbSource数据库中的arridSou实体以ptBaseSou为基点，
	//			拷贝到pDbTarget数据库ptBaseTar位置，arridTar是实体拷贝后在pDbTarget
	//			数据库中的ID
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  pDbSource和pDbTarget必须是不同的数据库
	bool CopyAmongDbOfBlkTbl(AcDbDatabase* pDbSource, const AcDbObjectIdArray& arridSou,
		const AcGePoint3d& ptBaseSou, AcDbDatabase* pDbTarget, const AcGePoint3d& ptBaseTar,
		AcDbObjectIdArray& arridTar);

	// Summary:   数据库内拷贝：将pDb数据库中的arrid实体以ptBase为基点，拷贝到pDb数据库的idBlkDef
	//			块定义的ptBaseCopied位置，arridCopied是拷贝后的实体ID
	// Time:	  2019年12月13日 peihaodong
	// Explain:	  
	bool CopyWithinDbOfBlkTbl(AcDbDatabase* pDb, const AcDbObjectIdArray& arrid,
		const AcGePoint3d& ptBase, const AcDbObjectId& idBlkDef,const AcGePoint3d& ptBaseCopied,
		AcDbObjectIdArray& arridCopied);

#pragma endregion


}
