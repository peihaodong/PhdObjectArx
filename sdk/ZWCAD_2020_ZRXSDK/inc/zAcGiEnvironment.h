

#pragma once

#include "zacgi.h"
#include "zAcGiLightTraits.h"
#pragma pack (push, 8)

#ifdef ZCGIENVIRONMENT_IMPL
#define ZCGIENV_IMPEXP __declspec(dllexport)
#else
#define ZCGIENV_IMPEXP __declspec(dllimport)
#endif

class ZcGiSolidBackgroundTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSolidBackgroundTraits);
    virtual void            setColorSolid           (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorSolid              (void) const            = 0;
};

class ZcGiGradientBackgroundTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGradientBackgroundTraits);

    virtual void            setColorTop             (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorTop                (void) const           = 0;
    virtual void            setColorMiddle          (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorMiddle             (void) const           = 0;
    virtual void            setColorBottom          (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorBottom             (void) const           = 0;
    virtual void            setHorizon              (double horizon)       = 0;
    virtual double          horizon                 (void) const           = 0;
    virtual void            setHeight               (double height)        = 0;
    virtual double          height                  (void) const           = 0;
    virtual void            setRotation             (double rotation)      = 0;
    virtual double          rotation                (void) const           = 0;
};

class ZcGiImageBackgroundTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiImageBackgroundTraits);

    virtual void            setImageFilename        (const ZTCHAR* filename) = 0;
    virtual const ZTCHAR *  imageFilename           (void) const           = 0;
    virtual void            setFitToScreen          (bool bFitToScreen)    = 0;
    virtual bool            fitToScreen             (void) const           = 0;
    virtual void            setMaintainAspectRatio  (bool bMaintainAspectRatio) = 0;
    virtual bool            maintainAspectRatio     (void) const           = 0;
    virtual void            setUseTiling            (bool bUseTiling)      = 0;
    virtual bool            useTiling               (void) const           = 0;
    virtual void            setXOffset              (double xOffset)       = 0;
    virtual double          xOffset                 (void) const           = 0;
    virtual void            setYOffset              (double yOffset)       = 0;
    virtual double          yOffset                 (void) const           = 0;
    virtual void            setXScale               (double xScale)        = 0;
    virtual double          xScale                  (void) const           = 0;
    virtual void            setYScale               (double yScale)        = 0;
    virtual double          yScale                  (void) const           = 0;
};

class ZcGiGroundPlaneBackgroundTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiGroundPlaneBackgroundTraits);

    virtual void            setColorSkyZenith       (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorSkyZenith          (void) const           = 0;
    virtual void            setColorSkyHorizon      (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorSkyHorizon         (void) const           = 0;
    virtual void            setColorUndergroundHorizon  (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorUndergroundHorizon     (void) const           = 0;
    virtual void            setColorUndergroundAzimuth  (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorUndergroundAzimuth     (void) const           = 0;
    virtual void            setColorGroundPlaneNear (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorGroundPlaneNear    (void) const           = 0;
    virtual void            setColorGroundPlaneFar  (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor colorGroundPlaneFar     (void) const           = 0;
};

class ZcGiSkyBackgroundTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiSkyBackgroundTraits);
    virtual void setSkyParameters(const ZcGiSkyParameters& params) = 0;
    virtual void skyParameters(ZcGiSkyParameters& params) const = 0;
};

class ZcGiMaterialTexture;

class ZcGiRenderEnvironmentTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiRenderEnvironmentTraits);

    virtual void            setEnable               (const bool bEnable)    = 0;
    virtual bool            enable                  (void) const            = 0;
    virtual void            setIsBackground         (const bool bEnable)    = 0;
    virtual bool            isBackground            (void) const            = 0;
    virtual void            setFogColor             (const ZcCmEntityColor & color) = 0;
    virtual ZcCmEntityColor fogColor                (void) const            = 0;
    virtual void            setNearDistance         (const double nearDist) = 0;
    virtual double          nearDistance            (void) const            = 0;
    virtual void            setFarDistance          (const double farDist)  = 0;
    virtual double          farDistance             (void) const            = 0;
    virtual void            setNearPercentage       (const double nearPct)  = 0;
    virtual double          nearPercentage          (void) const            = 0;
    virtual void            setFarPercentage        (const double farPct)   = 0;
    virtual double          farPercentage           (void) const            = 0;
    virtual void            setEnvironmentMap       (const ZcGiMaterialTexture * map) = 0;
    virtual ZcGiMaterialTexture * environmentMap    (void) const = 0;
};

class ZcGiRenderSettingsTraits : public ZcGiNonEntityTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiRenderSettingsTraits);

    virtual void setMaterialEnabled(bool enabled) = 0;
    virtual bool materialEnabled() const = 0;

    virtual void setTextureSampling(bool enabled) = 0;
    virtual bool textureSampling() const = 0;

    virtual void setBackFacesEnabled(bool enabled) = 0;
    virtual bool backFacesEnabled() const = 0;

    virtual void setShadowsEnabled(bool enabled) = 0;
    virtual bool shadowsEnabled() const = 0;

    virtual void setDiagnosticBackgroundEnabled(bool enabled) = 0;
    virtual bool diagnosticBackgroundEnabled() const = 0;
    virtual void            setModelScaleFactor     (double scaleFactor)    = 0;
    virtual double          modelScaleFactor        (void) const            = 0;
};

