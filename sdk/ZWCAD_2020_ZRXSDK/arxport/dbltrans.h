
#ifndef __DBLTRANS_H__
#define __DBLTRANS_H__

#include "dbmain.h"
#include "AdAChar.h"

#include "../inc/zdbltrans.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbLongTransWorkSetIterator
#define AcDbLongTransWorkSetIterator		ZcDbLongTransWorkSetIterator
#endif //#ifndef AcDbLongTransWorkSetIterator

#ifndef AcDbLongTransaction
#define AcDbLongTransaction		ZcDbLongTransaction
#endif //#ifndef AcDbLongTransaction

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBLTRANS_H__
