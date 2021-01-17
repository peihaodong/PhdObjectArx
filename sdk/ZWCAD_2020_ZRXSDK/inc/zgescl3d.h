

#ifndef ZC_GESCL3D_H
#define ZC_GESCL3D_H

#include "zadesk.h"
#include "zgegbl.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;

class 
GE_DLLEXPIMPORT
ZcGeScale3d
{
public:
    ZcGeScale3d();
    ZcGeScale3d(const ZcGeScale3d& src);
    ZcGeScale3d(double factor);
    ZcGeScale3d(double xFact, double yFact, double zFact);

    static const   ZcGeScale3d kIdentity;

    ZcGeScale3d    operator *  (const ZcGeScale3d& sclVec) const;
    ZcGeScale3d&   operator *= (const ZcGeScale3d& scl);
    ZcGeScale3d&   preMultBy   (const ZcGeScale3d& leftSide);
    ZcGeScale3d&   postMultBy  (const ZcGeScale3d& rightSide);
    ZcGeScale3d&   setToProduct(const ZcGeScale3d& sclVec1, const ZcGeScale3d& sclVec2);
    ZcGeScale3d    operator *  (double s) const;
    ZcGeScale3d&   operator *= (double s);
    ZcGeScale3d&   setToProduct(const ZcGeScale3d& sclVec, double s);
    friend
GE_DLLEXPIMPORT
    ZcGeScale3d    operator *  (double, const ZcGeScale3d& scl);

    ZcGeScale3d    inverse        () const;
    ZcGeScale3d&   invert         ();

    ZSoft::Boolean isProportional(const ZcGeTol& tol = ZcGeContext::gTol) const;

    bool operator == (const ZcGeScale3d& sclVec) const;
    bool operator != (const ZcGeScale3d& sclVec) const;
    bool isEqualTo   (const ZcGeScale3d& scaleVec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i);
    ZcGeScale3d&   set         (double sc0, double sc1, double sc2);

    operator       ZcGeMatrix3d   () const;
    void getMatrix(ZcGeMatrix3d& mat) const;
    ZcGeScale3d&   extractScale   ( const ZcGeMatrix3d& mat );
    ZcGeScale3d&   removeScale    ( ZcGeMatrix3d& mat );

    double         sx, sy, sz;
};

ZSOFT_FORCE_INLINE bool
ZcGeScale3d::operator == (const ZcGeScale3d& s) const
{
    return this->isEqualTo(s);
}

ZSOFT_FORCE_INLINE bool
ZcGeScale3d::operator != (const ZcGeScale3d& s) const
{
    return !(this->isEqualTo(s));
}

ZSOFT_FORCE_INLINE double
ZcGeScale3d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

ZSOFT_FORCE_INLINE double&
ZcGeScale3d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

#pragma pack (pop)
#endif
