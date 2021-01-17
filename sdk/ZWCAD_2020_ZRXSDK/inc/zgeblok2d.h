

#ifndef ZC_GEBLOCK2D_H
#define ZC_GEBLOCK2D_H

#include "zgeent2d.h"
#pragma pack (push, 8)
class ZcGePoint2d;
class ZcGeVector2d;

class 
GE_DLLEXPIMPORT
ZcGeBoundBlock2d : public ZcGeEntity2d
{
public:
                    
	ZcGeBoundBlock2d ();
	ZcGeBoundBlock2d (const ZcGePoint2d& point1, const ZcGePoint2d& point2);
	ZcGeBoundBlock2d (const ZcGePoint2d& base,
                      const ZcGeVector2d& dir1, const ZcGeVector2d& dir2);
	ZcGeBoundBlock2d (const ZcGeBoundBlock2d& block);

    void              getMinMaxPoints  (ZcGePoint2d& point1,
								        ZcGePoint2d& point2) const;
    void              get              (ZcGePoint2d& base,
								        ZcGeVector2d& dir1,
								        ZcGeVector2d& dir2) const;

    ZcGeBoundBlock2d& set         (const ZcGePoint2d& point1,
                                   const ZcGePoint2d& point2);
    ZcGeBoundBlock2d& set         (const ZcGePoint2d& base,
                                   const ZcGeVector2d& dir1,
                                   const ZcGeVector2d& dir2);

    ZcGeBoundBlock2d& extend      (const ZcGePoint2d& point);

    ZcGeBoundBlock2d& swell       (double distance);

    ZSoft::Boolean    contains    (const ZcGePoint2d& point) const;
    ZSoft::Boolean    isDisjoint  (const ZcGeBoundBlock2d& block)
                                                 const;

    ZcGeBoundBlock2d& operator =  (const ZcGeBoundBlock2d& block);

	ZSoft::Boolean    isBox     () const;
	ZcGeBoundBlock2d& setToBox  (ZSoft::Boolean);
};

#pragma pack (pop)
#endif
