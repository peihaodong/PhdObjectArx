

#ifndef _Zc_String_h_
#define _Zc_String_h_

#include "zadesk.h"
#include "zAcHeapOpers.h"
#include "zAdAChar.h"
#include "zacarray.h"
#ifndef _ZSOFT_WINDOWS_
#include <stdarg.h>
#endif

#pragma pack (push, 1)

class ZcDbHandle;

class ZcString : public ZcHeapOperators
{
  public:
    
    ZcString();
    ZcString(char ch);
    ZcString(wchar_t wch);
    ZcString(const char *psz);
    ZcString(const wchar_t *pwsz);
    ZcString(const ZcString & acs);
    enum {
        kAppRes = 0x0001,   
        kSigned = 0x0002,   
        kUnSigned = 0x0003, 
        kHex      = 0x0004  
    };
    ZcString(int nCtorFlags, unsigned nArg);
    ZcString(const ZcDbHandle &h);

#if defined(_WINBASE_) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_)
    ZcString(HINSTANCE hDll, unsigned nId);
#endif
    ~ZcString();
	const char * ansiPtr() const;
    const char * kszPtr() const;
    const wchar_t * kwszPtr() const;
#ifdef UNICODE
    const wchar_t *  constPtr() const;
    const wchar_t * kTCharPtr() const;
#else
    const  char   *  constPtr() const;
    const  char   * kTCharPtr() const;
#endif
    const ZTCHAR * kACharPtr() const;
    operator const char * () const;
    operator const wchar_t * () const;
    bool isEmpty() const;
    unsigned length() const;
    unsigned tcharLength() const;
    bool isAscii() const;
    enum {
        kParseZero = 0,       
        kParseMinus1 = 0x01,  
        kParseAssert = 0x02,  
        kParseExcept = 0x04,  
        kParseNoEmpty = 0x08, 
        kParseDefault = (kParseAssert | kParseZero)
    };
    int asDeci(int nFlags = kParseDefault) const;
    int asHex (int nFlags = kParseDefault) const;
    unsigned int asUDeci(int nFlags = kParseDefault) const;
    unsigned int asUHex (int nFlags = kParseDefault) const;
    ZSoft::Int64 asDeci64(int nFlags = kParseDefault) const;
    ZSoft::Int64 asHex64 (int nFlags = kParseDefault) const;
    ZSoft::UInt64 asUDeci64(int nFlags = kParseDefault) const;
    ZSoft::UInt64 asUHex64 (int nFlags = kParseDefault) const;
    ZcDbHandle asZcDbHandle(int nFlags = kParseDefault) const;

    int find(ZTCHAR ch) const;
    int find(const ZTCHAR *psz) const;
    int find(const ZcString & acs) const;
    int findOneOf(const ZTCHAR *psz) const;
    int findRev(ZTCHAR ch) const;
    int findRev(const ZTCHAR *psz) const;
    int findOneOfRev(const ZTCHAR *psz) const;
    
    int findRev(const ZcString & acs) const;
    ZcString mid(int nStart, int nNumChars) const;
    ZcString substr(int numChars) const;
    ZcString substr(int nStart, int nNumChars) const;
    ZcString substrRev(int numChars) const;

    ZcString & assign(char ch);
    ZcString & assign(wchar_t wch);
    ZcString & assign(const char *psz);
    ZcString & assign(const wchar_t *pwsz);
    ZcString & assign(const ZcString & acs);
    ZcString & assign(const ZcDbHandle & h);
    ZcString & operator = (char ch);
    ZcString & operator = (wchar_t wch);
    ZcString & operator = (const char *psz);
    ZcString & operator = (const wchar_t *pwsz);
    ZcString & operator = (const ZcString & acs);
    ZcString & operator = (const ZcDbHandle & h);
    ZcString & setEmpty();
    bool loadString(unsigned nId);

#if defined(_WINBASE_) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_)
    bool loadString(HINSTANCE hDll, unsigned nId);
#endif
    void format (const ZTCHAR    *pszFmt,  ...);
    void formatV(const ZTCHAR   *pszFmt,  va_list args);
    ZcString & operator += (char ch);
    ZcString & operator += (wchar_t wch);
    ZcString & operator += (const char * psz);
    ZcString & operator += (const wchar_t * pwsz);
    ZcString & operator += (const ZcString & acs);
    ZcString & append(char ch);
    ZcString & append(wchar_t wch);
    ZcString & append(const char *psz);
    ZcString & append(const wchar_t *pwsz);
    ZcString & append(const ZcString & acs);
    ZcString operator + (char ch) const;
    ZcString operator + (wchar_t wch) const;

