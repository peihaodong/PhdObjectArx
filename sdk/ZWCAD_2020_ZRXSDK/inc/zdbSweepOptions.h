
#pragma once

#ifndef ZDBSWEEPOPTIONS_H
#define ZDBSWEEPOPTIONS_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbbody.h"

#pragma pack(push, 8)

class ZcDbSweepOptions
{
public:
    ZcDbSweepOptions ();
    ZcDbSweepOptions ( const ZcDbSweepOptions& src );
    ~ZcDbSweepOptions ();
    ZcDbSweepOptions& operator = ( const ZcDbSweepOptions& src );

    enum AlignOption {
            kNoAlignment,
            kAlignSweepEntityToPath,
            kTranslateSweepEntityToPath,
            kTranslatePathToSweepEntity

    };

    enum MiterOption {
            kDefaultMiter,
            kOldMiter,
            kNewMiter,
            kCrimpMiter,
            kBendMiter
    };

    double  draftAngle () const;
    void  setDraftAngle ( double ang );
    double  startDraftDist () const;
    void  setStartDraftDist ( double val );
    double  endDraftDist () const;
    void  setEndDraftDist ( double val );
    double  twistAngle () const;
    void  setTwistAngle ( double ang );
    double  scaleFactor () const;
    void  setScaleFactor ( double val );
    double  alignAngle () const;
    void  setAlignAngle ( double ang );
    ZcDbSweepOptions::AlignOption  align () const;
    void  setAlign ( ZcDbSweepOptions::AlignOption val );
    ZcDbSweepOptions::MiterOption  miterOption () const;
    void  setMiterOption ( ZcDbSweepOptions::MiterOption val );
    bool  alignStart () const;
    void  setAlignStart ( bool val );
    ZcGePoint3d  basePoint () const;
    void  setBasePoint ( ZcGePoint3d& pnt );
    bool  bank () const;
    void  setBank ( bool val );
    bool  checkIntersections () const;
    void  setCheckIntersections ( bool val );
    ZcGeVector3d  twistRefVec () const;
    void  setTwistRefVec ( const ZcGeVector3d& vec );
    bool  getSweepEntityTransform ( ZcGeMatrix3d& mat );
    void  setSweepEntityTransform ( ZcGeMatrix3d& mat );
    Zcad::ErrorStatus  setSweepEntityTransform ( ZcArray<ZcDbEntity*>& sweepEntities,
                                                 bool displayErrorMessages = false );
    bool  getPathEntityTransform ( ZcGeMatrix3d& mat );
    void  setPathEntityTransform ( ZcGeMatrix3d& mat );
    Zcad::ErrorStatus  setPathEntityTransform ( ZcDbEntity *pPathEnt,
                                                bool displayErrorMessages = false );
    Zcad::ErrorStatus  checkSweepCurve ( ZcDbEntity *pSweepEnt,
        ZcDb::Planarity& planarity, ZcGePoint3d& pnt, ZcGeVector3d& vec,
        bool& closed, double& approxArcLen, bool displayErrorMessages = false );
    Zcad::ErrorStatus  checkPathCurve ( ZcDbEntity *pPathEnt,
                                        bool displayErrorMessages = false );

private:
    void *mpImpSweepOptions;
    friend class ZcDbImpSweepOptions;
};

#pragma pack(pop)

#endif 
