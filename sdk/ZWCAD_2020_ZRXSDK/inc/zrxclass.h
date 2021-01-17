

#pragma once

#include "zrxobject.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

class ZcRxMemberCollection;
class ZcRxAttributeCollection;
class ZcRxSet;
class ZcRxImpClass;
class ZcRxMemberCollectionBuilder;
typedef void (*ZcRxMemberCollectionConstructorPtr)(ZcRxMemberCollectionBuilder&, void*);


class ZcRxClass: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcRxClass);

    ZcRxObject* addX(ZcRxClass*, ZcRxObject*);
    ZcRxObject* getX(const ZcRxClass*);
    ZcRxObject* delX(ZcRxClass*);
    ZcRxObject* queryX(const ZcRxClass*);

    ZcRxObject* create();
    const ZTCHAR* appName() const;
    const ZTCHAR* dxfName() const;
    const ZTCHAR* name() const;
    void        getClassVersion(int& dwgVer,
                    int& maintVer) const;
    int         proxyFlags() const;

    bool isDerivedFrom(const ZcRxClass*) const;
    ZcRxClass*     myParent() const;
    ZcRx::Ordering comparedTo(const ZcRxObject*) const;

    AppNameChangeFuncPtr appNameCallbackPtr() const;
protected:
	ZcRxClass(const ZTCHAR*name, const ZTCHAR* parent, ZcRxMemberCollectionConstructorPtr  memberConstruct, void* userData = NULL);
	virtual ~ZcRxClass();
private:
	ZcRxClass();
	friend class ZcRxImpClass;
	ZcRxImpClass* m_pImp;
};

ZcRxClass* newZcRxClass(
    const ZTCHAR* className,
    const ZTCHAR* parentClassName,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZTCHAR* dxfName = NULL,
    const ZTCHAR* appName = NULL);

ZcRxClass* newZcRxClass(
    const ZTCHAR* className,
    const ZTCHAR* parentClassName,
    int         dwgVer,
    int         maintVer,
    int         proxyFlags = 0,
    ZcRxObject* (*pseudoConstructor)() = NULL,
    const ZTCHAR* dxfName = NULL,
    const ZTCHAR* appName = NULL,
    AppNameChangeFuncPtr func = NULL);

ZcRxClass* newZcRxClass(
	const ZTCHAR* className,
	const ZTCHAR* parentClassName,
	int         dwgVer,
	int         maintVer,
	int         proxyFlags ,
	ZcRxObject* (*pseudoConstructor)() ,
	const ZTCHAR* dxfName ,
	const ZTCHAR* appName ,
	AppNameChangeFuncPtr func,
	ZcRxMemberCollectionConstructorPtr makeMembers,
	void* userData = NULL);

void zcrxBuildClassHierarchy();

void deleteZcRxClass(ZcRxClass* pClassObj);

inline bool ZcRxObject::isKindOf(const ZcRxClass* pOtherClass) const
{
    const ZcRxClass * pMyClass = this->isA();
    return pMyClass == NULL ? false : pMyClass->isDerivedFrom(pOtherClass);
}

#pragma pack (pop)

