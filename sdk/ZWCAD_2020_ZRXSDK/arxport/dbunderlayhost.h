
#ifndef __DBUNDERLAYHOST_H__
#define __DBUNDERLAYHOST_H__

#include "dbmain.h"
#include "acstring.h"

#include "../inc/zdbunderlayhost.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbDgnUnderlayItem
#define AcDbDgnUnderlayItem		ZcDbDgnUnderlayItem
#endif //#ifndef AcDbDgnUnderlayItem

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbIntArray
#define AcDbIntArray		ZcDbIntArray
#endif //#ifndef AcDbIntArray

#ifndef AcDbUnderlayDrawContext
#define AcDbUnderlayDrawContext		ZcDbUnderlayDrawContext
#endif //#ifndef AcDbUnderlayDrawContext

#ifndef AcDbUnderlayFile
#define AcDbUnderlayFile		ZcDbUnderlayFile
#endif //#ifndef AcDbUnderlayFile

#ifndef AcDbUnderlayHost
#define AcDbUnderlayHost		ZcDbUnderlayHost
#endif //#ifndef AcDbUnderlayHost

#ifndef IAcReadStream
#define IAcReadStream			IZcReadStream
#endif 

#ifndef AcDbUnderlayItem
#define AcDbUnderlayItem		ZcDbUnderlayItem
#endif //#ifndef AcDbUnderlayItem

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePlane
#define AcGePlane		ZcGePlane
#endif //#ifndef AcGePlane

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGePoint3dArray
#define AcGePoint3dArray		ZcGePoint3dArray
#endif //#ifndef AcGePoint3dArray

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcImpUnderlayLayer
#define AcImpUnderlayLayer		ZcImpUnderlayLayer
#endif //#ifndef AcImpUnderlayLayer

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcUnderlayLayer
#define AcUnderlayLayer		ZcUnderlayLayer
#endif //#ifndef AcUnderlayLayer

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acdbConvertHslToRgb
#define acdbConvertHslToRgb		zcdbConvertHslToRgb
#endif //#ifndef acdbConvertHslToRgb

#ifndef acdbConvertRgbToHsl
#define acdbConvertRgbToHsl		zcdbConvertRgbToHsl
#endif //#ifndef acdbConvertRgbToHsl

#ifndef acdbGetCurrentDgnDocHost
#define acdbGetCurrentDgnDocHost		zcdbGetCurrentDgnDocHost
#endif //#ifndef acdbGetCurrentDgnDocHost

#ifndef acdbGetCurrentDgnHost
#define acdbGetCurrentDgnHost		zcdbGetCurrentDgnHost
#endif //#ifndef acdbGetCurrentDgnHost

#ifndef acdbGetCurrentDwfHost
#define acdbGetCurrentDwfHost		zcdbGetCurrentDwfHost
#endif //#ifndef acdbGetCurrentDwfHost

#ifndef acdbSetCurrentDgnDocHost
#define acdbSetCurrentDgnDocHost		zcdbSetCurrentDgnDocHost
#endif //#ifndef acdbSetCurrentDgnDocHost

#ifndef acdbSetCurrentDgnHost
#define acdbSetCurrentDgnHost		zcdbSetCurrentDgnHost
#endif //#ifndef acdbSetCurrentDgnHost

#ifndef acdbSetCurrentDwfHost
#define acdbSetCurrentDwfHost		zcdbSetCurrentDwfHost
#endif //#ifndef acdbSetCurrentDwfHost

#endif //#ifndef __DBUNDERLAYHOST_H__