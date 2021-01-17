
#ifndef __ZDBMLEADERSTYLE_H__
#define __ZDBMLEADERSTYLE_H__

#pragma once

#include "zAcString.h"
class ZcDbMLeaderStyle : public ZcDbObject
{
public:

    enum ContentType {
        kNoneContent                = 0,
        kBlockContent               = 1,
        kMTextContent               = 2,
        kToleranceContent           = 3,
    };
    enum DrawMLeaderOrderType {
        kDrawContentFirst           = 0,
        kDrawLeaderFirst            = 1
    };

    enum DrawLeaderOrderType {
        kDrawLeaderHeadFirst        = 0,
        kDrawLeaderTailFirst        = 1
    };

    enum LeaderType {
        kInVisibleLeader            = 0,
        kStraightLeader             = 1,
        kSplineLeader               = 2
    };

    enum TextAttachmentDirection {
        kAttachmentHorizontal       = 0,
        kAttachmentVertical         = 1
    };

    enum TextAttachmentType {
        kAttachmentTopOfTop         = 0,
        kAttachmentMiddleOfTop      = 1,
        kAttachmentMiddle           = 2,
        kAttachmentMiddleOfBottom   = 3,
        kAttachmentBottomOfBottom   = 4,
        kAttachmentBottomLine       = 5,
        kAttachmentBottomOfTopLine  = 6,
        kAttachmentBottomOfTop      = 7,
        kAttachmentAllLine          = 8,
        kAttachmentCenter           = 9,
        kAttachmentLinedCenter      = 10
    };

    enum TextAngleType {
        kInsertAngle                = 0,
        kHorizontalAngle            = 1,
        kAlwaysRightReadingAngle    = 2
    };
    enum TextAlignmentType {
        kLeftAlignment              = 0,
        kCenterAlignment            = 1,
        kRightAlignment             = 2
    };
    enum BlockConnectionType {
        kConnectExtents             = 0,
        kConnectBase                = 1
    };
    enum LeaderDirectionType {
        kUnknownLeader              = 0,
        kLeftLeader                 = 1,
        kRightLeader                = 2,
        kTopLeader                  = 3,
        kBottomLeader               = 4
    };
    enum SegmentAngleType {
        kAny                        = 0,
        k15                         = 1,
        k30                         = 2,
        k45                         = 3,
        k60                         = 4,
        k90                         = 6,
        kHorz                       = 12
    };

public:

    ZcDbMLeaderStyle();

    virtual ~ZcDbMLeaderStyle();

    ZCDB_DECLARE_MEMBERS(ZcDbMLeaderStyle);

    virtual Zcad::ErrorStatus   getName(ZTCHAR*& pszName) const;

    virtual Zcad::ErrorStatus   setName(const ZTCHAR * pszName);

    virtual const ZTCHAR*        description(void) const;

    virtual Zcad::ErrorStatus   setDescription(const ZTCHAR * pszDescription);

    virtual ZSoft::UInt32       bitFlags() const;

    virtual Zcad::ErrorStatus   setBitFlags(ZSoft::UInt32 flags);
    virtual Zcad::ErrorStatus getClassID                    (CLSID* pClsid) const;
    Zcad::ErrorStatus         setContentType                (ContentType contentType);

    ContentType               contentType                   () const;

    Zcad::ErrorStatus         setDrawMLeaderOrderType       (DrawMLeaderOrderType drawMLeaderOrderType);

    DrawMLeaderOrderType      drawMLeaderOrderType          () const;

    Zcad::ErrorStatus         setDrawLeaderOrderType        (DrawLeaderOrderType drawLeaderOrderType);

    DrawLeaderOrderType       drawLeaderOrderType           () const;

    Zcad::ErrorStatus         setMaxLeaderSegmentsPoints    (int maxLeaderSegmentsPoints);

    int                       maxLeaderSegmentsPoints       () const;

    Zcad::ErrorStatus         setFirstSegmentAngleConstraint (SegmentAngleType angle);

    SegmentAngleType          firstSegmentAngleConstraint    () const;

    Zcad::ErrorStatus         setSecondSegmentAngleConstraint(SegmentAngleType angle);

    SegmentAngleType          secondSegmentAngleConstraint   () const;

    Zcad::ErrorStatus         setLeaderLineType             (LeaderType leaderLineType);

    LeaderType                leaderLineType                () const;

    Zcad::ErrorStatus         setLeaderLineColor            (const ZcCmColor& leaderLineColor);

    ZcCmColor                 leaderLineColor               () const;

    Zcad::ErrorStatus         setLeaderLineTypeId           (ZcDbObjectId leaderLineTypeId);

    ZcDbObjectId              leaderLineTypeId              () const;

