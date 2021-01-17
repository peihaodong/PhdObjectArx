#include "StdAfx.h"
#include "GraphBlockViewWnd.h"
#include "rxdebug.h"


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
//
// GsPreviewCtrl.cpp : implementation file
//

 

/////////////////////////////////////////////////////////////////////////////
// CGraphBlockViewWnd
IMPLEMENT_DYNAMIC(CGraphBlockViewWnd, CGsMPCtrl)

CGraphBlockViewWnd::CGraphBlockViewWnd() 
{
	m_vectViewDir = AcGeVector3d(0,0,1);
	m_bCustomView = false;

	m_pDraw = NULL;
	EnablePan(false);
	EnableOrbin(false);
	EnableZoom(false);
} 

CGraphBlockViewWnd::~CGraphBlockViewWnd() 
{
	clearAll();
	ResetDraw(NULL);
}



BEGIN_MESSAGE_MAP(CGraphBlockViewWnd, CGsMPCtrl)
	//{{AFX_MSG_MAP(CGraphBlockViewWnd)
 	ON_WM_MBUTTONDBLCLK() 
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphBlockViewWnd message handlers
// 

void CGraphBlockViewWnd::OnMButtonDblClk(UINT nFlags, CPoint point) 
{
	zoomExtents(m_extentsMax.minPoint(),m_extentsMax.maxPoint());
	RefreshView( );
}

void CGraphBlockViewWnd::SetViewTo(AcDbExtents ext, AcGeMatrix3d& viewMat)
{
	m_extentsMax = ext;
	// we are going to set the view to the current view of the drawing
	// The overall approach is to calculate the extents of the database in the coordinate system of the view
 	AcGePoint3d extMax ;
	AcGePoint3d extMin ;
	// Calculate the extents in WCS
	extMax = ext.maxPoint();
	extMin = ext.minPoint();

	double dReduceDist = extMax.x-extMin.x;
	dReduceDist /= 10;
	double dTemp = extMin.x;
	dTemp -= dReduceDist;
	extMin.x = dTemp;
	dTemp = extMin.y;
	dTemp -= dReduceDist;
	extMin.y = dTemp;
// 	extMin.x -= dReduceDist;
// 	extMin.y -= dReduceDist;
 	extMax.x += dReduceDist;
	extMax.y += dReduceDist;

	// get the view port information - see parameter list
	AcGeVector3d viewDir(0,0,1);
	viewDir = m_vectViewDir;
 
	// we are only interested in the directions of the view, not the sizes, so we normalise. 
	viewDir = viewDir.normal();

	//**********************************************
	// Our view coordinate space consists of z direction 
	// get a perp vector off the z direction
	// Make sure its normalised
	AcGeVector3d viewXDir = viewDir.perpVector ().normal();
	// correct the x angle by applying the twist
	viewXDir = viewXDir.rotateBy (0, -viewDir);
	// now we can work out y, this is of course perp to the x and z directions. No need to normalise this, 
	// as we know that x and z are of unit length, and perpendicular, so their cross product must be on unit length
	AcGeVector3d viewYDir = viewDir.crossProduct (viewXDir);

	// find a nice point around which to transform the view. We'll use the same point as the center of the view.
	AcGePoint3d boxCenter = extMin + 0.5 * ( extMax - extMin );

	//**********************************************
	// create a transform from WCS to View space
	// this represents the transformation from WCS to the view space. (Actually not quite since 
	// we are keeping the fixed point as the center of the box for convenience )
	viewMat = AcGeMatrix3d::alignCoordSys (boxCenter, AcGeVector3d::kXAxis, AcGeVector3d::kYAxis, AcGeVector3d::kZAxis,  
		boxCenter, viewXDir, viewYDir, viewDir).inverse();

	AcDbExtents wcsExtents(extMin, extMax);
	// now we have the view Extents
	AcDbExtents viewExtents = wcsExtents;
	// transforms the extents in WCS->view space
	viewExtents.transformBy (viewMat);

	//**********************************************
	// get the extents of the AutoCAD view
	double xMax = fabs(viewExtents.maxPoint ().x - viewExtents.minPoint ().x);
	double yMax = fabs(viewExtents.maxPoint ().y - viewExtents.minPoint ().y);

	//**********************************************
	// setup the view
	AcGePoint3d eye = boxCenter + viewDir;

	// upvector				
	m_pView->setView(eye, boxCenter, viewYDir, xMax, yMax);
	// update the gsView
}

