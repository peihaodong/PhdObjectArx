#ifndef AECMODELER_INC_EDGE_H
#define AECMODELER_INC_EDGE_H

#include "zentity.h"
#include "zcolor.h"
#include "zcircle3d.h"
#include "zvertex.h"

AECMODELER_NAMESPACE_BEGIN


// Global edge flags
//
const Flag AEF    = ZWFLAG(0);   // Approximating Edge Flag
const Flag BEF    = ZWFLAG(1);   // Bridge        Edge Flag
const Flag PICKEF = ZWFLAG(2);   // Pickable      Edge Flag (for edge picking)

const Flag IEF1    = ZWFLAG(10);   // Internal usage1 Edge Flag
const Flag IEF2    = ZWFLAG(11);   // Internal usage2 Edge Flag
const Flag IEF3    = ZWFLAG(12);   // Internal usage2 Edge Flag

class DllImpExp ZwEdge : public ZwEntity
{
public:
    ZwEdge();
    ZwEdge(ZwVertex* pVertex, ZwFace* pFace, ZwEdge* prevEdge, ZwEdge* partner, ZwCurve* = NULL);
    
    ZwVertex* vertex        () const    { return mpVertex;  }
    ZwFace*   face          () const    { return mpFace;    }
    ZwEdge*   next          () const    { return mpNext;    }
    ZwEdge*   prev          () const    { return mpPrev;    }
    ZwColor   color         () const    { return mColor;    }
    ZwPoint3d point() const;

	ZwVector3d vector() const
	{ 
		return mpNext->mpVertex->point() - mpVertex->point(); 
	}

    void    setVertex     (ZwVertex* v) { mpVertex  = v;    }
    void    setFace       (ZwFace*   f) { mpFace    = f;    }
    void    setNext       (ZwEdge*   e) { mpNext    = e;    }
    void    setPrev       (ZwEdge*   e) { mpPrev    = e;    }
	void    setColor      (ZwColor,  bool partnersAlso = false);
    //void    setPartner    (Edge* par) { mpPartner = par;  }
	bool isEulerEdge() const;
    bool isBridge                   () const;
    bool isApprox                   () const;

    void save   (ZwSaveRestoreCallback* pCallBack) const;  // Not for public use
    void restore(ZwSaveRestoreCallback* pCallBack);        // Not for public use
private:
    ZwVertex*  mpVertex;
    ZwFace*    mpFace;     // The owning face.
    ZwEdge*    mpNext;     // The next edge in the loop of edges of a face.
    ZwEdge*    mpPrev;     // The previous edge in the loop of edges of a face.
    ZwColor    mColor;     // Edge color.

};  // class Edge

AECMODELER_NAMESPACE_END


#include "zface.h"
AECMODELER_NAMESPACE_BEGIN


inline ZwEdge::ZwEdge() 
      : mpVertex(NULL),
        mpNext   (NULL), 
        mpPrev   (NULL), 
        mColor   (kColorInvisible)
{
}


inline ZwPoint3d ZwEdge::point() const
{
    return mpVertex->point();
}


inline bool ZwEdge::isBridge() const
{
    return isFlagOn(BEF);
}



inline bool ZwEdge::isApprox() const
{
    return isFlagOn(AEF);
}

/*
inline void Edge::removePartner()
{
    Edge* e = this;

    do {
    } while ((e = e->partner())->partner() != this);

    e->setPartner(partner());
    setPartner(this);
}



inline void Edge::addAfter(Edge* prevEdge)
{
    MASSERT(prevEdge != NULL);

    setNext(prevEdge->next());
    setPrev(prevEdge);
    prevEdge->setNext(this);
    if (next() != NULL) {
        next()->setPrev(this);
    } else {
        FAIL;  // Not a cyclical loop of edges
    }
}


inline Vector3d Edge::unitVector() const 
{ 
    return (next()->point() - point()).normalize(); 
}



inline bool Edge::isManifold() const
{
    return partner()->partner() == this && partner() != this;
}



inline Plane Edge::plane() const
{
    return mpFace->plane();
}



inline Surface* Edge::surface() const
{
    return mpFace->surface();
}



inline Line3d Edge::line() const
{
    return Line3d(mpVertex->point(), vector());
}
*/

AECMODELER_NAMESPACE_END
#endif
