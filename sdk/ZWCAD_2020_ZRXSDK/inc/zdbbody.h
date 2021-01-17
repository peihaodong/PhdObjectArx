

#ifndef ZGEOMENT_DBBODY_H
#define ZGEOMENT_DBBODY_H

#include "zdbmain.h"
#include "zdbsubeid.h"

#pragma pack (push, 8)

class ZcDbBody: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBody);
	     ZcDbBody();
    virtual ~ZcDbBody();

    virtual ZSoft::Boolean    isNull       () const;
    virtual void              list         () const;

	ZCDB_PORT virtual void	  dragStatus(const ZcDb::DragStat);
	virtual void*             ZSMBodyCopy(bool bDeepCopy = false) const; 
	virtual void const *      getLockedZSMBody();                        
	virtual void              unlockZSMBody();                           
	virtual void*             getLockedWritableZSMBody();                
	virtual void              commitWritableZSMBody();                   
	virtual Zcad::ErrorStatus setZSMBody      (const void* modelerBody); 


    virtual ZcDbSubentId    internalSubentId (void*) const;                   
    virtual void*           internalSubentPtr(const ZcDbSubentId& id) const;  

    static  Zcad::ErrorStatus acisOut      (const ZTCHAR* fileName,
					    const ZcDbVoidPtrArray&);
    static  Zcad::ErrorStatus acisIn       (const ZTCHAR* fileName,
					    ZcDbVoidPtrArray&);

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
				ZcDb::SubentType type,
                                ZSoft::GsMarker gsMark,
				const ZcGePoint3d& pickPoint,
				const ZcGeMatrix3d& viewXform,
				int& numPaths,
				ZcDbFullSubentPath*& subentPaths,
				int numInserts = 0,
				ZcDbObjectId* entAndInsertStack = NULL) const;

    virtual Zcad::ErrorStatus getGsMarkersAtSubentPath(
				const ZcDbFullSubentPath& subPath,
                                ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const;
 
    virtual ZSoft::UInt32 numChanges() const;
	ZCDB_PORT virtual bool usesGraphicsCache();

    void invalidateCachedBodySubentIds();
};

#pragma pack (pop)

#endif
