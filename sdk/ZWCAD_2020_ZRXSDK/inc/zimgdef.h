

#ifndef __ZIMGDEF_H
#define __ZIMGDEF_H    1

#include "zdbmain.h"
#include "zacgi.h"
#include "zgept2dar.h"
#include "zgemat2d.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

class  RasterImageDefImp;                
class  ZcDbImpRasterImageDefReactor;     
namespace Ztil
{
    class  Image;
    class  FileReadDescriptor;
};

enum ClassVersion
{
    kVersion1   = 0,    
    kVersion2   = 1,    
    kVersion3   = 2     
};

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

class IZcReadStream;
class ISMDLLACCESS ZcDbRasterImageDef : public ZcDbObject 
{
public:

    static ClassVersion         classVersion();

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDef);

			                    ZcDbRasterImageDef();
    virtual						~ZcDbRasterImageDef();

    RasterImageDefImp*          ptrImp() const;
	RasterImageDefImp*          setPtrImp(RasterImageDefImp* pImp);

    virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing);
	virtual Zcad::ErrorStatus	subClose();

    virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const;

	virtual ZcGiSentScanLines*	makeScanLines(	
                                    const ZcGiRequestScanLines* pReq,
									const ZcGeMatrix2d& pixToScreen,
									ZcGePoint2dArray* pActiveClipBndy = 0,     
                                    ZSoft::Boolean draftQuality = false,
                                    ZSoft::Boolean isTransparent = false,
                                    const double brightness = 50.0,
                                    const double contrast = 50.0,
                                    const double fade = 0.0
                                ) const;

	virtual Zcad::ErrorStatus	setSourceFileName(const ZTCHAR* pPathName);
	virtual Zcad::ErrorStatus	setActiveFileName(const ZTCHAR* pPathName);
    virtual const ZTCHAR *       searchForActivePath();

    virtual const ZTCHAR *       sourceFileName() const;
    virtual const ZTCHAR *       activeFileName() const;

	virtual Zcad::ErrorStatus	embed();
	virtual ZSoft::Boolean		isEmbedded() const;

	virtual Zcad::ErrorStatus   load();
	virtual Zcad::ErrorStatus   unload(ZSoft::Boolean modifyDatabase = true);
    virtual ZSoft::Boolean		isLoaded() const;

	virtual ZcGeVector2d		size() const;

    virtual ZcGiImageOrg        organization() const;
    virtual int                 colorDepth() const;

    virtual const ZTCHAR *       fileType() const;
	virtual int					entityCount(
									ZSoft::Boolean* pbLocked = 0
								) const;
	virtual void				updateEntities() const;

	enum Units 
	{			
		kNone			= 0,
		kMillimeter		= 1,
		kCentimeter		= 2,
		kMeter			= 3,
		kKilometer		= 4,
		kInch			= 5,
		kFoot			= 6,
		kYard			= 7,
		kMile			= 8,
        kMicroinches    = 9,
        kMils           = 10,
        kAngstroms      = 11,
        kNanometers     = 12,
        kMicrons        = 13,
        kDecimeters     = 14,
        kDekameters     = 15,
        kHectometers    = 16,
        kGigameters     = 17,
        kAstronomical   = 18,
        kLightYears     = 19,
        kParsecs        = 20
	};

    virtual Zcad::ErrorStatus   setResolutionMMPerPixel(
                                    const ZcGeVector2d& resMMPerPixel);
	virtual ZcGeVector2d		resolutionMMPerPixel() const;
    virtual void                setResolutionUnits(
                                    ZcDbRasterImageDef::Units units);
	virtual Units				resolutionUnits() const;

	virtual Zcad::ErrorStatus	loadThumbnail(
									ZSoft::UInt16& maxWidth,
									ZSoft::UInt16& maxHeight,
									ZSoft::UInt8* pPalette = 0,
									int nPaletteEntries = 0
								);
	virtual Zcad::ErrorStatus	unloadThumbnail();
	virtual void*				createThumbnailBitmap(
									BITMAPINFO*& pBitmapInfo,
									ZSoft::UInt8 brightness = 50,
									ZSoft::UInt8 contrast = 50,
									ZSoft::UInt8 fade = 0
								);

    virtual Ztil::Image*			    imageCopy(ZSoft::Boolean bForceImageLoad = true) const;
    virtual Ztil::FileReadDescriptor*		    fileDescCopy() const;

    virtual Zcad::ErrorStatus	openImage(Ztil::Image*& pImage);

    virtual Zcad::ErrorStatus	closeImage();

	virtual Zcad::ErrorStatus	setImage(const Ztil::Image* pImage, 
                                    const Ztil::FileReadDescriptor* pFileDesc, 
                                    ZSoft::Boolean modifyDatabase = true);

    virtual Zcad::ErrorStatus	setUndoStoreSize(
					                unsigned int maxImages = 10
				                );
    virtual unsigned int		undoStoreSize() const;

    virtual ZSoft::Boolean       imageModified() const;
    virtual Zcad::ErrorStatus    setImageModified(ZSoft::Boolean modified);

	virtual IZcReadStream*      getReadStream();

    static Zcad::ErrorStatus     createImageDictionary(ZcDbDatabase* pDb, ZcDbObjectId& dictId);
    static ZcDbObjectId          imageDictionary(ZcDbDatabase* pDb);

    enum { kMaxSuggestNameSize = 2049 };
    static Zcad::ErrorStatus     suggestName(
                                     ZcDbDictionary* pImageDictionary, 
                                        const ZTCHAR* pNewImagePathName, 
                                        ZTCHAR* newImageName
                                 );
	static Zcad::ErrorStatus     suggestName(
                                     ZcDbDictionary* pImageDictionary, 
                                        const ZTCHAR* pNewImagePathName, 
                                        ZTCHAR* newImageName, 
                                        size_t nSize
                                 );
	
