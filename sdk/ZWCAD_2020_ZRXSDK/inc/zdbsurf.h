
#pragma once

#ifndef ZDBSURF_H
#define ZDBSURF_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbbody.h"
#include "zdbRevolveOptions.h"
#include "zdbSweepOptions.h"
#include "zdbLoftOptions.h"

#pragma pack(push, 8)

class ZcDbSurface: public ZcDbEntity
{
public:
    ZcDbSurface();
    virtual ~ZcDbSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbSurface);
    static Zcad::ErrorStatus createFrom ( const ZcDbEntity* pFromEntity,
                                          ZcDbSurface*& pNewSurface );
    virtual Zcad::ErrorStatus convertToRegion ( ZcArray<ZcDbEntity*>& regions );
    virtual Zcad::ErrorStatus thicken(double thickness,
        bool bBothSides, ZcDb3dSolid*& pSolid) const;

	virtual Zcad::ErrorStatus createInterferenceObjects(ZcArray<ZcDbEntity*>& interferenceObjects, ZcDbEntity* pEntity, unsigned int flags ) const;

	virtual Zcad::ErrorStatus booleanUnion(const ZcDbSurface* pSurface2, ZcDbSurface*& pNewSurface);
	virtual Zcad::ErrorStatus booleanSubtract(const ZcDbSurface* pSurface2, ZcDbSurface*& pNewSurface);
	virtual Zcad::ErrorStatus booleanSubtract(const ZcDb3dSolid* pSolid, ZcDbSurface*& pNewSurface);
	virtual Zcad::ErrorStatus booleanIntersect(const ZcDbSurface* pSurface2, ZcArray<ZcDbEntity*>& intersectionEntities);
	virtual Zcad::ErrorStatus booleanIntersect(const ZcDb3dSolid* pSolid, ZcArray<ZcDbEntity*>& intersectionEntities);
	virtual Zcad::ErrorStatus imprintEntity(const ZcDbEntity* pEntity);
	virtual Zcad::ErrorStatus createSectionObjects(const ZcGePlane& sectionPlane, ZcArray<ZcDbEntity*>& sectionObjects) const;
	virtual Zcad::ErrorStatus sliceByPlane(const ZcGePlane& slicePlane,	ZcDbSurface*& pNegHalfSurface, ZcDbSurface*& pNewSurface);
	virtual Zcad::ErrorStatus sliceBySurface(const ZcDbSurface* pSlicingSurface, ZcDbSurface*& pNegHalfSurface,	ZcDbSurface*& pNewSurface);
	virtual Zcad::ErrorStatus chamferEdges(const ZcArray<ZcDbSubentId *> &edgeSubentIds, const ZcDbSubentId& baseFaceSubentId, double baseDist, double otherDist);
	virtual Zcad::ErrorStatus filletEdges(const ZcArray<ZcDbSubentId *> &edgeSubentIds,
		const ZcGeDoubleArray& radius, 
		const ZcGeDoubleArray& startSetback, 
		const ZcGeDoubleArray& endSetback);
	virtual Zcad::ErrorStatus setSubentColor(const ZcDbSubentId& subentId, const ZcCmColor& color);
	virtual Zcad::ErrorStatus getSubentColor(const ZcDbSubentId& subentId, ZcCmColor& color) const;

	virtual Zcad::ErrorStatus setSubentMaterial(const ZcDbSubentId& subentId, const ZcDbObjectId& matId);
	virtual Zcad::ErrorStatus getSubentMaterial(const ZcDbSubentId& subentId, ZcDbObjectId& matId) const;

	virtual Zcad::ErrorStatus setSubentMaterialMapper(const ZcDbSubentId& subentId,	const ZcGiMapper& mapper);
	virtual Zcad::ErrorStatus getSubentMaterialMapper(const ZcDbSubentId& subentId,	ZcGiMapper& mapper) const;

    virtual Zcad::ErrorStatus getArea(double& area) const;

	ZCDB_PORT virtual void dragStatus(const ZcDb::DragStat);
	virtual void* ZSMBodyCopy(bool bDeepCopy = false) const;      
	virtual void const *      getLockedZSMBody();                 
	virtual void              unlockZSMBody();                    
	virtual void*             getLockedWritableZSMBody();         
	virtual void              commitWritableZSMBody();            
	virtual Zcad::ErrorStatus setZSMBody(const void* modelerBody);


    virtual ZcDbSubentId internalSubentId(void* ent) const;
    virtual void* internalSubentPtr(const ZcDbSubentId& id) const;
    virtual void list() const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
	virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual ZSoft::UInt16       uIsolineDensity() const;
    virtual Zcad::ErrorStatus   setUIsolineDensity(ZSoft::UInt16 numIsolines);

    virtual ZSoft::UInt16       vIsolineDensity() const;
    virtual Zcad::ErrorStatus   setVIsolineDensity(ZSoft::UInt16 numIsolines);

	virtual Zcad::ErrorStatus getPlane(ZcGePlane& plane, ZcDb::Planarity& planarity) const;
	ZCDB_PORT virtual bool usesGraphicsCache();
};

#pragma pack(pop)

#endif 
