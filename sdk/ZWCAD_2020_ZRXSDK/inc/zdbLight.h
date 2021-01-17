
#pragma once

#include "zdbmain.h"
#include "zdbents.h"

#pragma warning( disable: 4275 4251 )

#ifdef SCENEOE
#define LIGHTDLLIMPEXP __declspec(dllexport)
#else
#define LIGHTDLLIMPEXP
#endif

#include "zdbgrip.h"
#include "zAcGiLightTraits.h"

class ZcDbImpLight;

class LIGHTDLLIMPEXP ZcDbLight : public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbLight);

private:
    static ZSoft::UInt32 kCurrentVersionNumber ;
public:
    ZcDbLight ();
    ~ZcDbLight();

    virtual Zcad::ErrorStatus subClose();
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler *pFiler) const ;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler) ;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &   geomIds) const;

    virtual Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &   geomIds,
                                 const ZcGeMatrix3d& insertionMat) const;

    virtual Zcad::ErrorStatus getGripPoints (ZcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize, const ZcGeVector3d &curViewDir, const int bitflags) const ;
    virtual Zcad::ErrorStatus moveGripPointsAt (const ZcDbVoidPtrArray &gripAppData, const ZcGeVector3d &offset, const int bitflags) ;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const ;

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d & xform,ZcDbEntity *& pEnt) const;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus highlight(const ZcDbFullSubentPath& subId,
        const ZSoft::Boolean highlightAll) const;

    virtual Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath& subId,
        const ZSoft::Boolean highlightAll) const;
    virtual void list() const;

    virtual Zcad::ErrorStatus decomposeForSave(
            ZcDb::ZcDbDwgVersion ver,
            ZcDbObject*& replaceObj,
            ZcDbObjectId& replaceId,
            ZSoft::Boolean& exchangeXData);
    virtual void viewportDraw (ZcGiViewportDraw *mode) ;
    virtual ZSoft::Boolean worldDraw (ZcGiWorldDraw *mode) ;
    virtual ZSoft::UInt32  setAttributes(ZcGiDrawableTraits* pTraits);
    virtual ZcGiDrawable::DrawableType    drawableType() const;
    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);


    virtual Zcad::ErrorStatus deepClone(ZcDbObject* pOwner,ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap,ZSoft::Boolean isPrimary = true) const;

    virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary ) const;

    virtual Zcad::ErrorStatus copyFrom (const ZcRxObject* other);
    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual const ZcString& name() const;
    virtual Zcad::ErrorStatus setName(const ZcString & name);
    virtual ZcGiDrawable::DrawableType lightType() const;
    virtual Zcad::ErrorStatus setLightType(ZcGiDrawable::DrawableType type);
    virtual  bool isOn() const;
    virtual Zcad::ErrorStatus setOn(bool value);
    virtual bool isPlottable() const;
    virtual Zcad::ErrorStatus setIsPlottable(bool plot);
    virtual const ZcCmColor& lightColor() const;
    virtual Zcad::ErrorStatus setLightColor(const ZcCmColor& color);
    virtual double intensity() const;
    virtual Zcad::ErrorStatus setIntensity(double intensity);
    virtual void setLightAttenuation(const ZcGiLightAttenuation& params);
    virtual const ZcGiLightAttenuation& lightAttenuation() const;
    virtual Zcad::ErrorStatus setPosition(const ZcGePoint3d& pos);
    virtual const ZcGePoint3d& position() const;
    virtual const ZcGePoint3d& targetLocation() const;
    virtual Zcad::ErrorStatus setTargetLocation(const ZcGePoint3d& newVal);
    virtual Zcad::ErrorStatus setHotspotAndFalloff(double hotspot, double falloff);
    virtual double hotspotAngle() const;
    virtual double falloffAngle() const;
    virtual const ZcGeVector3d& lightDirection() const;
    virtual Zcad::ErrorStatus setLightDirection(const ZcGeVector3d& lightvec);

    enum PhysicalIntensityMethod {
        kPeakIntensity = 0,
        kFlux,
        kIlluminance
    };

    ZcDbLight::PhysicalIntensityMethod physicalIntensityMethod() const;
    Zcad::ErrorStatus setPhysicalIntensityMethod(ZcDbLight::PhysicalIntensityMethod method);
    double physicalIntensity() const;
    Zcad::ErrorStatus setPhysicalIntensity(double physicalIntensity);
    double illuminanceDistance() const;
    Zcad::ErrorStatus setIlluminanceDistance(double distance);

    enum LampColorType {
        kKelvin = 0,
        kPreset
    };

    ZcDbLight::LampColorType lampColorType() const;
    Zcad::ErrorStatus setLampColorType(ZcDbLight::LampColorType colorType);
    double lampColorTemp() const;
    Zcad::ErrorStatus setLampColorTemp(double colorTemp);

    enum LampColorPreset {
        kD65White = 0,
        kFluorescent,
        kCoolWhite,
        kWhiteFluorescent,
        kDaylightFluorescent,
        kIncandescent,
        kXenon,
        kHalogen,
        kQuartz,
        kMetalHalide,
        kMercury,
        kPhosphorMercury,
        kHighPressureSodium,
        kLowPressureSodium,
        kCustom
    };

    ZcDbLight::LampColorPreset lampColorPreset() const;
    Zcad::ErrorStatus setLampColorPreset(ZcDbLight::LampColorPreset colorPreset);
    Zcad::ErrorStatus lampColorRGB(ZcGiColorRGB& rgbColor) const;
    Zcad::ErrorStatus setLampColorRGB(ZcGiColorRGB rgbColor);
    Zcad::ErrorStatus resultingColor(ZcCmColor& rgbColor) const;
    Zcad::ErrorStatus webFile(ZcString& webFile) const;
    Zcad::ErrorStatus setWebFile(const ZTCHAR* webFile);
    Zcad::ErrorStatus webRotation(ZcGeVector3d& rotation) const;
    Zcad::ErrorStatus setWebRotation(ZcGeVector3d rotation);
    bool hasTarget() const;
    Zcad::ErrorStatus setHasTarget(bool hasTarget);
    Zcad::ErrorStatus shadowParameters(ZcGiShadowParameters& params) const;
    Zcad::ErrorStatus setShadowParameters(const ZcGiShadowParameters& params);

private:
    friend class ZcDbImpLight;
    ZcDbImpLight * mpZcDbImpLight;
    bool mSelected;
};
