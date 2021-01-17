#pragma once

//视图
namespace PhdView {
	
	//************************************
	// Summary: 	得到当前视图设置
	// Parameters: 	
	//    view		- 	输出当前视图信息
	// Returns:   	
	//************************************
	void GetCurrentView(AcDbViewTableRecord &view);

	//************************************
	// Summary: 	根据指定范围切换视图
	// Parameters: 	
	//    ptMin		- 	输入视图最小点
	//    ptMax		- 	输入视图最大点
	//    scale		- 	输入比例（一般不会直接切换到实体大小，可以用scale调整一下）
	// Returns:   	
	//************************************
	void SetViewExtent(const AcGePoint3d &ptMin, const AcGePoint3d &ptMax, double scale = 1.0);

	// Summary:   得到当前视图的高度
	// Time:	  2020年1月14日 peihaodong
	// Explain:	  
	double GetCurViewHeight();

	//得到当前视图数据
	void GetCurViewData(double& dHeight,double& dWidth,AcGePoint2d& ptCenter);

	//设置当前视图数据
	void SetCurViewData(double dHeight, double dWidth, const AcGePoint2d& ptCenter);
}

