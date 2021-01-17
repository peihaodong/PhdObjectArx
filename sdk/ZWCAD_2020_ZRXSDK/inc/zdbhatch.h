

#ifndef ZD_DBHATCH_H
#define ZD_DBHATCH_H 1

#include "zacdb.h"
#include "zdbmain.h"
#include "zgelnsg2d.h"
#include "zgelnsg3d.h"
#include "zgearc2d.h"
#include "zgearc3d.h"
#include "zgept2dar.h"
#include "zgevptar.h"
#include "zgeintarr.h"

#pragma pack(push, 8)

#define HATCH_PATTERN_NAME_LENGTH   35

#define GRADIENT_PATTERN_NAME_LENGTH    32

#define GRADIENT_COLOR_NAME_LENGTH    256
class ZcDbRegion;

class ZcDbHatch: public ZcDbEntity
{
public:
    enum HatchObjectType {
        kHatchObject      = 0,
        kGradientObject   = 1
    };

    enum HatchLoopType {
        kDefault          = 0,
        kExternal         = 1,
        kPolyline         = 2,
        kDerived          = 4,
        kTextbox          = 8,
        kOutermost        = 0x10,
        kNotClosed        = 0x20,
        kSelfIntersecting = 0x40,
        kTextIsland       = 0x80,

		kDuplicate		  = 0x100,
		kIsAnnotative        = 0x200,
		kDoesNotSupportScale = 0x400,
		kForceAnnoAllVisible = 0x800,
		kOrientToPaper       = 0x1000,
		kIsAnnotativeBlock   = 0x2000
    };

    enum HatchEdgeType {
        kLine             = 1,
        kCirArc           = 2,
        kEllArc           = 3,
        kSpline           = 4 
    };

    enum HatchPatternType {
        kUserDefined      = 0,
        kPreDefined       = 1,
        kCustomDefined    = 2 
    };

    enum HatchStyle {
        kNormal           = 0,
        kOuter            = 1,
        kIgnore           = 2 
    };

    enum GradientPatternType {
        kPreDefinedGradient     = 0,
        kUserDefinedGradient    = 1
    };

    ZcDbHatch ();

    virtual ~ZcDbHatch();

    ZCDB_DECLARE_MEMBERS(ZcDbHatch);

    double elevation() const;
    Zcad::ErrorStatus setElevation(double elevation);

    ZcGeVector3d normal() const;
    Zcad::ErrorStatus setNormal(const ZcGeVector3d& normal);

