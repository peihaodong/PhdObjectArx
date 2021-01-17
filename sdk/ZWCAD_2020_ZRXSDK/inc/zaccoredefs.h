#ifndef _ZACCOREDEFS_H_H
#define _ZACCOREDEFS_H_H

#ifndef ZCCORE_PORT
#ifdef ZCCORE_API
#define ZCCORE_PORT _declspec(dllexport)
#define ZCCORE_DATA_PORT _declspec(dllexport) extern
#define ZCCORE_STATIC_DATA_PORT _declspec(dllexport) static
#else
#define ZCCORE_PORT
#define ZCCORE_DATA_PORT _declspec(dllimport) extern
#define ZCCORE_STATIC_DATA_PORT _declspec(dllimport) static
#endif
#endif


#endif //_ZACCOREDEFS_H_H