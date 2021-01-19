#pragma once

//用户交互
namespace Phd{

class PHD_OBJECTARX_API PhdArxUiPr
{
public:
	//功能：选取单个实体
	//例子：PhdUiPr::SelEnt(_T("选择一条直线"), AcDbLine::desc(), id, pt);
	bool SelEnt(LPCTSTR szPrompt, AcRxClass* classType, AcDbObjectId& id, AcGePoint3d& pt);
	bool SelEnt(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectId& id,
		AcGePoint3d& pt);
	// Summary:   选取单个实体
	// Time:	  2020年6月10日 peihaodong
	// Explain:	  返回0：取消 返回1：成功 返回2：空格\回车
	int SelEnt2(LPCTSTR szPrompt, AcRxClass* classType, AcDbObjectId& id, AcGePoint3d& pt);

	//功能：选取多个实体
	bool SelEnts(LPCTSTR szPrompt, const AcArray<AcRxClass*>& arrclassType, AcDbObjectIdArray& idArr);

	//功能：选择关键字
	//例子：
	//std::vector<SKey> vecKey;
	//vecKey.push_back(SKey(_T("比例"), _T("Scale")));
	//vecKey.push_back(SKey(_T("编号"), _T("Number")));
	bool SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey,CString& key);
	bool SelKey(LPCTSTR szPrompt, const std::vector<SKey>& vecKey, CString& key, int nInitFlag);

	//功能：获取实数
	bool GetDouble(LPCTSTR szPrompt, double& dValue);
	bool GetDouble(LPCTSTR szPrompt,double& dValue,double dDefault);
	bool GetDouble(LPCTSTR szPrompt, double& dValue, double dDefault,int nInitFlag);

	//功能：获取整数
	bool GetInt(LPCTSTR szPrompt, int& nValue);
	bool GetInt(LPCTSTR szPrompt, int& nValue,int nDefault);

	//功能：获取字符串
	bool GetString(LPCTSTR szPrompt,CString& strValue);
	bool GetString(LPCTSTR szPrompt, CString& strValue,LPCTSTR szDefault);
	bool GetString(LPCTSTR szPrompt, CString& strValue, int nInitFlag);

	//功能：获取点
	bool GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt);
	bool GetPoint(LPCTSTR szPrompt, AcGePoint3d& pt, const AcGePoint3d& ptBase);

	//功能：获取角点
	bool GetCorner(LPCTSTR szPrompt, const AcGePoint3d& ptBase, AcGePoint3d& pt);

	//功能：获取角度
	//注意：用户输入度数，返回弧度值
	bool GetAngle(LPCTSTR szPrompt, double& dAngle);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle, double dDefault);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle,const AcGePoint3d& ptBase);
	bool GetAngle(LPCTSTR szPrompt, double& dAngle,const AcGePoint3d& ptBase, double dDefault);

	//功能：获取距离
	bool GetDist(LPCTSTR szPrompt, double& dDist);
	bool GetDist(LPCTSTR szPrompt, double& dDist, double dDefault);
	bool GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase);
	bool GetDist(LPCTSTR szPrompt, double& dDist, const AcGePoint3d& ptBase, double dDefault);





};

}