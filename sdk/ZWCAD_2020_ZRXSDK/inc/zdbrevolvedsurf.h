#pragma once

#ifndef ZDBREVOLVEDSURF_H
#define ZDBREVOLVEDSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)
class ZcDbRevolvedSurface: public ZcDbSurface
{
public:
    ZcDbRevolvedSurface ();
    virtual ~ZcDbRevolvedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbRevolvedSurface);
    virtual Zcad::ErrorStatus createRevolvedSurface ( ZcDbEntity* pRevEnt,
        const ZcGePoint3d& axisPnt, const ZcGeVector3d& axisDir,
        double revAngle, double startAngle,
        ZcDbRevolveOptions& revolveOptions );
    ZcDbEntity*   getRevolveEntity () const;
    ZcGePoint3d        getAxisPnt () const;
    Zcad::ErrorStatus  setAxisPnt ( const ZcGePoint3d& pnt );
    ZcGeVector3d       getAxisVec () const;
    Zcad::ErrorStatus  setAxisVec ( const ZcGeVector3d& vec );
    double             getRevolveAngle () const;
    Zcad::ErrorStatus  setRevolveAngle ( double ang );
    double             getStartAngle () const;
    void               getRevolveOptions ( ZcDbRevolveOptions& revolveOptions ) const;
    Zcad::ErrorStatus  setRevolveOptions ( const ZcDbRevolveOptions& revolveOptions );
    Zcad::ErrorStatus  setRevolve ( const ZcGePoint3d& axisPnt, const ZcGeVector3d& axisVec,
                                    double revAngle, const ZcDbRevolveOptions& revolveOptions );
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
