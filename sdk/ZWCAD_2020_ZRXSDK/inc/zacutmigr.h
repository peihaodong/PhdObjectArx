

#ifndef _ZCUTMIGR_H
#define _ZCUTMIGR_H

#include "zacutmem.h"

#pragma pack (push, 8)

inline Zcad::ErrorStatus newBuffer(char *&pOutput, size_t size)
{
    return ::zcutNewBuffer(pOutput, size);
}

inline Zcad::ErrorStatus newString(const ZTCHAR* pInput, ZTCHAR*& pOutput)
{
    return ::zcutNewString(pInput, pOutput);
}

inline Zcad::ErrorStatus newString(ZTCHAR*& pOutput, int nNumChars)
{
    return ::zcutNewString(pOutput, nNumChars);
}

inline Zcad::ErrorStatus updString(const ZTCHAR* pInput, ZTCHAR*& pOutput)
{
    return ::zcutUpdString(pInput, pOutput);
}

inline void delString(ZTCHAR*& pString)
{
    ::zcutDelString(pString);
}

inline void delBuffer(char*& pString)
{
    ::zcutDelString(pString);
}

#pragma pack (pop)
#endif 
