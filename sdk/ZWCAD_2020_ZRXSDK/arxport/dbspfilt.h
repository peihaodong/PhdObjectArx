
#ifndef __DBSPFILT_H__
#define __DBSPFILT_H__

#include "dbfilter.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#include "gept2dar.h"

#include "../inc/zdbspfilt.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACDB_INFINITE_XCLIP_DEPTH
#define ACDB_INFINITE_XCLIP_DEPTH		ZCDB_INFINITE_XCLIP_DEPTH
#endif //#ifndef ACDB_INFINITE_XCLIP_DEPTH

#ifndef AcDbBlockReference
#define AcDbBlockReference		ZcDbBlockReference
#endif //#ifndef AcDbBlockReference

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbFilter
#define AcDbFilter		ZcDbFilter
#endif //#ifndef AcDbFilter

#ifndef AcDbSpatialFilter
#define AcDbSpatialFilter		ZcDbSpatialFilter
#endif //#ifndef AcDbSpatialFilter

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint2dArray
#define AcGePoint2dArray		ZcGePoint2dArray
#endif //#ifndef AcGePoint2dArray

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __DBSPFILT_H__
