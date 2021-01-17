

#ifndef ZC_GECINT3D_H
#define ZC_GECINT3D_H

#include "zadesk.h"
#include "zgeent3d.h"
#include "zgeponc3d.h"
#include "zgeintrvl.h"
#pragma pack (push, 8)

class ZcGeCurve3d;

class  
GE_DLLEXPIMPORT
ZcGeCurveCurveInt3d : public ZcGeEntity3d
{

public:

    ZcGeCurveCurveInt3d ();
    ZcGeCurveCurveInt3d (const ZcGeCurve3d& curve1, const ZcGeCurve3d& curve2,
		                 const ZcGeVector3d& planeNormal =
						 ZcGeVector3d::kIdentity,
                         const ZcGeTol& tol = ZcGeContext::gTol );
    ZcGeCurveCurveInt3d (const ZcGeCurve3d& curve1, const ZcGeCurve3d& curve2,
                         const ZcGeInterval& range1, const ZcGeInterval& range2,
		                 const ZcGeVector3d& planeNormal=ZcGeVector3d::kIdentity,
                         const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeCurveCurveInt3d (const ZcGeCurveCurveInt3d& src);

    const ZcGeCurve3d  *curve1          () const;
    const ZcGeCurve3d  *curve2          () const;
    void               getIntRanges     (ZcGeInterval& range1,
                                         ZcGeInterval& range2) const;
	ZcGeVector3d	   planeNormal		() const;
    ZcGeTol            tolerance        () const;

    int                numIntPoints     () const;
    ZcGePoint3d        intPoint         (int intNum) const;
    void               getIntParams     (int intNum,
                                         double& param1, double& param2) const;
    void               getPointOnCurve1 (int intNum, ZcGePointOnCurve3d& pntOnCrv) const;
    void               getPointOnCurve2 (int intNum, ZcGePointOnCurve3d& pntOnCrv) const;
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

    ZcGeCurveCurveInt3d& orderWrt1  ();    
    ZcGeCurveCurveInt3d& orderWrt2  ();

    ZcGeCurveCurveInt3d& set        (const ZcGeCurve3d& curve1,
                                     const ZcGeCurve3d& curve2,
		                             const ZcGeVector3d& planeNormal = 
								     ZcGeVector3d::kIdentity,
                                     const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeCurveCurveInt3d& set        (const ZcGeCurve3d& curve1,
                                     const ZcGeCurve3d& curve2,
                                     const ZcGeInterval& range1,
                                     const ZcGeInterval& range2,
		                             const ZcGeVector3d& planeNormal = 
							         ZcGeVector3d::kIdentity,
                                     const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeCurveCurveInt3d& operator = (const ZcGeCurveCurveInt3d& src);
};

#pragma pack (pop)
#endif
