
#pragma once

#include "zdbmain.h"

#include "zrxprotevnt.h"

#pragma pack(push, 8)

class ZcDbAppEntityGrips : public ZcRxProtocolReactor
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbAppEntityGrips);
    virtual Zcad::ErrorStatus getGripPoints (
                                        ZcDbGripDataPtrArray& grips,
                                        const double          curViewUnitSize,
                                        const int             gripSize,
                                        const ZcGeVector3d&   curViewDir,
                                        const int             bitflags,
                                        ZcDbEntity*           pEntity) = 0;
    virtual Zcad::ErrorStatus moveGripPointsAt (
                         const ZcDbVoidPtrArray&        gripAppData,
                         const ZcGeVector3d&            offset,
                         const int                      bitflags,
                         ZcDbEntity*                    pEntity) = 0;
    virtual void gripStatus(const ZcDb::GripStat status,
                            ZcDbEntity*          pEntity) = 0;
};

class ZcDbBlockInsertionPoints :  public ZcRxProtocolReactor
{
    public:

        ZCRX_DECLARE_MEMBERS(ZcDbBlockInsertionPoints);
        virtual Zcad::ErrorStatus getInsertionPoints (
                        const ZcDbBlockTableRecord* pBlock,
                        const ZcDbBlockReference*   pBlkRef,
                        ZcGePoint3dArray&           insPts,
                        ZcGeVector3dArray&          alignmentDirections) = 0;
};

#pragma pack(pop)
