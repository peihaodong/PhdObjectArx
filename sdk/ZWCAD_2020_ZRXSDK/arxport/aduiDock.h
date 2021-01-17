
#ifndef __ADUIDOCK_H__
#define __ADUIDOCK_H__

#include <afxpriv.h>
#include "AdAChar.h"

#include "../inc/zaduiDock.h"

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ADUI_DOCK_CS_DESTROY_ON_CLOSE
#define ADUI_DOCK_CS_DESTROY_ON_CLOSE		ZDUI_DOCK_CS_DESTROY_ON_CLOSE
#endif //#ifndef ADUI_DOCK_CS_DESTROY_ON_CLOSE

#ifndef ADUI_DOCK_CS_STDMOUSECLICKS
#define ADUI_DOCK_CS_STDMOUSECLICKS		ZDUI_DOCK_CS_STDMOUSECLICKS
#endif //#ifndef ADUI_DOCK_CS_STDMOUSECLICKS

#ifndef ADUI_DOCK_NF_FRAMECHANGED
#define ADUI_DOCK_NF_FRAMECHANGED		ZDUI_DOCK_NF_FRAMECHANGED
#endif //#ifndef ADUI_DOCK_NF_FRAMECHANGED

#ifndef ADUI_DOCK_NF_SIZECHANGED
#define ADUI_DOCK_NF_SIZECHANGED		ZDUI_DOCK_NF_SIZECHANGED
#endif //#ifndef ADUI_DOCK_NF_SIZECHANGED

#ifndef ADUI_DOCK_NF_STATECHANGED
#define ADUI_DOCK_NF_STATECHANGED		ZDUI_DOCK_NF_STATECHANGED
#endif //#ifndef ADUI_DOCK_NF_STATECHANGED

#ifndef ADUI_DOCK_POSITION_TOOL_KEY
#define ADUI_DOCK_POSITION_TOOL_KEY		ZDUI_DOCK_POSITION_TOOL_KEY
#endif //#ifndef ADUI_DOCK_POSITION_TOOL_KEY

#ifndef ADUI_DOCK_STARTUP_TOOL_KEY
#define ADUI_DOCK_STARTUP_TOOL_KEY		ZDUI_DOCK_STARTUP_TOOL_KEY
#endif //#ifndef ADUI_DOCK_STARTUP_TOOL_KEY

#ifndef ADUI_LOADFN
#define ADUI_LOADFN		ZDUI_LOADFN
#endif //#ifndef ADUI_LOADFN

#ifndef ADUI_PORT
#define ADUI_PORT		ZDUI_PORT
#endif //#ifndef ADUI_PORT

#ifndef ADUI_SAVEFN
#define ADUI_SAVEFN		ZDUI_SAVEFN
#endif //#ifndef ADUI_SAVEFN

#ifndef ADUI_XML_DOCK_STARTUP_CMD_NAME
#define ADUI_XML_DOCK_STARTUP_CMD_NAME		ZDUI_XML_DOCK_STARTUP_CMD_NAME
#endif //#ifndef ADUI_XML_DOCK_STARTUP_CMD_NAME

#ifndef ADUI_XML_DOCK_STARTUP_INFO
#define ADUI_XML_DOCK_STARTUP_INFO		ZDUI_XML_DOCK_STARTUP_INFO
#endif //#ifndef ADUI_XML_DOCK_STARTUP_INFO

#ifndef ADUI_XML_DOCK_STARTUP_TOOL_NAME
#define ADUI_XML_DOCK_STARTUP_TOOL_NAME		ZDUI_XML_DOCK_STARTUP_TOOL_NAME
#endif //#ifndef ADUI_XML_DOCK_STARTUP_TOOL_NAME

#ifndef ADUI_XML_DOCK_TOOL
#define ADUI_XML_DOCK_TOOL		ZDUI_XML_DOCK_TOOL
#endif //#ifndef ADUI_XML_DOCK_TOOL

#ifndef ADUI_XML_DOCK_TOOL_CLSID
#define ADUI_XML_DOCK_TOOL_CLSID		ZDUI_XML_DOCK_TOOL_CLSID
#endif //#ifndef ADUI_XML_DOCK_TOOL_CLSID

#ifndef ADUI_XML_DOCK_TOOL_INFO
#define ADUI_XML_DOCK_TOOL_INFO		ZDUI_XML_DOCK_TOOL_INFO
#endif //#ifndef ADUI_XML_DOCK_TOOL_INFO

#ifndef ADUI_XML_ROOT
#define ADUI_XML_ROOT		ZDUI_XML_ROOT
#endif //#ifndef ADUI_XML_ROOT

#ifndef AdUiEnableDocking
#define AdUiEnableDocking		ZdUiEnableDocking
#endif //#ifndef AdUiEnableDocking

