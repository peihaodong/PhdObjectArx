

#ifndef ZD_IDGRAPH_H
#define ZD_IDGRAPH_H 1

#include "zgraph.h"
#include "zdbidmap.h"

#pragma pack (push, 8)

class ZcDbObjectIdGraphNode : public ZcDbGraphNode
{
public:
    ZcDbObjectIdGraphNode(const ZcDbObjectId id);
    virtual ~ZcDbObjectIdGraphNode();

    ZcDbObjectId           id           () const;

private:

    ZcDbObjectId        mId;
};

class ZcDbObjectIdGraph : public ZcDbGraph
{
public:
    ZcDbObjectIdGraph();
    virtual ~ZcDbObjectIdGraph();

    Zcad::ErrorStatus       addNode     (ZcDbObjectIdGraphNode *);
    Zcad::ErrorStatus       delNode     (ZcDbObjectIdGraphNode *);
    ZcDbObjectIdGraphNode*  findNode    (const ZcDbObjectId) const;
    ZcDbObjectIdGraphNode*  idNode      (int idx) const;

private:
    ZcDbIdMapping       mIdNodeMap;
};

inline ZcDbObjectId ZcDbObjectIdGraphNode::id() const
    {return mId; }

inline ZcDbObjectIdGraphNode* ZcDbObjectIdGraph::idNode(int idx) const
    { return (ZcDbObjectIdGraphNode*)node(idx); }

#pragma pack (pop)

#endif

