

#ifndef ZDB_DBAUDITA_H
#define ZDB_DBAUDITA_H 1

#include "zAdAChar.h"

#pragma pack(push, 8)

class ZcDbDatabase;
class ZcDbAuditInfo;
class ZcDbImpAuditInfo;
class ZcDbAuditImp;
class ZcDbObject;

#define ZCDB_AUDIT_RETURN(pAuditInfo, baseEs, localEs, boilDownLocalStatus)        \
    return (baseEs != eOk)                ?  \
               baseEs                     :  \
               (eOk == localEs)           ?  \
                   eOk                    :  \
                   boilDownLocalStatus    ?  \
                       (pAuditInfo->fixErrors()?  \
                           eFixedAllErrors     :  \
                           eLeftErrorsUnfixed) :  \
                       localEs;

class ZcDbAuditInfo
{
public:

    friend class ZcDbImpAuditInfo;
    friend class ZcDbAuditImp;

    enum AuditPass {
            PASS1 = 1,
            PASS2 = 2
    };

    ZcDbAuditInfo();
    ~ZcDbAuditInfo();

    bool           fixErrors(void) const;

    int numErrors() const;

    int numFixes(void) const;

    void errorsFound(int count);

    void errorsFixed(int count);

    AuditPass auditPass(void) const;

    void printError(const ZTCHAR * name,
                    const ZTCHAR * value,
                    const ZTCHAR * validation,
                    const ZTCHAR * defaultValue);

    void printError(const ZcDbObject *pObj,
                    const ZTCHAR * value,
                    const ZTCHAR * validation,
                    const ZTCHAR * defaultValue);

    void requestRegen();

    void resetNumEntities();
    
    void incNumEntities();

    int numEntities();

    void printNumEntities(const ZTCHAR* msg);
    Zcad::ErrorStatus fetchObject(ZcDbObjectId    originalObjId,
                                    ZcDbObjectId& newObjId,
                                    ZcRxClass*    pObjClass,
                                    bool          uneraseIfPossible = false,
                                    bool          createIfNotFound = true,
                                    bool          externalDbOk = false);
    Zcad::ErrorStatus registerObject(ZcDbHandle handle,
                                     bool       objIsValid,
                                     ZcRxClass* pObjClass);
    Zcad::ErrorStatus updateObject( ZcDbHandle   handle,
                                    bool         setFileObjIsValid,
                                    bool         setNewObjIsValid,
                                    bool         setFileObjClass,
                                    bool         setNewObjClass,
                                    bool         setNewObjId,
                                    bool         fileObjIsValid,
                                    bool         newObjIsValid,
                                    ZcRxClass*   pFileObjClass,
                                    ZcRxClass*   pNewObjClass,
                                    ZcDbObjectId newObjId);

private:

    ZcDbImpAuditInfo * getImpAudit() const;

    ZcDbImpAuditInfo * mpImpAudit;
};

class ZcDbRecover{

    public:
    virtual  int callBack(ZcDbDatabase*) = 0;
};

class  ZcDbImpRecoverCallBack;

class ZcDbRecoverCallBack {

    public:
    ZcDbRecoverCallBack();
    virtual ~ZcDbRecoverCallBack();

    virtual  Zcad::ErrorStatus registerCallBack(ZcDbRecover*);
    virtual  Zcad::ErrorStatus removeCallBack();

    private:

        ZcDbImpRecoverCallBack *mpImpRecoverCallBack;

};

#pragma pack(pop)

#endif