    ZcString operator + (const char * psz) const;
    ZcString operator + (const wchar_t * pwsz) const;
    ZcString operator + (const ZcString & acs) const;
    ZcString concat(char ch) const;
    ZcString concat(wchar_t wch) const;
    ZcString concat(const char * psz) const;
    ZcString concat(const wchar_t * pwsz) const;
    ZcString concat(const ZcString & acs) const;
    ZcString precat(ZTCHAR ch) const;
    ZcString precat(const char * psz) const;
    ZcString precat(const wchar_t * psz) const;
    int  compare(wchar_t wch) const;
    int  compare(const char *psz) const;
    int  compare(const wchar_t *pwsz) const;
    int  compare(const ZcString & acs) const;
    int  compareNoCase(wchar_t wch) const;
    int  compareNoCase(const char *psz) const;
    int  compareNoCase(const wchar_t *pwsz) const;
    int  compareNoCase(const ZcString & acs) const;
    bool operator == (wchar_t wch) const;
    bool operator == (const char *psz) const;
    bool operator == (const wchar_t *pwsz) const;
    bool operator == (const ZcString & acs) const;
    bool operator != (wchar_t wch) const;
    bool operator != (const char *psz) const;
    bool operator != (const wchar_t *pwsz) const;
    bool operator != (const ZcString & acs) const;
    bool operator >  (wchar_t wch) const;
    bool operator >  (const char *psz) const;
    bool operator >  (const wchar_t *pwsz) const;
    bool operator >  (const ZcString & acs) const;
    bool operator >= (wchar_t wch) const;
    bool operator >= (const char *psz) const;
    bool operator >= (const wchar_t *pwsz) const;
    bool operator >= (const ZcString & acs) const;
    bool operator <  (wchar_t wch) const;
    bool operator <  (const char *psz) const;
    bool operator <  (const wchar_t *pwsz) const;
    bool operator <  (const ZcString & acs) const;
    bool operator <= (const char ch) const;
    bool operator <= (const wchar_t wch) const;
    bool operator <= (const char *psz) const;
    bool operator <= (const wchar_t *pwsz) const;
    bool operator <= (const ZcString & acs) const;
    int  match(const char *psz) const;
    int  match(const wchar_t *pwsz) const;
    int  match(const ZcString & acs) const;
    int  matchNoCase(const char *psz) const;
    int  matchNoCase(const wchar_t *pwsz) const;
    int  matchNoCase(const ZcString & acs) const;

#if defined(_AFX) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_) || defined(__ATLSTR_H__)
    ZcString(const CStringW &csw);
    ZcString & operator = (const CStringW &csw);
    ZcString & operator += (const CStringW &csw);
    int  compare(const CStringW & csw) const;
    int  compareNoCase(const CStringW & csw) const;
    bool operator == (const CStringW & ) const;
    bool operator != (const CStringW & ) const;
    bool operator <  (const CStringW & ) const;
    bool operator <= (const CStringW & ) const;
    bool operator >  (const CStringW & ) const;
    bool operator >= (const CStringW & ) const;
    int  match(const CStringW & csw) const;
    int  matchNoCase(const CStringW & csw) const;
#endif

  private:

#if !defined(_WIN64) && !defined (_ZC64)
    enum {
#ifndef _ZSOFT_WINDOWS_
		kObjSize = 14,
#else
		kObjSize = 8,
#endif
        kMbArrSize = 7,
        kUCArrSize = 3,
        kPadArrSize = 3
    };
#else
    enum {
#ifndef _ZSOFT_WINDOWS_
		kObjSize = 30,
#else
		kObjSize = 16,
#endif
        kMbArrSize = 15,
        kUCArrSize = 7,
        kPadArrSize = 7
    };
#endif
    void clearAll();
    struct PtrAndData;
    unsigned char mnFlags;
    union {
        struct {
            unsigned char mnPad2[kPadArrSize];
            union {
                wchar_t *mpwszData;
                char *mpszData;
                PtrAndData *mpPtrAndData;
            };
        }mptr;
        struct {
            unsigned char mnPad1;
            wchar_t mwszStr[kUCArrSize];
        }mchr;
        char mszStr[kMbArrSize];
    };
    friend class ZcStringImp;
};

