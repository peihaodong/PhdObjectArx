

#pragma once

#include "zdbmain.h"
#include "zacgi.h"

#pragma pack (push, 8)

const ZTCHAR kszVSFlat[]                 = ZCRX_T("Flat");
const ZTCHAR kszVSFlatWithEdges[]        = ZCRX_T("FlatWithEdges");
const ZTCHAR kszVSGouraud[]              = ZCRX_T("Gouraud");
const ZTCHAR kszVSGouraudWithEdges[]     = ZCRX_T("GouraudWithEdges");

const ZTCHAR kszVS2DWireframe[]   = ZCRX_T("2dWireframe");
const ZTCHAR kszVS3DWireframe[]   = ZCRX_T("Wireframe");
const ZTCHAR kszVSBasic[]         = ZCRX_T("Basic");
const ZTCHAR kszVSHidden[]        = ZCRX_T("Hidden");
const ZTCHAR kszVSRealistic[]     = ZCRX_T("Realistic");
const ZTCHAR kszVSConceptual[]    = ZCRX_T("Conceptual");
const ZTCHAR kszVSCustom[]        = ZCRX_T("Custom");

const ZTCHAR kszVSShadesOfGray[]   = ZCRX_T("Shades of Gray");
const ZTCHAR kszVSSketchy[]        = ZCRX_T("Sketchy");
const ZTCHAR kszVSXRay[]           = ZCRX_T("X-Ray");

const ZTCHAR kszVSShadedWithEdges[]  = ZCRX_T("Shaded with edges");
const ZTCHAR kszVSShaded[]           = ZCRX_T("Shaded");

const ZTCHAR kszVSDim[]           = ZCRX_T("Dim");
const ZTCHAR kszVSBrighten[]      = ZCRX_T("Brighten");
const ZTCHAR kszVSThicken[]       = ZCRX_T("Thicken");
const ZTCHAR kszVSTransparent[]   = ZCRX_T("Transparent");
const ZTCHAR kszVSLinePattern[]   = ZCRX_T("Linepattern");
const ZTCHAR kszVSFacePattern[]   = ZCRX_T("Facepattern");
const ZTCHAR kszVSColorChange[]   = ZCRX_T("ColorChange");
const ZTCHAR kszVSJitterOff[]     = ZCRX_T("JitterOff");
const ZTCHAR kszVSOverhangOff[]   = ZCRX_T("OverhangOff");
const ZTCHAR kszVSEdgeColorOff[]  = ZCRX_T("EdgeColorOff");

class ZcDbVisualStyle : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbVisualStyle);

    ZcDbVisualStyle();

    virtual ~ZcDbVisualStyle();

    Zcad::ErrorStatus   setDescription (const ZTCHAR* pDescription);

    const ZTCHAR*        description    (void) const;

    Zcad::ErrorStatus setType(ZcGiVisualStyle::Type type);

    ZcGiVisualStyle::Type type() const;

#pragma warning (push)
#pragma warning (disable:4996)

    ZSOFT_DEPRECATED void setFaceStyle(const ZcGiFaceStyle& faceStyle);

    ZSOFT_DEPRECATED const ZcGiFaceStyle& faceStyle() const;

    ZSOFT_DEPRECATED void setEdgeStyle(const ZcGiEdgeStyle& edgeStyle);

    ZSOFT_DEPRECATED const ZcGiEdgeStyle& edgeStyle() const;

    ZSOFT_DEPRECATED Zcad::ErrorStatus setDisplayStyle(const ZcGiDisplayStyle& displayStyle);

    ZSOFT_DEPRECATED const ZcGiDisplayStyle& displayStyle() const;

#pragma warning (pop)

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                               const ZcGiVariant *pVal,
                               ZcGiVisualStyleOperations::Operation op 
                               = ZcGiVisualStyleOperations::kSet);

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                               int nVal,
                               ZcGiVisualStyleOperations::Operation op
                               = ZcGiVisualStyleOperations::kSet);

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                               bool bVal,
                               ZcGiVisualStyleOperations::Operation op
                               = ZcGiVisualStyleOperations::kSet);

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                              double dVal,
                              ZcGiVisualStyleOperations::Operation op
                              = ZcGiVisualStyleOperations::kSet);

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                               double red,
                               double green,
                               double blue,
                               ZcGiVisualStyleOperations::Operation op
                               = ZcGiVisualStyleOperations::kSet);

    Zcad::ErrorStatus setTrait(ZcGiVisualStyleProperties::Property prop, 
                               const ZcCmColor *pColor,
                               ZcGiVisualStyleOperations::Operation op
                               = ZcGiVisualStyleOperations::kSet);

    const ZcGiVariant& trait(ZcGiVisualStyleProperties::Property prop, 
                             ZcGiVisualStyleOperations::Operation *pOp = NULL) const;

    Zcad::ErrorStatus setTraitFlag(ZcGiVisualStyleProperties::Property flagProp,
                                   ZSoft::UInt32 flagVal,
                                   bool bEnable = true);

    bool traitFlag(ZcGiVisualStyleProperties::Property flagProp,
                   ZSoft::UInt32 flagVal) const;

    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);

    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);

    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;

    virtual ZcGiDrawable*     drawable     (void);

    virtual void              setGsNode    (ZcGsNode* pNode);

    virtual ZcGsNode*         gsNode       (void) const;
    virtual ZSoft::UInt32     setAttributes (ZcGiDrawableTraits* pTraits);
    virtual bool              isInternalUseOnly() const;

    virtual void              setInternalUseOnly(bool bInternalUseOnly);

    virtual Zcad::ErrorStatus copyTo(ZcGiVisualStyle * pDest) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcGiVisualStyle * pSrc);

    virtual Zcad::ErrorStatus decomposeForSave(
                                  ZcDb::ZcDbDwgVersion ver,
                                  ZcDbObject*&         replaceObj,
                                  ZcDbObjectId&        replaceId,
                                  ZSoft::Boolean&      exchangeXData);

};

#pragma pack (pop)

