

#ifndef ZC_GEGBLNEW_H
#define ZC_GEGBLNEW_H

#ifdef GE_LOCATED_NEW

#include "zgegblge.h"
#include "zgegetmti.h"

GE_DLLEXPIMPORT
void* operator new ( size_t, enum ZcGe::metaTypeIndex, const void* );

GE_DLLEXPIMPORT
void* operator new ( size_t, enum ZcGe::metaTypeIndex, unsigned int, const void* );

#define GENEWLOC( T, ptr)  new (ZcGeGetMetaTypeIndex<T >(), (ptr)) T
#define GENEWLOCVEC( T, count, ptr) new (ZcGeGetMetaTypeIndex<T >(),(count),(ptr)) T [ (count) ]
#else   
#define GENEWLOC( T, ptr)  new T
#define GENEWLOCVEC( T, count, ptr) new T [ (count) ]
#endif

#endif  
