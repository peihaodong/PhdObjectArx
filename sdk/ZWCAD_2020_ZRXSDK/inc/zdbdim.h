

#ifndef ZD_DBDIM_H
#define ZD_DBDIM_H

#include "zdbmain.h"
#include "zdbmtext.h"
#include "zacgi.h"

#pragma pack(push, 8)

namespace ZcDmUtil
{

    int dimfit  (int dimatfit, int dimtmove);
    int dimunit (int dimlunit, int dimfrac );

    int dimatfit(int dimfit);
    int dimtmove(int dimfit);
    int dimlunit(int dimunit);
    int dimfrac (int dimunit);

    const ZTCHAR * globalArrowName(const ZTCHAR * pName);
    const ZTCHAR * globalArrowName(ZcDbObjectId blockId);

    const ZTCHAR * arrowName(const ZTCHAR * pName);
    const ZTCHAR * arrowName(ZcDbObjectId blockId);

    bool isBuiltInArrow(const ZTCHAR * pName);

    bool isZeroLengthArrow(const ZTCHAR * pName);

    Zcad::ErrorStatus findArrowId(const ZTCHAR * pName,
                                        ZcDbObjectId& blockId, 
                                        ZcDbDatabase* pDb = 0);

    Zcad::ErrorStatus getArrowId(const ZTCHAR * pName,
                                        ZcDbObjectId& blockId, 
                                        ZcDbDatabase* pDb = 0);
};

