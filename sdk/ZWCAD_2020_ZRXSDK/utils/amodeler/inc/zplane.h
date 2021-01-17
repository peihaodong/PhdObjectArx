#ifndef AECMODELER_INC_PLANE_H
#define AECMODELER_INC_PLANE_H

#include "zpoint3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwPlane
{
public:

    ZwPlane()                                 : normal(ZwVector3d::kNull), d(0) {}
    ZwPlane(ZwVector3d nn, double dd)           : normal(nn), d(dd)             {}
    ZwPlane(ZwPoint3d, ZwVector3d); 
    ZwPlane(const ZwPoint3d&, const ZwPoint3d&,  const ZwPoint3d&);
    ZwPlane(const ZwPoint3d&, const ZwVector3d&, const ZwVector3d&);

    // Create plane from a polygon of vertices (n >=3). All polygon vertices
    // are used to calculate the plane coefficients to make the formula
    // symetrical.
    //
    ZwPlane(const ZwPoint3d plg[], int n);

    // The plane normal is given, just calculate the 'd' parameter from all 
    // polygon vertices.
    //
    ZwPlane(const ZwPoint3d plg[], int n, const ZwVector3d& normal);

    // Create a plane from the given set of coplanar points. Returns a null 
    // plane if the points do not define a plane. Unlike the Plane constructor
    // that takes a closed polygon, the set of points here is just any set of
    // points and the method tries to do some kind of a best fit plane from 
    // them
    //
    static ZwPlane fromPoints(const ZwPoint3d pts[], int pointCount, bool checkPlanarity);

    ZwPlane    operator -()                const { return ZwPlane(-normal, -d); }
    double   dist      (ZwPoint3d p)       const { return p % normal + d; }
    ZwPoint3d  project   (const ZwPoint3d& ) const;
    ZwVector3d project   (const ZwVector3d&) const;
    ZwLine3d   project   (const ZwLine3d&  ) const;

    ZwLine3d   operator* (const ZwPlane&   ) const;
    ZwPoint3d  operator* (const ZwLine3d&  ) const;

    bool     isValid   () const { return fabs(normal.length() - 1) < ZwEpsNor(); }

    bool     isEqual   (ZwPlane) const;

    void     orthoPlane(int& i1, int& i2)          const;
    void     orthoPlane(int& i1, int& i2, int& i3) const;

    // Public data members
    //    
    ZwVector3d normal;
    double   d;

}; // class Plane



inline ZwPlane::ZwPlane(ZwPoint3d p, ZwVector3d norm)
  : normal(norm)
{
    normal = normal.normalize();
    d = -p % normal;
}


inline bool ZwPlane::isEqual(ZwPlane pla) const 
{ 
    return normal.isEqual(pla.normal) && fabs(d-pla.d) <= ZwEpsAbs(); 
}


AECMODELER_NAMESPACE_END
#endif
