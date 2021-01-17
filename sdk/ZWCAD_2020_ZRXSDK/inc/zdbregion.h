

#ifndef ZGEOMENT_DBREGION_H
#define ZGEOMENT_DBREGION_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"

#pragma pack(push, 8)

class ZcDbRegion: public  ZcDbEntity
{
public:
    ZcDbRegion();
    virtual ~ZcDbRegion();
    ZCDB_DECLARE_MEMBERS(ZcDbRegion);

    static  
    Zcad::ErrorStatus createFromCurves(const ZcDbVoidPtrArray& curveSegments, 
                                       ZcDbVoidPtrArray& regions);

    virtual Zcad::ErrorStatus getPerimeter(double&) const;
    virtual Zcad::ErrorStatus getArea(double& regionArea) const;

	ZCDB_PORT virtual void	  dragStatus(const ZcDb::DragStat);
	virtual void*             ZSMBodyCopy(bool bDeepCopy = false) const; 
	virtual void const *      getLockedZSMBody();                        
	virtual void              unlockZSMBody();                           
	virtual void*             getLockedWritableZSMBody();                
	virtual void              commitWritableZSMBody();                   
	virtual Zcad::ErrorStatus setZSMBody(const void* modelerBody);       

    virtual Zcad::ErrorStatus getAreaProp(
                                 const ZcGePoint3d&  origin,
                                 const ZcGeVector3d& xAxis,
                                 const ZcGeVector3d& yAxis,
                                 double&             perimeter,
                                 double&             area,
                                 ZcGePoint2d&        centroid,
                                 double              momInertia[2],
                                 double&             prodInertia,
                                 double              prinMoments[2],
                                 ZcGeVector2d        prinAxes[2],
                                 double              radiiGyration[2],
                                 ZcGePoint2d&        extentsLow,
                                 ZcGePoint2d&        extentsHigh)const;

    virtual Zcad::ErrorStatus getPlane(ZcGePlane& regionPlane) const;

    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect   intType,
                                             ZcGePoint3dArray& points,
                                             ZSoft::GsMarker   thisGsMarker,
                                             ZSoft::GsMarker   otherGsMarker) const;
    virtual  Zcad::ErrorStatus intersectWith(const ZcDbEntity* ent,
                                             ZcDb::Intersect   intType,
                                             const ZcGePlane&  projPlane,
                                             ZcGePoint3dArray& points,
                                             ZSoft::GsMarker   thisGsMarker,
                                             ZSoft::GsMarker   otherGsMarker) const;

    virtual ZSoft::Boolean    isNull () const;
    virtual Zcad::ErrorStatus getNormal(ZcGeVector3d&) const;

    virtual ZcDbSubentId      internalSubentId      (void* ent) const;                
    virtual void*             internalSubentPtr     (const ZcDbSubentId& id) const;

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(ZcDb::SubentType     type,
                                                        ZSoft::GsMarker      gsMark,
                                                        const ZcGePoint3d&   pickPoint,
                                                        const ZcGeMatrix3d&  viewXform,
                                                        int&                 numPaths,
                                                        ZcDbFullSubentPath*& subentPaths,
                                                        int                  numInserts = 0,
                                                        ZcDbObjectId* entAndInsertStack = NULL) const;

    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                 const ZcDbFullSubentPath& subPath,
                                 ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
 
    virtual Zcad::ErrorStatus booleanOper(ZcDb::BoolOperType operation, ZcDbRegion* otherRegion);

    virtual ZSoft::UInt32 numChanges() const;

	ZCDB_PORT virtual bool usesGraphicsCache();
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
};

#pragma pack(pop)

#endif
