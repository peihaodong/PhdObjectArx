
#ifndef __DBSECTION_H__
#define __DBSECTION_H__

#include "AdAChar.h"
#include "dbhatch.h"
#include "acstring.h"

#include "../inc/zDbSection.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbGripDataPtrArray
#define AcDbGripDataPtrArray		ZcDbGripDataPtrArray
#endif //#ifndef AcDbGripDataPtrArray

#ifndef AcDbHatch
#define AcDbHatch		ZcDbHatch
#endif //#ifndef AcDbHatch

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbSection
#define AcDbSection		ZcDbSection
#endif //#ifndef AcDbSection

#ifndef AcDbSectionSettings
#define AcDbSectionSettings		ZcDbSectionSettings
#endif //#ifndef AcDbSectionSettings

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBSECTION_H__
