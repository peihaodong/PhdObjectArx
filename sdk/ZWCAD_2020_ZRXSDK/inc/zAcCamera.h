

#pragma once

#include "zacdb.h"
#include "zdbmain.h"
#include "zdbents.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef CAMERADLLIMPEXP
#undef CAMERADLLIMPEXP
#endif

#ifdef ZCCAMERA_EXPORTS
#define CAMERADLLIMPEXP __declspec( dllexport )
#else
#define CAMERADLLIMPEXP
#endif

class ZcDbImpCamera;

class CAMERADLLIMPEXP ZcDbCamera: public ZcDbEntity
{

public:
    ZcDbCamera ();
    virtual ~ZcDbCamera();
    ZCDB_DECLARE_MEMBERS(ZcDbCamera);
    ZcDbObjectId view() const;
    Zcad::ErrorStatus	setView(const ZcDbObjectId viewId);
    virtual Zcad::ErrorStatus getGripPoints(ZcDbGripDataPtrArray& grips,
                                            const double curViewUnitSize,
                                            const int gripSize,
                                            const ZcGeVector3d& curViewDir,
                                            const int bitflags) const;

    virtual Zcad::ErrorStatus moveGripPointsAt(
        const ZcDbVoidPtrArray& gripAppData,
        const ZcGeVector3d& offset,
        const int bitflags);

    virtual Zcad::ErrorStatus	getStretchPoints(
        ZcGePoint3dArray&  stretchPoints)
        const;
    virtual Zcad::ErrorStatus   moveStretchPointsAt(
        const ZcDbIntArray& indices,
        const ZcGeVector3d&     offset);

    virtual void		list() const;

    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);

    virtual ZSoft::Boolean worldDraw(ZcGiWorldDraw*	mode);
    virtual void viewportDraw(ZcGiViewportDraw* mode);
    virtual ZSoft::UInt32 setAttributes(ZcGiDrawableTraits* pTraits);
    virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing);
    virtual Zcad::ErrorStatus   subOpen(ZcDb::OpenMode openMode);
    virtual Zcad::ErrorStatus   subClose();

    virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const;

    virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual Zcad::ErrorStatus deepClone(ZcDbObject* pOwnerObject,
        ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap,
        ZSoft::Boolean isPrimary
        = ZSoft::kTrue) const;

    virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
        ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap,
        ZSoft::Boolean isPrimary
        = ZSoft::kTrue) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus highlight(const ZcDbFullSubentPath& subId = kNullSubent,
                                        const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;
    virtual Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath& subId = kNullSubent,
                                          const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;

private:
    friend class ZcDbImpCamera;
    ZcDbImpCamera* pImp;
};

#pragma pack (pop)
