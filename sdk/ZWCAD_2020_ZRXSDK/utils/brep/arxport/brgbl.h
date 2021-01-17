#ifndef ZRX_SDK_BRGBL_H
#define ZRX_SDK_BRGBL_H 1

#include "adesk.h"
#include "acadstrc.h"

#include "../inc/zcbrgbl.h"

#ifndef AcBrBrepData
#define AcBrBrepData    ZcBrBrepData
#endif //#ifndef AcBrBrepData

#ifndef AcGeCurve2d
#define AcGeCurve2d    ZcGeCurve2d
#endif //#ifndef AcGeCurve2d

#ifndef AcBrTraverser
#define AcBrTraverser    ZcBrTraverser
#endif //#ifndef AcBrTraverser

#ifndef AcBrFace
#define AcBrFace    ZcBrFace
#endif //#ifndef AcBrFace

#ifndef AcGeNurbSurface
#define AcGeNurbSurface    ZcGeNurbSurface
#endif //#ifndef AcGeNurbSurface

#ifndef AcBrMesh2dControl
#define AcBrMesh2dControl    ZcBrMesh2dControl
#endif //#ifndef AcBrMesh2dControl

#ifndef AcGeExternalBoundedSurface
#define AcGeExternalBoundedSurface    ZcGeExternalBoundedSurface
#endif //#ifndef AcGeExternalBoundedSurface

#ifndef AcBrLoop
#define AcBrLoop    ZcBrLoop
#endif //#ifndef AcBrLoop

#ifndef AcBrBrep
#define AcBrBrep    ZcBrBrep
#endif //#ifndef AcBrBrep

#ifndef AcGePoint2d
#define AcGePoint2d    ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcBrMassProps
#define AcBrMassProps    ZcBrMassProps
#endif //#ifndef AcBrMassProps

#ifndef AcGe
#define AcGe    ZcGe
#endif //#ifndef AcGe

#ifndef AcBrImpEntity
#define AcBrImpEntity    ZcBrImpEntity
#endif //#ifndef AcBrImpEntity

#ifndef AcBrElement2dData
#define AcBrElement2dData    ZcBrElement2dData
#endif //#ifndef AcBrElement2dData

#ifndef AcBrMesh2d
#define AcBrMesh2d    ZcBrMesh2d
#endif //#ifndef AcBrMesh2d

#ifndef AcDbEntity
#define AcDbEntity    ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcBrLoopVertexTraverser
#define AcBrLoopVertexTraverser    ZcBrLoopVertexTraverser
#endif //#ifndef AcBrLoopVertexTraverser

#ifndef AcBrMesh2dElement2dTraverser
#define AcBrMesh2dElement2dTraverser    ZcBrMesh2dElement2dTraverser
#endif //#ifndef AcBrMesh2dElement2dTraverser

#ifndef AcGePoint3d
#define AcGePoint3d    ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcBrVertex
#define AcBrVertex    ZcBrVertex
#endif //#ifndef AcBrVertex

#ifndef AcBrFaceLoopTraverser
#define AcBrFaceLoopTraverser    ZcBrFaceLoopTraverser
#endif //#ifndef AcBrFaceLoopTraverser

#ifndef AcBrShellFaceTraverser
#define AcBrShellFaceTraverser    ZcBrShellFaceTraverser
#endif //#ifndef AcBrShellFaceTraverser

#ifndef AcGeVector3d
#define AcGeVector3d    ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGeBoundBlock3d
#define AcGeBoundBlock3d    ZcGeBoundBlock3d
#endif //#ifndef AcGeBoundBlock3d

#ifndef AcBrComplex
#define AcBrComplex    ZcBrComplex
#endif //#ifndef AcBrComplex

#ifndef AcBrNodeData
#define AcBrNodeData    ZcBrNodeData
#endif //#ifndef AcBrNodeData

#ifndef AcGeSurface
#define AcGeSurface    ZcGeSurface
#endif //#ifndef AcGeSurface

#ifndef AcBrMeshControl
#define AcBrMeshControl    ZcBrMeshControl
#endif //#ifndef AcBrMeshControl

#ifndef AcBrBrepShellTraverser
#define AcBrBrepShellTraverser    ZcBrBrepShellTraverser
#endif //#ifndef AcBrBrepShellTraverser

#ifndef AcBrElement
#define AcBrElement    ZcBrElement
#endif //#ifndef AcBrElement

#ifndef AcBrImpHit
#define AcBrImpHit    ZcBrImpHit
#endif //#ifndef AcBrImpHit

#ifndef AcGeNurbCurve2d
#define AcGeNurbCurve2d    ZcGeNurbCurve2d
#endif //#ifndef AcGeNurbCurve2d

#ifndef AcGeLinearEnt3d
#define AcGeLinearEnt3d    ZcGeLinearEnt3d
#endif //#ifndef AcGeLinearEnt3d

#ifndef AcRxObject
#define AcRxObject    ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcBrImpMeshControl
#define AcBrImpMeshControl    ZcBrImpMeshControl
#endif //#ifndef AcBrImpMeshControl

