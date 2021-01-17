

#ifndef ZD_GRAPH_H
#define ZD_GRAPH_H 1

#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbGraph;

class ZcDbGraphNode : public ZcHeapOperators
{
friend class ZcDbGraph;

public:
    ZcDbGraphNode(void* pData = NULL);
    virtual ~ZcDbGraphNode();

    enum Flags    { kNone		= 0x00,
		    kVisited		= 0x01,   
		    kOutsideRefed	= 0x02,   
		    kSelected		= 0x04,   
		    kInList		= 0x08,   
		    kListAll		= 0x0E,   
		    kFirstLevel		= 0x10,   
		    kUnresTree		= 0x20,   
		    kAll		= 0x2F };

    void*		data		() const;
    void		setData		(void*);

    int			numOut		() const;
    int			numIn		() const;

    ZcDbGraphNode*	in		(int) const;
    ZcDbGraphNode*	out		(int) const;

    Zcad::ErrorStatus	addRefTo	(ZcDbGraphNode*);
    Zcad::ErrorStatus	removeRefTo	(ZcDbGraphNode*);
    Zcad::ErrorStatus	disconnectAll	();

    ZcDbGraph*		owner		() const;

    bool                isMarkedAs      (ZSoft::UInt8 flags) const;
    Zcad::ErrorStatus	markAs		(ZSoft::UInt8 flags);
    Zcad::ErrorStatus	clear		(ZSoft::UInt8 flags);

    Zcad::ErrorStatus   markTree	(ZSoft::UInt8 flags,
                                         ZcDbVoidPtrArray* = NULL);

    int			numCycleOut	() const;
    int			numCycleIn	() const;

    ZcDbGraphNode*	cycleIn		(int) const;
    ZcDbGraphNode*	cycleOut	(int) const;

    ZcDbGraphNode*	nextCycleNode	() const;

    bool                isCycleNode     () const;

	void			setEdgeGrowthRate(int outEdgeRate, int inEdgeRate);

private:

    ZcDbGraphNode(const ZcDbGraphNode&);
    ZcDbGraphNode&	operator =	(const ZcDbGraphNode&);

    ZcDbVoidPtrArray	mOutgoing;
    ZcDbVoidPtrArray	mIncoming;

    void*		mpData;

    void		setFirstLevel	(ZSoft::Boolean);

    ZSoft::UInt8	mFlags;

    Zcad::ErrorStatus	setOwner	(ZcDbGraph*);
    Zcad::ErrorStatus	resetCycles	();
    Zcad::ErrorStatus	removeCycleRefTo (ZcDbGraphNode*);
    Zcad::ErrorStatus   clearCycles	();

    ZcDbGraph*		mpOwner;

    ZcDbVoidPtrArray*	mpCycleOut;
    ZcDbVoidPtrArray*	mpCycleIn;
};

class ZcDbGraph : public ZcHeapOperators
{
friend class ZcDbGraphNode;

public:
    ZcDbGraph(ZcDbGraphNode* pRoot = NULL);
    virtual ~ZcDbGraph();

    ZcDbGraphNode*	node		(int index) const;
    ZcDbGraphNode*	rootNode	() const;

    int			numNodes	() const;
    bool                isEmpty         () const;

    Zcad::ErrorStatus	addNode		(ZcDbGraphNode*);
    Zcad::ErrorStatus	addEdge		(ZcDbGraphNode* pFrom,
                                         ZcDbGraphNode* pTo);

    Zcad::ErrorStatus	delNode		(ZcDbGraphNode*);

    void		reset		();
    void		clearAll	(ZSoft::UInt8 flags);

    void		getOutgoing	(ZcDbVoidPtrArray&);

    virtual ZSoft::Boolean findCycles	(ZcDbGraphNode* pStart = NULL);
    Zcad::ErrorStatus	breakCycleEdge	(ZcDbGraphNode* pFrom,
                                         ZcDbGraphNode* pTo);

