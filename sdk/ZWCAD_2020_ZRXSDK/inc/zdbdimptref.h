

#ifndef ZD_DIMREFPT_H
#define ZD_DIMREFPT_H


typedef ZcArray<ZcDbFullSubentPath, ZcArrayObjectCopyReallocator<ZcDbFullSubentPath> >
	ZcDbFullSubentPathArray;

typedef ZcArray<ZcDbHandle, ZcArrayObjectCopyReallocator<ZcDbHandle> >
	ZcDbHandleArrayPtRef;

class ZcDbPointRef : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbPointRef);

	enum OsnapType { 
		kOsnapNone         = 0,
		kOsnapEnd          = 1,
		kOsnapMid          = 2,
		kOsnapCen          = 3,
		kOsnapNode         = 4,
		kOsnapQuad         = 5, 
		kOsnapInt          = 6,
		kOsnapIns          = 7,
		kOsnapPerp         = 8,
		kOsnapTan          = 9,
		kOsnapNear         = 10,
		kOsnapApint        = 11,
		kOsnapPar          = 12,
		kOsnapStart        = 13
	};

	virtual ZcDbPointRef& operator=(const ZcDbPointRef& src);
	virtual Zcad::ErrorStatus evalPoint(ZcGePoint3d& pnt_wcs)=0; 
	virtual Zcad::ErrorStatus getEntities(ZcDbFullSubentPathArray& ents,
							  bool getLastPtRef = true) const=0;
	virtual bool              isGeomErased() const=0;
	virtual bool              isXrefObj(ZcDbObjectIdArray& ids1,
										ZcDbObjectIdArray& ids2,
										bool isMainObj = true) const=0;
	virtual Zcad::ErrorStatus updateXrefSubentPath()=0;

	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer,
										   ZcDbDatabase* pDb) const=0;
	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer,
										  ZcDbDatabase* pDb)=0;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer,
										   ZcDbDatabase* pDb) const=0;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer,
										  ZcDbDatabase* pDb)=0;

	virtual Zcad::ErrorStatus subErase(ZSoft::Boolean erasing) 
								{return Zcad::eOk;}
	virtual Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
										  ZcDbObject*& pClonedObject,
										  ZcDbIdMapping& idMap,
										  ZSoft::Boolean isPrimary = ZSoft::kTrue)
										  const {return Zcad::eOk;}
	virtual Zcad::ErrorStatus deepClone(ZcRxObject* pOwnerObject,
										ZcDbObject*& pClonedObject,
										ZcDbIdMapping& idMap,
										ZSoft::Boolean isPrimary = ZSoft::kTrue)
										const {return Zcad::eOk;}

	static Zcad::ErrorStatus  dwgInFields(ZcDbDwgFiler* filer,
										  ZcDbDatabase* pDb,
										  ZcDbPointRef*& pPointRef);
	static Zcad::ErrorStatus  dwgOutFields(ZcDbDwgFiler* filer,
										   ZcDbDatabase* pDb,
										   const ZcDbPointRef* pPointRef);
	static Zcad::ErrorStatus  dxfInFields(ZcDbDxfFiler* filer,
										  ZcDbDatabase* pDb,
										  ZcDbPointRef*& pPointRef);
	static Zcad::ErrorStatus  dxfOutFields(ZcDbDxfFiler* filer,
										   ZcDbDatabase* pDb,
										   const ZcDbPointRef* pPointRef);

	static ZcDbEntity*        subentPtr(const ZcDbFullSubentPath& objPath, 
										bool& isCloned, bool& reverseArc);
	static bool               calcTransform(const ZcDbObjectIdArray& ids,
											ZcGeMatrix3d& A_Ecs2Wcs);
	static ZcGeMatrix3d       wcsToDcsMatrix(const ZcDbViewport* pVPort);
	static ZcGeMatrix3d       mswcsToPswcs(const ZcDbViewport* pVPort);
};

