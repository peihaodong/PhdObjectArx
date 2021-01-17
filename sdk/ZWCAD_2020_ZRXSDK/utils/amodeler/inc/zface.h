#ifndef AECMODELER_INC_FACE_H
#define AECMODELER_INC_FACE_H

#include "zbody.h"
#include "zplane.h"
#include "zenums.h"

AECMODELER_NAMESPACE_BEGIN


// Global face flags
//
const Flag FFF      = ZWFLAG(0);  // Front  Face Flag
const Flag CONVEXFF = ZWFLAG(1);  // Convex Face Flag



class DllImpExp ZwFace : public ZwEntity
{
public:
    ZwFace();
    ZwFace(                 ZwBody*);
    ZwFace(       ZwSurface*, ZwBody*);
    ZwFace(ZwEdge*, ZwSurface*, ZwBody*);
    ZwFace(const ZwFace&);
    ~ZwFace(){};

    ZwFace(const ZwCircle3d&, int type, int approx, ZwBody*);

    ZwFace(const ZwPoint3d      plg       [],
         ZwPolygonVertexData* vertexData[],
         int                numVertices, 
         const ZwVector3d&    plgNormal,
         int                type,  
         bool               checkPlanarity, 
         ZwBody*);

    // Create a face from an array of points
    //
    ZwFace(ZwPoint3d            p[], 
         int                numEdges,
         int                type, 
         bool               checkPlanarity,
         ZwBody*,
         ZwEdge**             createdEdges = NULL);  // TODO The last argument is stupid

    // Create a face from an array of vertices
    //
    ZwFace(ZwVertex*            vertices[],
         ZwCurve*             curves[],
         ZwEdge*              partners[], 
         int                numEdges, 
         int                type, 
         bool               checkPlanarity, 
         ZwBody*, 
         ZwEdge**             createdEdges = NULL);

    void     modified      ();  // The face was modified in some way

    int      edgeCount     () const;
    ZwEdge*    edge          (int edgeIndexInFace) const;
    
    ZwEdge*    edgeLoop      () const        { return mpEdgeLoop; }
    ZwSurface* surface       () const        { return mpSurface;  }
    ZwFace*    next          () const        { return mpNext;     }
    ZwFace*    prev          () const        { return mpPrev;     }
    ZwColor    color         () const        { return mColor;     }
    void*    attrib        () const        { return mpAttrib;   }

    void     setEdgeLoop   (ZwEdge*       e) { mpEdgeLoop = e;    }
    void     setSurface    (ZwSurface*    s) { mpSurface  = s;    }
    void     setNext       (ZwFace*       f) { mpNext     = f;    }
    void     setPrev       (ZwFace*       f) { mpPrev     = f;    }

    void     setColor      (ZwColor, bool edgesAlso = false, bool partnerEdgesAlso = false);
    void     setAttrib     (void* a)       { mpAttrib = a; }

    void     addEdge       (ZwEdge*, ZwEdge* prevEdge = NULL);
    void     removeEdge    (ZwEdge*); // Does not delete the removed edge
    void     deleteAllEdges();

    void     negate        ();
    
    void     paint         (const ZwBody&, ZwColor, bool dae=false, bool dbe=false);

    void     massProperties(const ZwBody&,
                            bool     dae,
                            bool     dbe,
                            double&  perimeter,
                            double&  area,
                            ZwPoint3d& centroid) const;

    double   area          () const;  // Calculate the face area, also set the plane

    void     triangulate   (ZwOutputTriangleCallback*, 
                            ZwTriangulationType = kGenerateTriangles) const;

    // Transforms the face by the given transformation and add side faces. The
    // face is thus lifted from its current location to a new location. 
    //
    void  lift(const ZwTransf3d&, bool checkPlanarity, ZwBody* owningBody);

    // Extracts all loops of the face, skipping the bridge edges. 
    // Each std::vector<Edge*> represents one extracted loop. The outer loop
    // of the face is also returned.
    //
    void extractAllLoops(std::vector<std::vector<ZwEdge*> >& loops) const;

    // Splits the face at vertices e1->vertex() and e2->vertex(), e1 and e2 
    // being edges of this face. The newly created edges between this face and 
    // the newly created one are assigned the "approximating" flag
    //
    ZwFace* split(ZwEdge* e1, ZwEdge* e2, ZwBody*);

    // "This" face represents a positive face. The given holeFaces vector 
    // contains faces completely inside this face, coplanar with this faces, 
    // but with opposite orientation.
    //
    // The method joins the hole faces with this face by adding bridge edges.
    // The hole faces are then set to faces containg no edges. The result of 
    // this joining may be more than one well-formed face. All the faces are
    // returned in the faces vector. Notice that if the result is more than
    // one face, new faces are created and "this" face will become empty, i.e.
    // containing no edges
    // 
    void insertHoles(const std::vector<ZwFace*>& holeFaces, // Hole faces, coplanar and completely inside "this" face
                     ZwBody*                     pBody,     // Body that receives the new vertices and new faces
                     std::vector<ZwFace*>&       faces);    // The resulting contiguous faces (may be more than one)

