

#ifndef ZCDB_XRECORD_H
#define ZCDB_XRECORD_H

#include "zAdAChar.h"
#include "zdbmain.h"

#define ZCDB_XRECORD_CLASS          ZCRX_T("AcDbXrecord")
#define ZCDB_XRECORD_ITERATOR_CLASS ZCRX_T("AcDbXrecordClass")

#pragma pack(push, 8)

class ZcDbXrecord: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbXrecord);
    ZcDbXrecord();
    virtual ~ZcDbXrecord();

    Zcad::ErrorStatus rbChain(resbuf** ppRb, ZcDbDatabase* auxDb = NULL) const;
    Zcad::ErrorStatus setFromRbChain(const resbuf& pRb,
                                             ZcDbDatabase* auxDb = NULL);

    bool              isXlateReferences() const;
    void              setXlateReferences(bool translate);

    virtual Zcad::ErrorStatus subClose();
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const;
    virtual void  setMergeStyle(ZcDb::DuplicateRecordCloning style);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

class ZcDbImpXrecordIterator;

class ZcDbXrecordIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbXrecordIterator);
 
    ZcDbXrecordIterator(const ZcDbXrecord* pXrecord);
    virtual ~ZcDbXrecordIterator();

    void              start();
    bool              done() const;
    Zcad::ErrorStatus next();
    int               curRestype() const;
    Zcad::ErrorStatus getCurResbuf(resbuf& outItem, ZcDbDatabase* db) const;

protected:
    ZcDbXrecordIterator() {};
private:
    friend class ZcDbXrecord;
    friend class ZcDbImpXrecord;
    ZcDbImpXrecordIterator* mpImpIter;
};

#pragma pack(pop)

#endif
