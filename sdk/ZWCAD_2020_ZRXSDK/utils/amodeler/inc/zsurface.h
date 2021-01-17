#ifndef AECMODELER_INC_SURFACE_H
#define AECMODELER_INC_SURFACE_H

#include "zentity.h"
#include "zcircle3d.h"
#include "ztransf3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwSurface : public ZwEntity
{
public:

    ZwSurface(ZwBody* = NULL);
    
    // We support only these surface types
    //
    enum Type { kUnspecified, kCylinder, kCone, kSphere, kTorus };

    virtual Type     type     () const = NULL;
    virtual ZwSurface* copy     () const = NULL;

    // The transform() method returns true if the surface was successfully 
    // transformed or false if it could not be transformed (e.g. a sphere 
    // cannot be stretched)
    //
    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const Vector3d& /*stretchVect*/ = Vector3d::kNull) = NULL;

    // Returns true if two surfaces are equal. The definition of what equal 
    // means is highly questionable
    //
    virtual bool     isEqual  (const ZwSurface*) const = NULL;

    virtual bool containsPoint(const ZwPoint3d&) const = NULL;

    // The circle() method returns the equation of a circle which results from 
    // the intersection of the surface with the given plane. The Line3d is used 
    // to disambiguate between multiple intersections (e.g. torus-plane 
    // intersection produces two circles). The Line3d is an approximation of 
    // the circle we are interested in
    //
    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const = NULL;

    // The normal() method returns the outward-pointing unit normal vector to
    // the surface at the given point
    //
    virtual ZwVector3d normal   (const ZwPoint3d&) const = NULL;

    virtual void     print    (FILE* = NULL) const   = NULL;
    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*) {}

    ZwSurface*         next     () const     { return mpNext; }
    void             setNext  (ZwSurface* s) { mpNext = s;    }

    // Scratch data members
    //
    ZwSurface* sptr;
    int      n;     // For print

private:

    ZwSurface* mpNext;   // Next surface in the list of all surfaces of a body

}; // class Surface



class DllImpExp ZwUnspecifiedSurface : public ZwSurface
{
public:

    ZwUnspecifiedSurface(ZwBody* b = NULL) : ZwSurface(b) {}
    
    virtual Type     type     () const { return kUnspecified; }
    virtual ZwSurface* copy     () const { return new ZwUnspecifiedSurface(*this); }
    virtual void     print    (FILE* = NULL) const;

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const Vector3d& /*stretchVect*/ = Vector3d::kNull) 
    { return true; }

    virtual bool     isEqual  (const ZwSurface* s) const; // return this == s;

    virtual bool containsPoint(const ZwPoint3d&) const { return false; }

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const { return ZwCircle3d();      }
    virtual ZwVector3d normal   (const ZwPoint3d&)              const { return ZwVector3d(0,0,0); }

}; // class UnspecifiedSurface



class DllImpExp ZwRevolutionSurface : public ZwSurface
{
public:

    ZwRevolutionSurface();
    ZwRevolutionSurface(const ZwLine3d& axis, const ZwVector3d& startDir, ZwBody* = NULL);

    // The axis of the revolution and the direction of the beginning of the
    // revolution (the 0.0-parameter). The two vectors are orthogonal and unit
    // length
    //
    ZwLine3d           axis     () const { return mAxis;     } 
    ZwVector3d         startDir () const { return mStartDir; }

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    ZwLine3d   mAxis;
    ZwVector3d mStartDir;

}; // class RevolutionSurface



class DllImpExp ZwSphereSurface : public ZwRevolutionSurface
{
public:

    ZwSphereSurface() {}
    ZwSphereSurface(const ZwPoint3d& origin, double radius, int approx, ZwBody*); 

    // Return the sphere definiton data
    //
    ZwPoint3d          center   () const { return axis().point; }
    double           radius   () const { return mRadius;      }
    int              approx   () const { return mApprox;      }

    virtual Type     type     () const { return kSphere; }
    virtual ZwSurface* copy     () const { return new ZwSphereSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double  mRadius;
    int     mApprox;

}; // class SphereSurface



class DllImpExp ZwCylinderSurface : public ZwRevolutionSurface
{
public:

    ZwCylinderSurface() {}
    ZwCylinderSurface(const ZwLine3d& axis, double radius, int approx, ZwBody*);
    ZwCylinderSurface(const ZwLine3d& axis, const ZwVector3d& startDir, double radius, int approx, ZwBody*);

    // Return the cylinder definition data
    //
    double           radius   () const { return mRadius;  }
    int              approx   () const { return mApprox;  }

    virtual Type     type     () const { return kCylinder; }
    virtual ZwSurface* copy     () const { return new ZwCylinderSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double mRadius;
    int    mApprox;

}; // class CylinderSurface



class DllImpExp ZwConeSurface : public ZwRevolutionSurface
{
public:

    ZwConeSurface() {}
    ZwConeSurface(const ZwLine3d& axis, double radius1, double radius2, int approx, ZwBody*);

    // Return the cone definition data
    //
    double           radius   () const { return mRadius;   }
    double           tanAngle () const { return mTanAngle; }
    int              approx   () const { return mApprox;   }
    ZwPoint3d          apex     () const;

    virtual Type     type     () const { return kCone; }
    virtual ZwSurface* copy     () const { return new ZwConeSurface(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual  (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle   (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal   (const ZwPoint3d&)              const;

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    double mRadius;
    double mTanAngle;
    int    mApprox;

}; // class ConeSurface



class DllImpExp ZwTorusSurface : public ZwRevolutionSurface
{
public:
    ZwTorusSurface() {}
    ZwTorusSurface(const ZwLine3d& axis, 
                 double        majRadius, 
                 double        minRadius, 
                 int           majApprox, 
                 int           minApprox, 
                 ZwBody*         b);

    // Return the torus definition data
    //
    ZwPoint3d          center     () const { return axis().point; }
    double           majorRadius() const { return mMajorRadius; }
    double           minorRadius() const { return mMinorRadius; }
    int              majorApprox() const { return mMajorApprox; }
    int              minorApprox() const { return mMinorApprox; }

    virtual Type     type       () const { return kTorus;   }
    virtual ZwSurface* copy       () const { return new ZwTorusSurface(*this); }

    virtual bool     transform  (const ZwTransf3d&, 
                                 ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                                 const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual bool     isEqual    (const ZwSurface*) const;

    virtual bool containsPoint(const ZwPoint3d&) const; 

    virtual ZwCircle3d circle     (const ZwPlane&, const ZwLine3d&) const;
    virtual ZwVector3d normal     (const ZwPoint3d&)              const;

    virtual void     print      (FILE* = NULL)          const;
    virtual void     save       (ZwSaveRestoreCallback*)  const;
    virtual void     restore    (ZwSaveRestoreCallback*);

private:

    double mMajorRadius;
    double mMinorRadius;
    int    mMajorApprox;
    int    mMinorApprox;

}; // class TorusSurface


AECMODELER_NAMESPACE_END
#endif
