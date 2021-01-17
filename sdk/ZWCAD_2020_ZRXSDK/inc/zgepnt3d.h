

#ifndef ZC_GEPNT3D_H
#define ZC_GEPNT3D_H

#include "zgevec3d.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;
class ZcGeLinearEnt3d;
class ZcGePlane;
class ZcGePlanarEnt;
class ZcGeVector3d;
class ZcGePoint2d;

class
GE_DLLEXPIMPORT
ZcGePoint3d
{
public:
    ZcGePoint3d();
    ZcGePoint3d(const ZcGePoint3d& pnt);
    ZcGePoint3d(double x, double y, double z);
    ZcGePoint3d(const ZcGePlanarEnt& pln, const ZcGePoint2d& pnt2d);

    static const   ZcGePoint3d    kOrigin;

    friend
GE_DLLEXPIMPORT
    ZcGePoint3d    operator *  (const ZcGeMatrix3d& mat, const ZcGePoint3d& pnt);
    ZcGePoint3d&   setToProduct(const ZcGeMatrix3d& mat, const ZcGePoint3d& pnt);

    ZcGePoint3d&   transformBy (const ZcGeMatrix3d& leftSide);
    ZcGePoint3d&   rotateBy    (double angle, const ZcGeVector3d& vec,
                                const ZcGePoint3d& wrtPoint = ZcGePoint3d::kOrigin);
    ZcGePoint3d&   mirror      (const ZcGePlane& pln);
    ZcGePoint3d&   scaleBy     (double scaleFactor, const ZcGePoint3d&
                                wrtPoint = ZcGePoint3d::kOrigin);
    ZcGePoint2d    convert2d   (const ZcGePlanarEnt& pln) const;

    ZcGePoint3d    operator *  (double scl) const;
    friend
    ZcGePoint3d    operator *  (double scl, const ZcGePoint3d& pnt);
    ZcGePoint3d&   operator *= (double scl);
    ZcGePoint3d    operator /  (double scl) const;
    ZcGePoint3d&   operator /= (double scl);

    ZcGePoint3d    operator +  (const ZcGeVector3d& vec) const;
    ZcGePoint3d&   operator += (const ZcGeVector3d& vec);
    ZcGePoint3d    operator -  (const ZcGeVector3d& vec) const;
    ZcGePoint3d&   operator -= (const ZcGeVector3d& vec);
    ZcGePoint3d&   setToSum    (const ZcGePoint3d& pnt, const ZcGeVector3d& vec);

    ZcGeVector3d   operator -  (const ZcGePoint3d& pnt) const;
    ZcGeVector3d   asVector    () const;

    double         distanceTo       (const ZcGePoint3d& pnt) const;

    ZcGePoint3d    project       (const ZcGePlane& pln, const ZcGeVector3d& vec) const;
    ZcGePoint3d    orthoProject  (const ZcGePlane& pln) const;

    bool operator == (const ZcGePoint3d& pnt) const;
    bool operator != (const ZcGePoint3d& pnt) const;
    bool isEqualTo   (const ZcGePoint3d& pnt,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int idx);
    ZcGePoint3d&   set         (double x, double y, double z);
    ZcGePoint3d&   set         (const ZcGePlanarEnt& pln, const ZcGePoint2d& pnt);

    double         x, y, z;
};

ZSOFT_FORCE_INLINE
ZcGePoint3d::ZcGePoint3d() : x(0.0), y(0.0), z(0.0)
{
}

ZSOFT_FORCE_INLINE
ZcGePoint3d::ZcGePoint3d(const ZcGePoint3d& src) : x(src.x), y(src.y), z(src.z)
{
}

ZSOFT_FORCE_INLINE
ZcGePoint3d::ZcGePoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

ZSOFT_FORCE_INLINE bool
ZcGePoint3d::operator == (const ZcGePoint3d& p) const
{
    return this->isEqualTo(p);
}

ZSOFT_FORCE_INLINE bool
ZcGePoint3d::operator != (const ZcGePoint3d& p) const
{
    return !this->isEqualTo(p);
}

ZSOFT_FORCE_INLINE ZcGePoint3d
ZcGePoint3d::operator * (double val) const
{
    return ZcGePoint3d(x*val, y*val, z*val);
}

ZSOFT_FORCE_INLINE ZcGePoint3d
operator * (double val, const ZcGePoint3d& p)
{
    return ZcGePoint3d(p.x*val, p.y*val, p.z*val);
}

ZSOFT_FORCE_INLINE ZcGePoint3d&
ZcGePoint3d::operator *= (double val)
{
    x *= val;
    y *= val;
    z *= val;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGePoint3d
ZcGePoint3d::operator / (double val) const
{
    return ZcGePoint3d (x/val, y/val, z/val);
}

ZSOFT_FORCE_INLINE ZcGePoint3d&
ZcGePoint3d::operator /= (double val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGePoint3d
ZcGePoint3d::operator + (const ZcGeVector3d& v) const
{
    return ZcGePoint3d (x + v.x, y + v.y, z + v.z);
}

ZSOFT_FORCE_INLINE ZcGePoint3d&
ZcGePoint3d::operator += (const ZcGeVector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGePoint3d
ZcGePoint3d::operator - (const ZcGeVector3d& v) const
{
    return ZcGePoint3d (x - v.x, y - v.y, z - v.z);
}

ZSOFT_FORCE_INLINE ZcGePoint3d&
ZcGePoint3d::operator -= (const ZcGeVector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGePoint3d::operator - (const ZcGePoint3d& p) const
{
    return ZcGeVector3d (x - p.x, y - p.y, z - p.z);
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGePoint3d::asVector() const
{
    return ZcGeVector3d(x, y, z);
}

ZSOFT_FORCE_INLINE ZcGePoint3d&
ZcGePoint3d::set(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

ZSOFT_FORCE_INLINE double
ZcGePoint3d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

ZSOFT_FORCE_INLINE double&
ZcGePoint3d::operator [] (unsigned int i)
{
    return *(&x+i);
}

#define ZSOFT_ZCGEPOINT3D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
