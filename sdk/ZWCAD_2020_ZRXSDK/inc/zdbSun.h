
#pragma once

#include "zdbmain.h"
#pragma warning( disable: 4275 4251 )

#ifdef SCENEOE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

#include "zAcGiLightTraits.h"
#include "zrxboiler.h"
#include "zdbLight.h"

class ZcDbImpSun;
class LIGHTDLLIMPEXP ZcDbSun : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSun);
private:
    static ZSoft::UInt32 kCurrentVersionNumber;
public:
    ZcDbSun();
    ~ZcDbSun();
    virtual ZSoft::UInt32 setAttributes(ZcGiDrawableTraits* pTraits);
    virtual ZcGiDrawable* drawable();
    virtual DrawableType  drawableType() const { return ZcGiDrawable::kDistantLight; }
    virtual void          setGsNode(ZcGsNode* gsnode);
    virtual ZcGsNode*     gsNode() const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler *pFiler) const;

    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler *pFiler);

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler *pFiler) const;

    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler);

    virtual Zcad::ErrorStatus decomposeForSave(
            ZcDb::ZcDbDwgVersion ver,
            ZcDbObject*& replaceObj,
            ZcDbObjectId& replaceId,
            ZSoft::Boolean& exchangeXData);
    virtual bool isOn() const;
    virtual Zcad::ErrorStatus setOn(bool value);
    virtual double intensity() const;
    virtual Zcad::ErrorStatus setIntensity(double intensity);
    virtual const ZcCmColor& sunColor() const;
    virtual Zcad::ErrorStatus setSunColor(const ZcCmColor& color);
    virtual const ZcGiShadowParameters& shadowParameters() const;
    virtual void setShadowParameters(const ZcGiShadowParameters& params);
    virtual Zcad::ErrorStatus setDateTime(const ZcDbDate& datetime);
    virtual const ZcDbDate& dateTime() const;
    virtual Zcad::ErrorStatus setDayLightSavingsOn(bool value);
    virtual bool isDayLightSavingsOn() const;
    virtual Zcad::ErrorStatus setAzimuth(double azimuth);
    virtual double azimuth() const;
    virtual Zcad::ErrorStatus setAltitude(double altitude);
    virtual double altitude() const;
    virtual const ZcGeVector3d& sunDirection() const;
    virtual void setSunDirection(const ZcGeVector3d& sundir);
    Zcad::ErrorStatus setSkyParameters(const ZcGiSkyParameters& params);
    Zcad::ErrorStatus skyParameters(ZcGiSkyParameters& params) const;

private:
    ZcDbImpSun * mpZcDbImpSun;
};
