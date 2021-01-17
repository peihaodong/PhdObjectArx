
#ifndef __ACEDADS_H__
#define __ACEDADS_H__

#include "adsdef.h"
#include "acmem.h"
#include "AdAChar.h"

#include "../inc/zacedads.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef acdbAngToF
#define acdbAngToF		zcdbAngToF
#endif //#ifndef acdbAngToF

#ifndef acdbAngToS
#define acdbAngToS		zcdbAngToS
#endif //#ifndef acdbAngToS

#ifndef acdbDictAdd
#define acdbDictAdd		zcdbDictAdd
#endif //#ifndef acdbDictAdd

#ifndef acdbDictNext
#define acdbDictNext		zcdbDictNext
#endif //#ifndef acdbDictNext

#ifndef acdbDictRemove
#define acdbDictRemove		zcdbDictRemove
#endif //#ifndef acdbDictRemove

#ifndef acdbDictRename
#define acdbDictRename		zcdbDictRename
#endif //#ifndef acdbDictRename

#ifndef acdbDictSearch
#define acdbDictSearch		zcdbDictSearch
#endif //#ifndef acdbDictSearch

#ifndef acdbDisToF
#define acdbDisToF		zcdbDisToF
#endif //#ifndef acdbDisToF

#ifndef acdbEntDel
#define acdbEntDel		zcdbEntDel
#endif //#ifndef acdbEntDel

#ifndef acdbEntGet
#define acdbEntGet		zcdbEntGet
#endif //#ifndef acdbEntGet

#ifndef acdbEntGetX
#define acdbEntGetX		zcdbEntGetX
#endif //#ifndef acdbEntGetX

#ifndef acdbEntLast
#define acdbEntLast		zcdbEntLast
#endif //#ifndef acdbEntLast

#ifndef acdbEntMake
#define acdbEntMake		zcdbEntMake
#endif //#ifndef acdbEntMake

#ifndef acdbEntMakeX
#define acdbEntMakeX		zcdbEntMakeX
#endif //#ifndef acdbEntMakeX

#ifndef acdbEntMod
#define acdbEntMod		zcdbEntMod
#endif //#ifndef acdbEntMod

#ifndef acdbEntNext
#define acdbEntNext		zcdbEntNext
#endif //#ifndef acdbEntNext

#ifndef acdbEntUpd
#define acdbEntUpd		zcdbEntUpd
#endif //#ifndef acdbEntUpd

#ifndef acdbInters
#define acdbInters		zcdbInters
#endif //#ifndef acdbInters

#ifndef acdbNamedObjDict
#define acdbNamedObjDict		zcdbNamedObjDict
#endif //#ifndef acdbNamedObjDict

#ifndef acdbRToS
#define acdbRToS		zcdbRToS
#endif //#ifndef acdbRToS

#ifndef acdbRawAngToF
#define acdbRawAngToF		zcdbRawAngToF
#endif //#ifndef acdbRawAngToF

#ifndef acdbRawAngToS
#define acdbRawAngToS		zcdbRawAngToS
#endif //#ifndef acdbRawAngToS

#ifndef acdbRegApp
#define acdbRegApp		zcdbRegApp
#endif //#ifndef acdbRegApp

#ifndef acdbSNValid
#define acdbSNValid		zcdbSNValid
#endif //#ifndef acdbSNValid

#ifndef acdbTblNext
#define acdbTblNext		zcdbTblNext
#endif //#ifndef acdbTblNext

#ifndef acdbTblObjName
#define acdbTblObjName		zcdbTblObjName
#endif //#ifndef acdbTblObjName

#ifndef acdbTblSearch
#define acdbTblSearch		zcdbTblSearch
#endif //#ifndef acdbTblSearch

#ifndef acedAlert
#define acedAlert		zcedAlert
#endif //#ifndef acedAlert

#ifndef acedArxLoad
#define acedArxLoad		zcedZrxLoad
#endif //#ifndef acedArxLoad

#ifndef acedArxLoaded
#define acedArxLoaded		zcedZrxLoaded
#endif //#ifndef acedArxLoaded

