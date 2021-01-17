

#pragma once

#include "zrxdefs.h"
#include "zacadstrc.h"

#pragma pack (push, 8)

class ZcRxProtocolReactor;
class ZcRxProtocolReactorIterator;
class ZcRxProtocolReactorList;
class ZcRxProtocolReactorListIterator;
class ZcRxProtocolReactorManager;
class ZcRxProtocolReactorManagerFactory;

class ZSOFT_NO_VTABLE ZcRxProtocolReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactor);
};

class ZSOFT_NO_VTABLE ZcRxProtocolReactorIterator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactorIterator);
    virtual ZcRxClass* reactorClass () const = 0;
    virtual void start() = 0;
    virtual bool next () = 0;
    virtual bool done () const = 0;
    virtual ZcRxProtocolReactor* object () const = 0;
};

class ZSOFT_NO_VTABLE ZcRxProtocolReactorList : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactorList);
    virtual ZcRxClass* reactorClass() const = 0;
    virtual Zcad::ErrorStatus addReactor   (ZcRxProtocolReactor* pReactor) = 0;
    virtual void              removeReactor(ZcRxProtocolReactor* pReactor) = 0;
    virtual ZcRxProtocolReactorIterator* newIterator () const = 0;
};

class ZSOFT_NO_VTABLE ZcRxProtocolReactorListIterator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactorListIterator);
    virtual void start() = 0;
    virtual bool next () = 0;
    virtual bool done () const = 0;
    virtual ZcRxProtocolReactorList* object () const = 0;
};

class ZSOFT_NO_VTABLE ZcRxProtocolReactorManager: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactorManager);
    virtual ZcRxProtocolReactorList* createReactorList (
                                         ZcRxClass* pReactorClass) = 0;
    virtual ZcRxProtocolReactorListIterator* newIterator () const = 0;
};

class ZSOFT_NO_VTABLE ZcRxProtocolReactorManagerFactory : public ZcRxService
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxProtocolReactorManagerFactory);
    virtual ZcRxProtocolReactorManager* createReactorManager (
                                        ZcRxClass* pRxClass) const = 0;
};

#define zcrxProtocolReactors \
ZcRxProtocolReactorManagerFactory::cast(zcrxServiceDictionary-> \
                                        at(ZCRX_PROTOCOL_REACTOR_MANAGER))

#define ZCRX_PROTOCOL_REACTOR_MANAGER_AT(zcrxClass) \
zcrxProtocolReactors->createReactorManager(zcrxClass)

#define ZCRX_PROTOCOL_REACTOR_LIST_AT(zcrxClass, reactorClass) \
    ZCRX_PROTOCOL_REACTOR_MANAGER_AT(zcrxClass)->createReactorList(reactorClass)

#pragma pack (pop)
