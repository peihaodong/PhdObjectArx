

#ifndef ZC_GECOMP2D_H
#define ZC_GECOMP2D_H

#include "zgecurv2d.h"
#include "zgevptar.h"
#include "zgeintarr.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
ZcGeCompositeCurve2d : public ZcGeCurve2d
{
public:
    ZcGeCompositeCurve2d  ();
    ZcGeCompositeCurve2d  (const ZcGeVoidPointerArray& curveList);
    ZcGeCompositeCurve2d  (const ZcGeVoidPointerArray& curveList,
		                   const ZcGeIntArray& isOwnerOfCurves);
    ZcGeCompositeCurve2d  (const ZcGeCompositeCurve2d& compCurve);

    void		          getCurveList       (ZcGeVoidPointerArray& curveList) const;

    ZcGeCompositeCurve2d& setCurveList       (const ZcGeVoidPointerArray& curveList);
    ZcGeCompositeCurve2d& setCurveList       (const ZcGeVoidPointerArray& curveList,
		                                      const ZcGeIntArray& isOwnerOfCurves);

	double				  globalToLocalParam ( double param, int& crvNum ) const; 
	double				  localToGlobalParam ( double param, int crvNum ) const;

    ZcGeCompositeCurve2d& operator =         (const ZcGeCompositeCurve2d& compCurve);
};

#pragma pack (pop)
#endif
