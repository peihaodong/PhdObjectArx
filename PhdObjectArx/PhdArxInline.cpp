#include "StdAfx.h"
#include "PhdArxInline.h"


void Phd::PhdArxInline::CopyAdsPt(ads_point ptSource, ads_point ptTarget)
{
	ptSource[0] = ptTarget[0];
	ptSource[1] = ptTarget[1];
	ptSource[2] = ptTarget[2];
}

void Phd::PhdArxInline::CopyEname(ads_name nameSource, ads_name nameTarget)
{
	nameSource[0] = nameTarget[0];
	nameSource[1] = nameTarget[1];
}

AcGePoint3d Phd::PhdArxInline::MidPt(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
	return AcGePoint3d((pt1.x + pt2.x) / 2, (pt1.y + pt2.y) / 2, (pt1.z + pt2.z) / 2);
}

AcGePoint3d Phd::PhdArxInline::RelativePt(const AcGePoint3d& pt, double x, double y)
{
	return AcGePoint3d(pt.x + x, pt.y + y, pt.z);
}

AcGePoint3d Phd::PhdArxInline::PolarPt(const AcGePoint3d& pt, double angle, double distance)
{
	ads_point ptForm, ptTo;
	ptForm[X] = pt.x;
	ptForm[Y] = pt.y;
	ptForm[Z] = pt.z;

	acutPolar(ptForm, angle, distance, ptTo);
	return asPnt3d(ptTo);
}

bool Phd::PhdArxInline::IsEqual(double d1, double d2, double dTolerance /*= 0.0001*/)
{
	if (std::abs(d1 - d2) > dTolerance)
		return false;
	else
		return true;
}

bool Phd::PhdArxInline::IsOddNumber(int nNum)
{
	if (nNum % 2 == 0)
		return false;
	else
		return true;
}
