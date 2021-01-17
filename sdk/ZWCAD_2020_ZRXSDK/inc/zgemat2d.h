

#ifndef ZC_GEMAT2D_H
#define ZC_GEMAT2D_H

#include "zgegbl.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class ZcGeVector2d;
class ZcGeLine2d;
class ZcGeTol;

class 
GE_DLLEXPIMPORT
ZcGeMatrix2d
{
public:
    ZcGeMatrix2d();
    ZcGeMatrix2d(const ZcGeMatrix2d& src);

    static const   ZcGeMatrix2d   kIdentity;

    ZcGeMatrix2d&  setToIdentity();

    ZcGeMatrix2d   operator *   (const ZcGeMatrix2d& mat) const;
    ZcGeMatrix2d&  operator *=  (const ZcGeMatrix2d& mat);
    ZcGeMatrix2d&  preMultBy    (const ZcGeMatrix2d& leftSide);
    ZcGeMatrix2d&  postMultBy   (const ZcGeMatrix2d& rightSide);
    ZcGeMatrix2d&  setToProduct (const ZcGeMatrix2d& mat1, const ZcGeMatrix2d& mat2);

    ZcGeMatrix2d&  invert       ();
    ZcGeMatrix2d   inverse      () const;

    ZSoft::Boolean isSingular   (const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZcGeMatrix2d&  transposeIt  ();
    ZcGeMatrix2d   transpose    () const;

    bool operator ==  (const ZcGeMatrix2d& mat) const;
    bool operator !=  (const ZcGeMatrix2d& mat) const;
    bool isEqualTo    (const ZcGeMatrix2d& mat,
                       const ZcGeTol& tol = ZcGeContext::gTol) const;

    ZSoft::Boolean isUniScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
    ZSoft::Boolean isScaledOrtho(const ZcGeTol& tol = ZcGeContext::gTol) const;
	double		   scale(void);

    double         det          () const;

    ZcGeMatrix2d&  setTranslation(const ZcGeVector2d& vec);
    ZcGeVector2d   translation  () const;

    ZSoft::Boolean isConformal (double& scale, double& angle,
                                ZSoft::Boolean& isMirror, ZcGeVector2d& reflex) const;

    ZcGeMatrix2d&  setCoordSystem(const ZcGePoint2d& origin,
                                 const ZcGeVector2d& e0,
                                 const ZcGeVector2d& e1);
    void           getCoordSystem(ZcGePoint2d& origin,
                                 ZcGeVector2d& e0,
                                 ZcGeVector2d& e1) const;

    ZcGeMatrix2d& setToTranslation(const ZcGeVector2d& vec);
    ZcGeMatrix2d& setToRotation (double angle,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    ZcGeMatrix2d& setToScaling  (double scaleAll,
                                 const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    ZcGeMatrix2d& setToMirroring(const ZcGePoint2d& pnt);
    ZcGeMatrix2d& setToMirroring(const ZcGeLine2d& line);
    ZcGeMatrix2d& setToAlignCoordSys(const ZcGePoint2d&  fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

    static
    ZcGeMatrix2d translation    (const ZcGeVector2d& vec);
    static
    ZcGeMatrix2d rotation       (double angle, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    static
    ZcGeMatrix2d scaling        (double scaleAll, const ZcGePoint2d& center
				 = ZcGePoint2d::kOrigin);
    static
    ZcGeMatrix2d mirroring      (const ZcGePoint2d& pnt);
    static
    ZcGeMatrix2d mirroring      (const ZcGeLine2d& line);
    static
    ZcGeMatrix2d alignCoordSys  (const ZcGePoint2d& fromOrigin,
                                 const ZcGeVector2d& fromE0,
                                 const ZcGeVector2d& fromE1,
                                 const ZcGePoint2d&  toOrigin,
                                 const ZcGeVector2d& toE0,
                                 const ZcGeVector2d& toE1);

    double         operator ()  (unsigned int, unsigned int) const;
    double&        operator ()  (unsigned int, unsigned int);

    double         entry[3][3]; 
};

ZSOFT_FORCE_INLINE bool
ZcGeMatrix2d::operator == (const ZcGeMatrix2d& otherMatrix) const
{
    return this->isEqualTo(otherMatrix);
}

ZSOFT_FORCE_INLINE bool
ZcGeMatrix2d::operator != (const ZcGeMatrix2d& otherMatrix) const
{
    return !this->isEqualTo(otherMatrix);
}

ZSOFT_FORCE_INLINE double
ZcGeMatrix2d::operator () (
    unsigned int row,
    unsigned int column) const
{
    return entry[row][column];
}

ZSOFT_FORCE_INLINE double&
ZcGeMatrix2d::operator () (
    unsigned int row,
    unsigned int column)
{
    return entry[row][column];
}

#pragma pack (pop)
#endif