#ifndef acedArxUnload
#define acedArxUnload		zcedZrxUnload
#endif //#ifndef acedArxUnload

#ifndef acedCmd
#define acedCmd		zcedCmd
#endif //#ifndef acedCmd

#ifndef acedCommand
#define acedCommand		zcedCommand
#endif //#ifndef acedCommand

#ifndef acedDefun
#define acedDefun		zcedDefun
#endif //#ifndef acedDefun

#ifndef acedDragGen
#define acedDragGen		zcedDragGen
#endif //#ifndef acedDragGen

#ifndef acedEatCommandThroat
#define acedEatCommandThroat		zcedEatCommandThroat
#endif //#ifndef acedEatCommandThroat

#ifndef acedEntSel
#define acedEntSel		zcedEntSel
#endif //#ifndef acedEntSel

#ifndef acedFNSplit
#define acedFNSplit		zcedFNSplit
#endif //#ifndef acedFNSplit

#ifndef acedFindFile
#define acedFindFile		zcedFindFile
#endif //#ifndef acedFindFile

#ifndef acedGetAngle
#define acedGetAngle		zcedGetAngle
#endif //#ifndef acedGetAngle

#ifndef acedGetAppName
#define acedGetAppName		zcedGetAppName
#endif //#ifndef acedGetAppName

#ifndef acedGetArgs
#define acedGetArgs		zcedGetArgs
#endif //#ifndef acedGetArgs

#ifndef acedGetCName
#define acedGetCName		zcedGetCName
#endif //#ifndef acedGetCName

#ifndef acedGetCfg
#define acedGetCfg		zcedGetCfg
#endif //#ifndef acedGetCfg

#ifndef acedGetCorner
#define acedGetCorner		zcedGetCorner
#endif //#ifndef acedGetCorner

#ifndef acedGetDist
#define acedGetDist		zcedGetDist
#endif //#ifndef acedGetDist

#ifndef acedGetEnv
#define acedGetEnv		zcedGetEnv
#endif //#ifndef acedGetEnv

#ifndef acedGetFileD
#define acedGetFileD		zcedGetFileD
#endif //#ifndef acedGetFileD

#ifndef acedGetFileNavDialog
#define acedGetFileNavDialog		zcedGetFileNavDialog
#endif //#ifndef acedGetFileNavDialog

#ifndef acedGetFullInput
#define acedGetFullInput		zcedGetFullInput
#endif //#ifndef acedGetFullInput

#ifndef acedGetFullKword
#define acedGetFullKword		zcedGetFullKword
#endif //#ifndef acedGetFullKword

#ifndef acedGetFullString
#define acedGetFullString		zcedGetFullString
#endif //#ifndef acedGetFullString

#ifndef acedGetFunCode
#define acedGetFunCode		zcedGetFunCode
#endif //#ifndef acedGetFunCode

#ifndef acedGetInput
#define acedGetInput		zcedGetInput
#endif //#ifndef acedGetInput

#ifndef acedGetInt
#define acedGetInt		zcedGetInt
#endif //#ifndef acedGetInt

#ifndef acedGetKword
#define acedGetKword		zcedGetKword
#endif //#ifndef acedGetKword

#ifndef acedGetOrient
#define acedGetOrient		zcedGetOrient
#endif //#ifndef acedGetOrient

#ifndef acedGetPoint
#define acedGetPoint		zcedGetPoint
#endif //#ifndef acedGetPoint

#ifndef acedGetReal
#define acedGetReal		zcedGetReal
#endif //#ifndef acedGetReal

#ifndef acedGetString
#define acedGetString		zcedGetString
#endif //#ifndef acedGetString

#ifndef acedGetStringB
#define acedGetStringB		zcedGetStringB
#endif //#ifndef acedGetStringB

#ifndef acedGetSym
#define acedGetSym		zcedGetSym
#endif //#ifndef acedGetSym

#ifndef acedGetVar
#define acedGetVar		zcedGetVar
#endif //#ifndef acedGetVar

