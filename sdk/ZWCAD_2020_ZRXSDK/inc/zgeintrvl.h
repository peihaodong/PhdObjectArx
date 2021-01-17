

#ifndef ZC_GEINTRVL_H
#define ZC_GEINTRVL_H

#include "zgegbl.h"
#pragma pack (push, 8)
class ZcGeImpInterval;
class
GE_DLLEXPIMPORT
ZcGeInterval
{
public:
    ZcGeInterval(double tol = 1.e-12);
    ZcGeInterval(const ZcGeInterval& src);
    ZcGeInterval(double lower, double upper, double tol = 1.e-12);
    ZcGeInterval(ZSoft::Boolean boundedBelow, double bound,
                 double tol = 1.e-12);
    ~ZcGeInterval();

    ZcGeInterval&  operator =       (const ZcGeInterval& otherInterval);

    double         lowerBound       () const;
    double         upperBound       () const;
    double         element          () const;
    void           getBounds        (double& lower, double& upper) const;
    double         length           () const;
    double         tolerance        () const;

    ZcGeInterval&  set              (double lower, double upper);
    ZcGeInterval&  set              (ZSoft::Boolean boundedBelow, double bound);
    ZcGeInterval&  set              ();
    ZcGeInterval&  setUpper         (double upper);
    ZcGeInterval&  setLower         (double lower);
    ZcGeInterval&  setTolerance     (double tol);

    void           getMerge         (const ZcGeInterval& otherInterval, ZcGeInterval& result) const;
    int            subtract         (const ZcGeInterval& otherInterval,
                                     ZcGeInterval& lInterval,
                                     ZcGeInterval& rInterval) const;
    ZSoft::Boolean intersectWith    (const ZcGeInterval& otherInterval, ZcGeInterval& result) const;

    ZSoft::Boolean isBounded        () const;
    ZSoft::Boolean isBoundedAbove   () const;
    ZSoft::Boolean isBoundedBelow   () const;
    ZSoft::Boolean isUnBounded      () const;
    ZSoft::Boolean isSingleton      () const;

    ZSoft::Boolean isDisjoint       (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean contains         (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean contains         (double val) const;

    ZSoft::Boolean isContinuousAtUpper (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean isOverlapAtUpper    (const ZcGeInterval& otherInterval,
                                        ZcGeInterval& overlap) const;

    ZSoft::Boolean operator ==      (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean operator !=      (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean isEqualAtUpper   (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean isEqualAtUpper   (double value) const;
    ZSoft::Boolean isEqualAtLower   (const ZcGeInterval& otherInterval) const;
    ZSoft::Boolean isEqualAtLower   (double value) const;

    ZSoft::Boolean isPeriodicallyOn (double period, double& val);

    friend
    GE_DLLEXPIMPORT
    ZSoft::Boolean operator >       (double val, const ZcGeInterval& intrvl);
    ZSoft::Boolean operator >       (double val) const;
    ZSoft::Boolean operator >       (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    ZSoft::Boolean operator >=      (double val, const ZcGeInterval& intrvl);
    ZSoft::Boolean operator >=      (double val) const;
    ZSoft::Boolean operator >=      (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    ZSoft::Boolean operator <       (double val, const ZcGeInterval& intrvl);
    ZSoft::Boolean operator <       (double val) const;
    ZSoft::Boolean operator <       (const ZcGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    ZSoft::Boolean operator <=      (double val, const ZcGeInterval& intrvl);
    ZSoft::Boolean operator <=      (double val) const;
    ZSoft::Boolean operator <=      (const ZcGeInterval& otherInterval) const;

protected:
    friend class ZcGeImpInterval;

    ZcGeImpInterval  *mpImpInt;

    ZcGeInterval (ZcGeImpInterval&, int);

private:
    int              mDelInt;
};

#pragma pack (pop)
#endif
