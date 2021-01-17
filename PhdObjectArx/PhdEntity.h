#pragma once
#include <dbwipe.h>


namespace PhdEntity {

#pragma region 区域覆盖
	//功能：创建区域覆盖
	AcDbWipeout* CreateWipeout(const AcGePoint3d& ptMin, const AcGePoint3d& ptMax);
	AcDbWipeout* CreateWipeout(const AcGePoint3dArray& ptArr);

#pragma endregion

#pragma region 多段线
	//功能：创建多段线
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& ptArr);
	AcDbPolyline* CreatePolyline(const AcGePoint3dArray& arrpt,
		const AcArray<double>& arrdBulge);
	AcDbPolyline* CreatePolyline(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax);

	//判断该多段线是否是闭合多段线
	bool IsClosedPline(AcDbPolyline* pPline);
#pragma endregion

#pragma region 面域
	//功能：创建面域
	bool CreateRegion(const AcArray<AcDbEntity*>& arrpEnt, AcArray<AcDbRegion*>& arrpRegion);
	bool CreateRegion(AcDbEntity* pEnt, AcArray<AcDbRegion*>& arrpRegion);

#pragma endregion

#pragma region 圆弧
	//功能：创建圆弧
	AcDbArc* CreateArc(const AcGePoint3d& ptStart, const AcGePoint3d& ptOnArc, const AcGePoint3d& ptEnd);
	AcDbArc* CreateArc(const AcGePoint3d& ptStart,  const AcGePoint3d& ptEnd, double dRadius);
	//功能：圆心、起始点、终止点绘制圆弧（不知道谁是起始点和终止点）
	AcDbArc* CreateArcByPt(const AcGePoint3d& ptCenter, const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	// Summary:   通过圆心、起始点、终止点创建圆弧
	// Time:	  2019年11月29日 peihaodong
	// Explain:	  
	AcDbArc* CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd);
	AcDbArc* CreateArcByPt2(const AcGePoint3d& ptCenter, const AcGePoint3d& ptStart, 
		const AcGePoint3d& ptEnd,const AcDbObjectId& idProEnt);
	// Summary:   通过3点创建圆弧（不知道谁是起始点和终止点）
	// Time:	  2020年6月24日 peihaodong
	// Explain:	  
	AcDbArc* CreateArcBy3Pt(const AcGePoint3d& pt1,const AcGePoint3d& ptOnArc,
		const AcGePoint3d& pt2);

	// Summary:   得到圆弧中点坐标
	// Time:	  2020年2月17日 peihaodong
	// Explain:	  
	AcGePoint3d GetArcMidPt(AcDbArc* pArc);

	// Summary:   修改圆弧坐标点
	// Time:	  2020年3月6日 peihaodong
	// Explain:	  
	bool ModifyArcPt(AcDbArc* pArc, const AcGePoint3d& ptFrom, const AcGePoint3d& ptTo);
#pragma endregion

#pragma region 单行文字
	//功能：创建以pt为中心点的单行文字
	AcDbText* CreateTextForCenter(double dHeight, const AcGePoint3d& pt,LPCTSTR szText);
	AcDbText* CreateTextForCenter(const AcGePoint3d& pt, LPCTSTR szText,
		const AcDbObjectId& idProEnt);
	AcDbText* CreateTextForLeftTop(double dHeight,const AcGePoint3d& pt,LPCTSTR szText);
	AcDbText* CreateTextForLeft(double dHeight, const AcGePoint3d& pt, LPCTSTR szText);
	AcDbText* CreateTextForLeft(double dHeight, const AcGePoint3d& pt,
		LPCTSTR szText,AcDbEntity* pProEnt);
	AcDbText* CreateTextForLeft(const AcGePoint3d& pt,LPCTSTR szText, 
		const AcDbObjectId& idProEnt);

#pragma endregion

#pragma region 表格
	//功能：创建表格
	AcDbTable* CreateTable(const AcGePoint3d& ptInster);
#pragma endregion

#pragma region 直线
	// Summary:   创建直线
	// Time:	  2019年11月5日 peihaodong
	// Explain:	  
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd);
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd, AcDbEntity* pProEnt);
	AcDbLine* CreateLine(const AcGePoint3d& ptStart,
		const AcGePoint3d& ptEnd, const AcDbObjectId& idProEnt);
#pragma endregion

#pragma region 引线
	AcDbLeader* CreateLeader(const AcGePoint3dArray& arrpt,
		double dArrowSize,double dDimScale);
#pragma endregion

#pragma region 点
	AcDbPoint* CreatePoint(const AcGePoint3d& pt);

#pragma endregion

#pragma region 圆
	AcDbCircle* CreateCircle(const AcGePoint3d& ptCenter, double dRadius);

#pragma endregion

}

