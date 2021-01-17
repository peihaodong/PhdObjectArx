

#ifndef ZC_GEOFFC2D_H
#define ZC_GEOFFC2D_H

#include "zgecurv2d.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeOffsetCurve2d : public ZcGeCurve2d
{
public:

    ZcGeOffsetCurve2d (const ZcGeCurve2d& baseCurve, double offsetDistance);
    ZcGeOffsetCurve2d (const ZcGeOffsetCurve2d& offsetCurve);

    const ZcGeCurve2d*  curve             () const;
    double              offsetDistance    () const;
	ZSoft::Boolean		paramDirection    () const;
	ZcGeMatrix2d		transformation    () const;

    ZcGeOffsetCurve2d&  setCurve          (const ZcGeCurve2d& baseCurve);
    ZcGeOffsetCurve2d&  setOffsetDistance (double distance);

    ZcGeOffsetCurve2d&  operator = (const ZcGeOffsetCurve2d& offsetCurve);
};

#pragma pack (pop)
#endif
