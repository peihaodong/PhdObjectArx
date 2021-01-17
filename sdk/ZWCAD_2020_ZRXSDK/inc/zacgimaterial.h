
#pragma once

#include "zAdAChar.h"
#include "zacgi.h"
#pragma pack (push, 8)

#ifdef ZCGIMATERIAL_IMPL
  #define ZCGIMAT_IMPEXP ZSOFT_DLLEXPORT
#else
  #define ZCGIMAT_IMPEXP ZSOFT_DLLIMPORT
#endif

class ZcGiMaterialColor;
class ZcGiMaterialMap;

class ZcGiMaterialTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiMaterialTraits);

    enum IlluminationModel {
        kBlinnShader = 0,
        kMetalShader,
    };

    enum ChannelFlags
    {
        kNone          = 0x00000,
        kUseDiffuse    = 0x00001,
        kUseSpecular   = 0x00002,
        kUseReflection = 0x00004,
        kUseOpacity    = 0x00008,
        kUseBump       = 0x00010,
        kUseRefraction = 0x00020,
        kUseNormalMap  = 0x00040,
        kUseAll        = (kUseDiffuse | kUseSpecular | kUseReflection
                            | kUseOpacity | kUseBump | kUseRefraction
                            | kUseNormalMap),
    };

    enum Mode {
        kRealistic = 0,
        kAdvanced,
    };

	enum LuminanceMode
	{
		kSelfIllumination = 0,
		kLuminance,
	};

	enum NormalMapMethod
	{
		kTangentSpace
	};

	enum GlobalIlluminationMode
	{
		kGlobalIlluminationNone,
		kGlobalIlluminationCast,
		kGlobalIlluminationReceive,
		kGlobalIlluminationCastAndReceive
	};

	enum FinalGatherMode
	{
		kFinalGatherNone,
		kFinalGatherCast,
		kFinalGatherReceive,
		kFinalGatherCastAndReceive
	};
    virtual void setAmbient     (const ZcGiMaterialColor & color)   = 0;
    virtual void setDiffuse     (const ZcGiMaterialColor & color, 
                                 const ZcGiMaterialMap & map)       = 0;
    virtual void setSpecular    (const ZcGiMaterialColor & color, 
                                 const ZcGiMaterialMap & map,
                                 double dGloss)                     = 0;
    virtual void setReflection  (const ZcGiMaterialMap & map)       = 0;
    virtual void setOpacity     (double dPercentage, 
                                 const ZcGiMaterialMap & map)       = 0;
    virtual void setBump        (const ZcGiMaterialMap & map)       = 0;
    virtual void setRefraction  (double dIndex, 
                                 const ZcGiMaterialMap & map)       = 0;
    virtual void setTranslucence(double value)                      = 0;
    virtual void setSelfIllumination(double value)                  = 0;
    virtual void setReflectivity(double value)                      = 0;
    virtual void setIlluminationModel(IlluminationModel model)      = 0;
    virtual void setChannelFlags(ChannelFlags flags)                = 0;
    virtual void setMode(Mode value)                                = 0;
    virtual void ambient        (ZcGiMaterialColor & color) const   = 0;
    virtual void diffuse        (ZcGiMaterialColor & color, 
                                 ZcGiMaterialMap & map) const       = 0;
    virtual void specular       (ZcGiMaterialColor & color, 
                                 ZcGiMaterialMap & map,
                                 double & dGloss) const             = 0;
    virtual void reflection     (ZcGiMaterialMap & map) const       = 0;
    virtual void opacity        (double & dPercentage, 
                                 ZcGiMaterialMap & map) const       = 0;
    virtual void bump           (ZcGiMaterialMap & map) const       = 0;
    virtual void refraction     (double & dIndex, 
                                 ZcGiMaterialMap & map) const       = 0;
    virtual double translucence() const                             = 0;
    virtual double selfIllumination() const                         = 0;
    virtual double reflectivity() const                             = 0;
    virtual IlluminationModel illuminationModel() const             = 0;
    virtual ChannelFlags channelFlags() const                       = 0;
    virtual Mode mode() const                                       = 0;

	virtual void setColorBleedScale(double value)                   = 0;
    virtual void setIndirectBumpScale(double value)                 = 0;
    virtual void setReflectanceScale(double value)                  = 0;
    virtual void setTransmittanceScale(double value)                = 0;
    virtual void setTwoSided(bool value)                            = 0;
    virtual void setLuminanceMode(LuminanceMode value)              = 0;
    virtual void setLuminance(double value)                         = 0;
    virtual void setNormalMap(const ZcGiMaterialMap & map,
                              NormalMapMethod method,
                              double strength)                      = 0;
    virtual void setGlobalIllumination(GlobalIlluminationMode mode) = 0;
    virtual void setFinalGather(FinalGatherMode mode)               = 0;
    virtual double colorBleedScale() const                          = 0;
    virtual double indirectBumpScale() const                        = 0;
    virtual double reflectanceScale() const                         = 0;
    virtual double transmittanceScale() const                       = 0;
    virtual bool   twoSided() const                                 = 0;
    virtual LuminanceMode luminanceMode() const                     = 0;
    virtual double luminance() const                                = 0;
    virtual void normalMap(ZcGiMaterialMap & map,
                           NormalMapMethod &method,
                           double &strength) const                  = 0;
    virtual GlobalIlluminationMode globalIllumination() const       = 0;
    virtual FinalGatherMode finalGather() const                     = 0;
};

