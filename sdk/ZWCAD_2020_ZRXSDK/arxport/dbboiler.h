
#ifndef __DBBOILER_H__
#define __DBBOILER_H__

#include "rxboiler.h"

#include "../inc/zdbboiler.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbSystemInternals
#define AcDbSystemInternals		ZcDbSystemInternals
#endif //#ifndef AcDbSystemInternals

#ifndef MAKE_ACDBOPENOBJECT_FUNCTION
#define MAKE_ACDBOPENOBJECT_FUNCTION		MAKE_ZCDBOPENOBJECT_FUNCTION
#endif //#ifndef MAKE_ACDBOPENOBJECT_FUNCTION

#endif //#ifndef __DBBOILER_H__
