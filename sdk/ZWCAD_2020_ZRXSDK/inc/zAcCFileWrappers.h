

#pragma once
#pragma warning(push, 4)

#include "zAdCharFmt.h"
#include "zadesk.h"

#ifdef ASSERT
#define ZcCFile_Assert ASSERT
#elif defined assert
#define ZcCFile_Assert assert
#elif defined _ASSERTE
#define ZcCFile_Assert _ASSERTE
#else
#define ZcCFile_Assert(x)
#endif

#ifdef UNICODE
void zcByteSwap(wchar_t &wch);
void zcWriteWCharToCFile(wchar_t wch, CFile *pFile, unsigned nFmt, bool bUseCIF);
bool zcReadCIFFromCFile(CFile *pCFile, wchar_t &wch);
bool zcReadAnsiCharFromCFile(CFile *pCFile, wchar_t &wch, ZdCharFormatter *pChFmtr);
bool zcReadUtf8CharFromCFile(CFile *pCFile, wchar_t &wch, ZdCharFormatter *pChFmtr);
bool zcReadUtf16CharFromCFile(CFile *pCFile, wchar_t &wch, ZdCharFormatter *pChFmtr);
#endif
unsigned zcCheckCFileCharFormat(CFile *pCFile);

class ZcOutputBufMgr
{
  public:
    ZcOutputBufMgr();
    ~ZcOutputBufMgr();
    bool attachBuffer(void *pBuffer, unsigned nBufSize);
    bool detachBuffer();
    bool hasBuffer() const;
    unsigned byteCount() const;
    void * pointer() const;
    void * requestBytes(unsigned nBytesNeeded);
    unsigned takeBytes(unsigned nBytesUsed);
    bool     reset();
  private:
    void * mpBuffer;
    unsigned mnBufSize;
    unsigned mnByteCount;
    unsigned mnBytesRequested;
};

inline ZcOutputBufMgr::ZcOutputBufMgr()
        : mpBuffer(NULL), mnBufSize(0), mnByteCount(0), mnBytesRequested(0)
{
}

inline ZcOutputBufMgr::~ZcOutputBufMgr()
{
    ZcCFile_Assert(this->mnByteCount == 0);
    ZcCFile_Assert(this->mnBytesRequested == 0);
}

inline bool ZcOutputBufMgr::hasBuffer() const
{
    return this->mpBuffer != NULL;
}

inline unsigned ZcOutputBufMgr::byteCount() const
{
    return this->mnByteCount;
}

inline void * ZcOutputBufMgr::pointer() const
{
    return this->mpBuffer;
}

inline bool ZcOutputBufMgr::attachBuffer(void *pBuffer, unsigned nBufSize)
{
    ZcCFile_Assert(pBuffer != NULL);
    ZcCFile_Assert(nBufSize > 2);
    ZcCFile_Assert(nBufSize < 0x10000000);
    ZcCFile_Assert(this->mpBuffer == NULL);
    ZcCFile_Assert(this->mnBufSize == 0);
    ZcCFile_Assert(this->mnByteCount == 0);
    ZcCFile_Assert(this->mnBytesRequested == 0);
    if (this->mpBuffer != NULL || pBuffer == NULL)
        return false;
    this->mpBuffer = pBuffer;
    this->mnBufSize = nBufSize;
    return true;
}

inline bool ZcOutputBufMgr::detachBuffer()
{
    ZcCFile_Assert(this->mpBuffer != NULL);
    ZcCFile_Assert(this->mnBufSize != 0);
    ZcCFile_Assert(this->mnByteCount == 0);
    ZcCFile_Assert(this->mnBytesRequested == 0);
    if (this->mpBuffer == NULL || this->mnByteCount != 0
                               || this->mnBytesRequested != 0)
        return false;
    this->mpBuffer = NULL;
    this->mnBufSize = 0;
    return true;
}

inline void * ZcOutputBufMgr::requestBytes(unsigned nBytesNeeded)
{
    ZcCFile_Assert(this->hasBuffer());
    ZcCFile_Assert(this->mnBytesRequested == 0);
    if (!this->hasBuffer() || this->mnBytesRequested != 0)
        return NULL;
    ZcCFile_Assert(this->mnBufSize >= 2);
    ZcCFile_Assert(this->mnByteCount <= this->mnBufSize);
    ZcCFile_Assert(nBytesNeeded >= 1);
    ZcCFile_Assert(nBytesNeeded < this->mnBufSize);
    if (nBytesNeeded < 1 || nBytesNeeded >= this->mnBufSize)
        return NULL;
    if (this->mnByteCount + nBytesNeeded > this->mnBufSize)
        return NULL;
    this->mnBytesRequested = nBytesNeeded;
    return reinterpret_cast<char *>(this->mpBuffer) + this->mnByteCount;
}

