

#ifndef ZRX_DBMATCH_H
#define ZRX_DBMATCH_H

#include "zacdb.h"
#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbMatchProperties	: public ZcRxObject
{
public:
    enum Flags {
        kColorFlag     = 0x1,
        kLayerFlag     = 0x2,
        kLtypeFlag     = 0x4,
        kThicknessFlag = 0x8,
        kLtscaleFlag   = 0x10,
        kTextFlag      = 0x20,
        kDimensionFlag = 0x40,
        kHatchFlag     = 0x80,
        kLweightFlag   = 0x100,
        kPlotstylenameFlag = 0x200,
        kPolylineFlag  = 0x400,
        kViewportFlag  = 0x800,
        kTableFlag     = 0x1000,
        kMaterialFlag  = 0x2000,
        kShadowDisplayFlag    = 0x4000,
        kMultileaderFlag      = 0x8000,
		kTransparencyFlag     = 0x10000,
        kSetAllFlagsOn = 0x1FFFF,
    };

	ZCRX_DECLARE_MEMBERS(ZcDbMatchProperties);

	virtual void copyProperties(ZcDbEntity* pSrcEntity, ZcDbEntity* pTrgEntity,
								unsigned int flag) const  = 0;
};

#pragma pack (pop)

#endif

