
#ifndef __DBHELIX_H__
#define __DBHELIX_H__

#include "gegbl.h"
#include "dbmain.h"
#include "dbspline.h"

#include "../inc/zdbhelix.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbHelix
#define AcDbHelix		ZcDbHelix
#endif //#ifndef AcDbHelix

#ifndef AcDbSpline
#define AcDbSpline		ZcDbSpline
#endif //#ifndef AcDbSpline

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

#endif //#ifndef __DBHELIX_H__
