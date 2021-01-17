

#ifndef ZC_GELNSG2D_H
#define ZC_GELNSG2D_H

#include "zgeline2d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
ZcGeLineSeg2d : public ZcGeLinearEnt2d
{
public:
    ZcGeLineSeg2d();
    ZcGeLineSeg2d(const ZcGeLineSeg2d& line);
    ZcGeLineSeg2d(const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);
    ZcGeLineSeg2d(const ZcGePoint2d& pnt, const ZcGeVector2d& vec);

    ZcGeLineSeg2d& set(const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    ZcGeLineSeg2d& set(const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);
    ZcGeLineSeg2d& set(const ZcGeCurve2d& curve1,
                       const ZcGeCurve2d& curve2,
                       double& param1, double& param2,
                       ZSoft::Boolean& success);
    ZcGeLineSeg2d& set(const ZcGeCurve2d& curve, const ZcGePoint2d& point,
                       double& param, ZSoft::Boolean& success);

    void           getBisector(ZcGeLine2d& line) const;

    ZcGePoint2d    baryComb   (double blendCoeff) const;

    ZcGePoint2d    startPoint   () const;
    ZcGePoint2d    midPoint     () const;
    ZcGePoint2d    endPoint     () const;
    double         length       () const;
    double         length       (double fromParam, double toParam,
                                 double tol = ZcGeContext::gTol.equalPoint())
                                const;

    ZcGeLineSeg2d& operator =  (const ZcGeLineSeg2d& line);
};

#pragma pack (pop)
#endif
