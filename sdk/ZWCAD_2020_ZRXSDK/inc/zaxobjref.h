

#ifndef __ZXOBJREF_H_
#define __ZXOBJREF_H_

#include "zdbobjptr.h"
#pragma pack (push, 8)

#pragma warning (disable : 4786)

class ZcAxObjectRef
{
public:
    ZcAxObjectRef();
    ZcAxObjectRef(ZcDbObjectId objId);
    ZcAxObjectRef(ZcDbObject *&  pObj); 
    ~ZcAxObjectRef();
    
    Zcad::ErrorStatus acquire(ZcDbObjectId objId);
    Zcad::ErrorStatus acquire(ZcDbObject *& pObj);

    Zcad::ErrorStatus release(ZcDbObjectId& objId, ZcDbObject *& pObj);
    
    bool isNull();
    ZcDbObjectId objectId();

private:
    
    ZcAxObjectRef(ZcAxObjectRef & ref);
    ZcAxObjectRef& operator=(ZcAxObjectRef & ref);

    void internalRelease();
    
    ZcDbObjectId m_objId;
    ZcDbObject *   m_pObj;
};

inline
ZcAxObjectRef::ZcAxObjectRef()
    : m_objId(NULL),
      m_pObj(NULL)
{
}

inline
ZcAxObjectRef::ZcAxObjectRef(ZcDbObjectId objId)
    : m_objId(NULL),
      m_pObj(NULL)
{   
    acquire(objId);
}

inline
ZcAxObjectRef::ZcAxObjectRef(ZcDbObject *& pObj)
    : m_objId(NULL),
      m_pObj(NULL)
{
    acquire(pObj);
}

inline
ZcAxObjectRef::~ZcAxObjectRef()
{
    internalRelease();
}
    
inline Zcad::ErrorStatus
ZcAxObjectRef::acquire(ZcDbObjectId objId)
{
    if (objId.isNull())
        return Zcad::eNullObjectId;
    
    internalRelease();
    
    m_objId = objId;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus
ZcAxObjectRef::acquire(ZcDbObject *& pObj)
{
    if (NULL == pObj)
        return Zcad::eNullObjectPointer;
    
    if (!pObj->objectId().isNull())
        return acquire(pObj->objectId());

    internalRelease();

    m_pObj = pObj;
    pObj = NULL;
    
    return Zcad::eOk;
}
    
inline Zcad::ErrorStatus
ZcAxObjectRef::release(ZcDbObjectId& objId, ZcDbObject *& pObj)
{
    if (isNull())
        return Zcad::eNullObjectPointer;

    pObj = m_pObj;
    objId = m_objId;

    m_pObj = NULL;
    m_objId.setNull();
    
    return Zcad::eOk;
}

inline void
ZcAxObjectRef::internalRelease()
{
    if (NULL != m_pObj) 
    {
        if (m_pObj->objectId().isNull())
            delete m_pObj;
    
        else
        {
        }
        m_pObj = NULL;
    }
    m_objId.setNull();
}

inline bool
ZcAxObjectRef::isNull()
{
    return (NULL == m_pObj && m_objId.isNull());
}

inline ZcDbObjectId
ZcAxObjectRef::objectId()
{
    return m_objId;
}

template<class T_OBJECT>
class ZcAxObjectRefPtr : public ZcDbObjectPointer<T_OBJECT>
{
public:
    ZcAxObjectRefPtr();
    ZcAxObjectRefPtr(ZcAxObjectRef* const pRef,
                     ZcDb::OpenMode mode,
                     bool           openErased = false);
    ~ZcAxObjectRefPtr();

private:
    
    ZcAxObjectRefPtr(ZcAxObjectRefPtr & pObj);
    ZcAxObjectRefPtr& operator=(ZcAxObjectRefPtr & pObj);

    ZcAxObjectRef* const m_pRef;
};

template<class T_OBJECT> inline
ZcAxObjectRefPtr<T_OBJECT>::ZcAxObjectRefPtr()
    : ZcDbObjectPointer<T_OBJECT>(),
      m_pRef(NULL)
{}

template<class T_OBJECT> inline 
ZcAxObjectRefPtr<T_OBJECT>::ZcAxObjectRefPtr(ZcAxObjectRef* const pRef, ZcDb::OpenMode mode, bool openErased)
    : m_pRef(pRef)
{
    
    if (NULL == pRef)
    {
        this->m_status = Zcad::eNullObjectPointer;
        return;
    }

    ZcDbObjectId objId = pRef->objectId();

    if (!objId.isNull())
        this->m_status = zcdbOpenObject(this->m_ptr, objId, mode, openErased);
    else
    {
        ZcDbObject* pTmp = NULL;
        m_pRef->release(objId, pTmp);

        T_OBJECT* pTyped= T_OBJECT::cast(pTmp);
        if (NULL == pTyped) {
            this->m_ptr = NULL;
            m_pRef->acquire(pTmp);
            this->m_status = Zcad::eNotThatKindOfClass;
        }
        else
            this->acquire(pTyped);
    }
}
    
template<class T_OBJECT> inline
ZcAxObjectRefPtr<T_OBJECT>::~ZcAxObjectRefPtr()
{
    if (NULL != this->m_ptr && this->m_ptr->objectId().isNull()) {
        T_OBJECT* pTmp;
        this->release(pTmp);
        m_pRef->acquire(reinterpret_cast<ZcDbObject*&>(pTmp));
    }
}

typedef ZcAxObjectRefPtr<ZcDbObject> ZcDbObjectRefPtr;
typedef ZcAxObjectRefPtr<ZcDbEntity> ZcDbEntityRefPtr;

#pragma pack (pop)
#endif
