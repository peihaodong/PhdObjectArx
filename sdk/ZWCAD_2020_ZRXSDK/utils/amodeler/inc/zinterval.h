#ifndef AECMODELER_INC_INTERVAL_H
#define AECMODELER_INC_INTERVAL_H

#include <limits.h>
#include "zplane.h"
#include "zipoint2d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwInterval1d
{
public:

    ZwInterval1d(                  ) : lower(kMaxReal), upper(kMinReal) {}
    ZwInterval1d(double         val) : lower(val),  upper(val)          {}
    ZwInterval1d(double a, double b)        
    {
        if (a < b) { lower = a; upper = b; } else { lower = b; upper = a; } 
    }
    
    ZwInterval1d(double a, double b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    void operator +=(double val)
    {
        if (val < lower) lower = val;
        if (val > upper) upper = val;
    }
    
    void operator +=(const ZwInterval1d interv)
    {
        if (interv.lower < lower) lower = interv.lower;
        if (interv.upper > upper) upper = interv.upper;
    }

    void operator *=(const ZwInterval1d interv)
    {
        if (interv.lower > lower) lower = interv.lower;
        if (interv.upper < upper) upper = interv.upper;
    }
    
    ZwInterval1d operator *(const ZwInterval1d interv) const
    {
        return ZwInterval1d(__max(lower, interv.lower), __min(upper, interv.upper));
    }

    ZwInterval1d operator +(ZwInterval1d interv) const
    {
        ZwInterval1d tmp = *this;
        tmp += interv;
        return tmp;
    }

    // Do the two intervals overlap ?
    //
    bool operator &&(const ZwInterval1d interv) const
    {
        return lower <= interv.upper && upper >= interv.lower;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(const ZwInterval1d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else
        {
            return lower >= interv.lower && upper <= interv.upper;
        }
    }

    bool operator &&(double val) const
    {
        return lower <= val && val <= upper;
    }
        
    void   enlarge(double howMuch = 10*ZwEpsAbs());

    double length () const { return upper - lower;         }
    double mid    () const { return (upper + lower) * 0.5; }
    bool   isNull () const { return lower > upper;         }
    void   init   ()       { *this = kNull;                }

    static const ZwInterval1d kNull;

    // Public data members
    //
    double lower;
    double upper;

};  // class Interval1d


inline bool operator &&(double val, ZwInterval1d interv) 
{
    return interv.lower <= val && val <= interv.upper;
}



class DllImpExp ZwInterval2d
{
public:

    ZwInterval2d() : lower(kMaxReal, kMaxReal), upper(kMinReal, kMinReal) {}
    ZwInterval2d(int /*doNotIntialize*/)                                  {}
    ZwInterval2d(ZwPoint2d p) : lower(p), upper(p)                          {}
    ZwInterval2d(ZwPoint2d a, const ZwPoint2d b) 
    {
        if (a.x < b.x) { lower.x = a.x; upper.x = b.x; } else { lower.x = b.x; upper.x = a.x; }
        if (a.y < b.y) { lower.y = a.y; upper.y = b.y; } else { lower.y = b.y; upper.y = a.y; }
    }

    ZwInterval2d(ZwPoint2d center, double halfSize)
    {
        lower.x = center.x - halfSize;
        upper.x = center.x + halfSize;
        lower.y = center.y - halfSize;
        upper.y = center.y + halfSize;
    }

    ZwInterval2d(ZwPoint2d a, ZwPoint2d b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    void operator +=(ZwPoint2d p)
    {
        if (p.x < lower.x) lower.x = p.x;
        if (p.x > upper.x) upper.x = p.x;

        if (p.y < lower.y) lower.y = p.y;
        if (p.y > upper.y) upper.y = p.y;
    }

    void operator +=(ZwInterval2d interv)
    {
        if (interv.lower.x < lower.x) lower.x = interv.lower.x;
        if (interv.upper.x > upper.x) upper.x = interv.upper.x;
        if (interv.lower.y < lower.y) lower.y = interv.lower.y;
        if (interv.upper.y > upper.y) upper.y = interv.upper.y;
    }

    void operator *=(ZwInterval2d interv)
    {
        if (interv.lower.x > lower.x) lower.x = interv.lower.x;
        if (interv.upper.x < upper.x) upper.x = interv.upper.x;
        if (interv.lower.y > lower.y) lower.y = interv.lower.y;
        if (interv.upper.y < upper.y) upper.y = interv.upper.y;
    }

    ZwInterval2d operator *(ZwInterval2d interv) const
    {
        ZwInterval2d result;

        result.lower.x = __max(lower.x, interv.lower.x);
        result.upper.x = __min(upper.x, interv.upper.x);
        result.lower.y = __max(lower.y, interv.lower.y);
        result.upper.y = __min(upper.y, interv.upper.y);
        return result;
    }

    ZwInterval2d operator +(ZwInterval2d interv) const
    {
        ZwInterval2d tmp = *this;
        tmp += interv;
        return tmp;
    }

    bool operator &&(ZwInterval2d interv) const
    {
        return lower.x <= interv.upper.x && upper.x >= interv.lower.x &&
               lower.y <= interv.upper.y && upper.y >= interv.lower.y;
    }

    bool operator &&(ZwPoint2d p) const
    {
        return lower.x <= p.x && p.x <= upper.x &&
               lower.y <= p.y && p.y <= upper.y;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(const ZwInterval2d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else
        {
            return lower.x >= interv.lower.x && upper.x <= interv.upper.x &&
                   lower.y >= interv.lower.y && upper.y <= interv.upper.y;
        }
    }

    bool    isNull ()      const { return lower.x > upper.x || lower.y > upper.y; }
    ZwPoint2d mid    ()      const { return (lower + upper) * 0.5;           }
    double  length ()      const { return lower.dist(upper);               }
    double  length (int i) const { return upper[i] - lower[i];             }
    void    init   ()            { *this = kNull;                          }
    void    enlarge(double howMuch = 10*ZwEpsAbs());

    static const ZwInterval2d kNull;

    // Public data members
    //
    ZwPoint2d lower;
    ZwPoint2d upper;

};  // class Interval2d


inline bool operator &&(const ZwPoint2d p, ZwInterval2d interv) 
{
    return interv.lower.x <= p.x && p.x <= interv.upper.x &&
           interv.lower.y <= p.y && p.y <= interv.upper.y;
}



class DllImpExp ZwInterval3d
{
public:

    ZwInterval3d() { lower.x = lower.y = lower.z = kMaxReal; upper.x = upper.y = upper.z = kMinReal; }
    ZwInterval3d(int /*doNotIntialize*/)                      {}
    ZwInterval3d(ZwPoint3d p)              : lower(p), upper(p) {}
    ZwInterval3d(ZwPoint3d a, ZwPoint3d b) 
    {
        if (a.x < b.x) { lower.x = a.x; upper.x = b.x; } else { lower.x = b.x; upper.x = a.x; }
        if (a.y < b.y) { lower.y = a.y; upper.y = b.y; } else { lower.y = b.y; upper.y = a.y; }
        if (a.z < b.z) { lower.z = a.z; upper.z = b.z; } else { lower.z = b.z; upper.z = a.z; }
    }

    ZwInterval3d(ZwPoint3d a, ZwPoint3d b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    ZwInterval3d(ZwPoint3d center, double halfSize)
    {
        lower.x = center.x - halfSize;
        upper.x = center.x + halfSize;
        lower.y = center.y - halfSize;
        upper.y = center.y + halfSize;
        lower.z = center.z - halfSize;
        upper.z = center.z + halfSize;
    }

    void operator +=(ZwPoint3d p)
    {
        if (p.x < lower.x) lower.x = p.x;
        if (p.x > upper.x) upper.x = p.x;
        if (p.y < lower.y) lower.y = p.y;
        if (p.y > upper.y) upper.y = p.y;
        if (p.z < lower.z) lower.z = p.z;
        if (p.z > upper.z) upper.z = p.z;
    }

    void operator +=(ZwInterval3d interv)
    {
        if (interv.lower.x < lower.x) lower.x = interv.lower.x;
        if (interv.upper.x > upper.x) upper.x = interv.upper.x;
        if (interv.lower.y < lower.y) lower.y = interv.lower.y;
        if (interv.upper.y > upper.y) upper.y = interv.upper.y;
        if (interv.lower.z < lower.z) lower.z = interv.lower.z;
        if (interv.upper.z > upper.z) upper.z = interv.upper.z;
    }

    ZwInterval3d operator +(ZwInterval3d interv) const
    {
        ZwInterval3d tmp = *this;
        tmp += interv;
        return tmp;
    }

    void operator *=(ZwInterval3d interv)
    {
        if (interv.lower.x > lower.x) lower.x = interv.lower.x;
        if (interv.upper.x < upper.x) upper.x = interv.upper.x;
        if (interv.lower.y > lower.y) lower.y = interv.lower.y;
        if (interv.upper.y < upper.y) upper.y = interv.upper.y;
        if (interv.lower.z > lower.z) lower.z = interv.lower.z;
        if (interv.upper.z < upper.z) upper.z = interv.upper.z;
    }

    ZwInterval3d operator *(ZwInterval3d interv) const
    {
        ZwInterval3d result;

        result.lower.x = __max(lower.x, interv.lower.x);
        result.upper.x = __min(upper.x, interv.upper.x);
        result.lower.y = __max(lower.y, interv.lower.y);
        result.upper.y = __min(upper.y, interv.upper.y);
        result.lower.z = __max(lower.z, interv.lower.z);
        result.upper.z = __min(upper.z, interv.upper.z);
        return result;
    }

    ZwInterval3d operator *(const ZwLine3d& ray) const;

    bool operator &&(ZwInterval3d interv) const
    {
        return lower.x <= interv.upper.x && upper.x >= interv.lower.x &&
               lower.y <= interv.upper.y && upper.y >= interv.lower.y &&
               lower.z <= interv.upper.z && upper.z >= interv.lower.z;
    }

    bool operator &&(ZwPoint3d p) const
    {
        return lower.x <= p.x && p.x <= upper.x &&
               lower.y <= p.y && p.y <= upper.y &&
               lower.z <= p.z && p.z <= upper.z;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(ZwInterval3d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else 
        {
            return lower.x >= interv.lower.x && upper.x <= interv.upper.x &&
                   lower.y >= interv.lower.y && upper.y <= interv.upper.y &&
                   lower.z >= interv.lower.z && upper.z <= interv.upper.z;
        }
    }

    ZwInterval2d toInterval2d(int dropCoord) const
    {
        switch (dropCoord)
        {
        case 0:
            return ZwInterval2d(ZwPoint2d(lower.y, lower.z), ZwPoint2d(upper.y, upper.z));
        case 1:
            return ZwInterval2d(ZwPoint2d(lower.z, lower.x), ZwPoint2d(upper.z, upper.x));
        default:
            return ZwInterval2d(ZwPoint2d(lower.x, lower.y), ZwPoint2d(upper.x, upper.y));
        }
    }

    bool    isNull ()      const { return lower.x > upper.x || lower.y > upper.y || lower.z > upper.z; }
    ZwPoint3d mid    ()      const { return (lower + upper) * 0.5; }
    double  length ()      const { return lower.dist(upper); }
    double  length (int i) const { return upper[i] - lower[i]; }
    void    init   ()            { *this = kNull; }
    void    enlarge(double howMuch = 10*ZwEpsAbs());

    ZwPoint3d lowerInDirection(const ZwVector3d& direction) const
    {
        return ZwPoint3d(direction.x >= 0.0 ? lower.x : upper.x,
                       direction.y >= 0.0 ? lower.y : upper.y,
                       direction.z >= 0.0 ? lower.z : upper.z);
    }

    ZwPoint3d upperInDirection(const ZwVector3d& direction) const
    {
        return ZwPoint3d(direction.x >= 0.0 ? upper.x : lower.x,
                       direction.y >= 0.0 ? upper.y : lower.y,
                       direction.z >= 0.0 ? upper.z : lower.z);
    }
 
    bool intersectsPlane( const ZwPlane& plane) const
    {
        return plane.dist(lowerInDirection(plane.normal)) <=  ZwEpsAbs() &&
               plane.dist(upperInDirection(plane.normal)) >= -ZwEpsAbs();
    }

    static const ZwInterval3d kNull;

    // Public data members
    //
    ZwPoint3d lower;
    ZwPoint3d upper;

};  // class Interval3d



inline bool operator &&(ZwPoint3d p, ZwInterval3d interv) 
{
    return interv.lower.x <= p.x && p.x <= interv.upper.x &&
           interv.lower.y <= p.y && p.y <= interv.upper.y &&
           interv.lower.z <= p.z && p.z <= interv.upper.z;
}



class DllImpExp ZwIntInterval1d
{
public:

    ZwIntInterval1d()         : lower(INT_MAX), upper(INT_MIN) {}
    ZwIntInterval1d(int val ) : lower(val), upper(val)         {}
    ZwIntInterval1d(int a, int b)
    {
        if (a < b) { lower = a; upper = b; } else { lower = b; upper = a; }
    }

    ZwIntInterval1d(int a, int b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    void operator +=(int val)
    {
        if (val < lower) lower = val;
        if (val > upper) upper = val;
    }

    void operator +=(ZwIntInterval1d interv)
    {
        if (interv.lower < lower) lower = interv.lower;
        if (interv.upper > upper) upper = interv.upper;
    }

    void operator *=(ZwIntInterval1d interv)
    {
        if (interv.lower > lower) lower = interv.lower;
        if (interv.upper < upper) upper = interv.upper;
    }

    ZwIntInterval1d operator *(ZwIntInterval1d interv) const
    {
        ZwIntInterval1d result;

        result.lower = __max(lower, interv.lower);
        result.upper = __min(upper, interv.upper);
        return result;
    }

    ZwIntInterval1d operator +(ZwIntInterval1d interv) const
    {
        ZwIntInterval1d tmp = *this;
        tmp += interv;
        return tmp;
    }

    bool operator &&(ZwIntInterval1d interv) const
    {
        return lower <= interv.upper && upper >= interv.lower;
    }

    bool operator &&(int val) const
    {
        return lower <= val && val <= upper;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(ZwIntInterval1d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else
        {
            return lower >= interv.lower && upper <= interv.upper;
        }
    }

    int        length() const { return upper - lower;       }
    bool       isNull() const { return lower > upper;       }
    int        mid   () const { return (upper + lower) / 2; }
    void       init  ()       { *this = kNull;              }

    void enlarge(int howMuch = 1)
    {
        lower -= howMuch;
        upper += howMuch;
    }

    static const ZwIntInterval1d kNull;

    // Public data members
    //
    int lower;
    int upper;

};  // class IntInterval1d



inline bool operator &&(int val, ZwIntInterval1d interv) 
{
    return interv.lower <= val && val <= interv.upper;
}



class DllImpExp ZwIntInterval2d
{
public:

    ZwIntInterval2d()                    : lower(INT_MAX, INT_MAX), upper(INT_MIN, INT_MIN) {}
    ZwIntInterval2d(ZwIntPoint2d p)        : lower(p), upper(p)                               {}
    ZwIntInterval2d(ZwIntPoint2d a, ZwIntPoint2d b) 
    {
        if (a.x < b.x) { lower.x = a.x; upper.x = b.x; } else { lower.x = b.x; upper.x = a.x; }
        if (a.y < b.y) { lower.y = a.y; upper.y = b.y; } else { lower.y = b.y; upper.y = a.y; }
    }

    ZwIntInterval2d(ZwIntPoint2d a, ZwIntPoint2d b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    void operator +=(ZwIntPoint2d p)
    {
        if (p.x < lower.x) lower.x = p.x;
        if (p.x > upper.x) upper.x = p.x;
        if (p.y < lower.y) lower.y = p.y;
        if (p.y > upper.y) upper.y = p.y;
    }

    void operator +=(ZwIntInterval2d interv)
    {
        if (interv.lower.x < lower.x) lower.x = interv.lower.x;
        if (interv.upper.x > upper.x) upper.x = interv.upper.x;
        if (interv.lower.y < lower.y) lower.y = interv.lower.y;
        if (interv.upper.y > upper.y) upper.y = interv.upper.y;
    }

    void operator *=(ZwIntInterval2d interv)
    {
        if (interv.lower.x > lower.x) lower.x = interv.lower.x;
        if (interv.upper.x < upper.x) upper.x = interv.upper.x;
        if (interv.lower.y > lower.y) lower.y = interv.lower.y;
        if (interv.upper.y < upper.y) upper.y = interv.upper.y;
    }

    ZwIntInterval2d operator *(ZwIntInterval2d interv) const
    {
        ZwIntInterval2d result;

        result.lower.x = __max(lower.x, interv.lower.x);
        result.upper.x = __min(upper.x, interv.upper.x);
        result.lower.y = __max(lower.y, interv.lower.y);
        result.upper.y = __min(upper.y, interv.upper.y);
        return result;
    }

    ZwIntInterval2d operator +(ZwIntInterval2d interv) const
    {
        ZwIntInterval2d tmp = *this;
        tmp += interv;
        return tmp;
    }

    bool operator &&(ZwIntInterval2d interv) const
    {
        return lower.x <= interv.upper.x && upper.x >= interv.lower.x &&
               lower.y <= interv.upper.y && upper.y >= interv.lower.y;
    }

    bool operator &&(ZwIntPoint2d p) const
    {
        return lower.x <= p.x && p.x <= upper.x &&
               lower.y <= p.y && p.y <= upper.y;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(ZwInterval2d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else
        {
            return lower.x >= interv.lower.x && upper.x <= interv.upper.x &&
                   lower.y >= interv.lower.y && upper.y <= interv.upper.y;
        }
    }

    ZwIntInterval1d project(int i) const
    {
        return ZwIntInterval1d(lower[i], upper[i]);
    }

    int        length(int i) const { return upper[i] - lower[i]; }

    bool       isNull() const { return lower.x > upper.x || lower.y > upper.y; }
    ZwIntPoint2d mid   () const { return ZwIntPoint2d((upper.x + lower.x) / 2,
                                                  (upper.y + lower.y) / 2); }
    void       init  ()       { *this = kNull; }

    void enlarge(int howMuch = 1)
    {
        lower.x -= howMuch;
        lower.y -= howMuch;
        upper.x += howMuch;
        upper.y += howMuch;
    }
    static const ZwIntInterval2d kNull;

    // Public data members
    //
    ZwIntPoint2d lower;
    ZwIntPoint2d upper;

};  // class IntInterval2d


inline bool operator &&(ZwIntPoint2d p, ZwIntInterval2d interv) 
{
    return interv.lower.x <= p.x && p.x <= interv.upper.x &&
           interv.lower.y <= p.y && p.y <= interv.upper.y;
}





class DllImpExp ZwIntInterval3d
{
public:

    ZwIntInterval3d() : lower(INT_MAX, INT_MAX, INT_MAX), upper(INT_MIN, INT_MIN, INT_MIN) {}
    ZwIntInterval3d(ZwIntPoint3d p) : lower( p), upper( p)                            {}
    ZwIntInterval3d(ZwIntPoint3d a, const ZwIntPoint3d b) 
    {
        if (a.x < b.x) { lower.x = a.x; upper.x = b.x; } else { lower.x = b.x; upper.x = a.x; }
        if (a.y < b.y) { lower.y = a.y; upper.y = b.y; } else { lower.y = b.y; upper.y = a.y; }
        if (a.z < b.z) { lower.z = a.z; upper.z = b.z; } else { lower.z = b.z; upper.z = a.z; }
    }

    ZwIntInterval3d(ZwIntPoint3d a, ZwIntPoint3d b, int /*valuesAlreadyOrdered*/) : lower(a), upper(b) {}

    void operator +=(ZwIntPoint3d p)
    {
        if (p.x < lower.x) lower.x = p.x;
        if (p.x > upper.x) upper.x = p.x;
        if (p.y < lower.y) lower.y = p.y;
        if (p.y > upper.y) upper.y = p.y;
        if (p.z < lower.z) lower.z = p.z;
        if (p.z > upper.z) upper.z = p.z;
    }

    void operator +=(ZwIntInterval3d interv)
    {
        if (interv.lower.x < lower.x) lower.x = interv.lower.x;
        if (interv.upper.x > upper.x) upper.x = interv.upper.x;
        if (interv.lower.y < lower.y) lower.y = interv.lower.y;
        if (interv.upper.y > upper.y) upper.y = interv.upper.y;
        if (interv.lower.z < lower.z) lower.z = interv.lower.z;
        if (interv.upper.z > upper.z) upper.z = interv.upper.z;
    }

    void operator *=(ZwIntInterval3d interv)
    {
        if (interv.lower.x > lower.x) lower.x = interv.lower.x;
        if (interv.upper.x < upper.x) upper.x = interv.upper.x;
        if (interv.lower.y > lower.y) lower.y = interv.lower.y;
        if (interv.upper.y < upper.y) upper.y = interv.upper.y;
        if (interv.lower.z > lower.z) lower.z = interv.lower.z;
        if (interv.upper.z < upper.z) upper.z = interv.upper.z;
    }

    ZwIntInterval3d operator *(ZwIntInterval3d interv) const
    {
        ZwIntInterval3d result;

        result.lower.x = __max(lower.x, interv.lower.x);
        result.upper.x = __min(upper.x, interv.upper.x);
        result.lower.y = __max(lower.y, interv.lower.y);
        result.upper.y = __min(upper.y, interv.upper.y);
        result.lower.z = __max(lower.z, interv.lower.z);
        result.upper.z = __min(upper.z, interv.upper.z);
        return result;
    }

    ZwIntInterval3d operator +(ZwIntInterval3d interv) const
    {
        ZwIntInterval3d tmp = *this;
        tmp += interv;
        return tmp;
    }

    bool operator &&(ZwIntInterval3d interv) const
    {
        return lower.x <= interv.upper.x && upper.x >= interv.lower.x &&
               lower.y <= interv.upper.y && upper.y >= interv.lower.y &&
               lower.z <= interv.upper.z && upper.z >= interv.lower.z;
    }

    bool operator &&(ZwIntPoint3d p) const
    {
        return lower.x <= p.x && p.x <= upper.x &&
               lower.y <= p.y && p.y <= upper.y &&
               lower.z <= p.z && p.z <= upper.z;
    }

    // a <= b means a is subinterval of b
    //
    bool operator <=(ZwIntInterval3d interv) const
    {
        if (isNull())
        {
            return true;
        }
        else
        {
            return lower.x >= interv.lower.x && upper.x <= interv.upper.x &&
                   lower.y >= interv.lower.y && upper.y <= interv.upper.y &&
                   lower.z >= interv.lower.z && upper.z <= interv.upper.z;
        }
    }

    ZwIntInterval1d project(int i) const
    {
        return ZwIntInterval1d(lower[i], upper[i]);
    }

    int        length(int i) const { return upper[i] - lower[i]; }

    bool       isNull() const { return lower.x > upper.x || lower.y > upper.y || lower.z > upper.z; }
    ZwIntPoint3d mid   () const { return ZwIntPoint3d((upper.x + lower.x) / 2,
                                                  (upper.y + lower.y) / 2,
                                                  (upper.z + lower.z) / 2); }
    void enlarge(int howMuch = 1)
    {
        lower.x -= howMuch;
        lower.y -= howMuch;
        lower.z -= howMuch;
        upper.x += howMuch;
        upper.y += howMuch;
        upper.z += howMuch;
    }

    void       init  ()       { *this = kNull; }

    static const ZwIntInterval3d kNull;

    // Public data members
    //
    ZwIntPoint3d lower;
    ZwIntPoint3d upper;

};  // class IntInterval3d


inline bool operator &&(ZwIntPoint3d p, ZwIntInterval3d interv) 
{
    return interv.lower.x <= p.x && p.x <= interv.upper.x &&
           interv.lower.y <= p.y && p.y <= interv.upper.y &&
           interv.lower.z <= p.z && p.z <= interv.upper.z;
}


template<class I>
bool overlap(I i1, I i2)
{
    return i1.operator &&(i2);
}

inline bool point_inside(ZwInterval2d const &i, ZwPoint2d const& p)
{
    return i.operator &&(p);
}

inline bool point_inside(ZwInterval3d const &i, ZwPoint3d const& p)
{
    return i.operator &&(p);
}

inline bool point_inside(ZwIntInterval2d const &i, ZwIntPoint2d const& p)
{
    return i.operator &&(p);
}

inline bool point_inside(ZwIntInterval3d const &i, ZwIntPoint3d const& p)
{
    return i.operator &&(p);
}

inline bool point_inside(ZwInterval1d i, double d)
{
    return operator &&(d, i);
}

inline bool point_inside(ZwIntInterval1d i, int n)
{
    return operator &&(n, i);
}

AECMODELER_NAMESPACE_END
#endif
