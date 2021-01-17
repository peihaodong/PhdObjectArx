

#pragma once

#include "zAcTcUiCatalogView.h"

#ifdef _ZSOFT_WINDOWS_
class ZCTCUI_PORT CZcTcUiPaletteView : public CZcTcUiCatalogView  
{
public:
    CZcTcUiPaletteView();
    virtual ~CZcTcUiPaletteView();

protected:
    virtual DROPEFFECT  DragEnter           (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DragOver            (ZDUI_DRAGDATA* pDragData);
    virtual void        DragLeave           (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  Drop                (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DropEx              (ZDUI_DRAGDATA* pDragData);

protected:

protected:
    
    CZcTcUiPaletteView(ZcTcUiSystemInternals*);

protected:
    
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnInvokeCommand(UINT nID);
	afx_msg void OnPaletteRemove();
    afx_msg void OnCatalogItemSpecifyImage();
    afx_msg void OnCatalogItemRemoveImage();
    afx_msg void OnCatalogItemUpdateImage();
    
    DECLARE_MESSAGE_MAP()
};
#endif

