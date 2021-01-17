#pragma once

#include "zacdb.h"
#include "zdbmain.h"

class ZcDbViewport;

#pragma pack (push, 8)

class ZcDbAnnotativeObjectPE : public ZcRxObject
{
public:

	ZCRX_DECLARE_MEMBERS(ZcDbAnnotativeObjectPE);

	virtual bool annotative(ZcDbObject* pObject) const = 0;

	virtual Zcad::ErrorStatus setAnnotative( ZcDbObject* pObject,
		const bool  bAnnotative ) = 0;

	virtual Zcad::ErrorStatus setFromStyle(ZcDbObject* pObject, 
		bool&       bUpdated) = 0;

	virtual bool forceAnnoAllVisible(ZcDbObject* pObj) const { return false;} ;

	virtual Zcad::ErrorStatus setForceAnnoAllVisible(ZcDbObject* pObj,
		bool bForce) const 
	{return Zcad::eNotImplemented;}

	virtual Zcad::ErrorStatus resetScaleDependentProperties (
		ZcDbObject* pObject) 
	{return Zcad::eNotImplemented;}
};

class ZcDbPaperOrientationPE : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbPaperOrientationPE);
    virtual bool paperOrientation(ZcDbObject* pObject) const = 0;
    virtual Zcad::ErrorStatus setPaperOrientation(
                                         ZcDbObject* pObject,
                                         const bool  bPaperOrientation ) = 0;
    virtual Zcad::ErrorStatus applyPaperOrientationTransform (
                                         ZcDbObject* pObject,
                                         const ZcDbViewport *pVport ) const
        { return Zcad::eNotImplemented; }
};

#pragma pack (pop)

