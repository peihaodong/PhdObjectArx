#ifndef AECMODELER_INC_IVEC2D_H
#define AECMODELER_INC_IVEC2D_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwIntVector2d
{
public:

    // Note: No default constructor
    ZwIntVector2d(int xx, int yy) : x(xx), y(yy) {}

    ZwIntVector2d operator  +(ZwIntVector2d v) const { return ZwIntVector2d(x+v.x, y+v.y); }
    ZwIntVector2d operator  -(ZwIntVector2d v) const { return ZwIntVector2d(x-v.x, y-v.y); }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(ZwIntVector2d v) const { return x == v.x && y == v.y; }
    bool        operator !=(ZwIntVector2d v) const { return !(*this == v); }

    void        operator +=(ZwIntVector2d v)       { x += v.x; y += v.y; }
    void        operator -=(ZwIntVector2d v)       { x -= v.x; y -= v.y; }
        
    // Public data members
    //
    int x, y;

};  // Class IntVector2d


AECMODELER_NAMESPACE_END
#endif
