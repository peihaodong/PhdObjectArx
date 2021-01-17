#ifndef AECMODELER_INC_VERTEX_H
#define AECMODELER_INC_VERTEX_H


#include "zentity.h"
#include "zpoint3d.h"

AECMODELER_NAMESPACE_BEGIN

// Global vertex flags
//
const Flag PICKVF         = ZWFLAG(0);  // Pickable Vertex Flag (for vertex picking)
const Flag NONMANIFOLD_VF = ZWFLAG(1);


class DllImpExp ZwVertex : public ZwEntity
{
public:
    ZwVertex() : mpNext(NULL) {}
    ZwVertex(const ZwPoint3d&, ZwBody*);
    ~ZwVertex();

    const ZwPoint3d& point     () const           { return mPoint; }
    ZwVertex*        next      () const           { return mpNext; }

    void           setPoint  (const ZwPoint3d& p) { mPoint  = p;   }
    void           setNext   (ZwVertex* v)        { mpNext  = v;   }
    void           transform (const ZwTransf3d&); 
    void           modified  ();
    void               deleteVertexSurfaceData (){};

    void           print     (FILE* = NULL)         const;        // Not for public use
    void           save      (ZwSaveRestoreCallback* pCallBack) const;        // Not for public use
    void           restore   (ZwSaveRestoreCallback* pCallBack, int version); // Not for public use

    // Scratch data members (unioned to save space)
    //
    union
    {
        ZwVertex* vptr;
        int     n;
    };
    union
    {
        ZwEdge*   eptr;
        ZwVertex* vptr1;
    };

private:

    ZwPoint3d            mPoint;            
    ZwVertex*            mpNext; 

}; // class Vertex


// Inlines (do not look beyond this point)

inline ZwVertex::~ZwVertex()
{
    deleteVertexSurfaceData();
}


AECMODELER_NAMESPACE_END
#endif
