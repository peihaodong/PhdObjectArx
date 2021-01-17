
#ifndef __ACTCUI_H__
#define __ACTCUI_H__

#include "adui.h"
#include "AdAChar.h"
#include <afxtempl.h>

#include "../inc/zAcTcUI.h"

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ACTCUI_CNPS_CREATEHIDDEN
#define ACTCUI_CNPS_CREATEHIDDEN		ZCTCUI_CNPS_CREATEHIDDEN
#endif //#ifndef ACTCUI_CNPS_CREATEHIDDEN

#ifndef ACTCUI_CNPS_NOADD
#define ACTCUI_CNPS_NOADD		ZCTCUI_CNPS_NOADD
#endif //#ifndef ACTCUI_CNPS_NOADD

#ifndef ACTCUI_CNPS_NOCREATEWINDOW
#define ACTCUI_CNPS_NOCREATEWINDOW		ZCTCUI_CNPS_NOCREATEWINDOW
#endif //#ifndef ACTCUI_CNPS_NOCREATEWINDOW

#ifndef ACTCUI_DRAGFORMAT_CUSTOM
#define ACTCUI_DRAGFORMAT_CUSTOM		ZCTCUI_DRAGFORMAT_CUSTOM
#endif //#ifndef ACTCUI_DRAGFORMAT_CUSTOM

#ifndef ACTCUI_DRAGFORMAT_HDROP
#define ACTCUI_DRAGFORMAT_HDROP		ZCTCUI_DRAGFORMAT_HDROP
#endif //#ifndef ACTCUI_DRAGFORMAT_HDROP

#ifndef ACTCUI_DRAGFORMAT_IDROP
#define ACTCUI_DRAGFORMAT_IDROP		ZCTCUI_DRAGFORMAT_IDROP
#endif //#ifndef ACTCUI_DRAGFORMAT_IDROP

#ifndef ACTCUI_DRAG_HEADER
#define ACTCUI_DRAG_HEADER		ZCTCUI_DRAG_HEADER
#endif //#ifndef ACTCUI_DRAG_HEADER

#ifndef ACTCUI_PI_BREAK_SOURCE_LINK
#define ACTCUI_PI_BREAK_SOURCE_LINK		ZCTCUI_PI_BREAK_SOURCE_LINK
#endif //#ifndef ACTCUI_PI_BREAK_SOURCE_LINK

#ifndef ACTCUI_PI_NOTIFY_TOOLS
#define ACTCUI_PI_NOTIFY_TOOLS		ZCTCUI_PI_NOTIFY_TOOLS
#endif //#ifndef ACTCUI_PI_NOTIFY_TOOLS

#ifndef ACTCUI_PI_SHOW_PROGRESS
#define ACTCUI_PI_SHOW_PROGRESS		ZCTCUI_PI_SHOW_PROGRESS
#endif //#ifndef ACTCUI_PI_SHOW_PROGRESS

#ifndef ACTCUI_PI_USE_NEW_IDS
#define ACTCUI_PI_USE_NEW_IDS		ZCTCUI_PI_USE_NEW_IDS
#endif //#ifndef ACTCUI_PI_USE_NEW_IDS

#ifndef ACTCUI_PORT
#define ACTCUI_PORT		ZCTCUI_PORT
#endif //#ifndef ACTCUI_PORT

#ifndef AcTcCatalog
#define AcTcCatalog		ZcTcCatalog
#endif //#ifndef AcTcCatalog

#ifndef AcTcCatalogArray
#define AcTcCatalogArray		ZcTcCatalogArray
#endif //#ifndef AcTcCatalogArray

#ifndef AcTcCatalogItem
#define AcTcCatalogItem		ZcTcCatalogItem
#endif //#ifndef AcTcCatalogItem

#ifndef AcTcCatalogItemArray
#define AcTcCatalogItemArray		ZcTcCatalogItemArray
#endif //#ifndef AcTcCatalogItemArray

#ifndef AcTcStockTool
#define AcTcStockTool		ZcTcStockTool
#endif //#ifndef AcTcStockTool

#ifndef AcTcStockToolArray
#define AcTcStockToolArray		ZcTcStockToolArray
#endif //#ifndef AcTcStockToolArray

#ifndef AcTcTool
#define AcTcTool		ZcTcTool
#endif //#ifndef AcTcTool

#ifndef AcTcUiCatalogViewArray
#define AcTcUiCatalogViewArray		ZcTcUiCatalogViewArray
#endif //#ifndef AcTcUiCatalogViewArray

#ifndef AcTcUiCopyItems
#define AcTcUiCopyItems		ZcTcUiCopyItems
#endif //#ifndef AcTcUiCopyItems

#ifndef AcTcUiFilterShapesDialog
#define AcTcUiFilterShapesDialog		ZcTcUiFilterShapesDialog
#endif //#ifndef AcTcUiFilterShapesDialog

#ifndef AcTcUiGetDragInfo
#define AcTcUiGetDragInfo		ZcTcUiGetDragInfo
#endif //#ifndef AcTcUiGetDragInfo

#ifndef AcTcUiGetManager
#define AcTcUiGetManager		ZcTcUiGetManager
#endif //#ifndef AcTcUiGetManager

#ifndef AcTcUiGetToolPaletteWindow
#define AcTcUiGetToolPaletteWindow		ZcTcUiGetToolPaletteWindow
#endif //#ifndef AcTcUiGetToolPaletteWindow