#ifdef _ZCARRAY_H
typedef
	ZcArray< ZcString, ZcArrayObjectCopyReallocator< ZcString > > ZcStringArray;
#endif

#pragma pack (pop)
bool operator == (wchar_t wch, const ZcString & acs);

bool operator == (const char *psz, const ZcString & acs);

bool operator == (const wchar_t *pwsz, const ZcString & acs);

bool operator != (wchar_t wch, const ZcString & acs);

bool operator != (const char *psz, const ZcString & acs);

bool operator != (const wchar_t *pwsz, const ZcString & acs);

bool operator >  (wchar_t wch, const ZcString & acs);

bool operator >  (const char *psz, const ZcString & acs);

bool operator >  (const wchar_t *pwsz, const ZcString & acs);

bool operator >= (wchar_t wch, const ZcString & acs);

bool operator >= (const char *psz, const ZcString & acs);

bool operator >= (const wchar_t *pwsz, const ZcString & acs);

bool operator <  (wchar_t wch, const ZcString & acs);

bool operator <  (const char *psz, const ZcString & acs);

bool operator <  (const wchar_t *pwsz, const ZcString & acs);

bool operator <= (wchar_t wch, const ZcString & acs);

bool operator <= (const char *psz, const ZcString & acs);

bool operator <= (const wchar_t *pwsz, const ZcString & acs);

ZcString operator + (wchar_t wch, const ZcString & acs);

ZcString operator + (const char *psz, const ZcString & acs);

ZcString operator + (const wchar_t *pwsz, const ZcString & acs);

#if defined (_AFX) || defined(__ATLSTR_H__)

bool operator == (const CStringW & csw, const ZcString & acs);

bool operator != (const CStringW & csw, const ZcString & acs);

bool operator >  (const CStringW & csw, const ZcString & acs);

bool operator >= (const CStringW & csw, const ZcString & acs);

bool operator <  (const CStringW & csw, const ZcString & acs);

bool operator <= (const CStringW & csw, const ZcString & acs);

#define DISABLE_CSTRING_PLUS_ACSTRING 1
#ifndef DISABLE_CSTRING_PLUS_ACSTRING
ZcString operator + (const CStringW & csw, const ZcString & acs);
#endif
#endif

inline const char * ZcString::kszPtr() const
{
	return this->ansiPtr();
}

inline ZcString::operator const wchar_t *() const
{
    return this->kwszPtr();
}

#ifdef UNICODE
inline const wchar_t * ZcString::constPtr() const
{
    return this->kwszPtr();
}

inline const wchar_t * ZcString::kTCharPtr() const
{
    return this->kwszPtr();
}

inline unsigned ZcString::tcharLength() const
{
    return this->length();
}

#elif _UNICODE
#error "Unexpected _UNICODE definition"
#else
inline const char * ZcString::constPtr() const
{
    return this->kszPtr();
}

inline const char * ZcString::kTCharPtr() const
{
    return this->kszPtr();
}

#endif

inline const ZTCHAR * ZcString::kACharPtr() const
{
#ifdef _ZSOFT_WINDOWS_
    return this->kwszPtr();
#else
	return (ZTCHAR*)this->kwszPtr();
#endif
}

inline void ZcString::clearAll()
{
    this->mnFlags = 0;
    this->mchr.mnPad1 = 0;
    this->mchr.mwszStr[0] = 0;
    this->mptr.mpszData = nullptr;
}

inline int ZcString::find(ZTCHAR ch) const
{
	const ZTCHAR str[2] = {ch, '\0'};
	return this->findOneOf(str);
}

inline int ZcString::findRev(ZTCHAR ch) const
{
	const ZTCHAR str[2] = {ch, '\0'};
	return this->findOneOfRev(str);
}

inline ZcString ZcString::mid(int nStart, int nNumChars) const
{
    return this->substr(nStart, nNumChars);
}

