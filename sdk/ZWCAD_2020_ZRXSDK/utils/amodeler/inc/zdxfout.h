#ifndef AECMODELER_INC_DXFOUT_H
#define AECMODELER_INC_DXFOUT_H
#include "zcallback.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwOutputToDxfFileCallback : public ZwOutputPolylineCallback, 
                                          public ZwOutputTriangleCallback
{
public:

    // The constructor opens the DXF file and writes the SECTION ENTITIES header
    //
    ZwOutputToDxfFileCallback(const wchar_t* dxfFileName);

    // The destructor writes the ENDSEC and EOF groups and closes the file
    //
    ~ZwOutputToDxfFileCallback();

    virtual void outputPolyline(ZwEdge*             edgeArray [],
                                const ZwPoint3d     pointArray[], 
                                const double      bulgeArray[],
                                int               numPoints, 
                                bool              isClosed, 
                                bool              isVisible); 

    virtual void outputArc     (ZwEdge*          edge,
                                const ZwPoint3d& center,
                                double         radius,
                                double         startAngle,
                                double         endAngle,
                                bool           isVisible);

    virtual void outputTriangle(ZwEdge* edgeArray[], int arrayLength);

    virtual void outputTriStrip(ZwEdge* edgeArray[], int arrayLength, 
                                bool firstTriangleIsCcw);

private:

    FILE* mpFile;

    // Write group code and group value
    //
    void g(int code, const char*    value) const;
    void g(int code, int            value) const;
    void g(int code, double         value) const;
    void g(int code, const ZwPoint2d& value) const;
    void g(int code, const ZwPoint3d& value) const;

}; // class ZwOutputToDxfFileCallback



// Print the triangle to stdout
//
DllImpExp extern void ZwPrintTriangle(ZwEdge* edgeArray[], int numSides); 


AECMODELER_NAMESPACE_END
#endif

