

#ifndef ZD_DBINDEX_H
#define ZD_DBINDEX_H

#include "zdbmain.h"

#pragma pack(push, 8)

class ZcDbIndexIterator;
class ZcDbFilter;
class ZcDbIndexUpdateData;
class ZcDbBlockChangeIterator;
class ZcDbFilteredBlockIterator;
class ZcDbFilter;
class ZcDbImpDatabase;
class ZcDbBlockTableRecord;
class ZcDbBlockChangeIterator;
class ZcDbIndexUpdateData;

class ZcDbIndex : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbIndex);

    ZcDbIndex();
    virtual ~ZcDbIndex();

    virtual ZcDbFilteredBlockIterator* 
                  newIterator(const ZcDbFilter* pFilter) const;

    virtual Zcad::ErrorStatus rebuildFull(ZcDbIndexUpdateData* pIdxData);
 
    virtual ZcDbObjectId objectBeingIndexedId()  const;

    void           setLastUpdatedAt(const ZcDbDate& time);
    ZcDbDate       lastUpdatedAt() const;

    void           setLastUpdatedAtU(const ZcDbDate& time);
    ZcDbDate       lastUpdatedAtU() const;

    ZSoft::Boolean isUptoDate   () const;  

protected:

    virtual Zcad::ErrorStatus rebuildModified(ZcDbBlockChangeIterator* iter);

    friend class ZcDbImpIndex;
    friend Zcad::ErrorStatus processBTRIndexObjects(
                                   ZcDbBlockTableRecord* pBTR,
                                   int indexCtlVal,
                                   ZcDbBlockChangeIterator* pBlkChgIter,
                                   ZcDbIndexUpdateData*     pIdxUpdData);
};

class ZcDbFilteredBlockIterator
{
public:
    ZcDbFilteredBlockIterator()          {}
    virtual ~ZcDbFilteredBlockIterator() {}

    virtual Zcad::ErrorStatus start()               = 0;
    virtual ZcDbObjectId      next()                = 0;
    virtual ZcDbObjectId      id() const            = 0;
    virtual Zcad::ErrorStatus seek(ZcDbObjectId id) = 0;

    virtual double estimatedHitFraction() const             = 0;
    virtual Zcad::ErrorStatus accepts(ZcDbObjectId id, 
                      ZSoft::Boolean& idPassesFilter) const = 0;

    virtual ZSoft::Boolean    buffersForComposition() const;
    virtual Zcad::ErrorStatus addToBuffer(ZcDbObjectId id);
};

class ZcDbCompositeFilteredBlockIterator
{
private:
    ZcDbCompositeFilteredBlockIterator(
        const ZcDbCompositeFilteredBlockIterator& copyFrom);

protected:
    ZcDbCompositeFilteredBlockIterator() {}

public:
    virtual ~ZcDbCompositeFilteredBlockIterator() {}

    virtual Zcad::ErrorStatus init(ZcDbFilter* const * ppFilters,
                                   int numFilters,
                                   const ZcDbBlockTableRecord* pBtr) = 0;

    virtual Zcad::ErrorStatus start()    = 0;
    virtual ZcDbObjectId      next()     = 0;
    virtual ZcDbObjectId      id() const = 0;

    virtual Zcad::ErrorStatus seek(ZcDbObjectId id)  = 0;
    static ZcDbCompositeFilteredBlockIterator* newIterator();
};

class ZcDbBlockTableRecord;
class ZcDbBlockReference;

namespace ZcDbIndexFilterManager
{

    Zcad::ErrorStatus updateIndexes(ZcDbDatabase* pDb);

    Zcad::ErrorStatus addIndex    (ZcDbBlockTableRecord* pBTR,
                                   ZcDbIndex*            pIndex);

    Zcad::ErrorStatus removeIndex (ZcDbBlockTableRecord* pBTR, 
                                   const ZcRxClass*      key);

    Zcad::ErrorStatus getIndex(const ZcDbBlockTableRecord* pBTR,
                               const ZcRxClass* key, 
                               ZcDb::OpenMode readOrWrite,
                               ZcDbIndex*& pIndex);

