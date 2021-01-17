

#ifndef ZC_GECURV3D_H
#define ZC_GECURV3D_H

#include "zadesk.h"
#include "zgeent3d.h"
#include "zgeponc3d.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#include "zgedblar.h"
#include "zgevptar.h"
#include "zgeintarr.h"
#pragma pack (push, 8)

class ZcGeCurve2d;
class ZcGeSurface;
class ZcGePoint3d;
class ZcGePlane;
class ZcGeVector3d;
class ZcGeLinearEnt3d;
class ZcGeLine3d;
class ZcGePointOnCurve3d;
class ZcGePointOnSurface;
class ZcGeInterval;
class ZcGeMatrix3d;
class ZcGePointOnCurve3dData;
class ZcGeBoundBlock3d;

class
GE_DLLEXPIMPORT
ZcGeCurve3d : public ZcGeEntity3d
{
public:

    void           getInterval(ZcGeInterval& intrvl) const;
    void           getInterval(ZcGeInterval& intrvl, ZcGePoint3d& start,
                               ZcGePoint3d& end) const;
    ZcGeCurve3d&   reverseParam();
	ZcGeCurve3d&   setInterval();
	ZSoft::Boolean setInterval(const ZcGeInterval& intrvl);

    double       distanceTo(const ZcGePoint3d& pnt,
                            const ZcGeTol& tol = ZcGeContext::gTol) const;
    double       distanceTo(const ZcGeCurve3d& curve,
                            const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d closestPointTo(const ZcGePoint3d& pnt,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGePoint3d closestPointTo(const ZcGeCurve3d& curve3d,
                               ZcGePoint3d& pntOnOtherCrv,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;

    void getClosestPointTo(const ZcGePoint3d& pnt, ZcGePointOnCurve3d& pntOnCrv,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;
    void getClosestPointTo(const ZcGeCurve3d& curve3d,
                           ZcGePointOnCurve3d& pntOnThisCrv,
                           ZcGePointOnCurve3d& pntOnOtherCrv,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGePoint3d projClosestPointTo(const ZcGePoint3d& pnt,
                                   const ZcGeVector3d& projectDirection,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGePoint3d projClosestPointTo(const ZcGeCurve3d& curve3d,
                                   const ZcGeVector3d& projectDirection,
                                   ZcGePoint3d& pntOnOtherCrv,
                                   const ZcGeTol& tol = ZcGeContext::gTol) const;

    void getProjClosestPointTo(const ZcGePoint3d& pnt,
                               const ZcGeVector3d& projectDirection,
                               ZcGePointOnCurve3d& pntOnCrv,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;
    void getProjClosestPointTo(const ZcGeCurve3d& curve3d,
                               const ZcGeVector3d& projectDirection,
                               ZcGePointOnCurve3d& pntOnThisCrv,
                               ZcGePointOnCurve3d& pntOnOtherCrv,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;

	ZSoft::Boolean getNormalPoint(const ZcGePoint3d& pnt,
	                              ZcGePointOnCurve3d& pntOnCrv,
                                      const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeBoundBlock3d  boundBlock() const;
    ZcGeBoundBlock3d  boundBlock(const ZcGeInterval& range) const;

    ZcGeBoundBlock3d  orthoBoundBlock() const;
    ZcGeBoundBlock3d  orthoBoundBlock(const ZcGeInterval& range) const;

    ZcGeEntity3d*  project(const ZcGePlane& projectionPlane,
                           const ZcGeVector3d& projectDirection,
                           const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeEntity3d*  orthoProject(const ZcGePlane& projectionPlane,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isOn(const ZcGePoint3d& pnt,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn(const ZcGePoint3d& pnt, double& param,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isOn(double param,
                        const ZcGeTol& tol = ZcGeContext::gTol) const;

    double paramOf(const ZcGePoint3d& pnt, const ZcGeTol& tol = ZcGeContext::gTol)const;

	void getTrimmedOffset(double distance,
		              const ZcGeVector3d& planeNormal,
			      ZcGeVoidPointerArray& offsetCurveList,
			      ZcGe::OffsetCrvExtType extensionType = ZcGe::kFillet,
                              const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isClosed      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPlanar      (ZcGePlane& plane,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isLinear      (ZcGeLine3d& line,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isCoplanarWith(const ZcGeCurve3d& curve3d,
                                  ZcGePlane& plane,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPeriodic    (double& period) const;

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
    ZSoft::Boolean isDegenerate(ZcGeEntity3d*& pConvertedEntity,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    void getSplitCurves(double param, ZcGeCurve3d* & piece1,
                        ZcGeCurve3d* & piece2) const;

	ZSoft::Boolean explode       (ZcGeVoidPointerArray& explodedCurves,
	                              ZcGeIntArray& newExplodedCurves,
				      const ZcGeInterval* intrvl = NULL ) const;

    void getLocalClosestPoints(const ZcGePoint3d& point,
                               ZcGePointOnCurve3d& approxPnt,
                               const ZcGeInterval* nbhd = 0,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;
    void getLocalClosestPoints(const ZcGeCurve3d& otherCurve,
                               ZcGePointOnCurve3d& approxPntOnThisCrv,
                               ZcGePointOnCurve3d& approxPntOnOtherCrv,
                               const ZcGeInterval* nbhd1 = 0,
                               const ZcGeInterval* nbhd2 = 0,
                               const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean hasStartPoint(ZcGePoint3d& startPnt) const;
    ZSoft::Boolean hasEndPoint  (ZcGePoint3d& endPnt) const;

    ZcGePoint3d    evalPoint(double param) const;
    ZcGePoint3d    evalPoint(double param, int numDeriv,
                             ZcGeVector3dArray& derivArray) const;

    void           getSamplePoints(double fromParam, double toParam,
                                   double approxEps, ZcGePoint3dArray& 
 		                   pointArray, ZcGeDoubleArray& paramArray) const;
    void           getSamplePoints(int numSample, ZcGePoint3dArray& pointArray) const;
	void           getSamplePoints(int numSample, ZcGePoint3dArray& pointArray, ZcGeDoubleArray& paramArray) const;

    ZcGeCurve3d&   operator =  (const ZcGeCurve3d& curve);

protected:

    ZcGeCurve3d();
    ZcGeCurve3d(const ZcGeCurve3d&);
};

#pragma pack (pop)
#endif
