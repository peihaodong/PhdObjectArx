//
// (C) Copyright 2002 by Autodesk, Inc. 
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

// GsPreviewCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "rxdebug.h"
#include "GsMPCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// HINSTANCE hResourc = NULL;

IMPLEMENT_DYNAMIC(CGsMPCtrl, CStatic)
/////////////////////////////////////////////////////////////////////////////
// CGsPreviewCtrl

BEGIN_MESSAGE_MAP(CGsMPCtrl, CStatic)
	//{{AFX_MSG_MAP(CGsMPCtrl)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_NCHITTEST()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGsPreviewCtrl message handlers

CGsMPCtrl::CGsMPCtrl()
{
	m_pManager = NULL;
	m_pFactory = NULL;
	m_pDevice = NULL;
	m_pView = NULL;
	m_pModel = NULL;

	m_bEnablePan = true;
	m_bEnableOrbit = false;
	m_bEnableZoom = true;
	m_bPanning = false;
	m_bOrbiting = false;
	m_bZooming = false;

	m_bLbEnablePan = false;
	m_bLbEnableOrbit = false;
	m_bLbEnableZoom = false;

	m_bMouseDown = false;
	m_bMouseMoving = false;

	m_bInited = false;
	m_bCreatByCreate = false;
} 

CGsMPCtrl::~CGsMPCtrl()
{
	clearAll();
}

int CGsMPCtrl::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Initialize the control.
		Init();

	return 0;
}

void CGsMPCtrl::PreSubclassWindow()
{
	CStatic::PreSubclassWindow();

		// Initialize the control.
	if (!m_bCreatByCreate)
	{
		Init();
	}
}


void CGsMPCtrl::OnPaint() 
{
	CPaintDC dc(this); 
	//update the gs view
	if(NULL==m_pView)return;

	m_pView->invalidate(); 
	m_pView->update();
}


void CGsMPCtrl::clearAll()
{
	if (!m_bInited)
	{
		return;
	}

	m_bInited = false;
	DestroyView();
	DestroyModel();
	DestroyDevice();

	if (m_pFactory && m_pGhostModel) 
	{
		m_pFactory->deleteModel(m_pGhostModel);
		m_pGhostModel = NULL;
	}

	m_pFactory = NULL;
	m_pManager = NULL;
}

void CGsMPCtrl::Init()
{
	if (m_bInited)
	{
		return;
	}

	m_bInited = true;

	// Cursor
	CreateCursor();

	//Instantiate view, a device and a model object
	CRect rect;
	// get the AcGsManager object for a specified AutoCAD MDI Client CView
	m_pManager = acgsGetGsManager();
	RXASSERT(m_pManager);
	// get the GS class factory
	m_pFactory = m_pManager->getGSClassFactory();
	RXASSERT(m_pFactory);

	CreateDevice();	// Create a device
	CreateView();	// Create a view
	CreateModel();	// create a view

	m_pDevice->add(m_pView);

	//another model without open/close for the orbit gadget
	m_pGhostModel = m_pFactory->createModel(AcGsModel::kDirect,0,0,0);
	if(m_bEnableOrbit)
	{
		m_pView->add(&m_OrbitGadget,m_pGhostModel);
		m_OrbitGadget.setGsView(m_pView);
	}

	// 设置初始显示模式
	InitVisualStyle(m_pView);	
}

void CGsMPCtrl::EnableOrbin(bool bEnable) 
{
	m_bEnableOrbit = bEnable;
	if(m_pView)
	{
		AcGsModel * pmodel = m_pGhostModel;

		if(m_bEnableOrbit && pmodel)
		{
			m_pView->add(&m_OrbitGadget,pmodel);
			m_OrbitGadget.setGsView(m_pView);
		}
		else
		{
			m_pView->erase(&m_OrbitGadget);
			m_OrbitGadget.setGsView(NULL);
		}
	}
}

void CGsMPCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CRect rect;
	if (m_pDevice) {
		GetClientRect( &rect);
		m_pDevice->onSize(rect.Width(), rect.Height());
	}
}