#ifndef AdUiGetRegisteredPaletteSetFloatingFrameClass
#define AdUiGetRegisteredPaletteSetFloatingFrameClass		ZdUiGetRegisteredPaletteSetFloatingFrameClass
#endif //#ifndef AdUiGetRegisteredPaletteSetFloatingFrameClass

#ifndef AdUiRegisterDockingTool
#define AdUiRegisterDockingTool		ZdUiRegisterDockingTool
#endif //#ifndef AdUiRegisterDockingTool

#ifndef AdUiRegisterFloatingFrameClassAddress
#define AdUiRegisterFloatingFrameClassAddress		ZdUiRegisterFloatingFrameClassAddress
#endif //#ifndef AdUiRegisterFloatingFrameClassAddress

#ifndef AdUiRegisterPaletteSetFloatingFrameClass
#define AdUiRegisterPaletteSetFloatingFrameClass		ZdUiRegisterPaletteSetFloatingFrameClass
#endif //#ifndef AdUiRegisterPaletteSetFloatingFrameClass

#ifndef AdUiRegisterTool
#define AdUiRegisterTool		ZdUiRegisterTool
#endif //#ifndef AdUiRegisterTool

#ifndef AdUiSaveDockingToolPositions
#define AdUiSaveDockingToolPositions		ZdUiSaveDockingToolPositions
#endif //#ifndef AdUiSaveDockingToolPositions

#ifndef AdUiSetFloatingFrameClass
#define AdUiSetFloatingFrameClass		ZdUiSetFloatingFrameClass
#endif //#ifndef AdUiSetFloatingFrameClass

#ifndef AdUiShowDockControlBars
#define AdUiShowDockControlBars		ZdUiShowDockControlBars
#endif //#ifndef AdUiShowDockControlBars

#ifndef AdUiSkBtnItems
#define AdUiSkBtnItems		ZdUiSkBtnItems
#endif //#ifndef AdUiSkBtnItems

#ifndef AdUiSkIds
#define AdUiSkIds		ZdUiSkIds
#endif //#ifndef AdUiSkIds

#ifndef AdUiSkUiFlags
#define AdUiSkUiFlags		ZdUiSkUiFlags
#endif //#ifndef AdUiSkUiFlags

#ifndef AdUiTitleBarLocation
#define AdUiTitleBarLocation		ZdUiTitleBarLocation
#endif //#ifndef AdUiTitleBarLocation

#ifndef CAdUiAnchorBar
#define CAdUiAnchorBar		CZdUiAnchorBar
#endif //#ifndef CAdUiAnchorBar

#ifndef CAdUiBitmapButton
#define CAdUiBitmapButton		CZdUiBitmapButton
#endif //#ifndef CAdUiBitmapButton

#ifndef CAdUiDockBar
#define CAdUiDockBar		CZdUiDockBar
#endif //#ifndef CAdUiDockBar

#ifndef CAdUiDockBarMutator
#define CAdUiDockBarMutator		CZdUiDockBarMutator
#endif //#ifndef CAdUiDockBarMutator

#ifndef CAdUiDockControlBar
#define CAdUiDockControlBar		CZdUiDockControlBar
#endif //#ifndef CAdUiDockControlBar

#ifndef CAdUiDockDragContext
#define CAdUiDockDragContext		CZdUiDockDragContext
#endif //#ifndef CAdUiDockDragContext

#ifndef CAdUiDockFrame
#define CAdUiDockFrame		CZdUiDockFrame
#endif //#ifndef CAdUiDockFrame

#ifndef CAdUiDropTarget
#define CAdUiDropTarget		CZdUiDropTarget
#endif //#ifndef CAdUiDropTarget

#ifndef CAdUiImpPaletteSet
#define CAdUiImpPaletteSet		CZdUiImpPaletteSet
#endif //#ifndef CAdUiImpPaletteSet

#ifndef CAdUiPaletteSet
#define CAdUiPaletteSet		CZdUiPaletteSet
#endif //#ifndef CAdUiPaletteSet

#ifndef CAdUiPaletteSetDockFrame
#define CAdUiPaletteSetDockFrame		CZdUiPaletteSetDockFrame
#endif //#ifndef CAdUiPaletteSetDockFrame

#ifndef CanAutoCADTakeFocus
#define CanAutoCADTakeFocus		CanZWCADTakeFocus
#endif //#ifndef CanAutoCADTakeFocus

#ifndef ID_ADUI_ALLOWDOCK
#define ID_ADUI_ALLOWDOCK		ID_ZDUI_ALLOWDOCK
#endif //#ifndef ID_ADUI_ALLOWDOCK

#ifndef ID_ADUI_HIDEBAR
#define ID_ADUI_HIDEBAR		ID_ZDUI_HIDEBAR
#endif //#ifndef ID_ADUI_HIDEBAR

#ifndef AdskBar
#define AdskBar		ZwSoftBar
#endif //#ifndef AdskBar

#endif //#ifndef __ADUIDOCK_H__
