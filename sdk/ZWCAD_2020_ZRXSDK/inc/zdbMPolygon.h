

#pragma once

#include "zdbhatch.h"
#include <tchar.h>

class ZcDbCircle;
class ZcDb2dPolyline;
class ZcDbPolyline;
class ZcDbMPolygonCrossingArray;
class ZcDbMPolygonNode;

const double ZcDbMPolygonCrossingFuzz = 1E-6;

class ZcDbMPolygon : public ZcDbEntity {
public:

    enum loopDir {
        kExterior     = 0,            
        kInterior,                    
        kAnnotation                   
    };

    ZcDbMPolygon();
    virtual ~ZcDbMPolygon();

    ZCDB_DECLARE_MEMBERS(ZcDbMPolygon);

    virtual ZcDbHatch * hatch();

    virtual double elevation() const;
    virtual Zcad::ErrorStatus setElevation(double elevation);

    virtual ZcGeVector3d normal() const;
    virtual Zcad::ErrorStatus setNormal(const ZcGeVector3d& normal);

    virtual Zcad::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);

    virtual ZcDbHatch::HatchPatternType patternType() const;

    virtual const TCHAR* patternName() const;

    virtual Zcad::ErrorStatus  setPattern(ZcDbHatch::HatchPatternType patType,
                                  const TCHAR* patName);

    virtual double patternAngle() const;
    virtual Zcad::ErrorStatus setPatternAngle(double angle);

    virtual double patternSpace() const;
    virtual Zcad::ErrorStatus setPatternSpace(double space);

    virtual double patternScale() const;
    virtual Zcad::ErrorStatus setPatternScale(double scale);

    virtual bool patternDouble() const;
    virtual Zcad::ErrorStatus setPatternDouble(bool isDouble);

    virtual int numPatternDefinitions() const;
    virtual Zcad::ErrorStatus  getPatternDefinitionAt(int index, 
                                              double& angle,
                                              double& baseX,
                                              double& baseY,
                                              double& offsetX,
                                              double& offsetY,
                                              ZcGeDoubleArray& dashes)
                                              const;

    Zcad::ErrorStatus setGradientAngle(double angle);
    Zcad::ErrorStatus setGradientShift( float shiftValue );
	Zcad::ErrorStatus setGradientOneColorMode( ZSoft::Boolean oneColorMode );
    Zcad::ErrorStatus setGradientColors( unsigned int count, 
                                            ZcCmColor* colors,
                                            float* values );
    Zcad::ErrorStatus setGradient(ZcDbHatch::GradientPatternType gradType,
                                   const TCHAR* gradName);

    virtual ZcCmColor patternColor() const;
    virtual Zcad::ErrorStatus setPatternColor(const ZcCmColor& pc);

    virtual double getArea() const;
    virtual double getPerimeter() const;

    virtual bool isBalanced() const;

    virtual ZcGeVector2d getOffsetVector() const;

    virtual Zcad::ErrorStatus getMPolygonTree(ZcDbMPolygonNode*& loopNode) const;
    virtual void deleteMPolygonTree(ZcDbMPolygonNode* loopNode) const;

    virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDbCircle* pCircle,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDbPolyline* pPoly,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDb2dPolyline* pPoly,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

    virtual int numMPolygonLoops() const;
    virtual Zcad::ErrorStatus getMPolygonLoopAt(int loopIndex, ZcGePoint2dArray& vertices,
                                        ZcGeDoubleArray& bulges) const;

    virtual Zcad::ErrorStatus insertMPolygonLoopAt(int loopIndex, 
        const ZcGePoint2dArray& vertices, const ZcGeDoubleArray& bulges, 
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

    virtual Zcad::ErrorStatus appendMPolygonLoop(const ZcGePoint2dArray& vertices, 
        const ZcGeDoubleArray& bulges, bool excludeCrossing = true,
        double tol = ZcDbMPolygonCrossingFuzz);
    virtual Zcad::ErrorStatus removeMPolygonLoopAt(int loopIndex);

    virtual Zcad::ErrorStatus balanceTree();
    virtual Zcad::ErrorStatus balanceDisplay();

    virtual Zcad::ErrorStatus getLoopDirection(int lindex, ZcDbMPolygon::loopDir& dir) const;
    virtual Zcad::ErrorStatus setLoopDirection(int lindex, ZcDbMPolygon::loopDir dir);

    virtual Zcad::ErrorStatus getLoopAtGsMarker(int gsMark, int &loop) const;
    virtual void getChildLoops(int curLoop, ZcGeIntArray& selectedLoopIndexes) const;
    virtual int getParentLoop(int curLoop) const;
    virtual int getClosestLoopTo(const ZcGePoint3d& worldPt) const;

    virtual int isPointInsideMPolygon(const ZcGePoint3d& worldPt, ZcGeIntArray& loopsArray,
                                      double tol = ZcDbMPolygonCrossingFuzz) const;
    virtual bool isPointOnLoopBoundary(const ZcGePoint3d& worldPt, int loop, 
                                       double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual Zcad::ErrorStatus loopCrossesItself(bool& crosses, bool findAll,
                                        ZcDbMPolygonCrossingArray& crossingsArray,
                                        const ZcGePoint2dArray& vertexPts, 
                                        const ZcGeDoubleArray& vertexBulges, 
                                        double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual bool loopCrossesItself(const ZcGePoint2dArray& vertexPts, 
                           const ZcGeDoubleArray& vertexBulges, 
                           double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual Zcad::ErrorStatus loopCrossesMPolygon(bool& crosses, bool findAll,
                                          ZcDbMPolygonCrossingArray& crossingsArray,
                                          const ZcGePoint2dArray& testVertexPts, 
                                          const ZcGeDoubleArray& testVertexBulges, 
                                          double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual bool selfCrosses(const ZcGePoint2dArray& vertexPts, 
                     const ZcGeDoubleArray& vertexBulges,
                     double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual bool includesTouchingLoops(double tol = ZcDbMPolygonCrossingFuzz) const;

    virtual Zcad::ErrorStatus getClassID( CLSID* pClsid) const;

    virtual ZSoft::Boolean    worldDraw(ZcGiWorldDraw*  mode);
    virtual void              saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);

    virtual Zcad::ErrorStatus getSubentPathsAtGsMarker(
        ZcDb::SubentType      type,
        ZSoft::GsMarker/*int*/gsMark,
        const ZcGePoint3d&    pickPoint,
        const ZcGeMatrix3d&   viewXform,
        int&                  numPaths,
        ZcDbFullSubentPath*&  subentPaths,
        int                   numInserts = 0,
        ZcDbObjectId*         entAndInsertStack 
        = NULL) const;
    
    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath(
        const ZcDbFullSubentPath& subPath, 
        ZcArray<ZSoft::GsMarker>/*ZcDbIntArray*/&         gsMarkers) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;

    virtual Zcad::ErrorStatus   intersectWith(
        const ZcDbEntity*   ent,
        ZcDb::Intersect     intType,
        ZcGePoint3dArray&      points,
        ZSoft::GsMarker/*int*/                 thisGsMarker  = 0,
        ZSoft::GsMarker/*int*/                 otherGsMarker = 0)
        const;
    
    virtual Zcad::ErrorStatus   intersectWith(
        const ZcDbEntity*   ent,
        ZcDb::Intersect     intType,
        const ZcGePlane&    projPlane,
        ZcGePoint3dArray&      points,
        ZSoft::GsMarker/*int*/                 thisGsMarker  = 0,
        ZSoft::GsMarker/*int*/                 otherGsMarker = 0)
        const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
        ZcDb::OsnapMode       osnapMode,
        ZSoft::GsMarker/*int*/gsSelectionMark,
        const ZcGePoint3d&    pickPoint,
        const ZcGePoint3d&    lastPoint,
        const ZcGeMatrix3d&   viewXform,
        ZcGePoint3dArray&        snapPoints,
        ZcDbIntArray&     geomIds) const;

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&     gripPoints,
        ZcDbIntArray&  osnapModes,
        ZcDbIntArray&  geomIds) const;

    virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus getStretchPoints(ZcGePoint3dArray& stretchPoints) const;

    virtual Zcad::ErrorStatus moveStretchPointsAt( const ZcDbIntArray& indices,
        const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus	getGeomExtents(ZcDbExtents& extents) const;
    virtual void              list() const;
    
    virtual Zcad::ErrorStatus   explode( ZcDbVoidPtrArray& entitySet) const;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* );
    virtual Zcad::ErrorStatus decomposeForSave(ZcDb::ZcDbDwgVersion ver,
        ZcDbObject*& replaceObj, ZcDbObjectId& replaceId, 
        ZSoft::Boolean& exchangeXData);
    virtual Zcad::ErrorStatus createLoopsFromBoundaries (const ZcDbObjectIdArray &ids,
        ZcDbIntArray &rejectedObjs,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    virtual Zcad::ErrorStatus createLoops (const ZcArray<ZcGePoint2dArray,ZcArrayObjectCopyReallocator<ZcGePoint2dArray> > &vertices,
        const ZcArray<ZcGeDoubleArray,ZcArrayObjectCopyReallocator<ZcGeDoubleArray> > &bulges, ZcDbIntArray &rejectedObjs,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

private:
    friend class ZcDbImpMPolygon;
    void* pImp;
};

class ZcDbMpolygonLoops {
public:
    ZcDbMpolygonLoops(int lindex, int gindex = 0, int gcnt = 0);

    int mLoopIndex;                   
    bool mIsText;                     
    int mGripIndex;                   
    int mGripCount;                   
    ZcGePoint2dArray mVertexPoints;    
    ZcGeDoubleArray mVertexBulges;
};

inline
ZcDbMpolygonLoops::ZcDbMpolygonLoops(int lindex, int gindex, int gcnt)
{
    mLoopIndex = lindex;
    mGripIndex = gindex;
    mGripCount = gcnt;
}

class ZcDbMPolygonCrossing {
public:
    ZcDbMPolygonCrossing();
    ~ZcDbMPolygonCrossing();

    int getLoopIndex() const;         
    void setLoopIndex(int index);
    
    int getEdgeIndex() const;         
    void setEdgeIndex(int index);

    ZcGePoint2d getCrossingPoint() const; 
    void setCrossingPoint(const ZcGePoint2d& pt);

private:
    void* pImp;
};

class ZcDbMPolygonCrossingArray {
public:
    ~ZcDbMPolygonCrossingArray();

    ZcArray<ZcDbMPolygonCrossing *> mCrossingArray;
};

inline
ZcDbMPolygonCrossingArray::~ZcDbMPolygonCrossingArray()
{
    ZcDbMPolygonCrossing* pCrossing;
    int numCross = mCrossingArray.length();
    for (int i = numCross - 1; i >= 0; i--) {
        pCrossing = mCrossingArray[i];
        mCrossingArray.removeAt(i);
        if (pCrossing != NULL)
            delete pCrossing;
    }
}

class ZcDbMPolygonNode {
public:
    
    ZcDbMPolygonNode();

public:
    ZcDbMPolygonNode * mParent;
    ZcArray<ZcDbMPolygonNode*> mChildren;
    int mLoopIndex;                   
};

inline
ZcDbMPolygonNode::ZcDbMPolygonNode()
    : mLoopIndex(-1), mParent(NULL)
{
}



