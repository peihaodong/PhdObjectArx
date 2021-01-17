
#ifndef __DBSPLINE_H__
#define __DBSPLINE_H__

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"

#include "../inc/zdbspline.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDbCurve
#define AcDbCurve		ZcDbCurve
#endif //#ifndef AcDbCurve

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

#ifndef AcDbVoidPtrArray
#define AcDbVoidPtrArray		ZcDbVoidPtrArray
#endif //#ifndef AcDbVoidPtrArray

#ifndef AcGeDoubleArray
#define AcGeDoubleArray		ZcGeDoubleArray
#endif //#ifndef AcGeDoubleArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBSPLINE_H__
