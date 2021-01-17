#ifndef ZRX_AECMODELER_INC_GLOBAL_H
#define ZRX_AECMODELER_INC_GLOBAL_H

#include "../inc/zglobal.h"

#include <stdio.h>
#include <stdlib.h>
#include "errcodes.h"
#include "epsilon.h"
#include "float.h"
#include "flags.h"
#include "massert.h"



#ifndef Point2d
#define Point2d    ZwPoint2d
#endif //#ifndef Point2d


#ifndef Vector2d
#define Vector2d    ZwVector2d
#endif //#ifndef Vector2d


#ifndef Point3d
#define Point3d    ZwPoint3d
#endif //#ifndef Point3d


#ifndef Vector3d
#define Vector3d    ZwVector3d
#endif //#ifndef Vector3d


#ifndef IntPoint2d
#define IntPoint2d    ZwIntPoint2d
#endif //#ifndef IntPoint2d


#ifndef IntVector2d
#define IntVector2d    ZwIntVector2d
#endif //#ifndef IntVector2d


#ifndef IntPoint3d
#define IntPoint3d    ZwIntPoint3d
#endif //#ifndef IntPoint3d


#ifndef IntVector3d
#define IntVector3d    ZwIntVector3d
#endif //#ifndef IntVector3d


#ifndef Transf3d
#define Transf3d    ZwTransf3d
#endif //#ifndef Transf3d


#ifndef Line3d
#define Line3d    ZwLine3d
#endif //#ifndef Line3d


#ifndef Circle3d
#define Circle3d    ZwCircle3d
#endif //#ifndef Circle3d


#ifndef Plane
#define Plane    ZwPlane
#endif //#ifndef Plane


#ifndef Interval1d
#define Interval1d    ZwInterval1d
#endif //#ifndef Interval1d


#ifndef Interval2d
#define Interval2d    ZwInterval2d
#endif //#ifndef Interval2d


#ifndef Interval3d
#define Interval3d    ZwInterval3d
#endif //#ifndef Interval3d


#ifndef IntInterval1d
#define IntInterval1d    ZwIntInterval1d
#endif //#ifndef IntInterval1d


#ifndef IntInterval2d
#define IntInterval2d    ZwIntInterval2d
#endif //#ifndef IntInterval2d


#ifndef IntInterval3d
#define IntInterval3d    ZwIntInterval3d
#endif //#ifndef IntInterval3d


#ifndef Entity
#define Entity    ZwEntity
#endif //#ifndef Entity


#ifndef Body
#define Body    ZwBody
#endif //#ifndef Body


#ifndef Face
#define Face    ZwFace
#endif //#ifndef Face


#ifndef Edge
#define Edge    ZwEdge
#endif //#ifndef Edge


#ifndef Vertex
#define Vertex    ZwVertex
#endif //#ifndef Vertex


#ifndef Surface
#define Surface    ZwSurface
#endif //#ifndef Surface


#ifndef CylinderSurface
#define CylinderSurface    ZwCylinderSurface
#endif //#ifndef CylinderSurface


#ifndef ConeSurface
#define ConeSurface    ZwConeSurface
#endif //#ifndef ConeSurface


#ifndef SphereSurface
#define SphereSurface    ZwSphereSurface
#endif //#ifndef SphereSurface


#ifndef TorusSurface
#define TorusSurface    ZwTorusSurface
#endif //#ifndef TorusSurface


#ifndef Curve
#define Curve    ZwCurve
#endif //#ifndef Curve


#ifndef CircleCurve
#define CircleCurve    ZwCircleCurve
#endif //#ifndef CircleCurve


#ifndef PolygonVertexData
#define PolygonVertexData    ZwPolygonVertexData
#endif //#ifndef PolygonVertexData


#ifndef OutputPolylineCallback
#define OutputPolylineCallback    ZwOutputPolylineCallback
#endif //#ifndef OutputPolylineCallback


#ifndef OutputTriangleCallback
#define OutputTriangleCallback    ZwOutputTriangleCallback
#endif //#ifndef OutputTriangleCallback


#ifndef SaveRestoreCallback
#define SaveRestoreCallback    ZwSaveRestoreCallback
#endif //#ifndef SaveRestoreCallback


#ifndef TopologyChangeCallback
#define TopologyChangeCallback    ZwTopologyChangeCallback
#endif //#ifndef TopologyChangeCallback


#ifndef SaveToSatCallback
#define SaveToSatCallback    ZwSaveToSatCallback
#endif //#ifndef SaveToSatCallback


#ifndef TriangleCache
#define TriangleCache    ZwTriangleCache
#endif //#ifndef TriangleCache


#ifndef Darray
#define Darray    ZwDarray
#endif //#ifndef Darray


#ifndef MorphingMapElem
#define MorphingMapElem    ZwMorphingMapElem
#endif //#ifndef MorphingMapElem


#ifndef MorphingMap
#define MorphingMap    ZwMorphingMap
#endif //#ifndef MorphingMap


#ifndef VertexSurfaceData
#define VertexSurfaceData    ZwVertexSurfaceData
#endif //#ifndef VertexSurfaceData


#ifndef HideIntegerTransform
#define HideIntegerTransform    ZwHideIntegerTransform
#endif //#ifndef HideIntegerTransform


#ifndef setKeepInputBodiesWhenBooleanOperationsFail
#define setKeepInputBodiesWhenBooleanOperationsFail    ZwSetKeepInputBodiesWhenBooleanOperationsFail
#endif //#ifndef setKeepInputBodiesWhenBooleanOperationsFail


#ifndef keepInputBodiesWhenBooleanOperationsFail
#define keepInputBodiesWhenBooleanOperationsFail    ZwKeepInputBodiesWhenBooleanOperationsFail
#endif //#ifndef keepInputBodiesWhenBooleanOperationsFail



#endif
