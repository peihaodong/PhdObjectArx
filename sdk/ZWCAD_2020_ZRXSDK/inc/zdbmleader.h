
#ifndef __ZDBMLEADER_H__
#define __ZDBMLEADER_H__

#pragma once

#include "zdbgrip.h"
#include "zdbmleaderstyle.h"
#include "zdbents.h"

const int MAX_LEADER_NUMBER     = 5000;
const int MAX_LEADERLINE_NUMBER = 5000;

class ZcDbMLeaderObjectContextData;

class ZcDbMLeader : public ZcDbEntity
{
public:

    enum MoveType {
        kMoveAllPoints                  = 0,
        kMoveAllExceptArrowHeaderPoints = 1,
        kMoveContentAndDoglegPoints     = 2
    };
    enum gsMarkType {
        kNone               = 0,
        kArrowMark          = 1,
        kLeaderLineMark     = kArrowMark  + MAX_LEADERLINE_NUMBER,
        kDoglegMark         = kLeaderLineMark + MAX_LEADERLINE_NUMBER,
        kMTextMark          = kDoglegMark + MAX_LEADER_NUMBER,
        kMTextUnderLineMark = kMTextMark + 1,
        kToleranceMark      = kMTextUnderLineMark + 1,
        kBlockMark          = kToleranceMark + 1,
        kBlockAttribute     = kBlockMark + 1
    };
    enum PropertyOverrideType {
        kLeaderLineType         = 0,
        kLeaderLineColor        = 1,
        kLeaderLineTypeId       = 2,
        kLeaderLineWeight       = 3,
        kEnableLanding          = 4,
        kLandingGap             = 5,
        kEnableDogleg           = 6,
        kDoglegLength           = 7,
        kArrowSymbolId          = 8,
        kArrowSize              = 9,
        kContentType            = 10,
        kTextStyleId            = 11,
        kTextLeftAttachmentType     = 12,
        kTextAngleType          = 13,
        kTextAlignmentType      = 14,
        kTextColor              = 15,
        kTextHeight             = 16,
        kEnableFrameText        = 17,
        kDefaultMText           = 18,
        kBlockId                = 19,
        kBlockColor             = 20,
        kBlockScale             = 21,
        kBlockRotation          = 22,
        kBlockConnectionType    = 23,
        kScale                  = 24,
        kTextRightAttachmentType = 25,
        kTextSwitchAlignmentType = 26,
        kTextAttachmentDirection = 27,
        kTextTopAttachmentType = 28,
        kTextBottomAttachmentType = 29,
		kExtendLeaderToText      = 30,
        kSize = kExtendLeaderToText + 1
    };

    ZcDbMLeader();

    ~ZcDbMLeader();

