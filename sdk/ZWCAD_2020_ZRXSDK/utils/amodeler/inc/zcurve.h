#ifndef ZMODELER_INC_CURVE_H
#define ZMODELER_INC_CURVE_H

#include "zentity.h"
#include "zcircle3d.h"
#include "ztransf3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwCurve : public ZwEntity
{
public:
    ZwCurve(ZwBody* = NULL);

    // We support these curve types
    //
    enum Type { kUnspecified, kCircle };

    virtual Type     type     () const = NULL;
    virtual ZwCurve*   copy     () const = NULL;
    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull) = NULL;

    virtual void     print    (FILE* = NULL)         const = NULL;
    virtual void     save     (ZwSaveRestoreCallback*) const;
    virtual void     restore  (ZwSaveRestoreCallback*)       {}

    ZwCurve*           next     () const     { return mpNext; }
    void             setNext  (ZwCurve* c)   { mpNext = c;    }

    // Scratch data members
    //
    ZwCurve* cptr;
    int    n;     // For print

private:

    ZwCurve* mpNext;   // Next curve in the list of all curves of a body

}; // class Curve



class DllImpExp ZwUnspecifiedCurve : public ZwCurve
{
public:

    ZwUnspecifiedCurve(ZwBody* b = NULL) : ZwCurve(b) {}
    
    virtual Type     type     () const { return kUnspecified; }
    virtual ZwCurve*   copy     () const { return new ZwUnspecifiedCurve(*this); }
    virtual void     print    (FILE* = NULL) const;

    virtual bool     transform(const ZwTransf3d&,
                               ZwTransf3d::Type  /*transfType*/  = ZwTransf3d::kUnknown,
                               const Vector3d& /*stretchVect*/ = Vector3d::kNull) 
    { return true; }

}; // class UnspecifiedCurve



class DllImpExp ZwCircleCurve : public ZwCurve
{
public:

    ZwCircleCurve() {}
    ZwCircleCurve(const ZwCircle3d&, int approx, ZwBody*); 

    // Return circle definiton data
    //
    const ZwTransf3d&  transf   () const { return mTransf;          }
    ZwPoint3d          origin   () const { return mTransf.origin(); }
    ZwLine3d           axis     () const;  
    double           radius   () const { return mRadius; }
    int              approx   () const { return mApprox; }
    ZwCircle3d         circle   () const { return ZwCircle3d(axis(), mRadius); }

    virtual Type     type     () const { return kCircle; }
    virtual ZwCurve*   copy     () const { return new ZwCircleCurve(*this); }

    virtual bool     transform(const ZwTransf3d&, 
                               ZwTransf3d::Type  transfType  = ZwTransf3d::kUnknown,
                               const ZwVector3d& stretchVect = ZwVector3d::kNull);

    virtual void     print    (FILE* = NULL)          const;
    virtual void     save     (ZwSaveRestoreCallback*)  const;
    virtual void     restore  (ZwSaveRestoreCallback*);

private:

    ZwTransf3d mTransf;
    double   mRadius;
    int      mApprox;

}; // class CircleCurve



AECMODELER_NAMESPACE_END
#endif
