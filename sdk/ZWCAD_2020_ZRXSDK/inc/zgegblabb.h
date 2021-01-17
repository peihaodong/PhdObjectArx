

#ifndef ZC_GEGBLABB_H
#define ZC_GEGBLABB_H

#include "zgegbl.h"

const int eGood = ZcGe::eGood;
const int eBad = ZcGe::eBad;

typedef ZcGe::EntityId EntityId;

const ZcGe::EntityId kEntity2d = ZcGe::kEntity2d;
const ZcGe::EntityId kEntity3d = ZcGe::kEntity3d;
const ZcGe::EntityId kPointEnt2d = ZcGe::kPointEnt2d;
const ZcGe::EntityId kPointEnt3d = ZcGe::kPointEnt3d;
const ZcGe::EntityId kPosition2d = ZcGe::kPosition2d;
const ZcGe::EntityId kPosition3d = ZcGe::kPosition3d;
const ZcGe::EntityId kPointOnCurve2d = ZcGe::kPointOnCurve2d;
const ZcGe::EntityId kPointOnCurve3d = ZcGe::kPointOnCurve3d;
const ZcGe::EntityId kBoundedPlane = ZcGe::kBoundedPlane;
const ZcGe::EntityId kCircArc2d = ZcGe::kCircArc2d;
const ZcGe::EntityId kCircArc3d = ZcGe::kCircArc3d;
const ZcGe::EntityId kConic2d = ZcGe::kConic2d;
const ZcGe::EntityId kConic3d = ZcGe::kConic3d;
const ZcGe::EntityId kCurve2d = ZcGe::kCurve2d;
const ZcGe::EntityId kCurve3d = ZcGe::kCurve3d;
const ZcGe::EntityId kEllipArc2d = ZcGe::kEllipArc2d;
const ZcGe::EntityId kEllipArc3d = ZcGe::kEllipArc3d;
const ZcGe::EntityId kHelix = ZcGe::kHelix;
const ZcGe::EntityId kLine2d = ZcGe::kLine2d;
const ZcGe::EntityId kLine3d = ZcGe::kLine3d;
const ZcGe::EntityId kLinearEnt2d = ZcGe::kLinearEnt2d;
const ZcGe::EntityId kLinearEnt3d = ZcGe::kLinearEnt3d;
const ZcGe::EntityId kLineSeg2d = ZcGe::kLineSeg2d;
const ZcGe::EntityId kLineSeg3d = ZcGe::kLineSeg3d;
const ZcGe::EntityId kPlanarEnt = ZcGe::kPlanarEnt;
const ZcGe::EntityId kExternalCurve3d = ZcGe::kExternalCurve3d;
const ZcGe::EntityId kExternalCurve2d = ZcGe::kExternalCurve2d;
const ZcGe::EntityId kPlane = ZcGe::kPlane;
const ZcGe::EntityId kRay2d = ZcGe::kRay2d;
const ZcGe::EntityId kRay3d = ZcGe::kRay3d;
const ZcGe::EntityId kSurface = ZcGe::kSurface;
const ZcGe::EntityId kSphere = ZcGe::kSphere;
const ZcGe::EntityId kCone = ZcGe::kCone;
const ZcGe::EntityId kTorus = ZcGe::kTorus;
const ZcGe::EntityId kCylinder = ZcGe::kCylinder;
const ZcGe::EntityId kSplineEnt2d = ZcGe::kSplineEnt2d;
const ZcGe::EntityId kSurfaceCurve2dTo3d = ZcGe::kSurfaceCurve2dTo3d;
const ZcGe::EntityId kSurfaceCurve3dTo2d = ZcGe::kSurfaceCurve3dTo2d;

