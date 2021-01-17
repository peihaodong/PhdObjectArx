

#ifndef ZC_GECURV2D_H
#define ZC_GECURV2D_H

#include "zadesk.h"
#include "zgeent2d.h"
#include "zgeponc2d.h"
#include "zgept2dar.h"
#include "zgevc2dar.h"
#include "zgedblar.h"
#include "zgevptar.h"
#include "zgeintarr.h"
#pragma pack (push, 8)

class ZcGePoint2d;
class ZcGeVector2d;
class ZcGePointOnCurve2d;
class ZcGeInterval;
class ZcGeMatrix2d;
class ZcGeLine2d;
class ZcGePointOnCurve2dData;
class ZcGeBoundBlock2d;

class
GE_DLLEXPIMPORT
ZcGeCurve2d : public ZcGeEntity2d
{
public:

    void           getInterval(ZcGeInterval& intrvl) const;
    void           getInterval(ZcGeInterval& intrvl, ZcGePoint2d& start,
			                   ZcGePoint2d& end) const;
    ZcGeCurve2d&   reverseParam();
	ZcGeCurve2d&   setInterval();
	ZSoft::Boolean setInterval(const ZcGeInterval& intrvl);

    double         distanceTo(const ZcGePoint2d& pnt,
                              const ZcGeTol& = ZcGeContext::gTol) const;
    double         distanceTo(const ZcGeCurve2d&,
                              const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint2d closestPointTo(const ZcGePoint2d& pnt,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGePoint2d closestPointTo(const ZcGeCurve2d& curve2d,
                               ZcGePoint2d& pntOnOtherCrv,
                               const ZcGeTol& tol= ZcGeContext::gTol) const;

    void getClosestPointTo(const ZcGePoint2d& pnt,
                           ZcGePointOnCurve2d& pntOnCrv,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;
    void getClosestPointTo(const ZcGeCurve2d& curve2d,
                           ZcGePointOnCurve2d& pntOnThisCrv,
                           ZcGePointOnCurve2d& pntOnOtherCrv,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean getNormalPoint (const ZcGePoint2d& pnt,
	                           ZcGePointOnCurve2d& pntOnCrv,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isOn(const ZcGePoint2d& pnt,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn(const ZcGePoint2d& pnt, double& param,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn(double param,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         paramOf(const ZcGePoint2d& pnt,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;

	void           getTrimmedOffset (double distance,
									 ZcGeVoidPointerArray& offsetCurveList,
									 ZcGe::OffsetCrvExtType extensionType = ZcGe::kFillet,
                                     const ZcGeTol& = ZcGeContext::gTol) const;

    ZSoft::Boolean isClosed  (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPeriodic(double& period) const;
    ZSoft::Boolean isLinear  (ZcGeLine2d& line,
                              const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         length       (double fromParam, double toParam,
                                 double tol = ZcGeContext::gTol.equalPoint()) const;
    double         paramAtLength(double datumParam, double length,
                                 ZSoft::Boolean posParamDir = ZSoft::kTrue,
                                 double tol = ZcGeContext::gTol.equalPoint()) const;
    ZSoft::Boolean area         (double startParam, double endParam,
                                 double& value,
                                 const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isDegenerate(ZcGe::EntityId& degenerateType,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isDegenerate(ZcGeEntity2d*& pConvertedEntity,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    void           getSplitCurves (double param, ZcGeCurve2d* & piece1,
                                   ZcGeCurve2d* & piece2) const;

	ZSoft::Boolean explode      (ZcGeVoidPointerArray& explodedCurves,
	                             ZcGeIntArray& newExplodedCurve,
				     const ZcGeInterval* intrvl = NULL ) const;

    void getLocalClosestPoints(const ZcGePoint2d& point,
                               ZcGePointOnCurve2d& approxPnt,
                               const ZcGeInterval* nbhd = 0,
                               const ZcGeTol& = ZcGeContext::gTol) const;
    void getLocalClosestPoints(const ZcGeCurve2d& otherCurve,
                               ZcGePointOnCurve2d& approxPntOnThisCrv,
                               ZcGePointOnCurve2d& approxPntOnOtherCrv,
                               const ZcGeInterval* nbhd1 = 0,
                               const ZcGeInterval* nbhd2 = 0,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeBoundBlock2d  boundBlock() const;
    ZcGeBoundBlock2d  boundBlock(const ZcGeInterval& range) const;

    ZcGeBoundBlock2d  orthoBoundBlock() const;
    ZcGeBoundBlock2d  orthoBoundBlock(const ZcGeInterval& range) const;

    ZSoft::Boolean hasStartPoint(ZcGePoint2d& startPoint) const;
    ZSoft::Boolean hasEndPoint  (ZcGePoint2d& endPoint) const;

    ZcGePoint2d    evalPoint(double param) const;
    ZcGePoint2d    evalPoint(double param, int numDeriv,
                             ZcGeVector2dArray& derivArray) const;

    void     getSamplePoints(double fromParam, double toParam,
                             double approxEps, ZcGePoint2dArray& pointArray,
			     ZcGeDoubleArray& paramArray) const;
    void     getSamplePoints(int numSample, ZcGePoint2dArray&) const;

    ZcGeCurve2d&   operator =  (const ZcGeCurve2d& curve);

protected:

    ZcGeCurve2d ();
    ZcGeCurve2d (const ZcGeCurve2d&);
};

#pragma pack (pop)
#endif
