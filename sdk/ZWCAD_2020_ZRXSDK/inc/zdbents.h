

#ifndef ZD_DBENTS_H
#define ZD_DBENTS_H

#include "zdbmain.h"
#include "zdbcurve.h"
#include "zgescl3d.h"
#include "zgepnt2d.h"
#include "zdbmtext.h"
#include "zdbbackground.h"
#include "zdbdim.h"
#include "zgept2dar.h"
#include "zgedblar.h"
#include "zdbsymtb.h"
#include "zgemat3d.h"
#include "zAcDbXref.h"
#include "zacgi.h"
#include "zacgiviewport.h"
#include "zacgivisualstyle.h"

#pragma pack(push, 8)

class ZcDbAttribute;
class ZcDbSequenceEnd;
class ZcDb3dPolylineVertex;
class ZcDb2dVertex;
class ZcDbMText;
class ZcDbAnnotationScale;

namespace Ztil 
{
	class Image;
}

class ZcDbText: public ZcDbEntity
{
public:
    ZcDbText();
    ZcDbText(
        const ZcGePoint3d&  position,
        const ZTCHAR*        text,
        ZcDbObjectId        style = ZcDbObjectId::kNull,
        double              height = 0,
        double              rotation = 0);
    ~ZcDbText();
    ZCDB_DECLARE_MEMBERS(ZcDbText);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    ZcGePoint3d         alignmentPoint() const;
    Zcad::ErrorStatus   setAlignmentPoint(const ZcGePoint3d&);
    ZSoft::Boolean      isDefaultAlignment() const;

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual ZSoft::Boolean    isPlanar() const { return ZSoft::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              rotation() const; 
    Zcad::ErrorStatus   setRotation(double);

    double              height() const; 
    Zcad::ErrorStatus   setHeight(double);

    double              widthFactor() const; 
    Zcad::ErrorStatus   setWidthFactor(double);

    ZTCHAR*              textString() const;
    const ZTCHAR*        textStringConst() const;
    Zcad::ErrorStatus   setTextString(const ZTCHAR*);
     
    ZcDbObjectId        textStyle() const;
    Zcad::ErrorStatus   setTextStyle(ZcDbObjectId);
    
    ZSoft::Boolean      isMirroredInX() const;
    Zcad::ErrorStatus   mirrorInX(ZSoft::Boolean);
     
    ZSoft::Boolean      isMirroredInY() const;
    Zcad::ErrorStatus   mirrorInY(ZSoft::Boolean);
     
    ZcDb::TextHorzMode  horizontalMode() const;
    Zcad::ErrorStatus   setHorizontalMode(ZcDb::TextHorzMode);
     
    ZcDb::TextVertMode  verticalMode() const;
    Zcad::ErrorStatus   setVerticalMode(ZcDb::TextVertMode);

    int                 correctSpelling();
    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual ZSoft::UInt32       setAttributes(ZcGiDrawableTraits* pTraits);

    virtual Zcad::ErrorStatus   adjustAlignment(
        const ZcDbDatabase* pDb = nullptr);

    Zcad::ErrorStatus   setField(const ZTCHAR* pszPropName, ZcDbField* pField,
                                 ZcDbObjectId& fieldId);

    Zcad::ErrorStatus   removeField(ZcDbObjectId fieldId);
    Zcad::ErrorStatus   removeField(const ZTCHAR* pszPropName, ZcDbObjectId& returnId);
    Zcad::ErrorStatus   removeField(const ZTCHAR* pszPropName);

    Zcad::ErrorStatus   convertFieldToText();

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
};

class ZcDbAttributeDefinition: public ZcDbText
{
public:
    ZcDbAttributeDefinition();
    ZcDbAttributeDefinition(
        const ZcGePoint3d& position,
        const ZTCHAR*       text,
        const ZTCHAR*       tag,
        const ZTCHAR*       prompt,
        ZcDbObjectId       style = ZcDbObjectId::kNull);
    ~ZcDbAttributeDefinition();
    ZCDB_DECLARE_MEMBERS(ZcDbAttributeDefinition);

    ZTCHAR*              prompt() const;
    const ZTCHAR*        promptConst() const;
    Zcad::ErrorStatus   setPrompt(const ZTCHAR*);
     
    ZTCHAR*              tag() const;
    const ZTCHAR*        tagConst() const;
    Zcad::ErrorStatus   setTag(const ZTCHAR*);
 
    ZSoft::Boolean      isInvisible() const;
    Zcad::ErrorStatus   setInvisible(ZSoft::Boolean);
 
    ZSoft::Boolean      isConstant() const;
    Zcad::ErrorStatus   setConstant(ZSoft::Boolean);
 
    ZSoft::Boolean      isVerifiable() const;
    Zcad::ErrorStatus   setVerifiable(ZSoft::Boolean);
 
    ZSoft::Boolean      isPreset() const;
    Zcad::ErrorStatus   setPreset(ZSoft::Boolean);
     
    ZSoft::UInt16       fieldLength() const;
    Zcad::ErrorStatus   setFieldLength(ZSoft::UInt16);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus   adjustAlignment(
        const ZcDbDatabase* pDb = nullptr);

	bool				lockPositionInBlock() const;
	Zcad::ErrorStatus	setLockPositionInBlock	(bool bValue);
	bool              isMTextAttributeDefinition          () const;
	ZcDbMText *       getMTextAttributeDefinition         () const;
	const ZcDbMText * getMTextAttributeDefinitionConst    () const;
	Zcad::ErrorStatus setMTextAttributeDefinition         (ZcDbMText*);
	Zcad::ErrorStatus convertIntoMTextAttributeDefinition (ZSoft::Boolean val = ZSoft::kTrue);
	Zcad::ErrorStatus updateMTextAttributeDefinition      ();
};

class ZcDbAttribute: public ZcDbText
{
public:
    ZcDbAttribute();
    ZcDbAttribute(
        const ZcGePoint3d& position,
        const ZTCHAR*       text,
        const ZTCHAR*       tag,
        ZcDbObjectId       style = ZcDbObjectId::kNull);
    ~ZcDbAttribute();
    ZCDB_DECLARE_MEMBERS(ZcDbAttribute);

    ZTCHAR*              tag() const;
    const ZTCHAR*        tagConst() const;
    Zcad::ErrorStatus   setTag(const ZTCHAR* newTag);

    ZSoft::Boolean      isInvisible() const;
    Zcad::ErrorStatus   setInvisible(ZSoft::Boolean);

    ZSoft::Boolean      isConstant() const;
    ZSoft::Boolean      isVerifiable() const;
    ZSoft::Boolean      isPreset() const;

    ZSoft::UInt16       fieldLength() const;
    Zcad::ErrorStatus   setFieldLength(ZSoft::UInt16);

    Zcad::ErrorStatus setAttributeFromBlock(const ZcGeMatrix3d& blkXform);
    Zcad::ErrorStatus setAttributeFromBlock(
        const ZcDbAttributeDefinition *pAttdef,
        const ZcGeMatrix3d& blkXform);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    bool lockPositionInBlock() const;
	Zcad::ErrorStatus	setLockPositionInBlock	(bool bValue);
	bool              isMTextAttribute          ()                        const;
	ZcDbMText *       getMTextAttribute         ()                        const;
	const ZcDbMText * getMTextAttributeConst    ()                        const;
	Zcad::ErrorStatus setMTextAttribute         (ZcDbMText *);
	Zcad::ErrorStatus convertIntoMTextAttribute (ZSoft::Boolean val = ZSoft::kTrue);
	Zcad::ErrorStatus updateMTextAttribute      ();
	bool              isReallyLocked            ()                        const;
	
};

class ZcDbBlockReference: public ZcDbEntity
{
public:
            ZcDbBlockReference();
            ZcDbBlockReference(const ZcGePoint3d&  position,
                                     ZcDbObjectId  blockTableRec);
            ~ZcDbBlockReference();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockReference);

            ZcDbObjectId      blockTableRecord() const;
    virtual Zcad::ErrorStatus setBlockTableRecord(ZcDbObjectId);

    virtual ZcGePoint3d       position() const;
    virtual Zcad::ErrorStatus setPosition(const ZcGePoint3d&);

            ZcGeScale3d       scaleFactors() const;
            ZcGeScale3d       nonAnnotationScaleFactors() const;
    virtual Zcad::ErrorStatus setScaleFactors(const ZcGeScale3d& scale);

            double            rotation() const;
    virtual Zcad::ErrorStatus setRotation(double newVal);

            ZcGeVector3d      normal() const;
    virtual Zcad::ErrorStatus setNormal(const ZcGeVector3d& newVal);

    virtual ZSoft::Boolean    isPlanar() const { return ZSoft::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

            ZcGeMatrix3d      blockTransform() const;
            ZcGeMatrix3d      nonAnnotationBlockTransform() const;
    virtual Zcad::ErrorStatus setBlockTransform(const ZcGeMatrix3d&);

            Zcad::ErrorStatus appendAttribute(ZcDbAttribute*);
            Zcad::ErrorStatus appendAttribute(ZcDbObjectId&, ZcDbAttribute*);

            Zcad::ErrorStatus openAttribute(ZcDbAttribute*&, ZcDbObjectId,
                                            ZcDb::OpenMode,
                                            bool openErasedOne = false);

            Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

            ZcDbObjectIterator*  attributeIterator() const;

    virtual ZSoft::Boolean    treatAsZcDbBlockRefForExplode() const;

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                  ZcDb::SubentType,
                                  ZSoft::GsMarker       gsMark,
                                  const ZcGePoint3d&    pickPoint,
                                  const ZcGeMatrix3d&   viewXform,
                                  int&                  numPaths,
                                  ZcDbFullSubentPath*&  subentPaths,
                                  int                   numInserts = 0,
                                  ZcDbObjectId*         entAndInsertStack = nullptr) const;

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                  const ZcDbFullSubentPath& subPath,
                                  ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual Zcad::ErrorStatus highlight  (const ZcDbFullSubentPath&
                                          = kNullSubent, const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;

    virtual Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath&
                                          = kNullSubent, const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;

    virtual ZcDbEntity*       subentPtr  (const ZcDbFullSubentPath&) const;

    virtual ZSoft::Boolean    worldDraw(ZcGiWorldDraw* mode);
    virtual void              viewportDraw(ZcGiViewportDraw* mode);

            Zcad::ErrorStatus geomExtentsBestFit(
                                        ZcDbExtents& extents,
                                        const ZcGeMatrix3d& parentXform =
                                            ZcGeMatrix3d::kIdentity) const;

    virtual Zcad::ErrorStatus explodeToOwnerSpace() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
};

class ZcDbMInsertBlock: public ZcDbBlockReference
{
public:
    ZcDbMInsertBlock();
    ZcDbMInsertBlock(
        const ZcGePoint3d&  position,
        ZcDbObjectId        blockTableRec,
        ZSoft::UInt16       columns,
        ZSoft::UInt16       rows,
        double              colSpacing,
        double              rowSpacing);
    ~ZcDbMInsertBlock();
    ZCDB_DECLARE_MEMBERS(ZcDbMInsertBlock);

    ZSoft::UInt16      columns() const;
    Zcad::ErrorStatus  setColumns(ZSoft::UInt16);

    ZSoft::UInt16      rows() const;
    Zcad::ErrorStatus  setRows(ZSoft::UInt16);

    double             columnSpacing() const;
    Zcad::ErrorStatus  setColumnSpacing(double);

    double             rowSpacing() const;
    Zcad::ErrorStatus  setRowSpacing(double);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbBlockBegin: public ZcDbEntity
{
public:
    ZcDbBlockBegin();
    ~ZcDbBlockBegin();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockBegin);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

class ZcDbBlockEnd: public ZcDbEntity
{
public:
    ZcDbBlockEnd();
    ~ZcDbBlockEnd();
    ZCDB_DECLARE_MEMBERS(ZcDbBlockEnd);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

class ZcDbSequenceEnd: public ZcDbEntity
{
public:
    ZcDbSequenceEnd();
    ~ZcDbSequenceEnd();
    ZCDB_DECLARE_MEMBERS(ZcDbSequenceEnd);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

class ZcDbVertex: public ZcDbEntity
{
public:
    ZcDbVertex();
    ~ZcDbVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbVertex);
};

inline ZcDbVertex::~ZcDbVertex()
{
}

class ZcDb2dVertex: public ZcDbVertex
{
public:
    ZcDb2dVertex();
    ~ZcDb2dVertex();
    ZCDB_DECLARE_MEMBERS(ZcDb2dVertex);
    ZcDb2dVertex(
        const ZcGePoint3d&  position,
        double   bulge      = 0,
        double   startWidth = 0,
        double   endWidth   = 0,
        double   tangent    = 0,
		ZSoft::Int32 vertexIdentifier = 0);

    ZcDb::Vertex2dType vertexType() const;
    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    double              startWidth() const;
    Zcad::ErrorStatus   setStartWidth(double newVal);

    double              endWidth() const;
    Zcad::ErrorStatus   setEndWidth(double newVal);

    double              bulge() const;
    Zcad::ErrorStatus   setBulge(double newVal);

    ZSoft::Boolean      isTangentUsed() const;
    Zcad::ErrorStatus   useTangent();
    Zcad::ErrorStatus   ignoreTangent();

    double              tangent() const;
    Zcad::ErrorStatus   setTangent(double newVal);

	Zcad::ErrorStatus   setVertexIdentifier(ZSoft::Int32 suggestedValue);
	int                 vertexIdentifier() const;
};

class ZcDb3dPolylineVertex: public ZcDbVertex
{
public:
    ZcDb3dPolylineVertex();
    ~ZcDb3dPolylineVertex();
    ZCDB_DECLARE_MEMBERS(ZcDb3dPolylineVertex);
    ZcDb3dPolylineVertex(const ZcGePoint3d&);

    ZcDb::Vertex3dType vertexType() const;
    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);
};

class ZcDbPolygonMeshVertex: public ZcDbVertex
{
public:
    ZcDbPolygonMeshVertex();
    ZcDbPolygonMeshVertex(const ZcGePoint3d&  position);
    ~ZcDbPolygonMeshVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbPolygonMeshVertex);

    ZcDb::Vertex3dType vertexType() const;

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

};

class ZcDbPolyFaceMeshVertex: public ZcDbVertex
{
public:
    ZcDbPolyFaceMeshVertex();
    ZcDbPolyFaceMeshVertex(const ZcGePoint3d&  position);
    ~ZcDbPolyFaceMeshVertex();
    ZCDB_DECLARE_MEMBERS(ZcDbPolyFaceMeshVertex);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

};

class ZcDbFaceRecord: public ZcDbVertex
{
public:
    ZcDbFaceRecord();

    ZcDbFaceRecord(ZSoft::Int16 vtx0, ZSoft::Int16 vtx1,
                   ZSoft::Int16 vtx2, ZSoft::Int16 vtx3);
    ~ZcDbFaceRecord();
    ZCDB_DECLARE_MEMBERS(ZcDbFaceRecord);
    Zcad::ErrorStatus getVertexAt(ZSoft::UInt16 faceIdx,
                                  ZSoft::Int16& vtxIdx) const;
    Zcad::ErrorStatus setVertexAt(ZSoft::UInt16 faceIdx,
                                  ZSoft::Int16  vtxIdx);

    Zcad::ErrorStatus isEdgeVisibleAt(ZSoft::UInt16 faceIndex,
                                      ZSoft::Boolean& visible) const;

    Zcad::ErrorStatus makeEdgeVisibleAt(ZSoft::UInt16 faceIndex);
    Zcad::ErrorStatus makeEdgeInvisibleAt(ZSoft::UInt16 faceIndex);
};

class ZcDb2dPolyline: public ZcDbCurve
{
public:
    ZcDb2dPolyline();
    ~ZcDb2dPolyline();
    ZCDB_DECLARE_MEMBERS(ZcDb2dPolyline);
    ZcDb2dPolyline (
        ZcDb::Poly2dType  type,
        ZcGePoint3dArray& vertices,
        double            elevation     = 0,
        ZSoft::Boolean    closed        = ZSoft::kFalse,
        double            defStartWidth = 0,
        double            defEndWidth   = 0,
        ZcGeDoubleArray*  bulges        = nullptr,
		ZcArray<ZSoft::Int32>* vertexIdentifiers = nullptr);

    DBCURVE_METHODS

    ZcDb::Poly2dType    polyType() const;
    Zcad::ErrorStatus   setPolyType(ZcDb::Poly2dType);
    Zcad::ErrorStatus   convertToPolyType(ZcDb::Poly2dType newVal);

    Zcad::ErrorStatus   makeClosed();
    Zcad::ErrorStatus   makeOpen();

    double              defaultStartWidth() const;
    Zcad::ErrorStatus   setDefaultStartWidth(double);

