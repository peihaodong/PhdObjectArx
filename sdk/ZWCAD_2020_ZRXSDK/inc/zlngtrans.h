

#ifndef   _ZLTRANSMAN_H
#define   _ZLTRANSMAN_H

#include "zrxnames.h"
#include "zdbidar.h"
#pragma pack (push, 8)

class ZcDbLongTransaction;
class ZcDbDatabase;
class ZcDbIdMapping;
class ZcApDocument;

#define ZC_LONG_TRANSACTION_MANAGER_OBJ _T("ZcApLongTransactionManager")

class ZcApLongTransactionReactor: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcApLongTransactionReactor);

    virtual void beginCheckOut        (ZcDbLongTransaction& ,
                                       ZcDbObjectIdArray& originList);
    virtual void endCheckOut          (ZcDbLongTransaction& );
    virtual void beginCheckIn         (ZcDbLongTransaction& );
    virtual void endCheckIn           (ZcDbLongTransaction& );
    virtual void abortLongTransaction (ZcDbLongTransaction& );

protected:
    Zcad::ErrorStatus veto ();  

private:
    ZSoft::UInt8 mVeto;

friend class ZcApImpLongTransactionManager;
};

class ZcApLongTransactionManager: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcApLongTransactionManager);

    virtual Zcad::ErrorStatus   checkOut(
                                   ZcDbObjectId& transId,
                                   ZcDbObjectIdArray& objList,
                                   ZcDbObjectId toBlock,
                                   ZcDbIdMapping& errorMap,
                                   ZcDbObjectId lockBlkRef = 
                                       ZcDbObjectId::kNull) = 0;

    virtual Zcad::ErrorStatus   checkIn  (
                                   ZcDbObjectId transId,
                                   ZcDbIdMapping& errorMap,
                                   bool keepObjs = false) = 0;

    virtual Zcad::ErrorStatus   abortLongTransaction(
                                   ZcDbObjectId transId,
                                   bool keepObjs = false) = 0;

    virtual ZcDbObjectId        currentLongTransactionFor(
                                   const ZcApDocument* pDoc) const = 0;

    virtual void                addReactor(ZcApLongTransactionReactor*) = 0;
    virtual void                removeReactor(ZcApLongTransactionReactor*) = 0;

    virtual Zcad::ErrorStatus   addClassFilter (ZcRxClass* ) = 0;
    virtual bool                isFiltered (ZcRxClass* ) const = 0;
};

extern ZcApLongTransactionManager* zcapLongTransactionManagerPtr();
#define zcapLongTransactionManager  zcapLongTransactionManagerPtr()

#pragma pack (pop)
#endif  