typedef enum {
    krBox = 0,
    krTriangle,
    krGauss,
    krMitchell,
    krLanczos
} ZcGiMrFilter;

typedef enum {
    krSimple = 0,
    krSorted,
    krSegments
} ZcGiMrShadowMode;

typedef enum {
    krOff = 0,
    krGrid,
    krPhoton,
    krSamples,
    krBSP
} ZcGiMrDiagnosticMode;

typedef enum {
    krObject = 0,
    krWorld,
    krCamera
} ZcGiMrDiagnosticGridMode;

typedef enum {
    krDensity = 0,
    krIrradiance
} ZcGiMrDiagnosticPhotonMode;

typedef enum {
    krDepth = 0,
    krSize
} ZcGiMrDiagnosticBSPMode;

typedef enum {
    krHilbert = 0,
    krSpiral,
    krLeftToRight,
    krRightToLeft,
    krTopToBottom,
    krBottomToTop
} ZcGiMrTileOrder;

typedef enum {
    krAutomatic = 0,
    krLogarithmic
} ZcGiMrExposureType;

typedef enum {
    krFinalGatherOff = 0,
    krFinalGatherOn,
    krFinalGatherAuto
} ZcGiMrFinalGatheringMode;

typedef enum {
	krExportMIOff = 0,
	krExportMIWithRender,
	krExportMIOnly,
} ZcGiMrExportMIMode;

