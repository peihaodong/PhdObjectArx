

#ifndef ZC_GEVEC3D_H
#define ZC_GEVEC3D_H

#include "zadesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;
class ZcGeVector2d;
class ZcGePlane;
class ZcGePlanarEnt;

class 
GE_DLLEXPIMPORT
ZcGeVector3d
{
public:
    ZcGeVector3d();
    ZcGeVector3d(const ZcGeVector3d& vec);
    ZcGeVector3d(double x, double y, double z);
    ZcGeVector3d(const ZcGePlanarEnt&, const ZcGeVector2d&);

    static const   ZcGeVector3d kIdentity;
    static const   ZcGeVector3d kXAxis;
    static const   ZcGeVector3d kYAxis;
    static const   ZcGeVector3d kZAxis;

    friend
GE_DLLEXPIMPORT
    ZcGeVector3d   operator *  (const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);
    ZcGeVector3d&  setToProduct(const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);

    ZcGeVector3d&  transformBy (const ZcGeMatrix3d& leftSide);
    ZcGeVector3d&  rotateBy    (double ang , const ZcGeVector3d& axis );
    ZcGeVector3d&  mirror      (const ZcGeVector3d& normalToPlane);
    ZcGeVector2d   convert2d   (const ZcGePlanarEnt& pln) const;

    ZcGeVector3d   operator *  (double scl) const;
    friend
GE_DLLEXPIMPORT
    ZcGeVector3d   operator *  (double scl, const ZcGeVector3d& vec);
    ZcGeVector3d&  operator *= (double scl);
    ZcGeVector3d&  setToProduct(const ZcGeVector3d& vec, double scl);
    ZcGeVector3d   operator /  (double scl) const;
    ZcGeVector3d&  operator /= (double scl);

    ZcGeVector3d   operator +  (const ZcGeVector3d& vec) const;
    ZcGeVector3d&  operator += (const ZcGeVector3d& vec);
    ZcGeVector3d   operator -  (const ZcGeVector3d& vec) const;
    ZcGeVector3d&  operator -= (const ZcGeVector3d& vec);
    ZcGeVector3d&  setToSum    (const ZcGeVector3d& vec1, const ZcGeVector3d& vec2);
    ZcGeVector3d   operator -  () const;
    ZcGeVector3d&  negate      ();

    ZcGeVector3d   perpVector  () const;

    double         angleTo     (const ZcGeVector3d& vec) const;
    double         angleTo     (const ZcGeVector3d& vec,
                                const ZcGeVector3d& refVec) const;
    double         angleOnPlane(const ZcGePlanarEnt& pln) const;

    ZcGeVector3d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZcGeVector3d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
    ZcGeVector3d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
		
    double         length      () const;
    double         lengthSqrd  () const;
    ZSoft::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol, ZcGeError& flag) const;

    ZSoft::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;

    ZSoft::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;

    double         dotProduct  (const ZcGeVector3d& vec) const;
    ZcGeVector3d   crossProduct(const ZcGeVector3d& vec) const;

    ZcGeMatrix3d   rotateTo    (const ZcGeVector3d& vec, const ZcGeVector3d& axis
                                = ZcGeVector3d::kIdentity) const;

    ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection) const;
    ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection,  
								 const ZcGeTol& tol, ZcGeError& flag) const;

    ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal) const;
    ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal, 
								const ZcGeTol& tol, ZcGeError& flag) const;

    bool operator == (const ZcGeVector3d& vec) const;
    bool operator != (const ZcGeVector3d& vec) const;
    bool isEqualTo   (const ZcGeVector3d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         operator [] (unsigned int i) const;
    double&        operator [] (unsigned int i);
    unsigned int   largestElement() const;
    ZcGeVector3d&  set         (double x, double y, double z);
    ZcGeVector3d&  set         (const ZcGePlanarEnt& pln, const ZcGeVector2d& vec);

    operator       ZcGeMatrix3d() const;

    double         x, y, z;
};

ZSOFT_FORCE_INLINE
ZcGeVector3d::ZcGeVector3d() : x(0.0), y(0.0), z(0.0)
{
}

ZSOFT_FORCE_INLINE
ZcGeVector3d::ZcGeVector3d(const ZcGeVector3d& src) : x(src.x),y(src.y),z(src.z)
{
}

ZSOFT_FORCE_INLINE
ZcGeVector3d::ZcGeVector3d(double xx, double yy, double zz) : x(xx),y(yy),z(zz)
{
}

ZSOFT_FORCE_INLINE bool
ZcGeVector3d::operator == (const ZcGeVector3d& v) const
{
    return this->isEqualTo(v);
}

ZSOFT_FORCE_INLINE bool
ZcGeVector3d::operator != (const ZcGeVector3d& v) const
{
    return !this->isEqualTo(v);
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGeVector3d::operator + (const ZcGeVector3d& v) const
{
    return ZcGeVector3d (x + v.x, y + v.y, z + v.z);
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::operator += (const ZcGeVector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGeVector3d::operator - (const ZcGeVector3d& v) const
{
    return ZcGeVector3d (x - v.x, y - v.y, z - v.z);
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::operator -= (const ZcGeVector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::setToSum(const ZcGeVector3d& v1, const ZcGeVector3d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGeVector3d::operator - () const
{
    return ZcGeVector3d (-x, -y, -z);
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::negate()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGeVector3d::operator * (double s) const
{
    return ZcGeVector3d (x * s, y * s, z * s);
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::operator *= (double s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::setToProduct(const ZcGeVector3d& v, double s)
{
    x = s * v.x;
    y = s * v.y;
    z = s * v.z;
    return *this;
}

ZSOFT_FORCE_INLINE ZcGeVector3d
ZcGeVector3d::operator / (double val) const
{
    return ZcGeVector3d (x/val, y/val, z/val);
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::operator /= (double val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

ZSOFT_FORCE_INLINE double
ZcGeVector3d::lengthSqrd() const
{
    return x*x + y*y + z*z;
}

ZSOFT_FORCE_INLINE double
ZcGeVector3d::dotProduct(const ZcGeVector3d& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

ZSOFT_FORCE_INLINE ZcGeVector3d&
ZcGeVector3d::set(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

ZSOFT_FORCE_INLINE double
ZcGeVector3d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

ZSOFT_FORCE_INLINE double& ZcGeVector3d::operator [] (unsigned int i)
{
    return *(&x+i);
}
#define ZSOFT_ZCGEVECTOR3D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
