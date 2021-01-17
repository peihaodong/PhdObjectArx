

#ifndef ZC_GEPOS3D_H
#define ZC_GEPOS3D_H

#include "zadesk.h"
#include "zgepent3d.h"
#include "zgepnt3d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGePosition3d : public ZcGePointEnt3d
{
public:
    ZcGePosition3d ();
    ZcGePosition3d (const ZcGePoint3d& pnt);
    ZcGePosition3d (double x, double y, double z);
    ZcGePosition3d (const ZcGePosition3d& pos);

    ZcGePosition3d&  set        (const ZcGePoint3d&);
    ZcGePosition3d&  set        (double x, double y, double z );

    ZcGePosition3d& operator =  (const ZcGePosition3d& pos);
};

#pragma pack (pop)
#endif
