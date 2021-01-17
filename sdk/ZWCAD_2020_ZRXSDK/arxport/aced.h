
#ifndef __ACED_H__
#define __ACED_H__

#include "adesk.h"
#include "rxnames.h"
#include "rxevent.h"
#include "accmd.h"
#include "dbjig.h"

#include "../inc/zaced.h"

#ifndef ACED_EDITOR_OBJ
#define ACED_EDITOR_OBJ		ZCED_EDITOR_OBJ
#endif //#ifndef ACED_EDITOR_OBJ

#ifndef ACED_SERVICES
#define ACED_SERVICES		ZCED_SERVICES
#endif //#ifndef ACED_SERVICES

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_CMD_DEFUN
#define ACRX_CMD_DEFUN		ZCRX_CMD_DEFUN
#endif //#ifndef ACRX_CMD_DEFUN

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ADESK_DEPRECATED
#define ADESK_DEPRECATED		ZSOFT_DEPRECATED
#endif //#ifndef ADESK_DEPRECATED

#ifndef AcApDocument
#define AcApDocument		ZcApDocument
#endif //#ifndef AcApDocument

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#ifndef AcCm
#define AcCm		ZcCm
#endif //#ifndef AcCm

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbFcf
#define AcDbFcf		ZcDbFcf
#endif //#ifndef AcDbFcf

#ifndef AcDbFullSubentPathArray
#define AcDbFullSubentPathArray		ZcDbFullSubentPathArray
#endif //#ifndef AcDbFullSubentPathArray

#ifndef AcDbHatch
#define AcDbHatch		ZcDbHatch
#endif //#ifndef AcDbHatch

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbMText
#define AcDbMText		ZcDbMText
#endif //#ifndef AcDbMText

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbViewTableRecord
#define AcDbViewTableRecord		ZcDbViewTableRecord
#endif //#ifndef AcDbViewTableRecord

#ifndef AcDbViewport
#define AcDbViewport		ZcDbViewport
#endif //#ifndef AcDbViewport

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcEdColorDialogCallbackFunction
#define AcEdColorDialogCallbackFunction		ZcEdColorDialogCallbackFunction
#endif //#ifndef AcEdColorDialogCallbackFunction

#ifndef AcEdCommand
#define AcEdCommand		ZcEdCommand
#endif //#ifndef AcEdCommand

#ifndef AcEdCommandStruc
#define AcEdCommandStruc		ZcEdCommandStruc
#endif //#ifndef AcEdCommandStruc

#ifndef AcEdDrawOrderCmdType
#define AcEdDrawOrderCmdType		ZcEdDrawOrderCmdType
#endif //#ifndef AcEdDrawOrderCmdType

#ifndef AcEdServices
#define AcEdServices		ZcEdServices
#endif //#ifndef AcEdServices

#ifndef AcEdUIContext
#define AcEdUIContext		ZcEdUIContext
#endif //#ifndef AcEdUIContext

#ifndef AcEditor
#define AcEditor		ZcEditor
#endif //#ifndef AcEditor

#ifndef AcEditorImp
#define AcEditorImp		ZcEditorImp
#endif //#ifndef AcEditorImp

#ifndef AcEditorReactor
#define AcEditorReactor		ZcEditorReactor
#endif //#ifndef AcEditorReactor

#ifndef AcEditorReactor2
#define AcEditorReactor2		ZcEditorReactor2
#endif //#ifndef AcEditorReactor2

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxEvent
#define AcRxEvent		ZcRxEvent
#endif //#ifndef AcRxEvent

#ifndef AcRxEventReactor
#define AcRxEventReactor		ZcRxEventReactor
#endif //#ifndef AcRxEventReactor

#ifndef AcRxFunctionPtr
#define AcRxFunctionPtr		ZcRxFunctionPtr
#endif //#ifndef AcRxFunctionPtr

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcRxService
#define AcRxService		ZcRxService
#endif //#ifndef AcRxService

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcadContextMenuMode
#define AcadContextMenuMode		ZcadContextMenuMode
#endif //#ifndef AcadContextMenuMode

#ifndef AcadGetIDispatch
#define AcadGetIDispatch		ZcadGetIDispatch
#endif //#ifndef AcadGetIDispatch

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acdbCanonicalToSystemRange
#define acdbCanonicalToSystemRange		zcdbCanonicalToSystemRange
#endif //#ifndef acdbCanonicalToSystemRange

#ifndef acdbSystemRangeToCanonical
#define acdbSystemRangeToCanonical		zcdbSystemRangeToCanonical
#endif //#ifndef acdbSystemRangeToCanonical

#ifndef acedActiveViewportId
#define acedActiveViewportId		zcedActiveViewportId
#endif //#ifndef acedActiveViewportId

#ifndef acedAddDefaultContextMenu
#define acedAddDefaultContextMenu		zcedAddDefaultContextMenu
#endif //#ifndef acedAddDefaultContextMenu

