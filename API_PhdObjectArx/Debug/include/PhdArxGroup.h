#pragma once

namespace Phd{

class PHD_OBJECTARX_API PhdArxGroup
{
public:
	//创建组
	AcDbObjectId CreateGroup(LPCTSTR szGourpName, AcDbDatabase* pDb = acdbCurDwg(), bool bSelectable = true);
	bool CreateGroup(const AcDbObjectIdArray& ents, LPCTSTR szGroupName, AcDbObjectId& IdGroup, bool bSelectable = true);

	//功能：创建匿名组
	AcDbObjectId CreateAnonGroup(AcDbDatabase *pDb = acdbCurDwg(), bool bSelectable = true);

	//功能：通过组名寻找组
	bool HasGroup(LPCTSTR szGroupName, AcDbObjectId& IdGroup , AcDbDatabase* pDb = acdbCurDwg());

	//功能：实体添加到组
	bool AppendToGroup(const AcDbObjectId& idGroup,const AcDbObjectId& idEnt);
	bool AppendToGroup(const AcDbObjectId& idGroup, const AcDbObjectIdArray& arridEnt);

	//功能：得到该实体的组id，如果该实体没有添加到组，则返回空
	AcDbObjectId GetGroupId(const AcDbObjectId& ent);

	//功能：得到组中所有实体
	bool GetGroupEnts(AcDbObjectIdArray& IdArray, const AcDbObjectId& IdGroup);

	//功能：重新构建该组
	bool ResetGroup(const AcDbObjectIdArray& ents, const AcDbObjectId& IdGroup);

	// Summary:   得到数据库所有的组id
	// Time:	  2020年3月23日 peihaodong
	// Explain:	  
	AcDbObjectIdArray GetGroupIdsOnDb(AcDbDatabase* pDb);

	//删除组中的某个实体
	bool GroupRemoveEnt(const AcDbObjectId& idGroup,const AcDbObjectId& idDelEnt);

	//删除组
	bool DeleteGroup(const AcDbObjectId& idGroup);
};

}