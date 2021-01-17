

#ifndef __ZIMGENT_H
#define __ZIMGENT_H

#include "zdbents.h"
#include "zdbimage.h"
#include "zacgi.h"
#include "zgept3dar.h"
#include "zgebndpln.h"
#include "zgeplin2d.h"
#include "zdbproxy.h"
#pragma pack (push, 8)

const double kEpsilon = 1.0e-7;

const int kAllEntityProxyFlags =
    ZcDbProxyEntity::kEraseAllowed         |
    ZcDbProxyEntity::kTransformAllowed     |
    ZcDbProxyEntity::kColorChangeAllowed         |
    ZcDbProxyEntity::kLayerChangeAllowed         |
    ZcDbProxyEntity::kLinetypeChangeAllowed      |
    ZcDbProxyEntity::kMaterialChangeAllowed      |
    ZcDbProxyEntity::kLinetypeScaleChangeAllowed |
    ZcDbProxyEntity::kVisibilityChangeAllowed;

class RasterImageImp;

#pragma warning( disable : 4275 ) 

#ifdef ISMDLLACCESS
#undef ISMDLLACCESS
#endif
#ifdef ISMDLLACCESSDATA
#undef ISMDLLACCESSDATA
#endif
#ifdef ISM_OBJ 

#define ISMDLLACCESS __declspec(dllexport)
#define ISMDLLACCESSDATA
#else
#define ISMDLLACCESS 
#define ISMDLLACCESSDATA __declspec(dllimport)
#endif

class ISMDLLACCESS ZcDbRasterImage : public ZcDbImage 
{
public:

    static ClassVersion         classVersion();

	ZCRX_DECLARE_MEMBERS(ZcDbRasterImage);

    		                    ZcDbRasterImage();
    virtual                     ~ZcDbRasterImage();

    RasterImageImp*             ptrImp() const;
    RasterImageImp*             setPtrImp(RasterImageImp* pImp);

    virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual Zcad::ErrorStatus   subSwapIdWith(
                                    ZcDbObjectId otherId,
                                    ZSoft::Boolean swapXdata = ZSoft::kFalse,
                                    ZSoft::Boolean swapExtDict = ZSoft::kFalse
                                );

    virtual ZSoft::Boolean      worldDraw(ZcGiWorldDraw* mode);
    virtual void		        viewportDraw(ZcGiViewportDraw* mode);

    virtual void				list() const;
    virtual Zcad::ErrorStatus	getOsnapPoints(
								        ZcDb::OsnapMode 	osnapMode,
                                        ZSoft::GsMarker     gsSelectionMark,
                                        const ZcGePoint3d&  pickPoint,
                                        const ZcGePoint3d&  lastPoint,
                                        const ZcGeMatrix3d& viewXform,
                                        ZcGePoint3dArray&   snapPoints,
                                        ZcDbIntArray &   geomIds
                                ) const;
    virtual Zcad::ErrorStatus   getGripPoints(
                                        ZcGePoint3dArray&   gripPoints,
                                        ZcDbIntArray&       osnapModes,
                                        ZcDbIntArray &   geomIds
                                ) const;
    virtual Zcad::ErrorStatus   moveGripPointsAt(
                                        const ZcDbIntArray& indices,
                                        const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus   getStretchPoints(
                                    ZcGePoint3dArray&  stretchPoints
                                ) const;
    virtual Zcad::ErrorStatus   moveStretchPointsAt(
                                        const ZcDbIntArray& indices,
                                        const ZcGeVector3d& offset
                                );
    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   getTransformedCopy(
                                    const ZcGeMatrix3d& xform,
                                        ZcDbEntity*& ent
                                ) const;
    virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus   getSubentPathsAtGsMarker(
                                    ZcDb::SubentType      type,
                                    ZSoft::GsMarker       gsMark,
                                    const ZcGePoint3d&    pickPoint,
                                    const ZcGeMatrix3d&   viewXform,
                                    int&                  numPaths,
                                    ZcDbFullSubentPath*&  subentPaths,
                                    int                   numInserts = 0,
                                    ZcDbObjectId*         entAndInsertStack = 0
                                ) const;
    virtual Zcad::ErrorStatus   getGsMarkersAtSubentPath(
                                    const ZcDbFullSubentPath& subPath,
                                    ZcArray<ZSoft::GsMarker>& gsMarkers
                                ) const;
    virtual ZcDbEntity*         subentPtr(const ZcDbFullSubentPath& id) const;
    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);
    virtual Zcad::ErrorStatus   intersectWith(
                                    const ZcDbEntity*   ent,
                                    ZcDb::Intersect     intType,
                                    ZcGePoint3dArray&   points,
                                    ZSoft::GsMarker     thisGsMarker  = 0,
                                    ZSoft::GsMarker     otherGsMarker = 0
                                ) const;

    virtual Zcad::ErrorStatus   intersectWith(
                                    const ZcDbEntity*   ent,
                                    ZcDb::Intersect     intType,
                                    const ZcGePlane&    projPlane,
                                    ZcGePoint3dArray&   points,
                                    ZSoft::GsMarker     thisGsMarker  = 0,
                                    ZSoft::GsMarker     otherGsMarker = 0
                                ) const;