class ZcGiMentalRayRenderSettingsTraits : public ZcGiRenderSettingsTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiMentalRayRenderSettingsTraits);

    virtual void setSampling(int min, int max) = 0;
    virtual void sampling(int& min, int& max) const = 0;

    virtual void setSamplingFilter(ZcGiMrFilter filter, double width, double height) = 0;
    virtual void SamplingFilter(ZcGiMrFilter& filter, double& width, double& height) const = 0;

    virtual void setSamplingContrastColor(float r, float g, float b, float a) = 0;
    virtual void samplingContrastColor(float& r, float& g, float& b, float& a) const = 0;

    virtual void setShadowMode(ZcGiMrShadowMode mode) = 0;
    virtual ZcGiMrShadowMode shadowMode() const = 0;

    virtual void setShadowMapEnabled(bool enabled) = 0;
    virtual bool shadowMapEnabled() const = 0;

    virtual void setRayTraceEnabled(bool enabled) = 0;
    virtual bool rayTraceEnabled() const = 0;

    virtual void setRayTraceDepth(int reflection, int refraction, int sum) = 0;
    virtual void rayTraceDepth(int& reflection, int& refraction, int& sum) const = 0;

    virtual void setGlobalIlluminationEnabled(bool enabled) = 0;
    virtual bool globalIlluminationEnabled() const = 0;

    virtual void setGISampleCount(int num) = 0;
    virtual int giSampleCount() const = 0;

    virtual void setGISampleRadiusEnabled(bool enabled) = 0;
    virtual bool giSampleRadiusEnabled() const = 0;

    virtual void setGISampleRadius(double radius) = 0;
    virtual double giSampleRadius() const = 0;

    virtual void setGIPhotonsPerLight(int num) = 0;
    virtual int giPhotonsPerLight() const = 0;

    virtual void setPhotonTraceDepth(int reflection, int refraction, int sum) = 0;
    virtual void photonTraceDepth(int& reflection, int& refraction, int& sum) const = 0;

    virtual void setFinalGatheringEnabled(bool enabled) = 0;
    virtual bool finalGatheringEnabled() const = 0;

    virtual void setFGRayCount(int num) = 0;
    virtual int fgRayCount() const = 0;

    virtual void setFGRadiusState(bool bMin, bool bMax, bool bPixels) = 0;
    virtual void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) = 0;

    virtual void setFGSampleRadius(double min, double max) = 0;
    virtual void fgSampleRadius(double& min, double& max) const = 0;

    virtual void setLightLuminanceScale(double luminance) = 0;
    virtual double lightLuminanceScale() const = 0;

    virtual void setDiagnosticMode(ZcGiMrDiagnosticMode mode) = 0;
    virtual ZcGiMrDiagnosticMode diagnosticMode() const = 0;

    virtual void setDiagnosticGridMode(ZcGiMrDiagnosticGridMode mode, float fSize) = 0;
    virtual void diagnosticGridMode(ZcGiMrDiagnosticGridMode& mode, float& fSize) const = 0;

    virtual void setDiagnosticPhotonMode(ZcGiMrDiagnosticPhotonMode mode) = 0;
    virtual ZcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const = 0;

    virtual void setDiagnosticBSPMode(ZcGiMrDiagnosticBSPMode mode) = 0;
    virtual ZcGiMrDiagnosticBSPMode diagnosticBSPMode() const = 0;

    virtual void setExportMIEnabled(bool enabled) = 0;
    virtual bool exportMIEnabled() const = 0;

    virtual void setExportMIFileName(const ZTCHAR* miName) = 0;
    virtual const ZTCHAR* exportMIFileName() const = 0;

    virtual void setTileSize(int size) = 0;
    virtual int tileSize() const = 0;

    virtual void setTileOrder(ZcGiMrTileOrder order) = 0;
    virtual ZcGiMrTileOrder tileOrder() const = 0;

    virtual void setMemoryLimit(int limit) = 0;
    virtual int memoryLimit() const = 0;

    virtual void setEnergyMultiplier(float fScale) = 0;
    virtual float energyMultiplier() const = 0;

    virtual void setProgressMonitor(void* pMonitor) = 0;
    virtual const void* progressMonitor(void) const = 0;

    virtual void setExposureType(ZcGiMrExposureType type) = 0;
    virtual ZcGiMrExposureType exposureType() const = 0;

    virtual void setFinalGatheringMode(ZcGiMrFinalGatheringMode mode) = 0;
    virtual ZcGiMrFinalGatheringMode finalGatheringMode() const = 0;

    virtual void setShadowSamplingMultiplier(double multiplier) = 0;
    virtual double shadowSamplingMultiplier() const = 0;

	virtual void setExportMIMode(ZcGiMrExportMIMode mode) = 0;
	virtual ZcGiMrExportMIMode exportMIMode() const = 0;
};

class ZcGiToneOperatorParameters : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiToneOperatorParameters);

    ZcGiToneOperatorParameters();
    virtual ~ZcGiToneOperatorParameters();

	ZcGiToneOperatorParameters& operator=(const ZcGiToneOperatorParameters& params);
    bool operator==(const ZcGiToneOperatorParameters& params) const;
    virtual void setIsActive(bool active);
    virtual bool isActive() const;
    virtual void setChromaticAdaptation(bool enable);
    virtual bool chromaticAdaptation() const;
    virtual void setColorDifferentiation(bool enable);
    virtual bool colorDifferentiation() const;
    virtual void setWhiteColor(const ZcCmColor& color);
    virtual ZcCmColor whiteColor() const;
    virtual void setProcessBackground(bool processBG);
    virtual bool processBackground() const;
    virtual bool setBrightness(double brightness);
    virtual double brightness() const;
    virtual bool setContrast(double contrast);
    virtual double contrast() const;
    virtual bool setMidTones(double midTones);
    virtual double midTones() const;
    enum ExteriorDaylightMode {
        kDaylightOff = 0,
        kDaylightOn,
        kDaylightAuto
    };
    virtual bool setExteriorDaylight(ExteriorDaylightMode mode);
    virtual ExteriorDaylightMode exteriorDaylight() const;
	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

private:
    bool                    mbIsActive;
    bool                    mbChromaticAdaptation;
    bool                    mbColorDifferentiation;
    ZcCmColor               mWhiteColor;
    bool                    mbProcessBackground;
    double                  mBrightness;
    double                  mContrast;
    double                  mMidTones;
    ExteriorDaylightMode    mExteriorDaylight;
};

#pragma pack (pop)
