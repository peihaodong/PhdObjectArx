

#ifndef ZD_XGRAPH_H
#define ZD_XGRAPH_H 1

#include "zgraph.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcDbXrefGraphNode : public ZcDbGraphNode
{
public:
    ZcDbXrefGraphNode(const ZTCHAR * pName = NULL,
        const ZcDbObjectId& btrId = ZcDbObjectId::kNull,
        ZcDbDatabase* pDb = NULL,
        ZcDb::XrefStatus status = ZcDb::kXrfResolved);
    virtual ~ZcDbXrefGraphNode();

    const ZTCHAR * name() const;
    ZcDbObjectId btrId() const;
    ZcDbDatabase* database() const;

    Zcad::ErrorStatus setName(const ZTCHAR * pName);
    void setBtrId(const ZcDbObjectId& id);
    void setDatabase(ZcDbDatabase* pDb);

    bool isNested() const;

    ZcDb::XrefStatus xrefStatus() const;
    void setXrefStatus(ZcDb::XrefStatus stat);

    ZcDb::XrefNotificationStatus xrefNotificationStatus() const;
    void setXrefNotificationStatus(ZcDb::XrefNotificationStatus stat);

    void*   xData() { return mpxdata; }
    void    setxData(void *pXData) { mpxdata = pXData; }

    Zcad::ErrorStatus xrefReadSubstatus() const;

private:
    void* mpxdata; 
    ZTCHAR * mpName;
    ZcDbObjectId mBtrId;
    
    ZcDb::XrefStatus mStatus;
    ZcDb::XrefNotificationStatus mNotifyStatus;
};

class ZcDbXrefGraph : public ZcDbGraph
{
public:
    ZcDbXrefGraph(ZcDbXrefGraphNode* pHostDwg = NULL);
    virtual ~ZcDbXrefGraph();

    ZcDbXrefGraphNode* xrefNode(const ZTCHAR * pName) const;
    ZcDbXrefGraphNode* xrefNode(ZcDbObjectId btrId) const;
    ZcDbXrefGraphNode* xrefNode(const ZcDbDatabase* pDb) const;

    ZcDbXrefGraphNode* xrefNode(int idx) const;
    ZcDbXrefGraphNode*  hostDwg() const;

    ZSoft::Boolean markUnresolvedTrees ();

    virtual ZSoft::Boolean findCycles(ZcDbGraphNode* pStart = NULL);
};

Zcad::ErrorStatus zcedGetCurDwgXrefGraph(ZcDbXrefGraph&,
    ZSoft::Boolean includeGhosts = ZSoft::kFalse);

inline const ZTCHAR * ZcDbXrefGraphNode::name() const { return mpName; }
inline ZcDbObjectId ZcDbXrefGraphNode::btrId() const { return mBtrId; }
inline ZcDbDatabase* ZcDbXrefGraphNode::database() const
     { return (ZcDbDatabase*)data(); }

inline void ZcDbXrefGraphNode::setBtrId(const ZcDbObjectId& id)
    { mBtrId = id; }
inline void ZcDbXrefGraphNode::setDatabase(ZcDbDatabase* pDb)
    { setData(pDb); }

inline bool ZcDbXrefGraphNode::isNested() const
    { return !isMarkedAs(kFirstLevel); }

inline ZcDb::XrefStatus ZcDbXrefGraphNode::xrefStatus() const
    { return mStatus; }
inline void ZcDbXrefGraphNode::setXrefStatus(ZcDb::XrefStatus stat)
    { mStatus = stat; }
inline ZcDb::XrefNotificationStatus
ZcDbXrefGraphNode::xrefNotificationStatus() const
    { return mNotifyStatus; }
inline void ZcDbXrefGraphNode::setXrefNotificationStatus(
    ZcDb::XrefNotificationStatus stat)
    { mNotifyStatus = stat; }

inline ZcDbXrefGraphNode* ZcDbXrefGraph::xrefNode(int idx) const
    { return (ZcDbXrefGraphNode*)node(idx); }

inline ZcDbXrefGraphNode* ZcDbXrefGraph::hostDwg() const
    { return (ZcDbXrefGraphNode*)rootNode(); }

#pragma pack (pop)

#endif

