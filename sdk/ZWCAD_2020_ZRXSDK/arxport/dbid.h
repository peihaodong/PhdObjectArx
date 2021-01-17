
#ifndef __DBID_H__
#define __DBID_H__

#include "adesk.h"
#include "dbhandle.h"

#include "../inc/zdbid.h"

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbHandle
#define AcDbHandle		ZcDbHandle
#endif //#ifndef AcDbHandle

#ifndef AcDbHardOwnershipId
#define AcDbHardOwnershipId		ZcDbHardOwnershipId
#endif //#ifndef AcDbHardOwnershipId

#ifndef AcDbHardPointerId
#define AcDbHardPointerId		ZcDbHardPointerId
#endif //#ifndef AcDbHardPointerId

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSoftOwnershipId
#define AcDbSoftOwnershipId		ZcDbSoftOwnershipId
#endif //#ifndef AcDbSoftOwnershipId

#ifndef AcDbSoftPointerId
#define AcDbSoftPointerId		ZcDbSoftPointerId
#endif //#ifndef AcDbSoftPointerId

#ifndef AcDbStub
#define AcDbStub		ZcDbStub
#endif //#ifndef AcDbStub

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBID_H__
