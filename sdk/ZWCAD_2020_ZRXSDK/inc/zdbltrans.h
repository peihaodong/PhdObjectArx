

#ifndef ZD_DBLTRANS_H
#define ZD_DBLTRANS_H 1

#include "zdbmain.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcDbLongTransWorkSetIterator : public ZcRxObject
{
public:
    virtual ~ZcDbLongTransWorkSetIterator() {};
    ZCRX_DECLARE_MEMBERS(ZcDbLongTransWorkSetIterator);

    virtual void           start (bool incRemovedObjs = false,
                                  bool incSecondaryObjs = false) = 0; 

    virtual bool           done () = 0;
    virtual void           step () = 0;

    virtual ZcDbObjectId   objectId () const = 0;

    virtual bool           curObjectIsErased () const = 0;
    virtual bool           curObjectIsRemoved () const = 0;
    virtual bool           curObjectIsPrimary () const = 0;

};

class ZcDbLongTransaction : public ZcDbObject
{
public:
    ZcDbLongTransaction();
    ~ZcDbLongTransaction();
    ZCDB_DECLARE_MEMBERS(ZcDbLongTransaction);

    enum { kSameDb      = 0,
           kXrefDb      = 1,
           kUnrelatedDb = 2  };

    int                  type () const;
    ZcDbObjectId         originBlock() const;
    ZcDbObjectId         destinationBlock() const;

    Zcad::ErrorStatus    getLongTransactionName(ZTCHAR*&) const;

    Zcad::ErrorStatus    addToWorkSet (ZcDbObjectId id);
    Zcad::ErrorStatus    removeFromWorkSet (ZcDbObjectId id);
    Zcad::ErrorStatus    syncWorkSet ();

    Zcad::ErrorStatus    newWorkSetIterator(
                             ZcDbLongTransWorkSetIterator*& pNewIter,
                             bool incRemovedObjs = false,
                             bool incSecondaryObjs = false) 
                                 const;

    ZcDbObjectId         originObject(ZcDbObjectId id) const;

    bool                 workSetHas(ZcDbObjectId id, 
                                    bool bIncErased = false) const;

    ZcDbIdMapping*       activeIdMap();

    void                 regenWorkSetWithDrawOrder();

    bool                 disallowDrawOrder();
};

#pragma pack (pop)

#endif
