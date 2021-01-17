

#ifndef ZD_DBFRAME_H
#define ZD_DBFRAME_H

#include "zdbmain.h"
#include "zgepnt3d.h"

#pragma pack (push, 8)

class ZSOFT_NO_VTABLE ZcDbFrame: public ZcDbEntity
{
protected:
    ZcDbFrame();
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFrame);
    virtual ~ZcDbFrame();

};

#pragma pack (pop)

#endif  

