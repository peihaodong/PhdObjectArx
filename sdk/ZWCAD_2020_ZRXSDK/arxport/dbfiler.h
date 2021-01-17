
#ifndef __DBFILER_H__
#define __DBFILER_H__

#include <stdarg.h>
#include "AdAChar.h"
#include "acdb.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "gescl3d.h"
#include "adsdef.h"

#include "../inc/zdbfiler.h"


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

#ifndef AcDbAuditInfo
#define AcDbAuditInfo		ZcDbAuditInfo
#endif //#ifndef AcDbAuditInfo

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDwgVersion
#define AcDbDwgVersion		ZcDbDwgVersion
#endif //#ifndef AcDbDwgVersion

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbFilerController
#define AcDbFilerController		ZcDbFilerController
#endif //#ifndef AcDbFilerController

#ifndef AcDbHandle
#define AcDbHandle		ZcDbHandle
#endif //#ifndef AcDbHandle

#ifndef AcDbHardOwnershipId
#define AcDbHardOwnershipId		ZcDbHardOwnershipId
#endif //#ifndef AcDbHardOwnershipId

#ifndef AcDbHardPointerId
#define AcDbHardPointerId		ZcDbHardPointerId
#endif //#ifndef AcDbHardPointerId

#ifndef AcDbIdRefQueue
#define AcDbIdRefQueue		ZcDbIdRefQueue
#endif //#ifndef AcDbIdRefQueue

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSoftOwnershipId
#define AcDbSoftOwnershipId		ZcDbSoftOwnershipId
#endif //#ifndef AcDbSoftOwnershipId

#ifndef AcDbSoftPointerId
#define AcDbSoftPointerId		ZcDbSoftPointerId
#endif //#ifndef AcDbSoftPointerId

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeScale3d
#define AcGeScale3d		ZcGeScale3d
#endif //#ifndef AcGeScale3d

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef Adesk_Boolean_is_bool
#define Adesk_Boolean_is_bool		ZSoft_Boolean_is_bool
#endif //#ifndef Adesk_Boolean_is_bool

#ifndef ads_binary
#define ads_binary		zds_binary
#endif //#ifndef ads_binary

#ifndef readAcDbHandle
#define readAcDbHandle		readZcDbHandle
#endif //#ifndef readAcDbHandle

#ifndef writeAcDbHandle
#define writeAcDbHandle		writeZcDbHandle
#endif //#ifndef writeAcDbHandle

#endif //#ifndef __DBFILER_H__
