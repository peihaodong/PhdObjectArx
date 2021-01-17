
#ifndef __DBUNDERLAYDEF_H__
#define __DBUNDERLAYDEF_H__

#include "dbmain.h"
#include "acstring.h"

#include "../inc/zdbunderlaydef.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDbDgnDefinition
#define AcDbDgnDefinition		ZcDbDgnDefinition
#endif //#ifndef AcDbDgnDefinition

#ifndef AcDbDwfDefinition
#define AcDbDwfDefinition		ZcDbDwfDefinition
#endif //#ifndef AcDbDwfDefinition

#ifndef AcDbPdfDefinition
#define AcDbPdfDefinition		ZcDbPdfDefinition
#endif //#ifndef AcDbPdfDefinition

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbUnderlayDefinition
#define AcDbUnderlayDefinition		ZcDbUnderlayDefinition
#endif //#ifndef AcDbUnderlayDefinition

#ifndef AcDbUnderlayHost
#define AcDbUnderlayHost		ZcDbUnderlayHost
#endif //#ifndef AcDbUnderlayHost

#ifndef AcDbUnderlayItem
#define AcDbUnderlayItem		ZcDbUnderlayItem
#endif //#ifndef AcDbUnderlayItem

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBUNDERLAYDEF_H__