    void		setNodeGrowthRate(int rate);

protected:

    Zcad::ErrorStatus	clearAllCycles	();

private:

    ZcDbGraph(const ZcDbGraph&);
    ZcDbGraph&		operator =	(const ZcDbGraph&);

    ZcDbVoidPtrArray	mNodes;

    ZcDbVoidPtrArray*	mpCycleNodes;

    void		setDirty	();
    bool                mDirty;

};

class ZcDbGraphStack : public ZcHeapOperators
{
public:
    ZcDbGraphStack(int initPhysicalLength = 0, int initGrowLength = 8);
    ~ZcDbGraphStack();

    Zcad::ErrorStatus	push		(ZcDbGraphNode*);
    ZcDbGraphNode*	pop		();

    ZcDbGraphNode*	top		() const;

    bool                isEmpty         () const;

private:

    ZcDbVoidPtrArray	mStack;
};

inline void* ZcDbGraphNode::data() const { return mpData; }
inline void ZcDbGraphNode::setData(void* pData) { mpData = pData; }

inline int ZcDbGraphNode::numOut() const { return mOutgoing.length(); }
inline int ZcDbGraphNode::numIn() const { return mIncoming.length(); }

inline ZcDbGraphNode* ZcDbGraphNode::in(int idx) const
    { return (ZcDbGraphNode*)mIncoming.at(idx); }
inline ZcDbGraphNode* ZcDbGraphNode::out(int idx) const
    { return (ZcDbGraphNode*)mOutgoing.at(idx); }

inline bool ZcDbGraphNode::isMarkedAs(ZSoft::UInt8 flag) const
    { return (this->mFlags & flag) != 0; }

inline ZcDbGraph* ZcDbGraphNode::owner() const { return mpOwner; }
inline Zcad::ErrorStatus ZcDbGraphNode::setOwner(ZcDbGraph* pOwn)
    { assert(!mpOwner); if (mpOwner) return Zcad::eInvalidOwnerObject;
        mpOwner = pOwn; return Zcad::eOk; }

inline int ZcDbGraphNode::numCycleOut() const
    { return mpCycleOut == NULL ? 0 : mpCycleOut->length(); }
inline int ZcDbGraphNode::numCycleIn() const
    { return mpCycleIn == NULL ? 0 : mpCycleIn->length(); }

inline ZcDbGraphNode* ZcDbGraphNode::cycleOut(int idx) const
    { return (ZcDbGraphNode*)
	 (mpCycleOut == NULL ? NULL : mpCycleOut->at(idx)); }
inline ZcDbGraphNode* ZcDbGraphNode::cycleIn(int idx) const
    { return (ZcDbGraphNode*)
	 (mpCycleIn == NULL ? NULL : mpCycleIn->at(idx)); }

inline ZcDbGraphNode* ZcDbGraphNode::nextCycleNode() const
    { assert(mpCycleOut != NULL); return cycleOut(0); }

inline bool ZcDbGraphNode::isCycleNode() const
    { return mpCycleIn != NULL || mpCycleOut != NULL; }
inline int ZcDbGraph::numNodes() const { return mNodes.length(); }
inline ZcDbGraphNode* ZcDbGraph::node(int idx) const
    { return (ZcDbGraphNode*)mNodes.at(idx); }

inline ZcDbGraphNode* ZcDbGraph::rootNode() const
    { return (numNodes() > 0) ? node(0) : NULL; }

inline bool ZcDbGraph::isEmpty() const
    { return numNodes() == 0; }

inline void ZcDbGraph::setDirty() { mDirty = true; }

inline bool ZcDbGraphStack::isEmpty() const
    { return mStack.isEmpty(); }

inline ZcDbGraphNode* ZcDbGraphStack::top() const
    { return isEmpty() ? NULL : (ZcDbGraphNode*)mStack.last(); }

#pragma pack (pop)

#endif

