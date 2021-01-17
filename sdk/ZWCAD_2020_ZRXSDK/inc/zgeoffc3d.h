

#ifndef ZC_GEOFFC3D_H
#define ZC_GEOFFC3D_H

#include "zgecurv3d.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeOffsetCurve3d : public ZcGeCurve3d
{
public:

    ZcGeOffsetCurve3d (const ZcGeCurve3d& baseCurve, const ZcGeVector3d& planeNormal,
                       double offsetDistance);
    ZcGeOffsetCurve3d (const ZcGeOffsetCurve3d& offsetCurve);

    const ZcGeCurve3d*  curve             () const;
    ZcGeVector3d        normal            () const; 
    double              offsetDistance    () const;
	ZSoft::Boolean		paramDirection    () const;
	ZcGeMatrix3d		transformation    () const;

    ZcGeOffsetCurve3d&  setCurve          (const ZcGeCurve3d& baseCurve);
    ZcGeOffsetCurve3d&  setNormal         (const ZcGeVector3d& planeNormal);
    ZcGeOffsetCurve3d&  setOffsetDistance (double offsetDistance);

    ZcGeOffsetCurve3d&  operator = (const ZcGeOffsetCurve3d& offsetCurve);
};

#pragma pack (pop)
#endif
