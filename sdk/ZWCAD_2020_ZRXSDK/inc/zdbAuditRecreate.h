#ifndef _ZD_DBAUDITRECREATE_H
#define _ZD_DBAUDITRECREATE_H 1

#include "zacdb.h"

class ZcDbAuditRecreatePE : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAuditRecreatePE);
    virtual bool replace(ZcDbObject*&   pNewObj,
                         ZcDbObjectId   originalObjId,
                         ZcRxClass*     pObjClass,
                         ZcDbDatabase*  pDb,
                         ZcDbAuditInfo* pAuditInfo)
    { return false; };
    virtual bool redirect(ZcDbObjectId&  newObjId,
                          ZcDbObjectId   originalObjId,
                          ZcRxClass*     pObjClass,
                          ZcDbDatabase*  pDb,
                          ZcDbAuditInfo* pAuditInfo)
    { return false; };

};

#endif 
