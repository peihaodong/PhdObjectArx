/********************************************************************
描 述： 用来预览DWG图形的控件
*********************************************************************/
#ifndef _FC_GS_PREVIEW_CTRL_H__
#define _FC_GS_PREVIEW_CTRL_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "acgi.h"
#include <math.h>
#include "gs.h"
#include "acgs.h"
#include "acgsmanager.h"
#include <zdbxEntryPoint.h>
#define GCL_HCURSOR         (-12)

namespace Phd{

// 用来预览DWG图形的控件
class PHD_OBJECTARX_API CArxPreviewCtrl : public CStatic
{
public:
	//设置自定义预览
	void SetCustomPreview(double dScreenWidth, double dPixelWidth, double dPixelLength);
	//设置背景颜色索引
	inline void SetBackgroundColorIndex(int nColorIndex){
		m_nBackgroundColorIndex = nColorIndex;
	}

private:
	bool m_bCustomPreView;	
	double m_dPixelWidth;	//像素宽度
	double m_dPixelLength;	//像素长度
	double m_dDensity;		//密度

	int m_nBackgroundColorIndex;	//背景颜色索引

public:
	CArxPreviewCtrl();
	virtual ~CArxPreviewCtrl();

public:
	//函数功能:传入dwg文件即可预览
	BOOL Init(LPCTSTR szDwgFile, CString strBlkTblRcd = ACDB_MODEL_SPACE);
	//函数功能:传入数据库指针即可预览数据库中的实体
	BOOL Init(AcDbDatabase *pDb, CString strBlkTblRcd=ACDB_MODEL_SPACE);
	// 缩放到整个图纸可见
	void ZoomE();

	void Clear();

	void EraseAll();

	//************************************
	// Summary:  得到当前dwg图纸路径
	// Parameter:
	// Return:   
	// Notice:   
	// Update Time: 2020-10-21 17:51:37
	//************************************
	inline CString GetCurDwgPath() const {
		return m_strCurDwgPath;
	}

private:
	bool m_bNewself;	//自己创建的数据库

protected:
	void InitGS(HINSTANCE hRes); // 初始化图形系统
	BOOL InitInner(AcDbDatabase *pDb, CString strBlkTblRcd= ACDB_MODEL_SPACE); // 内部初始化
	bool GetActiveViewPortInfo (ads_real &height, ads_real &width, AcGePoint3d &target, 
		AcGeVector3d &viewDir, ads_real &viewTwist, bool getViewCenter);
	//获得块中的所有实体
	void GetAllEnt(const AcDbObjectId& idBlockRec, AcDbObjectIdArray& IDArray);
	//获得实体的范围
	Acad::ErrorStatus GetEntExtents(const AcDbObjectId& idEnt, AcDbExtents& extents);
	void GetEntExtents(const AcDbObjectIdArray& aridEnt, AcDbExtents& extents);
	void Mid(const AcGePoint3d& pt1, const AcGePoint3d& pt2, AcGePoint3d& ptMid); 
protected:
	//{{AFX_MSG(CPreviewCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()

private:
	AcDbExtents m_extents; // 图纸范围 
	HCURSOR m_hPanCursor; // 移动时的图标
	HCURSOR m_hCrossCursor; // 十字图标
	HCURSOR m_hOrbitCursor; // 旋转图标
	AcGsView *m_pView; // 图形系统中的视图，用来绘制图形的区域
	AcGsDevice *m_pDevice; // 图形系统中的设备，
	AcGsModel *m_pModel;

	bool m_bPanning; // 是否处于移动图形状态
	bool m_bOrbiting; // 是否处于旋转图形状态
	AcDbDatabase* m_pDb; // 该预览空间绑定的数据库 
	CPoint m_StartPt; // 移动或旋转时的起点

private:
	CString m_strCurDwgPath;	//当前显示的图纸路径

};

}

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(_FC_GS_PREVIEW_CTRL_H__)
