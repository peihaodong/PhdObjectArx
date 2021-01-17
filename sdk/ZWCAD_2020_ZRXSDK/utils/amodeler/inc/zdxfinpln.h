#ifndef AECMODELER_INC_DXFINPLN_H
#define AECMODELER_INC_DXFINPLN_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


DllImpExp void ZwDxfPolylineToAugmentedPolygon(FILE*                pInputDxfFile,
                                             int                  approx,
                                             ZwPoint3d*&            plg,
                                             ZwPolygonVertexData**& vertexData,
                                             int&                 numVertices,
                                             ZwVector3d&            plgNormal);

AECMODELER_NAMESPACE_END
#endif

