

#ifndef ZD_DBOLE_H
#define ZD_DBOLE_H

#include "zdbmain.h"
#include "zdbframe.h"
#include "zgepnt3d.h"

#pragma pack (push, 8)

class CRectangle3d
{
public:
    ZcGePoint3d upLeft;
    ZcGePoint3d upRight;
    ZcGePoint3d lowLeft;
    ZcGePoint3d lowRight;
};
class CRect;

class ZcDbOleFrame: public ZcDbFrame
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbOleFrame);

    ZcDbOleFrame();
    virtual ~ZcDbOleFrame();

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;
    virtual ZSoft::Boolean worldDraw(ZcGiWorldDraw*);
    virtual void viewportDraw(ZcGiViewportDraw* mode);
    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;

    virtual void* getOleObject(void) const;
    virtual void setOleObject(const void *pItem);

};

class ZcDbOle2Frame: public ZcDbOleFrame
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbOle2Frame);
    ZcDbOle2Frame();
    virtual ~ZcDbOle2Frame();

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const;

    virtual ZSoft::Boolean worldDraw(ZcGiWorldDraw*);
    virtual void viewportDraw(ZcGiViewportDraw* mode);
    virtual Zcad::ErrorStatus getGeomExtents(ZcDbExtents& extents) const;
    virtual Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus getTransformedCopy(const ZcGeMatrix3d& xform,
						                         ZcDbEntity*& ent) const;    
    virtual Zcad::ErrorStatus explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus getOsnapPoints(ZcDb::OsnapMode osnapMode,
                                ZSoft::GsMarker     gsSelectionMark,
                                const ZcGePoint3d&  pickPoint,
                                const ZcGePoint3d&  lastPoint,
                                const ZcGeMatrix3d& viewXform,
                                ZcGePoint3dArray&   snapPoints,
                                ZcDbIntArray &       geomIds) const;
    virtual Zcad::ErrorStatus	getGripPoints(ZcGePoint3dArray&    gripPoints,
								              ZcDbIntArray& 	   osnapModes,
								              ZcDbIntArray& 	   geomIds) const;
    virtual Zcad::ErrorStatus	moveGripPointsAt(const ZcDbIntArray& indices,
								                 const ZcGeVector3d& offset);
    virtual Zcad::ErrorStatus	getStretchPoints(ZcGePoint3dArray&  stretchPoints) const;
    virtual Zcad::ErrorStatus	moveStretchPointsAt(const ZcDbIntArray& indices,
								                    const ZcGeVector3d& offset);
  virtual Zcad::ErrorStatus   getSubentPathsAtGsMarker(ZcDb::SubentType      type,
                                                       ZSoft::GsMarker       gsMark,
                                                       const ZcGePoint3d&    pickPoint,
                                                       const ZcGeMatrix3d&   viewXform,
                                                       int&                  numPaths,
                                                       ZcDbFullSubentPath*&  subentPaths,
                                                       int                   numInserts = 0,
				                                       ZcDbObjectId*         entAndInsertStack = 0
                                                      ) const;

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                               const ZcDbFullSubentPath& subPath, 
                               ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual ZcDbEntity*        subentPtr(const ZcDbFullSubentPath& id) const;

    ZcCmTransparency            transparency() const;
    virtual Zcad::ErrorStatus   setTransparency(const ZcCmTransparency& trans,
                                                ZSoft::Boolean doSubents = true);

    ZcDb::Visibility            visibility() const;
    virtual Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal,
                                              ZSoft::Boolean doSubents = true);

    virtual void                list() const;
    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);

    virtual Zcad::ErrorStatus	intersectWith(
                                        const ZcDbEntity*   ent,
				                        ZcDb::Intersect     intType,
				                        ZcGePoint3dArray&   points,
                                        ZSoft::GsMarker     thisGsMarker  = 0,
                                        ZSoft::GsMarker     otherGsMarker = 0
                                                 ) const;
 
    virtual Zcad::ErrorStatus	intersectWith(
				                        const ZcDbEntity*   ent,
				                        ZcDb::Intersect     intType,
				                        const ZcGePlane&    projPlane,
				                        ZcGePoint3dArray&      points,
                                        ZSoft::GsMarker     thisGsMarker  = 0,
                                        ZSoft::GsMarker     otherGsMarker = 0
                                                 ) const;

    virtual void* getOleObject(void) const;
    virtual void setOleObject(const void *pItem);

    virtual void getLocation(ZcGePoint3d& point3d) const;

    void setLocation(const ZcGePoint3d& point3d);

    virtual void position(CRectangle3d& rect3d) const;

    virtual void setPosition(const CRectangle3d& rect3d);

    virtual void position(RECT& rect) const;

    virtual void setPosition(const RECT& rect);

    virtual void getUserType(ZTCHAR * pszName, int nNameSize) const;

    virtual int getType(void) const;

    virtual ZSoft::Boolean getLinkName(ZTCHAR * pszName, int nNameSize) const;

    virtual ZSoft::Boolean getLinkPath(ZTCHAR * pszPath, int nPathSize) const;

    virtual ZSoft::UInt8 outputQuality() const;
    virtual void setOutputQuality(ZSoft::UInt8);

	ZSoft::Boolean autoOutputQuality() const;
	void setAutoOutputQuality(ZSoft::UInt8);

    double rotation() const;
    Zcad::ErrorStatus setRotation(const double rotation);

    double wcsWidth() const;
    Zcad::ErrorStatus setWcsWidth(const double wcsWidth);

    double wcsHeight() const;
    Zcad::ErrorStatus setWcsHeight(const double wcsHeight);

    double scaleWidth() const;
    Zcad::ErrorStatus setScaleWidth(const double scaleWidth);

    double scaleHeight() const;
    Zcad::ErrorStatus setScaleHeight(const double scaleHeight);

    ZSoft::Boolean lockAspect() const;
    Zcad::ErrorStatus setLockAspect(const ZSoft::Boolean bLockAspect);

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

#pragma pack (pop)

#endif  