    virtual ZSoft::Boolean isPlanar() const { return true; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    ZcCmColor backgroundColor() const;
    Zcad::ErrorStatus setBackgroundColor(const ZcCmColor& color);

    int numLoops() const;

    ZSoft::Int32 loopTypeAt(int loopIndex) const;

    Zcad::ErrorStatus getLoopAt(int loopIndex,
                                ZSoft::Int32& loopType,
                                ZcGeVoidPointerArray& edgePtrs,
                                ZcGeIntArray&  edgeTypes) const;

    Zcad::ErrorStatus getLoopAt(int loopIndex,
                                ZSoft::Int32& loopType,
                                ZcGePoint2dArray& vertices,
                                ZcGeDoubleArray& bulges) const;

    Zcad::ErrorStatus appendLoop(ZSoft::Int32 loopType,
                                 const ZcGeVoidPointerArray& edgePtrs,
                                 const ZcGeIntArray&  edgeTypes);

    Zcad::ErrorStatus appendLoop(ZSoft::Int32 loopType,
                                 const ZcGePoint2dArray& vertices,
                                 const ZcGeDoubleArray& bulges);

    Zcad::ErrorStatus insertLoopAt(int loopIndex,
                                   ZSoft::Int32 loopType,
                                   const ZcGeVoidPointerArray& edgePtrs,
                                   const ZcGeIntArray&  edgeTypes);

    Zcad::ErrorStatus insertLoopAt(int loopIndex,
                                   ZSoft::Int32 loopType,
                                   const ZcGePoint2dArray& vertices,
                                   const ZcGeDoubleArray& bulges);

    Zcad::ErrorStatus removeLoopAt(int loopIndex);

    bool associative() const;
    Zcad::ErrorStatus setAssociative(bool isAssociative);

    Zcad::ErrorStatus appendLoop(ZSoft::Int32 loopType,
                                 const ZcDbObjectIdArray& dbObjIds);

    Zcad::ErrorStatus insertLoopAt(int loopIndex,
                                   ZSoft::Int32 loopType,
                                   const ZcDbObjectIdArray& dbObjIds);

    Zcad::ErrorStatus getAssocObjIdsAt(int loopIndex,
                                       ZcDbObjectIdArray& dbObjIds) const;

    Zcad::ErrorStatus getAssocObjIds(ZcDbObjectIdArray& dbObjIds) const;

    Zcad::ErrorStatus removeAssocObjIds();

    ZcDbHatch::HatchObjectType hatchObjectType() const;
    Zcad::ErrorStatus setHatchObjectType(ZcDbHatch::HatchObjectType type);

    virtual ZSoft::Boolean isGradient() const;
    virtual ZSoft::Boolean isHatch() const;

    ZcDbHatch::GradientPatternType gradientType() const;

    const ZTCHAR* gradientName() const;

    Zcad::ErrorStatus setGradient(ZcDbHatch::GradientPatternType gradType,
        const ZTCHAR* gradName);

    double gradientAngle() const;
    Zcad::ErrorStatus setGradientAngle(double angle);

    Zcad::ErrorStatus getGradientColors( unsigned int& count, 
                                            ZcCmColor*& colors,
                                            float*& values );
    
    Zcad::ErrorStatus setGradientColors( unsigned int count, 
                                            ZcCmColor* colors,
                                            float* values );

	ZSoft::Boolean getGradientOneColorMode() const;
	Zcad::ErrorStatus setGradientOneColorMode( ZSoft::Boolean oneColorMode );

	float getShadeTintValue() const;
	Zcad::ErrorStatus setShadeTintValue( float value );
    Zcad::ErrorStatus setShadeTintValueAndColor2( float value );

    float gradientShift() const;
    Zcad::ErrorStatus setGradientShift( float shiftValue );

    Zcad::ErrorStatus evaluateGradientColorAt( float value,
                                                ZcCmColor& color );

    ZcDbHatch::HatchPatternType patternType() const;

    const ZTCHAR* patternName() const;

    Zcad::ErrorStatus  setPattern(ZcDbHatch::HatchPatternType patType,
                                  const ZTCHAR* patName);

    double patternAngle() const;
    Zcad::ErrorStatus setPatternAngle(double angle);

    double patternSpace() const;
    Zcad::ErrorStatus setPatternSpace(double space);

    double patternScale() const;
    Zcad::ErrorStatus setPatternScale(double scale);

    bool patternDouble() const;
    Zcad::ErrorStatus setPatternDouble(bool isDouble);

    int numPatternDefinitions() const;
    Zcad::ErrorStatus  getPatternDefinitionAt(int index, 
                                              double& angle,
                                              double& baseX,
                                              double& baseY,
                                              double& offsetX,
                                              double& offsetY,
                                              ZcGeDoubleArray& dashes)
                                              const;

    ZcDbHatch::HatchStyle hatchStyle() const;
    Zcad::ErrorStatus setHatchStyle(ZcDbHatch::HatchStyle hstyle);

    Zcad::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);
    bool               lineGenerationEnabled() const;
    bool               setLineGenerationEnabled(bool bEnable);

    int numHatchLines() const;

    bool isSolidFill() const;
    
    Zcad::ErrorStatus  getHatchLineDataAt(int index, 
                                          ZcGePoint2d& startPt,
                                          ZcGePoint2d& endPt) const;

    Zcad::ErrorStatus  getHatchLinesData(ZcGePoint2dArray& startPts,
                                         ZcGePoint2dArray& endPts) const;

    virtual void modifiedGraphics(const ZcDbEntity* pObj);

    virtual Zcad::ErrorStatus subSwapIdWith(ZcDbObjectId otherId,
                 ZSoft::Boolean swapXdata = false,
				 ZSoft::Boolean swapExtDict = false);

    virtual Zcad::ErrorStatus  swapReferences(const ZcDbIdMapping& idMap);

    virtual Zcad::ErrorStatus  getClassID(CLSID* pClsid) const;

    Zcad::ErrorStatus getArea(double& a) const;

    Zcad::ErrorStatus setOriginPoint(const ZcGePoint2d& pt);
    ZcGePoint2d originPoint() const;

    ZcDbRegion* getRegionArea() const;

    void removeHatchLines();

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

}; 

#pragma pack(pop)

#endif 
