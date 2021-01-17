
#ifndef __DBOBJECTCONTEXTCOLLECTION_H__
#define __DBOBJECTCONTEXTCOLLECTION_H__

#include "acdb.h"
#include "dbmain.h"
#include "AcString.h"
#include "dbObjContext.h"

#include "../inc/zdbObjectContextCollection.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectContext
#define AcDbObjectContext		ZcDbObjectContext
#endif //#ifndef AcDbObjectContext

#ifndef AcDbObjectContextCollection
#define AcDbObjectContextCollection		ZcDbObjectContextCollection
#endif //#ifndef AcDbObjectContextCollection

#ifndef AcDbObjectContextCollectionIterator
#define AcDbObjectContextCollectionIterator		ZcDbObjectContextCollectionIterator
#endif //#ifndef AcDbObjectContextCollectionIterator

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBOBJECTCONTEXTCOLLECTION_H__
