#ifndef ZRX_AECMODELER_INC_DXFOUT_H
#define ZRX_AECMODELER_INC_DXFOUT_H

#include "callback.h"

#include "../inc/zdxfout.h"

#ifndef OutputToDxfFileCallback
#define OutputToDxfFileCallback    ZwOutputToDxfFileCallback
#endif //#ifndef OutputToDxfFileCallback


#ifndef OutputPolylineCallback
#define OutputPolylineCallback    ZwOutputPolylineCallback
#endif //#ifndef OutputPolylineCallback


#ifndef OutputTriangleCallback
#define OutputTriangleCallback    ZwOutputTriangleCallback
#endif //#ifndef OutputTriangleCallback


#ifndef Edge
#define Edge    ZwEdge
#endif //#ifndef Edge


#ifndef Point3d
#define Point3d    ZwPoint3d
#endif //#ifndef Point3d


#ifndef printTriangle
#define printTriangle    ZwPrintTriangle
#endif //#ifndef printTriangle



#endif

