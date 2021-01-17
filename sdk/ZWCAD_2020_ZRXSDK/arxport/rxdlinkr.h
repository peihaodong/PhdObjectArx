
#ifndef __RXDLINKR_H__
#define __RXDLINKR_H__

#include "rxobject.h"
#include "AdAChar.h"

#include "../inc/zrxdlinkr.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_DYNAMIC_LINKER
#define ACRX_DYNAMIC_LINKER		ZCRX_DYNAMIC_LINKER
#endif //#ifndef ACRX_DYNAMIC_LINKER

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AD_UNICODE
#ifdef  ZW_UNICODE_SWITCH
#define AD_UNICODE		ZD_UNICODE
#endif
#endif //#ifndef AD_UNICODE

#ifndef AcRxDLinkerReactor
#define AcRxDLinkerReactor		ZcRxDLinkerReactor
#endif //#ifndef AcRxDLinkerReactor

#ifndef AcRxDynamicLinker
#define AcRxDynamicLinker		ZcRxDynamicLinker
#endif //#ifndef AcRxDynamicLinker

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcRxService
#define AcRxService		ZcRxService
#endif //#ifndef AcRxService

#ifndef AcadApp
#define AcadApp		ZcadApp
#endif //#ifndef AcadApp

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acrxDynamicLinker
#define acrxDynamicLinker		zcrxDynamicLinker
#endif //#ifndef acrxDynamicLinker

#ifndef acrxSysRegistry
#define acrxSysRegistry		zcrxSysRegistry
#endif //#ifndef acrxSysRegistry

#ifndef kOnAutoCADStartup
#define kOnAutoCADStartup		kOnZWCADStartup
#endif //#ifndef kOnAutoCADStartup

#endif //#ifndef __RXDLINKR_H__