class ZSOFT_NO_VTABLE ZcDbDimension: public ZcDbEntity
{
protected:
    ZcDbDimension();
public:
    ~ZcDbDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbDimension);

    ZcGePoint3d         textPosition() const;
    Zcad::ErrorStatus   setTextPosition(const ZcGePoint3d&);

    ZSoft::Boolean      isUsingDefaultTextPosition() const;
    Zcad::ErrorStatus   useSetTextPosition();
    Zcad::ErrorStatus   useDefaultTextPosition();

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual ZSoft::Boolean    isPlanar() const { return true; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    double              elevation() const;
    Zcad::ErrorStatus   setElevation(double);

    ZTCHAR *             dimensionText() const;
    Zcad::ErrorStatus   setDimensionText(const ZTCHAR *);

    double              textRotation() const;
    Zcad::ErrorStatus   setTextRotation(double);

    ZcDbObjectId        dimensionStyle() const;
    Zcad::ErrorStatus   setDimensionStyle(ZcDbObjectId);

    ZcDbMText::AttachmentPoint textAttachment() const;
    Zcad::ErrorStatus   setTextAttachment(ZcDbMText::AttachmentPoint eAtt);

    ZcDb::LineSpacingStyle textLineSpacingStyle() const;
    Zcad::ErrorStatus   setTextLineSpacingStyle(ZcDb::LineSpacingStyle eStyle);

    double              textLineSpacingFactor() const;
    Zcad::ErrorStatus   setTextLineSpacingFactor(double dFactor);

    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);

    virtual void        erased(ZcDbObject* dbObj, ZSoft::Boolean bErasing);

    virtual void        objectClosed(const ZcDbObjectId dbObj);
	virtual void        dragStatus(const ZcDb::DragStat status);

    double              horizontalRotation() const;
    Zcad::ErrorStatus   setHorizontalRotation(double newVal);

    ZcDbObjectId        dimBlockId() const;
    Zcad::ErrorStatus   setDimBlockId(const ZcDbObjectId&);
    ZcGePoint3d         dimBlockPosition() const;
    Zcad::ErrorStatus   setDimBlockPosition(const ZcGePoint3d&);
    Zcad::ErrorStatus   recomputeDimBlock(bool forceUpdate = true);
    Zcad::ErrorStatus   generateLayout();
    Zcad::ErrorStatus   measurement(double &val);
    Zcad::ErrorStatus   formatMeasurement(ZTCHAR *MTextContentBuffer,
										  const size_t contentBufferLen,
                                          double measurement,
                                          ZTCHAR *dimensionText);
	Zcad::ErrorStatus	formatMeasurement(ZTCHAR *MTextContentBuffer,
                                          double measurement,
                                          ZTCHAR *dimensionText);//Deprecated: will be removed in future.
    bool                isDynamicDimension() const;
    Zcad::ErrorStatus   setDynamicDimension(bool newVal);
    Zcad::ErrorStatus getOsnapPointsAtSubentPath(ZcDb::OsnapMode osnapMode,
                                     const ZcDbFullSubentPath& subentId,
                                     const ZcGePoint3d&  pickPoint,
                                     const ZcGePoint3d&  lastPoint,
                                     const ZcGeMatrix3d& viewXform,
                                     ZcGePoint3dArray&   snapPoints,
                                     ZcDbIntArray&   geomIds) const;


    ZcDbObjectId dimLineLinetype() const;
    Zcad::ErrorStatus setDimLineLinetype(const ZcDbObjectId linetype);
    ZcDbObjectId dimExt1Linetype() const;
    Zcad::ErrorStatus setDimExt1Linetype(const ZcDbObjectId linetype);
    ZcDbObjectId dimExt2Linetype() const;
    Zcad::ErrorStatus setDimExt2Linetype(const ZcDbObjectId linetype);

    Zcad::ErrorStatus   removeTextField();
    Zcad::ErrorStatus   fieldToMText(ZcDbMText* pDimMText);
    Zcad::ErrorStatus   fieldFromMText(ZcDbMText* pDimMText);

    #undef ZDBDIMVAR_H                   
    #include "zdbdimvar.h"

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit (int );
    Zcad::ErrorStatus setDimunit(int );
    bool                isHorizontalRefTextRotation() const;
    Zcad::ErrorStatus   setHorizontalRefTextRotation(bool newVal);
    bool getArrowFirstIsFlipped() const;
    bool getArrowSecondIsFlipped() const;
    Zcad::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
    Zcad::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

    ZcGeMatrix3d blockTransform() const;
	enum DimInspect {
		kShapeRemove  = 0,     
		kShapeRound   = 1,     
		kShapeAngular = 2,     
		kShapeNone    = 4,     
		kShapeLabel   = 0x10,  
		kShapeRate    = 0x20,  
	};

	bool 				inspection() const;
	Zcad::ErrorStatus 	setInspection(bool val);

	int 				inspectionFrame() const;
	Zcad::ErrorStatus 	setInspectionFrame(int frame);

	const ZTCHAR* 		inspectionLabel() const;
	Zcad::ErrorStatus 	setInspectionLabel(const ZTCHAR* label);

	const ZTCHAR* 		inspectionRate() const;
	Zcad::ErrorStatus 	setInspectionRate(const ZTCHAR* label);
	
};

