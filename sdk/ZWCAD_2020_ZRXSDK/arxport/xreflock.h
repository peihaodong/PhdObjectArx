
#ifndef __XREFLOCK_H__
#define __XREFLOCK_H__

#include "rxnames.h"
#include "dbidar.h"

#include "../inc/zxreflock.h"

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDwgFileHandle
#define AcDwgFileHandle		ZcDwgFileHandle
#endif //#ifndef AcDwgFileHandle

#ifndef AcEdXrefFileLock
#define AcEdXrefFileLock		ZcEdXrefFileLock
#endif //#ifndef AcEdXrefFileLock

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __XREFLOCK_H__
