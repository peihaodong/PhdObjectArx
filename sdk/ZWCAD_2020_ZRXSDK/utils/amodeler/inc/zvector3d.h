#ifndef AECMODELER_INC_VECTOR3D_H
#define AECMODELER_INC_VECTOR3D_H

#include <math.h>
#include "zvector2d.h"
class ZcGeVector3d;

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwVector3d
{
public:

    ZwVector3d() {} // Note: No default constructor
    ZwVector3d(double xx, double yy, double zz) : x(xx),   y(yy),   z(zz)   {}
    //Vector3d(Vector2d     v)                  : x(v.x),  y(v.y),  z(0)    {}
    //Vector3d(IntVector3d iv)                  : x(iv.x), y(iv.y), z(iv.z) {}

    ZwVector3d operator + (ZwVector3d v)    const { return ZwVector3d(x+v.x, y+v.y, z+v.z); }
    ZwVector3d operator - (ZwVector3d v)    const { return ZwVector3d(x-v.x, y-v.y, z-v.z); }
    double   operator % (ZwVector3d v)    const { return x*v.x+y*v.y+z*v.z;             }
    ZwVector3d operator * (ZwVector3d v)    const; // Cross product
    ZwVector3d operator - ()              const { return ZwVector3d(-x, -y, -z);          }

    ZwVector3d operator * (double scalar) const { return ZwVector3d(x*scalar, y*scalar, z*scalar); }
    ZwVector3d operator / (double scalar) const { return ZwVector3d(x/scalar, y/scalar, z/scalar); }

    double   operator [](int index)     const { return (&x)[index]; }
    double&  operator [](int index)           { return (&x)[index]; }

    double   length     ()              const { return sqrt(x*x+y*y+z*z);       }
    double   lengthSqrd ()              const { return x*x+y*y+z*z;             }
    double   lengthRect ()              const { return fabs(x)+fabs(y)+fabs(z); }

    ZwVector3d normalize  () const;

    double   dist       (ZwVector3d v)    const { return (*this-v).length();     }
    double   distSqrd   (ZwVector3d v)    const { return (*this-v).lengthSqrd(); }
    double   distRect   (ZwVector3d v)    const { return (*this-v).lengthRect(); }

    bool     isEqual    (ZwVector3d v, double epsSqrd = ZwEpsNorSqrd()) const { return (distSqrd(v) <= epsSqrd); }
    bool     isEqualRect(ZwVector3d v, double epsRect = ZwEpsNor()    ) const { return (distRect(v) <= epsRect); }

    double   angle      (const ZwVector3d&) const;

    void     operator +=(ZwVector3d    v) { x += v.x; y += v.y; z += v.z; }
    void     operator -=(ZwVector3d    v) { x -= v.x; y -= v.y; z -= v.z; }
    void     operator *=(double scalar) { x *= scalar; y *= scalar; z *= scalar; }
    void     operator /=(double scalar) { x /= scalar; y /= scalar; z /= scalar; }

    ZwVector3d perpend() const;

    void     operator *=(const ZwTransf3d&);

    bool     isNull     (double epsSqrd = ZwEpsNorSqrd()) const { return lengthSqrd() <= epsSqrd; }
    bool     isParallel (const ZwVector3d&, double epsNorSqrd = ZwEpsNorSqrd()) const;
    bool     isParallelNorm(const ZwVector3d&, double epsNorSqrd = ZwEpsNorSqrd()) const; // For normalized vectors
    bool     isPerpend  (const ZwVector3d&, double epsNor = ZwEpsNor()) const;
    bool     isExactNull() const { return x == 0 && y == 0 && z == 0; }

    void     orthoPlane (int& i1, int& i2)          const;
    void     orthoPlane (int& i1, int& i2, int& i3) const;

    int      dominantDirection() const;

    //const Vector2d& toVector2d ()               const { return *((Vector2d*)this);             }
    //Vector2d        toVector2d (int i1, int i2) const { return Vector2d((*this)[i1], (*this)[i2]); }
    //Vector2d        toVector2d (int dropCoord ) const; 

    // Casts from ZModeler::Vector3d to ZcGeVector3d
    //
    operator       ZcGeVector3d& ()       { return *((ZcGeVector3d*)this);       }
    operator const ZcGeVector3d& () const { return *((const ZcGeVector3d*)this); }

    // Cast from l-value ZcGeVector3d to l-value ZModeler::Vector3d. This 
    // explicit cast function needs to be used only for l-values, e.g. when 
    // ZModeler returns a Vector3d but we want to capture it in an ZcGeVector3d.
    // For non-l-values, the Vector3d(const ZcGeVector3d&) constructor will 
    // perform the cast automatically.
    //
    static ZwVector3d& cast(ZcGeVector3d& v) { return *(ZwVector3d*)&v; }

    ZwVector3d(const ZcGeVector3d& v)        { *this = *(ZwVector3d*)&v; }

    static ZwVector3d random();
    
    // Public data members
    //
    double x, y, z;

    static const ZwVector3d kNull;
    static const ZwVector3d kXDir;
    static const ZwVector3d kYDir;
    static const ZwVector3d kZDir;

}; // class Vector3d


inline ZwVector3d operator *(double scalar, ZwVector3d v) 
{ 
    return ZwVector3d(scalar*v.x, scalar*v.y, scalar*v.z); 
}



inline ZwVector3d ZwVector3d::operator *(ZwVector3d v) const
{
    return ZwVector3d(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

inline double det(ZwVector3d a, ZwVector3d b, ZwVector3d c)
{
    return (a.x * (b.y*c.z - b.z*c.y) +
            a.y * (b.z*c.x - b.x*c.z) +
            a.z * (b.x*c.y - b.y*c.x));
} 

AECMODELER_NAMESPACE_END
#endif
