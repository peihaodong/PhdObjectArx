

#include "zadesk.h"
#ifndef _ZSOFT_WINDOWS_
#include <malloc/malloc.h>
#else
#include "malloc.h"
#endif
#include "zAdAChar.h"
#include "zAdCharFmt.h"

#ifdef ASSERT
#define ZcFStream_Assert ASSERT
#elif defined assert
#define ZcFStream_Assert assert
#else
#define ZcFStream_Assert(T)
#endif

#ifdef UNICODE
inline int ZcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
                                 char *pDest, int nDestSize);
inline std::locale ZcFStream_curLocale();
#endif

class ZcIfstream : public
#ifndef UNICODE
                        std::ifstream {
#else
                        std::wifstream {
#endif
  public:
    ZcIfstream() {};
    ZcIfstream(const ZTCHAR *pName);
#ifdef UNICODE
    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
#endif
};

class ZcOfstream : public
#ifndef UNICODE
                        std::ofstream {
#else
                        std::wofstream {
#endif
  public:
    class ZcOfstream() {};
    class ZcOfstream(const ZTCHAR *pName);
#ifdef UNICODE
    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
#endif

};

#ifndef UNICODE
inline ZcIfstream::ZcIfstream(const ZTCHAR *pName) : std::ifstream(pName)
{
}
inline ZcOfstream::ZcOfstream(const ZTCHAR *pName) : std::ofstream(pName)
{
}
#else
inline ZcIfstream::ZcIfstream(const ZTCHAR *pName)
{
    this->open(pName);
}

inline ZcOfstream::ZcOfstream(const ZTCHAR *pName)
{
    this->open(pName);
}

inline std::locale ZcFStream_curLocale()
{
#ifdef _ZSOFT_WINDOWS_
    char buf[100];
    sprintf_s(buf, 100, ".%d", GetACP());
	return std::locale(buf, LC_CTYPE);
#else
	STUB_WARNING(ZcFStream_curLocale);
	return std::locale();
#endif
}

inline int ZcFStream_wideToMulti(const wchar_t *pSrc, int nSrcSize,
                                 char *pDest, int nDestSize)
{
    return ::WideCharToMultiByte(
                        CP_ACP,
#if defined(WINVER) && (WINVER >= 0x0500)
                        WC_NO_BEST_FIT_CHARS,
#else
                        0,
#endif
                        pSrc,
                        nSrcSize,
                        pDest,
                        nDestSize,
                        NULL,
                        NULL);
}

inline void ZcIfstream::open(const wchar_t *pName)
{
#ifdef _ZSOFT_WINDOWS_ 
    this->std::wifstream::open(pName);
	this->imbue(ZcFStream_curLocale());
#else
	STUB_WARNING(ZcIfstream::open)
#endif
}

inline void ZcIfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifdef _ZSOFT_WINDOWS_
    this->std::wifstream::open(pName, nMode);
	this->imbue(ZcFStream_curLocale());
#else
	STUB_WARNING(ZcIfstream::open);
#endif
}

inline void ZcOfstream::open(const wchar_t *pName)
{
#ifdef _ZSOFT_WINDOWS_
    this->std::wofstream::open(pName);
	this->imbue(ZcFStream_curLocale());
#else
	STUB_WARNING(ZcOfstream::open);
#endif}

inline void ZcOfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifdef _ZSOFT_WINDOWS_
    this->std::wofstream::open(pName, nMode);
	this->imbue(ZcFStream_curLocale());
#else
	STUB_WARNING(ZcOfstream::open);
#endif
}

#endif

