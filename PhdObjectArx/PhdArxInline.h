#pragma once

#ifndef DEL
#define DEL(ptr) if (NULL != (ptr)){ delete (ptr); (ptr) = NULL;}
#endif

#ifndef PI
#define PI (atan(1.0)*4)		
#endif

#ifndef ReturnfalseNotTrue
#define ReturnfalseNotTrue(b) if (!(b)) return false;
#endif

#ifndef ReturnfalseNoteOk
#define ReturnfalseNoteOk(es) if (Acad::eOk != (es)) return false;
#endif

#ifndef Struct_Key
#define Struct_Key
struct SKey
{
	CString m_strName;
	CString m_strValue;

	SKey() {}
	SKey(LPCTSTR szName,LPCTSTR szValue)
	:m_strName(szName),m_strValue(szValue){}
};
#endif

namespace Phd{

class PHD_OBJECTARX_API PhdArxInline
{
public:
	//功能：对ads_point进行拷贝
	void CopyAdsPt(ads_point ptSource,ads_point ptTarget);
	//功能：对实体名进行拷贝
	void CopyEname(ads_name nameSource,ads_name nameTarget);

	//功能：得到两点中点
	AcGePoint3d MidPt(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
	//功能：相对坐标求点
	AcGePoint3d RelativePt(const AcGePoint3d& pt, double x, double y);
	//功能：极坐标求点
	// Parameters: 	
	//    pt		- 	输入初始点
	//    angle		- 	输入结果点与初始点的夹角(弧度)
	//    distance		- 	输入结果点到初始点的距离
	AcGePoint3d PolarPt(const AcGePoint3d& pt, double angle, double distance);

	//功能：判断两个实数是否相等
	bool IsEqual(double d1, double d2,double dTolerance = 0.0001);

	//是否是奇数
	bool IsOddNumber(int nNum);
};

}