

#ifndef ZC_GEPOS2D_H
#define ZC_GEPOS2D_H

#include "zadesk.h"
#include "zgepent2d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGePosition2d : public ZcGePointEnt2d
{
public:
    ZcGePosition2d ();
    ZcGePosition2d (const ZcGePoint2d& pnt);
    ZcGePosition2d (double x, double y);
    ZcGePosition2d (const ZcGePosition2d& pos);

    ZcGePosition2d&  set        (const ZcGePoint2d&);
    ZcGePosition2d&  set        (double x, double y );

    ZcGePosition2d& operator =  (const ZcGePosition2d& pos);
};

#pragma pack (pop)
#endif
