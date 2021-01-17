
#pragma once

#include "zAdAChar.h"
#include "zdbhatch.h"
#include "zAcString.h"

class ZcDbSectionSettings;

class ZcDbSection : public ZcDbEntity
{
public:
    enum State
    {
        kPlane              = (0x1 << 0),
        kBoundary           = (0x1 << 1),
        kVolume             = (0x1 << 2),
    };

    enum SubItem
    {
        kNone               = 0,
        kSectionLine        = (0x1 << 0),
        kSectionLineTop     = (0x1 << 1),
        kSectionLineBottom  = (0x1 << 2),
        kBackLine           = (0x1 << 3),
        kBackLineTop        = (0x1 << 4),
        kBackLineBottom     = (0x1 << 5),
        kVerticalLineTop    = (0x1 << 6),
        kVerticalLineBottom = (0x1 << 7),
    };

    enum Height
    {
        kHeightAboveSectionLine = 0x1,
        kHeightBelowSectionLine = 0x2,
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbSection);

    ZCDB_PORT ZcDbSection(void);
    ZCDB_PORT ZcDbSection(const ZcGePoint3dArray& pts,
        const ZcGeVector3d& verticalDir);
    ZCDB_PORT ZcDbSection(const ZcGePoint3dArray& pts,
        const ZcGeVector3d& verticalDir, const ZcGeVector3d& vecViewingDir);
    ZCDB_PORT ~ZcDbSection(void);

    ZCDB_PORT ZcDbSection::State state      (void) const;
    ZCDB_PORT Zcad::ErrorStatus setState    (ZcDbSection::State nState);

    ZCDB_PORT const ZTCHAR* getName          (void) const;
    ZCDB_PORT Zcad::ErrorStatus getName     (ZcString& sName) const;
    ZCDB_PORT Zcad::ErrorStatus getName     (ZTCHAR*& pszName) const;
    ZCDB_PORT Zcad::ErrorStatus setName     (const ZTCHAR* pszName);

    ZCDB_PORT ZcGeVector3d viewingDirection (void) const;
    ZCDB_PORT Zcad::ErrorStatus setViewingDirection(const ZcGeVector3d& dir);

    ZCDB_PORT ZcGeVector3d verticalDirection(void) const;
    ZCDB_PORT Zcad::ErrorStatus setVerticalDirection(const ZcGeVector3d& dir);

    ZCDB_PORT ZcGeVector3d normal           (void) const;
    ZCDB_PORT Zcad::ErrorStatus plane       (ZcGeVector3d& uAxis,
                                             ZcGeVector3d& vAxis) const;

    ZCDB_PORT int   indicatorTransparency   (void) const;
    ZCDB_PORT Zcad::ErrorStatus setIndicatorTransparency(int nTransparency);

    ZCDB_PORT ZcCmColor indicatorFillColor  (void) const;
    ZCDB_PORT Zcad::ErrorStatus setIndicatorFillColor(const ZcCmColor& color);

    ZCDB_PORT int numVertices               (void) const;
    ZCDB_PORT Zcad::ErrorStatus getVertex   (int nIndex,
                                             ZcGePoint3d& pt) const;
    ZCDB_PORT Zcad::ErrorStatus setVertex   (int nIndex,
                                             const ZcGePoint3d& pt);
    ZCDB_PORT Zcad::ErrorStatus addVertex   (int nInsertAt,
                                             const ZcGePoint3d& pt);
    ZCDB_PORT Zcad::ErrorStatus removeVertex(int nIndex);
    ZCDB_PORT Zcad::ErrorStatus getVertices (ZcGePoint3dArray& pts) const;
    ZCDB_PORT Zcad::ErrorStatus setVertices (const ZcGePoint3dArray& pts);

    ZCDB_PORT double height                 (ZcDbSection::Height nHeightType) const;
    ZCDB_PORT Zcad::ErrorStatus setHeight   (ZcDbSection::Height nHeightType,
                                             double fHeight);

