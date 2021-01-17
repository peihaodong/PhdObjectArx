

#ifndef _ZCUTASRT_H
#define _ZCUTASRT_H
#include "zAdAChar.h"
#pragma pack (push, 8)

void zcutAssertMessage(
    const ZTCHAR *condition,
    const ZTCHAR *filename,
    int         lineNumber,
    const ZTCHAR *status);

#pragma pack (pop)
#endif 
