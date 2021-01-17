

#ifndef ZCPLOBJECT_H
#define ZCPLOBJECT_H

#include "zrxobject.h"
#include "zAcHeapOpers.h"

class ZcPlObjectImp;
class ZcPlSystemInternals;

class ZSOFT_NO_VTABLE ZcPlObject : public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcPlObject);
    
    ZCPL_PORT virtual ~ZcPlObject();

protected:
    ZcPlObject();
    ZcPlObject(ZcPlSystemInternals*);

private:
    friend class ZcPlSystemInternals;
    ZcPlObjectImp*  mpPlObjectImp;
};

#define ZCPL_DECLARE_MEMBERS(CLASS_NAME) \
private: \
    friend class ZcPlSystemInternals; \
protected: \
    CLASS_NAME(ZcPlSystemInternals*); \
public: \
    ZCPL_PORT virtual ZcRxClass* isA() const; \
    ZCPL_PORT static ZcRxClass* gpDesc; \
    ZCPL_PORT static ZcRxClass* desc(); \
    ZCPL_PORT static CLASS_NAME* cast(const ZcRxObject* inPtr) \
        { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
          ? NULL : (CLASS_NAME*)inPtr; }; \
    ZCPL_PORT static void rxInit(); \
    ZCPL_PORT static void rxInit(AppNameChangeFuncPtr);

#define ZCPL_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
ZCRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME, BASE_CLASS) \
CLASS_NAME::CLASS_NAME(ZcPlSystemInternals* pInternals) \
: BASE_CLASS(pInternals) \
{ \
}
        
#endif 
