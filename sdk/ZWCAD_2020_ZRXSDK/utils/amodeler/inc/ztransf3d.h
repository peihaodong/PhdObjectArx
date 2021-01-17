#ifndef AECMODELER_INC_TRANSF3D_H
#define AECMODELER_INC_TRANSF3D_H

#include "zpoint3d.h"

class ZcGeMatrix3d;

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwTransf3d
{
public:

    // The constructor creates an identity transform.
    //
    ZwTransf3d();  

    // The constructor creates a rigid motion transform from an origin and 
    // directions of x, y and z axes.
    //
    ZwTransf3d(const ZwPoint3d&  origin, 
             const ZwVector3d& xDir, 
             const ZwVector3d& yDir, 
             const ZwVector3d& zDir);

    // The constructor creates a rigid motion transform from an origin and 
    // direction of x and y axis. If yDir is not perpendicular to xDir, yDir
    // will be adjusted.
    //
    ZwTransf3d(const ZwPoint3d&  origin, 
             const ZwVector3d& xDir, 
             const ZwVector3d& yDir);

    // The constructor creates a rigid motion transform from an origin 
    // (axis.point) and the direction of the z axis (axis.vector). The 
    // directions of the x and y axes are determined according to the 
    // AutoCAD's arbitrary axis algorithm.
    //
    ZwTransf3d(const ZwLine3d& axis);

    // The constructor creates a rigid motion transform from an origin. The
    // x, y and z axis are aligned with the world x, y and z axis.
    //
    ZwTransf3d(const ZwPoint3d& origin);

    double& operator ()(int i1, int i2)       { return c[i1][i2]; }
    double  operator ()(int i1, int i2) const { return c[i1][i2]; }

    // Transform points, vectors and other transforms
    //
    ZwPoint3d  operator *(const ZwPoint3d& ) const;
    ZwVector3d operator *(const ZwVector3d&) const;
    ZwLine3d   operator *(const ZwLine3d&  ) const;
    ZwTransf3d operator *(const ZwTransf3d&) const;

    void     getCoordSystem(ZwPoint3d&  origin,
                            ZwVector3d& xDir,
                            ZwVector3d& yDir,
                            ZwVector3d& zDir) const;

    ZwPoint3d  origin() const;
    ZwVector3d xDir  () const;
    ZwVector3d yDir  () const;
    ZwVector3d zDir  () const;
    
    // Create special transformations
    //
    static ZwTransf3d translation(const ZwVector3d&);
    static ZwTransf3d rotation   (const ZwLine3d& axis, double angle);
    static ZwTransf3d scaling    (const ZwPoint3d& fixedPt, double factor);
    static ZwTransf3d scaling    (const ZwPoint3d& fixedPt, const ZwVector3d& xyzFactors);
    static ZwTransf3d stretching (const ZwLine3d& axis);
    static ZwTransf3d mirroring  (const ZwPlane&);
    static ZwTransf3d projectOn  (const ZwPlane& projPlane, const ZwVector3d& projDir = ZwVector3d::kNull);

    // The transformation maps points as follows:
    //
    // Point  src1             maps to point  dst1
    // Vector (src1,src2)      maps to vector (dst1,dst2)
    // Plane  (src1,src2,src3) maps to plane  (dst1,dst2,dst3)
    //
    static ZwTransf3d align(const ZwPoint3d& src1,
                          const ZwPoint3d& src2,
                          const ZwPoint3d& src3,
                          const ZwPoint3d& dst1,
                          const ZwPoint3d& dst2,
                          const ZwPoint3d& dst3);

    // The transformation maps points and vectors as follows:
    //
    // Point  src1             maps to point  dst1
    // Vector src2             maps to vector dst2
    // Plane  (src1,src2,src3) maps to plane  (dst1,dst2,dst3)
    //
    static ZwTransf3d align(const ZwPoint3d&  src1,
                          const ZwVector3d& src2,
                          const ZwVector3d& src3,
                          const ZwPoint3d&  dst1,
                          const ZwVector3d& dst2,
                          const ZwVector3d& dst3);

    static ZwTransf3d align(const ZwPoint3d&  src1,
                          const ZwVector3d& src2,
                          const ZwPoint3d&  dst1,
                          const ZwVector3d& dst2);

    // Project a point, using the full 4x4 matrix, including the projective
    // part. Sets Transf3d::succeeded to false if the point couldn't be projected
    // by the perspective transform because it lied behind the view point.
    //
    ZwPoint3d project(const ZwPoint3d& p) const;

    enum ProjectionType { kParallelProjection, kPerspectiveProjection };

    // Create a general projection transformation (this is how to create
    // a projection transformation to be passed to the Body::hideDisplay() 
    // method).
    //
    ZwTransf3d(ProjectionType  type, 
             const ZwPoint3d&  fromPt, 
             const ZwPoint3d&  toPt   = ZwPoint3d (0,0,0), 
             const ZwVector3d& upDir  = ZwVector3d(0,0,0));

    // Some ready to use projection transformations 
    //
    static const ZwTransf3d kFrontView;
    static const ZwTransf3d kBackView;
    static const ZwTransf3d kTopView;
    static const ZwTransf3d kBottomView;
    static const ZwTransf3d kLeftView;
    static const ZwTransf3d kRightView;
    static const ZwTransf3d kIsometricView;
    static const ZwTransf3d kDimetricView;

    ZwTransf3d invert(bool isRigidMotion = true) const;

    bool     isValid                 () const;
    bool     isOrthogonal            () const;  // No shear
    bool     isEqualScalingOrthogonal() const;  // No shear, no nonequal scaling
    ZwVector3d stretchVector           () const;
    bool     isMirror                () const;
    bool     isPerspective           () const;
    bool     isIdentity              () const;

    static const ZwTransf3d kIdentity;

    // Casts from AModeler::Transf3d to ZcGeMatrix3d
    //
    operator       ZcGeMatrix3d& ()       { return *((ZcGeMatrix3d*)this);       }
    operator const ZcGeMatrix3d& () const { return *((const ZcGeMatrix3d*)this); }

    // Cast from l-value ZcGeMatrix3d to l-value AModeler::Transf3d. This 
    // explicit cast function needs to be used only for l-values, e.g. when 
    // AModeler returns a Transf3d as an output argument but we want to capture 
    // it in an ZcGeMatrix3d. For non-l-values, the Transf3d(const ZcGeMatrix3d&) 
    // constructor will perform the cast automatically.
    //
    static ZwTransf3d& cast(ZcGeMatrix3d& m) { return *(ZwTransf3d*)&m; }

    ZwTransf3d(const ZcGeMatrix3d& m)        { *this = *(ZwTransf3d*)&m; }


    //void save   (SaveRestoreCallback*) const;
    //void restore(SaveRestoreCallback*);

    // Public data member
    //
    double c[4][4];

    enum Type { kRigidMotion, kEqualScalingOrtho, kNonOrtho, kProjection, kUnknown };

}; // class Transf3d



// Transform a distance by a transform. Notice that if the transform
// contains non-uniform scaling, this operation does not make sense
//
DllImpExp void operator *=(double& dist, const ZwTransf3d&);  

inline ZwTransf3d::ZwTransf3d() 
{
    c[0][1] = c[0][2] = c[0][3] = c[1][0] = c[1][2] = c[1][3] = 
    c[2][0] = c[2][1] = c[2][3] = c[3][0] = c[3][1] = c[3][2] = 0.0;
    c[0][0] = c[1][1] = c[2][2] = c[3][3] = 1;
}


AECMODELER_NAMESPACE_END
#endif

