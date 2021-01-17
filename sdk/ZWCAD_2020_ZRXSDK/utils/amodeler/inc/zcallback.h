#ifndef AECMODELER_INC_CALLBACK_H
#define AECMODELER_INC_CALLBACK_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwOutputPolylineCallback
{
public:

    virtual ~ZwOutputPolylineCallback() {}

    virtual void outputPolyline(ZwEdge*          edgeArray [],
                                const ZwPoint3d  pointArray[],
                                const double   bulgeArray[],
                                int            numPoints,
                                bool           isClosed,
                                bool           isVisible) = NULL;

    virtual void outputArc     (ZwEdge*          edge,
                                const ZwPoint3d& center,
                                double         radius,
                                double         startAngle,
                                double         endAngle,
                                bool           isVisible) = NULL;

}; // class OutputPolylineCallback



class DllImpExp ZwOutputTriangleCallback
{
public:

    virtual ~ZwOutputTriangleCallback() {}

    virtual void outputTriangle(ZwEdge* edgeArray[], int arrayLength) = NULL;

    enum { kMaxTriStripLength = 200 };

    virtual void outputTriStrip(ZwEdge* edgeArray[], 
                                int   arrayLength,
                                bool  firstTriangleIsCcw) = NULL;

}; // class OutputTriangleCallback



class DllImpExp ZwSaveRestoreCallback
{
public:

    virtual ~ZwSaveRestoreCallback() {}

    virtual void saveBytes   (const void* buffer, int requiredLength) = NULL;
    virtual void restoreBytes(void*       buffer, int requiredLength) = NULL;

}; // class SaveRestoreCallback


class DllImpExp ZwTopologyChangeCallback
{
public:

    virtual ~ZwTopologyChangeCallback() {}
};

AECMODELER_NAMESPACE_END
#endif