    ZCDB_DECLARE_MEMBERS(ZcDbMLeader);

    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* filer);

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* filer);

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* mode);
    virtual void              viewportDraw(ZcGiViewportDraw* mode);
    virtual Zcad::ErrorStatus transformBy (const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus getStretchPoints           (ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus moveStretchPoints          (const ZcDbIntArray& indices,
                                                          const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus getGripPoints              (ZcDbGripDataPtrArray& grips,
                                                          const double curViewUnitSize,
                                                          const int gripSize,
                                                          const ZcGeVector3d& curViewDir,
                                                          const int bitflags) const;
    virtual Zcad::ErrorStatus moveGripPointsAt           (const ZcDbVoidPtrArray& gripAppData,
                                                          const ZcGeVector3d& offset,
                                                          const int bitflags);
    virtual Zcad::ErrorStatus getSubentPathsAtGsMarker   (ZcDb::SubentType     type,
                                                          ZSoft::GsMarker      gsMark,
                                                          const ZcGePoint3d&   pickPoint,
                                                          const ZcGeMatrix3d&  viewXform,
                                                          int&                 numPaths,
                                                          ZcDbFullSubentPath*& subentPaths,
                                                          int                  numInserts = 0,
                                                          ZcDbObjectId*        entAndInsertStack = NULL) const;
    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath   (const ZcDbFullSubentPath& subPath,
                                                          ZcArray<ZSoft::GsMarker>& gsMarkers) const;
    virtual Zcad::ErrorStatus getGripPointsAtSubentPath  (const ZcDbFullSubentPath& path,
                                                          ZcDbGripDataPtrArray& grips,
                                                          const double curViewUnitSize,
                                                          const int gripSize,
                                                          const ZcGeVector3d& curViewDir,
                                                          const int bitflags) const;
    virtual Zcad::ErrorStatus moveGripPointsAtSubentPaths(const ZcDbFullSubentPathArray& paths,
                                                          const ZcDbVoidPtrArray& gripAppData,
                                                          const ZcGeVector3d& offset,
                                                          const int bitflags);
    virtual Zcad::ErrorStatus deleteSubentPaths          (const ZcDbFullSubentPathArray& paths);
    virtual ZcDbEntity*       subentPtr                  (const ZcDbFullSubentPath& path) const;
    virtual Zcad::ErrorStatus getOsnapPoints             (ZcDb::OsnapMode     osnapMode,
                                                          ZSoft::GsMarker     gsSelectionMark,
                                                          const ZcGePoint3d&  pickPoint,
                                                          const ZcGePoint3d&  lastPoint,
                                                          const ZcGeMatrix3d& viewXform,
                                                          ZcGePoint3dArray&   snapPoints,
                                                          ZcDbIntArray&       geomIds) const;
    virtual Zcad::ErrorStatus intersectWith              (const ZcDbEntity* pEnt,
                                                          ZcDb::Intersect intType,
                                                          const ZcGePlane& projPlane,
                                                          ZcGePoint3dArray& points,
                                                          ZSoft::GsMarker thisGsMarker = 0,
                                                          ZSoft::GsMarker otherGsMarker = 0) const;
    virtual Zcad::ErrorStatus intersectWith              (const ZcDbEntity* pEnt,
                                                          ZcDb::Intersect intType,
                                                          ZcGePoint3dArray& points,
                                                          ZSoft::GsMarker thisGsMarker = 0,
                                                          ZSoft::GsMarker otherGsMarker = 0) const;
    virtual Zcad::ErrorStatus explode                     (ZcDbVoidPtrArray& entitySet) const;
    virtual void              list                        () const;
    virtual Zcad::ErrorStatus getGeomExtents              (ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus subClose                    ();

    virtual Zcad::ErrorStatus subErase                    (ZSoft::Boolean erasing);

    virtual void              objectClosed                (const ZcDbObjectId dbObjId);

    virtual void              modified                    (const ZcDbObject* dbObj);
    virtual Zcad::ErrorStatus getClassID                  (CLSID* pClsid) const;
    virtual Zcad::ErrorStatus getGripEntityUCS            (const void* pGripAppData,
                                                           ZcGeVector3d& normalVec,
                                                           ZcGePoint3d& origin,
                                                           ZcGeVector3d& xAxis) const;
    virtual void              gripStatus                  (const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus highlight                   (const ZcDbFullSubentPath& subId = kNullSubent,
                                                           const ZSoft::Boolean highlightAll = false) const;
    virtual Zcad::ErrorStatus unhighlight                 (const ZcDbFullSubentPath& subId = kNullSubent,
                                                           const ZSoft::Boolean highlightAll = false) const;
    virtual Zcad::ErrorStatus getTransformedCopy          (const ZcGeMatrix3d& xform,
                                                           ZcDbEntity*& pEnt) const;
    Zcad::ErrorStatus         setOverride                 (PropertyOverrideType propertyType,
                                                           bool isOverride = true);

    bool                      isOverride                  (PropertyOverrideType propertyType) const;

    Zcad::ErrorStatus         setScale                    (double scale);

    double                    scale                       () const;

    Zcad::ErrorStatus         getBlockAttributeValue(const ZcDbObjectId& attdefId,
                                                     ZcDbAttribute*& pAtt) const;

    Zcad::ErrorStatus         setBlockAttributeValue(const ZcDbObjectId& attdefId,
                                                     const ZcDbAttribute* pAtt);

    Zcad::ErrorStatus         getBlockAttributeValue      (const ZcDbObjectId& attdefId,
                                                           ZTCHAR*& value) const;

    Zcad::ErrorStatus         setBlockAttributeValue      (const ZcDbObjectId& attdefId,
                                                           const ZTCHAR* value);

    ZcGePlane         plane               () const;

    void              setPlane            (const ZcGePlane& plane);

    ZcGeVector3d      normal              () const;

    Zcad::ErrorStatus moveMLeader         (const ZcGeVector3d& vector,
                                           MoveType moveType,
                                           bool bAutoSwitchDogleg = true);

    Zcad::ErrorStatus getContentGeomExtents(ZcDbExtents& extents) const;

    int               numLeaders          () const;

    Zcad::ErrorStatus getLeaderIndexes(ZcArray<int>& leaderIndexes) const;

    Zcad::ErrorStatus addLeader           (int& leaderIndex);

    Zcad::ErrorStatus removeLeader        (int leaderIndex);

    int               numLeaderLines      () const;

    Zcad::ErrorStatus getLeaderLineIndexes(ZcArray<int>& leaderLineIndexes) const;

    Zcad::ErrorStatus addLeaderLine       (int leaderIndex, int& leaderLineIndex);

    Zcad::ErrorStatus addLeaderLine       (const ZcGePoint3d& point, int& leaderLineIndex);

    Zcad::ErrorStatus removeLeaderLine    (int leaderLineIndex);

    Zcad::ErrorStatus addFirstVertex      (int leaderLineIndex, const ZcGePoint3d& point);

    Zcad::ErrorStatus removeFirstVertex   (int leaderLineIndex);

    Zcad::ErrorStatus getFirstVertex      (int leaderLineIndex, ZcGePoint3d& point) const;

    Zcad::ErrorStatus setFirstVertex      (int leaderLineIndex, const ZcGePoint3d& point);

    Zcad::ErrorStatus addLastVertex       (int leaderLineIndex, const ZcGePoint3d& point);

    Zcad::ErrorStatus removeLastVertex    (int leaderLineIndex);

    Zcad::ErrorStatus getLastVertex       (int leaderLineIndex, ZcGePoint3d& point) const;

    Zcad::ErrorStatus setLastVertex       (int leaderLineIndex, const ZcGePoint3d& point);

    Zcad::ErrorStatus numVertices         (int leaderLineIndex, int& num) const;

    Zcad::ErrorStatus setVertex           (int leaderLineIndex, int index, const ZcGePoint3d& point);

    Zcad::ErrorStatus getVertex           (int leaderLineIndex, int index, ZcGePoint3d& point) const;

    Zcad::ErrorStatus getLeaderIndex      (int leaderLineIndex, int& leaderIndex) const;

    Zcad::ErrorStatus getLeaderLineIndexes(int leaderIndex, ZcArray<int>& leaderLineIndexes) const;

    Zcad::ErrorStatus setDoglegDirection           (int leaderIndex, const ZcGeVector3d& vector);

    Zcad::ErrorStatus getDoglegDirection           (int leaderIndex, ZcGeVector3d& vector) const;

    Zcad::ErrorStatus                     setLeaderLineType      (ZcDbMLeaderStyle::LeaderType leaderLineType);

    ZcDbMLeaderStyle::LeaderType          leaderLineType         () const;
    Zcad::ErrorStatus setLeaderLineType(int leaderLineIndex,
                                        ZcDbMLeaderStyle::LeaderType  leaderLineType);

    Zcad::ErrorStatus getLeaderLineType(int leaderLineIndex,
                                        ZcDbMLeaderStyle::LeaderType& leaderLineType) const;
    Zcad::ErrorStatus                     setLeaderLineColor     (const ZcCmColor& leaderLineColor);

    ZcCmColor                             leaderLineColor        () const;
    Zcad::ErrorStatus setLeaderLineColor(int leaderLineIndex,
                                         const ZcCmColor& leaderLineColor);

    Zcad::ErrorStatus getLeaderLineColor(int leaderLineIndex,
                                         ZcCmColor& leaderLineColor) const;
    Zcad::ErrorStatus                     setLeaderLineTypeId    (ZcDbObjectId leaderLineTypeId);

    ZcDbObjectId                          leaderLineTypeId       () const;
    Zcad::ErrorStatus setLeaderLineTypeId(int leaderLineIndex,
                                         ZcDbObjectId  leaderLineTypeId);

    Zcad::ErrorStatus getLeaderLineTypeId(int leaderLineIndex,
                                         ZcDbObjectId& leaderLineTypeId) const;
    Zcad::ErrorStatus                     setLeaderLineWeight    (ZcDb::LineWeight leaderLineWeight);

    ZcDb::LineWeight                      leaderLineWeight       () const;
    Zcad::ErrorStatus setLeaderLineWeight(int leaderLineIndex,
                                          ZcDb::LineWeight  leaderLineWeight);

    Zcad::ErrorStatus getLeaderLineWeight(int leaderLineIndex,
                                          ZcDb::LineWeight& leaderLineWeight) const;
    Zcad::ErrorStatus                     setLandingGap          (double landingGap);

    double                                landingGap             () const;

    Zcad::ErrorStatus                     setEnableLanding       (bool enableLanding);

    bool                                  enableLanding          () const;

    Zcad::ErrorStatus                     setEnableDogleg        (bool enableDogleg);

    bool                                  enableDogleg           () const;

    Zcad::ErrorStatus                     setDoglegLength        (int leaderIndex, double doglegLength);

    Zcad::ErrorStatus                     doglegLength           (int leaderIndex, double& doglegLength) const;

    Zcad::ErrorStatus                     setDoglegLength        (double doglegLength);

    double                                doglegLength           () const;

    Zcad::ErrorStatus                     setArrowSymbolId       (ZcDbObjectId arrowSymbolId);

    ZcDbObjectId                          arrowSymbolId          () const;

    Zcad::ErrorStatus getArrowSymbolId(int leaderLineIndex,
                                       ZcDbObjectId& arrowSymbolId) const;

    Zcad::ErrorStatus                     setArrowSize           (double arrowSize);

    double                                arrowSize              () const;
    Zcad::ErrorStatus setArrowSize(int leaderLineIndex, double  arrowSize);

    Zcad::ErrorStatus getArrowSize(int leaderLineIndex, double& arrowSize) const;
    Zcad::ErrorStatus                     setContentType         (ZcDbMLeaderStyle::ContentType contentType);

    ZcDbMLeaderStyle::ContentType         contentType            () const;

    Zcad::ErrorStatus                     setTextStyleId         (ZcDbObjectId textStyleId);

    ZcDbObjectId                          textStyleId            () const;

    Zcad::ErrorStatus                     setTextAttachmentType  (ZcDbMLeaderStyle::TextAttachmentType textAttachmentType,
                                                                  ZcDbMLeaderStyle::LeaderDirectionType leaderDirection);

    ZcDbMLeaderStyle::TextAttachmentType  textAttachmentType     (ZcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;

    Zcad::ErrorStatus                     setTextAttachmentType  (ZcDbMLeaderStyle::TextAttachmentType textAttachmentType);

    ZcDbMLeaderStyle::TextAttachmentType  textAttachmentType     () const;

    Zcad::ErrorStatus                     setTextAngleType       (ZcDbMLeaderStyle::TextAngleType textAngleType);

    ZcDbMLeaderStyle::TextAngleType       textAngleType          () const;

    Zcad::ErrorStatus                     setTextAlignmentType   (ZcDbMLeaderStyle::TextAlignmentType textAlignmentType);

    ZcDbMLeaderStyle::TextAlignmentType   textAlignmentType      () const;

    Zcad::ErrorStatus                     setTextColor           (const ZcCmColor& textColor);

    ZcCmColor                             textColor              () const;

    Zcad::ErrorStatus                     setTextHeight          (double textHeight);

    double                                textHeight             () const;

    Zcad::ErrorStatus                     setEnableFrameText     (bool enableFrameText);

    bool                                  enableFrameText        () const;

    Zcad::ErrorStatus                     setMText               (const ZcDbMText* pMText);

    ZcDbMText*                            mtext                  () const;

    Zcad::ErrorStatus                     setBlockContentId             (ZcDbObjectId blockId);

    ZcDbObjectId                          blockContentId                () const;

    Zcad::ErrorStatus                     setBlockColor          (const ZcCmColor& blockColor);

    ZcCmColor                             blockColor             () const;

    Zcad::ErrorStatus                     setBlockScale          (const ZcGeScale3d& scale);

    ZcGeScale3d                           blockScale             () const;

    Zcad::ErrorStatus                     setBlockRotation       (double rotation);

    double                                blockRotation          () const;

    Zcad::ErrorStatus                     setBlockConnectionType (ZcDbMLeaderStyle::BlockConnectionType blockConnectionType);

    ZcDbMLeaderStyle::BlockConnectionType blockConnectionType    () const;

    Zcad::ErrorStatus                     setEnableAnnotationScale(bool enableAnnotationScale);

    bool                                  enableAnnotationScale   () const;

    Zcad::ErrorStatus                     setMLeaderStyle        (ZcDbObjectId newStyleId);

    ZcDbObjectId                          MLeaderStyle           ();

    Zcad::ErrorStatus                     getOverridedMLeaderStyle(ZcDbMLeaderStyle& mleaderStyle);

    Zcad::ErrorStatus                     setContextDataManager  (void* pContextDataManager);

    void*                                 getContextDataManager  () const;

    Zcad::ErrorStatus                     setBlockPosition       (const ZcGePoint3d& position);

    Zcad::ErrorStatus                     getBlockPosition       (ZcGePoint3d& position) const;

    Zcad::ErrorStatus                     setTextLocation        (const ZcGePoint3d& location);

    Zcad::ErrorStatus                     getTextLocation        (ZcGePoint3d& location) const;

    Zcad::ErrorStatus                     setToleranceLocation   (const ZcGePoint3d& location);

    Zcad::ErrorStatus                     getToleranceLocation   (ZcGePoint3d& location) const;
    Zcad::ErrorStatus                     setArrowSymbolId       (int leaderLineIndex,
                                                                  ZcDbObjectId arrowSymbolId);

    ZcDbObjectId                          arrowSymbolId          (int leaderLineIndex) const;

    bool                                  hasContent             () const;

    Zcad::ErrorStatus                     connectionPoint        (const ZcGeVector3d& vect,
                                                                  ZcGePoint3d& point) const;
    Zcad::ErrorStatus                     connectionPoint        (const ZcGeVector3d& vect,
                                                                  ZcGePoint3d& point,
                                                                  ZcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
    Zcad::ErrorStatus                     recomputeBreakPoints   ();

    Zcad::ErrorStatus                     postMLeaderToDb        (ZcDbDatabase* pDb);

    Zcad::ErrorStatus                     updateLeaderLinePosition();

    Zcad::ErrorStatus                     removeLeaderLineRefAssoc(int leaderLineIndex) const;

    Zcad::ErrorStatus                     updateContentScale(ZcDbMLeaderObjectContextData* pContext);
    Zcad::ErrorStatus                     setTextAttachmentDirection(ZcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);

    ZcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;

	Zcad::ErrorStatus                     setExtendLeaderToText(bool value);
	bool                                  extendLeaderToText() const;
protected:

    virtual Zcad::ErrorStatus subGetClassID                  (CLSID* pClsid) const;
};

#endif

