#pragma once

//视口
namespace PhdViewport {

	//功能：创建视口
	void CreateViewport();

	//功能：显示四视口
	void ShowViewportSi();
	//功能：显示俯视口
	void ShowViewportFu();
	//功能：显示主视口
	void ShowViewportZhu();
	//功能：显示立视口
	void ShowViewportLi();
	//功能：显示左视口
	void ShowViewportZuo();
	//功能：显示单视口
	void ShowViewportDan();

	// Summary:   设置视口范围
	// Time:	  2019年10月31日
	// Explain:	  
	bool SetViewportRange(const AcGePoint3d& ptMin,const AcGePoint3d& ptMax,
		AcDbDatabase* pDb = acdbCurDwg());
	bool SetViewportRange(double dX, double dY,AcDbDatabase* pDb = acdbCurDwg());

	// Summary:   得到视口id
	// Time:	  2019年11月14日 peihaodong
	// Explain:	  
	AcDbObjectId GetViewportId(AcDbDatabase* pDb = acdbCurDwg());



}

