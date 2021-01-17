
#include "zacdb.h"
#include "zdbmain.h"

#pragma once
#pragma pack (push, 8)

class ZcDbInterferencePE : public ZcRxObject
{
public:
    enum Flags {
        kDefault     = 0x00,
    };

    ZCRX_DECLARE_MEMBERS(ZcDbInterferencePE);
    virtual Zcad::ErrorStatus
        createInterferenceObjects(  ZcArray<ZcDbEntity*>& interferenceObjects,
                                    ZcDbEntity* pEnt1,
                                    ZcDbEntity* pEnt2,
                                    unsigned int flags ) const = 0;
};

#pragma pack (pop)


