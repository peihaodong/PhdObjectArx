#ifndef AECMODELER_INC_VERTDATA_H
#define AECMODELER_INC_VERTDATA_H

#include "zcircle3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwPolygonVertexData
{
public:

    enum Type { kArc3d, kArcByRadius, kArcByBulge, kFilletByRadius, kUnspecifiedCurve };

    ZwPolygonVertexData(Type);                                         // kUnspecifiedCurve
    ZwPolygonVertexData(Type, const ZwCircle3d&, int apprx);             // kArc3d
    ZwPolygonVertexData(Type, double rad, bool isCenLeft, int apprx);  // kArcByRadius
    ZwPolygonVertexData(Type, double bulgeOrRadius, int apprx);        // kArcByBulge or kFilletByRadius

    bool isArc() const 
    { 
        return type == kArc3d || type == kArcByRadius || type == kArcByBulge || type == kFilletByRadius; 
    }

public: // data

    Type     type;
    ZwCircle3d circle;
    int      approx;
    bool     isCenterLeft;
    double   bulge;
    ZwCurve*   curve;
    ZwSurface* surface;

}; // class PolygonVertexData



// Deletes the VertexData objects the vertexDataArray points to and sets the
// pointers to NULL. If alsoDeleteArray is true, it also deletes the array,
// otherwise it does not
//
DllImpExp void deleteVertexData(ZwPolygonVertexData* vertexDataArray[], int arrayLength, bool alsoDeleteArray);


AECMODELER_NAMESPACE_END
#endif
