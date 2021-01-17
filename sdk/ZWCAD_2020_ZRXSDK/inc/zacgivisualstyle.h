
#pragma once

#include "zacgi.h"

class ZcGiImpFaceStyle;
class ZcGiImpEdgeStyle;
class ZcGiImpDisplayStyle;
class ZcGiImpVisualStyle;
class ZcGiFaceStyle : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiFaceStyle);

    enum LightingModel {
        kInvisible,
        kConstant,
        kPhong,
        kGooch
    };

    enum LightingQuality {
        kNoLighting,
        kPerFaceLighting,
		kPerVertexLighting,
        kPerPixelLighting
    };

    enum FaceColorMode {
        kNoColorMode,
        kObjectColor,
        kBackgroundColor,
        kMono,
        kTint,
        kDesaturate
    };

    enum FaceModifier {
        kNoFaceModifiers    = 0,
        kOpacity            = 1,
        kSpecular           = 2
    };

                             ZcGiFaceStyle          (void);

                             ZcGiFaceStyle          (const ZcGiFaceStyle& style);

    virtual                  ~ZcGiFaceStyle         (void);

    virtual void             set                    (const ZcGiFaceStyle& style);

    virtual ZcGiFaceStyle&   operator=              (const ZcGiFaceStyle& style);

   virtual bool             operator==             (const ZcGiFaceStyle& style) const;

    virtual void             setLightingModel       (LightingModel lightingModel);

    virtual LightingModel    lightingModel          (void) const;

    virtual void             setLightingQuality     (LightingQuality lightingQuality);

    virtual LightingQuality  lightingQuality        (void) const;

    virtual void             setFaceColorMode       (FaceColorMode mode);

    virtual FaceColorMode    faceColorMode          (void) const;

    virtual void             setFaceModifiers       ( ZSoft::UInt32  nModifiers);

    virtual void             setFaceModifierFlag    (FaceModifier flag, bool bEnable);

    virtual  ZSoft::UInt32     faceModifiers          (void) const;

    virtual bool             isFaceModifierFlagSet  (FaceModifier flag) const;

    virtual void             setOpacityLevel        (double nLevel, bool bEnableModifier);

    virtual double           opacityLevel           (void) const;

    virtual void             setSpecularAmount      (double nAmount, bool bEnableModifier);

    virtual double           specularAmount         (void) const;

    virtual void             setMonoColor           (const ZcCmColor& color, bool bEnableMode);

    virtual const ZcCmColor& monoColor              (void) const;

    virtual ZcCmColor&       monoColor              (void);

private:
    ZcGiImpFaceStyle* mpZcGiImpFaceStyle;
};

