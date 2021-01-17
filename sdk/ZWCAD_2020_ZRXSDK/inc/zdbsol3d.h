

#pragma once
#ifndef ZGEOMENT_DBSOL3D_H
#define ZGEOMENT_DBSOL3D_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zacarray.h"
#include "zdbsurf.h"

#pragma pack(push, 8)
struct LoftData;
class ZcDb3dSolid: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDb3dSolid);
    ZcDb3dSolid();
    virtual ~ZcDb3dSolid();

    virtual Zcad::ErrorStatus createBox(double xLen, double yLen, double zLen);
    virtual Zcad::ErrorStatus createFrustum(double height, double xRadius,
        double yRadius, double topXRadius);
    virtual Zcad::ErrorStatus createSphere(double radius);
    virtual Zcad::ErrorStatus createTorus(double majorRadius, double minorRadius);
    virtual Zcad::ErrorStatus createPyramid(double height, int sides,
        double radius, double topRadius = 0.0 );
    virtual Zcad::ErrorStatus createWedge(double xLen, double yLen, double zLen);
    virtual Zcad::ErrorStatus extrude(const ZcDbRegion* region, double height,
        double taperAngle = 0.0);
    virtual Zcad::ErrorStatus extrudeAlongPath(const ZcDbRegion* region,
        const ZcDbCurve* path, double taperAngle = 0.0);

	virtual Zcad::ErrorStatus sweep(short flag, const ZcDbEntity* sheet, const ZcDbCurve* path,
		int clor, const ZcGePoint3d &basepoint, const ZcGePoint3d &origin, const ZcGeMatrix3d &mat,
		double scale, double twist);

	virtual Zcad::ErrorStatus loft(short flag, const ZcArray<ZcDbEntity*>& lofts, 
		const ZcArray<ZcDbEntity*>& guides, ZcDbCurve* path, const LoftData* loftmode, int color);

    virtual Zcad::ErrorStatus revolve(const ZcDbRegion* region,
        const ZcGePoint3d& axisPoint, const ZcGeVector3d& axisDir,
        double angleOfRevolution);

    virtual Zcad::ErrorStatus createRevolvedSolid ( ZcDbEntity* pRevEnt,
                                                    const ZcGePoint3d& axisPnt,
                                                    const ZcGeVector3d& axisDir,
                                                    double revAngle, double startAngle,
                                                    ZcDbRevolveOptions& revolveOptions );
    virtual Zcad::ErrorStatus createRevolvedSolid ( ZcDbEntity* pRevEnt,
                                                    const ZcDbSubentId& faceSubentId,
                                                    const ZcGePoint3d& axisPnt,
                                                    const ZcGeVector3d& axisDir,
                                                    double revAngle, double startAngle,
                                                    ZcDbRevolveOptions& revolveOptions );

    virtual Zcad::ErrorStatus createSweptSolid ( ZcDbEntity* pSweepEnt,
                                                 ZcDbEntity* pPathEnt,
                                                 ZcDbSweepOptions& sweepOptions );
    virtual Zcad::ErrorStatus createSweptSolid ( ZcDbEntity *pSweepEnt,
                                                 const ZcDbSubentId& faceSubentId,
                                                 ZcDbEntity* pPathEnt,
                                                 ZcDbSweepOptions& sweepOptions );

    virtual Zcad::ErrorStatus createExtrudedSolid ( ZcDbEntity* pSweepEnt,
                                                    const ZcGeVector3d& directionVec,
                                                    ZcDbSweepOptions& sweepOptions );
    virtual Zcad::ErrorStatus createExtrudedSolid ( ZcDbEntity* pSweepEnt,
                                                    const ZcDbSubentId& faceSubentId,
                                                    const ZcGeVector3d& directionVec,
                                                    ZcDbSweepOptions& sweepOptions );
    virtual Zcad::ErrorStatus createExtrudedSolid ( ZcDbEntity* pSweepEnt,
                                                    const ZcDbSubentId& faceSubentId,
                                                    double height,
                                                    ZcDbSweepOptions& sweepOptions );
    
    virtual Zcad::ErrorStatus createLoftedSolid (
        ZcArray<ZcDbEntity*>& crossSectionCurves,
        ZcArray<ZcDbEntity*>& guideCurves,
        ZcDbEntity* pPathCurve, ZcDbLoftOptions& loftOptions );

	virtual Zcad::ErrorStatus createFrom(const ZcDbEntity* pFromEntity);

    virtual  Zcad::ErrorStatus getArea(double& area) const;
	ZCDB_PORT virtual void dragStatus(const ZcDb::DragStat);
	virtual void* ZSMBodyCopy(bool bDeepCopy = false) const;
	virtual void const * getLockedZSMBody();
	virtual void unlockZSMBody(); 
	virtual void*             getLockedWritableZSMBody();
	virtual void              commitWritableZSMBody();
	virtual Zcad::ErrorStatus setZSMBody(const void* modelerBody);


    virtual Zcad::ErrorStatus checkInterference(const ZcDb3dSolid* otherSolid,
        ZSoft::Boolean createNewSolid, ZSoft::Boolean& solidsInterfere,
        ZcDb3dSolid*& commonVolumeSolid)const;

    virtual Zcad::ErrorStatus getMassProp(double& volume,
        ZcGePoint3d& centroid, double momInertia[3], double prodInertia[3],
        double prinMoments[3], ZcGeVector3d prinAxes[3], 
        double radiiGyration[3], ZcDbExtents& extents) const;

    virtual ZSoft::Boolean isNull() const;
    virtual void list() const;

    virtual Zcad::ErrorStatus getSection(const ZcGePlane& plane,
        ZcDbRegion*& sectionRegion) const;

    virtual Zcad::ErrorStatus stlOut(const ZTCHAR* fileName,
        ZSoft::Boolean asciiFormat, double maxSurfaceDeviation = 0.0 ) const;

    virtual ZcDbSubentId internalSubentId(void* ent) const;          
    virtual void* internalSubentPtr(const ZcDbSubentId& id) const;

    virtual Zcad::ErrorStatus getSubentPathsAtGsMarker(ZcDb::SubentType type,
        ZSoft::GsMarker gsMark, const ZcGePoint3d&  pickPoint,
        const ZcGeMatrix3d& viewXform, int& numPaths, 
        ZcDbFullSubentPath*& subentPaths, int numInserts = 0,
        ZcDbObjectId* entAndInsertStack = NULL) const;

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
        const ZcDbFullSubentPath& subPath, ZcArray<ZSoft::GsMarker>& gsMarkers) const;
    virtual ZcDbEntity* subentPtr(const ZcDbFullSubentPath& id) const;

    virtual Zcad::ErrorStatus booleanOper(ZcDb::BoolOperType operation,
        ZcDb3dSolid* solid);

    virtual Zcad::ErrorStatus getSlice(const ZcGePlane& plane,
        ZSoft::Boolean getNegHalfToo, ZcDb3dSolid*& negHalfSolid);
    virtual Zcad::ErrorStatus getSlice(ZcDbSurface* pSurface,
        bool bGetNegHalfToo, ZcDb3dSolid*& pNegHalfSolid);

    virtual ZSoft::UInt32 numChanges() const;

    virtual Zcad::ErrorStatus copyEdge(const ZcDbSubentId &subentId,
        ZcDbEntity *&newEntity);
    virtual Zcad::ErrorStatus copyFace(const ZcDbSubentId &subentId,
        ZcDbEntity *&newEntity);
    virtual Zcad::ErrorStatus extrudeFaces(
        const ZcArray<ZcDbSubentId *> &faceSubentIds, double height, 
        double taper);
    virtual Zcad::ErrorStatus extrudeFacesAlongPath(
        const ZcArray<ZcDbSubentId *> &faceSubentIds, const ZcDbCurve* path);
    virtual Zcad::ErrorStatus imprintEntity(const ZcDbEntity *pEntity);
    virtual Zcad::ErrorStatus cleanBody();
    virtual Zcad::ErrorStatus offsetBody(double offsetDistance);
    ZCDB_PORT virtual Zcad::ErrorStatus offsetFaces(
        const ZcArray<ZcDbSubentId *> &faceSubentIds, double offsetDistance);
    virtual Zcad::ErrorStatus removeFaces(
        const ZcArray<ZcDbSubentId *> &faceSubentIds);
    virtual Zcad::ErrorStatus separateBody(ZcArray<ZcDb3dSolid *> &newSolids);
    virtual Zcad::ErrorStatus shellBody(
        const ZcArray<ZcDbSubentId *> &faceSubentIds, double offsetDistance);
    virtual Zcad::ErrorStatus taperFaces(
        const ZcArray<ZcDbSubentId *> &faceSubentIds, 
        const ZcGePoint3d &basePoint, const ZcGeVector3d &draftVector,
        double draftAngle);
    virtual Zcad::ErrorStatus transformFaces(
        const ZcArray<ZcDbSubentId *> &faceSubentIds,
        const ZcGeMatrix3d &matrix);

    virtual Zcad::ErrorStatus setSubentColor(const ZcDbSubentId &subentId,
        const ZcCmColor &color);
    virtual Zcad::ErrorStatus getSubentColor(const ZcDbSubentId &subentId,
        ZcCmColor &color) const;

    virtual Zcad::ErrorStatus setSubentMaterial(const ZcDbSubentId &subentId,
                                                ZcDbObjectId matId);
    virtual Zcad::ErrorStatus getSubentMaterial(const ZcDbSubentId &subentId,
                                                ZcDbObjectId& matId) const;


    virtual Zcad::ErrorStatus setSubentMaterialMapper(const ZcDbSubentId &subentId,
                                                    const ZcGiMapper& mapper);
    virtual Zcad::ErrorStatus getSubentMaterialMapper(const ZcDbSubentId &subentId,
                                                    ZcGiMapper& mapper) const;

    virtual ZSoft::Boolean    worldDraw(ZcGiWorldDraw* pWd);
    virtual void              viewportDraw(ZcGiViewportDraw *pVpDraw);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual bool recordHistory() const;

    virtual Zcad::ErrorStatus setRecordHistory(bool bRecord);

    virtual bool showHistory() const;

    virtual Zcad::ErrorStatus setShowHistory(bool bShow);

    virtual Zcad::ErrorStatus convertToBrepAtSubentPaths(
                                 const ZcDbFullSubentPathArray& paths);

    virtual Zcad::ErrorStatus chamferEdges(
                            const ZcArray<ZcDbSubentId *> &edgeSubentIds,
                            const ZcDbSubentId& baseFaceSubentId,
                            double baseDist, double otherDist);

    virtual Zcad::ErrorStatus filletEdges(
                            const ZcArray<ZcDbSubentId *> &edgeSubentIds,
                            const ZcGeDoubleArray& radius,
                            const ZcGeDoubleArray& startSetback,
                            const ZcGeDoubleArray& endSetback);
	ZCDB_PORT virtual bool usesGraphicsCache();
};

#pragma pack(pop)

#endif
