

#ifndef ZC_GECOMP3D_H
#define ZC_GECOMP3D_H

#include "zgecurv3d.h"
#include "zgevptar.h"
#include "zgeintarr.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeCompositeCurve3d : public ZcGeCurve3d
{
public:
    ZcGeCompositeCurve3d  ();
    ZcGeCompositeCurve3d  (const ZcGeVoidPointerArray& curveList);
    ZcGeCompositeCurve3d  (const ZcGeVoidPointerArray& curveList,
		                   const ZcGeIntArray& isOwnerOfCurves);
    ZcGeCompositeCurve3d  (const ZcGeCompositeCurve3d& compCurve);

    void		          getCurveList       (ZcGeVoidPointerArray& curveList) const;

    ZcGeCompositeCurve3d& setCurveList       (const ZcGeVoidPointerArray& curveList);
    ZcGeCompositeCurve3d& setCurveList       (const ZcGeVoidPointerArray& curveList,
		                                      const ZcGeIntArray& isOwnerOfCurves);

	double				  globalToLocalParam ( double param, int& segNum ) const; 
	double				  localToGlobalParam ( double param, int segNum ) const;

    ZcGeCompositeCurve3d& operator =         (const ZcGeCompositeCurve3d& compCurve);
};

#pragma pack (pop)
#endif
