

#ifndef __ZCTCUITOOLPALETTESET_H__
#define __ZCTCUITOOLPALETTESET_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zAcTcUi.h"
#include "zaduiPaletteSet.h"
#include "zAcTcUiToolPalette.h"
#include "zAcTcUiToolPaletteGroup.h"

class CZcTcUiImpToolPaletteSet;
class CZcTcUiScheme;

#ifdef _ZSOFT_WINDOWS_
class ZCTCUI_PORT CZcTcUiToolPaletteSet : public CZdUiPaletteSet
{
    friend CZcTcUiImpToolPaletteSet;

    DECLARE_DYNCREATE(CZcTcUiToolPaletteSet);

public:
    virtual ~CZcTcUiToolPaletteSet();

    virtual BOOL        Load                (IUnknown* pUnk);
    virtual BOOL        Save                (IUnknown* pUnk);
    virtual BOOL        Import              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        Export              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        HitTest             (CPoint pt, UINT& nFlag, 
                                             DWORD& dwData);
    int                 AddPalette          (CZdUiPalette* pPalette);
    int                 InsertPalette       (int iIndex, CZdUiPalette* pPalette);
    BOOL			    RemovePalette		(CZdUiPalette* pPalette);
    BOOL			    RemovePalette		(int iIndex);
    virtual void        TitleBarLocationUpdated(ZdUiTitleBarLocation newLoc);
    CZcTcUiToolPaletteGroup* GetToolPaletteGroup(BOOL bCreate = FALSE);
    CZcTcUiToolPaletteGroup* GetAllPalettesGroup(void);
    CZcTcUiToolPaletteGroup* GetActivePaletteGroup(void);
    BOOL                GetActivePaletteGroup(LPTSTR pszGroup,
                                              int cbSize) const;
    BOOL			    SetActivePaletteGroup(CZcTcUiToolPaletteGroup* pGroup);
    BOOL                SetActivePaletteGroup(LPCTSTR pszGroup);
    CZcTcUiScheme*      GetScheme           (void) const;
    BOOL                Show                (void);
    BOOL                Show                (BOOL bShow);
    BOOL                SetActivePalette    (CZdUiPalette* pPalette);
    BOOL                SetActivePalette    (int nPaletteIndex);
    BOOL                SetActivePalette    (LPCTSTR pszPalName,
                                             BOOL bSearchOnlyCurrentGroup) const;
    CZcTcUiToolPalette* FindPalette         (LPCTSTR pszPalName,
                                             CZcTcUiToolPaletteGroup** ppGroup,
                                             BOOL bSearchOnlyCurrentGroup) const;

protected:
    
    CZcTcUiToolPaletteSet();

protected:
    virtual BOOL        AddContextMenuItems (CMenu *pMenu, 
                                             int nHitFlag,
                                             int nRightClkTab = 0);
    virtual void        ThemeModified       (ZdUiThemeElement element);
    virtual void        OnTabDrag           (CPtrArray & arrayPalettes);
    virtual BOOL        OnBeginDrag         (COleDataSource* pDataSource,
                                             CPtrArray & arrayPalettes);
    virtual void        OnEndDrag           (DROPEFFECT dropEffect);
    virtual BOOL        OnBeginMove         (COleDataSource* pDataSource,
                                             CPtrArray & arrayPalettes);
    virtual void        OnEndMove           (DROPEFFECT dropEffect);
    virtual BOOL        OnRenderData        (LPFORMATETC lpFormatEtc,
                                             LPSTGMEDIUM lpStgMedium);
    virtual void        OnTearOff           (CZdUiPaletteSet* pSet);
    virtual void        DestroyStackedPaletteSet(void);

	virtual void		GetMinimumSize(CSize& size); // Added by ZWSOFT HePing 2018/08/16 for fix ZWCAD E2 14032: 调整工具选项板长度时，工具选项板会自动变长一小段。解决方案：调整最小尺寸以免PaletteSet窗口因初始尺寸过小首次OnSize时跳跃。

protected:
    
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
    afx_msg void OnRemovePaletteSet();
    afx_msg void OnRemoveActivePalette();
    afx_msg void OnRemovePalette();
    afx_msg void OnViewOptions();
    afx_msg void OnSelectPaletteGroup( UINT nID );
    afx_msg void OnShowCustomizeDialog();
    afx_msg void OnShowCustomizeDialogCUI();
    afx_msg void OnNewPalette();
    afx_msg void OnPaste();
    afx_msg void OnPaletteProperties();
    afx_msg void OnRefreshPaletteSet();
    afx_msg void OnRefreshActivePalette();
    afx_msg void OnClose();
    afx_msg void OnMoveUp();
    afx_msg void OnMoveDown();
    afx_msg void OnInvokeCommand(UINT nID);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:

    afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRenderData(WPARAM wParam, LPARAM lParam);
    DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;           

private:
    friend class ZcTcUiSystemInternals;

};
#endif

#endif 
