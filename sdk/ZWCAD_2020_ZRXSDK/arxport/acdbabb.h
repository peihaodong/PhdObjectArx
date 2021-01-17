
#ifndef __ACDBABB_H__
#define __ACDBABB_H__
#include "acdb.h"

#include "../inc/zacdbabb.h"

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef eFileLockedByACAD
#define eFileLockedByACAD		eFileLockedByZCAD
#endif //#ifndef eFileLockedByACAD

#endif //#ifndef __ACDBABB_H__
