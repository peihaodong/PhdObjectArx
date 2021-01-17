

#pragma once

#include "zacgi.h"

#pragma pack (push, 8)

class ZcGiLightTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiLightTraits);
    virtual void setOn(bool on) = 0;
    virtual bool isOn() const = 0;
};

class ZcGiShadowParameters : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiShadowParameters);

    ZcGiShadowParameters();
    virtual ~ZcGiShadowParameters();

    bool operator==(const ZcGiShadowParameters& params) const;
    virtual void setShadowsOn(bool on);
    virtual bool shadowsOn() const;
    
	enum ShadowType {
        kShadowsRayTraced = 0,
        kShadowMaps,
        kAreaSampled
    };
    
	virtual void setShadowType(ShadowType typ);
    virtual ShadowType shadowType() const;
    virtual bool setShadowMapSize(ZSoft::UInt16 sz);
    virtual ZSoft::UInt16 shadowMapSize() const;
    virtual bool setShadowMapSoftness(ZSoft::UInt8 soft);
    virtual ZSoft::UInt8 shadowMapSoftness() const;
    virtual bool setShadowSamples(ZSoft::UInt16 samples);
    virtual ZSoft::UInt16 shadowSamples() const;
    virtual void setShapeVisibility(bool visible);
    virtual bool shapeVisibility() const;
    
	enum ExtendedLightShape {
        kLinear = 0,
        kRectangle,
        kDisk,
        kCylinder,
        kSphere
    };
    
	virtual bool setExtendedLightShape(ExtendedLightShape shape);
    virtual ExtendedLightShape extendedLightShape() const;
    virtual bool setExtendedLightLength(double length);
    virtual double extendedLightLength() const;
    virtual bool setExtendedLightWidth(double width);
    virtual double extendedLightWidth() const;
    virtual bool setExtendedLightRadius(double radius);
    virtual double extendedLightRadius() const;

protected:
	bool				mShadowsOn;
	ShadowType			mShadowType;
	ZSoft::UInt16		mShadowMapSize;
	ZSoft::UInt8		mShadowMapSoftness;
    ZSoft::UInt16       mShadowSamples;
    bool                mbShapeVisibility;
    ExtendedLightShape  mExtLightShape;
    double              mExtLightLength;
    double              mExtLightWidth;
    double              mExtLightRadius;
};

class ZcGiLightAttenuation : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiLightAttenuation);

    ZcGiLightAttenuation();
    virtual ~ZcGiLightAttenuation();

    bool operator==(const ZcGiLightAttenuation& atten) const;
    
	enum AttenuationType {
        kNone = 0,
        kInverseLinear,
        kInverseSquare
    };

    virtual void setAttenuationType(AttenuationType typ);
    virtual AttenuationType attenuationType() const;
    virtual void setUseLimits(bool on);
    virtual bool useLimits() const;
    virtual void setLimits(double startlim, double endlim);
    virtual double startLimit() const;
    virtual double endLimit() const;

private:
    AttenuationType mAttenType;
    bool            mUseAttenLimits;
    double          mAttenStartLimit;
    double          mAttenEndLimit;
};

