

#pragma once

#include "zAcTc.h"
#include "zAcTcUi.h"

class CZcTcUiCatalogView;

#define ZCTCUI_CVISTYLE_PUSHBUTTON      0x0
#define ZCTCUI_CVISTYLE_SHOWTEXT        (0x1 << 1)
#define ZCTCUI_CVISTYLE_RIGHTTEXT       (0x1 << 2)
#define ZCTCUI_CVISTYLE_FLYOUT          (0x1 << 3)
#define ZCTCUI_CVISTYLE_FULLROW         (0x1 << 4)
#define ZCTCUI_CVISTYLE_HIDEIMAGE       (0x1 << 5)
#define ZCTCUI_CVISTYLE_TEXT            (0x1 << 6)
#define ZCTCUI_CVISTYLE_SEPARATOR       (0x1 << 7)
#define ZCTCUI_CVISTATE_HIGHLIGHTED     (0x1 << 0)
#define ZCTCUI_CVISTATE_SELECTED        (0x1 << 1)
#define ZCTCUI_CVISTATE_HALO            (0x1 << 2)
#define ZCTCUI_CVISTATE_FOCUSED         (0x1 << 3)

#define ZCTCUI_CVIR_BOUNDS              (0x1 << 0)
#define ZCTCUI_CVIR_IMAGE               (0x1 << 1)
#define ZCTCUI_CVIR_LABEL               (0x1 << 2)
#define ZCTCUI_CVIR_USEFULLLABEL        (0x1 << 3)
#define ZCTCUI_CVIR_TRIGGER             (0x1 << 4)
#define ZCTCUI_CVIR_WORLDRECT           (0x1 << 5)

class ZCTCUI_PORT CZcTcUiCatalogViewItem : public CObject  
{
    friend class CZcTcUiImpCatalogView;

public:
    virtual ~CZcTcUiCatalogViewItem();

    BOOL                Render              (BOOL bEraseBackground = FALSE);
    BOOL                Render              (CDC* pDC,
                                             int x,
                                             int y);
    BOOL                GetRect             (LPRECT lpRect, 
                                             int nCode) const;
    ZcTcCatalogItem *   GetCatalogItem      (void) const;
    BOOL                SetCatalogItem      (ZcTcCatalogItem* pCatalogItem);
    DWORD               GetStyle            (void) const;
    DWORD               GetState            (void) const;
    BOOL                SetState            (DWORD dwState);
    BOOL                GetPosition         (LPPOINT lpPoint) const;
    DWORD               GetData             (void) const;
    BOOL                SetData             (DWORD dwData);
    BOOL                Highlight           (BOOL bHighlight = TRUE);
    BOOL                Select              (BOOL bSelect = TRUE);
    BOOL                Halo                (BOOL bHalo = TRUE);

protected:

    CZcTcUiCatalogViewItem(CZcTcUiCatalogView* pCatalogView);
    CZcTcUiCatalogViewItem(CZcTcUiCatalogView* pCatalogView, 
        ZcTcCatalogItem* pCatalogItem, const CSize& sizeImage, 
        DWORD dwStyle = ZCTCUI_CVISTYLE_PUSHBUTTON);

protected:
    void            *   mpImpObj;           

private:
    friend class ZcTcUiSystemInternals;
};

typedef CTypedPtrArray<CPtrArray, CZcTcUiCatalogViewItem*> CZcTcUiCatalogViewItemArray;

