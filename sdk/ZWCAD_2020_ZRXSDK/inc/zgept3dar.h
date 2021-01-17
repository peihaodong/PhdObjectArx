

#ifndef ZC_GEPT3DAR_H
#define ZC_GEPT3DAR_H

#include "zadesk.h"
#include "assert.h"
#include "zgepnt3d.h"

#include "zacarray.h"
typedef ZcArray<ZcGePoint3d> ZcGePoint3dArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGePoint3dArray* pT);
#endif

#endif
