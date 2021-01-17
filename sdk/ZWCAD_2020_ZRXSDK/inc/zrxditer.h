

#ifndef _ZRXDITER_H
#define _ZRXDITER_H 1

#include "zrxobject.h"
#include "zrxiter.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

class ZcRxDictionaryIterator: public ZcRxIterator
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxDictionaryIterator);

    virtual const ZTCHAR * key   () const = 0;
    virtual ZcRxObject*   object() const = 0;
    virtual ZSoft::UInt32 id    () const = 0;
};

#pragma pack (pop)
#endif
