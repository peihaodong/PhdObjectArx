

#ifndef ZD_DBIDMAP_H
#define ZD_DBIDMAP_H 1

#include "zacdb.h"
#include "zrxobject.h"

#pragma pack (push, 8)

class ZcDbDatabase;

class ZcDbIdPair
{
public:
    ZcDbIdPair();
    ZcDbIdPair(const ZcDbIdPair&);
    ZcDbIdPair(ZcDbObjectId key, ZcDbObjectId value,
               bool isCloned,
               bool isPrimary = false,
               bool isOwnerXlated = true);

    ZcDbObjectId   key() const;
    ZcDbObjectId   value() const;
    bool           isCloned() const;
    bool           isPrimary() const;
    bool           isOwnerXlated() const;

    void 	   setKey(ZcDbObjectId);
    void	   setValue(ZcDbObjectId);
    void	   setIsCloned(bool isCloned);
    void	   setIsPrimary(bool isPrimary);
    void	   setIsOwnerXlated(bool isOwnerXlated);

private:
    ZcDbObjectId   mKey;
    ZcDbObjectId   mValue;
    bool           mIsCloned : 1;
    bool           mIsPrimary : 1;
    bool           mIsOwnerXlated : 1;
};

class ZcDbIdMappingIter;
class ZcDbImpIdMapping;
class ZcDbImpIdMappingIter;

class ZcDbIdMapping: public  ZcRxObject
{
public:
    ZcDbIdMapping();
    virtual ~ZcDbIdMapping();
    ZCRX_DECLARE_MEMBERS(ZcDbIdMapping);

    virtual Zcad::ErrorStatus		assign(const ZcDbIdPair&);
    virtual bool          		compute(ZcDbIdPair&) const;
    virtual bool                        change(const ZcDbIdPair&);
    virtual bool              		del(ZcDbObjectId key);

	    Zcad::ErrorStatus   destDb(ZcDbDatabase*& db) const;
	    Zcad::ErrorStatus   setDestDb(ZcDbDatabase* db);
	    Zcad::ErrorStatus   origDb(ZcDbDatabase*& db) const;

	    ZcDb::DeepCloneType deepCloneContext() const;
            ZcDb::DuplicateRecordCloning duplicateRecordCloning() const;

    virtual Zcad::ErrorStatus   copyFrom(const ZcRxObject* other);

private:
    friend class ZcDbSystemInternals;
    friend class ZcDbImpIdMappingIter;
    ZcDbIdMapping(const ZcDbIdMapping&);
    ZcDbIdMapping& operator= (const ZcDbIdMapping&);
    ZcDbImpIdMapping* mpImp;
};

class ZcDbIdMappingIter: public  ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbIdMappingIter);
    ZcDbIdMappingIter(const ZcDbIdMapping&);
    virtual ~ZcDbIdMappingIter();

    virtual Zcad::ErrorStatus	iterateOn(const ZcDbIdMapping&);

    virtual void		start();
    virtual bool           	getMap(ZcDbIdPair&);
    virtual bool           	next();
    virtual bool          	done();

private:
    friend class		ZcDbSystemInternals;
    ZcDbImpIdMappingIter*	mpImp;
};

inline
ZcDbObjectId ZcDbIdPair::key() const
{ return mKey; }

inline
ZcDbObjectId ZcDbIdPair::value() const
{ return mValue; }

inline
bool ZcDbIdPair::isCloned() const
{ return mIsCloned; }

inline
bool ZcDbIdPair::isPrimary() const
{ return mIsPrimary; }

inline
bool ZcDbIdPair::isOwnerXlated() const
{ return mIsOwnerXlated; }

inline
void ZcDbIdPair::setKey(ZcDbObjectId key)
{ mKey = key; }

inline
void ZcDbIdPair::setValue(ZcDbObjectId value)
{ mValue = value; }

inline
void ZcDbIdPair::setIsCloned(bool isCloned)
{ mIsCloned = isCloned; }

inline
void ZcDbIdPair::setIsPrimary(bool isPrimary)
{ mIsPrimary = isPrimary; }

inline
void ZcDbIdPair::setIsOwnerXlated(bool isOwnerXlated)
{ mIsOwnerXlated = isOwnerXlated; }

#pragma pack (pop)

#endif

