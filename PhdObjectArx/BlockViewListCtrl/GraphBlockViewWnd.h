#pragma once

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
#if !defined(AFX_GRAPHBLOCKVIEWWND_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_)
#define AFX_GRAPHBLOCKVIEWWND_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GsPreviewCtrl.h : header file
//
#include "acgi.h"
#include <math.h>
// Simple lighweight drawable to do orbit glyph

#include "GraphListCtrl.h"
#include "GsMPCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CGraphBlockViewWnd window
class CGraphListCtrl;

class   CGraphBlockViewWnd : public CGsMPCtrl
{
	friend class CGraphListCtrl;
	friend class CGraphButton;

	DECLARE_DYNAMIC(CGraphBlockViewWnd)
public:

	CGraphBlockViewWnd();
	virtual ~CGraphBlockViewWnd();

	void SetData(DWORD dwData);
	DWORD GetData() const;

	void SetGraphList(CGraphListCtrl* pCtrl);
	CGraphListCtrl* GetGraphList();;
 
	bool InitBlockView(LPCTSTR szBlk, AcDbDatabase* pDb);
	bool InitDrawable(AcGiDrawable* pDraw);

	CString GetBlockName(){ return m_strBlockName;}
	CString GetName(){ return m_strName;}
	void SetName(CString strName){m_strName = strName; }
	
	BOOL InitRect(UINT staticId, CWnd* pParent);
	// takes a drawing and updates the GsView with it

	//设置模型空间模式
	void SetModelSpace();
	//设置图纸空间模式
	void SetPaperSpace();

	//设置渲染模式
		//  	0，	k2DOptimized,               // Standard AutoCAD 2D Display
		// 		kBoundingBox,               // Bounding Box (when simpler than the geometry)
		// 		kWireframe,                 // Same display as k2Doptimized (but using the 3D Pipeline)
		// 		kHiddenLine,                // Wireframe display with hidden lines removed
		// 		kFlatShaded,                // Faceted - constant color per face
		// 		kGouraudShaded,             // Smooth shaded - colors interpolated between vertices
		// 		kFlatShadedWithWireframe,   // Faceted with wireframe overlayed
		// 		kGouraudShadedWithWireframe,// Smooth shaded with wireframe overlayed
		// 		kCount,
		// 		kNone = kCount
	void SetViewMode( int iRenderMode );
	void SetViewDir(AcGeVector3d viewDir);
	//add and close
	int addTempEntity(AcDbObject *ent, bool bAutoZoom = true);

	void SetReadOnly();

	int GetIndex();
	void CopyObjectsTo(CGraphBlockViewWnd* pOther);

	void Zoom();

protected:
	void SetViewTo(AcDbExtents ext, AcGeMatrix3d& viewMat);
	bool GetExtents(AcDbExtents& ext, AcGiDrawable* pObj);

	void ResetDraw(AcGiDrawable* pDraw);
	virtual void CreateView();
	virtual void DestroyView();
protected:
	//{{AFX_MSG(CGraphBlockViewWnd)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();

protected:
	AcGeVector3d m_vectViewDir;

	AcGiDrawable* m_pDraw;
	bool m_bCustomView;
	AcDbExtents m_extentsMax;
	CString m_strBlockName; //当前显示的块的名称
	CString m_strName;		//当前表示的名称，可以与块相同
	CPoint mCursorPoint;

	DWORD m_dwData;

	COLORREF m_colorBk;
 	CGraphListCtrl* m_pCtrl;

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHBLOCKVIEWWND_H__7DC11025_C827_11D2_B89C_080009DCA551__INCLUDED_)
