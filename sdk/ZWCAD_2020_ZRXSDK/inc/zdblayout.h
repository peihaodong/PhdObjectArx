

#ifndef ZD_DBLAYOUT_H
#define ZD_DBLAYOUT_H

#include "zdbmain.h"
#include "zdbdict.h"
#include "zAdAChar.h"
#include "zdbPlotSettings.h"

#pragma pack(push, 8)

class ZcDbLayout: public ZcDbPlotSettings
{
public:
            ZCDB_DECLARE_MEMBERS(ZcDbLayout);

    ZcDbLayout();
    virtual ~ZcDbLayout     ();

    ZcDbObjectId      
    getBlockTableRecordId   () const;

    virtual Zcad::ErrorStatus 
    setBlockTableRecordId   (ZcDbObjectId BlockTableRecordId);

    virtual Zcad::ErrorStatus 
    addToLayoutDict         (ZcDbDatabase *towhichDb,
                             ZcDbObjectId BlockTableRecordId);

    Zcad::ErrorStatus 
    getLayoutName           (const ZTCHAR*& layoutName) const;

    Zcad::ErrorStatus 
    getLayoutName           (ZTCHAR*& layoutName) const;

    virtual Zcad::ErrorStatus 
    setLayoutName           (const ZTCHAR* layoutName);

    int               
    getTabOrder             () const;

    virtual void              
    setTabOrder             (int newOrder);

    bool
    getTabSelected          () const;

    virtual void              
    setTabSelected          (ZSoft::Boolean tabSelected);

    ZcDbObjectIdArray 
    getViewportArray        () const;

    virtual Zcad::ErrorStatus 
    getClassID              (CLSID* pClsid) const;

#if defined(_WINDOWS_)
    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
#endif

    void
    getLimits (ZcGePoint2d& limMin, ZcGePoint2d& limMax) const;

    void
    getExtents (ZcGePoint3d& extMin, ZcGePoint3d& extMax) const;

    Zcad::ErrorStatus
    initialize(ZcDbObjectId* paperVportId = NULL);

    bool
    annoAllVisible() const;

    Zcad::ErrorStatus
    setAnnoAllVisible(bool newVal);
};

#pragma pack(pop)

#endif
