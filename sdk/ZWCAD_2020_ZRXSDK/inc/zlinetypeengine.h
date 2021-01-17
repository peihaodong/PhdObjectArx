
#pragma once

#include "zacgi.h"

#pragma pack (push, 8)

class ZcGiImpLinetypeEngine;

class ZcGiLinetypeEngine : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiLinetypeEngine);

    ZcGiLinetypeEngine();
    virtual ~ZcGiLinetypeEngine();
    virtual Zcad::ErrorStatus tessellate (bool                 bIsArc,
                                          bool                 bIsCircle,
                                          const ZSoft::UInt32  nPoints,
                                          const ZcGePoint3d  * pVertexList,
                                          ZcGiWorldDraw *      pWorldDraw,
                                          const ZcDbObjectId   linetypeId,
                                          double               linetypeScale,
										  const ZcGeVector3d * pNormal,
										  bool plineGen = false);
    virtual Zcad::ErrorStatus tessellate (bool                 bIsArc,
                                          bool                 bIsCircle,
                                          const ZSoft::UInt32  nPoints,
                                          const ZcGePoint3d  * pVertexList,
                                          ZcGiViewportDraw *   pViewportDraw,
                                          const ZcDbObjectId   linetypeId,
                                          double               linetypeScale,
                                          const ZcGeVector3d * pNormal,
										  bool plineGen = false);

    virtual Zcad::ErrorStatus tessellate (const ZcGeCircArc3d& arcSeg,
                                          const ZcGeMatrix3d&  ecsMat,
                                          double               startWidth,
                                          double               endWidth,
                                          ZcGiCommonDraw *     pDraw,
                                          const ZcDbObjectId   linetypeId,
                                          double               linetypeScale,
                                          double               thick);

    virtual Zcad::ErrorStatus tessellate (const ZcGeLineSeg3d& lineSeg,
                                          const ZcGeMatrix3d&  ecsMat,
                                          double               startWidth,
                                          double               endWidth,
                                          ZcGiCommonDraw *     pDraw,
                                          const ZcDbObjectId   linetypeId,
                                          double               linetypeScale);

private:
    ZcGiImpLinetypeEngine * mpAcGiImpLinetypeEngine;
};

#pragma pack (pop)
