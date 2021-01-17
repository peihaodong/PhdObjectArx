
#ifndef ZCDB_DBDWFHOST_H
#define ZCDB_DBDWFHOST_H

#include "zdbmain.h"
#include "zacstring.h"

#pragma pack (push, 8)

class ZcImpUnderlayLayer;
class IZcReadStream;
class ZcUnderlayLayer
{
public:
    ZcUnderlayLayer();
    ~ZcUnderlayLayer();

    typedef enum {
        kOff=0,
        kOn=1} State;

    ZcString name() const;
    State state() const;
    Zcad::ErrorStatus setName(const ZcString& name);
    Zcad::ErrorStatus setState(State state);

	ZcUnderlayLayer const & operator =(ZcUnderlayLayer const &);
	ZcUnderlayLayer( ZcUnderlayLayer const &);

private:
    ZcImpUnderlayLayer* m_pImpUnderlayLayer;
};

struct ZcDbUnderlayDrawContext
{

     ZSoft::UInt8 contrast;

     ZSoft::UInt8 fade;

     bool monochrome;

     bool adjustColorForBackground;

     ZcUnderlayLayer** pLayers;
};

const int kItemVersionNumber = 1;

class ZSOFT_NO_VTABLE ZcDbUnderlayItem
{
public:
    virtual ~ZcDbUnderlayItem() = 0;
    virtual ZcString getName() const = 0;
    virtual Zcad::ErrorStatus getThumbnail(
                                BITMAPINFO*& thumbnail) const = 0;
    virtual Zcad::ErrorStatus getExtents(
                                ZcGePoint2d& min,
                                ZcGePoint2d& max) const = 0;
    virtual ZcDb::UnitsValue getUnits() const = 0;
    virtual bool usingPartialContent() const = 0;
    virtual Zcad::ErrorStatus draw(
        ZcGiWorldDraw* pWorldDraw,
        ZcGiViewportDraw* pViewportDraw,
        const ZcDbUnderlayDrawContext& context) const = 0;
    virtual ZcGeMatrix3d modelTransform() const = 0;
    virtual Zcad::ErrorStatus getOsnapPoints(const ZcGeMatrix3d& modelToWorld,
                                             ZcDb::OsnapMode osnapMode,
                                             ZSoft::GsMarker   gsSelectionMark,
                                             const ZcGePoint3d&  pickPoint,
                                             const ZcGePoint3d&  lastPoint,
                                             const ZcGeMatrix3d& viewXform,
                                             ZcGePoint3dArray&      snapPoints,
                                             ZcDbIntArray &   geomIds)
                                             const = 0;
    virtual ZcDbEntity* getSubEntityAtGsMarker(const ZcGeMatrix3d& modelToWorld,ZSoft::GsMarker gsSelectionMark) const = 0;
    virtual Zcad::ErrorStatus intersectWith(const ZcGeMatrix3d& modelToWorld,
                                            const ZcDbEntity* pEnt,
                                            ZcDb::Intersect intType,
                                            const ZcGePlane* projPlane,
                                            ZcGePoint3dArray& points,
                                            ZSoft::GsMarker thisGsMarker,
                                            ZSoft::GsMarker otherGsMarker) const = 0;
    virtual ZSoft::UInt32 underlayLayerCount() const { return 0; }
    virtual Zcad::ErrorStatus getUnderlayLayer(int idx, ZcUnderlayLayer& layer) const { return Zcad::eNotImplemented; }
    int version() const;
};

class ZSOFT_NO_VTABLE ZcDbDgnUnderlayItem : public ZcDbUnderlayItem
{
public:
    virtual bool useMasterUnits() const = 0;
    virtual void setUseMasterUnits(bool bUseMasterUnits) = 0;
    virtual bool showRasterRef() const = 0;
    virtual void setShowRasterRef(bool bShow) = 0;
};

class ZSOFT_NO_VTABLE ZcDbUnderlayFile
{
public:
    virtual ~ZcDbUnderlayFile() = 0;
    virtual int getItemCount() const = 0;
    virtual Zcad::ErrorStatus getItem(
                                int i,
                                ZcDbUnderlayItem*& pItem) const = 0;
    virtual Zcad::ErrorStatus getItem(
                                const ZTCHAR* name,
                                ZcDbUnderlayItem*& pItem) const = 0;
};

class ZSOFT_NO_VTABLE ZcDbUnderlayHost
{
public:
    virtual Zcad::ErrorStatus getFile(
                                const ZTCHAR* fullPath,
                                const wchar_t* password,
                                ZcDbUnderlayFile*& pFile) const = 0;
	virtual Zcad::ErrorStatus getFile(
                                IZcReadStream* pFileStream,
                                const wchar_t* password, 
                                ZcDbUnderlayFile*& pFile) const = 0;
    static void getAdjustedColor(
                               ZcGeVector3d& rgbResult,
                               const ZcGeVector3d& rgbInputColor,
                               const ZcGeVector3d& rgbCurrentBackgroundColor,
                               const ZcGeVector3d& hslFadedContrastColor,
                               const ZcDbUnderlayDrawContext& drawContext);
protected:

    virtual ~ZcDbUnderlayHost() = 0;
};

ZCDB_PORT ZcDbUnderlayHost*
zcdbGetCurrentDwfHost();

ZCDB_PORT ZcDbUnderlayHost*
zcdbSetCurrentDwfHost(
    ZcDbUnderlayHost* pHost);

ZCDB_PORT ZcDbUnderlayHost*
zcdbGetCurrentDgnHost();

ZCDB_PORT ZcDbUnderlayHost*
zcdbSetCurrentDgnHost(
    ZcDbUnderlayHost* pHost);

ZCDB_PORT ZcDbUnderlayHost*
zcdbGetCurrentDgnDocHost();

ZCDB_PORT ZcDbUnderlayHost*
zcdbSetCurrentDgnDocHost(
    ZcDbUnderlayHost* pHost);

ZCDB_PORT void
zcdbConvertRgbToHsl(
           const ZcGeVector3d& rgb,
           ZcGeVector3d& hsl
           );

ZCDB_PORT void
zcdbConvertHslToRgb(
           const ZcGeVector3d& hsl,
           ZcGeVector3d& rgb);

#pragma pack (pop)

#endif
