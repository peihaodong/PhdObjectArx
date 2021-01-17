

#ifndef __ZcGiStyleAttributes_H_Defined__
#define __ZcGiStyleAttributes_H_Defined__

#include "zAcGiLineAttributes.h"



class ZSOFT_NO_VTABLE ZcGiStyleAttributes
{
public:
	enum AttributeFlags{
		kNothing								= 0x00,
		kColor      							= 0x01,
		kLine       							= 0x02,
		kLineType                               = 0x04,
		kPlotStyle                              = 0x08,
		kEverything                             = 0x0F
	}; 
    ZcGiStyleAttributes()   { }
    ZcGiStyleAttributes(const ZcGiStyleAttributes& source);
    virtual ~ZcGiStyleAttributes()  { }

    ZcCmEntityColor& getColorAttribute();
    const ZcCmEntityColor& getColorAttribute() const;
    void setColorAttribute(const ZcCmEntityColor& color);
    ZcDbObjectId linetypeObjectId() const;
    void setLinetypeObjectId(const ZcDbObjectId& newId);
    ZcDbObjectId plotStyleNameId() const;
    void setPlotStyleName(const ZcDbObjectId& newId);
	virtual ZcGiLineAttributes* getLineAttribute()                              = 0;
    virtual const ZcGiLineAttributes* getLineAttribute() const                  = 0;
    virtual void setLineAttribute(const ZcGiLineAttributes* pLineAttributes)    = 0;

    virtual void EnsureColorVisibility (ZcCmEntityColor& color)	                = 0;	

protected:
    
	ZcCmEntityColor m_colorAttribute;

    ZcDbObjectId    m_idLinetype;
    ZcDbObjectId    m_idPlotstyle;
};

inline
ZcGiStyleAttributes::ZcGiStyleAttributes(
	const ZcGiStyleAttributes& source) 
{
	m_colorAttribute = source.getColorAttribute();
    m_idLinetype = source.linetypeObjectId();
    m_idPlotstyle = source.plotStyleNameId();
}

inline
ZcCmEntityColor& 
ZcGiStyleAttributes::getColorAttribute()
{ 
    return m_colorAttribute; 
}

inline
const ZcCmEntityColor& 
ZcGiStyleAttributes::getColorAttribute() const
{ 
    return m_colorAttribute; 
}

inline 
void	
ZcGiStyleAttributes::setColorAttribute (
	const ZcCmEntityColor& color) 
{
	m_colorAttribute = color; 
}

inline
ZcDbObjectId
ZcGiStyleAttributes::linetypeObjectId() const
{
    return m_idLinetype;
}

inline
void
ZcGiStyleAttributes::setLinetypeObjectId(const ZcDbObjectId& newId)
{
    m_idLinetype = newId;
}

inline
ZcDbObjectId
ZcGiStyleAttributes::plotStyleNameId() const
{
    return m_idPlotstyle;
}

inline
void
ZcGiStyleAttributes::setPlotStyleName(const ZcDbObjectId& newId)
{
    m_idPlotstyle = newId;
}

#endif 