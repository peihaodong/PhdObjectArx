

#ifndef _zrxdict_h
#define _zrxdict_h 1

#include "zrxobject.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcRxDictionaryIterator;

class ZcRxDictionary: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxDictionary);

    virtual ZcRxObject*    at      (const ZTCHAR* key) const = 0;
    virtual ZcRxObject*    at      (ZSoft::UInt32 id) const = 0;

    ZcRxObject*            atPut   (const ZTCHAR* key, ZcRxObject* pObject);
    virtual ZcRxObject*    atPut   (const ZTCHAR* key, ZcRxObject* pObject,
        ZSoft::UInt32& retId) = 0;
    virtual ZcRxObject*    atPut   (ZSoft::UInt32 id, ZcRxObject* pObject) = 0;

    virtual ZSoft::Boolean resetKey(const ZTCHAR* oldKey, const ZTCHAR* newKey) = 0;
    virtual ZSoft::Boolean resetKey(ZSoft::UInt32 id, const ZTCHAR* newKey) = 0;

    virtual ZSoft::Boolean atKeyAndIdPut(const ZTCHAR* newKey, ZSoft::UInt32 id,
        ZcRxObject* pObject) = 0;

    virtual ZcRxObject*    remove  (const ZTCHAR* key) = 0;
    virtual ZcRxObject*    remove  (ZSoft::UInt32 id) = 0;

    virtual ZSoft::Boolean has     (const ZTCHAR* entryName) const = 0;
    virtual ZSoft::Boolean has     (ZSoft::UInt32 id) const = 0;

    virtual ZSoft::UInt32  idAt    (const ZTCHAR* key) const = 0;

    virtual const ZTCHAR*    keyAt   (ZSoft::UInt32 id) const = 0;

    virtual ZSoft::UInt32  numEntries() const = 0;

    virtual ZcRxDictionaryIterator* newIterator(
        ZcRx::DictIterType type = ZcRx::kDictSorted) = 0;

    virtual ZSoft::Boolean deletesObjects() const = 0;
    virtual ZSoft::Boolean isCaseSensitive() const = 0;
    virtual ZSoft::Boolean isSorted() const = 0;
};

extern "C" ZcRxDictionary* zcrxSysRegistry();

inline ZcRxObject* ZcRxDictionary::atPut(const ZTCHAR* key, ZcRxObject* pObj)
{ ZSoft::UInt32 temp; return atPut(key, pObj, temp); }

#define zcrxClassDictionary \
ZcRxDictionary::cast(zcrxSysRegistry()->at(ZCRX_CLASS_DICTIONARY))

#define zcrxServiceDictionary \
ZcRxDictionary::cast(zcrxSysRegistry()->at(ZCRX_SERVICE_DICTIONARY))

#pragma pack (pop)
#endif
