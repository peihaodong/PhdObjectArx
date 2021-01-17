
#ifndef ZD_DBDICT_H
#define ZD_DBDICT_H

#include "zdbmain.h"

#pragma pack(push, 8)

class ZcDbImpDictionary;
class ZcString;

class ZSOFT_NO_VTABLE ZcDbDictionaryIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDictionaryIterator);
    virtual ~ZcDbDictionaryIterator() {}

    virtual const ZTCHAR*      name       () const = 0;

    virtual Zcad::ErrorStatus getObject  (ZcDbObject*&   pObject,
                                          ZcDb::OpenMode mode) = 0;
    virtual ZcDbObjectId      objectId   () const = 0;

    virtual bool              done       () const = 0;
    virtual bool              next       () = 0;
    virtual bool              setPosition(ZcDbObjectId objId) = 0;

protected:
    ZcDbDictionaryIterator() {}
};

class ZcDbDictionary: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDictionary);
    ZcDbDictionary();
    virtual ~ZcDbDictionary();

    Zcad::ErrorStatus getAt(const ZTCHAR*   entryName,
                            ZcDbObject*&   entryObj,
                            ZcDb::OpenMode mode) const;
    Zcad::ErrorStatus getAt(const ZTCHAR*   entryName,
                            ZcDbObjectId&  entryObj) const;
    Zcad::ErrorStatus nameAt(ZcDbObjectId objId,
                             ZTCHAR*&      name) const;
    Zcad::ErrorStatus nameAt(ZcDbObjectId objId,
                             ZcString &   name) const;
    bool              has       (const ZTCHAR*  entryName) const;
    bool              has       (ZcDbObjectId objId) const;
    ZSoft::UInt32     numEntries() const;

    Zcad::ErrorStatus remove(const ZTCHAR *  key);
    Zcad::ErrorStatus remove(const ZTCHAR *  key,
                             ZcDbObjectId& returnId);
    Zcad::ErrorStatus remove(ZcDbObjectId  objId);

    bool              setName(const ZTCHAR*   oldName,
                              const ZTCHAR*   newName);
    Zcad::ErrorStatus setAt  (const ZTCHAR*   srchKey,
                              ZcDbObject*   newValue,
                              ZcDbObjectId& retObjId);

    bool              isTreatElementsAsHard () const;
    void              setTreatElementsAsHard(bool doIt);

	ZcDbDictionaryIterator* newIterator() const;

    virtual Zcad::ErrorStatus subErase     (ZSoft::Boolean pErasing
                                                = ZSoft::kTrue);
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const;
    virtual void  setMergeStyle(ZcDb::DuplicateRecordCloning style);

    virtual void goodbye(const ZcDbObject* pObject);
    virtual void erased (const ZcDbObject* pObject,
                         ZSoft::Boolean pErasing = ZSoft::kTrue);

    virtual Zcad::ErrorStatus decomposeForSave(
                                  ZcDb::ZcDbDwgVersion ver,
                                  ZcDbObject*&         replaceObj,
                                  ZcDbObjectId&        replaceId,
                                  ZSoft::Boolean&      exchangeXData);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

#pragma pack(pop)

#endif
