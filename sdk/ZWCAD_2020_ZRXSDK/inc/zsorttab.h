
#ifndef ZCDB_SORTTAB_H
#define ZCDB_SORTTAB_H 1

#include "zdbmain.h"

class ZcDbImpSortentsTable;

class ZcDbSortentsTable : public ZcDbObject
{

public:

    ZCRX_DECLARE_MEMBERS(ZcDbSortentsTable);

                        ZcDbSortentsTable();
    virtual             ~ZcDbSortentsTable();

    ZSoft::Boolean      sortAs(ZcDbObjectId, ZcDbHandle&) const;
    void                getSortHandle(ZcDbObjectId id, ZcDbHandle& h) const;

    Zcad::ErrorStatus   remove(ZcDbObjectId);

    Zcad::ErrorStatus   moveToBottom(const ZcDbObjectIdArray& ar);
    Zcad::ErrorStatus   moveToTop(const ZcDbObjectIdArray& ar);

    Zcad::ErrorStatus   moveBelow(const ZcDbObjectIdArray& ar,
                                  ZcDbObjectId target);
    Zcad::ErrorStatus   moveAbove(const ZcDbObjectIdArray& ar,
                                  ZcDbObjectId target);

    Zcad::ErrorStatus   swapOrder(ZcDbObjectId, ZcDbObjectId);

    Zcad::ErrorStatus   setBlockId(ZcDbObjectId);
    ZcDbObjectId        blockId() const;

    Zcad::ErrorStatus   firstEntityIsDrawnBeforeSecond(ZcDbObjectId first,
                                                       ZcDbObjectId second,
                                                       bool& result) const;

    Zcad::ErrorStatus   getFullDrawOrder(ZcDbObjectIdArray& ents,
                                         ZSoft::UInt8 honorSortentsMask=0) const;

    Zcad::ErrorStatus   getRelativeDrawOrder(ZcDbObjectIdArray& ar,
                                             ZSoft::UInt8 honorSortentsMask=0) const;

    Zcad::ErrorStatus   setRelativeDrawOrder(const ZcDbObjectIdArray& ar);

    virtual Zcad::ErrorStatus   applyPartialUndo(ZcDbDwgFiler*, ZcRxClass*);
    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler*);
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler*) const;
    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler*);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler*) const;
    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

private:
    friend class ZcDbSystemInternals;
    ZcDbImpSortentsTable*   mpImpObj;
};

#endif 
