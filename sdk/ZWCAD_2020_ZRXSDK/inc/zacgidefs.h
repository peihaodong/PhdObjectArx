
#ifndef _ZACGIDEFS_H_H
#define _ZACGIDEFS_H_H
typedef enum {
	eZcGiRegenTypeInvalid = 0,
	kZcGiStandardDisplay = 2,
	kZcGiHideOrShadeCommand,
	kZcGiRenderCommand,
	kZcGiShadedDisplay = kZcGiRenderCommand,
	kZcGiForExplode,
	kZcGiSaveWorldDrawForProxy
} ZcGiRegenType;

#define kZcGiSaveWorldDrawForR12 kZcGiForExplode 

typedef enum {
	kZcGiFillAlways = 1,
	kZcGiFillNever
} ZcGiFillType;

typedef enum {
	kZcGiInvisible = 0,
	kZcGiVisible,
	kZcGiSilhouette
} ZcGiVisibility;

typedef enum {
	kZcGiArcSimple = 0,                 
	kZcGiArcSector,                     
	kZcGiArcChord                       
} ZcGiArcType;

typedef enum {
	kZcGiCounterClockwise = -1,
	kZcGiNoOrientation = 0,
	kZcGiClockwise = 1
} ZcGiOrientationType;

typedef enum {
	kZcGiMaxDevForCircle = 0,
	kZcGiMaxDevForCurve,
	kZcGiMaxDevForBoundary,
	kZcGiMaxDevForIsoline,
	kZcGiMaxDevForFacet
} ZcGiDeviationType;

typedef enum {
	kZcGiBitonal,
	kZcGiPalette,
	kZcGiGray,
	kZcGiRGBA,
	kZcGiBGRA,
	kZcGiARGB,
	kZcGiABGR,
	kZcGiBGR,
	kZcGiRGB                              
} ZcGiImageOrg;

typedef enum {
	kZcGiXLeftToRightTopFirst,
	kZcGiXLeftToRightBottomFirst,
	kZcGiXRightToLeftTopFirst,
	kZcGiXRightToLeftBottomFirst,
	kZcGiYTopToBottomLeftFirst,
	kZcGiYTopToBottomRightFirst,
	kZcGiYBottomToTopLeftFirst,
	kZcGiYBottomToTopRightFirst
} ZcGiImageOrient;

typedef enum {
	kDefaultScaleFilter,
	kNearestScaleFilter,
	kBellScaleFilter,
	kMitchellScaleFilter,
	kTriangleScaleFilter,
	kCubicScaleFilter,
	kBsplineScaleFilter,
	kLanczos3ScaleFilter
} ZcGiScaleFilterType;

typedef enum {
	kDefaultRotationFilter,
	kInterpolatedRotationFilter,
	kNearestRotationFilter,
} ZcGiRotationFilterType;

typedef enum {
	kDefaultScale,
	kRelativeScale,
	kUnTransformedScale
} ZcGiScaleType;

enum ZcGiEdgeStyleMaskValues {
	kZcGiNoEdgeStyleMask = 0,
	kZcGiJitterMask      = 1,
	kZcGiOverhangMask    = 2,
	kZcGiEdgeColorMask   = 4
};

typedef unsigned int ZcGiEdgeStyleMask;

#endif 