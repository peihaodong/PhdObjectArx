

#ifndef __ZCTCUI_H__
#define __ZCTCUI_H__

#include "zadui.h"
#include "zAdAChar.h"
#include <afxtempl.h>

#ifdef  _ZCTCUI_BUILD
#  define   ZCTCUI_PORT  __declspec(dllexport)
#else
#  define   ZCTCUI_PORT  
#endif

class CZcTcUiManager;
class CZcTcUiToolPaletteSet;
class CZcTcUiToolPalette;
class CZcTcUiCatalogView;
class ZcTcCatalogItem;
class ZcTcCatalog;
class ZcTcStockTool;
class ZcTcTool;

typedef CTypedPtrArray<CPtrArray, ZcTcCatalogItem*> ZcTcCatalogItemArray;
typedef CTypedPtrArray<CPtrArray, ZcTcStockTool*>   ZcTcStockToolArray;
typedef CTypedPtrArray<CPtrArray, ZcTcCatalog*>     ZcTcCatalogArray;
typedef CTypedPtrArray<CPtrArray, CZcTcUiToolPaletteSet*> ZcTcUiToolPaletteSetArray;
typedef CTypedPtrArray<CPtrArray, CZcTcUiToolPalette*> ZcTcUiToolPaletteArray;
typedef CTypedPtrArray<CPtrArray, CZcTcUiCatalogView*> ZcTcUiCatalogViewArray;

#define ZCTCUI_DRAGFORMAT_CUSTOM        (0x1 << 0)
#define ZCTCUI_DRAGFORMAT_IDROP         (0x1 << 1)
#define ZCTCUI_DRAGFORMAT_HDROP         (0x1 << 2)

#define ZCTCUI_CNPS_NOCREATEWINDOW      (0x1 << 0)
#define ZCTCUI_CNPS_NOADD               (0x1 << 1)
#define ZCTCUI_CNPS_CREATEHIDDEN        (0x1 << 2)

#define CF_ZCTC_CATALOG_ITEM_17_11          ZCRX_T("CF_ZCTC_CATALOG_ITEM_17_11")
#define CF_ZCTCUI_CATALOG_ITEM_HEADER_17_11 ZCRX_T("CF_ZCTCUI_CATALOG_ITEM_HEADER_17_11")
#define CF_ZCTC_CATALOG_ITEM_17_1           ZCRX_T("CF_ZCTC_CATALOG_ITEM_17_1")
#define CF_ZCTCUI_CATALOG_ITEM_HEADER_17_1  ZCRX_T("CF_ZCTCUI_CATALOG_ITEM_HEADER_17_1")
#define CF_ZCTC_CATALOG_ITEM_16_1           ZCRX_T("CF_ZCTC_CATALOG_ITEM_16_1")
#define CF_ZCTCUI_CATALOG_ITEM_HEADER_16_1  ZCRX_T("CF_ZCTCUI_CATALOG_ITEM_HEADER_16_1")
#define CF_ZCTCUI_CATALOG_ITEM              ZCRX_T("CF_ZCTC_CATALOG_ITEM")
#define CF_ZCTCUI_CATALOG_ITEM_HEADER       ZCRX_T("CF_ZCTCUI_CATALOG_ITEM_HEADER")
#define CF_IDROP_ZCTCUI_TOOL                ZCRX_T("CF_IDROP.XML_ZCTCUI_TOOL")
#define CF_IDROP_ZCTCUI_PALETTE             ZCRX_T("CF_IDROP.XML_ZCTCUI_PALETTE")
#define CF_IDROP_ZCTCUI_PACKAGE             ZCRX_T("CF_IDROP.XML_ZCTCUI_PACKAGE")
#define CF_IDROP_ZCTCUI_CATEGORY            ZCRX_T("CF_IDROP.XML_ZCTCUI_CATEGORY")
#define CF_IDROP_ZCTCUI_CATALOG             ZCRX_T("CF_IDROP.XML_ZCTCUI_CATALOG")
#define CF_IDROP_ZCTCUI_STOCKTOOL           ZCRX_T("CF_IDROP.XML_ZCTCUI_STOCKTOOL")
#define CF_ZCTCUI_TOOLBAR_ITEM              ZCRX_T("CF_ZCTCUI_TOOLBAR_ITEM")

#define ZCTCUI_PI_SHOW_PROGRESS         (0x1 << 0)
#define ZCTCUI_PI_USE_NEW_IDS           (0x1 << 1)
#define ZCTCUI_PI_BREAK_SOURCE_LINK     (0x1 << 2)      
#define ZCTCUI_PI_NOTIFY_TOOLS          (0x1 << 3)      

typedef struct ZCTCUI_DRAG_HEADER
{
    DWORD               mdwDragFormat;
#ifdef _ZSOFT_WINDOWS_
	CLIPFORMAT          mcfClipFormat;   
#endif   
    BOOL                mbZWCADSource;
    DWORD               mdwSourceProcessId; 
    GUID                mRootId;            
    GUID                mParentId;          
    BOOL                mbReadOnlySource;   
    int                 mnCount;            
    int                 mnStockTools;       
    DWORD               mdwItemTypes;       
} ZCTCUI_DRAG_HEADER;

ZCTCUI_PORT CZcTcUiManager* ZcTcUiGetManager(void);
#ifdef _ZSOFT_WINDOWS_
ZCTCUI_PORT BOOL        ZcTcUiCopyItems     (COleDataSource* pDataSource,
                                             const ZcTcCatalogItemArray* pItems,
                                             BOOL bZWCADSource);
ZCTCUI_PORT BOOL        ZcTcUiGetDragInfo   (IDataObject* pDataObject,
                                             ZCTCUI_DRAG_HEADER* pHeader);
ZCTCUI_PORT BOOL        ZcTcUiPasteItems    (IDataObject* pDataObject,
                                             ZcTcCatalogItemArray* pItems,
                                             ZcTcCatalogItemArray* pStockTools,
                                             DWORD dwFlag = ZCTCUI_PI_SHOW_PROGRESS);
ZCTCUI_PORT CZcTcUiToolPaletteSet* ZcTcUiGetToolPaletteWindow(void);
ZCTCUI_PORT BOOL        ZcTcUiFilterShapesDialog(ZcTcCatalogItem* pPackage,
                                             ZcTcCatalogItemArray* pActiveShapes,
                                             ZcTcTool*& pCurrentShape,
                                             CWnd* pParentWnd);
#endif

#endif 
