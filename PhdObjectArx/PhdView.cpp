#include "StdAfx.h"
#include "PhdView.h"
#include "PhdConver.h"


void PhdView::GetCurrentView(AcDbViewTableRecord &view)
{
	struct resbuf rb;
	struct resbuf wcs, ucs, dcs;	// ת������ʱʹ�õ�����ϵͳ���

	wcs.restype = RTSHORT;
	wcs.resval.rint = 0;
	ucs.restype = RTSHORT;
	ucs.resval.rint = 1;
	dcs.restype = RTSHORT;
	dcs.resval.rint = 2;

	// ��õ�ǰ�ӿڵ�"�鿴"ģʽ
	acedGetVar(TEXT("VIEWMODE"), &rb);
	view.setPerspectiveEnabled((rb.resval.rint & 1) != 0);
	view.setFrontClipEnabled((rb.resval.rint & 2) != 0);
	view.setBackClipEnabled((rb.resval.rint & 4) != 0);
	view.setFrontClipAtEye((rb.resval.rint & 16) == 0);

	// ��ǰ�ӿ�����ͼ�����ĵ㣨UCS���꣩
	acedGetVar(TEXT("VIEWCTR"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &dcs, 0, rb.resval.rpoint);
	view.setCenterPoint(AcGePoint2d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y]));

	// ��ǰ�ӿ�͸��ͼ�еľ�ͷ���೤�ȣ���λΪ���ף�
	acedGetVar(TEXT("LENSLENGTH"), &rb);
	view.setLensLength(rb.resval.rreal);

	// ��ǰ�ӿ���Ŀ����λ�ã��� UCS �����ʾ��
	acedGetVar(TEXT("TARGET"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &wcs, 0, rb.resval.rpoint);
	view.setTarget(AcGePoint3d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y], rb.resval.rpoint[Z]));

	// ��ǰ�ӿڵĹ۲췽��UCS��
	acedGetVar(TEXT("VIEWDIR"), &rb);
	acedTrans(rb.resval.rpoint, &ucs, &wcs, 1, rb.resval.rpoint);
	view.setViewDirection(AcGeVector3d(rb.resval.rpoint[X],
		rb.resval.rpoint[Y], rb.resval.rpoint[Z]));

	// ��ǰ�ӿڵ���ͼ�߶ȣ�ͼ�ε�λ��
	acedGetVar(TEXT("VIEWSIZE"), &rb);
	view.setHeight(rb.resval.rreal);
	double height = rb.resval.rreal;

	// ������Ϊ��λ�ĵ�ǰ�ӿڵĴ�С��X �� Y ֵ��
	acedGetVar(TEXT("SCREENSIZE"), &rb);
	view.setWidth(rb.resval.rpoint[X] / rb.resval.rpoint[Y] * height);

	// ��ǰ�ӿڵ���ͼŤת��
	acedGetVar(TEXT("VIEWTWIST"), &rb);
	view.setViewTwist(rb.resval.rreal);

	// ��ģ��ѡ������һ������ѡ���Ϊ��ǰ
	acedGetVar(TEXT("TILEMODE"), &rb);
	int tileMode = rb.resval.rint;
	// ���õ�ǰ�ӿڵı�ʶ��
	acedGetVar(TEXT("CVPORT"), &rb);
	int cvport = rb.resval.rint;

	// �Ƿ���ģ�Ϳռ����ͼ
	bool paperspace = ((tileMode == 0) && (cvport == 1)) ? true : false;
	view.setIsPaperspaceView(paperspace);

	if (!paperspace)
	{
		// ��ǰ�ӿ���ǰ�����ƽ�浽Ŀ��ƽ���ƫ����
		acedGetVar(TEXT("FRONTZ"), &rb);
		view.setFrontClipDistance(rb.resval.rreal);

		// ��õ�ǰ�ӿں������ƽ�浽Ŀ��ƽ���ƫ��ֵ
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

	// �����������������������ϵת������ʾ����ϵ
	AcGePoint2d ptMinDcs = PhdConver::UcsToDcsPt(PhdConver::WcsToUcsPt(ptMin));
	AcGePoint2d ptMaxDcs = PhdConver::UcsToDcsPt(PhdConver::WcsToUcsPt(ptMax));

	// ������ͼ�����ĵ�
	view.setCenterPoint(AcGePoint2d((ptMinDcs.x + ptMaxDcs.x) / 2, (ptMinDcs.y + ptMaxDcs.y) / 2));

	// ������ͼ�ĸ߶ȺͿ��
	view.setHeight(fabs(ptMinDcs.y - ptMaxDcs.y) * scale);
	view.setWidth(fabs(ptMinDcs.x - ptMaxDcs.x) * scale);

	// ����ͼ��������Ϊ��ǰ��ͼ
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

	// ������ͼ�����ĵ�
	view.setCenterPoint(ptCenter);

	// ������ͼ�ĸ߶ȺͿ��
	view.setHeight(fabs(dHeight));
	view.setWidth(fabs(dWidth));

	// ����ͼ��������Ϊ��ǰ��ͼ
	acedSetCurrentView(&view, NULL);
}

