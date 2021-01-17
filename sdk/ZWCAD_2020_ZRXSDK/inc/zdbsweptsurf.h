
#pragma once

#ifndef ZDBSWEPTSURF_H
#define ZDBSWEPTSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)

class ZcDbSweptSurface: public ZcDbSurface
{
public:
    ZcDbSweptSurface ();
    virtual ~ZcDbSweptSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbSweptSurface);
    virtual Zcad::ErrorStatus createSweptSurface ( ZcDbEntity* pSweepEnt,
        ZcDbEntity* pPathEnt, ZcDbSweepOptions& sweepOptions );
    ZcDbEntity*   getSweepEntity () const;
    ZcDbEntity*   getPathEntity () const;
    void               getSweepOptions ( ZcDbSweepOptions& sweepOptions ) const;
    Zcad::ErrorStatus  setSweepOptions ( const ZcDbSweepOptions& sweepOptions );
    Zcad::ErrorStatus  getPathLength ( double& len ) const;
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
