
#ifndef ZCDB_DBUNDERLAYREF_H
#define ZCDB_DBUNDERALYREF_H
#pragma once

#include "zdbmain.h"
#include "zacstring.h"

#pragma pack (push, 8)

class ZcUnderlayLayer;

class ZSOFT_NO_VTABLE ZcDbUnderlayReference: public ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUnderlayReference);
    virtual ~ZcDbUnderlayReference() = 0;
    ZcGePoint3d       position() const;
    Zcad::ErrorStatus setPosition(const ZcGePoint3d& position);
    ZcGeScale3d       scaleFactors() const;
    Zcad::ErrorStatus setScaleFactors(const ZcGeScale3d& scale);
    double            rotation() const;
    Zcad::ErrorStatus setRotation(double rotation);
    ZcGeVector3d      normal() const;
    Zcad::ErrorStatus setNormal(const ZcGeVector3d& normal);
    ZcGeMatrix3d transform() const;
    Zcad::ErrorStatus setTransform(const ZcGeMatrix3d& transform);
    ZcDbObjectId      definitionId() const;
    Zcad::ErrorStatus setDefinitionId(ZcDbObjectId id);
    const ZcGePoint2dArray&  clipBoundary() const;
    Zcad::ErrorStatus        setClipBoundary(const ZcGePoint2dArray& clipBoundary);
	bool                     isClipped() const;
    Zcad::ErrorStatus        setIsClipped(bool value);
    ZSoft::UInt8      contrast() const;
    Zcad::ErrorStatus setContrast(ZSoft::UInt8 value);
    ZSoft::UInt8      fade() const;
    Zcad::ErrorStatus setFade(ZSoft::UInt8 value);
    bool              isOn() const;
    Zcad::ErrorStatus setIsOn(bool value);
    bool              isMonochrome() const;
    Zcad::ErrorStatus setIsMonochrome(bool value);
    bool              isAdjustedForBackground() const;
    Zcad::ErrorStatus setIsAdjustedForBackground(bool value);
    virtual bool isFrameVisible() const;
    virtual bool isFramePlottable() const;
    virtual bool isContentSnappable() const;
    ZSoft::UInt32 underlayLayerCount() const;
    Zcad::ErrorStatus getUnderlayLayer(int index, ZcUnderlayLayer& layer) const;
    Zcad::ErrorStatus setUnderlayLayer(int index, const ZcUnderlayLayer& layer);
    static ZSoft::UInt8 contrastLowerLimit();
    static ZSoft::UInt8 contrastUpperLimit();
    static ZSoft::UInt8 contrastDefault();
    static ZSoft::UInt8 fadeLowerLimit();
    static ZSoft::UInt8 fadeUpperLimit();
    static ZSoft::UInt8 fadeDefault();
	bool isClipInverted() const;
	Zcad::ErrorStatus setClipInverted(bool value);
	Zcad::ErrorStatus generateClipBoundaryFromPline(ZcDbObjectId polyId);
};

class ZcDbDwfReference: public ZcDbUnderlayReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDwfReference);
    ZcDbDwfReference();
    virtual ~ZcDbDwfReference();
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbDgnReference: public ZcDbUnderlayReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDgnReference);
    ZcDbDgnReference();
    virtual ~ZcDbDgnReference();
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    void setXrefDepth(int depth);
};

class ZcDbPdfReference: public ZcDbUnderlayReference
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbPdfReference);
	ZcDbPdfReference();
	virtual ~ZcDbPdfReference();

protected:
	virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

public:
	static ZSoft::UInt8 contrastDefault();
	static ZSoft::UInt8 fadeDefault();
};

#pragma pack (pop)

#endif