#ifndef acedGrDraw
#define acedGrDraw		zcedGrDraw
#endif //#ifndef acedGrDraw

#ifndef acedGrRead
#define acedGrRead		zcedGrRead
#endif //#ifndef acedGrRead

#ifndef acedGrText
#define acedGrText		zcedGrText
#endif //#ifndef acedGrText

#ifndef acedGrVecs
#define acedGrVecs		zcedGrVecs
#endif //#ifndef acedGrVecs

#ifndef acedGraphScr
#define acedGraphScr		zcedGraphScr
#endif //#ifndef acedGraphScr

#ifndef acedHelp
#define acedHelp		zcedHelp
#endif //#ifndef acedHelp

#ifndef acedInitGet
#define acedInitGet		zcedInitGet
#endif //#ifndef acedInitGet

#ifndef acedInvoke
#define acedInvoke		zcedInvoke
#endif //#ifndef acedInvoke

#ifndef acedMenuCmd
#define acedMenuCmd		zcedMenuCmd
#endif //#ifndef acedMenuCmd

#ifndef acedNEntSel
#define acedNEntSel		zcedNEntSel
#endif //#ifndef acedNEntSel

#ifndef acedNEntSelP
#define acedNEntSelP		zcedNEntSelP
#endif //#ifndef acedNEntSelP

#ifndef acedNEntSelPEx
#define acedNEntSelPEx		zcedNEntSelPEx
#endif //#ifndef acedNEntSelPEx

#ifndef acedOsnap
#define acedOsnap		zcedOsnap
#endif //#ifndef acedOsnap

#ifndef acedPrompt
#define acedPrompt		zcedPrompt
#endif //#ifndef acedPrompt

#ifndef acedPutSym
#define acedPutSym		zcedPutSym
#endif //#ifndef acedPutSym

#ifndef acedRedraw
#define acedRedraw		zcedRedraw
#endif //#ifndef acedRedraw

#ifndef acedRegFunc
#define acedRegFunc		zcedRegFunc
#endif //#ifndef acedRegFunc

#ifndef acedRetInt
#define acedRetInt		zcedRetInt
#endif //#ifndef acedRetInt

#ifndef acedRetList
#define acedRetList		zcedRetList
#endif //#ifndef acedRetList

#ifndef acedRetName
#define acedRetName		zcedRetName
#endif //#ifndef acedRetName

#ifndef acedRetNil
#define acedRetNil		zcedRetNil
#endif //#ifndef acedRetNil

#ifndef acedRetPoint
#define acedRetPoint		zcedRetPoint
#endif //#ifndef acedRetPoint

#ifndef acedRetReal
#define acedRetReal		zcedRetReal
#endif //#ifndef acedRetReal

#ifndef acedRetStr
#define acedRetStr		zcedRetStr
#endif //#ifndef acedRetStr

#ifndef acedRetT
#define acedRetT		zcedRetT
#endif //#ifndef acedRetT

#ifndef acedRetVal
#define acedRetVal		zcedRetVal
#endif //#ifndef acedRetVal

#ifndef acedRetVoid
#define acedRetVoid		zcedRetVoid
#endif //#ifndef acedRetVoid

#ifndef acedSSAdd
#define acedSSAdd		zcedSSAdd
#endif //#ifndef acedSSAdd

#ifndef acedSSDel
#define acedSSDel		zcedSSDel
#endif //#ifndef acedSSDel

#ifndef acedSSFree
#define acedSSFree		zcedSSFree
#endif //#ifndef acedSSFree

#ifndef acedSSGet
#define acedSSGet		zcedSSGet
#endif //#ifndef acedSSGet

#ifndef acedSSGetFirst
#define acedSSGetFirst		zcedSSGetFirst
#endif //#ifndef acedSSGetFirst

#ifndef acedSSGetKwordCallbackPtr
#define acedSSGetKwordCallbackPtr		zcedSSGetKwordCallbackPtr
#endif //#ifndef acedSSGetKwordCallbackPtr

