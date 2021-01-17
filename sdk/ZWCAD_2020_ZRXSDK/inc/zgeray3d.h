

#ifndef ZC_GERAY3D_H
#define ZC_GERAY3D_H

#include "zgelent3d.h"
#pragma pack (push, 8)

class ZcGeRay2d;

class
GE_DLLEXPIMPORT
ZcGeRay3d : public ZcGeLinearEnt3d
{
public:
    ZcGeRay3d();
    ZcGeRay3d(const ZcGeRay3d& line);
    ZcGeRay3d(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeRay3d(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    ZcGeRay3d&     set         (const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeRay3d&     set         (const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    ZcGeRay3d&     operator =  (const ZcGeRay3d& line);
};

#pragma pack (pop)
#endif
