

#ifndef ZD_DIMASSOC_H
#define ZD_DIMASSOC_H

class ZcDbPointRef;
class ZcDbLeader;
class ZcDbMLeader;

class ZcDbDimAssoc : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDimAssoc);

    enum { kMaxPointRefs = 4 };

    enum PointType {
		kXline1Point      = 0,
		kXline2Point      = 1,
		kOriginPoint      = 0,
		kDefiningPoint    = 1,
		kXline1Start      = 0,
		kXline1End        = 1,
		kXline2Start      = 2,
		kXline2End        = 3,
		kVertexPoint      = 2,
		kChordPoint       = 0,
		kCenterPoint      = 1,
		kFarChordPoint    = 1,
		kOverrideCenterPoint   = 2,
		kAngLineStart     = 2,
		kJogPoint         = 3,
    	kAngLineEnd       = 3,
		kLeaderPoint      = 0
	};

    enum AssocFlags {
        kFirstPointRef     = 1,
        kSecondPointRef    = 2,
        kThirdPointRef     = 4,
        kFourthPointRef    = 8
    };

    enum RotatedDimType {
        kUnknown       = 0,
        kParallel      = 1,
        kPerpendicular = 2
    };

	ZcDbDimAssoc();
	virtual ~ZcDbDimAssoc();
	ZcDbObjectId dimObjId() const;
	Zcad::ErrorStatus setDimObjId(const ZcDbObjectId& dimId);
	Zcad::ErrorStatus setAssocFlag(int ptType, bool value);
	void setAssocFlag(int assocFlg);
	bool assocFlag(int ptType) const;
	int assocFlag(void);
	Zcad::ErrorStatus setPointRef(int ptType, ZcDbPointRef* ptRef);
	const ZcDbPointRef *pointRef(int ptType) const;
	Zcad::ErrorStatus setRotatedDimType(RotatedDimType dimType);
	RotatedDimType    rotatedDimType() const;
	Zcad::ErrorStatus addToPointRefReactor();
	Zcad::ErrorStatus addToDimensionReactor(bool isAdd = true);
	Zcad::ErrorStatus removePointRef(int ptType);
	Zcad::ErrorStatus updateDimension(bool update = true, bool skipReactors = false);
	Zcad::ErrorStatus removeAssociativity(bool force = true);
	bool              isTransSpatial() const;
	Zcad::ErrorStatus setTransSpatial(bool value);
	Zcad::ErrorStatus startCmdWatcher();

	Zcad::ErrorStatus startOopsWatcher(bool bAddAll = true);
	void              removeOopsWatcher(void);
	Zcad::ErrorStatus restoreAssocFromOopsWatcher(void);
	bool              hasOopsWatcher(void) const;
	Zcad::ErrorStatus post(ZcDbObjectId dimId, 
							ZcDbObjectId& dimAssocId, 
							bool isActive = true);
	Zcad::ErrorStatus getDimAssocGeomIds(ZcDbObjectIdArray& geomIds) const;
	bool              isAllGeomErased() const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler*);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler*);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;
	virtual void modifiedGraphics(const ZcDbEntity* pObj);

	virtual Zcad::ErrorStatus swapReferences (const ZcDbIdMapping& idMap);


	Zcad::ErrorStatus updateFillet(const ZcDbObjectIdArray& ids);
	Zcad::ErrorStatus updateAssociativity(const ZcDbObjectIdArray& ids);
	Zcad::ErrorStatus updateXrefSubentPath();
	Zcad::ErrorStatus updateSubentPath(ZcDbIdMapping& idMap);
	void updateDueToMirror(bool wasInMirror);

protected:
	Zcad::ErrorStatus   setPointRefReactor  (int ptType, 
											 bool isAdd = true);
	Zcad::ErrorStatus   removeDimExtDict    (void);
	bool                isPointBetweenRays  (const ZcGePoint3d& vertex, 
											 const ZcGePoint3d& firstPt, 
											 const ZcGePoint3d& secondPt, 
											 const ZcGePoint3d& angPt,
											 const ZcGeVector3d& normal);
	Zcad::ErrorStatus   updateDimension     (ZcDbRotatedDimension* pRotDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbAlignedDimension* pAlnDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbRadialDimension* pRadDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbRadialDimensionLarge* pRadDimLarge, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbDiametricDimension* pDiaDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDb2LineAngularDimension* pA2Dim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDb3PointAngularDimension* pA3Dim,
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbOrdinateDimension* pOrdDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbArcDimension* pArcDim, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbLeader* pLeader, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimension     (ZcDbMLeader* pMLeader, 
											 ZcGePoint3d* pNewPts, 
											 bool bUpdate = true);
	Zcad::ErrorStatus   updateDimLineAndTextLocation(ZcDbRotatedDimension* pAlnDim, 
											 const ZcGePoint3d* kpOldPts, 
											 const ZcGePoint3d* kpNewPts);
	Zcad::ErrorStatus   updateDimLineAndTextLocation(ZcDbAlignedDimension* pAlnDim, 
											 const ZcGePoint3d* pOldPts, 
											 const ZcGePoint3d* pNewPts);
	Zcad::ErrorStatus   updateDimLineAndTextLocation(ZcDb2LineAngularDimension* pA2Dim, 
											 const ZcGePoint3d* pOldPts, 
											 const ZcGePoint3d* pNewPts);
	Zcad::ErrorStatus   updateDimLineAndTextLocation(ZcDb3PointAngularDimension* pA3Dim, 
											 const ZcGePoint3d* pOldPts, 
											 const ZcGePoint3d* pNewPts);
	Zcad::ErrorStatus   updateDimLineAndTextLocation(ZcDbArcDimension* pArcDim, 
											 const ZcGePoint3d* kpOldPts, 
											 const ZcGePoint3d* kpNewPts);
	Zcad::ErrorStatus   calculate3PointAngDimArcLocation(const ZcGePoint3d* kpOldPts, 
											 const ZcGePoint3d& kOldArcPt, 
											 const ZcGePoint3d& kOldTextPt, 
											 const ZcGePoint3d* kpNewPts, 
											 const ZcGeVector3d& normal, 
											 ZcGePoint3d& newArcPt, 
											 ZcGePoint3d& newTextPt);
	Zcad::ErrorStatus   calculate2LineAngDimArcLocation(const ZcGePoint3d* kpOldPts, 
											 const ZcGePoint3d& kOldArcPt, 
											 const ZcGePoint3d& kOldTextPt, 
											 const ZcGePoint3d* kpNewPts, 
											 const ZcGeVector3d& kNormal, 
											 ZcGePoint3d& newArcPt, 
											 ZcGePoint3d& newTextPt);


};


Zcad::ErrorStatus
zcdbPostDimAssoc(ZcDbObjectId dimId, ZcDbDimAssoc* pDimAssoc, 
				 ZcDbObjectId& dimAssocId, bool isActive = true);

Zcad::ErrorStatus
zcdbUpdateDimension(ZcDbObjectId dimId);

 
Zcad::ErrorStatus
zcdbUpdateAllDimensions(ZcDbDatabase* pDb);


Zcad::ErrorStatus
zcdbGetDimAssocId(ZcDbObjectId dimId, ZcDbObjectId& dimAssocId);


Zcad::ErrorStatus
zcdbGetDimAssocIds(ZcDbObjectId entId, ZcDbObjectIdArray& dimAssocIds);


bool
zcdbIsTransSpatial(const ZcDbFullSubentPath& idPath);

#endif  //  ZD_DBDIMASSOC_H