BOOL CGraphBlockViewWnd::InitRect(UINT staticId, CWnd* pParent)
{
	if (!SubclassDlgItem(staticId,pParent))
		return FALSE;

	return TRUE;
}

//设置模型空间模式
void CGraphBlockViewWnd::SetModelSpace()
{
	AcColorSettings colourSettings; 
	// get the AutoCAD current colour settings
	acedGetCurrentColors(&colourSettings); 	
	DWORD colorDW; 
	// get the background colour
	colorDW = colourSettings.dwGfxModelBkColor; 
	// get the current device background colour	
	AcGsColor color = m_pDevice->getBackgroundColor();
	// now update them to the new color
	color.m_red   = GetRValue(colorDW);
	color.m_green = GetGValue(colorDW);
	color.m_blue  = GetBValue(colorDW);
	color.m_filler = 255; // opaque background
	// finally lets set the new colour   
	m_pDevice->setBackgroundColor(color);

	// now remap the colours back to the default
	//m_pDevice->setLogicalPalette (MyAcadColorMs, 256);
	// update the gsView
	RefreshView();

}
//设置图纸空间模式
void CGraphBlockViewWnd::SetPaperSpace()
{
	// setup the backgroud colour to the same as Pspace
	//
	AcColorSettings colourSettings; 
	// get the AutoCAD current colour settings
	acedGetCurrentColors(&colourSettings); 	
	DWORD colorDW; 
	// get the background colour
	colorDW = colourSettings.dwGfxLayoutBkColor;
	// get the current device background colour	
	AcGsColor color = m_pDevice->getBackgroundColor();
	// now update them to the new color
	color.m_red   = GetRValue(colorDW);
	color.m_green = GetGValue(colorDW);
	color.m_blue  = GetBValue(colorDW);
	color.m_filler = 255; // opaque background
	// finally lets set the new colour   
	m_pDevice->setBackgroundColor(color);

	// now remap the colours, so that on a white background, white lines appear red
	//m_pDevice->setLogicalPalette (MyAcadColorPs, 256);
	// update the gsView
	RefreshView();

}


//设置渲染模式
void CGraphBlockViewWnd::SetViewMode( int iRenderMode )
{
// 	m_nRenderMode = (AcGsView::RenderMode)iRenderMode;
 	if(m_pView)m_pView->setMode((AcGsView::RenderMode)iRenderMode);
	RefreshView();
}

//add and close

int CGraphBlockViewWnd::addTempEntity( AcDbObject *ent, bool bAutoZoom /*= true*/ )
{
	ASSERT(NULL != ent);

	int nRs = CGsMPCtrl::addTempEntity(ent);
	if (bAutoZoom)
	{
		Zoom();
	}

	RefreshView();
	return nRs;
}

void CGraphBlockViewWnd::SetReadOnly()
{
	EnablePan(false);
	EnableOrbin(false);
	EnableZoom(false);
}

void CGraphBlockViewWnd::SetViewDir(AcGeVector3d viewDir)
{
	m_vectViewDir = viewDir;
}

bool CGraphBlockViewWnd::GetExtents( AcDbExtents& ext, AcGiDrawable* pObj )
{
	ASSERT(NULL != pObj);

	if (pObj->isKindOf(AcDbEntity::desc()))
	{
		AcDbEntity::cast(pObj)->getGeomExtents(ext);
	}
	else if (pObj->isKindOf(AcDbBlockTableRecord::desc()))
	{
// 		ext.addBlockExt(AcDbBlockTableRecord::cast(pObj));
		AcDbBlockTableRecord* pRc = AcDbBlockTableRecord::cast(pObj);
		ASSERT(NULL != pRc);

		AcDbBlockTableRecordIterator* pIt = NULL;
		if (Acad::eOk != pRc->newIterator(pIt))
		{
			return false;
		}

		pIt->start();
		AcDbEntity* pEnt = NULL;
		if (Acad::eOk != pIt->getEntity(pEnt, AcDb::kForRead))
		{
			return false;
		}

		pEnt->getGeomExtents(ext);
		pEnt->close();
		pIt->step();

		for (; !pIt->done(); pIt->step())
		{
			if (Acad::eOk != pIt->getEntity(pEnt, AcDb::kForRead))
			{
				return false;
			}

			AcDbExtents tempExt;
			pEnt->getGeomExtents(tempExt);
			ext.addExt(tempExt);
			pEnt->close();
		}

	}
	else
	{
// #if _MSC_VER > 1400
// 		return pObj->bounds(ext);
// #else
		return false;
// #endif
	}

	return true;
}

