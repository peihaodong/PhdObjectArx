#ifndef AECMODELER_INC_IPOINT2D_H
#define AECMODELER_INC_IPOINT2D_H

#include "zivect2d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwIntPoint2d
{
public:

    ZwIntPoint2d() {} // Note: No default constructor
    ZwIntPoint2d(int xx, int yy) : x(xx), y(yy) {}

    ZwIntPoint2d  operator  +(ZwIntPoint2d  p) const { return ZwIntPoint2d (x+p.x, y+p.y); }
    ZwIntPoint2d  operator  +(ZwIntVector2d v) const { return ZwIntPoint2d (x+v.x, y+v.y); }
    ZwIntVector2d operator  -(ZwIntPoint2d  p) const { return ZwIntVector2d(x-p.x, y-p.y); }
    ZwIntPoint2d  operator  -(ZwIntVector2d v) const { return ZwIntPoint2d (x-v.x, y-v.y); }
    ZwIntPoint2d  operator  -()              const { return ZwIntPoint2d(-x, -y);        }

    int         operator [](int index)     const { return (&x)[index]; }
    int&        operator [](int index)           { return (&x)[index]; }

    bool        operator ==(ZwIntPoint2d  p) const { return x == p.x && y == p.y; }
    bool        operator !=(ZwIntPoint2d  p) const { return !(*this == p); }

    void        operator +=(ZwIntPoint2d  p) { x += p.x; y += p.y; }
    void        operator +=(ZwIntVector2d v) { x += v.x; y += v.y; }
    void        operator -=(ZwIntPoint2d  p) { x -= p.x; y -= p.y; }
    void        operator -=(ZwIntVector2d v) { x -= v.x; y -= v.y; }
        
    // Public data members
    //
    int x, y;

    static const ZwIntPoint2d kNull;

};  // Class IntPoint2d


AECMODELER_NAMESPACE_END
#endif
