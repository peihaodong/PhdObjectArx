
#ifndef __DBRAY_H__
#define __DBRAY_H__

#include "dbmain.h"
#include "dbcurve.h"

#include "../inc/zdbray.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDbCurve
#define AcDbCurve		ZcDbCurve
#endif //#ifndef AcDbCurve

#ifndef AcDbRay
#define AcDbRay		ZcDbRay
#endif //#ifndef AcDbRay

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBRAY_H__
