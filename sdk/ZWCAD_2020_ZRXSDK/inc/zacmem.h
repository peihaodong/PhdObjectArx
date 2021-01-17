

#ifndef _ZCMEM_H
#define _ZCMEM_H

#include <stddef.h>
#include "zAdAChar.h"

#pragma pack (push, 8)

#ifdef __cplusplus
extern "C" {
#endif

void  *zcad_malloc  (size_t size);
void   zcad_free    (void *p);
size_t zcad__msize  (void *p);
void  *zcad_realloc (void *p, size_t size);
void  *zcad_calloc  (size_t num, size_t size);
ZTCHAR *zcad__strdup (const ZTCHAR *p);

#ifdef __cplusplus
} 
#endif

#pragma pack (pop)
#endif 