class ZcGiImpMaterialColor;

class ZcGiMaterialColor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiMaterialColor);

    enum Method {
        kInherit = 0,
        kOverride,     
    };

    ZCGIMAT_IMPEXP static const ZcGiMaterialColor kNull;

    ZcGiMaterialColor             (void);
    virtual ~ZcGiMaterialColor    (void);

    ZcGiMaterialColor             (const ZcGiMaterialColor &matColor);
    ZcGiMaterialColor & operator= (const ZcGiMaterialColor &matColor);
	bool                operator==(const ZcGiMaterialColor &matColor)const;

    virtual void set       (const ZcGiMaterialColor &matColor);
    virtual void setMethod (Method method);
    virtual void setFactor (double dFactor);
    virtual void setColor  (const ZcCmEntityColor& color);

    virtual Method                  method (void) const;
    virtual double                  factor (void) const;
    virtual const ZcCmEntityColor & color  (void) const;

private:
    ZcGiImpMaterialColor * mpZcGiImpMaterialColor;
};

class ZcGiMaterialTexture : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiMaterialTexture);
	virtual bool operator==(const ZcGiMaterialTexture & texture)const;
protected:
};

inline bool ZcGiMaterialTexture::operator==(const ZcGiMaterialTexture & texture) const {
        return (texture.isA() == isA());
}

class ZcGiImageTexture : public ZcGiMaterialTexture
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiImageTexture);
};

class ZcGiImpImageFileTexture;

class ZcGiImageFileTexture : public ZcGiImageTexture
{
	friend class ZcGiImpImageFileTexture;
public:
	ZCRX_DECLARE_MEMBERS(ZcGiImageFileTexture);

	ZcGiImageFileTexture             (void);
	virtual ~ZcGiImageFileTexture    (void);

	ZcGiImageFileTexture             (const ZcGiImageFileTexture &texture);
	ZcGiImageFileTexture & operator= (const ZcGiImageFileTexture &texture);
	virtual bool operator==(const ZcGiMaterialTexture & texture) const;

	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

	virtual void                setSourceFileName (const ZTCHAR * fileName);
	virtual const ZTCHAR *      sourceFileName    (void) const;
private:
	ZcGiImpImageFileTexture * mpZcGiImpImageFileTexture;
};

class ZcGiProceduralTexture : public ZcGiMaterialTexture
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiProceduralTexture);

	enum Type
	{
		kWood = 0,
		kMarble,
		kGeneric,
	};
	virtual Type type()const = 0;
};

class ZcGiGenericTexture : public ZcGiProceduralTexture
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiGenericTexture);

	ZcGiGenericTexture              (void);
	virtual ~ZcGiGenericTexture      (void);

	ZcGiGenericTexture              (const ZcGiGenericTexture &texture);
	ZcGiGenericTexture & operator=  (const ZcGiGenericTexture &texture);
	virtual bool         operator== (const ZcGiMaterialTexture &texture) const;

	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

	void            setDefinition   (const ZcGiVariant& definition);
	ZcGiVariant     definition      (void) const;
	void            definition      (ZcGiVariant*& pDefinition);
	virtual Type type()const {return kGeneric;}
protected:
	ZcGiVariant     m_definition;
};

class ZcGiImpWoodTexture;

class ZcGiWoodTexture : public ZcGiProceduralTexture
{
	friend class ZcGiImpWoodTexture;
public:
	ZCRX_DECLARE_MEMBERS(ZcGiWoodTexture);

	ZcGiWoodTexture             (void);
	virtual ~ZcGiWoodTexture    (void);

	ZcGiWoodTexture             (const ZcGiWoodTexture &texture);
	ZcGiWoodTexture & operator= (const ZcGiWoodTexture &texture);
	virtual bool      operator==(const ZcGiMaterialTexture & texture) const;

	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

	virtual void setColor1      (const ZcGiMaterialColor &woodColor1);
	virtual const ZcGiMaterialColor & color1  (void) const;

	virtual void setColor2      (const ZcGiMaterialColor &woodColor2);
	virtual const ZcGiMaterialColor & color2  (void) const;

	virtual void setRadialNoise (double radialNoise);
	virtual double radialNoise  (void) const;

	virtual void setAxialNoise  (double axialNoise);
	virtual double axialNoise   (void) const;

