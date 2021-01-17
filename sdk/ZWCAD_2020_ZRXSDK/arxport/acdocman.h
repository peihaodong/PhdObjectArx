
#ifndef __ACDOCMAN_H__
#define __ACDOCMAN_H__

#include "adesk.h"
#ifdef _ZSOFT_WINDOWS_
#include <wtypes.h>
#endif

#include "acdb.h"

#include "../inc/zacdocman.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AC_DOCUMENT_MANAGER_OBJ
#define AC_DOCUMENT_MANAGER_OBJ		ZC_DOCUMENT_MANAGER_OBJ
#endif //#ifndef AC_DOCUMENT_MANAGER_OBJ

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcAp
#define AcAp		ZcAp
#endif //#ifndef AcAp

#ifndef AcApDocImpManager
#define AcApDocImpManager		ZcApDocImpManager
#endif //#ifndef AcApDocImpManager

#ifndef AcApDocManager
#define AcApDocManager		ZcApDocManager
#endif //#ifndef AcApDocManager

#ifndef AcApDocManagerReactor
#define AcApDocManagerReactor		ZcApDocManagerReactor
#endif //#ifndef AcApDocManagerReactor

#ifndef AcApDocument
#define AcApDocument		ZcApDocument
#endif //#ifndef AcApDocument

#ifndef AcApDocumentIterator
#define AcApDocumentIterator		ZcApDocumentIterator
#endif //#ifndef AcApDocumentIterator

#ifndef AcApPlotReactor
#define AcApPlotReactor		ZcApPlotReactor
#endif //#ifndef AcApPlotReactor

#ifndef AcApStatusBar
#define AcApStatusBar		ZcApStatusBar
#endif //#ifndef AcApStatusBar

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcEdInputPointManager
#define AcEdInputPointManager		ZcEdInputPointManager
#endif //#ifndef AcEdInputPointManager

#ifndef AcLispAppInfo
#define AcLispAppInfo		ZcLispAppInfo
#endif //#ifndef AcLispAppInfo

#ifndef AcRxIterator
#define AcRxIterator		ZcRxIterator
#endif //#ifndef AcRxIterator

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcTransactionManager
#define AcTransactionManager		ZcTransactionManager
#endif //#ifndef AcTransactionManager

#ifndef AcTransaction
#define AcTransaction		ZcTransaction
#endif //#ifndef AcTransaction

#ifndef AcTransactionReactor
#define AcTransactionReactor		ZcTransactionReactor
#endif //#ifndef AcTransactionReactor

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acDocManager
#define acDocManager		zcDocManager
#endif //#ifndef acDocManager

#ifndef acDocManagerPtr
#define acDocManagerPtr		zcDocManagerPtr
#endif //#ifndef acDocManagerPtr

#ifndef newAcApDocumentIterator
#define newAcApDocumentIterator		newZcApDocumentIterator
#endif //#ifndef newAcApDocumentIterator

#ifndef pushAcadResourceHandle
#define pushAcadResourceHandle		pushZcadResourceHandle
#endif //#ifndef pushAcadResourceHandle

#endif //#ifndef __ACDOCMAN_H__
