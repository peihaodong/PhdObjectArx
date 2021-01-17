

#pragma once

#include "stdio.h"
#include <malloc.h>
#include "zAdCharFmt.h"

#pragma warning(push)
#pragma warning(disable:4996)

#ifdef ASSERT
#define ZcFILE_Assert ASSERT
#elif defined assert
#define ZcFILE_Assert assert
#elif defined _ASSERTE
#define ZcFILE_Assert _ASSERTE
#else
#define ZcFILE_Assert(T)
#endif

class ZcFILE {
  public:
    ZcFILE()
        : mpFILE(NULL),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
    {}
    ZcFILE(FILE *pFILE)
        : mpFILE(pFILE),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
    {}
    ~ZcFILE() {
        ZcFILE_Assert(this->mpFILE == NULL);
    }
    FILE * fopen(const TCHAR *pName, const TCHAR *pMode);
    FILE * fsopen(const TCHAR *pName, const TCHAR *pMode, int shflag);
    void attach(FILE *pFILE);
    FILE * detach();
    int fclose();
    int fputs(const TCHAR *pStr);
    TCHAR * fgets(TCHAR *pBuf, int nChars);
    int fprintf(const TCHAR *pFmtStr, ...);
    int vfprintf(const TCHAR *pFmtStr, va_list va);
    int fscanf(const TCHAR *pFmtStr, ...);
    int fputc(TCHAR c);
    int ungetc(TCHAR c);
    int fgetc();
    bool isOpen() const { return this->mpFILE != NULL; }
    FILE * pFILE() const { return this->mpFILE; }

    unsigned getCharFormat() const { return this->mChFmtr.getFormat(); }
    unsigned setCharFormat(unsigned nFmt) {
            return this->mChFmtr.setFormat(nFmt); }
    bool getUseCIF() const { return this->mChFmtr.getUseCIF(); }
    bool setUseCIF(bool bUseCIF) {
            return this->mChFmtr.setUseCIF(bUseCIF); }
    bool getExpandLF() const { return this->mChFmtr.getExpandLF(); }
    bool setExpandLF(bool bExpandLF) {
            return this->mChFmtr.setExpandLF(bExpandLF); }

    bool readBOM();
    bool writeBOM();

  private:

    #ifdef UNICODE
      bool parseAnsiOrCIF(wchar_t &wch);
      bool parseUtf8(wchar_t &wch);
      bool parseUtf16(wchar_t &wch);
      int  fputsWorker(const wchar_t* pSrc, int nOptions);
    #endif

    FILE *mpFILE;
    ZdCharFormatter mChFmtr;
};

inline FILE * ZcFILE::fopen(const TCHAR *pName, const TCHAR *pMode)
{
    ZcFILE_Assert(this->mpFILE == NULL);
    this->mpFILE = ::_tfopen(pName, pMode);
    return this->mpFILE;
}

inline FILE * ZcFILE::fsopen(const TCHAR *pName, const TCHAR *pMode, int shflag)
{
    ZcFILE_Assert(this->mpFILE == NULL);
    this->mpFILE = ::_tfsopen(pName, pMode, shflag);
    return this->mpFILE;
}

inline void ZcFILE::attach(FILE *pFILE)
{
    ZcFILE_Assert(this->mpFILE == NULL);
    this->mpFILE = pFILE;
}

inline FILE * ZcFILE::detach()
{
    FILE *pRet = this->mpFILE;
    this->mpFILE = NULL;
    return pRet;
}

inline int ZcFILE::fclose()
{
    int nRet = 0;
    if (this->mpFILE != NULL) {
        nRet = ::fclose(this->mpFILE);
        this->mpFILE = NULL;
    }
    return nRet;
}

inline int ZcFILE::fputs(const TCHAR *pStr)
{
    ZcFILE_Assert(this->mpFILE != NULL);
#ifndef UNICODE
    return ::fputs(pStr, this->mpFILE);
#else
    return fputsWorker(pStr, 0);
#endif
}

inline TCHAR * ZcFILE::fgets(TCHAR *pBuf, int nChars)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    ZcFILE_Assert(nChars > 1);
#ifndef UNICODE
    return ::fgets(pBuf, nChars, this->mpFILE);
