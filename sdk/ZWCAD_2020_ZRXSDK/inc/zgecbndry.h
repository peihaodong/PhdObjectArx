

#ifndef ZC_GECBNDRY_H
#define ZC_GECBNDRY_H

#include "zgegbl.h"
#pragma pack (push, 8)

class ZcGeCurve2d;
class ZcGeEntity3d;
class ZcGePosition3d;
class ZcGeImpCurveBoundary;
     
class 
GX_DLLEXPIMPORT
ZcGeCurveBoundary
{
public:
    ZcGeCurveBoundary();
    ZcGeCurveBoundary(int numberOfCurves, const ZcGeEntity3d *const * crv3d,
                      const ZcGeCurve2d *const * crv2d,
                      ZSoft::Boolean* orientation3d,
                      ZSoft::Boolean* orientation2d,
                      ZSoft::Boolean makeCopy = ZSoft::kTrue);
    ZcGeCurveBoundary(const ZcGeCurveBoundary&);

    ~ZcGeCurveBoundary();

    ZcGeCurveBoundary& operator =   (const ZcGeCurveBoundary& src);

    ZSoft::Boolean     isDegenerate () const;
    ZSoft::Boolean     isDegenerate (ZcGePosition3d& degenPoint, ZcGeCurve2d** paramCurve) const;
    int                numElements  () const;
    void               getContour   (int& n, ZcGeEntity3d*** crv3d,
                                     ZcGeCurve2d*** paramGeometry,
                                     ZSoft::Boolean** orientation3d,
                                     ZSoft::Boolean** orientation2d) const;

    ZcGeCurveBoundary& set (int numElements, const ZcGeEntity3d *const * crv3d,
                            const ZcGeCurve2d *const * crv2d,
                            ZSoft::Boolean* orientation3d,
                            ZSoft::Boolean* orientation2d,
                            ZSoft::Boolean makeCopy = ZSoft::kTrue);

    ZSoft::Boolean     isOwnerOfCurves() const;
    ZcGeCurveBoundary& setToOwnCurves ();

protected:
    friend class ZcGeImpCurveBoundary;

    ZcGeImpCurveBoundary    *mpImpBnd;
    int                     mDelBnd;
};

#pragma pack (pop)
#endif
