

#ifndef ZC_GELINE2D_H
#define ZC_GELINE2D_H

#include "zgelent2d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeLine2d : public ZcGeLinearEnt2d
{
public:
    ZcGeLine2d();
    ZcGeLine2d(const ZcGeLine2d& line);
    ZcGeLine2d(const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    ZcGeLine2d(const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    static const ZcGeLine2d kXAxis;
    static const ZcGeLine2d kYAxis;

    ZcGeLine2d& set (const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    ZcGeLine2d& set (const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    ZcGeLine2d& operator = (const ZcGeLine2d& line);
};

#pragma pack (pop)
#endif
