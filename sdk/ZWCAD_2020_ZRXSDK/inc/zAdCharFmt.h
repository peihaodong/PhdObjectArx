

#pragma once

#pragma warning(push, 4)

#ifdef ASSERT
#define ZdCharFmt_Assert ASSERT
#elif defined assert
#define ZdCharFmt_Assert assert
#elif defined _ASSERTE
#define ZdCharFmt_Assert _ASSERTE
#else
#define ZdCharFmt_Assert(x)
#endif

#include "zadesk.h"
class ZdCharFormatter
{
  public:
    enum {
        kUnknown = 0,
        kAnsi,

        kUtf8,
        kUtf16LE,
        kUtf16BE,
        kUtf32LE,
        kUtf32BE
    };
    enum {
#if defined(WINVER) && (WINVER >= 0x0500)
        kNoBestFitFlag = WC_NO_BEST_FIT_CHARS,
#else
        kNoBestFitFlag = 0x0400,
#endif
        kCIFLen = 7,
        kMIFLen = 8
    };
    ZdCharFormatter(unsigned nFormat, bool bUseCIF, bool bExpandLF) :
                mnFormat(nFormat), mbUseCIF(bUseCIF),
                mbExpandLF(bExpandLF)
    {

        ZdCharFmt_Assert(this->mbUseCIF == false || this->mnFormat == kAnsi);
    }
    ZdCharFormatter() : mnFormat(kAnsi), mbUseCIF(false),
                        mbExpandLF(true) {}
    unsigned static lookupBOM(unsigned nBom)
    {
        if ((nBom & 0x00ffffff) == 0xbfbbef)
            return kUtf8;
        if ((nBom & 0x0000ffff) == 0xfeff)
            return kUtf16LE;
        if ((nBom & 0x0000ffff) == 0xfffe)
            return kUtf16BE;
        if (nBom == 0x0000feff)
            return kUtf32LE;
        if (nBom == 0xfffe0000)
            return kUtf32BE;
        return kUnknown;
    }
    int static getBOM(unsigned &nBom, unsigned nFmt)
    {
        if (nFmt == kUtf8) {
            nBom = 0xbfbbef;
            return 3;
        }
        else if (nFmt == kUtf16LE) {
            nBom = 0xfeff;
            return 2;
        }
        else if (nFmt == kUtf16BE) {
            nBom = 0xfffe;
            return 2;
        }
        else if (nFmt == kUtf32LE) {
            nBom = 0x0000feff;
            return 4;
        }
        else if (nFmt == kUtf32BE) {
            nBom = 0xfffe0000;
            return 4;
        }
        else {
            ZdCharFmt_Assert(nFmt == kUnknown || nFmt == kAnsi);
            return 0;
        }
    }
    template <class ChType> static void putCIF(wchar_t wch, ChType *pDest)
    {
        pDest[0] = '\\';
        pDest[1] = 'U';
        pDest[2] = '+';
        for (int i = 0; i < 4; i++) {
            const ChType n = (ChType)(wch & 0xf);
            pDest[6 - i] = (n <= 9) ? ('0' + n) : ('A' - 10 + n);
            wch >>= 4;
        }
    }
    bool getUseCIF() const { return this->mbUseCIF; }
    bool getExpandLF() const { return this->mbExpandLF; }
    unsigned getFormat() const { return this->mnFormat; }