    Zcad::ErrorStatus         setLeaderLineWeight           (ZcDb::LineWeight leaderLineWeight);

    ZcDb::LineWeight          leaderLineWeight              () const;

    Zcad::ErrorStatus         setEnableLanding              (bool enableLanding);

    bool                      enableLanding                 () const;

    Zcad::ErrorStatus         setLandingGap                 (double landingGap);

    double                    landingGap                    () const;

    Zcad::ErrorStatus         setEnableDogleg               (bool enableDogleg);

    bool                      enableDogleg                  () const;

    Zcad::ErrorStatus         setDoglegLength               (double doglegLength);

    double                    doglegLength                  () const;

    Zcad::ErrorStatus         setArrowSymbolId              (const ZTCHAR* name);

    Zcad::ErrorStatus         setArrowSymbolId              (ZcDbObjectId arrowSymbolId);

    ZcDbObjectId              arrowSymbolId                 () const;

    Zcad::ErrorStatus         setArrowSize                  (double arrowSize);

    double                    arrowSize                     () const;

    Zcad::ErrorStatus         setDefaultMText               (const ZcDbMText* defaultMText);

    ZcDbMText*                defaultMText                  () const;

    Zcad::ErrorStatus         setTextStyleId                (ZcDbObjectId textStyleId);

    ZcDbObjectId              textStyleId                   () const;

    Zcad::ErrorStatus         setTextAttachmentType         (TextAttachmentType textAttachmentType,
                                                             LeaderDirectionType leaderDirection);

    TextAttachmentType        textAttachmentType            (LeaderDirectionType leaderDirection) const;

    Zcad::ErrorStatus         setTextAttachmentType         (TextAttachmentType textAttachmentType);

    TextAttachmentType        textAttachmentType            () const;

    Zcad::ErrorStatus         setTextAngleType              (TextAngleType textAngleType);

    TextAngleType             textAngleType                 () const;

    Zcad::ErrorStatus         setTextAlignmentType          (TextAlignmentType textAlignmentType);

    TextAlignmentType         textAlignmentType             () const;

    Zcad::ErrorStatus         setTextAlignAlwaysLeft        (bool bAlwaysLeft);

    bool                      textAlignAlwaysLeft           () const;

    Zcad::ErrorStatus         setTextColor                  (const ZcCmColor& textColor);

    ZcCmColor                 textColor                     () const;

    Zcad::ErrorStatus         setTextHeight                 (double textHeight);

    double                    textHeight                    () const;

    Zcad::ErrorStatus         setEnableFrameText            (bool enableFrameText);

    bool                      enableFrameText               () const;

    Zcad::ErrorStatus         setAlignSpace                 (double alignSpace);

    double                    alignSpace                    () const;

    Zcad::ErrorStatus         setBlockId                    (const ZTCHAR* name);

    Zcad::ErrorStatus         setBlockId                    (ZcDbObjectId blockId);

    ZcDbObjectId              blockId                       () const;

    Zcad::ErrorStatus         setBlockColor                 (const ZcCmColor& blockColor);

    ZcCmColor                 blockColor                    () const;

    Zcad::ErrorStatus         setBlockScale                 (const ZcGeScale3d& scale);

    ZcGeScale3d               blockScale                    () const;

    Zcad::ErrorStatus         setEnableBlockScale           (bool enableBlockScale);

    bool                      enableBlockScale              () const;

    Zcad::ErrorStatus         setBlockRotation              (double rotation);

    double                    blockRotation                 () const;

    Zcad::ErrorStatus         setEnableBlockRotation        (bool enableBlockRotation);

    bool                      enableBlockRotation           () const;

    Zcad::ErrorStatus         setBlockConnectionType        (BlockConnectionType blockConnectionType);

    BlockConnectionType       blockConnectionType           () const;

    Zcad::ErrorStatus         setScale                      (double scale);

    double                    scale                         () const;

    bool                      overwritePropChanged          () const;

    Zcad::ErrorStatus         postMLeaderStyleToDb          (ZcDbDatabase* pDb, const ZTCHAR* styleName, ZcDbObjectId & mleaderStyleId);

    Zcad::ErrorStatus         setAnnotative              (bool isAnnotative);

    bool                      annotative                 () const;

    Zcad::ErrorStatus         setBreakSize (double size);

    double                    breakSize () const;

    Zcad::ErrorStatus         setTextAttachmentDirection(ZcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);

    TextAttachmentDirection   textAttachmentDirection() const;

	Zcad::ErrorStatus         setExtendLeaderToText(bool value);
	bool                      extendLeaderToText() const;

protected:

    virtual Zcad::ErrorStatus subGetClassID                    (CLSID* pClsid) const;
};

#endif

