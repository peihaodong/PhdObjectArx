

#ifndef ZC_GEVEC2D_H
#define ZC_GEVEC2D_H

#include "zadesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix2d;

class 
GE_DLLEXPIMPORT
ZcGeVector2d
{
public:
    ZcGeVector2d();
    ZcGeVector2d(const ZcGeVector2d& vec);
    ZcGeVector2d(double x, double y);

    static const   ZcGeVector2d kIdentity;
    static const   ZcGeVector2d kXAxis;
    static const   ZcGeVector2d kYAxis;

    friend
GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    ZcGeVector2d&  setToProduct(const ZcGeMatrix2d& mat, const ZcGeVector2d& vec);
    ZcGeVector2d&  transformBy (const ZcGeMatrix2d& leftSide);
    ZcGeVector2d&  rotateBy    (double angle);
    ZcGeVector2d&  mirror      (const ZcGeVector2d& line );

    ZcGeVector2d   operator *  (double scl) const;
    friend
GE_DLLEXPIMPORT
    ZcGeVector2d   operator *  (double scl, const ZcGeVector2d& vec);
    ZcGeVector2d&  operator *= (double scl);
    ZcGeVector2d&  setToProduct(const ZcGeVector2d& vec, double scl);
    ZcGeVector2d   operator /  (double scl) const;
    ZcGeVector2d&  operator /= (double scl);

    ZcGeVector2d   operator +  (const ZcGeVector2d& vec) const;
    ZcGeVector2d&  operator += (const ZcGeVector2d& vec);
    ZcGeVector2d   operator -  (const ZcGeVector2d& vec) const;
    ZcGeVector2d&  operator -= (const ZcGeVector2d& vec);
    ZcGeVector2d&  setToSum    (const ZcGeVector2d& vec1, const ZcGeVector2d& vec2);
    ZcGeVector2d   operator -  () const;
    ZcGeVector2d&  negate      ();

    ZcGeVector2d   perpVector  () const;

    double         angle       () const;
    double         angleTo     (const ZcGeVector2d& vec) const;

    ZcGeVector2d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeVector2d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeVector2d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
			
    double         length      () const;
    double         lengthSqrd  () const;
    ZSoft::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isParallelTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isParallelTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    ZSoft::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isCodirectionalTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    ZSoft::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo(const ZcGeVector2d& vec,
						const ZcGeTol& tol, ZcGeError& flag) const;

    double         dotProduct  (const ZcGeVector2d& vec) const;

    bool operator == (const ZcGeVector2d& vec) const;
    bool operator != (const ZcGeVector2d& vec) const;
    bool isEqualTo   (const ZcGeVector2d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i) ;
    ZcGeVector2d&  set         (double x, double y);

    operator       ZcGeMatrix2d() const;

    double         x, y;
};

ZSOFT_FORCE_INLINE
ZcGeVector2d::ZcGeVector2d() : x(0.0), y(0.0)
{
}

ZSOFT_FORCE_INLINE
ZcGeVector2d::ZcGeVector2d(const ZcGeVector2d& src) : x(src.x), y(src.y)
{
}

ZSOFT_FORCE_INLINE
ZcGeVector2d::ZcGeVector2d(double xx, double yy) : x(xx), y(yy)
{
}

ZSOFT_FORCE_INLINE bool
ZcGeVector2d::operator == (const ZcGeVector2d& v) const
{
    return this->isEqualTo(v);
}

ZSOFT_FORCE_INLINE bool
ZcGeVector2d::operator != (const ZcGeVector2d& v) const
{
    return !this->isEqualTo(v);
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::operator * (double s) const
{
    return ZcGeVector2d (x * s, y * s);
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::operator *= (double s)
{
    x *= s;
    y *= s;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::setToProduct(const ZcGeVector2d& v, double s)
{
    x = s * v.x;
    y = s * v.y;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::operator / (double val) const
{
    return ZcGeVector2d (x/val, y/val);
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::operator /= (double val)
{
    x /= val;
    y /= val;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::operator + (const ZcGeVector2d& v) const
{
    return ZcGeVector2d (x + v.x, y + v.y);
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::operator += (const ZcGeVector2d& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::operator - (const ZcGeVector2d& v) const
{
    return ZcGeVector2d (x - v.x, y - v.y);
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::operator -= (const ZcGeVector2d& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::setToSum(const ZcGeVector2d& v1, const ZcGeVector2d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::operator - () const
{
    return ZcGeVector2d (-x, -y);
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::negate()
{
    x = -x;
    y = -y;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector2d
ZcGeVector2d::perpVector() const
{
    return ZcGeVector2d (-y, x);
}

ZSOFT_FORCE_INLINE double
ZcGeVector2d::lengthSqrd() const
{
    return x*x + y*y;
}

ZSOFT_FORCE_INLINE double
ZcGeVector2d::dotProduct(const ZcGeVector2d& v) const
{
    return x * v.x + y * v.y;
}

ZSOFT_FORCE_INLINE ZcGeVector2d&
ZcGeVector2d::set(double xx, double yy)
{
    x = xx;
    y = yy;
    return *this;
}

ZSOFT_FORCE_INLINE double
ZcGeVector2d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

ZSOFT_FORCE_INLINE double&
ZcGeVector2d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#define ZSOFT_ZCGEVECTOR2D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
