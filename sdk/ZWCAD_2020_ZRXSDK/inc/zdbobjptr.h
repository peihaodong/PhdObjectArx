

#ifndef ZD_DBOBJPTR_H
#define ZD_DBOBJPTR_H

#include <assert.h>
#include "zdbsymtb.h"

#ifdef ASSERT
#define DbObjPtr_Assert ASSERT
#elif defined assert
#define DbObjPtr_Assert assert
#elif defined _ASSERTE
#define DbObjPtr_Assert _ASSERTE
#else
#define DbObjPtr_Assert(T)
#endif

#pragma pack (push, 8)

template<class T_OBJECT>
class ZcDbObjectPointerBase
{
public:
    ZcDbObjectPointerBase();
    virtual ~ZcDbObjectPointerBase();

    const T_OBJECT *  object() const;
    T_OBJECT *        object();

    const T_OBJECT *  operator->() const;
    T_OBJECT *        operator->();
                      operator const T_OBJECT*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
                      operator T_OBJECT* &();
#else
                      operator T_OBJECT*();
#endif

    Zcad::ErrorStatus openStatus() const;

    Zcad::ErrorStatus open(ZcDbObjectId   objId,
                           ZcDb::OpenMode mode,
                           bool           openErased = false);

    Zcad::ErrorStatus acquire(T_OBJECT *& pObjToAcquire);
    Zcad::ErrorStatus release(T_OBJECT *& pReleasedObj);
    Zcad::ErrorStatus close();

    Zcad::ErrorStatus create();

protected:
    ZcDbObjectPointerBase(ZcDbObjectId   objId,
                          ZcDb::OpenMode mode,
                          bool           openErased);

#if DBOBJPTR_EXPOSE_PTR_REF
    ZcDbObjectPointerBase(T_OBJECT * pObject);
    void operator=(T_OBJECT *pObject);
#endif

    T_OBJECT *        m_ptr;
    Zcad::ErrorStatus m_status;

private:
    
    ZcDbObjectPointerBase(ZcDbObjectPointerBase & pObject);
    ZcDbObjectPointerBase& operator=(ZcDbObjectPointerBase & pObject);

    Zcad::ErrorStatus closeInternal();
};

template<class T_OBJECT>
class ZcDbObjectPointer : public ZcDbObjectPointerBase<T_OBJECT>
{
public:
    ZcDbObjectPointer();
    ZcDbObjectPointer(ZcDbObjectId   objId,
                      ZcDb::OpenMode mode,
                      bool           openErased = false);
    
#if DBOBJPTR_EXPOSE_PTR_REF
    ZcDbObjectPointer(T_OBJECT * pObject);
    void operator=(T_OBJECT *pObject);
#endif

    Zcad::ErrorStatus open(ZcDbObjectId objId,
                      ZcDb::OpenMode mode,
                      bool           openErased = false);

private:
    
    ZcDbObjectPointer(ZcDbObjectPointer & pObject);
    ZcDbObjectPointer& operator=(ZcDbObjectPointer & pObject);
};

typedef ZcDbObjectPointer<ZcDbDictionary> ZcDbDictionaryPointer;
typedef ZcDbObjectPointer<ZcDbEntity>     ZcDbEntityPointer;

template<class T_OBJECT>
class ZcDbSymbolTablePointer : public ZcDbObjectPointerBase<T_OBJECT>
{
public:
    ZcDbSymbolTablePointer();
    ZcDbSymbolTablePointer(ZcDbObjectId objId, ZcDb::OpenMode mode);
    ZcDbSymbolTablePointer(ZcDbDatabase * pDb, ZcDb::OpenMode mode);
#if DBOBJPTR_EXPOSE_PTR_REF
    ZcDbSymbolTablePointer(T_OBJECT * pObject);
    void operator=(T_OBJECT *pObject);
#endif

    Zcad::ErrorStatus open(ZcDbObjectId objId, ZcDb::OpenMode mode);
    Zcad::ErrorStatus open(ZcDbDatabase* pDb, ZcDb::OpenMode mode);

private:
    
    ZcDbSymbolTablePointer(ZcDbSymbolTablePointer & pObject);
    ZcDbSymbolTablePointer& operator=(ZcDbSymbolTablePointer & pObject);

