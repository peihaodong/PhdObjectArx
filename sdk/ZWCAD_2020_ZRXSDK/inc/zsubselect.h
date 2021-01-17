
#pragma once

#include "zacedinpt.h"

typedef ZcDbFullSubentPathArray ZcSubentPathArray;

class ZcGiViewport;

class ZcEdSubSelectFilter
{
public:
	virtual ~ZcEdSubSelectFilter() { }
    enum SubSelectStatus
    {
        kSubSelectionNone = 0,  
        kSubSelectionAugment,   
        kSubSelectionExclusive, 
        kSubSelectAll           
    };

    virtual Zcad::ErrorStatus subSelectClassList(ZcArray<ZcRxClass*>& clsIds)
    { return Zcad::eOk; }

    virtual bool selectEntity(
            const ZcGePoint3d&  wvpt, 
            const ZcGeVector3d& wvwdir,
            const ZcGeVector3d& wvwxdir,
            double              wxaper,
            double              wyaper,
            ZSoft::Int32        flags,
            const ZcGiViewport* pCurVp,
            ZcDbEntity*         pEnt) const
    { return false; }

    virtual SubSelectStatus subSelectEntity(
            const ZcGePoint3d&        wpt1,
            const ZcGePoint3d&        wpt2,
            const ZcGeVector3d&       wvwdir,
            const ZcGeVector3d&       wvwxdir,
            double                    wxaper,
            double                    wyaper,
            ZcDb::SelectType          seltype,
            bool                      bAugment,
            bool                      bIsInPickfirstSet,
            bool                      bEvery,
            const ZcGiViewport*       pCurVP,
            ZcDbEntity*               pEnt,
            ZcDbFullSubentPathArray&  paths)
    { return kSubSelectionNone; }

    virtual SubSelectStatus subSelectEntity(
            const resbuf*             pResbuf,
            bool                      bAugment,
            bool                      bIsInPickfirstSet,
            bool                      bEvery,
            const ZcGiViewport*       pCurVP,
            ZcDbEntity*               pEnt,
            ZcDbFullSubentPathArray&  paths)
    { return kSubSelectionNone; }

    virtual bool reSubSelectEntity(ZcDbEntity* pEnt,
            ZcDbFullSubentPathArray& paths)
    { return false; }
    
    virtual bool cancelSubSelect(ZcDbEntity* pEnt)
    { return false; }

    virtual bool cancelAllSubSelect()
    { return false; }

    virtual bool onKey(ZSoft::UInt32 wMsg, unsigned int nChar, 
            unsigned int rptCnt, unsigned int flags)
    { return false; }

    virtual bool isSubSelected(ZcDbEntity* pEnt) const
    { return false; }

};