class ZcDbOsnapPointRef : public ZcDbPointRef
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbOsnapPointRef);

	ZcDbOsnapPointRef();
	ZcDbOsnapPointRef(const ZcGePoint3d& refPt);
	ZcDbOsnapPointRef(ZcDbPointRef::OsnapType osnapType, 
					  const ZcDbFullSubentPath *objPath, 
					  const ZcDbFullSubentPath *intObjPath = NULL,
					  const ZcGePoint3d *refPt = NULL,
					  ZcDbPointRef* lastPtRef = NULL);
	ZcDbOsnapPointRef(const ZcDbOsnapPointRef& src);
	virtual ~ZcDbOsnapPointRef();

	virtual ZcDbPointRef& operator= (const ZcDbPointRef& src);
	ZcDbOsnapPointRef& operator= (const ZcDbOsnapPointRef& src);

	ZcDbPointRef::OsnapType osnapType() const;
	Zcad::ErrorStatus  setOsnapType(ZcDbPointRef::OsnapType osnType);

	Zcad::ErrorStatus  getIdPath(ZcDbFullSubentPath& idPath) const;
	Zcad::ErrorStatus  setIdPath(const ZcDbFullSubentPath& idPath);

	Zcad::ErrorStatus  getIntIdPath(ZcDbFullSubentPath& intIdPath) const;
	Zcad::ErrorStatus  setIntIdPath(const ZcDbFullSubentPath& intIdPath);

	Zcad::ErrorStatus  setLastPointRef(ZcDbPointRef *ptRef);
	ZcDbPointRef*      lastPointRef() const;

	Zcad::ErrorStatus  setPoint(const ZcGePoint3d& pt);
	ZcGePoint3d        point() const;

	double             nearPointParam() const;
	Zcad::ErrorStatus  setNearPointParam(double newVal);

	virtual bool       isGeomErased() const;
	virtual bool       isXrefObj(ZcDbObjectIdArray& ids1,
								 ZcDbObjectIdArray& ids2,
								 bool isMainObj = true) const;
	virtual Zcad::ErrorStatus updateXrefSubentPath();
	virtual Zcad::ErrorStatus evalPoint(ZcGePoint3d &pt);

	virtual Zcad::ErrorStatus getEntities(ZcDbFullSubentPathArray& ents,
										  bool getLastPtRef = true) const;
	virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* pSrc);
	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer,
										  ZcDbDatabase* pDb);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer,
										   ZcDbDatabase* pDb) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer,
										  ZcDbDatabase *pDb);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer,
										   ZcDbDatabase *pDb) const;

	Zcad::ErrorStatus  getXrefHandles(ZcDbHandleArrayPtRef& xrefHandles) const;
	Zcad::ErrorStatus  setXrefHandles(const ZcDbHandleArrayPtRef& xrefHandles);

	Zcad::ErrorStatus  getXrefIntHandles(ZcDbHandleArrayPtRef& xrefHandles) const;
	Zcad::ErrorStatus  setXrefIntHandles(const ZcDbHandleArrayPtRef& xrefHandles);

protected:
	ZcGePoint3d        nearPoint();
	double             findNearPointParam(const ZcGePoint3d& pt) const;
	bool               getEllipseParams(double& sP, double& eP) const;
	bool               isTransSpatial(bool isMainObj = true) const;

	Zcad::ErrorStatus  evalPointGuts(ZcDbPointRef::OsnapType ospType,
									 const ZcGePoint3d& pickPt,
									 const ZcGePoint3d& lastPt,
									 ZcGePoint3d &pt);

	Zcad::ErrorStatus  getIntPoints(const ZcDbEntity* pEnt,
									const ZcDbEntity* pIntEnt,
									ZcDb::Intersect intType,
									ZcGePoint3dArray& intPts,
									int gsMarker1 = 0,
									int gsMarker2 = 0) const;

private:
	OsnapType          mOsnapType;
	ZcDbFullSubentPath mObjPath;
	ZcDbFullSubentPath mIntObjPath;
	double             mNearPointParam;
	ZcGePoint3d        mPoint;
	ZcDbPointRef*      mpLastPointRef;

	ZcDbHandleArrayPtRef    mHandleArray;
	ZcDbHandleArrayPtRef    mIntHandleArray;
};

#endif //ZD_DIMREFPT_H