#else
    TCHAR *pSavePtr = pBuf;
    for (;;) {
        if (nChars <= 1)
            break;
        const int ch = this->fgetc();
        if (ch == EOF)
            break;
        ZcFILE_Assert((ch & ~0xffff) == 0);
        ZcFILE_Assert((wchar_t)ch == ch);
        *pSavePtr = (wchar_t)ch;
        pSavePtr++;
        if (ch == '\n')
            break;
        nChars--;
    }
    *pSavePtr = 0;

    if (pSavePtr == pBuf)
        return NULL;

    return pBuf;
#endif
}

inline int ZcFILE::fprintf(const TCHAR *pFmtStr, ...)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    va_list va;
    va_start(va, pFmtStr);
    return this->vfprintf(pFmtStr, va);
}

inline int ZcFILE::vfprintf(const TCHAR *pFmtStr, va_list va)
{
#ifndef UNICODE
    return ::vfprintf(this->mpFILE, pFmtStr, va);
#else
    int nChar = ::_vscwprintf(pFmtStr, va);

    wchar_t* wBuf = new wchar_t[nChar + 1];
    ::wmemset(wBuf, 0, nChar + 1);
    ::vswprintf_s(wBuf, nChar+ 1, pFmtStr, va);
    ZcFILE_Assert(wBuf[nChar] == 0);

    int iRet = fputsWorker(wBuf, 1);
    delete [] wBuf;
    return iRet;
#endif
}

#ifdef _ZSOFT_WINDOWS_
inline int ZcFILE::fscanf(const TCHAR *pFmtStr, ...)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    pFmtStr = NULL;
}
#endif

inline int ZcFILE::fputc(TCHAR c)
{
    ZcFILE_Assert(this->mpFILE != NULL);
#ifndef UNICODE
    return ::fputc(c, this->mpFILE);
#else
    char chBuf[8];
    const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf,
                                                       sizeof(chBuf));
    ZcFILE_Assert(nBytes >= 1);
    ZcFILE_Assert(nBytes <= 8);
    const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1,
                                                nBytes, this->mpFILE);
    if (nNumWrote == nBytes)
        return c;
    else
        return -1;
#endif
}

inline int ZcFILE::ungetc(TCHAR c)
{
    ZcFILE_Assert(this->mpFILE != NULL);
#ifndef UNICODE
    return ::ungetc(c, this->mpFILE);
#else
    char chBuf[8];
    const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf,
                                                       sizeof(chBuf));
    ZcFILE_Assert(nBytes >= 1);
    ZcFILE_Assert(nBytes <= 8);
    if (nBytes == 1 && ::ungetc(chBuf[0], this->mpFILE) == chBuf[0])
        return c;
    else
        return -1;
#endif
}

inline int ZcFILE::fgetc()
{
    ZcFILE_Assert(this->mpFILE != NULL);
#ifndef UNICODE
    return ::fgetc(this->mpFILE);
#else
    wchar_t wchLocal = L'\0';
    switch(this->getCharFormat())
    {
        case ZdCharFormatter::kAnsi:
            if (parseAnsiOrCIF(wchLocal))
                return wchLocal;
            return EOF;
            break;

        case ZdCharFormatter::kUtf8:
            if (parseUtf8(wchLocal))
                return wchLocal;
            return EOF;
            break;

        case ZdCharFormatter::kUtf16LE:
        case ZdCharFormatter::kUtf16BE:
            if (parseUtf16(wchLocal))
                return wchLocal;
            return EOF;
            break;

        case ZdCharFormatter::kUtf32LE:
        case ZdCharFormatter::kUtf32BE:
            ZcFILE_Assert(false);
            return EOF;
            break;
    }

    ZcFILE_Assert(false);
    return EOF;
#endif
}

