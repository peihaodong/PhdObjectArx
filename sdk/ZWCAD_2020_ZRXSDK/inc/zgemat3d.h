

#ifndef ZC_GEMAT3D_H
#define ZC_GEMAT3D_H

#include "zgegbl.h"
#include "zgemat2d.h"
#include "zgepnt3d.h"
#pragma pack (push, 8)

class ZcGeLine3d;
class ZcGeVector3d;
class ZcGePlane;
class ZcGeTol;

class 
GE_DLLEXPIMPORT
ZcGeMatrix3d
{
public:
    ZcGeMatrix3d();
    ZcGeMatrix3d(const ZcGeMatrix3d& src);

    static const   ZcGeMatrix3d    kIdentity;

    ZcGeMatrix3d&  setToIdentity();

    ZcGeMatrix3d   operator *      (const ZcGeMatrix3d& mat) const;
    ZcGeMatrix3d&  operator *=     (const ZcGeMatrix3d& mat);
    ZcGeMatrix3d&  preMultBy       (const ZcGeMatrix3d& leftSide);
    ZcGeMatrix3d&  postMultBy      (const ZcGeMatrix3d& rightSide);
    ZcGeMatrix3d&  setToProduct    (const ZcGeMatrix3d& mat1, const ZcGeMatrix3d& mat2);

    ZcGeMatrix3d&  invert          ();
    ZcGeMatrix3d   inverse         () const;

    ZSoft::Boolean isSingular      (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeMatrix3d&  transposeIt     ();
    ZcGeMatrix3d   transpose       () const;

    bool operator ==     (const ZcGeMatrix3d& mat) const;
    bool operator !=     (const ZcGeMatrix3d& mat) const;
    bool isEqualTo       (const ZcGeMatrix3d& mat, const ZcGeTol& tol
                                    = ZcGeContext::gTol) const;

    ZSoft::Boolean isUniScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isScaledOrtho   (const ZcGeTol& tol = ZcGeContext::gTol) const;

    double         det             () const;

    ZcGeMatrix3d&  setTranslation  (const ZcGeVector3d& vec);
    ZcGeVector3d   translation     () const;

    ZcGeMatrix3d&  setCoordSystem  (const ZcGePoint3d& origin,
                                    const ZcGeVector3d& xAxis,
                                    const ZcGeVector3d& yAxis,
                                    const ZcGeVector3d& zAxis);
    void           getCoordSystem  (ZcGePoint3d& origin,
                                    ZcGeVector3d& xAxis,
                                    ZcGeVector3d& yAxis,
                                    ZcGeVector3d& zAxis) const;

    ZcGeMatrix3d&  setToTranslation(const ZcGeVector3d& vec);
    ZcGeMatrix3d&  setToRotation   (double angle, const ZcGeVector3d& axis,
                                    const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    ZcGeMatrix3d&  setToScaling    (double scaleAll, const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    ZcGeMatrix3d&  setToMirroring  (const ZcGePlane& pln);
    ZcGeMatrix3d&  setToMirroring  (const ZcGePoint3d& pnt);
    ZcGeMatrix3d&  setToMirroring  (const ZcGeLine3d& line);
    ZcGeMatrix3d&  setToProjection (const ZcGePlane& projectionPlane,
                                    const ZcGeVector3d& projectDir);
    ZcGeMatrix3d&  setToAlignCoordSys(const ZcGePoint3d& fromOrigin,
                                    const ZcGeVector3d& fromXAxis,
                                    const ZcGeVector3d& fromYAxis,
                                    const ZcGeVector3d& fromZAxis,
                                    const ZcGePoint3d& toOrigin,
                                    const ZcGeVector3d& toXAxis,
                                    const ZcGeVector3d& toYAxis,
                                    const ZcGeVector3d& toZAxis);

    ZcGeMatrix3d&  setToWorldToPlane(const ZcGeVector3d& normal);
    ZcGeMatrix3d&  setToWorldToPlane(const ZcGePlane& plane);
    ZcGeMatrix3d&  setToPlaneToWorld(const ZcGeVector3d& normal);
    ZcGeMatrix3d&  setToPlaneToWorld(const ZcGePlane& plane);

    static
    ZcGeMatrix3d   translation     (const ZcGeVector3d& vec);
    static
    ZcGeMatrix3d   rotation        (double angle, const ZcGeVector3d& axis,
                                    const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    static
    ZcGeMatrix3d   scaling         (double scaleAll, const ZcGePoint3d& center
                                    = ZcGePoint3d::kOrigin);
    static
    ZcGeMatrix3d   mirroring       (const ZcGePlane& pln);
    static
    ZcGeMatrix3d   mirroring       (const ZcGePoint3d& pnt);
    static
    ZcGeMatrix3d   mirroring       (const ZcGeLine3d& line);
    static
    ZcGeMatrix3d   projection      (const ZcGePlane& projectionPlane,
                                    const ZcGeVector3d& projectDir);
    static
    ZcGeMatrix3d   alignCoordSys   (const ZcGePoint3d&  fromOrigin,
                                    const ZcGeVector3d& fromXAxis,
                                    const ZcGeVector3d& fromYAxis,
                                    const ZcGeVector3d& fromZAxis,
                                    const ZcGePoint3d&  toOrigin,
                                    const ZcGeVector3d& toXAxis,
                                    const ZcGeVector3d& toYAxis,
                                    const ZcGeVector3d& toZAxis);

    static
    ZcGeMatrix3d   worldToPlane    (const ZcGeVector3d& normal);
    static
    ZcGeMatrix3d   worldToPlane    (const ZcGePlane&);
    static
    ZcGeMatrix3d   planeToWorld    (const ZcGeVector3d& normal);
    static
    ZcGeMatrix3d   planeToWorld    (const ZcGePlane&);

	double scale(void) const;

    double          norm            () const;

    ZcGeMatrix2d convertToLocal     (ZcGeVector3d& normal, double& elev) const;

    double         operator ()     (unsigned int, unsigned int) const;
    double&        operator ()     (unsigned int, unsigned int);

    double         entry[4][4];    

    ZSoft::Boolean  inverse(ZcGeMatrix3d& inv, double tol) const;

private:
    void           pivot           (int, ZcGeMatrix3d&);
    int            pivotIndex(int) const;
    void           swapRows        (int, int, ZcGeMatrix3d&);
};

ZSOFT_FORCE_INLINE bool
ZcGeMatrix3d::operator == (const ZcGeMatrix3d& otherMatrix) const
{
    return this->isEqualTo(otherMatrix);
}

ZSOFT_FORCE_INLINE bool
ZcGeMatrix3d::operator != (const ZcGeMatrix3d& otherMatrix) const
{
    return !this->isEqualTo(otherMatrix);
}

ZSOFT_FORCE_INLINE double
ZcGeMatrix3d::operator () (
    unsigned int row,
    unsigned int column) const
{
    return entry[row][column];
}

ZSOFT_FORCE_INLINE double&
ZcGeMatrix3d::operator () (
    unsigned int row,
    unsigned int column)
{
    return entry[row][column];
}

#pragma pack (pop)
#endif
