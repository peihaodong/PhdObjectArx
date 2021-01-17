#ifndef AECMODELER_INC_IPOINT3D_H
#define AECMODELER_INC_IPOINT3D_H

#include "zipoint2d.h"
#include "zivect3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwIntPoint3d
{
public:

    ZwIntPoint3d() {} // Note: No default constructor
    ZwIntPoint3d(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

    ZwIntPoint3d  operator  +(ZwIntPoint3d  p) const { return ZwIntPoint3d (x+p.x, y+p.y, z+p.z); }
    ZwIntPoint3d  operator  +(ZwIntVector3d v) const { return ZwIntPoint3d (x+v.x, y+v.y, z+v.z); }
    ZwIntVector3d operator  -(ZwIntPoint3d  p) const { return ZwIntVector3d(x-p.x, y-p.y, z-p.z); }
    ZwIntPoint3d  operator  -(ZwIntVector3d v) const { return ZwIntPoint3d (x-v.x, y-v.y, z-v.z); }
    ZwIntPoint3d  operator  -()              const { return ZwIntPoint3d(-x, -y, -z);           }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(ZwIntPoint3d  p) const { return x == p.x && y == p.y && z == p.z; }
    bool        operator !=(ZwIntPoint3d  p) const { return !(*this == p); }

    void        operator +=(ZwIntPoint3d  p) { x += p.x; y += p.y; z += p.z; }
    void        operator +=(ZwIntVector3d v) { x += v.x; y += v.y; z += v.z; }
    void        operator -=(ZwIntPoint3d  p) { x -= p.x; y -= p.y; z -= p.z; }
    void        operator -=(ZwIntVector3d v) { x -= v.x; y -= v.y; z -= v.z; }

    const ZwIntPoint2d& toIntPoint2d() const { return *((ZwIntPoint2d*)this); }
        
    // Public data members
    //
    int x, y, z;

    static const ZwIntPoint3d kNull;

};  // Class IntPoint3d


AECMODELER_NAMESPACE_END
#endif
