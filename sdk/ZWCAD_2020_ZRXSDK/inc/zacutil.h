

#ifndef _ZCUTIL_H
#define _ZCUTIL_H

#include <stddef.h>
#include "zacadstrc.h"

#pragma pack (push, 8)

bool              zcutSplitString(
                      size_t &      numLeftBytes,
                      const ZTCHAR *& pRight,
                      const ZTCHAR  * source,
                      unsigned int  delimiter);

void              zcutTrimWhiteSpace(ZTCHAR * pStr);

bool              zcutWcMatchEx(
                      const ZTCHAR * string,
                      const ZTCHAR * pattern,
                      bool         ignoreCase);

size_t            zcutXStrLength(const ZTCHAR * str);

Zcad::ErrorStatus zcutXStrNormalize(
                      ZTCHAR *& pStr,
                      bool preserveCase);

inline Zcad::ErrorStatus
zcutXStrUppercase(ZTCHAR *& pStr)
{ return zcutXStrNormalize(pStr, false); }

#pragma pack (pop)
#endif 