    typedef typename T_OBJECT::RecordType T2;
};

typedef ZcDbSymbolTablePointer<ZcDbBlockTable>     ZcDbBlockTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbDimStyleTable>  ZcDbDimStyleTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbLayerTable>     ZcDbLayerTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbLinetypeTable>  ZcDbLinetypeTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbRegAppTable>    ZcDbRegAppTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbTextStyleTable> ZcDbTextStyleTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbUCSTable>       ZcDbUCSTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbViewTable>      ZcDbViewTablePointer;
typedef ZcDbSymbolTablePointer<ZcDbViewportTable>  ZcDbViewportTablePointer;

template<class T_OBJECT>
class ZcDbSymbolTableRecordPointer : public ZcDbObjectPointerBase<T_OBJECT>
{
public:
    ZcDbSymbolTableRecordPointer();
    ZcDbSymbolTableRecordPointer(ZcDbObjectId   objId,
                                 ZcDb::OpenMode mode,
                                 bool           openErased = false);
    ZcDbSymbolTableRecordPointer(const ZTCHAR *   name,
                                 ZcDbDatabase * pDb,
                                 ZcDb::OpenMode mode,
                                 bool           openErased = false);

#if DBOBJPTR_EXPOSE_PTR_REF
    ZcDbSymbolTableRecordPointer(T_OBJECT * pObject);
    void operator=(T_OBJECT *pObject);
#endif

    Zcad::ErrorStatus open(ZcDbObjectId   objId,
                           ZcDb::OpenMode mode,
                           bool           openErased = false);
    Zcad::ErrorStatus open(const ZTCHAR *   name,
                           ZcDbDatabase * pDb,
                           ZcDb::OpenMode mode,
                           bool           openErased = false);

private:
    
    ZcDbSymbolTableRecordPointer(ZcDbSymbolTableRecordPointer & pObject);
    ZcDbSymbolTableRecordPointer&
                       operator=(ZcDbSymbolTableRecordPointer & pObject);

    typedef typename T_OBJECT::TableType T2;
};

typedef ZcDbSymbolTableRecordPointer<ZcDbBlockTableRecord>
                                     ZcDbBlockTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbDimStyleTableRecord>
                                     ZcDbDimStyleTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbLayerTableRecord>
                                     ZcDbLayerTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbLinetypeTableRecord>
                                     ZcDbLinetypeTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbRegAppTableRecord>
                                     ZcDbRegAppTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbTextStyleTableRecord>
                                     ZcDbTextStyleTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbUCSTableRecord>
                                     ZcDbUCSTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbViewTableRecord>
                                     ZcDbViewTableRecordPointer;
typedef ZcDbSymbolTableRecordPointer<ZcDbViewportTableRecord>
                                     ZcDbViewportTableRecordPointer;

template<class T_OBJECT> inline
ZcDbObjectPointerBase<T_OBJECT>::ZcDbObjectPointerBase()
    : m_ptr(NULL),
      m_status(Zcad::eNullObjectPointer)
{
}

