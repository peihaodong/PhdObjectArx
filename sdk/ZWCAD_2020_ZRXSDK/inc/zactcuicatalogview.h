
#pragma once

#include "zAcTcUi.h"
#include "zAcTcUiCatalogViewItem.h"

typedef CTypedPtrArray<CPtrArray, ZcTcCatalogItem*> ZcTcCatalogItemArray;

class ZcTcUiSystemInternals;
class CZcTcUiScheme;

#define ZCTCUI_IDW_CATALOGVIEW              0xFFFF

#define ZCTCUI_CVSTYLE_SHOWTEXT             ZCTCUI_CVISTYLE_SHOWTEXT
#define ZCTCUI_CVSTYLE_SAVE_ORDER_IN_CATALOG (0x1 << 11)
#define ZCTCUI_CVSTYLE_NO_QSL               (0x1 << 12)
#define ZCTCUI_CVSTYLE_NO_SELECTION         (0x1 << 13)
#define ZCTCUI_CVSTYLE_NO_VIEW_BUTTON       (0x1 << 14)
#define ZCTCUI_CVSTYLE_LISTVIEW             (0x1 << 15)
#define ZCTCUI_CVSTYLE_TOOLTIPS             (0x1 << 16)
#define ZCTCUI_CVSTYLE_MULTISELECT          (0x1 << 17)
#define ZCTCUI_CVSTYLE_EDITLABELS           (0x1 << 18)
#define ZCTCUI_CVSTYLE_HOVERSELECT          (0x1 << 19)
#define ZCTCUI_CVSTYLE_NO_DRAGDROP          (0x1 << 20)
#define ZCTCUI_CVSTYLE_NO_CUT               (0x1 << 21)
#define ZCTCUI_CVSTYLE_NO_COPY              (0x1 << 22)
#define ZCTCUI_CVSTYLE_NO_PASTE             (0x1 << 23)
#define ZCTCUI_CVSTYLE_NO_REFRESH           (0x1 << 24)
#define ZCTCUI_CVSTYLE_NO_REMOVE            (0x1 << 25)
#define ZCTCUI_CVSTYLE_NO_RENAME            (0x1 << 26)
#define ZCTCUI_CVSTYLE_NO_PROPERTIES        (0x1 << 27)
#define ZCTCUI_CVSTYLE_NO_HELP              (0x1 << 28)
#define ZCTCUI_CVSTYLE_NO_VIEWOPTIONS       (0x1 << 29)
#define ZCTCUI_CVSTYLE_NO_OPERATIONS        (ZCTCUI_CVSTYLE_NO_CUT        | \
                                             ZCTCUI_CVSTYLE_NO_COPY       | \
                                             ZCTCUI_CVSTYLE_NO_PASTE      | \
                                             ZCTCUI_CVSTYLE_NO_REFRESH    | \
                                             ZCTCUI_CVSTYLE_NO_REMOVE     | \
                                             ZCTCUI_CVSTYLE_NO_RENAME     | \
                                             ZCTCUI_CVSTYLE_NO_PROPERTIES | \
                                             ZCTCUI_CVSTYLE_NO_HELP       | \
                                             ZCTCUI_CVSTYLE_NO_VIEWOPTIONS)
#define ZCTCUI_CVSTYLE_NO_FLYOUT            (0x1 << 30)
#define ZCTCUI_CVSTYLE_NO_SCROLLBAR         (0x1 << 31)
#define ZCTCUI_DDO_ACCEPT_TOOL              (0x1 << 0)
#define ZCTCUI_DDO_ACCEPT_PALETTE           (0x1 << 1)
#define ZCTCUI_DDO_ACCEPT_PACKAGE           (0x1 << 2)
#define ZCTCUI_DDO_ACCEPT_CATEGORY          (0x1 << 3)
#define ZCTCUI_DDO_ACCEPT_CATALOG           (0x1 << 4)
#define ZCTCUI_DDO_ACCEPT_STOCKTOOL         (0x1 << 5)
#define ZCTCUI_DDO_ACCEPT_FILES             (0x1 << 6)
#define ZCTCUI_DDO_ACCEPT_ALL_ITEMS         (ZCTCUI_DDO_ACCEPT_TOOL     | \
                                             ZCTCUI_DDO_ACCEPT_STOCKTOOL| \
                                             ZCTCUI_DDO_ACCEPT_PALETTE  | \
                                             ZCTCUI_DDO_ACCEPT_PACKAGE  | \
                                             ZCTCUI_DDO_ACCEPT_CATEGORY | \
                                             ZCTCUI_DDO_ACCEPT_CATALOG  | \
                                             ZCTCUI_DDO_ACCEPT_FILES)