private:

#ifdef MEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize) { return (void*)0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line) { return (void*)0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

	RasterImageDefImp*		     mpImp;
    static ClassVersion          mVersion;
};

inline RasterImageDefImp*
ZcDbRasterImageDef::ptrImp() const
{
    return mpImp;
}

inline RasterImageDefImp*             
ZcDbRasterImageDef::setPtrImp(RasterImageDefImp* pImp)
{
	RasterImageDefImp* oldImp=mpImp;
	mpImp=pImp;
	return oldImp;
}

class ISMDLLACCESS ZcDbRasterImageDefReactor : public ZcDbObject 
{
public:

    static ClassVersion         classVersion();

    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefReactor);

								ZcDbRasterImageDefReactor();
    virtual					    ~ZcDbRasterImageDefReactor();

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual void				erased(const ZcDbObject* dbObj,
									ZSoft::Boolean pErasing = true
								);
	virtual void				modified(const ZcDbObject* dbObj);

    enum DeleteImageEvent
    {
        kUnload     = 1,
        kErase      = 2,
    };

    virtual ZSoft::Boolean      onDeleteImage(
                                    const ZcDbRasterImageDef* pImageDef, 
                                    Ztil::Image* pImage,
                                    DeleteImageEvent event,
                                    ZSoft::Boolean cancelAllowed);

	static void					setEnable(ZSoft::Boolean enable);

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

    ZcDbImpRasterImageDefReactor*	mpImp;
    static ClassVersion             mVersion;
};

class ISMDLLACCESS ZcDbRasterImageDefTransReactor : public ZcDbObjectReactor 
{
public:
	
    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefTransReactor);

    virtual						~ZcDbRasterImageDefTransReactor();

    virtual ZSoft::Boolean      onDeleteImage(const ZcDbRasterImageDef* pImageDef, 
                                          Ztil::Image* pImage,
										  ZcDbRasterImageDefReactor::DeleteImageEvent event,
                                          ZSoft::Boolean cancelAllowed) = 0;

};

class ISMDLLACCESS ZcDbRasterImageDefFileAccessReactor : public ZcDbObjectReactor 
{
public:
	
    ZCRX_DECLARE_MEMBERS(ZcDbRasterImageDefFileAccessReactor);

    virtual						~ZcDbRasterImageDefFileAccessReactor();

    virtual void                onAttach(
                                    const ZcDbRasterImageDef*, 
                                    const ZTCHAR * pPath) = 0;
    virtual void                onDetach(
                                    const ZcDbRasterImageDef*, 
                                    const ZTCHAR * pPath) = 0;
    virtual ZSoft::Boolean      onOpen(
                                    const ZcDbRasterImageDef*,
                                    const ZTCHAR * pPath, 
                                    const ZTCHAR * pActivePath,
                                    ZSoft::Boolean& replacePath,
                                    ZTCHAR *& replacementPath) = 0;
    virtual ZSoft::Boolean      onPathChange(
                                    const ZcDbRasterImageDef*,
                                    const ZTCHAR * pPath, 
                                    const ZTCHAR * pActivePath,
                                    ZSoft::Boolean& replacePath,
                                    ZTCHAR *& replacementPath) = 0;
    virtual void                onClose(
                                    const ZcDbRasterImageDef*,
                                    const ZTCHAR * pPath) = 0;

    virtual void                onDialog(
                                     ZcDbRasterImageDef*,
                                     const ZTCHAR * pCaption, 
                                     const ZTCHAR * pFileExtensions
                                 ) = 0;
};

inline ClassVersion
ZcDbRasterImageDef::classVersion()
{   return mVersion; }

inline ClassVersion
ZcDbRasterImageDefReactor::classVersion()
{   return mVersion; }

#pragma warning( default : 4275 ) 

#pragma pack (pop)
#endif 
