
#pragma once

#ifndef ZDBREVOLVEOPTIONS_H
#define ZDBREVOLVEOPTIONS_H

#include "zdbmain.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbbody.h"

#pragma pack(push, 8)

class ZcDbRevolveOptions
{
public:
    ZcDbRevolveOptions ();
    ZcDbRevolveOptions ( const ZcDbRevolveOptions& src );
    ~ZcDbRevolveOptions ();
    ZcDbRevolveOptions& operator = ( const ZcDbRevolveOptions& src );
    double  draftAngle () const;
    void  setDraftAngle ( double ang );
    double  twistAngle () const;
    void  setTwistAngle ( double ang );
    bool  closeToAxis () const;
    void  setCloseToAxis ( bool val );
    Zcad::ErrorStatus  checkRevolveCurve ( ZcDbEntity* pRevEnt,
        const ZcGePoint3d& axisPnt, const ZcGeVector3d& axisDir,
        bool& closed, bool& endPointsOnAxis, bool& planar,
        bool displayErrorMessages = false );

private:
    void *mpImpRevolveOptions;
    friend class ZcDbImpRevolveOptions;
};

#pragma pack(pop)

#endif 