    // Valid faces represent a single contiguous area. This method decomposes 
    // a (potentially invalid) face that may represent several contiguous areas 
    // into several valid faces that each represents a single contiguous area.
    //
    // The result is returned in contiguousFaces vector. If the result is more 
    // than one face, new faces are created and "this" face will become empty,
    // i.e. containing no edges
    //
    void decomposeIntoContiguousFaces(ZwBody* pBody, std::vector<ZwFace*>& contiguousFaces);

    const ZwPlane&         plane       () const;  // Face plane 
    const ZwInterval3d&    interval    () const;  // Face interval (bounding box)
    const ZwIntInterval3d& projInterval() const;  // Integer projected interval

    void deletePlane          () const;
    void deleteInterval       () const;
    void deleteProjInterval   () const;

    void setProjInterval      (const ZwIntInterval3d&) const;

    bool isPointInside(const ZwPoint3d&)   const; // Returns true iff the point is inside or on edge/vertex
    bool isPlanar(double eps = ZwEpsAbs()) const;
    bool isSelfIntersecting()            const;

    void print   (FILE* = NULL)          const;
    void save    (ZwSaveRestoreCallback* pCallBack)  const;
    void restore (ZwSaveRestoreCallback* pCallBack, int version);
    
    // Scratch variables (unioned to save space)
    //
    union
    {
        ZwEdge* iel;   // Inner edge list   (Booleans)
        ZwFace* fptr;  // Next face in list (hide, interfere)
        int   n;     // Entity index      (print)
    };

private:

    ZwEdge*          mpEdgeLoop;     // One edge in the loop of edges of the face
    ZwSurface*       mpSurface;      // Exact surface, NULL for real planar faces

    ZwFace*          mpNext;         // Next face in the linear list of faces of a body
    ZwFace*          mpPrev;

    ZwPlane*         mpPlane;        // Face plane
    ZwInterval3d*    mpInterval;     // Face interval
    ZwIntInterval3d* mpProjInterval; // Integer projected interval (hide, picking)

    ZwColor          mColor;         // Face color
    void*          mpAttrib;       // Arbitrary user-defined attribute data

    double evaluatePlane   () const;  // Evaluate face plane, return face area  
    void   evaluateInterval() const;  // Evaluate face interval

};  // class Face


AECMODELER_NAMESPACE_END


// Inlines (do not look beyond this point)
// sdl for ZW_ASSERT
#include <stddef.h>
#include "zedge.h"

AECMODELER_NAMESPACE_BEGIN


inline const ZwPlane& ZwFace::plane() const 
{
/*sdl    if (mpPlane == NULL)
        evaluatePlane();

    ZW_ASSERT(mpPlane->isValid());
*/    
    return *mpPlane; 
}



inline const ZwInterval3d& ZwFace::interval() const 
{ 
/*    if (mpInterval == NULL)
        evaluateInterval();
*/
    return *mpInterval;
}

inline const ZwIntInterval3d& ZwFace::projInterval() const 
{ 
//    ZW_ASSERT(mpProjInterval != NULL);
    return *mpProjInterval;
}


inline void ZwFace::addEdge(ZwEdge* e, ZwEdge* prevEdge)
{
/*sdl    if (e == NULL) {
        return;
    }

    // The edge should be in a neutral state
    //
//sdl    ZW_ASSERT(e->next() == NULL && e->prev() == NULL && e->face() == NULL);

    // If no prevEdge is given, use Face::edgeLoop()
    //
    if (prevEdge == NULL)
        prevEdge = edgeLoop();

    if (prevEdge != NULL) 
    {
//sdl        e->addAfter(prevEdge);

    } else {
        // Adding the first edge to the face
        //
//        e->setNext(e);
        e->setPrev(e);
    }

    e->setFace(this);
    setEdgeLoop(e);  // Let this face point to the given edge
*/}


inline void ZwFace::removeEdge(ZwEdge* e)
{
/*sdl    if (e == NULL || e->face() != this)
    {
        FAIL;
        return;
    }

    // If the Face::edgeLoop() pointer of this face points to the edge being
    // removed, change it to point to another edge in the loop of edges of this
    // face
    //
    if (edgeLoop() == e)
    {
        if (e->next() != e)
        {
            setEdgeLoop(e->next());
        }
        else
        {
            setEdgeLoop(NULL); // We are removing the last edge in the loop
        }
    }

    // Unlink the edge and put it to a neutral state
    //
    e->next()->setPrev(e->prev());
    e->prev()->setNext(e->next());
    // sdl e->removePartner();

    e->setNext(NULL);
    e->setPrev(NULL);
    e->setFace(NULL);
*/}

AECMODELER_NAMESPACE_END
#endif
