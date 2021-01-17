
#ifndef ZC3DDWFNAVTREE_H
#define ZC3DDWFNAVTREE_H

class Zc3dDwfNavTreeNode : public ZcRxObject
{
public:
    virtual const ZcString&     displayName() const = 0;
    virtual const ZcArray<long>& keys() const = 0;
    virtual       int           nDescendants() const = 0;
    virtual       bool          isGroup() const = 0;
    virtual const ZcArray<const Zc3dDwfNavTreeNode*>& children() const = 0;
    virtual       bool          isBlock() const = 0;
    virtual       bool          addChild(const Zc3dDwfNavTreeNode* node) = 0;
    virtual       bool          removeChild(const Zc3dDwfNavTreeNode* node) = 0;
};

#endif