inline bool ZcFILE::readBOM()
{
    ZcFILE_Assert(this->mpFILE != NULL);
    const long lFilePos = ::ftell(this->mpFILE);
    ZcFILE_Assert(lFilePos == 0L);
    if (lFilePos != 0L)
        return false;

    unsigned short nVal;
    if (::fread(&nVal, 1, 2, this->mpFILE) == 2) {
        if (nVal == 0xfeff) {
            this->setCharFormat(ZdCharFormatter::kUtf16LE);
            return true;
        }
        if (nVal == 0xfffe) {
            this->setCharFormat(ZdCharFormatter::kUtf16BE);
            return true;
        }
        if (nVal == 0xbbef) {
            unsigned char nByte3;
            if (::fread(&nByte3, 1, 1, this->mpFILE) == 1) {
                if (nByte3 == 0xbf) {
                    this->setCharFormat(ZdCharFormatter::kUtf8);
                    return true;
                }
            }
        }
        else if (nVal == 0 || nVal == 0xfeff) {
            unsigned nVal2;
            if (::fread(&nVal2, 1, 2, this->mpFILE) == 2) {
                if (nVal == 0 && nVal2 == 0xfffe) {
                    this->setCharFormat(ZdCharFormatter::kUtf32BE);
                    return true;
                }
                else if (nVal == 0xfeff && nVal2 == 0) {
                    this->setCharFormat(ZdCharFormatter::kUtf32LE);
                    return true;
                }
            }
        }
    }
    ::rewind(this->mpFILE);
    return false;
}

inline bool ZcFILE::writeBOM()
{
    ZcFILE_Assert(this->mpFILE != NULL);
    if (this->mpFILE == NULL)
        return false;

    const long lFilePos = ::ftell(this->mpFILE);
    ZcFILE_Assert(lFilePos == 0L);
    if (lFilePos != 0L)
        return false;

    unsigned nBom = 0;
    const int cbBomSize = ZdCharFormatter::getBOM(nBom,
                                this->getCharFormat());
    if (cbBomSize == 0)
        return false;

    const int cbWritten = (int) ::fwrite(&nBom,
                                         1,
                                         cbBomSize,
                                         this->mpFILE);

    ZcFILE_Assert(cbWritten == cbBomSize);
    if (cbWritten != cbBomSize)
    {
        ::rewind(this->mpFILE);
        return false;
    }

    return true;
}

#ifdef UNICODE

inline bool ZcFILE::parseAnsiOrCIF(wchar_t &wch)
{
    ZcFILE_Assert(this->getCharFormat() == ZdCharFormatter::kAnsi);
    wch = L'\0';
    unsigned char cFirstChar = 0;
    int nBytesRead = (int)::fread(&cFirstChar, 1, 1, this->mpFILE);
    if (nBytesRead <= 0)
        return false;

    if (cFirstChar > 0x7f)
    {
        char chBuf[2] = {0};
        wchar_t wchLocal = 0;
        chBuf[0] = ((char) cFirstChar);

        const BOOL bIsDBCS = ::IsDBCSLeadByteEx(CP_ACP, cFirstChar);
        if (bIsDBCS != FALSE)
        {
            unsigned char cSecondChar = 0;
            nBytesRead = (int)::fread(&cSecondChar, 1, 1, this->mpFILE);
            if (nBytesRead <= 0)
                return false;
            chBuf[1] = ((char) cSecondChar);
        }
        const int nRet = ::MultiByteToWideChar(
                            CP_ACP,
                            MB_ERR_INVALID_CHARS,
                            chBuf,
                            bIsDBCS ? 2 : 1,
                            &wchLocal,
                            1);

        ZcFILE_Assert(nRet == 1);
        wch = (nRet == 1) ? wchLocal : L'?';
        return true;
    }

    ZcFILE_Assert(cFirstChar <= 0x7f);

    wch = ((wchar_t) cFirstChar);
    if (cFirstChar == '\r' && (this->mChFmtr.getExpandLF())) {
        unsigned char cNewLinePair = 0;
        nBytesRead = (int)::fread(&cNewLinePair, 1, 1, this->mpFILE);
        if (nBytesRead <= 0)
            return true;
        if (cNewLinePair != '\n') {
            ::fseek(this->mpFILE, -1L, SEEK_CUR);
            return true;
        }

        wch = L'\n';
        return true;
    }
    if (cFirstChar != '\\' || (this->getUseCIF()) == false)
        return true;
    char chBuffer[8] = {0};
    chBuffer[0] = '\\';
    nBytesRead = (int) ::fread(&chBuffer[1],
                               1,
                               6,
                               this->mpFILE);
    if (ZdCharFormatter::isCIFString(chBuffer))
    {
        ZdCharFormatter::parseCIF(chBuffer, wch);
        return true;
    }
    if (nBytesRead > 0)
        ::fseek(this->mpFILE, -nBytesRead, SEEK_CUR);

    wch = L'\\';
    return true;
}

