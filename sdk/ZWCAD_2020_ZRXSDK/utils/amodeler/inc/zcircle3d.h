#ifndef AECMODELER_INC_CIRCLE3D_H
#define AECMODELER_INC_CIRCLE3D_H

#include "zline3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwCircle3d
{
public:
    ZwCircle3d() : radius(0) {}
    ZwCircle3d(ZwLine3d ax, double rad) : axis(ax), radius(rad) {}

    ZwCircle3d(const ZwPoint3d&  p1,
             const ZwPoint3d&  p2,
             const ZwVector3d& norm, 
             double          rad,
             bool            isCenterLeft);

    ZwCircle3d(const ZwPoint3d& p1,
             const ZwPoint3d& p2,
             const ZwPoint3d& p3,
             double         rad); 
    
    void operator *=(const ZwTransf3d&);

    ZwVector3d tangentAt(const ZwPoint3d& pointOnCircle) const;

    bool isValid() const { return radius != 0 && axis.isValid(); }

    bool isEqual(const ZwCircle3d&) const;

    int tessellate(int            approx,
                   bool           goCcw,
                   const ZwPoint3d  startPoint, 
                   const ZwPoint3d  endPoint, 
                   ZwPoint3d*       ptsArray); // The length of ptsArray must be >= approx+2

    ZwLine3d axis;
    double radius;

};


AECMODELER_NAMESPACE_END
#endif