inline ZcString ZcString::substr(int nNumChars) const
{
	return this->substr(0, nNumChars);
}

inline ZcString & ZcString::assign(char ch)
{
	const char str[2] = {ch, '\0'};
	return this->assign(str);
}

inline ZcString & ZcString::assign(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->assign(wstr);
}

inline ZcString & ZcString::operator = (char ch)
{
    return this->assign(ch);
}

inline ZcString & ZcString::operator = (wchar_t wch)
{
    return this->assign(wch);
}

inline ZcString & ZcString::operator = (const char *psz)
{
    return this->assign(psz);
}

inline ZcString & ZcString::operator = (const wchar_t *pwsz)
{
    return this->assign(pwsz);
}

inline ZcString & ZcString::operator = (const ZcString & acs)
{
    return this->assign(acs);
}

inline ZcString & ZcString::operator = (const ZcDbHandle & h)
{
    return this->assign(h);
}

inline ZcString & ZcString::operator += (char ch)
{
    return this->append(ch);
}

inline ZcString & ZcString::operator += (wchar_t wch)
{
    return this->append(wch);
}

inline ZcString & ZcString::operator += (const char *psz)
{
    return this->append(psz);
}

inline ZcString & ZcString::operator += (const wchar_t *pwsz)
{
    return this->append(pwsz);
}

inline ZcString & ZcString::operator += (const ZcString & acs)
{
    return this->append(acs);
}

inline ZcString & ZcString::append(char ch)
{
	const char str[2] = {ch, '\0'};
	return this->append(str);
}

inline ZcString & ZcString::append(wchar_t wch)
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->append(wstr);
}

inline ZcString ZcString::operator + (char ch) const
{
    return this->concat(ch);
}

inline ZcString ZcString::operator + (wchar_t wch) const
{
    return this->concat(wch);
}

inline ZcString ZcString::operator + (const char * psz) const
{
    return this->concat(psz);
}

inline ZcString ZcString::operator + (const wchar_t * pwsz) const
{
    return this->concat(pwsz);
}

inline ZcString ZcString::operator + (const ZcString & acs) const
{
    return this->concat(acs);
}

inline ZcString ZcString::concat(char ch) const
{
	const char str[2] = {ch, '\0'};
	return this->concat(str);
}

inline ZcString ZcString::concat(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->concat(wstr);
}

inline ZcString ZcString::precat(ZTCHAR ch) const
{
	const ZTCHAR str[2] = {ch, '\0'};
	return this->precat(str);
}

inline int ZcString::compare(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compare(wstr);
}

inline int ZcString::compareNoCase(wchar_t wch) const
{
	const wchar_t wstr[2] = {wch, L'\0'};
	return this->compareNoCase(wstr);
}

inline bool ZcString::operator == (wchar_t wch) const
{
    return this->compare(wch) == 0;
}

inline bool ZcString::operator == (const char *psz) const
{
    return this->compare(psz) == 0;
}

inline bool ZcString::operator == (const wchar_t *pwsz) const
{
    return this->compare(pwsz) == 0;
}

inline bool ZcString::operator == (const ZcString & acs) const
{
    return this->compare(acs) == 0;
}

inline bool ZcString::operator != (wchar_t wch) const
{
    return this->compare(wch) != 0;
}

inline bool ZcString::operator != (const char *psz) const
{
    return this->compare(psz) != 0;
}

inline bool ZcString::operator != (const wchar_t *pwsz) const
{
    return this->compare(pwsz) != 0;
}

inline bool ZcString::operator != (const ZcString & acs) const
{
    return this->compare(acs) != 0;
}

inline bool ZcString::operator > (wchar_t wch) const
{
    return this->compare(wch) > 0;
}

inline bool ZcString::operator > (const char *psz) const
{
    return this->compare(psz) > 0;
}

inline bool ZcString::operator > (const wchar_t *pwsz) const
{
    return this->compare(pwsz) > 0;
}

inline bool ZcString::operator > (const ZcString & acs) const
{
    return this->compare(acs) > 0;
}

inline bool ZcString::operator >= (wchar_t wch) const
{
    return this->compare(wch) >= 0;
}

inline bool ZcString::operator >= (const char *psz) const
{
    return this->compare(psz) >= 0;
}

inline bool ZcString::operator >= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) >= 0;
}

