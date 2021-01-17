

#ifndef ZD_DBDIMDATA_H
#define ZD_DBDIMDATA_H

#include "zacdb.h"
#include "zacarray.h"
#include "zdbdim.h"

class ZcDbDimData;

typedef ZcArray<ZcDbDimData*> ZcDbDimDataPtrArray;
typedef ZcGeVector3d (*DimDataSetValueFuncPtr) (ZcDbDimData* pThis,
                                        ZcDbEntity* pEnt, 
                                        double newValue,
                                        const ZcGeVector3d& offset);
typedef ZcGeVector3d (*DimDataSetCustomStringFuncPtr) (ZcDbDimData* pThis,
                                        ZcDbEntity* pEnt,
                                        const ZTCHAR* pCustomString,
                                        const ZcGeVector3d& offset);
class ZcDbDimData
{
public:
    enum DimDataFlags {
        kDimEditable           = 0x1,
        kDimInvisible          = 0x2,
        kDimFocal              = 0x4,
        kDimHideIfValueIsZero  = 0x8,
        kDimEmptyData          = 0x10,
        kDimResultantLength    = 0x20,
        kDimDeltaLength        = 0x40,
        kDimResultantAngle     = 0x80,
        kDimDeltaAngle         = 0x100,
        kDimRadius             = 0x200,
        kDimCustomValue        = 0x400,
        kDimConstrained        = 0x800,
        kDimCustomString       = 0x1000

    };

    ZcDbDimData();
    ZcDbDimData(ZcDbDimension* pDim, 
                DimDataSetValueFuncPtr setDimFunc = NULL,
                unsigned int bitFlags = 0,
                void* appData = NULL,
                DimDataSetCustomStringFuncPtr setCustomStringFunc = NULL);

    ~ZcDbDimData();

    ZcDbDimData(const ZcDbDimData&);
    ZcDbDimData&  operator = (const ZcDbDimData&);
    ZcDbDimension* dimension() const;
    Zcad::ErrorStatus setDimension(ZcDbDimension* pDim);
    ZcDbObjectId ownerId() const;
    Zcad::ErrorStatus setOwnerId(const ZcDbObjectId& objId);
    unsigned int bitFlags() const;
    Zcad::ErrorStatus setBitFlags(unsigned int flags);
    bool isDimFocal() const;
    Zcad::ErrorStatus setDimFocal(bool focal);
    bool isDimEditable() const;
    Zcad::ErrorStatus setDimEditable(bool editable);
    bool isDimInvisible() const;
    Zcad::ErrorStatus setDimInvisible(bool invisible);
    bool isDimHideIfValueIsZero() const;
    Zcad::ErrorStatus setDimHideIfValueIsZero(bool hide);
    void *appData() const;
    Zcad::ErrorStatus setAppData(void* appData);
    DimDataSetValueFuncPtr dimValueFunc() const;
    Zcad::ErrorStatus setDimValueFunc(DimDataSetValueFuncPtr funcPtr);
    DimDataSetCustomStringFuncPtr customStringFunc() const;
    Zcad::ErrorStatus setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr);
    bool isDimResultantLength() const;
    Zcad::ErrorStatus setDimResultantLength(bool bValue);
    bool isDimDeltaLength() const;
    Zcad::ErrorStatus setDimDeltaLength(bool bValue);
    bool isDimResultantAngle() const;
    Zcad::ErrorStatus setDimResultantAngle(bool bValue);
    bool isDimDeltaAngle() const;
    Zcad::ErrorStatus setDimDeltaAngle(bool bValue);
    bool isDimRadius() const;
    Zcad::ErrorStatus setDimRadius(bool bValue);
    bool isCustomDimValue() const;
    Zcad::ErrorStatus setCustomDimValue(bool custom);
    bool isConstrained() const;
    Zcad::ErrorStatus setConstrain(bool bValue);
    bool isCustomString() const;
    Zcad::ErrorStatus setCustomString(bool bValue);

private:
    ZcDbDimension*      mpDim;
    ZcDbObjectId        mOwnerId;
    unsigned int        mBitFlags;
    DimDataSetValueFuncPtr  mpSetDimValueFunc;
	void*               mpAppData;    
    DimDataSetCustomStringFuncPtr  mpSetCustomStringFunc;
};

typedef ZcArray<ZcDbDimData> ZcDbDimDataArray;
inline ZcDbDimData::ZcDbDimData() : 
    mpDim(NULL), 
    mBitFlags(0),
    mpSetDimValueFunc(NULL),
    mpAppData (NULL),
    mpSetCustomStringFunc(NULL)
{
}

inline ZcDbDimData::ZcDbDimData(ZcDbDimension* pDim,
                   DimDataSetValueFuncPtr setValueFunc,
                   unsigned int bitFlags,
                   void* appData,
                   DimDataSetCustomStringFuncPtr setCustomStringFunc) :
    mpDim(pDim),
	mBitFlags(bitFlags),
    mpSetDimValueFunc(setValueFunc),
    mpAppData(appData),
    mpSetCustomStringFunc(setCustomStringFunc)
{
}

inline ZcDbDimData::ZcDbDimData(const ZcDbDimData& src)
{
    *this = src;
}

inline ZcDbDimData::~ZcDbDimData()
{
    if (mpDim) 
        delete mpDim;
}

