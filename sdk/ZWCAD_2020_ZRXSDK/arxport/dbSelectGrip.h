
#ifndef __DBSELECTGRIP_H__
#define __DBSELECTGRIP_H__

#include "acdb.h"
#include "dbmain.h"

#include "../inc/zdbSelectGrip.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbSelectGrip
#define AcDbSelectGrip		ZcDbSelectGrip
#endif //#ifndef AcDbSelectGrip

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#endif //#ifndef __DBSELECTGRIP_H__
