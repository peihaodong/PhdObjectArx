#pragma once

//选择集选取实体
namespace Phd{

class PHD_OBJECTARX_API PhdArxSelSet
{
public:
	//功能：通过过滤条件选取实体
	//例子：resbuf* pRb = acutBuildList(-4, _T("<and"), RTDXF0, _T("INSERT"), 1001, _T("扩展数据应用程序名"), -4, _T("and>"), RTNONE);
	AcDbObjectIdArray SelEntsByFilter(resbuf* pRb);

	//功能：选取多个实体
	//例子：resbuf* pRb = acutBuildList(-4, _T("<OR"),RTDXF0, _T("LINE"),RTDXF0, _T("ARC"),RTDXF0, _T("LWPOLYLINE"),-4, _T("OR>"),RTNONE);
	//函数内部释放pRb指针
	bool SelEnts(LPCTSTR szPrompt, resbuf* pRb,AcDbObjectIdArray& arrid );
	bool SelEnts(LPCTSTR szPrompt, AcDbObjectIdArray& arrid);

	//功能：选取多个实体，存在关键字
	//注意：需要编写Callback函数
	//例子：
	//std::vector<SKey> vecKey;
	//vecKey.push_back(SKey(_T("比例"), _T("Scale")));
	//vecKey.push_back(SKey(_T("编号"), _T("Number")));
	bool SelEnts(LPCTSTR szPrompt, resbuf* pRb, const std::vector<SKey>& vecKey, AcDbObjectIdArray& arrid);

	// Summary:   得到区域内实体id
	// Time:	  2019年10月22日
	// Explain:	  使用此函数时需要显示全部实体
	AcDbObjectIdArray GetAreaEnts(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax);


};

}