BOOL CGsMPCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if (m_pView && IsEnableZoom())
	{
		if (zDelta<0)
			m_pView->zoom(0.5);
		else
			m_pView->zoom(1.5);
		Invalidate();
	}
	return TRUE;
}

void CGsMPCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// if zooming
	if (m_bZooming)
	{
		m_bMouseDown = true;
		m_bMouseMoving = false;    
	}
	else
	{
		SetFocus();
		//start orbit
		if(IsEnableOrbin())
		{//旋转
			m_bOrbiting = true;
			SetCapture();
			//set up the proper cursor
			SetClassLongPtr(m_hWnd,GCLP_HCURSOR,(LONG)NULL);
			::SetCursor(m_hOrbitCursor);
		}
		else if( LbIsEnableZoom() )
		{//放大缩小
			m_bZooming=true;
			SetCapture();
			//set up the proper cursor
			SetClassLongPtr(m_hWnd,GCLP_HCURSOR,(LONG)NULL);
			::SetCursor(m_hZoomCursor);
			m_previouPt=point;
		}
		else if ( LbIsEnablePan() )
		{//移动
			m_bPanning=true;
			SetCapture();
			//set up the proper cursor
			SetClassLongPtr(m_hWnd,GCLP_HCURSOR,(LONG)NULL);
			::SetCursor(m_hPanCursor);
		}
	}

	//store the start point
	m_StartPt = point;
}

void CGsMPCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//end orbit
	if ( IsEnableOrbin() )
		m_bOrbiting = false;
	else if ( LbIsEnableZoom() )
       m_bZooming=false;
	else if(LbIsEnablePan())
		m_bPanning =false;
	
	::SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
	::SetCursor(m_hCrossCursor);
	ReleaseCapture();
}

void CGsMPCtrl::OnMButtonDown(UINT nFlags, CPoint point) 
{
	if(IsEnablePan())
	{
		//start pan
		m_bPanning = true;
		SetCapture();
		//set up the proper cursor
		SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
		::SetCursor(m_hPanCursor);
		//store the start point
		m_StartPt = point;
	}
}

void CGsMPCtrl::OnMButtonUp(UINT nFlags, CPoint point) 
{
	//end pan
	ReleaseCapture();
	m_bPanning = false;
	SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
	::SetCursor(m_hCrossCursor);
}

static BOOL g_bHot = FALSE;

void CGsMPCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(!(m_bPanning || m_bOrbiting || m_bZooming))
	{
		SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
		::SetCursor(m_hCrossCursor);
	}

	// is the GsView valid
	if (m_pView)
	{
		if (m_bZooming)
		{
			//计算view高度
			AcGsDCRect screen_rect;

			m_pView->getViewport(screen_rect);
			double yViewPort = screen_rect.m_max.y-screen_rect.m_min.y;

			double yDist=point.y-m_previouPt.y ;
			double nRate = abs(yDist/yViewPort);

			if ( yDist>0)
			{
				m_pView->zoom(1-nRate);
			}
			else if (yDist<0  )
			{
				m_pView->zoom(nRate+1);
			}
			m_previouPt=point;
			Invalidate();

			//}
		}
		else
		{
			if (m_bPanning)
			{
				//transform the point from device coordinates to
				//world coordinates
				AcGeVector3d pan_vec(-(point.x-m_StartPt.x),point.y-m_StartPt.y,0);
				pan_vec.transformBy(m_pView->viewingMatrix() * m_pView->worldToDeviceMatrix().inverse());
				m_pView->dolly(pan_vec);
				Invalidate();
				m_StartPt = point;
			}
			if (m_bOrbiting)
			{
				const double Half_Pi =  1.570796326795;

				AcGsDCRect view_rect;
				m_pView->getViewport (view_rect);

				int nViewportX = (view_rect.m_max.x - view_rect.m_min.x) + 1;
				int nViewportY = (view_rect.m_max.y - view_rect.m_min.y) + 1;

				int centerX = (int)(nViewportX / 2.0f + view_rect.m_min.x);
				int centerY = (int)(nViewportY / 2.0f + view_rect.m_min.y); 

				const double radius  = min (nViewportX, nViewportY) * 0.4f;

				// compute two vectors from last and new cursor positions:

				AcGeVector3d last_vector ((m_StartPt.x - centerX) / radius,
					-(m_StartPt.y - centerY) / radius,
					0.0);

				if (last_vector.lengthSqrd () > 1.0)     // outside the radius
					last_vector.normalize  ();
				else
					last_vector.z = sqrt (1.0 - last_vector.x * last_vector.x - last_vector.y * last_vector.y);

				AcGeVector3d new_vector((point.x - centerX) / radius,
					-(point.y - centerY) / radius,
					0.0);

				if (new_vector.lengthSqrd () > 1.0)     // outside the radius
					new_vector.normalize  ();
				else
					new_vector.z = sqrt (1.0 - new_vector.x * new_vector.x - new_vector.y * new_vector.y);

				// determine angles for proper sequence of camera manipulations:

				AcGeVector3d    rotation_vector (last_vector);
				rotation_vector = rotation_vector.crossProduct (new_vector);  // rotation_vector = last_vector x new_vector

				AcGeVector3d    work_vector (rotation_vector);
				work_vector.z = 0.0f;                      // projection of rotation_vector onto xy plane

				double          roll_angle      = atan2 (work_vector.x, 
					work_vector.y);        // assuming that the camera's up vector is "up",
				// this computes the angle between the up vector 
				// and the work vector, which is the roll required
				// to make the up vector coincident with the rotation_vector

				double length = rotation_vector.length ();
				double orbit_y_angle = (length != 0.0) ? acos (rotation_vector.z / length) + Half_Pi : Half_Pi;                   // represents inverse cosine of the dot product of the
				if (length > 1.0f)                                              // rotation_vector and the up_vector divided by the
					length = 1.0f;                                              // magnitude of both vectors.  We add pi/2 because we 
				// are making the up-vector parallel to the the rotation
				double          rotation_angle  = asin (length);                // vector ... up-vector is perpin. to the eye-vector.

				// perform view manipulations

				m_pView->roll( roll_angle);               // 1: roll camera to make up vector coincident with rotation vector
				m_pView->orbit( 0.0f,  orbit_y_angle);     // 2: orbit along y to make up vector parallel with rotation vector
				m_pView->orbit( rotation_angle, 0.0f);     // 3: orbit along x by rotation angle
				m_pView->orbit( 0.0f, -orbit_y_angle);     // 4: orbit along y by the negation of 2
				m_pView->roll(-roll_angle);               // 5: roll camera by the negation of 1
				Invalidate();
				m_StartPt = point;
			}
		}
	}
}

#if _MSC_VER < 1400
UINT
#else
LRESULT
#endif
CGsMPCtrl::OnNcHitTest(CPoint point) 
{
	return HTCLIENT;
}


void CGsMPCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
	::SetCursor(m_hCrossCursor);
}

//////////////////////////////////////////////////////////////////////////
// records a temp entity and returns the total number recorded internally
int CGsMPCtrl::addTempEntity(AcEntity *ent)
{
	if(m_pView)
		m_pView->add(ent,model());
	// remember this entity
	m_TempEnts.append(ent);
	return m_TempEnts.length();
}
//////////////////////////////////////////////////////////////////////////
// frees the temporary memory, returns the total number freed
int CGsMPCtrl::freeTempEntities()
{
	int count = 0;
	int length = m_TempEnts.length();
	// loop through and free the memory
	for (int i=0; i<length; ++i)
	{
		// if ok
		if (m_TempEnts[i] != NULL)
		{
			if (m_pView)
			{
				m_pView->erase(m_TempEnts[i]);
			}

			// delete
			if (!m_TempEnts[i]->isPersistent())
			{
				delete m_TempEnts[i];
			}

			++count;
		}
	}

	m_TempEnts.setLogicalLength(0);

	return count;
}

void CGsMPCtrl::zoomExtents( const AcGePoint3d& minPoint, const AcGePoint3d& maxPoint )
{
	if(m_pView == NULL)
		return;

#if _MSC_VER > 1300
	view()->zoomExtents(minPoint,maxPoint);
#else
	AcGePoint3d pt3dCen = minPoint + (maxPoint - minPoint) / 2;
	double dX = (maxPoint.x - minPoint.x) * 1.05;
	double dY = (maxPoint.y - minPoint.y) * 1.05;
	view()->setView(pt3dCen + AcGeVector3d::kZAxis,pt3dCen,AcGeVector3d::kYAxis,dX,dY);
#endif
}

