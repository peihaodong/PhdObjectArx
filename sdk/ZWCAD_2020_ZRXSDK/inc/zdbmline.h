

#ifndef ZD_DBMLINE_H
#define ZD_DBMLINE_H

#include "zdbmain.h"

#pragma pack(push, 8)

struct Mline
{
    typedef ZSoft::Int8 MlineJustification;
    enum {
        kTop        = 0,
        kZero       = 1,
        kBottom     = 2
    };
    enum {
        kOpen         = 0,
        kClosed       = 1,
        kMerged       = 2
    };
};

class ZcGePlane;

class ZcDbMline: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbMline);
    ZcDbMline();
    virtual ~ZcDbMline();

    Zcad::ErrorStatus setStyle(const ZcDbObjectId &newStyleId);
    ZcDbObjectId      style() const;

    Zcad::ErrorStatus setJustification(Mline::MlineJustification newJust);
    Mline::MlineJustification justification() const;

    Zcad::ErrorStatus setScale(double newScale);
    double            scale() const;

    ZcGeVector3d      normal            () const;
    Zcad::ErrorStatus setNormal(const ZcGeVector3d & newNormal);

    Zcad::ErrorStatus appendSeg(const ZcGePoint3d& newVertex);
    Zcad::ErrorStatus removeLastSeg(ZcGePoint3d& lastVertex);

    Zcad::ErrorStatus moveVertexAt(int index, const ZcGePoint3d& newPosition);

    Zcad::ErrorStatus setClosedMline(bool closed);
    bool              closedMline() const;

    void              setSupressStartCaps(bool supressIt);
    bool              supressStartCaps() const;
    void              setSupressEndCaps(bool supressIt);
    bool              supressEndCaps() const;

    int               numVertices() const;
    int               element(const ZcGePoint3d & pt) const;
    ZcGePoint3d       vertexAt(int index) const;

    ZcGeVector3d      axisAt(int index) const;
    ZcGeVector3d      miterAt(int index) const;
    Zcad::ErrorStatus getParametersAt(int index,
                                      ZcGeVoidPointerArray& params) const;
    Zcad::ErrorStatus setParametersAt(int index,
                                            ZcGeVoidPointerArray& params);

    void              list() const;
    Zcad::ErrorStatus getClosestPointTo(
                         const ZcGePoint3d& givenPoint,
                         ZcGePoint3d& pointOnCurve,
                         bool extend,
                         bool excludeCaps = false) const;
    Zcad::ErrorStatus getClosestPointTo(
                         const ZcGePoint3d& givenPoint,
                         const ZcGeVector3d& normal,
                         ZcGePoint3d& pointOnCurve,
                         bool extend,
                         bool excludeCaps = false) const;

    void              getPlane(ZcGePlane&) const;
    Zcad::ErrorStatus getGeomExtents(ZcDbExtents&) const;

    Zcad::ErrorStatus getSubentPathsAtGsMarker(
                         ZcDb::SubentType      type,
                         ZSoft::GsMarker       gsMark,
                         const ZcGePoint3d&    pickPoint,
                         const ZcGeMatrix3d&   viewXform,
                         int&                  numPaths,
                         ZcDbFullSubentPath*&  subentPaths,
                         int                   numInserts = 0,
                         ZcDbObjectId*         entAndInsertStack = NULL) const;

    Zcad::ErrorStatus getGsMarkersAtSubentPath(const ZcDbFullSubentPath& subPath,
                                               ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

#pragma pack(pop)

#endif
