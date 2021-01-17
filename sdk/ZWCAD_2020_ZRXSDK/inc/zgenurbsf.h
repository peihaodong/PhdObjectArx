

#ifndef ZC_GENURBSF_H
#define ZC_GENURBSF_H

#include "zgegbl.h"
#include "zgesurf.h"
#include "zgept3dar.h"
#include "zgedblar.h"
#pragma pack (push, 8)

class ZcGeKnotVector;
class ZcGeNurbCurve3d;

class
GX_DLLEXPIMPORT
ZcGeNurbSurface : public ZcGeSurface
{
public:
   ZcGeNurbSurface();
   ZcGeNurbSurface(int degreeU, int degreeV, int propsInU, int propsInV,
                   int numControlPointsInU, int numControlPointsInV,
                   const ZcGePoint3d controlPoints[],
                   const double weights[],
                   const ZcGeKnotVector& uKnots,
                   const ZcGeKnotVector& vKnots,
                   const ZcGeTol& tol = ZcGeContext::gTol);
   ZcGeNurbSurface(const ZcGeNurbSurface& nurb);

   ZcGeNurbSurface& operator = (const ZcGeNurbSurface& nurb);

   ZSoft::Boolean   isRationalInU      () const;
   ZSoft::Boolean   isPeriodicInU      (double&) const;
   ZSoft::Boolean   isRationalInV      () const;
   ZSoft::Boolean   isPeriodicInV      (double&) const;

   int singularityInU () const;
   int singularityInV () const;

   int            degreeInU            () const;

   int            numControlPointsInU  () const;

   int            degreeInV            () const;

   int            numControlPointsInV  () const;

   void           getControlPoints     (ZcGePoint3dArray& points) const;

   ZSoft::Boolean getWeights           (ZcGeDoubleArray& weights) const;

   int       numKnotsInU    () const;
   void      getUKnots      (ZcGeKnotVector& uKnots) const;

   int       numKnotsInV    () const;
   void      getVKnots      (ZcGeKnotVector& vKnots) const;

   void      getDefinition  (int& degreeU, int& degreeV,
                             int& propsInU,	int& propsInV,
                             int& numControlPointsInU,
                             int& numControlPointsInV,
                             ZcGePoint3dArray& controlPoints,
                             ZcGeDoubleArray& weights,
                             ZcGeKnotVector& uKnots,
                             ZcGeKnotVector& vKnots) const;

   ZcGeNurbSurface& set     (int degreeU, int degreeV,
                             int propsInU, int propsInV,
                             int numControlPointsInU,
                             int numControlPointsInV,
                             const ZcGePoint3d controlPoints[],
                             const double weights[],
                             const ZcGeKnotVector& uKnots,
                             const ZcGeKnotVector& vKnots,
                             const ZcGeTol& tol = ZcGeContext::gTol);

   void           setsingularityInU(int);	// INTERNAL USE ONLY
   void           setsingularityInV(int);	// INTERNAL USE ONLY

   void           setdegreeInU(int);		// INTERNAL USE ONLY
   void           setdegreeInV(int);		// INTERNAL USE ONLY
   void           setnumControlPointsInU(int);	// INTERNAL USE ONLY
   void           setnumControlPointsInV(int);	// INTERNAL USE ONLY

   void			  setControlPoints     (ZcGePoint3dArray& points);	// INTERNAL USE ONLY
   void           setWeights           (ZcGeDoubleArray& weights);	// INTERNAL USE ONLY
   void			  setUknots      (ZcGeKnotVector& uKnots);			// INTERNAL USE ONLY
   void           setVknots      (ZcGeKnotVector& vKnots);			// INTERNAL USE ONLY

   void computeVIsoLine(double V, ZcGeNurbCurve3d& isoline) const;	// INTERNAL USE ONLY
   void computeUIsoLine(double U, ZcGeNurbCurve3d& isoline) const;	// INTERNAL USE ONLY


   int loc(int i, int j) const;		// INTERNAL USE ONLY
protected:
   void calculateNURBSProperties();	// INTERNAL USE ONLY

};

#pragma pack (pop)
#endif