inline ZcDbDimData& ZcDbDimData::operator = (const ZcDbDimData& src)
{
    if (this == &src)
        return *this;

    mpDim = (ZcDbDimension*)src.dimension()->clone();
    mOwnerId = src.ownerId();
    mpSetDimValueFunc = src.dimValueFunc();
    mpSetCustomStringFunc = src.customStringFunc();
    mBitFlags = src.bitFlags();
    mpAppData = src.appData();
    return *this;
}

inline ZcDbDimension*
ZcDbDimData::dimension() const
{
    return mpDim;
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimension(ZcDbDimension* pDim)
{
    mpDim = pDim;
    return Zcad::eOk;
}

inline ZcDbObjectId
ZcDbDimData::ownerId() const
{
    return mOwnerId;
}

inline Zcad::ErrorStatus
ZcDbDimData::setOwnerId(const ZcDbObjectId& objId)
{
    mOwnerId = objId;
    return Zcad::eOk;
}

inline unsigned int 
ZcDbDimData::bitFlags() const
{
    return mBitFlags;
}

inline Zcad::ErrorStatus
ZcDbDimData::setBitFlags(unsigned int flags)
{
    mBitFlags = flags;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isDimFocal() const
{
    return !!(mBitFlags & kDimFocal);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimFocal(bool focal)
{
    if (focal)
        mBitFlags |= kDimFocal;
    else
        mBitFlags &= ~kDimFocal;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isDimEditable() const
{
    return !!(mBitFlags & kDimEditable);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimEditable(bool editable)
{
    if (editable)
        mBitFlags |= kDimEditable;
    else
        mBitFlags &= ~kDimEditable;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isDimInvisible() const
{
    return !!(mBitFlags & kDimInvisible);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimInvisible(bool invisible)
{
    if (invisible)
        mBitFlags |= kDimInvisible;
    else
        mBitFlags &= ~kDimInvisible;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isDimHideIfValueIsZero() const
{
    return !!(mBitFlags & kDimHideIfValueIsZero);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimHideIfValueIsZero(bool hide)
{
    if (hide)
        mBitFlags |= kDimHideIfValueIsZero;
    else
        mBitFlags &= ~kDimHideIfValueIsZero;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isDimResultantLength() const
{
    return !!(mBitFlags & kDimResultantLength);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimResultantLength(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimResultantLength;
    else
        mBitFlags &= ~kDimResultantLength;
    return Zcad::eOk;
}
inline bool
ZcDbDimData::isDimDeltaLength() const
{
    return !!(mBitFlags & kDimDeltaLength);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimDeltaLength(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimDeltaLength;
    else
        mBitFlags &= ~kDimDeltaLength;
    return Zcad::eOk;
}
inline bool
ZcDbDimData::isDimResultantAngle() const
{
    return !!(mBitFlags & kDimResultantAngle);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimResultantAngle(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimResultantAngle;
    else
        mBitFlags &= ~kDimResultantAngle;
    return Zcad::eOk;
}
inline bool
ZcDbDimData::isDimDeltaAngle() const
{
    return !!(mBitFlags & kDimDeltaAngle);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimDeltaAngle(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimDeltaAngle;
    else
        mBitFlags &= ~kDimDeltaAngle;
    return Zcad::eOk;
}
inline bool
ZcDbDimData::isDimRadius() const
{
    return !!(mBitFlags & kDimRadius);
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimRadius(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimRadius;
    else
        mBitFlags &= ~kDimRadius;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isCustomDimValue() const
{
    return !!(mBitFlags & kDimCustomValue);
}

inline Zcad::ErrorStatus
ZcDbDimData::setCustomDimValue(bool custom)
{
    if (custom)
        mBitFlags |= kDimCustomValue;
    else
        mBitFlags &= ~kDimCustomValue;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isConstrained() const
{
    return !!(mBitFlags & kDimConstrained);
}

inline Zcad::ErrorStatus
ZcDbDimData::setConstrain(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimConstrained;
    else
        mBitFlags &= ~kDimConstrained;
    return Zcad::eOk;
}

inline bool
ZcDbDimData::isCustomString() const
{
    return !!(mBitFlags & kDimCustomString);
}

inline Zcad::ErrorStatus
ZcDbDimData::setCustomString(bool bValue)
{
    if (bValue)
        mBitFlags |= kDimCustomString;
    else
        mBitFlags &= ~kDimCustomString;
    return Zcad::eOk;
}

inline void*
ZcDbDimData::appData() const
{
    return mpAppData;
}

inline Zcad::ErrorStatus
ZcDbDimData::setAppData(void* appData)
{
    mpAppData = appData;
    return Zcad::eOk;
}

inline DimDataSetValueFuncPtr
ZcDbDimData::dimValueFunc() const
{
    return mpSetDimValueFunc;
}

inline Zcad::ErrorStatus
ZcDbDimData::setDimValueFunc(DimDataSetValueFuncPtr funcPtr)
{
    mpSetDimValueFunc = funcPtr;
    return Zcad::eOk;
}

inline DimDataSetCustomStringFuncPtr
ZcDbDimData::customStringFunc() const
{
    return mpSetCustomStringFunc;
}

inline Zcad::ErrorStatus
ZcDbDimData::setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr)
{
    mpSetCustomStringFunc = funcPtr;
    return Zcad::eOk;
}

#endif 