    bool setUseCIF(bool bUseCIF) {
        const bool bOldUseCIF = this->mbUseCIF;
        this->mbUseCIF = bUseCIF;
        return bOldUseCIF;
    }
    bool setExpandLF(bool bExpandLF) {
        const bool bOldExpandLF = this->mbExpandLF;
        this->mbExpandLF = bExpandLF;
        return bOldExpandLF;
    }
    unsigned setFormat(unsigned nFormat) {
        const unsigned nOldFormat = this->mnFormat;
        this->mnFormat = nFormat;
        return nOldFormat;
    }
    static unsigned wcsLength(const wchar_t * pStr)
    {
        unsigned nLen = 0;
        while (*pStr != L'\0') {
            nLen++;
            pStr++;
        }
        return nLen;
    }
    static unsigned wcharToAnsiOrUtf8(wchar_t wch, char *pDestBuf,
                                      unsigned nDestBufSize,
                                      bool bToAnsi,
                                      bool bUseCIF, bool bExpandLF)
    {
        ZdCharFmt_Assert(bToAnsi || !bUseCIF);
        ZdCharFmt_Assert(nDestBufSize >= 2);
        if (nDestBufSize < 2)
            return 0;
        ZdCharFmt_Assert(!bUseCIF || nDestBufSize >= 7);
        ZdCharFmt_Assert(bToAnsi || nDestBufSize >= 4);
        if (wch >= 0 && wch <= 0x7f) {
            if (wch == L'\n' && bExpandLF) {
                pDestBuf[0] = '\r';
                pDestBuf[1] = '\n';
                return 2;
            }
            pDestBuf[0] = (char)wch;
            ZdCharFmt_Assert(pDestBuf[0] == wch);
            return 1;
        }
        BOOL bUsedDefaultChar = false;
        const unsigned nCvted = ::WideCharToMultiByte(

                    bToAnsi ?  CP_ACP : CP_UTF8,

                    (bToAnsi && bUseCIF) ?  kNoBestFitFlag : 0,
                    &wch,
                    1,
                    pDestBuf,
                    bToAnsi ?  2 : 4,
                    NULL,
                    bToAnsi ?  &bUsedDefaultChar : NULL);

        ZdCharFmt_Assert(nCvted >= 1);
        ZdCharFmt_Assert(nCvted <= 4);
        ZdCharFmt_Assert(nCvted <= 2 || !bToAnsi);
        ZdCharFmt_Assert(!bUsedDefaultChar || bToAnsi);
        if (bToAnsi && bUsedDefaultChar && bUseCIF) {

            putCIF<char>(wch, pDestBuf);
            return 7;
        }
        else
            return nCvted;
    }
    static unsigned wcharToUtf16(wchar_t wch, char * pDestBuf,
                                 unsigned nDestBufSize,
                                 bool bLittleEndian, bool bExpandLF)
    {
        ZdCharFmt_Assert(nDestBufSize >= 2);
        if (nDestBufSize < 2)
            return 0;
        unsigned short *pShortDest = (unsigned short *)pDestBuf;
        unsigned nBytes = 2;
        if (wch == L'\n' && bExpandLF) {
            ZdCharFmt_Assert(nDestBufSize >= 4);

            *pShortDest = bLittleEndian ? 0x000d : 0x0d00;
            nBytes += 2;
            pShortDest++;
        }
        if (bLittleEndian)
            *pShortDest = wch;
        else
            *pShortDest = ((wch >> 8) & 0xff) | ((wch << 8) & 0xff00);
        return nBytes;
    }
    unsigned wcharToBytes(wchar_t wch, char *pDestBuf,
                          unsigned nDestBufSize) const
    {
        if (this->mnFormat == kAnsi || this->mnFormat == kUtf8)
            return wcharToAnsiOrUtf8(wch, pDestBuf, nDestBufSize,
                                     this->mnFormat == kAnsi,
                                     this->mbUseCIF, this->mbExpandLF);
        else if (this->mnFormat == kUtf16LE || this->mnFormat == kUtf16BE) {
            ZdCharFmt_Assert(!this->mbUseCIF);
            return wcharToUtf16(wch, pDestBuf, nDestBufSize,
                                this->mnFormat == kUtf16LE,
                                this->mbExpandLF);
        }
        else {
            ZdCharFmt_Assert(!this->mbUseCIF);
            ZdCharFmt_Assert(nDestBufSize >= 4);
            ZdCharFmt_Assert(this->mnFormat == kUtf32LE ||
                             this->mnFormat == kUtf32BE);
            ZdCharFmt_Assert(this->mnFormat != kUtf32LE);
            ZdCharFmt_Assert(this->mnFormat != kUtf32BE);
            return 0;
        }
    }

    template <class ChType> static bool isHex(ChType ch)
    {

        return (ch >= '0' && ch <= '9') ||
               (ch >= 'A' && ch <= 'F') ||
               (ch >= 'a' && ch <= 'f');
    }

    template <class ChType> static bool isHex(ChType ch, unsigned &uVal)
    {
        if (ch >= '0' && ch <= '9') {
            uVal = ch - '0';
            ZdCharFmt_Assert(uVal <= 9);
            return true;
        }
        if (ch >= 'A' && ch <= 'F') {
            uVal = ch - 'A' + 10;
            ZdCharFmt_Assert(uVal >= 10);
            ZdCharFmt_Assert(uVal <= 15);
            return true;
        }
        if (ch >= 'a' && ch <= 'f') {
            uVal = ch - 'a' + 10;
            ZdCharFmt_Assert(uVal >= 10);
            ZdCharFmt_Assert(uVal <= 15);
            return true;
        }
        return false;
    }
    template <class ChType> static bool isCIFString(const ChType *pSrcBuf)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        if (pSrcBuf[0] == '\\' &&
                (pSrcBuf[1] == 'U' || pSrcBuf[1] == 'u') &&
                pSrcBuf[2] == '+' &&
                isHex<ChType>(pSrcBuf[3])  &&
                isHex<ChType>(pSrcBuf[4])  &&
                isHex<ChType>(pSrcBuf[5])  &&
                isHex<ChType>(pSrcBuf[6]))
            return true;

