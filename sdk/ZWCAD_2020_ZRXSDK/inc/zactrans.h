

#ifndef   _ZCTRANS_H
#define   _ZCTRANS_H

#include "zrxnames.h"
#include "zaced.h"
#include "zdbptrar.h"
#include "zdbtrans.h"
#include "zacdocman.h"
#pragma pack (push, 8)

class ZcTransactionManager: public ZcDbTransactionManager 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcTransactionManager);

    virtual Zcad::ErrorStatus   enableGraphicsFlush(bool doEnable) = 0;
    virtual void                flushGraphics() = 0; 
};

inline ZcTransactionManager* zcTransactionManagerPtr()
{
	ZcApDocument* pApDoc = zcDocManager->curDocument();
    return pApDoc ? pApDoc->transactionManager() : NULL;
}

#define zctrTransactionManager  zcTransactionManagerPtr()

#pragma pack (pop)
#endif
