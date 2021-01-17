
#ifndef __DBFRAME_H__
#define __DBFRAME_H__

#include "dbmain.h"
#include "gepnt3d.h"

#include "../inc/zdbframe.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbFrame
#define AcDbFrame		ZcDbFrame
#endif //#ifndef AcDbFrame

#endif //#ifndef __DBFRAME_H__
