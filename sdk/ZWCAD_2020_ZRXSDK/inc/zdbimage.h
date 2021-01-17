

#ifndef ZD_DBIMAGE_H
#define ZD_DBIMAGE_H

#include "zdbmain.h"
#include "zacgi.h"
#pragma pack (push, 8)

class ZcDbImage: public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbImage);

    virtual ZcGiSentScanLines*	
        getScanLines(const ZcGiRequestScanLines&) const = 0;
    virtual ZSoft::Boolean	
        freeScanLines(ZcGiSentScanLines*) const = 0;    
};

#pragma pack (pop) 
#endif  

