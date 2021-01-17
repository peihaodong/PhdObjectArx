

#ifndef ZC_GERAY2D_H
#define ZC_GERAY2D_H

#include "zgelent2d.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeRay2d : public ZcGeLinearEnt2d
{
public:
    ZcGeRay2d();
    ZcGeRay2d(const ZcGeRay2d& line);
    ZcGeRay2d(const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    ZcGeRay2d(const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    ZcGeRay2d&     set         (const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    ZcGeRay2d&     set         (const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    ZcGeRay2d&     operator =  (const ZcGeRay2d& line);
};

#pragma pack (pop)
#endif
