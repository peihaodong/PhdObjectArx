

#ifndef ZC_GEGBL_H
#define ZC_GEGBL_H

#include <stdlib.h>
#include "zgedll.h"
#include "zadesk.h"
#include "zgetol.h"

#include "zgegblge.h"
#pragma pack (push, 8)

class ZcGeVector3d;

struct
GE_DLLEXPIMPORT
ZcGeContext
{

    static ZcGeTol      gTol;

    static void (*gErrorFunc)();



    static void (*gOrthoVector)(const ZcGeVector3d&,ZcGeVector3d&);

#ifndef unix
    static void* (*gAllocMem)(size_t);
#ifdef MEM_DEBUG
    static void* (*gAllocMemLeak)(size_t, const char *, int);
#endif
    static void  (*gFreeMem)(void*);
#endif
#ifdef GE_LOCATED_NEW
	static void* (*gAllocMemNear) (size_t, ZcGe::metaTypeIndex, const void* );
	static void* (*gAllocMemNearVector) (size_t, ZcGe::metaTypeIndex, unsigned int, const void* );
	static void (*gSetExternalStore) (const void* );
#endif
#ifndef NDEBUG
    static void (*gAssertFunc)(const ZTCHAR *condition, const ZTCHAR *filename,
                                    int lineNumber, const ZTCHAR *status);
#endif
};

#pragma pack (pop)
#endif 

