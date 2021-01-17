

#ifndef _ZCUTMEM_H
#define _ZCUTMEM_H

#include "zacadstrc.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

Zcad::ErrorStatus zcutNewBuffer(void *&pOutput, size_t size);
Zcad::ErrorStatus zcutNewString(ZTCHAR *&pOutput, int nNumChars);
Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);
Zcad::ErrorStatus zcutUpdString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

void zcutDelBuffer(void *& pBuffer);


inline Zcad::ErrorStatus zcutNewBuffer(char *&pOutput, size_t size)
{
    return ::zcutNewBuffer((void * &)pOutput, size);
}

inline void zcutDelBuffer(char *& pString)
{
    ::zcutDelBuffer((void * &)pString);
}

inline void zcutDelString(char *& pString)
{
    ::zcutDelBuffer((void * &)pString);
}

inline void zcutDelString(wchar_t *& pString)
{
    ::zcutDelBuffer((void * &)pString);
}

#pragma pack (pop)
#endif 
