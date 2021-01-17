
#ifndef __ACARRAY_H__
#define __ACARRAY_H__

#include <memory.h>     
#include <stdlib.h>
#include "adesk.h"
#include "assert.h"

#include "../inc/zacarray.h"

#ifndef ACARRAY_GROWTH_THRESHOLD
#define ACARRAY_GROWTH_THRESHOLD		ZCARRAY_GROWTH_THRESHOLD
#endif //#ifndef ACARRAY_GROWTH_THRESHOLD

#ifndef AC_ARRAY_ASSERT
#define AC_ARRAY_ASSERT		ZC_ARRAY_ASSERT
#endif //#ifndef AC_ARRAY_ASSERT

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayMemCopyReallocator
#define AcArrayMemCopyReallocator		ZcArrayMemCopyReallocator
#endif //#ifndef AcArrayMemCopyReallocator

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#endif //#ifndef __ACARRAY_H__
