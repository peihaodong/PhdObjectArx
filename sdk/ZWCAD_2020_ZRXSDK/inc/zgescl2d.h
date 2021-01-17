

#ifndef ZC_GESCL2D_H
#define ZC_GESCL2D_H

#include "zadesk.h"
#include "zgegbl.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;
class ZcGeScale3d;

class 
GE_DLLEXPIMPORT
ZcGeScale2d
{
public:
    ZcGeScale2d();
    ZcGeScale2d(const ZcGeScale2d& src);
    ZcGeScale2d(double factor);
    ZcGeScale2d(double xFactor, double yFactor);

    static const   ZcGeScale2d kIdentity;

    ZcGeScale2d    operator *  (const ZcGeScale2d& sclVec) const;
    ZcGeScale2d&   operator *= (const ZcGeScale2d& scl);
    ZcGeScale2d&   preMultBy   (const ZcGeScale2d& leftSide);
    ZcGeScale2d&   postMultBy  (const ZcGeScale2d& rightSide);
    ZcGeScale2d&   setToProduct(const ZcGeScale2d& sclVec1, const ZcGeScale2d& sclVec2);
    ZcGeScale2d    operator *  (double s) const;
    ZcGeScale2d&   operator *= (double s);
    ZcGeScale2d&   setToProduct(const ZcGeScale2d& sclVec, double s);
    friend
GE_DLLEXPIMPORT
    ZcGeScale2d    operator *  (double, const ZcGeScale2d& scl);

    ZcGeScale2d    inverse        () const;
    ZcGeScale2d&   invert         ();

    ZSoft::Boolean isProportional(const ZcGeTol& tol = ZcGeContext::gTol) const;

    bool operator == (const ZcGeScale2d& sclVec) const;
    bool operator != (const ZcGeScale2d& sclVec) const;
    bool isEqualTo   (const ZcGeScale2d& scaleVec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i);
    ZcGeScale2d&   set         (double sc0, double sc1);

    operator       ZcGeMatrix2d   () const;
    void           getMatrix      (ZcGeMatrix2d& mat) const;
    ZcGeScale2d&   extractScale   ( const ZcGeMatrix2d& mat );
    ZcGeScale2d&   removeScale    ( ZcGeMatrix2d& mat );

    operator       ZcGeScale3d    () const;

    double         sx, sy;
};

ZSOFT_FORCE_INLINE double
ZcGeScale2d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

ZSOFT_FORCE_INLINE double&
ZcGeScale2d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

ZSOFT_FORCE_INLINE bool
ZcGeScale2d::operator == (const ZcGeScale2d& s) const
{
    return this->isEqualTo(s);
}

ZSOFT_FORCE_INLINE bool
ZcGeScale2d::operator != (const ZcGeScale2d& s) const
{
    return !this->isEqualTo(s);
}

#pragma pack (pop)
#endif