	virtual void setGrainThickness  (double grainThickness);
	virtual double grainThickness   (void) const;
	virtual Type type()const {return kWood;}
private:
	ZcGiImpWoodTexture * mpZcGiImpWoodTexture;
};

class ZcGiImpMarbleTexture;

class ZcGiMarbleTexture : public ZcGiProceduralTexture
{
	friend class ZcGiImpMarbleTexture;
public:
	ZCRX_DECLARE_MEMBERS(ZcGiMarbleTexture);

	ZcGiMarbleTexture             (void);
	virtual ~ZcGiMarbleTexture    (void);

	ZcGiMarbleTexture             (const ZcGiMarbleTexture &texture);
	ZcGiMarbleTexture & operator= (const ZcGiMarbleTexture &texture);
	virtual bool        operator==(const ZcGiMaterialTexture & texture) const;

	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

	virtual void setStoneColor     (const ZcGiMaterialColor &stoneColor);
	virtual const ZcGiMaterialColor & stoneColor  (void) const;

	virtual void setVeinColor      (const ZcGiMaterialColor &veinColor);
	virtual const ZcGiMaterialColor & veinColor  (void) const;

	virtual void setVeinSpacing    (double veinSpacing);
	virtual double veinSpacing     (void) const;

	virtual void setVeinWidth      (double veinWidth);
	virtual double veinWidth       (void) const;
	virtual Type type()const {return kMarble;}
private:
	ZcGiImpMarbleTexture * mpZcGiImpMarbleTexture;
};

class ZcGiMapper;
class ZcGiImpMaterialMap;

class ZcGiMaterialMap: public ZcRxObject 
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiMaterialMap);

    enum Source {
        kScene = 0,
        kFile,
        kProcedural
    };

	enum Filter 
	{
		kFilterDefault = 0,
		kFilterNone
	};

	ZCGIMAT_IMPEXP Zcad::ErrorStatus   setFilter   (Filter filter);
	ZCGIMAT_IMPEXP Filter              filter      (void) const;
    ZCGIMAT_IMPEXP static const ZcGiMaterialMap kNull;

    ZcGiMaterialMap             (void);
    virtual ~ZcGiMaterialMap    (void);

    ZcGiMaterialMap             (const ZcGiMaterialMap &matMap);
    ZcGiMaterialMap & operator= (const ZcGiMaterialMap &matMap);
    bool              operator==(const ZcGiMaterialMap &matMap)const;
    virtual void set               (const ZcGiMaterialMap &matMap);
    virtual void setSource         (Source source);
    ZSOFT_DEPRECATED virtual void setSourceFileName (const ZTCHAR * fileName);
    virtual void setTexture        (const ZcGiMaterialTexture * pTexture);
    virtual void setBlendFactor    (double blendFactor);
    virtual void setMapper         (const ZcGiMapper &mapper);

    virtual Source                  source         (void) const;
    ZSOFT_DEPRECATED virtual const ZTCHAR * sourceFileName (void) const;
    virtual const ZcGiMaterialTexture *  texture   (void) const;
    virtual double                  blendFactor    (void) const;
    virtual const ZcGiMapper &      mapper         (void) const;

private:
    ZcGiImpMaterialMap * mpZcGiImpMaterialMap;
};

class ZcGiImpMapper;

class ZcGiMapper: public ZcRxObject 
{
public:
	ZCRX_DECLARE_MEMBERS(ZcGiMapper);

    enum Projection {
        kInheritProjection = 0,
        kPlanar,
        kBox,
        kCylinder,
        kSphere
    };

    enum Tiling {
        kInheritTiling = 0,
        kTile,
        kCrop,
        kClamp,
        kMirror,
    };

    enum AutoTransform {
        kInheritAutoTransform = 0x0,
        kNone                 = 0x1,
        kObject               = 0x2,
        kModel                = 0x4
    };

    ZCGIMAT_IMPEXP static const ZcGiMapper kIdentity;

    ZcGiMapper             (void);
    virtual ~ZcGiMapper    (void);

    ZcGiMapper             (const ZcGiMapper &mapper);
    ZcGiMapper & operator= (const ZcGiMapper &mapper);
    bool         operator==(const ZcGiMapper &mapper) const;
    bool         operator!=(const ZcGiMapper &mapper) const
    {
        return !(*this == mapper);
    };
    virtual                  void set               (const ZcGiMapper &mapper);
    virtual                  void setProjection     (Projection projection);
    virtual                  void setAutoTransform  (AutoTransform autoTransform);
    virtual                  void setTransform      (const ZcGeMatrix3d &transform);
    virtual                     Projection             projection    (void) const;
	virtual                     AutoTransform          autoTransform (void) const;
    virtual                     const ZcGeMatrix3d&    transform     (void) const;
    void        setUTiling        (Tiling tiling);
    void        setVTiling        (Tiling tiling);
    Tiling      uTiling           (void) const;
    Tiling      vTiling           (void) const;
private:
	ZcGiImpMapper * mpZcGiImpMapper;
};

#pragma pack (pop)
