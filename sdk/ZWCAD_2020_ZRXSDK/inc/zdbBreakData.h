

#pragma once

#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbBreakPointRef;

class ZcDbBreakData : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBreakData);

    ZcDbBreakData();
    virtual ~ZcDbBreakData();

    ZcDbObjectId dimObjId() const;
    Zcad::ErrorStatus setDimObjId(const ZcDbObjectId& dimId);

    Zcad::ErrorStatus addBreakPointRef(ZcDbBreakPointRef* ptRef);
    Zcad::ErrorStatus getBreakPointRef(int lineIndex,
                              ZcArray<ZcDbBreakPointRef*>& ptRefs) const;
    Zcad::ErrorStatus getBreakPointRef(ZcArray<ZcDbBreakPointRef*>& ptRefs) const;
    Zcad::ErrorStatus deleteAllBreakPointRefs();
    Zcad::ErrorStatus removeAssociativity(bool force = true);
    Zcad::ErrorStatus postToDb(ZcDbObjectId& breakObjId);
    Zcad::ErrorStatus eraseFromDb(void);
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler*);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler*);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;

    virtual void  modifiedGraphics(const ZcDbEntity* pEnt);
    Zcad::ErrorStatus updateAssociativity(const ZcDbObjectIdArray& ids, int cmdType);
};

class ZcDbBreakPointRef : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBreakPointRef);

    enum BreakPointType {
        kDynamic           = 0,
        kStatic            = 1,
        kStatic2Point      = 2
    };

    ZcDbBreakPointRef();
    virtual ~ZcDbBreakPointRef();

    ZcDbBreakPointRef::BreakPointType pointType() const;
    Zcad::ErrorStatus setPointType(ZcDbBreakPointRef::BreakPointType newVal);
    ZSoft::Int32 lineIndex() const;
    Zcad::ErrorStatus setLineIndex(ZSoft::Int32 index);
    ZcGePoint3d breakPoint() const;
    Zcad::ErrorStatus setBreakPoint(const ZcGePoint3d& pt);
    ZcGePoint3d breakPoint2() const;
    Zcad::ErrorStatus setBreakPoint2(const ZcGePoint3d& pt);
    Zcad::ErrorStatus getBreakPointId(ZcDbFullSubentPath& idPath) const;
    Zcad::ErrorStatus setBreakPointId(const ZcDbFullSubentPath& idPath);
    ZcDbEntity *subentPtr() const;
    Zcad::ErrorStatus intersectWith(const ZcDbEntity* pEnt,
                                    ZcGePoint3dArray& points,
                                    ZcGePoint3dArray& textBoxPts);
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler*);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler*);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;
};

Zcad::ErrorStatus zcdbGetBreakSubentIndex(ZcDbEntity* pEnt,
                                     const ZcGePoint3d& pickPt,
                                     const ZcGeVector3d& viewDir,
                                     int& subentIndex,
                                     ZcGePoint3d& ptOnEnt,
                                     const ZcGeTol& tol = ZcGeContext::gTol);

#pragma pack (pop)