    virtual bool                castShadows() const;
    virtual void                setCastShadows(bool newVal);
    virtual bool                receiveShadows() const;
    virtual void                setReceiveShadows(bool newVal);
    virtual ZcGiSentScanLines*  getScanLines(
                                    const ZcGiRequestScanLines& req
                                ) const;
    virtual ZSoft::Boolean      freeScanLines(
                                    ZcGiSentScanLines* pSSL
                                ) const;

    virtual Zcad::ErrorStatus   setImageDefId(ZcDbObjectId imageId);
    virtual ZcDbObjectId        imageDefId() const;

    virtual void                setReactorId(ZcDbObjectId reactorId);
    virtual ZcDbObjectId        reactorId() const;

    virtual ZSoft::Boolean      setOrientation(
                                    const ZcGePoint3d& origin,
                                    const ZcGeVector3d& uCorner,
                                    const ZcGeVector3d& vOnPlane);
    virtual void                getOrientation(
                                    ZcGePoint3d& origin,
                                    ZcGeVector3d& u,
                                    ZcGeVector3d& v) const;

    virtual ZcGeVector2d        scale() const;
    virtual ZcGeVector2d        imageSize(ZSoft::Boolean bGetCachedValue
                                        = ZSoft::kFalse) const;

    enum ClipBoundaryType
    {
        kInvalid,
        kRect,
        kPoly
    };
#ifndef _ZSOFT_MAC_
	virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage(ZcGeVector2d& size);
	Zcad::ErrorStatus   setClipBoundaryToWholeImage()
	{
		ZcGeVector2d size(0,0);
		return setClipBoundaryToWholeImage(size);
	}
#else
    virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage(ZcGeVector2d& size );
    virtual Zcad::ErrorStatus   setClipBoundaryToWholeImage()
    {
        ZcGeVector2d size(0,0);
        return setClipBoundaryToWholeImage(size);
    }
#endif
    virtual Zcad::ErrorStatus   setClipBoundary(
                                    ClipBoundaryType type,
                                    const ZcGePoint2dArray&
                                    );
    virtual const ZcGePoint2dArray&  clipBoundary() const;
    virtual ClipBoundaryType    clipBoundaryType() const;
    ZSoft::Boolean              isClipped() const;

    virtual Zcad::ErrorStatus   getVertices(
                                    ZcGePoint3dArray& verts
                                ) const;

    virtual Zcad::ErrorStatus   getPixelToModelTransform(ZcGeMatrix3d&) const;

    enum ImageDisplayOpt
    {
        kShow                   = 1,
        kShowUnAligned          = 2,
        kClip                   = 4,
        kTransparent            = 8
    };

    virtual void                setDisplayOpt(
                                    ImageDisplayOpt option,
                                    ZSoft::Boolean bValue
                                );
    virtual ZSoft::Boolean      isSetDisplayOpt(ImageDisplayOpt option) const;

    virtual Zcad::ErrorStatus   setBrightness( ZSoft::Int8 value );
    virtual ZSoft::Int8         brightness() const;

    virtual Zcad::ErrorStatus   setContrast( ZSoft::Int8 value );
    virtual ZSoft::Int8         contrast() const;

    virtual Zcad::ErrorStatus   setFade( ZSoft::Int8 value );
    virtual ZSoft::Int8         fade() const;

	virtual ZSoft::Boolean      isClipInverted() const;
	virtual void                setClipInverted(ZSoft::Boolean newVal);

    double                      width() const;
    double                      height() const;
    Zcad::ErrorStatus           setHeight(double);
    Zcad::ErrorStatus           setWidth(double);
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

private:
#ifdef MEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize) { return 0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line) { return 0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

    RasterImageImp*			mpImp;
    static ClassVersion     mVersion;
};

inline RasterImageImp*
ZcDbRasterImage::ptrImp() const
{
    return mpImp;
}

inline RasterImageImp*             
ZcDbRasterImage::setPtrImp(RasterImageImp* pImp)
{
	RasterImageImp* oldImp=mpImp;
	mpImp=pImp;
	return oldImp;
}

inline ClassVersion
ZcDbRasterImage::classVersion()
{   return mVersion; }

inline void 
pixelToModel(
  const ZcGeMatrix3d&		pixToMod,
  const ZcGePoint2d&		pixPt,
  ZcGePoint3d&				modPt)
{

	modPt.set(pixPt.x, pixPt.y, 0);
	modPt.transformBy(pixToMod);
}

inline void 
modelToPixel(
  const ZcGeMatrix3d&		modToPix,
  const ZcGePoint3d&		modPt,
  ZcGePoint2d&				pixPt)
{

	ZcGePoint3d modelPt = modPt;
	modelPt.transformBy(modToPix);
    pixPt.set(modelPt.x, modelPt.y);
}

inline void
modelToPixel(
  const ZcGeVector3d& viewDir,
  const ZcGeMatrix3d& modToPix,
  const ZcGePlane& plane,
  const ZcGePoint3d& modPt,
  ZcGePoint2d& pixPt)
{

    ZcGePoint3d ptOnPlane = modPt.project(plane, viewDir);
    ptOnPlane.transformBy(modToPix);
    pixPt.set(ptOnPlane.x, ptOnPlane.y);
}

#pragma warning( default : 4275 ) 

#pragma pack (pop)
#endif 