inline bool ZcFILE::parseUtf8(wchar_t &wch)
{
    ZcFILE_Assert(this->getUseCIF() == false);
    unsigned char cCharacter = 0;
    int nBytesRead = (int) ::fread(&cCharacter, 1, 1, this->mpFILE);
    if (nBytesRead <= 0)
        return false;

    if (cCharacter <= 0x7f)
    {
        wch = cCharacter;
        if (cCharacter == '\r' && mChFmtr.getExpandLF()) {
            unsigned char cNewLine = 0;
            nBytesRead = (int) ::fread(&cNewLine, 1, 1, this->mpFILE);
            if (nBytesRead <= 0)
                return true;
            if (cNewLine != '\n') {
                ::fseek(this->mpFILE, -1L, SEEK_CUR);
                return true;
            }
            wch = L'\n';
        }
        return true;
    }

    int nByteCount;
    char chBuffer[4] = {0};
    chBuffer[0] = ((char) cCharacter);
    if ((chBuffer[0] & 0xe0) == 0xc0)
        nByteCount = 2;
    else if((chBuffer[0] & 0xf0) == 0xe0)
        nByteCount = 3;
    else if((chBuffer[0] & 0xf8) == 0xf0)
        nByteCount = 4;
    else
    {
        ZcFILE_Assert(false);
        return false;
    }
    nBytesRead = (int) ::fread(&chBuffer[1],
                               1,
                               nByteCount - 1,
                               this->mpFILE);

    ZcFILE_Assert(nBytesRead == nByteCount - 1);
    if (nBytesRead < nByteCount - 1)
        return false;

    const int nCvted = MultiByteToWideChar(CP_UTF8,
                                           0,
                                           chBuffer,
                                           nByteCount,
                                           &wch,
                                           1);

    ZcFILE_Assert(nCvted == 1);
    return nCvted == 1;
}

inline bool ZcFILE::parseUtf16(wchar_t &wch)
{
    wchar_t wchLocal = 0;
    int nBytesRead = (int) ::fread(&wchLocal, 1, 2, this->mpFILE);
    if (nBytesRead <= 0)
        return false;

    const unsigned nFormat = this->mChFmtr.getFormat();
    if (nFormat == ZdCharFormatter::kUtf16BE)
        wchLocal = (wchLocal >> 8) | (wchLocal << 8);

    wch = wchLocal;
    if (wchLocal == L'\r' && mChFmtr.getExpandLF()) {
        wchar_t wchNewLine = L'\n';
        nBytesRead = (int) ::fread(&wchNewLine, 1, 2, this->mpFILE);
        if (nBytesRead <= 0)
            return true;

        if (nFormat == ZdCharFormatter::kUtf16BE)
            wchNewLine = (wchNewLine >> 8) | (wchNewLine << 8);
        if (wchNewLine != L'\n') {
            ::fseek(this->mpFILE, -2L, SEEK_CUR);
            return true;
        }
        wch = L'\n';
    }

    return true;
}

inline int ZcFILE::fputsWorker(const wchar_t* pSrc, int nOptions)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    ZcFILE_Assert(pSrc != NULL);

    int nNumInput = 0;
    for (;;) {
        const wchar_t wch = *pSrc;
        if (wch == 0)
            break;
        char chBuf[8];
        const unsigned nBytes = this->mChFmtr.wcharToBytes(wch, chBuf,
                                                           sizeof(chBuf));
        ZcFILE_Assert(nBytes >= 1);
        ZcFILE_Assert(nBytes <= 8);
        const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1,
                                                    nBytes, this->mpFILE);
        if (nNumWrote != nBytes)
            return -1;
        nNumInput++;
        pSrc++;
    }

    if (nOptions == 0)
        return 0;
    else if (nOptions == 1)
        return nNumInput;
    else {
        ZcFILE_Assert(false);
    }

    return -1;
}

#endif
#pragma warning(pop)

