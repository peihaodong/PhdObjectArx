

#ifndef __ZcGiLineAttributes_H_Defined__
#define __ZcGiLineAttributes_H_Defined__

#include "zacdb.h"
#include "zAcGiLineAttrUtils.h"

typedef enum {
	
	kLineTypeSolid							= 0x00,
	kDashed									= 0x01,
	kDotted									= 0x02,
	kDash_Dot								= 0x03,
	kShort_Dash								= 0x04,
	kMedium_Dash							= 0x05,
	kLong_Dash								= 0x06,
	kShort_Dash_X2							= 0x07,
	kMedium_Dash_X2							= 0x08,
	kLong_Dash_X2							= 0x09,
	kMedium_Long_Dash						= 0x0A,
	kMedium_Dash_Short_Dash_Short_Dash		= 0x0B,
	kLong_Dash_Short_Dash					= 0x0C,
	kLong_Dash_Dot_Dot						= 0x0D,
	kLong_Dash_Dot							= 0x0E,
	kMedium_Dash_Dot_Short_Dash_Dot			= 0x0F,
	kSparse_Dot								= 0x10,
	kISO_Dash								= 0x11,
	kISO_Dash_Space							= 0x12,
	kISO_Long_Dash_Dot						= 0x13,
	kISO_Long_Dash_Double_Dot				= 0x14,
	kISO_Long_Dash_Triple_Dot				= 0x15,
	kISO_Dot								= 0x16,
	kISO_Long_Dash_Short_Dash				= 0x17,
	kISO_Long_Dash_Double_Short_Dash		= 0x18,
	kISO_Dash_Dot							= 0x19,
	kISO_Double_Dash_Dot					= 0x1A,
	kISO_Dash_Double_Dot					= 0x1B,
	kISO_Double_Dash_Double_Dot				= 0x1C,
	kISO_Dash_Triple_Dot					= 0x1D,
	kISO_Double_Dash_Triple_Dot				= 0x1E,
	kLineTypeNone							= 0x1F,
	kSolid_6_Pixels_Blank_6_Pixels          = 0x20,
}ZcGiLineType;

typedef enum {
	kMiterJoin								= 0x00,
	kBevelJoin								= 0x01,
	kRoundJoin								= 0x02,
	kDiamondJoin							= 0x03,
} ZcGiLineJoinStyle;

typedef enum {
	kButtCap								= 0x00,
	kSquareCap								= 0x01,                          
	kRoundCap								= 0x02,                           
	kDiamondCap								= 0x03,
} ZcGiLineEndStyle;

typedef enum {
	kFillStyleSolid							= 0x00,
	kCheckerboard							= 0x01,    
	kCrosshatch								= 0x02,      
	kDiamonds								= 0x03,        
	kHorizontal_Bars						= 0x04, 
	kSlant_Left								= 0x05,      
	kSlant_Right							= 0x06,     
	kSquare_Dots							= 0x07,
	kVertical_Bars							= 0x08,   
	kUser_Defined							= 0x09
}ZcGiLineFillStyle;

class ZSOFT_NO_VTABLE ZcGiLineAttributes
{
public:

    virtual ~ZcGiLineAttributes() { }

	virtual ZcDb::LineWeight	getLineweight	() const						= 0;
	virtual void setLineweight					(ZcDb::LineWeight lweight)		= 0;

	virtual ZcGiLineJoinStyle	getJoinstyle	() const						= 0;
	virtual void setJoinstyle					(ZcGiLineJoinStyle joinstyle)	= 0;
	
	virtual ZcGiLineEndStyle	getEndstyle		() const						= 0;
	virtual void setEndstyle					(ZcGiLineEndStyle endstyle)		= 0;

	virtual ZcGiLineType		getLinetype		() const						= 0;
	virtual void setLinetype					(ZcGiLineType linetype)			= 0;
	
	virtual ZcGiLineFillStyle	getFillstyle	() const						= 0;
	virtual void setFillstyle					(ZcGiLineFillStyle fillstyle)	= 0;

	virtual bool isLinetypeAdaptive				() const						= 0;
	virtual void setLinetypeAdaptive			(bool isAdaptive)				= 0;

	virtual bool isLineWeightByLayer			() const						= 0;
	virtual void setLineWeightByLayer			(bool isLineweightByLayer)		= 0;

	virtual bool hasCustomLineweight			() const						= 0;
	virtual void setCustomLineweight			(bool isCustomLineweight)		= 0;

    virtual bool isLineweightDefault            () const                        = 0;
    virtual void setLineweightDefault           ()                              = 0;

    virtual ZcGiLineAttributes* clone           () const                        = 0;

};	

#endif 