#ifndef AECMODELER_INC_MORPHMAP_H
#define AECMODELER_INC_MORPHMAP_H

#include "zglobal.h"
#include <vector>

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwMorphingMap
{
public:
    ZwMorphingMap() {}
    ZwMorphingMap(const ZwMorphingMap&);
    ~ZwMorphingMap();

    ZwMorphingMap& operator =(const ZwMorphingMap&);

    void  add  (int from, int to, int vis = 0);
    void  addAt(int index, int from, int to, int vis = 0);
    void  del  (int index);
    void  get  (int index, int& fromIndex, int& toIndex, int& visibility) const;

    int  length() const { return 0; }
    bool isNull() const { return true; }
    bool isIdentity() const;

    void setToExplicitIdentityMap(int numEdges); // Mapping 0-->0, 1-->1, 2-->2, 3-->3, etc.

    //void createFromTwoPointLoops(const std::vector<Point2d>&, const std::vector<Point2d>&);

    void init();         // Empties the map
    void print() const;

    // Converts mapping m --> n (m > n) to:
    // a --> 1
    // n --> n
    // b --> 1
    //
    // and mapping m --> n (m < n) to:
    // 1 --> a
    // m --> m
    // 1 --> b
    //
    // where a = abs(m-n+1)/2 and b = abs(m-n) - a
    //
    void normalize(int numEdges0, int numEdges1);

    void remapIndices(const std::vector<int>& fromIndexMap, const std::vector<int>& toIndexMap);

    static const ZwMorphingMap kNull;

    enum { kCrossEdgeIsApprox = 1, kBaseEdgeIsApprox = 2 };

private:

    class MorphingMapElem
    {
    public:
        MorphingMapElem(int i, int j, int vis = 0) : fromIndex(i), toIndex(j), visibility(vis) {} 

        int fromIndex;
        int toIndex;
        int visibility;
    };

    //std::vector<MorphingMapElem*> mArray;
}; 

AECMODELER_NAMESPACE_END
#endif

