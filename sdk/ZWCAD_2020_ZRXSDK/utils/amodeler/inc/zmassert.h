#ifndef AECMODELER_INC_MASSERT_H
#define AECMODELER_INC_MASSERT_H

#include <tchar.h>

AECMODELER_NAMESPACE_BEGIN


#ifdef _DEBUG

#define MASSERT(x) AECMODELER_NAMESPACE::ZwAssertFunction(x, _T(__FILE__), __LINE__, _T(#x))
#define FAIL       AECMODELER_NAMESPACE::ZwAssertFunction(0, _T(__FILE__), __LINE__, _T("FAIL"))

#else

#define MASSERT(x)
#define FAIL
#endif


DllImpExp extern void ZwAssertFunction(int ex, const wchar_t* file, int line, const wchar_t* str = 0);


AECMODELER_NAMESPACE_END
#endif






