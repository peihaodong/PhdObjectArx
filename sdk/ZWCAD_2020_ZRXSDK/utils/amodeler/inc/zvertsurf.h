#ifndef AECMODELER_INC_VERTSURF_H
#define AECMODELER_INC_VERTSURF_H

#include "zentity.h"
#include "zvector3d.h"

AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwVertexSurfaceData : public ZwEntity
{
public:
    ZwVertexSurfaceData() : mpSurface(NULL), mpNext(NULL), mNormal(0,0,0) {}

    ZwVertexSurfaceData(const ZwEdge*);

    ZwSurface*           surface() const                  { return mpSurface; }
    ZwVertexSurfaceData* next   () const                  { return mpNext;    }
    const ZwVector3d&    normal () const                  { return mNormal;   }

    void               setNext   (ZwVertexSurfaceData* pVsd) { mpNext = pVsd; }
    void               setSurface(ZwSurface*           s)    { mpSurface = s; }
    void               transform (const ZwTransf3d&    t)    { mNormal  *= t; }


    void            print     (FILE* = NULL)         const; // Not for public use
    void            save      (ZwSaveRestoreCallback*) const; // Not for public use
    void            restore   (ZwSaveRestoreCallback*);       // Not for public use

private:

    ZwSurface*           mpSurface; 
    ZwVertexSurfaceData* mpNext;  
    ZwVector3d           mNormal;  // Direction of the surface normal at the vertex
//  Point2d            mParamPoint;

}; // class VertexSurfaceData


AECMODELER_NAMESPACE_END
#endif
