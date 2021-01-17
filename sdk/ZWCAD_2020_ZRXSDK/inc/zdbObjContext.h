

#pragma once
#pragma pack(push, 8)

#include "zdbmain.h"
class ZcDbObjectContext : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbObjectContext);
    ZcDbObjectContext ();
    virtual ~ZcDbObjectContext ();
    virtual Zcad::ErrorStatus getName ( ZcString& name) const = 0;
    virtual Zcad::ErrorStatus setName ( const ZcString& name ) = 0;
    virtual ZSoft::LongPtr uniqueIdentifier () const = 0;
    virtual ZcString collectionName () const = 0;
};

#pragma pack(pop)
