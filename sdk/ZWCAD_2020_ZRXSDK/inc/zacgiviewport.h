
#pragma once

#include "zAcGiEnvironment.h"

class ZcGiViewportTraits : public ZcGiDrawableTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiViewportTraits);

    virtual void setBackground(const ZcDbObjectId backgroundId) = 0;
    virtual ZcDbObjectId        background () const = 0;

    enum DefaultLightingType {
        kOneDistantLight = 0,
        kTwoDistantLights,
        kBackLighting,
    };
    virtual bool isDefaultLightingOn() const = 0;
    virtual void setDefaultLightingOn(bool on) = 0;
    virtual DefaultLightingType defaultLightingType() const = 0;
    virtual void setDefaultLightingType(DefaultLightingType typ) = 0;

    virtual void setAmbientLightColor(const ZcCmColor& clr) = 0;
    virtual ZcCmColor ambientLightColor() const = 0;

    virtual void setBrightness (double brightness) = 0;
    virtual double brightness() const = 0;

    virtual void setContrast (double contrast) = 0;
    virtual double contrast() const = 0;

    virtual void setRenderEnvironment (const ZcDbObjectId renderEnvId) = 0;
    virtual ZcDbObjectId renderEnvironment () const = 0;

    virtual void setRenderSettings (const ZcDbObjectId renderSettingsId) = 0;
    virtual ZcDbObjectId renderSettings () const = 0;
    virtual void setToneOperatorParameters(const ZcGiToneOperatorParameters& params) = 0;
    virtual void toneOperatorParameters(ZcGiToneOperatorParameters& params) const = 0;
};
