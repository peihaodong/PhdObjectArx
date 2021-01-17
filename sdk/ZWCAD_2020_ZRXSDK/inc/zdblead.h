

#ifndef ZD_DBLEAD_H
#define ZD_DBLEAD_H 1

#include "zdbmain.h"
#include "zdbcurve.h"
#include "zgescl3d.h"
#include "zgepnt2d.h"
#include "zgeplane.h"

#pragma pack(push, 8)

class ZcDbLeader: public  ZcDbCurve
{
public:
    ZcDbLeader();
    ~ZcDbLeader();
    ZCDB_DECLARE_MEMBERS(ZcDbLeader);
    DBCURVE_METHODS

    virtual void              setPlane          (const ZcGePlane&);
    virtual ZcGeVector3d      normal            () const;

    virtual  int numVertices() const;
    virtual  ZSoft::Boolean appendVertex(const ZcGePoint3d&);
    virtual  void              removeLastVertex  ();
    virtual  ZcGePoint3d firstVertex() const;
    virtual  ZcGePoint3d lastVertex() const;
    virtual  ZcGePoint3d vertexAt(int) const;
    virtual  ZSoft::Boolean setVertexAt(int, const ZcGePoint3d&);

    virtual ZSoft::Boolean    hasArrowHead      () const;
    virtual void              enableArrowHead   ();
    virtual void              disableArrowHead  ();
    virtual ZSoft::Boolean    hasHookLine       () const;
    
    virtual void              setToSplineLeader ();
    virtual void              setToStraightLeader();
    virtual ZSoft::Boolean    isSplined         () const;
    
    virtual ZcDbHardPointerId dimensionStyle    () const;
    virtual void              setDimensionStyle (const ZcDbHardPointerId&);
    
    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);

    virtual Zcad::ErrorStatus attachAnnotation  (const ZcDbObjectId& annoId);
    virtual Zcad::ErrorStatus detachAnnotation  ();
    virtual ZcDbObjectId      annotationObjId   () const;
    virtual Zcad::ErrorStatus evaluateLeader    ();

    virtual ZcGeVector3d      annotationOffset   () const;
    virtual Zcad::ErrorStatus setAnnotationOffset(const ZcGeVector3d& offset);

    enum AnnoType { 
        kMText = 0,
        kFcf,
        kBlockRef,
        kNoAnno 
    };
    AnnoType annoType()   const;
    double   annoHeight() const;
    double   annoWidth()  const;

    virtual  Zcad::ErrorStatus intersectWith    (const ZcDbEntity*,
                                                 ZcDb::Intersect,
                                                 ZcGePoint3dArray&,
                                                 ZSoft::GsMarker thisGsMarker = 0,
                                                 ZSoft::GsMarker otherGsMarker = 0) const;
    virtual  Zcad::ErrorStatus intersectWith    (const ZcDbEntity*,
                                                 ZcDb::Intersect,
                                                 const ZcGePlane& projPlane,
                                                 ZcGePoint3dArray&,
                                                 ZSoft::GsMarker thisGsMarker = 0,
                                                 ZSoft::GsMarker otherGsMarker = 0) const;

    virtual Zcad::ErrorStatus explode           (ZcDbVoidPtrArray& entitySet) const;

    virtual double           dimasz   () const;
    virtual ZcCmColor        dimclrd  () const;
    virtual double           dimgap   () const;
    virtual ZcDb::LineWeight dimlwd   () const;
    virtual ZcDbObjectId     dimldrblk() const;
    virtual bool             dimsah   () const;
    virtual double           dimscale () const;
    virtual int              dimtad   () const;
    virtual ZcDbObjectId     dimtxsty () const;
    virtual double           dimtxt   () const;

    virtual Zcad::ErrorStatus setDimasz   (double         val);
    virtual Zcad::ErrorStatus setDimclrd  (ZcCmColor&     val);
    virtual Zcad::ErrorStatus setDimgap   (double         val);
    virtual Zcad::ErrorStatus setDimldrblk(ZcDbObjectId   val);
    virtual Zcad::ErrorStatus setDimldrblk(const ZTCHAR *  val);
    virtual Zcad::ErrorStatus setDimlwd   (ZcDb::LineWeight v);  
    virtual Zcad::ErrorStatus setDimsah   (bool           val);
    virtual Zcad::ErrorStatus setDimscale (double         val);
    virtual Zcad::ErrorStatus setDimtad   (int            val);
    virtual Zcad::ErrorStatus setDimtxsty (ZcDbObjectId   val);
    virtual Zcad::ErrorStatus setDimtxt   (double         val);

    virtual void              modified          (const ZcDbObject*);
    virtual void              erased            (const ZcDbObject*,
                                                 ZSoft::Boolean = ZSoft::kTrue);
    virtual void              goodbye           (const ZcDbObject*);
    virtual void              copied            (const ZcDbObject*,
                                                 const ZcDbObject*);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual void              setDimVars        ();
    virtual Zcad::ErrorStatus setColorIndex     (ZSoft::UInt16,
                                 ZSoft::Boolean doSubents = ZSoft::kTrue);

};

inline ZSoft::Boolean ZcDbLeader::isClosed() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbLeader::isPeriodic() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbLeader::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbLeader::getStartParam(double& param) const
{
    param = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbLeader::getOrthoProjectedCurve(const ZcGePlane&,
                                                ZcDbCurve*& ) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getProjectedCurve(const ZcGePlane&,
                                                const ZcGeVector3d& projDir,
                                                ZcDbCurve*& projCrv) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getOffsetCurves(double offsetDist,
                                        ZcDbVoidPtrArray& offsetCurves) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getSecondDeriv (double param,
                                        ZcGeVector3d& secDeriv) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getSecondDeriv (const ZcGePoint3d&,
                                ZcGeVector3d& secDeriv) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getSplitCurves (const ZcGeDoubleArray& params,
                                ZcDbVoidPtrArray& curveSegments) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getSplitCurves (const ZcGePoint3dArray& points,
                                ZcDbVoidPtrArray& curveSegments) const
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::extend(double)
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::extend(ZSoft::Boolean, const ZcGePoint3d&)
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbLeader::getArea(double&) const
{
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif

