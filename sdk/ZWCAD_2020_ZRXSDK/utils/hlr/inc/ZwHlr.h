#pragma once
#include "zdbmain.h"
#include "zdbsubeid.h"
//-----------------------------------------------------------------------------
#ifdef ZWHLR_EXPORTS
#define DllImpExp __declspec(dllexport)
#else
#define DllImpExp __declspec(dllimport)
#endif

#pragma warning (disable: 4251)

#define ZsdkHlrApiServiceName _T(/*NOXLATE*/"ZSDK_HLR_API_SERVICES")

//-----------------------------------------------------------------------------
enum ZsdkHlrControl {
    kProject            =0x0001, //----- Should the curves be projected to a plane?
    kShowAll            =0x0002, //----- Should all curves be returned, or just visible ones?
    kEntity             =0x0004, //----- No affection if it is set or not in ZwHlr. 
    kBlock              =0x0008, //----- Not supported yet. Will be supported in next version.
    kSubentity          =0x0010, //----- Not supported yet. Will be supported in next version with kBlock control.
    kHideTangents       =0x0020, //----- No affection if it is set or not in ZwHlr.
    kCleanup            =0x0040, //----- Should stored data be cleaned after use?
    kIsolines           =0x0080, //----- Should isolines be shown (same as would be seen in ZWCAD)?
    kUnite              =0x0100, //----- Should the entities be united before hidden lines?
                                 //----- Will be much slower, but more accurate for intersecting entities.
    kReuse              =0x0200, //----- Should the algorithm use the data which were created previously?
    kProgress           =0x0400, //----- Should the progress & abort callbacks be called?
    kHandlePoints       =0x0800, //----- Not supported yet.
    kProcessAll         =0x1000, //----- Process all entities without looking at their layer state on which they lie on.
    kHonorInternals     =0x2000, //----- Not supported yet.
    kMeshSilhouettes    =0x4000, //----- Not supported yet.
    kSingleCacheVp      =0x8000  //----- No affection if it is set or not in ZwHlr
} ;

//-----------------------------------------------------------------------------
class DllImpExp ZsdkHlrData {

public:
    enum Visibility {
        kVisible,           //----- Not hidden by anything
        kHidden,            //----- Hidden by a face
        kOccluded,          //----- Not happen in ZwHlr. Probably be supported in future.
        kInternallyHidden,  //----- Should never happen in ZwHlr. 
        kUndefined          //----- Initialized state in ZwHlr
    } ;

public:
    ZcDbEntity *m_pEntity ;             //----- Entity which generated the curve

    ZcDbObjectIdArray m_objectIds ;     //----- Not supported yet. Will be supported in next version with kBlock control
    ZcDbSubentId m_subentId ;           //----- Not supported yet. Will be supported in next version with kBlock control

    ZsdkHlrData::Visibility m_visibility;//----- Is the curve visible? etc.
    Visibility m_hlrVisibility;          //----- Should never happen in ZwHlr
    ZcDbEntity *m_pResultEntity;        //----- Resulting entity (usually a curve)

public:
    ZsdkHlrData ();
    virtual ~ZsdkHlrData ();

    //----- Corresponding setting functions not anticipated for use by applications
    void setEntity (ZcDbEntity *pEnt);
    void setObjectIds (ZcDbObjectIdArray id);
    void setResultEntity (ZcDbEntity *pResultEnt);
    void setVisibility (ZsdkHlrData::Visibility visibility);
    void setHlrVisibility (ZsdkHlrData::Visibility visibility);
    void setSubentId (ZcDbSubentId subentId);

    //----- Gets entity causing this curve
    ZcDbEntity *getEntity ();
    //----- Gets ObjectIds causing this curve
    ZcDbObjectIdArray &getObjectIds ();
    //----- Curve itself. This is the actual curve stored by the class.
    //----- !In case of point, the resulting entity would be a point and not a curve!
    ZcDbEntity *getResultEntity ();
    //----- Obtains visiblity of this curve
    ZsdkHlrData::Visibility getVisibility ();
    ZsdkHlrData::Visibility getHlrVisibility ();
    //----- Obtains the subentities of the curve
    ZcDbSubentId getSubentId ();
} ;

//-----------------------------------------------------------------------------
class ZsdkHlrEngine ;