class ZcGiEdgeStyle : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiEdgeStyle);

    enum  EdgeModel {
        kNoEdges,
        kIsolines,
        kFacetEdges
    };

    enum EdgeStyle {
        kNoEdgeStyle        =  0,
        kVisible            =  1,
        kSilhouette         =  2,
        kObscured           =  4,
        kIntersection       = 8
    };

    enum EdgeModifier {
        kNoEdgeModifiers    =   0,
        kOverhang           =   1,
        kJitter             =   2,
        kWidth              =   4,
        kColor              =   8,
        kHaloGap            =  16,
        kAlwaysOnTop        =  64,
         kOpacity            = 128,
		kWiggle          = 0x100,
		kTexture         = 0x200,
    };

    enum JitterAmount {
        kJitterLow = 1,
        kJitterMedium,
        kJitterHigh,
    };

	enum WiggleAmount
	{
		kWiggleLow    = 1,
		kWiggleMedium = 2,
		kWiggleHigh   = 3,
	};

    enum Linetype {
        kSolid = 1,
        kDashed,
        kDotted,
        kShortDash,
        kMediumDash,
        kLongDash,
        kDoubleShortDash,
        kDoubleMediumDash,
        kDoubleLongDash,
        kMediumLongDash,
        kSparseDot
    };

    enum EdgeStyleApply {
        kDefault,
        kAll
	};

                                ZcGiEdgeStyle   (void);

                                ZcGiEdgeStyle   (const ZcGiEdgeStyle& style);

    virtual                     ~ZcGiEdgeStyle  (void);

    virtual void                set             (const ZcGiEdgeStyle& style);

    virtual ZcGiEdgeStyle&      operator=       (const ZcGiEdgeStyle& style);

    virtual bool                operator==      (const ZcGiEdgeStyle& style) const;

    virtual void                setEdgeModel            (EdgeModel model);

    virtual EdgeModel           edgeModel               (void) const;

    virtual void                setEdgeStyles           ( ZSoft::UInt32  nStyles);

    virtual void                setEdgeStyleFlag        (EdgeStyle flag, bool bEnable);

    virtual ZSoft::UInt32       edgeStyles              (void) const;

    virtual bool                isEdgeStyleFlagSet      (EdgeStyle flag) const;

    virtual void                setIntersectionColor    (const ZcCmColor& color);

    virtual const ZcCmColor&    intersectionColor       (void) const;

    virtual ZcCmColor&          intersectionColor       (void);

    virtual void                setObscuredColor        (const ZcCmColor& color);

    virtual const ZcCmColor&    obscuredColor           (void) const;

    virtual ZcCmColor&          obscuredColor           (void);

    virtual void                setObscuredLinetype     (Linetype ltype);

    virtual Linetype            obscuredLinetype        (void) const;

    virtual void                setIntersectionLinetype     (Linetype ltype);

    virtual Linetype            intersectionLinetype        (void) const;

    virtual void                setCreaseAngle          (double nAngle);

    virtual double              creaseAngle             (void) const;

    virtual void                setEdgeModifiers        (ZSoft::UInt32 nModifiers);

    virtual void                setEdgeModifierFlag     (EdgeModifier flag, bool bEnable);

    virtual ZSoft::UInt32       edgeModifiers           (void) const;

    virtual bool                isEdgeModifierFlagSet   (EdgeModifier flag) const;

    virtual void                setEdgeColor            (const ZcCmColor& color, bool bEnableModifier);

    virtual const ZcCmColor&    edgeColor               (void) const;

    virtual ZcCmColor&          edgeColor               (void);

    virtual void             setOpacityLevel        (double nLevel, bool bEnableModifier);

    virtual double           opacityLevel           (void) const;

    virtual void                setEdgeWidth            (int nWidth, bool bEnableModifier);

    virtual int                 edgeWidth               (void) const;

    virtual void                setOverhangAmount       (int nAmount, bool bEnableModifier);

    virtual int                 overhangAmount          (void) const;

    virtual void                setJitterAmount         (JitterAmount amount, bool bEnableModifier);

    virtual JitterAmount        jitterAmount            (void) const;

	virtual void				setWiggleAmount(WiggleAmount amount, bool bEnableModifier);
	virtual WiggleAmount	    wiggleAmount() const;

    virtual void                setSilhouetteColor      (const ZcCmColor& color);

    virtual const ZcCmColor&    silhouetteColor         (void) const;

    virtual ZcCmColor&          silhouetteColor         (void);

    virtual void                setSilhouetteWidth      (short nWidth);

    virtual short               silhouetteWidth         (void) const;

    virtual void                setHaloGap              (int nHaloGap, bool bEnableModifier);

    virtual int                 haloGap                 (void) const;

    virtual void                setIsolines             (unsigned short nIsolines);

    virtual unsigned short      isolines                (void) const;

    virtual void                setHidePrecision        (bool bHidePrecision);

    virtual bool                hidePrecision           (void) const;

    virtual void                setEdgeStyleApply       (EdgeStyleApply apply);

    virtual EdgeStyleApply      edgeStyleApply          (void) const; 

private:
    ZcGiImpEdgeStyle* mpZcGiImpEdgeStyle;
};

class ZcGiDisplayStyle : public ZcRxObject
{
public:

    enum DisplaySettings {
        kNone                =  0,
        kBackgrounds         =  1,
        kLighting            =  2,
        kMaterials           =  4,
        kTextures            =  8,
    };

    enum ShadowType {
        kShadowsNone,
        kShadowsGroundPlane,
        kShadowsFull,
        kShadowsFullAndGround,
    };

    ZCRX_DECLARE_MEMBERS(ZcGiDisplayStyle);

                                ZcGiDisplayStyle       (void);

                                ZcGiDisplayStyle       (const ZcGiDisplayStyle& style);

    virtual                     ~ZcGiDisplayStyle      (void);

    virtual void                set                    (const ZcGiDisplayStyle& style);

    virtual ZcGiDisplayStyle&   operator=              (const ZcGiDisplayStyle& style);

    virtual bool                operator==             (const ZcGiDisplayStyle& style) const;

    virtual void                setDisplaySettings     (ZSoft::UInt32 nSettings);

    virtual void                setDisplaySettingsFlag (DisplaySettings flag, bool bEnable);

    virtual ZSoft::UInt32       displaySettings        (void) const;

    virtual bool                isDisplaySettingsFlagSet(DisplaySettings flag) const;

    virtual void                setBrightness          (double value);

    virtual double              brightness             (void) const;

    virtual void                setShadowType          (ShadowType type);

    virtual ShadowType          shadowType             (void) const;

private:
    ZcGiImpDisplayStyle* mpZcGiImpDisplayStyle;
};

namespace ZcGiVisualStyleProperties
{

