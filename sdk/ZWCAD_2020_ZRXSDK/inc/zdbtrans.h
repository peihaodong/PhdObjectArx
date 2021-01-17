

#ifndef   _ZCDBTRANS_H__
#define   _ZCDBTRANS_H__

#include "zdbapserv.h"

#pragma pack (push, 8)

class ZcTransaction;
class ZcTransactionReactor;

class ZcDbTransactionManager: public ZcRxObject
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcDbTransactionManager);

    virtual ZcTransaction*      startTransaction() = 0;
    virtual Zcad::ErrorStatus   endTransaction  () = 0;
    virtual Zcad::ErrorStatus   abortTransaction() = 0;

    virtual int                 numActiveTransactions() = 0;
    virtual ZcTransaction*      topTransaction() = 0;
    virtual Zcad::ErrorStatus   addNewlyCreatedDBRObject(ZcDbObject* obj,
                                     bool add = true) = 0;

    virtual Zcad::ErrorStatus   getAllObjects(ZcDbVoidPtrArray& objs) = 0;

    virtual void                addReactor(ZcTransactionReactor* reactor) = 0;
    virtual void                removeReactor(ZcTransactionReactor* reactor) =0;

    virtual Zcad::ErrorStatus   getObject(ZcDbObject*& obj, ZcDbObjectId id,
                                          ZcDb::OpenMode mode, 
                                          bool openErasedObj = false) = 0; 

    virtual Zcad::ErrorStatus   markObjectPageable(ZcDbObject* pObject) = 0;
    virtual Zcad::ErrorStatus   queueForGraphicsFlush() = 0;

};

class ZcTransaction: public ZcRxObject
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcTransaction);
    virtual 
    Zcad::ErrorStatus getObject(ZcDbObject*& obj, 
                                ZcDbObjectId   objectId, ZcDb::OpenMode mode,
                                bool openErasedObject = false) = 0;

    virtual 
    Zcad::ErrorStatus markObjectPageable(ZcDbObject* pObject) = 0;

    virtual Zcad::ErrorStatus   getAllObjects(ZcDbVoidPtrArray& objs) = 0;
};

class ZcTransactionReactor: public ZcRxObject

{
public:
    ZCRX_DECLARE_MEMBERS(ZcTransactionReactor);

    virtual void transactionAboutToStart (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void transactionStarted      (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void transactionAboutToEnd   (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void transactionEnded        (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void transactionAboutToAbort (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void transactionAborted      (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void endCalledOnOutermostTransaction (int& numTransactions,
        ZcDbTransactionManager* transactionManagerPtr);
    virtual void objectIdSwapped (const ZcDbObject* pTransResObj,
        const ZcDbObject* pOtherObj,
        ZcDbTransactionManager* transactionManagerPtr);
};

inline ZcDbTransactionManager* zcdbTransactionManagerPtr()
{
    return zcdbHostApplicationServices()->workingTransactionManager();
}

#define zcdbTransactionManager  zcdbTransactionManagerPtr()

#pragma pack (pop)

#endif   _ZCDBTRANS_H__
