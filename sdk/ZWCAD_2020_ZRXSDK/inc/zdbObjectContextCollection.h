
#ifndef ZCDB_OBJECTCONTEXTCOLLECTION_H
#define ZCDB_OBJECTCONTEXTCOLLECTION_H

#pragma once

#include "zacdb.h"
#include "zdbmain.h"
#include "zAcString.h"
#include "zdbObjContext.h"

#pragma pack (push, 8)

class ZcDbObjectContextCollectionIterator;

class ZSOFT_NO_VTABLE ZcDbObjectContextCollection: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectContextCollection);
    virtual ZcString            name() const = 0;
    virtual ZcDbObjectContext*  currentContext(
                        const ZcDbObject* pRequestingObject) const = 0;
    virtual Zcad::ErrorStatus   setCurrentContext(
                                        const ZcDbObjectContext* pContext) = 0;
    virtual Zcad::ErrorStatus   addContext(
                                        const ZcDbObjectContext* pContext) = 0;
    virtual Zcad::ErrorStatus   removeContext(
                                        const ZcString& contextName) = 0;
    virtual Zcad::ErrorStatus   lockContext(
                                        const ZcDbObjectContext* pContext) = 0;
    virtual Zcad::ErrorStatus   unlockContext() = 0;
    virtual bool                locked() const = 0;
    virtual ZcDbObjectContext*  getContext(
                                        const ZcString& contextName) const = 0;
    virtual bool                hasContext(
                                        const ZcString& contextName) const = 0;
    virtual ZcDbObjectContextCollectionIterator* newIterator() const = 0;
};

class ZSOFT_NO_VTABLE ZcDbObjectContextCollectionIterator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectContextCollectionIterator);
    virtual Zcad::ErrorStatus start() = 0;
    virtual bool              next() = 0;
    virtual bool              done() const = 0;
    virtual Zcad::ErrorStatus getContext(ZcDbObjectContext*& pObjectContext) const = 0;
};
#pragma pack (pop)

#endif