        return false;
    }
    template <class ChType> static bool isCIFString(
                    const ChType *pSrcBuf, unsigned nSrcBufSize)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        ZdCharFmt_Assert(nSrcBufSize > 0);
        if(nSrcBufSize < 7)
            return false;
        return isCIFString<ChType>(pSrcBuf);
    }
    template <class ChType> static bool parseCIF(
                        const ChType *pSrcBuf, wchar_t &wch)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        if(pSrcBuf == NULL)
            return false;
        if (pSrcBuf[0] != '\\' || (pSrcBuf[1] != 'U' && pSrcBuf[1] != 'u') || pSrcBuf[2] != '+')
            return false;
        unsigned uVal;
        if (!isHex<ChType>(pSrcBuf[3], uVal))
            return false;
        wch = (wchar_t)(uVal << 12);
        if (!isHex<ChType>(pSrcBuf[4], uVal))
            return false;
        wch |= (wchar_t)(uVal << 8);
        if (!isHex<ChType>(pSrcBuf[5], uVal))
            return false;
        wch |= (wchar_t)(uVal << 4);
        if (!isHex<ChType>(pSrcBuf[6], uVal))
            return false;
        wch |= (wchar_t)uVal;

        return true;
    }
    template <class ChType> static bool isMIFString(const ChType *pSrcBuf)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        if (pSrcBuf[0] == '\\' &&
                (pSrcBuf[1] == 'M' || pSrcBuf[1] == 'm')  &&
                pSrcBuf[2] == '+'  &&
                pSrcBuf[3] >= '1'  &&
                pSrcBuf[3] <= '5'  &&
                isHex<ChType>(pSrcBuf[4])  &&
                isHex<ChType>(pSrcBuf[5])  &&
                isHex<ChType>(pSrcBuf[6])  &&
                isHex<ChType>(pSrcBuf[7]))
            return true;

        return false;
    }
    template <class ChType> static bool isMIFString(const ChType *pSrcBuf,
                unsigned nSrcBufSize)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        ZdCharFmt_Assert(nSrcBufSize > 0);
        if(nSrcBufSize < 8)
            return false;
        return isMIFString<ChType>(pSrcBuf);
    }

    static unsigned winCodePageFromMIFIndex(unsigned nIdx)
    {
        return nIdx == 1 ? 932 :
               nIdx == 2 ? 950 :
               nIdx == 3 ? 949 :
               nIdx == 4 ? 1361 :
               nIdx == 5 ? 936 : 0;
    }

    static unsigned char MIFIndexFromWinCodePage(unsigned nCodePage)
    {
        return nCodePage == 932 ? 1 :
               nCodePage == 950 ? 2 :
               nCodePage == 949 ? 3 :
               nCodePage == 1361 ? 4 :
               nCodePage == 936 ? 5 : 0;
    }
    template <class ChType> static bool putMIF(wchar_t wch,
                                ChType *pMbOut, unsigned nWinCodePage)
    {
        const unsigned char nMIFIndex = MIFIndexFromWinCodePage(nWinCodePage);
        if (nMIFIndex == 0)
            return false;
        ZdCharFmt_Assert(nMIFIndex >= 1);
        ZdCharFmt_Assert(nMIFIndex <= 5);
        char mbBuf[2];
        const int nMbChars = isNativeToCodePage(wch, nWinCodePage, mbBuf);
        if (nMbChars == 0)
            return false;
        if (nMbChars == 1) {
            mbBuf[1] = mbBuf[0];
            mbBuf[0] = 0;
        }
        ZdCharFmt_Assert(nMbChars <= 2);
        pMbOut[0] = '\\';
        pMbOut[1] = 'M';
        pMbOut[2] = '+';
        pMbOut[3] = '0' + nMIFIndex;
        unsigned nNibs[4];
        nNibs[0] = mbBuf[0] >> 4;
        nNibs[1] = mbBuf[0];
        nNibs[2] = mbBuf[1] >> 4;
        nNibs[3] = mbBuf[1];
        for (int i = 0; i < 4; i++) {
            const ChType n = (ChType)(nNibs[i] & 0xf);
            pMbOut[4 + i] = (n <= 9) ? ('0' + n) : ('A' - 10 + n);
        }
        return true;
    }
    template <class ChType> static unsigned getMIFCodePage(ChType ch)
    {
        return
                ch == '1' ?  932  :
                ch == '2' ?  950  :
                ch == '3' ?  949  :
                ch == '4' ? 1361  :
                ch == '5' ?  936  :
                0;
    }
    template <class ChType> static bool parseMIF(const ChType *pSrcBuf,
                                                 wchar_t &wch)
    {
        ZdCharFmt_Assert(pSrcBuf != NULL);
        if (pSrcBuf == NULL)
            return false;

        if (pSrcBuf[0] != '\\' || (pSrcBuf[1] != 'M' && pSrcBuf[1] != 'm') || pSrcBuf[2] != '+')
            return false;

        const unsigned nCodePage = getMIFCodePage<ChType>(pSrcBuf[3]);
        if (nCodePage == 0)
            return false;

        char mbBuf[2];
        unsigned uVal;
        if (!isHex<ChType>(pSrcBuf[4], uVal))
            return false;
        mbBuf[0] = (char)(uVal << 4);
        if (!isHex<ChType>(pSrcBuf[5], uVal))
            return false;
        mbBuf[0] |= (char)uVal;

        if (!isHex<ChType>(pSrcBuf[6], uVal))
            return false;
        mbBuf[1] = (char)(uVal << 4);
        if (!isHex<ChType>(pSrcBuf[7], uVal))
            return false;
        mbBuf[1] |= (char)(uVal);
        if (mbBuf[0] == 0) {
            mbBuf[0] = mbBuf[1];
            mbBuf[1] = 0;
        }
        const int nCvted = MultiByteToWideChar(
            nCodePage,
            MB_ERR_INVALID_CHARS,
            mbBuf,
            mbBuf[1] == 0 ? 1 : 2,
            &wch,
            1);
        ZdCharFmt_Assert(nCvted >= 0);
        ZdCharFmt_Assert(nCvted <= 1);
        if(nCvted != 1)
            return false;

        return true;
    }
    static int isNativeToCodePage(wchar_t wch,
                        unsigned nCodePage,
                        char *pChNative = NULL)
    {
        if (wch >= 0 && wch <= 0x7f)
        {
            if (pChNative != NULL) {
                *pChNative = (char)wch;
                ZdCharFmt_Assert(*pChNative == (char)wch);
            }
            return 1;
        }

        BOOL bDefaultUsed = FALSE;

        char chNative[2];
        if (pChNative == NULL)
            pChNative = chNative;
        const int nCvted = WideCharToMultiByte(nCodePage,
                        kNoBestFitFlag,
                        &wch, 1,
                        pChNative, 2,
                        NULL, &bDefaultUsed);
        if (nCvted <= 0 || bDefaultUsed != FALSE)
            return 0;

        return nCvted;
    }
    static int wcharNonNativeToCIF(
        const wchar_t *szSrc,
        wchar_t *szDst,
        size_t cchDstSize,
		bool b2byteCharToCIF = false)
    {
#ifdef _ZSOFT_WINDOWS_
        ZdCharFmt_Assert(szSrc != NULL);
        ZdCharFmt_Assert(szDst == NULL || cchDstSize > 0);
        if (szSrc == NULL || (szDst != NULL && cchDstSize <= 0))
            return 0;

        unsigned int cchWritten = 0;
        wchar_t *lpReadPtr = ((wchar_t *) szSrc);

        while(*lpReadPtr)
        {

            if (szDst && (cchWritten >= cchDstSize - 1))
                break;

            const wchar_t wch = *lpReadPtr;
			int nRet = isNativeToCodePage(wch, CP_ACP);
            if (!(b2byteCharToCIF && (2 == nRet)) && (nRet > 0))
            {
                if (szDst != NULL)
                    *szDst++ = wch;

                cchWritten++;
            }
            else
            {
                if (szDst != NULL)
                {
                    ZdCharFmt_Assert(cchDstSize - cchWritten >= 8);
                    if(cchDstSize - cchWritten < 8)
                        break;

                    putCIF<wchar_t>(wch, szDst);
                    szDst = szDst + 7;
                }

                cchWritten += 7;
            }

            lpReadPtr++;
        }

        if (szDst != NULL)
            *szDst = L'\0';
		return cchWritten + 1;
#else
		return 0;
#endif
    }
    static int wcharFromCIFMIF(
        const wchar_t *szSrc,
        wchar_t *szDst,
        int cchDstSize)
    {
        ZdCharFmt_Assert(szSrc != NULL);
        ZdCharFmt_Assert(szDst == NULL || cchDstSize > 0);
        ZdCharFmt_Assert(szDst != NULL || cchDstSize <= 0);
        if (szSrc == NULL)
            return 0;
        if (szDst != NULL && cchDstSize <= 0)
            return 0;
        if (szDst == NULL && cchDstSize > 0)
            return 0;

        int cchWritten = 0;
        const wchar_t *lpReadPtr  = szSrc;
        wchar_t *lpWritePtr = szDst;
        wchar_t *lpWriteEnd = szDst + cchDstSize;

        if (szDst == NULL && cchDstSize < 0)
        {
            lpWritePtr = const_cast<wchar_t *>(szSrc);
            lpWriteEnd = NULL;
        }

        for (;;) {
            if (lpWritePtr && lpWriteEnd && lpWritePtr >= lpWriteEnd)
                break;

            const wchar_t wch = *lpReadPtr;
            wchar_t wchOut;
            if (parseCIF<wchar_t>(lpReadPtr, wchOut))
                lpReadPtr += 7;
            else if (parseMIF<wchar_t>(lpReadPtr, wchOut))
                lpReadPtr += 8;
            else {
                wchOut = wch;
                lpReadPtr++;
            }

            if (lpWritePtr != NULL)
                *lpWritePtr++ = wchOut;

            cchWritten++;
            if (wch == 0)
                break;
        }

        return cchWritten;
    }
    static int wcharNonNativeToRTF(
        unsigned nCodePage,
        const wchar_t *szSrc,
        int cchSrcLen,
        char *szDst,
        int *pcbDstSize)
    {
        ZdCharFmt_Assert(szSrc != NULL);
        ZdCharFmt_Assert(pcbDstSize != NULL);
        ZdCharFmt_Assert(cchSrcLen >= -1);
        ZdCharFmt_Assert(cchSrcLen < 0x1000000);
        if (szSrc == NULL || pcbDstSize == NULL)
            return 0;
        if (cchSrcLen < -1)
            return 0;
        ZdCharFmt_Assert(szDst == NULL || *pcbDstSize > 0);
        if (szDst != NULL && *pcbDstSize <= 0)
            return 0;

        int cbWritten = 0;
        int cchProcessed = 0;
        for (;;) {
            if (cchSrcLen >= 0) {
                ZdCharFmt_Assert(cchProcessed <= cchSrcLen);
                if (cchProcessed >= cchSrcLen)
                    break;
            }
            char szAnsiBuf[2];
            const wchar_t wch = szSrc[cchProcessed];
            if (wch == L'\0') {
                if (cchSrcLen < 0)
                    break;
            }
            const int cbAnsiSize = isNativeToCodePage(
                wch, nCodePage, szAnsiBuf);

            ZdCharFmt_Assert(cbAnsiSize >= 0);
            ZdCharFmt_Assert(cbAnsiSize <= 2);
            if (cbAnsiSize > 0) {
                if (szDst) {
                    if (cbWritten + cbAnsiSize >= *pcbDstSize)
                        break;
                    szDst[cbWritten] = szAnsiBuf[0];
                    if (cbAnsiSize > 1)
                        szDst[cbWritten+1] = szAnsiBuf[1];
                }
                cbWritten += cbAnsiSize;
            }
            else {
                unsigned short nValue = wch;
                ZdCharFmt_Assert(nValue >= 128);
                int nDigits = 3;
                if (nValue < 1000)       nDigits += 3;
                else if (nValue < 10000) nDigits += 4;
                else                     nDigits += 5;

                if (szDst) {
                    if (cbWritten + nDigits >= *pcbDstSize)
                        break;
                    szDst[cbWritten + 0] = '\\';
                    szDst[cbWritten + 1] = 'u';
                    int i = cbWritten + nDigits - 1;
                    szDst[i] = '?';
                    do {
                        ZdCharFmt_Assert(i > cbWritten + 1);
                        i--;
                        szDst[i] = (char)((nValue % 10) + '0');
                        nValue /= 10;
                    } while (nValue != 0);
                    ZdCharFmt_Assert(i == cbWritten + 2);
                }
                cbWritten += nDigits;
            }
            cchProcessed++;
        }
        *pcbDstSize = cbWritten;
        if (cchSrcLen < 0) {
            if (szDst) szDst[cbWritten] = 0;
            *pcbDstSize = cbWritten + 1;
        }
        return cchProcessed;
    }

  private:
    unsigned mnFormat;
    bool mbUseCIF;
    bool mbExpandLF;
};

#pragma warning(pop)