template<class T_OBJECT> inline
ZcDbObjectPointerBase<T_OBJECT>::ZcDbObjectPointerBase(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
    : m_ptr(NULL),
      m_status(zcdbOpenObject(m_ptr, objId, mode, openErased))
{
}

template<class T_OBJECT> inline
ZcDbObjectPointerBase<T_OBJECT>::~ZcDbObjectPointerBase()
{
    if (m_ptr != NULL) {
        assert(m_status == Zcad::eOk);
        Zcad::ErrorStatus closeStatus = closeInternal();
        assert(closeStatus == Zcad::eOk);
    }
}

template<class T_OBJECT> inline Zcad::ErrorStatus 
ZcDbObjectPointerBase<T_OBJECT>::open(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
{
    if (m_ptr != NULL) {
        assert(m_status == Zcad::eOk);
        Zcad::ErrorStatus closeStatus = closeInternal();
        if (closeStatus != Zcad::eOk)
            return closeStatus;
    }
    m_status = zcdbOpenObject(m_ptr, objId, mode, openErased);
    return m_status;
}

template<class T_OBJECT> inline const T_OBJECT *
ZcDbObjectPointerBase<T_OBJECT>::object() const
{
    assert(m_status == Zcad::eOk);
    assert(m_ptr != NULL);
    DbObjPtr_Assert(m_ptr == NULL || m_ptr->isReadEnabled());
    return m_ptr;
}

template<class T_OBJECT> inline T_OBJECT *
ZcDbObjectPointerBase<T_OBJECT>::object()
{
    assert(m_status == Zcad::eOk);
    assert(m_ptr != NULL);
    DbObjPtr_Assert(m_ptr == NULL || m_ptr->isReadEnabled());
    return m_ptr;
}

template<class T_OBJECT> inline const T_OBJECT *
ZcDbObjectPointerBase<T_OBJECT>::operator->() const
{
    return object();
}

template<class T_OBJECT> inline T_OBJECT *
ZcDbObjectPointerBase<T_OBJECT>::operator->()
{
    return object();
}

template<class T_OBJECT> inline 
ZcDbObjectPointerBase<T_OBJECT>::operator const T_OBJECT*() const
{
    return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF
template<class T_OBJECT> inline 
ZcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT* &()
{
    
    return this->m_ptr;
}
#else
template<class T_OBJECT> inline 
ZcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT*()
{
    return object();
}
#endif

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::openStatus() const
{
    return m_status;
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::acquire(T_OBJECT *& pObjToAcquire)
{
    if (pObjToAcquire == NULL)
        return Zcad::eNullObjectPointer;
    if (m_ptr != NULL) {
        assert(m_status == Zcad::eOk);
        Zcad::ErrorStatus closeStatus = closeInternal();
        if (closeStatus != Zcad::eOk)
            return closeStatus;
    }
    m_ptr = pObjToAcquire;
    m_status = Zcad::eOk;
    pObjToAcquire = NULL;
    return Zcad::eOk;
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::release(T_OBJECT *& pReleasedObj)
{
    if (m_ptr == NULL)
        return Zcad::eNullObjectPointer;
    assert(m_status == Zcad::eOk);
    pReleasedObj = m_ptr;
    m_ptr    = NULL;
    m_status = Zcad::eNullObjectPointer;
    return Zcad::eOk;
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::close()
{
    if (m_ptr == NULL)
        return Zcad::eNullObjectPointer;
    assert(m_status == Zcad::eOk);
    Zcad::ErrorStatus closeStatus = closeInternal();
    assert(closeStatus == Zcad::eOk);
    return Zcad::eOk;
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::create()
{
    T_OBJECT * pObject = new T_OBJECT;
    if (pObject == NULL)
        return Zcad::eNullObjectPointer;
    if (m_ptr != NULL) {
        assert(m_status == Zcad::eOk);
        Zcad::ErrorStatus closeStatus = closeInternal();
        if (closeStatus != Zcad::eOk) {
            delete pObject;
            return closeStatus;
        }
    }
    m_ptr = pObject;
    m_status = Zcad::eOk;
    return Zcad::eOk;
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointerBase<T_OBJECT>::closeInternal()
{
    if (m_ptr == NULL)
        return Zcad::eOk;
    Zcad::ErrorStatus es = Zcad::eOk;
    if (m_ptr->objectId().isNull()) {
        delete m_ptr;
        es = Zcad::eOk;
    } else {
        es = m_ptr->close();
    }
    m_ptr       = NULL;
    m_status    = Zcad::eNullObjectPointer;
    return es;
}

template<class T_OBJECT> inline
ZcDbObjectPointer<T_OBJECT>::ZcDbObjectPointer()
    : ZcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
ZcDbObjectPointer<T_OBJECT>::ZcDbObjectPointer(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
    : ZcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbObjectPointer<T_OBJECT>::open(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
{
    return ZcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}

template<class T_OBJECT> inline
ZcDbSymbolTablePointer<T_OBJECT>::ZcDbSymbolTablePointer()
    : ZcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
ZcDbSymbolTablePointer<T_OBJECT>::ZcDbSymbolTablePointer(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode)
    : ZcDbObjectPointerBase<T_OBJECT>(objId, mode, false)
{
}

template<class T_OBJECT> inline
ZcDbSymbolTablePointer<T_OBJECT>::ZcDbSymbolTablePointer(
    ZcDbDatabase * pDb,
    ZcDb::OpenMode mode)
    : ZcDbObjectPointerBase<T_OBJECT>()
{
  this->m_status = (pDb == NULL) ? Zcad::eNullObjectPointer
                             : pDb->getSymbolTable(this->m_ptr, mode);
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbSymbolTablePointer<T_OBJECT>::open(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode)
{
    return ZcDbObjectPointerBase<T_OBJECT>::open(objId, mode, false);
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbSymbolTablePointer<T_OBJECT>::open(
    ZcDbDatabase* pDb,
    ZcDb::OpenMode mode)
{
    if (pDb == NULL)
        return Zcad::eInvalidInput;
    Zcad::ErrorStatus es = Zcad::eOk;
    if (this->m_ptr != NULL)
        es = this->close();
    if (es == Zcad::eOk) {
        es = pDb->getSymbolTable(this->m_ptr, mode);
        this->m_status = es;
    }
    return es;
}

template<class T_OBJECT> inline
ZcDbSymbolTableRecordPointer<T_OBJECT>::ZcDbSymbolTableRecordPointer()
    : ZcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
ZcDbSymbolTableRecordPointer<T_OBJECT>::ZcDbSymbolTableRecordPointer(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
    : ZcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

template<class T_OBJECT> inline
ZcDbSymbolTableRecordPointer<T_OBJECT>
    ::ZcDbSymbolTableRecordPointer(
    const ZTCHAR *   name,
    ZcDbDatabase * pDb,
    ZcDb::OpenMode mode,
    bool           openErased)
    : ZcDbObjectPointerBase<T_OBJECT>()
{
    if (name == NULL)
        this->m_status = Zcad::eInvalidInput;
    else {
        ZcDbSymbolTablePointer<typename T_OBJECT::TableType>
            pTable(pDb, ZcDb::kForRead);
        this->m_status = pTable.openStatus();
        if (this->m_status == Zcad::eOk)
           this->m_status = pTable->getAt(name, this->m_ptr, mode, openErased);
    }
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbSymbolTableRecordPointer<T_OBJECT>::open(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased)
{
    return ZcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}

template<class T_OBJECT> inline Zcad::ErrorStatus
ZcDbSymbolTableRecordPointer<T_OBJECT>
    ::open(const ZTCHAR *   name,
           ZcDbDatabase * pDb,
           ZcDb::OpenMode mode,
           bool           openErased)
{
    if (name == NULL)
        return Zcad::eInvalidInput;
    else {
        ZcDbSymbolTablePointer<typename T_OBJECT::TableType>
            pTable(pDb, ZcDb::kForRead);
        Zcad::ErrorStatus es = pTable.openStatus();
        if (es == Zcad::eOk) {
            if (this->m_ptr != NULL)
                es = this->close();
            if (es == Zcad::eOk) {
                es = pTable->getAt(name, this->m_ptr, mode, openErased);
                this->m_status = es;
            }
        }
        return es;
    }
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT> inline
ZcDbObjectPointerBase<T_OBJECT>::ZcDbObjectPointerBase(T_OBJECT *pObject)
    : m_ptr(NULL),
      m_status(Zcad::eNullObjectPointer)
{
    if (pObject != NULL)
        this->acquire(pObject);
}

template<class T_OBJECT> inline void
ZcDbObjectPointerBase<T_OBJECT>::operator=(T_OBJECT *pObject)
{
    if (pObject == NULL) {
        DbObjPtr_Assert(this->m_ptr == NULL);
    }
    else
        this->acquire(pObject);
}

template<class T_OBJECT> inline
ZcDbObjectPointer<T_OBJECT>::ZcDbObjectPointer(T_OBJECT *pObject)
                : ZcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline ZcDbSymbolTablePointer<T_OBJECT>::
        ZcDbSymbolTablePointer(T_OBJECT *pObject)
                : ZcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline ZcDbSymbolTableRecordPointer<T_OBJECT>::
        ZcDbSymbolTableRecordPointer(T_OBJECT *pObject)
                : ZcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline void
ZcDbObjectPointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
    ZcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

template<class T_OBJECT> inline void
ZcDbSymbolTablePointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
    ZcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

template<class T_OBJECT> inline void
ZcDbSymbolTableRecordPointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
    ZcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

#endif  

#pragma pack (pop)

#endif 