    ZCDB_PORT bool  hitTest                 (const ZcGePoint3d& ptHit,
                                             int* pSegmentIndex,
                                             ZcGePoint3d* ptOnSegment,
                                             ZcDbSection::SubItem* pSubItem) const;

    ZCDB_PORT Zcad::ErrorStatus createJog   (const ZcGePoint3d& ptOnSection);

    ZCDB_PORT ZcDbObjectId getSettings      (void) const;
    ZCDB_PORT Zcad::ErrorStatus getSettings (ZcDbSectionSettings*& pSettings,
                                             ZcDb::OpenMode mode) const;

    ZCDB_PORT bool  isLiveSectionEnabled    (void) const;
    ZCDB_PORT Zcad::ErrorStatus enableLiveSection(bool bEnable);

    ZCDB_PORT Zcad::ErrorStatus generateSectionGeometry (ZcDbEntity *pEnt,
                                ZcArray<ZcDbEntity*>& intBoundaryEnts,
                                ZcArray<ZcDbEntity*>& intFillEnts,
                                ZcArray<ZcDbEntity*>& backgroundEnts,
                                ZcArray<ZcDbEntity*>& foregroundEnts,
                                ZcArray<ZcDbEntity*>& curveTangencyEnts) const;

public:

    ZCDB_PORT virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    ZCDB_PORT virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    ZCDB_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    ZCDB_PORT virtual ZSoft::Boolean worldDraw(ZcGiWorldDraw* wd);
    ZCDB_PORT virtual Zcad::ErrorStatus getGripPoints(ZcDbGripDataPtrArray& grips,
                                             const double curViewUnitSize,
                                             const int gripSize,
                                             const ZcGeVector3d& curViewDir,
                                             const int bitflags) const;
    ZCDB_PORT virtual Zcad::ErrorStatus moveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
                                             const ZcGeVector3d& offset,
                                             const int bitflags);
    ZCDB_PORT virtual Zcad::ErrorStatus subClose();
    ZCDB_PORT virtual Zcad::ErrorStatus getOsnapPoints(ZcDb::OsnapMode osnapMode,
                                             ZSoft::GsMarker gsSelectionMark,
                                             const ZcGePoint3d& pickPoint,
                                             const ZcGePoint3d& lastPoint,
                                             const ZcGeMatrix3d& viewXform,
                                             ZcGePoint3dArray& snapPoints,
                                             ZcDbIntArray & geomIds) const;
    ZCDB_PORT virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    ZCDB_PORT virtual void list             (void) const;
    ZCDB_PORT virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    ZCDB_PORT Zcad::ErrorStatus generateSectionGeometry (const ZcArray<ZcDbEntity*>& entset,
                                ZcArray<ZcDbEntity*>& intBoundaryEnts,
                                ZcArray<ZcDbEntity*>& intFillEnts,
                                ZcArray<ZcDbEntity*>& backgroundEnts,
                                ZcArray<ZcDbEntity*>& foregroundEnts,
                                ZcArray<ZcDbEntity*>& curveTangencyEnts) const;

};

class ZcDbSectionSettings : public ZcDbObject
{
public:
    enum SectionType
    {

        kLiveSection                = (0x1 << 0),
        k2dSection                  = (0x1 << 1),
        k3dSection                  = (0x1 << 2),
    };

    enum Geometry
    {

        kIntersectionBoundary       = (0x1 << 0),
        kIntersectionFill           = (0x1 << 1),
        kBackgroundGeometry         = (0x1 << 2),
        kForegroundGeometry         = (0x1 << 3),
        kCurveTangencyLines         = (0x1 << 4),
    };

    enum Generation
    {

        kSourceAllObjects           = (0x1 << 0),
        kSourceSelectedObjects      = (0x1 << 1),
        kDestinationNewBlock        = (0x1 << 4),
        kDestinationReplaceBlock    = (0x1 << 5),
        kDestinationFile            = (0x1 << 6),
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbSectionSettings);

