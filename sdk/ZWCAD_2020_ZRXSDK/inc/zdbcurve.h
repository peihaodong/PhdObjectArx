

#ifndef ZD_DBCURVE_H
#define ZD_DBCURVE_H

#include "zdbmain.h"
#include "zgept3dar.h"
#include "zgedblar.h"
#include "zgeplane.h"
#include "zdbptrar.h"

class ZcDbSpline;

#pragma pack(push, 8)

class ZSOFT_NO_VTABLE ZcDbCurve: public ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbCurve);

    virtual ~ZcDbCurve();

    virtual ZSoft::Boolean    isClosed     () const;      
    virtual ZSoft::Boolean    isPeriodic   () const;

    virtual Zcad::ErrorStatus getStartParam(double&) const;
    virtual Zcad::ErrorStatus getEndParam  (double&) const;
    virtual Zcad::ErrorStatus getStartPoint(ZcGePoint3d&) const;
    virtual Zcad::ErrorStatus getEndPoint  (ZcGePoint3d&) const;

    virtual Zcad::ErrorStatus getPointAtParam(double, ZcGePoint3d&) const;
    virtual Zcad::ErrorStatus getParamAtPoint(const ZcGePoint3d&, double&)const;
    virtual Zcad::ErrorStatus getDistAtParam (double param, double& dist) const;
    virtual Zcad::ErrorStatus getParamAtDist (double dist, double& param) const;
    virtual Zcad::ErrorStatus getDistAtPoint (const ZcGePoint3d&, double&)const;
    virtual Zcad::ErrorStatus getPointAtDist (double, ZcGePoint3d&) const;

    virtual Zcad::ErrorStatus getFirstDeriv  (double param,
                                              ZcGeVector3d& firstDeriv) const;
    virtual Zcad::ErrorStatus getFirstDeriv  (const ZcGePoint3d&,
                                              ZcGeVector3d& firstDeriv) const;
    virtual Zcad::ErrorStatus getSecondDeriv (double param,
                                              ZcGeVector3d& secDeriv) const;
    virtual Zcad::ErrorStatus getSecondDeriv (const ZcGePoint3d&,
                                              ZcGeVector3d& secDeriv) const;

    virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d& givenPnt,
                                                ZcGePoint3d& pointOnCurve,
                                                ZSoft::Boolean extend
                                                = ZSoft::kFalse) const;
    virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d& givenPnt,
                                                const ZcGeVector3d& direction,
                                                ZcGePoint3d& pointOnCurve,
                                                ZSoft::Boolean extend
                                                = ZSoft::kFalse) const;

    virtual Zcad::ErrorStatus getOrthoProjectedCurve(const ZcGePlane&,
                                                ZcDbCurve*& projCrv) const;
    virtual Zcad::ErrorStatus getProjectedCurve(const ZcGePlane&,
                                                const ZcGeVector3d& projDir,
                                                ZcDbCurve*& projCrv) const;

    virtual Zcad::ErrorStatus getOffsetCurves(double offsetDist,
                                          ZcDbVoidPtrArray& offsetCurves) const;
    virtual Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;
    virtual Zcad::ErrorStatus getSpline      (ZcDbSpline*& spline) const;
    virtual Zcad::ErrorStatus getSplitCurves (const ZcGeDoubleArray& params,
                                         ZcDbVoidPtrArray& curveSegments) const;
    virtual Zcad::ErrorStatus getSplitCurves (const ZcGePoint3dArray& points,
                                         ZcDbVoidPtrArray& curveSegments) const;

    virtual Zcad::ErrorStatus extend(double newParam);
    virtual Zcad::ErrorStatus extend(ZSoft::Boolean extendStart,
                                     const ZcGePoint3d& toPoint);

    virtual Zcad::ErrorStatus getArea(double&) const;
	virtual Zcad::ErrorStatus reverseCurve();
	ZCDB_PORT virtual Zcad::ErrorStatus  getZcGeCurve ( ZcGeCurve3d*& pGeCurve, const ZcGeTol& tol = ZcGeContext::gTol ) const;
	ZCDB_PORT virtual Zcad::ErrorStatus  setFromZcGeCurve ( const ZcGeCurve3d& geCurve, ZcGeVector3d *normal = NULL, const ZcGeTol& tol = ZcGeContext::gTol );


