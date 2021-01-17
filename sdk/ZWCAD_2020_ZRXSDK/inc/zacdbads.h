

#ifndef _zcdbads_h
#define _zcdbads_h 1

#include "zadsdef.h"

#include "zacmem.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

#ifdef __cplusplus
#include "zadesk.h"
#endif
void           zcdbFail (const ZTCHAR *str);

int            zcdbHandEnt (const ZTCHAR *handle, zds_name entres);
#ifdef __cplusplus
int            zcdbXdRoom (const zds_name ent, ZSoft::Int32 *result);
int            zcdbXdSize (const struct resbuf *rb, ZSoft::Int32 *result);
ZTCHAR *        zcdbXStrSave (ZTCHAR *pSource, ZTCHAR **pDest);
int            zcdbXStrCase (ZTCHAR *str, size_t strLen);
#endif
#ifdef __STDC__
#define zcdbNameSet(from, to)  (memcpy(to, from, sizeof(zds_name)))
#define zcdbPointSet(from,to)  (memcpy(to, from, sizeof(zds_point)))
#else
#define zcdbNameSet(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define zcdbPointSet(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  

#define zcdbNameClear(name)    name[0] = name[1] = 0
#define zcdbNameNil(name)      (name[0] == 0 && name[1] == 0)
#define zcdbNameEqual(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])
#pragma pack (pop)

#endif

