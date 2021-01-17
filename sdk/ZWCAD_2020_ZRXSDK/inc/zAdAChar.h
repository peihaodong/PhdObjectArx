

#pragma once

#define ZD_UNICODE 1

#if defined(__cplusplus) && !defined(_NATIVE_WCHAR_T_DEFINED)
#error Please use native wchar_t type (/Zc:wchar_t)
#endif

typedef wchar_t ZTCHAR;

//

#define _ZCRX_T(x)      L ## x
#define ZCRX_T(x)      _ZCRX_T(x)



