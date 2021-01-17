

#ifndef ZC_GEPENT2D_H
#define ZC_GEPENT2D_H

#include "zadesk.h"
#include "zgeent2d.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGePointEnt2d : public ZcGeEntity2d
{
public:

    ZcGePoint2d     point2d     () const;

    operator        ZcGePoint2d () const;

    ZcGePointEnt2d& operator =  (const ZcGePointEnt2d& pnt);

protected:

    ZcGePointEnt2d ();
    ZcGePointEnt2d (const ZcGePointEnt2d&);
};

#pragma pack (pop)
#endif
