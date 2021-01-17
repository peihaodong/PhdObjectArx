

#ifndef ZD_DBPL_H
#define ZD_DBPL_H 1

#include "zdbmain.h"
#include "zdbcurve.h"

#include "zgelnsg2d.h"
#include "zgelnsg3d.h"
#include "zgearc2d.h"
#include "zgearc3d.h"
#include "zgept2dar.h"
#include "zdbboiler.h"

#pragma pack(push, 8)

class ZcDb2dPolyline;

class ZcDbPolyline : public ZcDbCurve
{

public:
                      ZcDbPolyline();
                      ZcDbPolyline(unsigned int num_verts);
    virtual          ~ZcDbPolyline();

    ZCDB_DECLARE_MEMBERS(ZcDbPolyline);

    virtual Zcad::ErrorStatus convertFrom(ZcDbEntity*& pPline, 
                                  ZSoft::Boolean transferId = ZSoft::kTrue);
    Zcad::ErrorStatus convertTo(ZcDb2dPolyline*&  pPline,
                                ZSoft::Boolean transferId = ZSoft::kTrue) const;

    Zcad::ErrorStatus getPointAt(unsigned int, ZcGePoint3d& pt) const;

    enum SegType {
        kLine,
        kArc,
        kCoincident,
        kPoint,
        kEmpty
    };

    SegType           segType           (unsigned int index) const;

    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg2d& ln) const;
    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg3d& ln) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc2d& arc) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc3d& arc) const;
    virtual ZSoft::Boolean onSegAt      (unsigned int index, const ZcGePoint2d& pt2d,
                                         double& param) const;

    virtual void              setClosed       (ZSoft::Boolean);
    void		              setPlinegen     (ZSoft::Boolean);
    virtual void			  setElevation    (double);
	virtual	Zcad::ErrorStatus setThickness    (double);
	virtual	Zcad::ErrorStatus setConstantWidth(double);
	virtual	Zcad::ErrorStatus setNormal       (const ZcGeVector3d&);

    ZSoft::Boolean    isOnlyLines     ()                        const;
    ZSoft::Boolean    hasPlinegen     ()                        const;
    double            elevation       ()                        const;
    double            thickness       ()                        const;
    Zcad::ErrorStatus getConstantWidth(double&)                 const;
    ZcGeVector3d      normal          ()                        const;

    virtual Zcad::ErrorStatus addVertexAt     (unsigned int index,
                                       const ZcGePoint2d& pt,
                                       double bulge = 0.,
                                       double startWidth = -1.,
                                       double endWidth = -1);

    virtual Zcad::ErrorStatus removeVertexAt  (unsigned int index);

    unsigned int      numVerts        ()                        const;

    Zcad::ErrorStatus getPointAt        (unsigned int index,
                                       ZcGePoint2d& pt)         const;
    Zcad::ErrorStatus getBulgeAt      (unsigned int index,
                                       double&      bulge)      const;
    Zcad::ErrorStatus getWidthsAt     (unsigned int index,
                                       double&      startWidth,
                                       double&      endWidth)   const;

   virtual Zcad::ErrorStatus setPointAt(unsigned int index,
                                       const ZcGePoint2d& pt);
   virtual Zcad::ErrorStatus setBulgeAt(unsigned int index,
                                       double       bulge);
   virtual Zcad::ErrorStatus setVertexIdentifierAt (unsigned int index, ZSoft::Int32 suggestedValue);
   virtual Zcad::ErrorStatus setWidthsAt     (unsigned int index,
                                       double       startWidth,
                                       double       endWidth);

    Zcad::ErrorStatus minimizeMemory  ();
    Zcad::ErrorStatus maximizeMemory  ();

    virtual void              reset           (ZSoft::Boolean reuse,
                                       unsigned int numVerts);

    ZSoft::Boolean     hasBulges       ()        const;
    ZSoft::Boolean     hasWidth        ()        const;
	
	DBCURVE_METHODS

    virtual Zcad::ErrorStatus getOsnapPoints(ZcDb::OsnapMode osnapMode,
                                             ZSoft::GsMarker gsSelectionMark,
                                             const ZcGePoint3d&  pickPoint,
                                             const ZcGePoint3d&  lastPoint,
                                             const ZcGeMatrix3d& viewXform,
                                             ZcGePoint3dArray&      snapPoints,
                                             ZcDbIntArray&   geomIds)
                                             const;

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
                                            ZcDbIntArray& osnapMasks,
                                            ZcDbIntArray& geomIds)
                                            const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,  
                                               const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                            ZcDb::Intersect intType,
                                            ZcGePoint3dArray& points,
                                            ZSoft::GsMarker thisGsMarker  = 0,
                                            ZSoft::GsMarker otherGsMarker = 0)
                                            const;

    virtual Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect intType,
                                             const ZcGePlane& projPlane,
                                             ZcGePoint3dArray& points,
                                             ZSoft::GsMarker thisGsMarker  = 0,
                                             ZSoft::GsMarker otherGsMarker = 0)
                                             const;

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray&  stretchPoints)
                                               const;

    virtual Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& 
                                                 indices,
                                                 const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d& xform,
                                                 ZcDbEntity*& ent) const;

    virtual void              getEcs(ZcGeMatrix3d& retVal) const;

    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
    virtual Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                 ZcDb::SubentType     type, 
                                 ZSoft::GsMarker      gsMark,
                                 const ZcGePoint3d&   pickPoint,
                                 const ZcGeMatrix3d&  viewXform,
                                 int&                 numIds, 
                                 ZcDbFullSubentPath*& subentIds,
                                 int                  numInserts,
                                 ZcDbObjectId*        entAndInsertStack)
                                                                     const;

    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;

    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* mode);
    virtual void              viewportDraw(ZcGiViewportDraw* mode);

    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* filer,
                                               ZcRxClass*    classobj);

    virtual bool              castShadows() const;
    virtual bool              receiveShadows() const;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual void              saveAs(ZcGiWorldDraw* mode,
                                     ZcDb::SaveType st);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;
};

inline ZSoft::Boolean ZcDbPolyline::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbPolyline::getStartParam(double& startParam) const
{
    startParam = 0.;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbPolyline::getSpline(ZcDbSpline*& spline) const
{
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif 
