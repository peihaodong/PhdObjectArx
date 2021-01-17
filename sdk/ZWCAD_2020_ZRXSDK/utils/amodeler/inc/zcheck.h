#ifndef AECMODELER_INC_CHECK_H
#define AECMODELER_INC_CHECK_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN

DllImpExp void ZwCheckProfile    (const ZwBody& profileBody);
DllImpExp void ZwCheckMorphingMap(const ZwMorphingMap& morphingMap, int numEdges0, int numEdges1);

DllImpExp void ZwCheckFaceAgainstAxis(ZwFace*, const ZwLine3d& axis);

DllImpExp bool ZwIsPolygonSelfIntersecting(const ZwPoint3d plg[], int numEdges, int i1, int i2);

DllImpExp ZwErrorCode ZwCheckPolygon(const ZwPoint3d   plg[], 
                                 int             numEdges,
                                 const ZwPlane&    plgPlane, 
                                 const ZwVector3d& plgNormal);


AECMODELER_NAMESPACE_END
#endif

