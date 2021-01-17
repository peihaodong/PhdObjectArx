
#pragma once

#ifndef _ZC_TCSLEN
#define _ZC_TCSLEN

#if defined ASSERT
#define ZcTcsLen_Assert ASSERT
#elif defined(assert)
#define ZcTcsLen_Assert assert
#elif defined(_ASSERTE)
#define ZcTcsLen_Assert _ASSERTE
#elif defined ATLASSERT
#define ZcTcsLen_Assert ATLASSERT
#else
#define ZcTcsLen_Assert(x)
#endif

#ifndef USEINTRINSTRLEN

#ifdef _tcslen
#undef _tcslen
#endif

#ifdef UNICODE
#define _tcslen zc_wcslen
#else
#define _tcslen zc_strlen
#endif

#ifdef wcslen
#undef wcslen
#endif
#define wcslen zc_wcslen
#ifdef strlen
#undef strlen
#endif
#define strlen zc_strlen



__declspec(noinline) inline unsigned __stdcall zc_wcslen(const wchar_t * s)
{
    unsigned n = 0;
    while (*s != L'\0') {
        s++;
        n++;
        ZcTcsLen_Assert(n < 0x7FFFFFFE);
    }
    return n;
}

__declspec(noinline) inline unsigned __stdcall zc_strlen(const char * s)
{
    unsigned n = 0;
    while (*s != '\0') {
        s++;
        n++;
        ZcTcsLen_Assert(n < 0x7FFFFFFE);
    }
    return n;
}

#else

#ifndef _tcslen
	#ifdef UNICODE
		#define _tcslen wcslen
	#else
		#define _tcslen strlen
	#endif
#endif

#endif//USEINTRINSTRLEN

#endif//_ZC_TCSLEN_
