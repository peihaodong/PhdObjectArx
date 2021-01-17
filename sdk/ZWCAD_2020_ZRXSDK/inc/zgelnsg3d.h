

#ifndef ZC_GELNSG3D_H
#define ZC_GELNSG3D_H

#include "zgeline3d.h"
#include "zgeplane.h"
#pragma pack (push, 8)

class ZcGeLineSeg2d;

class 
GE_DLLEXPIMPORT
ZcGeLineSeg3d : public ZcGeLinearEnt3d
{
public:
    ZcGeLineSeg3d();
    ZcGeLineSeg3d(const ZcGeLineSeg3d& line);
    ZcGeLineSeg3d(const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeLineSeg3d(const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);

    void           getBisector  (ZcGePlane& plane) const;

    ZcGePoint3d    baryComb     (double blendCoeff) const;

    ZcGePoint3d    startPoint   () const;
    ZcGePoint3d    midPoint     () const;
    ZcGePoint3d    endPoint     () const;
    double         length       () const;
    double         length       (double fromParam, double toParam,
                                 double tol = ZcGeContext::gTol.equalPoint()) const;

    ZcGeLineSeg3d& set          (const ZcGePoint3d& pnt, const ZcGeVector3d& vec);
    ZcGeLineSeg3d& set          (const ZcGePoint3d& pnt1, const ZcGePoint3d& pnt2);
   	ZcGeLineSeg3d& set          (const ZcGeCurve3d& curve1,
                                 const ZcGeCurve3d& curve2,
                                 double& param1, double& param2,
                                 ZSoft::Boolean& success);
  	ZcGeLineSeg3d& set          (const ZcGeCurve3d& curve,
                                 const ZcGePoint3d& point, double& param,
                                 ZSoft::Boolean& success);

    ZcGeLineSeg3d& operator =   (const ZcGeLineSeg3d& line);
};

#pragma pack (pop)
#endif
