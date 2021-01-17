

#ifndef ZC_GEAPLN3D_H
#define ZC_GEAPLN3D_H

#include "zgecurv3d.h"
#include "zgekvec.h"
#include "zgept3dar.h"
#include "zgevc3dar.h"
#include "zgevec3d.h"
#include "zgepnt3d.h"
#include "zgeplin3d.h"

#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeAugPolyline3d : public ZcGePolyline3d
{
public:
    ZcGeAugPolyline3d();
    ZcGeAugPolyline3d(const ZcGeAugPolyline3d& apline);
    ZcGeAugPolyline3d(const ZcGeKnotVector& knots,
                      const ZcGePoint3dArray& cntrlPnts,
                      const ZcGeVector3dArray& vecBundle);
    ZcGeAugPolyline3d(const ZcGePoint3dArray& cntrlPnts,
                      const ZcGeVector3dArray& vecBundle);

    ZcGeAugPolyline3d(const ZcGeCurve3d& curve,
                      double fromParam, double toParam, 
		              double apprEps);

    ZcGeAugPolyline3d& operator = (const ZcGeAugPolyline3d& apline);

    ZcGePoint3d           getPoint(int idx) const;
    ZcGeAugPolyline3d&    setPoint(int idx, ZcGePoint3d pnt);
    void                  getPoints(ZcGePoint3dArray& pnts) const;

    ZcGeVector3d          getVector(int idx) const;
    ZcGeAugPolyline3d&    setVector(int idx, ZcGeVector3d pnt);
    void                  getD1Vectors(ZcGeVector3dArray& tangents) const;

    ZcGeVector3d          getD2Vector(int idx) const;
    ZcGeAugPolyline3d&    setD2Vector(int idx, ZcGeVector3d pnt);
    void                  getD2Vectors(ZcGeVector3dArray& d2Vectors) const;

	double                approxTol      () const;
    ZcGeAugPolyline3d&    setApproxTol   (double approxTol);

};

#pragma pack (pop)
#endif