inline unsigned ZcOutputBufMgr::takeBytes(unsigned nBytesUsed)
{
    ZcCFile_Assert(this->hasBuffer());
    ZcCFile_Assert(this->mnBytesRequested != 0);
    ZcCFile_Assert(this->mnBytesRequested >= nBytesUsed);
    if (!this->hasBuffer() || this->mnBytesRequested < nBytesUsed)
        return 0;
    this->mnBytesRequested = 0;
    this->mnByteCount += nBytesUsed;
    ASSERT(this->mnByteCount <= this->mnBufSize);
    return this->mnBufSize - this->mnByteCount;
}

inline bool ZcOutputBufMgr::reset()
{
    ZcCFile_Assert(this->hasBuffer());
    ZcCFile_Assert(this->mnBytesRequested == 0);
    if (!this->hasBuffer() || this->mnBytesRequested != 0)
        return false;
    this->mnByteCount = 0;
    return true;
}

class ZcCFile : public CFile
{
public:

    ZcCFile();
    ZcCFile(HANDLE hFile);
    ZcCFile(LPCTSTR lpszFileName, UINT nOpenFlags);
    virtual ~ZcCFile();
    virtual UINT Read(void *lpBuf, UINT nCount);
    virtual void Write(const void *lpBuf, UINT nCount);
    virtual UINT Read(LPTSTR lpBuf, UINT nCount);
    virtual void Write(LPCTSTR pString, UINT nCount);
    virtual void Write(LPCTSTR pString);
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
    bool attachBuffer(void *pBuffer, unsigned nBufSize);
    bool detachBuffer();
    bool flushBytes();
    bool hasBuffer() const;

  private:
    ZdCharFormatter mChFmtr;
    ZcOutputBufMgr mOutputBufMgr;
};

#ifdef _ZSOFT_WINDOWS_
class ZcCStdioFile : public CStdioFile
{
public:

    ZcCStdioFile();
    ZcCStdioFile(FILE* pOpenStream);
    ZcCStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags);
    virtual ~ZcCStdioFile();
    virtual void WriteString(LPCTSTR lpsz);
    virtual LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
    virtual BOOL ReadString(CString& rString);
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
    bool attachBuffer(void *pBuffer, unsigned nBufSize);
    bool detachBuffer();
    bool flushBytes();
    bool hasBuffer() const;

  private:
    ZdCharFormatter mChFmtr;
    ZcOutputBufMgr mOutputBufMgr;
};
#endif

inline unsigned zcCheckCFileCharFormat(CFile *pCFile)
{
    ZcCFile_Assert(pCFile != NULL);
    ZcCFile_Assert((pCFile->m_hFile) != (CFile::hFileNull));
    const int nLength = (int) pCFile->GetLength();
    if(nLength <= 3)
        return ZdCharFormatter::kAnsi;
    const ULONGLONG ullPrevPos = pCFile->GetPosition();
    pCFile->Seek(0L, SEEK_SET);

    DWORD dwMagicCode = 0;
    pCFile->Read(&dwMagicCode, 4);
    pCFile->Seek(ullPrevPos, SEEK_SET);
    const unsigned nCharFmt = ZdCharFormatter::lookupBOM(dwMagicCode);
    return (nCharFmt == ZdCharFormatter::kUnknown) ?
            ZdCharFormatter::kAnsi : nCharFmt;
}

inline ZcCFile::ZcCFile()
        : mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
{
    this->mChFmtr.setExpandLF(false);
}

inline ZcCFile::ZcCFile(HANDLE hFile)
        : CFile(hFile),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
{
}

inline ZcCFile::ZcCFile(LPCTSTR lpszFileName, UINT nOpenFlags)
        : CFile(lpszFileName, nOpenFlags),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
{
}

inline ZcCFile::~ZcCFile()
{
}

#ifdef UNICODE
inline void zcWriteWCharToCFile(wchar_t wch, CFile *pFile,
                                const ZdCharFormatter &charFmt)
{
    char chBuf[8];
    const int nBytes = charFmt.wcharToBytes(wch, chBuf,
                                            sizeof(chBuf));
    ZcCFile_Assert(nBytes >= 1);
    ZcCFile_Assert(nBytes <= 8);
    pFile->Write(chBuf, nBytes);
}
#endif

