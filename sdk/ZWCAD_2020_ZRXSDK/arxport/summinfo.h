
#ifndef __SUMMINFO_H__
#define __SUMMINFO_H__

#include "adesk.h"

#include "../inc/zsumminfo.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDatabaseSummaryInfo
#define AcDbDatabaseSummaryInfo		ZcDbDatabaseSummaryInfo
#endif //#ifndef AcDbDatabaseSummaryInfo

#ifndef AcDbSummaryInfoManager
#define AcDbSummaryInfoManager		ZcDbSummaryInfoManager
#endif //#ifndef AcDbSummaryInfoManager

#ifndef AcDbSummaryInfoReactor
#define AcDbSummaryInfoReactor		ZcDbSummaryInfoReactor
#endif //#ifndef AcDbSummaryInfoReactor

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbGetSummaryInfo
#define acdbGetSummaryInfo		zcdbGetSummaryInfo
#endif //#ifndef acdbGetSummaryInfo

#ifndef acdbPutSummaryInfo
#define acdbPutSummaryInfo		zcdbPutSummaryInfo
#endif //#ifndef acdbPutSummaryInfo

#ifndef acdbSummaryInfoManager
#define acdbSummaryInfoManager		zcdbSummaryInfoManager
#endif //#ifndef acdbSummaryInfoManager

#ifndef deleteAcDbSummaryInfoManager
#define deleteAcDbSummaryInfoManager		deleteZcDbSummaryInfoManager
#endif //#ifndef deleteAcDbSummaryInfoManager

#ifndef initAcDbSummaryInfoManager
#define initAcDbSummaryInfoManager		initZcDbSummaryInfoManager
#endif //#ifndef initAcDbSummaryInfoManager

#endif //#ifndef __SUMMINFO_H__
