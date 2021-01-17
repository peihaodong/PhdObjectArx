#include "StdAfx.h"
#include "PhdView.h"
#include "PhdConver.h"


void PhdView::GetCurrentView(AcDbViewTableRecord &view)
{
	struct resbuf rb;
	struct resbuf wcs, ucs, dcs;	// 转换坐标时使用的坐标系统标记

	wcs.restype = RTSHORT;
	wcs.resval.rint = 0;
	ucs.restype = RTSHORT;
	ucs.resval.rint = 1;
	dcs.restype = RTSHORT;
	dcs.resval.rint = 2;

	// 获得当前视口的"查看"模式
	acedGetVar(TEXT("VIEWMODE"), &rb);
	view.setPerspectiveEnabled((rb.resval.rint & 1) != 0);
	view.setFrontClipEnabled((rb.resval.rint & 2) != 0);
	view.setBackClipEnabled((rb.resval.rint & 4) != 0);
	view.setFrontClipAtEye((rb.resval.rint & 16) == 0);

	// 当前视口中视图的中心点（UCS坐标）
	acedGetVar(TEXT("VIEWCTR"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &dcs, 0, rb.resval.rpoint);
	view.setCenterPoint(AcGePoint2d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y]));

	// 当前视口透视图中的镜头焦距长度（单位为毫米）
	acedGetVar(TEXT("LENSLENGTH"), &rb);
	view.setLensLength(rb.resval.rreal);

	// 当前视口中目标点的位置（以 UCS 坐标表示）
	acedGetVar(TEXT("TARGET"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &wcs, 0, rb.resval.rpoint);
	view.setTarget(AcGePoint3d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y], rb.resval.rpoint[Z]));

	// 当前视口的观察方向（UCS）
	acedGetVar(TEXT("VIEWDIR"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &wcs, 1, rb.resval.rpoint);
	view.setViewDirection(AcGeVector3d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y], rb.resval.rpoint[Z]));

	// 当前视口的视图高度（图形单位）
	acedGetVar(TEXT("VIEWSIZE"), &rb);
	view.setHeight(rb.resval.rreal);
	double height = rb.resval.rreal;

	// 以像素为单位的当前视口的大小（X 和 Y 值）
	acedGetVar(TEXT("SCREENSIZE"), &rb);
	view.setWidth(rb.resval.rpoint[X] / rb.resval.rpoint[Y] * height);

	// 当前视口的视图扭转角
	acedGetVar(TEXT("VIEWTWIST"), &rb);
	view.setViewTwist(rb.resval.rreal);

	// 将模型选项卡或最后一个布局选项卡置为当前
	acedGetVar(TEXT("TILEMODE"), &rb);
	int tileMode = rb.resval.rint;
	// 设置当前视口的标识码
	acedGetVar(TEXT("CVPORT"), &rb);
	int cvport = rb.resval.rint;

	// 是否是模型空间的视图
	bool paperspace = ((tileMode == 0) && (cvport == 1)) ? true : false;
	view.setIsPaperspaceView(paperspace);

	if (!paperspace)
	{
		// 当前视口中前向剪裁平面到目标平面的偏移量
		acedGetVar(TEXT("FRONTZ"), &rb);
		view.setFrontClipDistance(rb.resval.rreal);

		// 获得当前视口后向剪裁平面到目标平面的偏移值
		acedGetVar(TEXT("BACKZ"), &rb);
		view.setBackClipDistance(rb.resval.rreal);
	}
	else
	{
		view.setFrontClipDistance(0.0);
		view.setBackClipDistance(0.0);
	}
}

void PhdView::SetViewExtent(const AcGePoint3d &ptMin, const AcGePoint3d &ptMax, double scale /*= 1.0*/)
{
	AcDbViewTableRecord view;
	GetCurrentView(view);

	// 将参数的两个点从世界坐标系转换到显示坐标系
	AcGePoint2d ptMinDcs = PhdConver::UcsToDcsPt(PhdConver::WcsToUcsPt(ptMin));
	AcGePoint2d ptMaxDcs = PhdConver::UcsToDcsPt(PhdConver::WcsToUcsPt(ptMax));

	// 设置视图的中心点
	view.setCenterPoint(AcGePoint2d((ptMinDcs.x + ptMaxDcs.x) / 2, (ptMinDcs.y + ptMaxDcs.y) / 2));

	// 设置视图的高度和宽度
	view.setHeight(fabs(ptMinDcs.y - ptMaxDcs.y) * scale);
	view.setWidth(fabs(ptMinDcs.x - ptMaxDcs.x) * scale);

	// 将视图对象设置为当前视图
	acedSetCurrentView(&view, NULL);
}

double PhdView::GetCurViewHeight()
{
	AcDbViewTableRecord view;
	GetCurrentView(view);
	double dHeight = view.height();
	return dHeight;
}

void PhdView::GetCurViewData(double& dHeight, double& dWidth, AcGePoint2d& ptCenter)
{
	AcDbViewTableRecord view;
	GetCurrentView(view);

	dHeight = view.height();
	dWidth = view.width();
	ptCenter = view.centerPoint();
}

void PhdView::SetCurViewData(double dHeight, double dWidth, const AcGePoint2d& ptCenter)
{
	AcDbViewTableRecord view;
	GetCurrentView(view);

	// 设置视图的中心点
	view.setCenterPoint(ptCenter);

	// 设置视图的高度和宽度
	view.setHeight(fabs(dHeight));
	view.setWidth(fabs(dWidth));

	// 将视图对象设置为当前视图
	acedSetCurrentView(&view, NULL);
}