const ZcGe::EntityId kPolyline2d = ZcGe::kPolyline2d;
const ZcGe::EntityId kAugPolyline2d = ZcGe::kAugPolyline2d;
const ZcGe::EntityId kNurbCurve2d = ZcGe::kNurbCurve2d;
const ZcGe::EntityId kDSpline2d = ZcGe::kDSpline2d;
const ZcGe::EntityId kCubicSplineCurve2d = ZcGe::kCubicSplineCurve2d;
const ZcGe::EntityId kSplineEnt3d = ZcGe::kSplineEnt3d;
const ZcGe::EntityId kPolyline3d = ZcGe::kPolyline3d;
const ZcGe::EntityId kAugPolyline3d = ZcGe::kAugPolyline3d;
const ZcGe::EntityId kNurbCurve3d = ZcGe::kNurbCurve3d;
const ZcGe::EntityId kDSpline3d = ZcGe::kDSpline3d;
const ZcGe::EntityId kCubicSplineCurve3d = ZcGe::kCubicSplineCurve3d;
const ZcGe::EntityId kTrimmedCrv2d = ZcGe::kTrimmedCrv2d;
const ZcGe::EntityId kCompositeCrv2d = ZcGe::kCompositeCrv2d;
const ZcGe::EntityId kCompositeCrv3d = ZcGe::kCompositeCrv3d;
const ZcGe::EntityId kEnvelope2d = ZcGe::kEnvelope2d;

const ZcGe::EntityId kExternalSurface = ZcGe::kExternalSurface;
const ZcGe::EntityId kNurbSurface = ZcGe::kNurbSurface;
const ZcGe::EntityId kOffsetSurface = ZcGe::kOffsetSurface;
const ZcGe::EntityId kTrimmedSurface = ZcGe::kTrimmedSurface;
const ZcGe::EntityId kCurveBoundedSurface = ZcGe::kCurveBoundedSurface;
const ZcGe::EntityId kPointOnSurface = ZcGe::kPointOnSurface;
const ZcGe::EntityId kExternalBoundedSurface = ZcGe::kExternalBoundedSurface;
const ZcGe::EntityId kCurveCurveInt2d = ZcGe::kCurveCurveInt2d;
const ZcGe::EntityId kCurveCurveInt3d = ZcGe::kCurveCurveInt3d;
const ZcGe::EntityId kBoundBlock2d = ZcGe::kBoundBlock2d;
const ZcGe::EntityId kBoundBlock3d = ZcGe::kBoundBlock3d;
const ZcGe::EntityId kOffsetCurve2d = ZcGe::kOffsetCurve2d;
const ZcGe::EntityId kOffsetCurve3d = ZcGe::kOffsetCurve3d;
const ZcGe::EntityId kPolynomCurve3d = ZcGe::kPolynomCurve3d;
const ZcGe::EntityId kBezierCurve3d = ZcGe::kBezierCurve3d;
const ZcGe::EntityId kObject = ZcGe::kObject;
const ZcGe::EntityId kFitData3d = ZcGe::kFitData3d;
const ZcGe::EntityId kHatch = ZcGe::kHatch;
const ZcGe::EntityId kTrimmedCurve2d = ZcGe::kTrimmedCurve2d;
const ZcGe::EntityId kTrimmedCurve3d = ZcGe::kTrimmedCurve3d;
const ZcGe::EntityId kCurveSampleData = ZcGe::kCurveSampleData;

const ZcGe::EntityId kEllipCone = ZcGe::kEllipCone;
const ZcGe::EntityId kEllipCylinder = ZcGe::kEllipCylinder;
const ZcGe::EntityId kIntervalBoundBlock = ZcGe::kIntervalBoundBlock;
const ZcGe::EntityId kClipBoundary2d = ZcGe::kClipBoundary2d;
const ZcGe::EntityId kExternalObject = ZcGe::kExternalObject;
const ZcGe::EntityId kCurveSurfaceInt = ZcGe::kCurveSurfaceInt;
const ZcGe::EntityId kSurfaceSurfaceInt = ZcGe::kSurfaceSurfaceInt;

typedef ZcGe::ExternalEntityKind ExternalEntityKind;

const ZcGe::ExternalEntityKind kAcisEntity = ZcGe::kAcisEntity;
const ZcGe::ExternalEntityKind kExternalEntityUndefined
                                = ZcGe::kExternalEntityUndefined;

typedef ZcGe::NurbSurfaceProperties NurbSurfaceProperties;