class DllImpExp ZsdkHlrCollector {

protected:
    ZcArray<ZcDbEntity *> m_entities ;    //----- Memory input entity
    bool m_bDeleteInDestructor ;            //----- Indicates if the collector object is responsible to destroy
    //----- all memory objects
    ZcDbObjectIdArray m_entityIds ;        //----- Database Resident input entity

public:
    ZcArray<ZsdkHlrData *> mOutputData ;//----- ZsdkHlrData output array (contains the curves and data)

public:
    ZsdkHlrCollector ();
    ZsdkHlrCollector (ZcDbObjectIdArray &ids) ;
    ZsdkHlrCollector (ZcArray<ZcDbEntity *> &entities, bool deleteInDestructor =false) ;
    ZsdkHlrCollector (ZsdkHlrCollector &collector) ;

    virtual ~ZsdkHlrCollector () ;

    bool getDeleteState ();
    void setDeleteState (bool bFlag);

    ZcArray<ZcDbEntity *> &getInputEntities ();
    ZcDbObjectIdArray &getInputEntityIds ();

    void addEntity (ZcDbEntity *pEnt) ;
    void addEntities (ZcArray<ZcDbEntity *> &pEnts) ;
    void addEntity (ZcDbObjectId id) ;
    void addEntities (ZcDbObjectIdArray &ids) ;

    void removeEntity (ZcDbEntity *pEnt) ;
    void removeEntities (ZcArray<ZcDbEntity *> &pEnts) ;
    void removeEntity (ZcDbObjectId id) ;
    void removeEntities (ZcDbObjectIdArray &ids) ;

    void clear () ;

protected:
    //----- Do not call those two methods in your program
    //----- They are called by the 'ZsdkHlrEngine' to open/close DBR entities
    virtual int initialize (ZcArray<ZcDbEntity *> &collection) ;
    virtual void close (ZcArray<ZcDbEntity *> &collection) ;

    friend class ZsdkHlrEngine ;
} ;

//-----------------------------------------------------------------------------
typedef void (*_AbortCallbackFct) (bool *abort) ;
typedef void (*_ProgressCallbackFct) (int percent_completed) ;

class DllImpExp ZsdkHlrEngine {

protected:
    ZcDbViewport *m_pViewport ;
    int m_nControl ;
    _AbortCallbackFct m_pAbortCallbackFct ;
    _ProgressCallbackFct m_pAcisConvertionProgressCallbackFct ;
    _ProgressCallbackFct m_pAhlProgressCallbackFct ;
    _ProgressCallbackFct m_pZcadConvertionProgressCallbackFct ;

public:
    ZsdkHlrEngine (int ctrl =kShowAll | kEntity | kBlock | kSubentity | kReuse) ;
    ZsdkHlrEngine (ZcDbObjectId id, int ctrl =kShowAll | kEntity | kBlock | kSubentity | kReuse) ;
    ZsdkHlrEngine (ZcDbViewport *pViewport, int ctrl =kShowAll | kEntity | kBlock | kSubentity | kReuse) ;
    ZsdkHlrEngine (ZcGePoint3d &viewTarget, ZcGeVector3d &viewDirection, int ctrl =kShowAll | kEntity | kBlock | kSubentity | kReuse) ;

    virtual ~ZsdkHlrEngine () ;

    Zcad::ErrorStatus run (ZsdkHlrCollector &collector) ;

    void setAbortCallback (_AbortCallbackFct fct) ;

    void setAcisConversionProgressCallBack (_ProgressCallbackFct fct) ;
    void setAhlProgressCallBack (_ProgressCallbackFct fct) ;
    void setAcadConversionProgressCallBack (_ProgressCallbackFct fct) ;

    static void cleanHlrCache () ;  // Internally call ZsdkHiddenLineBase::clear() method.
    static void cleanHlrCache (ZcDbEntity *pEnt, ZcDbViewport *pVp =NULL) ;      // Clear cache for pEnt. pVp is unreferenced right now, which means all cached info will be cleared for all viewport.
    static void cleanHlrCache (ZcDbEntity *pEnt, ZcGePoint3d viewTarget, ZcGeVector3d viewDir) ;
} ;

//-----------------------------------------------------------------------------
extern "C" void *createBodyFromTriangles (ZcGePoint3dArray &pts, ZcGeIntArray &indices) ;  // The tol for stitching triangles is 1e-4.
