
#ifndef ZCDB_ANNOTATIONSCALE_H
#define ZCDB_ANNOTATIONSCALE_H

#pragma once
#pragma pack(push, 8)

#include "zdbObjContext.h"

class ZcDbImpAnnotationScale;

class ZcDbAnnotationScale : public ZcDbObjectContext, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAnnotationScale);
    ZcDbAnnotationScale ();
    virtual ~ZcDbAnnotationScale ();
    virtual Zcad::ErrorStatus getName (ZcString& name) const;
    virtual Zcad::ErrorStatus setName (const ZcString& name);
    virtual ZSoft::LongPtr uniqueIdentifier () const;
    virtual ZcString collectionName () const;
    virtual Zcad::ErrorStatus copyFrom ( const ZcRxObject *pOther);
    virtual Zcad::ErrorStatus getPaperUnits (double& dPaperUnits) const;
    virtual Zcad::ErrorStatus setPaperUnits (double dPaperUnits);
    virtual Zcad::ErrorStatus getDrawingUnits (double&  dDrawingUnits) const;
    virtual Zcad::ErrorStatus setDrawingUnits (const double dDrawingUnits);
    virtual Zcad::ErrorStatus getScale (double& dScale) const;
    virtual Zcad::ErrorStatus  getIsTemporaryScale (bool& bTemporary) const;
    virtual bool matchScaleId(ZSoft::LongPtr id) const;
protected:
    ZcDbImpAnnotationScale* mpImp;
    friend class ZcDbSystemInternals;
    ZcDbAnnotationScale ( bool );

};

// Notification of Annotation Scale change.
class ZCDB_PORT ZcDbAnnotationScaleReactor: public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAnnotationScaleReactor);

	virtual void annotationScaleChanged (const ZcDbDatabase* pDb,
		const ZcDbViewport* pVP, 
		const ZcDbAnnotationScale* pScale,
		const bool bInitializing);
};

ZCDB_PORT bool zcdbAddAnnotationScaleReactor(ZcDbAnnotationScaleReactor *pReactor);

ZCDB_PORT bool zcdbRemoveAnnotationScaleReactor(ZcDbAnnotationScaleReactor *pReactor);

#pragma pack(pop)

#endif
