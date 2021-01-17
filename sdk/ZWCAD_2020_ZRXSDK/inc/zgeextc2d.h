

#ifndef ZC_GEEXTC2D_H
#define ZC_GEEXTC2D_H

#include "zgecurv2d.h"
#include "zgearc2d.h"
#include "zgevec2d.h"
#include "zgepnt2d.h"
#pragma pack (push, 8)

class ZcGeNurbCurve2d;
class ZcGeExternalCurve2d;
class ZcGeExternalCurve2d;

class
GX_DLLEXPIMPORT
ZcGeExternalCurve2d : public ZcGeCurve2d
{
public:
    ZcGeExternalCurve2d();
    ZcGeExternalCurve2d(const ZcGeExternalCurve2d&);
    ZcGeExternalCurve2d(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                        ZSoft::Boolean makeCopy = ZSoft::kTrue);

    ZSoft::Boolean isNurbCurve() const;
    ZSoft::Boolean isNurbCurve(ZcGeNurbCurve2d& nurbCurve) const;
    ZSoft::Boolean isDefined  () const;

    void           getExternalCurve(void*& curveDef) const;

    ZcGe::ExternalEntityKind externalCurveKind() const;

    ZcGeExternalCurve2d& set(void* curveDef, ZcGe::ExternalEntityKind curveKind,
                             ZSoft::Boolean makeCopy = ZSoft::kTrue);

    ZcGeExternalCurve2d& operator = (const ZcGeExternalCurve2d& src);

    ZSoft::Boolean       isOwnerOfCurve() const;
    ZcGeExternalCurve2d& setToOwnCurve();
};

#pragma pack (pop)
#endif
