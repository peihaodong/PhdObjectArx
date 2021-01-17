#ifndef ZC_BRGBL_H
#define ZC_BRGBL_H 1

#include "zadesk.h"
#include "zacadstrc.h"

#ifdef ZWBREP_EXPORTS
#define DllImpExp __declspec(dllexport)
#else
#define DllImpExp __declspec(dllimport)
#endif

#define ZWBREPVENO 0

struct ZcBr
{
    enum ErrorStatus    { eOk                   = 0,	// status OK; no errors

                          eNotImplementedYet    = Zcad::eNotImplementedYet, 
                          eNotApplicable        = Zcad::eNotApplicable, 
                          eInvalidInput         = Zcad::eInvalidInput, 
                          eOutOfMemory          = Zcad::eOutOfMemory, 
                          eNullObjectPointer    = Zcad::eUnrecoverableErrors, 
                          eWrongObjectType      = Zcad::eWrongObjectType, 
                          eWrongSubentityType   = Zcad::eWrongSubentityType,
                          eNullObjectId         = Zcad::eNullObjectId, 
                          eNullSubentityId      = Zcad::eInvalidIndex, 
                          eObjectIdMismatch     = Zcad::eWrongDatabase, 
                          eTopologyMismatch     = Zcad::eWrongDatabase, 
                          eUnsuitableGeometry   = Zcad::eAmbiguousOutput, 
                          eMissingGeometry      = Zcad::eDegenerateGeometry, 
						  eMissingSubentity		= Zcad::eNotInDatabase, 
						  eInvalidObject		= Zcad::eUnrecoverableErrors, 
						  eAmbiguousOutput		= Zcad::eAmbiguousOutput, 
						  
                          eBrepChanged          = 3008,	// Associated AutoCAD object has been modified since
														//   the AcBr* object was last set
                          eUnsuitableTopology   = 3013,	// topology is unsuitable for this class or function
						  eDegenerateTopology	= 3020,	// topology hierarchy is incomplete
						  eUninitialisedObject  = 3021	// AcBr* object is uninitialised
	};

    enum Relation       { kUnknown              = 0,	// point or curve containment cannot be determined, or
														//   curve is partially inside and partially outside
                          kOutside              = 1,	// point or curve is outside geometry bounds
                          kInside               = 2,	// point is inside geometry bounds, or curve is fully
														//   inside or on geometry bounds
                          kBoundary             = 3,	// point is on geometry bounds
                          kCoincident           = 4,	// obsolete; now returns kInside
                          kTangent              = 5,	// obsolete; now returns kUnknown
                          kIntersect            = 6		// obsolete; now returns kUnknown
                        };

    enum Element2dShape	{ kDefault              = 0,	// use system defaults (i.e., by surface type)
						  kAllPolygons			= 1,	// attempt to only produce ngons, where n>4                  
						  kAllQuadrilaterals    = 2,	// attempt to only produce 4gons (complete quadrangles)
                          kAllTriangles         = 3		// attempt to only produce 3gons (approx. equilateral)
	                    };

	enum LoopType		{ kUnclassified		    = 0,	// obsolete; now returns kLoopUnclassified
		                  kExterior             = 1,	// obsolete; now returns kLoopExterior
						  kInterior				= 2,	// obsolete; now returns kLoopInterior
						  kWinding				= 3,	// obsolete; now returns kLoopWinding
						  kLoopUnclassified		= kUnclassified,
														// loop type cannot be determined at this time, or
														//   is ambiguous (such as for loops embedded in
														//   spherical, toroidal or periodic nurb surfaces)
		                  kLoopExterior         = kExterior,
														// loop is on peripheral boundary (there is exactly
														//   one, unless the loop is on a conic surface; in
														//   which case there are winding loops instead)
						  kLoopInterior			= kInterior,
														// loop is a hole in the interior of a face (there
														//   may be more than one interior loop per surface)
						  kLoopWinding			= kWinding
														// loop is winding on a conic surface (there is one
														//   winding loop for each non-degenerate base)
						};

	enum ValidationLevel { kFullValidation		= 0,	// validate the brep on every query (default)
		                   kNoValidation		= 1		// never validate the brep (NOTE: potentially unsafe)
	                     };

	enum ShellType		{ kShellUnclassified	= 0,	// shell type cannot be determined at this time
		                  kShellExterior        = 1,	// shell is on peripheral boundary of region or brep
						  kShellInterior		= 2		// shell is a void in the interior of a region or brep
														//   (there may be more than one interior shell per solid)
						};
};

#endif