    ZcDbSectionSettings();
    ~ZcDbSectionSettings();

    ZCDB_PORT virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    ZCDB_PORT Zcad::ErrorStatus reset(void);
    ZCDB_PORT Zcad::ErrorStatus reset(ZcDbSectionSettings::SectionType nSecType);

    ZCDB_PORT ZcDbSectionSettings::SectionType currentSectionType(void) const;
    ZCDB_PORT Zcad::ErrorStatus setCurrentSectionType(ZcDbSectionSettings::SectionType nSecType);

    ZCDB_PORT ZcDbSectionSettings::Generation generationOptions(ZcDbSectionSettings::SectionType nSecType) const;
    ZCDB_PORT Zcad::ErrorStatus setGenerationOptions(ZcDbSectionSettings::SectionType nSecType,
        ZcDbSectionSettings::Generation nOptions);

    ZCDB_PORT Zcad::ErrorStatus getSourceObjects(ZcDbSectionSettings::SectionType nSecType,
        ZcDbObjectIdArray& ids) const;
    ZCDB_PORT Zcad::ErrorStatus setSourceObjects(ZcDbSectionSettings::SectionType nSecType,
        const ZcDbObjectIdArray& ids);

    ZCDB_PORT ZcDbObjectId destinationBlock(ZcDbSectionSettings::SectionType nSecType) const;
    ZCDB_PORT Zcad::ErrorStatus setDestinationBlock(ZcDbSectionSettings::SectionType nSecType,
        const ZcDbObjectId& id);

    ZCDB_PORT const ZTCHAR* destinationFile(ZcDbSectionSettings::SectionType nSecType) const;
    ZCDB_PORT Zcad::ErrorStatus setDestinationFile(ZcDbSectionSettings::SectionType nSecType,
        const ZTCHAR* pszFileName);

    ZCDB_PORT bool  visibility              (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setVisibility(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             bool bVisible);
    ZCDB_PORT ZcCmColor color               (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setColor    (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZcCmColor& color);
    ZCDB_PORT const ZTCHAR* layer            (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setLayer    (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZTCHAR* pszLayer);
    ZCDB_PORT const ZTCHAR* linetype         (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setLinetype (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZTCHAR* pszLinetype);
    ZCDB_PORT double linetypeScale          (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setLinetypeScale(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             double fScale);
    ZCDB_PORT const ZTCHAR* plotStyleName    (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setPlotStyleName(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZTCHAR* pszPlotStyleName);
    ZCDB_PORT ZcDb::LineWeight lineWeight   (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setLineWeight(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             ZcDb::LineWeight nLineWeight);
    ZCDB_PORT int   faceTransparency        (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setFaceTransparency(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             int nTransparency);
    ZCDB_PORT int   edgeTransparency        (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setEdgeTransparency(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             int nTransparency);
    ZCDB_PORT bool  hatchVisibility         (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setHatchVisibility(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             bool bVisible);
    ZCDB_PORT Zcad::ErrorStatus getHatchPattern(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             ZcDbHatch::HatchPatternType& nPatternType,
                                             const ZTCHAR*& pszPatternName) const;
    ZCDB_PORT Zcad::ErrorStatus setHatchPattern(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             ZcDbHatch::HatchPatternType nPatternType,
                                             const ZTCHAR* pszPatternName);
    ZCDB_PORT double hatchAngle             (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setHatchAngle(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             double fAngle);
    ZCDB_PORT double hatchSpacing           (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setHatchSpacing(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             double fSpacing);
    ZCDB_PORT double hatchScale             (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setHatchScale(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             double fScale);
    ZCDB_PORT bool  hiddenLine              (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setHiddenLine(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             bool bHiddenLine);
    ZCDB_PORT bool  divisionLines           (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    ZCDB_PORT Zcad::ErrorStatus setDivisionLines(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             bool bShow);
};