    enum Property {

        kInvalidProperty = -1,

        kFaceLightingModel,

        kFaceLightingQuality,

        kFaceColorMode,

        kFaceModifiers,

        kFaceOpacity,

        kFaceSpecular,

        kFaceMonoColor,

        kEdgeModel,

        kEdgeStyles,

        kEdgeIntersectionColor,

        kEdgeObscuredColor,

        kEdgeObscuredLinePattern,

        kEdgeIntersectionLinePattern,

        kEdgeCreaseAngle,

        kEdgeModifiers,

        kEdgeColor,

        kEdgeOpacity,

        kEdgeWidth,

        kEdgeOverhang,

        kEdgeJitterAmount,

        kEdgeSilhouetteColor,

        kEdgeSilhouetteWidth,

        kEdgeHaloGap,

        kEdgeIsolines,

        kEdgeHidePrecision,

        kDisplayStyles,

        kDisplayBrightness,

        kDisplayShadowType,

		kUseDrawOrder,	                 //= 28, // boolean
		kViewportTransparency,        // = 29, // boolean
		kLightingEnabled,              //= 30, // boolean
		kPosterizeEffect,              //= 31, // boolean
		kMonoEffect,                   //= 32, // boolean

		kBlurEffect,                   //= 33, // boolean
		kPencilEffect,                 //= 34, // boolean
		kBloomEffect,                  //= 35, // boolean
		kPastelEffect,                 //= 36, // boolean
		kBlurAmount,                   //= 37, // integer
		kPencilAngle,                 // = 38, // double
		kPencilScale,                  //= 39, // -integer- (double)
		kPencilPattern,                //= 40, // integer
		kPencilColor,                  //= 41, // color
		kBloomThreshold,            //   = 42, // -double- (integer)
		kBloomRadius,                 // = 43, // -double- (integer)
		kTintColor,                   // = 44, // color
		kFaceAdjustment,          //     = 45, // boolean
		kPostContrast,               //  = 46, // -double? (integer)
		kPostBrightness,            //   = 47, // -double? (integer)
		kPostPower,                  //  = 48, // -double? (integer)
		kTintEffect,                  // = 49, // boolean
		kBloomIntensity,          //     = 50, // -double- (integer)
		kColor,                       // = 51, // color
		kTransparency,                 //= 52, // double
		kEdgeWiggleAmount,         //    = 53, // integer
		kEdgeTexturePath,             // = 54, // string
		kDepthOfField,                // = 55, // boolean
		kFocusDistance,              //  = 56, // double
		kFocusWidth,                  // = 57, // double
        kPropertyCount,
		kPropertyCountPre2013 = kUseDrawOrder,
    };

    enum FaceLightingModel {

        kInvisible,

        kConstant,

        kPhong,

        kGooch,

		kZebra
    };

    enum FaceLightingQuality {

        kNoLighting,

        kPerFaceLighting,

        kPerVertexLighting,

        kPerPixelLighting
    };

    enum FaceColorMode {

        kNoColorMode,

        kObjectColor,

        kBackgroundColor,

        kMono,

        kTint,

        kDesaturate
    };

    enum FaceModifiers {

        kNoFaceModifiers    = 0,

        kFaceOpacityFlag    = 1,

        kSpecularFlag       = 2
    };

    enum  EdgeModel {

        kNoEdges,

        kIsolines,

        kFacetEdges
    };

    enum EdgeStyles {

        kNoEdgeStyle        =  0,

        kVisibleFlag        =  1,

        kSilhouetteFlag     =  2,

        kObscuredFlag       =  4,

        kIntersectionFlag   = 8
    };

    enum EdgeModifiers {

        kNoEdgeModifiers    =   0,

        kEdgeOverhangFlag       =   1,

        kEdgeJitterFlag     =   2,

        kEdgeWidthFlag      =   4,

        kEdgeColorFlag      =   8,

        kEdgeHaloGapFlag    =  16,

        kAlwaysOnTopFlag    =  64,

        kEdgeOpacityFlag        = 128,

		kEdgeWiggleFlag         = 256,

		kEdgeTextureFlag         = 512,
    };

    enum EdgeJitterAmount {

        kJitterLow = 1,

        kJitterMedium,

        kJitterHigh,
    };

    enum EdgeLinePattern {

        kSolid = 1,

        kDashedLine,

        kDotted,

        kShortDash,

        kMediumDash,

        kLongDash,

        kDoubleShortDash,

        kDoubleMediumDash,

        kDoubleLongDash,

        kMediumLongDash,

        kSparseDot
    };

    enum DisplayStyles {

        kNoDisplayStyle      =  0,

        kBackgroundsFlag     =  1,

        kLightingFlag        =  2,

