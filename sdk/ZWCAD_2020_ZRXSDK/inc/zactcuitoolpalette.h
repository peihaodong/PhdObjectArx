

#ifndef __ZCTCUITOOLPALETTE_H__
#define __ZCTCUITOOLPALETTE_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zAcTcUi.h"
#include "zaduiPalette.h"
#include "zAcTcUiPaletteView.h"

class CZcTcUiImpToolPalette;
class ZcTcUiSystemInternals;
class CZcTcUiScheme;

#ifdef _ZSOFT_WINDOWS_
class ZCTCUI_PORT CZcTcUiToolPalette : public CZdUiPalette
{
    friend CZcTcUiImpToolPalette;

    DECLARE_DYNCREATE(CZcTcUiToolPalette);

public:
    CZcTcUiToolPalette();
    virtual ~CZcTcUiToolPalette();
    
    CZcTcUiPaletteView* GetView             (void);

public:
    
    virtual BOOL        Create              (CZdUiPaletteSet* pParent);
    BOOL                Create              (DWORD dwStyle, 
                                             LPCTSTR pszName, 
                                             CZdUiPaletteSet* pParent,
                                             DWORD dwPaletteStyle = 0);
    virtual BOOL        Load                (IUnknown* pUnk);
    virtual bool        CanFrameworkTakeFocus();
    virtual BOOL        Save                (IUnknown* pUnk);
    virtual BOOL        Import              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        Export              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        OnKillActive        (void);
    virtual BOOL        GetMinimumSize      (CSize& size);
    virtual void        OnSetActive         (void);
    virtual BOOL        NameEditValidation  (CEdit* pEdit);
    virtual BOOL        Paste               (IDataObject* pDataObject, 
                                             int iIndex = -1,
                                             ZcTcCatalogItemArray* pNewTools = NULL);
    virtual BOOL        CanPaste            (IDataObject* pDataObject);
    BOOL                SetView             (CZcTcUiPaletteView* pView);
    CZcTcUiScheme*      GetScheme           (void) const;

protected:

protected:
    
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    
    afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);
    DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;           

private:
    friend class ZcTcUiSystemInternals;
};
#endif

#endif 