#ifndef AcTcUiPasteItems
#define AcTcUiPasteItems		ZcTcUiPasteItems
#endif //#ifndef AcTcUiPasteItems

#ifndef AcTcUiToolPaletteArray
#define AcTcUiToolPaletteArray		ZcTcUiToolPaletteArray
#endif //#ifndef AcTcUiToolPaletteArray

#ifndef AcTcUiToolPaletteSetArray
#define AcTcUiToolPaletteSetArray		ZcTcUiToolPaletteSetArray
#endif //#ifndef AcTcUiToolPaletteSetArray

#ifndef CAcTcUiCatalogView
#define CAcTcUiCatalogView		CZcTcUiCatalogView
#endif //#ifndef CAcTcUiCatalogView

#ifndef CAcTcUiManager
#define CAcTcUiManager		CZcTcUiManager
#endif //#ifndef CAcTcUiManager

#ifndef CAcTcUiToolPalette
#define CAcTcUiToolPalette		CZcTcUiToolPalette
#endif //#ifndef CAcTcUiToolPalette

#ifndef CAcTcUiToolPaletteSet
#define CAcTcUiToolPaletteSet		CZcTcUiToolPaletteSet
#endif //#ifndef CAcTcUiToolPaletteSet

#ifndef _ACTCUI_BUILD
#define _ACTCUI_BUILD		_ZCTCUI_BUILD
#endif //#ifndef _ACTCUI_BUILD

#ifndef CF_ACTC_CATALOG_ITEM_17_11
#define CF_ACTC_CATALOG_ITEM_17_11		CF_ZCTC_CATALOG_ITEM_17_11
#endif //#ifndef CF_ACTC_CATALOG_ITEM_17_11

#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER_17_11
#define CF_ACTCUI_CATALOG_ITEM_HEADER_17_11		CF_ZCTCUI_CATALOG_ITEM_HEADER_17_11
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER_17_11

#ifndef CF_ACTCUI_CATALOG_ITEM
#define CF_ACTCUI_CATALOG_ITEM		CF_ZCTCUI_CATALOG_ITEM
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM

#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER 
#define CF_ACTCUI_CATALOG_ITEM_HEADER		CF_ZCTCUI_CATALOG_ITEM_HEADER 
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER

#ifndef CF_ACTCUI_CATALOG_ITEM
#define CF_ACTCUI_CATALOG_ITEM		CF_ZCTCUI_CATALOG_ITEM
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM

#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER
#define CF_ACTCUI_CATALOG_ITEM_HEADER		CF_ZCTCUI_CATALOG_ITEM_HEADER
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER

#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER_16_1
#define CF_ACTCUI_CATALOG_ITEM_HEADER_16_1		CF_ZCTCUI_CATALOG_ITEM_HEADER_16_1
#endif //#ifndef CF_ACTCUI_CATALOG_ITEM_HEADER_16_1

#ifndef CF_ACTCUI_TOOLBAR_ITEM
#define CF_ACTCUI_TOOLBAR_ITEM		CF_ZCTCUI_TOOLBAR_ITEM
#endif //#ifndef CF_ACTCUI_TOOLBAR_ITEM

#ifndef CF_ACTC_CATALOG_ITEM_16_1
#define CF_ACTC_CATALOG_ITEM_16_1		CF_ZCTC_CATALOG_ITEM_16_1
#endif //#ifndef CF_ACTC_CATALOG_ITEM_16_1

#ifndef CF_IDROP_ACTCUI_CATALOG
#define CF_IDROP_ACTCUI_CATALOG		CF_IDROP_ZCTCUI_CATALOG
#endif //#ifndef CF_IDROP_ACTCUI_CATALOG

#ifndef CF_IDROP_ACTCUI_CATEGORY
#define CF_IDROP_ACTCUI_CATEGORY		CF_IDROP_ZCTCUI_CATEGORY
#endif //#ifndef CF_IDROP_ACTCUI_CATEGORY

#ifndef CF_IDROP_ACTCUI_PACKAGE
#define CF_IDROP_ACTCUI_PACKAGE		CF_IDROP_ZCTCUI_PACKAGE
#endif //#ifndef CF_IDROP_ACTCUI_PACKAGE

#ifndef CF_IDROP_ACTCUI_PALETTE
#define CF_IDROP_ACTCUI_PALETTE		CF_IDROP_ZCTCUI_PALETTE
#endif //#ifndef CF_IDROP_ACTCUI_PALETTE

#ifndef CF_IDROP_ACTCUI_STOCKTOOL
#define CF_IDROP_ACTCUI_STOCKTOOL		CF_IDROP_ZCTCUI_STOCKTOOL
#endif //#ifndef CF_IDROP_ACTCUI_STOCKTOOL

#ifndef CF_IDROP_ACTCUI_TOOL
#define CF_IDROP_ACTCUI_TOOL		CF_IDROP_ZCTCUI_TOOL
#endif //#ifndef CF_IDROP_ACTCUI_TOOL

#ifndef bAutoCADSource
#define bAutoCADSource		bZWCADSource
#endif //#ifndef bAutoCADSource

#ifndef mbAutoCADSource
#define mbAutoCADSource		mbZWCADSource
#endif //#ifndef mbAutoCADSource


#endif //#ifndef __ACTCUI_H__