#ifndef AcBrNode
#define AcBrNode    ZcBrNode
#endif //#ifndef AcBrNode

#ifndef AcGeNurbCurve3d
#define AcGeNurbCurve3d    ZcGeNurbCurve3d
#endif //#ifndef AcGeNurbCurve3d

#ifndef AcBrEntity
#define AcBrEntity    ZcBrEntity
#endif //#ifndef AcBrEntity

#ifndef AcBrVertexLoopTraverser
#define AcBrVertexLoopTraverser    ZcBrVertexLoopTraverser
#endif //#ifndef AcBrVertexLoopTraverser

#ifndef AcBrEdgeLoopTraverser
#define AcBrEdgeLoopTraverser    ZcBrEdgeLoopTraverser
#endif //#ifndef AcBrEdgeLoopTraverser

#ifndef AcBrShell
#define AcBrShell    ZcBrShell
#endif //#ifndef AcBrShell

#ifndef AcBrImpMeshEntity
#define AcBrImpMeshEntity    ZcBrImpMeshEntity
#endif //#ifndef AcBrImpMeshEntity

#ifndef AcBrLoopEdgeTraverser
#define AcBrLoopEdgeTraverser    ZcBrLoopEdgeTraverser
#endif //#ifndef AcBrLoopEdgeTraverser

#ifndef AcBrMesh2dFilter
#define AcBrMesh2dFilter    ZcBrMesh2dFilter
#endif //#ifndef AcBrMesh2dFilter

#ifndef AcBr
#define AcBr    ZcBr
#endif //#ifndef AcBr

#ifndef AcBrMesh
#define AcBrMesh    ZcBrMesh
#endif //#ifndef AcBrMesh

#ifndef AcDbSurface
#define AcDbSurface    ZcDbSurface
#endif //#ifndef AcDbSurface

#ifndef AcBrVertexEdgeTraverser
#define AcBrVertexEdgeTraverser    ZcBrVertexEdgeTraverser
#endif //#ifndef AcBrVertexEdgeTraverser

#ifndef AcBrComplexShellTraverser
#define AcBrComplexShellTraverser    ZcBrComplexShellTraverser
#endif //#ifndef AcBrComplexShellTraverser

#ifndef AcBrMeshEntity
#define AcBrMeshEntity    ZcBrMeshEntity
#endif //#ifndef AcBrMeshEntity

#ifndef AcGeCurve3d
#define AcGeCurve3d    ZcGeCurve3d
#endif //#ifndef AcGeCurve3d

#ifndef AcBrBrepVertexTraverser
#define AcBrBrepVertexTraverser    ZcBrBrepVertexTraverser
#endif //#ifndef AcBrBrepVertexTraverser

#ifndef AcBrHitData
#define AcBrHitData    ZcBrHitData
#endif //#ifndef AcBrHitData

#ifndef AcDbFullSubentPath
#define AcDbFullSubentPath    ZcDbFullSubentPath
#endif //#ifndef AcDbFullSubentPath

#ifndef AcBrHitPath
#define AcBrHitPath    ZcBrHitPath
#endif //#ifndef AcBrHitPath

#ifndef Adesk
#define Adesk    ZSoft
#endif //#ifndef Adesk

#ifndef AcBrMesh2dData
#define AcBrMesh2dData    ZcBrMesh2dData
#endif //#ifndef AcBrMesh2dData

#ifndef AcBrHit
#define AcBrHit    ZcBrHit
#endif //#ifndef AcBrHit

#ifndef AcBrBrepFaceTraverser
#define AcBrBrepFaceTraverser    ZcBrBrepFaceTraverser
#endif //#ifndef AcBrBrepFaceTraverser

#ifndef AcBrTraverserData
#define AcBrTraverserData    ZcBrTraverserData
#endif //#ifndef AcBrTraverserData

#ifndef AcBrImpTraverser
#define AcBrImpTraverser    ZcBrImpTraverser
#endif //#ifndef AcBrImpTraverser

#ifndef AcBrEdge
#define AcBrEdge    ZcBrEdge
#endif //#ifndef AcBrEdge

#ifndef AcBrElement2dNodeTraverser
#define AcBrElement2dNodeTraverser    ZcBrElement2dNodeTraverser
#endif //#ifndef AcBrElement2dNodeTraverser

#ifndef AcDb3dSolid
#define AcDb3dSolid    ZcDb3dSolid
#endif //#ifndef AcDb3dSolid

#ifndef AcBrElement2d
#define AcBrElement2d    ZcBrElement2d
#endif //#ifndef AcBrElement2d

#ifndef AcBrBrepEdgeTraverser
#define AcBrBrepEdgeTraverser    ZcBrBrepEdgeTraverser
#endif //#ifndef AcBrBrepEdgeTraverser

#ifndef AcBrBrepComplexTraverser
#define AcBrBrepComplexTraverser    ZcBrBrepComplexTraverser
#endif //#ifndef AcBrBrepComplexTraverser

#endif

