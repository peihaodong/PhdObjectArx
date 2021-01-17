
#ifndef __ACEDSEL_H__
#define __ACEDSEL_H__

#include "AcArray.h"
#include "dbid.h"
#include "dbsubeid.h"

#include "../inc/zacedsel.h"

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef AcEdSolidSubentitySelector
#define AcEdSolidSubentitySelector		ZcEdSolidSubentitySelector
#endif //#ifndef AcEdSolidSubentitySelector

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __ACEDSEL_H__
