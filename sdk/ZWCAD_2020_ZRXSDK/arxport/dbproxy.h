
#ifndef __DBPROXY_H__
#define __DBPROXY_H__

#include "dbmain.h"
#include <dbintar.h>

#include "../inc/zdbproxy.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbProxyEntity
#define AcDbProxyEntity		ZcDbProxyEntity
#endif //#ifndef AcDbProxyEntity

#ifndef AcDbProxyObject
#define AcDbProxyObject		ZcDbProxyObject
#endif //#ifndef AcDbProxyObject

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBPROXY_H__
