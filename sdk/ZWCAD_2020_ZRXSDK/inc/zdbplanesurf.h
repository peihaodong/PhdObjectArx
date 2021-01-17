
#pragma once

#ifndef ZDBPLANESURF_H
#define ZDBPLANESURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)

class ZcDbPlaneSurface: public ZcDbSurface
{
public:
    ZcDbPlaneSurface ();
    virtual ~ZcDbPlaneSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbPlaneSurface);
    virtual Zcad::ErrorStatus createFromRegion ( ZcDbRegion *pRegion );
    virtual void list() const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus getGripPoints ( ZcGePoint3dArray&  gripPoints,
                                              ZcDbIntArray&  osnapModes,
                                              ZcDbIntArray &  geomIds ) const;
    virtual Zcad::ErrorStatus getGripPoints ( ZcDbGripDataPtrArray& grips,
                                              const double curViewUnitSize,
                                              const int gripSize,
                                              const ZcGeVector3d& curViewDir,
                                              const int bitflags ) const;
    virtual Zcad::ErrorStatus moveGripPointsAt ( const ZcDbIntArray& indices,
                                                 const ZcGeVector3d& offset );
    virtual Zcad::ErrorStatus moveStretchPointsAt ( const ZcDbIntArray& indices,
                                                    const ZcGeVector3d& offset );

    virtual bool isDependent() const;

};
#pragma pack(pop)

#endif 
