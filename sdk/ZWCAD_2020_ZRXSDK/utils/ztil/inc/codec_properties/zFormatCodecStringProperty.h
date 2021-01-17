#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#include "zFormatCodecPropertyInterface.h"
#endif
#ifndef ZSTRINGBUFFER_H
#include "zStringBuffer.h"
#endif

#ifndef ZFORMATCODECSTRINGPROPERTY_H
#define ZFORMATCODECSTRINGPROPERTY_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class holds an integer value. 
/// </summary>
///
/// <remarks>
/// The double value is most often used in conjunction with other simple
/// data type properties in a set grouping that forms something analogous to
/// a structure in 'c'.
/// </remarks>
///
class DllImpExp FormatCodecStringProperty : public FormatCodecPropertyInterface
{
public:
    /// <summary>
    /// This enum describes the format of the string held by the property.
    /// </summary>
    enum StringType {
        /// <summary>
        /// This entry indicates that the string is a single line.
        /// </summary>
        kSingleLine, 
        /// <summary>
        /// This entry indicates that the string has multiple lines separated by character return/linefeeds.
        /// </summary>
        kMultiLine 
    };

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~FormatCodecStringProperty ();

    /// <summary>
    /// This method is an artificial copy constructor. It will make a complete
    /// and accurate copy of the class.
    /// </summary>
    ///
    /// <returns>
    /// This method returns a new <c>FormatCodecStringProperty</c> instance as a 
    /// <c>FormatCodecPropertyInterface</c> pointer.
    /// </returns>
    ///
    virtual FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This method will return the default value of the property.
    /// </summary>
    ///
    /// <param name="sbDefault">
    /// A StringBuffer reference which will be set to the default value of the instance.
    /// </param>
    ///
    virtual void getDefaultValue (StringBuffer& sbDefault);


    /// <summary>
    /// This method will get the string from the property.
    /// </summary>
    ///
    /// <param name="sbValue">
    /// A StringBuffer reference which will set to set the string in the property.
    /// </param>
    ///
    virtual void getValue (StringBuffer& sbValue) const;

    /// <summary>
    /// This method will set the string into the property.
    /// </summary>
    ///
    /// <param name="sbValue">
    /// The const StringBuffer reference which will be used to set the value held by the instance.
    /// </param>
    ///
    /// <returns>
    /// This will return true on success.
    /// </returns>
    ///
    virtual bool setValue (const StringBuffer& sbValue);

    /// <summary>
    /// This method will get the maximum number of bytes (not characters) the string in the property can hold.
    /// </summary>
    ///
    /// <returns>
    /// This will return the maximum number of bytes the internal string can hold.
    /// </returns>
    ///
    virtual int maximumStringBytes () const;

    /// <summary>
    /// This describes the type of the string held by the property.
    /// </summary>
    ///
    /// <returns>
    /// This returns the <c>StringType</c> enum entry describing the string.
    /// </returns>
    ///
	virtual StringType getStringType() const;

protected:
    /// <summary>
    /// (Protected) The constructor for the property.
    /// </summary>
    ///
    /// <param name="sbDefault">
    /// The const StringBuffer reference which will be used to set the value held by the instance.
    /// </param>
    ///
    /// <param name="nMaximumBytes">
    /// This will be used to set the maximum number of bytes the internal string can hold.
    /// </param>
    ///
	FormatCodecStringProperty (const StringBuffer& sbDefault, int nMaximumBytes);

protected:
    /// <summary>
    /// (Protected) The default string.
    /// </summary>
    StringBuffer msbDefault;

    /// <summary>
    /// (Protected) The value string.
    /// </summary> 
    StringBuffer msbValue;

    /// <summary>
    /// (Protected) The string byte limit.
    /// </summary>
    int mnMaximumBytes;

    /// <summary>
    /// (Protected) The type of the string as described by the <c>StringType</c> enum.
    /// </summary>
    StringType	mStringType;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif


