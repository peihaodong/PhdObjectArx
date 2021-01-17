#ifndef AECMODELER_INC_BODY_H
#define AECMODELER_INC_BODY_H

#pragma warning(push)
#pragma warning(disable : 4702) // unreachable code
#include <vector>
#pragma warning(pop)
#include "zentity.h"
#include "ztransf3d.h"
#include "zcolor.h"
#include "zmorphmap.h"
#include "zenums.h"
#include "zglobal.h"
#include "zinterval.h"

AECMODELER_NAMESPACE_BEGIN

const Flag IPBF   = ZWFLAG(0);  // Interval Present            Body Flag  
const Flag NEGBF  = ZWFLAG(1);  // Negative                    Body Flag
const Flag DASHBF = ZWFLAG(2);  // Display DASHed        lines Body Flag
const Flag WFBF   = ZWFLAG(3);  // Display Wireframe           Body Flag
const Flag DAEBF  = ZWFLAG(4);  // Display Approximating Edges Body Flag
const Flag DBEBF  = ZWFLAG(5);  // Display Bridge        Edges Body Flag


class DllImpExp ZwBody : public ZwEntity
{
public:
    ZwBody();
    ZwBody(const ZwBody&);
    ~ZwBody();
    ZwBody& operator =(const ZwBody &);
    ZwBody copy() const;
    void init(bool  deleteContents);
    bool isValid(int validityCheckingLevel = -1) const;
    ZwBody boolOper(ZwBody&, ZwBoolOperType eType, bool  hideZeroSlopeEdges = true, ZwTopologyChangeCallback* pCallBack = NULL, bool  keepInputBodiesWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());
	
	void section(const ZwPlane&, bool keepInputBodyWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());
	void section(const ZwPlane&, const ZwPoint3d& point, bool keepInputBodyWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());
	bool slice(const ZwPlane&, std::vector<ZwPoint3d>& outputVertices, std::vector<int>& outputLoops) const;

	bool planeIntersectsBody(const ZwPlane&) const;

    ZwBody operator + (const ZwBody& );
    ZwBody  operator - (const ZwBody& );
    ZwBody  operator * (const ZwBody& );
	ZwBody  operator - (const ZwPlane&);
    ZwBody& operator +=(const ZwBody& );
    ZwBody& operator -=(const ZwBody& );
    ZwBody& operator *=(const ZwBody& ); 
	ZwBody& operator -=(const ZwPlane&);

    ZwBody operator -();

    ZwBodyInterferenceType interfere(const ZwBody& body) const;
	ZwPointInBodyLocation  contains(const ZwPoint3d&) const; 
	ZwPointInBodyLocation  contains(const ZwPoint3d&, ZwEntity*& coincidentEntity) const;

	ZwBody& translate(const ZwVector3d&);

	ZwBody& rotate   (const ZwLine3d& axis, double angle);

	ZwBody& scale    (const ZwPoint3d& fixedPt, double factor);

	ZwBody& scale    (const ZwPoint3d& fixedPt, const ZwVector3d& xyzFactors);

	ZwBody& stretch  (const ZwLine3d& axis);

	ZwBody& mirror   (const ZwPlane&);

	ZwBody& align    (const ZwPoint3d& src1, 
		const ZwPoint3d& src2,
		const ZwPoint3d& src3,
		const ZwPoint3d& dst1,
		const ZwPoint3d& dst2,
		const ZwPoint3d& dst3);

	ZwBody& align    (const ZwPoint3d&  src1, 
		const ZwVector3d& src2,
		const ZwVector3d& src3,
		const ZwPoint3d&  dst1,
		const ZwVector3d& dst2,
		const ZwVector3d& dst3);

	ZwBody& align    (const ZwPoint3d&  src1, 
		const ZwVector3d& src2,
		const ZwPoint3d&  dst1,
		const ZwVector3d& dst2);

	ZwBody& transform(const ZwTransf3d&);

	double volume() const;

    static ZwBody box (const ZwPoint3d& corner, const ZwVector3d& sizes);
    static ZwBody sphere (const ZwPoint3d& center, double radius, int approx);
    static ZwBody cylinder(const ZwLine3d&axis, double radius, int approx);
    static ZwBody cylinder(const ZwLine3d&axis, const ZwVector3d& baseNormal,double radius, int approx);
    static ZwBody cone(const ZwLine3d&axis, double radius1, double radius2, int approx);
    static ZwBody cone(const ZwLine3d&axis, const ZwVector3d& baseNormal, double radius1, double radius2, int approx);
    static ZwBody torus(const ZwLine3d&axis, double majorRadius, double minorRadius, int majorApprox, int minorApprox);
    static ZwBody pipe(const ZwLine3d&axis, double outerRadius, double innerRadius, int approx);
    static ZwBody pipe(const ZwLine3d&axis, const ZwVector3d& baseNormal, double outerRadius, double innerRadius, int approx);
    static ZwBody pipeConic(const ZwLine3d&axis, double outerRadius1, double innerRadius1, double outerRadius2, double innerRadius2, int approx);
    static ZwBody pipeConic(const ZwLine3d&axis, const ZwVector3d& baseNormal, double outerRadius1, double innerRadius1, double outerRadius2, double innerRadius2, int approx);
    static ZwBody tetrahedron (const ZwPoint3d& p1, const ZwPoint3d& p2, const ZwPoint3d& p3, const ZwPoint3d& p4);
    static ZwBody reducingElbow(const ZwPoint3d& elbowCenter, const ZwPoint3d& endCenter1, const ZwPoint3d& endCenter2, double endRadius1, double endRadius2, int majorApprox, int minorApprox);
    static ZwBody rectangleToCircleReducer(const ZwPoint3d& baseCorner, const ZwVector2d& baseSizes,const ZwCircle3d& topCircle,int approx);
    static ZwBody convexHull(const ZwPoint3d pts[], int numPoints);
    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector,const ZwPoint3d& scaleTwistFixedPt,double scaleFactor,double twistAngle = 0.0);
    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector);
    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector,const std::vector<void*>*attribs);
    static ZwBody pyramid(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d&plgNormal,const ZwPoint3d& pyramidApex);
    static ZwBody axisRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, const ZwLine3d& axis, double revolutionAngle, int approx, const ZwPoint3d& scaleTwistFixedPt, double scaleFactor, double twistAngle = 0.0);
    static ZwBody axisRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, const ZwLine3d& axis, double revolutionAngle, int approx);
    static ZwBody endpointRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, double revolutionAngle, int approx);
    
    static ZwBody extrusionAlongPath(const ZwBody& startProfile,const ZwBody& endProfile,const ZwPoint3d pathPlg[], ZwPolygonVertexData* pathVertexData[],int pathNumVertices,bool pathIsClosed,bool checkBodyValidity = true, const ZwPoint3d& scaleTwistFixedPt = ZwPoint3d::kNull, double scaleFactor= 1.0, double twistAngle= 0.0,const ZwMorphingMap& morphingMap= ZwMorphingMap::kNull,bool calcluateMorphingMapAutomatically = false,std::vector<int>startProfileSignificantVertices= std::vector<int>(), std::vector<int>endProfileSignificantVertices = std::vector<int>());
    static ZwBody skin (ZwBody* profiles[], int numProfiles, bool isClosed,bool checkPlanarity,ZwMorphingMap** morphingMaps = NULL,bool markInnerProfileEdgesAsApprox = false,bool ckeckInputProfiles= true);
    void hideDisplay(const ZwTransf3d&projectionTransf,ZwOutputPolylineCallback*,bool  = true, ZwHiddenLineDrawingImprove = kNoDrawingImprove, ZwHideIntegerTransform* = NULL);
    void setHiddenLineParams(ZwHiddenLinesDisplay hiddenLinesDisplay = kHiddenLinesInvisible, bool displayApproxEdges = false, bool displayBridgeEdges = false);
    void triangulate(ZwOutputTriangleCallback* pCallBack, ZwTriangulationType type = kGenerateTriangles,bool  cacheTriangles= true) const;
    void save(ZwSaveRestoreCallback* pCallBack) const;
    void save(FILE*)const;
    void save(const wchar_t* fileName) const;
    static ZwBody restore(ZwSaveRestoreCallback* pCallBack);
    static ZwBody restore(FILE*);
    static ZwBody restore(const wchar_t* fileName);
    bool  isNull() const;
    ZwVertex* vertexList() const;

    // Save to ACIS SAT text file. If colorsAlso is true, every face and edge 
    // receives a color-adesk-attrib
    //
    //void        saveToSat(SaveToSatCallback*,   bool colorsAlso = false) const;
    void        saveToSat(FILE*,                bool colorsAlso = false) const;
    void        saveToSat(const wchar_t* fileName, bool colorsAlso = false) const;

    void     setFaceList      (ZwFace*    f) { mpFaceList    = f;    }
//     void     setSurfaceList   (Surface* s) { mpSurfaceList = s;    }
//     void     setCurveList     (Curve*   c) { mpCurveList   = c;    }
    void     setVertexList    (ZwVertex*  v) { mpVertexList  = v;    }

    ZwFace*    faceList         () const     { return mpFaceList;    }
//     Surface* surfaceList      () const     { return mpSurfaceList; }
//     Curve*   curveList        () const     { return mpCurveList;   }

    void     addFace          (ZwFace*   );
    void     addSurface       (ZwSurface*);
    void     addCurve         (ZwCurve*  );
    void     addVertex        (ZwVertex* );

	void setColor(ZwColor color); 
	ZwBody*    next   () const;
	void     setNext(ZwBody* nxt);

    int      vertexCount  () const;
    int      edgeCount    () const;  
    int      faceCount    () const;
    int      surfaceCount () const;
    int      curveCount   () const;
    int      triangleCount() const;

    void triangulateAllFaces();

	void mergeCoplanarEntities(bool bridgeEdgesOnly    = true,
		bool sameColorOnly      = true,
		ZwTopologyChangeCallback* = NULL);

	const ZwInterval3d& interval(double enlargeBy = 10*ZwEpsAbs()) const;  // Obtain body interval (bounding box) 

private:
    
    ZwFace*      mpFaceList;     // Linear list of all faces
    //Surface*   mpSurfaceList;  // Linear list of all surfaces
    //Curve*     mpCurveList;    // Linear list of all curves
    ZwVertex*    mpVertexList;   // Linear list of all vertices
    ZwBody*      mpNext;         // Next body, currently used only by hideDisplay()

    ZwInterval3d mInterval;      // Enclosing interval of the body

    ZwTriangleCache* mpTriangleCache; 

};  // class Body

AECMODELER_NAMESPACE_END
#endif

