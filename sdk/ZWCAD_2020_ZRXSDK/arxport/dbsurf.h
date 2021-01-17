

#ifndef __DBSURF_H__
#define __DBSURF_H__

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "dbbody.h"
#include "dbRevolveOptions.h"
#include "dbSweepOptions.h"
#include "dbLoftOptions.h"

#include "../inc/zdbsurf.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDb3dSolid
#define AcDb3dSolid		ZcDb3dSolid
#endif //#ifndef AcDb3dSolid

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef AcDbSurface
#define AcDbSurface		ZcDbSurface
#endif //#ifndef AcDbSurface

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBSURF_H__