class ZcDbOrdinateDimension: public ZcDbDimension
{
public:
    ZcDbOrdinateDimension();
    ZcDbOrdinateDimension(
        ZSoft::Boolean     useXAxis,
        const ZcGePoint3d& definingPoint,
        const ZcGePoint3d& leaderEndPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle  = ZcDbObjectId::kNull);
    ~ZcDbOrdinateDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbOrdinateDimension);

    ZSoft::Boolean      isUsingXAxis() const;
    ZSoft::Boolean      isUsingYAxis() const;
    Zcad::ErrorStatus   useXAxis();
    Zcad::ErrorStatus   useYAxis();

    ZcGePoint3d         origin() const;
    Zcad::ErrorStatus   setOrigin(const ZcGePoint3d&);

    ZcGePoint3d         definingPoint() const;
    Zcad::ErrorStatus   setDefiningPoint(const ZcGePoint3d&);

    ZcGePoint3d         leaderEndPoint() const;
    Zcad::ErrorStatus   setLeaderEndPoint(const ZcGePoint3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbAlignedDimension: public ZcDbDimension
{
public:
    ZcDbAlignedDimension();
    ZcDbAlignedDimension(
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& dimLinePoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbAlignedDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbAlignedDimension);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         dimLinePoint() const;
    Zcad::ErrorStatus   setDimLinePoint(const ZcGePoint3d&);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	bool 				jogSymbolOn() const;
	Zcad::ErrorStatus 	setJogSymbolOn(bool value);

	ZcGePoint3d 		jogSymbolPosition() const;
	Zcad::ErrorStatus 	setJogSymbolPosition(const ZcGePoint3d& pt);
};

class ZcDbRotatedDimension: public ZcDbDimension
{
public:
    ZcDbRotatedDimension();
    ZcDbRotatedDimension(
        double             rotation,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& dimLinePoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbRotatedDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbRotatedDimension);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         dimLinePoint() const;
    Zcad::ErrorStatus   setDimLinePoint(const ZcGePoint3d&);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              rotation() const;
    Zcad::ErrorStatus   setRotation(double);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	bool 				jogSymbolOn() const;
	Zcad::ErrorStatus 	setJogSymbolOn(bool value);

	ZcGePoint3d 		jogSymbolPosition() const;
	Zcad::ErrorStatus 	setJogSymbolPosition(const ZcGePoint3d& pt);
};

class ZcDb3PointAngularDimension: public ZcDbDimension
{
public:
    ZcDb3PointAngularDimension();
    ZcDb3PointAngularDimension(
        const ZcGePoint3d& centerPoint,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDb3PointAngularDimension();
    ZCDB_DECLARE_MEMBERS(ZcDb3PointAngularDimension);

    ZcGePoint3d         arcPoint() const;
    Zcad::ErrorStatus   setArcPoint(const ZcGePoint3d&);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         centerPoint() const;
    Zcad::ErrorStatus   setCenterPoint(const ZcGePoint3d&);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	bool 				extArcOn() const;
	Zcad::ErrorStatus 	setExtArcOn(bool value);
};

class ZcDb2LineAngularDimension: public ZcDbDimension
{
public:
    ZcDb2LineAngularDimension();
    ZcDb2LineAngularDimension(
        const ZcGePoint3d& xLine1Start,
        const ZcGePoint3d& xLine1End,
        const ZcGePoint3d& xLine2Start,
        const ZcGePoint3d& xLine2End,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDb2LineAngularDimension();
    ZCDB_DECLARE_MEMBERS(ZcDb2LineAngularDimension);

    ZcGePoint3d         arcPoint() const;
    Zcad::ErrorStatus   setArcPoint(const ZcGePoint3d&);

    ZcGePoint3d         xLine1Start() const;
    Zcad::ErrorStatus   setXLine1Start(const ZcGePoint3d&);

    ZcGePoint3d         xLine1End() const;
    Zcad::ErrorStatus   setXLine1End(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Start() const;
    Zcad::ErrorStatus   setXLine2Start(const ZcGePoint3d&);

    ZcGePoint3d         xLine2End() const;
    Zcad::ErrorStatus   setXLine2End(const ZcGePoint3d&);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	bool 				extArcOn() const;
	Zcad::ErrorStatus 	setExtArcOn(bool value);
};

class ZcDbRadialDimension: public ZcDbDimension
{
public:
    ZcDbRadialDimension();
    ZcDbRadialDimension(
        const ZcGePoint3d& center,
        const ZcGePoint3d& chordPoint,
        double             leaderLength,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbRadialDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbRadialDimension);

    double              leaderLength() const;
    Zcad::ErrorStatus   setLeaderLength(double);

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&);

    ZcGePoint3d         chordPoint() const;
    Zcad::ErrorStatus   setChordPoint(const ZcGePoint3d&);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    double extArcStartAngle() const;
    Zcad::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    Zcad::ErrorStatus setExtArcEndAngle(double newAngle);
};

class ZcDbDiametricDimension: public ZcDbDimension
{
public:
    ZcDbDiametricDimension();
    ZcDbDiametricDimension(
        const ZcGePoint3d& chordPoint,
        const ZcGePoint3d& farChordPoint,
        double             leaderLength,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbDiametricDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbDiametricDimension);

    double              leaderLength() const;
    Zcad::ErrorStatus   setLeaderLength(double);

    ZcGePoint3d         chordPoint() const;
    Zcad::ErrorStatus   setChordPoint(const ZcGePoint3d&);

    ZcGePoint3d         farChordPoint() const;
    Zcad::ErrorStatus   setFarChordPoint(const ZcGePoint3d&);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
	double 				extArcStartAngle() const;
	Zcad::ErrorStatus 	setExtArcStartAngle(double newAngle);

	double 				extArcEndAngle() const;
	Zcad::ErrorStatus 	setExtArcEndAngle(double newAngle);
};

class ZcDbArcDimension: public ZcDbDimension
{
public:
    ZcDbArcDimension();

    ZcDbArcDimension(
        const ZcGePoint3d& centerPoint,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR * dimText = NULL,
        ZcDbObjectId dimStyle = ZcDbObjectId::kNull);

	~ZcDbArcDimension();
	ZCDB_DECLARE_MEMBERS(ZcDbArcDimension);

	ZcGePoint3d         arcPoint() const;
	Zcad::ErrorStatus	setArcPoint(const ZcGePoint3d & arcPt);

	ZcGePoint3d         xLine1Point() const;
	Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d & xLine1Pt);

	ZcGePoint3d         xLine2Point() const;
	Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d & xLine2Pt);

	ZcGePoint3d         centerPoint() const;
	Zcad::ErrorStatus   setCenterPoint(const ZcGePoint3d & ctrPt);

	bool                isPartial() const;
	Zcad::ErrorStatus   setIsPartial(const bool & partial);

	double              arcStartParam() const;
	Zcad::ErrorStatus   setArcStartParam(const double & arcParam);

	double              arcEndParam() const;
	Zcad::ErrorStatus   setArcEndParam(const double & arcParam);

	bool                hasLeader() const;
	Zcad::ErrorStatus   setHasLeader(const bool & leaderVal);

	ZcGePoint3d         leader1Point() const;       
	Zcad::ErrorStatus   setLeader1Point(const ZcGePoint3d & ldr1Pt);

	ZcGePoint3d         leader2Point() const;   
	Zcad::ErrorStatus   setLeader2Point(const ZcGePoint3d & ldr2Pt);

	int					arcSymbolType() const;
	Zcad::ErrorStatus	setArcSymbolType(const int symbol);
	virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbRadialDimensionLarge: public ZcDbDimension
{
public:

	ZcDbRadialDimensionLarge();

    ZcDbRadialDimensionLarge(
        const ZcGePoint3d& center,
        const ZcGePoint3d& chordPoint,
        const ZcGePoint3d& overrideCenter,
        const ZcGePoint3d& jogPoint,
        double             jogAngle,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);

	~ZcDbRadialDimensionLarge();
	ZCDB_DECLARE_MEMBERS(ZcDbRadialDimensionLarge);

	ZcGePoint3d         center() const;
	Zcad::ErrorStatus	setCenter(const ZcGePoint3d & centerPoint);

	ZcGePoint3d         chordPoint() const;
	Zcad::ErrorStatus	setChordPoint(const ZcGePoint3d & chordPoint);

	ZcGePoint3d         overrideCenter() const;
	Zcad::ErrorStatus	setOverrideCenter(const ZcGePoint3d & overrideCenterPoint);

	ZcGePoint3d         jogPoint() const;
	Zcad::ErrorStatus	setJogPoint(const ZcGePoint3d & jogPoint);

	double              jogAngle() const;
	Zcad::ErrorStatus	setJogAngle(double jogAngle);
    Zcad::ErrorStatus   setOverrideCenterPP(const ZcGePoint3d & overrideCenterPointPP);
    Zcad::ErrorStatus   setJogPointPP(const ZcGePoint3d & jogPointPP);
    Zcad::ErrorStatus   setTextPositionPP(const ZcGePoint3d & textPointPP);
    virtual Zcad::ErrorStatus   getClassID(CLSID * pClsid) const;
	double				extArcStartAngle() const;
    Zcad::ErrorStatus setExtArcStartAngle(double newAngle);

	double				extArcEndAngle() const;
    Zcad::ErrorStatus setExtArcEndAngle(double newAngle);
};

#pragma pack(pop)

#endif
