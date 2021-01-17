
#ifndef __DBIDMAP_H__
#define __DBIDMAP_H__

#include "acdb.h"
#include "rxobject.h"

#include "../inc/zdbidmap.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbIdMappingIter
#define AcDbIdMappingIter		ZcDbIdMappingIter
#endif //#ifndef AcDbIdMappingIter

#ifndef AcDbIdPair
#define AcDbIdPair		ZcDbIdPair
#endif //#ifndef AcDbIdPair

#ifndef AcDbImpIdMapping
#define AcDbImpIdMapping		ZcDbImpIdMapping
#endif //#ifndef AcDbImpIdMapping

#ifndef AcDbImpIdMappingIter
#define AcDbImpIdMappingIter		ZcDbImpIdMappingIter
#endif //#ifndef AcDbImpIdMappingIter

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSystemInternals
#define AcDbSystemInternals		ZcDbSystemInternals
#endif //#ifndef AcDbSystemInternals

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __DBIDMAP_H__
