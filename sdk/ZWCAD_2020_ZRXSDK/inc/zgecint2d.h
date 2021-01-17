

#ifndef ZC_GECINT2D_H
#define ZC_GECINT2D_H

#include "zadesk.h"
#include "zgegbl.h"
#include "zgeent2d.h"
#include "zgeponc2d.h"
#include "zgeintrvl.h"
#pragma pack (push, 8)

class ZcGeCurve2d;

class  
GE_DLLEXPIMPORT
ZcGeCurveCurveInt2d : public ZcGeEntity2d
{

public:

    ZcGeCurveCurveInt2d ();
    ZcGeCurveCurveInt2d (const ZcGeCurve2d& curve1, const ZcGeCurve2d& curve2,
                         const ZcGeTol& tol = ZcGeContext::gTol );
    ZcGeCurveCurveInt2d (const ZcGeCurve2d& curve1, const ZcGeCurve2d& curve2,
                         const ZcGeInterval& range1, const ZcGeInterval& range2,
                         const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeCurveCurveInt2d (const ZcGeCurveCurveInt2d& src);

    const ZcGeCurve2d  *curve1          () const;
    const ZcGeCurve2d  *curve2          () const;
    void               getIntRanges     (ZcGeInterval& range1,
                                         ZcGeInterval& range2) const;
    ZcGeTol            tolerance        () const;

    int                numIntPoints     () const;
    ZcGePoint2d        intPoint         (int intNum) const;
    void               getIntParams     (int intNum,
                                         double& param1, double& param2) const;
    void               getPointOnCurve1 (int intNum, ZcGePointOnCurve2d&) const;
    void               getPointOnCurve2 (int intNum, ZcGePointOnCurve2d&) const;
    void			   getIntConfigs    (int intNum, ZcGe::ZcGeXConfig& config1wrt2, 
                                         ZcGe::ZcGeXConfig& config2wrt1) const;
    ZSoft::Boolean     isTangential     (int intNum) const;
    ZSoft::Boolean     isTransversal    (int intNum) const;
    double             intPointTol      (int intNum) const;
    int                overlapCount     () const;
	ZSoft::Boolean	   overlapDirection () const;
    void               getOverlapRanges (int overlapNum,
                                         ZcGeInterval& range1,
                                         ZcGeInterval& range2) const;

    void               changeCurveOrder ();

    ZcGeCurveCurveInt2d& orderWrt1  ();    
    ZcGeCurveCurveInt2d& orderWrt2  ();

    ZcGeCurveCurveInt2d& set        (const ZcGeCurve2d& curve1,
                                     const ZcGeCurve2d& curve2,
                                     const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeCurveCurveInt2d& set        (const ZcGeCurve2d& curve1,
                                     const ZcGeCurve2d& curve2,
                                     const ZcGeInterval& range1,
                                     const ZcGeInterval& range2,
                                     const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCurveCurveInt2d& operator = (const ZcGeCurveCurveInt2d& src);
};

#pragma pack (pop)
#endif
