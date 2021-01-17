

#ifndef ZC_GEDLL_H
#define ZC_GEDLL_H

#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#pragma warning(disable:4251)
#pragma warning(disable:4273)
#pragma warning(disable:4275)
#endif

#ifdef  ZCGE_INTERNAL
#define GE_DLLEXPIMPORT ZSOFT_DLLEXPORT
#else
#define GE_DLLEXPIMPORT ZSOFT_DLLIMPORT
#endif

#ifdef  ZCGX_INTERNAL
#define GX_DLLEXPIMPORT ZSOFT_DLLEXPORT
#else
#define GX_DLLEXPIMPORT ZSOFT_DLLIMPORT
#endif

//#ifdef ZCGE_INTERNAL
//#ifndef GELIB_REGRESS
//#include "zcmemdebug.h"
//#endif
//#endif

#endif 