protected:
    ZcDbCurve();
};

#define DBCURVE_METHODS \
virtual ZSoft::Boolean isClosed() const; \
virtual ZSoft::Boolean isPeriodic() const; \
virtual ZSoft::Boolean isPlanar() const; \
virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const; \
virtual Zcad::ErrorStatus getStartParam(double&) const; \
virtual Zcad::ErrorStatus getEndParam(double&) const; \
virtual Zcad::ErrorStatus getStartPoint(ZcGePoint3d&) const; \
virtual Zcad::ErrorStatus getEndPoint(ZcGePoint3d&) const; \
virtual Zcad::ErrorStatus getPointAtParam(double, ZcGePoint3d&) const; \
virtual Zcad::ErrorStatus getParamAtPoint(const ZcGePoint3d&, double&) const; \
virtual Zcad::ErrorStatus getDistAtParam(double, double&) const; \
virtual Zcad::ErrorStatus getParamAtDist(double, double&) const; \
virtual Zcad::ErrorStatus getDistAtPoint(const ZcGePoint3d&, double&) const; \
virtual Zcad::ErrorStatus getPointAtDist(double, ZcGePoint3d&) const; \
virtual Zcad::ErrorStatus getFirstDeriv(double, ZcGeVector3d&) const; \
virtual Zcad::ErrorStatus getFirstDeriv(const ZcGePoint3d&,ZcGeVector3d&)const;\
virtual Zcad::ErrorStatus getSecondDeriv(double, ZcGeVector3d&) const; \
virtual Zcad::ErrorStatus getSecondDeriv(const ZcGePoint3d&, \
                              ZcGeVector3d&) const; \
virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d&, ZcGePoint3d&, \
                              ZSoft::Boolean = ZSoft::kFalse) const; \
virtual Zcad::ErrorStatus getClosestPointTo(const ZcGePoint3d&, \
                              const ZcGeVector3d&, ZcGePoint3d&, \
                              ZSoft::Boolean = ZSoft::kFalse) const; \
virtual Zcad::ErrorStatus getOrthoProjectedCurve(const ZcGePlane&, \
                              ZcDbCurve*&) const; \
virtual Zcad::ErrorStatus getProjectedCurve(const ZcGePlane&, \
                              const ZcGeVector3d&, ZcDbCurve*&) const; \
virtual Zcad::ErrorStatus getOffsetCurves(double, ZcDbVoidPtrArray&) const; \
virtual Zcad::ErrorStatus getSpline(ZcDbSpline*&) const; \
virtual Zcad::ErrorStatus getSplitCurves(const ZcGeDoubleArray&, \
                              ZcDbVoidPtrArray& curveSegments) const; \
virtual Zcad::ErrorStatus getSplitCurves(const ZcGePoint3dArray&, \
                              ZcDbVoidPtrArray&) const; \
virtual Zcad::ErrorStatus extend(double); \
virtual Zcad::ErrorStatus extend(ZSoft::Boolean, const ZcGePoint3d&); \
virtual Zcad::ErrorStatus getArea(double&) const;\
virtual Zcad::ErrorStatus reverseCurve(); \
ZCDB_PORT virtual Zcad::ErrorStatus getZcGeCurve ( ZcGeCurve3d*& pGeCurve, const ZcGeTol& tol = ZcGeContext::gTol ) const; \
ZCDB_PORT virtual Zcad::ErrorStatus setFromZcGeCurve ( const ZcGeCurve3d& geCurve, ZcGeVector3d *normal = NULL, const ZcGeTol& tol = ZcGeContext::gTol );


#pragma pack(pop)

#endif