#define ZCTCUI_CVHT_NOWHERE                 (0x0)
#define ZCTCUI_CVHT_ITEM                    (0x1 << 0)
#define ZCTCUI_CVHT_ITEMIMAGE               (0x1 << 1)
#define ZCTCUI_CVHT_ITEMLABEL               (0x1 << 2)
#define ZCTCUI_CVHT_BACKGROUND              (0x1 << 3)
#define ZCTCUI_CVHT_ABOVE                   (0x1 << 4)
#define ZCTCUI_CVHT_BELOW                   (0x1 << 5)
#define ZCTCUI_CVHT_LEFT                    (0x1 << 6)
#define ZCTCUI_CVHT_RIGHT                   (0x1 << 7)
#define ZCTCUI_CVHT_ITEMTRIGGER             (0x1 << 8)
#define ZCTCUI_OVERLAY_ALIGN_TOPLEFT        1
#define ZCTCUI_OVERLAY_ALIGN_TOPRIGHT       2
#define ZCTCUI_OVERLAY_ALIGN_BOTTOMLEFT     3
#define ZCTCUI_OVERLAY_ALIGN_BOTTOMRIGHT    4

#ifdef _ZSOFT_WINDOWS_
class ZCTCUI_PORT CZcTcUiCatalogView : public CWnd  
{
    friend CZcTcUiImpCatalogView;

public:
    CZcTcUiCatalogView();
    CZcTcUiCatalogView(ZcTcCatalogItem* pCatalogItem);
    virtual ~CZcTcUiCatalogView();

    BOOL                Create              (DWORD dwWndStyle, 
                                             DWORD dwCatalogViewStyle, 
                                             const RECT& rect, 
                                             CWnd* pParent,
                                             UINT nID = ZCTCUI_IDW_CATALOGVIEW);
    ZcTcCatalogItem *   GetCatalogItem      (void) const;
    BOOL                SetCatalogItem      (ZcTcCatalogItem* pCatalogItem);
    DWORD               GetCatalogViewStyle (void) const;
    BOOL                SetCatalogViewStyle (DWORD dwStyle);
    DWORD               GetDragDropOption   (void) const;
    BOOL                SetDragDropOption   (DWORD dwOption);
    int                 GetItemCount        (void) const;
    CZcTcUiCatalogViewItem* GetItem         (int iIndex) const;
    DWORD               GetItemData         (int iIndex) const;
    BOOL                SetItemData         (int iIndex, DWORD dwData);
    BOOL                GetImageSize        (LPSIZE lpSize) const;
    BOOL                SetImageSize        (const SIZE& size);
    BOOL                Update              (BOOL bRedraw = TRUE);
    int                 GetRowsInPage       (BOOL bIncludePartialRows) const;
    int                 GetColumnsInPage    (void) const;
    BOOL                Scroll              (CSize sizeScroll);
    BOOL                EnsureVisible       (int nIndex,
                                             BOOL bPartialOk);
    BOOL                GetInsertMark       (int& nIndex, 
                                             BOOL& bAfter) const;
    BOOL                SetInsertMark       (int nIndex, 
                                             BOOL bAfter = FALSE);
    int                 GetFirstVisibleItemIndex(BOOL bPartialOk = TRUE) const;
    int                 GetLastVisibleItemIndex(BOOL bPartialOk = TRUE) const;
    CEdit           *   EditLabel           (int nIndex);
    BOOL                IsLabelEditing      (void) const;
    BOOL                EndLabelEdit        (BOOL bCancel = FALSE);
    BOOL                Load                (IUnknown* pUnk);
    BOOL                Save                (IUnknown* pUnk);
    BOOL                SelectItem          (int nIndex, 
                                             BOOL bSelect = TRUE);
    BOOL                SelectItemRange     (int nStartIndex, 
                                             int nEndIndex, 
                                             BOOL bSelect = TRUE);
    int                 GetSelectedCount    (void) const;
    CZcTcUiCatalogViewItem* GetSelectedItem(void) const;
    POSITION            GetFirstSelectedItemPosition(void) const;
    CZcTcUiCatalogViewItem* GetNextSelectedItem(POSITION& pos) const;
    BOOL                GetItemRect         (int iIndex, LPRECT lpRect, int nCode) const;
    CZcTcUiCatalogViewItem* GetItemFromPoint(const CPoint& pt);
    BOOL                GetViewRect         (LPRECT lpRect) const;
    int                 GetItemIndex        (CZcTcUiCatalogViewItem* pItem) const;
    int                 HitTest             (const CPoint& pt, 
                                             UINT* pHitFlags) const;
    CZcTcUiCatalogViewItem * GetCurrentItem (void) const;
    virtual BOOL        GetMinimumSize      (CSize& size);
    virtual BOOL        PreTranslateMessage (MSG* pMsg);
    virtual BOOL        Copy                (const CZcTcUiCatalogViewItemArray& itemsCopied,
                                             IDataObject* pDataObject);
    virtual BOOL        Paste               (IDataObject* pDataObject, 
                                             int iIndex = -1,
                                             ZcTcCatalogItemArray* pNewTools = NULL);
    virtual BOOL        CanPaste            (IDataObject* pDataObject);
    BOOL                GetOverlayImageSize (LPSIZE lpSize) const;
    BOOL                SetOverlayImageSize (const SIZE& size);
    int                 GetOverlayImageAlignment(void) const;
    BOOL                SetOverlayImageAlignment(int nAlignment);
    BOOL                GetItemOrder        (ZcTcCatalogItemArray& items) const;
    BOOL                SetItemOrder        (const ZcTcCatalogItemArray& items);
    BOOL                ResetItemOrder      (void);
    CZcTcUiScheme*      GetScheme           (void) const;
    BOOL                Sort                (int nSortOption);

protected:
    