inline void ZcCFile::Write(const void * lpBuf, UINT nCount)
{
    this->CFile::Write(lpBuf, nCount);
}

inline void ZcCFile::Write(LPCTSTR lpBuf, UINT nCount)
{
    ZcCFile_Assert(nCount < 0x1000000);
#ifndef UNICODE
    this->CFile::Write(lpBuf, nCount);
#else
    const bool bHasBuffer = this->hasBuffer();
    for (unsigned i = 0; i < nCount; i++) {
        if (!bHasBuffer)
            ::zcWriteWCharToCFile(lpBuf[i], this, this->mChFmtr);
        else {

            const int kReservedSize = 8;
            void *pOutBuf = this->mOutputBufMgr.requestBytes(kReservedSize);
            const int nBytes = this->mChFmtr.wcharToBytes(lpBuf[i],
                                        reinterpret_cast<char *>(pOutBuf),
                                        kReservedSize);
            ZcCFile_Assert(nBytes >= 1);
            ZcCFile_Assert(nBytes <= kReservedSize);
            const unsigned nBytesLeft = this->mOutputBufMgr.takeBytes(nBytes);
            if (nBytesLeft <= kReservedSize)
                this->flushBytes();
        }
    }
#endif
}

inline void ZcCFile::Write(LPCTSTR lpBuf)
{
#ifndef UNICODE
    this->Write(lpBuf, (UINT)strlen(lpBuf));
#else
    this->Write(lpBuf, ZdCharFormatter::wcsLength(lpBuf));
#endif
}

inline UINT ZcCFile::Read(void * lpBuf, UINT nCount)
{
    return this->CFile::Read(lpBuf, nCount);
}

