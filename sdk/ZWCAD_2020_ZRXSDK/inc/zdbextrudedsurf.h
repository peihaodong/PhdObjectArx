
#pragma once

#ifndef ZDBEXTRUDEDSURF_H
#define ZDBEXTRUDEDSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)
class ZcDbExtrudedSurface: public ZcDbSurface
{
public:
    ZcDbExtrudedSurface ();
    virtual ~ZcDbExtrudedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbExtrudedSurface);
    virtual Zcad::ErrorStatus createExtrudedSurface ( ZcDbEntity* pSweepEnt,
        const ZcGeVector3d& directionVec, ZcDbSweepOptions& sweepOptions );
    ZcDbEntity*   getSweepEntity () const;
    ZcGeVector3d       getSweepVec () const;
    Zcad::ErrorStatus  setSweepVec ( const ZcGeVector3d& sweepVec );
    double             getHeight () const;
    Zcad::ErrorStatus  setHeight ( double height );
    void               getSweepOptions ( ZcDbSweepOptions& sweepOptions ) const;
    Zcad::ErrorStatus  setSweepOptions ( const ZcDbSweepOptions& sweepOptions );
    Zcad::ErrorStatus  setExtrude ( const ZcGeVector3d& sweepVec,
                                    const ZcDbSweepOptions& sweepOptions );
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

    virtual Zcad::ErrorStatus getGripEntityUCS ( const void* pGripAppData,
                                                 ZcGeVector3d& normalVec,
                                                 ZcGePoint3d& origin,
                                                 ZcGeVector3d& xAxis ) const;

    virtual bool isDependent() const;

};

#pragma pack(pop)

#endif 
