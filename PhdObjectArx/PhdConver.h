#pragma once



namespace PhdConver {

	/*
	asPnt3d();		//将ads_point转换成AcGePoint3d
	asVec3d();		//将ads_point转换成AcGeVector3d
	asDblArray();	//将AcGePoint3d或AcGeVector3d转换成ads_point

	AcDbObject::objectId();				//从指针到ID
	AcDbDatabase::getAcDbObjectId();	//从句柄到ID
	AcDbObjectId::handle();				//从ID到句柄
	AcDbObject::getAcDbHandle();		//从指针到句柄
	*/

#pragma region 转为字符串
	//功能：Id转为字符串（类名和句柄）
	CString IdToStr(const AcDbObjectId& id);

	//功能：点转为字符串
	//参数：prec-小数点位数，如果为-1则使用AutoCAD LUPREC系统变量的当前值；	unit-将字符串格式化为有效的AutoCAD LUNITS值的单位;如果-1，使用当前的LUNITS值
	CString PtToStr(const AcGePoint3d& pt, int prec = -1, int unit = -1);
	CString PtToStr(const AcGePoint2d& pt, int prec = -1, int unit = -1);

	//功能：向量转为字符串
	CString VecToStr(const AcGeVector3d& vec,int prec = -1, int unit = -1);
	CString VecToStr(const AcGeVector2d& vec, int prec = -1, int unit = -1);

	//功能：角度转为字符串
	CString AngleToStr(const double angle,int prec = -1, int unit = -1);

	//功能：浮点数转为字符串
	CString DoubleToStr(const double realVal, int prec = -1, int unit = -1);

	//功能：整数转为字符串
	CString IntToStr(const int intVal);

	//功能：指针（地址）转为字符串
	CString PtrToStr(void* ptr);

	//功能：数据库的名字（文件名）转为字符串
	CString DbToStr(AcDbDatabase* pDb);

	//功能：布尔值转为字符串
	CString BoolToStr(bool b);

#pragma endregion

#pragma region 转为整数
	//功能：浮点数转整数（四舍五入）
	int ToInt(double dValue);

	//功能：浮点数转整数（向上取整）
	int ToIntOfTop(double dValue);

	//功能：浮点数转整数（向下取整）
	int ToIntOfBottom(double dValue);
#pragma endregion


	//功能：浮点数根据小数点位数更新值
	//参数：unDot-小数点位数
	double UpdateOnDotNum(double dValue,unsigned int unDot);

	//功能：角度转换为弧度
	double ToRadian(double dAngle);
	//功能：弧度转换为角度
	double ToAngle(double dRadian);

	//功能：ads_name转为Id
	bool AdsnameToId(const ads_name objName,AcDbObjectId& id);
	//功能：Id转为ads_name
	bool IdToAdsname(const AcDbObjectId& id,ads_name& name);

	//功能：转为二维点
	AcGePoint2d ToPt2d(const AcGePoint3d& pt);
	//功能：转为三维点
	AcGePoint3d ToPt3d(const AcGePoint2d& pt, double z = 0);

	//功能：用户坐标系转换为世界坐标系
	AcGePoint3d UcsToWcsPt(const AcGePoint3d &point);
	//功能：用户坐标系转换为显示坐标系
	AcGePoint2d UcsToDcsPt(const AcGePoint3d& pt);
	//功能：世界坐标系转换成用户坐标系
	AcGePoint3d WcsToUcsPt(const AcGePoint3d &point);
	//功能：世界坐标转显示坐标
	AcGePoint3d WcsToDcsPt(const AcGePoint3d &point);
	
	// Summary:   将字符转为ASCII码
	// Time:	  2019年12月30日 peihaodong
	// Explain:	  
	int ToASCII(TCHAR s);
	// Summary:   将ASCII码转为字符
	// Time:	  2019年12月30日 peihaodong
	// Explain:	  
	TCHAR ToChar(int n);


}