inline bool ZcCFile::readBOM()
{
    const ULONGLONG dwPosition = this->GetPosition();
    ZcCFile_Assert(dwPosition == 0);
    if (dwPosition != 0)
        return false;

    unsigned short nVal;
    if (this->Read(&nVal, 2) == 2) {
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
            if (this->Read(&nByte3, 1) == 1) {
                if (nByte3 == 0xbf) {
                    this->setCharFormat(ZdCharFormatter::kUtf8);
                    return true;
                }
            }
        }
        else if (nVal == 0 || nVal == 0xfeff) {
            unsigned nVal2;
            if (this->Read(&nVal2, 2) == 2) {
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
    this->SeekToBegin();
    return false;
}

inline bool ZcCFile::writeBOM()
{
    ZcCFile_Assert((this->m_hFile) != CFile::hFileNull);
    if ((this->m_hFile) == CFile::hFileNull)
        return false;

    const ULONGLONG dwPosition = this->GetPosition();
    ZcCFile_Assert(dwPosition == 0);
    if (dwPosition != 0)
        return false;

    unsigned nBom = 0;
    const int cbBomSize = ZdCharFormatter::getBOM(nBom,
                                this->getCharFormat());
    if (cbBomSize == 0)
        return false;

    this->Write(&nBom, cbBomSize);
    return true;
}

inline bool ZcCFile::attachBuffer(void *pBuffer, unsigned nBufSize)
{
    return this->mOutputBufMgr.attachBuffer(pBuffer, nBufSize);
}

inline bool ZcCFile::detachBuffer()
{
    return this->mOutputBufMgr.detachBuffer();
}

inline bool ZcCFile::hasBuffer() const
{
    return this->mOutputBufMgr.hasBuffer();
}

inline bool ZcCFile::flushBytes()
{
    ZcCFile_Assert(this->hasBuffer());
    if (!this->hasBuffer())
        return false;
    const unsigned nBytes = this->mOutputBufMgr.byteCount();
    if (nBytes != 0) {
        const void *pBuf = this->mOutputBufMgr.pointer();
        this->Write(pBuf, nBytes);
    }
    this->mOutputBufMgr.reset();
    return true;
}

#ifdef UNICODE
inline void zcByteSwap(wchar_t &wch)
{

    const wchar_t lobits = (wch >> 8) & 0x00ff;
    const wchar_t hibits = (wch << 8) & 0xff00;
    wch = lobits | hibits;
}

inline bool zcReadCIFFromCFile(CFile *pCFile, wchar_t &wch)
{
    const ULONGLONG nCurPos = pCFile->GetPosition();
    char chbuf[9];
    chbuf[0] = '\\';
    const unsigned nCharRead = pCFile->Read(chbuf+1, 1);
    ZcCFile_Assert(nCharRead <= 1);
    if (nCharRead == 1) {
        if (chbuf[1] == 'U' || chbuf[1] == 'u') {

            const unsigned nMoreCharsRead = pCFile->Read(chbuf+2, 5);
            ZcCFile_Assert(nMoreCharsRead <= 5);
            chbuf[2 + nMoreCharsRead] = 0;
            if (ZdCharFormatter::isCIFString(chbuf))
                if (ZdCharFormatter::parseCIF(chbuf, wch))
                    return true;
        }
        else if (chbuf[1] == 'M' || chbuf[1] == 'm') {

            const unsigned nMoreCharsRead = pCFile->Read(chbuf+2, 6);
            ZcCFile_Assert(nMoreCharsRead <= 6);
            chbuf[2 + nMoreCharsRead] = 0;
            if (ZdCharFormatter::isCIFString(chbuf))
                if (ZdCharFormatter::parseCIF(chbuf, wch))
                    return true;
        }
    }

    pCFile->Seek(nCurPos, SEEK_SET);
    return false;
}

inline bool zcReadAnsiCharFromCFile(CFile *pCFile, wchar_t &wch, ZdCharFormatter *pChFmtr)
{
    char chbuf[2];
    const bool bUseCIF = pChFmtr->getUseCIF();
    const int nCharsRead = pCFile->Read(chbuf, 1);
    if (nCharsRead <= 0)
        return false;
    ZcCFile_Assert(nCharsRead == 1);
    if (chbuf[0] >= 0 && static_cast<unsigned char>(chbuf[0]) <= 0x7f) {
        wch = chbuf[0];
        if (chbuf[0] == '\r' && pChFmtr->getExpandLF()) {
            unsigned char newLine = 0;
            const int nBytesRead = pCFile->Read(&newLine, 1);
            if (nBytesRead < 1)
                return true;
            if (newLine != '\n') {
                pCFile->Seek(-1L, CFile::current);
                return true;
            }
            wch = L'\n';
        }
        if (chbuf[0] == '\\' && bUseCIF && zcReadCIFFromCFile(pCFile, wch))
            return true;
        return true;
    }
    bool bDoubleByte = false;
    if (::IsDBCSLeadByte(chbuf[0])) {
        const int nTrailingCharsRead = pCFile->Read(chbuf+1, 1);
        ZcCFile_Assert(nTrailingCharsRead == 1);
        if (nTrailingCharsRead != 1) {
            return false;
        }
        bDoubleByte = true;
    }
    const int nConverted = ::MultiByteToWideChar(
                        CP_ACP,
                        0,
                        chbuf,
                        bDoubleByte ? 2 : 1,
                        &wch,
                        1);
    ZcCFile_Assert(nConverted == 1);
    if (nConverted != 1) {

    }
    return true;
}

inline bool zcReadUtf8CharFromCFile(CFile *pCFile,
                                    wchar_t &wch,
                                    ZdCharFormatter *pChFmtr)
{
    char chbuf[4];
    wch = 0;
    unsigned nCharsRead = pCFile->Read(chbuf, 1);
    if (nCharsRead <= 0)
        return false;
    ZcCFile_Assert(nCharsRead == 1);

    unsigned nByteCount = 1;
    unsigned char firstByte = (unsigned char) chbuf[0];
    if (!(firstByte & 0x80))
    {
        wch = (wchar_t) firstByte;
        if (firstByte == '\r' && pChFmtr->getExpandLF()) {
            unsigned char newLine = 0;
            const int nBytesRead = pCFile->Read(&newLine, 1);
            if (nBytesRead < 1)
                return true;
            if (newLine != '\n') {
                pCFile->Seek(-1L, CFile::current);
                return true;
            }
            wch = L'\n';
        }
        return true;
    }
    if ((firstByte & 0xF0) == 0xF0)
        nByteCount = 4;
    else if ((firstByte & 0xE0) == 0xE0)
        nByteCount = 3;
    else if ((firstByte & 0xC0) == 0xC0)
        nByteCount = 2;
    if(nByteCount > 1)
    {
        nCharsRead = pCFile->Read(&chbuf[1], nByteCount - 1);
        ZcCFile_Assert(nCharsRead >= 1);
        ZcCFile_Assert(nCharsRead == (nByteCount - 1));
    }

    const int nConverted = ::MultiByteToWideChar(
                                CP_UTF8,
                                0,
                                chbuf,
                                nByteCount,
                                &wch,
                                1);
    ZcCFile_Assert(nConverted == 1);
    if (nConverted != 1) {

    }
    return true;
}

inline bool zcReadUtf16CharFromCFile(CFile *pCFile,
                                     wchar_t &wch,
                                     ZdCharFormatter *pChFmtr)
{
    ZcCFile_Assert(pChFmtr != NULL);
    const int nCharsRead = pCFile->Read(&wch, 2);
    if (nCharsRead < 2) {
        wch = 0;
        return false;
    }

    ZcCFile_Assert(nCharsRead == 2);
    const unsigned nFileFormat = pChFmtr->getFormat();
    if (nFileFormat == ZdCharFormatter::kUtf16BE)
        zcByteSwap(wch);
    if (wch == L'\r' && pChFmtr->getExpandLF()) {
        wchar_t wchNewLine = 0;
        const int nBytesRead = pCFile->Read(&wchNewLine, 2);
        if (nBytesRead < 2)
            return true;
        if (nFileFormat == ZdCharFormatter::kUtf16BE)
            zcByteSwap(wchNewLine);
        if (wchNewLine != '\n') {
            pCFile->Seek(-2L, CFile::current);
            return true;
        }
        wch = '\n';
        return true;
    }

    return true;
}
#endif

inline UINT ZcCFile::Read(LPTSTR lpBuf, UINT nCount)
{
#ifndef UNICODE
    return this->CFile::Read(lpBuf, nCount);
#else
    UINT nDestIndex = 0;
    for (;;) {
        ZcCFile_Assert(nDestIndex <= nCount);
        if (nDestIndex == nCount)
            break;
        wchar_t wch = 0;
        bool bReadOk = false;
        switch(this->mChFmtr.getFormat())
        {
          case ZdCharFormatter::kAnsi:
            bReadOk = ::zcReadAnsiCharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf8:
            bReadOk = ::zcReadUtf8CharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf16LE:
          case ZdCharFormatter::kUtf16BE:
            bReadOk = ::zcReadUtf16CharFromCFile(this, wch, &(this->mChFmtr));
            break;
        }

        if (!bReadOk)
            break;
        lpBuf[nDestIndex] = wch;
        nDestIndex++;
    }
    return nDestIndex;
#endif
}

#ifdef _ZSOFT_WINDOWS_
inline ZcCStdioFile::ZcCStdioFile()
        : mChFmtr(ZdCharFormatter::kAnsi,
                  true,
                  false)
{
}

inline ZcCStdioFile::ZcCStdioFile(FILE* pOpenStream)
        : CStdioFile(pOpenStream),
          mChFmtr(ZdCharFormatter::kAnsi,
                  true,
                  false)
{
}

inline ZcCStdioFile::ZcCStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags)
        : CStdioFile(lpszFileName, nOpenFlags),
          mChFmtr(ZdCharFormatter::kAnsi,
                  true,
                  false)
{
}

inline ZcCStdioFile::~ZcCStdioFile()
{
}

inline void ZcCStdioFile::WriteString(LPCTSTR lpsz)
{
#ifndef UNICODE
    this->CStdioFile::WriteString(lpsz);
#else
    const bool bHasBuffer = this->hasBuffer();
    for (;;) {
        const wchar_t wch = *lpsz;
        if (wch == L'\0')
            break;
        if (!bHasBuffer)
            ::zcWriteWCharToCFile(wch, this, this->mChFmtr);
        else {

            const int kReservedSize = 8;
            void *pOutBuf = this->mOutputBufMgr.requestBytes(kReservedSize);
            const int nBytes = this->mChFmtr.wcharToBytes(wch,
                                        reinterpret_cast<char *>(pOutBuf),
                                        kReservedSize);
            ZcCFile_Assert(nBytes >= 1);
            ZcCFile_Assert(nBytes <= kReservedSize);
            const unsigned nBytesLeft = this->mOutputBufMgr.takeBytes(nBytes);
            if (nBytesLeft <= kReservedSize)
                this->flushBytes();
        }
        lpsz++;
    }

#endif
}

inline LPTSTR ZcCStdioFile::ReadString(LPTSTR lpsz, UINT nMax)
{
#ifndef UNICODE
    return this->CStdioFile::ReadString(lpsz, nMax);
#else
    ZcCFile_Assert(lpsz != NULL);
    ZcCFile_Assert(nMax >= 1);
    if (nMax < 1)
        return NULL;
    bool bGotAnyData = false;
    UINT nDestIndex = 0;
    for (;;) {
        ZcCFile_Assert(nDestIndex < nMax - 1);
        if (nDestIndex >= nMax - 1)
            break;
        wchar_t wch = 0;
        bool bReadOk = false;
        switch(this->mChFmtr.getFormat())
        {
          case ZdCharFormatter::kAnsi:
            bReadOk = ::zcReadAnsiCharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf8:
            bReadOk = ::zcReadUtf8CharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf16LE:
          case ZdCharFormatter::kUtf16BE:
            bReadOk = ::zcReadUtf16CharFromCFile(this, wch, &(this->mChFmtr));
            break;
        }

        if (!bReadOk)
            break;
        lpsz[nDestIndex] = wch;
        nDestIndex++;
        bGotAnyData = true;
        if (wch == L'\n' || nDestIndex >= nMax - 1)
            break;
    }
    ZcCFile_Assert(nDestIndex < nMax);
    lpsz[nDestIndex] = 0;
    return bGotAnyData ? lpsz : NULL;
#endif
}

inline BOOL ZcCStdioFile::ReadString(CString& rString)
{
#ifndef UNICODE
    return this->CStdioFile::ReadString(rString);
#else
    rString.Empty();
    bool bGotAnyData = false;
    for (;;) {
        wchar_t wch = 0;
        bool bReadOk = false;
        switch(this->mChFmtr.getFormat())
        {
          case ZdCharFormatter::kAnsi:
            bReadOk = ::zcReadAnsiCharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf8:
            bReadOk = ::zcReadUtf8CharFromCFile(this, wch, &(this->mChFmtr));
            break;
          case ZdCharFormatter::kUtf16LE:
          case ZdCharFormatter::kUtf16BE:
            bReadOk = ::zcReadUtf16CharFromCFile(this, wch, &(this->mChFmtr));
            break;
        }

        if (!bReadOk)
            break;
        bGotAnyData = true;
        if (wch == L'\n')
            break;
        rString.AppendChar(wch);
    }
    return bGotAnyData;
#endif
}

inline bool ZcCStdioFile::readBOM()
{
    const ULONGLONG dwPosition = this->GetPosition();
    ZcCFile_Assert(dwPosition == 0);
    if (dwPosition != 0)
        return false;

    unsigned short nVal;
    if (this->Read(&nVal, 2) == 2) {
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
            if (this->Read(&nByte3, 1) == 1) {
                if (nByte3 == 0xbf) {
                    this->setCharFormat(ZdCharFormatter::kUtf8);
                    return true;
                }
            }
        }
        else if (nVal == 0 || nVal == 0xfeff) {
            unsigned nVal2;
            if (this->Read(&nVal2, 2) == 2) {
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
    this->SeekToBegin();
    return false;
}

inline bool ZcCStdioFile::writeBOM()
{
    ZcCFile_Assert((this->m_hFile) != CFile::hFileNull);
    if ((this->m_hFile) == CFile::hFileNull)
        return false;

    const ULONGLONG dwPosition = this->GetPosition();
    ZcCFile_Assert(dwPosition == 0);
    if (dwPosition != 0)
        return false;

    unsigned nBom = 0;
    const int cbBomSize = ZdCharFormatter::getBOM(nBom,
                                this->getCharFormat());
    if (cbBomSize == 0)
        return false;

    this->Write(&nBom, cbBomSize);
    return true;
}

inline bool ZcCStdioFile::attachBuffer(void *pBuffer, unsigned nBufSize)
{
    return this->mOutputBufMgr.attachBuffer(pBuffer, nBufSize);
}

inline bool ZcCStdioFile::detachBuffer()
{
    return this->mOutputBufMgr.detachBuffer();
}

inline bool ZcCStdioFile::hasBuffer() const
{
    return this->mOutputBufMgr.hasBuffer();
}

inline bool ZcCStdioFile::flushBytes()
{
    ZcCFile_Assert(this->hasBuffer());
    if (!this->hasBuffer())
        return false;
    const unsigned nBytes = this->mOutputBufMgr.byteCount();
    if (nBytes != 0) {
        const void *pBuf = this->mOutputBufMgr.pointer();
        this->Write(pBuf, nBytes);
    }
    this->mOutputBufMgr.reset();
    return true;
}
#endif

#pragma warning(pop)

