

#ifndef ZGEOMENT_DBSUBEID_H
#define ZGEOMENT_DBSUBEID_H

#include "zacdb.h"
#include "zdbidar.h"
#include "ZRXExports.h"

#pragma pack (push, 8)

class ZcDbSubentId
{
public:
    ZcDbSubentId();
    ZcDbSubentId(ZcDb::SubentType type, ZSoft::GsMarker index);
    ZcDbSubentId(ZcRxClass* pTypeClass, ZSoft::GsMarker index);

    bool               operator ==(const ZcDbSubentId& id) const;
    bool               operator !=(const ZcDbSubentId& id) const;

    ZcDb::SubentType   type () const;
    void               setType(ZcDb::SubentType);
    ZcRxClass*         typeClass () const;
    void               setTypeClass(ZcRxClass* pClass);
    ZSoft::GsMarker    index() const;
    void               setIndex(ZSoft::GsMarker);
    
private:
    ZcDb::SubentType mType;
    ZSoft::GsMarker  mIndex;
    ZcRxClass*       mpTypeClass;
};

const ZSoft::GsMarker kNullSubentIndex = 0;
__declspec(selectany) extern const ZcDbSubentId kNullSubentId(ZcDb::kNullSubentType, kNullSubentIndex);

class ZcDbFullSubentPath
{
public:
    ZcDbFullSubentPath();
    ZcDbFullSubentPath(ZcDb::SubentType type, ZSoft::GsMarker index);
    ZcDbFullSubentPath(ZcDbObjectId entId, ZcDb::SubentType type, ZSoft::GsMarker index);
    ZcDbFullSubentPath(ZcDbObjectId entId, ZcDbSubentId subId);
    ZcDbFullSubentPath(ZcDbObjectIdArray objectIds, ZcDbSubentId subId);
    ZcDbFullSubentPath(const ZcDbFullSubentPath&);
    ~ZcDbFullSubentPath();

    ZcDbFullSubentPath&     operator =  (const ZcDbFullSubentPath&);

    bool           operator ==(const ZcDbFullSubentPath& id) const;
    bool           operator !=(const ZcDbFullSubentPath& id) const;

    void                objectIds(ZcDbObjectIdArray& objectIds) const;
    ZcDbObjectIdArray&  objectIds();
    const ZcDbObjectIdArray&  objectIds() const;
    const ZcDbSubentId  subentId () const;
    ZcDbSubentId&       subentId ();
	void* userAppData() const;
	void setUserAppData(void* pData);
private:                            
    ZcDbObjectIdArray mObjectIds;
    ZcDbSubentId      mSubentId;
	void*             mpUserAppData;
};

inline ZcDb::SubentType
ZcDbSubentId::type () const
{
    return mType;
}

inline void
ZcDbSubentId::setType(ZcDb::SubentType type)
{
    mType = type;
    if (mType != ZcDb::kClassSubentType)
        mpTypeClass = nullptr;
}

inline ZSoft::GsMarker
ZcDbSubentId::index() const
{
    return mIndex;
}

inline void
ZcDbSubentId::setIndex(ZSoft::GsMarker index)
{
    mIndex = index;
}

inline ZcRxClass*
ZcDbSubentId::typeClass() const
{
    return mpTypeClass;
}

inline void
ZcDbSubentId::setTypeClass(ZcRxClass* pTypeClass)
{
    mpTypeClass = pTypeClass;
    if (mpTypeClass != nullptr)
        mType = ZcDb::kClassSubentType;
}

inline
ZcDbSubentId::ZcDbSubentId() 
    : mType(ZcDb::kNullSubentType), mIndex(kNullSubentIndex), mpTypeClass(nullptr)
{
}

inline
ZcDbSubentId::ZcDbSubentId(ZcDb::SubentType t, ZSoft::GsMarker i)
    : mType(t), mIndex(i), mpTypeClass(nullptr)
{
}

inline
ZcDbSubentId::ZcDbSubentId(ZcRxClass* pTypeClass, ZSoft::GsMarker i)
    : mType(ZcDb::kClassSubentType), mIndex(i), mpTypeClass(pTypeClass)
{
}

inline bool
ZcDbSubentId::operator ==(const ZcDbSubentId& id) const
{
    return ((mIndex == id.mIndex)
            && (mType == id.mType)
            && (mpTypeClass == id.mpTypeClass));
}

inline bool
ZcDbSubentId::operator !=(const ZcDbSubentId& id) const
{
    return ((mIndex != id.mIndex)
            || (mType != id.mType)
            || (mpTypeClass != id.mpTypeClass));
}

inline
ZcDbFullSubentPath::ZcDbFullSubentPath() 
{
}

inline
ZcDbFullSubentPath::ZcDbFullSubentPath(ZcDb::SubentType type,
                                       ZSoft::GsMarker index)
    : mSubentId(type, index)
{
}

inline void
ZcDbFullSubentPath::objectIds(ZcDbObjectIdArray& objectIds) const
{
    objectIds = mObjectIds;
}

inline ZcDbObjectIdArray&
ZcDbFullSubentPath::objectIds()
{
    return mObjectIds;
}

inline const ZcDbObjectIdArray&
ZcDbFullSubentPath::objectIds() const
{
    return mObjectIds;
}

inline const ZcDbSubentId
ZcDbFullSubentPath::subentId () const
{
    return mSubentId;
}

inline ZcDbSubentId&
ZcDbFullSubentPath::subentId ()
{
    return mSubentId;
}

inline void*
ZcDbFullSubentPath::userAppData() const
{
	return mpUserAppData;
}

inline void
ZcDbFullSubentPath::setUserAppData(void* pData)
{
	mpUserAppData = pData;
}


#pragma pack (pop)

#endif