    Zcad::ErrorStatus getIndex(const ZcDbBlockTableRecord* pBTR,
                               int index,
                               ZcDb::OpenMode readOrWrite,
                               ZcDbIndex*& pIndex);

    int numIndexes(const ZcDbBlockTableRecord* pBtr);

    Zcad::ErrorStatus addFilter(ZcDbBlockReference* pBlkRef,
                                ZcDbFilter*         pFilter);

    Zcad::ErrorStatus removeFilter(ZcDbBlockReference* pBlkRef,
                                   const ZcRxClass*    key);

    Zcad::ErrorStatus getFilter(const ZcDbBlockReference* pRef,
                                const ZcRxClass*          key,       
                                ZcDb::OpenMode readOrWrite,
                                ZcDbFilter*&   pFilter);
    
    Zcad::ErrorStatus getFilter(const ZcDbBlockReference* pRef,
                                int index,
                                ZcDb::OpenMode readOrWrite,
                                ZcDbFilter*& pFilter);

    int  numFilters(const ZcDbBlockReference* pBlkRef);
};

class ZcDbHandleTable;
class ZcDbHandleTableIterator;

class ZcDbIndexUpdateData 
{
    public:
        
        enum UpdateFlags 
        {                      
            kModified   = 1,   
            kDeleted    = 2,

            kProcessed  = 4,   
            kUnknownKey = 8

        };
        
        Zcad::ErrorStatus addId      (ZcDbObjectId id);

        Zcad::ErrorStatus setIdFlags (ZcDbObjectId id, ZSoft::UInt8 flags);
        
        Zcad::ErrorStatus setIdData  (ZcDbObjectId id, ZSoft::ULongPtr data);
        
        Zcad::ErrorStatus getIdData       (ZcDbObjectId id, ZSoft::ULongPtr& data)  const;
        Zcad::ErrorStatus getIdFlags      (ZcDbObjectId id, ZSoft::UInt8&  flags) const;       
        Zcad::ErrorStatus getFlagsAndData (ZcDbObjectId   id, 
                                           ZSoft::UInt8&  flags, 
                                           ZSoft::ULongPtr& data) const;

    private:
        ZcDbIndexUpdateData();
        ~ZcDbIndexUpdateData();

        ZcDbIndexUpdateData(const ZcDbIndexUpdateData&);

        ZcDbHandleTable* mpTable;

        friend class ZcDbIndexUpdateDataIterator;
        friend class ZcDbImpDatabase;
};

class ZcDbIndexUpdateDataIterator
{
    public:
        ZcDbIndexUpdateDataIterator  (const ZcDbIndexUpdateData* p);
        ~ZcDbIndexUpdateDataIterator ();

        void start   ();
        void next    ();
        bool done    ();

        Zcad::ErrorStatus currentData (ZcDbObjectId&  id, 
                                       ZSoft::UInt8&  flags, 
                                       ZSoft::ULongPtr& data) const;
 
    private:
        ZcDbHandleTableIterator* mpIter;
};

class ZcDbBlockChangeIterator
{
private:
    ZcDbBlockChangeIterator();
    ZcDbBlockChangeIterator(const ZcDbBlockChangeIterator&);

    ZcDbBlockChangeIterator (ZcDbObjectId         btrId,
                             ZcDbIndexUpdateData* pIdxUpdData);
    ~ZcDbBlockChangeIterator();
    
public:
    void         start ();
    ZcDbObjectId id    () const;
    void         next  ();
    bool         done  ();

    Zcad::ErrorStatus    curIdInfo    (ZcDbObjectId&  id,
                                       ZSoft::UInt8&  flags, 
                                       ZSoft::ULongPtr& data) const;

    Zcad::ErrorStatus    setCurIdInfo (ZSoft::UInt8   flags,  
                                       ZSoft::ULongPtr data);

    ZcDbIndexUpdateData* updateData () const;

    void clearProcessedFlags();

private:
    ZcDbIndexUpdateData*         mpIds;
    ZcDbObjectId                 mBTRId;

    ZcDbIndexUpdateDataIterator* mpIter;

    friend class ZcDbImpDatabase;
};


#pragma pack(pop)

#endif 
