#ifndef AECMODELER_INC_GLOBAL_H
#define AECMODELER_INC_GLOBAL_H

#ifdef AECMODELER_EXPORTS
#define DllImpExp __declspec(dllexport)
#else
#define DllImpExp __declspec(dllimport)
#endif


#define AECMODELER_NAMESPACE         AECModeler
#define AECMODELER_NAMESPACE_BEGIN   namespace AECModeler {
#define AECMODELER_NAMESPACE_END     }


#include <stdio.h>
#include <stdlib.h>
#include "zerrcodes.h"
#include "zepsilon.h"
#include "float.h"
#include "zflags.h"
#include "zmassert.h" 


AECMODELER_NAMESPACE_BEGIN

const double kPi = 3.14159265358979323846;      
const double kTwoPi = 6.28318530717958647692;    
const double kHalfPi = 1.57079632679489661923;
// 
const double kMaxReal = FLT_MAX ;  // A very big number, but not too big
const double kMinReal = FLT_MIN;
// DllImpExp extern const double kDeg2Rad;  // Degrees --> radians coefficient
const double kEpsZero = FLT_MIN;  // Really a very small value

//const int kTooBigInt = 10000000;    // Too big number of anything is 10 million


class ZwPoint2d;
class ZwVector2d;
class ZwPoint3d;
class ZwVector3d;
class ZwIntPoint2d;
class ZwIntVector2d;
class ZwIntPoint3d;
class ZwIntVector3d;
class ZwTransf3d;
class ZwLine3d;
class ZwCircle3d;
class ZwPlane;
class ZwInterval1d;
class ZwInterval2d;
class ZwInterval3d;
class ZwIntInterval1d;
class ZwIntInterval2d;
class ZwIntInterval3d;
class ZwEntity;
class ZwBody;
class ZwFace;
class ZwEdge;
class ZwVertex;
class ZwSurface;
class ZwCylinderSurface;
class ZwConeSurface;
class ZwSphereSurface;
class ZwTorusSurface;
class ZwCurve;
class ZwCircleCurve;
class ZwPolygonVertexData;
class ZwOutputPolylineCallback;
class ZwOutputTriangleCallback;
class ZwSaveRestoreCallback;
class ZwTopologyChangeCallback;
class ZwSaveToSatCallback;
class ZwTriangleCache;
class ZwDarray;
class ZwMorphingMapElem;
class ZwMorphingMap;
class ZwVertexSurfaceData;
class ZwHideIntegerTransform;


DllImpExp void ZwSetKeepInputBodiesWhenBooleanOperationsFail(bool yesNo);
DllImpExp bool ZwKeepInputBodiesWhenBooleanOperationsFail();

AECMODELER_NAMESPACE_END
#endif
