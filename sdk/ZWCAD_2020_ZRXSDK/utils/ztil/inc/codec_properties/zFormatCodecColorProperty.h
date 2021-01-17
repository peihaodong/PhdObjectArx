#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZIMAGEPIXEL_H
#include "zImagePixel.h"
#endif

#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#include "zFormatCodecPropertyInterface.h"
#endif

#ifndef ZFORMATCODECCOLORPROPERTY_H
#define ZFORMATCODECCOLORPROPERTY_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
/// <summary>
/// This class represents a single color. 
/// </summary>
///
class DllImpExp FormatCodecColorProperty : public FormatCodecPropertyInterface
{
public:
    /// <summary>
    /// This enum declares the descriptions of the meaning of the color.
    /// </summary>
    enum ColorType { 

        /// <summary>
        /// This entry indicates that the encoded color
        /// is a key color that should be transparent.
        /// </summary>
        ///
        /// <remarks>
        /// It would be best to use the <c>FormatCodecTransparency</c> property
        /// to indicate transparency key colors.
        /// </remarks>
        ///
        kTransparent,

        /// <summary>
        /// This entry indicates that the color is a foreground color.
        /// </summary>
        kForeground, 

        /// <summary>
        /// This entry indicates that the color is a background color.
        /// </summary>
        kBackground, 

        /// <summary>
        /// This entry indicates that the color use is defined by the subclasser.
        /// </summary>
        kCustom 
    };
public:

    /// <summary>
    /// The constructor for the property.
    /// </summary>
    ///
    /// <param name="type">
    /// A <c>ColorType</c> entry that will be used to set up the class.
    /// </param>
    ///
    FormatCodecColorProperty (ColorType type);

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~FormatCodecColorProperty ();

    /// <summary>
    /// This method is an artificial copy constructor. It will make a complete
    /// and accurate copy of the class.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecColorProperty</c> instance as a 
    /// <c>FormatCodecPropertyInterface</c> pointer.
    /// </returns>
    ///
    virtual FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This returns the color as a <c>ImagePixel</c>.
    /// </summary>
    ///
    /// <returns>
    /// This returns the color held by the property as an <c>ImagePixel</c> instance.
    /// </returns>
    ///
    virtual ImagePixel getColor ( ) const;
    
    /// <summary>
    /// This describes the usage of the color.
    /// </summary>
    ///
    /// <returns>
    /// This returns the <c>ColorType</c> enum entry describing the color.
    /// </returns>
    ///
    virtual ColorType getType ( ) const;

    /// <summary>
    /// This sets the color and it's <c>ColorType<c> enum description.
    /// </summary>
    ///
    /// <param name="color">
    /// An <c>ImagePixel</c> instance that holds the color.
    /// </param>
    ///
    /// <param name="type">
    /// A <c>ColorType</c> entry that describes the color.
    /// </param>
    ///
    /// <returns>
    /// This will return true if the color could be set.
    /// </returns>
    ///
    virtual bool setColor (ImagePixel color, ColorType type );

protected:
    /// <summary>
    /// (Protected) The <c>ImagePixel</c> that holds the color.
    /// </summary>
    ///
    ImagePixel mColor;

    /// <summary>
    /// (Protected) The <c>ColorType</c> enum that describes the color held.
    /// </summary>
    ///
    ColorType mColorType;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
