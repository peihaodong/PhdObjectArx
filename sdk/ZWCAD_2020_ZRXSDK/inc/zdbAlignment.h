
#ifndef _ZDBALIGNMENT_H
#define _ZDBALIGNMENT_H

#include "zacdb.h"
#include "zdbmain.h"

#pragma pack (push, 8)

class ZSOFT_NO_VTABLE ZcDbAlignment : public ZcRxObject {
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAlignment);
    virtual Zcad::ErrorStatus getAlignment(
        ZcDbEntity*           pEnt,
        const ZcArray< ZcDbObjectIdArray,
            ZcArrayObjectCopyReallocator< ZcDbObjectIdArray > >&
                nestedPickedEntities,
        const ZcGePoint3d&    pickPoint,
        const ZcGeVector3d&   normal,
        ZcGePoint3d&          closestPoint,
        ZcGeVector3d&         direction) = 0;
};

#pragma pack (pop)

#endif

