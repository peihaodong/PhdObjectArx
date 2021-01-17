

#ifndef ZC_GEENT2D_H
#define ZC_GEENT2D_H

#include "zgegbl.h"
#include "zgepnt2d.h"
#include "zgeintrvl.h"
#include "zgegblnew.h"
#pragma pack (push, 8)

class ZcGeImpEntity3d;
class
GE_DLLEXPIMPORT
ZcGeEntity2d
{
public:
    ~ZcGeEntity2d();

    ZSoft::Boolean   isKindOf    (ZcGe::EntityId entType) const;
    ZcGe::EntityId   type        () const;

    ZcGeEntity2d*    copy        () const;
    ZcGeEntity2d&    operator =  (const ZcGeEntity2d& entity);

    ZSoft::Boolean   operator == (const ZcGeEntity2d& entity) const;
    ZSoft::Boolean   operator != (const ZcGeEntity2d& entity) const;
    ZSoft::Boolean   isEqualTo   (const ZcGeEntity2d& entity,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeEntity2d&    transformBy (const ZcGeMatrix2d& xfm);
    ZcGeEntity2d&    translateBy (const ZcGeVector2d& translateVec);
    ZcGeEntity2d&    rotateBy    (double angle, const ZcGePoint2d& wrtPoint
                                  = ZcGePoint2d::kOrigin);      
    ZcGeEntity2d&    mirror      (const ZcGeLine2d& line);
    ZcGeEntity2d&    scaleBy     (double scaleFactor,
                                  const ZcGePoint2d& wrtPoint
                                  = ZcGePoint2d::kOrigin);

    ZSoft::Boolean   isOn        (const ZcGePoint2d& pnt,
                                  const ZcGeTol& tol = ZcGeContext::gTol) const;
protected:
    friend class ZcGeEntity3d;
    friend class ZcGeImpEntity3d;
    ZcGeImpEntity3d* mpImpEnt;
    int mDelEnt;
    ZcGeEntity2d ();
    ZcGeEntity2d (const ZcGeEntity2d&);
    ZcGeEntity2d (ZcGeImpEntity3d&, int);
    ZcGeEntity2d (ZcGeImpEntity3d*);
    ZcGeEntity2d*    newEntity2d (ZcGeImpEntity3d*) const;
};

ZSOFT_FORCE_INLINE ZcGeEntity2d*
ZcGeEntity2d::newEntity2d (ZcGeImpEntity3d *impEnt ) const
{
    return GENEWLOC( ZcGeEntity2d, this) ( impEnt );
}

#pragma pack (pop)
#endif
