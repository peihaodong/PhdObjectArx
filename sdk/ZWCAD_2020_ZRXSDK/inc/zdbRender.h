
#pragma once

#include "zAcGiEnvironment.h"

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP
#endif

class ZcDbImpRenderSettings;
class ZcDbImpRenderEnvironment;
class ZcDbImpRenderGlobal;
class ZcDbImpMentalRayRenderSettings;

class SCENEDLLIMPEXP ZcDbRenderSettings : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbRenderSettings);
    ZcDbRenderSettings();
    virtual ~ZcDbRenderSettings();

    virtual ZcGiDrawable* drawable();
    Zcad::ErrorStatus setName(const ZcString& strName);
    ZcString name() const;
    void setDescription(const ZcString& strDes);
    ZcString description() const;
    void setDisplayIndex(int idx);
    int displayIndex() const;
    void setMaterialsEnabled(bool bEnabled);
    bool materialsEnabled() const;
    void setTextureSampling(bool bSampling);
    bool textureSampling() const;
    void setBackFacesEnabled(bool bEnabled);
    bool backFacesEnabled() const;
    void setShadowsEnabled(bool bEnabled);
    bool shadowsEnabled() const;
    Zcad::ErrorStatus setPreviewImageFileName(const ZcString& strFileName);
    ZcString previewImageFileName() const;
    void setDiagnosticBackgroundEnabled(bool bEnabled);
    bool diagnosticBackgroundEnabled() const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* other);
    virtual ZSoft::UInt32 setAttributes(ZcGiDrawableTraits* pTraits);

	virtual bool operator==(const ZcDbRenderSettings& settings);

private:
    ZcDbImpRenderSettings* mpImp;
};

class SCENEDLLIMPEXP ZcDbMentalRayRenderSettings : public ZcDbRenderSettings
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbMentalRayRenderSettings);
    ZcDbMentalRayRenderSettings();
    virtual ~ZcDbMentalRayRenderSettings();
    Zcad::ErrorStatus setSampling(int iMin, int iMax);
    void sampling(int& iMin, int& iMax) const;
    Zcad::ErrorStatus setSamplingFilter(ZcGiMrFilter eFilter, double fWidth,
        double fHeight);
    void SamplingFilter(ZcGiMrFilter& eFilter, double& fWidth, double& fHeight)
        const;
    Zcad::ErrorStatus setSamplingContrastColor(float r, float g, float b,
        float a);
    void samplingContrastColor(float& r, float& g, float& b, float& a) const;
    void setShadowMode(ZcGiMrShadowMode eShadowMode);
    ZcGiMrShadowMode shadowMode() const;
    void setShadowMapsEnabled(bool bEnabled);
    bool shadowMapsEnabled() const;
    void setRayTracingEnabled(bool bEnabled);
    bool rayTracingEnabled() const;
    Zcad::ErrorStatus setRayTraceDepth(int iReflection, int iRefraction,
        int iSum);
    void rayTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;
    void setGlobalIlluminationEnabled(bool bEnabled);
    bool globalIlluminationEnabled() const;
    Zcad::ErrorStatus setGISampleCount(int iNum);
    int giSampleCount() const;
    void setGISampleRadiusEnabled(bool bEnabled);
    bool giSampleRadiusEnabled() const;
    Zcad::ErrorStatus setGISampleRadius(double fRadius);
    double giSampleRadius() const;
    Zcad::ErrorStatus setGIPhotonsPerLight(int iNum);
    int giPhotonsPerLight() const;
    Zcad::ErrorStatus setPhotonTraceDepth(int iReflection, int iRefraction,
        int iSum);
    void photonTraceDepth(int& iReflection, int& iRefraction, int& iSum) const;
    void setFinalGatheringEnabled(bool bEnabled);
    bool finalGatheringEnabled() const;
    Zcad::ErrorStatus setFinalGatheringMode(ZcGiMrFinalGatheringMode mode);
    ZcGiMrFinalGatheringMode finalGatheringMode() const;
    Zcad::ErrorStatus setFGRayCount(int iNum);
    int fgRayCount() const;
    void setFGRadiusState(bool bMin, bool bMax, bool bPixels);
    void fgSampleRadiusState(bool& bMin, bool& bMax, bool& bPixels) const;
    Zcad::ErrorStatus setFGSampleRadius(double fMin, double fMax);
    void fgSampleRadius(double& fMin, double& fMax) const;
    Zcad::ErrorStatus setLightLuminanceScale(double fLuminance);
    double lightLuminanceScale() const;
    Zcad::ErrorStatus setEnergyMultiplier(float fScale);
    float energyMultiplier() const;
    void setDiagnosticMode(ZcGiMrDiagnosticMode eDiagnosticMode);
    ZcGiMrDiagnosticMode diagnosticMode() const;
    Zcad::ErrorStatus setDiagnosticGridMode(
        ZcGiMrDiagnosticGridMode eDiagnosticGridMode, float fSize);
    void diagnosticGridMode(
        ZcGiMrDiagnosticGridMode& eDiagnosticGridMode, float& fSize) const;
    void setDiagnosticPhotonMode(
        ZcGiMrDiagnosticPhotonMode eDiagnosticPhotonMode);
    ZcGiMrDiagnosticPhotonMode diagnosticPhotonMode() const;
    void setDiagnosticSamplesMode(bool bDiagnosticSamplesMode);
    bool diagnosticSamplesMode() const;
    void setDiagnosticBSPMode(ZcGiMrDiagnosticBSPMode eDiagnosticBSPMode);
    ZcGiMrDiagnosticBSPMode diagnosticBSPMode() const;
    void setExportMIEnabled(bool bEnabled);
    bool exportMIEnabled() const;
    Zcad::ErrorStatus setExportMIFileName(const ZcString& strFileName);
    ZcString exportMIFileName() const;
    Zcad::ErrorStatus setTileSize(int iTileSize);
    int tileSize() const;
    void setTileOrder(ZcGiMrTileOrder eTileOrder);
    ZcGiMrTileOrder tileOrder() const;
    Zcad::ErrorStatus setMemoryLimit(int iMemoryLimit);
    int memoryLimit() const;
    enum ShadowSamplingMultiplier {
        kSamplingMultiplierZero = 0,
        kSamplingMultiplierOneEighth,
        kSamplingMultiplierOneFourth,
        kSamplingMultiplierOneHalf,
        kSamplingMultiplierOne,
        kSamplingMultiplierTwo
    };
    Zcad::ErrorStatus setShadowSamplingMultiplier(
        ZcDbMentalRayRenderSettings::ShadowSamplingMultiplier multiplier);
    ZcDbMentalRayRenderSettings::ShadowSamplingMultiplier shadowSamplingMultiplier() const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual ZSoft::UInt32 setAttributes(ZcGiDrawableTraits* pTraits);

	virtual bool operator==(const ZcDbMentalRayRenderSettings& settings);

	Zcad::ErrorStatus copyFrom(const ZcRxObject* other);

