

#ifndef ZCDB_DBSPLINE_H
#define ZCDB_DBSPLINE_H

#include "zgegbl.h"
#include "zdbmain.h"
#include "zdbcurve.h"
#include "zgekvec.h"

#pragma pack (push, 8)

static const unsigned int kPlineVerticesThrehold = 10000;

class ZcDbSpline: public  ZcDbCurve
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSpline);
    ZcDbSpline();
    virtual ~ZcDbSpline();
    ZcDbSpline(
               const ZcGePoint3dArray& points,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);
    ZcDbSpline(
               const ZcGePoint3dArray& points,
	       const ZcGeVector3d&     startTangent,
	       const ZcGeVector3d&     endTangent,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);

    ZcDbSpline(
               int                     degree, 
	       ZSoft::Boolean          rational, 
	       ZSoft::Boolean          closed, 
	       ZSoft::Boolean          periodic,
	       const ZcGePoint3dArray& controlPoints, 
	       const ZcGeDoubleArray&  knots, 
	       const ZcGeDoubleArray&  weights,
	       double                  controlPtTol = 0.0, 
	       double                  knotTol = ZcGeKnotVector::globalKnotTolerance);

    ZcDbSpline(
               const ZcGePoint3d&  center,
	       const ZcGeVector3d& unitNormal,
	       const ZcGeVector3d& majorAxis,
	       double              radiusRatio,
	       double              startAngle = 0.0,
	       double              endAngle = 6.28318530717958647692);

    ZSoft::Boolean          isNull() const;

    ZSoft::Boolean          isRational() const;

    int                     degree() const;
    Zcad::ErrorStatus       elevateDegree(int newDegree);

    int               numControlPoints() const;
    Zcad::ErrorStatus getControlPointAt(int index, ZcGePoint3d& point) const;
    Zcad::ErrorStatus setControlPointAt(int index, const ZcGePoint3d& point);

    int               numFitPoints() const;
    Zcad::ErrorStatus getFitPointAt(int index, ZcGePoint3d& point) const;
    Zcad::ErrorStatus setFitPointAt(int index, const ZcGePoint3d& point);

    Zcad::ErrorStatus insertFitPointAt(int index, const ZcGePoint3d& point);
    Zcad::ErrorStatus removeFitPointAt(int index);

    double            fitTolerance() const;
    Zcad::ErrorStatus setFitTol(double tol);

    Zcad::ErrorStatus getFitTangents(ZcGeVector3d& startTangent, 
				     ZcGeVector3d& endTangent) const;
    Zcad::ErrorStatus setFitTangents(const ZcGeVector3d& startTangent, 
				     const ZcGeVector3d& endTangent);

    ZSoft::Boolean    hasFitData() const;

    Zcad::ErrorStatus getFitData(
                                 ZcGePoint3dArray&  fitPoints, 
			         int&               degree, 
				 double&            fitTolerance, 
				 ZSoft::Boolean&    tangentsExist,
                                 ZcGeVector3d&      startTangent, 
				 ZcGeVector3d&      endTangent) const;

    Zcad::ErrorStatus setFitData(
                                 const ZcGePoint3dArray&  fitPoints, 
				 int                   degree, 
				 double                fitTolerance, 
                                 const ZcGeVector3d&   startTangent, 
				 const ZcGeVector3d&   endTangent);

    Zcad::ErrorStatus purgeFitData();
    Zcad::ErrorStatus updateFitData();

    Zcad::ErrorStatus getNurbsData(
                                  int&              degree, 
		                  ZSoft::Boolean&   rational, 
				  ZSoft::Boolean&   closed, 
				  ZSoft::Boolean&   periodic,
	                          ZcGePoint3dArray& controlPoints, 
				  ZcGeDoubleArray&  knots, 
				  ZcGeDoubleArray&  weights,
				  double&           controlPtTol,
				  double&           knotTol) const;

    Zcad::ErrorStatus setNurbsData(
                                  int                  degree, 
				  ZSoft::Boolean       rational, 
				  ZSoft::Boolean       closed, 
				  ZSoft::Boolean       periodic,
	                          const ZcGePoint3dArray& controlPoints, 
				  const ZcGeDoubleArray& knots, 
				  const ZcGeDoubleArray& weights,
				  double               controlPtTol = 0.0,
				  double               knotTol = 0.0);

    double            weightAt(int index) const;
    Zcad::ErrorStatus setWeightAt(int index, double weight);
    Zcad::ErrorStatus insertKnot(double param);

    DBCURVE_METHODS

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

	Zcad::ErrorStatus toPolyline(ZcDbCurve*& pCurve, int precision = 10,
		int* maxSuggestedPrecision = NULL,
		unsigned int numOfVerticesThreshold = kPlineVerticesThrehold) const;
};

#pragma pack (pop)

#endif
