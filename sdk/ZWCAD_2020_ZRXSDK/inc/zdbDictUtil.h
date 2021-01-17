
#ifndef ZD_DBDICTUTIL_H
#define ZD_DBDICTUTIL_H 1

#include <assert.h>
#include <stddef.h>
#include "zdbdict.h"

namespace ZcDbDictUtil
{

inline Zcad::ErrorStatus
dictionaryNameAt(ZTCHAR*& pName, ZcDbObjectId itemId, ZcDbObjectId ownerDictId)
{
    assert(!itemId.isNull() && !ownerDictId.isNull());
    ZcDbDictionary* pDict;
    Zcad::ErrorStatus es = zcdbOpenObject(pDict, ownerDictId, ZcDb::kForRead);
    if (es == Zcad::eOk) {
        es = pDict->nameAt(itemId, pName);
        pDict->close();
    }
    return es;
}

inline Zcad::ErrorStatus
dictionaryNameAt(ZTCHAR*& pName, ZcDbObjectId itemId)
{
    assert(!itemId.isNull());
    ZcDbObject* pObject;
    Zcad::ErrorStatus es = zcdbOpenObject(pObject, itemId, ZcDb::kForRead);
    if (es != Zcad::eOk)
        return es;
    ZcDbObjectId dictId = pObject->ownerId();
    es = pObject->close();
    assert(es == Zcad::eOk);
    return dictionaryNameAt(pName, itemId, dictId);
}

inline Zcad::ErrorStatus
dictionaryGetAt(ZcDbObjectId& id, const ZTCHAR* name, ZcDbObjectId ownerDictId)
{
    assert(!ownerDictId.isNull());
    ZcDbDictionary* pDict;
    Zcad::ErrorStatus es = zcdbOpenObject(pDict, ownerDictId, ZcDb::kForRead);
    assert(es == Zcad::eOk);
    if (es == Zcad::eOk) {
        es = pDict->getAt(name, id);
        pDict->close();
    }
    return es;
}

#define DBDICTUTIL_MAKE_DICTIONARY_UTILS(LOWERNAME, UPPERNAME) \
inline Zcad::ErrorStatus \
get##UPPERNAME##Id(ZcDbObjectId& id, const ZTCHAR* name, ZcDbDatabase* pDb) \
{ \
    assert(pDb != NULL); \
    return (pDb != NULL) \
        ? dictionaryGetAt(id, name, pDb->LOWERNAME##DictionaryId()) \
        : Zcad::eInvalidInput; \
} \
inline Zcad::ErrorStatus \
get##UPPERNAME##Name(ZTCHAR*& name, ZcDbObjectId itemId) \
{ \
    ZcDbDatabase* pDb = itemId.database(); \
    return (pDb != NULL) \
        ? dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()) \
        : Zcad::eInvalidInput; \
} \
inline bool \
has##UPPERNAME(const ZTCHAR* name, ZcDbDatabase* pDb) \
{ \
    ZcDbObjectId id; \
    return (get##UPPERNAME##Id(id, name, pDb) == Zcad::eOk); \
}

DBDICTUTIL_MAKE_DICTIONARY_UTILS( mLStyle,       MLStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( group,         Group)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( layout,        Layout)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotSettings,  PlotSettings)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotStyleName, PlotStyleName)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( material,      Material)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( color,         Color)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( tableStyle,    TableStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( visualStyle,    VisualStyle)

#undef DBDICTUTIL_MAKE_DICTIONARY_UTILS

}

#endif 
