

#pragma once

#include "zdbmain.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP
#endif

const ZTCHAR ZCDB_MOTIONPATH_DICTIONARY[]  = ZCRX_T("ACAD_MOTION");

Zcad::ErrorStatus SCENEDLLIMPEXP zcdbGetMotionPathDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                                            ZcDb::OpenMode mode, bool createIfNonExist);
Zcad::ErrorStatus SCENEDLLIMPEXP zcdbGetMotionPathDictionary   (ZcDbDatabase* pDb, ZcDbDictionary*& pDict,
                                                            ZcDb::OpenMode mode);

class ZcDbImpMotionPath;

class SCENEDLLIMPEXP ZcDbMotionPath : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbMotionPath);
	ZcDbMotionPath();
    virtual ~ZcDbMotionPath();

    ZcDbObjectId        cameraPath() const;
    Zcad::ErrorStatus   setCameraPath(const ZcDbObjectId& id);

    ZcDbObjectId        targetPath() const;
    Zcad::ErrorStatus   setTargetPath(const ZcDbObjectId& id);

    ZcDbObjectId        viewTableRecordId() const;
    Zcad::ErrorStatus   setViewTableRecordId(const ZcDbObjectId& id);

    ZSoft::UInt32       frames() const;
    Zcad::ErrorStatus   setFrames(ZSoft::UInt16 frames);

    ZSoft::UInt32       frameRate() const;
    Zcad::ErrorStatus   setFrameRate(ZSoft::UInt16 rate);

    bool				cornerDecel() const;
    Zcad::ErrorStatus   setCornerDecel(bool cornerDecel);
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const;
    virtual ZSoft::UInt32  setAttributes (ZcGiDrawableTraits* pTraits);

protected:

    ZcDbImpMotionPath* imp() const;

private:
    friend class ZcDbImpMotionPath;
    ZcDbImpMotionPath* mpImp;
};

