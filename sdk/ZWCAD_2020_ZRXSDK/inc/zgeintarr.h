

#ifndef ZC_GEINTARR_H
#define ZC_GEINTARR_H

#ifndef unix
#include <stdlib.h>
#endif
#include "zadesk.h"
#include "assert.h"

#include "zacarray.h"
typedef ZcArray<int> ZcGeIntArray;
typedef ZcArray<ZSoft::IntPtr> ZcGeIntPtrArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
ZcGe::metaTypeIndex ZcGeGetMetaTypeIndex(ZcGeIntArray* pT);
#endif
#endif
