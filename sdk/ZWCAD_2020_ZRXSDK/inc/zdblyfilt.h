

#ifndef ZD_DBLYFILT_H
#define ZD_DBLYFILT_H

#include "zdbfilter.h"
#include "zAdAChar.h"

#pragma pack (push, 8)

class ZcDbLayerFilter: public  ZcDbFilter
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerFilter);
             ZcDbLayerFilter();
    virtual ~ZcDbLayerFilter();

    virtual ZcRxClass* indexClass() const;
    virtual ZSoft::Boolean isValid() const;

    Zcad::ErrorStatus add(const ZTCHAR * pLayer);
    Zcad::ErrorStatus remove(const ZTCHAR * pLayer);
    Zcad::ErrorStatus getAt(int index, const ZTCHAR *& pName) const;
    int layerCount() const;
};

#pragma pack (pop)

#endif 
