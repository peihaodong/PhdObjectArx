
#ifndef __ACMEM_H__
#define __ACMEM_H__

#include <stddef.h>
#include "AdAChar.h"

#include "../inc/zacmem.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef acad__msize
#define acad__msize		zcad__msize
#endif //#ifndef acad__msize

#ifndef acad__strdup
#define acad__strdup		zcad__strdup
#endif //#ifndef acad__strdup

#ifndef acad_calloc
#define acad_calloc		zcad_calloc
#endif //#ifndef acad_calloc

#ifndef acad_free
#define acad_free		zcad_free
#endif //#ifndef acad_free

#ifndef acad_malloc
#define acad_malloc		zcad_malloc
#endif //#ifndef acad_malloc

#ifndef acad_realloc
#define acad_realloc		zcad_realloc
#endif //#ifndef acad_realloc

#endif //#ifndef __ACMEM_H__
