

#ifndef ZC_DBIDAR_H
#define ZC_DBIDAR_H

#include "zadesk.h"
#include "assert.h"

#ifdef ZCAD_OBJID_INLINE_INTERNAL
#include "dbidinln.h"
#else
#include "zdbidapps.h"
#endif
#include "zacarray.h"
typedef ZcArray<ZcDbObjectId> ZcDbObjectIdArray;
#endif
