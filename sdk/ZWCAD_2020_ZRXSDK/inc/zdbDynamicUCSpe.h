
#include "zacdb.h"
#include "zdbmain.h"

#pragma once
#pragma pack (push, 8)

class ZcDbDynamicUCSPE	: public ZcRxObject
{
public:
    enum Flags {
        kDefault     = 0x00,
    };

	ZCRX_DECLARE_MEMBERS(ZcDbDynamicUCSPE);
    virtual Zcad::ErrorStatus
        getCandidatePlanes(ZcArray<ZcGePlane>& results,
                            double &distToEdge,
                            double &objWidth,
                            double &objHeight,
                            ZcDbEntity* pEnt,
                            const ZcDbSubentId& subentId,
                            const ZcGePlane& viewplane,
                            ZcDbDynamicUCSPE::Flags flags = kDefault
                            ) const = 0;
};

#pragma pack (pop)


