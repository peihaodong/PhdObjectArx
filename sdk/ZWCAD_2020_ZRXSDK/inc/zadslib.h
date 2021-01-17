

#ifndef _zdslib_h
#define _zdslib_h 1

#ifdef _WINDOWS
#define WIN 1
#endif

#ifdef WINVER
#define WIN 1
#endif

#ifdef _MSC_VER
#define MICROSOFT 1
#endif

#include "zads.h"
#include "zadscodes.h"
#pragma pack (push, 8)

#ifdef __cplusplus

bool zcrxUnlockApplication(void* appId);

bool zcrxApplicationIsLocked(const ZTCHAR* modulename);

bool zcrxLockApplication(void* appId);

#endif 

#pragma pack (pop)

#endif 