const ZcGe::NurbSurfaceProperties kOpen = ZcGe::kOpen;
const ZcGe::NurbSurfaceProperties kClosed = ZcGe::kClosed;
const ZcGe::NurbSurfaceProperties kPeriodic = ZcGe::kPeriodic;
const ZcGe::NurbSurfaceProperties kRational = ZcGe::kRational;
const ZcGe::NurbSurfaceProperties kNoPoles= ZcGe::kNoPoles;
const ZcGe::NurbSurfaceProperties kPoleAtMin = ZcGe::kPoleAtMin;
const ZcGe::NurbSurfaceProperties kPoleAtMax = ZcGe::kPoleAtMax;
const ZcGe::NurbSurfaceProperties kPoleAtBoth = ZcGe::kPoleAtBoth;

typedef ZcGe::PointContainment PointContainment;

const ZcGe::PointContainment kInside = ZcGe::kInside;
const ZcGe::PointContainment kOutside = ZcGe::kOutside;
const ZcGe::PointContainment kOnBoundary = ZcGe::kOnBoundary;

typedef ZcGe::ZcGeXConfig ZcGeXConfig;

const ZcGe::ZcGeXConfig kNotDefined = ZcGe::kNotDefined;
const ZcGe::ZcGeXConfig kUnknown = ZcGe::kUnknown;
const ZcGe::ZcGeXConfig kLeftRight = ZcGe::kLeftRight;
const ZcGe::ZcGeXConfig kRightLeft = ZcGe::kRightLeft;
const ZcGe::ZcGeXConfig kLeftLeft = ZcGe::kLeftLeft;
const ZcGe::ZcGeXConfig kRightRight = ZcGe::kRightRight;
const ZcGe::ZcGeXConfig kPointLeft = ZcGe::kPointLeft;
const ZcGe::ZcGeXConfig kPointRight = ZcGe::kPointRight;
const ZcGe::ZcGeXConfig kLeftOverlap = ZcGe::kLeftOverlap;
const ZcGe::ZcGeXConfig kOverlapLeft = ZcGe::kOverlapLeft;
const ZcGe::ZcGeXConfig kRightOverlap = ZcGe::kRightOverlap;
const ZcGe::ZcGeXConfig kOverlapRight = ZcGe::kOverlapRight;
const ZcGe::ZcGeXConfig kOverlapStart = ZcGe::kOverlapStart;
const ZcGe::ZcGeXConfig kOverlapEnd = ZcGe::kOverlapEnd;
const ZcGe::ZcGeXConfig kOverlapOverlap = ZcGe::kOverlapOverlap;

typedef ZcGe::ErrorCondition  ZcGeError;
 
const ZcGe::ErrorCondition	kOk = ZcGe::kOk;
const ZcGe::ErrorCondition	k0This = ZcGe::k0This;
const ZcGe::ErrorCondition	k0Arg1 = ZcGe::k0Arg1;
const ZcGe::ErrorCondition	k0Arg2 = ZcGe::k0Arg2;
const ZcGe::ErrorCondition	kPerpendicularArg1Arg2 = ZcGe::kPerpendicularArg1Arg2;     
const ZcGe::ErrorCondition	kEqualArg1Arg2 = ZcGe::kEqualArg1Arg2;
const ZcGe::ErrorCondition	kEqualArg1Arg3 = ZcGe::kEqualArg1Arg3;
const ZcGe::ErrorCondition	kEqualArg2Arg3 = ZcGe::kEqualArg2Arg3;
const ZcGe::ErrorCondition	kLinearlyDependentArg1Arg2Arg3 = ZcGe::kLinearlyDependentArg1Arg2Arg3;
const ZcGe::ErrorCondition	kArg1TooBig = ZcGe::kArg1TooBig;
const ZcGe::ErrorCondition	kArg1OnThis = ZcGe::kArg1OnThis;
const ZcGe::ErrorCondition	kArg1InsideThis = ZcGe::kArg1InsideThis;

typedef ZcGe::ZcGeIntersectError ZcGeIntersectError;

const ZcGe::ZcGeIntersectError kXXOk = ZcGe::kXXOk;
const ZcGe::ZcGeIntersectError kXXIndexOutOfRange = ZcGe::kXXIndexOutOfRange;
const ZcGe::ZcGeIntersectError kXXWrongDimensionAtIndex = ZcGe::kXXWrongDimensionAtIndex;
const ZcGe::ZcGeIntersectError kXXUnknown = ZcGe::kXXUnknown;
#endif
