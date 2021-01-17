

#ifndef ZC_GEPENT3D_H
#define ZC_GEPENT3D_H

#include "zadesk.h"
#include "zgeent3d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGePointEnt3d : public ZcGeEntity3d
{
public:

    ZcGePoint3d     point3d     () const;

    operator        ZcGePoint3d () const;

    ZcGePointEnt3d& operator =  (const ZcGePointEnt3d& pnt);

protected:
    ZcGePointEnt3d ();
    ZcGePointEnt3d (const ZcGePointEnt3d&);
};

#pragma pack (pop)
#endif