class ZcGiSkyParameters : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSkyParameters);

    ZcGiSkyParameters();
    virtual ~ZcGiSkyParameters();

    bool operator==(const ZcGiSkyParameters& params) const;
    void setIllumination(bool enable)   { return setIlluminationImp(enable); }
    bool illumination() const { return illuminationImp(); }
    bool setIntensityFactor(double intensity)   { return setIntensityFactorImp(intensity); }
    double intensityFactor() const { return intensityFactorImp(); }
    bool setHaze(double haze) { return setHazeImp(haze); }
    double haze() const { return hazeImp(); }
    bool setHorizonHeight(double height) { return setHorizonHeightImp(height); }
    double horizonHeight() const    { return horizonHeightImp(); }
    bool setHorizonBlur(double blur) { return setHorizonBlurImp(blur); }
    double horizonBlur() const { return horizonBlurImp(); }
    void setGroundColor(const ZcCmColor& color) { return setGroundColorImp(color); }
    ZcCmColor groundColor() const { return groundColorImp(); }
    void setNightColor(const ZcCmColor& color) { setNightColorImp(color); }
    ZcCmColor nightColor() const    { return nightColorImp(); }
    void setAerialPerspective(bool apply) { setAerialPerspectiveImp(apply); }
    bool aerialPerspective() const { return aerialPerspectiveImp(); }
    bool setVisibilityDistance(double distance) { return setVisibilityDistanceImp(distance); }
    double visibilityDistance() const { return visibilityDistanceImp(); }
    bool setDiskScale(double scale) { return setDiskScaleImp(scale); }
    double diskScale() const { return diskScaleImp(); }
    bool setGlowIntensity (double intensity) { return setGlowIntensityImp(intensity); }
    double glowIntensity() const { return glowIntensityImp(); }
    bool setDiskIntensity(double intensity) { return setDiskIntensityImp(intensity); }
    double diskIntensity() const { return diskIntensityImp(); }
    bool setSolarDiskSamples(ZSoft::UInt16 samples) { return setSolarDiskSamplesImp(samples); }
    ZSoft::UInt16 solarDiskSamples() const { return solarDiskSamplesImp(); }
    bool setSunDirection(const ZcGeVector3d& sundir) { return setSunDirectionImp(sundir); }
    const ZcGeVector3d& sunDirection() const { return sunDirectionImp(); }
    bool setRedBlueShift (double redBlueShift)  { return setRedBlueShiftImp(redBlueShift); }
    double redBlueShift  (void) const           { return redBlueShiftImp(); }
    bool setSaturation (double saturation)      { return setSaturationImp(saturation); }
    double saturation (void) const              { return saturationImp(); }

protected:
    virtual void setIlluminationImp (bool enable);
    virtual bool illuminationImp (void) const;

    virtual bool setIntensityFactorImp (double intensity);
    virtual double intensityFactorImp () const;

    virtual bool setHazeImp (double haze);
    virtual double hazeImp (void) const;

    virtual bool setHorizonHeightImp        (double height);
    virtual double horizonHeightImp (void) const;

    virtual bool setHorizonBlurImp (double blur);
    virtual double horizonBlurImp () const;

    virtual void setGroundColorImp (const ZcCmColor& color);
    virtual ZcCmColor groundColorImp () const;

    virtual void setNightColorImp (const ZcCmColor& color);
    virtual ZcCmColor nightColorImp () const;

    virtual void setAerialPerspectiveImp (bool apply);
    virtual bool aerialPerspectiveImp () const;

    virtual bool setVisibilityDistanceImp (double distance);
    virtual double visibilityDistanceImp () const;

    virtual bool setDiskScaleImp (double scale);
    virtual double diskScaleImp () const;

    virtual bool setGlowIntensityImp (double intensity);
    virtual double glowIntensityImp () const;

    virtual bool setDiskIntensityImp (double intensity);
    virtual double diskIntensityImp () const;

    virtual bool setSolarDiskSamplesImp (ZSoft::UInt16 samples);
    virtual ZSoft::UInt16 solarDiskSamplesImp (void) const;

    virtual bool  setSunDirectionImp (const ZcGeVector3d& sundir);
    virtual const ZcGeVector3d& sunDirectionImp (void) const;

    virtual bool setRedBlueShiftImp  (double redBlueShift);
    virtual double  redBlueShiftImp (void) const;

    virtual bool setSaturationImp (double saturation);
    virtual double  saturationImp (void) const;

private:
    bool            mStatus;
    double          mIntensityFactor;
    double          mHaze;
    double          mHorizonHeight;
    double          mHorizonBlur;
    ZcCmColor       mGroundColor;
    ZcCmColor       mNightColor;
    bool            mAerialPerspective;
    double          mVisibilityDistance;
    double          mDiskScale;
    double          mGlowIntensity;
    double          mDiskIntensity;
    ZSoft::UInt16   mSolarDiskSamples;
    ZcGeVector3d    mSunDirection;
    double          mRedBlueShift;
    double          mSaturation;
};

class ZcGiStandardLightTraits : public ZcGiLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiStandardLightTraits);
    virtual void setIntensity(double inten) = 0;
    virtual double intensity() const = 0;
    virtual void setLightColor(const ZcCmColor& color) = 0;
    virtual ZcCmColor lightColor() const = 0;
    virtual void setShadowParameters(const ZcGiShadowParameters& params) = 0;
    virtual void shadowParameters(ZcGiShadowParameters& params) const = 0;
};

