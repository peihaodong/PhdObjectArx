

#ifndef _ZDUI_DROP_TARGET_H_
#define _ZDUI_DROP_TARGET_H_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zadesk.h"

#define UM_ZDUI_DRAGENTER				(WM_USER + 120)
#define UM_ZDUI_DRAGOVER				(WM_USER + 121)
#define UM_ZDUI_DRAGLEAVE				(WM_USER + 122)
#define UM_ZDUI_DROP					(WM_USER + 123)
#define UM_ZDUI_DROPEX					(WM_USER + 124)
#define UM_ZDUI_DRAGSCROLL				(WM_USER + 125)

#ifdef _ZSOFT_WINDOWS_
typedef struct tagZDUI_DRAGDATA
{

	CWnd				*	mpWnd;
	COleDataObject		*	mpDataObject;
	DWORD					mdwKeyState;
	POINTL					mPoint;
	DROPEFFECT				mDropEffect;
	DROPEFFECT				mDropList;

} ZDUI_DRAGDATA,*PZDUI_DRAGDATA;

#pragma warning(push)
#pragma warning(disable : 4275)
class CZdUiDropTarget : public COleDropTarget
{
public:
    CZdUiDropTarget();

    CZdUiDropTarget(int nId);
    ~CZdUiDropTarget();
    BOOL            SetTargetWindowForMessages(CWnd* pWnd);

protected:
    virtual DROPEFFECT 	OnDragEnter			(CWnd* pWnd, 
											 COleDataObject* pDataObject, 
											 DWORD dwKeyState, 
											 CPoint point);
    virtual DROPEFFECT 	OnDragOver			(CWnd* pWnd, 
											 COleDataObject* pDataObject, 
											 DWORD dwKeyState, 
											 CPoint point);
    virtual BOOL		OnDrop				(CWnd* pWnd, 
											 COleDataObject* pDataObject, 
											 DROPEFFECT 	dropEffect, 
											 CPoint point);
    virtual DROPEFFECT 	OnDropEx			(CWnd* pWnd, 
											 COleDataObject* pDataObject, 
											 DROPEFFECT dropDefault, 
											 DROPEFFECT dropList, 
											 CPoint point);
    virtual void		OnDragLeave			(CWnd* pWnd);
    virtual DROPEFFECT  OnDragScroll	    (CWnd* pWnd,
									         DWORD dwKeyState, 
										     CPoint point);

protected:
	DWORD				mdwKeyState;
    int                 mnId;
    CWnd            *   mpTargetWnd;
};
#pragma warning(pop)
#endif

#endif 
