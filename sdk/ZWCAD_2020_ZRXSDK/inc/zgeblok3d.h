

#ifndef ZC_GEBLOCK3D_H
#define ZC_GEBLOCK3D_H

#include "zgeent3d.h"
#pragma pack (push, 8)
class ZcGePoint3d;
class ZcGeVector3d;

class 
GE_DLLEXPIMPORT
ZcGeBoundBlock3d : public ZcGeEntity3d
{
public:
                    
	ZcGeBoundBlock3d ();
	ZcGeBoundBlock3d (const ZcGePoint3d& base, const ZcGeVector3d& dir1,
					  const ZcGeVector3d& dir2, const ZcGeVector3d& dir3);
	ZcGeBoundBlock3d (const ZcGeBoundBlock3d& block);

    void              getMinMaxPoints  (ZcGePoint3d& point1,
								        ZcGePoint3d& point2) const;
    void              get              (ZcGePoint3d& base,
								        ZcGeVector3d& dir1,
								        ZcGeVector3d& dir2,
								        ZcGeVector3d& dir3) const;

    ZcGeBoundBlock3d& set              (const ZcGePoint3d& point1,
								        const ZcGePoint3d& point2);
    ZcGeBoundBlock3d& set              (const ZcGePoint3d& base,
								        const ZcGeVector3d& dir1,
								        const ZcGeVector3d& dir2,
								        const ZcGeVector3d& dir3);

    ZcGeBoundBlock3d& extend           (const ZcGePoint3d& point);

    ZcGeBoundBlock3d& swell            (double distance);

    ZSoft::Boolean    contains         (const ZcGePoint3d& point) const;
    ZSoft::Boolean    isDisjoint       (const ZcGeBoundBlock3d& block) const;

    ZcGeBoundBlock3d& operator =       (const ZcGeBoundBlock3d& block);

    ZSoft::Boolean     isBox    () const;
    ZcGeBoundBlock3d&  setToBox (ZSoft::Boolean);
};

#pragma pack (pop)
#endif
