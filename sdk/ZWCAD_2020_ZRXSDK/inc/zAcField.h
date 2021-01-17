

#pragma once

#include "zadesk.h"
#include "zAdAChar.h"
#include "zAcValue.h"

class ZcDbField;
class ZcDbFieldCache;
class ZcFdFieldResult;
class ZcFdFieldEvaluator;
class ZcFdFieldEvaluatorLoader;
class ZcFdFieldEngine;
class ZcFdFieldValue;
class ZcFdImpFieldFormat;
class ZcDbEvalVariant;

class ZcFdFieldEvaluator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluator);

    ZCDB_PORT ZcFdFieldEvaluator(void);
    ZCDB_PORT virtual ~ZcFdFieldEvaluator(void);

    ZCDB_PORT virtual const ZTCHAR * evaluatorId(void) const;
    ZCDB_PORT virtual const ZTCHAR * evaluatorId(ZcDbField* pField);

    ZCDB_PORT virtual Zcad::ErrorStatus initialize(ZcDbField* pField); 
    ZCDB_PORT virtual Zcad::ErrorStatus compile(ZcDbField* pField, 
                                             ZcDbDatabase* pDb,
                                             ZcFdFieldResult* pResult);
    ZCDB_PORT virtual Zcad::ErrorStatus evaluate(ZcDbField* pField, 
                                             int nContext, 
                                             ZcDbDatabase* pDb, 
                                             ZcFdFieldResult* pResult);
    ZCDB_PORT virtual Zcad::ErrorStatus format(ZcDbField* pField, 
                                             ZTCHAR *& pszValue);

protected:
    ZcFdFieldEvaluator(void*);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZcFdFieldEvaluatorLoader : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEvaluatorLoader);

    ZCDB_PORT ZcFdFieldEvaluatorLoader(void);
    ZCDB_PORT ZcFdFieldEvaluatorLoader(void*);    
    ZCDB_PORT ~ZcFdFieldEvaluatorLoader(void);

    ZCDB_PORT virtual ZcFdFieldEvaluator* getEvaluator(
                                                const ZTCHAR * pszEvalId);
    ZCDB_PORT virtual ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField,
                                             const ZTCHAR *& pszEvalId);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZcFdFieldEngine : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldEngine);

    ZCDB_PORT ZcFdFieldEngine();
    ZCDB_PORT virtual ~ZcFdFieldEngine();

    ZCDB_PORT Zcad::ErrorStatus registerEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
    ZCDB_PORT Zcad::ErrorStatus unregisterEvaluatorLoader(ZcFdFieldEvaluatorLoader* pLoader);
    ZCDB_PORT int   evaluatorLoaderCount    (void) const;
    ZCDB_PORT ZcFdFieldEvaluatorLoader * getEvaluatorLoader(int iIndex);
    ZCDB_PORT ZcFdFieldEvaluator * getEvaluator (const ZTCHAR * pszEvalId);
    ZCDB_PORT ZcFdFieldEvaluator * findEvaluator(ZcDbField* pField, 
                                             const ZTCHAR *& pszEvalId);

protected:
    void        *   mpImpObj;

private:
    friend class ZcFdSystemInternals;
};

class ZcFdFieldResult : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldResult);

    ZcFdFieldResult(void);
    ZCDB_PORT virtual Zcad::ErrorStatus setFieldValue(const ZcValue* pValue);
    ZCDB_PORT virtual Zcad::ErrorStatus setEvaluationStatus(int nStatus, 
                                             int dwErrCode = 0, 
                                             const ZTCHAR * pszMsg = NULL);
};

class ZcFdFieldValue : public ZcValue
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldValue);

    ZCDB_PORT ZcFdFieldValue(void);
    ZCDB_PORT ZcFdFieldValue(ZcFdFieldValue::DataType nDataType);
    ZCDB_PORT ZcFdFieldValue(const ZcFdFieldValue& value);
    ZCDB_PORT ZcFdFieldValue(const ZTCHAR * pszValue);
    ZCDB_PORT ZcFdFieldValue(ZSoft::Int32 lValue);
    ZCDB_PORT ZcFdFieldValue(double fValue);
#ifdef _ZSOFT_WINDOWS_
    ZCDB_PORT ZcFdFieldValue(const __time64_t& date);
    ZCDB_PORT ZcFdFieldValue(const SYSTEMTIME& date);
#endif
    ZCDB_PORT ZcFdFieldValue(const ZcGePoint2d& pt);
    ZCDB_PORT ZcFdFieldValue(double x, double y);
    ZCDB_PORT ZcFdFieldValue(const ZcGePoint3d& pt);
    ZCDB_PORT ZcFdFieldValue(double x, double y, double z);
    ZCDB_PORT ZcFdFieldValue(const ZcDbObjectId& id);
    ZCDB_PORT ZcFdFieldValue(const resbuf& rb);
    ZCDB_PORT ZcFdFieldValue(const ZcDbEvalVariant& evalVar);
    ZCDB_PORT ZcFdFieldValue(const VARIANT& var);
    ZCDB_PORT ZcFdFieldValue(const void* pBuf, DWORD dwBufSize);
};

class ZcFdFieldReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcFdFieldReactor);

    virtual Zcad::ErrorStatus beginEvaluateFields(int nContext,
                                             ZcDbDatabase* pDb);
    virtual Zcad::ErrorStatus endEvaluateFields(int nContext,
                                             ZcDbDatabase* pDb);
};

typedef ZcArray<ZcFdFieldReactor*> FieldReactors;
Zcad::ErrorStatus   zcdbAddFieldReactor     (ZcFdFieldReactor* pReactor);
Zcad::ErrorStatus   zcdbRemoveFieldReactor  (ZcFdFieldReactor* pReactor);
