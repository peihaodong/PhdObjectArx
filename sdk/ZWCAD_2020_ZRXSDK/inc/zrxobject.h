

#ifndef ZD_RXOBJECT_H
#define ZD_RXOBJECT_H 1

#include "zrxdefs.h"
#include "zrxboiler.h"
#include "zacadstrc.h"
#pragma pack (push, 8)

#ifdef  ZCDB_API
    #  define   ZCDB_PORT _declspec(dllexport)
#else
    #  define   ZCDB_PORT
#endif

class ZcRxClass;

class ZSOFT_NO_VTABLE ZcRxObject
{
public:
    virtual ~ZcRxObject();

    static ZcRxClass*         desc();
    static ZcRxObject*        cast(const ZcRxObject * inPtr);

    inline bool               isKindOf(const ZcRxClass * aClass) const;

    ZcRxObject*               queryX(const ZcRxClass* protocolClass) const;
    ZcRxObject*               x(const ZcRxClass* protocolClass) const;
    virtual ZcRxClass*        isA() const;

    virtual ZcRxObject*       clone() const;
    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);
    virtual ZSoft::Boolean    isEqualTo(const ZcRxObject * other) const;
    virtual ZcRx::Ordering    comparedTo(const ZcRxObject * other) const;

protected:
    ZcRxObject();
};

inline ZcRxObject::~ZcRxObject()
{
}

#pragma pack (pop)

#include "zrxclass.h"

#define ZCRX_PE_PTR(RxObj,PEClass) PEClass::cast(RxObj-> \
                                            queryX(PEClass::desc()))

#define ZCRX_X_CALL(RxObj,PEClass) PEClass::cast(RxObj->x(PEClass::desc()))

#include "zrxdict.h"

#endif