private:
	ZcDbImpMentalRayRenderSettings* mpImpMentalRay;
};

class SCENEDLLIMPEXP ZcDbRenderEnvironment : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbRenderEnvironment);
    ZcDbRenderEnvironment();
    virtual ~ZcDbRenderEnvironment();

    virtual ZcGiDrawable* drawable();
    void setFogEnabled(bool bEnable);
    bool fogEnabled() const;
    void setFogBackgroundEnabled(bool bEnable);
    bool fogBackgroundEnabled() const;
    void setFogColor(const ZcCmEntityColor& color);
    ZcCmEntityColor fogColor() const;
    Zcad::ErrorStatus setFogDensity(double dNear, double dFar);
    void fogDensity(double& dNear, double& dFar) const;
    Zcad::ErrorStatus setDistances(double dNear, double dFar);
    void distances(double& dNear, double& dFar) const;
    void setEnvironmentImageEnabled(bool bEnabled);
    bool environmentImageEnabled() const;
    Zcad::ErrorStatus setEnvironmentImageFileName(const ZcString& strFileName);
    ZcString environmentImageFileName() const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual ZSoft::UInt32 setAttributes(ZcGiDrawableTraits* pTraits);

	virtual bool operator==(const ZcDbRenderEnvironment& environment);

private:
    ZcDbImpRenderEnvironment* mpImp;
};

class SCENEDLLIMPEXP ZcDbRenderGlobal : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbRenderGlobal);
    enum Procedure
    {
        krView = 0,
        krCrop,
        krSelected
    };
    enum Destination
    {
        krWindow = 0,
        krViewport
    };
    ZcDbRenderGlobal();
    virtual ~ZcDbRenderGlobal();
    void setProcedureAndDestination(Procedure eProcedure,
        Destination eDestination);
    void procedureAndDestination(Procedure& eProcedure,
        Destination& eDestination) const;
    void setSaveEnabled(bool bEnabled);
    bool saveEnabled() const;
    Zcad::ErrorStatus setSaveFileName(const ZcString& strFileName);
    ZcString saveFileName() const;
    Zcad::ErrorStatus setDimensions(int w, int h);
    void dimensions(int& w, int& h) const;
    void setPredefinedPresetsFirst(bool bPredefinedPresetsFirst);
    bool predefinedPresetsFirst() const;
    void setHighInfoLevel(bool bHighInfoLevel);
    bool highInfoLevel() const;
    Zcad::ErrorStatus setExposureType(ZcGiMrExposureType type);
    ZcGiMrExposureType exposureType() const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    Zcad::ErrorStatus copyFrom( const ZcRxObject* other );

private:
    ZcDbImpRenderGlobal* mpImp;
public:
	bool operator==(const ZcDbRenderGlobal& global);
	ZcString dimensionName() const;
};

