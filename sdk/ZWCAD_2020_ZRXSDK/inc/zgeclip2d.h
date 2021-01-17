

#ifndef ZC_GECLIP2D_H
#define ZC_GECLIP2D_H

#include "zadesk.h"
#include "assert.h"
#include "zgeent2d.h"
#include "zgepnt2d.h"
#include "zgept2dar.h"
#include "zgegbl.h"
#include "zgeintarr.h"
#pragma pack (push, 8)

class ZcGeImpClipBoundary2d;

class
GE_DLLEXPIMPORT
ZcGeClipBoundary2d : public ZcGeEntity2d
{
public:

    ZcGeClipBoundary2d();

    ZcGeClipBoundary2d(const ZcGePoint2d& cornerA, const ZcGePoint2d& cornerB);

    ZcGeClipBoundary2d(const ZcGePoint2dArray& clipBoundary);

	ZcGeClipBoundary2d (const ZcGeClipBoundary2d& src);

	ZcGe::ClipError		set(const ZcGePoint2d& cornerA, const ZcGePoint2d& cornerB);

    ZcGe::ClipError		set(const ZcGePoint2dArray& clipBoundary);

    ZcGe::ClipError		clipPolygon(const ZcGePoint2dArray& rawVertices, 
                                    ZcGePoint2dArray& clippedVertices,
                                    ZcGe::ClipCondition& clipCondition,
                                    ZcGeIntArray* pClippedSegmentSourceLabel = 0) const;

    ZcGe::ClipError		clipPolyline(const ZcGePoint2dArray& rawVertices, 
                                     ZcGePoint2dArray& clippedVertices,
                                     ZcGe::ClipCondition& clipCondition,
                                     ZcGeIntArray* pClippedSegmentSourceLabel = 0) const;

    ZcGeClipBoundary2d& operator = (const ZcGeClipBoundary2d& crvInt);
};

#pragma pack (pop)
#endif
