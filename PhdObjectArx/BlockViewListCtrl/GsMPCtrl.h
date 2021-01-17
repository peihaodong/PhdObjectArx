//
// (C) Copyright 2002-2006 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

#if !defined(AFX_GSMPCTRL_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_)
#define AFX_GSMPCTRL_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GsMPCtrl.h : header file
//
#include "acgi.h"
#include <math.h>
#include "gs.h"
#include "AcadVistualDeclare.h"

#pragma warning(disable: 4275)

class OrbitGadgetZ : public AcGiDrawable
{
	AcGsNode* m_pNode;
	AcGsView* m_pAcGsView;
	bool m_isShowOrbit;//显示旋转的参照物
public:

	OrbitGadgetZ():m_pNode(NULL),m_isShowOrbit(false) {}
	void setGsView(AcGsView* pView) {m_pAcGsView=pView;}

public:

	_setAttributes;
	virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits * traits)
	{
		traits->setTrueColor(AcCmEntityColor(0, 200, 0));
		return kDrawableNone;
	}

	_worldDraw;
	virtual Adesk::Boolean  subWorldDraw (AcGiWorldDraw * wd)
	{
		return Adesk::kFalse;
	}

	_viewportDraw;
	virtual void            subViewportDraw    (AcGiViewportDraw * pViewportDraw)
	{
		AcGsDCRect view_rect;
		m_pAcGsView->getViewport (view_rect);

		int nViewportX = (view_rect.m_max.x - view_rect.m_min.x) + 1;
		int nViewportY = (view_rect.m_max.y - view_rect.m_min.y) + 1;
		AcGeMatrix3d scale = m_pAcGsView->viewingMatrix() * m_pAcGsView->worldToDeviceMatrix().inverse();
		AcGeVector3d viewDir = m_pAcGsView->target()-m_pAcGsView->position();
		const double radius  = min (nViewportX, nViewportY) * 0.4f*scale.scale();
		if ( m_isShowOrbit)
		{
			pViewportDraw->geometry().circle(m_pAcGsView->target(),radius,viewDir);
		}
		return;
	}

public:
	virtual Adesk::Boolean  isPersistent    (void) const
	{ 
		return Adesk::kFalse;
	};                 
	virtual AcDbObjectId    id              (void) const
	{
		return AcDbObjectId::kNull;
	}
	virtual void            setGsNode       (AcGsNode * gsnode)
	{
		m_pNode = gsnode;
	}
	virtual AcGsNode*       gsNode          (void) const
	{
		return m_pNode;
	}
	void EnableShowOrbit(bool bIsShowOrbit)
	{
		m_isShowOrbit = bIsShowOrbit;
	}
};

#define AcEntity AcDbObject
/////////////////////////////////////////////////////////////////////////////
// CGsMPCtrl window

class   CGsMPCtrl : public CStatic
{
	DECLARE_DYNAMIC(CGsMPCtrl)
public:
	CGsMPCtrl();
	virtual ~CGsMPCtrl();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   动作控制
	void EnablePan(bool bEnable) {m_bEnablePan = bEnable;};
	void EnableOrbin(bool bEnable) ;
	void EnableZoom(bool bEnable) {m_bEnableZoom = bEnable;};
	bool IsEnablePan() {return  m_bEnablePan;};
	bool IsEnableOrbin() {return  m_bEnableOrbit;};
	bool IsEnableZoom() {return  m_bEnableZoom;};

	//左键是否是pan模式
	void LbEnablePan(bool bLbEnable) {m_bLbEnablePan = bLbEnable;}

	//左键是否是zoom模式
	void LbEnableZoom(bool bLbEnable) {m_bLbEnableZoom = bLbEnable;}

	bool LbIsEnablePan(){return m_bLbEnablePan;}
	//bool LbIsEnableOrbin(){return m_bLbEnableOrbit;}
	bool LbIsEnableZoom(){return m_bLbEnableZoom;}

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   缩放范围
	void zoomExtents(const AcGePoint3d& minPoint, const AcGePoint3d& maxPoint);
	void RefreshView( );

	AcGsView*   view()      { return m_pView; }
	AcGsDevice* device()    { return m_pDevice; }
	AcGsModel*  model()     { return m_pModel; }

protected:
	bool IsInited() const {return m_bInited;}
	void clearAll();
	void Init();
	void InitVisualStyle(AcGsView* pGsView);

	virtual void CreateCursor();
	virtual void CreateView();
	virtual void CreateDevice();
	virtual void CreateModel();
	virtual void DestroyView();
	virtual void DestroyDevice();
	virtual void DestroyModel();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGsMPCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);

#if _MSC_VER < 1400
	afx_msg UINT OnNcHitTest(CPoint point);
#else
	afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	AcGsManager         *m_pManager;
	AcGsClassFactory    *m_pFactory;
	AcGsDevice          *m_pDevice;
	AcGsView            *m_pView;
	AcGsModel           *m_pModel;
	AcGsModel           *m_pGhostModel;
	OrbitGadgetZ         m_OrbitGadget;

private:
	HCURSOR m_hPanCursor;
	HCURSOR m_hCrossCursor;
	HCURSOR m_hOrbitCursor;
	HCURSOR m_hZoomCursor;

	bool m_bEnablePan;
	bool m_bEnableOrbit;
	bool m_bEnableZoom;

	bool m_bLbEnablePan;
	bool m_bLbEnableOrbit;
	bool m_bLbEnableZoom;

	bool m_bPanning;
	bool m_bOrbiting;
	bool m_bZooming;

	// zooming functionality
	bool m_bMouseDown;
	bool m_bMouseMoving;

	CPoint m_StartPt;
	CPoint m_EndPt; 
	CPoint m_previouPt;

	bool m_bInited;

	bool m_bCreatByCreate;	// 标记是被Create还是使用DDX创建

public:
	// functions for adding and freeing temporary entities, these are entities that exist in the AcGsView but 
	// don't exist in the AcDbDatabase
	// records a temp entity and returns the total number recorded internally
	int addTempEntity(AcEntity *ent);
	// frees the temporary memory, returns the total number freed
	int freeTempEntities();
protected:
	AcArray<AcEntity *> m_TempEnts;
};

#pragma warning(default: 4275)

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GSMPCTRL_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_)