
#ifndef __IDGRAPH_H__
#define __IDGRAPH_H__

#include "graph.h"
#include "dbidmap.h"

#include "../inc/zidgraph.h"

#ifndef AcDbGraph
#define AcDbGraph		ZcDbGraph
#endif //#ifndef AcDbGraph

#ifndef AcDbGraphNode
#define AcDbGraphNode		ZcDbGraphNode
#endif //#ifndef AcDbGraphNode

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdGraph
#define AcDbObjectIdGraph		ZcDbObjectIdGraph
#endif //#ifndef AcDbObjectIdGraph

#ifndef AcDbObjectIdGraphNode
#define AcDbObjectIdGraphNode		ZcDbObjectIdGraphNode
#endif //#ifndef AcDbObjectIdGraphNode

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#endif //#ifndef __IDGRAPH_H__
