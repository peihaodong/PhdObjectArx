

#ifndef _zrxiter_h
#define _zrxiter_h 1

#include "zrxobject.h"
#pragma pack (push, 8)

class ZcRxIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxIterator);

    virtual ZSoft::Boolean done() const = 0;
    virtual ZSoft::Boolean next() = 0;
    virtual ZcRxObject*    object() const = 0;
};

#pragma pack (pop)
#endif
