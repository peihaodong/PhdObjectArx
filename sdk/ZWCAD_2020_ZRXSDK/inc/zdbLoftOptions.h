
#pragma once

#ifndef ZDBLOFTOPTIONS_H
#define ZDBLOFTOPTIONS_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbbody.h"

#pragma pack(push, 8)

class ZcDbLoftOptions
{
public:
    ZcDbLoftOptions ();
    ZcDbLoftOptions ( const ZcDbLoftOptions& src );
    ~ZcDbLoftOptions ();
    ZcDbLoftOptions& operator = ( const ZcDbLoftOptions& src );

    enum NormalOption {
            kNoNormal,
            kFirstNormal,
            kLastNormal,
            kEndsNormal,
            kAllNormal,
            kUseDraftAngles
    };

    double  draftStart () const;
    void  setDraftStart ( double ang );
    double  draftEnd () const;
    void  setDraftEnd ( double ang );
    double  draftStartMag () const;
    void  setDraftStartMag ( double val );
    double  draftEndMag () const;
    void  setDraftEndMag ( double val );
    bool  arcLengthParam () const;
    void  setArcLengthParam ( bool val );
    bool  noTwist () const;
    void  setNoTwist ( bool val );
    bool  alignDirection () const;
    void  setAlignDirection ( bool val );
    bool  simplify () const;
    void  setSimplify ( bool val );
    bool  closed () const;
    void  setClosed ( bool val );
    bool  ruled () const;
    void  setRuled ( bool val );
    bool  virtualGuide () const;
    void  setVirtualGuide ( bool val );
    ZcDbLoftOptions::NormalOption  normal () const;
    void  setNormal ( ZcDbLoftOptions::NormalOption val );
    Zcad::ErrorStatus  setOptionsFromSysvars ();
    Zcad::ErrorStatus  setSysvarsFromOptions ();
    Zcad::ErrorStatus  checkOptions ( bool displayErrorMessages = false  );
    Zcad::ErrorStatus checkLoftCurves (
        ZcArray<ZcDbEntity*>& crossSectionCurves,
        ZcArray<ZcDbEntity*>& guideCurves,
        ZcDbEntity* pPathCurve,
        bool& allOpen, bool& allClosed, bool& allPlanar,
        bool displayErrorMessages = false );
    Zcad::ErrorStatus checkCrossSectionCurves (
        ZcArray<ZcDbEntity*>& crossSectionCurves,
        bool& allOpen, bool& allClosed, bool& allPlanar,
        bool displayErrorMessages = false );
    Zcad::ErrorStatus checkGuideCurves ( ZcArray<ZcDbEntity*>& guideCurves,
                                         bool displayErrorMessages = false );
    Zcad::ErrorStatus checkPathCurve ( ZcDbEntity *pPathCurve,
                                       bool displayErrorMessages = false );

private:
    void *mpImpLoftOptions;
    friend class ZcDbImpLoftOptions;
};

#pragma pack(pop)

#endif 