    virtual void        OnLButtonClicked    (UINT nFlags, 
                                             CPoint point);
    virtual void        OnLButtonDblClicked (UINT nFlags, 
                                             CPoint point);
    virtual BOOL        AddContextMenuItems (CMenu *pMenu, 
                                             int nHitFlag);
    virtual void        OnItemCopy          (void);
    virtual void        OnItemCut           (void);
    virtual void        OnItemPaste         (void);
    virtual void        OnItemRemove        (void);
    virtual void        OnItemRename        (void);
    virtual void        OnItemRefresh       (void);
    virtual void        OnItemProperties    (void);
    virtual void        OnItemInstallTool   (void);
    virtual void        OnItemHelp          (void);
    virtual DROPEFFECT  DragEnter           (ZDUI_DRAGDATA* pDragData);
    virtual void        DragLeave           (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DragOver            (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  Drop                (ZDUI_DRAGDATA* pDragData);
    virtual DROPEFFECT  DropEx              (ZDUI_DRAGDATA* pDragData);
    virtual void        OnBeginDrag         (const CZcTcUiCatalogViewItemArray& itemsDragged,
                                             IDataObject* pDataObject,
                                             DWORD dwKeyState);
    virtual HRESULT     OnDragInProgress    (DROPEFFECT dropEffect);
    virtual void        OnEndDrag           (DROPEFFECT dropEffect);
    virtual LONG        OnBeginZcadDrop     (BOOL* pCancelDrop);
    virtual LONG        OnEndZcadDrop       (BOOL bSuccess);

protected:

protected:
    BOOL OnToolTipGetDispInfo(UINT id, NMHDR * pNMHDR, LRESULT * pResult);

protected:
    
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint pos);
    afx_msg void OnDestroy();
    afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
    afx_msg void OnCatalogItemCut();
    afx_msg void OnCatalogItemCopy();
    afx_msg void OnCatalogItemRemove();
    afx_msg void OnCatalogItemRename();
    afx_msg void OnCatalogItemHelp();
    afx_msg void OnCatalogItemProperties();
    afx_msg void OnCatalogItemInstallTool();
    afx_msg void OnCatalogItemRefresh();
    afx_msg void OnCatalogItemPaste();
    afx_msg void OnSortByName();
    afx_msg void OnSortByType();
    afx_msg void OnAddText();
    afx_msg void OnAddSeparator();
    afx_msg void OnViewOptions();
    afx_msg void OnCatalogParentProperties();
    afx_msg void OnCatalogParentRefresh();
    afx_msg void OnViewButton();
    afx_msg void OnCatalogParentRename();
    afx_msg void OnAllowDocking();
    afx_msg void OnAutoHide();
    afx_msg void OnTransparency();
    afx_msg void OnNewPalette();
    afx_msg void OnCustomize();
    afx_msg void OnCustomizeCUI();
	afx_msg void OnSearchWithSeek();
    afx_msg UINT OnGetDlgCode();

    afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragScroll(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnBeginLabelEdit(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnEndLabelEdit(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGiveFeedback(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnBeginZcadDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnEndZcadDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRenderData(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragEnterToolbarItem(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragOverToolbarItem(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragLeaveToolbarItem(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropToolbarItem(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnChildAdded(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnChildDeleted(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnChildDetached(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnCloseShapePalette(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnGetItemCount(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT  OnGetText(WPARAM wParam,LPARAM  lParam);
    afx_msg LRESULT OnGetItemTextLen(WPARAM wParam,LPARAM lParam);
    afx_msg LRESULT OnGetItemRect(WPARAM wParam,LPARAM lParam);
    DECLARE_MESSAGE_MAP()

protected:
    
    CZcTcUiCatalogView(ZcTcUiSystemInternals*);

protected:
    void            *   mpImpObj;       

private:
    friend class ZcTcUiSystemInternals;    

};
#endif