void CGraphBlockViewWnd::Zoom()
{
	AcDbExtents ext;
	AcDbExtents tempExt;
	int nIndex = 0;
	for (nIndex = 0; nIndex < m_TempEnts.length(); nIndex++)
	{
		if (GetExtents(tempExt, m_TempEnts[nIndex]))
		{
			ext.addExt(tempExt);
		}
	}

	if (NULL != m_pDraw && GetExtents(tempExt, m_pDraw))
	{
		ext.addExt(tempExt);
	}

	AcGeMatrix3d matrix;
	SetViewTo(ext, matrix);
	RefreshView();
}

int CGraphBlockViewWnd::GetIndex()
{
	if (NULL == m_pCtrl)
	{
		return -1;
	}

	return m_pCtrl->GetItem(this);
}

void CGraphBlockViewWnd::CopyObjectsTo( CGraphBlockViewWnd* pOther )
{
	pOther->freeTempEntities();
	if (NULL != m_pDraw)
	{
		if (m_pDraw->isPersistent())
		{
			pOther->InitDrawable(m_pDraw);
		}
		else
		{
			pOther->InitDrawable(AcGiDrawable::cast(m_pDraw->clone()));
		}
	}

	int nLenth = m_TempEnts.length();
	for (int nIndex = 0; nIndex < nLenth; nIndex++)
	{
		pOther->addTempEntity(m_TempEnts[nIndex], false);
	}

	pOther->Zoom();
}

bool CGraphBlockViewWnd::InitBlockView( LPCTSTR szBlk, AcDbDatabase* pDb )
{
	if (NULL == pDb)
	{
		return false;
	}

	m_strBlockName = szBlk;
	AcDbBlockTableRecordPointer pBlk(szBlk, pDb, AcDb::kForRead);
	return InitDrawable(pBlk.object());
}

bool CGraphBlockViewWnd::InitDrawable( AcGiDrawable* pDraw )
{
	if (NULL == pDraw)
	{
		return false;
	}

	bool bNeedReInit = false;
	if (IsInited())
	{
		bNeedReInit = true;
		clearAll();
	}

	ResetDraw(pDraw);

	if (bNeedReInit)
	{
		Init();
		Zoom();
	}

	return true;
}

CGraphListCtrl* CGraphBlockViewWnd::GetGraphList()
{
	return m_pCtrl;
}

void CGraphBlockViewWnd::SetGraphList( CGraphListCtrl* pCtrl )
{
	m_pCtrl = pCtrl;
}

DWORD CGraphBlockViewWnd::GetData() const
{
	return m_dwData;
}

void CGraphBlockViewWnd::SetData( DWORD dwData )
{
	m_dwData = dwData;
}

void CGraphBlockViewWnd::OnDestroy()
{
	clearAll();
	ResetDraw(NULL);
	CGsMPCtrl::OnDestroy();
}

void CGraphBlockViewWnd::CreateView()
{
	if (NULL == m_pDraw)
	{
		CGsMPCtrl::CreateView();
		return;
	}

	if (NULL != m_pManager && NULL == m_pView)
	{
		m_bCustomView = true;
		m_pView = m_pManager->createAutoCADView(m_pDraw);
	}
}

void CGraphBlockViewWnd::DestroyView()
{
	if (!m_bCustomView)
	{
		CGsMPCtrl::DestroyView();
		return;
	}

	m_bCustomView = false;
	if (m_pView)  
	{
		m_pView->eraseAll();
	}

	if (m_pDevice)    
	{
		bool b = m_pDevice->erase(m_pView);
		RXASSERT(b);
	}

	if (m_pManager && m_pView)    
	{
		// free all of our temporary entities
		freeTempEntities();

		m_pManager->destroyAutoCADView(m_pView);
		m_pView = NULL;
	}
}

void CGraphBlockViewWnd::ResetDraw( AcGiDrawable* pDraw )
{
	if (NULL != m_pDraw && !m_pDraw->isPersistent())
	{
		delete m_pDraw;
		m_pDraw = NULL;
	}

	m_pDraw = pDraw;
}