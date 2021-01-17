
#ifndef __DBIDAR_H__
#define __DBIDAR_H__

#include "adesk.h"
#include "assert.h"
#include "acarray.h"

#include "../inc/zdbidar.h"

#ifndef ACAD_OBJID_INLINE_INTERNAL
#define ACAD_OBJID_INLINE_INTERNAL		ZCAD_OBJID_INLINE_INTERNAL
#endif //#ifndef ACAD_OBJID_INLINE_INTERNAL

#ifndef AD_OBJID_INLINE_INTERNAL
#define AD_OBJID_INLINE_INTERNAL		ZD_OBJID_INLINE_INTERNAL
#endif //#ifndef AD_OBJID_INLINE_INTERNAL

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#endif //#ifndef __DBIDAR_H__