        kMaterialsFlag       =  4,

        kTexturesFlag        =  8,
    };

    enum DisplayShadowType {

        kShadowsNone,

        kShadowsGroundPlane,

        kShadowsFull,

        kShadowsFullAndGround,
    };
};

namespace ZcGiVisualStyleOperations
{

    enum Operation {
        kInvalidOperation = -1,

        kInherit = 0,

        kSet,

        kDisable,

        kEnable
    };
};

class ZcGiVisualStyle : public ZcRxObject
{
public:
    friend class            ZcDbImpVisualStyle;
    ZCRX_DECLARE_MEMBERS(ZcGiVisualStyle);
    typedef ZcGiVisualStyleProperties::Property Property;
    typedef ZcGiVisualStyleOperations::Operation Operation;
    enum Type {
        kFlat,
        kFlatWithEdges,
        kGouraud,
        kGouraudWithEdges,
        k2DWireframe,
        k3DWireframe,
        kHidden,
        kBasic,
        kRealistic,
        kConceptual,
        kCustom,
        kDim,
        kBrighten,
        kThicken,
        kLinePattern,
        kFacePattern,
        kColorChange,
        kFaceOnly,
        kEdgeOnly,
        kDisplayOnly,
        kJitterOff,
        kOverhangOff,
        kEdgeColorOff,
        kShadesOfGray,
        kSketchy,
        kXRay,
        kShadedWithEdges,
        kShaded,
        kByViewport,
        kByLayer,
        kByBlock,
        kEmptyStyle
    };

                            ZcGiVisualStyle     (void);

                            ZcGiVisualStyle     (Type type);

                            ZcGiVisualStyle     (const ZcGiVisualStyle& visualStyle);

                            ~ZcGiVisualStyle    (void);

    ZcGiVisualStyle& operator=(const ZcGiVisualStyle& visualStyle);

    bool operator==(const ZcGiVisualStyle& visualStyle) const;
    ZCDB_PORT bool              setType     (Type type);

    ZCDB_PORT Type              type        (void) const;

    ZCDB_PORT virtual bool      setTrait    (Property prop, Operation op);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             const ZcGiVariant *pVal,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             int nVal,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             bool bVal,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             double dVal,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             double red,
                                             double green,
                                             double blue,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual bool      setTrait    (Property prop, 
                                             const ZcCmColor *pColor,
                                             Operation op = ZcGiVisualStyleOperations::kSet);

	ZCDB_PORT virtual bool      setTrait    (Property prop, 
											const ZcString *pStr,
											Operation op = ZcGiVisualStyleOperations::kSet);

    ZCDB_PORT virtual const ZcGiVariant& trait (Property prop, 
                                             Operation *pOp = NULL) const;

    ZCDB_PORT virtual Operation          operation (Property prop) const;

    ZCDB_PORT virtual bool      setTraitFlag(Property flagProp,
                                             ZSoft::UInt32 flagVal,
                                             bool bEnable = true);

    ZCDB_PORT virtual bool      traitFlag   (Property flagProp,
                                             ZSoft::UInt32 flagVal) const;

    ZCDB_PORT static ZcGiVariant::VariantType propertyType(Property prop);

    ZSOFT_DEPRECATED void                    configureForType    (Type type);

    ZSOFT_DEPRECATED ZcGiFaceStyle&          faceStyle    (void);

    ZSOFT_DEPRECATED ZcGiEdgeStyle&          edgeStyle    (void);

    ZSOFT_DEPRECATED ZcGiDisplayStyle&       displayStyle (void);

    ZSOFT_DEPRECATED const ZcGiFaceStyle&    faceStyle    (void) const;

    ZSOFT_DEPRECATED const ZcGiEdgeStyle&    edgeStyle    (void) const;

    ZSOFT_DEPRECATED const ZcGiDisplayStyle& displayStyle (void) const;

    ZSOFT_DEPRECATED void  setFaceStyle      (const ZcGiFaceStyle& style);

    ZSOFT_DEPRECATED void  setEdgeStyle      (const ZcGiEdgeStyle& style);

    ZSOFT_DEPRECATED void  setDisplayStyle   (const ZcGiDisplayStyle& style);
private:
    const ZcGiImpVisualStyle* readImp  (void) const;
    ZcGiImpVisualStyle*       writeImp (void);

    ZcGiImpVisualStyle* mpZcGiImpVisualStyle;
};

class ZcGiVisualStyleTraits : public ZcGiDrawableTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiVisualStyleTraits);

    virtual void                   setZcGiVisualStyle   (const ZcGiVisualStyle& visualStyle) = 0;

    virtual const ZcGiVisualStyle& zcgiVisualStyle      (void) const = 0;
};
