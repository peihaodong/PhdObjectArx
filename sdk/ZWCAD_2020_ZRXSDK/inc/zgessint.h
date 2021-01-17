

#ifndef ZC_GESSINT_H
#define ZC_GESSINT_H

#include "zadesk.h"
#include "zgeent3d.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeCurve3d;
class ZcGeCurve2d;

class ZcGeSurface;

class  
GX_DLLEXPIMPORT
ZcGeSurfSurfInt  : public ZcGeEntity3d
{

public:

    ZcGeSurfSurfInt ();
    ZcGeSurfSurfInt (
						const ZcGeSurface& srf1, 
						const ZcGeSurface& srf2,
						const ZcGeTol& tol = ZcGeContext::gTol );
    ZcGeSurfSurfInt (const ZcGeSurfSurfInt& src);

    const ZcGeSurface  *surface1        () const;
    const ZcGeSurface  *surface2        () const;
    ZcGeTol            tolerance        () const;

    int                numResults (ZcGe::ZcGeIntersectError& err) const;
                    
    ZcGeCurve3d*   intCurve (int intNum, ZSoft::Boolean isExternal, ZcGe::ZcGeIntersectError& err) const;
					
    ZcGeCurve2d*   intParamCurve(int num, ZSoft::Boolean isExternal, ZSoft::Boolean isFirst, ZcGe::ZcGeIntersectError& err) const;

	ZcGePoint3d  intPoint (int intNum, ZcGe::ZcGeIntersectError& err) const;
					
    void               getIntPointParams (int intNum,
                                         ZcGePoint2d& param1, ZcGePoint2d& param2, ZcGe::ZcGeIntersectError& err) const;
	void getIntConfigs (int intNum, ZcGe::ssiConfig& surf1Left,  ZcGe::ssiConfig& surf1Right,
							ZcGe::ssiConfig& surf2Left,  ZcGe::ssiConfig& surf2Right,
							ZcGe::ssiType& intType, int& dim, ZcGe::ZcGeIntersectError& err ) const;
    int		getDimension (int intNum, ZcGe::ZcGeIntersectError& err) const;
	ZcGe::ssiType	getType(int intNum, ZcGe::ZcGeIntersectError& err ) const;

    ZcGeSurfSurfInt& set (const ZcGeSurface& srf1,
                                     const ZcGeSurface& srf2,
                                     const ZcGeTol& tol = ZcGeContext::gTol);

    ZcGeSurfSurfInt& operator = (const ZcGeSurfSurfInt& crvInt);
};
#pragma pack (pop)
#endif