inline bool ZcString::operator >= (const ZcString & acs) const
{
    return this->compare(acs) >= 0;
}

inline bool ZcString::operator < (wchar_t wch) const
{
    return this->compare(wch) < 0;
}

inline bool ZcString::operator < (const char *psz) const
{
    return this->compare(psz) < 0;
}

inline bool ZcString::operator < (const wchar_t *pwsz) const
{
    return this->compare(pwsz) < 0;
}

inline bool ZcString::operator < (const ZcString & acs) const
{
    return this->compare(acs) < 0;
}

inline bool ZcString::operator <= (char ch) const
{
	return this->compare(ch) <= 0;
}

inline bool ZcString::operator <= (wchar_t wch) const
{
    return this->compare(wch) <= 0;
}

inline bool ZcString::operator <= (const char *psz) const
{
    return this->compare(psz) <= 0;
}

inline bool ZcString::operator <= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) <= 0;
}

inline bool ZcString::operator <= (const ZcString & acs) const
{
    return this->compare(acs) <= 0;
}
#if defined(_AFX) || defined(_ZSOFT_MAC_) || defined(_ZSOFT_LINUX_) || defined(__ATLSTR_H__)

inline ZcString::ZcString(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    this->clearAll();
    *this = pwsz;
}

inline ZcString & ZcString::operator=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->assign(pwsz);
}

inline ZcString & ZcString::operator+=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->append(pwsz);
}

inline int ZcString::compare(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compare(pwsz);
}

inline int ZcString::compareNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compareNoCase(pwsz);
}

inline int ZcString::match(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->match(pwsz);
}

inline int ZcString::matchNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->matchNoCase(pwsz);
}

inline bool ZcString::operator == (const CStringW & csw) const
{
    return this->compare(csw) == 0;
}

inline bool ZcString::operator != (const CStringW & csw) const
{
    return this->compare(csw) != 0;
}

inline bool ZcString::operator > (const CStringW & csw) const
{
    return this->compare(csw) > 0;
}

inline bool ZcString::operator >= (const CStringW & csw) const
{
    return this->compare(csw) >= 0;
}

inline bool ZcString::operator < (const CStringW & csw) const
{
    return this->compare(csw) < 0;
}

inline bool ZcString::operator <= (const CStringW & csw) const
{
    return this->compare(csw) <= 0;
}
#endif

#ifdef _AFX
inline bool operator == (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) == 0;
}

inline bool operator != (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) != 0;
}

inline bool operator >  (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) < 0;
}

inline bool operator >= (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) <= 0;
}

inline bool operator <  (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) > 0;
}

inline bool operator <= (const CStringW & csw, const ZcString & acs)
{
    return acs.compare(csw) >= 0;
}

#ifndef DISABLE_CSTRING_PLUS_ACSTRING
inline ZcString operator + (const CStringW & csw, const ZcString & acs)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return acs.precat(pwsz);
}
#endif
#endif
inline bool operator == (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) == 0;
}

inline bool operator == (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) == 0;
}

inline bool operator == (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) == 0;
}

inline bool operator != (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) != 0;
}

inline bool operator != (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) != 0;
}

inline bool operator != (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) != 0;
}

inline bool operator > (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) < 0;
}

inline bool operator > (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) < 0;
}

inline bool operator > (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) < 0;
}

inline bool operator >= (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) <= 0;
}

inline bool operator >= (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) <= 0;
}

inline bool operator >= (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) <= 0;
}

inline bool operator < (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) > 0;
}

inline bool operator < (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) > 0;
}

inline bool operator < (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) > 0;
}

inline bool operator <= (wchar_t wch, const ZcString & acs)
{
    return acs.compare(wch) >= 0;
}

inline bool operator <= (const char *psz, const ZcString & acs)
{
    return acs.compare(psz) >= 0;
}

inline bool operator <= (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.compare(pwsz) >= 0;
}

inline ZcString operator + (ZTCHAR ch, const ZcString & acs)
{
    return acs.precat(ch);
}

inline ZcString operator + (const char *psz, const ZcString & acs)
{
    return acs.precat(psz);
}

inline ZcString operator + (const wchar_t *pwsz, const ZcString & acs)
{
    return acs.precat(pwsz);
}

#endif 

