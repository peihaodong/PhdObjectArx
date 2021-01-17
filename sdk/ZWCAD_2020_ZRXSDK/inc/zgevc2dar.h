

#ifndef ZC_GEVC2DAR_H
#define ZC_GEVC2DAR_H

#include "zadesk.h"
#include "assert.h"
#include "zgevec2d.h"

#include "zacarray.h"
typedef ZcArray<ZcGeVector2d> ZcGeVector2dArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGeVector2dArray* pT);
#endif

#endif
