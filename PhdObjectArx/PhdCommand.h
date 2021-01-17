#pragma once


namespace PhdCommand {

	//功能：关闭命令回显
	void CommandEchoOff();

	//设置标注线性比例
	//说明：标注显示的数值按dValue进行缩放
	bool SetDimLineScale(double dValue);

	// Summary:   设置标注全局比例
	// Time:	  2019年11月12日 peihaodong
	// Explain:	  
	bool SetDimScale(double dValue);

	//功能：设置区域覆盖是否显示边框
	bool SetWipeoutShow(bool bShow = false);

	//功能：设置倒圆角半径
	bool SetFilletRadius(double dRadius);

	//功能：调用cad命令倒圆角
	//返回圆弧id
	AcDbObjectId FilletByCommand(const AcDbObjectId& idLine1, const AcDbObjectId& idLine2);

	//功能：定位实体
	bool OrientationEnt(const AcDbObjectId& idEnt);

	//功能：zoom显示全部实体
	bool ZoomAllEnt();

	// Summary:   通过调用cad命令，样条曲线转多段线
	// Time:	  2020年4月1日 peihaodong
	// Explain:	  生成新的多段线
	bool SplineToPline(const AcDbObjectIdArray& arridSpline,
		AcDbObjectIdArray& arridPline,int nPrecision = 10);
	bool SplineToPline(const AcDbObjectId& idSpline,
		AcDbObjectId& idPline, int nPrecision = 10);
	bool SplineToPline(AcDbSpline* pSpline,
		AcDbObjectId& idPline, int nPrecision = 10);
	bool SplineToPline2(AcDbSpline* pSpline,
		AcDbObjectId& idPline);
}

