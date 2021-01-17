
#ifndef __ZDBWIPE_H__
#define __ZDBWIPE_H__

#ifdef _DBWIPEOBJ_
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif
#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
 #include "windows.h"
#endif
#include "zimgdef.h"
#include "zimgent.h"

namespace Atil
{
    class Image;
};

#define WIPEOUTOBJSERVICE	ZCRX_T("WipeOut")

#pragma warning(push)
#pragma warning( disable : 4275 )

class DLLIMPEXP ZcDbWipeout : public ZcDbRasterImage
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbWipeout);

                                ZcDbWipeout();

    virtual ZSoft::Boolean      worldDraw(ZcGiWorldDraw* mode);
    virtual void    	        viewportDraw(ZcGiViewportDraw* mode);
    virtual void				list() const;
    virtual Zcad::ErrorStatus	moveGripPointsAt(
								   const ZcDbIntArray& indices,
								   const ZcGeVector3d&     offset);
    virtual Zcad::ErrorStatus   transformBy(
                                    const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   getTransformedCopy(
                                    const ZcGeMatrix3d& xform,
						            ZcDbEntity*& ent
                                ) const;
    virtual ZcRxObject*         clone() const;
    virtual ZcGeVector2d        imageSize(ZSoft::Boolean bGetCachedValue = ZSoft::kFalse) const;
    ZcGiSentScanLines*          getScanLines(const ZcGiRequestScanLines& req) const;
	ZSoft::Boolean				isClipped() const;
	virtual void				setDisplayOpt(
                                    ImageDisplayOpt option,
                                    ZSoft::Boolean bValue
                                );
	virtual ZSoft::Boolean		isSetDisplayOpt(ImageDisplayOpt option) const;

	virtual Zcad::ErrorStatus	setBrightness( ZSoft::Int8 value );
	virtual ZSoft::Int8			brightness() const;

	virtual Zcad::ErrorStatus	setContrast( ZSoft::Int8 value );
	virtual ZSoft::Int8			contrast() const;

	virtual Zcad::ErrorStatus	setFade( ZSoft::Int8 value );
	virtual ZSoft::Int8			fade() const;

    virtual ZcGeVector2d        scale() const;
	virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    Zcad::ErrorStatus           append(ZcDbObjectId& id);
    static Zcad::ErrorStatus    createImageDefinition();
    static Zcad::ErrorStatus    fitPointsToImage(
                                    ZcGePoint2dArray& pointArray,
                                    ZcGePoint2d& minPoint,
                                    double& scale,
                                    ZSoft::Boolean bFlipY = ZSoft::kFalse);
    ZSoft::Boolean        frame() const;
    ZSoft::Boolean        setFrame(ZSoft::Boolean bFrame);

private:
    ZSoft::Boolean              isHighlighted() const;

    void                        getPlane(ZcGeBoundedPlane& boundedPlane) const;
    ZcGeMatrix2d                fastMatrixInvert(const ZcGeMatrix2d& m) const;
    void                        drawFrame(
                                    ZcGiViewportDraw* mode,
                                    const ZcGePoint3dArray& verts) const;
    Zcad::ErrorStatus           setDcToScreen(
                                    const ZcGePoint2d& lowerLeft,
                                    const ZcGePoint2d& upperRight,
                                    int width,
                                    int height,
                                    ZcGeMatrix2d& dcToScreen) const;
    void                        setFrameExtents(
                                    ZcGiWorldDraw* mode,
                                    const ZcGePoint3dArray& verts) const;

public:
    static long                 mImageData;

private:
    ZSoft::Boolean              mHighlight;

#ifdef MEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize) throw() { return 0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line) throw() { return 0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif
};

#pragma warning(pop)
#endif 
