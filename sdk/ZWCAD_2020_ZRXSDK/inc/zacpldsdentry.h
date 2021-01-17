

#ifndef ZCPLDSDENTRY_H
#define ZCPLDSDENTRY_H

#pragma once

#include "zacpl.h"
#include "zacplobject.h"

class ZcPlDSDEntry  : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlDSDEntry)
public:

    enum SheetType {
        kSingleDWF  = 0,
        kMultiDWF = 1,
        kOriginalDevice = 2,
		kSingleDWFx = 3,
		kMultiDWFx = 4,
		kSinglePDF = 5,
		kMultiPDF = 6,
    };

    ZCPL_PORT ZcPlDSDEntry();

    ZCPL_PORT virtual ~ZcPlDSDEntry();

    ZCPL_PORT ZcPlDSDEntry(const ZcPlDSDEntry & src);

    ZCPL_PORT ZcPlDSDEntry& operator= (const ZcPlDSDEntry &src);

    ZCPL_PORT const ZTCHAR *      dwgName() const;
    ZCPL_PORT void              setDwgName(const ZTCHAR * pName);

    ZCPL_PORT const ZTCHAR *      layout() const;
    ZCPL_PORT void              setLayout(const ZTCHAR * pLayoutName);
    
    ZCPL_PORT const ZTCHAR *      title() const;
    ZCPL_PORT void              setTitle(const ZTCHAR * pTitle);
    
    ZCPL_PORT const ZTCHAR *      NPS() const;
    ZCPL_PORT void              setNPS(const ZTCHAR * pNPSName);
    
    ZCPL_PORT const ZTCHAR *      NPSSourceDWG() const;
    ZCPL_PORT void              setNPSSourceDWG(const ZTCHAR * pNPWDWGName);

    ZCPL_PORT bool               has3dDwfSetup() const;
    ZCPL_PORT void              setHas3dDwfSetup(bool b3dDwfSetup);
};

#endif 
