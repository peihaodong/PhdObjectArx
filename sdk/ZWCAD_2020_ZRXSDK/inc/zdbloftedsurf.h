
#pragma once

#ifndef ZDBLOFTEDSURF_H
#define ZDBLOFTEDSURF_H

#include "zdbsurf.h"

#pragma pack(push, 8)

class ZcDbLoftedSurface: public ZcDbSurface
{
public:
    ZcDbLoftedSurface ();
    virtual ~ZcDbLoftedSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbLoftedSurface);
    virtual Zcad::ErrorStatus createLoftedSurface (
        ZcArray<ZcDbEntity*>& crossSectionCurves,
        ZcArray<ZcDbEntity*>& guideCurves,
        ZcDbEntity* pPathCurve, ZcDbLoftOptions& loftOptions );
    int           numCrossSections () const;
    ZcDbEntity*   getCrossSection ( int idx ) const;
    int           numGuideCurves () const;
    ZcDbEntity*   getGuideCurve ( int idx ) const;
    ZcDbEntity*   getPathEntity () const;
    void          getLoftOptions ( ZcDbLoftOptions& loftOptions ) const;
    Zcad::ErrorStatus  setLoftOptions ( const ZcDbLoftOptions& loftOptions );
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
