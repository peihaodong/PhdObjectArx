#ifndef AECMODELER_INC_ENUMS_H
#define AECMODELER_INC_ENUMS_H

AECMODELER_NAMESPACE_BEGIN

enum ZwBoolOperType
{
    kBoolOperUnite,
    kBoolOperSubtract,
    kBoolOperIntersect
};

enum ZwBodyInterferenceType
{
    kBodiesDoNotInterfere,
    kBodiesTouch,
    kBodiesInterfere
};

enum ZwPointInBodyLocation
{
    kPointOutsideBody,
    kPointAtVertex,
    kPointOnEdge,
    kPointInFace,
    kPointInsideBody
};

enum ZwHiddenLinesDisplay
{
    kHiddenLinesInvisible,
    kHiddenLinesDashed,
    kHiddenLinesVisible
};

enum ZwHiddenLineDrawingImprove
{
    kNoDrawingImprove,
    kConnectDrawingImprove,
    kArcReconstructDrawingImprove
};

enum ZwTriangulationType
{
    kGenerateTriangles,
    kGenerateQuadrilaterals,
    kGenerateTriStrips,
    kGenerateTriStripsPerSurface
};

enum ZwRayBodyIntersection
{
    kRayDoesNotIntersect,
    kRayPointAtVertex,
    kRayPointOnEdge,
    kRayPointInFace,
    kRayIntersectsVertex,
    kRayIntersectsEdge,
    kRayIntersectsFace
};


AECMODELER_NAMESPACE_END
#endif

