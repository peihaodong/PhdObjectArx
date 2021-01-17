#ifndef AECMODELER_INC_IVEC3D_H
#define AECMODELER_INC_IVEC3D_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwIntVector3d
{
public:

    // Note: No default constructor
    ZwIntVector3d(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

    ZwIntVector3d operator  +(ZwIntVector3d v) const { return ZwIntVector3d(x+v.x, y+v.y, z+v.z); }
    ZwIntVector3d operator  -(ZwIntVector3d v) const { return ZwIntVector3d(x-v.x, y-v.y, z-v.z); }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(ZwIntVector3d v) const { return x == v.x && y == v.y && z == v.z; }
    bool        operator !=(ZwIntVector3d v) const { return !(*this == v); }

    void        operator +=(ZwIntVector3d v)       { x += v.x; y += v.y; z += v.z; }
    void        operator -=(ZwIntVector3d v)       { x -= v.x; y -= v.y; z -= v.z; }
        
    // Public data members
    //
    int x, y, z;

};  // Class IntVector3d


AECMODELER_NAMESPACE_END
#endif
