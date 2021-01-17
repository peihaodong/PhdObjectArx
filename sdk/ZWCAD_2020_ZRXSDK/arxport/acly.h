
#ifndef __ACLY_H__
#define __ACLY_H__

#include "AdAChar.h"
#include "acadstrc.h"
#include "acarray.h"
#include "dbsymtb.h"
#include "dbxrecrd.h"

#include "../inc/zacly.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbDxfFiler
#define AcDbDxfFiler		ZcDbDxfFiler
#endif //#ifndef AcDbDxfFiler

#ifndef AcDbLayerTableRecord
#define AcDbLayerTableRecord		ZcDbLayerTableRecord
#endif //#ifndef AcDbLayerTableRecord

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef AcLyAndExpr
#define AcLyAndExpr		ZcLyAndExpr
#endif //#ifndef AcLyAndExpr

#ifndef AcLyBoolExpr
#define AcLyBoolExpr		ZcLyBoolExpr
#endif //#ifndef AcLyBoolExpr

#ifndef AcLyLayerFilter
#define AcLyLayerFilter		ZcLyLayerFilter
#endif //#ifndef AcLyLayerFilter

#ifndef AcLyLayerFilterManager
#define AcLyLayerFilterManager		ZcLyLayerFilterManager
#endif //#ifndef AcLyLayerFilterManager

#ifndef AcLyLayerGroup
#define AcLyLayerGroup		ZcLyLayerGroup
#endif //#ifndef AcLyLayerGroup

#ifndef AcLyRelExpr
#define AcLyRelExpr		ZcLyRelExpr
#endif //#ifndef AcLyRelExpr

#ifndef AcLySystemInternals
#define AcLySystemInternals		ZcLySystemInternals
#endif //#ifndef AcLySystemInternals

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef aclyGetLayerFilterManager
#define aclyGetLayerFilterManager		zclyGetLayerFilterManager
#endif //#ifndef aclyGetLayerFilterManager

#endif //#ifndef __ACLY_H__
