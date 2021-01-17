
#ifndef __DBDICTDFLT_H__
#define __DBDICTDFLT_H__

#include "dbdict.h"

#include "../inc/zdbdictdflt.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDictionary
#define AcDbDictionary		ZcDbDictionary
#endif //#ifndef AcDbDictionary

#ifndef AcDbDictionaryWithDefault
#define AcDbDictionaryWithDefault		ZcDbDictionaryWithDefault
#endif //#ifndef AcDbDictionaryWithDefault

#ifndef AcDbDwgVersion
#define AcDbDwgVersion		ZcDbDwgVersion
#endif //#ifndef AcDbDwgVersion

#ifndef AcDbImpDictionaryWithDefault
#define AcDbImpDictionaryWithDefault		ZcDbImpDictionaryWithDefault
#endif //#ifndef AcDbImpDictionaryWithDefault

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBDICTDFLT_H__