    double              defaultEndWidth() const;
    Zcad::ErrorStatus   setDefaultEndWidth(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    double              elevation() const;
    Zcad::ErrorStatus   setElevation(double);

    ZSoft::Boolean      isLinetypeGenerationOn() const;
    Zcad::ErrorStatus   setLinetypeGenerationOn();
    Zcad::ErrorStatus   setLinetypeGenerationOff();

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   splineFit();
    Zcad::ErrorStatus   splineFit(ZcDb::Poly2dType splineType,
                                  ZSoft::Int16   splineSegs);
    Zcad::ErrorStatus   curveFit();
    Zcad::ErrorStatus appendVertex(ZcDb2dVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDb2dVertex*);

    Zcad::ErrorStatus insertVertexAt(const ZcDb2dVertex* pIndexVert,
        ZcDb2dVertex* pNewVertex);
    Zcad::ErrorStatus insertVertexAt(ZcDbObjectId& newVertId,
        const ZcDbObjectId& indexVertId, ZcDb2dVertex* pNewVertex);

    Zcad::ErrorStatus openVertex(ZcDb2dVertex*&, ZcDbObjectId    vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false) const;
    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;
    ZcGePoint3d       vertexPosition(const ZcDb2dVertex& vert) const;
    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

inline ZSoft::Boolean ZcDb2dPolyline::isPeriodic() const
{
    return ZSoft::kFalse;
}
inline ZSoft::Boolean ZcDb2dPolyline::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDb2dPolyline::getStartParam(double& param) const
{
    param = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDb2dPolyline::extend (double param)
{
    return Zcad::eNotApplicable;
}
class ZcDb3dPolyline: public ZcDbCurve
{
public:
    ZcDb3dPolyline();
    ~ZcDb3dPolyline();
    ZCDB_DECLARE_MEMBERS(ZcDb3dPolyline);
    ZcDb3dPolyline(ZcDb::Poly3dType, ZcGePoint3dArray& vertices,
                   ZSoft::Boolean closed = ZSoft::kFalse);

    DBCURVE_METHODS

    Zcad::ErrorStatus   makeClosed();
    Zcad::ErrorStatus   makeOpen();

    ZcDb::Poly3dType    polyType() const;
    Zcad::ErrorStatus   setPolyType(ZcDb::Poly3dType);
    Zcad::ErrorStatus   convertToPolyType(ZcDb::Poly3dType newVal);

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   splineFit();
    Zcad::ErrorStatus   splineFit(ZcDb::Poly3dType splineType,
                                  ZSoft::Int16   splineSegs);
    Zcad::ErrorStatus appendVertex(ZcDb3dPolylineVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDb3dPolylineVertex*);

    Zcad::ErrorStatus insertVertexAt(const ZcDb3dPolylineVertex* pIndexVert,
        ZcDb3dPolylineVertex* pNewVertex);
    Zcad::ErrorStatus insertVertexAt(ZcDbObjectId& newVertId,
        const ZcDbObjectId& indexVertId, ZcDb3dPolylineVertex* pNewVertex);

    Zcad::ErrorStatus openVertex(ZcDb3dPolylineVertex*&, ZcDbObjectId vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator* vertexIterator() const;
    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};
inline ZSoft::Boolean    ZcDb3dPolyline::isPeriodic   () const
{
    return ZSoft::kFalse;
}

inline Zcad::ErrorStatus ZcDb3dPolyline::getStartParam(double& param) const
{
    param = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDb3dPolyline::extend(double newparam)
{

    return Zcad::eNotApplicable;
}
class ZcDbArc: public ZcDbCurve
{
public:
    ZcDbArc();
    ZcDbArc(const ZcGePoint3d& center, double radius,
            double startAngle, double endAngle);
    ZcDbArc(const ZcGePoint3d& center, const ZcGeVector3d& normal,
            double radius, double startAngle, double endAngle);
    ~ZcDbArc();
    ZCDB_DECLARE_MEMBERS(ZcDbArc);

    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                      const ZcGeMatrix3d& xform,
                      ZcDbEntity*& ent) const;

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&);

    double              radius() const;
    Zcad::ErrorStatus   setRadius(double);

    double              startAngle() const;
    Zcad::ErrorStatus   setStartAngle(double);

    double              endAngle() const;
    Zcad::ErrorStatus   setEndAngle(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
};

inline ZSoft::Boolean ZcDbArc::isClosed() const
{
    return ZSoft::kFalse;
}
inline ZSoft::Boolean ZcDbArc::isPeriodic() const
{
    return ZSoft::kFalse;
}
inline ZSoft::Boolean ZcDbArc::isPlanar() const
{
    return ZSoft::kTrue;
}

class ZcDbCircle: public ZcDbCurve
{
public:
    ZcDbCircle();
    ZcDbCircle(const ZcGePoint3d& cntr, const ZcGeVector3d& nrm, double radius);
    ~ZcDbCircle();
    ZCDB_DECLARE_MEMBERS(ZcDbCircle);

    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                         const ZcGeMatrix3d& xform,
                         ZcDbEntity*& ent) const;

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&);

    double              radius() const;
    Zcad::ErrorStatus   setRadius(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void        gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
};

inline ZSoft::Boolean ZcDbCircle::isClosed() const
{
    return ZSoft::kTrue;
}

inline ZSoft::Boolean ZcDbCircle::isPeriodic() const
{
    return ZSoft::kTrue;
}

inline ZSoft::Boolean ZcDbCircle::isPlanar () const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbCircle::getStartParam(double& p) const
{
    p = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbCircle::extend(double)
{
    return Zcad::eNotApplicable;
}

inline Zcad::ErrorStatus ZcDbCircle::extend(ZSoft::Boolean, const ZcGePoint3d&)
{
    return Zcad::eNotApplicable;
}
class ZcDbLine: public ZcDbCurve
{
public:
    ZcDbLine();
    ZcDbLine(const ZcGePoint3d& start, const ZcGePoint3d& end);
    ~ZcDbLine();
    ZCDB_DECLARE_MEMBERS(ZcDbLine);

    DBCURVE_METHODS

    Zcad::ErrorStatus getTransformedCopy(
                            const ZcGeMatrix3d& xform,
                            ZcDbEntity*& ent) const;

    Zcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const ZcGeVector3d& normal, double offsetDist,
        ZcDbVoidPtrArray& offsetCurves) const;

    ZcGePoint3d         startPoint() const;
    Zcad::ErrorStatus   setStartPoint(const ZcGePoint3d&);

    ZcGePoint3d         endPoint() const;
    Zcad::ErrorStatus   setEndPoint(const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray &  geomIds) const;
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
};

inline ZSoft::Boolean ZcDbLine::isClosed() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbLine::isPeriodic() const
{
    return ZSoft::kFalse;
}

inline ZSoft::Boolean ZcDbLine::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbLine::getStartParam(double& v1) const
{
    v1 = 0.0;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbLine::getSpline(ZcDbSpline*&) const
{
    return Zcad::eNotApplicable;
}
class ZcDbPoint: public ZcDbEntity
{
public:
    ZcDbPoint();
    ZcDbPoint(const ZcGePoint3d&   position);
    ~ZcDbPoint();
    ZCDB_DECLARE_MEMBERS(ZcDbPoint);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    double              ecsRotation() const;
    Zcad::ErrorStatus   setEcsRotation(double);
    virtual ZSoft::Boolean    isPlanar() const { return ZSoft::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    virtual ZSoft::UInt32     setAttributes(ZcGiDrawableTraits* pTraits);
    virtual ZSoft::Boolean worldDraw(ZcGiWorldDraw* mode);
    virtual void viewportDraw(ZcGiViewportDraw* pVpDraw);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
};

class ZcDbFace: public ZcDbEntity
{
public:
    ZcDbFace();
    ZcDbFace(const ZcGePoint3d&   pt0,
             const ZcGePoint3d&   pt1,
             const ZcGePoint3d&   pt2,
             const ZcGePoint3d&   pt3,
                   ZSoft::Boolean e0vis = ZSoft::kTrue,
                   ZSoft::Boolean e1vis = ZSoft::kTrue,
                   ZSoft::Boolean e2vis = ZSoft::kTrue,
                   ZSoft::Boolean e3vis = ZSoft::kTrue);
    ZcDbFace(const ZcGePoint3d&   pt0,
             const ZcGePoint3d&   pt1,
             const ZcGePoint3d&   pt2,
                   ZSoft::Boolean e0vis = ZSoft::kTrue,
                   ZSoft::Boolean e1vis = ZSoft::kTrue,
                   ZSoft::Boolean e2vis = ZSoft::kTrue,
                   ZSoft::Boolean e3vis = ZSoft::kTrue);
    ~ZcDbFace();
    ZCDB_DECLARE_MEMBERS(ZcDbFace);

    Zcad::ErrorStatus getVertexAt(ZSoft::UInt16, ZcGePoint3d&) const;
    Zcad::ErrorStatus setVertexAt(ZSoft::UInt16, const ZcGePoint3d&);

    Zcad::ErrorStatus isEdgeVisibleAt(ZSoft::UInt16, ZSoft::Boolean&) const;
    Zcad::ErrorStatus makeEdgeVisibleAt(ZSoft::UInt16);
    Zcad::ErrorStatus makeEdgeInvisibleAt(ZSoft::UInt16);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbPolyFaceMesh: public ZcDbEntity
{
public:
    ZcDbPolyFaceMesh();
    ~ZcDbPolyFaceMesh();
    ZCDB_DECLARE_MEMBERS(ZcDbPolyFaceMesh);

    ZSoft::Int16 numVertices() const;
    ZSoft::Int16 numFaces() const;

    Zcad::ErrorStatus appendVertex(ZcDbPolyFaceMeshVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDbPolyFaceMeshVertex*);

    Zcad::ErrorStatus appendFaceRecord(ZcDbFaceRecord*);
    Zcad::ErrorStatus appendFaceRecord(ZcDbObjectId&, ZcDbFaceRecord*);

    Zcad::ErrorStatus openVertex(ZcDbVertex*&, ZcDbObjectId subObjId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbPolygonMesh: public ZcDbEntity
{
public:
    ZcDbPolygonMesh();
    ZcDbPolygonMesh(ZcDb::PolyMeshType pType,
                    ZSoft::Int16       mSize,
                    ZSoft::Int16       nSize,
                    const ZcGePoint3dArray& vertices,
                    ZSoft::Boolean     mClosed = ZSoft::kTrue,
                    ZSoft::Boolean     nClosed = ZSoft::kTrue);
    ~ZcDbPolygonMesh();
    ZCDB_DECLARE_MEMBERS(ZcDbPolygonMesh);

    ZcDb::PolyMeshType  polyMeshType() const;
    Zcad::ErrorStatus   setPolyMeshType(ZcDb::PolyMeshType);
    Zcad::ErrorStatus   convertToPolyMeshType(ZcDb::PolyMeshType newVal);

    ZSoft::Int16        mSize() const;
    Zcad::ErrorStatus   setMSize(ZSoft::Int16);

    ZSoft::Int16        nSize() const;
    Zcad::ErrorStatus   setNSize(ZSoft::Int16);

    ZSoft::Boolean      isMClosed() const;
    Zcad::ErrorStatus   makeMClosed();
    Zcad::ErrorStatus   makeMOpen();

    ZSoft::Boolean      isNClosed() const;
    Zcad::ErrorStatus   makeNClosed();
    Zcad::ErrorStatus   makeNOpen();

    ZSoft::Int16        mSurfaceDensity() const;
    Zcad::ErrorStatus   setMSurfaceDensity(ZSoft::Int16);

    ZSoft::Int16        nSurfaceDensity() const;
    Zcad::ErrorStatus   setNSurfaceDensity(ZSoft::Int16);

    Zcad::ErrorStatus   straighten();
    Zcad::ErrorStatus   surfaceFit();
    Zcad::ErrorStatus   surfaceFit(ZcDb::PolyMeshType surfType,
                                   ZSoft::Int16 surfu, ZSoft::Int16 surfv);
    Zcad::ErrorStatus appendVertex(ZcDbPolygonMeshVertex*);
    Zcad::ErrorStatus appendVertex(ZcDbObjectId& objId, ZcDbPolygonMeshVertex*);

    Zcad::ErrorStatus openVertex(ZcDbPolygonMeshVertex*&, ZcDbObjectId vertId,
                                 ZcDb::OpenMode,
                                 bool openErasedOne = false);

    Zcad::ErrorStatus openSequenceEnd(ZcDbSequenceEnd*&, ZcDb::OpenMode);

    ZcDbObjectIterator*  vertexIterator() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbSolid: public ZcDbEntity
{
public:
    ZcDbSolid();
    ZcDbSolid(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2,
              const ZcGePoint3d&    pt3);
    ZcDbSolid(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2);
    ~ZcDbSolid();
    ZCDB_DECLARE_MEMBERS(ZcDbSolid);

    Zcad::ErrorStatus transformBy(const ZcGeMatrix3d& pXform);
    Zcad::ErrorStatus getTransformedCopy(
              const ZcGeMatrix3d& xform,
              ZcDbEntity*&  pEnt) const;

    Zcad::ErrorStatus getPointAt(ZSoft::UInt16 idx, ZcGePoint3d& pntRes) const;
    Zcad::ErrorStatus setPointAt(ZSoft::UInt16 idx, const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbTrace: public ZcDbEntity
{
public:
    ZcDbTrace();
    ZcDbTrace(const ZcGePoint3d&    pt0,
              const ZcGePoint3d&    pt1,
              const ZcGePoint3d&    pt2,
              const ZcGePoint3d&    pt3);
    ~ZcDbTrace();
    ZCDB_DECLARE_MEMBERS(ZcDbTrace);
    Zcad::ErrorStatus getPointAt(ZSoft::UInt16 idx, ZcGePoint3d& PntRes) const;
    Zcad::ErrorStatus setPointAt(ZSoft::UInt16 idx, const ZcGePoint3d&);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual ZSoft::Boolean    isPlanar() const { return ZSoft::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    virtual bool        castShadows() const;
    virtual bool        receiveShadows() const;
};

class ZcDbShape: public ZcDbEntity
{
public:
    ZcDbShape();
    ZcDbShape(const ZcGePoint3d&  position,
                    double        size,
                    double        rotation    = 0,
                    double        widthFactor = 0);
    ~ZcDbShape();
    ZCDB_DECLARE_MEMBERS(ZcDbShape);

    ZcGePoint3d         position() const;
    Zcad::ErrorStatus   setPosition(const ZcGePoint3d&);

    double              size() const;
    Zcad::ErrorStatus   setSize(double);

    ZTCHAR*              name() const;
    Zcad::ErrorStatus   setName(const ZTCHAR*);

    double              rotation() const;
    Zcad::ErrorStatus   setRotation(double);

    double              widthFactor() const;
    Zcad::ErrorStatus   setWidthFactor(double);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              thickness() const;
    Zcad::ErrorStatus   setThickness(double);

    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual ZSoft::Boolean    isPlanar() const { return ZSoft::kTrue; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const;

    ZSoft::Int16      shapeNumber() const;
    Zcad::ErrorStatus setShapeNumber(ZSoft::Int16);

    ZcDbObjectId        styleId() const;
    Zcad::ErrorStatus   setStyleId(ZcDbObjectId id);
    ZcDbObjectId        shapeIndex() const { return this->styleId(); }
    Zcad::ErrorStatus   setShapeIndex(ZcDbObjectId id)
                                 { return this->setStyleId(id); }

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;
};

class ZcDbViewport: public ZcDbEntity
{
public:
                      ZcDbViewport();
                      ~ZcDbViewport();
    ZCDB_DECLARE_MEMBERS(ZcDbViewport);
    Zcad::ErrorStatus setModelView      (const ZcDbXrefObjectId &xrefObjId);
    Zcad::ErrorStatus getModelView      (ZcDbXrefObjectId &xrefObjId) const;
    Zcad::ErrorStatus removeModelView   (void);

    Zcad::ErrorStatus setSheetView      (ZcDbObjectId objId);
    Zcad::ErrorStatus getSheetView      (ZcDbObjectId &objId)const;
    Zcad::ErrorStatus removeSheetView   (void);

    Zcad::ErrorStatus setLabelBlock     (ZcDbObjectId objId);
    Zcad::ErrorStatus getLabelBlock     (ZcDbObjectId &objId)const;
    Zcad::ErrorStatus removeLabelBlock  (void);

    Zcad::ErrorStatus syncModelView     (void);
#ifdef _WINDOWS_
    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
#endif
    double            height() const;
    Zcad::ErrorStatus setHeight(double);

    double            width() const;
    Zcad::ErrorStatus setWidth(double);

    ZcGePoint3d       centerPoint() const;
    Zcad::ErrorStatus setCenterPoint(const ZcGePoint3d&);

    ZSoft::Int16      number() const;

    bool              isOn() const;
    Zcad::ErrorStatus setOn();
    Zcad::ErrorStatus setOff();

    ZcGePoint3d       viewTarget() const;
    Zcad::ErrorStatus setViewTarget(const ZcGePoint3d&);

    ZcGeVector3d      viewDirection() const;
    Zcad::ErrorStatus setViewDirection(const ZcGeVector3d&);
    double            viewHeight() const;
    Zcad::ErrorStatus setViewHeight(double ht);

    ZcGePoint2d       viewCenter() const;
    Zcad::ErrorStatus setViewCenter(const ZcGePoint2d& pt);

    double            twistAngle() const;
    Zcad::ErrorStatus setTwistAngle(double);

    double            lensLength() const;
    Zcad::ErrorStatus setLensLength(double);

    bool              isFrontClipOn() const;
    Zcad::ErrorStatus setFrontClipOn();
    Zcad::ErrorStatus setFrontClipOff();

    bool              isBackClipOn() const;
    Zcad::ErrorStatus setBackClipOn();
    Zcad::ErrorStatus setBackClipOff();

    bool              isFrontClipAtEyeOn() const;
    Zcad::ErrorStatus setFrontClipAtEyeOn();
    Zcad::ErrorStatus setFrontClipAtEyeOff();
    double            frontClipDistance() const;
    Zcad::ErrorStatus setFrontClipDistance(double newVal);
    double            backClipDistance() const;
    Zcad::ErrorStatus setBackClipDistance(double newVal);

    bool              isPerspectiveOn() const;
    Zcad::ErrorStatus setPerspectiveOn();
    Zcad::ErrorStatus setPerspectiveOff();

    bool              isUcsFollowModeOn() const;
    Zcad::ErrorStatus setUcsFollowModeOn();
    Zcad::ErrorStatus setUcsFollowModeOff();

    bool              isUcsIconVisible() const;
    Zcad::ErrorStatus setUcsIconVisible();
    Zcad::ErrorStatus setUcsIconInvisible();

    bool              isUcsIconAtOrigin() const;
    Zcad::ErrorStatus setUcsIconAtOrigin();
    Zcad::ErrorStatus setUcsIconAtCorner();

	bool              isFastZoomOn() const { return true; }
	Zcad::ErrorStatus setFastZoomOn() { return Zcad::eOk; }
	Zcad::ErrorStatus setFastZoomOff() { return Zcad::eOk; }

    ZSoft::UInt16     circleSides() const;
    Zcad::ErrorStatus setCircleSides(ZSoft::UInt16);

    bool              isSnapOn() const;
    Zcad::ErrorStatus setSnapOn();
    Zcad::ErrorStatus setSnapOff();

    bool              isSnapIsometric() const;
    Zcad::ErrorStatus setSnapIsometric();
    Zcad::ErrorStatus setSnapStandard();

    double            snapAngle() const;
    Zcad::ErrorStatus setSnapAngle(double);

    ZcGePoint2d       snapBasePoint() const;
    Zcad::ErrorStatus setSnapBasePoint(const ZcGePoint2d&);

    ZcGeVector2d      snapIncrement() const;
    Zcad::ErrorStatus setSnapIncrement(const ZcGeVector2d&);

    ZSoft::UInt16     snapIsoPair() const;
    Zcad::ErrorStatus setSnapIsoPair(ZSoft::UInt16);

    bool              isGridOn() const;
    Zcad::ErrorStatus setGridOn();
    Zcad::ErrorStatus setGridOff();

    bool              isGridBoundToLimits() const;
    Zcad::ErrorStatus setGridBoundToLimits(bool bNewVal);

    bool              isGridAdaptive() const;
    Zcad::ErrorStatus setGridAdaptive(bool bNewVal);

    bool              isGridSubdivisionRestricted() const;
    Zcad::ErrorStatus setGridSubdivisionRestricted(bool bNewVal);

    bool              isGridFollow() const;
    Zcad::ErrorStatus setGridFollow(bool bNewVal);

    ZSoft::UInt16     gridMajor() const;
    Zcad::ErrorStatus setGridMajor(ZSoft::UInt16);

    ZcGeVector2d      gridIncrement() const;
    Zcad::ErrorStatus setGridIncrement(const ZcGeVector2d&);

    bool              hiddenLinesRemoved() const;
    Zcad::ErrorStatus showHiddenLines();
    Zcad::ErrorStatus removeHiddenLines();

    Zcad::ErrorStatus freezeLayersInViewport(const ZcDbObjectIdArray&);
    Zcad::ErrorStatus thawLayersInViewport(const ZcDbObjectIdArray&);
    Zcad::ErrorStatus thawAllLayersInViewport();
    bool              isLayerFrozenInViewport(const ZcDbObjectId& layerId) const;
    Zcad::ErrorStatus getFrozenLayerList(ZcDbObjectIdArray& ids) const;

    Zcad::ErrorStatus updateDisplay() const;

    ZcDbObjectId       background() const;
    Zcad::ErrorStatus  setBackground(ZcDbObjectId backgroundId);
    ZcDbObjectId       previousBackground(ZcGiDrawable::DrawableType type
                                          = ZcGiDrawable::kGeometry) const;
    Zcad::ErrorStatus  setPreviousBackground(ZcDbObjectId backgroundId,
                                             ZcGiDrawable::DrawableType type
                                             = ZcGiDrawable::kGeometry);
    ZcDbObjectId      visualStyle() const;
    Zcad::ErrorStatus setVisualStyle(const ZcDbObjectId oidVisualStyle);
    bool                isDefaultLightingOn() const;
    Zcad::ErrorStatus   setDefaultLightingOn(bool on);
    ZcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Zcad::ErrorStatus   setDefaultLightingType(ZcGiViewportTraits::DefaultLightingType typ);
    double              brightness() const;
    Zcad::ErrorStatus   setBrightness(double);

    double              contrast() const;
    Zcad::ErrorStatus   setContrast(double);

    ZcCmColor           ambientLightColor() const;
    Zcad::ErrorStatus   setAmbientLightColor(const ZcCmColor& clr);
    ZcDbObjectId        sunId() const;
    Zcad::ErrorStatus   setSun(ZcDbObjectId& retId, ZcDbObject* pSun);
    virtual ZSoft::UInt32     setAttributes(ZcGiDrawableTraits*);
    virtual ZSoft::Boolean    worldDraw   (ZcGiWorldDraw* pWd);

    bool              isLocked() const;
    Zcad::ErrorStatus setLocked();
    Zcad::ErrorStatus setUnlocked();

    Zcad::ErrorStatus setAnnotationScale(const ZcDbAnnotationScale *pScaleObj);
    ZcDbAnnotationScale* annotationScale() const;

    bool              isTransparent() const;
    Zcad::ErrorStatus setTransparent();
    Zcad::ErrorStatus setOpaque();

    enum StandardScaleType {
        kScaleToFit,                  
        kCustomScale,                 
        k1_1,                         
        k1_2,                         
        k1_4, 
		k1_5,
        k1_8,                         
        k1_10,                        
        k1_16,                        
        k1_20,                        
        k1_30,                        
        k1_40,                        
        k1_50,                        
        k1_100,                       
        k2_1,                         
        k4_1,                         
        k8_1,                         
        k10_1,                        
        k100_1,                       
        k1_128in_1ft,                 
        k1_64in_1ft,                  
        k1_32in_1ft,                  
        k1_16in_1ft,                  
        k3_32in_1ft,                  
        k1_8in_1ft,                   
        k3_16in_1ft,                  
        k1_4in_1ft,                   
        k3_8in_1ft,                   
        k1_2in_1ft,                   
        k3_4in_1ft,                   
        k1in_1ft,                     
        k1and1_2in_1ft,               
        k3in_1ft,                     
        k6in_1ft,                     
        k1ft_1ft                      
    };

    double            customScale() const;
    Zcad::ErrorStatus setCustomScale(double);

    StandardScaleType standardScale() const;
    Zcad::ErrorStatus setStandardScale(const StandardScaleType);

    Zcad::ErrorStatus plotStyleSheet(ZTCHAR *&) const;
    Zcad::ErrorStatus plotStyleSheet(const ZTCHAR *&) const;
    Zcad::ErrorStatus effectivePlotStyleSheet(const ZTCHAR *&);
    Zcad::ErrorStatus setPlotStyleSheet(const ZTCHAR *);

    bool              isNonRectClipOn() const;
    Zcad::ErrorStatus setNonRectClipOn();
    Zcad::ErrorStatus setNonRectClipOff();

    ZcDbObjectId      nonRectClipEntityId() const;
    Zcad::ErrorStatus setNonRectClipEntityId(ZcDbObjectId);

    virtual void      erased(const ZcDbObject* , ZSoft::Boolean);
    virtual void      modified(const ZcDbObject *);
    virtual void      copied(const ZcDbObject* pDbObj,const ZcDbObject* pNewObj);
    virtual void      subObjModified(const ZcDbObject* pDbObj,
                            const ZcDbObject* pSubObj);

    Zcad::ErrorStatus getUcs (ZcGePoint3d& origin,
                                ZcGeVector3d& xAxis,
                                ZcGeVector3d& yAxis ) const;
    bool              isUcsOrthographic(ZcDb::OrthographicView& view) const;
    ZcDbObjectId      ucsName           () const;
    double            elevation         () const;

    Zcad::ErrorStatus setUcs(const ZcGePoint3d& origin,
                                const ZcGeVector3d& xAxis,
                                const ZcGeVector3d& yAxis);
    Zcad::ErrorStatus setUcs(ZcDb::OrthographicView view);
    Zcad::ErrorStatus setUcs(const ZcDbObjectId& ucsId);
    Zcad::ErrorStatus setUcsToWorld();
    Zcad::ErrorStatus setElevation(double elev );

    bool           isViewOrthographic(ZcDb::OrthographicView& view ) const;
    Zcad::ErrorStatus setViewDirection(ZcDb::OrthographicView view );

    bool           isUcsSavedWithViewport () const;
    void           setUcsPerViewport ( bool ucsvp );

    void setRenderMode(ZcDbAbstractViewTableRecord::RenderMode mode);
    ZcDbAbstractViewTableRecord::RenderMode renderMode() const;

    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const;

    enum ShadePlotType {
        kAsDisplayed    = 0,
        kWireframe      = 1,
        kHidden         = 2,
        kRendered       = 3,
        kVisualStyle    = 4,
        kRenderPreset   = 5
    };

    ShadePlotType     shadePlot() const;
    Zcad::ErrorStatus setShadePlot(const ShadePlotType);

    ZcDbObjectId      shadePlotId() const;
    Zcad::ErrorStatus setShadePlot(const ShadePlotType type,
                                   const ZcDbObjectId shadePlotId);

    bool              plotWireframe() const;
    bool              plotAsRaster()  const;

    Zcad::ErrorStatus toneOperatorParameters(ZcGiToneOperatorParameters& params) const;
    Zcad::ErrorStatus setToneOperatorParameters(const ZcGiToneOperatorParameters& params);
};

#pragma pack(pop)

#endif