#ifndef acedAddObjectContextMenu
#define acedAddObjectContextMenu		zcedAddObjectContextMenu
#endif //#ifndef acedAddObjectContextMenu

#ifndef acedClearOLELock
#define acedClearOLELock		zcedClearOLELock
#endif //#ifndef acedClearOLELock

#ifndef acedCmdLookup
#define acedCmdLookup		zcedCmdLookup
#endif //#ifndef acedCmdLookup

#ifndef acedCmdLookup2
#define acedCmdLookup2		zcedCmdLookup2
#endif //#ifndef acedCmdLookup2

#ifndef acedCmdUndefine
#define acedCmdUndefine		zcedCmdUndefine
#endif //#ifndef acedCmdUndefine

#ifndef acedConvertEntityToHatch
#define acedConvertEntityToHatch		zcedConvertEntityToHatch
#endif //#ifndef acedConvertEntityToHatch

#ifndef acedCreateEnhancedViewportOnDrop
#define acedCreateEnhancedViewportOnDrop		zcedCreateEnhancedViewportOnDrop
#endif //#ifndef acedCreateEnhancedViewportOnDrop

#ifndef acedCreateEnhancedViewportOnDropDWG
#define acedCreateEnhancedViewportOnDropDWG		zcedCreateEnhancedViewportOnDropDWG
#endif //#ifndef acedCreateEnhancedViewportOnDropDWG

#ifndef acedCreateViewportByView
#define acedCreateViewportByView		zcedCreateViewportByView
#endif //#ifndef acedCreateViewportByView

#ifndef acedDisableDefaultARXExceptionHandler
#define acedDisableDefaultARXExceptionHandler		zcedDisableDefaultZRXExceptionHandler
#endif //#ifndef acedDisableDefaultARXExceptionHandler

#ifndef acedDrawOrderInherit
#define acedDrawOrderInherit		zcedDrawOrderInherit
#endif //#ifndef acedDrawOrderInherit

#ifndef acedEditMTextInteractive
#define acedEditMTextInteractive		zcedEditMTextInteractive
#endif //#ifndef acedEditMTextInteractive

#ifndef acedEditToleranceInteractive
#define acedEditToleranceInteractive		zcedEditToleranceInteractive
#endif //#ifndef acedEditToleranceInteractive

#ifndef acedEditor
#define acedEditor		zcedEditor
#endif //#ifndef acedEditor

#ifndef acedGetCMBaseAlias
#define acedGetCMBaseAlias		zcedGetCMBaseAlias
#endif //#ifndef acedGetCMBaseAlias

#ifndef acedGetCommandForDocument
#define acedGetCommandForDocument		zcedGetCommandForDocument
#endif //#ifndef acedGetCommandForDocument

#ifndef acedGetCurViewportObjectId
#define acedGetCurViewportObjectId		zcedGetCurViewportObjectId
#endif //#ifndef acedGetCurViewportObjectId

#ifndef acedGetCurrentSelectionSet
#define acedGetCurrentSelectionSet		zcedGetCurrentSelectionSet
#endif //#ifndef acedGetCurrentSelectionSet

#ifndef acedGetCurrentUCS
#define acedGetCurrentUCS		zcedGetCurrentUCS
#endif //#ifndef acedGetCurrentUCS

#ifndef acedGetFullSubentPathsForCurrentSelection
#define acedGetFullSubentPathsForCurrentSelection		zcedGetFullSubentPathsForCurrentSelection
#endif //#ifndef acedGetFullSubentPathsForCurrentSelection

#ifndef acedGetIDispatch
#define acedGetIDispatch		zcedGetIDispatch
#endif //#ifndef acedGetIDispatch

#ifndef acedGetRGB
#define acedGetRGB		zcedGetRGB
#endif //#ifndef acedGetRGB

#ifndef acedGetUnitsValueString
#define acedGetUnitsValueString		zcedGetUnitsValueString
#endif //#ifndef acedGetUnitsValueString

#ifndef acedInitDialog
#define acedInitDialog		zcedInitDialog
#endif //#ifndef acedInitDialog

#ifndef acedIsDragging
#define acedIsDragging		zcedIsDragging
#endif //#ifndef acedIsDragging

#ifndef acedIsMenuGroupLoaded
#define acedIsMenuGroupLoaded		zcedIsMenuGroupLoaded
#endif //#ifndef acedIsMenuGroupLoaded

#ifndef acedLoadPartialMenu
#define acedLoadPartialMenu		zcedLoadPartialMenu
#endif //#ifndef acedLoadPartialMenu

#ifndef acedIsUpdateDisplayPaused
#define acedIsUpdateDisplayPaused		zcedIsUpdateDisplayPaused
#endif //#ifndef acedIsUpdateDisplayPaused

#ifndef acedMspace
#define acedMspace		zcedMspace
#endif //#ifndef acedMspace

#ifndef acedNumberOfViewports
#define acedNumberOfViewports		zcedNumberOfViewports
#endif //#ifndef acedNumberOfViewports