void CGsMPCtrl::CreateView()
{
	if (NULL != m_pFactory && NULL == m_pView)
	{
		m_pView = m_pFactory->createView();
		RXASSERT(m_pView);
	}
}	

void CGsMPCtrl::CreateCursor()
{
	HMODULE hRes = _hdllInstance;

	//Load our special cursors
// 	m_hPanCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDI_PAN));
// 	m_hCrossCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDI_CROSS));
// 	m_hOrbitCursor = LoadCursor(hRes,MAKEINTRESOURCE(IDI_ORBIT));
// 	m_hZoomCursor   = LoadCursor(hRes,MAKEINTRESOURCE(IDI_ZOOM));
	SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG)NULL);
}

void CGsMPCtrl::CreateDevice()
{
	if (NULL != m_pManager && NULL == m_pDevice)
	{
		m_pDevice = m_pManager->createAutoCADDevice(m_hWnd);
		RXASSERT(m_pDevice);

		CRect rect;
		// get the size of the window that we are going to draw in
		GetClientRect( &rect);
		// make sure the gs device knows how big the window is
		m_pDevice->onSize(rect.Width(), rect.Height());   
	}
}

void CGsMPCtrl::CreateModel()
{
	if (NULL != m_pManager && NULL == m_pModel)
	{
		m_pModel = m_pManager->createAutoCADModel();
		RXASSERT(m_pModel);
	}
}

void CGsMPCtrl::DestroyView()
{
	if (m_pView)  
	{
		m_pView->eraseAll();
	}

	if (m_pDevice)    
	{
		bool b = m_pDevice->erase(m_pView);
		RXASSERT(b);
	}

	if (m_pFactory)    
	{
		if (m_pView)  
		{
			// free all of our temporary entities
			freeTempEntities();

			m_pFactory->deleteView(m_pView);
			m_pView = NULL;
		}
	}
}

void CGsMPCtrl::DestroyDevice()
{
	if (m_pManager)    
	{
		if (m_pDevice)    
		{
			m_pManager->destroyAutoCADDevice(m_pDevice);
			m_pDevice = NULL;
		}
	}    
}

void CGsMPCtrl::DestroyModel()
{
	if (m_pManager)    
	{
		if (m_pModel) 
		{
			m_pManager->destroyAutoCADModel(m_pModel);
			m_pModel = NULL;
		}
	}    
}

void CGsMPCtrl::InitVisualStyle( AcGsView* pGsView )
{
	ASSERT(NULL != pGsView);

#if defined(ARX) && ARX < 17
	// get the owner dictionary entry, to find out the name of the visual style
	AcDbDictionaryPointer visualStyleDict(curDoc()->database()->visualStyleDictionaryId(), AcDb::kForRead);
	// if ok
	if (visualStyleDict.openStatus() == Acad::eOk)
	{
		AcDbVisualStyle *pVisualStyleObj;
		// Get the visual style
		Acad::ErrorStatus es = visualStyleDict->getAt(kszVS3DWireframe, (AcDbObject *&)pVisualStyleObj, AcDb::kForRead);
		// if ok
		if (es == Acad::eOk) 
		{
			// Get the visual style's object ID
			AcDbObjectId visualStyleId = pVisualStyleObj->objectId();
			pVisualStyleObj->close();
			pGsView->setVisualStyle(visualStyleId);
		}
	}

#endif

}

void CGsMPCtrl::OnDestroy()
{
	clearAll();
	CStatic::OnDestroy();
}

BOOL CGsMPCtrl::PreCreateWindow( CREATESTRUCT& cs )
{
	if (!CStatic::PreCreateWindow(cs))
	{
		return FALSE;
	}

	m_bCreatByCreate = true;
	return TRUE;
}

void CGsMPCtrl::RefreshView( )
{
	if (m_pView != NULL)
	{
		m_pView->invalidate();
		m_pView->update();
	}
}
