

#ifndef __ZIMGVARS_H
#define __ZIMGVARS_H

#include "zdbmain.h"
#include "zimgdef.h"

#pragma pack (push, 8)

class ZcDbImpRasterVariables;

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

class ISMDLLACCESS ZcDbRasterVariables : public ZcDbObject
{
public:

    static ClassVersion        classVersion();

	ZCRX_DECLARE_MEMBERS(ZcDbRasterVariables);

	enum FrameSettings {
		kImageFrameInvalid = -1,
		kImageFrameOff   = 0,
		kImageFrameAbove = 1,
        kImageFrameBelow    =  2,
        kImageFrameOnNoPlot =  3
	};

	enum ImageQuality {
		kImageQualityInvalid = -1,
		kImageQualityDraft = 0,
		kImageQualityHigh  = 1
	};

    static ZcDbRasterVariables* create(); 
								ZcDbRasterVariables();
	virtual						~ZcDbRasterVariables();

    virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const;

	virtual FrameSettings		imageFrame() const;
	virtual Zcad::ErrorStatus	setImageFrame( FrameSettings value );

	virtual ImageQuality		imageQuality() const;
	virtual Zcad::ErrorStatus	setImageQuality( ImageQuality value );

    virtual ZcDbRasterImageDef::Units userScale() const;
	virtual Zcad::ErrorStatus	setUserScale(
									ZcDbRasterImageDef::Units units );

	static ZcDbRasterVariables*	openRasterVariables(
									ZcDb::OpenMode mode,
									ZcDbDatabase* pDatabase = 0
								);

private:

#ifdef MEM_DEBUG
#undef new
#undef delete
#endif
    void *operator new[](size_t nSize)throw() { return 0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line)throw() { return 0;}
#ifdef MEM_DEBUG
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

    ZcDbImpRasterVariables*		mpImp;
    static ClassVersion         mVersion;
};

inline ClassVersion
ZcDbRasterVariables::classVersion()
{   return mVersion; }

#pragma warning( default : 4275 ) 

#pragma pack (pop)
#endif  
