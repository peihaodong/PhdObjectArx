
#ifndef __ARXENTRYPOINT_H__
#define __ARXENTRYPOINT_H__

#include "dbxEntryPoint.h"

#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

#include "../inc/zarxEntryPoint.h"

#ifndef ACED_ADSCOMMAND_ENTRYBYID_AUTO
#define ACED_ADSCOMMAND_ENTRYBYID_AUTO		ZCED_ZDSCOMMAND_ENTRYBYID_AUTO
#endif //#ifndef ACED_ADSCOMMAND_ENTRYBYID_AUTO

#ifndef ACED_ADSCOMMAND_ENTRY_AUTO
#define ACED_ADSCOMMAND_ENTRY_AUTO		ZCED_ZDSCOMMAND_ENTRY_AUTO
#endif //#ifndef ACED_ADSCOMMAND_ENTRY_AUTO

#ifndef ACED_ADSSYMBOL_ENTRYBYID_AUTO
#define ACED_ADSSYMBOL_ENTRYBYID_AUTO		ZCED_ZDSSYMBOL_ENTRYBYID_AUTO
#endif //#ifndef ACED_ADSSYMBOL_ENTRYBYID_AUTO

#ifndef ACED_ADSSYMBOL_ENTRY_AUTO
#define ACED_ADSSYMBOL_ENTRY_AUTO		ZCED_ZDSSYMBOL_ENTRY_AUTO
#endif //#ifndef ACED_ADSSYMBOL_ENTRY_AUTO

#ifndef ACED_ADSSYMBOL_ENTRY_PRAGMA
#define ACED_ADSSYMBOL_ENTRY_PRAGMA		ZCED_ZDSSYMBOL_ENTRY_PRAGMA
#endif //#ifndef ACED_ADSSYMBOL_ENTRY_PRAGMA

#ifndef ACED_ARXCOMMAND_ENTRYBYID_AUTO
#define ACED_ARXCOMMAND_ENTRYBYID_AUTO		ZCED_ZRXCOMMAND_ENTRYBYID_AUTO
#endif //#ifndef ACED_ARXCOMMAND_ENTRYBYID_AUTO

#ifndef ACED_ARXCOMMAND_ENTRY_AUTO
#define ACED_ARXCOMMAND_ENTRY_AUTO		ZCED_ZRXCOMMAND_ENTRY_AUTO
#endif //#ifndef ACED_ARXCOMMAND_ENTRY_AUTO

#ifndef ACED_ARXCOMMAND_ENTRY_PRAGMA
#define ACED_ARXCOMMAND_ENTRY_PRAGMA		ZCED_ZRXCOMMAND_ENTRY_PRAGMA
#endif //#ifndef ACED_ARXCOMMAND_ENTRY_PRAGMA

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_CMD_SESSION
#define ACRX_CMD_SESSION		ZCRX_CMD_SESSION
#endif //#ifndef ACRX_CMD_SESSION

#ifndef AcEdUIContext
#define AcEdUIContext		ZcEdUIContext
#endif //#ifndef AcEdUIContext

#ifndef AcRx
#define AcRx		ZcRx
#endif //#ifndef AcRx

#ifndef AcRxArxApp
#define AcRxArxApp		ZcRxZrxApp
#endif //#ifndef AcRxArxApp

#ifndef AcRxDbxApp
#define AcRxDbxApp		ZcRxDbxApp
#endif //#ifndef AcRxDbxApp

#ifndef AcRxDynPropManager
#define AcRxDynPropManager		ZcRxDynPropManager
#endif //#ifndef AcRxDynPropManager

#ifndef AcRxFunctionPtr
#define AcRxFunctionPtr		ZcRxFunctionPtr
#endif //#ifndef AcRxFunctionPtr

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef _ADSSYMBOL_ENTRY
#define _ADSSYMBOL_ENTRY		_ZDSSYMBOL_ENTRY
#endif //#ifndef _ADSSYMBOL_ENTRY

#ifndef acedDefun
#define acedDefun		zcedDefun
#endif //#ifndef acedDefun

#ifndef acedGetFunCode
#define acedGetFunCode		zcedGetFunCode
#endif //#ifndef acedGetFunCode

#ifndef acedRegCmds
#define acedRegCmds		zcedRegCmds
#endif //#ifndef acedRegCmds

#ifndef acedRegFunc
#define acedRegFunc		zcedRegFunc
#endif //#ifndef acedRegFunc

#ifndef acedUndef
#define acedUndef		zcedUndef
#endif //#ifndef acedUndef

#ifndef ads_
#define ads_		zds_
#endif //#ifndef ads_

#ifndef _ARXCOMMAND_ENTRY
#define _ARXCOMMAND_ENTRY		_ZRXCOMMAND_ENTRY
#endif //#ifndef _ARXCOMMAND_ENTRY

#ifndef __pArxCmdMapEntryFirst
#define __pArxCmdMapEntryFirst		__pZrxCmdMapEntryFirst
#endif //#ifndef __pArxCmdMapEntryFirst

#ifndef __pArxCmdMapEntryLast
#define __pArxCmdMapEntryLast		__pZrxCmdMapEntryLast
#endif //#ifndef __pArxCmdMapEntryLast

#ifndef ppArxCmdMapEntryFirst
#define ppArxCmdMapEntryFirst		ppZrxCmdMapEntryFirst
#endif //#ifndef ppArxCmdMapEntryFirst

#ifndef ppArxCmdMapEntryLast
#define ppArxCmdMapEntryLast		ppZrxCmdMapEntryLast
#endif //#ifndef ppArxCmdMapEntryLast

#ifndef __pArxCmdMapEntryFirst
#define __pArxCmdMapEntryFirst		__pZrxCmdMapEntryFirst
#endif //#ifndef __pArxCmdMapEntryFirst

#ifndef __pArxCmdMapEntryLast
#define __pArxCmdMapEntryLast		__pZrxCmdMapEntryLast
#endif //#ifndef __pArxCmdMapEntryLast

#ifndef ppAdsSymbolMapEntryFirst
#define ppAdsSymbolMapEntryFirst	ppZdsSymbolMapEntryFirst
#endif //#ifndef ppAdsSymbolMapEntryFirst

#ifndef ppAdsSymbolMapEntryLast
#define ppAdsSymbolMapEntryLast		ppZdsSymbolMapEntryLast
#endif //#ifndef ppAdsSymbolMapEntryLast

#ifndef __pAdsSymbolMapEntryFirst
#define __pAdsSymbolMapEntryFirst   __pZdsSymbolMapEntryFirst
#endif //#ifndef __pAdsSymbolMapEntryFirst

#ifndef __pAdsSymbolMapEntryLast
#define __pAdsSymbolMapEntryLast	__pZdsSymbolMapEntryLast
#endif //#ifndef __pAdsSymbolMapEntryLast

#endif //#ifndef __ARXENTRYPOINT_H__