class ZcGiPointLightTraits : public ZcGiStandardLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiPointLightTraits);
    virtual void setPosition(const ZcGePoint3d& pos) = 0;
    virtual ZcGePoint3d position() const = 0;
    virtual void lightAttenuation(ZcGiLightAttenuation& atten) const = 0;
    virtual void setAttenuation(const ZcGiLightAttenuation& atten) = 0;
    virtual void setPhysicalIntensity(double physicalIntensity) = 0;
    virtual double physicalIntensity() const = 0;
    virtual void setLampColor (const ZcGiColorRGB& rgbColor) = 0;
    virtual void lampColor (ZcGiColorRGB& rgbColor) const = 0;
    virtual void setHasTarget (bool bHasTarget) = 0;
    virtual bool hasTarget (void) const = 0;
    virtual void setTargetLocation(const ZcGePoint3d& loc) = 0;
    virtual ZcGePoint3d targetLocation() const = 0;
};

class ZcGiSpotLightTraits : public ZcGiStandardLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSpotLightTraits);
    virtual void setPosition(const ZcGePoint3d& pos) = 0;
    virtual ZcGePoint3d position() const = 0;
    virtual void setTargetLocation(const ZcGePoint3d& loc) = 0;
    virtual ZcGePoint3d targetLocation() const = 0;
    virtual bool setHotspotAndFalloff(double hotspot, double falloff) = 0;
    virtual double hotspot() const = 0;
    virtual double falloff() const = 0;
    virtual void lightAttenuation(ZcGiLightAttenuation& atten) const = 0;
    virtual void setAttenuation(const ZcGiLightAttenuation& atten) = 0;
};

class ZcGiSpotLightTraits2 : public ZcGiSpotLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSpotLightTraits2);
    virtual void setPhysicalIntensity(double physicalIntensity) = 0;
    virtual double physicalIntensity() const = 0;
    virtual void setLampColor (const ZcGiColorRGB& rgbColor) = 0;
    virtual void lampColor (ZcGiColorRGB& rgbColor) const = 0;
    virtual void setShadowParameters(const ZcGiShadowParameters& params) = 0;
    virtual void shadowParameters(ZcGiShadowParameters& params) const = 0;
};

class ZcGiDistantLightTraits : public ZcGiStandardLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiDistantLightTraits);
    virtual void setLightDirection(const ZcGeVector3d& vec) = 0;
    virtual ZcGeVector3d lightDirection() const = 0;
    virtual void setIsSunlight(bool isSunlight) = 0;
    virtual bool isSunlight() const = 0;
    virtual void setPhysicalIntensity(double physicalIntensity) = 0;
    virtual double physicalIntensity() const = 0;
    virtual void setLampColor (const ZcGiColorRGB& rgbColor) = 0;
    virtual void lampColor (ZcGiColorRGB& rgbColor) const = 0;
    virtual void setSkyParameters(const ZcGiSkyParameters& params) = 0;
    virtual void skyParameters(ZcGiSkyParameters& params) const = 0;
};

class ZcGiWebLightTraits : public ZcGiPointLightTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiWebLightTraits);
    enum WebFileType
    {
        kTypeC = 1,
        kTypeB = 2,
        kTypeA = 3
    };

    enum WebSymmetry
    {
        kNoSymmetry = 0,
        kSingleSymmetry = 1,
        kDoubleSymmetry = 2,
        kAxialSymmetry = 3,
    };

    virtual void setWebFile(const ZTCHAR* webFile) = 0;
    virtual void webFile(ZcString& webFile) const = 0;
    virtual void setWebRotation(ZcGeVector3d rotation) = 0;
    virtual void webRotation(ZcGeVector3d& rotation) const = 0;
    virtual void setWebFlux(double flux) const = 0;
    virtual double webFlux() const = 0;
    virtual void setWebFileType (WebFileType type) = 0;
    virtual WebFileType webFileType (void) const = 0;
    virtual void setWebSymmetry (WebSymmetry symmetry) = 0;
    virtual WebSymmetry webSymmetry (void) const = 0;
    virtual void setWebHorzAng90to270 (bool bIs90to270) = 0;
    virtual bool webHorzAng90to270 (void) const = 0;
};

#pragma pack (pop)
