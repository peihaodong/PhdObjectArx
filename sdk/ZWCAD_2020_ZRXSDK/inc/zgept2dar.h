

#ifndef ZC_GEPT2DAR_H
#define ZC_GEPT2DAR_H

#include "zadesk.h"
#include "assert.h"
#include "zgepnt2d.h"

#include "zacarray.h"
typedef ZcArray<ZcGePoint2d> ZcGePoint2dArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGePoint2dArray* pT);
#endif

#endif
