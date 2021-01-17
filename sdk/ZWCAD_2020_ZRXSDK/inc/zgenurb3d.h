

#ifndef ZC_GENURB3D_H
#define ZC_GENURB3D_H

#include "zgecurv3d.h"
#include "zgeintrvl.h"
#include "zgekvec.h"
#include "zgept3dar.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgesent3d.h"
#include "zgeplin3d.h"
#include "zgedblar.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#pragma pack (push, 8)

class ZcGeEllipArc3d;
class ZcGeLineSeg3d;

class 
GE_DLLEXPIMPORT
ZcGeNurbCurve3d : public ZcGeSplineEnt3d
{
public:

    ZcGeNurbCurve3d ();
    ZcGeNurbCurve3d (const ZcGeNurbCurve3d& src );
    ZcGeNurbCurve3d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint3dArray& cntrlPnts, 
                     ZSoft::Boolean isPeriodic = ZSoft::kFalse );
    ZcGeNurbCurve3d (int degree, const ZcGeKnotVector& knots,
                     const ZcGePoint3dArray& cntrlPnts, 
                     const ZcGeDoubleArray&  weights,
                     ZSoft::Boolean isPeriodic = ZSoft::kFalse );

    ZcGeNurbCurve3d (int degree, const ZcGePolyline3d& fitPolyline,
                     ZSoft::Boolean isPeriodic = ZSoft::kFalse );
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
				     const ZcGeVector3d& startTangent, 
				     const ZcGeVector3d& endTangent,
				     ZSoft::Boolean startTangentDefined = ZSoft::kTrue,
					 ZSoft::Boolean endTangentDefined   = ZSoft::kTrue,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol);
    ZcGeNurbCurve3d (const ZcGePoint3dArray& fitPoints, 
                     const ZcGeVector3dArray& fitTangents,
				     const ZcGeTol& fitTolerance = ZcGeContext::gTol,
				     ZSoft::Boolean isPeriodic = ZSoft::kFalse);

	ZcGeNurbCurve3d (const ZcGeEllipArc3d&  ellipse);

	ZcGeNurbCurve3d (const ZcGeLineSeg3d& linSeg);

    int             numFitPoints      () const;
    ZSoft::Boolean  getFitPointAt     (int index, ZcGePoint3d& point) const;
    ZSoft::Boolean  getFitTolerance   (ZcGeTol& fitTolerance) const;
    ZSoft::Boolean  getFitTangents    (ZcGeVector3d& startTangent, 
				                       ZcGeVector3d& endTangent) const;
    ZSoft::Boolean  getFitTangents    (ZcGeVector3d& startTangent, 
                                       ZcGeVector3d& endTangent,
                                       ZSoft::Boolean& startTangentDefined,
                                       ZSoft::Boolean& endTangentDefined) const;
    ZSoft::Boolean  getFitData        (ZcGePoint3dArray& fitPoints,
		                               ZcGeTol& fitTolerance,
				                       ZSoft::Boolean& tangentsExist,
				                       ZcGeVector3d& startTangent, 
				                       ZcGeVector3d& endTangent) const;
    void            getDefinitionData (int& degree, ZSoft::Boolean& rational,
								       ZSoft::Boolean& periodic,
			                           ZcGeKnotVector& knots,
			                           ZcGePoint3dArray& controlPoints,
			                           ZcGeDoubleArray& weights) const;
    int             numWeights        () const;
    double          weightAt          (int idx) const;
    ZSoft::Boolean  evalMode          () const;        
	ZSoft::Boolean  getParamsOfC1Discontinuity (ZcGeDoubleArray& params,
				                                const ZcGeTol& tol 
					                            = ZcGeContext::gTol) const;
	ZSoft::Boolean	getParamsOfG1Discontinuity (ZcGeDoubleArray& params,
					                            const ZcGeTol& tol 
					                            = ZcGeContext::gTol) const;

    ZSoft::Boolean   setFitPointAt    (int index, const ZcGePoint3d& point);
    ZSoft::Boolean   addFitPointAt    (int index, const ZcGePoint3d& point);
    ZSoft::Boolean   deleteFitPointAt (int index);
    ZSoft::Boolean   setFitTolerance  (const ZcGeTol& fitTol=ZcGeContext::gTol);
    ZSoft::Boolean   setFitTangents   (const ZcGeVector3d& startTangent, 
	                        	       const ZcGeVector3d& endTangent);
    ZSoft::Boolean   setFitTangents   (const ZcGeVector3d& startTangent, 
                                       const ZcGeVector3d& endTangent,
                                       ZSoft::Boolean startTangentDefined,
                                       ZSoft::Boolean endTangentDefined) const;
    ZcGeNurbCurve3d& setFitData       (const ZcGePoint3dArray& fitPoints,                                             
				                       const ZcGeVector3d& startTangent, 
				                       const ZcGeVector3d& endTangent,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    ZcGeNurbCurve3d& setFitData       (const ZcGeKnotVector& fitKnots,
		                               const ZcGePoint3dArray& fitPoints,
				                       const ZcGeVector3d& startTangent, 
				                       const ZcGeVector3d& endTangent,										 
                        			   const ZcGeTol& fitTol=ZcGeContext::gTol,
				                       ZSoft::Boolean isPeriodic=ZSoft::kFalse);
    ZcGeNurbCurve3d&  setFitData      (int degree, 
                                       const ZcGePoint3dArray& fitPoints,
				                       const ZcGeTol& fitTol=ZcGeContext::gTol);
    ZSoft::Boolean    purgeFitData    ();
    ZcGeNurbCurve3d&  addKnot         (double newKnot);
    ZcGeNurbCurve3d&  insertKnot      (double newKnot);
    ZcGeSplineEnt3d&  setWeightAt     (int idx, double val);
    ZcGeNurbCurve3d&  setEvalMode     (ZSoft::Boolean evalMode=ZSoft::kFalse );
	ZcGeNurbCurve3d&  joinWith        (const ZcGeNurbCurve3d& curve);
	ZcGeNurbCurve3d&  hardTrimByParams(double newStartParam, 
		                               double newEndParam);
    ZcGeNurbCurve3d&  makeRational    (double weight = 1.0);
    ZcGeNurbCurve3d&  makeClosed      ();
    ZcGeNurbCurve3d&  makePeriodic    ();
    ZcGeNurbCurve3d&  makeNonPeriodic ();
    ZcGeNurbCurve3d&  makeOpen        ();
    ZcGeNurbCurve3d&  elevateDegree   (int plusDegree);

    ZcGeNurbCurve3d&  operator =      (const ZcGeNurbCurve3d& spline);

	void			  setDefinitionData	(int						degree, 
											ZSoft::Boolean				rational,
											ZSoft::Boolean				periodic,
											const ZcGeKnotVector&		knots,
											const ZcGePoint3dArray&		controlPoints,
											const ZcGeDoubleArray&		weights);	// INTERNAL USE ONLY
};

#pragma pack (pop)
#endif
