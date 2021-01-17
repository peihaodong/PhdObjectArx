

#ifndef ZC_GELINE3D_H
#define ZC_GELINE3D_H

#include "zgelent3d.h"
#pragma pack (push, 8)

class ZcGeLine2d;

class
GE_DLLEXPIMPORT
ZcGeLine3d : public ZcGeLinearEnt3d
{
public:
    ZcGeLine3d();
    ZcGeLine3d(const ZcGeLine3d& line);
    ZcGeLine3d(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeLine3d(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    static const ZcGeLine3d kXAxis;
    static const ZcGeLine3d kYAxis;
    static const ZcGeLine3d kZAxis;

    ZcGeLine3d& set(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeLine3d& set(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    ZcGeLine3d& operator = (const ZcGeLine3d& line);
};

#pragma pack (pop)
#endif