#ifndef acedPopCommandDirectory
#define acedPopCommandDirectory		zcedPopCommandDirectory
#endif //#ifndef acedPopCommandDirectory

#ifndef acedPostCommandPrompt
#define acedPostCommandPrompt		zcedPostCommandPrompt
#endif //#ifndef acedPostCommandPrompt

#ifndef acedPspace
#define acedPspace		zcedPspace
#endif //#ifndef acedPspace

#ifndef acedRemoveDefaultContextMenu
#define acedRemoveDefaultContextMenu		zcedRemoveDefaultContextMenu
#endif //#ifndef acedRemoveDefaultContextMenu

#ifndef acedRemoveObjectContextMenu
#define acedRemoveObjectContextMenu		zcedRemoveObjectContextMenu
#endif //#ifndef acedRemoveObjectContextMenu

#ifndef acedRestoreCurrentView
#define acedRestoreCurrentView		zcedRestoreCurrentView
#endif //#ifndef acedRestoreCurrentView

#ifndef acedRestorePreviousUCS
#define acedRestorePreviousUCS		zcedRestorePreviousUCS
#endif //#ifndef acedRestorePreviousUCS

#ifndef acedSendModelessOperationEnded
#define acedSendModelessOperationEnded		zcedSendModelessOperationEnded
#endif //#ifndef acedSendModelessOperationEnded

#ifndef acedSendModelessOperationStart
#define acedSendModelessOperationStart		zcedSendModelessOperationStart
#endif //#ifndef acedSendModelessOperationStart

#ifndef acedServices
#define acedServices		zcedServices
#endif //#ifndef acedServices

#ifndef acedSetCMBaseAlias
#define acedSetCMBaseAlias		zcedSetCMBaseAlias
#endif //#ifndef acedSetCMBaseAlias

#ifndef acedSetColorDialog
#define acedSetColorDialog		zcedSetColorDialog
#endif //#ifndef acedSetColorDialog

#ifndef acedSetColorDialogTrueColor
#define acedSetColorDialogTrueColor		zcedSetColorDialogTrueColor
#endif //#ifndef acedSetColorDialogTrueColor

#ifndef acedSetColorDialogTrueColorWithCallback
#define acedSetColorDialogTrueColorWithCallback		zcedSetColorDialogTrueColorWithCallback
#endif //#ifndef acedSetColorDialogTrueColorWithCallback

#ifndef acedSetColorPrompt
#define acedSetColorPrompt		zcedSetColorPrompt
#endif //#ifndef acedSetColorPrompt

#ifndef acedSetCurrentUCS
#define acedSetCurrentUCS		zcedSetCurrentUCS
#endif //#ifndef acedSetCurrentUCS

#ifndef acedSetCurrentVPort
#define acedSetCurrentVPort		zcedSetCurrentVPort
#endif //#ifndef acedSetCurrentVPort

#ifndef acedSetCurrentView
#define acedSetCurrentView		zcedSetCurrentView
#endif //#ifndef acedSetCurrentView

#ifndef acedSetOLELock
#define acedSetOLELock		zcedSetOLELock
#endif //#ifndef acedSetOLELock

#ifndef acedSyncFileOpen
#define acedSyncFileOpen		zcedSyncFileOpen
#endif //#ifndef acedSyncFileOpen

#ifndef acedUpdateDisplay
#define acedUpdateDisplay		zcedUpdateDisplay
#endif //#ifndef acedUpdateDisplay

#ifndef acedUpdateDisplayPause
#define acedUpdateDisplayPause		zcedUpdateDisplayPause
#endif //#ifndef acedUpdateDisplayPause

#ifndef acedVPLayer
#define acedVPLayer		zcedVPLayer
#endif //#ifndef acedVPLayer

#ifndef acedViewportIdFromNumber
#define acedViewportIdFromNumber		zcedViewportIdFromNumber
#endif //#ifndef acedViewportIdFromNumber

#ifndef acedVportTableRecords2Vports
#define acedVportTableRecords2Vports		zcedVportTableRecords2Vports
#endif //#ifndef acedVportTableRecords2Vports

#ifndef acedVports2VportTableRecords
#define acedVports2VportTableRecords		zcedVports2VportTableRecords
#endif //#ifndef acedVports2VportTableRecords

#ifndef acrxServiceDictionary
#define acrxServiceDictionary		zcrxServiceDictionary
#endif //#ifndef acrxServiceDictionary

#ifndef acrxSysRegistry
#define acrxSysRegistry		zcrxSysRegistry
#endif //#ifndef acrxSysRegistry

#ifndef newAcEdCommand
#define newAcEdCommand		newZcEdCommand
#endif //#ifndef newAcEdCommand

#ifndef acedTraceBoundary
#define acedTraceBoundary		zcedTraceBoundary
#endif //#ifndef acedTraceBoundary

#ifndef acedRegenLayers
#define acedRegenLayers		zcedRegenLayers
#endif //#ifndef acedRegenLayers

#endif //#ifndef __ACED_H__