#ifndef acedSSGetOtherCallbackPtr
#define acedSSGetOtherCallbackPtr		zcedSSGetOtherCallbackPtr
#endif //#ifndef acedSSGetOtherCallbackPtr

#ifndef acedSSLength
#define acedSSLength		zcedSSLength
#endif //#ifndef acedSSLength

#ifndef acedSSMemb
#define acedSSMemb		zcedSSMemb
#endif //#ifndef acedSSMemb

#ifndef acedSSName
#define acedSSName		zcedSSName
#endif //#ifndef acedSSName

#ifndef acedSSNameX
#define acedSSNameX		zcedSSNameX
#endif //#ifndef acedSSNameX

#ifndef acedSSNameXEx
#define acedSSNameXEx		zcedSSNameXEx
#endif //#ifndef acedSSNameXEx

#ifndef acedSSSetFirst
#define acedSSSetFirst		zcedSSSetFirst
#endif //#ifndef acedSSSetFirst

#ifndef acedSSSetKwordCallbackPtr
#define acedSSSetKwordCallbackPtr		zcedSSSetKwordCallbackPtr
#endif //#ifndef acedSSSetKwordCallbackPtr

#ifndef acedSSSetOtherCallbackPtr
#define acedSSSetOtherCallbackPtr		zcedSSSetOtherCallbackPtr
#endif //#ifndef acedSSSetOtherCallbackPtr

#ifndef acedSetCfg
#define acedSetCfg		zcedSetCfg
#endif //#ifndef acedSetCfg

#ifndef acedSetEnv
#define acedSetEnv		zcedSetEnv
#endif //#ifndef acedSetEnv

#ifndef acedSetFunHelp
#define acedSetFunHelp		zcedSetFunHelp
#endif //#ifndef acedSetFunHelp

#ifndef acedSetVar
#define acedSetVar		zcedSetVar
#endif //#ifndef acedSetVar

#ifndef acedSetView
#define acedSetView		zcedSetView
#endif //#ifndef acedSetView

#ifndef acedTablet
#define acedTablet		zcedTablet
#endif //#ifndef acedTablet

#ifndef acedTextBox
#define acedTextBox		zcedTextBox
#endif //#ifndef acedTextBox

#ifndef acedTextPage
#define acedTextPage		zcedTextPage
#endif //#ifndef acedTextPage

#ifndef acedTextScr
#define acedTextScr		zcedTextScr
#endif //#ifndef acedTextScr

#ifndef acedTrans
#define acedTrans		zcedTrans
#endif //#ifndef acedTrans

#ifndef acedUndef
#define acedUndef		zcedUndef
#endif //#ifndef acedUndef

#ifndef acedUpdate
#define acedUpdate		zcedUpdate
#endif //#ifndef acedUpdate

#ifndef acedUsrBrk
#define acedUsrBrk		zcedUsrBrk
#endif //#ifndef acedUsrBrk

#ifndef acedVports
#define acedVports		zcedVports
#endif //#ifndef acedVports

#ifndef acedXformSS
#define acedXformSS		zcedXformSS
#endif //#ifndef acedXformSS

#ifndef acrx_abort
#define acrx_abort		zcrx_abort
#endif //#ifndef acrx_abort

#ifndef ads_matrix
#define ads_matrix		zds_matrix
#endif //#ifndef ads_matrix

#ifndef ads_name
#define ads_name		zds_name
#endif //#ifndef ads_name

#ifndef ads_point
#define ads_point		zds_point
#endif //#ifndef ads_point

#ifndef ads_real
#define ads_real		zds_real
#endif //#ifndef ads_real

#ifndef adsw_acadDocWnd
#define adsw_acadDocWnd		zdsw_zcadDocWnd
#endif //#ifndef adsw_acadDocWnd

#ifndef adsw_acadMainWnd
#define adsw_acadMainWnd		zdsw_zcadMainWnd
#endif //#ifndef adsw_acadMainWnd

#ifndef adsw_hwndAcad
#define adsw_hwndAcad		zdsw_hwndZcad
#endif //#ifndef adsw_hwndAcad


#endif //#ifndef __ACEDADS_H__
