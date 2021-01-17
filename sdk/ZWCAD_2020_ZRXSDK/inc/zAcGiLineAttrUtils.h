

#pragma once

#include "zacdb.h"

class ZcGiLineAttrUtils
{
public:
    static char ZSOFT_STDCALL zcgiLineWeightToIndex(ZcDb::LineWeight lw);
    static ZcDb::LineWeight ZSOFT_STDCALL zcgiIndexToLineWeight(char index);
};
