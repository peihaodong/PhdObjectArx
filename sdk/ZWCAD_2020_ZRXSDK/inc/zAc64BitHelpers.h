
#pragma once

#include "zac_tcslen.h"
#include "zadesk.h"

#define Zc64Assert ZcTcsLen_Assert

#ifdef _ZSOFT_WINDOWS_
#if !defined(_WIN64) && !defined(_ZC64)

#ifdef GetWindowLongPtr
#undef GetWindowLongPtr
#endif
inline LONG_PTR __stdcall GetWindowLongPtr(HWND h, int n)
{
    return static_cast<LONG_PTR>(::GetWindowLong(h, n));
}

#ifdef SetWindowLongPtr
#undef SetWindowLongPtr
#endif
inline LONG_PTR __stdcall SetWindowLongPtr(HWND h, int n, LONG_PTR v)
{
    const long nLongV = static_cast<long>(v);
    return static_cast<LONG_PTR>(::SetWindowLong(h, n, nLongV));
}

inline LONG_PTR __stdcall SetWindowLongPtr(HWND h, int n, void * v)
{
    const LONG_PTR vPtr = reinterpret_cast<LONG_PTR>(v);
    return ::SetWindowLongPtr(h, n, vPtr);
}

#ifdef GetClassLongPtr
#undef GetClassLongPtr
#endif

inline ULONG_PTR __stdcall GetClassLongPtr(HWND h, int n)
{
   return static_cast<ULONG_PTR>(::GetClassLong(h, n));
}

#ifdef SetClassLongPtr
#undef SetClassLongPtr
#endif

inline ULONG_PTR __stdcall SetClassLongPtr(HWND h, int n, LONG_PTR v)
{
    const long vLong = static_cast<long>(v);
    return static_cast<ULONG_PTR>(::SetClassLong(h, n, vLong));
}

inline ULONG_PTR __stdcall SetClassLongPtr(HWND h, int n, void * v)
{
    const ULONG_PTR vPtr = reinterpret_cast<ULONG_PTR>(v);
    return ::SetClassLongPtr(h, n, vPtr);
}

#ifdef offsetof
#undef offsetof
#endif

#define offsetof(s,m) static_cast<unsigned>( \
             reinterpret_cast<UINT_PTR> (\
                 &reinterpret_cast<const volatile char&>( \
                     reinterpret_cast<const s *>(0)->m )))

#else

#if _MSC_VER < 1700
#ifdef HIWORD
#undef HIWORD
#endif
#define HIWORD(v) (static_cast<WORD>((((DWORD_PTR)(v) >> 16) & 0xFFFF)))
#endif
#endif
#endif

#ifdef  HIBYTE
#undef HIBYTE
#endif
#define HIBYTE(w)           LOBYTE((DWORD_PTR)(w) >> 8)

#pragma warning(push)
#pragma warning(disable:4100)
inline int ZcIntPtrToInt(ZSoft::LongPtr nVal, ZSoft::LongPtr nLimit = 0x1000000)
{
    Zc64Assert(nVal < nLimit);
    Zc64Assert(nVal > -nLimit);
    const int nRet = static_cast<int>(nVal);
    Zc64Assert(nRet == nVal);
    return nRet;
}

inline unsigned int ZcUIntPtrToUInt(ZSoft::ULongPtr nVal, ZSoft::ULongPtr nLimit = 0x1000000)
{
    Zc64Assert(nVal < nLimit);
    const unsigned int nRet = static_cast<unsigned int>(nVal);
    Zc64Assert(nRet == nVal);
    return nRet;
}
#pragma warning(pop)

inline ZSoft::LongPtr __stdcall ZcStrToIntPtr(const wchar_t * s)
{
#if defined(_WIN64) || defined(_ZC64)
    return _wtoi64(s);
#else
    return _wtoi(s);
#endif
}
